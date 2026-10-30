/* Function: memmove @ 00010744 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmove_0001f5d4)(__dest);
  return pvVar1;
}



/* Function: snprintf @ 00010750 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_0001f5d8)(__s);
  return iVar1;
}



/* Function: __cxa_begin_cleanup @ 0001075c */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_0001f5dc)();
  return;
}



/* Function: memcpy @ 00010768 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0001f5e0)(__dest);
  return pvVar1;
}



/* Function: puts @ 00010774 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_0001f5e4)(__s);
  return iVar1;
}



/* Function: getuid @ 0001078c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
  __uid_t _Var1;
  
  _Var1 = (*(code *)PTR_getuid_0001f5ec)();
  return _Var1;
}



/* Function: malloc @ 00010798 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_0001f5f0)(__size);
  return pvVar1;
}



/* Function: abort @ 000107a4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_0001f5f4)();
  return;
}



/* Function: __stack_chk_fail @ 000107b0 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_0001f5f8)();
  return;
}



/* Function: strtod @ 000107bc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double strtod(char *__nptr,char **__endptr)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  
  uVar1 = (*(code *)PTR_strtod_0001f5fc)(__nptr);
  return (double)CONCAT44(extraout_s1,uVar1);
}



/* Function: modf @ 000107c8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double modf(double __x,double *__iptr)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  
  uVar1 = (*(code *)PTR_modf_0001f600)(SUB84(__x,0),__iptr);
  return (double)CONCAT44(extraout_s1,uVar1);
}



/* Function: strstr @ 000107d4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strstr_0001f604)(__haystack);
  return pcVar1;
}



/* Function: __cxa_type_match @ 000107e0 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_0001f608)();
  return;
}



/* Function: localtime @ 000107ec */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)(*(code *)PTR_localtime_0001f60c)(__timer);
  return ptVar1;
}



/* Function: memset @ 000107f8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_0001f610)(__s);
  return pvVar1;
}



/* Function: time @ 00010804 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = (*(code *)PTR_time_0001f614)(__timer);
  return tVar1;
}



/* Function: strcmp @ 00010810 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_0001f618)(__s1);
  return iVar1;
}



/* Function: __gnu_Unwind_Find_exidx @ 0001081c */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_0001f61c)();
  return;
}



/* Function: sprintf @ 00010828 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sprintf_0001f620)(__s);
  return iVar1;
}



/* Function: atoi @ 00010834 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_atoi_0001f624)(__nptr);
  return iVar1;
}



/* Function: strlen @ 00010840 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_0001f628)(__s);
  return sVar1;
}



/* Function: raise @ 0001084c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_raise_0001f62c)(__sig);
  return iVar1;
}



/* Function: free @ 00010858 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0001f630)(__ptr);
  return;
}



/* Function: entry @ 00010868 */

void processEntry entry(void)

{
  (*(code *)PTR___cxa_finalize_0001f5e8)(DAT_00010874);
  return;
}



/* Function: FUN_00010878 @ 00010878 */

int FUN_00010878(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_00010978;
  if (param_2 == 0) {
    iVar2 = -10;
  }
  else {
    snprintf((char *)(param_2 + 4),1000,(char *)(param_1 + 0x14));
    snprintf(&stack0xfffffff0 + iVar2,100,(char *)(DAT_0001097c + 0x108a2));
    snprintf(&stack0x00000054 + iVar2,100,(char *)(DAT_00010980 + 0x108b0));
    snprintf(&stack0x000000b8 + iVar2,100,(char *)(DAT_00010984 + 0x108bc));
    snprintf(&stack0x0000011c + iVar2,100,(char *)(DAT_00010988 + 0x108c8));
    snprintf(&stack0x00000180 + iVar2,100,(char *)(DAT_0001098c + 0x108d4));
    snprintf(&stack0x000001e4 + iVar2,100,(char *)(DAT_00010990 + 0x108e0));
    snprintf(&stack0x00000248 + iVar2,100,(char *)(DAT_00010994 + 0x108ec));
    snprintf(&stack0x000002ac + iVar2,100,(char *)(DAT_00010998 + 0x108f8));
    snprintf(&stack0x00000310 + iVar2,100,(char *)(DAT_0001099c + 0x10904));
    snprintf(&stack0x00000374 + iVar2,100,(char *)(DAT_000109a0 + 0x10910));
    snprintf(&stack0x000003d8 + iVar2,100,(char *)(DAT_000109a4 + 0x1091c));
    snprintf(&stack0x0000043c + iVar2,100,(char *)(DAT_000109a8 + 0x10928));
    snprintf(&stack0xffffffec + DAT_000109b0 + iVar2,100,(char *)(DAT_000109ac + 0x10938));
    snprintf(&stack0x00000504 + iVar2,100,(char *)(DAT_000109b4 + 0x10946));
    iVar3 = 0;
    do {
      pcVar1 = strstr((char *)(param_2 + 4),&stack0xfffffff0 + iVar2 + iVar3 * 100);
      if (pcVar1 != (char *)0x0) {
        return -0xb - iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0xe);
    iVar2 = 0;
  }
  return iVar2;
}



/* Function: FUN_000109bc @ 000109bc */

bool FUN_000109bc(int param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  tm *ptVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_30 [8];
  char local_28 [8];
  time_t local_20;
  char local_1c [8];
  
  if ((param_3 != (char *)0x0) && (param_2 != (char *)0x0)) {
    local_28[4] = '\0';
    local_28[5] = '\0';
    local_28[0] = '\0';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    snprintf(local_28,6,(char *)(DAT_00010ab0 + 0x109da));
    pcVar1 = strstr(param_2,local_28);
    if (pcVar1 == param_2) {
      local_20 = time((time_t *)0x0);
      ptVar2 = localtime(&local_20);
      iVar3 = ptVar2->tm_mon;
      local_30[0] = '\0';
      local_30[1] = '\0';
      local_30[2] = '\0';
      local_30[3] = '\0';
      local_30[4] = '\0';
      local_30[5] = '\0';
      iVar6 = 0;
      while ((char *)(param_1 + 0x14) < param_3) {
        param_3 = param_3 + -1;
        if (9 < (byte)(*param_3 - 0x30U)) break;
        if (iVar6 == 4) {
          return true;
        }
        local_30[iVar6] = *param_3;
        iVar6 = iVar6 + 1;
      }
      if (iVar6 != 0) {
        local_1c[0] = '\0';
        local_1c[1] = '\0';
        if (iVar6 == 1) {
          iVar4 = atoi(local_30);
        }
        else {
          local_1c[1] = 0;
          if (iVar6 == 2) {
            local_1c[0] = local_30[0];
            iVar4 = atoi(local_1c);
            local_1c[0] = local_30[1];
            iVar6 = atoi(local_1c);
            iVar4 = iVar6 * 10 + iVar4;
          }
          else {
            iVar4 = 0;
            if (iVar6 == 3) {
              local_1c[0] = local_30[0];
              iVar4 = atoi(local_1c);
              local_1c[0] = local_30[1];
              iVar6 = atoi(local_1c);
              local_1c[0] = local_30[2];
              iVar5 = atoi(local_1c);
              iVar4 = iVar6 * 10 + iVar5 * 100 + iVar4;
            }
          }
        }
        return iVar4 == iVar3 + 1;
      }
    }
  }
  return true;
}



/* Function: FUN_00010ab4 @ 00010ab4 */

undefined4 FUN_00010ab4(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1;
  do {
    piVar2 = piVar1 + 1;
    if (*piVar1 != 0) {
      FUN_00019c5c();
      *piVar1 = 0;
    }
    piVar1 = piVar2;
  } while (piVar2 != param_1 + 10);
  return param_2;
}



/* Function: FUN_00010ad8 @ 00010ad8 */

void FUN_00010ad8(undefined4 param_1,char *param_2,char *param_3,int param_4,int param_5)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  size_t sVar5;
  uint uVar6;
  char *pcVar7;
  byte *pbVar8;
  char *pcVar9;
  int iVar10;
  char *__s;
  int iVar11;
  int iVar12;
  int iVar13;
  int local_128;
  char acStack_10c [6];
  char acStack_106 [6];
  char acStack_100 [6];
  char acStack_fa [6];
  char acStack_f4 [6];
  char acStack_ee [6];
  char acStack_e8 [6];
  char acStack_e2 [6];
  char acStack_dc [6];
  char acStack_d6 [6];
  char acStack_d0 [6];
  char acStack_ca [6];
  char acStack_c4 [12];
  char acStack_b8 [16];
  char acStack_a8 [16];
  char acStack_98 [16];
  char acStack_88 [16];
  char acStack_78 [16];
  char acStack_68 [16];
  char acStack_58 [16];
  char acStack_48 [15];
  char acStack_39 [16];
  byte abStack_29 [13];
  int local_1c;
  
  local_1c = **(int **)(DAT_00010e1c + 0x10ae8);
  memset(acStack_39 + 1,0,0xd);
  if (param_5 == 3) {
    iVar12 = 0x400;
  }
  else {
    iVar12 = 1;
    if (param_5 == 4) {
      iVar12 = 0x100000;
    }
  }
  iVar11 = 0;
  for (; param_2 <= param_3; param_2 = param_2 + 1) {
    cVar1 = *param_2;
    if ((cVar1 != ',') && (cVar1 != ' ')) {
      acStack_39[iVar11 + 1] = cVar1;
      iVar11 = iVar11 + 1;
    }
    if (0xb < iVar11) {
      iVar11 = 3;
      goto LAB_00010bec;
    }
  }
  iVar11 = iVar11 + -1;
  if ((byte)((acStack_39 + 1)[iVar11] - 0x30U) < 10) {
    strtod(acStack_39 + 1,(char **)0x0);
    uVar3 = FUN_0001a734();
    uVar4 = FUN_0001a978(iVar12);
    FUN_0001aa24(uVar3,uVar4);
    iVar11 = FUN_0001ad1c();
    goto LAB_00010ef4;
  }
  if (param_4 == 3) {
    memset(acStack_48,0,0xd);
    memset(acStack_58,0,0xd);
    memset(acStack_68,0,0xd);
    memset(acStack_78,0,0xd);
    memset(acStack_88,0,0xd);
    memset(acStack_98,0,0xd);
    memset(acStack_a8,0,0xd);
    memset(acStack_b8,0,0xd);
    iVar13 = snprintf(acStack_48,0xd,(char *)(DAT_00010e20 + 0x10be4));
    if ((((-1 < iVar13) &&
         (iVar13 = snprintf(acStack_58,0xd,(char *)(DAT_00010e24 + 0x10bfa)), -1 < iVar13)) &&
        (iVar13 = snprintf(acStack_68,0xd,(char *)(DAT_00010e28 + 0x10c0a)), -1 < iVar13)) &&
       (((iVar13 = snprintf(acStack_78,0xd,(char *)(DAT_00010e2c + 0x10c1a)), -1 < iVar13 &&
         (iVar13 = snprintf(acStack_88,0xd,(char *)(DAT_00010e30 + 0x10c2a)), -1 < iVar13)) &&
        ((iVar13 = snprintf(acStack_98,0xd,(char *)(DAT_00010e34 + 0x10c3a)), -1 < iVar13 &&
         (iVar13 = snprintf(acStack_a8,0xd,(char *)(DAT_00010e38 + 0x10c4a)), -1 < iVar13)))))) {
      iVar13 = snprintf(acStack_b8,0xd,(char *)(DAT_00010e3c + 0x10c5a));
      if (-1 < iVar13) {
        pcVar9 = acStack_39 + 1;
        iVar13 = strcmp(pcVar9,acStack_48);
        if (((iVar13 == 0) || (iVar13 = strcmp(pcVar9,acStack_58), iVar13 == 0)) ||
           ((iVar13 = strcmp(pcVar9,acStack_68), iVar13 == 0 ||
            ((((iVar13 = strcmp(pcVar9,acStack_78), iVar13 == 0 ||
               (iVar13 = strcmp(pcVar9,acStack_88), iVar13 == 0)) ||
              (iVar13 = strcmp(pcVar9,acStack_98), iVar13 == 0)) ||
             ((iVar13 = strcmp(pcVar9,acStack_a8), iVar13 == 0 ||
              (iVar13 = strcmp(pcVar9,acStack_b8), iVar13 == 0)))))))) {
          iVar11 = 0;
          goto LAB_00010ef4;
        }
        goto LAB_00010cd4;
      }
    }
    iVar11 = 6;
LAB_00010bec:
    iVar11 = -iVar11;
  }
  else {
LAB_00010cd4:
    snprintf(acStack_10c,6,(char *)(DAT_00010e40 + 0x10ce4));
    snprintf(acStack_106,6,(char *)(DAT_00010e44 + 0x10cf0));
    snprintf(acStack_100,6,(char *)(DAT_00010e48 + 0x10cfe));
    snprintf(acStack_fa,6,(char *)(DAT_00010e4c + 0x10d0a));
    snprintf(acStack_f4,6,(char *)(DAT_00010e50 + 0x10d18));
    snprintf(acStack_ee,6,(char *)(DAT_00010e54 + 0x10d24));
    snprintf(acStack_e8,6,(char *)(DAT_00010e58 + 0x10d32));
    snprintf(acStack_e2,6,(char *)(DAT_00010e5c + 0x10d3e));
    snprintf(acStack_dc,6,(char *)(DAT_00010e60 + 0x10d4c));
    snprintf(acStack_d6,6,(char *)(DAT_00010e64 + 0x10d58));
    snprintf(acStack_d0,6,(char *)(DAT_00010e68 + 0x10d66));
    snprintf(acStack_ca,6,(char *)(DAT_00010e6c + 0x10d72));
    snprintf(acStack_c4,6,(char *)(DAT_00010e70 + 0x10d80));
    memset(abStack_29 + 1,0,10);
    iVar13 = 0;
    pcVar9 = (char *)(DAT_00010e74 + 0x10d96);
    local_128 = 0;
    sVar5 = 0;
    __s = (char *)(DAT_00010e78 + 0x10d9c);
    for (; iVar11 != -1; iVar11 = iVar11 + -1) {
      if (__s == pcVar9) {
        iVar13 = 0;
        while( true ) {
          __s = acStack_10c + iVar13 * 6;
          sVar5 = strlen(__s);
          iVar10 = sVar5 - 1;
          pcVar7 = acStack_39 + ((iVar10 + iVar11) - sVar5) + 2;
          bVar2 = true;
          for (; -1 < iVar10; iVar10 = iVar10 + -1) {
            cVar1 = *pcVar7;
            pcVar7 = pcVar7 + -1;
            bVar2 = (bool)(bVar2 & __s[iVar10] == cVar1);
          }
          if (bVar2) break;
          iVar13 = iVar13 + 1;
          if (iVar13 == 0xd) goto LAB_00010e9a;
        }
      }
      sVar5 = sVar5 - 1;
      if ((int)sVar5 < 0) {
        iVar11 = iVar11 + 1;
        __s = (char *)(DAT_00010e7c + 0x10e0c);
      }
      else if (acStack_39[iVar11 + 1] == __s[sVar5]) {
        if (sVar5 == 0) {
          abStack_29[local_128 + 1] = (byte)iVar13;
          local_128 = local_128 + 1;
        }
      }
      else {
        __s = (char *)((int)&DAT_00010e1c + DAT_00010e80);
      }
    }
LAB_00010e9a:
    pbVar8 = abStack_29 + local_128;
    iVar11 = 0;
    while (local_128 = local_128 + -1, local_128 != -1) {
      if (8 < local_128) {
        iVar11 = 1;
        goto LAB_00010bec;
      }
      uVar6 = (uint)*pbVar8;
      if (uVar6 == 0xc) {
        uVar6 = (uint)pbVar8[1] * 1000;
LAB_00010ee2:
        iVar11 = iVar11 + uVar6;
      }
      else {
        if (uVar6 == 0xb) {
          uVar6 = (uint)pbVar8[1] * 100;
          goto LAB_00010ee2;
        }
        if (uVar6 == 10) {
          iVar11 = iVar11 + (uint)pbVar8[1] * 10;
        }
        else if (local_128 == 0) goto LAB_00010ee2;
      }
      pbVar8 = pbVar8 + -1;
    }
    iVar11 = iVar11 * iVar12;
  }
LAB_00010ef4:
  if (local_1c == **(int **)(DAT_00010f0c + 0x10efc)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar11);
}



/* Function: FUN_00010f10 @ 00010f10 */

undefined4 FUN_00010f10(int param_1,int *param_2,int *param_3)

{
  size_t sVar1;
  char *pcVar2;
  char *pcVar3;
  size_t sVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  char cVar11;
  char *__maxlen;
  int *__haystack;
  int *piVar12;
  uint uVar13;
  int *local_84;
  char *local_80;
  int *local_78;
  uint local_70;
  int *local_68;
  char *local_58;
  uint local_54;
  int local_4c [10];
  int local_24;
  undefined1 local_20;
  char local_1c [8];
  
  if ((param_2 != (int *)0x0) && (param_1 != 0)) {
    pcVar6 = (char *)(param_1 + 0x14);
    sVar1 = strlen(pcVar6);
    if ((0 < (int)sVar1) &&
       (((((int)sVar1 < 0x3e9 && (param_3 != (int *)0x0)) && (param_2[1] - 1U < 4)) &&
        ((0 < *param_2 && (*param_2 < 5)))))) {
      memset(param_3,0,0x3ec);
      local_1c[0] = '\0';
      local_1c[1] = '\0';
      local_1c[2] = 0;
      snprintf(local_1c,3,(char *)(DAT_000112b4 + 0x10f7c));
      piVar12 = local_4c;
      piVar9 = piVar12;
      do {
        *piVar9 = 0;
        piVar9 = piVar9 + 1;
      } while (piVar9 != &local_24);
      __haystack = param_2 + 2;
      pcVar2 = strstr((char *)__haystack,local_1c);
      local_70 = 0;
      piVar9 = piVar12;
      if (pcVar2 != (char *)0x0) {
        do {
          iVar8 = FUN_00019c80(0x328);
          *piVar9 = iVar8;
          piVar9 = piVar9 + 1;
        } while (piVar9 != &local_24);
        local_24 = 0;
        local_20 = 0;
        local_70 = 0;
        piVar9 = __haystack;
        local_78 = piVar12;
        while ((piVar9 != (int *)0x0 &&
               (pcVar2 = strstr((char *)piVar9,local_1c), pcVar2 != (char *)0x0))) {
          if (DAT_000112b8 < (int)pcVar2 - (int)piVar9) goto LAB_000112ac;
          snprintf((char *)(*local_78 + 8),((int)pcVar2 - (int)piVar9) + 1,(char *)piVar9);
          sVar1 = strlen((char *)__haystack);
          sVar4 = strlen(local_1c);
          if ((char *)((int)param_2 + (sVar1 - sVar4) + 7) < pcVar2) goto LAB_000112ac;
          pcVar2 = pcVar2 + sVar4;
          pcVar3 = strstr(pcVar2,local_1c);
          if ((pcVar3 == (char *)0x0) || (__maxlen = pcVar3 + (1 - (int)pcVar2), 5 < (int)__maxlen))
          goto LAB_000112ac;
          snprintf((char *)&local_24,(size_t)__maxlen,pcVar2);
          piVar9 = (int *)*local_78;
          iVar8 = atoi((char *)&local_24);
          *piVar9 = iVar8;
          local_24 = 0;
          local_20 = 0;
          sVar1 = strlen((char *)__haystack);
          sVar4 = strlen(local_1c);
          if ((char *)((int)param_2 + (sVar1 - sVar4) + 7) < pcVar3) goto LAB_000112ac;
          local_24 = 0;
          pcVar3 = pcVar3 + sVar4;
          local_20 = 0;
          pcVar2 = strstr(pcVar3,local_1c);
          if (pcVar2 != (char *)0x0) {
            if (4 < (int)pcVar2 - (int)pcVar3) goto LAB_000112ac;
            __maxlen = (char *)(((int)pcVar2 - (int)pcVar3) + 1);
          }
          snprintf((char *)&local_24,(size_t)__maxlen,pcVar3);
          iVar7 = *local_78;
          local_78 = local_78 + 1;
          iVar8 = atoi((char *)&local_24);
          *(int *)(iVar7 + 4) = iVar8;
          sVar1 = strlen((char *)__haystack);
          sVar4 = strlen(local_1c);
          local_70 = local_70 + 1;
          if ((char *)((int)param_2 + (sVar1 - sVar4) + 7) <= pcVar3) break;
          if (local_70 == 10) goto LAB_0001132e;
          piVar9 = (int *)(pcVar2 + sVar4);
        }
      }
      piVar9 = param_2 + 0x66;
      pcVar2 = strstr((char *)piVar9,local_1c);
      if (pcVar2 == (char *)0x0) {
        uVar13 = 0;
LAB_000111b0:
        if (uVar13 < local_70) {
          local_70 = uVar13;
        }
        local_54 = 1;
        if (0 < (int)local_70) {
          local_54 = local_70;
        }
        *param_3 = 0;
        local_68 = (int *)0x0;
        local_84 = (int *)0xffffffff;
        local_78 = (int *)0xffffffff;
        pcVar2 = pcVar6;
        local_58 = pcVar6;
LAB_000111e2:
        if (0 < (int)local_70) {
          memset(param_2,0,0x328);
          piVar10 = (int *)*piVar12;
          param_2[1] = piVar10[1];
          *param_2 = *piVar10;
          snprintf((char *)__haystack,400,(char *)(piVar10 + 2));
          snprintf((char *)piVar9,400,(char *)(*piVar12 + 0x198));
        }
        if ((int)local_84 + 6U < 6) {
          local_80 = strstr(local_58,(char *)__haystack);
        }
        else {
          local_80 = strstr(pcVar2,(char *)__haystack);
          local_84 = (int *)0xffffffff;
          local_58 = pcVar2;
        }
        if (local_80 != (char *)0x0) {
          sVar1 = strlen((char *)__haystack);
          cVar11 = '\0';
          pcVar2 = local_80 + sVar1;
          do {
            if ((4 < (int)local_78 + 5U) || (cVar11 = cVar11 + '\x01', cVar11 == '\x15'))
            goto LAB_00011354;
            local_80 = strstr(pcVar6,(char *)piVar9);
            if (local_80 == (char *)0x0) {
              pcVar6 = (char *)(DAT_000112c0 + 0x1127e);
              goto LAB_000112a8;
            }
            do {
              if (pcVar2 <= local_80) break;
              if ((char)param_2[0x66] == '\0') goto LAB_0001132e;
              sVar1 = strlen((char *)piVar9);
              sVar4 = strlen(pcVar6);
              if ((char *)(param_1 + sVar4 + 0x14) <= local_80 + sVar1) {
                pcVar6 = (char *)(DAT_000112c4 + 0x112aa);
                goto LAB_000112a8;
              }
              local_80 = strstr(local_80 + sVar1,(char *)piVar9);
            } while (local_80 != (char *)0x0);
            sVar1 = strlen((char *)__haystack);
            iVar8 = FUN_000109bc(param_1,__haystack,(int)pcVar2 - sVar1);
            if (iVar8 != 0) {
              local_84 = (int *)FUN_00010ad8(pcVar6,pcVar2,local_80 + -1,param_2[1],*param_2);
              local_78 = local_84;
            }
            if (5 < (int)local_78 + 6U) goto code_r0x0001130e;
            if ((char)param_2[2] == '\0') {
              puts((char *)(DAT_00011378 + 0x1132c));
              goto LAB_0001132e;
            }
            pcVar2 = strstr(pcVar2,(char *)__haystack);
            if (pcVar2 == (char *)0x0) goto LAB_00011354;
            sVar1 = strlen((char *)__haystack);
            pcVar2 = pcVar2 + sVar1;
          } while( true );
        }
        pcVar6 = (char *)(DAT_000112bc + 0x1124c);
LAB_000112a8:
        puts(pcVar6);
LAB_000112ac:
        iVar8 = 3;
        goto LAB_00011332;
      }
      uVar13 = 0;
      local_84 = piVar9;
      local_68 = piVar12;
      do {
        if (local_84 == (int *)0x0) goto LAB_000111b0;
        iVar8 = *local_68;
        local_68 = local_68 + 1;
        if (iVar8 == 0) goto LAB_000111b0;
        pcVar2 = strstr((char *)local_84,local_1c);
        if (pcVar2 == (char *)0x0) {
          sVar1 = strlen((char *)piVar9);
          iVar7 = (int)param_2 + ((sVar1 + 0x198) - (int)local_84);
          if (iVar7 <= DAT_000112b8) {
            snprintf((char *)(iVar8 + 0x198),iVar7 + 1,(char *)local_84);
            uVar13 = uVar13 + 1;
            goto LAB_000111b0;
          }
          break;
        }
        if (DAT_000112b8 < (int)pcVar2 - (int)local_84) break;
        snprintf((char *)(iVar8 + 0x198),((int)pcVar2 - (int)local_84) + 1,(char *)local_84);
        sVar1 = strlen(local_1c);
        uVar13 = uVar13 + 1;
        local_84 = (int *)(pcVar2 + sVar1);
        sVar1 = strlen((char *)piVar9);
        if ((int *)((int)param_2 + sVar1 + 0x197) < local_84) goto LAB_000111b0;
      } while (uVar13 != 10);
LAB_0001132e:
      iVar8 = 1;
LAB_00011332:
      iVar8 = -iVar8;
      goto LAB_00011368;
    }
  }
  return 0xffffffff;
code_r0x0001130e:
  *param_3 = *param_3 + (int)local_78;
  local_78 = (int *)0xffffffff;
LAB_00011354:
  piVar12 = piVar12 + 1;
  local_68 = (int *)((int)local_68 + 1);
  if ((int)local_54 <= (int)local_68) goto LAB_00011364;
  goto LAB_000111e2;
LAB_00011364:
  iVar8 = 0;
LAB_00011368:
  uVar5 = FUN_00010ab4(local_4c,iVar8);
  return uVar5;
}



/* Function: FUN_0001137c @ 0001137c */

void FUN_0001137c(int *param_1)

{
  (**(code **)(*param_1 + 0x3c))();
  return;
}



/* Function: FUN_00011388 @ 00011388 */

void FUN_00011388(int *param_1)

{
  (**(code **)(*param_1 + 0x178))();
  return;
}



/* Function: FUN_00011394 @ 00011394 */

int FUN_00011394(int *param_1,void *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_3);
  iVar2 = FUN_0001137c(param_1);
  if (iVar2 == 0) {
    iVar4 = DAT_00011440 + 0x113bc;
    uVar3 = FUN_00011388(param_1,uVar1,DAT_00011444 + 0x113be,iVar4);
    iVar2 = FUN_0001137c(param_1);
    if (iVar2 == 0) {
      uVar3 = (**(code **)(*param_1 + 0x17c))(param_1,param_3,uVar3);
      uVar1 = FUN_00011388(param_1,uVar1,DAT_00011448 + 0x113ea,iVar4);
      iVar2 = FUN_0001137c(param_1);
      if (iVar2 == 0) {
        uVar1 = (**(code **)(*param_1 + 0x17c))(param_1,param_3,uVar1);
        memset(param_2,0,0x3fc);
        iVar2 = FUN_000145b8(param_1,uVar3,param_2,0x14);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = FUN_000145b8(param_1,uVar1,(int)param_2 + 0x14,1000);
        return iVar2;
      }
    }
  }
  return -1;
}



/* Function: FUN_0001144c @ 0001144c */

void FUN_0001144c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x74))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00011468 @ 00011468 */

int FUN_00011468(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,DAT_000114f0 + 0x1147c);
  iVar2 = FUN_0001137c(param_1);
  if (iVar2 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x84))
                      (param_1,uVar1,DAT_000114f4 + 0x11496,DAT_000114f8 + 0x11498);
    iVar2 = FUN_0001137c(param_1);
    if (iVar2 == 0) {
      uVar5 = *param_3;
      uVar4 = (**(code **)(*param_1 + 0x29c))(param_1,param_3 + 1);
      iVar2 = FUN_0001137c(param_1);
      if (iVar2 != 0) {
        iVar2 = 4;
        goto LAB_000114de;
      }
      iVar2 = FUN_0001144c(param_1,uVar1,uVar3,uVar5,uVar4);
      if (iVar2 != 0) {
        FUN_00011804(param_1,param_2);
        return 0;
      }
    }
  }
  iVar2 = 1;
LAB_000114de:
  return -iVar2;
}



/* Function: Java_com_tencent_tccdb_SmsParser_nativeGetWrongSmsType @ 000114fc */

void Java_com_tencent_tccdb_SmsParser_nativeGetWrongSmsType
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = DAT_00011578;
  *(undefined4 *)(&stack0xffffffec + DAT_0001157c + DAT_00011578) =
       **(undefined4 **)(DAT_00011574 + 0x1150a);
  uVar4 = *(undefined4 *)(&stack0xffffffec + DAT_00011580 + DAT_00011578);
  iVar2 = FUN_00011bdc();
  if (iVar2 == 0) {
    iVar2 = -10;
  }
  else {
    iVar2 = FUN_00011394(param_1,&stack0xfffffff0 + iVar1,param_4);
    if (iVar2 == 0) {
      iVar3 = FUN_00010878(&stack0xfffffff0 + iVar1,&stack0x000003ec + iVar1);
      iVar2 = FUN_00011468(param_1,uVar4,&stack0x000003ec + iVar1);
      if (iVar2 == 0) {
        iVar2 = iVar3;
      }
    }
  }
  if (*(int *)(&stack0xffffffec + DAT_0001157c + iVar1) != **(int **)(DAT_00011584 + 0x11560)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



/* Function: Java_com_tencent_tccdb_SmsParser_nativeGetNumberEntrance @ 0001158c */

void Java_com_tencent_tccdb_SmsParser_nativeGetNumberEntrance
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *__s;
  
  iVar1 = DAT_00011728;
  puVar3 = *(undefined4 **)(DAT_0001172c + 0x115a4);
  *(undefined4 *)(&stack0xfffffff0 + DAT_00011728) =
       *(undefined4 *)(&stack0x00000b3c + DAT_00011728);
  uVar4 = *puVar3;
  *(undefined4 *)(&stack0x00000008 + DAT_00011728) =
       *(undefined4 *)(&stack0xffffffec + DAT_00011730 + DAT_00011728);
  *(undefined4 *)(&stack0xffffffec + DAT_00011734 + DAT_00011728) = uVar4;
  iVar2 = FUN_00011bdc();
  if (iVar2 == 0) {
    iVar2 = 10;
  }
  else {
    *(undefined1 **)(&stack0xfffffffc + iVar1) = &stack0x00000010 + iVar1;
    iVar2 = FUN_00011394(param_1,&stack0x00000010 + iVar1,param_4);
    if (iVar2 != 0) goto LAB_000116e4;
    uVar4 = (**(code **)(*param_1 + 0x7c))(param_1,*(undefined4 *)(&stack0xfffffff0 + iVar1));
    *(undefined4 *)(&stack0xfffffff4 + iVar1) = uVar4;
    iVar2 = FUN_0001137c(param_1);
    if (iVar2 == 0) {
      iVar6 = DAT_00011738 + 0x115f8;
      uVar4 = FUN_00011388(param_1,*(undefined4 *)(&stack0xfffffff4 + iVar1),DAT_0001173c + 0x115fa,
                           iVar6);
      iVar2 = FUN_0001137c(param_1);
      if (iVar2 == 0) {
        uVar4 = (**(code **)(*param_1 + 400))
                          (param_1,*(undefined4 *)(&stack0xfffffff0 + iVar1),uVar4);
        *(undefined4 *)(&stack0x00000000 + iVar1) = uVar4;
        uVar4 = FUN_00011388(param_1,*(undefined4 *)(&stack0xfffffff4 + iVar1),
                             DAT_00011740 + 0x11626,iVar6);
        iVar2 = FUN_0001137c(param_1);
        if (iVar2 == 0) {
          uVar4 = (**(code **)(*param_1 + 400))
                            (param_1,*(undefined4 *)(&stack0xfffffff0 + iVar1),uVar4);
          *(undefined4 *)(&stack0x00000004 + iVar1) = uVar4;
          iVar6 = DAT_00011744 + 0x1164e;
          uVar4 = FUN_00011388(param_1,*(undefined4 *)(&stack0xfffffff4 + iVar1),
                               DAT_00011748 + 0x11650,iVar6);
          *(undefined4 *)(&stack0xfffffff8 + iVar1) = uVar4;
          iVar2 = FUN_0001137c(param_1);
          if (iVar2 == 0) {
            uVar4 = (**(code **)(*param_1 + 0x17c))
                              (param_1,*(undefined4 *)(&stack0xfffffff0 + iVar1),
                               *(undefined4 *)(&stack0xfffffff8 + iVar1));
            *(undefined4 *)(&stack0xfffffff8 + iVar1) = uVar4;
            uVar4 = FUN_00011388(param_1,*(undefined4 *)(&stack0xfffffff4 + iVar1),
                                 DAT_0001174c + 0x1167e,iVar6);
            iVar2 = FUN_0001137c(param_1);
            if (iVar2 == 0) {
              uVar4 = (**(code **)(*param_1 + 0x17c))
                                (param_1,*(undefined4 *)(&stack0xfffffff0 + iVar1),uVar4);
              __s = &stack0xffffffec + DAT_00011750 + iVar1;
              memset(__s,0,0x328);
              uVar5 = *(undefined4 *)(&stack0x00000000 + iVar1);
              *(undefined4 *)(__s + 4) = *(undefined4 *)(&stack0x00000004 + iVar1);
              *(undefined4 *)(&stack0xffffffec + DAT_00011750 + iVar1) = uVar5;
              iVar2 = FUN_000145b8(param_1,*(undefined4 *)(&stack0xfffffff8 + iVar1),
                                   &stack0xffffffec + DAT_00011754 + iVar1,400);
              if ((iVar2 == 0) &&
                 (iVar2 = FUN_000145b8(param_1,uVar4,&stack0xffffffec + DAT_00011758 + iVar1,400),
                 iVar2 == 0)) {
                iVar6 = FUN_00010f10(*(undefined4 *)(&stack0xfffffffc + iVar1),__s,
                                     &stack0x0000040c + iVar1);
                iVar2 = FUN_00011468(param_1,*(undefined4 *)(&stack0x00000008 + iVar1),
                                     &stack0x0000040c + iVar1);
                if (iVar2 == 0) {
                  iVar2 = iVar6;
                }
              }
              goto LAB_000116e4;
            }
          }
        }
      }
    }
    iVar2 = 1;
  }
  iVar2 = -iVar2;
LAB_000116e4:
  if (*(int *)(&stack0xffffffec + DAT_00011734 + iVar1) == **(int **)(DAT_0001175c + 0x116ec)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}



/* Function: FUN_00011764 @ 00011764 */

void FUN_00011764(int *param_1)

{
  (**(code **)(*param_1 + 0x7c))();
  return;
}



/* Function: FUN_00011770 @ 00011770 */

void FUN_00011770(int *param_1)

{
  (**(code **)(*param_1 + 0x84))();
  return;
}



/* Function: FUN_000117e4 @ 000117e4 */

void FUN_000117e4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0xf8))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00011804 @ 00011804 */

void FUN_00011804(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00011764();
  iVar2 = FUN_00011770(param_1,uVar1,DAT_0001183c + 0x1181a,DAT_00011840 + 0x1181c,param_4);
  if (iVar2 != 0) {
    FUN_000117e4(param_1,param_2,iVar2,param_3);
  }
  (**(code **)(*param_1 + 0x5c))(param_1,uVar1);
  return;
}



/* Function: FUN_00011844 @ 00011844 */

void FUN_00011844(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x8c))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00011864 @ 00011864 */

void FUN_00011864(int *param_1,undefined4 param_2)

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
  local_1c[0] = **(int **)(DAT_00011b7c + 0x11870);
  if (*(char *)(DAT_00011b80 + 0x1187e) == '\0') {
    _Var2 = getuid();
    uVar1 = FUN_00011764(param_1,param_2);
    iVar3 = FUN_0001137c(param_1);
    if (iVar3 == 0) {
      uVar1 = FUN_00011770(param_1,uVar1,DAT_00011b84 + 0x118aa,DAT_00011b88 + 0x118ac);
      iVar3 = FUN_0001137c(param_1);
      if (iVar3 == 0) {
        uVar1 = FUN_00011844(param_1,param_2,uVar1);
        iVar3 = FUN_0001137c(param_1);
        if (iVar3 == 0) {
          uVar4 = FUN_00011764(param_1,uVar1);
          iVar3 = FUN_0001137c(param_1);
          if (iVar3 == 0) {
            uVar5 = FUN_00011770(param_1,uVar4,DAT_00011b8c + 0x118f6,DAT_00011b90 + 0x118f8);
            iVar3 = FUN_0001137c(param_1);
            if (iVar3 == 0) {
              uVar5 = FUN_00011844(param_1,uVar1,uVar5,_Var2);
              iVar3 = FUN_0001137c(param_1);
              if (iVar3 == 0) {
                iVar3 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar5);
                __format = (char *)(DAT_00011b94 + 0x1193c);
                for (local_80 = 0; local_80 < iVar3; local_80 = local_80 + 1) {
                  uVar6 = (**(code **)(*param_1 + 0x2b4))(param_1,uVar5,local_80);
                  iVar7 = FUN_0001137c(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar6,0);
                  (**(code **)(*param_1 + 0x2a8))(param_1,uVar6,uVar8);
                  uVar8 = FUN_00011770(param_1,uVar4,DAT_00011b98 + 0x11988,DAT_00011b9c + 0x1198a);
                  iVar7 = FUN_0001137c(param_1);
                  if (iVar7 != 0) break;
                  uVar6 = FUN_00011844(param_1,uVar1,uVar8,uVar6,0x40);
                  iVar7 = FUN_0001137c(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = FUN_00011764(param_1,uVar6);
                  iVar7 = FUN_0001137c(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = (**(code **)(*param_1 + 0x178))
                                    (param_1,uVar8,DAT_00011ba0 + 0x119de,DAT_00011ba4 + 0x119e0);
                  iVar7 = FUN_0001137c(param_1);
                  if (iVar7 != 0) break;
                  uVar6 = (**(code **)(*param_1 + 0x17c))(param_1,uVar6,uVar8);
                  iVar7 = FUN_0001137c(param_1);
                  if (iVar7 != 0) break;
                  iVar7 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar6);
                  for (local_84 = 0; local_84 < iVar7; local_84 = local_84 + 1) {
                    uVar8 = (**(code **)(*param_1 + 0x2b4))(param_1,uVar6,local_84);
                    iVar9 = FUN_0001137c(param_1);
                    if (iVar9 != 0) goto LAB_00011b64;
                    uVar10 = FUN_00011764(param_1,uVar8);
                    iVar9 = FUN_0001137c(param_1);
                    if (iVar9 != 0) goto LAB_00011b64;
                    uVar10 = FUN_00011770(param_1,uVar10,DAT_00011ba8 + 0x11a64,
                                          DAT_00011bac + 0x11a66);
                    iVar9 = FUN_0001137c(param_1);
                    if (iVar9 != 0) goto LAB_00011b64;
                    uVar8 = FUN_00011844(param_1,uVar8,uVar10);
                    iVar9 = FUN_0001137c(param_1);
                    if (iVar9 != 0) goto LAB_00011b64;
                    uVar10 = (**(code **)(*param_1 + 0x2e0))(param_1,uVar8,0);
                    uVar11 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar8);
                    memset(local_2c,0,0x10);
                    iVar9 = DAT_00011bb0;
                    FUN_00012a34(uVar10,uVar11,local_2c);
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
                      iVar12 = strcmp(acStack_50,(char *)(iVar9 + 0x11acc + iVar14 * 0x21));
                      if (iVar12 == 0) {
                        (**(code **)(*param_1 + 0x300))(param_1,uVar8,uVar10,0);
                        uVar1 = 1;
                        *(undefined1 *)(DAT_00011bb4 + 0x11b1a) = 1;
                        goto LAB_00011b66;
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
LAB_00011b64:
    uVar1 = 0;
  }
LAB_00011b66:
  if (local_1c[0] == **(int **)(DAT_00011bb8 + 0x11b6e)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}



/* Function: FUN_00011bbc @ 00011bbc */

void FUN_00011bbc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x1d8))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00011bdc @ 00011bdc */

bool FUN_00011bdc(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,DAT_00011c14 + 0x11bea);
  uVar2 = (**(code **)(*param_1 + 0x1c4))
                    (param_1,uVar1,DAT_00011c18 + 0x11c02,DAT_00011c1c + 0x11bfc);
  iVar3 = FUN_00011bbc(param_1,uVar1,uVar2);
  return iVar3 == 1;
}



/* Function: FUN_00011c20 @ 00011c20 */

void FUN_00011c20(undefined1 *param_1,undefined1 *param_2)

{
  *param_2 = param_1[3];
  param_2[1] = param_1[2];
  param_2[2] = param_1[1];
  param_2[3] = *param_1;
  return;
}



/* Function: FUN_00011c34 @ 00011c34 */

void FUN_00011c34(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)((uint)param_1 >> 0x18);
  param_2[1] = (char)((uint)param_1 >> 0x10);
  param_2[2] = (char)((uint)param_1 >> 8);
  param_2[3] = (char)param_1;
  return;
}



/* Function: FUN_00011c44 @ 00011c44 */

void FUN_00011c44(uint *param_1)

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
        uVar5 = DAT_00011ca4;
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



/* Function: FUN_00011cd4 @ 00011cd4 */

void FUN_00011cd4(int param_1,int *param_2,int param_3)

{
  int iVar1;
  uint local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  FUN_00011c20(param_1,local_1c);
  FUN_00011c20(param_1 + 4,&local_20);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + DAT_00011d48;
    local_1c[0] = (local_20 * 0x10 + *param_2 ^ (local_20 >> 5) + param_2[1] ^ iVar1 + local_20) +
                  local_1c[0];
    local_20 = (param_2[3] + (local_1c[0] >> 5) ^ local_1c[0] * 0x10 + param_2[2] ^
               local_1c[0] + iVar1) + local_20;
  } while (iVar1 != DAT_00011d44);
  FUN_00011c34(local_1c[0],param_3);
  FUN_00011c34(local_20,param_3 + 4);
  return;
}



/* Function: FUN_00011d4c @ 00011d4c */

void FUN_00011d4c(int param_1,int *param_2,int param_3)

{
  int iVar1;
  uint local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  FUN_00011c20(param_1,local_1c);
  FUN_00011c20(param_1 + 4,&local_20);
  iVar1 = DAT_00011db8;
  do {
    local_20 = local_20 -
               (local_1c[0] * 0x10 + param_2[2] ^ (local_1c[0] >> 5) + param_2[3] ^
               iVar1 + local_1c[0]);
    local_1c[0] = local_1c[0] -
                  ((local_20 >> 5) + param_2[1] ^ local_20 * 0x10 + *param_2 ^ local_20 + iVar1);
    iVar1 = iVar1 + DAT_00011dbc;
  } while (iVar1 != 0);
  FUN_00011c34(local_1c[0],param_3);
  FUN_00011c34(local_20,param_3 + 4);
  return;
}



/* Function: FUN_00011dc8 @ 00011dc8 */

void FUN_00011dc8(undefined4 *param_1)

{
  *param_1 = DAT_00011de4;
  param_1[1] = DAT_00011de8;
  param_1[2] = DAT_00011dec;
  param_1[3] = DAT_00011df0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  return;
}



/* Function: FUN_00011df4 @ 00011df4 */

void FUN_00011df4(int *param_1,uint param_2,uint *param_3)

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
      uVar9 = *(int *)((int)&DAT_00012054 + uVar6 * 4 + DAT_00012058) +
              local_58[*(char *)(DAT_00012058 + 0x12014 + uVar6)] + uVar8 +
              ((uVar3 ^ uVar1) & uVar4 ^ uVar3);
      uVar10 = uVar6 & 3;
      uVar6 = uVar6 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_0001203c + 0x11e82 + uVar10) & 0x1f;
      uVar10 = (uVar9 >> uVar10 | uVar9 << 0x20 - uVar10) + uVar4;
      uVar9 = uVar1;
      uVar8 = uVar3;
    } while (uVar6 != 0x10);
    uVar9 = 0;
    do {
      uVar8 = uVar10;
      uVar6 = uVar1;
      uVar1 = uVar4;
      uVar10 = *(int *)(DAT_00012040 + uVar9 * 4 + 0x11f1c) +
               local_58[*(char *)(DAT_00012040 + uVar9 + 0x11eac)] + uVar3 +
               ((uVar1 ^ uVar8) & uVar6 ^ uVar1);
      uVar4 = uVar9 & 3;
      uVar9 = uVar9 + 1;
      uVar4 = 0x20U - (int)*(char *)(DAT_00012044 + uVar4 + 0x11eec) & 0x1f;
      uVar10 = (uVar10 >> uVar4 | uVar10 << 0x20 - uVar4) + uVar8;
      uVar4 = uVar8;
      uVar3 = uVar6;
    } while (uVar9 != 0x10);
    uVar4 = 0;
    do {
      uVar3 = uVar8;
      uVar8 = uVar10;
      uVar9 = uVar1;
      uVar6 = *(int *)(DAT_00012048 + uVar4 * 4 + 0x11fd4) +
              local_58[*(char *)(DAT_00012048 + uVar4 + 0x11f34)] + uVar6 + (uVar3 ^ uVar8 ^ uVar9);
      uVar10 = uVar4 & 3;
      uVar4 = uVar4 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_0001204c + uVar10 + 0x11f6c) & 0x1f;
      uVar10 = (uVar6 >> uVar10 | uVar6 << 0x20 - uVar10) + uVar8;
      uVar1 = uVar3;
      uVar6 = uVar9;
    } while (uVar4 != 0x10);
    uVar4 = 0;
    do {
      uVar1 = uVar3;
      uVar6 = uVar10;
      uVar3 = uVar8;
      uVar9 = *(int *)((int)&DAT_00012080 + DAT_00012050 + uVar4 * 4 + 2) +
              local_58[*(char *)(DAT_00012050 + uVar4 + 0x11fb2)] + uVar9 +
              ((~uVar1 | uVar6) ^ uVar3);
      uVar10 = uVar4 & 3;
      uVar4 = uVar4 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_00012054 + uVar10 + 0x11fde) & 0x1f;
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



/* Function: FUN_0001205c @ 0001205c */

void FUN_0001205c(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00012080;
  param_1[5] = 0;
  *param_1 = uVar1;
  uVar1 = DAT_00012084;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[1] = uVar1;
  uVar1 = DAT_00012088;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[2] = uVar1;
  param_1[3] = DAT_0001208c;
  param_1[4] = DAT_00012090;
  return;
}



/* Function: FUN_00012094 @ 00012094 */

void FUN_00012094(uint *param_1)

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
    uVar5 = uVar12 + DAT_0001221c + uVar11 + (uVar10 >> 0x1b | uVar10 << 5) +
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
    uVar5 = uVar12 + DAT_00012220 + uVar14 + (uVar6 >> 0x1b | uVar6 << 5) +
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
    uVar5 = uVar12 + DAT_00012224 + uVar11 + (uVar13 >> 0x1b | uVar13 << 5) +
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
    uVar5 = uVar12 + DAT_00012228 + uVar10 + (uVar6 >> 0x1b | uVar6 << 5) +
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



/* Function: FUN_0001222c @ 0001222c */

void FUN_0001222c(int param_1,undefined1 *param_2,int param_3)

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
        FUN_00012094(param_1);
      }
      param_2 = param_2 + 1;
    }
  }
  return;
}



/* Function: FUN_00012278 @ 00012278 */

void FUN_00012278(int param_1)

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
    FUN_00012094(param_1);
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
  FUN_00012094(param_1);
  return;
}



/* Function: FUN_00012318 @ 00012318 */

void FUN_00012318(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    FUN_00012278();
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



/* Function: FUN_00012360 @ 00012360 */

void FUN_00012360(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_84 [104];
  int local_1c;
  
  piVar1 = *(int **)(DAT_000123a0 + 0x1236c);
  local_1c = *piVar1;
  FUN_0001205c(auStack_84);
  FUN_0001222c(auStack_84,param_1,param_2);
  FUN_00012318(auStack_84,param_3);
  if (local_1c != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_000123a4 @ 000123a4 */

void FUN_000123a4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte local_54 [20];
  byte abStack_40 [44];
  int local_14;
  
  local_14 = **(int **)(DAT_00012434 + 0x123b0);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_54[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x36;
    }
  }
  else {
    FUN_0001205c();
    pbVar2 = local_54;
    FUN_0001222c(param_1,param_2,param_3);
    FUN_00012318(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x36;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_40);
    iVar1 = 0x14;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_54[iVar1] = 0x36;
  }
  FUN_0001205c(param_1);
  FUN_0001222c(param_1,local_54,0x40);
  if (local_14 == **(int **)(DAT_00012438 + 0x12424)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00012548 @ 00012548 */

void FUN_00012548(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00012578;
  param_1[8] = 0;
  *param_1 = uVar1;
  uVar1 = DAT_0001257c;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[1] = uVar1;
  uVar1 = DAT_00012580;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[2] = uVar1;
  param_1[3] = DAT_00012584;
  param_1[4] = DAT_00012588;
  param_1[5] = DAT_0001258c;
  param_1[6] = DAT_00012590;
  param_1[7] = DAT_00012594;
  return;
}



/* Function: FUN_00012598 @ 00012598 */

void FUN_00012598(uint *param_1)

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
    piVar4 = (int *)(DAT_0001270c + 0x12674 + iVar16);
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



/* Function: FUN_00012710 @ 00012710 */

void FUN_00012710(int param_1,undefined1 *param_2,int param_3)

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
        if (iVar3 != 0) goto LAB_0001272a;
      }
      else {
LAB_0001272a:
        iVar2 = 0;
      }
      *(int *)(param_1 + 0x70) = iVar2;
      if ((iVar2 == 0) && (*(int *)(param_1 + 0x28) == 0x40)) {
        FUN_00012598(param_1);
      }
      param_2 = param_2 + 1;
    }
  }
  return;
}



/* Function: FUN_00012770 @ 00012770 */

void FUN_00012770(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_00011df4(param_1 + 7,iVar3 + 8,param_1,iVar1,param_4);
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  return;
}



/* Function: FUN_000127dc @ 000127dc */

void FUN_000127dc(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint __n;
  uint uVar2;
  
  if ((param_3 & 0x3f) == 0) {
    FUN_00011df4(param_2,param_3,param_1);
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
        FUN_00011df4((void *)(param_1 + 0x1c),uVar2 & 0xffffffc0,param_1);
        memcpy((void *)(param_1 + 0x1c),(void *)(param_1 + (uVar2 & 0xffffffc0) + 0x1c),uVar2 & 0x3f
              );
        *(uint *)(param_1 + 0x18) = uVar2 & 0x3f;
      }
      param_2 = (void *)((int)param_2 + __n);
      param_3 = param_3 - __n;
    }
    if (0x40 < (int)param_3) {
      FUN_00011df4(param_2,param_3 & 0xffffffc0,param_1);
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



/* Function: FUN_00012890 @ 00012890 */

void FUN_00012890(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  byte local_5c [16];
  byte abStack_4c [48];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001293c + 0x1289e);
  FUN_00012770(param_1,param_4);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_5c[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x5c;
    }
  }
  else {
    FUN_00011dc8(param_1);
    pbVar2 = local_5c;
    FUN_000127dc(param_1,param_2,param_3);
    FUN_00012770(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x5c;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_4c);
    iVar1 = 0x10;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_5c[iVar1] = 0x5c;
  }
  FUN_00011dc8(param_1);
  FUN_000127dc(param_1,local_5c,0x40);
  FUN_000127dc(param_1,param_4,0x10);
  FUN_00012770(param_1,param_4);
  if (local_1c == **(int **)(DAT_00012940 + 0x1292c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00012a34 @ 00012a34 */

void FUN_00012a34(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_b8 [156];
  int local_1c;
  
  piVar1 = *(int **)(DAT_00012a74 + 0x12a40);
  local_1c = *piVar1;
  FUN_00011dc8(auStack_b8);
  FUN_000127dc(auStack_b8,param_1,param_2);
  FUN_00012770(auStack_b8,param_3);
  if (local_1c != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00012a78 @ 00012a78 */

void FUN_00012a78(void *param_1,size_t param_2,uint *param_3)

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



/* Function: FUN_00012e70 @ 00012e70 */

void FUN_00012e70(void *param_1,size_t param_2,void *param_3)

{
  undefined1 auStack_b8 [156];
  int local_1c;
  
  local_1c = **(int **)(DAT_00012ee0 + 0x12e7c);
  memset(param_3,0,0x10);
  if (((int)param_2 < 0x11) || (param_1 == (void *)0x0)) {
    if ((0 < (int)param_2) && (param_1 != (void *)0x0)) {
      memcpy(param_3,param_1,param_2);
    }
  }
  else {
    FUN_00011dc8(auStack_b8);
    FUN_000127dc(auStack_b8,param_1,param_2);
    FUN_00012770(auStack_b8,param_3);
  }
  if (local_1c != **(int **)(DAT_00012ee4 + 0x12ed0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00012ee8 @ 00012ee8 */

uint FUN_00012ee8(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
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
    uVar8 = DAT_00013024;
    if ((((param_2 & 3) == 0) && (uVar8 = param_2, param_5 != (uint *)0x0)) &&
       (uVar8 = DAT_00013024, (int)param_2 <= param_6)) {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      uVar8 = param_2 >> 2;
      FUN_00012e70(param_3,param_4,auStack_28);
      uVar3 = uVar8 - 1;
      uVar7 = *param_5;
      if ((int)uVar3 < 1) {
        puVar4 = auStack_28 + 3;
        do {
          uVar8 = *puVar4;
          puVar4 = puVar4 + -1;
          uVar7 = uVar7 - (uVar8 ^ DAT_00013028);
          uVar7 = (uVar7 >> 0x10 | uVar7 * 0x10000) ^ DAT_00013034;
        } while (puVar4 != &local_2c);
        *param_5 = uVar7;
        uVar8 = param_2;
      }
      else {
        iVar1 = FUN_00019c90(0x34,uVar8);
        uVar5 = (iVar1 + 6) * DAT_00013028;
        iVar9 = uVar8 + DAT_0001302c;
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
          uVar5 = uVar5 + DAT_00013030;
        }
      }
    }
  }
  return uVar8;
}



/* Function: FUN_00013074 @ 00013074 */

uint FUN_00013074(uint *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
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
    if ((param_5 != (uint *)0x0) && (uVar10 = DAT_000131b0, (int)uVar8 <= param_6)) {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      for (; (int)param_2 < (int)uVar8; param_2 = param_2 + 1) {
        *(undefined1 *)((int)param_5 + param_2) = 0;
      }
      puVar4 = local_28;
      FUN_00012e70(param_3,param_4,puVar4);
      uVar8 = (param_2 >> 2) - 1;
      puVar11 = param_5 + uVar8;
      uVar9 = *puVar11;
      uVar6 = *param_5;
      uVar10 = param_2;
      if ((int)uVar8 < 1) {
        do {
          uVar8 = *puVar4;
          puVar4 = puVar4 + 1;
          uVar6 = ((uVar6 >> 0x10 | uVar6 << 0x10) ^ DAT_000131b4) + (uVar8 ^ DAT_000131b4);
        } while (puVar4 != &uStack_18);
        *param_5 = uVar6;
      }
      else {
        iVar1 = FUN_00019c90(0x34);
        uVar6 = iVar1 * DAT_000131b4 + DAT_000131b8;
        uVar7 = 0;
        while (uVar7 != uVar6) {
          uVar7 = uVar7 + DAT_000131b4;
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



/* Function: FUN_000131bc @ 000131bc */

int FUN_000131bc(void *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,void *param_5,
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
      iVar2 = FUN_00013074(param_5,sVar1,param_3,param_4,param_5,sVar1);
    }
  }
  return iVar2;
}



/* Function: FUN_0001321c @ 0001321c */

void FUN_0001321c(int param_1,int param_2)

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
      FUN_00012598(param_1);
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
    FUN_00012598(param_1);
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



/* Function: FUN_000132ec @ 000132ec */

void FUN_000132ec(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte local_54 [32];
  byte abStack_34 [32];
  int local_14;
  
  local_14 = **(int **)(DAT_0001337c + 0x132f8);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_54[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x36;
    }
  }
  else {
    FUN_00012548();
    pbVar2 = local_54;
    FUN_00012710(param_1,param_2,param_3);
    FUN_0001321c(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x36;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_34);
    iVar1 = 0x20;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_54[iVar1] = 0x36;
  }
  FUN_00012548(param_1);
  FUN_00012710(param_1,local_54,0x40);
  if (local_14 == **(int **)(DAT_00013380 + 0x1336c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00013384 @ 00013384 */

void FUN_00013384(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  byte local_5c [32];
  byte abStack_3c [32];
  int local_1c;
  
  local_1c = **(int **)(DAT_00013430 + 0x13392);
  FUN_0001321c(param_1,param_4);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_5c[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x5c;
    }
  }
  else {
    FUN_00012548(param_1);
    pbVar2 = local_5c;
    FUN_00012710(param_1,param_2,param_3);
    FUN_0001321c(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x5c;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_3c);
    iVar1 = 0x20;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_5c[iVar1] = 0x5c;
  }
  FUN_00012548(param_1);
  FUN_00012710(param_1,local_5c,0x40);
  FUN_00012710(param_1,param_4,0x20);
  FUN_0001321c(param_1,param_4);
  if (local_1c == **(int **)(DAT_00013434 + 0x13420)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00013488 @ 00013488 */

int FUN_00013488(char *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (char *)0x0) {
    while (*param_1 != '\0') {
      if (param_1[1] == '\0') {
        return iVar1 + 1;
      }
      if (param_1[2] == '\0') {
        return iVar1 + 2;
      }
      if (param_1[3] == '\0') {
        return iVar1 + 3;
      }
      iVar1 = iVar1 + 4;
      param_1 = param_1 + 4;
    }
  }
  return iVar1;
}



/* Function: FUN_000134dc @ 000134dc */

void FUN_000134dc(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    cVar1 = *(char *)(param_2 + iVar2);
    *(char *)(param_1 + iVar2) = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  return;
}



/* Function: FUN_0001361c @ 0001361c */

int FUN_0001361c(short *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (short *)0x0) {
    while (*param_1 != 0) {
      if (param_1[1] == 0) {
        return iVar1 + 1;
      }
      if (param_1[2] == 0) {
        return iVar1 + 2;
      }
      if (param_1[3] == 0) {
        return iVar1 + 3;
      }
      iVar1 = iVar1 + 4;
      param_1 = param_1 + 4;
    }
  }
  return iVar1;
}



/* Function: FUN_0001370c @ 0001370c */

int FUN_0001370c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = 0;
  if (param_1 != param_2) {
    do {
      uVar3 = (uint)*(ushort *)(param_1 + iVar4);
      uVar2 = (uint)*(ushort *)(param_2 + iVar4);
      if ((uVar3 - 0x41 & 0xffff) < 0x1a) {
        uVar3 = uVar3 + 0x20 & 0xffff;
      }
      if ((uVar2 - 0x41 & 0xffff) < 0x1a) {
        uVar2 = uVar2 + 0x20 & 0xffff;
      }
    } while ((uVar3 != 0) && (iVar4 = iVar4 + 2, uVar3 == uVar2));
    iVar1 = uVar3 - uVar2;
  }
  return iVar1;
}



/* Function: FUN_00013844 @ 00013844 */

undefined4 FUN_00013844(uint *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 >> 0x1c < 6) {
                    /* WARNING: Could not emulate address calculation at 0x00013854 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((*param_1 >> 0x1c) * 4 + DAT_00013870 + 0x13856) +
                      DAT_00013870 + 0x13856))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_00013874 @ 00013874 */

void FUN_00013874(uint *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  iVar1 = FUN_00013844();
  puVar2 = (undefined1 *)(iVar1 + (*param_1 & 0xfffffff));
  uVar3 = *param_1 & 0xfffffff;
  while ((int)uVar3 < (int)(uVar3 + 1 & 0xfffffffe)) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  }
  *param_1 = uVar3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_000138a8 @ 000138a8 */

void FUN_000138a8(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00013844();
  for (uVar2 = *param_1 & 0xfffffff; (int)uVar2 < (int)(uVar2 + 3 & 0xfffffffc); uVar2 = uVar2 + 1)
  {
    *(undefined1 *)(iVar1 + uVar2) = 0;
  }
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_000138d4 @ 000138d4 */

int FUN_000138d4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00013844();
  return iVar1 + param_2;
}



/* Function: FUN_000138ec @ 000138ec */

int FUN_000138ec(byte *param_1,int param_2,byte *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = param_4;
  if (param_2 < param_4) {
    iVar3 = param_2;
  }
  pbVar4 = param_1 + iVar3;
  iVar3 = 0;
  while( true ) {
    if (iVar3 != 0) {
      return iVar3;
    }
    if (pbVar4 <= param_1) break;
    bVar1 = *param_1;
    bVar2 = *param_3;
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
    iVar3 = (uint)bVar1 - (uint)bVar2;
  }
  return param_2 - param_4;
}



/* Function: FUN_00013914 @ 00013914 */

int FUN_00013914(byte *param_1,int param_2,byte *param_3,int param_4)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = param_4;
  if (param_2 < param_4) {
    iVar1 = param_2;
  }
  pbVar2 = param_1 + iVar1;
  iVar1 = 0;
  while( true ) {
    if (iVar1 != 0) {
      return iVar1;
    }
    if (pbVar2 <= param_1) break;
    iVar1 = (uint)*param_1 - (uint)*param_3;
    if (iVar1 != 0) {
      if ((*param_1 - 0x61 & 0xff) < 0x1a) {
        iVar1 = iVar1 + -0x20;
      }
      if ((*param_3 - 0x61 & 0xff) < 0x1a) {
        iVar1 = iVar1 + 0x20;
      }
    }
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
  }
  return param_2 - param_4;
}



/* Function: FUN_00013958 @ 00013958 */

void FUN_00013958(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00013844();
  FUN_000138ec(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_00013998 @ 00013998 */

void FUN_00013998(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_4;
  uVar1 = FUN_00013844();
  uVar2 = param_4;
  if ((int)(*param_1 & 0xfffffff) < (int)param_4) {
    uVar2 = *param_1 & 0xfffffff;
  }
  if ((int)param_3 < (int)param_4) {
    param_4 = param_3;
  }
  FUN_000138ec(uVar1,uVar2,param_2,param_4,uVar3);
  return;
}



/* Function: FUN_000139c4 @ 000139c4 */

void FUN_000139c4(uint *param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (*param_1 & 0xfffffff) - param_2;
  iVar1 = FUN_00013844();
  iVar2 = param_5;
  if (iVar3 < param_5) {
    iVar2 = iVar3;
  }
  if (param_4 < param_5) {
    param_5 = param_4;
  }
  FUN_000138ec(iVar1 + param_2,iVar2,param_3,param_5);
  return;
}



/* Function: FUN_000139f8 @ 000139f8 */

void FUN_000139f8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00013844();
  FUN_00013914(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_00013a14 @ 00013a14 */

void FUN_00013a14(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_4;
  iVar1 = FUN_00013844();
  FUN_00013914(iVar1 + param_2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,uVar2);
  return;
}



/* Function: FUN_00013a38 @ 00013a38 */

void FUN_00013a38(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_4;
  uVar1 = FUN_00013844();
  uVar2 = param_4;
  if ((int)(*param_1 & 0xfffffff) < (int)param_4) {
    uVar2 = *param_1 & 0xfffffff;
  }
  if ((int)param_3 < (int)param_4) {
    param_4 = param_3;
  }
  FUN_00013914(uVar1,uVar2,param_2,param_4,uVar3);
  return;
}



/* Function: FUN_00013a64 @ 00013a64 */

bool FUN_00013a64(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (*param_1 & 0xfffffff) - param_3;
  bVar3 = false;
  if (0 < iVar2) {
    iVar1 = FUN_00013844();
    iVar2 = FUN_000138ec(iVar1 + iVar2,param_3,param_2,param_3);
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}



/* Function: FUN_00013abc @ 00013abc */

int FUN_00013abc(uint *param_1,int param_2,int param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_00013844();
  do {
    iVar4 = 0;
    do {
      iVar3 = iVar4 + param_4;
      if ((int)(*param_1 & 0xfffffff) <= iVar3) {
        if (iVar4 != param_3) {
          param_4 = -1;
        }
        return param_4;
      }
      if (iVar4 == param_3) {
        return param_4;
      }
      pcVar1 = (char *)(param_2 + iVar4);
      iVar4 = iVar4 + 1;
    } while (*(char *)(iVar2 + iVar3) == *pcVar1);
    param_4 = param_4 + 1;
  } while( true );
}



/* Function: FUN_00013af8 @ 00013af8 */

int FUN_00013af8(uint *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  iVar1 = FUN_00013844();
  do {
    iVar4 = 0;
    do {
      if ((int)(*param_1 & 0xfffffff) <= iVar4 + param_4) {
        if (iVar4 != param_3) {
          param_4 = -1;
        }
        return param_4;
      }
      if (iVar4 == param_3) {
        return param_4;
      }
      cVar2 = *(char *)(iVar1 + iVar4 + param_4);
      cVar3 = *(char *)(param_2 + iVar4);
      if ((byte)(cVar2 + 0xbfU) < 0x1a) {
        cVar2 = cVar2 + ' ';
      }
      if ((byte)(cVar3 + 0xbfU) < 0x1a) {
        cVar3 = cVar3 + ' ';
      }
      iVar4 = iVar4 + 1;
    } while (cVar2 == cVar3);
    param_4 = param_4 + 1;
  } while( true );
}



/* Function: FUN_00013b9c @ 00013b9c */

uint * FUN_00013b9c(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  
  if ((param_3 == 0xffffffff) || ((int)(*param_2 & 0xfffffff) < (int)param_3)) {
    param_3 = *param_2 & 0xfffffff;
  }
  uVar1 = FUN_00013844(param_2);
  *param_1 = param_3 | 0x10000000;
  param_1[1] = uVar1;
  return param_1;
}



/* Function: FUN_00013bcc @ 00013bcc */

uint * FUN_00013bcc(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_3 == 0xffffffff) || ((int)(*param_2 & 0xfffffff) < (int)param_3)) {
    param_3 = *param_2 & 0xfffffff;
  }
  iVar1 = FUN_00013844(param_2);
  uVar2 = *param_2;
  *param_1 = param_3 | 0x10000000;
  param_1[1] = iVar1 + ((uVar2 & 0xfffffff) - param_3);
  return param_1;
}



/* Function: FUN_00013c08 @ 00013c08 */

int FUN_00013c08(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00013844();
  return iVar1 + param_2;
}



/* Function: FUN_00013c14 @ 00013c14 */

int FUN_00013c14(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00013844();
  return iVar1 + param_2;
}



/* Function: FUN_00013c3c @ 00013c3c */

void FUN_00013c3c(uint *param_1,undefined1 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00013844();
  for (iVar2 = 0; iVar2 < (int)param_3; iVar2 = iVar2 + 1) {
    *(undefined1 *)(iVar1 + iVar2) = param_2;
  }
  *param_1 = param_3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00013c60 @ 00013c60 */

void FUN_00013c60(uint *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1 & 0xfffffff;
  uVar3 = param_3 + uVar2;
  iVar1 = FUN_00013844();
  for (; (int)uVar2 < (int)uVar3; uVar2 = uVar2 + 1) {
    *(undefined1 *)(iVar1 + uVar2) = param_2;
  }
  *param_1 = uVar3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00013c8c @ 00013c8c */

void FUN_00013c8c(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1;
  if ((uVar2 & 0xfffffff) != 0) {
    iVar1 = FUN_00013844();
    uVar2 = uVar2 & 0xfffffff;
    do {
      uVar3 = uVar2 - 1;
      if ((4 < *(byte *)(iVar1 + uVar3) - 9) && (*(byte *)(iVar1 + uVar3) != 0x20)) break;
      *(undefined1 *)(iVar1 + uVar3) = 0;
      uVar2 = uVar3;
    } while (0 < (int)uVar3);
    *param_1 = uVar2 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_00013ccc @ 00013ccc */

void FUN_00013ccc(uint *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_1;
  if ((uVar5 & 0xfffffff) != 0) {
    iVar2 = FUN_00013844();
    uVar3 = 0;
    uVar4 = 0;
    do {
      bVar1 = *(byte *)(iVar2 + uVar3);
      if ((4 < bVar1 - 9) && (bVar1 != 0x20)) {
        if (uVar3 != uVar4) {
          *(byte *)(iVar2 + uVar4) = bVar1;
        }
        uVar4 = uVar4 + 1;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < (int)(uVar5 & 0xfffffff));
    *param_1 = uVar4 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_00013d0c @ 00013d0c */

void FUN_00013d0c(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_00013844();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((byte)(*(char *)(iVar1 + iVar3) + 0xbfU) < 0x1a) {
      *(char *)(iVar1 + iVar3) = *(char *)(iVar1 + iVar3) + ' ';
    }
  }
  return;
}



/* Function: FUN_00013d38 @ 00013d38 */

void FUN_00013d38(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_00013844();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((byte)(*(char *)(iVar1 + iVar3) + 0xbfU) < 0x1a) {
      *(char *)(iVar1 + iVar3) = *(char *)(iVar1 + iVar3) + -0x20;
    }
  }
  return;
}



/* Function: FUN_00013d64 @ 00013d64 */

void FUN_00013d64(uint *param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_00013844();
  *(undefined1 *)(iVar1 + (uVar2 & 0xfffffff)) = param_2;
  *param_1 = (uVar2 & 0xfffffff) + 1 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00013ecc @ 00013ecc */

void FUN_00013ecc(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar1;
  uVar1 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar1;
  uVar1 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar1;
  return;
}



/* Function: FUN_00013efc @ 00013efc */

undefined4 FUN_00013efc(uint *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 >> 0x1c < 6) {
                    /* WARNING: Could not emulate address calculation at 0x00013f0c */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((*param_1 >> 0x1c) * 4 + DAT_00013f28 + 0x13f0e) +
                      DAT_00013f28 + 0x13f0e))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_00013f2c @ 00013f2c */

int FUN_00013f2c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00013efc();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_00013f3c @ 00013f3c */

int FUN_00013f3c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00013efc();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_00013f4c @ 00013f4c */

int FUN_00013f4c(ushort *param_1,int param_2,ushort *param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = param_4;
  if (param_2 < param_4) {
    iVar3 = param_2;
  }
  puVar4 = param_1 + iVar3;
  iVar3 = 0;
  while( true ) {
    if (iVar3 != 0) {
      return iVar3;
    }
    if (puVar4 <= param_1) break;
    uVar1 = *param_1;
    uVar2 = *param_3;
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
    iVar3 = (uint)uVar1 - (uint)uVar2;
  }
  return param_2 - param_4;
}



/* Function: FUN_00013f74 @ 00013f74 */

int FUN_00013f74(ushort *param_1,int param_2,ushort *param_3,int param_4)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = param_4;
  if (param_2 < param_4) {
    iVar1 = param_2;
  }
  puVar2 = param_1 + iVar1;
  iVar1 = 0;
  while( true ) {
    if (iVar1 != 0) {
      return iVar1;
    }
    if (puVar2 <= param_1) break;
    iVar1 = (uint)*param_1 - (uint)*param_3;
    if (iVar1 != 0) {
      if ((*param_1 - 0x61 & 0xffff) < 0x1a) {
        iVar1 = iVar1 + -0x20;
      }
      if ((*param_3 - 0x61 & 0xffff) < 0x1a) {
        iVar1 = iVar1 + 0x20;
      }
    }
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
  }
  return param_2 - param_4;
}



/* Function: FUN_00013fb8 @ 00013fb8 */

void FUN_00013fb8(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00013efc();
  FUN_00013f4c(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_0001405c @ 0001405c */

void FUN_0001405c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00013efc();
  FUN_00013f74(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_00014078 @ 00014078 */

void FUN_00014078(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_4;
  iVar1 = FUN_00013efc();
  FUN_00013f74(iVar1 + param_2 * 2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,uVar2);
  return;
}



/* Function: FUN_000140f8 @ 000140f8 */

int FUN_000140f8(uint *param_1,short *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = FUN_00013efc();
  psVar3 = (short *)(iVar2 + param_3 * 2);
  while( true ) {
    if ((int)(*param_1 & 0xfffffff) <= param_3) {
      return -1;
    }
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
    if (*param_2 == sVar1) break;
    param_3 = param_3 + 1;
  }
  return param_3;
}



/* Function: FUN_00014128 @ 00014128 */

int FUN_00014128(uint *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_00013efc();
  do {
    iVar4 = 0;
    do {
      iVar3 = iVar4 + param_4;
      if ((int)(*param_1 & 0xfffffff) <= iVar3) {
        if (iVar4 != param_3) {
          param_4 = -1;
        }
        return param_4;
      }
      if (iVar4 == param_3) {
        return param_4;
      }
      iVar2 = iVar4 * 2;
      iVar4 = iVar4 + 1;
    } while (*(short *)(iVar3 * 2 + iVar1) == *(short *)(iVar2 + param_2));
    param_4 = param_4 + 1;
  } while( true );
}



/* Function: FUN_00014240 @ 00014240 */

uint * FUN_00014240(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_3 == 0xffffffff) || ((int)(*param_2 & 0xfffffff) < (int)param_3)) {
    param_3 = *param_2 & 0xfffffff;
  }
  iVar1 = FUN_00013efc(param_2);
  uVar2 = *param_2;
  *param_1 = param_3 | 0x10000000;
  param_1[1] = iVar1 + ((uVar2 & 0xfffffff) - param_3) * 2;
  return param_1;
}



/* Function: FUN_0001427c @ 0001427c */

int FUN_0001427c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00013efc();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_0001428c @ 0001428c */

int FUN_0001428c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00013efc();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_0001429c @ 0001429c */

void FUN_0001429c(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (0 < iVar3) {
    iVar1 = FUN_00013efc();
    iVar2 = 0;
    do {
      *(undefined2 *)(iVar1 + iVar2) = param_2;
      iVar2 = iVar2 + 2;
    } while (iVar2 != iVar3 * 2);
  }
  return;
}



/* Function: FUN_000142b8 @ 000142b8 */

void FUN_000142b8(uint *param_1,undefined2 param_2,uint param_3)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = (undefined2 *)FUN_00013efc();
  for (iVar2 = 0; iVar2 < (int)param_3; iVar2 = iVar2 + 1) {
    *puVar1 = param_2;
    puVar1 = puVar1 + 1;
  }
  *param_1 = param_3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_000142e0 @ 000142e0 */

void FUN_000142e0(uint *param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_1;
  iVar1 = FUN_00013efc();
  uVar3 = uVar3 & 0xfffffff;
  puVar2 = (undefined2 *)(iVar1 + uVar3 * 2);
  uVar4 = param_3 + uVar3;
  for (; (int)uVar3 < (int)uVar4; uVar3 = uVar3 + 1) {
    *puVar2 = param_2;
    puVar2 = puVar2 + 1;
  }
  *param_1 = uVar4 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00014310 @ 00014310 */

void FUN_00014310(uint *param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  
  uVar4 = *param_1 & 0xfffffff;
  if (uVar4 != 0) {
    iVar1 = FUN_00013efc();
    puVar2 = (ushort *)(iVar1 + (uVar4 - 1) * 2);
    puVar3 = puVar2;
    do {
      if ((4 < *puVar2 - 9) && (*puVar2 != 0x20)) break;
      uVar4 = uVar4 - 1;
      *puVar3 = 0;
      puVar2 = puVar2 + -1;
      puVar3 = puVar3 + -1;
    } while (0 < (int)uVar4);
    *param_1 = uVar4 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_00014354 @ 00014354 */

void FUN_00014354(uint *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_1;
  if ((uVar5 & 0xfffffff) != 0) {
    iVar2 = FUN_00013efc();
    uVar3 = 0;
    uVar4 = 0;
    do {
      uVar1 = *(ushort *)(iVar2 + uVar3 * 2);
      if ((4 < uVar1 - 9) && (uVar1 != 0x20)) {
        if (uVar3 != uVar4) {
          *(ushort *)(uVar4 * 2 + iVar2) = uVar1;
        }
        uVar4 = uVar4 + 1;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < (int)(uVar5 & 0xfffffff));
    *param_1 = uVar4 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_00014398 @ 00014398 */

void FUN_00014398(uint *param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  psVar1 = (short *)FUN_00013efc();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((ushort)(*psVar1 - 0x41U) < 0x1a) {
      *psVar1 = *psVar1 + 0x20;
    }
    psVar1 = psVar1 + 1;
  }
  return;
}



/* Function: FUN_000143c8 @ 000143c8 */

void FUN_000143c8(uint *param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  psVar1 = (short *)FUN_00013efc();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((ushort)(*psVar1 - 0x41U) < 0x1a) {
      *psVar1 = *psVar1 + -0x20;
    }
    psVar1 = psVar1 + 1;
  }
  return;
}



/* Function: FUN_000143f8 @ 000143f8 */

void FUN_000143f8(uint *param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_00013efc();
  *(undefined2 *)((uVar2 & 0xfffffff) * 2 + iVar1) = param_2;
  *param_1 = (uVar2 & 0xfffffff) + 1 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00014564 @ 00014564 */

void FUN_00014564(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar1;
  uVar1 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = uVar1;
  uVar1 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = uVar1;
  return;
}



/* Function: FUN_00014594 @ 00014594 */

void FUN_00014594(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00013efc(param_2);
  (**(code **)(*param_1 + 0x28c))(param_1,uVar1,*param_2 & 0xfffffff);
  return;
}



/* Function: FUN_000145b8 @ 000145b8 */

undefined4 FUN_000145b8(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,param_2,0);
  iVar2 = (**(code **)(*param_1 + 0x3c))(param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_00013488(iVar1);
    if (iVar2 < param_4) {
      FUN_000134dc(param_3,iVar1);
    }
    else {
      for (iVar2 = 0; iVar2 < param_4 + -1; iVar2 = iVar2 + 1) {
        *(undefined1 *)(param_3 + iVar2) = *(undefined1 *)(iVar1 + iVar2);
      }
      *(undefined1 *)(param_3 + param_4 + -1) = 0;
    }
    (**(code **)(*param_1 + 0x2a8))(param_1,param_2,iVar1);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}



/* Function: FUN_00014628 @ 00014628 */

void FUN_00014628(uint *param_1,void *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < param_3) {
    uVar2 = param_1[1];
    uVar3 = *param_1;
    iVar1 = FUN_00013efc();
    memcpy((void *)(iVar1 + (uVar3 & 0xfffffff) * 2),param_2,param_3 * 2);
    uVar3 = param_3 + (uVar3 & 0xfffffff);
    *param_1 = *param_1 & 0xf0000000 | uVar3;
    if ((int)uVar3 < (int)uVar2) {
      *(undefined2 *)(uVar3 * 2 + iVar1) = 0;
    }
  }
  return;
}



/* Function: FUN_0001466c @ 0001466c */

void FUN_0001466c(uint *param_1,void *param_2,uint param_3)

{
  void *__dest;
  uint uVar1;
  
  *param_1 = *param_1 & 0xf0000000;
  if (0 < (int)param_3) {
    uVar1 = param_1[1];
    __dest = (void *)FUN_00013efc();
    memcpy(__dest,param_2,param_3 * 2);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar1) {
      *(undefined2 *)((int)__dest + param_3 * 2) = 0;
    }
  }
  return;
}



/* Function: FUN_000146b0 @ 000146b0 */

void FUN_000146b0(uint *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < (int)param_3) {
    uVar2 = param_1[1];
    uVar3 = *param_1;
    iVar1 = FUN_00013844();
    memcpy((void *)(iVar1 + (uVar3 & 0xfffffff)),param_2,param_3);
    uVar3 = param_3 + (uVar3 & 0xfffffff);
    *param_1 = *param_1 & 0xf0000000 | uVar3;
    if ((int)uVar3 < (int)uVar2) {
      *(undefined1 *)(iVar1 + uVar3) = 0;
    }
  }
  return;
}



/* Function: FUN_000146f0 @ 000146f0 */

void FUN_000146f0(uint *param_1,void *param_2,uint param_3)

{
  void *__dest;
  uint uVar1;
  
  *param_1 = *param_1 & 0xf0000000;
  if (0 < (int)param_3) {
    uVar1 = param_1[1];
    __dest = (void *)FUN_00013844();
    memcpy(__dest,param_2,param_3);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar1) {
      *(undefined1 *)((int)__dest + param_3) = 0;
    }
  }
  return;
}



/* Function: FUN_00014730 @ 00014730 */

void * FUN_00014730(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  *(undefined1 *)((int)param_1 + param_3) = 0;
  return param_1;
}



/* Function: FUN_00014744 @ 00014744 */

undefined4 FUN_00014744(uint *param_1,int param_2)

{
  undefined4 uVar1;
  void *__dest;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((int)param_1[1] <= param_2) {
    uVar3 = param_2 + 2U & 0xfffffffe;
    __dest = (void *)FUN_00019c88(uVar3 << 1);
    uVar2 = *param_1;
    if (__dest == (void *)0x0) {
      uVar1 = 0xfffffffc;
    }
    else {
      if ((void *)param_1[2] != (void *)0x0) {
        memcpy(__dest,(void *)param_1[2],(uVar2 & 0xfffffff) << 1);
        if ((*param_1 >> 0x1c == 5) && (param_1[2] != 0)) {
          FUN_00019c68();
        }
      }
      param_1[2] = (uint)__dest;
      *param_1 = uVar2 & 0xfffffff | 0x50000000;
      param_1[1] = uVar3;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* Function: FUN_0001479c @ 0001479c */

int FUN_0001479c(uint *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00014744(param_1,(*param_1 & 0xfffffff) + 1);
  if (iVar1 == 0) {
    FUN_000143f8(param_1,param_2);
  }
  return iVar1;
}



/* Function: FUN_000147c0 @ 000147c0 */

int FUN_000147c0(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00014744(param_1,param_3 + (*param_1 & 0xfffffff),param_3,param_4,param_4);
    if (iVar1 == 0) {
      FUN_00014628(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_000147f0 @ 000147f0 */

int FUN_000147f0(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  *param_1 = uVar2 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00014744(param_1,param_3,param_3,uVar2 & 0xf0000000,param_4);
    if (iVar1 == 0) {
      FUN_0001466c(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00014824 @ 00014824 */

undefined4 FUN_00014824(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x294))(param_1,*param_2);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffc;
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x290))(param_1,*param_2);
    uVar2 = FUN_000147f0(param_3,iVar1,uVar2);
    (**(code **)(*param_1 + 0x298))(param_1,*param_2,iVar1);
  }
  return uVar2;
}



/* Function: FUN_00014880 @ 00014880 */

undefined4 FUN_00014880(uint *param_1,void *param_2,uint param_3)

{
  void *__dest;
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_1 >> 0x1c;
  if (uVar2 == 3) {
    uVar2 = param_1[1];
    if ((int)uVar2 < (int)param_3) {
      return 0xfffffffa;
    }
    __dest = (void *)FUN_00013efc();
    memcpy(__dest,param_2,param_3 * 2);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar2) {
      *(undefined2 *)((int)__dest + param_3 * 2) = 0;
    }
  }
  else if ((uVar2 == 5) || (uVar2 == 2)) {
    uVar1 = FUN_000147f0(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}



/* Function: FUN_000148e4 @ 000148e4 */

undefined4 * FUN_000148e4(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0x20000000;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = FUN_00013efc(param_2);
  FUN_000147f0(param_1,uVar1,*param_2 & 0xfffffff);
  return param_1;
}



/* Function: FUN_0001493c @ 0001493c */

void FUN_0001493c(uint *param_1)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_00019c68();
    }
  }
  param_1[2] = 0;
  *param_1 = 0x20000000;
  param_1[1] = 0;
  return;
}



/* Function: FUN_00014964 @ 00014964 */

void FUN_00014964(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_00019c68();
    }
  }
  param_1[2] = param_2;
  *param_1 = param_3 | 0x20000000;
  param_1[1] = param_4;
  return;
}



/* Function: FUN_00014994 @ 00014994 */

void FUN_00014994(uint *param_1)

{
  if (*param_1 >> 0x1c == 4) {
    if (param_1[1] != 0) {
      FUN_00019c68();
      param_1[1] = 0;
    }
    *param_1 = 0x10000000;
  }
  else if (*param_1 >> 0x1c == 5) {
    if (param_1[2] != 0) {
      FUN_00019c68();
      param_1[2] = 0;
    }
    *param_1 = 0x20000000;
    param_1[1] = 0;
  }
  return;
}



/* Function: FUN_000149d8 @ 000149d8 */

undefined4 FUN_000149d8(undefined4 param_1)

{
  FUN_00014994();
  return param_1;
}



/* Function: FUN_000149e4 @ 000149e4 */

undefined4 FUN_000149e4(undefined4 param_1)

{
  FUN_00014994();
  return param_1;
}



/* Function: FUN_00014a1c @ 00014a1c */

undefined4 FUN_00014a1c(undefined4 param_1)

{
  FUN_00014994();
  FUN_00014994(param_1);
  return param_1;
}



/* Function: FUN_00014a30 @ 00014a30 */

undefined4 FUN_00014a30(undefined4 param_1)

{
  FUN_0001493c();
  FUN_00014a1c(param_1);
  return param_1;
}



/* Function: FUN_00014a44 @ 00014a44 */

undefined4 FUN_00014a44(undefined4 param_1)

{
  FUN_0001493c();
  FUN_00014a1c(param_1);
  return param_1;
}



/* Function: FUN_00014a58 @ 00014a58 */

undefined4 FUN_00014a58(undefined4 param_1)

{
  FUN_00014a1c();
  return param_1;
}



/* Function: FUN_00014a64 @ 00014a64 */

undefined4 FUN_00014a64(undefined4 param_1)

{
  FUN_00014a1c();
  return param_1;
}



/* Function: FUN_00014b7c @ 00014b7c */

undefined4 FUN_00014b7c(uint *param_1,int param_2)

{
  undefined4 uVar1;
  void *__dest;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((int)param_1[1] <= param_2) {
    uVar3 = param_2 + 4U & 0xfffffffc;
    __dest = (void *)FUN_00019c88(uVar3);
    uVar2 = *param_1;
    if (__dest == (void *)0x0) {
      uVar1 = 0xfffffffc;
    }
    else {
      if ((void *)param_1[2] != (void *)0x0) {
        memcpy(__dest,(void *)param_1[2],uVar2 & 0xfffffff);
        if ((*param_1 >> 0x1c == 5) && (param_1[2] != 0)) {
          FUN_00019c68();
        }
      }
      param_1[2] = (uint)__dest;
      *param_1 = uVar2 & 0xfffffff | 0x50000000;
      param_1[1] = uVar3;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* Function: FUN_00014bd4 @ 00014bd4 */

int FUN_00014bd4(uint *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00014b7c(param_1,(*param_1 & 0xfffffff) + 1);
  if (iVar1 == 0) {
    FUN_00013d64(param_1,param_2);
  }
  return iVar1;
}



/* Function: FUN_00014bf8 @ 00014bf8 */

int FUN_00014bf8(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00014b7c(param_1,param_3 + (*param_1 & 0xfffffff),param_3,param_4,param_4);
    if (iVar1 == 0) {
      FUN_000146b0(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00014c28 @ 00014c28 */

int FUN_00014c28(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  *param_1 = uVar2 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00014b7c(param_1,param_3,param_3,uVar2 & 0xf0000000,param_4);
    if (iVar1 == 0) {
      FUN_000146f0(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00014c5c @ 00014c5c */

undefined4 FUN_00014c5c(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,*param_2);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffc;
  }
  else {
    uVar2 = FUN_00013488(iVar1);
    uVar2 = FUN_00014c28(param_3,iVar1,uVar2);
    (**(code **)(*param_1 + 0x2a8))(param_1,*param_2,iVar1);
  }
  return uVar2;
}



/* Function: FUN_00014cb0 @ 00014cb0 */

undefined4 FUN_00014cb0(uint *param_1,void *param_2,uint param_3)

{
  void *__dest;
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_1 >> 0x1c;
  if (uVar2 == 3) {
    uVar2 = param_1[1];
    if ((int)uVar2 < (int)param_3) {
      return 0xfffffffa;
    }
    __dest = (void *)FUN_00013844();
    memcpy(__dest,param_2,param_3);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar2) {
      *(undefined1 *)((int)__dest + param_3) = 0;
    }
  }
  else if ((uVar2 == 5) || (uVar2 == 2)) {
    uVar1 = FUN_00014c28(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}



/* Function: FUN_00014d10 @ 00014d10 */

void FUN_00014d10(uint *param_1)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_00019c68();
    }
  }
  param_1[2] = 0;
  *param_1 = 0x20000000;
  param_1[1] = 0;
  return;
}



/* Function: FUN_00014d38 @ 00014d38 */

void FUN_00014d38(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_00019c68();
    }
  }
  param_1[2] = param_2;
  *param_1 = param_3 | 0x20000000;
  param_1[1] = param_4;
  return;
}



/* Function: FUN_00014d68 @ 00014d68 */

void FUN_00014d68(uint *param_1)

{
  if (*param_1 >> 0x1c == 4) {
    if (param_1[1] != 0) {
      FUN_00019c68();
      param_1[1] = 0;
    }
    *param_1 = 0x10000000;
  }
  else if (*param_1 >> 0x1c == 5) {
    if (param_1[2] != 0) {
      FUN_00019c68();
      param_1[2] = 0;
    }
    *param_1 = 0x20000000;
    param_1[1] = 0;
  }
  return;
}



/* Function: FUN_00014dac @ 00014dac */

undefined4 FUN_00014dac(undefined4 param_1)

{
  FUN_00014d68();
  return param_1;
}



/* Function: FUN_00014db8 @ 00014db8 */

undefined4 FUN_00014db8(undefined4 param_1)

{
  FUN_00014d68();
  return param_1;
}



/* Function: FUN_00014df0 @ 00014df0 */

undefined4 FUN_00014df0(undefined4 param_1)

{
  FUN_00014d68();
  FUN_00014d68(param_1);
  return param_1;
}



/* Function: FUN_00014e04 @ 00014e04 */

undefined4 FUN_00014e04(undefined4 param_1)

{
  FUN_00014d10();
  FUN_00014df0(param_1);
  return param_1;
}



/* Function: FUN_00014e18 @ 00014e18 */

undefined4 FUN_00014e18(undefined4 param_1)

{
  FUN_00014d10();
  FUN_00014df0(param_1);
  return param_1;
}



/* Function: FUN_00014e2c @ 00014e2c */

undefined4 FUN_00014e2c(undefined4 param_1)

{
  FUN_00014df0();
  return param_1;
}



/* Function: FUN_00014e38 @ 00014e38 */

undefined4 FUN_00014e38(undefined4 param_1)

{
  FUN_00014df0();
  return param_1;
}



/* Function: FUN_00014f64 @ 00014f64 */

void FUN_00014f64(uint *param_1)

{
  ushort *__dest;
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  
  uVar3 = *param_1 & 0xfffffff;
  if (uVar3 != 0) {
    __dest = (ushort *)FUN_00013efc();
    iVar1 = 0;
    puVar2 = __dest;
    do {
      if ((4 < *puVar2 - 9) && (*puVar2 != 0x20)) {
        if (iVar1 == 0) {
          return;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar1 < (int)uVar3);
    uVar3 = uVar3 - iVar1;
    memmove(__dest,__dest + iVar1,uVar3 * 2);
    *param_1 = uVar3 | *param_1 & 0xf0000000;
    __dest[uVar3] = 0;
  }
  return;
}



/* Function: FUN_00014fb8 @ 00014fb8 */

void FUN_00014fb8(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *param_1;
  iVar3 = (uVar2 & 0xfffffff) - param_2;
  if (iVar3 < param_3) {
    param_3 = iVar3;
  }
  iVar1 = FUN_00013efc(param_1);
  memmove((void *)(iVar1 + param_2 * 2),(void *)(iVar1 + (param_3 + param_2) * 2),
          (iVar3 - param_3) * 2);
  *param_1 = (uVar2 & 0xfffffff) - param_3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015000 @ 00015000 */

void FUN_00015000(uint *param_1,int param_2,int param_3,void *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < param_5) {
    uVar2 = param_1[1];
    iVar1 = FUN_00013efc();
    uVar3 = *param_1;
    memmove((void *)(iVar1 + (param_5 + param_2) * 2),(void *)(iVar1 + (param_3 + param_2) * 2),
            (((uVar3 & 0xfffffff) - param_2) - param_3) * 2);
    memcpy((void *)(iVar1 + param_2 * 2),param_4,param_5 << 1);
    uVar3 = ((uVar3 & 0xfffffff) - param_3) + param_5;
    *param_1 = *param_1 & 0xf0000000 | uVar3;
    if ((int)uVar3 < (int)uVar2) {
      *(undefined2 *)(uVar3 * 2 + iVar1) = 0;
    }
  }
  return;
}



/* Function: FUN_00015070 @ 00015070 */

int FUN_00015070(uint *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = FUN_00014744(param_1,((*param_1 & 0xfffffff) - param_3) + param_5);
  if (((iVar1 == 0) && (param_4 != 0)) && (0 < param_5)) {
    FUN_00015000(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}



/* Function: FUN_000150ac @ 000150ac */

void FUN_000150ac(uint *param_1,int param_2,void *param_3,size_t param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *__src;
  
  if (0 < (int)param_4) {
    uVar2 = *param_1;
    uVar3 = param_1[1];
    iVar1 = FUN_00013efc();
    __src = (void *)(iVar1 + param_2 * 2);
    memmove((void *)(iVar1 + (param_4 + param_2) * 2),__src,(uVar2 & 0xfffffff) - param_2);
    memcpy(__src,param_3,param_4);
    uVar2 = param_4 + (uVar2 & 0xfffffff);
    *param_1 = *param_1 & 0xf0000000 | uVar2;
    if ((int)uVar2 < (int)uVar3) {
      *(undefined2 *)(uVar2 * 2 + iVar1) = 0;
    }
  }
  return;
}



/* Function: FUN_0001510c @ 0001510c */

int FUN_0001510c(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_4 < 1) || (param_3 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00014744(param_1,param_4 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_000150ac(param_1,param_2,param_3,param_4);
    }
  }
  return iVar1;
}



/* Function: FUN_00015144 @ 00015144 */

void FUN_00015144(uint *param_1)

{
  void *__dest;
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1 & 0xfffffff;
  if (uVar2 != 0) {
    __dest = (void *)FUN_00013844();
    iVar1 = 0;
    do {
      if ((4 < *(byte *)((int)__dest + iVar1) - 9) && (*(byte *)((int)__dest + iVar1) != 0x20)) {
        if (iVar1 == 0) {
          return;
        }
        break;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)uVar2);
    uVar2 = uVar2 - iVar1;
    memmove(__dest,(void *)((int)__dest + iVar1),uVar2);
    *param_1 = *param_1 & 0xf0000000 | uVar2;
    *(undefined1 *)((int)__dest + uVar2) = 0;
  }
  return;
}



/* Function: FUN_000151d0 @ 000151d0 */

void FUN_000151d0(uint *param_1,int param_2,int param_3,void *param_4,size_t param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < (int)param_5) {
    uVar2 = param_1[1];
    iVar1 = FUN_00013844();
    uVar3 = *param_1;
    memmove((void *)(iVar1 + param_5 + param_2),(void *)(iVar1 + param_3 + param_2),
            ((uVar3 & 0xfffffff) - param_2) - param_3);
    memcpy((void *)(iVar1 + param_2),param_4,param_5);
    uVar3 = ((uVar3 & 0xfffffff) - param_3) + param_5;
    *param_1 = *param_1 & 0xf0000000 | uVar3;
    if ((int)uVar3 < (int)uVar2) {
      *(undefined1 *)(iVar1 + uVar3) = 0;
    }
  }
  return;
}



/* Function: FUN_00015234 @ 00015234 */

int FUN_00015234(uint *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = FUN_00014b7c(param_1,((*param_1 & 0xfffffff) - param_3) + param_5);
  if (((iVar1 == 0) && (param_4 != 0)) && (0 < param_5)) {
    FUN_000151d0(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}



/* Function: FUN_00015270 @ 00015270 */

void FUN_00015270(uint *param_1,int param_2,void *param_3,size_t param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < (int)param_4) {
    uVar2 = *param_1;
    uVar3 = param_1[1];
    iVar1 = FUN_00013844();
    memmove((void *)(iVar1 + param_4 + param_2),(void *)(iVar1 + param_2),
            (uVar2 & 0xfffffff) - param_2);
    memcpy((void *)(iVar1 + param_2),param_3,param_4);
    uVar2 = param_4 + (uVar2 & 0xfffffff);
    *param_1 = *param_1 & 0xf0000000 | uVar2;
    if ((int)uVar2 < (int)uVar3) {
      *(undefined1 *)(iVar1 + uVar2) = 0;
    }
  }
  return;
}



/* Function: FUN_000152c8 @ 000152c8 */

int FUN_000152c8(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_4 < 1) || (param_3 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00014b7c(param_1,param_4 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_00015270(param_1,param_2,param_3,param_4);
    }
  }
  return iVar1;
}



/* Function: FUN_00015300 @ 00015300 */

void FUN_00015300(uint *param_1,uint param_2)

{
  void *__s;
  
  __s = (void *)FUN_00013efc();
  memset(__s,0,param_2 << 1);
  *param_1 = param_2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015320 @ 00015320 */

void FUN_00015320(int param_1)

{
  void *__s;
  
  __s = (void *)FUN_00013efc();
  memset(__s,0,*(int *)(param_1 + 4) << 1);
  return;
}



/* Function: FUN_00015334 @ 00015334 */

void FUN_00015334(uint *param_1,uint param_2)

{
  void *__s;
  
  __s = (void *)FUN_00013844();
  memset(__s,0,param_2);
  *param_1 = param_2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015354 @ 00015354 */

void FUN_00015354(int param_1)

{
  void *__s;
  
  __s = (void *)FUN_00013844();
  memset(__s,0,*(size_t *)(param_1 + 4));
  return;
}



/* Function: FUN_00015368 @ 00015368 */

void FUN_00015368(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 )

{
  int iVar1;
  
  iVar1 = FUN_00013efc();
  FUN_00018928(iVar1 + param_2 * 2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,param_5);
  return;
}



/* Function: FUN_00015490 @ 00015490 */

void * FUN_00015490(uint *param_1)

{
  void *__src;
  void *__dest;
  uint __n;
  
  __dest = (void *)0x0;
  __n = *param_1 & 0xfffffff;
  if ((__n != 0) && (__dest = malloc(__n + 1), __dest != (void *)0x0)) {
    __src = (void *)FUN_00013844(param_1);
    memcpy(__dest,__src,__n);
    *(undefined1 *)((int)__dest + __n) = 0;
  }
  return __dest;
}



/* Function: FUN_000154c4 @ 000154c4 */

void FUN_000154c4(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 )

{
  int iVar1;
  
  iVar1 = FUN_00013844();
  FUN_000192c8(iVar1 + param_2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,param_5);
  return;
}



/* Function: FUN_00015610 @ 00015610 */

int FUN_00015610(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = DAT_00015670;
  uVar4 = *param_1;
  iVar2 = FUN_00016388(param_2,param_3,0,0,DAT_00015670);
  uVar4 = uVar4 & 0xfffffff;
  iVar3 = FUN_00014b7c(param_1,iVar2 + uVar4);
  iVar2 = iVar3;
  if (iVar3 == 0) {
    iVar2 = FUN_00013844(param_1);
    iVar2 = FUN_00016388(param_2,param_3,iVar2 + uVar4,param_1[1] - uVar4,uVar1);
    if (-1 < iVar2) {
      *param_1 = iVar2 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
      iVar2 = iVar3;
    }
  }
  return iVar2;
}



/* Function: FUN_00015674 @ 00015674 */

int FUN_00015674(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  iVar1 = FUN_000166f8(param_3,param_4,0,0,param_2);
  uVar3 = uVar3 & 0xfffffff;
  iVar2 = FUN_00014b7c(param_1,iVar1 + uVar3);
  iVar1 = iVar2;
  if (iVar2 == 0) {
    iVar1 = FUN_00013844(param_1);
    iVar1 = FUN_000166f8(param_3,param_4,iVar1 + uVar3,param_1[1] - uVar3,param_2);
    if (-1 < iVar1) {
      *param_1 = iVar1 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



/* Function: FUN_00015778 @ 00015778 */

int FUN_00015778(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_00013844();
  iVar1 = FUN_000166f8(param_2,param_3,iVar1 + (uVar2 & 0xfffffff),param_1[1] - (uVar2 & 0xfffffff),
                       DAT_000157b8);
  if (-1 < iVar1) {
    *param_1 = iVar1 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
    iVar1 = 0;
  }
  return iVar1;
}



/* Function: FUN_000157bc @ 000157bc */

uint FUN_000157bc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  uVar1 = FUN_00013844();
  uVar2 = FUN_000166f8(param_2,param_3,uVar1,uVar2,DAT_000157f0);
  if (-1 < (int)uVar2) {
    *param_1 = uVar2 | *param_1 & 0xf0000000;
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_00015850 @ 00015850 */

int FUN_00015850(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_00013844();
  iVar1 = FUN_000165e8(param_2,param_3,iVar1 + (uVar2 & 0xfffffff),param_1[1] - (uVar2 & 0xfffffff),
                       param_4);
  if (-1 < iVar1) {
    *param_1 = iVar1 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
    iVar1 = 0;
  }
  return iVar1;
}



/* Function: FUN_00015888 @ 00015888 */

uint FUN_00015888(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  uVar1 = FUN_00013844();
  uVar2 = FUN_000165e8(param_2,param_3,uVar1,uVar2,param_4);
  if (-1 < (int)uVar2) {
    *param_1 = uVar2 | *param_1 & 0xf0000000;
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_000158ec @ 000158ec */

uint FUN_000158ec(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00013844();
  uVar2 = FUN_000131bc(uVar1,*param_1 & 0xfffffff,param_2,param_3,uVar1,param_1[1]);
  if (-1 < (int)uVar2) {
    *param_1 = uVar2 | *param_1 & 0xf0000000;
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_00015924 @ 00015924 */

void FUN_00015924(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00013efc();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_000162b8(param_2,param_3,iVar1 + uVar2 * 2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015954 @ 00015954 */

int FUN_00015954(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000162b8(param_2,param_3,0,0,param_4);
    iVar1 = FUN_00014744(param_1,iVar1 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_00015924(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00015994 @ 00015994 */

void FUN_00015994(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00013efc();
  uVar2 = FUN_000162b8(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_000159b8 @ 000159b8 */

int FUN_000159b8(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_000162b8(param_2,param_3,0,0,param_4);
    iVar2 = FUN_00014744(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_00015994(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_000159fc @ 000159fc */

void FUN_000159fc(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00013efc();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_0001688c(param_2,param_3,iVar1 + uVar2 * 2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015a2c @ 00015a2c */

int FUN_00015a2c(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0001688c(param_2,param_3,0,0,param_4);
    iVar1 = FUN_00014744(param_1,iVar1 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_000159fc(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00015a6c @ 00015a6c */

void FUN_00015a6c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00013efc();
  uVar2 = FUN_0001688c(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015a90 @ 00015a90 */

int FUN_00015a90(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_0001688c(param_2,param_3,0,0,param_4);
    iVar2 = FUN_00014744(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_00015a6c(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_00015ad4 @ 00015ad4 */

void FUN_00015ad4(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00013844();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_000162c0(param_2,param_3,iVar1 + uVar2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015b04 @ 00015b04 */

int FUN_00015b04(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000162c0(param_2,param_3,0,0,param_4);
    iVar1 = FUN_00014b7c(param_1,(*param_1 & 0xfffffff) * 2 + iVar1);
    if (iVar1 == 0) {
      FUN_00015ad4(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00015b44 @ 00015b44 */

void FUN_00015b44(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00013844();
  uVar2 = FUN_000162c0(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015b68 @ 00015b68 */

int FUN_00015b68(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_000162c0(param_2,param_3,0,0,param_4);
    iVar2 = FUN_00014b7c(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_00015b44(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_00015bac @ 00015bac */

void FUN_00015bac(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00013844();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_00016964(param_2,param_3,iVar1 + uVar2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015bdc @ 00015bdc */

int FUN_00015bdc(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00016964(param_2,param_3,0,0,param_4);
    iVar1 = FUN_00014b7c(param_1,(*param_1 & 0xfffffff) * 2 + iVar1);
    if (iVar1 == 0) {
      FUN_00015bac(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00015c1c @ 00015c1c */

void FUN_00015c1c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00013844();
  uVar2 = FUN_00016964(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00015c40 @ 00015c40 */

int FUN_00015c40(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_00016964(param_2,param_3,0,0,param_4);
    iVar2 = FUN_00014b7c(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_00015c1c(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_00015c84 @ 00015c84 */

int FUN_00015c84(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = 0;
  if ((0 < param_3) && (iVar1 = FUN_00017654(param_2,param_3,param_4), -1 < iVar1)) {
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_00014744(param_1,iVar1 + uVar2);
    if (-1 < iVar1) {
      iVar1 = FUN_00013efc(param_1);
      iVar1 = FUN_00016f30(iVar1 + uVar2 * 2,param_1[1] - uVar2,param_2,param_3,param_4);
      if (-1 < iVar1) {
        uVar2 = iVar1 + uVar2;
        iVar1 = 0;
        *param_1 = uVar2 | *param_1 & 0xf0000000;
      }
    }
  }
  return iVar1;
}



/* Function: FUN_00015dac @ 00015dac */

void FUN_00015dac(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (0 < param_3) {
    uVar2 = *param_1;
    iVar1 = FUN_00013efc();
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_00016f30(iVar1 + uVar2 * 2,param_1[1] - uVar2,param_2,param_3,param_4);
    *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_00015eb0 @ 00015eb0 */

int FUN_00015eb0(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = 0;
  if ((0 < param_3) && (iVar1 = FUN_0001832c(param_2,param_3,param_4), -1 < iVar1)) {
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_00014b7c(param_1,iVar1 + uVar2);
    if (-1 < iVar1) {
      iVar1 = FUN_00013844(param_1);
      iVar1 = FUN_00017c00(iVar1 + uVar2,param_1[1] - uVar2,param_2,param_3,param_4);
      if (-1 < iVar1) {
        uVar2 = iVar1 + uVar2;
        iVar1 = 0;
        *param_1 = uVar2 | *param_1 & 0xf0000000;
      }
    }
  }
  return iVar1;
}



/* Function: FUN_00015fd8 @ 00015fd8 */

void FUN_00015fd8(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (0 < param_3) {
    uVar2 = *param_1;
    iVar1 = FUN_00013844();
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_00017c00(iVar1 + uVar2,param_1[1] - uVar2,param_2,param_3,param_4);
    *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_000160dc @ 000160dc */

undefined4 FUN_000160dc(byte *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  ushort auStack_50 [32];
  
  *param_3 = DAT_000161bc;
  uVar2 = (uint)*param_1;
  if ((int)(uVar2 * 0x1000000) < 0) {
    if (uVar2 < 0xa0) {
      memcpy(auStack_50,(void *)(DAT_000161c0 + 0x16100),0x40);
      *param_3 = (uint)auStack_50[uVar2 + DAT_000161c4];
    }
    else if (((0xc1 < uVar2) && (1 < param_2)) && (uVar1 = (uint)param_1[1], (uVar1 & 0xc0) == 0x80)
            ) {
      if (uVar2 < 0xe0) {
        *param_3 = (uVar1 & 0x3f) + (uVar2 & 0x1f) * 0x40;
        return 2;
      }
      if (uVar2 < 0xf0) {
        if ((((uVar2 != 0xe0) || (0x9f < uVar1)) && (param_2 != 2)) && ((param_1[2] & 0xc0) == 0x80)
           ) {
          *param_3 = (param_1[2] & 0x3f) + (uVar2 & 0xf) * 0x1000 + (uVar1 & 0x3f) * 0x40;
          return 3;
        }
      }
      else if (uVar2 < 0xf5) {
        if (uVar2 == 0xf0) {
          if (uVar1 < 0x90) {
            return 1;
          }
        }
        else if ((uVar2 == 0xf4) && (0x8f < uVar1)) {
          return 1;
        }
        if (((3 < param_2) && ((param_1[2] & 0xc0) == 0x80)) && ((param_1[3] & 0xc0) == 0x80)) {
          *param_3 = (param_1[3] & 0x3f) + (uVar2 & 7) * 0x40000 + (uVar1 & 0x3f) * 0x1000 +
                     (param_1[2] & 0x3f) * 0x40;
          return 4;
        }
      }
    }
  }
  else {
    *param_3 = uVar2;
  }
  return 1;
}



/* Function: FUN_000162b8 @ 000162b8 */

undefined4 FUN_000162b8(void)

{
  return 0xfffffffb;
}



/* Function: FUN_000162c0 @ 000162c0 */

undefined4 FUN_000162c0(void)

{
  return 0xfffffffb;
}



/* Function: FUN_000162c8 @ 000162c8 */

int FUN_000162c8(byte *param_1,int param_2,byte *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    if (param_2 == -1) {
      param_2 = FUN_00013488(param_1);
    }
    param_4 = param_4 & (param_3 == (byte *)0x0) - 1;
    iVar1 = 0;
    while (0 < param_2) {
      if (*param_1 == 0x3d) {
        iVar2 = param_2 + -1;
        pbVar5 = param_1 + 1;
        if ((iVar2 == 0) || ((*pbVar5 != 10 && (*pbVar5 != 0xd)))) {
          if (iVar1 < (int)param_4) {
            bVar4 = *pbVar5 - 0x30;
            if (9 < bVar4) {
              bVar4 = (*pbVar5 & 0xdf) - 0x37;
            }
            *param_3 = bVar4;
            bVar3 = param_1[2] - 0x30;
            if (9 < bVar3) {
              bVar3 = (param_1[2] & 0xdf) - 0x37;
            }
            *param_3 = bVar3 + bVar4 * '\x10';
            param_3 = param_3 + 1;
          }
          param_1 = param_1 + 3;
          param_2 = param_2 + -3;
          goto LAB_00016376;
        }
        do {
          iVar2 = iVar2 + -1;
          pbVar5 = pbVar5 + 1;
          if (iVar2 == 0) goto LAB_0001637c;
        } while ((*pbVar5 - 9 < 5) || (param_2 = iVar2, param_1 = pbVar5, *pbVar5 == 0x20));
      }
      else {
        if (iVar1 < (int)param_4) {
          *param_3 = *param_1;
          param_3 = param_3 + 1;
        }
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
LAB_00016376:
        iVar1 = iVar1 + 1;
      }
    }
LAB_0001637c:
    if (iVar1 < (int)param_4) {
      *param_3 = 0;
    }
  }
  return iVar1;
}



/* Function: FUN_00016388 @ 00016388 */

int FUN_00016388(int param_1,int param_2,char *param_3,uint param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  
  iVar2 = 0;
  if (param_1 != 0) {
    if (param_2 == -1) {
      param_2 = FUN_00013488(param_1);
    }
    param_4 = param_4 & (param_3 == (char *)0x0) - 1;
    iVar3 = 0;
    iVar2 = 0;
    for (iVar5 = 0; 0 < param_2 - iVar5; iVar5 = iVar5 + 1) {
      cVar1 = *(char *)(param_1 + iVar5);
      if ((((((byte)(cVar1 - 0x21U) < 0x5e) && (cVar1 != '=')) && (cVar1 != ';')) &&
          ((cVar1 != ':' && (cVar1 != '\\')))) &&
         ((cVar1 != '<' && ((cVar1 != '>' && (cVar1 != '/')))))) {
        if (iVar2 < (int)param_4) {
          *param_3 = cVar1;
          param_3 = param_3 + 1;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 1;
      }
      else {
        if (iVar2 + 2 < (int)param_4) {
          *param_3 = '=';
          bVar4 = *(byte *)(param_1 + iVar5) >> 4;
          bVar6 = bVar4 + 0x30;
          param_3[1] = bVar6;
          if (0x39 < bVar6) {
            param_3[1] = bVar4 + 0x37;
          }
          bVar4 = *(byte *)(param_1 + iVar5) & 0xf;
          bVar6 = bVar4 + 0x30;
          param_3[2] = bVar6;
          if (0x39 < bVar6) {
            param_3[2] = bVar4 + 0x37;
          }
          param_3 = param_3 + 3;
        }
        iVar2 = iVar2 + 3;
        iVar3 = iVar3 + 3;
      }
      if (param_5 <= iVar3) {
        if (iVar2 + 2 < (int)param_4) {
          param_3[1] = '\r';
          *param_3 = '=';
          param_3[2] = '\n';
          param_3 = param_3 + 3;
        }
        iVar2 = iVar2 + 3;
        iVar3 = 0;
      }
    }
    if (iVar2 < (int)param_4) {
      *param_3 = '\0';
    }
  }
  return iVar2;
}



/* Function: FUN_00016470 @ 00016470 */

int FUN_00016470(byte *param_1,int param_2,byte *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    if (param_2 == -1) {
      param_2 = FUN_00013488(param_1);
    }
    param_4 = param_4 & (param_3 == (byte *)0x0) - 1;
    iVar1 = 0;
    while (0 < param_2) {
      if (*param_1 == 0x25) {
        iVar2 = param_2 + -1;
        pbVar5 = param_1 + 1;
        if ((iVar2 == 0) || ((*pbVar5 != 10 && (*pbVar5 != 0xd)))) {
          if (iVar1 < (int)param_4) {
            bVar4 = *pbVar5 - 0x30;
            if (9 < bVar4) {
              bVar4 = (*pbVar5 & 0xdf) - 0x37;
            }
            *param_3 = bVar4;
            bVar3 = param_1[2] - 0x30;
            if (9 < bVar3) {
              bVar3 = (param_1[2] & 0xdf) - 0x37;
            }
            *param_3 = bVar3 + bVar4 * '\x10';
            param_3 = param_3 + 1;
          }
          param_1 = param_1 + 3;
          param_2 = param_2 + -3;
          goto LAB_0001651e;
        }
        do {
          iVar2 = iVar2 + -1;
          pbVar5 = pbVar5 + 1;
          if (iVar2 == 0) goto LAB_00016524;
        } while ((*pbVar5 - 9 < 5) || (param_2 = iVar2, param_1 = pbVar5, *pbVar5 == 0x20));
      }
      else {
        if (iVar1 < (int)param_4) {
          *param_3 = *param_1;
          param_3 = param_3 + 1;
        }
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
LAB_0001651e:
        iVar1 = iVar1 + 1;
      }
    }
LAB_00016524:
    if (iVar1 < (int)param_4) {
      *param_3 = 0;
    }
  }
  return iVar1;
}



/* Function: FUN_00016530 @ 00016530 */

int FUN_00016530(int param_1,int param_2,char *param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  
  iVar2 = 0;
  if (param_1 != 0) {
    if (param_2 == -1) {
      param_2 = FUN_00013488(param_1);
    }
    param_4 = param_4 & (param_3 == (char *)0x0) - 1;
    iVar2 = 0;
    for (iVar3 = 0; 0 < param_2 - iVar3; iVar3 = iVar3 + 1) {
      cVar1 = *(char *)(param_1 + iVar3);
      if ((((byte)(cVar1 + 0x9fU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) ||
         ((byte)(cVar1 + 0xbfU) < 0x1a)) {
        if (iVar2 < (int)param_4) {
          *param_3 = cVar1;
          param_3 = param_3 + 1;
        }
        iVar2 = iVar2 + 1;
      }
      else {
        if (iVar2 + 2 < (int)param_4) {
          *param_3 = '%';
          bVar4 = *(byte *)(param_1 + iVar3) >> 4;
          bVar5 = bVar4 + 0x30;
          param_3[1] = bVar5;
          if (0x39 < bVar5) {
            param_3[1] = bVar4 + 0x37;
          }
          bVar4 = *(byte *)(param_1 + iVar3) & 0xf;
          bVar5 = bVar4 + 0x30;
          param_3[2] = bVar5;
          if (0x39 < bVar5) {
            param_3[2] = bVar4 + 0x37;
          }
          param_3 = param_3 + 3;
        }
        iVar2 = iVar2 + 3;
      }
    }
    if (iVar2 < (int)param_4) {
      *param_3 = '\0';
    }
  }
  return iVar2;
}



/* Function: FUN_000165e8 @ 000165e8 */

int FUN_000165e8(int param_1,int param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_2c;
  
  iVar1 = 0;
  if (param_1 != 0) {
    if (param_2 == -1) {
      param_2 = FUN_00013488(param_1);
    }
    param_4 = param_4 & (param_3 == (undefined1 *)0x0) - 1;
    iVar1 = 0;
    iVar5 = 0;
LAB_000166e0:
    if (iVar5 < param_2) {
      iVar4 = 0;
      uVar3 = 0;
      while (iVar6 = iVar5, iVar4 < 4) {
        if (param_2 <= iVar5) {
LAB_00016696:
          if (iVar4 == 3) {
            if (iVar1 + 1 < (int)param_4) {
              *param_3 = (char)(uVar3 >> 10);
              param_3[1] = (char)(uVar3 >> 2);
              param_3 = param_3 + 2;
            }
            iVar1 = iVar1 + 2;
            iVar5 = iVar6;
            goto LAB_000166e0;
          }
          break;
        }
        uVar2 = (uint)*(byte *)(param_1 + iVar5);
        local_2c = uVar3;
        if ((4 < uVar2 - 9) && (uVar2 != 0x20)) {
          local_2c = uVar2 - 0x41;
          if ((0x19 < (local_2c & 0xff)) &&
             (((local_2c = uVar2 - 0x47, 0x19 < (uVar2 - 0x61 & 0xff) &&
               (local_2c = uVar2 + 4, 9 < (uVar2 - 0x30 & 0xff))) &&
              (local_2c = 0x3e, uVar2 != 0x2b)))) {
            iVar6 = param_2;
            if (uVar2 != 0x2f) goto LAB_00016696;
            local_2c = 0x3f;
          }
          if (iVar4 != 0) {
            local_2c = local_2c + uVar3 * 0x40;
          }
          iVar4 = iVar4 + 1;
        }
        iVar5 = iVar5 + 1;
        uVar3 = local_2c;
      }
      iVar5 = iVar6;
      if (iVar4 == 4) {
        if (iVar1 + 2 < (int)param_4) {
          *param_3 = (char)(uVar3 >> 0x10);
          param_3[1] = (char)(uVar3 >> 8);
          param_3[2] = (char)uVar3;
          param_3 = param_3 + 3;
        }
        iVar1 = iVar1 + 3;
      }
      else if (iVar4 == 2) {
        if (iVar1 < (int)param_4) {
          *param_3 = (char)(uVar3 >> 4);
          param_3 = param_3 + 1;
        }
        iVar1 = iVar1 + 1;
      }
      goto LAB_000166e0;
    }
    if (iVar1 < (int)param_4) {
      *param_3 = 0;
    }
  }
  return iVar1;
}



/* Function: FUN_000166f8 @ 000166f8 */

int FUN_000166f8(byte *param_1,int param_2,undefined1 *param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int local_2c;
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  if (param_2 == -1) {
    param_2 = FUN_00013488(param_1);
  }
  param_4 = param_4 & -(uint)(param_3 != (undefined1 *)0x0);
  FUN_00019d6c(param_2,3);
  iVar3 = 0;
  iVar4 = DAT_00016880 + 0x16744;
  iVar2 = 0;
  pbVar5 = param_1;
  for (local_2c = 0; local_2c < param_2 - extraout_r1; local_2c = local_2c + 3) {
    if (iVar2 + 3 < (int)param_4) {
      *param_3 = *(undefined1 *)(iVar4 + (uint)(*pbVar5 >> 2) + 0x40);
      param_3[1] = *(undefined1 *)(iVar4 + ((*pbVar5 & 3) << 4 | (int)(uint)pbVar5[1] >> 4) + 0x40);
      param_3[2] = *(undefined1 *)
                    (iVar4 + ((pbVar5[1] & 0xf) << 2 | (int)(uint)pbVar5[2] >> 6) + 0x40);
      param_3[3] = *(undefined1 *)(iVar4 + (pbVar5[2] & 0x3f) + 0x40);
      param_3 = param_3 + 4;
    }
    iVar3 = iVar3 + 4;
    iVar1 = iVar2 + 4;
    if ((param_5 <= iVar3) && (local_2c + 3 < param_2)) {
      if (iVar2 + 6 < (int)param_4) {
        *param_3 = 0xd;
        param_3[1] = 10;
        param_3[2] = 0x20;
        param_3 = param_3 + 3;
      }
      iVar1 = iVar2 + 7;
      iVar3 = 0;
    }
    pbVar5 = pbVar5 + 3;
    iVar2 = iVar1;
  }
  if (extraout_r1 == 1) {
    if (iVar2 + 3 < (int)param_4) {
      iVar3 = DAT_00016888 + 0x16852;
      *param_3 = *(undefined1 *)(iVar3 + (uint)(param_1[param_2 + -1] >> 2) + 0x40);
      param_3[1] = *(undefined1 *)(iVar3 + (param_1[param_2 + -1] & 3) * 0x10 + 0x40);
      param_3[2] = 0x3d;
LAB_0001686e:
      param_3[3] = 0x3d;
      param_3 = param_3 + 4;
    }
  }
  else {
    if (extraout_r1 != 2) goto LAB_00016874;
    if (iVar2 + 3 < (int)param_4) {
      iVar3 = DAT_00016884 + 0x16806;
      *param_3 = *(undefined1 *)(iVar3 + (uint)(param_1[param_2 + -2] >> 2) + 0x40);
      param_3[1] = *(undefined1 *)
                    (iVar3 + ((param_1[param_2 + -2] & 3) << 4 |
                             (int)(uint)param_1[param_2 + -1] >> 4) + 0x40);
      param_3[2] = *(undefined1 *)(iVar3 + (param_1[param_2 + -1] & 0xf) * 4 + 0x40);
      goto LAB_0001686e;
    }
  }
  iVar2 = iVar2 + 4;
LAB_00016874:
  if (iVar2 < (int)param_4) {
    *param_3 = 0;
  }
  return iVar2;
}



/* Function: FUN_0001688c @ 0001688c */

int FUN_0001688c(byte *param_1,int param_2,ushort *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint local_1c [2];
  
  if (param_2 == -1) {
    param_2 = FUN_00013488();
  }
  iVar3 = 0;
  param_4 = param_4 & (param_3 == (ushort *)0x0) - 1;
  while (0 < param_2) {
    bVar1 = *param_1;
    if ((int)((uint)bVar1 * 0x1000000) < 0) {
      iVar2 = FUN_000160dc(param_1,param_2,local_1c);
      param_1 = param_1 + iVar2;
      iVar2 = -iVar2;
    }
    else {
      param_1 = param_1 + 1;
      iVar2 = -1;
      local_1c[0] = (uint)bVar1;
    }
    param_2 = param_2 + iVar2;
    if (DAT_00016944 < local_1c[0]) {
      if (DAT_00016954 < local_1c[0]) {
        local_1c[0] = DAT_00016950;
      }
      else {
        if (iVar3 + 1 < (int)param_4) {
          *param_3 = (ushort)((local_1c[0] + DAT_00016958 & 0xfffff) >> 10) | (ushort)DAT_0001695c;
          param_3[1] = (ushort)local_1c[0] & 0x3ff | (ushort)DAT_00016960;
          param_3 = param_3 + 2;
        }
        iVar3 = iVar3 + 2;
      }
    }
    else {
      if (local_1c[0] + DAT_00016948 <= DAT_0001694c) {
        local_1c[0] = DAT_00016950;
      }
      if (iVar3 < (int)param_4) {
        *param_3 = (ushort)local_1c[0];
        param_3 = param_3 + 1;
      }
      iVar3 = iVar3 + 1;
    }
  }
  if (iVar3 < (int)param_4) {
    *param_3 = 0;
  }
  return iVar3;
}



/* Function: FUN_00016964 @ 00016964 */

void FUN_00016964(ushort *param_1,int param_2,byte *param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  if (param_2 == -1) {
    param_2 = FUN_0001361c();
  }
  param_4 = param_4 & (param_3 == (byte *)0x0) - 1;
  iVar2 = 0;
LAB_00016a8c:
  do {
    while( true ) {
      if (param_2 < 1) {
        if (iVar2 < (int)param_4) {
          *param_3 = 0;
        }
        return;
      }
      uVar4 = (uint)*param_1;
      puVar6 = param_1 + 1;
      iVar3 = param_2 + -1;
      if ((DAT_00016aa8 < DAT_00016aa4 + uVar4) || (iVar3 < 1)) break;
      uVar1 = *puVar6;
      uVar5 = uVar4;
      if (DAT_00016aac + (uint)uVar1 <= DAT_00016aa8) {
        puVar6 = param_1 + 2;
        iVar3 = param_2 + -2;
        uVar4 = (uVar4 & 0x3ff) * 0x400 + (uVar1 & 0x3ff) + 0x10000;
        uVar5 = DAT_00016abc;
        if (uVar4 <= DAT_00016ab0) break;
      }
LAB_00016a06:
      param_2 = iVar3;
      param_1 = puVar6;
      if (DAT_00016ab8 < uVar5) {
        if (iVar2 + 3 < (int)param_4) {
          *param_3 = (byte)(uVar5 >> 0x12) | 0xf0;
          param_3[1] = (byte)(uVar5 >> 0xc) & 0x3f | 0x80;
          param_3[2] = (byte)(uVar5 >> 6) & 0x3f | 0x80;
          param_3[3] = (byte)uVar5 & 0x3f | 0x80;
          param_3 = param_3 + 4;
        }
        iVar2 = iVar2 + 4;
      }
      else {
        if (iVar2 + 2 < (int)param_4) {
          *param_3 = (byte)(uVar5 >> 0xc) | 0xe0;
          param_3[1] = (byte)(uVar5 >> 6) & 0x3f | 0x80;
          param_3[2] = (byte)uVar5 & 0x3f | 0x80;
          param_3 = param_3 + 3;
        }
        iVar2 = iVar2 + 3;
      }
    }
    param_2 = iVar3;
    param_1 = puVar6;
    if (0x7f < uVar4) {
      uVar5 = uVar4;
      if (DAT_00016ab4 < uVar4) goto LAB_00016a06;
      if (iVar2 + 1 < (int)param_4) {
        *param_3 = (byte)(uVar4 >> 6) | 0xc0;
        param_3[1] = (byte)uVar4 & 0x3f | 0x80;
        param_3 = param_3 + 2;
      }
      iVar2 = iVar2 + 2;
      goto LAB_00016a8c;
    }
    if (iVar2 < (int)param_4) {
      *param_3 = (byte)uVar4;
      param_3 = param_3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}



/* Function: thunk_FUN_00016ac4 @ 00016ac0 */

void thunk_FUN_00016ac4(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  for (; *param_1 != '.'; param_1 = param_1 + 1) {
    if (*param_1 == '\0') {
      return;
    }
  }
  do {
    pcVar2 = param_1;
    cVar1 = pcVar2[1];
    pcVar3 = pcVar2;
    if ((cVar1 == 'e') || (cVar1 == '\0')) break;
    param_1 = pcVar2 + 1;
  } while (cVar1 != 'E');
  for (; *pcVar3 == '0'; pcVar3 = pcVar3 + -1) {
  }
  pcVar3 = pcVar3 + -(uint)(*pcVar3 == '.');
  do {
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
    *pcVar3 = *pcVar2;
  } while (*pcVar2 != '\0');
  return;
}



/* Function: FUN_00016ac4 @ 00016ac4 */

void FUN_00016ac4(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  for (; *param_1 != '.'; param_1 = param_1 + 1) {
    if (*param_1 == '\0') {
      return;
    }
  }
  do {
    pcVar2 = param_1;
    cVar1 = pcVar2[1];
    pcVar3 = pcVar2;
    if ((cVar1 == 'e') || (cVar1 == '\0')) break;
    param_1 = pcVar2 + 1;
  } while (cVar1 != 'E');
  for (; *pcVar3 == '0'; pcVar3 = pcVar3 + -1) {
  }
  pcVar3 = pcVar3 + -(uint)(*pcVar3 == '.');
  do {
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
    *pcVar3 = *pcVar2;
  } while (*pcVar2 != '\0');
  return;
}



/* Function: FUN_00016b08 @ 00016b08 */

void FUN_00016b08(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  while( true ) {
    cVar1 = *param_1;
    if (cVar1 == '\0') {
      *param_1 = '.';
      param_1[1] = '\0';
      return;
    }
    if (cVar1 == '.') break;
    if ((cVar1 == 'E') || (cVar1 == 'e')) {
      iVar2 = FUN_00013488(param_1);
      pcVar3 = param_1 + iVar2;
      for (; 0 < iVar2; iVar2 = iVar2 + -1) {
        pcVar3[1] = *pcVar3;
        pcVar3 = pcVar3 + -1;
      }
      *param_1 = '.';
      return;
    }
    param_1 = param_1 + 1;
  }
  return;
}



/* Function: FUN_00016b48 @ 00016b48 */

byte * FUN_00016b48(double *param_1,undefined4 param_2,int param_3,int *param_4,undefined4 *param_5,
                   byte *param_6,int param_7)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  double *pdVar6;
  undefined4 extraout_r0_01;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  undefined4 extraout_s0;
  undefined4 extraout_s0_00;
  undefined4 extraout_s0_01;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined8 uVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x20 < param_3) {
    param_3 = 0x20;
  }
  *param_5 = 0;
  iVar5 = FUN_0001a688(param_1,param_2,DAT_00016d18,DAT_00016d1c);
  if (iVar5 != 0) {
    *param_5 = 1;
  }
  modf((double)CONCAT44(extraout_s1,extraout_s0),param_1);
  uVar1 = CONCAT44(extraout_r1,extraout_r0);
  iVar5 = FUN_0001a674(local_20,local_1c,DAT_00016d18,DAT_00016d1c);
  pbVar9 = param_6;
  if (iVar5 == 0) {
    iVar11 = 0;
    pbVar8 = param_6 + 0x22;
    while( true ) {
      uVar3 = local_1c;
      uVar2 = local_20;
      iVar5 = FUN_0001a674(local_20,local_1c,DAT_00016d18,DAT_00016d1c);
      if (iVar5 != 0) break;
      pdVar6 = (double *)FUN_0001a3a8(uVar2,uVar3,DAT_00016d20,DAT_00016d24);
      modf((double)CONCAT44(extraout_s1_00,extraout_s0_00),pdVar6);
      local_28._0_4_ = extraout_r0_00;
      local_28._4_4_ = extraout_r1_00;
      uVar10 = FUN_00019d90();
      FUN_0001a13c((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_00016d20,DAT_00016d24);
      cVar4 = FUN_0001a6d8();
      pbVar8 = pbVar8 + -1;
      *pbVar8 = cVar4 + 0x30;
      iVar11 = iVar11 + 1;
    }
    for (; pbVar8 < param_6 + 0x22; pbVar8 = pbVar8 + 1) {
      *pbVar9 = *pbVar8;
      pbVar9 = pbVar9 + 1;
    }
  }
  else {
    iVar5 = FUN_0001a6c4(extraout_r0,extraout_r1,DAT_00016d18,DAT_00016d1c);
    iVar11 = 0;
    if (iVar5 != 0) {
      while( true ) {
        local_34 = (undefined4)((ulonglong)uVar1 >> 0x20);
        local_38 = (undefined4)uVar1;
        local_28 = FUN_0001a13c(local_38,local_34,DAT_00016d20,DAT_00016d24);
        iVar5 = FUN_0001a688((int)local_28,(int)((ulonglong)local_28 >> 0x20),DAT_00016d30,
                             DAT_00016d34);
        if (iVar5 == 0) break;
        iVar11 = iVar11 + -1;
        uVar1 = local_28;
      }
    }
  }
  pbVar8 = param_6 + param_3;
  if (param_7 == 0) {
    pbVar8 = pbVar8 + iVar11;
  }
  *param_4 = iVar11;
  if (pbVar8 < param_6) {
    *param_6 = 0;
  }
  else {
    pbVar7 = param_6 + 0x22;
    puVar12 = &local_28;
    while( true ) {
      local_34 = (undefined4)((ulonglong)uVar1 >> 0x20);
      local_38 = (undefined4)uVar1;
      if ((pbVar8 < pbVar9) || (pbVar7 <= pbVar9)) break;
      pdVar6 = (double *)FUN_0001a13c(local_38,local_34,DAT_00016d20,DAT_00016d24,pbVar7,puVar12);
      modf((double)CONCAT44(extraout_s1_01,extraout_s0_01),pdVar6);
      uVar1 = CONCAT44(extraout_r1_01,extraout_r0_01);
      cVar4 = FUN_0001a6d8((undefined4)local_28,local_28._4_4_);
      *pbVar9 = cVar4 + 0x30;
      pbVar9 = pbVar9 + 1;
    }
    if (pbVar8 < param_6 + 0x22) {
      *pbVar8 = *pbVar8 + 5;
      pbVar9 = pbVar8;
      while (0x39 < *pbVar9) {
        *pbVar9 = 0x30;
        if (param_6 < pbVar9) {
          pbVar9 = pbVar9 + -1;
          *pbVar9 = *pbVar9 + 1;
        }
        else {
          *pbVar9 = 0x31;
          *param_4 = *param_4 + 1;
          if (param_7 == 0) {
            if (param_6 < pbVar8) {
              *pbVar8 = 0x30;
            }
            pbVar8 = pbVar8 + 1;
          }
        }
      }
      *pbVar8 = 0;
    }
    else {
      param_6[0x21] = 0;
    }
  }
  return param_6;
}



/* Function: FUN_00016d38 @ 00016d38 */

void FUN_00016d38(undefined4 param_1,undefined4 param_2,char *param_3,int param_4,size_t param_5)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char extraout_r1;
  char extraout_r1_00;
  char extraout_r1_01;
  char *local_50;
  char local_4c;
  int local_48;
  int local_44;
  undefined1 auStack_40 [36];
  int local_1c;
  
  local_1c = **(int **)(DAT_00016f28 + 0x16d46);
  if ((param_4 == 0x45) || (local_4c = '\0', param_4 == 0x47)) {
    param_4 = (param_4 + 0x20) * 0x1000000 >> 0x18;
    local_4c = ' ';
  }
  if (param_4 == 0x67) {
    FUN_00016b48(param_1,param_2,param_5,&local_44,&local_48,auStack_40,1);
    if ((local_44 + -1 < (int)param_5) && (-5 < local_44 + -1)) {
      param_5 = param_5 - local_44;
LAB_00016e5a:
      pcVar4 = (char *)FUN_00016b48(param_1,param_2,param_5,&local_44,&local_48,auStack_40,0);
      pcVar1 = param_3;
      if (local_48 != 0) {
        *param_3 = '-';
        pcVar1 = param_3 + 1;
      }
      if (*pcVar4 == '\0') {
        *pcVar1 = '0';
        param_3 = pcVar1 + 1;
        if (0 < (int)param_5) {
          pcVar1[1] = '.';
          pcVar4 = pcVar1 + 2;
          do {
            *pcVar4 = '0';
            pcVar4 = pcVar4 + 1;
          } while (pcVar4 != pcVar1 + param_5 + 2);
          param_3 = pcVar1 + 2 + param_5;
        }
      }
      else if (local_44 < 1) {
        *pcVar1 = '0';
        pcVar1[1] = '.';
        pcVar1 = pcVar1 + 2;
        for (iVar2 = 0; iVar2 < -local_44; iVar2 = iVar2 + 1) {
          *pcVar1 = '0';
          pcVar1 = pcVar1 + 1;
        }
        for (iVar2 = 0; pcVar4[iVar2] != '\0'; iVar2 = iVar2 + 1) {
          pcVar1[iVar2] = pcVar4[iVar2];
        }
        param_3 = pcVar1 + iVar2;
      }
      else {
        param_3 = pcVar1;
        for (iVar2 = 0; pcVar4[iVar2] != '\0'; iVar2 = iVar2 + 1) {
          if (iVar2 == local_44) {
            *param_3 = '.';
            param_3 = param_3 + 1;
          }
          *param_3 = pcVar4[iVar2];
          param_3 = param_3 + 1;
        }
      }
      goto LAB_00016f00;
    }
    param_5 = param_5 - 1;
  }
  else if (param_4 != 0x65) {
    if (param_4 != 0x66) goto LAB_00016f00;
    goto LAB_00016e5a;
  }
  pcVar1 = (char *)FUN_00016b48(param_1,param_2,param_5 + 1,&local_44,&local_48,auStack_40,1);
  if (local_48 != 0) {
    *param_3 = '-';
    param_3 = param_3 + 1;
  }
  *param_3 = *pcVar1;
  local_50 = param_3 + 1;
  if (0 < (int)param_5) {
    param_3[1] = '.';
    local_50 = param_3 + 2;
  }
  memcpy(local_50,pcVar1 + 1,param_5);
  local_50 = local_50 + param_5;
  *local_50 = 'e' - local_4c;
  if (local_44 == 0) {
    iVar2 = FUN_0001a674(param_1,param_2,DAT_00016f20,DAT_00016f24);
    local_44 = 0;
    if (iVar2 != 0) goto LAB_00016e14;
    local_44 = -1;
LAB_00016e0c:
    local_50[1] = '-';
    local_44 = -local_44;
  }
  else {
    local_44 = local_44 + -1;
    if (local_44 < 0) goto LAB_00016e0c;
LAB_00016e14:
    local_50[1] = '+';
  }
  FUN_00019d6c(local_44,10);
  local_50[4] = extraout_r1 + '0';
  uVar3 = FUN_00019c90(local_44,10);
  FUN_00019d6c(uVar3,10);
  local_50[3] = extraout_r1_00 + '0';
  uVar3 = FUN_00019c90(uVar3,10);
  FUN_00019d6c(uVar3,10);
  local_50[2] = extraout_r1_01 + '0';
  param_3 = local_50 + 5;
LAB_00016f00:
  *param_3 = '\0';
  if (local_1c == **(int **)(DAT_00016f2c + 0x16f0c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00016f30 @ 00016f30 */

void FUN_00016f30(undefined2 *param_1,uint param_2,ushort *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 local_b0;
  ushort *local_ac;
  int local_a0;
  uint local_84;
  
  iVar1 = **(int **)(DAT_00017220 + 0x16f40);
  local_b0 = 0;
  if (param_3 != (ushort *)0x0) {
    local_84 = 0;
    local_ac = param_3;
    local_a0 = param_4;
    while( true ) {
      if (local_a0 < 1) {
        if (0 < (int)(param_2 & -(uint)(param_1 != (undefined2 *)0x0))) {
          *param_1 = 0;
        }
        goto LAB_00017606;
      }
      uVar2 = 0;
      if ((*local_ac - 0x20 & 0xffff) < 0x5b) {
        uVar2 = *(byte *)(DAT_00017228 + (uint)*local_ac + 0x16f4a) & 0xf;
      }
      local_84 = (int)(uint)*(byte *)(uVar2 * 9 + local_84 + DAT_00017224 + 0x16f6c) >> 4;
      if (local_84 == 8) break;
      local_ac = local_ac + 1;
      local_a0 = local_a0 + -1;
      if (local_84 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x00016fd6 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_84 * 4 + DAT_0001722c + 0x16fd8) + DAT_0001722c + 0x16fd8))();
        return;
      }
    }
    local_b0 = 0xffffffff;
  }
LAB_00017606:
  if (iVar1 == **(int **)(DAT_00017620 + 0x17610)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_b0);
}



/* Function: FUN_00017654 @ 00017654 */

void FUN_00017654(ushort *param_1,int param_2)

{
  uint uVar1;
  undefined4 local_98;
  ushort *local_94;
  int local_80;
  uint local_74;
  
  local_98 = 0;
  if (param_1 != (ushort *)0x0) {
    local_74 = 0;
    local_94 = param_1;
    local_80 = param_2;
    while (0 < local_80) {
      uVar1 = 0;
      if ((*local_94 - 0x20 & 0xffff) < 0x5b) {
        uVar1 = *(byte *)(DAT_00017938 + (uint)*local_94 + 0x17660) & 0xf;
      }
      local_74 = (int)(uint)*(byte *)(uVar1 * 9 + local_74 + DAT_0001793c + 0x17682) >> 4;
      if (local_74 == 8) {
        local_98 = 0xffffffff;
        break;
      }
      local_94 = local_94 + 1;
      local_80 = local_80 + -1;
      if (local_74 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x000176e8 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_74 * 4 + DAT_00017940 + 0x176ea) + DAT_00017940 + 0x176ea))();
        return;
      }
    }
  }
  if (**(int **)(DAT_00017934 + 0x17660) == **(int **)(DAT_00017bd4 + 0x17bc6)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_98);
}



/* Function: FUN_00017c00 @ 00017c00 */

void FUN_00017c00(undefined1 *param_1,uint param_2,byte *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 local_b0;
  byte *local_ac;
  int local_a0;
  uint local_84;
  
  iVar1 = **(int **)(DAT_00017efc + 0x17c10);
  local_b0 = 0;
  if (param_3 != (byte *)0x0) {
    local_84 = 0;
    local_ac = param_3;
    local_a0 = param_4;
    while( true ) {
      if (local_a0 < 1) {
        if (0 < (int)(param_2 & -(uint)(param_1 != (undefined1 *)0x0))) {
          *param_1 = 0;
        }
        goto LAB_000182de;
      }
      uVar2 = 0;
      if ((*local_ac - 0x20 & 0xff) < 0x5b) {
        uVar2 = *(byte *)(DAT_00017f04 + (uint)*local_ac + 0x17c1a) & 0xf;
      }
      local_84 = (int)(uint)*(byte *)(uVar2 * 9 + local_84 + DAT_00017f00 + 0x17c3c) >> 4;
      if (local_84 == 8) break;
      local_ac = local_ac + 1;
      local_a0 = local_a0 + -1;
      if (local_84 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x00017ca6 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_84 * 4 + DAT_00017f08 + 0x17ca8) + DAT_00017f08 + 0x17ca8))();
        return;
      }
    }
    local_b0 = 0xffffffff;
  }
LAB_000182de:
  if (iVar1 == **(int **)(DAT_000182f8 + 0x182e8)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_b0);
}



/* Function: FUN_0001832c @ 0001832c */

void FUN_0001832c(byte *param_1,int param_2)

{
  uint uVar1;
  undefined4 local_98;
  byte *local_94;
  int local_84;
  uint local_74;
  
  local_98 = 0;
  if (param_1 != (byte *)0x0) {
    local_74 = 0;
    local_94 = param_1;
    local_84 = param_2;
    while (0 < local_84) {
      uVar1 = 0;
      if ((*local_94 - 0x20 & 0xff) < 0x5b) {
        uVar1 = *(byte *)(DAT_0001862c + (uint)*local_94 + 0x18338) & 0xf;
      }
      local_74 = (int)(uint)*(byte *)(uVar1 * 9 + local_74 + DAT_00018630 + 0x1835a) >> 4;
      if (local_74 == 8) {
        local_98 = 0xffffffff;
        break;
      }
      local_94 = local_94 + 1;
      local_84 = local_84 + -1;
      if (local_74 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x000183c0 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_74 * 4 + DAT_00018634 + 0x183c2) + DAT_00018634 + 0x183c2))();
        return;
      }
    }
  }
  if (**(int **)(DAT_00018628 + 0x18338) == **(int **)(DAT_000188c8 + 0x188b8)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_98);
}



/* Function: FUN_000188f4 @ 000188f4 */

void FUN_000188f4(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_1 << 0x1a < 0) {
    uVar1 = param_3[1];
    *param_2 = *param_3;
    param_2[1] = uVar1;
    return;
  }
  if (param_1 << 0x1b < 0) {
    uVar1 = *param_3;
  }
  else {
    if (param_1 << 0x1d < 0) {
      *(short *)param_2 = (short)*param_3;
      return;
    }
    uVar1 = *param_3;
    if (param_1 << 0x1c < 0) {
      *(char *)param_2 = (char)uVar1;
      return;
    }
  }
  *param_2 = uVar1;
  return;
}



/* Function: FUN_00018928 @ 00018928 */

void FUN_00018928(int param_1,int param_2,ushort *param_3,int param_4)

{
  ushort uVar1;
  int extraout_r1;
  int iVar2;
  ushort *extraout_r1_00;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *extraout_r3;
  ushort *extraout_r3_00;
  uint uVar6;
  uint extraout_r3_01;
  int iVar7;
  int iVar8;
  int iStack_c4;
  
  iVar3 = **(int **)(DAT_00018c18 + 0x18938);
  iVar7 = 0;
  FUN_0001926a();
  uVar4 = (uint)*param_3;
  if ((uVar4 - 9 < 5) || (uVar4 == 0x20)) {
    puVar5 = (ushort *)(param_1 + iStack_c4 * 2);
    for (; ((*puVar5 - 9 < 5 || (*puVar5 == 0x20)) && (puVar5 = puVar5 + 1, iStack_c4 < param_2));
        iStack_c4 = iStack_c4 + 1) {
    }
    param_3 = param_3 + 1;
    do {
      iVar7 = iVar7 + 1;
      if (iVar7 == param_4) {
        FUN_0001926a();
        param_3 = extraout_r3;
      }
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      if ((4 < uVar1 - 9) && (uVar1 != 0x20)) {
        FUN_0001926a();
        param_3 = extraout_r3_00;
      }
    } while( true );
  }
  if (uVar4 != 0x25) {
    if (*(ushort *)(iStack_c4 * 2 + param_1) != uVar4) {
      FUN_00019276();
    }
    iVar7 = 1;
    FUN_0001926a();
  }
  iVar8 = iVar7 + 1;
  puVar5 = param_3 + iVar8;
  if (*puVar5 == 0x2a) {
    iVar8 = iVar7 + 2;
  }
  uVar4 = (uint)(*puVar5 == 0x2a);
  puVar5 = param_3 + iVar8;
  iVar7 = 0;
  while( true ) {
    uVar6 = (uint)*puVar5;
    puVar5 = puVar5 + 1;
    if (9 < uVar6 - 0x30) break;
    uVar4 = uVar4 | 2;
    iVar7 = (uVar6 - 0x30) + iVar7 * 10;
    iVar8 = iVar8 + 1;
  }
  iVar2 = iVar8;
  if (((int)(uVar4 << 0x1e) < 0) && (iVar7 < 1)) {
    FUN_00019276();
    iVar2 = extraout_r1;
    uVar6 = extraout_r3_01;
  }
  if (uVar6 != 0x4c) {
    iVar7 = iVar8;
    if (uVar6 < 0x4d) {
      if (uVar6 == 0x49) {
        iVar7 = iVar8 + 1;
        if (param_3[iVar7] == 0x36) {
          if (param_3[iVar8 + 2] == 0x34) {
            iVar7 = iVar2 + 3;
          }
        }
        else if ((param_3[iVar7] == 0x33) && (param_3[iVar8 + 2] == 0x32)) {
          iVar7 = iVar2 + 3;
        }
      }
      goto LAB_00018a8a;
    }
    if (uVar6 == 0x68) {
      iVar7 = iVar8 + 1;
      if (param_3[iVar7] == 0x68) {
        iVar7 = iVar8 + 2;
      }
      goto LAB_00018a8a;
    }
    if (uVar6 != 0x6c) goto LAB_00018a8a;
    if (param_3[iVar8 + 1] == 0x6c) {
      iVar7 = iVar8 + 2;
      goto LAB_00018a8a;
    }
  }
  iVar7 = iVar8 + 1;
LAB_00018a8a:
  uVar1 = param_3[iVar7];
  if ((uVar1 != 0x4e) && (uVar1 != 0x6e)) {
    if ((uVar1 != 0x43) && ((uVar1 != 99 && (uVar1 != 0x5b)))) {
      puVar5 = (ushort *)(param_1 + iStack_c4 * 2);
      while ((*puVar5 - 9 < 5 || (*puVar5 == 0x20))) {
        puVar5 = puVar5 + 1;
        if (param_2 <= iStack_c4) {
          FUN_00019276();
          puVar5 = extraout_r1_00;
        }
        iStack_c4 = iStack_c4 + 1;
      }
    }
    if (param_2 <= iStack_c4) {
      FUN_00019276();
      return;
    }
  }
  if ((ushort)(uVar1 - 0x43) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x00018b04 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(ushort)(uVar1 - 0x43) * 4 + DAT_00018c1c + 0x18b06) +
              DAT_00018c1c + 0x18b06))();
    return;
  }
  if ((*(ushort *)(iStack_c4 * 2 + param_1) == uVar1) && (iVar7 + 1 < param_4)) {
    FUN_0001894c();
  }
  if (iVar3 == **(int **)(DAT_000192c0 + 0x19280)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}



/* Function: FUN_0001894c @ 0001894c */

void FUN_0001894c(void)

{
  ushort uVar1;
  short sVar2;
  int extraout_r1;
  int iVar3;
  ushort *extraout_r1_00;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *extraout_r3;
  ushort *extraout_r3_00;
  uint uVar7;
  uint extraout_r3_01;
  int unaff_r5;
  int iVar8;
  int unaff_r7;
  bool bVar9;
  int in_stack_00000004;
  int in_stack_00000024;
  undefined4 in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000034;
  int in_stack_000000ac;
  
  uVar5 = (uint)*(ushort *)(unaff_r5 * 2 + in_stack_00000024);
  if ((uVar5 - 9 < 5) || (uVar5 == 0x20)) {
    puVar6 = (ushort *)(unaff_r7 + in_stack_00000004 * 2);
    for (; ((*puVar6 - 9 < 5 || (*puVar6 == 0x20)) &&
           (puVar6 = puVar6 + 1, in_stack_00000004 < in_stack_0000002c));
        in_stack_00000004 = in_stack_00000004 + 1) {
    }
    puVar6 = (ushort *)(in_stack_00000024 + (unaff_r5 + 1) * 2);
    do {
      unaff_r5 = unaff_r5 + 1;
      if (unaff_r5 == in_stack_00000034) {
        FUN_0001926a();
        puVar6 = extraout_r3;
      }
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      if ((4 < uVar1 - 9) && (uVar1 != 0x20)) {
        FUN_0001926a();
        puVar6 = extraout_r3_00;
      }
    } while( true );
  }
  if (uVar5 != 0x25) {
    if (*(ushort *)(in_stack_00000004 * 2 + unaff_r7) != uVar5) {
      FUN_00019276();
    }
    unaff_r5 = unaff_r5 + 1;
    FUN_0001926a();
  }
  iVar8 = unaff_r5 + 1;
  bVar9 = *(short *)(iVar8 * 2 + in_stack_00000024) == 0x2a;
  if (bVar9) {
    iVar8 = unaff_r5 + 2;
  }
  uVar5 = (uint)bVar9;
  puVar6 = (ushort *)(in_stack_00000024 + iVar8 * 2);
  iVar4 = 0;
  while( true ) {
    uVar7 = (uint)*puVar6;
    puVar6 = puVar6 + 1;
    if (9 < uVar7 - 0x30) break;
    uVar5 = uVar5 | 2;
    iVar4 = (uVar7 - 0x30) + iVar4 * 10;
    iVar8 = iVar8 + 1;
  }
  iVar3 = iVar8;
  if (((int)(uVar5 << 0x1e) < 0) && (iVar4 < 1)) {
    FUN_00019276();
    iVar3 = extraout_r1;
    uVar7 = extraout_r3_01;
  }
  if (uVar7 != 0x4c) {
    iVar4 = iVar8;
    if (uVar7 < 0x4d) {
      if (uVar7 == 0x49) {
        iVar4 = iVar8 + 1;
        sVar2 = *(short *)(iVar4 * 2 + in_stack_00000024);
        if (sVar2 == 0x36) {
          if (*(short *)((iVar8 + 2) * 2 + in_stack_00000024) == 0x34) {
            iVar4 = iVar3 + 3;
          }
        }
        else if ((sVar2 == 0x33) && (*(short *)((iVar8 + 2) * 2 + in_stack_00000024) == 0x32)) {
          iVar4 = iVar3 + 3;
        }
      }
      goto LAB_00018a8a;
    }
    if (uVar7 == 0x68) {
      iVar4 = iVar8 + 1;
      if (*(short *)(iVar4 * 2 + in_stack_00000024) == 0x68) {
        iVar4 = iVar8 + 2;
      }
      goto LAB_00018a8a;
    }
    if (uVar7 != 0x6c) goto LAB_00018a8a;
    if (*(short *)((iVar8 + 1) * 2 + in_stack_00000024) == 0x6c) {
      iVar4 = iVar8 + 2;
      goto LAB_00018a8a;
    }
  }
  iVar4 = iVar8 + 1;
LAB_00018a8a:
  sVar2 = *(short *)(iVar4 * 2 + in_stack_00000024);
  if ((sVar2 != 0x4e) && (sVar2 != 0x6e)) {
    if ((sVar2 != 0x43) && ((sVar2 != 99 && (sVar2 != 0x5b)))) {
      puVar6 = (ushort *)(unaff_r7 + in_stack_00000004 * 2);
      while ((*puVar6 - 9 < 5 || (*puVar6 == 0x20))) {
        puVar6 = puVar6 + 1;
        if (in_stack_0000002c <= in_stack_00000004) {
          FUN_00019276();
          puVar6 = extraout_r1_00;
        }
        in_stack_00000004 = in_stack_00000004 + 1;
      }
    }
    if (in_stack_0000002c <= in_stack_00000004) {
      FUN_00019276();
      return;
    }
  }
  if ((ushort)(sVar2 - 0x43) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x00018b04 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(ushort)(sVar2 - 0x43) * 4 + DAT_00018c1c + 0x18b06) +
              DAT_00018c1c + 0x18b06))();
    return;
  }
  if ((*(short *)(in_stack_00000004 * 2 + unaff_r7) == sVar2) && (iVar4 + 1 < in_stack_00000034)) {
    FUN_0001894c();
  }
  if (in_stack_000000ac == **(int **)(DAT_000192c0 + 0x19280)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(in_stack_00000028);
}



/* Function: FUN_0001926a @ 0001926a */

void FUN_0001926a(void)

{
  int unaff_r5;
  undefined4 in_stack_00000028;
  int in_stack_00000034;
  int in_stack_000000ac;
  
  if (unaff_r5 < in_stack_00000034) {
    FUN_0001894c();
  }
  if (in_stack_000000ac != **(int **)(DAT_000192c0 + 0x19280)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_00019276 @ 00019276 */

void FUN_00019276(void)

{
  undefined4 in_stack_00000028;
  int in_stack_000000ac;
  
  if (in_stack_000000ac != **(int **)(DAT_000192c0 + 0x19280)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_000192c8 @ 000192c8 */

void FUN_000192c8(int param_1,int param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  int extraout_r1;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint extraout_r3;
  int iVar7;
  int iVar8;
  int iStack_c4;
  
  iVar4 = **(int **)(DAT_000195e0 + 0x192d8);
  iVar7 = 0;
  FUN_00019b76();
  uVar5 = (uint)*param_3;
  if ((uVar5 - 9 < 5) || (uVar5 == 0x20)) {
    for (; ((*(byte *)(param_1 + iStack_c4) - 9 < 5 || (*(byte *)(param_1 + iStack_c4) == 0x20)) &&
           (iStack_c4 < param_2)); iStack_c4 = iStack_c4 + 1) {
    }
    do {
      iVar7 = iVar7 + 1;
      if (iVar7 == param_4) {
        FUN_00019b76();
      }
      if ((4 < param_3[iVar7] - 9) && (param_3[iVar7] != 0x20)) {
        FUN_00019b76();
      }
    } while( true );
  }
  if (uVar5 != 0x25) {
    if (*(byte *)(param_1 + iStack_c4) != uVar5) {
      FUN_00019b82();
    }
    iVar7 = 1;
    FUN_00019b76();
  }
  iVar8 = iVar7 + 1;
  pbVar1 = param_3 + iVar8;
  if (*pbVar1 == 0x2a) {
    iVar8 = iVar7 + 2;
  }
  uVar5 = (uint)(*pbVar1 == 0x2a);
  iVar7 = 0;
  while( true ) {
    uVar6 = (uint)param_3[iVar8];
    if (9 < uVar6 - 0x30) break;
    uVar5 = uVar5 | 2;
    iVar7 = (uVar6 - 0x30) + iVar7 * 10;
    iVar8 = iVar8 + 1;
  }
  iVar3 = iVar8;
  if (((int)(uVar5 << 0x1e) < 0) && (iVar7 < 1)) {
    FUN_00019b82();
    iVar3 = extraout_r1;
    uVar6 = extraout_r3;
  }
  if (uVar6 != 0x4c) {
    iVar7 = iVar8;
    if (uVar6 < 0x4d) {
      if (uVar6 == 0x49) {
        iVar7 = iVar8 + 1;
        if (param_3[iVar7] == 0x36) {
          if (param_3[iVar8 + 2] == 0x34) {
            iVar7 = iVar3 + 3;
          }
        }
        else if ((param_3[iVar7] == 0x33) && (param_3[iVar8 + 2] == 0x32)) {
          iVar7 = iVar3 + 3;
        }
      }
      goto LAB_00019400;
    }
    if (uVar6 == 0x68) {
      iVar7 = iVar8 + 1;
      if (param_3[iVar7] == 0x68) {
        iVar7 = iVar8 + 2;
      }
      goto LAB_00019400;
    }
    if (uVar6 != 0x6c) goto LAB_00019400;
    if (param_3[iVar8 + 1] == 0x6c) {
      iVar7 = iVar8 + 2;
      goto LAB_00019400;
    }
  }
  iVar7 = iVar8 + 1;
LAB_00019400:
  bVar2 = param_3[iVar7];
  if ((bVar2 != 0x4e) && (bVar2 != 0x6e)) {
    if ((bVar2 != 0x43) && ((bVar2 != 99 && (bVar2 != 0x5b)))) {
      for (; (*(byte *)(param_1 + iStack_c4) - 9 < 5 || (*(byte *)(param_1 + iStack_c4) == 0x20));
          iStack_c4 = iStack_c4 + 1) {
        if (param_2 <= iStack_c4) {
          FUN_00019b82();
          return;
        }
      }
    }
    if (param_2 <= iStack_c4) {
      FUN_00019b82();
      return;
    }
  }
  if ((byte)(bVar2 + 0xbd) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x0001946c */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(byte)(bVar2 + 0xbd) * 4 + DAT_000195e4 + 0x1946e) +
              DAT_000195e4 + 0x1946e))();
    return;
  }
  if ((*(byte *)(param_1 + iStack_c4) == bVar2) && (iVar7 + 1 < param_4)) {
    FUN_000192ea();
  }
  if (iVar4 == **(int **)(DAT_00019bd0 + 0x19b8c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}



/* Function: FUN_000192ea @ 000192ea */

void FUN_000192ea(void)

{
  char cVar1;
  int extraout_r1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r3;
  int unaff_r5;
  int iVar6;
  bool bVar7;
  int in_stack_00000004;
  int in_stack_00000020;
  int in_stack_00000024;
  undefined4 in_stack_00000028;
  int in_stack_00000030;
  int in_stack_00000034;
  int in_stack_000000ac;
  
  uVar4 = (uint)*(byte *)(in_stack_00000024 + unaff_r5);
  if ((uVar4 - 9 < 5) || (uVar4 == 0x20)) {
    for (; ((*(byte *)(in_stack_00000020 + in_stack_00000004) - 9 < 5 ||
            (*(byte *)(in_stack_00000020 + in_stack_00000004) == 0x20)) &&
           (in_stack_00000004 < in_stack_00000030)); in_stack_00000004 = in_stack_00000004 + 1) {
    }
    do {
      unaff_r5 = unaff_r5 + 1;
      if (unaff_r5 == in_stack_00000034) {
        FUN_00019b76();
      }
      if ((4 < *(byte *)(in_stack_00000024 + unaff_r5) - 9) &&
         (*(byte *)(in_stack_00000024 + unaff_r5) != 0x20)) {
        FUN_00019b76();
      }
    } while( true );
  }
  if (uVar4 != 0x25) {
    if (*(byte *)(in_stack_00000020 + in_stack_00000004) != uVar4) {
      FUN_00019b82();
    }
    unaff_r5 = unaff_r5 + 1;
    FUN_00019b76();
  }
  iVar6 = unaff_r5 + 1;
  bVar7 = *(char *)(in_stack_00000024 + iVar6) == '*';
  if (bVar7) {
    iVar6 = unaff_r5 + 2;
  }
  uVar4 = (uint)bVar7;
  iVar3 = 0;
  while( true ) {
    uVar5 = (uint)*(byte *)(in_stack_00000024 + iVar6);
    if (9 < uVar5 - 0x30) break;
    uVar4 = uVar4 | 2;
    iVar3 = (uVar5 - 0x30) + iVar3 * 10;
    iVar6 = iVar6 + 1;
  }
  iVar2 = iVar6;
  if (((int)(uVar4 << 0x1e) < 0) && (iVar3 < 1)) {
    FUN_00019b82();
    iVar2 = extraout_r1;
    uVar5 = extraout_r3;
  }
  if (uVar5 != 0x4c) {
    iVar3 = iVar6;
    if (uVar5 < 0x4d) {
      if (uVar5 == 0x49) {
        iVar3 = iVar6 + 1;
        if (*(char *)(in_stack_00000024 + iVar3) == '6') {
          if (*(char *)(in_stack_00000024 + iVar3 + 1) == '4') {
            iVar3 = iVar2 + 3;
          }
        }
        else if ((*(char *)(in_stack_00000024 + iVar3) == '3') &&
                (*(char *)(in_stack_00000024 + iVar3 + 1) == '2')) {
          iVar3 = iVar2 + 3;
        }
      }
      goto LAB_00019400;
    }
    if (uVar5 == 0x68) {
      iVar3 = iVar6 + 1;
      if (*(char *)(in_stack_00000024 + iVar3) == 'h') {
        iVar3 = iVar6 + 2;
      }
      goto LAB_00019400;
    }
    if (uVar5 != 0x6c) goto LAB_00019400;
    if (*(char *)(in_stack_00000024 + iVar6 + 1) == 'l') {
      iVar3 = iVar6 + 2;
      goto LAB_00019400;
    }
  }
  iVar3 = iVar6 + 1;
LAB_00019400:
  cVar1 = *(char *)(in_stack_00000024 + iVar3);
  if ((cVar1 != 'N') && (cVar1 != 'n')) {
    if ((cVar1 != 'C') && ((cVar1 != 'c' && (cVar1 != '[')))) {
      for (; (*(byte *)(in_stack_00000020 + in_stack_00000004) - 9 < 5 ||
             (*(byte *)(in_stack_00000020 + in_stack_00000004) == 0x20));
          in_stack_00000004 = in_stack_00000004 + 1) {
        if (in_stack_00000030 <= in_stack_00000004) {
          FUN_00019b82();
          return;
        }
      }
    }
    if (in_stack_00000030 <= in_stack_00000004) {
      FUN_00019b82();
      return;
    }
  }
  if ((byte)(cVar1 + 0xbd) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x0001946c */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(byte)(cVar1 + 0xbd) * 4 + DAT_000195e4 + 0x1946e) +
              DAT_000195e4 + 0x1946e))();
    return;
  }
  if ((*(char *)(in_stack_00000020 + in_stack_00000004) == cVar1) && (iVar3 + 1 < in_stack_00000034)
     ) {
    FUN_000192ea();
  }
  if (in_stack_000000ac == **(int **)(DAT_00019bd0 + 0x19b8c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(in_stack_00000028);
}



/* Function: FUN_00019b76 @ 00019b76 */

void FUN_00019b76(void)

{
  int unaff_r5;
  undefined4 in_stack_00000028;
  int in_stack_00000034;
  int in_stack_000000ac;
  
  if (unaff_r5 < in_stack_00000034) {
    FUN_000192ea();
  }
  if (in_stack_000000ac != **(int **)(DAT_00019bd0 + 0x19b8c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_00019b82 @ 00019b82 */

void FUN_00019b82(void)

{
  undefined4 in_stack_00000028;
  int in_stack_000000ac;
  
  if (in_stack_000000ac != **(int **)(DAT_00019bd0 + 0x19b8c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_00019c5c @ 00019c5c */

void FUN_00019c5c(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  return;
}



/* Function: FUN_00019c68 @ 00019c68 */

void FUN_00019c68(void)

{
  FUN_00019c5c();
  return;
}



/* Function: FUN_00019c80 @ 00019c80 */

void FUN_00019c80(size_t param_1)

{
  malloc(param_1);
  return;
}



/* Function: FUN_00019c88 @ 00019c88 */

void FUN_00019c88(void)

{
  FUN_00019c80();
  return;
}



/* Function: FUN_00019c90 @ 00019c90 */

uint FUN_00019c90(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_1 ^ param_2;
  if (param_2 == 0) {
    FUN_0001ada8();
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



/* Function: FUN_00019d6c @ 00019d6c */

void FUN_00019d6c(void)

{
  FUN_00019c90();
  return;
}



/* Function: FUN_00019d90 @ 00019d90 */

ulonglong FUN_00019d90(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  uVar9 = param_2 << 1;
  uVar5 = param_4 << 1;
  iVar8 = (int)uVar9 >> 0x15;
  iVar1 = (int)uVar5 >> 0x15;
  if ((((uVar9 == uVar5 && param_1 == param_3 || uVar9 == 0 && param_1 == 0) ||
       uVar5 == 0 && param_3 == 0) || iVar8 == -1) || iVar1 == -1) {
    if (iVar8 == -1 || iVar1 == -1) {
      uVar9 = param_3;
      uVar5 = param_4;
      if (iVar8 == -1) {
        uVar9 = param_1;
        uVar5 = param_2;
      }
      if (iVar8 != -1 || iVar1 != -1) {
        param_3 = uVar9;
        param_4 = uVar5;
      }
      bVar14 = (uVar5 & 0xfffff) == 0;
      bVar15 = uVar9 == 0 && bVar14;
      if (uVar9 == 0 && bVar14) {
        bVar15 = param_3 == 0 && (param_4 & 0xfffff) == 0;
      }
      if (!bVar15 || uVar5 != param_4) {
        uVar5 = uVar5 | 0x80000;
      }
      return CONCAT44(uVar5,uVar9);
    }
    if (uVar9 != uVar5 || param_1 != param_3) {
      if (uVar9 == 0 && param_1 == 0) {
        param_1 = param_3;
        param_2 = param_4;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != param_4) {
      return 0;
    }
    if ((param_2 & 0x7fffffff) >> 0x14 == 0) {
      bVar2 = (byte)(param_1 >> 0x1f);
      uVar9 = param_2 * 2 + (uint)bVar2;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar2)) {
        uVar9 = uVar9 | 0x80000000;
      }
      return CONCAT44(uVar9,param_1 << 1);
    }
    if (uVar9 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_0001a000:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar9 = (param_2 & 0x7fffffff) >> 0x14;
  uVar5 = (param_4 & 0x7fffffff) >> 0x14;
  uVar11 = uVar5 - uVar9;
  bVar14 = uVar11 != 0;
  if (uVar5 < uVar9) {
    uVar11 = -uVar11;
  }
  uVar10 = param_1;
  uVar7 = param_2;
  if (bVar14 && uVar9 <= uVar5) {
    uVar9 = uVar9 + uVar11;
    uVar10 = param_3;
    uVar7 = param_4;
    param_3 = param_1;
    param_4 = param_2;
  }
  if (0x36 < uVar11) {
    return CONCAT44(uVar7,uVar10);
  }
  uVar5 = uVar7 & 0xfffff | 0x100000;
  if ((uVar7 & 0x80000000) != 0) {
    bVar14 = uVar10 != 0;
    uVar10 = -uVar10;
    uVar5 = -(uVar5 + bVar14);
  }
  uVar7 = param_4 & 0xfffff | 0x100000;
  if ((param_4 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar7 = -(uVar7 + bVar14);
  }
  if (uVar9 == uVar11) {
    uVar7 = uVar7 ^ 0x100000;
    if (uVar9 == 0) {
      uVar5 = uVar5 ^ 0x100000;
      uVar9 = 1;
    }
    else {
      uVar11 = uVar11 - 1;
    }
  }
  uVar13 = -uVar11 + 0x20;
  if ((int)uVar11 < 0x21) {
    uVar12 = param_3 << (uVar13 & 0xff);
    param_3 = param_3 >> (uVar11 & 0xff);
    uVar4 = uVar10 + param_3;
    uVar6 = uVar7 << (uVar13 & 0xff);
    uVar13 = uVar4 + uVar6;
    uVar5 = uVar5 + CARRY4(uVar10,param_3) + ((int)uVar7 >> (uVar11 & 0xff)) +
            (uint)CARRY4(uVar4,uVar6);
  }
  else {
    uVar12 = uVar7 << (-uVar11 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar12 = uVar12 | 2;
    }
    uVar11 = (int)uVar7 >> (uVar11 - 0x20 & 0xff);
    uVar13 = uVar10 + uVar11;
    uVar5 = uVar5 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar10,uVar11);
  }
  param_2 = uVar5 & 0x80000000;
  uVar11 = uVar5;
  if ((int)uVar5 < 0) {
    bVar14 = uVar12 == 0;
    uVar12 = -uVar12;
    uVar11 = -uVar13;
    uVar13 = -(uVar13 + !bVar14);
    uVar11 = -(uVar5 + (bVar14 <= uVar11));
  }
  if (0xfffff < uVar11) {
    uVar10 = uVar9 - 1;
    if (0x1fffff < uVar11) {
      bVar2 = (byte)uVar11;
      uVar11 = uVar11 >> 1;
      bVar3 = (byte)uVar13;
      uVar13 = (uint)(bVar2 & 1) << 0x1f | uVar13 >> 1;
      uVar12 = (uint)(bVar3 & 1) << 0x1f | uVar12 >> 1;
      uVar10 = uVar9;
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_0001a000;
    }
LAB_00019ea8:
    bVar14 = 0x7fffffff < uVar12;
    if (uVar12 == 0x80000000) {
      bVar14 = (bool)((byte)uVar13 & 1);
    }
    return CONCAT44(uVar11 + uVar10 * 0x100000 + (uint)CARRY4(uVar13,(uint)bVar14) | param_2,
                    uVar13 + bVar14);
  }
  bVar2 = (byte)(uVar12 >> 0x1f);
  uVar12 = uVar12 << 1;
  uVar10 = uVar13 * 2;
  bVar14 = CARRY4(uVar13,uVar13);
  uVar13 = uVar13 * 2 + (uint)bVar2;
  uVar11 = uVar11 * 2 + (uint)(bVar14 || CARRY4(uVar10,(uint)bVar2));
  uVar10 = uVar9 - 2;
  if ((uVar11 & 0x100000) != 0) goto LAB_00019ea8;
  uVar9 = uVar13;
  uVar7 = uVar11;
  if (uVar11 == 0) {
    uVar9 = 0;
    uVar7 = uVar13;
  }
  iVar8 = LZCOUNT(uVar7);
  if (uVar11 == 0) {
    iVar8 = iVar8 + 0x20;
  }
  uVar4 = iVar8 - 0xb;
  bVar15 = SBORROW4(uVar4,0x20);
  uVar6 = iVar8 - 0x2b;
  bVar14 = uVar6 == 0;
  uVar11 = uVar6;
  uVar13 = uVar6;
  if ((int)uVar4 < 0x20) {
    bVar15 = SCARRY4(uVar6,0xc);
    uVar13 = iVar8 - 0x1f;
    bVar14 = uVar13 == 0;
    uVar11 = uVar4;
    if (!bVar14 && -0xd < (int)uVar6) {
      uVar9 = uVar7 << (uVar4 & 0xff);
      uVar7 = uVar7 >> (0xc - uVar13 & 0xff);
      goto LAB_00019f28;
    }
  }
  if (bVar14 || (int)uVar13 < 0 != bVar15) {
    uVar12 = 0x20 - uVar11;
  }
  uVar7 = uVar7 << (uVar11 & 0xff);
  if (bVar14 || (int)uVar13 < 0 != bVar15) {
    uVar7 = uVar7 | uVar9 >> (uVar12 & 0xff);
    uVar9 = uVar9 << (uVar11 & 0xff);
  }
LAB_00019f28:
  if ((int)uVar4 <= (int)uVar10) {
    return CONCAT44(uVar7 + (uVar10 - uVar4) * 0x100000 | param_2,uVar9);
  }
  uVar11 = ~(uVar10 - uVar4);
  if ((int)uVar11 < 0x1f) {
    if (uVar11 - 0x13 != 0 && -0xd < (int)(uVar11 - 0x1f)) {
      uVar11 = 0xc - (uVar11 - 0x13);
      return CONCAT44(uVar5,uVar9 >> (0x20 - uVar11 & 0xff) | uVar7 << (uVar11 & 0xff)) &
             0x80000000ffffffff;
    }
    uVar11 = uVar11 + 1;
    return CONCAT44(param_2 | uVar7 >> (uVar11 & 0xff),
                    uVar9 >> (uVar11 & 0xff) | uVar7 << (0x20 - uVar11 & 0xff));
  }
  return CONCAT44(uVar5,uVar7 >> (uVar11 - 0x1f & 0xff)) & 0x80000000ffffffff;
}



/* Function: FUN_0001a060 @ 0001a060 */

ulonglong FUN_0001a060(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint in_r12;
  bool bVar9;
  bool bVar10;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar8 = param_1 & 0x80000000;
  uVar2 = param_1;
  if ((int)uVar8 < 0) {
    uVar2 = -param_1;
  }
  uVar1 = 0;
  iVar5 = LZCOUNT(uVar2);
  uVar6 = iVar5 + 0x15;
  bVar10 = SBORROW4(uVar6,0x20);
  uVar3 = iVar5 - 0xb;
  bVar9 = uVar3 == 0;
  uVar7 = uVar3;
  uVar4 = uVar3;
  if (uVar6 < 0x20) {
    bVar10 = SCARRY4(uVar3,0xc);
    uVar4 = iVar5 + 1;
    bVar9 = uVar4 == 0;
    uVar7 = uVar6;
    if (!bVar9 && -0xd < (int)uVar3) {
      uVar1 = uVar2 << uVar6;
      uVar2 = uVar2 >> (0xc - uVar4 & 0xff);
      goto LAB_00019f28;
    }
  }
  if (bVar9 || (int)uVar4 < 0 != bVar10) {
    in_r12 = 0x20 - uVar7;
  }
  uVar2 = uVar2 << (uVar7 & 0xff);
  if (bVar9 || (int)uVar4 < 0 != bVar10) {
    uVar2 = uVar2 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar7 & 0xff);
  }
LAB_00019f28:
  if (uVar6 < 0x433) {
    return CONCAT44(uVar2 + (0x432 - uVar6) * 0x100000 | uVar8,uVar1);
  }
  uVar7 = ~(0x432 - uVar6);
  if (0x1e < (int)uVar7) {
    return CONCAT44(param_1,uVar2 >> (uVar7 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar7 - 0x13 == 0 || (int)(uVar7 - 0x1f) < -0xc) {
    uVar7 = uVar7 + 1;
    return CONCAT44(uVar8 | uVar2 >> (uVar7 & 0xff),
                    uVar1 >> (uVar7 & 0xff) | uVar2 << (0x20 - uVar7 & 0xff));
  }
  uVar8 = 0xc - (uVar7 - 0x13);
  return CONCAT44(param_1,uVar1 >> (0x20 - uVar8 & 0xff) | uVar2 << (uVar8 & 0xff)) &
         0x80000000ffffffff;
}



/* Function: FUN_0001a13c @ 0001a13c */

ulonglong FUN_0001a13c(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  uint uVar4;
  uint extraout_r2;
  uint extraout_r3;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint extraout_r12;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  uVar14 = CONCAT44(param_2,param_1);
  uVar10 = 0x7ff;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar11 = uVar6 == 0;
  if (!bVar11) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar11 = unaff_r5 == 0;
  }
  if (!bVar11) {
    bVar11 = uVar6 == 0x7ff;
  }
  if (!bVar11) {
    bVar11 = unaff_r5 == 0x7ff;
  }
  if (bVar11) {
    uVar14 = FUN_0001a31c();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar10 = extraout_r12;
  }
  uVar4 = (uint)(uVar14 >> 0x20);
  iVar7 = uVar6 + unaff_r5;
  uVar9 = uVar4 ^ param_4;
  uVar4 = uVar4 & ~(uVar10 << 0x15);
  param_4 = param_4 & ~(uVar10 << 0x15);
  uVar6 = uVar4 | 0x100000;
  uVar5 = param_4 | 0x100000;
  if ((uint)uVar14 == 0 && (uVar4 & 0xfffff) == 0 || param_3 == 0 && (param_4 & 0xfffff) == 0) {
    param_3 = (uint)uVar14 | param_3;
    uVar5 = (uVar9 & 0x80000000 | uVar6) ^ uVar5;
    uVar6 = uVar10 >> 1;
    bVar13 = SBORROW4(iVar7,uVar6);
    uVar8 = iVar7 - uVar6;
    bVar11 = uVar8 == 0;
    uVar4 = uVar8;
    if (!bVar11 && (int)uVar6 <= iVar7) {
      bVar13 = SBORROW4(uVar10,uVar8);
      uVar4 = uVar10 - uVar8;
      bVar11 = uVar10 == uVar8;
    }
    if (!bVar11 && (int)uVar4 < 0 == bVar13) {
      return CONCAT44(uVar5 | uVar8 * 0x100000,param_3);
    }
    uVar5 = uVar5 | 0x100000;
    uVar10 = 0;
    bVar13 = SBORROW4(uVar8,1);
    uVar8 = uVar8 - 1;
    bVar11 = uVar8 == 0;
    uVar6 = uVar8;
  }
  else {
    uVar2 = (ulonglong)param_3 * (uVar14 & 0xffffffff);
    uVar14 = (ulonglong)uVar5 * (uVar14 & 0xffffffff) +
             (ulonglong)param_3 * (ulonglong)uVar6 + (uVar2 >> 0x20);
    uVar4 = (uint)uVar14;
    lVar1 = (ulonglong)uVar5 * (ulonglong)uVar6 + (uVar14 >> 0x20);
    uVar10 = (uint)lVar1;
    uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
    if ((int)uVar2 != 0) {
      uVar4 = uVar4 | 1;
    }
    uVar8 = (iVar7 + -0xff) - ((uVar6 < 0x200) + 0x300);
    if (uVar6 < 0x200) {
      bVar3 = (byte)(uVar4 >> 0x1f);
      uVar4 = uVar4 << 1;
      lVar1 = CONCAT44(uVar6 * 2 + (uint)(CARRY4(uVar10,uVar10) || CARRY4(uVar10 * 2,(uint)bVar3)),
                       uVar10 * 2 + (uint)bVar3);
    }
    uVar5 = uVar9 & 0x80000000 | (int)((ulonglong)lVar1 >> 0x20) << 0xb | (uint)lVar1 >> 0x15;
    param_3 = (uint)lVar1 << 0xb | uVar4 >> 0x15;
    uVar10 = uVar4 * 0x800;
    bVar12 = 0xfc < uVar8;
    bVar13 = SBORROW4(uVar8,0xfd);
    uVar9 = uVar8 - 0xfd;
    bVar11 = uVar9 == 0;
    uVar6 = uVar9;
    if (bVar12 && !bVar11) {
      bVar12 = 0x6ff < uVar9;
      bVar13 = SBORROW4(uVar9,0x700);
      uVar6 = uVar8 - 0x7fd;
      bVar11 = uVar9 == 0x700;
    }
    if (!bVar12 || bVar11) {
      bVar11 = 0x7fffffff < uVar10;
      if (uVar10 == 0x80000000) {
        bVar11 = (bool)((byte)(uVar4 >> 0x15) & 1);
      }
      return CONCAT44(uVar5 + uVar8 * 0x100000 + (uint)CARRY4(param_3,(uint)bVar11),param_3 + bVar11
                     );
    }
  }
  if (!bVar11 && (int)uVar6 < 0 == bVar13) {
    return (ulonglong)(uVar5 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if (-0x36 < (int)uVar8) {
    uVar6 = -uVar8;
    uVar4 = uVar6 - 0x20;
    if (0x1f < (int)uVar6) {
      uVar9 = param_3 >> (uVar4 & 0xff) | uVar5 << (0x20 - uVar4 & 0xff);
      uVar6 = (uVar5 >> (uVar4 & 0xff) & ~((uVar5 & 0x80000000) >> (uVar4 & 0xff))) -
              ((int)uVar9 >> 0x1f);
      if ((uVar10 == 0 && param_3 << (0x20 - uVar4 & 0xff) == 0) && (uVar9 & 0x7fffffff) == 0) {
        uVar6 = uVar6 & ~(uVar9 >> 0x1f);
      }
      return CONCAT44(uVar5,uVar6) & 0x80000000ffffffff;
    }
    if (uVar6 - 0x14 != 0 && -0xd < (int)uVar4) {
      uVar4 = 0xc - (uVar6 - 0x14);
      uVar6 = param_3 << (uVar4 & 0xff);
      uVar4 = param_3 >> (0x20 - uVar4 & 0xff) | uVar5 << (uVar4 & 0xff);
      uVar9 = uVar4 + -((int)uVar6 >> 0x1f);
      if (uVar10 == 0 && (uVar6 & 0x7fffffff) == 0) {
        uVar9 = uVar9 & ~(uVar6 >> 0x1f);
      }
      return CONCAT44((uVar5 & 0x80000000) + (uint)CARRY4(uVar4,-((int)uVar6 >> 0x1f)),uVar9);
    }
    uVar4 = param_3 << (uVar8 + 0x20 & 0xff);
    uVar9 = param_3 >> (uVar6 & 0xff) | uVar5 << (uVar8 + 0x20 & 0xff);
    uVar8 = uVar9 + -((int)uVar4 >> 0x1f);
    if (uVar10 == 0 && (uVar4 & 0x7fffffff) == 0) {
      uVar8 = uVar8 & ~(uVar4 >> 0x1f);
    }
    return CONCAT44((uVar5 & 0x80000000) + ((uVar5 & 0x7fffffff) >> (uVar6 & 0xff)) +
                    (uint)CARRY4(uVar9,-((int)uVar4 >> 0x1f)),uVar8);
  }
  return (ulonglong)(uVar5 & 0x80000000) << 0x20;
}



/* Function: FUN_0001a31c @ 0001a31c */

ulonglong FUN_0001a31c(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint unaff_r4;
  uint uVar4;
  uint uVar5;
  uint in_r12;
  
  uVar4 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 != in_r12 && uVar4 != in_r12) {
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0 || param_3 == 0 && (param_4 & 0x7fffffff) == 0)
    {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    if (unaff_r4 == 0) {
      uVar5 = param_2 & 0x80000000;
      do {
        iVar2 = param_1 >> 0x1f;
        param_1 = param_1 << 1;
        param_2 = param_2 * 2 - iVar2;
      } while ((param_2 & 0x100000) == 0);
      param_2 = param_2 | uVar5;
      if (uVar4 != 0) {
        return CONCAT44(param_2,param_1);
      }
    }
    do {
      iVar2 = param_3 >> 0x1f;
      param_3 = param_3 << 1;
      param_4 = param_4 * 2 - iVar2;
    } while ((param_4 & 0x100000) == 0);
    return CONCAT44(param_2,param_1);
  }
  bVar1 = (param_2 & 0x7fffffff) != 0;
  uVar5 = param_4;
  iVar2 = param_3;
  if (param_1 != 0 || bVar1) {
    uVar5 = param_2;
    iVar2 = param_1;
  }
  uVar3 = uVar5;
  if ((((param_1 != 0 || bVar1) && (param_3 != 0 || (param_4 & 0x7fffffff) != 0)) &&
      ((unaff_r4 != in_r12 || (iVar2 == 0 && (uVar5 & 0xfffff) == 0)))) &&
     ((uVar4 != in_r12 ||
      (iVar2 = param_3, uVar3 = param_4, param_3 == 0 && (param_4 & 0xfffff) == 0)))) {
    return (ulonglong)((uVar5 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
  }
  return CONCAT44(uVar3,iVar2) | 0x7ff8000000000000;
}



/* Function: FUN_0001a3a8 @ 0001a3a8 */

ulonglong FUN_0001a3a8(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint extraout_r2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint extraout_r12;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined8 uVar16;
  
  uVar16 = CONCAT44(param_2,param_1);
  uVar11 = 0x7ff;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar13 = uVar6 == 0;
  if (!bVar13) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar13 = unaff_r5 == 0;
  }
  if (!bVar13) {
    bVar13 = uVar6 == 0x7ff;
  }
  if (!bVar13) {
    bVar13 = unaff_r5 == 0x7ff;
  }
  if (bVar13) {
    uVar16 = FUN_0001a53c();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar11 = extraout_r12;
  }
  uVar8 = (uint)((ulonglong)uVar16 >> 0x20);
  uVar2 = (uint)uVar16;
  iVar7 = uVar6 - unaff_r5;
  if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
    uVar6 = (uVar8 ^ param_4) & 0x80000000 | uVar8 & 0xfffff;
    bVar14 = SCARRY4(iVar7,uVar11 >> 1);
    uVar8 = iVar7 + (uVar11 >> 1);
    bVar13 = (int)uVar8 < 0;
    bVar15 = uVar8 == 0;
    if (!bVar15 && bVar13 == bVar14) {
      bVar14 = SBORROW4(uVar11,uVar8);
      bVar13 = (int)(uVar11 - uVar8) < 0;
      bVar15 = uVar11 == uVar8;
    }
    if (!bVar15 && bVar13 == bVar14) {
      return CONCAT44(uVar6 | uVar8 * 0x100000,uVar2);
    }
    uVar6 = uVar6 | 0x100000;
    uVar4 = 0;
    bVar15 = SBORROW4(uVar8,1);
    uVar8 = uVar8 - 1;
    bVar13 = uVar8 == 0;
    uVar11 = uVar8;
  }
  else {
    uVar4 = (param_4 & 0xfffff) << 8 | 0x10000000 | param_3 >> 0x18;
    uVar11 = param_3 << 8;
    uVar9 = (uVar8 & 0xfffff) << 8 | 0x10000000 | uVar2 >> 0x18;
    uVar2 = uVar2 * 0x100;
    uVar6 = (uVar8 ^ param_4) & 0x80000000;
    bVar13 = uVar4 <= uVar9;
    if (uVar9 == uVar4) {
      bVar13 = uVar11 <= uVar2;
    }
    iVar7 = iVar7 + (uint)bVar13;
    uVar8 = iVar7 + 0x3fd;
    if (!bVar13) {
      uVar4 = uVar4 >> 1;
      uVar11 = (uint)((byte)(param_3 >> 0x18) & 1) << 0x1f | (param_3 & 0xffffff) << 7;
    }
    uVar10 = uVar2 - uVar11;
    uVar9 = uVar9 - (uVar4 + (uVar2 < uVar11));
    uVar5 = uVar4 >> 1;
    uVar3 = (uint)((byte)uVar4 & 1) << 0x1f | uVar11 >> 1;
    uVar2 = 0x100000;
    uVar11 = 0x80000;
    while( true ) {
      bVar13 = uVar3 <= uVar10;
      if (uVar5 < uVar9 || uVar9 - uVar5 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11;
        uVar9 = uVar9 - (uVar5 + !bVar13);
      }
      uVar4 = uVar5 >> 1;
      uVar3 = (uint)((byte)uVar5 & 1) << 0x1f | uVar3 >> 1;
      bVar13 = uVar3 <= uVar10;
      if (uVar4 < uVar9 || uVar9 - uVar4 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11 >> 1;
        uVar9 = uVar9 - (uVar4 + !bVar13);
      }
      uVar12 = uVar5 >> 2;
      uVar1 = (uint)((byte)uVar4 & 1) << 0x1f | uVar3 >> 1;
      bVar13 = uVar1 <= uVar10;
      if (uVar12 < uVar9 || uVar9 - uVar12 < (uint)bVar13) {
        uVar10 = uVar10 - uVar1;
        uVar2 = uVar2 | uVar11 >> 2;
        uVar9 = uVar9 - (uVar12 + !bVar13);
      }
      uVar5 = uVar5 >> 3;
      uVar3 = (uint)((byte)uVar12 & 1) << 0x1f | uVar1 >> 1;
      bVar13 = uVar3 <= uVar10;
      if (uVar5 < uVar9 || uVar9 - uVar5 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11 >> 3;
        uVar9 = uVar9 - (uVar5 + !bVar13);
      }
      uVar4 = uVar9 | uVar10;
      if (uVar4 == 0) break;
      uVar9 = uVar9 << 4 | uVar10 >> 0x1c;
      uVar10 = uVar10 << 4;
      uVar5 = uVar5 << 3 | uVar3 >> 0x1d;
      uVar3 = (uVar1 >> 1) << 3;
      uVar11 = uVar11 >> 4;
      if (uVar11 == 0) {
        if ((uVar6 & 0x100000) != 0) goto LAB_0001a4e8;
        uVar6 = uVar6 | uVar2;
        uVar2 = 0;
        uVar11 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar2;
      uVar2 = 0;
    }
LAB_0001a4e8:
    bVar14 = 0xfc < uVar8;
    bVar15 = SBORROW4(uVar8,0xfd);
    uVar12 = iVar7 + 0x300;
    bVar13 = uVar12 == 0;
    uVar11 = uVar12;
    if (bVar14 && !bVar13) {
      bVar14 = 0x6ff < uVar12;
      bVar15 = SBORROW4(uVar12,0x700);
      uVar11 = iVar7 - 0x400;
      bVar13 = uVar12 == 0x700;
    }
    if (!bVar14 || bVar13) {
      bVar13 = uVar5 <= uVar9;
      if (uVar9 == uVar5) {
        bVar13 = uVar3 <= uVar10;
      }
      if (uVar9 == uVar5 && uVar10 == uVar3) {
        bVar13 = (bool)((byte)uVar2 & 1);
      }
      return CONCAT44(uVar6 + uVar8 * 0x100000 + (uint)CARRY4(uVar2,(uint)bVar13),uVar2 + bVar13);
    }
  }
  if (!bVar13 && (int)uVar11 < 0 == bVar15) {
    return (ulonglong)(uVar6 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if ((int)uVar8 < -0x35) {
    return (ulonglong)(uVar6 & 0x80000000) << 0x20;
  }
  uVar11 = -uVar8;
  uVar9 = uVar11 - 0x20;
  if (0x1f < (int)uVar11) {
    uVar8 = uVar2 >> (uVar9 & 0xff) | uVar6 << (0x20 - uVar9 & 0xff);
    uVar11 = (uVar6 >> (uVar9 & 0xff) & ~((uVar6 & 0x80000000) >> (uVar9 & 0xff))) -
             ((int)uVar8 >> 0x1f);
    if ((uVar4 == 0 && uVar2 << (0x20 - uVar9 & 0xff) == 0) && (uVar8 & 0x7fffffff) == 0) {
      uVar11 = uVar11 & ~(uVar8 >> 0x1f);
    }
    return CONCAT44(uVar6,uVar11) & 0x80000000ffffffff;
  }
  if (uVar11 - 0x14 != 0 && -0xd < (int)uVar9) {
    uVar8 = 0xc - (uVar11 - 0x14);
    uVar11 = uVar2 << (uVar8 & 0xff);
    uVar2 = uVar2 >> (0x20 - uVar8 & 0xff) | uVar6 << (uVar8 & 0xff);
    uVar8 = uVar2 + -((int)uVar11 >> 0x1f);
    if (uVar4 == 0 && (uVar11 & 0x7fffffff) == 0) {
      uVar8 = uVar8 & ~(uVar11 >> 0x1f);
    }
    return CONCAT44((uVar6 & 0x80000000) + (uint)CARRY4(uVar2,-((int)uVar11 >> 0x1f)),uVar8);
  }
  uVar9 = uVar2 << (uVar8 + 0x20 & 0xff);
  uVar2 = uVar2 >> (uVar11 & 0xff) | uVar6 << (uVar8 + 0x20 & 0xff);
  uVar8 = uVar2 + -((int)uVar9 >> 0x1f);
  if (uVar4 == 0 && (uVar9 & 0x7fffffff) == 0) {
    uVar8 = uVar8 & ~(uVar9 >> 0x1f);
  }
  return CONCAT44((uVar6 & 0x80000000) + ((uVar6 & 0x7fffffff) >> (uVar11 & 0xff)) +
                  (uint)CARRY4(uVar2,-((int)uVar9 >> 0x1f)),uVar8);
}



/* Function: FUN_0001a53c @ 0001a53c */

ulonglong FUN_0001a53c(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r4;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  
  uVar2 = in_r12 & param_4 >> 0x14;
  uVar3 = param_2;
  if (unaff_r4 != in_r12 || uVar2 != in_r12) {
    if (unaff_r4 == in_r12) {
      if ((param_1 == 0 && (param_2 & 0xfffff) == 0) &&
         (param_1 = param_3, uVar3 = param_4, uVar2 != in_r12)) {
LAB_0001a384:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else if (uVar2 == in_r12) {
      param_1 = param_3;
      uVar3 = param_4;
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
LAB_0001a338:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
    }
    else {
      if ((param_1 != 0 || (param_2 & 0x7fffffff) != 0) &&
          (param_3 != 0 || (param_4 & 0x7fffffff) != 0)) {
        if (unaff_r4 == 0) {
          uVar3 = param_2 & 0x80000000;
          do {
            iVar1 = param_1 >> 0x1f;
            param_1 = param_1 << 1;
            param_2 = param_2 * 2 - iVar1;
          } while ((param_2 & 0x100000) == 0);
          param_2 = param_2 | uVar3;
          if (uVar2 != 0) {
            return CONCAT44(param_2,param_1);
          }
        }
        do {
          iVar1 = param_3 >> 0x1f;
          param_3 = param_3 << 1;
          param_4 = param_4 * 2 - iVar1;
        } while ((param_4 & 0x100000) == 0);
        return CONCAT44(param_2,param_1);
      }
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) goto LAB_0001a384;
      if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) goto LAB_0001a338;
    }
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}



/* Function: FUN_0001a5bc @ 0001a5bc */

uint FUN_0001a5bc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (((int)(param_2 << 1) >> 0x15 == -1 || (int)(param_4 << 1) >> 0x15 == -1) &&
     ((((int)(param_2 << 1) >> 0x15 == -1 && (param_1 != 0 || (param_2 & 0xfffff) != 0)) ||
      (((int)(param_4 << 1) >> 0x15 == -1 && (param_3 != 0 || (param_4 & 0xfffff) != 0)))))) {
    return 1;
  }
  bVar3 = (param_2 & 0x7fffffff) == 0;
  bVar2 = param_1 == 0 && bVar3;
  if (param_1 == 0 && bVar3) {
    bVar2 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
  }
  if (!bVar2) {
    bVar2 = param_2 == param_4;
  }
  if (!bVar2 || param_1 != param_3) {
    uVar1 = param_2 ^ param_4;
    bVar3 = uVar1 == 0;
    if (-1 < (int)uVar1) {
      bVar3 = param_2 == param_4;
    }
    bVar2 = -1 < (int)uVar1 && param_4 <= param_2;
    if (bVar3) {
      bVar2 = param_3 <= param_1;
    }
    param_4 = (int)param_4 >> 0x1f;
    if (!bVar2) {
      param_4 = ~param_4;
    }
    return param_4 | 1;
  }
  return 0;
}



/* Function: FUN_0001a644 @ 0001a644 */

void FUN_0001a644(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0001a660(param_3,param_4,param_1,param_2);
  return;
}



/* Function: FUN_0001a660 @ 0001a660 */

undefined4 FUN_0001a660(undefined4 param_1)

{
  FUN_0001a5bc();
  return param_1;
}



/* Function: FUN_0001a674 @ 0001a674 */

undefined1 FUN_0001a674(void)

{
  undefined1 in_ZR;
  
  FUN_0001a660();
  return in_ZR;
}



/* Function: FUN_0001a688 @ 0001a688 */

bool FUN_0001a688(void)

{
  undefined1 in_CY;
  
  FUN_0001a660();
  return !(bool)in_CY;
}



/* Function: FUN_0001a69c @ 0001a69c */

bool FUN_0001a69c(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_0001a660();
  return !(bool)in_CY || (bool)in_ZR;
}



/* Function: FUN_0001a6b0 @ 0001a6b0 */

bool FUN_0001a6b0(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_0001a644();
  return !(bool)in_CY || (bool)in_ZR;
}



/* Function: FUN_0001a6c4 @ 0001a6c4 */

bool FUN_0001a6c4(void)

{
  undefined1 in_CY;
  
  FUN_0001a644();
  return !(bool)in_CY;
}



/* Function: FUN_0001a6d8 @ 0001a6d8 */

uint FUN_0001a6d8(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar2) {
      return 0;
    }
    uVar1 = iVar2 >> 0x15;
    uVar3 = -uVar1 - 0x3e1;
    if (uVar1 < 0xfffffc20 && uVar3 != 0) {
      uVar1 = (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
      if ((param_2 & 0x80000000) != 0) {
        uVar1 = -uVar1;
      }
      return uVar1;
    }
  }
  else if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    return 0;
  }
  param_2 = param_2 & 0x80000000;
  if (param_2 == 0) {
    param_2 = 0x7fffffff;
  }
  return param_2;
}



/* Function: FUN_0001a734 @ 0001a734 */

uint FUN_0001a734(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  bool bVar4;
  bool bVar5;
  
  uVar2 = param_2 * 2;
  bVar5 = uVar2 < 0x70000000;
  uVar3 = uVar2 + 0x90000000;
  uVar1 = uVar3;
  if (!bVar5) {
    in_r12 = uVar2 + 0x8fe00000;
    uVar1 = in_r12;
  }
  bVar4 = uVar1 == 0;
  if (!bVar5 && uVar3 >= 0x200000) {
    bVar4 = in_r12 == 0x1fc00000;
  }
  if (((bVar5 || uVar3 < 0x200000) || 0x1fc00000 < in_r12) || bVar4) {
    if ((param_2 & 0x40000000) != 0) {
      if (((int)uVar2 >> 0x15 == -1) && (param_1 != 0 || (param_2 & 0xfffff) != 0)) {
        return 0x7fc00000;
      }
      return param_2 & 0x80000000 | 0x7f800000;
    }
    if ((int)uVar3 < -0x2e00000) {
      return param_2 & 0x80000000;
    }
    uVar3 = 0x18 - (uVar2 + 0x92e00000 >> 0x15);
    uVar2 = param_1 >> (uVar3 & 0xff);
    if (param_1 << (0x20 - uVar3 & 0xff) != 0) {
      uVar2 = uVar2 | 1;
    }
    uVar1 = param_2 & 0x1fffff | 0x100000;
    param_1 = uVar2 | uVar1 << (0x20 - uVar3 & 0xff);
    uVar3 = (uVar1 >> (uVar3 & 0xff)) << 1;
  }
  uVar2 = (param_2 & 0x80000000 | param_1 >> 0x1d) + uVar3 * 4 + (uint)(0x7fffffff < param_1 * 8);
  if (param_1 * 8 == 0x80000000) {
    uVar2 = uVar2 & 0xfffffffe;
  }
  return uVar2;
}



/* Function: FUN_0001a978 @ 0001a978 */

uint FUN_0001a978(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 & 0x80000000;
  if ((int)uVar3 < 0) {
    param_1 = -param_1;
  }
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = LZCOUNT(param_1);
  uVar2 = uVar1 - 8;
  iVar4 = ((uVar3 | 0x4b000000) - 0x800000) + uVar2 * -0x800000;
  if (7 < uVar1) {
    uVar3 = 0 << (uVar2 & 0xff);
    uVar1 = iVar4 + (param_1 << (uVar2 & 0xff)) + (0U >> (0x20 - uVar2 & 0xff)) +
            (uint)(0x7fffffff < uVar3);
    if (uVar3 == 0x80000000) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    return uVar1;
  }
  uVar3 = param_1 << uVar1 + 0x18;
  uVar1 = (iVar4 + (param_1 >> (0x20 - (uVar1 + 0x18) & 0xff))) - ((int)uVar3 >> 0x1f);
  if ((uVar3 & 0x7fffffff) == 0) {
    uVar1 = uVar1 & ~(uVar3 >> 0x1f);
  }
  return uVar1;
}



/* Function: FUN_0001aa24 @ 0001aa24 */

uint FUN_0001aa24(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  uVar4 = param_1 >> 0x17 & 0xff;
  bVar10 = uVar4 == 0;
  if (!bVar10) {
    param_4 = param_2 >> 0x17 & 0xff;
    bVar10 = param_4 == 0;
  }
  if (!bVar10) {
    bVar10 = uVar4 == 0xff;
  }
  if (!bVar10) {
    bVar10 = param_4 == 0xff;
  }
  if (bVar10) {
    param_4 = param_2 >> 0x17 & 0xff;
    if (uVar4 == 0xff || param_4 == 0xff) {
      uVar3 = param_2;
      if (param_1 != 0 && param_1 != 0x80000000) {
        uVar3 = param_1;
      }
      uVar6 = uVar3;
      if (((((param_1 == 0 || param_1 == 0x80000000) || param_2 == 0) || param_2 == 0x80000000) ||
          ((uVar4 == 0xff && ((uVar3 & 0x7fffff) != 0)))) ||
         ((param_4 == 0xff && (uVar6 = param_2, (param_2 & 0x7fffff) != 0)))) {
        return uVar6 | 0x7fc00000;
      }
      uVar3 = uVar3 ^ param_2;
      goto LAB_0001aba0;
    }
    if ((param_1 & 0x7fffffff) == 0 || (param_2 & 0x7fffffff) == 0) {
      return (param_1 ^ param_2) & 0x80000000;
    }
    bVar10 = uVar4 == 0;
    uVar3 = param_1 & 0x80000000;
    while( true ) {
      if (bVar10) {
        param_1 = param_1 << 1;
        bVar10 = (param_1 & 0x800000) == 0;
      }
      if (!bVar10) break;
      uVar4 = uVar4 - 1;
    }
    param_1 = param_1 | uVar3;
    bVar10 = param_4 == 0;
    uVar3 = param_2 & 0x80000000;
    while( true ) {
      if (bVar10) {
        param_2 = param_2 << 1;
        bVar10 = (param_2 & 0x800000) == 0;
      }
      if (!bVar10) break;
      param_4 = param_4 - 1;
    }
    param_2 = param_2 | uVar3;
  }
  iVar5 = uVar4 + param_4;
  uVar4 = param_1 ^ param_2;
  bVar10 = param_1 << 9 == 0;
  if (!bVar10) {
    param_2 = param_2 << 9;
    bVar10 = param_2 == 0;
  }
  if (bVar10) {
    if (param_1 << 9 == 0) {
      param_2 = param_2 << 9;
    }
    uVar3 = uVar4 & 0x80000000 | param_1 & 0x7fffff | param_2 >> 9;
    bVar11 = SBORROW4(iVar5,0x7f);
    iVar7 = iVar5 + -0x7f;
    bVar10 = iVar7 == 0;
    iVar8 = iVar7;
    if (!bVar10 && 0x7e < iVar5) {
      bVar11 = SBORROW4(0xff,iVar7);
      iVar8 = -iVar7 + 0xff;
      bVar10 = -iVar7 == -0xff;
    }
    if (!bVar10 && iVar8 < 0 == bVar11) {
      return uVar3 | iVar7 * 0x800000;
    }
    uVar3 = uVar3 | 0x800000;
    uVar9 = 0;
    bVar11 = SBORROW4(iVar7,1);
    uVar6 = iVar5 - 0x80;
    bVar10 = uVar6 == 0;
    uVar4 = uVar6;
  }
  else {
    lVar2 = (ulonglong)(param_2 >> 5 | 0x8000000) *
            (ulonglong)((param_1 & 0x7fffff) << 4 | 0x8000000);
    bVar10 = (uint)((ulonglong)lVar2 >> 0x20) < 0x800000;
    if (bVar10) {
      lVar2 = lVar2 * 2;
    }
    uVar9 = (uint)lVar2;
    uVar3 = uVar4 & 0x80000000 | (uint)((ulonglong)lVar2 >> 0x20);
    uVar6 = iVar5 - (bVar10 + 0x7f);
    bVar11 = SBORROW4(uVar6,0xfd);
    bVar10 = uVar6 == 0xfd;
    uVar4 = uVar6 - 0xfd;
    if (uVar6 < 0xfe) {
      uVar4 = uVar3 + uVar6 * 0x800000 + (uint)(0x7fffffff < uVar9);
      if (uVar9 == 0x80000000) {
        uVar4 = uVar4 & 0xfffffffe;
      }
      return uVar4;
    }
  }
  if (bVar10 || (int)uVar4 < 0 != bVar11) {
    if (-0x19 < (int)uVar6) {
      uVar1 = (uVar3 << 1) >> (-uVar6 & 0xff);
      uVar4 = uVar3 << (uVar6 + 0x20 & 0xff);
      uVar3 = (uVar3 & 0x80000000 | uVar1 >> 1) + (uint)((byte)uVar1 & 1);
      if (uVar9 == 0 && (uVar4 & 0x7fffffff) == 0) {
        uVar3 = uVar3 & ~(uVar4 >> 0x1f);
      }
      return uVar3;
    }
    return uVar3 & 0x80000000;
  }
LAB_0001aba0:
  return uVar3 & 0x80000000 | 0x7f800000;
}



/* Function: FUN_0001ad1c @ 0001ad1c */

uint FUN_0001ad1c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 << 1 < 0x7f000000) {
    return 0;
  }
  uVar1 = (param_1 & 0x7fffffff) >> 0x17;
  uVar2 = 0x9e - uVar1;
  if (uVar1 < 0x9f && uVar2 != 0) {
    uVar1 = (param_1 << 8 | 0x80000000) >> (uVar2 & 0xff);
    if ((param_1 & 0x80000000) != 0) {
      uVar1 = -uVar1;
    }
    return uVar1;
  }
  if ((uVar2 == 0xffffff9f) && ((param_1 & 0x7fffff) != 0)) {
    return 0;
  }
  param_1 = param_1 & 0x80000000;
  if (param_1 == 0) {
    param_1 = 0x7fffffff;
  }
  return param_1;
}



/* Function: FUN_0001ad78 @ 0001ad78 */

undefined8 FUN_0001ad78(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_1 * param_4 + param_3 * param_2,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



/* Function: FUN_0001ad8c @ 0001ad8c */

void FUN_0001ad8c(void)

{
  FUN_0001adfc();
  return;
}



/* Function: FUN_0001ada8 @ 0001ada8 */

void FUN_0001ada8(void)

{
  raise(8);
  return;
}



/* Function: FUN_0001adb8 @ 0001adb8 */

void FUN_0001adb8(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = FUN_0001c7ac();
  lVar2 = lVar2 * CONCAT44(param_4,param_3);
  uVar1 = (uint)lVar2;
  *param_5 = param_1 - uVar1;
  param_5[1] = param_2 - ((int)((ulonglong)lVar2 >> 0x20) + (uint)(param_1 < uVar1));
  return;
}



/* Function: FUN_0001adfc @ 0001adfc */

void FUN_0001adfc(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = FUN_0001c330();
  lVar2 = lVar2 * CONCAT44(param_4,param_3);
  uVar1 = (uint)lVar2;
  *param_5 = param_1 - uVar1;
  param_5[1] = param_2 - ((int)((ulonglong)lVar2 >> 0x20) + (uint)(param_1 < uVar1));
  return;
}



/* Function: FUN_0001ae40 @ 0001ae40 */

undefined4 FUN_0001ae40(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: FUN_0001ae8c @ 0001ae8c */

undefined4 FUN_0001ae8c(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: FUN_0001aed8 @ 0001aed8 */

int FUN_0001aed8(uint *param_1)

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



/* Function: FUN_0001af1c @ 0001af1c */

undefined4 FUN_0001af1c(uint param_1,uint param_2,undefined4 param_3,int param_4)

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
LAB_0001b314:
    do {
      while( true ) {
        local_58 = *puVar8;
        if (local_58 == 0) goto LAB_0001b320;
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
        FUN_0001ae40(param_3,0,0xf,0,&local_30);
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
LAB_0001b214:
              FUN_0001ae40(param_3,0,0xd,0,&local_30);
              *(uint **)(param_2 + 0x28) = puVar6;
              *(uint *)(param_2 + 0x20) = local_30;
              *(int *)(param_2 + 0x24) = local_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar5 = *(uint *)(param_2 + 0x20);
          FUN_0001ae40(param_3,0,0xd,0,&local_30);
          if ((uVar5 == local_30) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            local_30 = FUN_0001aed8(puVar6);
            FUN_0001ae8c(param_3,0,0xf,0,&local_30);
LAB_0001b2d8:
            uVar4 = 0;
            local_30 = param_2;
            goto LAB_0001b394;
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
              if (local_58 == uVar5) goto LAB_0001b214;
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
          FUN_0001ae40(param_3,0,0xd,0,&local_30);
          if ((uVar10 == local_30) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar6 + 1;
            *(uint *)(param_2 + 0x28) = uVar5;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar6) {
              local_30 = FUN_0001aed8(puVar6 + uVar5 + 1);
              FUN_0001ae8c(param_3,0,0xf,0,&local_30);
              goto LAB_0001b2d8;
            }
            bVar9 = true;
          }
        }
        if ((int)*puVar6 < 0) {
          puVar6 = puVar6 + 1;
        }
        puVar8 = puVar6 + uVar5 + 1;
        goto LAB_0001b314;
      }
      if (uVar7 == 0) {
        bVar1 = false;
      }
      puVar8 = puVar6 + 1;
    } while (!bVar1);
    uVar5 = FUN_0001aed8(puVar6);
    *(uint **)(param_2 + 0x38) = puVar8;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      local_30 = uVar5;
      goto LAB_0001b394;
    }
  }
  else {
    bVar9 = false;
LAB_0001b320:
    iVar3 = FUN_0001bf78(param_3,&local_3c);
    if (iVar3 == 0) {
      if (!bVar9) {
        return 8;
      }
      FUN_0001ae40(param_3,0,0xf,0,&local_30);
      FUN_0001ae8c(param_3,0,0xe,0,&local_30);
      uVar4 = 0xf;
      local_30 = *(uint *)(DAT_0001b3ac + 0x1b384);
LAB_0001b394:
      FUN_0001ae8c(param_3,0,uVar4,0,&local_30);
      return 7;
    }
  }
  return 9;
}



/* Function: FUN_0001b3c8 @ 0001b3c8 */

undefined4 FUN_0001b3c8(int param_1,int param_2)

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
  
  iVar8 = DAT_0001b57c + 0x1b3dc;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_0001b580) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_0001b588);
    local_2c[0] = *(int *)(iVar8 + DAT_0001b584) - iVar2 >> 3;
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
        uVar3 = FUN_0001aed8(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_0001aed8(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_0001b554;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_0001aed8(iVar10);
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
        uVar5 = FUN_0001aed8();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_0001aed8();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_0001b58c;
      if (((uVar9 == 0) || (iVar2 = DAT_0001b590, uVar9 == 1)) || (iVar2 = DAT_0001b594, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_0001b554:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}



/* Function: FUN_0001b598 @ 0001b598 */

void FUN_0001b598(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      FUN_0001bd18(param_1 + 0x12);
    }
    else {
      FUN_0001bd28();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_0001bd38(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_0001bd48(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_0001bdd0(param_1 + 0x8c);
  return;
}



/* Function: FUN_0001b604 @ 0001b604 */

int FUN_0001b604(code *param_1,undefined4 param_2,int param_3)

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
    iVar1 = FUN_0001b3c8(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_0001b6c0:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    FUN_0001ae8c(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_0001b6c0;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_0001b598(&local_2c0);
  return iVar1;
}



/* Function: FUN_0001b6d8 @ 0001b6d8 */

int FUN_0001b6d8(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_0001b3c8(param_1,local_228);
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
    FUN_0001bd04(&local_264);
  }
  return 9;
}



/* Function: FUN_0001b810 @ 0001b810 */

void FUN_0001b810(int param_1,int param_2)

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
    iVar1 = FUN_0001b3c8(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_0001b85c;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 != 7) {
LAB_0001b85c:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = FUN_0001bd04(param_2 + 4);
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
    iVar2 = FUN_0001b3c8(iVar1,local_228);
    if (iVar2 != 0) goto LAB_0001b900;
    iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&local_268);
  } while (iVar2 == 8);
  FUN_0001b598(&local_268);
  if (iVar2 == 6) {
    FUN_0001b810(iVar1,iVar3);
  }
LAB_0001b900:
                    /* WARNING: Could not recover jumptable at 0x0001b908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x1b868)(9);
  return;
}



/* Function: FUN_0001b998 @ 0001b998 */

undefined4 FUN_0001b998(uint *param_1,undefined4 param_2,uint param_3,int param_4)

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
        FUN_0001bd30();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        FUN_0001bd20(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_0001bd40(param_1 + 0x34);
    }
    if (bVar8) {
      FUN_0001bd20(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0001bd30(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_0001bb34;
      FUN_0001bd40(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_0001bb34:
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
      FUN_0001bd18(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0001bd28(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_0001bd38(local_b0);
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
          FUN_0001bd8c(param_1 + 0x6c);
        }
        FUN_0001bd8c(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_0001bd48(auStack_130);
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
        FUN_0001bde4(param_1 + 0x8c);
      }
      FUN_0001bde4(local_30);
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
      FUN_0001bdd0(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: FUN_0001bd04 @ 0001bd04 */

undefined8 FUN_0001bd04(undefined8 *param_1)

{
  return *param_1;
}



/* Function: FUN_0001bd18 @ 0001bd18 */

undefined4 FUN_0001bd18(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0001bd20 @ 0001bd20 */

void FUN_0001bd20(undefined8 *param_1)

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



/* Function: FUN_0001bd28 @ 0001bd28 */

undefined4 FUN_0001bd28(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0001bd30 @ 0001bd30 */

void FUN_0001bd30(undefined8 *param_1)

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



/* Function: FUN_0001bd38 @ 0001bd38 */

void FUN_0001bd38(void)

{
  return;
}



/* Function: FUN_0001bd40 @ 0001bd40 */

void FUN_0001bd40(undefined8 *param_1)

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



/* Function: FUN_0001bd48 @ 0001bd48 */

int FUN_0001bd48(int param_1)

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



/* Function: FUN_0001bd8c @ 0001bd8c */

int FUN_0001bd8c(int param_1)

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



/* Function: FUN_0001bdd0 @ 0001bdd0 */

int FUN_0001bdd0(int param_1)

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



/* Function: FUN_0001bde4 @ 0001bde4 */

int FUN_0001bde4(int param_1)

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



/* Function: FUN_0001beac @ 0001beac */

uint FUN_0001beac(uint *param_1)

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



/* Function: FUN_0001bf04 @ 0001bf04 */

void FUN_0001bf04(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: FUN_0001bf4c @ 0001bf4c */

undefined4 FUN_0001bf4c(void)

{
  int in_r3;
  
  FUN_0001ae40();
  return *(undefined4 *)(in_r3 + 0x48);
}



/* Function: FUN_0001bf78 @ 0001bf78 */

undefined4 FUN_0001bf78(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
LAB_0001bf90:
  do {
    while( true ) {
      uVar1 = FUN_0001beac(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        FUN_0001ae40(param_1,0,0xe,0,&local_24,uVar7,param_3);
        FUN_0001ae8c(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      FUN_0001ae40(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_0001c0c8:
      piVar6 = &local_24;
      FUN_0001ae8c(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_0001beac(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = FUN_0001b998(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_0001bf90;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      FUN_0001ae40(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_0001c0c8;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_0001beac(param_2);
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
          FUN_0001ae40(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_0001beac(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_0001c0c8;
        }
        if (uVar1 == 0xb3) {
          FUN_0001beac(param_2);
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
        FUN_0001beac(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_0001beac(param_2);
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
            FUN_0001beac(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_0001beac(param_2);
          }
          goto LAB_0001c2cc;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_0001c2cc:
      uVar2 = 1;
    }
    iVar5 = FUN_0001b998(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: FUN_0001c2f0 @ 0001c2f0 */

void FUN_0001c2f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_0001bf78(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}



/* Function: FUN_0001c330 @ 0001c330 */

undefined8 FUN_0001c330(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  if ((int)param_2 < 0) {
    bVar12 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + bVar12);
    uVar8 = 0xffffffff;
  }
  else {
    uVar8 = 0;
  }
  if ((int)param_4 < 0) {
    bVar12 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(param_4 + bVar12);
    uVar8 = ~uVar8;
  }
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        param_3 = FUN_0001cbb8(1,0);
      }
      iVar4 = LZCOUNT(param_3);
      if (iVar4 == 0) {
        iVar4 = param_2 - param_3;
        uVar6 = 1;
      }
      else {
        param_3 = param_3 << iVar4;
        uVar7 = param_2 >> (0x20U - iVar4 & 0xff);
        uVar2 = param_3 >> 0x10;
        uVar9 = param_1 >> (0x20U - iVar4 & 0xff) | param_2 << iVar4;
        param_1 = param_1 << iVar4;
        FUN_0001cc64(uVar7,uVar2);
        iVar4 = FUN_0001cbb8(uVar7,uVar2);
        uVar10 = uVar9 >> 0x10 | extraout_r1_01 << 0x10;
        uVar7 = (param_3 & 0xffff) * iVar4;
        iVar1 = iVar4;
        if (uVar10 < uVar7) {
          bVar12 = CARRY4(uVar10,param_3);
          uVar10 = uVar10 + param_3;
          iVar1 = iVar4 + -1;
          if ((!bVar12) && (uVar10 < uVar7)) {
            iVar1 = iVar4 + -2;
            uVar10 = uVar10 + param_3;
          }
        }
        FUN_0001cc64(uVar10 - uVar7,uVar2);
        uVar2 = FUN_0001cbb8(uVar10 - uVar7,uVar2);
        uVar9 = uVar9 & 0xffff | extraout_r1_02 << 0x10;
        uVar7 = (param_3 & 0xffff) * uVar2;
        uVar6 = uVar2;
        if (uVar9 < uVar7) {
          bVar12 = CARRY4(uVar9,param_3);
          uVar9 = uVar9 + param_3;
          uVar6 = uVar2 - 1;
          if ((!bVar12) && (uVar9 < uVar7)) {
            uVar6 = uVar2 - 2;
            uVar9 = uVar9 + param_3;
          }
        }
        iVar4 = uVar9 - uVar7;
        uVar6 = uVar6 | iVar1 << 0x10;
      }
      uVar2 = param_3 >> 0x10;
      FUN_0001cc64(iVar4,uVar2);
      iVar1 = FUN_0001cbb8(iVar4,uVar2);
      uVar9 = param_1 >> 0x10 | extraout_r1_03 << 0x10;
      uVar7 = (param_3 & 0xffff) * iVar1;
      iVar4 = iVar1;
      if (uVar9 < uVar7) {
        bVar12 = CARRY4(uVar9,param_3);
        uVar9 = uVar9 + param_3;
        iVar4 = iVar1 + -1;
        if ((!bVar12) && (uVar9 < uVar7)) {
          iVar4 = iVar1 + -2;
          uVar9 = uVar9 + param_3;
        }
      }
      FUN_0001cc64(uVar9 - uVar7,uVar2);
      uVar7 = FUN_0001cbb8(uVar9 - uVar7,uVar2);
      uVar10 = param_1 & 0xffff | extraout_r1_04 << 0x10;
      uVar9 = (param_3 & 0xffff) * uVar7;
      uVar2 = uVar7;
      if (uVar10 < uVar9) {
        uVar2 = uVar7 - 1;
        if ((!CARRY4(uVar10,param_3)) && (uVar10 + param_3 < uVar9)) {
          uVar2 = uVar7 - 2;
        }
      }
      uVar2 = uVar2 | iVar4 << 0x10;
      goto LAB_0001c784;
    }
    iVar4 = LZCOUNT(param_3);
    if (iVar4 != 0) {
      param_3 = param_3 << iVar4;
      param_2 = param_1 >> (0x20U - iVar4 & 0xff) | param_2 << iVar4;
    }
    uVar2 = param_3 >> 0x10;
    if (iVar4 != 0) {
      param_1 = param_1 << iVar4;
    }
    FUN_0001cc64(param_2,uVar2);
    iVar1 = FUN_0001cbb8(param_2,uVar2);
    uVar9 = param_1 >> 0x10 | extraout_r1 << 0x10;
    uVar7 = (param_3 & 0xffff) * iVar1;
    iVar4 = iVar1;
    if (uVar9 < uVar7) {
      bVar12 = CARRY4(uVar9,param_3);
      uVar9 = uVar9 + param_3;
      iVar4 = iVar1 + -1;
      if ((!bVar12) && (uVar9 < uVar7)) {
        iVar4 = iVar1 + -2;
        uVar9 = uVar9 + param_3;
      }
    }
    FUN_0001cc64(uVar9 - uVar7,uVar2);
    uVar7 = FUN_0001cbb8(uVar9 - uVar7,uVar2);
    uVar10 = param_1 & 0xffff | extraout_r1_00 << 0x10;
    uVar9 = (param_3 & 0xffff) * uVar7;
    uVar2 = uVar7;
    if (uVar10 < uVar9) {
      uVar2 = uVar7 - 1;
      if ((!CARRY4(uVar10,param_3)) && (uVar10 + param_3 < uVar9)) {
        uVar2 = uVar7 - 2;
      }
    }
    uVar2 = uVar2 | iVar4 << 0x10;
LAB_0001c774:
    uVar6 = 0;
  }
  else {
    if (param_4 <= param_2) {
      iVar4 = LZCOUNT(param_4);
      if (iVar4 != 0) {
        uVar9 = 0x20 - iVar4;
        uVar7 = param_2 >> (uVar9 & 0xff);
        uVar5 = param_3 >> (uVar9 & 0xff) | param_4 << iVar4;
        uVar2 = uVar5 >> 0x10;
        uVar9 = param_1 >> (uVar9 & 0xff) | param_2 << iVar4;
        FUN_0001cc64(uVar7,uVar2);
        iVar3 = FUN_0001cbb8(uVar7,uVar2);
        uVar7 = (uVar5 & 0xffff) * iVar3;
        uVar10 = uVar9 >> 0x10 | extraout_r1_05 << 0x10;
        iVar1 = iVar3;
        if (uVar10 < uVar7) {
          bVar12 = CARRY4(uVar10,uVar5);
          uVar10 = uVar10 + uVar5;
          iVar1 = iVar3 + -1;
          if ((!bVar12) && (uVar10 < uVar7)) {
            iVar1 = iVar3 + -2;
            uVar10 = uVar10 + uVar5;
          }
        }
        FUN_0001cc64(uVar10 - uVar7,uVar2);
        uVar7 = FUN_0001cbb8(uVar10 - uVar7,uVar2);
        uVar10 = uVar9 & 0xffff | extraout_r1_06 << 0x10;
        uVar9 = (uVar5 & 0xffff) * uVar7;
        uVar2 = uVar7;
        if (uVar10 < uVar9) {
          bVar12 = CARRY4(uVar10,uVar5);
          uVar10 = uVar10 + uVar5;
          uVar2 = uVar7 - 1;
          if ((!bVar12) && (uVar10 < uVar9)) {
            uVar10 = uVar10 + uVar5;
            uVar2 = uVar7 - 2;
          }
        }
        uVar10 = uVar10 - uVar9;
        uVar2 = uVar2 | iVar1 << 0x10;
        uVar7 = uVar2 >> 0x10;
        uVar9 = (param_3 << iVar4) >> 0x10;
        uVar11 = uVar2 & ~(uVar7 << 0x10);
        uVar6 = param_3 << iVar4 & ~(uVar9 << 0x10);
        uVar5 = uVar11 * uVar6;
        uVar6 = uVar7 * uVar6;
        uVar11 = uVar9 * uVar11;
        iVar1 = uVar7 * uVar9;
        uVar7 = uVar6 + uVar11;
        if (CARRY4(uVar6,uVar11)) {
          iVar1 = iVar1 + 0x10000;
        }
        uVar9 = uVar7 * 0x10000;
        uVar7 = iVar1 + (uVar7 >> 0x10) + (uint)CARRY4(uVar5,uVar9);
        if ((uVar7 < uVar10 || uVar7 == uVar10) &&
           (uVar6 = 0, uVar5 + uVar9 <= param_1 << iVar4 || uVar7 != uVar10)) goto LAB_0001c784;
        uVar2 = uVar2 - 1;
        goto LAB_0001c774;
      }
      bVar12 = param_4 <= param_2;
      if (param_2 <= param_4) {
        bVar12 = param_3 <= param_1;
      }
      if (bVar12) {
        uVar2 = 1;
        uVar6 = 0;
        goto LAB_0001c784;
      }
    }
    uVar6 = 0;
    uVar2 = 0;
  }
LAB_0001c784:
  if (uVar8 != 0) {
    bVar12 = uVar2 != 0;
    uVar2 = -uVar2;
    uVar6 = -(uVar6 + bVar12);
  }
  return CONCAT44(uVar6,uVar2);
}



/* Function: FUN_0001c7ac @ 0001c7ac */

undefined8 FUN_0001c7ac(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        param_3 = FUN_0001cbb8(1,0);
      }
      iVar3 = LZCOUNT(param_3);
      if (iVar3 == 0) {
        iVar3 = param_2 - param_3;
        uVar8 = 1;
      }
      else {
        param_3 = param_3 << iVar3;
        uVar5 = param_2 >> (0x20U - iVar3 & 0xff);
        uVar7 = param_3 >> 0x10;
        uVar6 = param_1 >> (0x20U - iVar3 & 0xff) | param_2 << iVar3;
        param_1 = param_1 << iVar3;
        FUN_0001cc64(uVar5,uVar7);
        iVar3 = FUN_0001cbb8(uVar5,uVar7);
        uVar5 = uVar6 >> 0x10 | extraout_r1_01 << 0x10;
        uVar4 = (param_3 & 0xffff) * iVar3;
        iVar1 = iVar3;
        if (uVar5 < uVar4) {
          bVar10 = CARRY4(uVar5,param_3);
          uVar5 = uVar5 + param_3;
          iVar1 = iVar3 + -1;
          if ((!bVar10) && (uVar5 < uVar4)) {
            iVar1 = iVar3 + -2;
            uVar5 = uVar5 + param_3;
          }
        }
        FUN_0001cc64(uVar5 - uVar4,uVar7);
        uVar7 = FUN_0001cbb8(uVar5 - uVar4,uVar7);
        uVar6 = uVar6 & 0xffff | extraout_r1_02 << 0x10;
        uVar5 = (param_3 & 0xffff) * uVar7;
        uVar8 = uVar7;
        if (uVar6 < uVar5) {
          bVar10 = CARRY4(uVar6,param_3);
          uVar6 = uVar6 + param_3;
          uVar8 = uVar7 - 1;
          if ((!bVar10) && (uVar6 < uVar5)) {
            uVar8 = uVar7 - 2;
            uVar6 = uVar6 + param_3;
          }
        }
        iVar3 = uVar6 - uVar5;
        uVar8 = uVar8 | iVar1 << 0x10;
      }
      uVar7 = param_3 >> 0x10;
      FUN_0001cc64(iVar3,uVar7);
      iVar1 = FUN_0001cbb8(iVar3,uVar7);
      uVar6 = param_1 >> 0x10 | extraout_r1_03 << 0x10;
      uVar5 = (param_3 & 0xffff) * iVar1;
      iVar3 = iVar1;
      if (uVar6 < uVar5) {
        bVar10 = CARRY4(uVar6,param_3);
        uVar6 = uVar6 + param_3;
        iVar3 = iVar1 + -1;
        if ((!bVar10) && (uVar6 < uVar5)) {
          iVar3 = iVar1 + -2;
          uVar6 = uVar6 + param_3;
        }
      }
      FUN_0001cc64(uVar6 - uVar5,uVar7);
      uVar5 = FUN_0001cbb8(uVar6 - uVar5,uVar7);
      uVar4 = param_1 & 0xffff | extraout_r1_04 << 0x10;
      uVar6 = (param_3 & 0xffff) * uVar5;
      uVar7 = uVar5;
      if (uVar4 < uVar6) {
        uVar7 = uVar5 - 1;
        if ((!CARRY4(uVar4,param_3)) && (uVar4 + param_3 < uVar6)) {
          uVar7 = uVar5 - 2;
        }
      }
      uVar7 = uVar7 | iVar3 << 0x10;
      goto LAB_0001cba8;
    }
    iVar3 = LZCOUNT(param_3);
    uVar6 = param_2;
    uVar5 = param_3;
    uVar7 = param_3;
    if (iVar3 != 0) {
      uVar7 = param_1 >> (0x20U - iVar3 & 0xff);
      uVar5 = param_3 << iVar3;
      uVar6 = uVar7 | param_2 << iVar3;
    }
    uVar4 = uVar5 >> 0x10;
    uVar9 = param_1;
    if (iVar3 != 0) {
      uVar9 = param_1 << iVar3;
    }
    FUN_0001cc64(uVar6,uVar4,uVar7,iVar3,param_1,param_2,param_3);
    iVar1 = FUN_0001cbb8(uVar6,uVar4);
    uVar6 = uVar9 >> 0x10 | extraout_r1 << 0x10;
    uVar7 = (uVar5 & 0xffff) * iVar1;
    iVar3 = iVar1;
    if (uVar6 < uVar7) {
      bVar10 = CARRY4(uVar6,uVar5);
      uVar6 = uVar6 + uVar5;
      iVar3 = iVar1 + -1;
      if ((!bVar10) && (uVar6 < uVar7)) {
        iVar3 = iVar1 + -2;
        uVar6 = uVar6 + uVar5;
      }
    }
    FUN_0001cc64(uVar6 - uVar7,uVar4);
    uVar6 = FUN_0001cbb8(uVar6 - uVar7,uVar4);
    uVar9 = uVar9 & 0xffff | extraout_r1_00 << 0x10;
    uVar4 = (uVar5 & 0xffff) * uVar6;
    uVar7 = uVar6;
    if (uVar9 < uVar4) {
      uVar7 = uVar6 - 1;
      if ((!CARRY4(uVar9,uVar5)) && (uVar9 + uVar5 < uVar4)) {
        uVar7 = uVar6 - 2;
      }
    }
    uVar7 = uVar7 | iVar3 << 0x10;
LAB_0001cb98:
    uVar8 = 0;
  }
  else {
    if (param_4 <= param_2) {
      iVar3 = LZCOUNT(param_4);
      if (iVar3 != 0) {
        uVar4 = 0x20 - iVar3;
        uVar8 = param_3 >> (uVar4 & 0xff) | param_4 << iVar3;
        uVar5 = param_2 >> (uVar4 & 0xff);
        uVar6 = param_1 >> (uVar4 & 0xff);
        uVar7 = uVar8 >> 0x10;
        uVar9 = uVar6 | param_2 << iVar3;
        FUN_0001cc64(uVar5,uVar7,uVar4,uVar6,param_1,param_2,param_3);
        iVar1 = extraout_r1_05;
        iVar2 = FUN_0001cbb8(uVar5,uVar7);
        uVar6 = uVar9 >> 0x10 | iVar1 << 0x10;
        param_3 = param_3 << iVar3;
        uVar5 = (uVar8 & 0xffff) * iVar2;
        iVar1 = iVar2;
        if (uVar6 < uVar5) {
          bVar10 = CARRY4(uVar6,uVar8);
          uVar6 = uVar6 + uVar8;
          iVar1 = iVar2 + -1;
          if ((!bVar10) && (uVar6 < uVar5)) {
            iVar1 = iVar2 + -2;
            uVar6 = uVar6 + uVar8;
          }
        }
        FUN_0001cc64(uVar6 - uVar5,uVar7);
        iVar2 = extraout_r1_06;
        uVar5 = FUN_0001cbb8(uVar6 - uVar5,uVar7);
        uVar4 = uVar9 & 0xffff | iVar2 << 0x10;
        uVar6 = (uVar8 & 0xffff) * uVar5;
        uVar7 = uVar5;
        if (uVar4 < uVar6) {
          bVar10 = CARRY4(uVar4,uVar8);
          uVar4 = uVar4 + uVar8;
          uVar7 = uVar5 - 1;
          if ((!bVar10) && (uVar4 < uVar6)) {
            uVar4 = uVar4 + uVar8;
            uVar7 = uVar5 - 2;
          }
        }
        uVar4 = uVar4 - uVar6;
        uVar7 = uVar7 | iVar1 << 0x10;
        uVar5 = uVar7 >> 0x10;
        uVar6 = param_3 >> 0x10;
        uVar8 = uVar7 & ~(uVar5 << 0x10);
        param_3 = param_3 & ~(uVar6 << 0x10);
        uVar9 = uVar8 * param_3;
        param_3 = uVar5 * param_3;
        uVar8 = uVar6 * uVar8;
        iVar1 = uVar5 * uVar6;
        uVar5 = param_3 + uVar8;
        if (CARRY4(param_3,uVar8)) {
          iVar1 = iVar1 + 0x10000;
        }
        uVar6 = uVar5 * 0x10000;
        uVar5 = iVar1 + (uVar5 >> 0x10) + (uint)CARRY4(uVar9,uVar6);
        if ((uVar5 < uVar4 || uVar5 == uVar4) &&
           (uVar8 = 0, uVar9 + uVar6 <= param_1 << iVar3 || uVar5 != uVar4)) goto LAB_0001cba8;
        uVar7 = uVar7 - 1;
        goto LAB_0001cb98;
      }
      bVar10 = param_4 <= param_2;
      if (param_2 <= param_4) {
        bVar10 = param_3 <= param_1;
      }
      if (bVar10) {
        uVar7 = 1;
        uVar8 = 0;
        goto LAB_0001cba8;
      }
    }
    uVar8 = 0;
    uVar7 = 0;
  }
LAB_0001cba8:
  return CONCAT44(uVar8,uVar7);
}



/* Function: FUN_0001cbb8 @ 0001cbb8 */

uint FUN_0001cbb8(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    FUN_0001ada8();
    return 0;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    return param_1 >> (0x1fU - LZCOUNT(param_2) & 0xff);
  }
  uVar1 = param_2 << (LZCOUNT(param_2) - LZCOUNT(param_1) & 0xffU);
  uVar3 = 1 << (LZCOUNT(param_2) - LZCOUNT(param_1) & 0xffU);
  uVar2 = 0;
  while( true ) {
    if (uVar1 <= param_1) {
      param_1 = param_1 - uVar1;
      uVar2 = uVar2 | uVar3;
    }
    if (uVar1 >> 1 <= param_1) {
      param_1 = param_1 - (uVar1 >> 1);
      uVar2 = uVar2 | uVar3 >> 1;
    }
    if (uVar1 >> 2 <= param_1) {
      param_1 = param_1 - (uVar1 >> 2);
      uVar2 = uVar2 | uVar3 >> 2;
    }
    if (uVar1 >> 3 <= param_1) {
      param_1 = param_1 - (uVar1 >> 3);
      uVar2 = uVar2 | uVar3 >> 3;
    }
    bVar4 = param_1 == 0;
    if (!bVar4) {
      uVar3 = uVar3 >> 4;
      bVar4 = uVar3 == 0;
    }
    if (bVar4) break;
    uVar1 = uVar1 >> 4;
  }
  return uVar2;
}



/* Function: FUN_0001cc64 @ 0001cc64 */

void FUN_0001cc64(void)

{
  FUN_0001cbb8();
  return;
}



/* Function: memmove @ 00020000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: snprintf @ 00020004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_begin_cleanup @ 0002000c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 00020010 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 00020014 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: puts @ 00020018 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_finalize @ 0002001c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getuid @ 00020020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 00020024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 00020028 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 0002002c */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtod @ 00020030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double strtod(char *__nptr,char **__endptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: modf @ 00020034 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double modf(double __x,double *__iptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strstr @ 00020038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 0002003c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: localtime @ 00020040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 00020044 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: time @ 00020048 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 0002004c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 00020050 */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sprintf @ 00020054 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: atoi @ 00020058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 0002005c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: raise @ 00020060 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 00020064 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



