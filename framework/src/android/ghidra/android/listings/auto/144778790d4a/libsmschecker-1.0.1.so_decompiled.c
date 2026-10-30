/* Function: putchar @ 00010d8c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_putchar_00027124)(__c);
  return iVar1;
}



/* Function: printf @ 00010d98 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00027128)(__format);
  return iVar1;
}



/* Function: memmove @ 00010da4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmove_0002712c)(__dest);
  return pvVar1;
}



/* Function: __cxa_begin_cleanup @ 00010db0 */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_00027130)();
  return;
}



/* Function: qsort @ 00010dbc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void qsort(void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar)

{
  (*(code *)PTR_qsort_00027134)(__base);
  return;
}



/* Function: memcpy @ 00010dc8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00027138)(__dest);
  return pvVar1;
}



/* Function: getuid @ 00010de0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
  __uid_t _Var1;
  
  _Var1 = (*(code *)PTR_getuid_00027140)();
  return _Var1;
}



/* Function: malloc @ 00010dec */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00027144)(__size);
  return pvVar1;
}



/* Function: strtoul @ 00010df8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
  uVar1 = (*(code *)PTR_strtoul_00027148)(__nptr);
  return uVar1;
}



/* Function: fflush @ 00010e04 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fflush_0002714c)(__stream);
  return iVar1;
}



/* Function: strncasecmp @ 00010e10 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncasecmp_00027150)(__s1);
  return iVar1;
}



/* Function: abort @ 00010e1c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_00027154)();
  return;
}



/* Function: __stack_chk_fail @ 00010e28 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00027158)();
  return;
}



/* Function: calloc @ 00010e34 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_calloc_0002715c)(__nmemb);
  return pvVar1;
}



/* Function: modf @ 00010e40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double modf(double __x,double *__iptr)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  
  uVar1 = (*(code *)PTR_modf_00027160)(SUB84(__x,0),__iptr);
  return (double)CONCAT44(extraout_s1,uVar1);
}



/* Function: fseek @ 00010e4c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fseek_00027164)(__stream);
  return iVar1;
}



/* Function: strstr @ 00010e58 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strstr_00027168)(__haystack);
  return pcVar1;
}



/* Function: strncmp @ 00010e64 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncmp_0002716c)(__s1);
  return iVar1;
}



/* Function: strncpy @ 00010e70 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strncpy_00027170)(__dest);
  return pcVar1;
}



/* Function: strcasecmp @ 00010e7c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcasecmp_00027174)(__s1);
  return iVar1;
}



/* Function: __cxa_type_match @ 00010e88 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_00027178)();
  return;
}



/* Function: realloc @ 00010e94 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_realloc_0002717c)(__ptr);
  return pvVar1;
}



/* Function: memcmp @ 00010ea0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_00027180)(__s1);
  return iVar1;
}



/* Function: fread @ 00010eac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fread_00027184)(__ptr);
  return sVar1;
}



/* Function: fopen @ 00010eb8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_00027188)(__filename);
  return pFVar1;
}



/* Function: memset @ 00010ec4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_0002718c)(__s);
  return pvVar1;
}



/* Function: ftell @ 00010ed0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long ftell(FILE *__stream)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_ftell_00027190)(__stream);
  return lVar1;
}



/* Function: fclose @ 00010edc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_00027194)(__stream);
  return iVar1;
}



/* Function: strcmp @ 00010ee8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00027198)(__s1);
  return iVar1;
}



/* Function: __gnu_Unwind_Find_exidx @ 00010ef4 */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_0002719c)();
  return;
}



/* Function: sprintf @ 00010f00 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sprintf_000271a0)(__s);
  return iVar1;
}



/* Function: localtime_r @ 00010f0c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime_r(time_t *__timer,tm *__tp)

{
  tm *ptVar1;
  
  ptVar1 = (tm *)(*(code *)PTR_localtime_r_000271a4)(__timer);
  return ptVar1;
}



/* Function: fwrite @ 00010f18 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_000271a8)(__ptr);
  return sVar1;
}



/* Function: strlen @ 00010f24 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_000271ac)(__s);
  return sVar1;
}



/* Function: strchr @ 00010f30 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strchr_000271b0)(__s);
  return pcVar1;
}



/* Function: __aeabi_atexit @ 00010f3c */

void __aeabi_atexit(void)

{
  (*(code *)PTR___aeabi_atexit_000271b4)();
  return;
}



/* Function: raise @ 00010f48 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_raise_000271b8)(__sig);
  return iVar1;
}



/* Function: free @ 00010f54 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_000271bc)(__ptr);
  return;
}



/* Function: entry @ 00010f60 */

void processEntry entry(void)

{
  (*(code *)PTR___cxa_finalize_0002713c)(DAT_00010f6c);
  return;
}



/* Function: FUN_00010f70 @ 00010f70 */

void FUN_00010f70(int *param_1)

{
  (**(code **)(*param_1 + 0x3c))();
  return;
}



/* Function: FUN_00010f7c @ 00010f7c */

void FUN_00010f7c(int *param_1)

{
  (**(code **)(*param_1 + 0x178))();
  return;
}



/* Function: FUN_00010f88 @ 00010f88 */

void FUN_00010f88(int *param_1)

{
  (**(code **)(*param_1 + 400))();
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_deleteObject @ 00010f98 */

void Java_com_tencent_tccdb_SmsChecker_deleteObject(void)

{
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_newObject @ 00010f9c */

void Java_com_tencent_tccdb_SmsChecker_newObject(void)

{
  FUN_00011b90();
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_nativeGetFinalAction @ 00010fa4 */

int Java_com_tencent_tccdb_SmsChecker_nativeGetFinalAction
              (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined1 local_6c;
  
  iVar2 = FUN_00011b90();
  if (iVar2 == 0) {
    iVar2 = 2;
  }
  else {
    uVar3 = (**(code **)(*param_1 + 0x7c))(param_1,param_4);
    iVar2 = FUN_00010f70(param_1);
    if (iVar2 == 0) {
      iVar8 = DAT_000110d0 + 0x10fda;
      uVar4 = FUN_00010f7c(param_1,uVar3,DAT_000110d4 + 0x10fdc,iVar8);
      iVar2 = FUN_00010f70(param_1);
      if (iVar2 == 0) {
        uVar4 = FUN_00010f88(param_1,param_4,uVar4);
        uVar5 = FUN_00010f7c(param_1,uVar3,DAT_000110d8 + 0x11002,iVar8,uVar4);
        iVar2 = FUN_00010f70(param_1);
        if (iVar2 == 0) {
          uVar5 = FUN_00010f88(param_1,param_4,uVar5);
          uVar6 = FUN_00010f7c(param_1,uVar3,DAT_000110dc + 0x11028,iVar8,uVar4,uVar5);
          iVar2 = FUN_00010f70(param_1);
          if (iVar2 == 0) {
            uVar6 = FUN_00010f88(param_1,param_4,uVar6);
            uVar7 = FUN_00010f7c(param_1,uVar3,DAT_000110e0 + 0x1104e,iVar8,uVar4,uVar5,uVar6);
            iVar2 = FUN_00010f70(param_1);
            if (iVar2 == 0) {
              uVar7 = FUN_00010f88(param_1,param_4,uVar7);
              uVar3 = FUN_00010f7c(param_1,uVar3,DAT_000110e4 + 0x11074,iVar8,uVar4,uVar5,uVar6,
                                   uVar7);
              local_6d = (undefined1)uVar7;
              local_6e = (undefined1)uVar6;
              local_6f = (undefined1)uVar5;
              local_70 = (undefined1)uVar4;
              iVar2 = FUN_00010f70(param_1);
              if (iVar2 == 0) {
                uVar1 = FUN_00010f88(param_1,param_4,uVar3);
                memset(&local_70,0,0x58);
                local_6c = uVar1;
                iVar2 = FUN_00011f9c(&local_70);
                return iVar2;
              }
            }
          }
        }
      }
    }
    iVar2 = 1;
  }
  return -iVar2;
}



/* Function: FUN_000110e8 @ 000110e8 */

int FUN_000110e8(int *param_1,void *param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  
  uVar4 = (**(code **)(*param_1 + 0x7c))(param_1,param_3);
  iVar5 = FUN_00010f70(param_1);
  if (iVar5 == 0) {
    iVar9 = DAT_0001122c + 0x11110;
    uVar6 = FUN_00010f7c(param_1,uVar4,DAT_00011230 + 0x11112,iVar9);
    iVar5 = FUN_00010f70(param_1);
    if (iVar5 == 0) {
      uVar6 = (**(code **)(*param_1 + 0x17c))(param_1,param_3,uVar6);
      uVar7 = FUN_00010f7c(param_1,uVar4,DAT_00011234 + 0x11140,iVar9);
      iVar5 = FUN_00010f70(param_1);
      if (iVar5 == 0) {
        uVar7 = (**(code **)(*param_1 + 0x17c))(param_1,param_3,uVar7);
        iVar9 = DAT_00011238 + 0x1116a;
        uVar8 = FUN_00010f7c(param_1,uVar4,DAT_0001123c + 0x1116c,iVar9);
        iVar5 = FUN_00010f70(param_1);
        if (iVar5 == 0) {
          uVar1 = FUN_00010f88(param_1,param_3,uVar8);
          uVar8 = FUN_00010f7c(param_1,uVar4,DAT_00011240 + 0x11194,iVar9);
          iVar5 = FUN_00010f70(param_1);
          if (iVar5 == 0) {
            uVar2 = FUN_00010f88(param_1,param_3,uVar8);
            uVar4 = FUN_00010f7c(param_1,uVar4,DAT_00011244 + 0x111ba,iVar9);
            iVar5 = FUN_00010f70(param_1);
            if (iVar5 == 0) {
              uVar3 = FUN_00010f88(param_1,param_3,uVar4);
              memset(param_2,0,0x130);
              iVar5 = FUN_00019020(param_1,uVar6,param_2,0x13);
              if (iVar5 != 0) {
                return iVar5;
              }
              iVar5 = FUN_00019020(param_1,uVar7,(int)param_2 + 0x14,0x118);
              if (iVar5 != 0) {
                return iVar5;
              }
              *(undefined1 *)((int)param_2 + DAT_00011248) = uVar1;
              *(undefined1 *)((int)param_2 + 0x12e) = uVar2;
              *(undefined1 *)((int)param_2 + DAT_0001124c) = uVar3;
              return 0;
            }
          }
        }
      }
    }
  }
  return -1;
}



/* Function: FUN_00011250 @ 00011250 */

void FUN_00011250(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x74))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_0001126c @ 0001126c */

int FUN_0001126c(int *param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  int local_40;
  uint local_3c;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,DAT_000113a0 + 0x1127e);
  iVar2 = FUN_00010f70(param_1);
  if (iVar2 == 0) {
    iVar8 = DAT_000113a4 + 0x11298;
    uVar3 = (**(code **)(*param_1 + 0x84))(param_1,uVar1,iVar8,DAT_000113a8 + 0x1129c);
    iVar2 = FUN_00010f70(param_1);
    if (iVar2 == 0) {
      uVar4 = (**(code **)(*param_1 + 0x18))(param_1,DAT_000113ac + 0x112ba);
      iVar2 = FUN_00010f70(param_1);
      if (iVar2 == 0) {
        uVar5 = (**(code **)(*param_1 + 0x84))(param_1,uVar4,iVar8,DAT_000113b0 + 0x112d4);
        iVar2 = FUN_00010f70(param_1);
        if (iVar2 == 0) {
          local_3c = (uint)(byte)param_3[2];
          if (10 < local_3c) {
            local_3c = 10;
          }
          uVar6 = (**(code **)(*param_1 + 0x2b0))(param_1,local_3c,uVar4,0);
          iVar2 = FUN_00010f70(param_1);
          if (iVar2 == 0) {
            puVar9 = param_3;
            for (local_40 = 0; local_40 < (int)local_3c; local_40 = local_40 + 1) {
              uVar7 = FUN_00011250(param_1,uVar4,uVar5,puVar9[8],*(undefined4 *)(puVar9 + 0xc));
              iVar2 = FUN_00010f70(param_1);
              puVar9 = puVar9 + 8;
              if (iVar2 != 0) goto LAB_0001138c;
              (**(code **)(*param_1 + 0x2b8))(param_1,uVar6,local_40,uVar7);
              (**(code **)(*param_1 + 0x5c))(param_1,uVar7);
            }
            iVar2 = FUN_00011250(param_1,uVar1,uVar3,*param_3,param_3[1],param_3[2],
                                 (int)(char)param_3[3],param_3[4],uVar6);
            if (iVar2 != 0) {
              FUN_000117b8(param_1,param_2);
              return 0;
            }
LAB_0001138c:
            iVar2 = 4;
            goto LAB_0001138e;
          }
        }
      }
    }
  }
  iVar2 = 1;
LAB_0001138e:
  return -iVar2;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_nativeGetRuleFileInfo @ 000113b4 */

void Java_com_tencent_tccdb_SmsChecker_nativeGetRuleFileInfo
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_14c;
  undefined1 auStack_148 [256];
  undefined4 local_48;
  undefined4 local_44;
  undefined1 auStack_40 [36];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001149c + 0x113c6);
  iVar1 = FUN_00011b90();
  if (iVar1 == 0) {
    iVar1 = -2;
    goto LAB_00011482;
  }
  iVar1 = FUN_00019020(param_1,param_4,auStack_148,0x100);
  if (iVar1 != 0) goto LAB_00011482;
  local_14c = iVar1;
  iVar1 = FUN_00011eec(&local_14c,&local_48,auStack_148);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x18))(param_1,DAT_000114a0 + 0x1140a);
    iVar3 = FUN_00010f70(param_1);
    if (iVar3 == 0) {
      uVar4 = (**(code **)(*param_1 + 0x84))
                        (param_1,uVar2,DAT_000114a4 + 0x11424,DAT_000114a8 + 0x11426);
      iVar3 = FUN_00010f70(param_1);
      if (iVar3 != 0) goto LAB_00011478;
      uVar5 = (**(code **)(*param_1 + 0x29c))(param_1,auStack_40);
      iVar3 = FUN_00010f70(param_1);
      if (iVar3 == 0) {
        iVar3 = FUN_00011250(param_1,uVar2,uVar4,local_48,local_44,uVar5);
        if (iVar3 != 0) {
          FUN_000117b8(param_1,param_5);
          goto LAB_0001147c;
        }
        goto LAB_00011478;
      }
      iVar1 = 4;
    }
    else {
LAB_00011478:
      iVar1 = 1;
    }
    iVar1 = -iVar1;
  }
LAB_0001147c:
  FUN_00011e54(&local_14c);
LAB_00011482:
  if (local_1c != **(int **)(DAT_000114ac + 0x1148c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_finishChargeChecker @ 000114b0 */

void Java_com_tencent_tccdb_SmsChecker_finishChargeChecker(void)

{
  FUN_0001201c();
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_checkChargeSms @ 000114b8 */

void Java_com_tencent_tccdb_SmsChecker_checkChargeSms
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_1a4 [2];
  byte local_1a2;
  undefined1 auStack_14c [304];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001151c + 0x114c4);
  iVar1 = FUN_000110e8(param_1,auStack_14c,param_4);
  if (iVar1 == 0) {
    iVar2 = FUN_000121c4(auStack_14c,auStack_1a4);
    for (iVar1 = 0; (iVar1 < 10 && (iVar1 < (int)(uint)local_1a2)); iVar1 = iVar1 + 1) {
    }
    iVar1 = FUN_0001126c(param_1,param_5,auStack_1a4);
    if (iVar1 == 0) {
      iVar1 = iVar2;
    }
  }
  if (local_1c != **(int **)(DAT_00011520 + 0x1150c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_reloadChargeRule @ 00011524 */

void Java_com_tencent_tccdb_SmsChecker_reloadChargeRule
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_11c [256];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001157c + 0x11532);
  iVar1 = FUN_00011b90();
  if (iVar1 == 0) {
    FUN_0001201c();
    iVar1 = -2;
  }
  else {
    iVar1 = FUN_00019020(param_1,param_5,auStack_11c,0x100);
    if (iVar1 == 0) {
      iVar1 = FUN_000120d8(param_4,auStack_11c);
    }
  }
  if (local_1c != **(int **)(DAT_00011580 + 0x1156e)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_initChargeChecker @ 00011584 */

void Java_com_tencent_tccdb_SmsChecker_initChargeChecker
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_11c [256];
  int local_1c;
  
  local_1c = **(int **)(DAT_000115dc + 0x11592);
  iVar1 = FUN_00011b90();
  if (iVar1 == 0) {
    FUN_0001201c();
    iVar1 = -2;
  }
  else {
    iVar1 = FUN_00019020(param_1,param_5,auStack_11c,0x100);
    if (iVar1 == 0) {
      iVar1 = FUN_00012024(param_4,auStack_11c);
    }
  }
  if (local_1c != **(int **)(DAT_000115e0 + 0x115ce)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_finishSmsChecker @ 000115e4 */

void Java_com_tencent_tccdb_SmsChecker_finishSmsChecker(void)

{
  FUN_00012134();
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_checkSmsSys @ 000115ec */

void Java_com_tencent_tccdb_SmsChecker_checkSmsSys
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_1a4 [2];
  byte local_1a2;
  undefined1 auStack_14c [304];
  int local_1c;
  
  local_1c = **(int **)(DAT_00011650 + 0x115f8);
  iVar1 = FUN_000110e8(param_1,auStack_14c,param_4);
  if (iVar1 == 0) {
    iVar2 = FUN_00012470(auStack_14c,auStack_1a4);
    for (iVar1 = 0; (iVar1 < 10 && (iVar1 < (int)(uint)local_1a2)); iVar1 = iVar1 + 1) {
    }
    iVar1 = FUN_0001126c(param_1,param_5,auStack_1a4);
    if (iVar1 == 0) {
      iVar1 = iVar2;
    }
  }
  if (local_1c != **(int **)(DAT_00011654 + 0x11640)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_reloadModRule @ 00011658 */

void Java_com_tencent_tccdb_SmsChecker_reloadModRule
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_11c [256];
  int local_1c;
  
  local_1c = **(int **)(DAT_000116b0 + 0x11666);
  iVar1 = FUN_00011b90();
  if (iVar1 == 0) {
    FUN_00012134();
    iVar1 = -2;
  }
  else {
    iVar1 = FUN_00019020(param_1,param_5,auStack_11c,0x100);
    if (iVar1 == 0) {
      iVar1 = FUN_00012908(param_4,auStack_11c);
    }
  }
  if (local_1c != **(int **)(DAT_000116b4 + 0x116a2)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: Java_com_tencent_tccdb_SmsChecker_initSmsChecker @ 000116b8 */

void Java_com_tencent_tccdb_SmsChecker_initSmsChecker
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_11c [256];
  int local_1c;
  
  local_1c = **(int **)(DAT_00011710 + 0x116c6);
  iVar1 = FUN_00011b90();
  if (iVar1 == 0) {
    FUN_00012134();
    iVar1 = -2;
  }
  else {
    iVar1 = FUN_00019020(param_1,param_5,auStack_11c,0x100);
    if (iVar1 == 0) {
      iVar1 = FUN_000128f4(param_4,auStack_11c);
    }
  }
  if (local_1c != **(int **)(DAT_00011714 + 0x11702)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: FUN_00011718 @ 00011718 */

void FUN_00011718(int *param_1)

{
  (**(code **)(*param_1 + 0x7c))();
  return;
}



/* Function: FUN_00011724 @ 00011724 */

void FUN_00011724(int *param_1)

{
  (**(code **)(*param_1 + 0x84))();
  return;
}



/* Function: FUN_00011798 @ 00011798 */

void FUN_00011798(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0xf8))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_000117b8 @ 000117b8 */

void FUN_000117b8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00011718();
  iVar2 = FUN_00011724(param_1,uVar1,DAT_000117f0 + 0x117ce,DAT_000117f4 + 0x117d0,param_4);
  if (iVar2 != 0) {
    FUN_00011798(param_1,param_2,iVar2,param_3);
  }
  (**(code **)(*param_1 + 0x5c))(param_1,uVar1);
  return;
}



/* Function: FUN_000117f8 @ 000117f8 */

void FUN_000117f8(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x8c))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00011818 @ 00011818 */

void FUN_00011818(int *param_1,undefined4 param_2)

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
  local_1c[0] = **(int **)(DAT_00011b30 + 0x11824);
  if (*(char *)(DAT_00011b34 + 0x11832) == '\0') {
    _Var2 = getuid();
    uVar1 = FUN_00011718(param_1,param_2);
    iVar3 = FUN_00010f70(param_1);
    if (iVar3 == 0) {
      uVar1 = FUN_00011724(param_1,uVar1,DAT_00011b38 + 0x1185e,DAT_00011b3c + 0x11860);
      iVar3 = FUN_00010f70(param_1);
      if (iVar3 == 0) {
        uVar1 = FUN_000117f8(param_1,param_2,uVar1);
        iVar3 = FUN_00010f70(param_1);
        if (iVar3 == 0) {
          uVar4 = FUN_00011718(param_1,uVar1);
          iVar3 = FUN_00010f70(param_1);
          if (iVar3 == 0) {
            uVar5 = FUN_00011724(param_1,uVar4,DAT_00011b40 + 0x118aa,DAT_00011b44 + 0x118ac);
            iVar3 = FUN_00010f70(param_1);
            if (iVar3 == 0) {
              uVar5 = FUN_000117f8(param_1,uVar1,uVar5,_Var2);
              iVar3 = FUN_00010f70(param_1);
              if (iVar3 == 0) {
                iVar3 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar5);
                __format = (char *)(DAT_00011b48 + 0x118f0);
                for (local_80 = 0; local_80 < iVar3; local_80 = local_80 + 1) {
                  uVar6 = (**(code **)(*param_1 + 0x2b4))(param_1,uVar5,local_80);
                  iVar7 = FUN_00010f70(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar6,0);
                  (**(code **)(*param_1 + 0x2a8))(param_1,uVar6,uVar8);
                  uVar8 = FUN_00011724(param_1,uVar4,DAT_00011b4c + 0x1193c,DAT_00011b50 + 0x1193e);
                  iVar7 = FUN_00010f70(param_1);
                  if (iVar7 != 0) break;
                  uVar6 = FUN_000117f8(param_1,uVar1,uVar8,uVar6,0x40);
                  iVar7 = FUN_00010f70(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = FUN_00011718(param_1,uVar6);
                  iVar7 = FUN_00010f70(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = (**(code **)(*param_1 + 0x178))
                                    (param_1,uVar8,DAT_00011b54 + 0x11992,DAT_00011b58 + 0x11994);
                  iVar7 = FUN_00010f70(param_1);
                  if (iVar7 != 0) break;
                  uVar6 = (**(code **)(*param_1 + 0x17c))(param_1,uVar6,uVar8);
                  iVar7 = FUN_00010f70(param_1);
                  if (iVar7 != 0) break;
                  iVar7 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar6);
                  for (local_84 = 0; local_84 < iVar7; local_84 = local_84 + 1) {
                    uVar8 = (**(code **)(*param_1 + 0x2b4))(param_1,uVar6,local_84);
                    iVar9 = FUN_00010f70(param_1);
                    if (iVar9 != 0) goto LAB_00011b18;
                    uVar10 = FUN_00011718(param_1,uVar8);
                    iVar9 = FUN_00010f70(param_1);
                    if (iVar9 != 0) goto LAB_00011b18;
                    uVar10 = FUN_00011724(param_1,uVar10,DAT_00011b5c + 0x11a18,
                                          DAT_00011b60 + 0x11a1a);
                    iVar9 = FUN_00010f70(param_1);
                    if (iVar9 != 0) goto LAB_00011b18;
                    uVar8 = FUN_000117f8(param_1,uVar8,uVar10);
                    iVar9 = FUN_00010f70(param_1);
                    if (iVar9 != 0) goto LAB_00011b18;
                    uVar10 = (**(code **)(*param_1 + 0x2e0))(param_1,uVar8,0);
                    uVar11 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar8);
                    memset(local_2c,0,0x10);
                    iVar9 = DAT_00011b64;
                    FUN_0001749c(uVar10,uVar11,local_2c);
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
                      iVar12 = strcmp(acStack_50,(char *)(iVar9 + 0x11a80 + iVar14 * 0x21));
                      if (iVar12 == 0) {
                        (**(code **)(*param_1 + 0x300))(param_1,uVar8,uVar10,0);
                        uVar1 = 1;
                        *(undefined1 *)(DAT_00011b68 + 0x11ace) = 1;
                        goto LAB_00011b1a;
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
LAB_00011b18:
    uVar1 = 0;
  }
LAB_00011b1a:
  if (local_1c[0] == **(int **)(DAT_00011b6c + 0x11b22)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}



/* Function: FUN_00011b70 @ 00011b70 */

void FUN_00011b70(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x1d8))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00011b90 @ 00011b90 */

bool FUN_00011b90(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,DAT_00011bc8 + 0x11b9e);
  uVar2 = (**(code **)(*param_1 + 0x1c4))
                    (param_1,uVar1,DAT_00011bcc + 0x11bb6,DAT_00011bd0 + 0x11bb0);
  iVar3 = FUN_00011b70(param_1,uVar1,uVar2);
  return iVar3 == 1;
}



/* Function: FUN_00011bd4 @ 00011bd4 */

int FUN_00011bd4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = 1;
  if ((0x68 < param_2) && (iVar1 = 2, 0 < param_4)) {
    if (param_5 * param_4 <= param_3 - param_2) {
      return 0;
    }
    iVar1 = 3;
  }
  return -iVar1;
}



/* Function: FUN_00011bf8 @ 00011bf8 */

undefined4 FUN_00011bf8(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if ((FILE *)*param_1 == (FILE *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    fflush((FILE *)*param_1);
    uVar1 = 0;
  }
  return uVar1;
}



/* Function: FUN_00011c10 @ 00011c10 */

int FUN_00011c10(undefined4 *param_1)

{
  int iVar1;
  long lVar2;
  
  if ((FILE *)*param_1 == (FILE *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = fseek((FILE *)*param_1,0,2);
    if (iVar1 == 0) {
      lVar2 = ftell((FILE *)*param_1);
      return lVar2;
    }
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_00011c38 @ 00011c38 */

long FUN_00011c38(undefined4 *param_1)

{
  long lVar1;
  
  if ((FILE *)*param_1 == (FILE *)0x0) {
    lVar1 = -1;
  }
  else {
    lVar1 = ftell((FILE *)*param_1);
  }
  return lVar1;
}



/* Function: FUN_00011c4c @ 00011c4c */

int FUN_00011c4c(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 != (char *)0x0) {
    iVar1 = strncmp(param_2,(char *)(DAT_00011c80 + 0x11c5e),3);
    iVar2 = 2;
    if (iVar1 == 0) {
      iVar2 = strncmp(param_2 + 3,(char *)(DAT_00011c84 + 0x11c70),3);
      if (-1 < iVar2) {
        return 0;
      }
      iVar2 = 3;
    }
  }
  return -iVar2;
}



/* Function: FUN_00011c88 @ 00011c88 */

int FUN_00011c88(undefined4 *param_1,void *param_2)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = 1;
  if (((FILE *)*param_1 != (FILE *)0x0) && (iVar2 = 2, param_2 != (void *)0x0)) {
    fseek((FILE *)*param_1,0,0);
    sVar1 = fwrite(param_2,1,0x69,(FILE *)*param_1);
    if (sVar1 == 0x69) {
      return 0;
    }
    iVar2 = 3;
  }
  return -iVar2;
}



/* Function: FUN_00011cc0 @ 00011cc0 */

int FUN_00011cc0(undefined4 *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = 1;
  if (((FILE *)*param_1 != (FILE *)0x0) && (iVar2 = 2, param_2 != (void *)0x0)) {
    fseek((FILE *)*param_1,0,2);
    sVar1 = fwrite(param_2,1,param_3,(FILE *)*param_1);
    if (sVar1 == param_3) {
      return 0;
    }
    iVar2 = 3;
  }
  return -iVar2;
}



/* Function: FUN_00011cf8 @ 00011cf8 */

int FUN_00011cf8(undefined4 *param_1,void *param_2,size_t param_3,long param_4)

{
  size_t sVar1;
  int iVar2;
  
  if ((FILE *)*param_1 == (FILE *)0x0) {
    iVar2 = 1;
  }
  else if (param_2 == (void *)0x0) {
    iVar2 = 2;
  }
  else {
    fseek((FILE *)*param_1,param_4,0);
    sVar1 = fwrite(param_2,1,param_3,(FILE *)*param_1);
    if (sVar1 == param_3) {
      return 0;
    }
    iVar2 = 3;
  }
  return -iVar2;
}



/* Function: FUN_00011d34 @ 00011d34 */

int FUN_00011d34(undefined4 *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  size_t sVar2;
  
  if ((FILE *)*param_1 == (FILE *)0x0) {
    iVar1 = 1;
  }
  else if (param_2 == (void *)0x0) {
    iVar1 = 2;
  }
  else {
    fseek((FILE *)*param_1,0,0);
    sVar2 = fread(param_2,1,0x69,(FILE *)*param_1);
    if (sVar2 == 0x69) {
      *param_3 = 0x69;
      return 0;
    }
    iVar1 = 3;
  }
  return -iVar1;
}



/* Function: FUN_00011d74 @ 00011d74 */

int FUN_00011d74(undefined4 *param_1,void *param_2,size_t *param_3,long param_4)

{
  size_t sVar1;
  int iVar2;
  
  if ((FILE *)*param_1 == (FILE *)0x0) {
    iVar2 = 1;
  }
  else if (param_2 == (void *)0x0) {
    iVar2 = 2;
  }
  else {
    fseek((FILE *)*param_1,param_4,0);
    sVar1 = fread(param_2,1,*param_3,(FILE *)*param_1);
    if (sVar1 == *param_3) {
      return 0;
    }
    *param_3 = sVar1;
    iVar2 = 3;
  }
  return -iVar2;
}



/* Function: FUN_00011db4 @ 00011db4 */

void * FUN_00011db4(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,int param_5,
                   int param_6,int param_7)

{
  int iVar1;
  void *__ptr;
  void *pvVar2;
  void *local_24;
  void *local_20;
  void *local_1c [2];
  
  iVar1 = FUN_00011bd4(param_1,param_3,param_4,param_5,param_6);
  if (iVar1 == 0) {
    pvVar2 = (void *)(param_4 - param_3);
    local_1c[0] = pvVar2;
    __ptr = malloc((size_t)pvVar2);
    if (__ptr == (void *)0x0) {
      iVar1 = 2;
    }
    else {
      local_24 = (void *)FUN_00011d74(param_1,__ptr,local_1c,param_3);
      if (local_24 == (void *)0x0) {
        if (param_7 != 1) {
          *param_2 = __ptr;
          return pvVar2;
        }
        local_20 = local_24;
        iVar1 = FUN_000136b8(__ptr,local_1c[0],&local_24,&local_20);
        pvVar2 = local_20;
        if (iVar1 == 0) {
          if (param_6 * param_5 <= (int)local_20) {
            free(__ptr);
            *param_2 = local_24;
            return pvVar2;
          }
          free(local_24);
          free(__ptr);
          iVar1 = 5;
        }
        else {
          free(__ptr);
          iVar1 = 4;
        }
      }
      else {
        iVar1 = 3;
      }
    }
  }
  else {
    iVar1 = 1;
  }
  return (void *)-iVar1;
}



/* Function: FUN_00011e54 @ 00011e54 */

undefined4 FUN_00011e54(undefined4 *param_1)

{
  if ((FILE *)*param_1 != (FILE *)0x0) {
    fclose((FILE *)*param_1);
    *param_1 = 0;
  }
  return 0;
}



/* Function: FUN_00011e6c @ 00011e6c */

int FUN_00011e6c(undefined4 *param_1,char *param_2,char *param_3)

{
  FILE *pFVar1;
  
  FUN_00011e54();
  pFVar1 = fopen(param_2,param_3);
  *param_1 = pFVar1;
  return -(uint)(pFVar1 == (FILE *)0x0);
}



/* Function: FUN_00011e8c @ 00011e8c */

int FUN_00011e8c(undefined4 param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_14 [2];
  
  iVar2 = 1;
  if ((param_2 != (void *)0x0) && (iVar2 = 2, param_3 != 0)) {
    iVar1 = FUN_00011e6c(param_1,param_3,DAT_00011ee8 + 0x11ea6);
    iVar2 = 3;
    if (-1 < iVar1) {
      memset(param_2,0,0x69);
      local_14[0] = 0x69;
      iVar1 = FUN_00011d34(param_1,param_2,local_14);
      iVar2 = 4;
      if (iVar1 == 0) {
        iVar2 = FUN_00011c4c(param_1,param_2);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = 5;
      }
    }
  }
  return -iVar2;
}



/* Function: FUN_00011eec @ 00011eec */

void FUN_00011eec(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined1 auStack_94 [3];
  char acStack_91 [3];
  undefined4 local_8e;
  undefined4 local_28;
  undefined1 auStack_24 [16];
  int local_14;
  
  iVar1 = 1;
  local_14 = **(int **)(DAT_00011f90 + 0x11ef8);
  if (param_2 != (char *)0x0) {
    iVar1 = FUN_00011e8c(param_1,auStack_94);
    if (iVar1 == 0) {
      memset(param_2,0,0x2c);
      strncpy(param_2,acStack_91,3);
      *(undefined4 *)(param_2 + 4) = local_8e;
      iVar1 = FUN_00011c10(param_1);
      if (0x10 < iVar1) {
        local_28 = 0x10;
        FUN_00011d74(param_1,auStack_24,&local_28,iVar1 + -0x10);
        FUN_00013374(auStack_24,param_2 + 8,0x21);
        FUN_00011e54(param_1);
        iVar1 = 0;
        goto LAB_00011f7a;
      }
      FUN_00011e54(param_1);
      iVar1 = 3;
    }
    else {
      FUN_00011e54(param_1);
      iVar1 = 2;
    }
  }
  iVar1 = -iVar1;
LAB_00011f7a:
  if (local_14 != **(int **)(DAT_00011f94 + 0x11f82)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: FUN_00011f9c @ 00011f9c */

uint FUN_00011f9c(byte *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (byte *)0x0) {
    iVar1 = 1;
LAB_00011fbc:
    uVar2 = -iVar1;
  }
  else {
    if (*(int *)(DAT_00011fe8 + 0x11faa) != 3) {
      uVar2 = (uint)*param_1;
      if (3 < (uVar2 - 1 & 0xff)) {
        iVar1 = 2;
        goto LAB_00011fbc;
      }
      if (uVar2 != 1) {
        return uVar2;
      }
      if ((param_1[4] != 5) && (param_1[4] != 1)) {
        return 1;
      }
      if ((int)(char)param_1[3] <= *(int *)(DAT_00011fec + 0x11fde)) {
        return 1;
      }
    }
    uVar2 = 4;
  }
  return uVar2;
}



/* Function: FUN_00011ff0 @ 00011ff0 */

void FUN_00011ff0(void)

{
  int iVar1;
  
  iVar1 = DAT_00012010 + 0x11ff8;
  FUN_000138bc(iVar1);
  __aeabi_atexit(iVar1,*(undefined4 *)(DAT_00012014 + 0x12004),
                 *(undefined4 *)(DAT_00012018 + 0x1200a));
  return;
}



/* Function: FUN_0001201c @ 0001201c */

void FUN_0001201c(void)

{
  FUN_00014a60();
  return;
}



/* Function: FUN_00012024 @ 00012024 */

int FUN_00012024(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_88 [10];
  byte local_7e;
  byte local_7d;
  char local_7c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_1c [2];
  
  iVar2 = DAT_000120cc;
  if (param_2 == 0) {
    return -1;
  }
  *(int *)(DAT_000120cc + 0x12044) = param_1;
  FUN_00015e38();
  if (-1 < param_1 << 0x1c) {
    return 0;
  }
  local_1c[0] = 0;
  iVar1 = FUN_00011e8c(local_1c,auStack_88,param_2);
  if (iVar1 < 0) {
    iVar2 = 2;
LAB_000120bc:
    iVar2 = -iVar2;
    FUN_00011e54(local_1c);
  }
  else {
    if ((local_7e - 0xb & 0xff) < 0x45) {
      *(uint *)(iVar2 + 0x12048) = (uint)local_7e;
    }
    if ((local_7d - 0x1f & 0xff) < 0x46) {
      *(uint *)(DAT_000120d0 + 0x1208e) = (uint)local_7d;
    }
    iVar2 = (int)local_7c;
    if ((iVar2 <= *(int *)(DAT_000120d4 + 0x12094)) && (-100 < iVar2)) {
      *(int *)(DAT_000120d4 + 0x1208c) = iVar2;
    }
    if (local_38 != 0) {
      iVar1 = FUN_00015030(local_34,local_30,local_38,1,local_1c);
      iVar2 = 3;
      if (iVar1 != 0) goto LAB_000120bc;
    }
    FUN_00011e54(local_1c);
    iVar2 = 0;
  }
  return iVar2;
}



/* Function: FUN_000120d8 @ 000120d8 */

void FUN_000120d8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_000120f4;
  FUN_0001201c();
  uVar2 = *(undefined4 *)(iVar1 + 0x120ec);
  FUN_00012024(param_1,param_2);
  *(undefined4 *)(iVar1 + 0x120ec) = uVar2;
  return;
}



/* Function: FUN_000120f8 @ 000120f8 */

void FUN_000120f8(undefined4 param_1,undefined4 param_2)

{
  FUN_00013930(DAT_0001210c + 0x12106,param_1,param_2);
  return;
}



/* Function: FUN_00012134 @ 00012134 */

void FUN_00012134(void)

{
  if (*(int *)(DAT_00012164 + 0x12150) << 0x1f < 0) {
    FUN_00015f04();
  }
  if (*(int *)(DAT_00012168 + 0x1215e) << 0x1e < 0) {
    FUN_000154a0();
  }
  if (*(int *)((int)&DAT_0001216c + DAT_0001216c) << 0x1d < 0) {
    FUN_00013c2c();
  }
  return;
}



/* Function: FUN_00012170 @ 00012170 */

void FUN_00012170(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined1 param_5,
                 undefined1 param_6,undefined4 param_7,int *param_8,int param_9)

{
  if (0 < param_2) {
    if (param_2 < 0xb) {
      *(undefined1 *)(param_2 * 8 + param_9) = param_6;
      *(undefined4 *)(param_9 + param_2 * 8 + 4) = param_7;
    }
    if ((*param_8 < param_3) && (0 < param_3)) {
      *param_8 = param_3;
      *(undefined1 *)(param_9 + 1) = param_5;
    }
    *(char *)(param_9 + 2) = (char)param_2;
    FUN_0001527c(*(undefined4 *)(FUN_000121c4 + DAT_000121c0),param_1,param_4,param_5,param_9);
  }
  return;
}



/* Function: FUN_000121c4 @ 000121c4 */

void FUN_000121c4(void *param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char acStack_160 [20];
  undefined1 auStack_14c [283];
  char cStack_31;
  undefined1 auStack_30 [10];
  undefined1 local_26;
  char cStack_25;
  undefined1 local_24;
  undefined4 local_20;
  int local_1c;
  
  local_1c = **(int **)(DAT_000122c0 + 0x121d0);
  iVar3 = 1;
  if ((param_1 != (void *)0x0) && (iVar3 = 2, param_2 != (char *)0x0)) {
    memset(param_2,0,0x58);
    memset(auStack_30,0,0x14);
    *(undefined4 *)(DAT_000122c4 + 0x1221a) = 0;
    memset(acStack_160,0,0x130);
    memcpy(acStack_160,param_1,0x130);
    FUN_000152cc(acStack_160);
    if (acStack_160[DAT_000122c8] == '\x01') {
      iVar1 = FUN_00014eb0(acStack_160,auStack_14c,auStack_30);
    }
    else {
      iVar1 = FUN_00014c70(acStack_160,auStack_14c,param_2);
    }
    if (-1 < iVar1) {
      iVar3 = 1;
      if (iVar1 == 0) {
        if (cStack_31 == '\x01') {
          FUN_00012170(local_26,1,(int)cStack_25,0,local_24,6,local_20,DAT_000122cc + 0x1228e,
                       param_2);
        }
        iVar3 = DAT_000122d0;
        if (*param_2 == '\x03') {
          if ((int)param_2[3] < *(int *)(DAT_000122d0 + 0x1229a)) {
            *param_2 = '\x01';
            if (*(int *)(iVar3 + 0x12292) < (int)param_2[3]) {
              cVar2 = '\x05';
            }
            else {
              cVar2 = '\t';
            }
            param_2[4] = cVar2;
          }
        }
        iVar3 = 0;
      }
      goto LAB_000122a6;
    }
    iVar3 = 3;
  }
  iVar3 = -iVar3;
LAB_000122a6:
  if (local_1c != **(int **)(DAT_000122d4 + 0x122b0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar3);
  }
  return;
}



/* Function: FUN_000122d8 @ 000122d8 */

void FUN_000122d8(char *param_1,int *param_2,int *param_3,char *param_4)

{
  int iVar1;
  size_t sVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_1a0;
  char local_194 [88];
  size_t local_13c;
  undefined1 auStack_138 [284];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001245c + 0x122e6);
  if (param_1 == (char *)0x0) {
    iVar1 = 1;
  }
  else {
    if (param_4 != (char *)0x0) {
      local_1a0 = *param_3;
      iVar6 = *param_2;
      memcpy(local_194,param_4,0x58);
      iVar1 = 0;
      iVar5 = DAT_00012460 + 0x12334;
      while( true ) {
        iVar1 = FUN_000155fc(param_1,iVar1);
        if (iVar1 < 0) break;
        puVar3 = (undefined4 *)FUN_0001543c(iVar1);
        *param_2 = *param_2 + (int)*(char *)((int)puVar3 + 0xd);
        iVar4 = *param_3;
        *param_3 = iVar4 + 1;
        FUN_00012170(*(undefined1 *)(puVar3 + 3),iVar4 + 1,(int)*(char *)((int)puVar3 + 0xd),
                     *param_2,*(undefined1 *)((int)puVar3 + 0xe),2,*puVar3,iVar5,param_4);
        if ((byte)(*param_4 - 1U) < 2) {
          iVar1 = 1;
          goto LAB_00012444;
        }
        iVar1 = iVar1 + 1;
      }
      if ((int)param_4[3] < *(int *)(DAT_00012464 + 0x1238c)) {
        sVar2 = strlen(param_1);
        local_13c = sVar2;
        FUN_00015974(param_1,sVar2,auStack_138,&local_13c);
        if (((int)local_13c < (int)sVar2) && (8 < (int)local_13c)) {
          iVar1 = 0;
          iVar5 = DAT_00012468 + 0x123d0;
          while( true ) {
            iVar1 = FUN_000155fc(auStack_138,iVar1);
            if (iVar1 < 0) break;
            puVar3 = (undefined4 *)FUN_0001543c(iVar1);
            local_1a0 = local_1a0 + 1;
            iVar6 = iVar6 + *(char *)((int)puVar3 + 0xd);
            FUN_00012170(*(undefined1 *)(puVar3 + 3),local_1a0,(int)*(char *)((int)puVar3 + 0xd),
                         iVar6,*(undefined1 *)((int)puVar3 + 0xe),2,*puVar3,iVar5,local_194);
            if ((byte)(local_194[0] - 1U) < 2) {
              *param_2 = iVar6;
              *param_3 = local_1a0;
              memcpy(param_4,local_194,0x58);
              iVar1 = 2;
              goto LAB_00012444;
            }
            iVar1 = iVar1 + 1;
          }
          if ((*param_2 < iVar6) && (*param_3 < local_1a0)) {
            *param_2 = iVar6;
            *param_3 = local_1a0;
            memcpy(param_4,local_194,0x58);
            iVar1 = 3;
            goto LAB_00012444;
          }
        }
      }
      iVar1 = 0;
      goto LAB_00012444;
    }
    iVar1 = 2;
  }
  iVar1 = -iVar1;
LAB_00012444:
  if (local_1c != **(int **)(DAT_0001246c + 0x1244c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



/* Function: FUN_00012470 @ 00012470 */

void FUN_00012470(void *param_1,char *param_2)

{
  undefined1 *__s;
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  undefined4 uVar8;
  byte *pbVar9;
  int iVar10;
  char cVar11;
  undefined4 uVar12;
  int *piVar13;
  uint *puVar14;
  undefined4 *puVar15;
  uint *puVar16;
  undefined4 *puVar17;
  uint *puVar18;
  
  iVar4 = DAT_0001276c;
  puVar14 = (uint *)(&stack0xffffffec + DAT_0001276c);
  puVar15 = (undefined4 *)(&stack0xffffffec + DAT_0001276c);
  puVar16 = (uint *)(&stack0xffffffec + DAT_0001276c);
  puVar17 = (undefined4 *)(&stack0xffffffec + DAT_0001276c);
  puVar18 = (uint *)(&stack0xffffffec + DAT_0001276c);
  iVar5 = 1;
  *(undefined4 *)(&stack0x00000278 + DAT_0001276c) = **(undefined4 **)(DAT_00012768 + 0x1247c);
  if ((param_1 == (void *)0x0) || (iVar5 = 2, param_2 == (char *)0x0)) {
LAB_00012718:
    iVar5 = -iVar5;
  }
  else {
    memset(param_2,0,0x58);
    __s = &stack0x0000002c + iVar4;
    *(undefined4 *)(&stack0x00000028 + iVar4) = 0;
    *(undefined4 *)(&stack0x00000024 + iVar4) = 0;
    memset(__s,0,0x130);
    memcpy(__s,param_1,0x130);
    *(undefined1 **)(&stack0x00000010 + iVar4) = &stack0x00000040 + iVar4;
    sVar6 = strlen(&stack0x00000040 + iVar4);
    iVar5 = DAT_00012770;
    piVar13 = (int *)(DAT_00012770 + 0x124d2);
    *(undefined4 *)(DAT_00012770 + 0x124ee) = 0;
    if (*piVar13 != 3) {
      *(size_t *)(&stack0x00000020 + iVar4) = sVar6;
      *(uint *)(&stack0x0000000c + iVar4) = (uint)(byte)(&stack0x0000015a)[iVar4];
      if ((byte)(&stack0x0000015a)[iVar4] == 2) {
        iVar5 = FUN_00014204(__s,*(undefined4 *)(&stack0x00000010 + iVar4));
        if (iVar5 == 1) {
          *param_2 = '\x01';
        }
        else {
          *param_2 = (&stack0x0000000c)[iVar4];
        }
      }
      else {
        FUN_000152cc(__s);
        if (((((__s[DAT_00012774] & 1) != 0) && (iVar7 = FUN_00016010(__s), -1 < iVar7)) &&
            (iVar7 = FUN_00015e9c(), iVar7 != 0)) &&
           ((*(byte *)(iVar7 + 0x14) < 2 && (0x7e < *(byte *)(iVar7 + 0x16))))) {
          iVar10 = *(int *)(&stack0x00000028 + iVar4);
          *(int *)(&stack0x00000024 + iVar4) =
               (int)*(char *)(iVar7 + 0x15) + *(int *)(&stack0x00000024 + iVar4);
          *(int *)(&stack0x00000028 + iVar4) = iVar10 + 1;
          uVar1 = *(undefined1 *)(iVar7 + 0x14);
          *(int *)(&stack0x0000000c + iVar4) = (int)*(char *)(iVar7 + 0x15);
          *puVar14 = (uint)*(byte *)(iVar7 + 0x16);
          *(undefined4 *)(&stack0xfffffff0 + iVar4) = 1;
          uVar8 = *(undefined4 *)(iVar7 + 0x18);
          *(int *)(&stack0xfffffff8 + iVar4) = iVar5 + 0x124ee;
          *(undefined4 *)(&stack0xfffffff4 + iVar4) = uVar8;
          *(char **)(&stack0xfffffffc + iVar4) = param_2;
          FUN_00012170(uVar1,iVar10 + 1,*(undefined4 *)(&stack0x0000000c + iVar4));
          if ((byte)(*param_2 - 1U) < 2) goto LAB_0001274a;
        }
        if (((int)((uint)(byte)(&stack0x0000002c)[DAT_00012774 + iVar4] << 0x1e) < 0) &&
           (sVar6 - 9 <= DAT_00012778)) {
          iVar5 = DAT_0001277c + 0x12598;
          *puVar15 = DAT_00012780;
          *(size_t *)(&stack0x00000020 + iVar4) = sVar6;
          FUN_00015ae8(&stack0x00000040 + iVar4,sVar6,iVar5,&stack0x00000020 + iVar4);
          FUN_00013838(iVar5,*(undefined4 *)(&stack0x00000020 + iVar4));
          if ((8 < *(int *)(&stack0x00000020 + iVar4)) &&
             (iVar5 = FUN_000122d8(iVar5,&stack0x00000024 + iVar4,&stack0x00000028 + iVar4,param_2),
             iVar5 - 1U < 2)) goto LAB_0001274a;
        }
        if (((((&stack0x0000002c)[DAT_00012774 + iVar4] & 1) != 0) &&
            (iVar5 = FUN_00016010(), -1 < iVar5)) && (iVar5 = FUN_00015e9c(), iVar5 != 0)) {
          iVar7 = *(int *)(&stack0x00000028 + iVar4);
          *(int *)(&stack0x00000024 + iVar4) =
               (int)*(char *)(iVar5 + 0x15) + *(int *)(&stack0x00000024 + iVar4);
          *(int *)(&stack0x00000028 + iVar4) = iVar7 + 1;
          uVar1 = *(undefined1 *)(iVar5 + 0x14);
          *(int *)(&stack0x0000000c + iVar4) = (int)*(char *)(iVar5 + 0x15);
          bVar2 = *(byte *)(iVar5 + 0x16);
          *(undefined4 *)(&stack0xfffffff0 + iVar4) = 1;
          *puVar16 = (uint)bVar2;
          *(undefined4 *)(&stack0xfffffff4 + iVar4) = *(undefined4 *)(iVar5 + 0x18);
          *(int *)(&stack0xfffffff8 + iVar4) = DAT_00012784 + 0x1261a;
          *(char **)(&stack0xfffffffc + iVar4) = param_2;
          FUN_00012170(uVar1,iVar7 + 1,*(undefined4 *)(&stack0x0000000c + iVar4));
          if ((byte)(*param_2 - 1U) < 2) goto LAB_0001274a;
        }
        if ((*(int *)(DAT_00012788 + 0x12634) << 0x1d < 0) &&
           (iVar5 = *(int *)(&stack0x00000020 + iVar4), 0x17 < iVar5)) {
          *(undefined1 **)(&stack0x0000000c + iVar4) = &stack0x0000015c + iVar4;
          iVar10 = DAT_0001278c + 0x12644;
          *(undefined4 *)(&stack0x0000001c + iVar4) = DAT_00012790;
          iVar7 = FUN_000159fc(iVar10,iVar5,*(undefined4 *)(&stack0x0000000c + iVar4),
                               &stack0x0000001c + iVar4);
          *(int *)(&stack0x00000010 + iVar4) = iVar10;
          if (iVar7 == 0) {
            iVar5 = *(int *)(&stack0x0000001c + iVar4);
            *(undefined4 *)(&stack0x00000010 + iVar4) = *(undefined4 *)(&stack0x0000000c + iVar4);
          }
          for (iVar7 = 0; iVar7 < iVar5; iVar7 = iVar7 + 1) {
            if ((3 < (byte)(*(char *)(*(int *)(&stack0x00000010 + iVar4) + iVar7) + 0x9fU)) &&
               (3 < (byte)(*(char *)(*(int *)(&stack0x00000010 + iVar4) + iVar7) - 0x31U))) {
              iVar7 = 1;
              goto LAB_000126ea;
            }
          }
          iVar7 = 10;
LAB_000126ea:
          *(undefined1 **)(&stack0x00000014 + iVar4) = &stack0x0000002c + iVar4;
          *(int *)(&stack0x00000008 + iVar4) = iVar5;
          *(int *)(&stack0x00000018 + iVar4) = DAT_00012794 + 0x12714;
          for (; iVar7 != 10; iVar7 = iVar7 + 1) {
            uVar12 = *(undefined4 *)(&stack0x00000024 + iVar4);
            uVar8 = *(undefined4 *)(&stack0x00000010 + iVar4);
            *puVar17 = *(undefined4 *)(&stack0x00000014 + iVar4);
            *(undefined4 *)(&stack0xfffffff0 + iVar4) = uVar12;
            *(int *)(&stack0xfffffff4 + iVar4) = iVar7;
            iVar5 = FUN_00013b40(uVar8,*(undefined4 *)(&stack0x00000008 + iVar4),
                                 &stack0x00000040 + iVar4,sVar6);
            if (((iVar5 - 1U < 0x10) && (pbVar9 = (byte *)FUN_00013c10(), pbVar9 != (byte *)0x0)) &&
               (pbVar9[4] != 0)) {
              iVar5 = *(int *)(&stack0x00000028 + iVar4);
              *(int *)(&stack0x00000024 + iVar4) =
                   (int)(char)pbVar9[2] + *(int *)(&stack0x00000024 + iVar4);
              *(int *)(&stack0x00000028 + iVar4) = iVar5 + 1;
              bVar2 = pbVar9[1];
              *(int *)(&stack0x0000000c + iVar4) = (int)(char)pbVar9[2];
              *puVar18 = (uint)pbVar9[3];
              *(undefined4 *)(&stack0xfffffff0 + iVar4) = 5;
              bVar3 = *pbVar9;
              *(char **)(&stack0xfffffffc + iVar4) = param_2;
              *(uint *)(&stack0xfffffff4 + iVar4) = (uint)bVar3;
              *(undefined4 *)(&stack0xfffffff8 + iVar4) = *(undefined4 *)(&stack0x00000018 + iVar4);
              FUN_00012170(bVar2,iVar5 + 1,*(undefined4 *)(&stack0x0000000c + iVar4));
              if ((byte)(*param_2 - 1U) < 2) goto LAB_0001274a;
            }
          }
        }
        iVar5 = DAT_00012798;
        if (*(int *)(&stack0x00000028 + iVar4) == 0) {
          *param_2 = '\x01';
          if (*(int *)(&stack0x00000020 + iVar4) < 9) {
            cVar11 = '\a';
          }
          else {
            cVar11 = '\t';
          }
          param_2[4] = cVar11;
          iVar5 = 3;
          goto LAB_00012718;
        }
        if ((*param_2 == '\x03') && ((int)param_2[3] < *(int *)(DAT_00012798 + 0x12738))) {
          *param_2 = '\x01';
          if ((int)sVar6 < 9) {
            cVar11 = '\a';
          }
          else if (*(int *)(iVar5 + 0x12730) < (int)param_2[3]) {
            cVar11 = '\x05';
          }
          else {
            cVar11 = '\t';
          }
          param_2[4] = cVar11;
        }
      }
    }
LAB_0001274a:
    iVar5 = 0;
  }
  if (*(int *)(&stack0x00000278 + iVar4) == **(int **)(DAT_0001279c + 0x12754)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar5);
}



/* Function: FUN_000127a0 @ 000127a0 */

int FUN_000127a0(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_88 [10];
  byte local_7e;
  byte local_7d;
  char local_7c;
  byte local_7b;
  byte local_79;
  uint local_78;
  uint local_74;
  int local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  byte local_45;
  uint local_44;
  uint local_40;
  int local_3c;
  undefined4 local_1c [2];
  
  iVar2 = DAT_000128d8;
  *(uint *)(DAT_000128d8 + 0x127c0) = param_1;
  FUN_00015e38();
  if (param_2 == 0) {
    return -1;
  }
  if ((param_1 & 7) == 0) {
    return 0;
  }
  local_1c[0] = 0;
  iVar1 = FUN_00011e8c(local_1c,auStack_88,param_2);
  if (iVar1 < 0) {
    iVar2 = 2;
  }
  else {
    if ((local_7e - 0xb & 0xff) < 0x45) {
      *(uint *)(iVar2 + 0x127b8) = (uint)local_7e;
    }
    if ((local_7d - 0x1f & 0xff) < 0x46) {
      *(uint *)(DAT_000128dc + 0x12812) = (uint)local_7d;
    }
    iVar2 = (int)local_7c;
    if ((iVar2 <= *(int *)(DAT_000128e0 + 0x12818)) && (-100 < iVar2)) {
      *(int *)(DAT_000128e0 + 0x12810) = iVar2;
    }
    iVar2 = 0;
    *(uint *)(DAT_000128e4 + 0x12824) = (uint)local_7b;
    if (local_7b == 3) goto LAB_000128cc;
    if ((int)(param_1 << 0x1f) < 0) {
      uVar3 = local_78 << 8 | (uint)local_79;
      if (uVar3 == 0) {
        FUN_00015f04();
      }
      else {
        iVar1 = FUN_00016060(local_74 << 8 | local_78 >> 0x18,local_70 << 8 | local_74 >> 0x18,uVar3
                             ,param_3,local_1c);
        iVar2 = 3;
        if (iVar1 != 0) goto LAB_000128ca;
      }
    }
    if ((int)(param_1 << 0x1e) < 0) {
      if (local_6c == 0) {
        FUN_000154a0();
      }
      else {
        iVar1 = FUN_00015668(local_68,local_64,local_6c,param_3,local_1c);
        iVar2 = 4;
        if (iVar1 != 0) goto LAB_000128ca;
      }
    }
    if ((-1 < (int)(param_1 << 0x1d)) || (uVar3 = local_44 << 8 | (uint)local_45, uVar3 == 0)) {
LAB_000128be:
      FUN_00011e54(local_1c);
      return 0;
    }
    iVar1 = FUN_00013cdc(local_40 << 8 | local_44 >> 0x18,local_3c << 8 | local_40 >> 0x18,uVar3,
                         param_3,local_1c);
    iVar2 = 5;
    if (iVar1 == 0) goto LAB_000128be;
  }
LAB_000128ca:
  iVar2 = -iVar2;
LAB_000128cc:
  FUN_00011e54(local_1c);
  return iVar2;
}



/* Function: FUN_000128f4 @ 000128f4 */

void FUN_000128f4(uint param_1,undefined4 param_2)

{
  if ((param_1 & 4) == 0) {
    param_1 = param_1 | 4;
  }
  FUN_000127a0(param_1,param_2,1);
  return;
}



/* Function: FUN_00012908 @ 00012908 */

void FUN_00012908(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00012918;
  uVar2 = *(undefined4 *)(DAT_00012918 + 0x12924);
  FUN_000128f4();
  *(undefined4 *)(iVar1 + 0x12924) = uVar2;
  return;
}



/* Function: FUN_0001291c @ 0001291c */

void FUN_0001291c(undefined4 *param_1)

{
  param_1[5] = 0;
  param_1[4] = 0;
  *param_1 = DAT_00012934;
  param_1[1] = DAT_00012938;
  param_1[2] = DAT_0001293c;
  param_1[3] = DAT_00012940;
  return;
}



/* Function: FUN_00012944 @ 00012944 */

void FUN_00012944(int *param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_58 [4];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint uStack_18;
  
  uVar5 = param_1[2];
  iVar8 = *param_1;
  uVar11 = param_1[1];
  uVar13 = param_1[3];
  puVar6 = local_58;
  puVar7 = puVar6;
  do {
    pbVar1 = param_2 + 1;
    pbVar2 = param_2 + 2;
    bVar4 = *param_2;
    pbVar3 = param_2 + 3;
    param_2 = param_2 + 4;
    *puVar7 = (uint)*pbVar3 << 0x18 | (uint)*pbVar2 << 0x10 | (uint)*pbVar1 << 8 | (uint)bVar4;
    puVar7 = puVar7 + 1;
  } while (puVar7 != &uStack_18);
  uVar9 = local_58[0] + DAT_00012d80 + iVar8 + (uVar5 & uVar11 | uVar13 & ~uVar11);
  uVar10 = (uVar9 >> 0x19 | uVar9 * 0x80) + uVar11;
  uVar13 = uVar13 + local_58[1] + DAT_00012d84 + (uVar10 & uVar11 | uVar5 & ~uVar10);
  uVar13 = (uVar13 >> 0x14 | uVar13 * 0x1000) + uVar10;
  uVar5 = local_58[2] + DAT_00012d88 + uVar5 + (uVar13 & uVar10 | uVar11 & ~uVar13);
  uVar9 = (uVar5 >> 0xf | uVar5 * 0x20000) + uVar13;
  uVar5 = uVar11 + local_58[3] + DAT_00012d8c + (uVar9 & uVar13 | uVar10 & ~uVar9);
  uVar12 = (uVar5 >> 10 | uVar5 * 0x400000) + uVar9;
  uVar5 = uVar10 + local_48 + DAT_00012d90 + (uVar12 & uVar9 | uVar13 & ~uVar12);
  uVar10 = (uVar5 >> 0x19 | uVar5 * 0x80) + uVar12;
  uVar5 = uVar13 + local_44 + DAT_00012d94 + (uVar10 & uVar12 | uVar9 & ~uVar10);
  uVar5 = (uVar5 >> 0x14 | uVar5 * 0x1000) + uVar10;
  uVar11 = uVar9 + local_40 + DAT_00012d98 + (uVar5 & uVar10 | uVar12 & ~uVar5);
  uVar11 = (uVar11 >> 0xf | uVar11 * 0x20000) + uVar5;
  uVar13 = uVar12 + local_3c + DAT_00012d9c + (uVar11 & uVar5 | uVar10 & ~uVar11);
  uVar13 = (uVar13 >> 10 | uVar13 * 0x400000) + uVar11;
  uVar9 = uVar10 + local_38 + DAT_00012da0 + (uVar13 & uVar11 | uVar5 & ~uVar13);
  uVar9 = (uVar9 >> 0x19 | uVar9 * 0x80) + uVar13;
  uVar5 = uVar5 + local_34 + DAT_00012da4 + (uVar9 & uVar13 | uVar11 & ~uVar9);
  uVar5 = (uVar5 >> 0x14 | uVar5 * 0x1000) + uVar9;
  uVar11 = uVar11 + local_30 + DAT_00012da8 + (uVar5 & uVar9 | uVar13 & ~uVar5);
  uVar11 = (uVar11 >> 0xf | uVar11 * 0x20000) + uVar5;
  uVar13 = uVar13 + local_2c + DAT_00012dac + (uVar11 & uVar5 | uVar9 & ~uVar11);
  uVar12 = (uVar13 >> 10 | uVar13 * 0x400000) + uVar11;
  uVar13 = uVar9 + local_28 + DAT_00012db0 + (uVar12 & uVar11 | uVar5 & ~uVar12);
  uVar9 = (uVar13 >> 0x19 | uVar13 * 0x80) + uVar12;
  uVar5 = uVar5 + local_24 + DAT_00012db4 + (uVar9 & uVar12 | uVar11 & ~uVar9);
  uVar10 = (uVar5 >> 0x14 | uVar5 * 0x1000) + uVar9;
  uVar5 = local_20 + DAT_00012db8 + uVar11 + (uVar10 & uVar9 | ~uVar10 & uVar12);
  uVar11 = (uVar5 >> 0xf | uVar5 * 0x20000) + uVar10;
  uVar5 = local_1c + DAT_00012dbc + uVar12 + (uVar11 & uVar10 | ~uVar11 & uVar9);
  uVar13 = (uVar5 >> 10 | uVar5 * 0x400000) + uVar11;
  uVar5 = local_58[1] + DAT_00012dc0 + uVar9 + (~uVar10 & uVar11 | uVar13 & uVar10);
  uVar9 = (uVar5 >> 0x1b | uVar5 * 0x20) + uVar13;
  uVar5 = local_40 + DAT_00012dc4 + uVar10 + (~uVar11 & uVar13 | uVar9 & uVar11);
  uVar5 = (uVar5 >> 0x17 | uVar5 * 0x200) + uVar9;
  uVar11 = uVar11 + local_2c + DAT_00012dc8 + (uVar9 & ~uVar13 | uVar5 & uVar13);
  uVar11 = (uVar11 >> 0x12 | uVar11 * 0x4000) + uVar5;
  uVar13 = uVar13 + local_58[0] + DAT_00012dcc + (uVar5 & ~uVar9 | uVar11 & uVar9);
  uVar13 = (uVar13 >> 0xc | uVar13 * 0x100000) + uVar11;
  uVar9 = uVar9 + local_44 + DAT_00012dd0 + (uVar11 & ~uVar5 | uVar13 & uVar5);
  uVar9 = (uVar9 >> 0x1b | uVar9 * 0x20) + uVar13;
  uVar5 = uVar5 + local_30 + DAT_00012dd4 + (uVar13 & ~uVar11 | uVar9 & uVar11);
  uVar5 = (uVar5 >> 0x17 | uVar5 * 0x200) + uVar9;
  uVar11 = uVar11 + local_1c + DAT_00012dd8 + (uVar9 & ~uVar13 | uVar5 & uVar13);
  uVar11 = (uVar11 >> 0x12 | uVar11 * 0x4000) + uVar5;
  uVar13 = uVar13 + local_48 + DAT_00012ddc + (uVar5 & ~uVar9 | uVar11 & uVar9);
  uVar13 = (uVar13 >> 0xc | uVar13 * 0x100000) + uVar11;
  uVar9 = uVar9 + local_34 + DAT_00012de0 + (uVar11 & ~uVar5 | uVar13 & uVar5);
  uVar9 = (uVar9 >> 0x1b | uVar9 * 0x20) + uVar13;
  uVar5 = uVar5 + local_20 + DAT_00012de4 + (uVar13 & ~uVar11 | uVar9 & uVar11);
  uVar5 = (uVar5 >> 0x17 | uVar5 * 0x200) + uVar9;
  uVar11 = uVar11 + local_58[3] + DAT_00012de8 + (uVar9 & ~uVar13 | uVar5 & uVar13);
  uVar11 = (uVar11 >> 0x12 | uVar11 * 0x4000) + uVar5;
  uVar13 = uVar13 + local_38 + DAT_00012dec + (uVar5 & ~uVar9 | uVar11 & uVar9);
  uVar13 = (uVar13 >> 0xc | uVar13 * 0x100000) + uVar11;
  uVar9 = uVar9 + local_24 + DAT_00012df0 + (uVar11 & ~uVar5 | uVar13 & uVar5);
  uVar10 = (uVar9 >> 0x1b | uVar9 * 0x20) + uVar13;
  uVar5 = uVar5 + local_58[2] + DAT_00012df4 + (uVar13 & ~uVar11 | uVar10 & uVar11);
  uVar9 = (uVar5 >> 0x17 | uVar5 * 0x200) + uVar10;
  uVar5 = local_3c + DAT_00012df8 + uVar11 + (uVar10 & ~uVar13 | uVar9 & uVar13);
  uVar5 = (uVar5 >> 0x12 | uVar5 * 0x4000) + uVar9;
  uVar11 = local_28 + DAT_00012dfc + uVar13 + (uVar9 & ~uVar10 | uVar5 & uVar10);
  uVar12 = (uVar11 >> 0xc | uVar11 * 0x100000) + uVar5;
  uVar11 = local_44 + DAT_00012e00 + uVar10 + (uVar5 ^ uVar9 ^ uVar12);
  uVar10 = (uVar11 >> 0x1c | uVar11 * 0x10) + uVar12;
  uVar11 = local_38 + DAT_00012e04 + uVar9 + (uVar12 ^ uVar5 ^ uVar10);
  uVar13 = (uVar11 >> 0x15 | uVar11 * 0x800) + uVar10;
  uVar5 = local_2c + DAT_00012e08 + uVar5 + (uVar10 ^ uVar12 ^ uVar13);
  uVar5 = (uVar5 >> 0x10 | uVar5 * 0x10000) + uVar13;
  uVar11 = local_20 + DAT_000130f4 + uVar12 + (uVar13 ^ uVar10 ^ uVar5);
  uVar11 = (uVar11 >> 9 | uVar11 * 0x800000) + uVar5;
  uVar9 = local_58[1] + DAT_000130f8 + uVar10 + (uVar5 ^ uVar13 ^ uVar11);
  uVar10 = (uVar9 >> 0x1c | uVar9 * 0x10) + uVar11;
  uVar13 = local_48 + DAT_000130fc + uVar13 + (uVar11 ^ uVar5 ^ uVar10);
  uVar9 = (uVar13 >> 0x15 | uVar13 * 0x800) + uVar10;
  uVar5 = local_3c + DAT_00013100 + uVar5 + (uVar10 ^ uVar11 ^ uVar9);
  uVar5 = (uVar5 >> 0x10 | uVar5 * 0x10000) + uVar9;
  uVar11 = local_30 + DAT_00013104 + uVar11 + (uVar9 ^ uVar10 ^ uVar5);
  uVar13 = (uVar11 >> 9 | uVar11 * 0x800000) + uVar5;
  uVar11 = local_24 + DAT_00013108 + uVar10 + (uVar5 ^ uVar9 ^ uVar13);
  uVar10 = (uVar11 >> 0x1c | uVar11 * 0x10) + uVar13;
  uVar11 = local_58[0] + DAT_0001310c + uVar9 + (uVar13 ^ uVar5 ^ uVar10);
  uVar11 = (uVar11 >> 0x15 | uVar11 * 0x800) + uVar10;
  uVar5 = local_58[3] + DAT_00013110 + uVar5 + (uVar10 ^ uVar13 ^ uVar11);
  uVar5 = (uVar5 >> 0x10 | uVar5 * 0x10000) + uVar11;
  uVar13 = local_40 + DAT_00013114 + uVar13 + (uVar11 ^ uVar10 ^ uVar5);
  uVar9 = (uVar13 >> 9 | uVar13 * 0x800000) + uVar5;
  uVar13 = local_34 + DAT_00013118 + uVar10 + (uVar5 ^ uVar11 ^ uVar9);
  uVar13 = (uVar13 >> 0x1c | uVar13 * 0x10) + uVar9;
  uVar11 = local_28 + DAT_00013120 + uVar11 + (uVar9 ^ uVar5 ^ uVar13);
  uVar11 = (uVar11 >> 0x15 | uVar11 * 0x800) + uVar13;
  uVar5 = local_1c + DAT_00013124 + uVar5 + (uVar13 ^ uVar9 ^ uVar11);
  uVar12 = (uVar5 >> 0x10 | uVar5 * 0x10000) + uVar11;
  uVar5 = local_58[2] + DAT_00013128 + uVar9 + (uVar13 ^ uVar11 ^ uVar12);
  uVar9 = (uVar5 >> 9 | uVar5 * 0x800000) + uVar12;
  uVar5 = local_58[0] + DAT_0001311c + uVar13 + ((~uVar11 | uVar9) ^ uVar12);
  uVar10 = (uVar5 >> 0x1a | uVar5 * 0x40) + uVar9;
  uVar5 = local_3c + DAT_0001312c + uVar11 + ((~uVar12 | uVar10) ^ uVar9);
  uVar5 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar10;
  uVar11 = local_20 + DAT_00013130 + uVar12 + ((~uVar9 | uVar5) ^ uVar10);
  uVar13 = (uVar11 >> 0x11 | uVar11 * 0x8000) + uVar5;
  uVar11 = local_44 + DAT_00013134 + uVar9 + ((~uVar10 | uVar13) ^ uVar5);
  uVar9 = (uVar11 >> 0xb | uVar11 * 0x200000) + uVar13;
  uVar11 = ((~uVar5 | uVar9) ^ uVar13) + local_28 + DAT_00013138 + uVar10;
  uVar11 = (uVar11 >> 0x1a | uVar11 * 0x40) + uVar9;
  uVar5 = local_58[3] + DAT_0001313c + uVar5 + ((~uVar13 | uVar11) ^ uVar9);
  uVar12 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar11;
  uVar5 = ((~uVar9 | uVar12) ^ uVar11) + local_30 + DAT_00013140 + uVar13;
  uVar10 = (uVar5 >> 0x11 | uVar5 * 0x8000) + uVar12;
  uVar5 = local_58[1] + DAT_00013144 + uVar9 + ((~uVar11 | uVar10) ^ uVar12);
  uVar13 = (uVar5 >> 0xb | uVar5 * 0x200000) + uVar10;
  uVar5 = ((~uVar12 | uVar13) ^ uVar10) + local_38 + DAT_00013148 + uVar11;
  uVar9 = (uVar5 >> 0x1a | uVar5 * 0x40) + uVar13;
  uVar5 = local_1c + DAT_0001314c + uVar12 + ((~uVar10 | uVar9) ^ uVar13);
  uVar5 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar9;
  uVar11 = ((~uVar13 | uVar5) ^ uVar9) + local_40 + DAT_00013150 + uVar10;
  uVar11 = (uVar11 >> 0x11 | uVar11 * 0x8000) + uVar5;
  uVar13 = local_24 + DAT_00013154 + uVar13 + ((~uVar9 | uVar11) ^ uVar5);
  uVar13 = (uVar13 >> 0xb | uVar13 * 0x200000) + uVar11;
  uVar9 = local_48 + DAT_00013158 + uVar9 + ((~uVar5 | uVar13) ^ uVar11);
  uVar10 = (uVar9 >> 0x1a | uVar9 * 0x40) + uVar13;
  uVar5 = local_2c + DAT_0001315c + uVar5 + ((~uVar11 | uVar10) ^ uVar13);
  uVar9 = (uVar5 >> 0x16 | uVar5 * 0x400) + uVar10;
  uVar5 = local_58[2] + DAT_00013160 + uVar11 + ((~uVar13 | uVar9) ^ uVar10);
  uVar11 = (uVar5 >> 0x11 | uVar5 * 0x8000) + uVar9;
  uVar5 = local_34 + DAT_00013164 + uVar13 + ((~uVar10 | uVar11) ^ uVar9);
  *param_1 = *param_1 + uVar10;
  param_1[3] = param_1[3] + uVar9;
  param_1[1] = uVar11 + param_1[1] + (uVar5 >> 0xb | uVar5 * 0x200000);
  param_1[2] = param_1[2] + uVar11;
  do {
    *(undefined1 *)puVar6 = 0;
    puVar6 = (uint *)((int)puVar6 + 1);
  } while (puVar6 != &uStack_18);
  return;
}



/* Function: FUN_00013168 @ 00013168 */

void FUN_00013168(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = param_3 * 8 + *(uint *)(param_1 + 0x10);
  uVar2 = (*(uint *)(param_1 + 0x10) & 0x1ff) >> 3;
  *(uint *)(param_1 + 0x10) = uVar1;
  if (uVar1 < param_3 * 8) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  uVar1 = -uVar2 + 0x40;
  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (param_3 >> 0x1d);
  iVar5 = 0;
  if (uVar1 <= param_3) {
    uVar3 = 0;
    do {
      *(undefined1 *)(param_1 + uVar2 + 0x18 + uVar3) = *(undefined1 *)(param_2 + uVar3);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
    FUN_00012944(param_1,param_1 + 0x18);
    iVar5 = param_2 + uVar1;
    for (uVar1 = -uVar2 + 0x7f; uVar1 < param_3; uVar1 = uVar1 + 0x40) {
      FUN_00012944(param_1,iVar5);
      iVar5 = iVar5 + 0x40;
    }
    iVar5 = uVar1 - 0x3f;
    uVar2 = 0;
  }
  for (iVar4 = 0; iVar4 != param_3 - iVar5; iVar4 = iVar4 + 1) {
    *(undefined1 *)(param_1 + uVar2 + 0x18 + iVar4) = *(undefined1 *)(param_2 + iVar5 + iVar4);
  }
  return;
}



/* Function: FUN_000131f0 @ 000131f0 */

void FUN_000131f0(undefined1 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 4) {
    *param_1 = (char)*param_2;
    param_1[1] = (char)((uint)*param_2 >> 8);
    param_1[2] = (char)*(undefined2 *)((int)param_2 + 2);
    uVar2 = *param_2;
    param_2 = param_2 + 1;
    param_1[3] = (char)((uint)uVar2 >> 0x18);
    param_1 = param_1 + 4;
  }
  return;
}



/* Function: FUN_00013214 @ 00013214 */

void FUN_00013214(undefined4 param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 auStack_1c [8];
  int local_14;
  
  local_14 = **(int **)(DAT_00013284 + 0x13220);
  FUN_000131f0(auStack_1c,param_2 + 0x10,8);
  iVar3 = 0x38;
  uVar1 = (*(uint *)(param_2 + 0x10) & 0x1ff) >> 3;
  if (0x37 < uVar1) {
    iVar3 = 0x78;
  }
  FUN_00013168(param_2,DAT_00013288 + 0x13248,iVar3 - uVar1);
  FUN_00013168(param_2,auStack_1c,8);
  FUN_000131f0(param_1,param_2,0x10);
  puVar2 = param_2 + 0x58;
  do {
    *param_2 = 0;
    param_2 = param_2 + 1;
  } while (param_2 != puVar2);
  if (local_14 != **(int **)(DAT_0001328c + 0x13274)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00013290 @ 00013290 */

void FUN_00013290(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_74 [88];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001330c + 0x1329e);
  if (param_4 < 0x10) {
    uVar1 = 0xffffffff;
  }
  else {
    FUN_0001291c(auStack_74);
    iVar3 = param_1;
    for (uVar2 = 0; uVar2 != param_2 >> 10; uVar2 = uVar2 + 1) {
      FUN_00013168(auStack_74,iVar3,0x400);
      iVar3 = iVar3 + 0x400;
    }
    FUN_00013168(auStack_74,param_1 + uVar2 * 0x400,param_2 & 0x3ff);
    FUN_00013214(param_3,auStack_74);
    uVar1 = 0;
  }
  if (local_1c != **(int **)(DAT_00013310 + 0x132fc)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



/* Function: FUN_00013314 @ 00013314 */

undefined4 FUN_00013314(char *param_1,ulong *param_2,uint param_3)

{
  size_t sVar1;
  ulong uVar2;
  undefined4 uVar3;
  ulong *puVar4;
  char local_1c [8];
  
  if (((param_3 < 0x10) || (param_1 == (char *)0x0)) || (sVar1 = strlen(param_1), sVar1 != 0x20)) {
LAB_0001336c:
    uVar3 = 0;
  }
  else {
    local_1c[0] = '\0';
    local_1c[1] = '\0';
    local_1c[2] = '\0';
    local_1c[3] = '\0';
    memset(param_2,0,param_3);
    puVar4 = param_2 + 4;
    do {
      strncpy(local_1c,param_1,2);
      uVar2 = strtoul(local_1c,(char **)0x0,0x10);
      if (uVar2 == 0xffffffff) goto LAB_0001336c;
      *param_2 = uVar2;
      param_2 = (ulong *)((int)param_2 + 1);
      param_1 = param_1 + 2;
    } while (param_2 != puVar4);
    uVar3 = 1;
  }
  return uVar3;
}



/* Function: FUN_00013374 @ 00013374 */

undefined4 FUN_00013374(int param_1,char *param_2,uint param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  char *__format;
  int iVar3;
  char *__s;
  
  uVar2 = 0;
  if (0x20 < param_3) {
    iVar3 = 0;
    __format = (char *)(DAT_000133ac + 0x1338c);
    __s = param_2;
    do {
      pbVar1 = (byte *)(param_1 + iVar3);
      iVar3 = iVar3 + 1;
      sprintf(__s,__format,(uint)*pbVar1);
      __s = __s + 2;
    } while (iVar3 != 0x10);
    param_2[0x20] = '\0';
    uVar2 = 1;
  }
  return uVar2;
}



/* Function: FUN_000133b0 @ 000133b0 */

void FUN_000133b0(char *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined1 *puVar1;
  int iVar2;
  FILE *__stream;
  size_t sVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = DAT_00013474;
  *(undefined4 *)(&stack0xfffffff8 + DAT_00013474) = param_3;
  *(undefined4 *)(&stack0xffffffec + DAT_00013478 + DAT_00013474) =
       **(undefined4 **)(DAT_0001347c + 0x133c4);
  if (((param_4 < 0x10) || ((int)param_2 < 1)) ||
     (__stream = fopen(param_1,(char *)(DAT_00013480 + 0x133d6)), __stream == (FILE *)0x0)) {
    uVar4 = 0xffffffff;
  }
  else {
    *(int *)(&stack0xfffffff4 + iVar2) = (int)param_2 >> 10;
    *(undefined1 **)(&stack0xfffffff0 + iVar2) = &stack0xffffffec + DAT_00013484 + iVar2;
    iVar5 = 0;
    FUN_0001291c(&stack0xffffffec + DAT_00013484 + iVar2);
    puVar1 = &stack0xfffffffc + iVar2;
    while ((iVar5 < *(int *)(&stack0xfffffff4 + iVar2) &&
           (sVar3 = fread(puVar1,1,0x400,__stream), 0 < (int)sVar3))) {
      uVar4 = *(undefined4 *)(&stack0xfffffff0 + iVar2);
      puVar1[sVar3] = 0;
      FUN_00013168(uVar4,puVar1);
      iVar5 = iVar5 + 1;
    }
    puVar1 = &stack0xfffffffc + iVar2;
    sVar3 = fread(puVar1,1,param_2 & 0x3ff,__stream);
    if (sVar3 == (param_2 & 0x3ff)) {
      puVar1[sVar3] = 0;
      FUN_00013168(&stack0xffffffec + DAT_00013484 + iVar2,puVar1,sVar3);
    }
    fclose(__stream);
    FUN_00013214(*(undefined4 *)(&stack0xfffffff8 + iVar2),&stack0xffffffec + DAT_00013484 + iVar2);
    uVar4 = 0;
  }
  if (*(int *)(&stack0xffffffec + DAT_00013478 + iVar2) != **(int **)(DAT_00013488 + 0x1345e)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



/* Function: FUN_0001354c @ 0001354c */

void FUN_0001354c(void *param_1,size_t param_2,void *param_3)

{
  memset(param_3,0,0x10);
  if (((int)param_2 < 0x11) || (param_1 == (void *)0x0)) {
    if ((0 < (int)param_2) && (param_1 != (void *)0x0)) {
      memcpy(param_3,param_1,param_2);
    }
  }
  else {
    FUN_00013290(param_1,param_2,param_3,0x10);
  }
  return;
}



/* Function: FUN_00013590 @ 00013590 */

uint FUN_00013590(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
                 int param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint auStack_28 [5];
  
  if ((param_2 & 3) == 0) {
    if (param_5 == (uint *)0x0) {
      return param_2;
    }
    iVar1 = 2;
    if ((int)param_2 <= param_6) {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      iVar7 = (int)param_2 >> 2;
      uVar9 = iVar7 - 1;
      FUN_0001354c(param_3,param_4,auStack_28);
      iVar1 = 3;
      if (uVar9 != 0) {
        iVar1 = FUN_0001e6f8(0x34,iVar7);
        uVar8 = *param_5;
        for (uVar6 = (iVar1 + 6) * DAT_000136b0; uVar6 != 0; uVar6 = uVar6 + iVar1) {
          uVar2 = uVar6 >> 2 & 3;
          puVar3 = param_5 + uVar9;
          uVar5 = uVar9;
          while( true ) {
            iVar1 = DAT_000136b4;
            if ((int)uVar5 < 1) break;
            uVar4 = uVar5 & 3;
            puVar10 = puVar3 + -1;
            uVar5 = uVar5 - 1;
            uVar8 = *puVar3 - ((auStack_28[uVar4 ^ uVar2] ^ *puVar10) + (uVar8 ^ uVar6) ^
                              (uVar8 >> 3 ^ *puVar10 << 4) + (*puVar10 >> 5 ^ uVar8 << 2));
            *puVar3 = uVar8;
            puVar3 = puVar10;
          }
          uVar4 = param_5[uVar9];
          uVar8 = *param_5 -
                  ((auStack_28[uVar5 & 3 ^ uVar2] ^ uVar4) + (uVar8 ^ uVar6) ^
                  (uVar4 << 4 ^ uVar8 >> 3) + (uVar4 >> 5 ^ uVar8 << 2));
          *param_5 = uVar8;
        }
        uVar6 = param_5[iVar7 + -1];
        if ((-1 < (int)uVar6) && ((int)uVar6 <= (int)(uVar9 * 4))) {
          *(undefined1 *)((int)param_5 + uVar6) = 0;
          return uVar6;
        }
        iVar1 = 4;
      }
    }
  }
  else {
    iVar1 = 1;
  }
  return -iVar1;
}



/* Function: FUN_000136b8 @ 000136b8 */

int FUN_000136b8(undefined4 param_1,size_t param_2,undefined4 *param_3,int *param_4)

{
  void *__ptr;
  int iVar1;
  size_t sVar2;
  char *__s;
  
  __ptr = malloc(param_2);
  if (__ptr == (void *)0x0) {
    iVar1 = 1;
  }
  else {
    __s = *(char **)(DAT_0001370c + 0x136d8);
    sVar2 = strlen(__s);
    iVar1 = FUN_00013590(param_1,param_2,__s,sVar2,__ptr,param_2);
    if (-1 < iVar1) {
      *param_4 = iVar1;
      *param_3 = __ptr;
      return 0;
    }
    free(__ptr);
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_00013710 @ 00013710 */

int FUN_00013710(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
                int param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint auStack_28 [5];
  
  iVar6 = param_2 + 4;
  uVar2 = param_2 & 3;
  if (uVar2 != 0) {
    iVar6 = (param_2 + 8) - uVar2;
  }
  if (param_5 != (uint *)0x0) {
    if (param_6 < iVar6) {
      iVar6 = -1;
    }
    else {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      iVar6 = iVar6 >> 2;
      param_5[iVar6 + -1] = param_2;
      if (uVar2 != 0) {
        memset((void *)((int)param_5 + param_2),0,4 - uVar2);
      }
      FUN_0001354c(param_3,param_4,auStack_28);
      iVar1 = FUN_0001e6f8(0x34,iVar6);
      puVar7 = param_5 + iVar6 + -1;
      uVar8 = *puVar7;
      uVar2 = 0;
      for (iVar1 = iVar1 + 6; 0 < iVar1; iVar1 = iVar1 + -1) {
        uVar2 = uVar2 + DAT_00013834;
        uVar9 = uVar2 >> 2 & 3;
        uVar5 = 0;
        puVar3 = param_5;
        while( true ) {
          if (iVar6 + -1 <= (int)uVar5) break;
          uVar4 = uVar5 & 3;
          uVar5 = uVar5 + 1;
          uVar8 = ((uVar8 << 4 ^ puVar3[1] >> 3) + (puVar3[1] << 2 ^ uVar8 >> 5) ^
                  (auStack_28[uVar4 ^ uVar9] ^ uVar8) + (uVar2 ^ puVar3[1])) + *puVar3;
          *puVar3 = uVar8;
          puVar3 = puVar3 + 1;
        }
        uVar4 = *param_5;
        uVar8 = ((uVar8 ^ auStack_28[uVar5 & 3 ^ uVar9]) + (uVar2 ^ uVar4) ^
                (uVar4 >> 3 ^ uVar8 << 4) + (uVar4 << 2 ^ uVar8 >> 5)) + *puVar7;
        *puVar7 = uVar8;
      }
      iVar6 = iVar6 << 2;
    }
  }
  return iVar6;
}



/* Function: FUN_00013838 @ 00013838 */

undefined4 FUN_00013838(char *param_1,size_t param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  if (param_1 == (char *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    if ((int)param_2 < 1) {
      param_2 = strlen(param_1);
    }
    iVar5 = DAT_000138a8 + 0x1385e;
    for (iVar7 = 0; iVar7 < (int)param_2; iVar7 = iVar7 + iVar2) {
      pcVar6 = param_1 + iVar7;
      iVar2 = FUN_00016298(*pcVar6);
      if (iVar2 == 3) {
        iVar3 = FUN_000165c8(iVar5,6,pcVar6,3,0,DAT_000138ac);
        if (-1 < iVar3) {
          iVar3 = iVar5 + iVar3 * 6;
          *pcVar6 = *(char *)(iVar3 + 3);
          cVar1 = *(char *)(iVar3 + 5);
          pcVar6[1] = *(char *)(iVar3 + 4);
          pcVar6[2] = cVar1;
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



/* Function: FUN_000138bc @ 000138bc */

void FUN_000138bc(undefined4 *param_1)

{
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



/* Function: FUN_00013930 @ 00013930 */

undefined4 FUN_00013930(int *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  char *__s;
  int local_20;
  size_t local_1c;
  
  if (param_2 == (char *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    local_1c = param_3;
    if ((int)param_3 < 1) {
      local_1c = strlen(param_2);
    }
    pcVar4 = (char *)*param_1;
    if (pcVar4 == (char *)0x0) {
      local_20 = 9;
      pcVar4 = (char *)(DAT_000139b4 + 0x13968);
    }
    else {
      local_20 = param_1[1];
    }
    __s = pcVar4;
    for (iVar5 = 0; iVar5 < local_20; iVar5 = iVar5 + 1) {
      sVar3 = strlen(__s);
      iVar1 = strncmp(__s,param_2,sVar3);
      __s = __s + 10;
      if (iVar1 == 0) goto LAB_00013990;
    }
    uVar2 = 1;
    if (iVar5 != local_20) {
LAB_00013990:
      sVar3 = strlen(pcVar4 + iVar5 * 10);
      memmove(param_2,param_2 + sVar3,local_1c - sVar3);
      param_2[local_1c - sVar3] = '\0';
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* Function: FUN_000139b8 @ 000139b8 */

void FUN_000139b8(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  param_1[1] = 0;
  return;
}



/* Function: FUN_000139d0 @ 000139d0 */

int FUN_000139d0(undefined4 *param_1,ushort *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *__dest;
  uint __n;
  int local_30;
  
  iVar1 = 1;
  if (param_2 != (ushort *)0x0) {
    if ((int)param_3 < 1) {
      iVar1 = 2;
    }
    else {
      pcVar2 = calloc(param_3,10);
      if (pcVar2 == (char *)0x0) {
        iVar1 = 3;
      }
      else {
        local_30 = 0;
        __dest = pcVar2;
        for (; __n = (uint)*param_2, __n - 1 < 9; param_2 = (ushort *)((int)param_2 + __n + 3)) {
          local_30 = local_30 + __n + 3;
          if (param_4 < local_30) {
LAB_00013a52:
            iVar1 = 5;
            goto LAB_000139ea;
          }
          strncpy(__dest,(char *)(param_2 + 1),__n);
          __dest[__n] = '\0';
          __dest = __dest + 10;
          if (__dest == pcVar2 + param_3 * 10) {
            if (local_30 == param_4) {
              param_1[1] = param_3;
              if ((void *)*param_1 != (void *)0x0) {
                free((void *)*param_1);
              }
              *param_1 = pcVar2;
              return 0;
            }
            goto LAB_00013a52;
          }
        }
        iVar1 = 4;
      }
    }
  }
LAB_000139ea:
  return -iVar1;
}



/* Function: FUN_00013a70 @ 00013a70 */

int FUN_00013a70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c [2];
  
  local_1c[0] = 0;
  iVar1 = FUN_00011db4(param_1 + 8,local_1c,param_2,param_3,param_4,3,param_5);
  iVar2 = 1;
  if (-1 < iVar1) {
    iVar1 = FUN_000139d0(param_1,local_1c[0],iVar1,param_4);
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = 2;
  }
  return -iVar2;
}



/* Function: FUN_00013ab8 @ 00013ab8 */

int FUN_00013ab8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_7c [92];
  uint local_20;
  uint local_1c;
  uint local_18;
  byte local_14;
  
  iVar2 = 1;
  if (param_2 != 0) {
    iVar1 = FUN_00011e8c(param_1 + 8,auStack_7c);
    iVar2 = 2;
    if (-1 < iVar1) {
      uVar3 = local_1c << 0x18 | local_20 >> 8;
      if (uVar3 == 0) {
        iVar2 = 4;
      }
      else {
        iVar2 = FUN_00013a70(param_1,local_18 << 0x18 | local_1c >> 8,
                             (uint)local_14 << 0x18 | local_18 >> 8,uVar3,1);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = 3;
      }
    }
  }
  return -iVar2;
}



/* Function: FUN_00013b18 @ 00013b18 */

int FUN_00013b18(int param_1)

{
  FUN_000139b8();
  FUN_00011e54(param_1 + 8);
  return param_1;
}



/* Function: FUN_00013b2c @ 00013b2c */

int FUN_00013b2c(int param_1)

{
  FUN_000139b8();
  FUN_00011e54(param_1 + 8);
  return param_1;
}



/* Function: FUN_00013b40 @ 00013b40 */

int FUN_00013b40(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
                int param_7)

{
  int iVar1;
  
  if (param_7 - 1U < 9) {
    if ((param_4 < 0x18) || (param_2 < 0x18)) {
      iVar1 = 2;
    }
    else if (param_1 == 0) {
      iVar1 = 3;
    }
    else if (param_3 == 0) {
      iVar1 = 4;
    }
    else {
      if (param_5 != 0) {
        iVar1 = (**(code **)(param_7 * 4 + DAT_00013b8c + 0x13b84))();
        return iVar1;
      }
      iVar1 = 5;
    }
  }
  else {
    iVar1 = 1;
  }
  return -iVar1;
}



/* Function: FUN_00013b90 @ 00013b90 */

undefined4
FUN_00013b90(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int param_6)

{
  code cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if ((0x1d < param_6) && (0 < param_4)) {
    uVar3 = FUN_0001eac8(param_4 - param_2);
    uVar4 = FUN_0001eac8(param_4);
    uVar3 = FUN_0001ee10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar4,
                         (int)((ulonglong)uVar4 >> 0x20));
    uVar3 = FUN_0001eba4((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_00013c00,DAT_00013c04);
    cVar1 = FUN_00013c10[DAT_00013c08 + 4];
    if ((char)cVar1 < '\r') {
      cVar1 = (code)0xd;
    }
    uVar4 = FUN_0001eac8((int)(char)cVar1);
    iVar2 = FUN_0001f12c((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar4,
                         (int)((ulonglong)uVar4 >> 0x20));
    if (iVar2 != 0) {
      return 0xe;
    }
  }
  return 0;
}



/* Function: FUN_00013c10 @ 00013c10 */

int FUN_00013c10(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 - 1U < 0x10) {
    iVar1 = DAT_00013c28 + 0x13c24 + param_1 * 5;
  }
  return iVar1;
}



/* Function: FUN_00013c2c @ 00013c2c */

undefined4 FUN_00013c2c(void)

{
  return 0;
}



/* Function: FUN_00013c30 @ 00013c30 */

void FUN_00013c30(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  char *__format;
  int iVar5;
  
  printf((char *)(DAT_00013cb4 + 0x13c3c),0x10);
  pbVar4 = (byte *)(DAT_00013cb8 + 0x13c4d);
  pbVar1 = (byte *)(DAT_00013cb8 + 0x13c9d);
  __format = (char *)(DAT_00013cbc + 0x13c54);
  iVar2 = DAT_00013cc4 + 0x13c56;
  iVar3 = DAT_00013cc0 + 0x13c58;
  iVar5 = DAT_00013cc8 + 0x13c5a;
  do {
    printf(__format,iVar3,iVar5,(uint)*pbVar4);
    printf(__format,iVar3,iVar2,(uint)pbVar4[1]);
    printf((char *)(DAT_00013ccc + 0x13c82),iVar3,DAT_00013cd0 + 0x13c80,(int)(char)pbVar4[2]);
    printf(__format,iVar3,DAT_00013cd4 + 0x13c8e,(uint)pbVar4[3]);
    printf(__format,iVar3,DAT_00013cd8 + 0x13c9c,(uint)pbVar4[4]);
    putchar(10);
    pbVar4 = pbVar4 + 5;
  } while (pbVar4 != pbVar1);
  return;
}



/* Function: FUN_00013cdc @ 00013cdc */

undefined4
FUN_00013cdc(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  byte *local_14;
  
  local_14 = (byte *)0x0;
  iVar1 = FUN_00011db4(param_5,&local_14,param_1,param_2,param_3,5,param_4);
  if (iVar1 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    if (0xf < param_3) {
      uVar3 = 1;
      puVar4 = (undefined1 *)(DAT_00013d5c + 0x13d1d);
      pbVar5 = local_14;
      do {
        if (uVar3 != *pbVar5) break;
        if ((pbVar5[1] < 3) && ((byte)(pbVar5[2] + 0x50) < 0xa1)) {
          *puVar4 = (char)uVar3;
          puVar4[1] = pbVar5[1];
          puVar4[2] = pbVar5[2];
          puVar4[3] = pbVar5[3];
          puVar4[4] = pbVar5[4];
        }
        uVar3 = uVar3 + 1;
        pbVar5 = pbVar5 + 5;
        puVar4 = puVar4 + 5;
      } while (uVar3 != 0x11);
    }
    if (local_14 != (byte *)0x0) {
      free(local_14);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_00013dac @ 00013dac */

int FUN_00013dac(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == 0) {
    iVar2 = -1;
  }
  else {
    iVar1 = FUN_000148ac(param_3,param_4);
    iVar2 = 0;
    if (iVar1 == 1) {
      iVar2 = FUN_00014960(param_3,param_4);
      iVar2 = 10 - (uint)(iVar2 == 1);
    }
  }
  return iVar2;
}



/* Function: FUN_00013de0 @ 00013de0 */

int FUN_00013de0(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_1 != 0) {
    if (param_3 != 0) {
      iVar1 = FUN_000143e0();
      if ((iVar1 != 1) && (iVar1 = FUN_000143e0(param_3,param_4), iVar1 != 1)) {
        return 0;
      }
      return 8;
    }
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_00013e14 @ 00013e14 */

int FUN_00013e14(int param_1,undefined4 param_2,int param_3,undefined4 param_4,char *param_5,
                int param_6)

{
  int iVar1;
  size_t sVar2;
  size_t __n;
  size_t local_20;
  int local_1c [2];
  
  iVar1 = 1;
  if ((param_1 != 0) && (iVar1 = 2, param_5 != (char *)0x0)) {
    if (param_3 != 0) {
      if (9 < param_6) {
        local_1c[0] = 0;
        local_20 = 0;
        iVar1 = FUN_00014460(param_3,param_4,local_1c,&local_20);
        if ((iVar1 == 1) ||
           (iVar1 = FUN_00014460(param_1,param_2,local_1c,&local_20), param_3 = param_1, iVar1 == 1)
           ) {
          sVar2 = strlen(param_5);
          if (local_20 - 0xb < 2) {
            if ((int)local_20 <= (int)sVar2) {
              param_5 = param_5 + (sVar2 - local_20) + 1;
            }
            __n = local_20 - 1;
            iVar1 = local_1c[0] + 1;
          }
          else {
            __n = local_20;
            iVar1 = local_1c[0];
            if ((int)local_20 <= (int)sVar2) {
              param_5 = param_5 + (sVar2 - local_20);
            }
          }
          iVar1 = strncmp((char *)(param_3 + iVar1),param_5,__n);
          if (iVar1 != 0) {
            if ((param_6 == 10) && (*(char *)(DAT_00013ecc + 0x13f08) == '\x01')) {
              return 0x10;
            }
            return 6;
          }
          return 7;
        }
      }
      return 0;
    }
    iVar1 = 3;
  }
  return -iVar1;
}



/* Function: FUN_00013ed0 @ 00013ed0 */

uint FUN_00013ed0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char *__s1;
  char *pcVar3;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar2 = (param_2 - param_3) - param_4;
  if (2 < iVar2) {
    if ((5 < iVar2) &&
       (iVar1 = strncmp((char *)(param_1 + param_4 + param_3),(char *)(DAT_00013f98 + 0x13efc),6),
       iVar1 == 0)) {
      return 0;
    }
    pcVar3 = (char *)(param_1 + param_4 + param_3);
    iVar1 = FUN_000149bc(pcVar3);
    if (iVar1 == 1) {
      return 1;
    }
    iVar1 = strncmp(pcVar3,(char *)(DAT_00013f9c + 0x13f1c),3);
    if (iVar1 == 0) {
      return 1;
    }
    if ((5 < iVar2) &&
       (iVar2 = strncmp(pcVar3,(char *)(param_1 + param_4 + param_3 + 3),3), iVar2 == 0)) {
      return 1;
    }
  }
  if (2 < param_3) {
    pcVar3 = (char *)(param_1 + param_3 + -3);
    iVar2 = FUN_000149bc(pcVar3);
    if (iVar2 == 1) {
      return 1;
    }
    if (5 < param_3) {
      __s1 = (char *)(param_1 + param_3 + -6);
      iVar2 = FUN_000149bc(__s1);
      if (iVar2 == 1) {
        return 1;
      }
      iVar2 = strncmp(__s1,(char *)(DAT_00013fa0 + 0x13f66),3);
      if (iVar2 == 0) {
        return 1;
      }
      iVar2 = strncmp(__s1,pcVar3,3);
      if (iVar2 == 0) {
        return 1;
      }
      if (8 < param_3) {
        iVar2 = FUN_000149bc(param_1 + param_3 + -9);
        return (uint)(iVar2 == 1);
      }
    }
  }
  return 0;
}



/* Function: FUN_00013fa4 @ 00013fa4 */

int FUN_00013fa4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char *param_5,
                int param_6)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int local_1c [2];
  
  iVar1 = 1;
  if (param_1 != 0) {
    if (param_5 != (char *)0x0) {
      if (9 < param_6) {
        local_1c[0] = 0;
        iVar1 = FUN_00014650(param_1,param_2,local_1c);
        if (iVar1 == 1) {
          sVar2 = strlen(param_5);
          iVar1 = local_1c[0];
          if (0xb < (int)sVar2) {
            param_5 = param_5 + (sVar2 - 0xb);
          }
          iVar3 = strncmp((char *)(param_1 + local_1c[0]),param_5,0xb);
          if (iVar3 == 0) {
            return 5;
          }
          iVar1 = FUN_00013ed0(param_1,param_2,iVar1,0xb);
          return 4 - (uint)(iVar1 == 1);
        }
      }
      return 0;
    }
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_00014060 @ 00014060 */

bool FUN_00014060(int param_1)

{
  bool bVar1;
  
  if ((param_1 == 0x69) || (param_1 == 0x31)) {
    bVar1 = true;
  }
  else {
    bVar1 = param_1 == 0x49;
  }
  return bVar1;
}



/* Function: FUN_00014090 @ 00014090 */

int FUN_00014090(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = 0;
  if (param_1 != 0) {
    iVar3 = 0;
    while( true ) {
      uVar2 = (uint)*(byte *)(param_1 + iVar3);
      if (((param_2 <= iVar3) || (uVar2 == 0)) ||
         (((uVar2 == 0xffffffff ||
           ((*(byte *)(**(int **)(DAT_000140e0 + 0x140a4) + uVar2 + 1) & 4) == 0)) &&
          ((((uVar2 != 0x4f && (uVar2 != 0x6f)) && (uVar2 != 0x69)) && (uVar2 != 0x49)))))) break;
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}



/* Function: FUN_000140e4 @ 000140e4 */

bool FUN_000140e4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 != 0) {
    iVar1 = FUN_00014090(param_1,param_3);
    bVar2 = iVar1 == param_3;
  }
  return bVar2;
}



/* Function: FUN_00014100 @ 00014100 */

int FUN_00014100(byte *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    while( true ) {
      uVar2 = (uint)*param_1;
      if ((uVar2 == 0) ||
         ((((uVar2 == 0xffffffff ||
            ((*(byte *)(**(int **)(DAT_00014140 + 0x14112) + uVar2 + 1) & 4) == 0)) &&
           (uVar2 != 0x4f)) && (((uVar2 != 0x6f && (uVar2 != 0x69)) && (uVar2 != 0x49)))))) break;
      param_1 = param_1 + 1;
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}



/* Function: FUN_00014144 @ 00014144 */

bool FUN_00014144(undefined1 *param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  if ((param_1 == (undefined1 *)0x0) || (iVar2 = FUN_00014060(*param_1), iVar2 == 0)) {
    bVar3 = false;
  }
  else {
    cVar1 = param_1[1];
    if ((cVar1 == '5') || (cVar1 == '3')) {
      bVar3 = true;
    }
    else {
      bVar3 = cVar1 == '8';
    }
  }
  return bVar3;
}



/* Function: FUN_00014170 @ 00014170 */

bool FUN_00014170(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if (((param_1 == 0) || (param_2 < 0xb)) || (iVar1 = FUN_00014144(), iVar1 == 0)) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_000140e4(param_1 + 2,param_2 + -2,9);
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}



/* Function: FUN_00014204 @ 00014204 */

bool FUN_00014204(int param_1,char *param_2)

{
  char *pcVar1;
  bool bVar2;
  
  if ((param_1 == 0) || (param_2 == (char *)0x0)) {
    bVar2 = false;
  }
  else {
    pcVar1 = strstr(param_2,(char *)(DAT_00014254 + 0x14218));
    if ((pcVar1 == (char *)0x0) ||
       ((pcVar1 = strstr(param_2,(char *)(DAT_00014258 + 0x14226)), pcVar1 == (char *)0x0 &&
        (pcVar1 = strstr(param_2,(char *)(DAT_0001425c + 0x14234)), pcVar1 == (char *)0x0)))) {
      pcVar1 = strstr(param_2,(char *)(DAT_00014260 + 0x14242));
      bVar2 = pcVar1 != (char *)0x0;
    }
    else {
      bVar2 = true;
    }
  }
  return bVar2;
}



/* Function: FUN_00014264 @ 00014264 */

bool FUN_00014264(char *param_1,int param_2)

{
  int iVar1;
  char *__s2;
  
  if (param_1 != (char *)0x0) {
    __s2 = (char *)(DAT_000142ac + 0x14276);
    iVar1 = strncmp(param_1,__s2,3);
    if (iVar1 == 0) {
      return true;
    }
    iVar1 = strncmp(param_1,(char *)(DAT_000142b0 + 0x1428a),3);
    if ((iVar1 == 0) && (5 < param_2)) {
      iVar1 = strncmp(param_1 + param_2 + -5,__s2,3);
      return iVar1 == 0;
    }
  }
  return false;
}



/* Function: FUN_000142b4 @ 000142b4 */

bool FUN_000142b4(char *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == (char *)0x0) || (param_2 != 10)) {
    bVar2 = false;
  }
  else {
    iVar1 = strncmp(param_1,(char *)(DAT_000142d4 + 0x142c6),3);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



/* Function: FUN_000142d8 @ 000142d8 */

bool FUN_000142d8(char *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 == (char *)0x0) || (param_2 != 10)) {
    bVar2 = false;
  }
  else {
    iVar1 = strncmp(param_1,(char *)(DAT_000142f8 + 0x142ea),3);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



/* Function: FUN_00014320 @ 00014320 */

undefined4 FUN_00014320(int param_1)

{
  char *__s1;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (__s1 = (char *)FUN_00016350(), __s1 != (char *)0x0)) {
    iVar3 = 0;
    iVar2 = DAT_00014354 + 0x14338;
    do {
      iVar1 = strcmp(__s1,(char *)(iVar2 + iVar3 * 6));
      if (iVar1 == 0) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 6);
  }
  return 0;
}



/* Function: FUN_00014358 @ 00014358 */

undefined4 FUN_00014358(undefined1 *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    while (9 < param_2) {
      iVar1 = FUN_00016298(*param_1);
      if (iVar1 == 1) {
        iVar1 = FUN_00014100(param_1);
        if (iVar1 == 10) {
          iVar1 = FUN_000142b4(param_1,10);
          if (iVar1 == 1) {
            return 1;
          }
          iVar1 = 10;
          goto LAB_00014390;
        }
        if (0 < iVar1) goto LAB_00014390;
        param_2 = param_2 + -1;
        param_1 = param_1 + 1;
      }
      else {
LAB_00014390:
        param_2 = param_2 - iVar1;
        param_1 = param_1 + iVar1;
      }
    }
  }
  return 0;
}



/* Function: FUN_0001439c @ 0001439c */

undefined4 FUN_0001439c(undefined1 *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    while (9 < param_2) {
      iVar1 = FUN_00016298(*param_1);
      if (iVar1 == 1) {
        iVar1 = FUN_00014100(param_1);
        if (iVar1 == 10) {
          iVar1 = FUN_000142d8(param_1,10);
          if (iVar1 == 1) {
            return 1;
          }
          iVar1 = 10;
          goto LAB_000143d4;
        }
        if (0 < iVar1) goto LAB_000143d4;
        param_2 = param_2 + -1;
        param_1 = param_1 + 1;
      }
      else {
LAB_000143d4:
        param_2 = param_2 - iVar1;
        param_1 = param_1 + iVar1;
      }
    }
  }
  return 0;
}



/* Function: FUN_000143e0 @ 000143e0 */

bool FUN_000143e0(int param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 != 0) {
    iVar1 = FUN_0001439c(param_1);
    bVar2 = true;
    if (iVar1 == 0) {
      iVar1 = FUN_00014358(param_1,param_2);
      bVar2 = iVar1 != 0;
    }
  }
  return bVar2;
}



/* Function: FUN_00014460 @ 00014460 */

undefined4 FUN_00014460(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *__needle;
  int iVar5;
  char *__needle_00;
  char *__s1;
  int iVar6;
  
  if (((param_1 != (char *)0x0) && (param_3 != (int *)0x0)) && (param_4 != (int *)0x0)) {
    __needle = (char *)(DAT_00014618 + 0x14488);
    __needle_00 = (char *)(DAT_0001461c + 0x1448a);
    __s1 = param_1;
    iVar6 = param_2;
    while (6 < iVar6) {
      iVar2 = FUN_00016298(*__s1);
      if (iVar2 == 1) {
        iVar2 = FUN_00014100(__s1);
        if (iVar2 < 7) {
          if (0 < iVar2) goto LAB_000144ba;
          iVar6 = iVar6 + -1;
          __s1 = __s1 + 1;
        }
        else {
          cVar1 = *__s1;
          if (cVar1 != '1') {
            if ((cVar1 == 'o') || (cVar1 == '0')) {
              if ((iVar2 - 0xbU < 2) &&
                 ((param_2 - iVar6 < 7 ||
                  ((pcVar3 = strstr(param_1,__needle), pcVar3 == (char *)0x0 &&
                   (pcVar3 = strstr(param_1,__needle_00), pcVar3 == (char *)0x0)))))) {
                *param_3 = param_2 - iVar6;
                *param_4 = iVar2;
                return 1;
              }
            }
            else if (iVar2 - 7U < 2) {
              pcVar3 = strstr(param_1,(char *)(DAT_00014620 + 0x14512));
              iVar5 = param_2 - iVar6;
              if ((((((((pcVar3 == (char *)0x0) || (iVar5 < (int)pcVar3 - (int)param_1)) &&
                      ((pcVar3 = strstr(param_1,(char *)(DAT_00014624 + 0x1452c)),
                       pcVar3 == (char *)0x0 || (iVar5 < (int)pcVar3 - (int)param_1)))) &&
                     ((((iVar5 < 7 ||
                        (pcVar3 = strstr(param_1,(char *)(DAT_00014628 + 0x14548)),
                        pcVar3 == (char *)0x0)) &&
                       (iVar4 = strncmp(__s1,(char *)(DAT_0001462c + 0x14558),3), iVar4 != 0)) &&
                      ((pcVar3 = strstr(param_1,(char *)(DAT_00014630 + 0x14566)),
                       pcVar3 == (char *)0x0 || ((char *)0x3 < __s1 + (-6 - (int)pcVar3))))))) &&
                    ((iVar5 < 7 ||
                     (pcVar3 = strstr(param_1,(char *)(DAT_00014634 + 0x14582)),
                     pcVar3 == (char *)0x0)))) &&
                   (((iVar4 = strncmp(__s1 + iVar2,(char *)(DAT_00014638 + 0x14592),3), iVar4 != 0
                     && (pcVar3 = strstr(param_1,(char *)(DAT_0001463c + 0x145a0)),
                        pcVar3 == (char *)0x0)) &&
                    ((pcVar3 = strstr(param_1,(char *)(DAT_00014640 + 0x145ae)),
                     pcVar3 == (char *)0x0 &&
                     ((pcVar3 = strstr(param_1,(char *)(DAT_00014644 + 0x145bc)),
                      pcVar3 == (char *)0x0 || ((char *)0x3 < __s1 + (-6 - (int)pcVar3))))))))) &&
                  ((pcVar3 = strstr(param_1,(char *)(DAT_00014648 + 0x145d2)), pcVar3 == (char *)0x0
                   || (((int)__s1 - (int)pcVar3 != 9 && ((int)__s1 - (int)pcVar3 != 6)))))) &&
                 (iVar4 = strncmp(__s1,(char *)(DAT_0001464c + 0x1460e),7), iVar4 != 0)) {
                *param_3 = iVar5;
                *param_4 = iVar2;
                return 1;
              }
            }
            goto LAB_000145f4;
          }
LAB_000144ba:
          iVar6 = iVar6 - iVar2;
          __s1 = __s1 + iVar2;
        }
      }
      else {
LAB_000145f4:
        iVar6 = iVar6 - iVar2;
        __s1 = __s1 + iVar2;
      }
    }
  }
  return 0;
}



/* Function: FUN_00014650 @ 00014650 */

undefined4 FUN_00014650(undefined1 *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int local_28;
  
  iVar1 = DAT_000146e8;
  iVar5 = DAT_000146e4 + 0x1465c;
  if ((param_1 != (undefined1 *)0x0) && (param_3 != (int *)0x0)) {
    local_28 = 0;
    puVar6 = param_1;
    for (iVar4 = param_2; 10 < iVar4; iVar4 = iVar4 - iVar2) {
      iVar2 = FUN_00016298(*puVar6);
      if ((((iVar2 == 1) && (iVar3 = FUN_00014170(puVar6,iVar4), iVar3 != 0)) &&
          ((local_28 != 1 ||
           ((*(byte *)(**(int **)(iVar5 + iVar1) + (uint)(byte)param_1[(param_2 + -1) - iVar4] + 1)
            & 4) == 0)))) &&
         ((iVar4 == 0xb ||
          ((*(byte *)(**(int **)(iVar5 + iVar1) + (uint)(byte)puVar6[0xb] + 1) & 4) == 0)))) {
        *param_3 = param_2 - iVar4;
        return 1;
      }
      puVar6 = puVar6 + iVar2;
      local_28 = iVar2;
    }
  }
  return 0;
}



/* Function: FUN_000146ec @ 000146ec */

undefined4 FUN_000146ec(char *param_1,int param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if ((param_1 != (char *)0x0) && (param_3 != (char *)0x0)) {
    pcVar1 = strchr(param_1,0x71);
    pcVar2 = strstr(param_3,(char *)(DAT_00014750 + 0x1470c));
    if ((pcVar2 == (char *)0x0) && (pcVar1 != (char *)0x0)) {
      param_2 = param_2 - ((int)pcVar1 - (int)param_1);
LAB_0001473c:
      param_2 = param_2 + -1;
      pcVar1 = pcVar1 + 1;
      do {
        if (param_2 < 8) {
          return 0;
        }
        iVar3 = FUN_00016298(*pcVar1);
        if (iVar3 == 1) {
          iVar3 = FUN_00014100(pcVar1);
          if (iVar3 - 8U < 4) {
            return 1;
          }
          if (iVar3 < 1) goto LAB_0001473c;
        }
        param_2 = param_2 - iVar3;
        pcVar1 = pcVar1 + iVar3;
      } while( true );
    }
  }
  return 0;
}



/* Function: FUN_00014754 @ 00014754 */

undefined4 FUN_00014754(char *param_1)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  char *__needle;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar1 = DAT_000147e0;
  iVar5 = DAT_000147d8 + 0x1475e;
  if (param_1 != (char *)0x0) {
    iVar6 = 0;
    pcVar7 = (char *)(DAT_000147dc + 0x1478e);
    pcVar8 = pcVar7;
    do {
      __needle = pcVar7 + iVar6 * 6;
      pcVar2 = strstr(param_1,__needle);
      if (pcVar2 != (char *)0x0) {
        if (*pcVar8 == '.') {
          sVar3 = strlen(__needle);
          iVar4 = FUN_00016298(pcVar2[sVar3]);
          if ((iVar4 == 1) &&
             ((*(byte *)(**(int **)(iVar5 + iVar1) + (uint)(byte)pcVar2[sVar3] + 1) & 7) != 0))
          goto LAB_000147c8;
        }
        pcVar2 = strchr(param_1,0x40);
        if (pcVar2 != (char *)0x0) {
          return 1;
        }
      }
LAB_000147c8:
      iVar6 = iVar6 + 1;
      pcVar8 = pcVar8 + 6;
    } while (iVar6 != 6);
  }
  return 0;
}



/* Function: FUN_000147e4 @ 000147e4 */

undefined4 FUN_000147e4(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  size_t __n;
  int iVar3;
  
  if (param_1 != (char *)0x0) {
    while (0xe < param_2) {
      iVar2 = FUN_00016298(*param_1);
      if (iVar2 == 1) {
        iVar2 = FUN_00014100(param_1);
        iVar1 = DAT_00014850;
        if (0xe < iVar2) {
          iVar2 = 0;
          do {
            __n = strlen(&UNK_00014854 + iVar2 * 5 + iVar1);
            iVar3 = strncmp(param_1,&UNK_00014854 + iVar2 * 5 + iVar1,__n);
            if (iVar3 == 0) {
              return 2;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 != 7);
          return 1;
        }
        if (0 < iVar2) goto LAB_00014842;
        param_2 = param_2 + -1;
        param_1 = param_1 + 1;
      }
      else {
LAB_00014842:
        param_2 = param_2 - iVar2;
        param_1 = param_1 + iVar2;
      }
    }
  }
  return 0;
}



/* Function: FUN_000148ac @ 000148ac */

undefined4 FUN_000148ac(char *param_1)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  
  iVar5 = DAT_00014950 + 0x148b6;
  if (param_1 != (char *)0x0) {
    iVar6 = 0;
    iVar7 = DAT_00014954 + 0x14900;
    do {
      iVar2 = FUN_000162dc(param_1,iVar7 + iVar6 * 0xe);
      iVar1 = DAT_0001495c;
      if (iVar2 != 0) {
        return 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 10);
    iVar6 = 0;
    pcVar8 = &UNK_0001494e + DAT_00014958;
    pcVar9 = pcVar8;
    do {
      iVar7 = FUN_000162dc(param_1,pcVar8 + iVar6 * 6);
      if (iVar7 != 0) {
        if (*pcVar9 == '.') {
          sVar3 = strlen(pcVar8 + iVar6 * 6);
          iVar2 = FUN_00016298(*(byte *)(iVar7 + sVar3));
          if ((iVar2 == 1) &&
             ((*(byte *)(**(int **)(iVar5 + iVar1) + (uint)*(byte *)(iVar7 + sVar3) + 1) & 7) != 0))
          goto LAB_00014940;
        }
        pcVar4 = strchr(param_1,0x40);
        if (pcVar4 == (char *)0x0) {
          return 1;
        }
      }
LAB_00014940:
      iVar6 = iVar6 + 1;
      pcVar9 = pcVar9 + 6;
    } while (iVar6 != 0xe);
  }
  return 0;
}



/* Function: FUN_00014960 @ 00014960 */

undefined4 FUN_00014960(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (iVar1 = FUN_000148ac(param_1), iVar1 != 0)) {
    iVar1 = 0;
    iVar3 = DAT_00014998 + 0x149c6;
    do {
      iVar2 = FUN_000162dc(param_1,iVar3 + iVar1 * 5);
      if (iVar2 != 0) {
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 6);
  }
  return 0;
}



/* Function: FUN_0001499c @ 0001499c */

void FUN_0001499c(void)

{
  qsort((void *)(DAT_000149b0 + 0x149a8),DAT_000149b8,4,(__compar_fn_t)(DAT_000149b4 + 0x149aa));
  return;
}



/* Function: FUN_000149bc @ 000149bc */

uint FUN_000149bc(undefined1 *param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  iVar1 = DAT_00014a10;
  if (param_1 != (undefined1 *)0x0) {
    pcVar3 = &UNK_00014a3e + DAT_00014a10;
    if (*pcVar3 == '\0') {
      FUN_0001499c();
      *(undefined4 *)(&UNK_00014a42 + iVar1) = DAT_00014a14;
      *pcVar3 = '\x01';
    }
    iVar1 = FUN_00016298(*param_1);
    if (iVar1 == 3) {
      uVar2 = FUN_000165c8(DAT_00014a1c + 0x149fa,4,param_1,3,0,
                           *(int *)(DAT_00014a18 + 0x14a6e) + -1);
      return ~uVar2 >> 0x1f;
    }
  }
  return 0;
}



/* Function: FUN_00014a20 @ 00014a20 */

void FUN_00014a20(void *param_1,void *param_2)

{
  memcmp(param_1,param_2,3);
  return;
}



/* Function: FUN_00014a60 @ 00014a60 */

void FUN_00014a60(void)

{
  int iVar1;
  void *__ptr;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = DAT_00014ab4;
  piVar4 = (int *)(DAT_00014ab4 + 0x14a68);
  if (*piVar4 != 0) {
    iVar5 = 0;
    for (iVar6 = 0; iVar6 < *(int *)(iVar1 + 0x14a6c); iVar6 = iVar6 + 1) {
      __ptr = *(void **)(*piVar4 + iVar5 + 0x18);
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
      iVar5 = iVar5 + 0x1c;
    }
    free((void *)*piVar4);
    *piVar4 = 0;
  }
  iVar1 = DAT_00014ab8;
  *(undefined4 *)(DAT_00014ab8 + 0x14aa6) = 0;
  *(undefined4 *)(iVar1 + 0x14aa2) = 0;
  puVar2 = (undefined4 *)(iVar1 + 0x14aaa);
  puVar3 = (undefined4 *)(iVar1 + 0x14ac6);
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while (puVar2 != (undefined4 *)(iVar1 + 0x14ac6));
  return;
}



/* Function: FUN_00014abc @ 00014abc */

void FUN_00014abc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  char *__format;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int local_30;
  int local_28;
  int local_24;
  
  iVar11 = DAT_00014c1c;
  printf((char *)(DAT_00014c20 + 0x14acc),*(undefined4 *)(DAT_00014c1c + 0x14ad0));
  printf((char *)(DAT_00014c24 + 0x14ad8),*(undefined4 *)(iVar11 + 0x14acc));
  puVar12 = (undefined4 *)(iVar11 + 0x14ad4);
  puVar8 = (undefined4 *)(iVar11 + 0x14af0);
  pcVar6 = (char *)(DAT_00014c28 + 0x14ae8);
  iVar11 = 0;
  do {
    uVar4 = *puVar12;
    puVar12 = puVar12 + 1;
    uVar5 = *puVar8;
    puVar8 = puVar8 + 1;
    iVar10 = iVar11 + 1;
    printf(pcVar6,iVar11,uVar4,uVar5);
    iVar1 = DAT_00014c2c;
    iVar11 = iVar10;
  } while (iVar10 != 7);
  local_30 = 0;
  piVar9 = (int *)(DAT_00014c2c + 0x14b06);
  piVar7 = (int *)(DAT_00014c30 + 0x14b08);
  for (local_24 = 0; local_24 < *(int *)(iVar1 + 0x14b0a); local_24 = local_24 + 1) {
    iVar11 = DAT_00014c34 + 0x14b16;
    printf((char *)(DAT_00014c38 + 0x14b1e),iVar11,DAT_00014c3c + 0x14b1a,*piVar9 + local_30);
    pcVar6 = (char *)(DAT_00014c40 + 0x14b2c);
    printf(pcVar6,iVar11,DAT_00014c44 + 0x14b30,(uint)*(byte *)(*piVar9 + local_30 + 0x14));
    printf(pcVar6,iVar11,DAT_00014c48 + 0x14b46,(uint)*(ushort *)(*piVar9 + local_30 + 0x16));
    putchar(10);
    iVar11 = DAT_00014c50;
    iVar10 = 0;
    pcVar6 = (char *)(DAT_00014c4c + 0x14b5c);
    for (local_28 = 0; iVar2 = DAT_00014c58,
        local_28 < (int)(uint)*(ushort *)(*piVar7 + local_30 + 0x16); local_28 = local_28 + 1) {
      iVar3 = iVar11 + 0x14b6e;
      printf(pcVar6,iVar3,DAT_00014c54 + 0x14b74,*(int *)(*piVar7 + local_30 + 0x18) + iVar10);
      __format = (char *)(iVar2 + 0x14b84);
      printf(__format,iVar3,DAT_00014c5c + 0x14b8a,
             (uint)*(byte *)(*(int *)(*piVar7 + local_30 + 0x18) + iVar10 + 10));
      printf((char *)(DAT_00014c60 + 0x14bb0),iVar3,DAT_00014c64 + 0x14ba4,
             (int)*(char *)(*(int *)(*piVar7 + local_30 + 0x18) + iVar10 + 0xb));
      printf(__format,iVar3,DAT_00014c68 + 0x14bc2,
             (uint)*(byte *)(*(int *)(*piVar7 + local_30 + 0x18) + iVar10 + 0xc));
      printf(__format,iVar3,DAT_00014c6c + 0x14bda,
             *(undefined4 *)(*(int *)(*piVar7 + local_30 + 0x18) + iVar10 + 0x10));
      iVar10 = iVar10 + 0x14;
    }
    putchar(10);
    local_30 = local_30 + 0x1c;
  }
  return;
}



/* Function: FUN_00014c70 @ 00014c70 */

/* WARNING: Type propagation algorithm not settling */

int FUN_00014c70(char *param_1,char *param_2,char *param_3)

{
  ushort uVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  char *__needle;
  int iVar7;
  char *__haystack;
  int iVar8;
  int local_30;
  size_t local_20 [3];
  
  iVar7 = DAT_00014e78;
  iVar5 = 1;
  if ((param_1 != (char *)0x0) && (iVar5 = 2, param_2 != (char *)0x0)) {
    piVar6 = (int *)(DAT_00014e78 + 0x14c8e);
    if (*piVar6 == 0) {
      iVar5 = 3;
    }
    else {
      if (0 < *(int *)(DAT_00014e78 + 0x14c92)) {
        local_20[1] = 0;
        sVar2 = strlen(param_1);
        if ((int)sVar2 < 3) {
          return 1;
        }
        iVar5 = FUN_00014264(param_1,sVar2);
        if (iVar5 == 1) {
          return 2;
        }
        if ((*param_1 != '1') || (iVar5 = FUN_00014170(param_1,sVar2), iVar5 == 1)) {
          return 3;
        }
        iVar5 = FUN_000164e0(*piVar6,0x1c,param_1,*(int *)(iVar7 + 0x14cae),
                             *(int *)(iVar7 + 0x14cae) + *(int *)(iVar7 + 0x14cca) + -1);
        if ((iVar5 < 0) || (*(int *)(iVar7 + 0x14c96) <= iVar5)) {
          iVar8 = 0;
          iVar7 = 0;
        }
        else {
          iVar8 = 1;
          iVar5 = *(int *)(*(int *)(DAT_00014e7c + 0x14cec) + iVar5 * 0x1c + 0x18);
          iVar7 = (int)*(char *)(iVar5 + 0xb);
          FUN_00012170(*(undefined1 *)(iVar5 + 10),1,iVar7,iVar7,*(undefined1 *)(iVar5 + 0xc),6,
                       *(undefined4 *)(iVar5 + 0x10),local_20 + 1,param_3);
          if ((byte)(*param_3 - 1U) < 2) {
            return 0;
          }
        }
        iVar5 = DAT_00014e80;
        piVar6 = (int *)(DAT_00014e80 + 0x14d36);
        iVar3 = FUN_0001639c(*piVar6,0x1c,param_1,*(int *)(DAT_00014e80 + 0x14d5a),
                             *(int *)(DAT_00014e80 + 0x14d5a) + *(int *)(DAT_00014e80 + 0x14d76) +
                             -1,1);
        if ((-1 < iVar3) && (iVar3 < *(int *)(iVar5 + 0x14d3a))) {
          iVar8 = iVar8 + 1;
          iVar5 = *(int *)(*piVar6 + iVar3 * 0x1c + 0x18);
          iVar7 = iVar7 + *(char *)(iVar5 + 0xb);
          FUN_00012170(*(undefined1 *)(iVar5 + 10),iVar8,(int)*(char *)(iVar5 + 0xb),iVar7,
                       *(undefined1 *)(iVar5 + 0xc),6,*(undefined4 *)(iVar5 + 0x10),local_20 + 1,
                       param_3);
          if ((byte)(*param_3 - 1U) < 2) {
            return 0;
          }
        }
        iVar5 = DAT_00014e84;
        piVar6 = (int *)(DAT_00014e84 + 0x14d9c);
        if (0 < *(int *)(DAT_00014e84 + 0x14dd4)) {
          local_20[0] = strlen(param_2);
          iVar3 = DAT_00014e88 + 0x14db0;
          FUN_00015ae8(param_2,local_20[0],iVar3,local_20,DAT_00014e8c);
          FUN_00013838(iVar3,local_20[0]);
          if (0x13 < (int)local_20[0]) {
            __haystack = (char *)(DAT_00014e90 + 0x14dda);
            iVar5 = *piVar6 + *(int *)(iVar5 + 0x14db8) * 0x1c;
            __needle = *(char **)(iVar5 + 0x18);
            uVar1 = *(ushort *)(iVar5 + 0x16);
            for (local_30 = 1; local_30 != uVar1 + 1; local_30 = local_30 + 1) {
              if ((*__needle != '\0') &&
                 (pcVar4 = strstr(__haystack,__needle), pcVar4 != (char *)0x0)) {
                iVar7 = iVar7 + __needle[0xb];
                iVar8 = iVar8 + 1;
                FUN_00012170(__needle[10],iVar8,(int)__needle[0xb],iVar7,__needle[0xc],6,
                             *(undefined4 *)(__needle + 0x10),local_20 + 1,param_3);
                if ((byte)(*param_3 - 1U) < 2) {
                  return 0;
                }
              }
              __needle = __needle + 0x14;
            }
          }
        }
        if (iVar8 != 0) {
          return 0;
        }
        return 4;
      }
      iVar5 = 4;
    }
  }
  return -iVar5;
}



/* Function: FUN_00014eb0 @ 00014eb0 */

int FUN_00014eb0(int param_1,char *param_2,undefined4 *param_3)

{
  ushort uVar1;
  bool bVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *__s2;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  
  iVar7 = DAT_00015020;
  iVar6 = 1;
  if ((param_1 != 0) && (iVar6 = 2, param_2 != (char *)0x0)) {
    iVar6 = 3;
    piVar8 = (int *)(DAT_00015020 + 0x14ece);
    iVar9 = *piVar8;
    if (iVar9 != 0) {
      if (0 < *(int *)(DAT_00015020 + 0x14ed2)) {
        sVar3 = strlen(param_2);
        if (9 < (int)sVar3) {
          return 3;
        }
        iVar6 = strcmp(param_2,(char *)(DAT_00015024 + 0x14ef4));
        if (iVar6 == 0) {
          return 4;
        }
        iVar6 = FUN_000164e0(iVar9,0x1c,param_1,*(int *)(iVar7 + 0x14ede),
                             *(int *)(iVar7 + 0x14ede) + *(int *)(iVar7 + 0x14efa) + -1);
        if ((iVar6 < 0) || (*(int *)(iVar7 + 0x14ed2) <= iVar6)) {
          bVar2 = false;
        }
        else {
          iVar7 = *piVar8 + iVar6 * 0x1c;
          uVar1 = *(ushort *)(iVar7 + 0x16);
          __s2 = *(char **)(iVar7 + 0x18);
          for (iVar6 = 0; iVar6 < (int)(uint)uVar1; iVar6 = iVar6 + 1) {
            if (*__s2 == '\0') {
              uVar4 = *(undefined4 *)(__s2 + 4);
              uVar5 = *(undefined4 *)(__s2 + 8);
              *param_3 = *(undefined4 *)__s2;
              param_3[1] = uVar4;
              param_3[2] = uVar5;
              uVar4 = *(undefined4 *)(__s2 + 0x10);
              param_3[3] = *(undefined4 *)(__s2 + 0xc);
              param_3[4] = uVar4;
              return 0;
            }
            iVar7 = strcasecmp(param_2,__s2);
            if (iVar7 == 0) goto LAB_00015008;
            __s2 = __s2 + 0x14;
          }
          bVar2 = true;
        }
        iVar7 = DAT_00015028;
        piVar8 = (int *)(DAT_00015028 + 0x14f68);
        iVar9 = FUN_000164e0(*piVar8,0x1c,param_1,*(int *)(DAT_00015028 + 0x14f7c),
                             *(int *)(DAT_00015028 + 0x14f7c) + *(int *)(DAT_00015028 + 0x14f98) +
                             -1);
        iVar6 = DAT_0001502c;
        if ((iVar9 < 0) || (*(int *)(iVar7 + 0x14f6c) <= iVar9)) {
          if (!bVar2) {
            piVar8 = (int *)(DAT_0001502c + 0x14fdc);
            iVar7 = FUN_0001639c(*piVar8,0x1c,param_1,*(int *)(DAT_0001502c + 0x14ff4),
                                 *(int *)(DAT_0001502c + 0x14ff4) + *(int *)(DAT_0001502c + 0x15010)
                                 + -1,1);
            if ((iVar7 < 0) || (*(int *)(iVar6 + 0x14fe0) <= iVar7)) {
              return 2;
            }
            __s2 = *(char **)(*piVar8 + iVar7 * 0x1c + 0x18);
LAB_00015008:
            uVar4 = *(undefined4 *)(__s2 + 4);
            uVar5 = *(undefined4 *)(__s2 + 8);
            *param_3 = *(undefined4 *)__s2;
            param_3[1] = uVar4;
            param_3[2] = uVar5;
            uVar4 = *(undefined4 *)(__s2 + 0x10);
            param_3[3] = *(undefined4 *)(__s2 + 0xc);
            param_3[4] = uVar4;
            return 0;
          }
        }
        else {
          iVar7 = *piVar8 + iVar9 * 0x1c;
          uVar1 = *(ushort *)(iVar7 + 0x16);
          __s2 = *(char **)(iVar7 + 0x18);
          for (iVar6 = 0; iVar6 < (int)(uint)uVar1; iVar6 = iVar6 + 1) {
            if (*__s2 == '\0') {
              uVar4 = *(undefined4 *)(__s2 + 4);
              uVar5 = *(undefined4 *)(__s2 + 8);
              *param_3 = *(undefined4 *)__s2;
              param_3[1] = uVar4;
              param_3[2] = uVar5;
              uVar4 = *(undefined4 *)(__s2 + 0x10);
              param_3[3] = *(undefined4 *)(__s2 + 0xc);
              param_3[4] = uVar4;
              return 0;
            }
            sVar3 = strlen(__s2);
            iVar7 = strncasecmp(param_2,__s2,sVar3);
            if (iVar7 == 0) goto LAB_00015008;
            __s2 = __s2 + 0x14;
          }
        }
        return 1;
      }
      iVar6 = 4;
    }
  }
  return -iVar6;
}



/* Function: FUN_00015030 @ 00015030 */

int FUN_00015030(undefined4 param_1,undefined4 param_2,size_t param_3,undefined4 param_4,
                undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  void *pvVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int *piVar13;
  char *__s;
  int iVar14;
  char *__dest;
  int iVar15;
  char *__s_00;
  size_t local_44;
  int local_40;
  char *local_1c [2];
  
  local_1c[0] = (char *)0x0;
  iVar2 = FUN_00011db4(param_5,local_1c,param_1,param_2,param_3,0x28,param_4);
  __s_00 = local_1c[0];
  if (iVar2 < 1) {
    iVar7 = 1;
  }
  else {
    iVar11 = 1;
    if ((local_1c[0] != (char *)0x0) && (iVar11 = 2, 0 < (int)param_3)) {
      if (*(int *)(DAT_0001525c + 0x15076) != 0) {
        FUN_00014a60();
      }
      iVar11 = DAT_00015260;
      puVar12 = (undefined4 *)(DAT_00015260 + 0x15088);
      *(undefined4 *)(DAT_00015260 + 0x1508c) = 0;
      *(undefined4 *)(iVar11 + 0x15090) = 0;
      pvVar5 = calloc(param_3,0x1c);
      *puVar12 = pvVar5;
      iVar7 = DAT_00015264;
      iVar11 = 3;
      if (pvVar5 != (void *)0x0) {
        local_40 = 0;
        local_44 = 0;
        piVar13 = (int *)(DAT_00015264 + 0x150a6);
        while (sVar3 = strlen(__s_00), sVar3 - 1 < 0x13) {
          iVar11 = local_44 * 0x1c;
          strncpy((char *)(*piVar13 + iVar11),__s_00,sVar3);
          iVar14 = *piVar13 + iVar11;
          *(undefined1 *)(iVar14 + sVar3) = 0;
          bVar1 = __s_00[0x14];
          *(byte *)(iVar14 + 0x14) = bVar1;
          uVar9 = (uint)*(ushort *)(__s_00 + 0x15);
          *(ushort *)(iVar14 + 0x16) = *(ushort *)(__s_00 + 0x15);
          if (6 < bVar1) {
LAB_000151a4:
            iVar11 = 0;
            if (local_40 == iVar2) goto LAB_000151b2;
            iVar11 = 8;
            goto LAB_000151b0;
          }
          if (uVar9 == 0) {
            iVar11 = 5;
            goto LAB_000151b0;
          }
          *(int *)(iVar7 + 0x150aa) = *(int *)(iVar7 + 0x150aa) + 1;
          iVar14 = uVar9 * 0x11 + 0x17;
          local_40 = iVar14 + local_40;
          if (iVar2 < local_40) {
            iVar11 = 6;
            goto LAB_000151b0;
          }
          pcVar4 = calloc(uVar9,0x14);
          if (pcVar4 == (char *)0x0) {
            iVar11 = 7;
            goto LAB_000151b0;
          }
          *(uint *)(iVar7 + 0x150ae) = uVar9 + *(int *)(iVar7 + 0x150ae);
          __dest = pcVar4;
          for (__s = __s_00 + 0x17; __s != __s_00 + iVar14; __s = __s + 0x11) {
            __dest[10] = __s[10];
            __dest[0xb] = __s[0xb];
            __dest[0xc] = __s[0xc];
            *(undefined4 *)(__dest + 0x10) = *(undefined4 *)(__s + 0xd);
            sVar3 = strlen(__s);
            if (sVar3 == 0) {
              *__dest = '\0';
            }
            else {
              strncpy(__dest,__s,9);
              __dest[9] = '\0';
            }
            __dest = __dest + 0x14;
          }
          *(char **)(*(int *)(DAT_00015268 + 0x1518c) + iVar11 + 0x18) = pcVar4;
          local_44 = local_44 + 1;
          if (local_44 == param_3) goto LAB_000151a4;
          __s_00 = __s_00 + 0x17 + uVar9 * 0x11;
        }
        iVar11 = 4;
      }
    }
LAB_000151b0:
    iVar11 = -iVar11;
LAB_000151b2:
    if (local_1c[0] != (char *)0x0) {
      free(local_1c[0]);
    }
    iVar2 = DAT_0001526c;
    iVar7 = 2;
    if (iVar11 == 0) {
      piVar13 = (int *)(DAT_0001526c + 0x151c8);
      pvVar5 = (void *)*piVar13;
      if ((pvVar5 != (void *)0x0) && (0 < (int)*(size_t *)(DAT_0001526c + 0x151cc))) {
        qsort(pvVar5,*(size_t *)(DAT_0001526c + 0x151cc),0x1c,
              (__compar_fn_t)(DAT_00015270 + 0x151da));
        iVar7 = DAT_00015278;
        iVar11 = DAT_00015274;
        iVar15 = *(int *)(iVar2 + 0x151cc);
        iVar14 = *piVar13;
        uVar9 = 1;
        iVar2 = 0;
LAB_00015242:
        pbVar6 = (byte *)(iVar14 + iVar2 * 0x1c + 0x14);
        for (; iVar10 = iVar2, iVar2 < iVar15; iVar2 = iVar2 + 1) {
          uVar8 = (uint)*pbVar6;
          pbVar6 = pbVar6 + 0x1c;
          if ((int)uVar9 <= (int)uVar8) {
            if (uVar8 == uVar9) {
              *(int *)(iVar7 + uVar9 * 4 + 0x151fa) = iVar2;
              pbVar6 = (byte *)(iVar14 + (iVar2 + 1) * 0x1c + 0x14);
              goto LAB_00015218;
            }
            break;
          }
        }
        goto LAB_00015238;
      }
      iVar7 = 3;
    }
  }
  return -iVar7;
  while (bVar1 = *pbVar6, pbVar6 = pbVar6 + 0x1c, bVar1 == uVar8) {
LAB_00015218:
    iVar10 = iVar10 + 1;
    if (iVar10 == iVar15) break;
  }
  *(int *)(uVar8 * 4 + iVar11 + 0x15210) = iVar10 - iVar2;
LAB_00015238:
  uVar9 = uVar9 + 1;
  iVar2 = iVar10;
  if (uVar9 == 7) {
    return 0;
  }
  goto LAB_00015242;
}



/* Function: FUN_0001527c @ 0001527c */

void FUN_0001527c(int param_1,int param_2,int param_3,undefined1 param_4,undefined1 *param_5)

{
  undefined1 uVar1;
  
  if (param_2 == 0) {
    *param_5 = 1;
    uVar1 = 2;
  }
  else {
    if (param_2 != 1) {
      if (param_2 != 2) {
        return;
      }
      if (param_3 < 0x65) {
        if (param_3 < -100) {
          param_3 = -100;
        }
      }
      else {
        param_3 = 100;
      }
      *param_5 = 3;
      param_5[4] = 4;
      param_5[3] = (char)param_3;
      if (param_3 < param_1) {
        return;
      }
      *param_5 = 2;
      param_5[4] = 6;
      return;
    }
    *param_5 = 2;
    uVar1 = 3;
  }
  param_5[4] = uVar1;
  param_5[1] = param_4;
  return;
}



/* Function: FUN_000152cc @ 000152cc */

undefined4 FUN_000152cc(char *param_1)

{
  size_t sVar1;
  int iVar2;
  char *__src;
  
  sVar1 = strlen(param_1);
  if (*param_1 == '+') {
    iVar2 = strncmp(param_1,(char *)(DAT_000153d4 + 0x152e6),3);
    if ((iVar2 == 0) || (iVar2 = strncmp(param_1,(char *)(DAT_000153d8 + 0x152f6),3), iVar2 == 0)) {
      sVar1 = sVar1 - 3;
      __src = param_1 + 3;
      goto LAB_00015366;
    }
    iVar2 = strncmp(param_1,(char *)(DAT_000153dc + 0x1530c),4);
    if (((iVar2 != 0) && (iVar2 = strncmp(param_1,(char *)(DAT_000153e0 + 0x1531c),4), iVar2 != 0))
       && (iVar2 = strncmp(param_1,(char *)(DAT_000153e4 + 0x1532c),4), iVar2 != 0)) {
      sVar1 = sVar1 - 1;
      __src = param_1 + 1;
      goto LAB_00015366;
    }
  }
  else {
    if ((*param_1 != '0') || (param_1[1] != '0')) {
      iVar2 = strncmp(param_1,(char *)(DAT_000153fc + 0x153ba),5);
      if (iVar2 != 0) {
        return 0;
      }
      memmove(param_1,param_1 + 5,sVar1 - 5);
      param_1[sVar1 - 5] = '\0';
      return 0;
    }
    iVar2 = strncmp(param_1,(char *)(DAT_000153e8 + 0x1534c),4);
    if ((iVar2 != 0) && (iVar2 = strncmp(param_1,(char *)(DAT_000153ec + 0x1535c),4), iVar2 != 0)) {
      iVar2 = strncmp(param_1,(char *)(DAT_000153f0 + 0x1537e),5);
      if ((iVar2 == 0) ||
         ((iVar2 = strncmp(param_1,(char *)(DAT_000153f4 + 0x1538e),5), iVar2 == 0 ||
          (iVar2 = strncmp(param_1,(char *)(DAT_000153f8 + 0x1539e),5), iVar2 == 0)))) {
        sVar1 = sVar1 - 5;
        __src = param_1 + 5;
      }
      else {
        sVar1 = sVar1 - 2;
        __src = param_1 + 2;
      }
      goto LAB_00015366;
    }
  }
  sVar1 = sVar1 - 4;
  __src = param_1 + 4;
LAB_00015366:
  memmove(param_1,__src,sVar1);
  param_1[sVar1] = '\0';
  return 0;
}



/* Function: FUN_0001543c @ 0001543c */

int FUN_0001543c(int param_1)

{
  int iVar1;
  
  if (((param_1 < 0) || (*(int *)(DAT_0001545c + 0x15442) == 0)) ||
     (*(int *)(DAT_0001545c + 0x15446) <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(DAT_0001545c + 0x15442) + param_1 * 0x10;
  }
  return iVar1;
}



/* Function: FUN_00015460 @ 00015460 */

int * FUN_00015460(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((-1 < param_1) && (*(int **)(DAT_00015490 + 0x15468) != (int *)0x0)) {
    piVar2 = *(int **)(DAT_00015490 + 0x15468);
    for (iVar1 = 0; iVar1 < *(int *)(DAT_00015490 + 0x1546c); iVar1 = iVar1 + 1) {
      if (*piVar2 == param_1) {
        return piVar2;
      }
      piVar2 = piVar2 + 4;
    }
  }
  return (int *)0x0;
}



/* Function: FUN_000154a0 @ 000154a0 */

void FUN_000154a0(void)

{
  int iVar1;
  void *__ptr;
  int *piVar2;
  int iVar3;
  
  iVar1 = DAT_000154dc;
  iVar3 = 0;
  piVar2 = (int *)(DAT_000154dc + 0x154aa);
  if (*piVar2 != 0) {
    for (; iVar3 < *(int *)(iVar1 + 0x154ae); iVar3 = iVar3 + 1) {
      __ptr = *(void **)(*piVar2 + iVar3 * 0x10 + 8);
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
    }
    free((void *)*piVar2);
    *piVar2 = 0;
  }
  *(undefined4 *)((int)&DAT_000154dc + DAT_000154e0 + 2) = 0;
  return;
}



/* Function: FUN_000154e4 @ 000154e4 */

void FUN_000154e4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar2 = DAT_000155d4;
  iVar1 = DAT_000155cc;
  piVar7 = (int *)(DAT_000155cc + 0x154f0);
  printf((char *)(DAT_000155d0 + 0x154f6),*(undefined4 *)(DAT_000155cc + 0x154f4));
  for (local_24 = 0; local_24 < *(int *)(iVar1 + 0x154f4); local_24 = local_24 + 1) {
    iVar5 = local_24 * 0x10;
    iVar8 = DAT_000155dc + 0x15514;
    pcVar9 = (char *)(DAT_000155d8 + 0x15516);
    printf(pcVar9,iVar8,DAT_000155e0 + 0x1551a,*(undefined4 *)(*piVar7 + iVar5));
    printf(pcVar9,iVar8,DAT_000155e4 + 0x1552e,*(undefined4 *)(*piVar7 + iVar5 + 4));
    printf(pcVar9,iVar8,DAT_000155e8 + 0x15542,(uint)*(byte *)(*piVar7 + iVar5 + 0xc));
    printf((char *)(DAT_000155ec + 0x15560),iVar8,DAT_000155f0 + 0x1555e,
           (int)*(char *)(*piVar7 + iVar5 + 0xd));
    iVar3 = DAT_000155f8;
    printf(pcVar9,iVar8,DAT_000155f4 + 0x15574,(uint)*(byte *)(*piVar7 + iVar5 + 0xe));
    iVar8 = 0;
    putchar(10);
    for (local_20 = 0; iVar6 = *(int *)(iVar2 + 0x15500) + iVar5, local_20 < *(int *)(iVar6 + 4);
        local_20 = local_20 + 1) {
      pcVar9 = (char *)(*(int *)(iVar6 + 8) + iVar8);
      sVar4 = strlen(pcVar9);
      printf((char *)(iVar3 + 0x15584),sVar4,pcVar9);
      iVar8 = iVar8 + 0x14;
    }
    putchar(10);
  }
  return;
}



/* Function: FUN_000155fc @ 000155fc */

int FUN_000155fc(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__needle;
  
  iVar3 = 1;
  if (-1 < param_2) {
    if ((*(int *)(DAT_00015664 + 0x1560e) == 0) ||
       (iVar3 = *(int *)(DAT_00015664 + 0x15612), iVar3 == 0)) {
      iVar3 = 2;
    }
    else {
      iVar4 = *(int *)(DAT_00015664 + 0x1560e) + param_2 * 0x10;
      for (; param_2 < iVar3; param_2 = param_2 + 1) {
        iVar2 = *(int *)(iVar4 + 4);
        if (iVar2 != 0) {
          __needle = *(char **)(iVar4 + 8);
          for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
            pcVar1 = strstr(param_1,__needle);
            __needle = __needle + 0x14;
            if (pcVar1 == (char *)0x0) break;
          }
          if (iVar5 == iVar2) {
            return param_2;
          }
        }
        iVar4 = iVar4 + 0x10;
      }
      iVar3 = 3;
    }
  }
  return -iVar3;
}



/* Function: FUN_00015668 @ 00015668 */

/* WARNING: Type propagation algorithm not settling */

void FUN_00015668(int param_1,int param_2,size_t param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  void *pvVar4;
  uint __n;
  char *__s;
  undefined4 *puVar5;
  size_t sVar6;
  int iVar7;
  char *local_a8;
  void *local_a0;
  undefined4 *local_94;
  undefined4 *local_90;
  undefined4 *local_8c;
  int local_88;
  undefined4 *local_78;
  undefined4 *local_74;
  size_t local_70;
  char acStack_6c [80];
  int local_1c;
  
  iVar1 = 1;
  local_1c = **(int **)(DAT_000158bc + 0x15678);
  if (param_1 < 0x69) goto LAB_0001587a;
  if (((int)param_3 < 1) || (param_2 <= param_1)) {
    iVar1 = 2;
    goto LAB_0001587a;
  }
  sVar6 = param_2 - param_1;
  local_70 = sVar6;
  local_8c = malloc(sVar6);
  if (local_8c == (undefined4 *)0x0) {
    iVar1 = 3;
    goto LAB_0001587a;
  }
  puVar2 = (undefined4 *)FUN_00011d74(param_5,local_8c,&local_70,param_1);
  if ((puVar2 != (undefined4 *)0x0) || (local_70 != sVar6)) {
    free(local_8c);
    iVar1 = 4;
    goto LAB_0001587a;
  }
  puVar5 = (undefined4 *)(param_3 * 10);
  if (param_4 == 1) {
    local_78 = puVar2;
    local_74 = puVar2;
    iVar1 = FUN_000136b8(local_8c,local_70,&local_78,&local_74);
    if (iVar1 != 0) {
      free(local_8c);
      iVar1 = 5;
      goto LAB_0001587a;
    }
    local_90 = local_74;
    if ((int)local_74 <= (int)puVar5) {
      free(local_78);
      free(local_8c);
      iVar1 = 6;
      goto LAB_0001587a;
    }
    free(local_8c);
    local_8c = local_78;
  }
  else {
    local_90 = puVar5;
    if ((int)local_70 <= (int)puVar5) {
      free(local_8c);
      iVar1 = 7;
      goto LAB_0001587a;
    }
  }
  if (*(int *)(DAT_000158c0 + 0x1572c) != 0) {
    FUN_000154a0();
  }
  puVar2 = calloc(param_3,0x10);
  *(undefined4 **)(DAT_000158c4 + 0x15742) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    local_94 = (undefined4 *)0x0;
    local_88 = 0;
    puVar5 = local_8c;
    do {
      *puVar2 = *puVar5;
      *(undefined1 *)(puVar2 + 3) = *(undefined1 *)(puVar5 + 1);
      *(undefined1 *)((int)puVar2 + 0xd) = *(undefined1 *)((int)puVar5 + 5);
      *(undefined1 *)((int)puVar2 + 0xe) = *(undefined1 *)((int)puVar5 + 6);
      __n = (uint)*(ushort *)((int)puVar5 + 7);
      if ((0x4e < __n - 1) ||
         (local_94 = (undefined4 *)((int)local_94 + __n + 9), (int)local_90 < (int)local_94))
      goto LAB_00015862;
      strncpy(acStack_6c,(char *)((int)puVar5 + 9),__n);
      acStack_6c[__n] = '\0';
      sVar6 = strlen(acStack_6c);
      local_a0 = (void *)0x0;
      iVar7 = 0;
      iVar1 = 0;
      while (iVar7 < (int)sVar6) {
        __s = acStack_6c + iVar7;
        pcVar3 = strchr(__s,0x26);
        local_a8 = (char *)(sVar6 - iVar7);
        if (pcVar3 != (char *)0x0) {
          local_a8 = pcVar3 + (-iVar7 - (int)acStack_6c);
        }
        if ((int)local_a8 < 1) {
          iVar7 = iVar7 + 1;
        }
        else {
          pvVar4 = realloc(local_a0,(iVar1 + 1) * 0x14);
          if (pvVar4 == (void *)0x0) {
            iVar1 = 0;
            if (local_a0 != (void *)0x0) {
              free(local_a0);
            }
            goto LAB_00015842;
          }
          if (0x13 < (int)local_a8) {
            local_a8 = (char *)0x13;
          }
          pcVar3 = (char *)((int)pvVar4 + iVar1 * 0x14);
          strncpy(pcVar3,__s,(size_t)local_a8);
          pcVar3[(int)local_a8] = '\0';
          iVar7 = iVar7 + 1 + (int)local_a8;
          iVar1 = iVar1 + 1;
          local_a0 = pvVar4;
        }
      }
      puVar2[2] = local_a0;
LAB_00015842:
      puVar2[1] = iVar1;
      iVar7 = DAT_000158d4;
      puVar2 = puVar2 + 4;
      local_88 = local_88 + 1;
      if ((int)param_3 <= local_88) goto LAB_0001585a;
      puVar5 = (undefined4 *)((int)puVar5 + __n + 9);
    } while( true );
  }
  goto LAB_00015872;
LAB_0001585a:
  if (local_94 == local_90) {
    puVar2 = (undefined4 *)(DAT_000158d4 + 0x158a6);
    *(size_t *)(DAT_000158d4 + 0x158aa) = param_3;
    free(local_8c);
    iVar1 = 0;
    if (1 < (int)*(size_t *)(iVar7 + 0x158aa)) {
      qsort((void *)*puVar2,*(size_t *)(iVar7 + 0x158aa),0x10,
            (__compar_fn_t)(DAT_000158cc + 0x15888));
      iVar1 = 0;
    }
    goto LAB_0001588c;
  }
LAB_00015862:
  iVar1 = DAT_000158c8;
  puVar2 = (undefined4 *)(DAT_000158c8 + 0x15868);
  free((void *)*puVar2);
  *puVar2 = 0;
  *(undefined4 *)(iVar1 + 0x1586c) = 0;
LAB_00015872:
  free(local_8c);
  iVar1 = 8;
LAB_0001587a:
  iVar1 = -iVar1;
LAB_0001588c:
  if (local_1c == **(int **)(DAT_000158d0 + 0x15894)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar1);
}



/* Function: FUN_000158d8 @ 000158d8 */

int FUN_000158d8(byte *param_1,byte *param_2,int *param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  int *piVar4;
  byte bVar5;
  int iVar6;
  
  if ((param_4 < 3) || (*param_3 != 3)) {
    if (*param_3 == 1) {
      *param_2 = (byte)*(undefined2 *)((*param_1 + 1) * 2 + **(int **)(DAT_00015970 + 0x1594e));
      goto LAB_00015966;
    }
  }
  else if (*param_1 == 0xef) {
    pbVar1 = param_1 + 1;
    pbVar3 = param_1 + 2;
    bVar2 = param_1[2];
    param_1 = pbVar3;
    if (*pbVar1 == 0xbd) {
      bVar5 = bVar2 - 0x20;
      if ((byte)(bVar2 + 0x7f) < 0x1a) {
LAB_00015938:
        *param_2 = bVar5;
        return 1;
      }
    }
    else if ((*pbVar1 == 0xbc) && (((byte)(bVar2 + 0x5f) < 0x1a || ((byte)(bVar2 + 0x70) < 10)))) {
      piVar4 = *(int **)(DAT_0001596c + 0x1592c);
      *param_2 = bVar2 + 0xa0;
      bVar5 = (byte)*(undefined2 *)(((byte)(bVar2 + 0xa0) + 1) * 2 + *piVar4);
      goto LAB_00015938;
    }
  }
  for (iVar6 = 0; iVar6 < *param_3; iVar6 = iVar6 + 1) {
    param_2[iVar6] = param_1[iVar6];
  }
LAB_00015966:
  return *param_3;
}



/* Function: FUN_00015974 @ 00015974 */

undefined4 FUN_00015974(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  size_t __n;
  undefined4 uVar2;
  byte *__src;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DAT_000159f8;
  iVar4 = DAT_000159f4 + 0x15980;
  if (((param_3 == 0) || (param_1 == 0)) || (*param_4 < param_2)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar5 = 0;
    iVar3 = 0;
    while (iVar3 < param_2) {
      __src = (byte *)(param_1 + iVar3);
      __n = FUN_00016298(*__src);
      if ((__n == 1) && ((*(byte *)(**(int **)(iVar4 + iVar1) + (uint)*__src + 1) & 7) != 0)) {
        iVar3 = iVar3 + 1;
      }
      else {
        memcpy((void *)(param_3 + iVar5),__src,__n);
        iVar3 = iVar3 + __n;
        iVar5 = iVar5 + __n;
      }
    }
    *param_4 = iVar5;
    uVar2 = 0;
    *(undefined1 *)(param_3 + iVar5) = 0;
  }
  return uVar2;
}



/* Function: FUN_000159fc @ 000159fc */

undefined4 FUN_000159fc(int param_1,int param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  size_t sVar2;
  uint uVar3;
  char *__s;
  undefined1 *__src;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_1c;
  
  if (((param_3 == 0) || (param_1 == 0)) || (*param_4 < param_2)) {
    return 0xffffffff;
  }
  iVar4 = 0;
  iVar5 = 0;
  iVar6 = DAT_00015ab4 + 0x15a26;
  do {
    while( true ) {
      if (param_2 <= iVar5) {
        *param_4 = iVar4;
        *(undefined1 *)(param_3 + iVar4) = 0;
        return 0;
      }
      __src = (undefined1 *)(param_1 + iVar5);
      sVar2 = FUN_00016298(*__src);
      if (sVar2 == 3) break;
LAB_00015a88:
      memcpy((void *)(param_3 + iVar4),__src,sVar2);
      iVar5 = iVar5 + sVar2;
      iVar4 = iVar4 + sVar2;
    }
    local_1c = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
    local_1c._0_1_ = *__src;
    uVar1 = local_1c;
    local_1c._0_1_ = (undefined1)uVar1;
    local_1c._3_1_ = SUB41(uVar1,3);
    local_1c._0_3_ = CONCAT12(__src[2],CONCAT11(__src[1],(undefined1)local_1c));
    uVar3 = FUN_00016564(iVar6,8,local_1c,0,0x53);
    if (0x53 < uVar3) goto LAB_00015a88;
    __s = (char *)(iVar6 + uVar3 * 8 + 4);
    sVar2 = strlen(__s);
    memcpy((void *)(param_3 + iVar4),__s,sVar2);
    iVar5 = iVar5 + 3;
    iVar4 = iVar4 + sVar2;
  } while( true );
}



/* Function: FUN_00015ab8 @ 00015ab8 */

uint FUN_00015ab8(void *param_1,size_t param_2)

{
  uint uVar1;
  undefined4 local_c [2];
  
  local_c[0] = 0;
  memcpy(local_c,param_1,param_2);
  uVar1 = FUN_00016264(DAT_00015ae4 + 0x15af6,local_c[0],0,0xd8);
  return uVar1 >> 0x1f;
}



/* Function: FUN_00015ae8 @ 00015ae8 */

undefined4 FUN_00015ae8(byte *param_1,int param_2,byte *param_3,int *param_4,uint param_5)

{
  short sVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  size_t sVar8;
  uint uVar9;
  byte *__s1;
  bool bVar10;
  int local_38;
  int local_1c [2];
  
  iVar7 = DAT_00015dc0 + 0x15af4;
  if (((param_3 == (byte *)0x0) || (param_1 == (byte *)0x0)) || (*param_4 < param_2)) {
    return 0xffffffff;
  }
  pbVar3 = param_1 + param_2;
  *param_4 = 0;
  local_38 = 0;
  iVar5 = DAT_00015dc4 + 0x15b24;
LAB_00015e04:
  do {
    __s1 = param_1;
    bVar6 = *__s1;
    uVar9 = (uint)bVar6;
    if ((uVar9 == 0) || (pbVar3 <= __s1)) {
LAB_00015e12:
      *param_3 = 0;
      *param_4 = local_38;
      return 0;
    }
    if ((param_5 & 0x204) != 0) {
      sVar1 = *(short *)((uVar9 + 1) * 2 + **(int **)(iVar7 + DAT_00015dc8));
      if (sVar1 == 0x68) {
        iVar2 = strncasecmp((char *)__s1,(char *)(DAT_00015dcc + 0x15b4e),7);
        if (iVar2 == 0) {
          param_1 = __s1 + 7;
          while (((param_1 < pbVar3 && (*param_1 != 0)) &&
                 (*(char *)(DAT_00015dd0 + 0x15b5e + (uint)*param_1) != '\0'))) {
            param_1 = param_1 + 1;
          }
LAB_00015ba4:
          if ((int)(param_5 << 0x1d) < 0) {
            sVar8 = (int)param_1 - (int)__s1;
            memcpy(param_3,__s1,sVar8);
LAB_00015ce2:
            local_38 = local_38 + sVar8;
            param_3 = param_3 + sVar8;
          }
          goto LAB_00015e04;
        }
      }
      else if (sVar1 == 0x77) {
        iVar2 = strncasecmp((char *)__s1,(char *)(DAT_00015dd4 + 0x15b80),4);
        if (iVar2 == 0) {
          param_1 = __s1 + 4;
          while (((param_1 < pbVar3 && (*param_1 != 0)) &&
                 (*(char *)(DAT_00015dd8 + 0x15b90 + (uint)*param_1) != '\0'))) {
            param_1 = param_1 + 1;
          }
          goto LAB_00015ba4;
        }
      }
      else {
        if (sVar1 != 0x66) goto LAB_00015c0c;
        iVar2 = strncasecmp((char *)__s1,(char *)(DAT_00015ddc + 0x15bce),6);
        if (iVar2 == 0) {
          param_1 = __s1 + 6;
          while (((param_1 < pbVar3 && (*param_1 != 0)) &&
                 (*(char *)(iVar5 + (uint)*param_1) != '\0'))) {
            param_1 = param_1 + 1;
          }
          if ((int)(param_5 << 0x1d) < 0) {
            sVar8 = (int)param_1 - (int)__s1;
            memcpy(param_3,__s1,sVar8);
            param_3 = param_3 + sVar8;
            local_38 = local_38 + sVar8;
          }
          goto LAB_00015e04;
        }
      }
LAB_00015de4:
      if (uVar9 < 0x100) {
        bVar6 = (byte)*(undefined2 *)((uVar9 + 1) * 2 + **(int **)(iVar7 + DAT_00015e34));
      }
      *param_3 = bVar6;
      param_1 = __s1 + 1;
LAB_00015dfc:
      param_3 = param_3 + 1;
      local_38 = local_38 + 1;
      goto LAB_00015e04;
    }
LAB_00015c0c:
    if (-1 < (int)(param_5 << 0x17)) goto LAB_00015de4;
    if ((param_5 & 1) != 0) {
      if ((uVar9 == 0 || (int)(uVar9 * 0x1000000) < 0) ||
         ((uVar9 != 0xffffffff &&
          ((*(byte *)(**(int **)(iVar7 + DAT_00015de0) + uVar9 + 1) & 7) != 0)))) {
        if (-1 < (int)(param_5 << 0x15)) goto LAB_00015de4;
        local_1c[0] = FUN_00016298(uVar9);
        param_1 = __s1 + local_1c[0];
        if (__s1 + local_1c[0] <= pbVar3) {
          if ((local_1c[0] < 5) && (local_1c[0] != 1)) {
            iVar2 = FUN_00015ab8(__s1,local_1c[0]);
            if (iVar2 == 1) {
              if (((int)pbVar3 - (int)__s1 < 2) || (local_1c[0] != 2)) {
LAB_00015e28:
                sVar8 = FUN_000158d8(__s1,param_3,local_1c);
              }
              else {
                bVar6 = *__s1;
                bVar4 = __s1[1];
                if (bVar6 == 0xd0) {
                  if (0x2f < (byte)(bVar4 + 0x70)) goto LAB_00015e28;
                }
                else if (bVar6 == 0xd1) {
                  if (0xf < (bVar4 ^ 0x80)) goto LAB_00015e28;
                }
                else if (bVar6 == 0xce) {
                  if (0x2e < (byte)(bVar4 + 0x6f)) goto LAB_00015e28;
                }
                else if ((bVar6 != 0xc3) || (0x1e < (bVar4 ^ 0x80))) goto LAB_00015e28;
                sVar8 = 0;
              }
              param_1 = __s1 + local_1c[0];
              goto LAB_00015ce2;
            }
            param_1 = __s1 + local_1c[0];
          }
          else {
            iVar2 = FUN_000158d8(__s1,param_3,local_1c,(int)pbVar3 - (int)__s1);
            param_3 = param_3 + iVar2;
            local_38 = local_38 + iVar2;
            param_1 = __s1 + local_1c[0];
          }
        }
      }
      else {
LAB_00015dba:
        param_1 = __s1 + 1;
      }
      goto LAB_00015e04;
    }
    if (0x7d < (uVar9 + 0x7f & 0xff)) {
      if ((uVar9 == 0xffffffff) ||
         ((*(byte *)(**(int **)(iVar7 + DAT_00015de0) + uVar9 + 1) & 7) == 0)) goto LAB_00015dba;
      goto LAB_00015de4;
    }
    bVar4 = __s1[1];
    if (bVar4 == 0) goto LAB_00015e12;
    param_1 = __s1 + 2;
    if (uVar9 == 0xa3) {
      bVar10 = (byte)(bVar4 + 0x3f) < 0x1a;
      if ((byte)(bVar4 + 0x1f) < 0x1a) {
        if (bVar10) goto LAB_00015d2c;
        bVar4 = bVar4 + 0x60;
      }
      else {
        if (!bVar10) {
          if (9 < (byte)(bVar4 + 0x50)) goto LAB_00015d58;
          *param_3 = bVar4 + 0x80;
          param_3 = param_3 + 1;
          local_38 = local_38 + 1;
          goto LAB_00015e04;
        }
LAB_00015d2c:
        bVar4 = bVar4 ^ 0x80;
      }
      *param_3 = bVar4;
      goto LAB_00015dfc;
    }
LAB_00015d58:
    if (((((bVar4 ^ 0x80) < 0x7f) || ((byte)(bVar4 - 0x40) < 0x3f)) &&
        ((8 < (uVar9 + 0x5f & 0xff) || (0x5d < (byte)(bVar4 + 0x5f))))) &&
       ((1 < (uVar9 + 0x58 & 0xff) || ((0x20 < (bVar4 ^ 0x80) && (0x3e < (byte)(bVar4 - 0x40)))))))
    {
      *param_3 = bVar6;
      param_3[1] = bVar4;
      param_3 = param_3 + 2;
      local_38 = local_38 + 2;
    }
  } while( true );
}



/* Function: FUN_00015e38 @ 00015e38 */

void FUN_00015e38(void)

{
  undefined2 uVar1;
  int iVar2;
  void *__base;
  undefined2 *puVar3;
  undefined2 *puVar4;
  int iVar5;
  __compar_fn_t __compar;
  int iVar6;
  
  iVar2 = DAT_00015e8c;
  if (*(int *)(DAT_00015e8c + 0x15e44) == 0) {
    iVar6 = DAT_00015e8c + 0x15e48;
    __base = (void *)(DAT_00015e90 + 0x15e6e);
    iVar5 = 0;
    do {
      puVar3 = (undefined2 *)(iVar6 + iVar5 * 6);
      uVar1 = puVar3[1];
      puVar4 = (undefined2 *)((int)__base + iVar5 * 4);
      iVar5 = iVar5 + 1;
      *puVar4 = *puVar3;
      puVar4[1] = uVar1;
    } while (iVar5 != 0xd9);
    __compar = *(__compar_fn_t *)(DAT_00015e94 + 0x15e72);
    qsort(__base,0xd9,4,__compar);
    qsort((void *)(DAT_00015e98 + 0x15e82),0x54,8,__compar);
    *(undefined4 *)(iVar2 + 0x15e44) = 1;
  }
  return;
}



/* Function: FUN_00015e9c @ 00015e9c */

int FUN_00015e9c(int param_1)

{
  int iVar1;
  
  if (((param_1 < 0) || (*(int *)(DAT_00015ec0 + 0x15ea2) == 0)) ||
     (*(int *)(DAT_00015ec0 + 0x15ea6) <= param_1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(DAT_00015ec0 + 0x15ea2) + param_1 * 0x1c;
  }
  return iVar1;
}



/* Function: FUN_00015ec4 @ 00015ec4 */

int FUN_00015ec4(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((-1 < param_1) && (*(int *)(DAT_00015ef4 + 0x15ecc) != 0)) {
    iVar2 = *(int *)(DAT_00015ef4 + 0x15ecc);
    for (iVar1 = 0; iVar1 < *(int *)(DAT_00015ef4 + 0x15ed0); iVar1 = iVar1 + 1) {
      if (*(int *)(iVar2 + 0x18) == param_1) {
        return iVar2;
      }
      iVar2 = iVar2 + 0x1c;
    }
  }
  return 0;
}



/* Function: FUN_00015f04 @ 00015f04 */

void FUN_00015f04(void)

{
  int iVar1;
  void *__ptr;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(DAT_00015f24 + 0x15f0c);
  __ptr = (void *)*puVar2;
  if (__ptr != (void *)0x0) {
    free(__ptr);
    *puVar2 = 0;
  }
  iVar1 = DAT_00015f28;
  *(undefined4 *)((int)&DAT_00015f24 + DAT_00015f28) = 0;
  *(undefined4 *)((int)&DAT_00015f28 + iVar1) = 0;
  return;
}



/* Function: FUN_00015f2c @ 00015f2c */

void FUN_00015f2c(void)

{
  int iVar1;
  int iVar2;
  char *__format;
  int *piVar3;
  char *__format_00;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  
  iVar1 = DAT_00015fe0;
  piVar3 = (int *)(DAT_00015fe0 + 0x15f38);
  printf((char *)(DAT_00015fe4 + 0x15f3a),*(undefined4 *)(DAT_00015fe0 + 0x15f3c));
  iVar2 = DAT_00015fec;
  iVar4 = 0;
  __format = (char *)(DAT_00015fe8 + 0x15f48);
  for (local_24 = 0; local_24 < *(int *)(iVar1 + 0x15f3c); local_24 = local_24 + 1) {
    iVar5 = iVar2 + 0x15f58;
    printf(__format,iVar5,DAT_00015ff0 + 0x15f5c,*piVar3 + iVar4);
    __format_00 = (char *)(DAT_00015ff4 + 0x15f6c);
    printf(__format_00,iVar5,DAT_00015ff8 + 0x15f70,(uint)*(byte *)(*piVar3 + iVar4 + 0x14));
    printf((char *)(DAT_00015ffc + 0x15f8e),iVar5,DAT_00016000 + 0x15f8a,
           (int)*(char *)(*piVar3 + iVar4 + 0x15));
    printf(__format_00,iVar5,DAT_00016004 + 0x15f9c,(uint)*(byte *)(*piVar3 + iVar4 + 0x16));
    printf(__format_00,iVar5,DAT_00016008 + 0x15fae,*(undefined4 *)(*piVar3 + iVar4 + 0x18));
    printf(__format_00,iVar5,DAT_0001600c + 0x15fc0,(uint)*(byte *)(*piVar3 + iVar4 + 0x17));
    putchar(10);
    iVar4 = iVar4 + 0x1c;
  }
  return;
}



/* Function: FUN_00016010 @ 00016010 */

int FUN_00016010(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = DAT_0001605c;
  piVar3 = (int *)(DAT_0001605c + 0x1601c);
  iVar1 = *piVar3;
  if (iVar1 == 0) {
    iVar2 = 1;
  }
  else {
    if (param_1 != 0) {
      iVar1 = FUN_000164e0(iVar1,0x1c,param_1,*(undefined4 *)(DAT_0001605c + 0x16028),
                           *(int *)(DAT_0001605c + 0x16020) + -1);
      if (-1 < iVar1) {
        return iVar1;
      }
      iVar2 = FUN_0001639c(*piVar3,0x1c,param_1,0,*(int *)(iVar2 + 0x16028) + -1,
                           *(undefined4 *)(iVar2 + 0x16024));
      return iVar2;
    }
    iVar2 = 2;
  }
  return -iVar2;
}



/* Function: FUN_00016060 @ 00016060 */

int FUN_00016060(int param_1,int param_2,size_t param_3,int param_4,undefined4 param_5)

{
  char *pcVar1;
  void *pvVar2;
  char *__dest;
  size_t sVar3;
  int iVar4;
  uint __n;
  int *piVar5;
  char *__size;
  int iVar6;
  size_t local_40;
  char *local_3c;
  char *local_34;
  char *local_24;
  char *local_20;
  char *local_1c [2];
  
  if (*(int *)(DAT_00016204 + 0x16070) != 0) {
    FUN_00015f04();
  }
  if ((param_1 < 0x69) || ((int)param_3 < 1)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 2;
    if (param_1 < param_2) {
      __size = (char *)(param_2 - param_1);
      local_1c[0] = __size;
      local_3c = malloc((size_t)__size);
      if (local_3c == (char *)0x0) {
        iVar4 = 3;
      }
      else {
        pcVar1 = (char *)FUN_00011d74(param_5,local_3c,local_1c,param_1);
        if (pcVar1 == (char *)0x0) {
          if (param_4 == 1) {
            local_24 = pcVar1;
            local_20 = pcVar1;
            iVar4 = FUN_000136b8(local_3c,local_1c[0],&local_24,&local_20);
            __size = local_20;
            if (iVar4 != 0) {
              free(local_3c);
              iVar4 = 5;
              goto LAB_000161f6;
            }
            if ((int)local_20 <= (int)(param_3 * 0xb)) {
              free(local_24);
              free(local_3c);
              iVar4 = 6;
              goto LAB_000161f6;
            }
            free(local_3c);
            local_3c = local_24;
          }
          if (local_3c != (char *)0x0) {
            pvVar2 = calloc(param_3,0x1c);
            iVar4 = DAT_00016208;
            piVar5 = (int *)(DAT_00016208 + 0x1610e);
            *piVar5 = (int)pvVar2;
            if (pvVar2 != (void *)0x0) {
              local_34 = (char *)0x0;
              local_40 = 0;
              pcVar1 = local_3c;
              while( true ) {
                __dest = (char *)(*piVar5 + local_40 * 0x1c);
                __dest[0x14] = *pcVar1;
                __dest[0x15] = pcVar1[1];
                __dest[0x16] = pcVar1[2];
                __dest[0x17] = pcVar1[3];
                *(undefined4 *)(__dest + 0x18) = *(undefined4 *)(pcVar1 + 4);
                __n = (uint)*(ushort *)(pcVar1 + 8);
                if (0x12 < __n - 1) break;
                local_34 = local_34 + __n + 10;
                if ((int)__size < (int)local_34) break;
                strncpy(__dest,pcVar1 + 10,__n);
                pvVar2 = (void *)*piVar5;
                *(undefined1 *)((int)pvVar2 + __n + local_40 * 0x1c) = 0;
                iVar6 = DAT_0001620c;
                local_40 = local_40 + 1;
                if (local_40 == param_3) {
                  if (local_34 == __size) {
                    *(size_t *)(iVar4 + 0x16112) = param_3;
                    qsort(pvVar2,param_3,0x1c,(__compar_fn_t)(iVar6 + 0x161a4));
                    *(undefined4 *)(iVar4 + 0x16116) = 0x14;
                    local_40 = 0;
                    iVar6 = 0;
                    goto LAB_000161c0;
                  }
                  break;
                }
                pcVar1 = pcVar1 + __n + 10;
              }
            }
          }
          free(local_3c);
          iVar4 = 7;
        }
        else {
          iVar4 = 4;
        }
      }
    }
  }
LAB_000161f6:
  return -iVar4;
  while( true ) {
    sVar3 = strlen((char *)(*piVar5 + local_40));
    iVar6 = iVar6 + 1;
    if ((int)sVar3 < *(int *)(iVar4 + 0x16116)) {
      *(size_t *)(iVar4 + 0x16116) = sVar3;
    }
    local_40 = local_40 + 0x1c;
    if ((int)param_3 <= iVar6) break;
LAB_000161c0:
    if (((char *)(*piVar5 + local_40))[0x17] != '\0') break;
  }
  *(int *)(DAT_00016210 + 0x161f8) = iVar6;
  free(local_3c);
  return 0;
}



/* Function: FUN_00016214 @ 00016214 */

void FUN_00016214(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_00015f04();
  FUN_00016060(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* Function: FUN_00016238 @ 00016238 */

int FUN_00016238(char *param_1,char *param_2)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = param_1[0x17];
  if (bVar1 == 0) {
    if (param_2[0x17] == '\0') goto LAB_0001625c;
  }
  else if (param_2[0x17] != '\0') goto LAB_0001625c;
  if ((byte)param_2[0x17] < bVar1) {
    return 1;
  }
  if (bVar1 != param_2[0x17]) {
    return -1;
  }
LAB_0001625c:
  iVar2 = strcmp(param_1,param_2);
  return iVar2;
}



/* Function: FUN_00016264 @ 00016264 */

int FUN_00016264(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 1;
  if (param_1 != 0) {
    while (param_3 <= param_4) {
      iVar1 = (param_4 + param_3) / 2;
      uVar2 = *(uint *)(iVar1 * 4 + param_1);
      if (uVar2 == param_2) {
        return iVar1;
      }
      if (uVar2 < param_2) {
        param_3 = iVar1 + 1;
      }
      else {
        param_4 = iVar1 + -1;
      }
    }
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_00016298 @ 00016298 */

char FUN_00016298(uint param_1)

{
  char cVar1;
  
  cVar1 = '\x06';
  if ((((param_1 < 0xfc) && (cVar1 = '\x05', 3 < (param_1 + 8 & 0xff))) &&
      (cVar1 = '\x04', 7 < (param_1 + 0x10 & 0xff))) &&
     (cVar1 = '\x03', 0xf < (param_1 + 0x20 & 0xff))) {
    cVar1 = ((param_1 + 0x40 & 0xff) < 0x20) + '\x01';
  }
  return cVar1;
}



/* Function: FUN_000162dc @ 000162dc */

byte * FUN_000162dc(byte *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_2 == (byte *)0x0) || (param_1 == (byte *)0x0)) {
    return (byte *)0x0;
  }
LAB_0001633a:
  if (*param_1 == 0) {
    return (byte *)0x0;
  }
  pbVar3 = param_2;
  if (*param_2 == 0) {
    return (byte *)0x0;
  }
  do {
    uVar4 = (uint)*param_1;
    uVar1 = (uint)*pbVar3;
    if (uVar4 != uVar1) {
      uVar5 = uVar1;
      if ((uVar1 - 0x61 & 0xff) < 0x1a) {
        uVar5 = uVar1 - 0x20;
      }
      if (uVar4 != uVar5) {
        if ((uVar1 - 0x41 & 0xff) < 0x1a) {
          uVar1 = uVar1 + 0x20;
        }
        if (uVar4 != uVar1) break;
      }
    }
    if (pbVar3[1] == 0) {
      return param_1 + ((int)param_2 - (int)pbVar3);
    }
    param_1 = param_1 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      return (byte *)0x0;
    }
  } while( true );
  iVar2 = (int)pbVar3 - (int)param_2;
  param_2 = pbVar3 + -iVar2;
  param_1 = param_1 + (1 - iVar2);
  goto LAB_0001633a;
}



/* Function: FUN_00016350 @ 00016350 */

char * FUN_00016350(char *param_1)

{
  size_t sVar1;
  int iVar2;
  
  if (((param_1 == (char *)0x0) || (sVar1 = strlen(param_1), (int)sVar1 < 6)) || (*param_1 != '0'))
  {
    param_1 = (char *)0x0;
  }
  else {
    iVar2 = strncmp(param_1,(char *)(DAT_00016394 + 0x16370),3);
    if (iVar2 != 0) {
      iVar2 = strncmp(param_1,(char *)(DAT_00016398 + 0x16380),2);
      if (iVar2 != 0) {
        return param_1 + 4;
      }
    }
    param_1 = param_1 + 3;
  }
  return param_1;
}



/* Function: FUN_0001639c @ 0001639c */

int FUN_0001639c(int param_1,int param_2,char *param_3,int param_4,int param_5)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  if ((param_3 == (char *)0x0) || (param_1 == 0)) {
    iVar3 = 1;
  }
  else {
    pcVar4 = (char *)(param_1 + param_4 * param_2);
    for (; param_4 <= param_5; param_4 = param_4 + 1) {
      sVar1 = strlen(pcVar4);
      iVar3 = strncmp(pcVar4,param_3,sVar1);
      if (iVar3 == 0) {
        pcVar4 = (char *)(param_1 + (param_4 + 1) * param_2);
        iVar3 = param_4;
        while( true ) {
          param_4 = param_4 + 1;
          if (param_5 < param_4) {
            return iVar3;
          }
          sVar1 = strlen(pcVar4);
          iVar2 = strncmp(pcVar4,param_3,sVar1);
          iVar5 = param_4;
          if ((iVar2 != 0) && (iVar5 = iVar3, 0 < iVar2)) break;
          pcVar4 = pcVar4 + param_2;
          iVar3 = iVar5;
        }
        return iVar3;
      }
      pcVar4 = pcVar4 + param_2;
      if (-1 < iVar3) {
        iVar3 = 2;
        goto LAB_000163e4;
      }
    }
    iVar3 = 3;
  }
LAB_000163e4:
  return -iVar3;
}



/* Function: FUN_00016420 @ 00016420 */

void FUN_00016420(int param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  char *__format;
  char *__s;
  
  if (param_4 <= param_2 * 2) {
    param_2 = param_4 / 2 + -1;
  }
  __format = (char *)(DAT_00016470 + 0x16442);
  __s = param_3;
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    sprintf(__s,__format,(uint)*(byte *)(param_1 + iVar1));
    __s = __s + 2;
  }
  if (iVar1 < 1) {
    *param_3 = '\0';
  }
  else {
    param_3[iVar1 * 2] = '\0';
  }
  return;
}



/* Function: FUN_000164e0 @ 000164e0 */

int FUN_000164e0(int param_1,int param_2,char *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if (param_1 != 0) {
    while (param_4 <= param_5) {
      iVar2 = (param_4 + param_5) / 2;
      iVar1 = strcmp((char *)(param_1 + iVar2 * param_2),param_3);
      if (iVar1 == 0) {
        return iVar2;
      }
      if (iVar1 < 0) {
        param_4 = iVar2 + 1;
      }
      else {
        param_5 = iVar2 + -1;
      }
    }
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_0001652c @ 0001652c */

int FUN_0001652c(void *param_1,void *param_2)

{
  int iVar1;
  uint local_10;
  uint local_c;
  
  local_c = 0;
  local_10 = 0;
  memcpy(&local_c,param_1,4);
  memcpy(&local_10,param_2,4);
  iVar1 = 1;
  if (local_c <= local_10) {
    iVar1 = (local_c == local_10) - 1;
  }
  return iVar1;
}



/* Function: FUN_00016564 @ 00016564 */

int FUN_00016564(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  uint local_1c [2];
  
  if ((param_2 < 4) || (param_1 == 0)) {
    iVar1 = 1;
  }
  else {
    local_1c[0] = 0;
    while (param_4 <= param_5) {
      iVar1 = (param_5 + param_4) / 2;
      memcpy(local_1c,(void *)(param_1 + iVar1 * param_2),4);
      if (local_1c[0] == param_3) {
        return iVar1;
      }
      if (local_1c[0] < param_3) {
        param_4 = iVar1 + 1;
      }
      else {
        param_5 = iVar1 + -1;
      }
    }
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_000165c8 @ 000165c8 */

int FUN_000165c8(int param_1,int param_2,void *param_3,size_t param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if (param_1 != 0) {
    while (param_5 <= param_6) {
      iVar2 = (param_6 + param_5) / 2;
      iVar1 = memcmp((void *)(param_1 + iVar2 * param_2),param_3,param_4);
      if (iVar1 == 0) {
        return iVar2;
      }
      if (iVar1 < 0) {
        param_5 = iVar2 + 1;
      }
      else {
        param_6 = iVar2 + -1;
      }
    }
    iVar1 = 2;
  }
  return -iVar1;
}



/* Function: FUN_00016618 @ 00016618 */

bool FUN_00016618(time_t param_1,time_t param_2)

{
  bool bVar1;
  time_t local_70;
  time_t local_6c;
  tm tStack_68;
  tm tStack_3c;
  
  local_70 = param_2;
  local_6c = param_1;
  localtime_r(&local_6c,&tStack_3c);
  localtime_r(&local_70,&tStack_68);
  if (((tStack_3c.tm_year == tStack_68.tm_year) && (tStack_3c.tm_mon == tStack_68.tm_mon)) &&
     (tStack_3c.tm_mday == tStack_68.tm_mday)) {
    bVar1 = tStack_3c.tm_hour == tStack_68.tm_hour;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}



/* Function: FUN_00016660 @ 00016660 */

bool FUN_00016660(time_t param_1,int param_2,int param_3)

{
  time_t local_44 [2];
  tm tStack_3c;
  
  local_44[0] = param_1;
  localtime_r(local_44,&tStack_3c);
  return tStack_3c.tm_hour == param_3 && tStack_3c.tm_mday == param_2;
}



/* Function: FUN_00016688 @ 00016688 */

void FUN_00016688(undefined1 *param_1,undefined1 *param_2)

{
  *param_2 = param_1[3];
  param_2[1] = param_1[2];
  param_2[2] = param_1[1];
  param_2[3] = *param_1;
  return;
}



/* Function: FUN_0001669c @ 0001669c */

void FUN_0001669c(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)((uint)param_1 >> 0x18);
  param_2[1] = (char)((uint)param_1 >> 0x10);
  param_2[2] = (char)((uint)param_1 >> 8);
  param_2[3] = (char)param_1;
  return;
}



/* Function: FUN_000166ac @ 000166ac */

void FUN_000166ac(uint *param_1)

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
        uVar5 = DAT_0001670c;
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



/* Function: FUN_0001673c @ 0001673c */

void FUN_0001673c(int param_1,int *param_2,int param_3)

{
  int iVar1;
  uint local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  FUN_00016688(param_1,local_1c);
  FUN_00016688(param_1 + 4,&local_20);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + DAT_000167b0;
    local_1c[0] = (local_20 * 0x10 + *param_2 ^ (local_20 >> 5) + param_2[1] ^ iVar1 + local_20) +
                  local_1c[0];
    local_20 = (param_2[3] + (local_1c[0] >> 5) ^ local_1c[0] * 0x10 + param_2[2] ^
               local_1c[0] + iVar1) + local_20;
  } while (iVar1 != DAT_000167ac);
  FUN_0001669c(local_1c[0],param_3);
  FUN_0001669c(local_20,param_3 + 4);
  return;
}



/* Function: FUN_000167b4 @ 000167b4 */

void FUN_000167b4(int param_1,int *param_2,int param_3)

{
  int iVar1;
  uint local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  FUN_00016688(param_1,local_1c);
  FUN_00016688(param_1 + 4,&local_20);
  iVar1 = DAT_00016820;
  do {
    local_20 = local_20 -
               (local_1c[0] * 0x10 + param_2[2] ^ (local_1c[0] >> 5) + param_2[3] ^
               iVar1 + local_1c[0]);
    local_1c[0] = local_1c[0] -
                  ((local_20 >> 5) + param_2[1] ^ local_20 * 0x10 + *param_2 ^ local_20 + iVar1);
    iVar1 = iVar1 + DAT_00016824;
  } while (iVar1 != 0);
  FUN_0001669c(local_1c[0],param_3);
  FUN_0001669c(local_20,param_3 + 4);
  return;
}



/* Function: FUN_00016830 @ 00016830 */

void FUN_00016830(undefined4 *param_1)

{
  *param_1 = DAT_0001684c;
  param_1[1] = DAT_00016850;
  param_1[2] = DAT_00016854;
  param_1[3] = DAT_00016858;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  return;
}



/* Function: FUN_0001685c @ 0001685c */

void FUN_0001685c(int *param_1,uint param_2,uint *param_3)

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
      uVar9 = *(int *)((int)&DAT_00016abc + uVar6 * 4 + DAT_00016ac0) +
              local_58[*(char *)(DAT_00016ac0 + 0x16a7c + uVar6)] + uVar8 +
              ((uVar3 ^ uVar1) & uVar4 ^ uVar3);
      uVar10 = uVar6 & 3;
      uVar6 = uVar6 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_00016aa4 + 0x168ea + uVar10) & 0x1f;
      uVar10 = (uVar9 >> uVar10 | uVar9 << 0x20 - uVar10) + uVar4;
      uVar9 = uVar1;
      uVar8 = uVar3;
    } while (uVar6 != 0x10);
    uVar9 = 0;
    do {
      uVar8 = uVar10;
      uVar6 = uVar1;
      uVar1 = uVar4;
      uVar10 = *(int *)(DAT_00016aa8 + uVar9 * 4 + 0x16984) +
               local_58[*(char *)(DAT_00016aa8 + uVar9 + 0x16914)] + uVar3 +
               ((uVar1 ^ uVar8) & uVar6 ^ uVar1);
      uVar4 = uVar9 & 3;
      uVar9 = uVar9 + 1;
      uVar4 = 0x20U - (int)*(char *)(DAT_00016aac + uVar4 + 0x16954) & 0x1f;
      uVar10 = (uVar10 >> uVar4 | uVar10 << 0x20 - uVar4) + uVar8;
      uVar4 = uVar8;
      uVar3 = uVar6;
    } while (uVar9 != 0x10);
    uVar4 = 0;
    do {
      uVar3 = uVar8;
      uVar8 = uVar10;
      uVar9 = uVar1;
      uVar6 = *(int *)(DAT_00016ab0 + uVar4 * 4 + 0x16a3c) +
              local_58[*(char *)(DAT_00016ab0 + uVar4 + 0x1699c)] + uVar6 + (uVar3 ^ uVar8 ^ uVar9);
      uVar10 = uVar4 & 3;
      uVar4 = uVar4 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_00016ab4 + uVar10 + 0x169d4) & 0x1f;
      uVar10 = (uVar6 >> uVar10 | uVar6 << 0x20 - uVar10) + uVar8;
      uVar1 = uVar3;
      uVar6 = uVar9;
    } while (uVar4 != 0x10);
    uVar4 = 0;
    do {
      uVar1 = uVar3;
      uVar6 = uVar10;
      uVar3 = uVar8;
      uVar9 = *(int *)((int)&DAT_00016ae8 + DAT_00016ab8 + uVar4 * 4 + 2) +
              local_58[*(char *)(DAT_00016ab8 + uVar4 + 0x16a1a)] + uVar9 +
              ((~uVar1 | uVar6) ^ uVar3);
      uVar10 = uVar4 & 3;
      uVar4 = uVar4 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_00016abc + uVar10 + 0x16a46) & 0x1f;
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



/* Function: FUN_00016ac4 @ 00016ac4 */

void FUN_00016ac4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00016ae8;
  param_1[5] = 0;
  *param_1 = uVar1;
  uVar1 = DAT_00016aec;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[1] = uVar1;
  uVar1 = DAT_00016af0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[2] = uVar1;
  param_1[3] = DAT_00016af4;
  param_1[4] = DAT_00016af8;
  return;
}



/* Function: FUN_00016afc @ 00016afc */

void FUN_00016afc(uint *param_1)

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
    uVar5 = uVar12 + DAT_00016c84 + uVar11 + (uVar10 >> 0x1b | uVar10 << 5) +
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
    uVar5 = uVar12 + DAT_00016c88 + uVar14 + (uVar6 >> 0x1b | uVar6 << 5) +
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
    uVar5 = uVar12 + DAT_00016c8c + uVar11 + (uVar13 >> 0x1b | uVar13 << 5) +
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
    uVar5 = uVar12 + DAT_00016c90 + uVar10 + (uVar6 >> 0x1b | uVar6 << 5) +
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



/* Function: FUN_00016c94 @ 00016c94 */

void FUN_00016c94(int param_1,undefined1 *param_2,int param_3)

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
        FUN_00016afc(param_1);
      }
      param_2 = param_2 + 1;
    }
  }
  return;
}



/* Function: FUN_00016ce0 @ 00016ce0 */

void FUN_00016ce0(int param_1)

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
    FUN_00016afc(param_1);
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
  FUN_00016afc(param_1);
  return;
}



/* Function: FUN_00016d80 @ 00016d80 */

void FUN_00016d80(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    FUN_00016ce0();
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



/* Function: FUN_00016dc8 @ 00016dc8 */

void FUN_00016dc8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_84 [104];
  int local_1c;
  
  piVar1 = *(int **)(DAT_00016e08 + 0x16dd4);
  local_1c = *piVar1;
  FUN_00016ac4(auStack_84);
  FUN_00016c94(auStack_84,param_1,param_2);
  FUN_00016d80(auStack_84,param_3);
  if (local_1c != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00016e0c @ 00016e0c */

void FUN_00016e0c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte local_54 [20];
  byte abStack_40 [44];
  int local_14;
  
  local_14 = **(int **)(DAT_00016e9c + 0x16e18);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_54[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x36;
    }
  }
  else {
    FUN_00016ac4();
    pbVar2 = local_54;
    FUN_00016c94(param_1,param_2,param_3);
    FUN_00016d80(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x36;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_40);
    iVar1 = 0x14;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_54[iVar1] = 0x36;
  }
  FUN_00016ac4(param_1);
  FUN_00016c94(param_1,local_54,0x40);
  if (local_14 == **(int **)(DAT_00016ea0 + 0x16e8c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00016fb0 @ 00016fb0 */

void FUN_00016fb0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00016fe0;
  param_1[8] = 0;
  *param_1 = uVar1;
  uVar1 = DAT_00016fe4;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[1] = uVar1;
  uVar1 = DAT_00016fe8;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[2] = uVar1;
  param_1[3] = DAT_00016fec;
  param_1[4] = DAT_00016ff0;
  param_1[5] = DAT_00016ff4;
  param_1[6] = DAT_00016ff8;
  param_1[7] = DAT_00016ffc;
  return;
}



/* Function: FUN_00017000 @ 00017000 */

void FUN_00017000(uint *param_1)

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
    piVar4 = (int *)(DAT_00017174 + 0x170dc + iVar16);
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



/* Function: FUN_00017178 @ 00017178 */

void FUN_00017178(int param_1,undefined1 *param_2,int param_3)

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
        if (iVar3 != 0) goto LAB_00017192;
      }
      else {
LAB_00017192:
        iVar2 = 0;
      }
      *(int *)(param_1 + 0x70) = iVar2;
      if ((iVar2 == 0) && (*(int *)(param_1 + 0x28) == 0x40)) {
        FUN_00017000(param_1);
      }
      param_2 = param_2 + 1;
    }
  }
  return;
}



/* Function: FUN_000171d8 @ 000171d8 */

void FUN_000171d8(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_0001685c(param_1 + 7,iVar3 + 8,param_1,iVar1,param_4);
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  return;
}



/* Function: FUN_00017244 @ 00017244 */

void FUN_00017244(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint __n;
  uint uVar2;
  
  if ((param_3 & 0x3f) == 0) {
    FUN_0001685c(param_2,param_3,param_1);
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
        FUN_0001685c((void *)(param_1 + 0x1c),uVar2 & 0xffffffc0,param_1);
        memcpy((void *)(param_1 + 0x1c),(void *)(param_1 + (uVar2 & 0xffffffc0) + 0x1c),uVar2 & 0x3f
              );
        *(uint *)(param_1 + 0x18) = uVar2 & 0x3f;
      }
      param_2 = (void *)((int)param_2 + __n);
      param_3 = param_3 - __n;
    }
    if (0x40 < (int)param_3) {
      FUN_0001685c(param_2,param_3 & 0xffffffc0,param_1);
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



/* Function: FUN_000172f8 @ 000172f8 */

void FUN_000172f8(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  byte local_5c [16];
  byte abStack_4c [48];
  int local_1c;
  
  local_1c = **(int **)(DAT_000173a4 + 0x17306);
  FUN_000171d8(param_1,param_4);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_5c[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x5c;
    }
  }
  else {
    FUN_00016830(param_1);
    pbVar2 = local_5c;
    FUN_00017244(param_1,param_2,param_3);
    FUN_000171d8(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x5c;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_4c);
    iVar1 = 0x10;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_5c[iVar1] = 0x5c;
  }
  FUN_00016830(param_1);
  FUN_00017244(param_1,local_5c,0x40);
  FUN_00017244(param_1,param_4,0x10);
  FUN_000171d8(param_1,param_4);
  if (local_1c == **(int **)(DAT_000173a8 + 0x17394)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_0001749c @ 0001749c */

void FUN_0001749c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_b8 [156];
  int local_1c;
  
  piVar1 = *(int **)(DAT_000174dc + 0x174a8);
  local_1c = *piVar1;
  FUN_00016830(auStack_b8);
  FUN_00017244(auStack_b8,param_1,param_2);
  FUN_000171d8(auStack_b8,param_3);
  if (local_1c != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_000174e0 @ 000174e0 */

void FUN_000174e0(void *param_1,size_t param_2,uint *param_3)

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



/* Function: FUN_000178d8 @ 000178d8 */

void FUN_000178d8(void *param_1,size_t param_2,void *param_3)

{
  undefined1 auStack_b8 [156];
  int local_1c;
  
  local_1c = **(int **)(DAT_00017948 + 0x178e4);
  memset(param_3,0,0x10);
  if (((int)param_2 < 0x11) || (param_1 == (void *)0x0)) {
    if ((0 < (int)param_2) && (param_1 != (void *)0x0)) {
      memcpy(param_3,param_1,param_2);
    }
  }
  else {
    FUN_00016830(auStack_b8);
    FUN_00017244(auStack_b8,param_1,param_2);
    FUN_000171d8(auStack_b8,param_3);
  }
  if (local_1c != **(int **)(DAT_0001794c + 0x17938)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00017950 @ 00017950 */

uint FUN_00017950(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
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
    uVar8 = DAT_00017a8c;
    if ((((param_2 & 3) == 0) && (uVar8 = param_2, param_5 != (uint *)0x0)) &&
       (uVar8 = DAT_00017a8c, (int)param_2 <= param_6)) {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      uVar8 = param_2 >> 2;
      FUN_000178d8(param_3,param_4,auStack_28);
      uVar3 = uVar8 - 1;
      uVar7 = *param_5;
      if ((int)uVar3 < 1) {
        puVar4 = auStack_28 + 3;
        do {
          uVar8 = *puVar4;
          puVar4 = puVar4 + -1;
          uVar7 = uVar7 - (uVar8 ^ DAT_00017a90);
          uVar7 = (uVar7 >> 0x10 | uVar7 * 0x10000) ^ DAT_00017a9c;
        } while (puVar4 != &local_2c);
        *param_5 = uVar7;
        uVar8 = param_2;
      }
      else {
        iVar1 = FUN_0001e6f8(0x34,uVar8);
        uVar5 = (iVar1 + 6) * DAT_00017a90;
        iVar9 = uVar8 + DAT_00017a94;
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
          uVar5 = uVar5 + DAT_00017a98;
        }
      }
    }
  }
  return uVar8;
}



/* Function: FUN_00017adc @ 00017adc */

uint FUN_00017adc(uint *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
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
    if ((param_5 != (uint *)0x0) && (uVar10 = DAT_00017c18, (int)uVar8 <= param_6)) {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      for (; (int)param_2 < (int)uVar8; param_2 = param_2 + 1) {
        *(undefined1 *)((int)param_5 + param_2) = 0;
      }
      puVar4 = local_28;
      FUN_000178d8(param_3,param_4,puVar4);
      uVar8 = (param_2 >> 2) - 1;
      puVar11 = param_5 + uVar8;
      uVar9 = *puVar11;
      uVar6 = *param_5;
      uVar10 = param_2;
      if ((int)uVar8 < 1) {
        do {
          uVar8 = *puVar4;
          puVar4 = puVar4 + 1;
          uVar6 = ((uVar6 >> 0x10 | uVar6 << 0x10) ^ DAT_00017c1c) + (uVar8 ^ DAT_00017c1c);
        } while (puVar4 != &uStack_18);
        *param_5 = uVar6;
      }
      else {
        iVar1 = FUN_0001e6f8(0x34);
        uVar6 = iVar1 * DAT_00017c1c + DAT_00017c20;
        uVar7 = 0;
        while (uVar7 != uVar6) {
          uVar7 = uVar7 + DAT_00017c1c;
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



/* Function: FUN_00017c24 @ 00017c24 */

int FUN_00017c24(void *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,void *param_5,
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
      iVar2 = FUN_00017adc(param_5,sVar1,param_3,param_4,param_5,sVar1);
    }
  }
  return iVar2;
}



/* Function: FUN_00017c84 @ 00017c84 */

void FUN_00017c84(int param_1,int param_2)

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
      FUN_00017000(param_1);
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
    FUN_00017000(param_1);
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



/* Function: FUN_00017d54 @ 00017d54 */

void FUN_00017d54(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte local_54 [32];
  byte abStack_34 [32];
  int local_14;
  
  local_14 = **(int **)(DAT_00017de4 + 0x17d60);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_54[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x36;
    }
  }
  else {
    FUN_00016fb0();
    pbVar2 = local_54;
    FUN_00017178(param_1,param_2,param_3);
    FUN_00017c84(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x36;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_34);
    iVar1 = 0x20;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_54[iVar1] = 0x36;
  }
  FUN_00016fb0(param_1);
  FUN_00017178(param_1,local_54,0x40);
  if (local_14 == **(int **)(DAT_00017de8 + 0x17dd4)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00017dec @ 00017dec */

void FUN_00017dec(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  byte local_5c [32];
  byte abStack_3c [32];
  int local_1c;
  
  local_1c = **(int **)(DAT_00017e98 + 0x17dfa);
  FUN_00017c84(param_1,param_4);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_5c[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x5c;
    }
  }
  else {
    FUN_00016fb0(param_1);
    pbVar2 = local_5c;
    FUN_00017178(param_1,param_2,param_3);
    FUN_00017c84(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x5c;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_3c);
    iVar1 = 0x20;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_5c[iVar1] = 0x5c;
  }
  FUN_00016fb0(param_1);
  FUN_00017178(param_1,local_5c,0x40);
  FUN_00017178(param_1,param_4,0x20);
  FUN_00017c84(param_1,param_4);
  if (local_1c == **(int **)(DAT_00017e9c + 0x17e88)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00017ef0 @ 00017ef0 */

int FUN_00017ef0(char *param_1)

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



/* Function: FUN_00017f44 @ 00017f44 */

void FUN_00017f44(int param_1,int param_2)

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



/* Function: FUN_00018084 @ 00018084 */

int FUN_00018084(short *param_1)

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



/* Function: FUN_00018174 @ 00018174 */

int FUN_00018174(int param_1,int param_2)

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



/* Function: FUN_000182ac @ 000182ac */

undefined4 FUN_000182ac(uint *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 >> 0x1c < 6) {
                    /* WARNING: Could not emulate address calculation at 0x000182bc */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((*param_1 >> 0x1c) * 4 + DAT_000182d8 + 0x182be) +
                      DAT_000182d8 + 0x182be))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_000182dc @ 000182dc */

void FUN_000182dc(uint *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  iVar1 = FUN_000182ac();
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



/* Function: FUN_00018310 @ 00018310 */

void FUN_00018310(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_000182ac();
  for (uVar2 = *param_1 & 0xfffffff; (int)uVar2 < (int)(uVar2 + 3 & 0xfffffffc); uVar2 = uVar2 + 1)
  {
    *(undefined1 *)(iVar1 + uVar2) = 0;
  }
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001833c @ 0001833c */

int FUN_0001833c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_000182ac();
  return iVar1 + param_2;
}



/* Function: FUN_00018354 @ 00018354 */

int FUN_00018354(byte *param_1,int param_2,byte *param_3,int param_4)

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



/* Function: FUN_0001837c @ 0001837c */

int FUN_0001837c(byte *param_1,int param_2,byte *param_3,int param_4)

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



/* Function: FUN_000183c0 @ 000183c0 */

void FUN_000183c0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000182ac();
  FUN_00018354(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_00018400 @ 00018400 */

void FUN_00018400(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_4;
  uVar1 = FUN_000182ac();
  uVar2 = param_4;
  if ((int)(*param_1 & 0xfffffff) < (int)param_4) {
    uVar2 = *param_1 & 0xfffffff;
  }
  if ((int)param_3 < (int)param_4) {
    param_4 = param_3;
  }
  FUN_00018354(uVar1,uVar2,param_2,param_4,uVar3);
  return;
}



/* Function: FUN_0001842c @ 0001842c */

void FUN_0001842c(uint *param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (*param_1 & 0xfffffff) - param_2;
  iVar1 = FUN_000182ac();
  iVar2 = param_5;
  if (iVar3 < param_5) {
    iVar2 = iVar3;
  }
  if (param_4 < param_5) {
    param_5 = param_4;
  }
  FUN_00018354(iVar1 + param_2,iVar2,param_3,param_5);
  return;
}



/* Function: FUN_00018460 @ 00018460 */

void FUN_00018460(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000182ac();
  FUN_0001837c(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_0001847c @ 0001847c */

void FUN_0001847c(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_4;
  iVar1 = FUN_000182ac();
  FUN_0001837c(iVar1 + param_2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,uVar2);
  return;
}



/* Function: FUN_000184a0 @ 000184a0 */

void FUN_000184a0(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_4;
  uVar1 = FUN_000182ac();
  uVar2 = param_4;
  if ((int)(*param_1 & 0xfffffff) < (int)param_4) {
    uVar2 = *param_1 & 0xfffffff;
  }
  if ((int)param_3 < (int)param_4) {
    param_4 = param_3;
  }
  FUN_0001837c(uVar1,uVar2,param_2,param_4,uVar3);
  return;
}



/* Function: FUN_000184cc @ 000184cc */

bool FUN_000184cc(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (*param_1 & 0xfffffff) - param_3;
  bVar3 = false;
  if (0 < iVar2) {
    iVar1 = FUN_000182ac();
    iVar2 = FUN_00018354(iVar1 + iVar2,param_3,param_2,param_3);
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}



/* Function: FUN_00018524 @ 00018524 */

int FUN_00018524(uint *param_1,int param_2,int param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_000182ac();
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



/* Function: FUN_00018560 @ 00018560 */

int FUN_00018560(uint *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  iVar1 = FUN_000182ac();
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



/* Function: FUN_00018604 @ 00018604 */

uint * FUN_00018604(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  
  if ((param_3 == 0xffffffff) || ((int)(*param_2 & 0xfffffff) < (int)param_3)) {
    param_3 = *param_2 & 0xfffffff;
  }
  uVar1 = FUN_000182ac(param_2);
  *param_1 = param_3 | 0x10000000;
  param_1[1] = uVar1;
  return param_1;
}



/* Function: FUN_00018634 @ 00018634 */

uint * FUN_00018634(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_3 == 0xffffffff) || ((int)(*param_2 & 0xfffffff) < (int)param_3)) {
    param_3 = *param_2 & 0xfffffff;
  }
  iVar1 = FUN_000182ac(param_2);
  uVar2 = *param_2;
  *param_1 = param_3 | 0x10000000;
  param_1[1] = iVar1 + ((uVar2 & 0xfffffff) - param_3);
  return param_1;
}



/* Function: FUN_00018670 @ 00018670 */

int FUN_00018670(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_000182ac();
  return iVar1 + param_2;
}



/* Function: FUN_0001867c @ 0001867c */

int FUN_0001867c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_000182ac();
  return iVar1 + param_2;
}



/* Function: FUN_000186a4 @ 000186a4 */

void FUN_000186a4(uint *param_1,undefined1 param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000182ac();
  for (iVar2 = 0; iVar2 < (int)param_3; iVar2 = iVar2 + 1) {
    *(undefined1 *)(iVar1 + iVar2) = param_2;
  }
  *param_1 = param_3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_000186c8 @ 000186c8 */

void FUN_000186c8(uint *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1 & 0xfffffff;
  uVar3 = param_3 + uVar2;
  iVar1 = FUN_000182ac();
  for (; (int)uVar2 < (int)uVar3; uVar2 = uVar2 + 1) {
    *(undefined1 *)(iVar1 + uVar2) = param_2;
  }
  *param_1 = uVar3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_000186f4 @ 000186f4 */

void FUN_000186f4(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1;
  if ((uVar2 & 0xfffffff) != 0) {
    iVar1 = FUN_000182ac();
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



/* Function: FUN_00018734 @ 00018734 */

void FUN_00018734(uint *param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_1;
  if ((uVar5 & 0xfffffff) != 0) {
    iVar2 = FUN_000182ac();
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



/* Function: FUN_00018774 @ 00018774 */

void FUN_00018774(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_000182ac();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((byte)(*(char *)(iVar1 + iVar3) + 0xbfU) < 0x1a) {
      *(char *)(iVar1 + iVar3) = *(char *)(iVar1 + iVar3) + ' ';
    }
  }
  return;
}



/* Function: FUN_000187a0 @ 000187a0 */

void FUN_000187a0(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_000182ac();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((byte)(*(char *)(iVar1 + iVar3) + 0xbfU) < 0x1a) {
      *(char *)(iVar1 + iVar3) = *(char *)(iVar1 + iVar3) + -0x20;
    }
  }
  return;
}



/* Function: FUN_000187cc @ 000187cc */

void FUN_000187cc(uint *param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_000182ac();
  *(undefined1 *)(iVar1 + (uVar2 & 0xfffffff)) = param_2;
  *param_1 = (uVar2 & 0xfffffff) + 1 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00018934 @ 00018934 */

void FUN_00018934(undefined4 *param_1,undefined4 *param_2)

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



/* Function: FUN_00018964 @ 00018964 */

undefined4 FUN_00018964(uint *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 >> 0x1c < 6) {
                    /* WARNING: Could not emulate address calculation at 0x00018974 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((*param_1 >> 0x1c) * 4 + DAT_00018990 + 0x18976) +
                      DAT_00018990 + 0x18976))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_00018994 @ 00018994 */

int FUN_00018994(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00018964();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_000189a4 @ 000189a4 */

int FUN_000189a4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00018964();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_000189b4 @ 000189b4 */

int FUN_000189b4(ushort *param_1,int param_2,ushort *param_3,int param_4)

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



/* Function: FUN_000189dc @ 000189dc */

int FUN_000189dc(ushort *param_1,int param_2,ushort *param_3,int param_4)

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



/* Function: FUN_00018a20 @ 00018a20 */

void FUN_00018a20(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00018964();
  FUN_000189b4(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_00018ac4 @ 00018ac4 */

void FUN_00018ac4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00018964();
  FUN_000189dc(uVar1,*param_1 & 0xfffffff,param_2,param_3);
  return;
}



/* Function: FUN_00018ae0 @ 00018ae0 */

void FUN_00018ae0(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_4;
  iVar1 = FUN_00018964();
  FUN_000189dc(iVar1 + param_2 * 2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,uVar2);
  return;
}



/* Function: FUN_00018b60 @ 00018b60 */

int FUN_00018b60(uint *param_1,short *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = FUN_00018964();
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



/* Function: FUN_00018b90 @ 00018b90 */

int FUN_00018b90(uint *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_00018964();
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



/* Function: FUN_00018ca8 @ 00018ca8 */

uint * FUN_00018ca8(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_3 == 0xffffffff) || ((int)(*param_2 & 0xfffffff) < (int)param_3)) {
    param_3 = *param_2 & 0xfffffff;
  }
  iVar1 = FUN_00018964(param_2);
  uVar2 = *param_2;
  *param_1 = param_3 | 0x10000000;
  param_1[1] = iVar1 + ((uVar2 & 0xfffffff) - param_3) * 2;
  return param_1;
}



/* Function: FUN_00018ce4 @ 00018ce4 */

int FUN_00018ce4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00018964();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_00018cf4 @ 00018cf4 */

int FUN_00018cf4(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00018964();
  return iVar1 + param_2 * 2;
}



/* Function: FUN_00018d04 @ 00018d04 */

void FUN_00018d04(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (0 < iVar3) {
    iVar1 = FUN_00018964();
    iVar2 = 0;
    do {
      *(undefined2 *)(iVar1 + iVar2) = param_2;
      iVar2 = iVar2 + 2;
    } while (iVar2 != iVar3 * 2);
  }
  return;
}



/* Function: FUN_00018d20 @ 00018d20 */

void FUN_00018d20(uint *param_1,undefined2 param_2,uint param_3)

{
  undefined2 *puVar1;
  int iVar2;
  
  puVar1 = (undefined2 *)FUN_00018964();
  for (iVar2 = 0; iVar2 < (int)param_3; iVar2 = iVar2 + 1) {
    *puVar1 = param_2;
    puVar1 = puVar1 + 1;
  }
  *param_1 = param_3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00018d48 @ 00018d48 */

void FUN_00018d48(uint *param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_1;
  iVar1 = FUN_00018964();
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



/* Function: FUN_00018d78 @ 00018d78 */

void FUN_00018d78(uint *param_1)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  
  uVar4 = *param_1 & 0xfffffff;
  if (uVar4 != 0) {
    iVar1 = FUN_00018964();
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



/* Function: FUN_00018dbc @ 00018dbc */

void FUN_00018dbc(uint *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_1;
  if ((uVar5 & 0xfffffff) != 0) {
    iVar2 = FUN_00018964();
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



/* Function: FUN_00018e00 @ 00018e00 */

void FUN_00018e00(uint *param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  psVar1 = (short *)FUN_00018964();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((ushort)(*psVar1 - 0x41U) < 0x1a) {
      *psVar1 = *psVar1 + 0x20;
    }
    psVar1 = psVar1 + 1;
  }
  return;
}



/* Function: FUN_00018e30 @ 00018e30 */

void FUN_00018e30(uint *param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  psVar1 = (short *)FUN_00018964();
  uVar2 = *param_1;
  for (iVar3 = 0; iVar3 < (int)(uVar2 & 0xfffffff); iVar3 = iVar3 + 1) {
    if ((ushort)(*psVar1 - 0x41U) < 0x1a) {
      *psVar1 = *psVar1 + -0x20;
    }
    psVar1 = psVar1 + 1;
  }
  return;
}



/* Function: FUN_00018e60 @ 00018e60 */

void FUN_00018e60(uint *param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_00018964();
  *(undefined2 *)((uVar2 & 0xfffffff) * 2 + iVar1) = param_2;
  *param_1 = (uVar2 & 0xfffffff) + 1 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00018fcc @ 00018fcc */

void FUN_00018fcc(undefined4 *param_1,undefined4 *param_2)

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



/* Function: FUN_00018ffc @ 00018ffc */

void FUN_00018ffc(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00018964(param_2);
  (**(code **)(*param_1 + 0x28c))(param_1,uVar1,*param_2 & 0xfffffff);
  return;
}



/* Function: FUN_00019020 @ 00019020 */

undefined4 FUN_00019020(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,param_2,0);
  iVar2 = (**(code **)(*param_1 + 0x3c))(param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_00017ef0(iVar1);
    if (iVar2 < param_4) {
      FUN_00017f44(param_3,iVar1);
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



/* Function: FUN_00019090 @ 00019090 */

void FUN_00019090(uint *param_1,void *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < param_3) {
    uVar2 = param_1[1];
    uVar3 = *param_1;
    iVar1 = FUN_00018964();
    memcpy((void *)(iVar1 + (uVar3 & 0xfffffff) * 2),param_2,param_3 * 2);
    uVar3 = param_3 + (uVar3 & 0xfffffff);
    *param_1 = *param_1 & 0xf0000000 | uVar3;
    if ((int)uVar3 < (int)uVar2) {
      *(undefined2 *)(uVar3 * 2 + iVar1) = 0;
    }
  }
  return;
}



/* Function: FUN_000190d4 @ 000190d4 */

void FUN_000190d4(uint *param_1,void *param_2,uint param_3)

{
  void *__dest;
  uint uVar1;
  
  *param_1 = *param_1 & 0xf0000000;
  if (0 < (int)param_3) {
    uVar1 = param_1[1];
    __dest = (void *)FUN_00018964();
    memcpy(__dest,param_2,param_3 * 2);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar1) {
      *(undefined2 *)((int)__dest + param_3 * 2) = 0;
    }
  }
  return;
}



/* Function: FUN_00019118 @ 00019118 */

void FUN_00019118(uint *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < (int)param_3) {
    uVar2 = param_1[1];
    uVar3 = *param_1;
    iVar1 = FUN_000182ac();
    memcpy((void *)(iVar1 + (uVar3 & 0xfffffff)),param_2,param_3);
    uVar3 = param_3 + (uVar3 & 0xfffffff);
    *param_1 = *param_1 & 0xf0000000 | uVar3;
    if ((int)uVar3 < (int)uVar2) {
      *(undefined1 *)(iVar1 + uVar3) = 0;
    }
  }
  return;
}



/* Function: FUN_00019158 @ 00019158 */

void FUN_00019158(uint *param_1,void *param_2,uint param_3)

{
  void *__dest;
  uint uVar1;
  
  *param_1 = *param_1 & 0xf0000000;
  if (0 < (int)param_3) {
    uVar1 = param_1[1];
    __dest = (void *)FUN_000182ac();
    memcpy(__dest,param_2,param_3);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar1) {
      *(undefined1 *)((int)__dest + param_3) = 0;
    }
  }
  return;
}



/* Function: FUN_00019198 @ 00019198 */

void * FUN_00019198(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  *(undefined1 *)((int)param_1 + param_3) = 0;
  return param_1;
}



/* Function: FUN_000191ac @ 000191ac */

undefined4 FUN_000191ac(uint *param_1,int param_2)

{
  undefined4 uVar1;
  void *__dest;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((int)param_1[1] <= param_2) {
    uVar3 = param_2 + 2U & 0xfffffffe;
    __dest = (void *)FUN_0001e6f0(uVar3 << 1);
    uVar2 = *param_1;
    if (__dest == (void *)0x0) {
      uVar1 = 0xfffffffc;
    }
    else {
      if ((void *)param_1[2] != (void *)0x0) {
        memcpy(__dest,(void *)param_1[2],(uVar2 & 0xfffffff) << 1);
        if ((*param_1 >> 0x1c == 5) && (param_1[2] != 0)) {
          FUN_0001e6d0();
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



/* Function: FUN_00019204 @ 00019204 */

int FUN_00019204(uint *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_000191ac(param_1,(*param_1 & 0xfffffff) + 1);
  if (iVar1 == 0) {
    FUN_00018e60(param_1,param_2);
  }
  return iVar1;
}



/* Function: FUN_00019228 @ 00019228 */

int FUN_00019228(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000191ac(param_1,param_3 + (*param_1 & 0xfffffff),param_3,param_4,param_4);
    if (iVar1 == 0) {
      FUN_00019090(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00019258 @ 00019258 */

int FUN_00019258(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  *param_1 = uVar2 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000191ac(param_1,param_3,param_3,uVar2 & 0xf0000000,param_4);
    if (iVar1 == 0) {
      FUN_000190d4(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_0001928c @ 0001928c */

undefined4 FUN_0001928c(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x294))(param_1,*param_2);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffc;
  }
  else {
    uVar2 = (**(code **)(*param_1 + 0x290))(param_1,*param_2);
    uVar2 = FUN_00019258(param_3,iVar1,uVar2);
    (**(code **)(*param_1 + 0x298))(param_1,*param_2,iVar1);
  }
  return uVar2;
}



/* Function: FUN_000192e8 @ 000192e8 */

undefined4 FUN_000192e8(uint *param_1,void *param_2,uint param_3)

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
    __dest = (void *)FUN_00018964();
    memcpy(__dest,param_2,param_3 * 2);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar2) {
      *(undefined2 *)((int)__dest + param_3 * 2) = 0;
    }
  }
  else if ((uVar2 == 5) || (uVar2 == 2)) {
    uVar1 = FUN_00019258(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}



/* Function: FUN_0001934c @ 0001934c */

undefined4 * FUN_0001934c(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0x20000000;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = FUN_00018964(param_2);
  FUN_00019258(param_1,uVar1,*param_2 & 0xfffffff);
  return param_1;
}



/* Function: FUN_000193a4 @ 000193a4 */

void FUN_000193a4(uint *param_1)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_0001e6d0();
    }
  }
  param_1[2] = 0;
  *param_1 = 0x20000000;
  param_1[1] = 0;
  return;
}



/* Function: FUN_000193cc @ 000193cc */

void FUN_000193cc(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_0001e6d0();
    }
  }
  param_1[2] = param_2;
  *param_1 = param_3 | 0x20000000;
  param_1[1] = param_4;
  return;
}



/* Function: FUN_000193fc @ 000193fc */

void FUN_000193fc(uint *param_1)

{
  if (*param_1 >> 0x1c == 4) {
    if (param_1[1] != 0) {
      FUN_0001e6d0();
      param_1[1] = 0;
    }
    *param_1 = 0x10000000;
  }
  else if (*param_1 >> 0x1c == 5) {
    if (param_1[2] != 0) {
      FUN_0001e6d0();
      param_1[2] = 0;
    }
    *param_1 = 0x20000000;
    param_1[1] = 0;
  }
  return;
}



/* Function: FUN_00019440 @ 00019440 */

undefined4 FUN_00019440(undefined4 param_1)

{
  FUN_000193fc();
  return param_1;
}



/* Function: FUN_0001944c @ 0001944c */

undefined4 FUN_0001944c(undefined4 param_1)

{
  FUN_000193fc();
  return param_1;
}



/* Function: FUN_00019484 @ 00019484 */

undefined4 FUN_00019484(undefined4 param_1)

{
  FUN_000193fc();
  FUN_000193fc(param_1);
  return param_1;
}



/* Function: FUN_00019498 @ 00019498 */

undefined4 FUN_00019498(undefined4 param_1)

{
  FUN_000193a4();
  FUN_00019484(param_1);
  return param_1;
}



/* Function: FUN_000194ac @ 000194ac */

undefined4 FUN_000194ac(undefined4 param_1)

{
  FUN_000193a4();
  FUN_00019484(param_1);
  return param_1;
}



/* Function: FUN_000194c0 @ 000194c0 */

undefined4 FUN_000194c0(undefined4 param_1)

{
  FUN_00019484();
  return param_1;
}



/* Function: FUN_000194cc @ 000194cc */

undefined4 FUN_000194cc(undefined4 param_1)

{
  FUN_00019484();
  return param_1;
}



/* Function: FUN_000195e4 @ 000195e4 */

undefined4 FUN_000195e4(uint *param_1,int param_2)

{
  undefined4 uVar1;
  void *__dest;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((int)param_1[1] <= param_2) {
    uVar3 = param_2 + 4U & 0xfffffffc;
    __dest = (void *)FUN_0001e6f0(uVar3);
    uVar2 = *param_1;
    if (__dest == (void *)0x0) {
      uVar1 = 0xfffffffc;
    }
    else {
      if ((void *)param_1[2] != (void *)0x0) {
        memcpy(__dest,(void *)param_1[2],uVar2 & 0xfffffff);
        if ((*param_1 >> 0x1c == 5) && (param_1[2] != 0)) {
          FUN_0001e6d0();
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



/* Function: FUN_0001963c @ 0001963c */

int FUN_0001963c(uint *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_000195e4(param_1,(*param_1 & 0xfffffff) + 1);
  if (iVar1 == 0) {
    FUN_000187cc(param_1,param_2);
  }
  return iVar1;
}



/* Function: FUN_00019660 @ 00019660 */

int FUN_00019660(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000195e4(param_1,param_3 + (*param_1 & 0xfffffff),param_3,param_4,param_4);
    if (iVar1 == 0) {
      FUN_00019118(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_00019690 @ 00019690 */

int FUN_00019690(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  *param_1 = uVar2 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000195e4(param_1,param_3,param_3,uVar2 & 0xf0000000,param_4);
    if (iVar1 == 0) {
      FUN_00019158(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_000196c4 @ 000196c4 */

undefined4 FUN_000196c4(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,*param_2);
  if (iVar1 == 0) {
    uVar2 = 0xfffffffc;
  }
  else {
    uVar2 = FUN_00017ef0(iVar1);
    uVar2 = FUN_00019690(param_3,iVar1,uVar2);
    (**(code **)(*param_1 + 0x2a8))(param_1,*param_2,iVar1);
  }
  return uVar2;
}



/* Function: FUN_00019718 @ 00019718 */

undefined4 FUN_00019718(uint *param_1,void *param_2,uint param_3)

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
    __dest = (void *)FUN_000182ac();
    memcpy(__dest,param_2,param_3);
    *param_1 = *param_1 & 0xf0000000 | param_3;
    if ((int)param_3 < (int)uVar2) {
      *(undefined1 *)((int)__dest + param_3) = 0;
    }
  }
  else if ((uVar2 == 5) || (uVar2 == 2)) {
    uVar1 = FUN_00019690(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}



/* Function: FUN_00019778 @ 00019778 */

void FUN_00019778(uint *param_1)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_0001e6d0();
    }
  }
  param_1[2] = 0;
  *param_1 = 0x20000000;
  param_1[1] = 0;
  return;
}



/* Function: FUN_000197a0 @ 000197a0 */

void FUN_000197a0(uint *param_1,uint param_2,uint param_3,uint param_4)

{
  if (*param_1 >> 0x1c != 2) {
    if (*param_1 >> 0x1c != 5) {
      return;
    }
    if (param_1[2] != 0) {
      FUN_0001e6d0();
    }
  }
  param_1[2] = param_2;
  *param_1 = param_3 | 0x20000000;
  param_1[1] = param_4;
  return;
}



/* Function: FUN_000197d0 @ 000197d0 */

void FUN_000197d0(uint *param_1)

{
  if (*param_1 >> 0x1c == 4) {
    if (param_1[1] != 0) {
      FUN_0001e6d0();
      param_1[1] = 0;
    }
    *param_1 = 0x10000000;
  }
  else if (*param_1 >> 0x1c == 5) {
    if (param_1[2] != 0) {
      FUN_0001e6d0();
      param_1[2] = 0;
    }
    *param_1 = 0x20000000;
    param_1[1] = 0;
  }
  return;
}



/* Function: FUN_00019814 @ 00019814 */

undefined4 FUN_00019814(undefined4 param_1)

{
  FUN_000197d0();
  return param_1;
}



/* Function: FUN_00019820 @ 00019820 */

undefined4 FUN_00019820(undefined4 param_1)

{
  FUN_000197d0();
  return param_1;
}



/* Function: FUN_00019858 @ 00019858 */

undefined4 FUN_00019858(undefined4 param_1)

{
  FUN_000197d0();
  FUN_000197d0(param_1);
  return param_1;
}



/* Function: FUN_0001986c @ 0001986c */

undefined4 FUN_0001986c(undefined4 param_1)

{
  FUN_00019778();
  FUN_00019858(param_1);
  return param_1;
}



/* Function: FUN_00019880 @ 00019880 */

undefined4 FUN_00019880(undefined4 param_1)

{
  FUN_00019778();
  FUN_00019858(param_1);
  return param_1;
}



/* Function: FUN_00019894 @ 00019894 */

undefined4 FUN_00019894(undefined4 param_1)

{
  FUN_00019858();
  return param_1;
}



/* Function: FUN_000198a0 @ 000198a0 */

undefined4 FUN_000198a0(undefined4 param_1)

{
  FUN_00019858();
  return param_1;
}



/* Function: FUN_000198ac @ 000198ac */

undefined4 FUN_000198ac(uint *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 >> 0x1c < 6) {
                    /* WARNING: Could not emulate address calculation at 0x000198c4 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((*param_1 >> 0x1c) * 4 + DAT_0001996c + 0x198c6) +
                      DAT_0001996c + 0x198c6))();
    return uVar1;
  }
  return 0;
}



/* Function: FUN_00019970 @ 00019970 */

int FUN_00019970(void)

{
  int iVar1;
  
  iVar1 = FUN_000198ac();
  if (iVar1 == 0) {
    iVar1 = DAT_00019984 + 0x1998c;
  }
  return iVar1;
}



/* Function: FUN_00019988 @ 00019988 */

void FUN_00019988(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00019970(param_2);
  (**(code **)(*param_1 + 0x29c))(param_1,uVar1);
  return;
}



/* Function: FUN_000199cc @ 000199cc */

void FUN_000199cc(uint *param_1)

{
  ushort *__dest;
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  
  uVar3 = *param_1 & 0xfffffff;
  if (uVar3 != 0) {
    __dest = (ushort *)FUN_00018964();
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



/* Function: FUN_00019a20 @ 00019a20 */

void FUN_00019a20(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *param_1;
  iVar3 = (uVar2 & 0xfffffff) - param_2;
  if (iVar3 < param_3) {
    param_3 = iVar3;
  }
  iVar1 = FUN_00018964(param_1);
  memmove((void *)(iVar1 + param_2 * 2),(void *)(iVar1 + (param_3 + param_2) * 2),
          (iVar3 - param_3) * 2);
  *param_1 = (uVar2 & 0xfffffff) - param_3 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00019a68 @ 00019a68 */

void FUN_00019a68(uint *param_1,int param_2,int param_3,void *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < param_5) {
    uVar2 = param_1[1];
    iVar1 = FUN_00018964();
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



/* Function: FUN_00019ad8 @ 00019ad8 */

int FUN_00019ad8(uint *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = FUN_000191ac(param_1,((*param_1 & 0xfffffff) - param_3) + param_5);
  if (((iVar1 == 0) && (param_4 != 0)) && (0 < param_5)) {
    FUN_00019a68(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}



/* Function: FUN_00019b14 @ 00019b14 */

void FUN_00019b14(uint *param_1,int param_2,void *param_3,size_t param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *__src;
  
  if (0 < (int)param_4) {
    uVar2 = *param_1;
    uVar3 = param_1[1];
    iVar1 = FUN_00018964();
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



/* Function: FUN_00019b74 @ 00019b74 */

int FUN_00019b74(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_4 < 1) || (param_3 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000191ac(param_1,param_4 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_00019b14(param_1,param_2,param_3,param_4);
    }
  }
  return iVar1;
}



/* Function: FUN_00019bac @ 00019bac */

void FUN_00019bac(uint *param_1)

{
  void *__dest;
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1 & 0xfffffff;
  if (uVar2 != 0) {
    __dest = (void *)FUN_000182ac();
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



/* Function: FUN_00019c38 @ 00019c38 */

void FUN_00019c38(uint *param_1,int param_2,int param_3,void *param_4,size_t param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < (int)param_5) {
    uVar2 = param_1[1];
    iVar1 = FUN_000182ac();
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



/* Function: FUN_00019c9c @ 00019c9c */

int FUN_00019c9c(uint *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = FUN_000195e4(param_1,((*param_1 & 0xfffffff) - param_3) + param_5);
  if (((iVar1 == 0) && (param_4 != 0)) && (0 < param_5)) {
    FUN_00019c38(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}



/* Function: FUN_00019cd8 @ 00019cd8 */

void FUN_00019cd8(uint *param_1,int param_2,void *param_3,size_t param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (0 < (int)param_4) {
    uVar2 = *param_1;
    uVar3 = param_1[1];
    iVar1 = FUN_000182ac();
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



/* Function: FUN_00019d30 @ 00019d30 */

int FUN_00019d30(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_4 < 1) || (param_3 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000195e4(param_1,param_4 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_00019cd8(param_1,param_2,param_3,param_4);
    }
  }
  return iVar1;
}



/* Function: FUN_00019d68 @ 00019d68 */

void FUN_00019d68(uint *param_1,uint param_2)

{
  void *__s;
  
  __s = (void *)FUN_00018964();
  memset(__s,0,param_2 << 1);
  *param_1 = param_2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00019d88 @ 00019d88 */

void FUN_00019d88(int param_1)

{
  void *__s;
  
  __s = (void *)FUN_00018964();
  memset(__s,0,*(int *)(param_1 + 4) << 1);
  return;
}



/* Function: FUN_00019d9c @ 00019d9c */

void FUN_00019d9c(uint *param_1,uint param_2)

{
  void *__s;
  
  __s = (void *)FUN_000182ac();
  memset(__s,0,param_2);
  *param_1 = param_2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_00019dbc @ 00019dbc */

void FUN_00019dbc(int param_1)

{
  void *__s;
  
  __s = (void *)FUN_000182ac();
  memset(__s,0,*(size_t *)(param_1 + 4));
  return;
}



/* Function: FUN_00019dd0 @ 00019dd0 */

void FUN_00019dd0(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 )

{
  int iVar1;
  
  iVar1 = FUN_00018964();
  FUN_0001d390(iVar1 + param_2 * 2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,param_5);
  return;
}



/* Function: FUN_00019ef8 @ 00019ef8 */

void * FUN_00019ef8(uint *param_1)

{
  void *__src;
  void *__dest;
  uint __n;
  
  __dest = (void *)0x0;
  __n = *param_1 & 0xfffffff;
  if ((__n != 0) && (__dest = malloc(__n + 1), __dest != (void *)0x0)) {
    __src = (void *)FUN_000182ac(param_1);
    memcpy(__dest,__src,__n);
    *(undefined1 *)((int)__dest + __n) = 0;
  }
  return __dest;
}



/* Function: FUN_00019f2c @ 00019f2c */

void FUN_00019f2c(uint *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 )

{
  int iVar1;
  
  iVar1 = FUN_000182ac();
  FUN_0001dd30(iVar1 + param_2,(*param_1 & 0xfffffff) - param_2,param_3,param_4,param_5);
  return;
}



/* Function: FUN_0001a078 @ 0001a078 */

int FUN_0001a078(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = DAT_0001a0d8;
  uVar4 = *param_1;
  iVar2 = FUN_0001adf0(param_2,param_3,0,0,DAT_0001a0d8);
  uVar4 = uVar4 & 0xfffffff;
  iVar3 = FUN_000195e4(param_1,iVar2 + uVar4);
  iVar2 = iVar3;
  if (iVar3 == 0) {
    iVar2 = FUN_000182ac(param_1);
    iVar2 = FUN_0001adf0(param_2,param_3,iVar2 + uVar4,param_1[1] - uVar4,uVar1);
    if (-1 < iVar2) {
      *param_1 = iVar2 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
      iVar2 = iVar3;
    }
  }
  return iVar2;
}



/* Function: FUN_0001a0dc @ 0001a0dc */

int FUN_0001a0dc(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  iVar1 = FUN_0001b160(param_3,param_4,0,0,param_2);
  uVar3 = uVar3 & 0xfffffff;
  iVar2 = FUN_000195e4(param_1,iVar1 + uVar3);
  iVar1 = iVar2;
  if (iVar2 == 0) {
    iVar1 = FUN_000182ac(param_1);
    iVar1 = FUN_0001b160(param_3,param_4,iVar1 + uVar3,param_1[1] - uVar3,param_2);
    if (-1 < iVar1) {
      *param_1 = iVar1 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
      iVar1 = iVar2;
    }
  }
  return iVar1;
}



/* Function: FUN_0001a1e0 @ 0001a1e0 */

int FUN_0001a1e0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_000182ac();
  iVar1 = FUN_0001b160(param_2,param_3,iVar1 + (uVar2 & 0xfffffff),param_1[1] - (uVar2 & 0xfffffff),
                       DAT_0001a220);
  if (-1 < iVar1) {
    *param_1 = iVar1 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
    iVar1 = 0;
  }
  return iVar1;
}



/* Function: FUN_0001a224 @ 0001a224 */

uint FUN_0001a224(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  uVar1 = FUN_000182ac();
  uVar2 = FUN_0001b160(param_2,param_3,uVar1,uVar2,DAT_0001a258);
  if (-1 < (int)uVar2) {
    *param_1 = uVar2 | *param_1 & 0xf0000000;
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_0001a2b8 @ 0001a2b8 */

int FUN_0001a2b8(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = FUN_000182ac();
  iVar1 = FUN_0001b050(param_2,param_3,iVar1 + (uVar2 & 0xfffffff),param_1[1] - (uVar2 & 0xfffffff),
                       param_4);
  if (-1 < iVar1) {
    *param_1 = iVar1 + (*param_1 & 0xfffffff) | *param_1 & 0xf0000000;
    iVar1 = 0;
  }
  return iVar1;
}



/* Function: FUN_0001a2f0 @ 0001a2f0 */

uint FUN_0001a2f0(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  uVar1 = FUN_000182ac();
  uVar2 = FUN_0001b050(param_2,param_3,uVar1,uVar2,param_4);
  if (-1 < (int)uVar2) {
    *param_1 = uVar2 | *param_1 & 0xf0000000;
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_0001a354 @ 0001a354 */

uint FUN_0001a354(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_000182ac();
  uVar2 = FUN_00017c24(uVar1,*param_1 & 0xfffffff,param_2,param_3,uVar1,param_1[1]);
  if (-1 < (int)uVar2) {
    *param_1 = uVar2 | *param_1 & 0xf0000000;
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_0001a38c @ 0001a38c */

void FUN_0001a38c(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00018964();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_0001ad20(param_2,param_3,iVar1 + uVar2 * 2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a3bc @ 0001a3bc */

int FUN_0001a3bc(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0001ad20(param_2,param_3,0,0,param_4);
    iVar1 = FUN_000191ac(param_1,iVar1 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_0001a38c(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_0001a3fc @ 0001a3fc */

void FUN_0001a3fc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00018964();
  uVar2 = FUN_0001ad20(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a420 @ 0001a420 */

int FUN_0001a420(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_0001ad20(param_2,param_3,0,0,param_4);
    iVar2 = FUN_000191ac(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_0001a3fc(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_0001a464 @ 0001a464 */

void FUN_0001a464(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00018964();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_0001b2f4(param_2,param_3,iVar1 + uVar2 * 2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a494 @ 0001a494 */

int FUN_0001a494(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0001b2f4(param_2,param_3,0,0,param_4);
    iVar1 = FUN_000191ac(param_1,iVar1 + (*param_1 & 0xfffffff));
    if (iVar1 == 0) {
      FUN_0001a464(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_0001a4d4 @ 0001a4d4 */

void FUN_0001a4d4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00018964();
  uVar2 = FUN_0001b2f4(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a4f8 @ 0001a4f8 */

int FUN_0001a4f8(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_0001b2f4(param_2,param_3,0,0,param_4);
    iVar2 = FUN_000191ac(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_0001a4d4(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_0001a53c @ 0001a53c */

void FUN_0001a53c(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_000182ac();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_0001ad28(param_2,param_3,iVar1 + uVar2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a56c @ 0001a56c */

int FUN_0001a56c(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0001ad28(param_2,param_3,0,0,param_4);
    iVar1 = FUN_000195e4(param_1,(*param_1 & 0xfffffff) * 2 + iVar1);
    if (iVar1 == 0) {
      FUN_0001a53c(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_0001a5ac @ 0001a5ac */

void FUN_0001a5ac(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_000182ac();
  uVar2 = FUN_0001ad28(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a5d0 @ 0001a5d0 */

int FUN_0001a5d0(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_0001ad28(param_2,param_3,0,0,param_4);
    iVar2 = FUN_000195e4(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_0001a5ac(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_0001a614 @ 0001a614 */

void FUN_0001a614(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_000182ac();
  uVar2 = *param_1 & 0xfffffff;
  iVar1 = FUN_0001b3cc(param_2,param_3,iVar1 + uVar2,param_1[1] - uVar2,param_4);
  *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a644 @ 0001a644 */

int FUN_0001a644(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0001b3cc(param_2,param_3,0,0,param_4);
    iVar1 = FUN_000195e4(param_1,(*param_1 & 0xfffffff) * 2 + iVar1);
    if (iVar1 == 0) {
      FUN_0001a614(param_1,param_2,param_3);
    }
  }
  return iVar1;
}



/* Function: FUN_0001a684 @ 0001a684 */

void FUN_0001a684(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_000182ac();
  uVar2 = FUN_0001b3cc(param_2,param_3,uVar1,param_1[1]);
  *param_1 = uVar2 | *param_1 & 0xf0000000;
  return;
}



/* Function: FUN_0001a6a8 @ 0001a6a8 */

int FUN_0001a6a8(uint *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *param_1 = *param_1 & 0xf0000000;
  if ((param_3 < 1) || (param_2 == 0)) {
    iVar2 = 0;
  }
  else {
    uVar1 = FUN_0001b3cc(param_2,param_3,0,0,param_4);
    iVar2 = FUN_000195e4(param_1,uVar1);
    if (iVar2 == 0) {
      FUN_0001a684(param_1,param_2,param_3);
    }
  }
  return iVar2;
}



/* Function: FUN_0001a6ec @ 0001a6ec */

int FUN_0001a6ec(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = 0;
  if ((0 < param_3) && (iVar1 = FUN_0001c0bc(param_2,param_3,param_4), -1 < iVar1)) {
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_000191ac(param_1,iVar1 + uVar2);
    if (-1 < iVar1) {
      iVar1 = FUN_00018964(param_1);
      iVar1 = FUN_0001b998(iVar1 + uVar2 * 2,param_1[1] - uVar2,param_2,param_3,param_4);
      if (-1 < iVar1) {
        uVar2 = iVar1 + uVar2;
        iVar1 = 0;
        *param_1 = uVar2 | *param_1 & 0xf0000000;
      }
    }
  }
  return iVar1;
}



/* Function: FUN_0001a814 @ 0001a814 */

void FUN_0001a814(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (0 < param_3) {
    uVar2 = *param_1;
    iVar1 = FUN_00018964();
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_0001b998(iVar1 + uVar2 * 2,param_1[1] - uVar2,param_2,param_3,param_4);
    *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_0001a918 @ 0001a918 */

int FUN_0001a918(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  iVar1 = 0;
  if ((0 < param_3) && (iVar1 = FUN_0001cd94(param_2,param_3,param_4), -1 < iVar1)) {
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_000195e4(param_1,iVar1 + uVar2);
    if (-1 < iVar1) {
      iVar1 = FUN_000182ac(param_1);
      iVar1 = FUN_0001c668(iVar1 + uVar2,param_1[1] - uVar2,param_2,param_3,param_4);
      if (-1 < iVar1) {
        uVar2 = iVar1 + uVar2;
        iVar1 = 0;
        *param_1 = uVar2 | *param_1 & 0xf0000000;
      }
    }
  }
  return iVar1;
}



/* Function: FUN_0001aa40 @ 0001aa40 */

void FUN_0001aa40(uint *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (0 < param_3) {
    uVar2 = *param_1;
    iVar1 = FUN_000182ac();
    uVar2 = uVar2 & 0xfffffff;
    iVar1 = FUN_0001c668(iVar1 + uVar2,param_1[1] - uVar2,param_2,param_3,param_4);
    *param_1 = iVar1 + uVar2 | *param_1 & 0xf0000000;
  }
  return;
}



/* Function: FUN_0001ab44 @ 0001ab44 */

undefined4 FUN_0001ab44(byte *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  ushort auStack_50 [32];
  
  *param_3 = DAT_0001ac24;
  uVar2 = (uint)*param_1;
  if ((int)(uVar2 * 0x1000000) < 0) {
    if (uVar2 < 0xa0) {
      memcpy(auStack_50,(void *)(DAT_0001ac28 + 0x1ab68),0x40);
      *param_3 = (uint)auStack_50[uVar2 + DAT_0001ac2c];
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



/* Function: FUN_0001ad20 @ 0001ad20 */

undefined4 FUN_0001ad20(void)

{
  return 0xfffffffb;
}



/* Function: FUN_0001ad28 @ 0001ad28 */

undefined4 FUN_0001ad28(void)

{
  return 0xfffffffb;
}



/* Function: FUN_0001ad30 @ 0001ad30 */

int FUN_0001ad30(byte *param_1,int param_2,byte *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    if (param_2 == -1) {
      param_2 = FUN_00017ef0(param_1);
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
          goto LAB_0001adde;
        }
        do {
          iVar2 = iVar2 + -1;
          pbVar5 = pbVar5 + 1;
          if (iVar2 == 0) goto LAB_0001ade4;
        } while ((*pbVar5 - 9 < 5) || (param_2 = iVar2, param_1 = pbVar5, *pbVar5 == 0x20));
      }
      else {
        if (iVar1 < (int)param_4) {
          *param_3 = *param_1;
          param_3 = param_3 + 1;
        }
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
LAB_0001adde:
        iVar1 = iVar1 + 1;
      }
    }
LAB_0001ade4:
    if (iVar1 < (int)param_4) {
      *param_3 = 0;
    }
  }
  return iVar1;
}



/* Function: FUN_0001adf0 @ 0001adf0 */

int FUN_0001adf0(int param_1,int param_2,char *param_3,uint param_4,int param_5)

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
      param_2 = FUN_00017ef0(param_1);
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



/* Function: FUN_0001aed8 @ 0001aed8 */

int FUN_0001aed8(byte *param_1,int param_2,byte *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  
  iVar1 = 0;
  if (param_1 != (byte *)0x0) {
    if (param_2 == -1) {
      param_2 = FUN_00017ef0(param_1);
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
          goto LAB_0001af86;
        }
        do {
          iVar2 = iVar2 + -1;
          pbVar5 = pbVar5 + 1;
          if (iVar2 == 0) goto LAB_0001af8c;
        } while ((*pbVar5 - 9 < 5) || (param_2 = iVar2, param_1 = pbVar5, *pbVar5 == 0x20));
      }
      else {
        if (iVar1 < (int)param_4) {
          *param_3 = *param_1;
          param_3 = param_3 + 1;
        }
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
LAB_0001af86:
        iVar1 = iVar1 + 1;
      }
    }
LAB_0001af8c:
    if (iVar1 < (int)param_4) {
      *param_3 = 0;
    }
  }
  return iVar1;
}



/* Function: FUN_0001af98 @ 0001af98 */

int FUN_0001af98(int param_1,int param_2,char *param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  
  iVar2 = 0;
  if (param_1 != 0) {
    if (param_2 == -1) {
      param_2 = FUN_00017ef0(param_1);
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



/* Function: FUN_0001b050 @ 0001b050 */

int FUN_0001b050(int param_1,int param_2,undefined1 *param_3,uint param_4)

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
      param_2 = FUN_00017ef0(param_1);
    }
    param_4 = param_4 & (param_3 == (undefined1 *)0x0) - 1;
    iVar1 = 0;
    iVar5 = 0;
LAB_0001b148:
    if (iVar5 < param_2) {
      iVar4 = 0;
      uVar3 = 0;
      while (iVar6 = iVar5, iVar4 < 4) {
        if (param_2 <= iVar5) {
LAB_0001b0fe:
          if (iVar4 == 3) {
            if (iVar1 + 1 < (int)param_4) {
              *param_3 = (char)(uVar3 >> 10);
              param_3[1] = (char)(uVar3 >> 2);
              param_3 = param_3 + 2;
            }
            iVar1 = iVar1 + 2;
            iVar5 = iVar6;
            goto LAB_0001b148;
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
            if (uVar2 != 0x2f) goto LAB_0001b0fe;
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
      goto LAB_0001b148;
    }
    if (iVar1 < (int)param_4) {
      *param_3 = 0;
    }
  }
  return iVar1;
}



/* Function: FUN_0001b160 @ 0001b160 */

int FUN_0001b160(byte *param_1,int param_2,undefined1 *param_3,uint param_4,int param_5)

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
    param_2 = FUN_00017ef0(param_1);
  }
  param_4 = param_4 & -(uint)(param_3 != (undefined1 *)0x0);
  FUN_0001e7d4(param_2,3);
  iVar3 = 0;
  iVar4 = DAT_0001b2e8 + 0x1b1ac;
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
      iVar3 = DAT_0001b2f0 + 0x1b2ba;
      *param_3 = *(undefined1 *)(iVar3 + (uint)(param_1[param_2 + -1] >> 2) + 0x40);
      param_3[1] = *(undefined1 *)(iVar3 + (param_1[param_2 + -1] & 3) * 0x10 + 0x40);
      param_3[2] = 0x3d;
LAB_0001b2d6:
      param_3[3] = 0x3d;
      param_3 = param_3 + 4;
    }
  }
  else {
    if (extraout_r1 != 2) goto LAB_0001b2dc;
    if (iVar2 + 3 < (int)param_4) {
      iVar3 = DAT_0001b2ec + 0x1b26e;
      *param_3 = *(undefined1 *)(iVar3 + (uint)(param_1[param_2 + -2] >> 2) + 0x40);
      param_3[1] = *(undefined1 *)
                    (iVar3 + ((param_1[param_2 + -2] & 3) << 4 |
                             (int)(uint)param_1[param_2 + -1] >> 4) + 0x40);
      param_3[2] = *(undefined1 *)(iVar3 + (param_1[param_2 + -1] & 0xf) * 4 + 0x40);
      goto LAB_0001b2d6;
    }
  }
  iVar2 = iVar2 + 4;
LAB_0001b2dc:
  if (iVar2 < (int)param_4) {
    *param_3 = 0;
  }
  return iVar2;
}



/* Function: FUN_0001b2f4 @ 0001b2f4 */

int FUN_0001b2f4(byte *param_1,int param_2,ushort *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint local_1c [2];
  
  if (param_2 == -1) {
    param_2 = FUN_00017ef0();
  }
  iVar3 = 0;
  param_4 = param_4 & (param_3 == (ushort *)0x0) - 1;
  while (0 < param_2) {
    bVar1 = *param_1;
    if ((int)((uint)bVar1 * 0x1000000) < 0) {
      iVar2 = FUN_0001ab44(param_1,param_2,local_1c);
      param_1 = param_1 + iVar2;
      iVar2 = -iVar2;
    }
    else {
      param_1 = param_1 + 1;
      iVar2 = -1;
      local_1c[0] = (uint)bVar1;
    }
    param_2 = param_2 + iVar2;
    if (DAT_0001b3ac < local_1c[0]) {
      if (DAT_0001b3bc < local_1c[0]) {
        local_1c[0] = DAT_0001b3b8;
      }
      else {
        if (iVar3 + 1 < (int)param_4) {
          *param_3 = (ushort)((local_1c[0] + DAT_0001b3c0 & 0xfffff) >> 10) | (ushort)DAT_0001b3c4;
          param_3[1] = (ushort)local_1c[0] & 0x3ff | (ushort)DAT_0001b3c8;
          param_3 = param_3 + 2;
        }
        iVar3 = iVar3 + 2;
      }
    }
    else {
      if (local_1c[0] + DAT_0001b3b0 <= DAT_0001b3b4) {
        local_1c[0] = DAT_0001b3b8;
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



/* Function: FUN_0001b3cc @ 0001b3cc */

void FUN_0001b3cc(ushort *param_1,int param_2,byte *param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  if (param_2 == -1) {
    param_2 = FUN_00018084();
  }
  param_4 = param_4 & (param_3 == (byte *)0x0) - 1;
  iVar2 = 0;
LAB_0001b4f4:
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
      if ((DAT_0001b510 < DAT_0001b50c + uVar4) || (iVar3 < 1)) break;
      uVar1 = *puVar6;
      uVar5 = uVar4;
      if (DAT_0001b514 + (uint)uVar1 <= DAT_0001b510) {
        puVar6 = param_1 + 2;
        iVar3 = param_2 + -2;
        uVar4 = (uVar4 & 0x3ff) * 0x400 + (uVar1 & 0x3ff) + 0x10000;
        uVar5 = DAT_0001b524;
        if (uVar4 <= DAT_0001b518) break;
      }
LAB_0001b46e:
      param_2 = iVar3;
      param_1 = puVar6;
      if (DAT_0001b520 < uVar5) {
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
      if (DAT_0001b51c < uVar4) goto LAB_0001b46e;
      if (iVar2 + 1 < (int)param_4) {
        *param_3 = (byte)(uVar4 >> 6) | 0xc0;
        param_3[1] = (byte)uVar4 & 0x3f | 0x80;
        param_3 = param_3 + 2;
      }
      iVar2 = iVar2 + 2;
      goto LAB_0001b4f4;
    }
    if (iVar2 < (int)param_4) {
      *param_3 = (byte)uVar4;
      param_3 = param_3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}



/* Function: thunk_FUN_0001b52c @ 0001b528 */

void thunk_FUN_0001b52c(char *param_1)

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



/* Function: FUN_0001b52c @ 0001b52c */

void FUN_0001b52c(char *param_1)

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



/* Function: FUN_0001b570 @ 0001b570 */

void FUN_0001b570(char *param_1)

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
      iVar2 = FUN_00017ef0(param_1);
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



/* Function: FUN_0001b5b0 @ 0001b5b0 */

byte * FUN_0001b5b0(double *param_1,undefined4 param_2,int param_3,int *param_4,undefined4 *param_5,
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
  iVar5 = FUN_0001f0f0(param_1,param_2,DAT_0001b780,DAT_0001b784);
  if (iVar5 != 0) {
    *param_5 = 1;
  }
  modf((double)CONCAT44(extraout_s1,extraout_s0),param_1);
  uVar1 = CONCAT44(extraout_r1,extraout_r0);
  iVar5 = FUN_0001f0dc(local_20,local_1c,DAT_0001b780,DAT_0001b784);
  pbVar9 = param_6;
  if (iVar5 == 0) {
    iVar11 = 0;
    pbVar8 = param_6 + 0x22;
    while( true ) {
      uVar3 = local_1c;
      uVar2 = local_20;
      iVar5 = FUN_0001f0dc(local_20,local_1c,DAT_0001b780,DAT_0001b784);
      if (iVar5 != 0) break;
      pdVar6 = (double *)FUN_0001ee10(uVar2,uVar3,DAT_0001b788,DAT_0001b78c);
      modf((double)CONCAT44(extraout_s1_00,extraout_s0_00),pdVar6);
      local_28._0_4_ = extraout_r0_00;
      local_28._4_4_ = extraout_r1_00;
      uVar10 = FUN_0001e7f8();
      FUN_0001eba4((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_0001b788,DAT_0001b78c);
      cVar4 = FUN_0001f140();
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
    iVar5 = FUN_0001f12c(extraout_r0,extraout_r1,DAT_0001b780,DAT_0001b784);
    iVar11 = 0;
    if (iVar5 != 0) {
      while( true ) {
        local_34 = (undefined4)((ulonglong)uVar1 >> 0x20);
        local_38 = (undefined4)uVar1;
        local_28 = FUN_0001eba4(local_38,local_34,DAT_0001b788,DAT_0001b78c);
        iVar5 = FUN_0001f0f0((int)local_28,(int)((ulonglong)local_28 >> 0x20),DAT_0001b798,
                             DAT_0001b79c);
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
      pdVar6 = (double *)FUN_0001eba4(local_38,local_34,DAT_0001b788,DAT_0001b78c,pbVar7,puVar12);
      modf((double)CONCAT44(extraout_s1_01,extraout_s0_01),pdVar6);
      uVar1 = CONCAT44(extraout_r1_01,extraout_r0_01);
      cVar4 = FUN_0001f140((undefined4)local_28,local_28._4_4_);
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



/* Function: FUN_0001b7a0 @ 0001b7a0 */

void FUN_0001b7a0(undefined4 param_1,undefined4 param_2,char *param_3,int param_4,size_t param_5)

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
  
  local_1c = **(int **)(DAT_0001b990 + 0x1b7ae);
  if ((param_4 == 0x45) || (local_4c = '\0', param_4 == 0x47)) {
    param_4 = (param_4 + 0x20) * 0x1000000 >> 0x18;
    local_4c = ' ';
  }
  if (param_4 == 0x67) {
    FUN_0001b5b0(param_1,param_2,param_5,&local_44,&local_48,auStack_40,1);
    if ((local_44 + -1 < (int)param_5) && (-5 < local_44 + -1)) {
      param_5 = param_5 - local_44;
LAB_0001b8c2:
      pcVar4 = (char *)FUN_0001b5b0(param_1,param_2,param_5,&local_44,&local_48,auStack_40,0);
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
      goto LAB_0001b968;
    }
    param_5 = param_5 - 1;
  }
  else if (param_4 != 0x65) {
    if (param_4 != 0x66) goto LAB_0001b968;
    goto LAB_0001b8c2;
  }
  pcVar1 = (char *)FUN_0001b5b0(param_1,param_2,param_5 + 1,&local_44,&local_48,auStack_40,1);
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
    iVar2 = FUN_0001f0dc(param_1,param_2,DAT_0001b988,DAT_0001b98c);
    local_44 = 0;
    if (iVar2 != 0) goto LAB_0001b87c;
    local_44 = -1;
LAB_0001b874:
    local_50[1] = '-';
    local_44 = -local_44;
  }
  else {
    local_44 = local_44 + -1;
    if (local_44 < 0) goto LAB_0001b874;
LAB_0001b87c:
    local_50[1] = '+';
  }
  FUN_0001e7d4(local_44,10);
  local_50[4] = extraout_r1 + '0';
  uVar3 = FUN_0001e6f8(local_44,10);
  FUN_0001e7d4(uVar3,10);
  local_50[3] = extraout_r1_00 + '0';
  uVar3 = FUN_0001e6f8(uVar3,10);
  FUN_0001e7d4(uVar3,10);
  local_50[2] = extraout_r1_01 + '0';
  param_3 = local_50 + 5;
LAB_0001b968:
  *param_3 = '\0';
  if (local_1c == **(int **)(DAT_0001b994 + 0x1b974)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_0001b998 @ 0001b998 */

void FUN_0001b998(undefined2 *param_1,uint param_2,ushort *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 local_b0;
  ushort *local_ac;
  int local_a0;
  uint local_84;
  
  iVar1 = **(int **)(DAT_0001bc88 + 0x1b9a8);
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
        goto LAB_0001c06e;
      }
      uVar2 = 0;
      if ((*local_ac - 0x20 & 0xffff) < 0x5b) {
        uVar2 = *(byte *)(DAT_0001bc90 + (uint)*local_ac + 0x1b9b2) & 0xf;
      }
      local_84 = (int)(uint)*(byte *)(uVar2 * 9 + local_84 + DAT_0001bc8c + 0x1b9d4) >> 4;
      if (local_84 == 8) break;
      local_ac = local_ac + 1;
      local_a0 = local_a0 + -1;
      if (local_84 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x0001ba3e */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_84 * 4 + DAT_0001bc94 + 0x1ba40) + DAT_0001bc94 + 0x1ba40))();
        return;
      }
    }
    local_b0 = 0xffffffff;
  }
LAB_0001c06e:
  if (iVar1 == **(int **)(DAT_0001c088 + 0x1c078)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_b0);
}



/* Function: FUN_0001c0bc @ 0001c0bc */

void FUN_0001c0bc(ushort *param_1,int param_2)

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
        uVar1 = *(byte *)(DAT_0001c3a0 + (uint)*local_94 + 0x1c0c8) & 0xf;
      }
      local_74 = (int)(uint)*(byte *)(uVar1 * 9 + local_74 + DAT_0001c3a4 + 0x1c0ea) >> 4;
      if (local_74 == 8) {
        local_98 = 0xffffffff;
        break;
      }
      local_94 = local_94 + 1;
      local_80 = local_80 + -1;
      if (local_74 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x0001c150 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_74 * 4 + DAT_0001c3a8 + 0x1c152) + DAT_0001c3a8 + 0x1c152))();
        return;
      }
    }
  }
  if (**(int **)(DAT_0001c39c + 0x1c0c8) == **(int **)(DAT_0001c63c + 0x1c62e)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_98);
}



/* Function: FUN_0001c668 @ 0001c668 */

void FUN_0001c668(undefined1 *param_1,uint param_2,byte *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 local_b0;
  byte *local_ac;
  int local_a0;
  uint local_84;
  
  iVar1 = **(int **)(DAT_0001c964 + 0x1c678);
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
        goto LAB_0001cd46;
      }
      uVar2 = 0;
      if ((*local_ac - 0x20 & 0xff) < 0x5b) {
        uVar2 = *(byte *)(DAT_0001c96c + (uint)*local_ac + 0x1c682) & 0xf;
      }
      local_84 = (int)(uint)*(byte *)(uVar2 * 9 + local_84 + DAT_0001c968 + 0x1c6a4) >> 4;
      if (local_84 == 8) break;
      local_ac = local_ac + 1;
      local_a0 = local_a0 + -1;
      if (local_84 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x0001c70e */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_84 * 4 + DAT_0001c970 + 0x1c710) + DAT_0001c970 + 0x1c710))();
        return;
      }
    }
    local_b0 = 0xffffffff;
  }
LAB_0001cd46:
  if (iVar1 == **(int **)(DAT_0001cd60 + 0x1cd50)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_b0);
}



/* Function: FUN_0001cd94 @ 0001cd94 */

void FUN_0001cd94(byte *param_1,int param_2)

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
        uVar1 = *(byte *)(DAT_0001d094 + (uint)*local_94 + 0x1cda0) & 0xf;
      }
      local_74 = (int)(uint)*(byte *)(uVar1 * 9 + local_74 + DAT_0001d098 + 0x1cdc2) >> 4;
      if (local_74 == 8) {
        local_98 = 0xffffffff;
        break;
      }
      local_94 = local_94 + 1;
      local_84 = local_84 + -1;
      if (local_74 < 8) {
                    /* WARNING: Could not emulate address calculation at 0x0001ce28 */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(int *)(local_74 * 4 + DAT_0001d09c + 0x1ce2a) + DAT_0001d09c + 0x1ce2a))();
        return;
      }
    }
  }
  if (**(int **)(DAT_0001d090 + 0x1cda0) == **(int **)(DAT_0001d330 + 0x1d320)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(local_98);
}



/* Function: FUN_0001d35c @ 0001d35c */

void FUN_0001d35c(int param_1,undefined4 *param_2,undefined4 *param_3)

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



/* Function: FUN_0001d390 @ 0001d390 */

void FUN_0001d390(int param_1,int param_2,ushort *param_3,int param_4)

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
  
  iVar3 = **(int **)(DAT_0001d680 + 0x1d3a0);
  iVar7 = 0;
  FUN_0001dcd2();
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
        FUN_0001dcd2();
        param_3 = extraout_r3;
      }
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      if ((4 < uVar1 - 9) && (uVar1 != 0x20)) {
        FUN_0001dcd2();
        param_3 = extraout_r3_00;
      }
    } while( true );
  }
  if (uVar4 != 0x25) {
    if (*(ushort *)(iStack_c4 * 2 + param_1) != uVar4) {
      FUN_0001dcde();
    }
    iVar7 = 1;
    FUN_0001dcd2();
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
    FUN_0001dcde();
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
      goto LAB_0001d4f2;
    }
    if (uVar6 == 0x68) {
      iVar7 = iVar8 + 1;
      if (param_3[iVar7] == 0x68) {
        iVar7 = iVar8 + 2;
      }
      goto LAB_0001d4f2;
    }
    if (uVar6 != 0x6c) goto LAB_0001d4f2;
    if (param_3[iVar8 + 1] == 0x6c) {
      iVar7 = iVar8 + 2;
      goto LAB_0001d4f2;
    }
  }
  iVar7 = iVar8 + 1;
LAB_0001d4f2:
  uVar1 = param_3[iVar7];
  if ((uVar1 != 0x4e) && (uVar1 != 0x6e)) {
    if ((uVar1 != 0x43) && ((uVar1 != 99 && (uVar1 != 0x5b)))) {
      puVar5 = (ushort *)(param_1 + iStack_c4 * 2);
      while ((*puVar5 - 9 < 5 || (*puVar5 == 0x20))) {
        puVar5 = puVar5 + 1;
        if (param_2 <= iStack_c4) {
          FUN_0001dcde();
          puVar5 = extraout_r1_00;
        }
        iStack_c4 = iStack_c4 + 1;
      }
    }
    if (param_2 <= iStack_c4) {
      FUN_0001dcde();
      return;
    }
  }
  if ((ushort)(uVar1 - 0x43) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x0001d56c */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(ushort)(uVar1 - 0x43) * 4 + DAT_0001d684 + 0x1d56e) +
              DAT_0001d684 + 0x1d56e))();
    return;
  }
  if ((*(ushort *)(iStack_c4 * 2 + param_1) == uVar1) && (iVar7 + 1 < param_4)) {
    FUN_0001d3b4();
  }
  if (iVar3 == **(int **)(DAT_0001dd28 + 0x1dce8)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}



/* Function: FUN_0001d3b4 @ 0001d3b4 */

void FUN_0001d3b4(void)

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
        FUN_0001dcd2();
        puVar6 = extraout_r3;
      }
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      if ((4 < uVar1 - 9) && (uVar1 != 0x20)) {
        FUN_0001dcd2();
        puVar6 = extraout_r3_00;
      }
    } while( true );
  }
  if (uVar5 != 0x25) {
    if (*(ushort *)(in_stack_00000004 * 2 + unaff_r7) != uVar5) {
      FUN_0001dcde();
    }
    unaff_r5 = unaff_r5 + 1;
    FUN_0001dcd2();
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
    FUN_0001dcde();
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
      goto LAB_0001d4f2;
    }
    if (uVar7 == 0x68) {
      iVar4 = iVar8 + 1;
      if (*(short *)(iVar4 * 2 + in_stack_00000024) == 0x68) {
        iVar4 = iVar8 + 2;
      }
      goto LAB_0001d4f2;
    }
    if (uVar7 != 0x6c) goto LAB_0001d4f2;
    if (*(short *)((iVar8 + 1) * 2 + in_stack_00000024) == 0x6c) {
      iVar4 = iVar8 + 2;
      goto LAB_0001d4f2;
    }
  }
  iVar4 = iVar8 + 1;
LAB_0001d4f2:
  sVar2 = *(short *)(iVar4 * 2 + in_stack_00000024);
  if ((sVar2 != 0x4e) && (sVar2 != 0x6e)) {
    if ((sVar2 != 0x43) && ((sVar2 != 99 && (sVar2 != 0x5b)))) {
      puVar6 = (ushort *)(unaff_r7 + in_stack_00000004 * 2);
      while ((*puVar6 - 9 < 5 || (*puVar6 == 0x20))) {
        puVar6 = puVar6 + 1;
        if (in_stack_0000002c <= in_stack_00000004) {
          FUN_0001dcde();
          puVar6 = extraout_r1_00;
        }
        in_stack_00000004 = in_stack_00000004 + 1;
      }
    }
    if (in_stack_0000002c <= in_stack_00000004) {
      FUN_0001dcde();
      return;
    }
  }
  if ((ushort)(sVar2 - 0x43) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x0001d56c */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(ushort)(sVar2 - 0x43) * 4 + DAT_0001d684 + 0x1d56e) +
              DAT_0001d684 + 0x1d56e))();
    return;
  }
  if ((*(short *)(in_stack_00000004 * 2 + unaff_r7) == sVar2) && (iVar4 + 1 < in_stack_00000034)) {
    FUN_0001d3b4();
  }
  if (in_stack_000000ac == **(int **)(DAT_0001dd28 + 0x1dce8)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(in_stack_00000028);
}



/* Function: FUN_0001dcd2 @ 0001dcd2 */

void FUN_0001dcd2(void)

{
  int unaff_r5;
  undefined4 in_stack_00000028;
  int in_stack_00000034;
  int in_stack_000000ac;
  
  if (unaff_r5 < in_stack_00000034) {
    FUN_0001d3b4();
  }
  if (in_stack_000000ac != **(int **)(DAT_0001dd28 + 0x1dce8)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_0001dcde @ 0001dcde */

void FUN_0001dcde(void)

{
  undefined4 in_stack_00000028;
  int in_stack_000000ac;
  
  if (in_stack_000000ac != **(int **)(DAT_0001dd28 + 0x1dce8)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_0001dd30 @ 0001dd30 */

void FUN_0001dd30(int param_1,int param_2,byte *param_3,int param_4)

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
  
  iVar4 = **(int **)(DAT_0001e048 + 0x1dd40);
  iVar7 = 0;
  FUN_0001e5de();
  uVar5 = (uint)*param_3;
  if ((uVar5 - 9 < 5) || (uVar5 == 0x20)) {
    for (; ((*(byte *)(param_1 + iStack_c4) - 9 < 5 || (*(byte *)(param_1 + iStack_c4) == 0x20)) &&
           (iStack_c4 < param_2)); iStack_c4 = iStack_c4 + 1) {
    }
    do {
      iVar7 = iVar7 + 1;
      if (iVar7 == param_4) {
        FUN_0001e5de();
      }
      if ((4 < param_3[iVar7] - 9) && (param_3[iVar7] != 0x20)) {
        FUN_0001e5de();
      }
    } while( true );
  }
  if (uVar5 != 0x25) {
    if (*(byte *)(param_1 + iStack_c4) != uVar5) {
      FUN_0001e5ea();
    }
    iVar7 = 1;
    FUN_0001e5de();
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
    FUN_0001e5ea();
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
      goto LAB_0001de68;
    }
    if (uVar6 == 0x68) {
      iVar7 = iVar8 + 1;
      if (param_3[iVar7] == 0x68) {
        iVar7 = iVar8 + 2;
      }
      goto LAB_0001de68;
    }
    if (uVar6 != 0x6c) goto LAB_0001de68;
    if (param_3[iVar8 + 1] == 0x6c) {
      iVar7 = iVar8 + 2;
      goto LAB_0001de68;
    }
  }
  iVar7 = iVar8 + 1;
LAB_0001de68:
  bVar2 = param_3[iVar7];
  if ((bVar2 != 0x4e) && (bVar2 != 0x6e)) {
    if ((bVar2 != 0x43) && ((bVar2 != 99 && (bVar2 != 0x5b)))) {
      for (; (*(byte *)(param_1 + iStack_c4) - 9 < 5 || (*(byte *)(param_1 + iStack_c4) == 0x20));
          iStack_c4 = iStack_c4 + 1) {
        if (param_2 <= iStack_c4) {
          FUN_0001e5ea();
          return;
        }
      }
    }
    if (param_2 <= iStack_c4) {
      FUN_0001e5ea();
      return;
    }
  }
  if ((byte)(bVar2 + 0xbd) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x0001ded4 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(byte)(bVar2 + 0xbd) * 4 + DAT_0001e04c + 0x1ded6) +
              DAT_0001e04c + 0x1ded6))();
    return;
  }
  if ((*(byte *)(param_1 + iStack_c4) == bVar2) && (iVar7 + 1 < param_4)) {
    FUN_0001dd52();
  }
  if (iVar4 == **(int **)(DAT_0001e638 + 0x1e5f4)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}



/* Function: FUN_0001dd52 @ 0001dd52 */

void FUN_0001dd52(void)

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
        FUN_0001e5de();
      }
      if ((4 < *(byte *)(in_stack_00000024 + unaff_r5) - 9) &&
         (*(byte *)(in_stack_00000024 + unaff_r5) != 0x20)) {
        FUN_0001e5de();
      }
    } while( true );
  }
  if (uVar4 != 0x25) {
    if (*(byte *)(in_stack_00000020 + in_stack_00000004) != uVar4) {
      FUN_0001e5ea();
    }
    unaff_r5 = unaff_r5 + 1;
    FUN_0001e5de();
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
    FUN_0001e5ea();
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
      goto LAB_0001de68;
    }
    if (uVar5 == 0x68) {
      iVar3 = iVar6 + 1;
      if (*(char *)(in_stack_00000024 + iVar3) == 'h') {
        iVar3 = iVar6 + 2;
      }
      goto LAB_0001de68;
    }
    if (uVar5 != 0x6c) goto LAB_0001de68;
    if (*(char *)(in_stack_00000024 + iVar6 + 1) == 'l') {
      iVar3 = iVar6 + 2;
      goto LAB_0001de68;
    }
  }
  iVar3 = iVar6 + 1;
LAB_0001de68:
  cVar1 = *(char *)(in_stack_00000024 + iVar3);
  if ((cVar1 != 'N') && (cVar1 != 'n')) {
    if ((cVar1 != 'C') && ((cVar1 != 'c' && (cVar1 != '[')))) {
      for (; (*(byte *)(in_stack_00000020 + in_stack_00000004) - 9 < 5 ||
             (*(byte *)(in_stack_00000020 + in_stack_00000004) == 0x20));
          in_stack_00000004 = in_stack_00000004 + 1) {
        if (in_stack_00000030 <= in_stack_00000004) {
          FUN_0001e5ea();
          return;
        }
      }
    }
    if (in_stack_00000030 <= in_stack_00000004) {
      FUN_0001e5ea();
      return;
    }
  }
  if ((byte)(cVar1 + 0xbd) < 0x36) {
                    /* WARNING: Could not emulate address calculation at 0x0001ded4 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)((uint)(byte)(cVar1 + 0xbd) * 4 + DAT_0001e04c + 0x1ded6) +
              DAT_0001e04c + 0x1ded6))();
    return;
  }
  if ((*(char *)(in_stack_00000020 + in_stack_00000004) == cVar1) && (iVar3 + 1 < in_stack_00000034)
     ) {
    FUN_0001dd52();
  }
  if (in_stack_000000ac == **(int **)(DAT_0001e638 + 0x1e5f4)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(in_stack_00000028);
}



/* Function: FUN_0001e5de @ 0001e5de */

void FUN_0001e5de(void)

{
  int unaff_r5;
  undefined4 in_stack_00000028;
  int in_stack_00000034;
  int in_stack_000000ac;
  
  if (unaff_r5 < in_stack_00000034) {
    FUN_0001dd52();
  }
  if (in_stack_000000ac != **(int **)(DAT_0001e638 + 0x1e5f4)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_0001e5ea @ 0001e5ea */

void FUN_0001e5ea(void)

{
  undefined4 in_stack_00000028;
  int in_stack_000000ac;
  
  if (in_stack_000000ac != **(int **)(DAT_0001e638 + 0x1e5f4)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(in_stack_00000028);
  }
  return;
}



/* Function: FUN_0001e6c4 @ 0001e6c4 */

void FUN_0001e6c4(void *param_1)

{
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  return;
}



/* Function: FUN_0001e6d0 @ 0001e6d0 */

void FUN_0001e6d0(void)

{
  FUN_0001e6c4();
  return;
}



/* Function: FUN_0001e6e8 @ 0001e6e8 */

void FUN_0001e6e8(size_t param_1)

{
  malloc(param_1);
  return;
}



/* Function: FUN_0001e6f0 @ 0001e6f0 */

void FUN_0001e6f0(void)

{
  FUN_0001e6e8();
  return;
}



/* Function: FUN_0001e6f8 @ 0001e6f8 */

uint FUN_0001e6f8(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_1 ^ param_2;
  if (param_2 == 0) {
    FUN_0001f26c();
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



/* Function: FUN_0001e7d4 @ 0001e7d4 */

void FUN_0001e7d4(void)

{
  FUN_0001e6f8();
  return;
}



/* Function: FUN_0001e7f8 @ 0001e7f8 */

ulonglong FUN_0001e7f8(uint param_1,uint param_2,uint param_3,uint param_4)

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
LAB_0001ea68:
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
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_0001ea68;
    }
LAB_0001e910:
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
  if ((uVar11 & 0x100000) != 0) goto LAB_0001e910;
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
      goto LAB_0001e990;
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
LAB_0001e990:
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



/* Function: FUN_0001eac8 @ 0001eac8 */

ulonglong FUN_0001eac8(uint param_1)

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
      goto LAB_0001e990;
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
LAB_0001e990:
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



/* Function: FUN_0001eba4 @ 0001eba4 */

ulonglong FUN_0001eba4(undefined4 param_1,uint param_2,uint param_3,uint param_4)

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
    uVar14 = FUN_0001ed84();
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



/* Function: FUN_0001ed84 @ 0001ed84 */

ulonglong FUN_0001ed84(int param_1,uint param_2,int param_3,uint param_4)

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



/* Function: FUN_0001ee10 @ 0001ee10 */

ulonglong FUN_0001ee10(undefined4 param_1,uint param_2,uint param_3,uint param_4)

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
    uVar16 = FUN_0001efa4();
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
        if ((uVar6 & 0x100000) != 0) goto LAB_0001ef50;
        uVar6 = uVar6 | uVar2;
        uVar2 = 0;
        uVar11 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar2;
      uVar2 = 0;
    }
LAB_0001ef50:
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



/* Function: FUN_0001efa4 @ 0001efa4 */

ulonglong FUN_0001efa4(int param_1,uint param_2,int param_3,uint param_4)

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
LAB_0001edec:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else if (uVar2 == in_r12) {
      param_1 = param_3;
      uVar3 = param_4;
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
LAB_0001eda0:
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
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) goto LAB_0001edec;
      if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) goto LAB_0001eda0;
    }
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}



/* Function: FUN_0001f024 @ 0001f024 */

uint FUN_0001f024(uint param_1,uint param_2,uint param_3,uint param_4)

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



/* Function: FUN_0001f0ac @ 0001f0ac */

void FUN_0001f0ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0001f0c8(param_3,param_4,param_1,param_2);
  return;
}



/* Function: FUN_0001f0c8 @ 0001f0c8 */

undefined4 FUN_0001f0c8(undefined4 param_1)

{
  FUN_0001f024();
  return param_1;
}



/* Function: FUN_0001f0dc @ 0001f0dc */

undefined1 FUN_0001f0dc(void)

{
  undefined1 in_ZR;
  
  FUN_0001f0c8();
  return in_ZR;
}



/* Function: FUN_0001f0f0 @ 0001f0f0 */

bool FUN_0001f0f0(void)

{
  undefined1 in_CY;
  
  FUN_0001f0c8();
  return !(bool)in_CY;
}



/* Function: FUN_0001f104 @ 0001f104 */

bool FUN_0001f104(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_0001f0c8();
  return !(bool)in_CY || (bool)in_ZR;
}



/* Function: FUN_0001f118 @ 0001f118 */

bool FUN_0001f118(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_0001f0ac();
  return !(bool)in_CY || (bool)in_ZR;
}



/* Function: FUN_0001f12c @ 0001f12c */

bool FUN_0001f12c(void)

{
  undefined1 in_CY;
  
  FUN_0001f0ac();
  return !(bool)in_CY;
}



/* Function: FUN_0001f140 @ 0001f140 */

uint FUN_0001f140(uint param_1,uint param_2)

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



/* Function: FUN_0001f19c @ 0001f19c */

uint FUN_0001f19c(uint param_1,uint param_2)

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



/* Function: FUN_0001f23c @ 0001f23c */

undefined8 FUN_0001f23c(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_1 * param_4 + param_3 * param_2,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



/* Function: FUN_0001f250 @ 0001f250 */

void FUN_0001f250(void)

{
  FUN_0001f2c0();
  return;
}



/* Function: FUN_0001f26c @ 0001f26c */

void FUN_0001f26c(void)

{
  raise(8);
  return;
}



/* Function: FUN_0001f27c @ 0001f27c */

void FUN_0001f27c(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = FUN_00020c70();
  lVar2 = lVar2 * CONCAT44(param_4,param_3);
  uVar1 = (uint)lVar2;
  *param_5 = param_1 - uVar1;
  param_5[1] = param_2 - ((int)((ulonglong)lVar2 >> 0x20) + (uint)(param_1 < uVar1));
  return;
}



/* Function: FUN_0001f2c0 @ 0001f2c0 */

void FUN_0001f2c0(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = FUN_000207f4();
  lVar2 = lVar2 * CONCAT44(param_4,param_3);
  uVar1 = (uint)lVar2;
  *param_5 = param_1 - uVar1;
  param_5[1] = param_2 - ((int)((ulonglong)lVar2 >> 0x20) + (uint)(param_1 < uVar1));
  return;
}



/* Function: FUN_0001f304 @ 0001f304 */

undefined4 FUN_0001f304(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: FUN_0001f350 @ 0001f350 */

undefined4 FUN_0001f350(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: FUN_0001f39c @ 0001f39c */

int FUN_0001f39c(uint *param_1)

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



/* Function: FUN_0001f3e0 @ 0001f3e0 */

undefined4 FUN_0001f3e0(uint param_1,uint param_2,undefined4 param_3,int param_4)

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
LAB_0001f7d8:
    do {
      while( true ) {
        local_58 = *puVar8;
        if (local_58 == 0) goto LAB_0001f7e4;
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
        FUN_0001f304(param_3,0,0xf,0,&local_30);
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
LAB_0001f6d8:
              FUN_0001f304(param_3,0,0xd,0,&local_30);
              *(uint **)(param_2 + 0x28) = puVar6;
              *(uint *)(param_2 + 0x20) = local_30;
              *(int *)(param_2 + 0x24) = local_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar5 = *(uint *)(param_2 + 0x20);
          FUN_0001f304(param_3,0,0xd,0,&local_30);
          if ((uVar5 == local_30) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            local_30 = FUN_0001f39c(puVar6);
            FUN_0001f350(param_3,0,0xf,0,&local_30);
LAB_0001f79c:
            uVar4 = 0;
            local_30 = param_2;
            goto LAB_0001f858;
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
              if (local_58 == uVar5) goto LAB_0001f6d8;
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
          FUN_0001f304(param_3,0,0xd,0,&local_30);
          if ((uVar10 == local_30) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar6 + 1;
            *(uint *)(param_2 + 0x28) = uVar5;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar6) {
              local_30 = FUN_0001f39c(puVar6 + uVar5 + 1);
              FUN_0001f350(param_3,0,0xf,0,&local_30);
              goto LAB_0001f79c;
            }
            bVar9 = true;
          }
        }
        if ((int)*puVar6 < 0) {
          puVar6 = puVar6 + 1;
        }
        puVar8 = puVar6 + uVar5 + 1;
        goto LAB_0001f7d8;
      }
      if (uVar7 == 0) {
        bVar1 = false;
      }
      puVar8 = puVar6 + 1;
    } while (!bVar1);
    uVar5 = FUN_0001f39c(puVar6);
    *(uint **)(param_2 + 0x38) = puVar8;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      local_30 = uVar5;
      goto LAB_0001f858;
    }
  }
  else {
    bVar9 = false;
LAB_0001f7e4:
    iVar3 = FUN_0002043c(param_3,&local_3c);
    if (iVar3 == 0) {
      if (!bVar9) {
        return 8;
      }
      FUN_0001f304(param_3,0,0xf,0,&local_30);
      FUN_0001f350(param_3,0,0xe,0,&local_30);
      uVar4 = 0xf;
      local_30 = *(uint *)(DAT_0001f870 + 0x1f848);
LAB_0001f858:
      FUN_0001f350(param_3,0,uVar4,0,&local_30);
      return 7;
    }
  }
  return 9;
}



/* Function: FUN_0001f88c @ 0001f88c */

undefined4 FUN_0001f88c(int param_1,int param_2)

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
  
  iVar8 = DAT_0001fa40 + 0x1f8a0;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_0001fa44) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_0001fa4c);
    local_2c[0] = *(int *)(iVar8 + DAT_0001fa48) - iVar2 >> 3;
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
        uVar3 = FUN_0001f39c(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_0001f39c(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_0001fa18;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_0001f39c(iVar10);
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
        uVar5 = FUN_0001f39c();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_0001f39c();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_0001fa50;
      if (((uVar9 == 0) || (iVar2 = DAT_0001fa54, uVar9 == 1)) || (iVar2 = DAT_0001fa58, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_0001fa18:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}



/* Function: FUN_0001fa5c @ 0001fa5c */

void FUN_0001fa5c(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      FUN_000201dc(param_1 + 0x12);
    }
    else {
      FUN_000201ec();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_000201fc(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_0002020c(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_00020294(param_1 + 0x8c);
  return;
}



/* Function: FUN_0001fac8 @ 0001fac8 */

int FUN_0001fac8(code *param_1,undefined4 param_2,int param_3)

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
    iVar1 = FUN_0001f88c(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_0001fb84:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    FUN_0001f350(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_0001fb84;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_0001fa5c(&local_2c0);
  return iVar1;
}



/* Function: FUN_0001fb9c @ 0001fb9c */

int FUN_0001fb9c(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_0001f88c(param_1,local_228);
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
    FUN_000201c8(&local_264);
  }
  return 9;
}



/* Function: FUN_0001fcd4 @ 0001fcd4 */

void FUN_0001fcd4(int param_1,int param_2)

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
    iVar1 = FUN_0001f88c(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_0001fd20;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 != 7) {
LAB_0001fd20:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = FUN_000201c8(param_2 + 4);
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
    iVar2 = FUN_0001f88c(iVar1,local_228);
    if (iVar2 != 0) goto LAB_0001fdc4;
    iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&local_268);
  } while (iVar2 == 8);
  FUN_0001fa5c(&local_268);
  if (iVar2 == 6) {
    FUN_0001fcd4(iVar1,iVar3);
  }
LAB_0001fdc4:
                    /* WARNING: Could not recover jumptable at 0x0001fdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x1fd2c)(9);
  return;
}



/* Function: FUN_0001fe5c @ 0001fe5c */

undefined4 FUN_0001fe5c(uint *param_1,undefined4 param_2,uint param_3,int param_4)

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
        FUN_000201f4();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        FUN_000201e4(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_00020204(param_1 + 0x34);
    }
    if (bVar8) {
      FUN_000201e4(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_000201f4(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_0001fff8;
      FUN_00020204(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_0001fff8:
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
      FUN_000201dc(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_000201ec(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_000201fc(local_b0);
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
          FUN_00020250(param_1 + 0x6c);
        }
        FUN_00020250(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_0002020c(auStack_130);
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
        FUN_000202a8(param_1 + 0x8c);
      }
      FUN_000202a8(local_30);
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
      FUN_00020294(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: FUN_000201c8 @ 000201c8 */

undefined8 FUN_000201c8(undefined8 *param_1)

{
  return *param_1;
}



/* Function: FUN_000201dc @ 000201dc */

undefined4 FUN_000201dc(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_000201e4 @ 000201e4 */

void FUN_000201e4(undefined8 *param_1)

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



/* Function: FUN_000201ec @ 000201ec */

undefined4 FUN_000201ec(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_000201f4 @ 000201f4 */

void FUN_000201f4(undefined8 *param_1)

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



/* Function: FUN_000201fc @ 000201fc */

void FUN_000201fc(void)

{
  return;
}



/* Function: FUN_00020204 @ 00020204 */

void FUN_00020204(undefined8 *param_1)

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



/* Function: FUN_0002020c @ 0002020c */

int FUN_0002020c(int param_1)

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



/* Function: FUN_00020250 @ 00020250 */

int FUN_00020250(int param_1)

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



/* Function: FUN_00020294 @ 00020294 */

int FUN_00020294(int param_1)

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



/* Function: FUN_000202a8 @ 000202a8 */

int FUN_000202a8(int param_1)

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



/* Function: FUN_00020370 @ 00020370 */

uint FUN_00020370(uint *param_1)

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



/* Function: FUN_000203c8 @ 000203c8 */

void FUN_000203c8(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: FUN_00020410 @ 00020410 */

undefined4 FUN_00020410(void)

{
  int in_r3;
  
  FUN_0001f304();
  return *(undefined4 *)(in_r3 + 0x48);
}



/* Function: FUN_0002043c @ 0002043c */

undefined4 FUN_0002043c(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
LAB_00020454:
  do {
    while( true ) {
      uVar1 = FUN_00020370(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        FUN_0001f304(param_1,0,0xe,0,&local_24,uVar7,param_3);
        FUN_0001f350(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      FUN_0001f304(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_0002058c:
      piVar6 = &local_24;
      FUN_0001f350(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_00020370(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = FUN_0001fe5c(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_00020454;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      FUN_0001f304(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_0002058c;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_00020370(param_2);
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
          FUN_0001f304(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_00020370(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_0002058c;
        }
        if (uVar1 == 0xb3) {
          FUN_00020370(param_2);
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
        FUN_00020370(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_00020370(param_2);
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
            FUN_00020370(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_00020370(param_2);
          }
          goto LAB_00020790;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_00020790:
      uVar2 = 1;
    }
    iVar5 = FUN_0001fe5c(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: FUN_000207b4 @ 000207b4 */

void FUN_000207b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_0002043c(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}



/* Function: FUN_000207f4 @ 000207f4 */

undefined8 FUN_000207f4(uint param_1,uint param_2,uint param_3,uint param_4)

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
        param_3 = FUN_0002107c(1,0);
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
        FUN_00021128(uVar7,uVar2);
        iVar4 = FUN_0002107c(uVar7,uVar2);
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
        FUN_00021128(uVar10 - uVar7,uVar2);
        uVar2 = FUN_0002107c(uVar10 - uVar7,uVar2);
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
      FUN_00021128(iVar4,uVar2);
      iVar1 = FUN_0002107c(iVar4,uVar2);
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
      FUN_00021128(uVar9 - uVar7,uVar2);
      uVar7 = FUN_0002107c(uVar9 - uVar7,uVar2);
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
      goto LAB_00020c48;
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
    FUN_00021128(param_2,uVar2);
    iVar1 = FUN_0002107c(param_2,uVar2);
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
    FUN_00021128(uVar9 - uVar7,uVar2);
    uVar7 = FUN_0002107c(uVar9 - uVar7,uVar2);
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
LAB_00020c38:
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
        FUN_00021128(uVar7,uVar2);
        iVar3 = FUN_0002107c(uVar7,uVar2);
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
        FUN_00021128(uVar10 - uVar7,uVar2);
        uVar7 = FUN_0002107c(uVar10 - uVar7,uVar2);
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
           (uVar6 = 0, uVar5 + uVar9 <= param_1 << iVar4 || uVar7 != uVar10)) goto LAB_00020c48;
        uVar2 = uVar2 - 1;
        goto LAB_00020c38;
      }
      bVar12 = param_4 <= param_2;
      if (param_2 <= param_4) {
        bVar12 = param_3 <= param_1;
      }
      if (bVar12) {
        uVar2 = 1;
        uVar6 = 0;
        goto LAB_00020c48;
      }
    }
    uVar6 = 0;
    uVar2 = 0;
  }
LAB_00020c48:
  if (uVar8 != 0) {
    bVar12 = uVar2 != 0;
    uVar2 = -uVar2;
    uVar6 = -(uVar6 + bVar12);
  }
  return CONCAT44(uVar6,uVar2);
}



/* Function: FUN_00020c70 @ 00020c70 */

undefined8 FUN_00020c70(uint param_1,uint param_2,uint param_3,uint param_4)

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
        param_3 = FUN_0002107c(1,0);
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
        FUN_00021128(uVar5,uVar7);
        iVar3 = FUN_0002107c(uVar5,uVar7);
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
        FUN_00021128(uVar5 - uVar4,uVar7);
        uVar7 = FUN_0002107c(uVar5 - uVar4,uVar7);
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
      FUN_00021128(iVar3,uVar7);
      iVar1 = FUN_0002107c(iVar3,uVar7);
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
      FUN_00021128(uVar6 - uVar5,uVar7);
      uVar5 = FUN_0002107c(uVar6 - uVar5,uVar7);
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
      goto LAB_0002106c;
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
    FUN_00021128(uVar6,uVar4,uVar7,iVar3,param_1,param_2,param_3);
    iVar1 = FUN_0002107c(uVar6,uVar4);
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
    FUN_00021128(uVar6 - uVar7,uVar4);
    uVar6 = FUN_0002107c(uVar6 - uVar7,uVar4);
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
LAB_0002105c:
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
        FUN_00021128(uVar5,uVar7,uVar4,uVar6,param_1,param_2,param_3);
        iVar1 = extraout_r1_05;
        iVar2 = FUN_0002107c(uVar5,uVar7);
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
        FUN_00021128(uVar6 - uVar5,uVar7);
        iVar2 = extraout_r1_06;
        uVar5 = FUN_0002107c(uVar6 - uVar5,uVar7);
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
           (uVar8 = 0, uVar9 + uVar6 <= param_1 << iVar3 || uVar5 != uVar4)) goto LAB_0002106c;
        uVar7 = uVar7 - 1;
        goto LAB_0002105c;
      }
      bVar10 = param_4 <= param_2;
      if (param_2 <= param_4) {
        bVar10 = param_3 <= param_1;
      }
      if (bVar10) {
        uVar7 = 1;
        uVar8 = 0;
        goto LAB_0002106c;
      }
    }
    uVar8 = 0;
    uVar7 = 0;
  }
LAB_0002106c:
  return CONCAT44(uVar8,uVar7);
}



/* Function: _FINI_1 @ 00020f60 */

uint _FINI_1(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int extraout_r1;
  uint uVar4;
  uint uVar5;
  int in_r3;
  uint uVar6;
  uint uVar7;
  uint unaff_r4;
  int unaff_r5;
  uint uVar8;
  int unaff_r6;
  uint unaff_r7;
  uint unaff_r8;
  int iVar9;
  int unaff_r11;
  uint uVar10;
  bool bVar11;
  int iStack00000004;
  
  iStack00000004 = in_r3;
  iVar2 = FUN_0002107c();
  uVar6 = unaff_r4 >> 0x10 | iStack00000004 << 0x10;
  uVar8 = unaff_r5 << (unaff_r8 & 0xff);
  uVar3 = unaff_r11 * iVar2;
  iVar9 = iVar2;
  if (uVar6 < uVar3) {
    bVar11 = CARRY4(uVar6,unaff_r7);
    uVar6 = uVar6 + unaff_r7;
    iVar9 = iVar2 + -1;
    if ((!bVar11) && (uVar6 < uVar3)) {
      iVar9 = iVar2 + -2;
      uVar6 = uVar6 + unaff_r7;
    }
  }
  FUN_00021128(uVar6 - uVar3);
  iStack00000004 = extraout_r1;
  uVar6 = FUN_0002107c(uVar6 - uVar3);
  uVar7 = unaff_r4 & 0xffff | iStack00000004 << 0x10;
  uVar4 = unaff_r11 * uVar6;
  uVar3 = uVar6;
  if (uVar7 < uVar4) {
    bVar11 = CARRY4(uVar7,unaff_r7);
    uVar7 = uVar7 + unaff_r7;
    uVar3 = uVar6 - 1;
    if ((!bVar11) && (uVar7 < uVar4)) {
      uVar7 = uVar7 + unaff_r7;
      uVar3 = uVar6 - 2;
    }
  }
  uVar3 = uVar3 | iVar9 << 0x10;
  uVar6 = uVar3 >> 0x10;
  uVar1 = uVar8 >> 0x10;
  uVar10 = uVar3 & ~(uVar6 << 0x10);
  uVar8 = uVar8 & ~(uVar1 << 0x10);
  uVar5 = uVar10 * uVar8;
  uVar8 = uVar6 * uVar8;
  uVar10 = uVar1 * uVar10;
  iVar9 = uVar6 * uVar1;
  uVar6 = uVar8 + uVar10;
  if (CARRY4(uVar8,uVar10)) {
    iVar9 = iVar9 + 0x10000;
  }
  uVar8 = uVar6 * 0x10000;
  uVar6 = iVar9 + (uVar6 >> 0x10) + (uint)CARRY4(uVar5,uVar8);
  if ((uVar7 - uVar4 < uVar6) ||
     ((uint)(unaff_r6 << (unaff_r8 & 0xff)) < uVar5 + uVar8 && uVar6 == uVar7 - uVar4)) {
    uVar3 = uVar3 - 1;
  }
  return uVar3;
}



/* Function: FUN_0002107c @ 0002107c */

uint FUN_0002107c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    FUN_0001f26c();
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



/* Function: FUN_00021128 @ 00021128 */

void FUN_00021128(void)

{
  FUN_0002107c();
  return;
}



/* Function: putchar @ 00029000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: printf @ 00029004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memmove @ 00029008 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_begin_cleanup @ 00029010 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: qsort @ 00029014 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void qsort(void *__base,size_t __nmemb,size_t __size,__compar_fn_t __compar)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 00029018 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 0002901c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_finalize @ 00029020 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getuid @ 00029024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 00029028 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtoul @ 0002902c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fflush @ 00029030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncasecmp @ 00029034 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 00029038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 0002903c */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: calloc @ 00029040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * calloc(size_t __nmemb,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: modf @ 00029048 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double modf(double __x,double *__iptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fseek @ 0002904c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strstr @ 00029050 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncmp @ 00029054 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncpy @ 00029058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcasecmp @ 0002905c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcasecmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 00029060 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: realloc @ 00029064 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcmp @ 00029068 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fread @ 0002906c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fopen @ 00029070 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 00029074 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ftell @ 00029078 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long ftell(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fclose @ 0002907c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 00029080 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 00029084 */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sprintf @ 00029088 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: localtime_r @ 0002908c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime_r(time_t *__timer,tm *__tp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fwrite @ 00029090 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 0002909c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strchr @ 000290a0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_atexit @ 000290a4 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: raise @ 000290a8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 000290ac */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



