/* Function: munmap @ 00011004 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munmap(void *__addr,size_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_munmap_00015f90)(__addr);
  return iVar1;
}



/* Function: __errno @ 00011010 */

void __errno(void)

{
  (*(code *)PTR___errno_00015f94)();
  return;
}



/* Function: __cxa_begin_cleanup @ 0001101c */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_00015f98)();
  return;
}



/* Function: memcpy @ 00011028 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00015f9c)(__dest);
  return pvVar1;
}



/* Function: __android_log_vprint @ 00011040 */

void __android_log_vprint(void)

{
  (*(code *)PTR___android_log_vprint_00015fa4)();
  return;
}



/* Function: operator.delete @ 0001104c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1)

{
  (*(code *)PTR_operator_delete_00015fa8)(param_1);
  return;
}



/* Function: mmap @ 00011058 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_mmap_00015fac)(__addr);
  return pvVar1;
}



/* Function: abort @ 00011064 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_00015fb0)();
  return;
}



/* Function: strrchr @ 00011070 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strrchr_00015fb4)(__s);
  return pcVar1;
}



/* Function: dlopen @ 0001107c */

void dlopen(void)

{
  (*(code *)PTR_dlopen_00015fb8)();
  return;
}



/* Function: __cxa_type_match @ 00011088 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_00015fbc)();
  return;
}



/* Function: strcmp @ 000110a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00015fc4)(__s1);
  return iVar1;
}



/* Function: __gnu_Unwind_Find_exidx @ 000110ac */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_00015fc8)();
  return;
}



/* Function: sprintf @ 000110b8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sprintf_00015fcc)(__s);
  return iVar1;
}



/* Function: operator.new @ 000110c4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new_00015fd0)(param_1);
  return pvVar1;
}



/* Function: mprotect @ 000110d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mprotect_00015fd4)(__addr);
  return iVar1;
}



/* Function: raise @ 000110dc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_raise_00015fd8)(__sig);
  return iVar1;
}



/* Function: entry @ 000110e8 */

void processEntry entry(undefined4 param_1)

{
  (*(code *)PTR___cxa_atexit_00015fc0)(param_1,0,(int)&DAT_000110f8 + DAT_000110f8);
  return;
}



/* Function: _FINI_0 @ 000110fc */

void _FINI_0(void)

{
  (*(code *)PTR___cxa_finalize_00015fa0)((int)&DAT_00011108 + DAT_00011108);
  return;
}



/* Function: MSGetImageByName @ 0001110c */

char * MSGetImageByName(char *param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(DAT_000111a0 + 0x11120);
  if (*piVar3 == 0) {
    iVar2 = dlopen(DAT_000111a8 + 0x11198,3);
    *piVar3 = iVar2;
  }
  if (param_1 != (char *)0x0) {
    pcVar1 = strrchr(param_1,0x2f);
    if (pcVar1 != (char *)0x0) {
      param_1 = pcVar1 + 1;
    }
    for (pcVar1 = *(char **)(DAT_000111a4 + 0x11158); pcVar1 != (char *)0x0;
        pcVar1 = *(char **)(pcVar1 + 0xa4)) {
      iVar2 = strcmp(pcVar1,param_1);
      if (iVar2 == 0) {
        return pcVar1;
      }
    }
  }
  return (char *)0x0;
}



/* Function: MSFindSymbol @ 000111ac */

int MSFindSymbol(int param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  int extraout_r1;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = (uint)*param_2;
  if (uVar5 == 0) {
    iVar6 = 0;
  }
  else {
    uVar1 = 0;
    pbVar3 = param_2;
    do {
      uVar1 = uVar5 + uVar1 * 0x10;
      pbVar3 = pbVar3 + 1;
      uVar5 = (uint)*pbVar3;
      uVar4 = uVar1 & 0xf0000000;
      uVar1 = uVar4 ^ uVar1 ^ uVar4 >> 0x18;
    } while (uVar5 != 0);
    __aeabi_uidivmod(uVar1,*(undefined4 *)(param_1 + 0xb4),uVar4);
    iVar6 = extraout_r1 << 2;
  }
  iVar8 = *(int *)(param_1 + 0xb0);
  iVar9 = *(int *)(param_1 + 0xac);
  iVar6 = *(int *)(*(int *)(param_1 + 0xbc) + iVar6);
  while( true ) {
    if (iVar6 == 0) {
      return 0;
    }
    iVar7 = iVar8 + iVar6 * 0x10;
    if ((*(short *)(iVar7 + 0xe) != 0) &&
       (iVar2 = strcmp((char *)param_2,(char *)(iVar9 + *(int *)(iVar8 + iVar6 * 0x10))), iVar2 == 0
       )) break;
    iVar6 = *(int *)(*(int *)(param_1 + 0xc0) + iVar6 * 4);
  }
  return *(int *)(param_1 + 0x8c) + *(int *)(iVar7 + 4);
}



/* Function: MSCloseFunction @ 00011260 */

undefined4 * MSCloseFunction(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar3 = mmap((void *)0x0,0x30,3,0x22,-1,0);
  if (puVar3 == (undefined4 *)0xffffffff) {
    puVar3 = (undefined4 *)__errno();
    MSLog(2,DAT_0001138c + 0x1133c,*puVar3);
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[2] = 0xe92d4000;
    uVar1 = DAT_00011374;
    iVar4 = DAT_00011370;
    puVar3[10] = param_2;
    puVar3[3] = iVar4;
    puVar3[4] = iVar4 + 0x3121008;
    puVar3[5] = iVar4 + 0x312c008;
    uVar2 = DAT_00011378;
    *puVar3 = uVar1;
    uVar1 = DAT_0001137c;
    puVar3[6] = uVar2;
    uVar2 = DAT_00011380;
    puVar3[1] = uVar1;
    puVar3[0xb] = param_1;
    puVar3[7] = uVar2;
    puVar3[8] = DAT_00011384;
    puVar3[9] = DAT_00011388;
    iVar4 = mprotect(puVar3,0x30,5);
    if (iVar4 == -1) {
      puVar5 = (undefined4 *)__errno(0xffffffff);
      MSLog(2,DAT_00011390 + 0x1135c,*puVar5);
      munmap(puVar3,0x30);
      puVar3 = (undefined4 *)0x0;
    }
  }
  return puVar3;
}



/* Function: MSLogHexEx @ 00011394 */

/* MSLogHexEx(void const*, unsigned int, unsigned int, char const*) */

void MSLogHexEx(void *param_1,uint param_2,uint param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  void *__src;
  uint uVar8;
  char *__format;
  char *__format_00;
  uint local_140;
  char local_128 [52];
  char acStack_f4 [208];
  
  iVar7 = DAT_00011694;
  if (param_2 != 0) {
    iVar6 = 0;
    local_128[0] = '\0';
    pcVar4 = (char *)(DAT_00011690 + 0x113d8);
    __format = (char *)(DAT_00011698 + 0x113e4);
    __format_00 = (char *)(DAT_0001169c + 0x113e8);
    uVar8 = 0;
    local_140 = 0;
    do {
      if (local_140 == 0) {
        if (param_4 != (char *)0x0) {
          iVar1 = sprintf(local_128 + iVar6,(char *)(iVar7 + 0x11414),param_4);
          iVar6 = iVar6 + iVar1;
        }
        iVar1 = sprintf(local_128 + iVar6,pcVar4,uVar8);
        iVar6 = iVar6 + iVar1;
      }
      iVar1 = 0;
      local_128[iVar6] = ' ';
      local_128[iVar6 + 1] = '\0';
      iVar6 = iVar6 + 1;
      if (param_3 == 0) {
LAB_0001149c:
        uVar3 = 1;
        iVar1 = iVar6;
        do {
          uVar3 = uVar3 + 1;
          local_128[iVar1] = ' ';
          local_128[iVar1 + 1] = '\0';
          iVar1 = iVar1 + 1;
        } while (uVar3 != param_3);
        iVar6 = param_3 + iVar6 + -1;
      }
      else {
        do {
          iVar2 = sprintf(local_128 + iVar6,__format,
                          (uint)*(byte *)((int)param_1 + iVar1 + (param_3 - 1) + uVar8));
          iVar1 = iVar1 + -1;
          iVar6 = iVar6 + iVar2;
        } while (param_3 + iVar1 != 0);
        uVar8 = uVar8 + param_3;
        if (param_3 != 1) {
          local_140 = uVar8 & 0xf;
          goto LAB_0001149c;
        }
        local_140 = uVar8 & 0xf;
      }
      if ((uVar8 & 3) == 0) {
        local_128[iVar6] = ' ';
        local_128[iVar6 + 1] = '\0';
        iVar6 = iVar6 + 1;
      }
      if (local_140 == 0) {
        local_128[iVar6] = ' ';
        local_128[iVar6 + 1] = '\0';
        iVar6 = iVar6 + 1;
        pbVar5 = (byte *)((int)param_1 + (uVar8 - 0x10));
        while( true ) {
          uVar3 = (uint)*pbVar5;
          if (0x5f < uVar3 - 0x20) {
            uVar3 = 0x2e;
          }
          iVar1 = sprintf(local_128 + iVar6,__format_00,uVar3);
          if (pbVar5 + 1 == (byte *)((int)param_1 + uVar8)) break;
          iVar6 = iVar6 + iVar1;
          pbVar5 = pbVar5 + 1;
        }
        iVar6 = 0;
        MSLog(0,DAT_000116ac + 0x11684,local_128);
        local_128[0] = '\0';
      }
    } while (uVar8 != param_2);
    if (local_140 != 0) {
      __src = (void *)(DAT_000116a0 + 0x11520);
      uVar3 = local_140;
      iVar7 = iVar6;
      do {
        uVar3 = uVar3 + 1;
        memcpy(local_128 + iVar7,__src,4);
        iVar7 = iVar7 + 3;
      } while (uVar3 != 0x10);
      iVar6 = ~local_140 * 3 + 0x33 + iVar6;
      uVar3 = 0;
      iVar7 = iVar6;
      do {
        uVar3 = uVar3 + 1;
        local_128[iVar7] = ' ';
        local_128[iVar7 + 1] = '\0';
        iVar7 = iVar7 + 1;
      } while (uVar3 != 0x13 - local_140 >> 2);
      iVar6 = iVar6 + uVar3;
      local_128[iVar6] = ' ';
      acStack_f4[iVar6 + -0x33] = '\0';
      if (uVar8 != (uVar8 & 0xfffffff0)) {
        iVar6 = iVar6 + 1;
        pbVar5 = (byte *)((int)param_1 + (uVar8 & 0xfffffff0));
        pcVar4 = (char *)(DAT_000116a4 + 0x115cc);
        while( true ) {
          uVar8 = (uint)*pbVar5;
          if (0x5f < uVar8 - 0x20) {
            uVar8 = 0x2e;
          }
          iVar7 = sprintf(local_128 + iVar6,pcVar4,uVar8);
          if (pbVar5 == (byte *)((int)param_1 + (param_2 - 1))) break;
          iVar6 = iVar6 + iVar7;
          pbVar5 = pbVar5 + 1;
        }
      }
      MSLog(0,DAT_000116a8 + 0x11610,local_128);
    }
  }
  return;
}



/* Function: MSLogHex @ 000116b0 */

/* MSLogHex(void const*, unsigned int, char const*) */

void MSLogHex(void *param_1,uint param_2,char *param_3)

{
  MSLogHexEx(param_1,param_2,1,param_3);
  return;
}



/* Function: MSGetInstructionWidth @ 000116bc */

undefined4 MSGetInstructionWidth(uint param_1)

{
  if (((param_1 & 1) != 0) &&
     (((*(ushort *)(param_1 & 0xfffffffe) & 0xe000) != 0xe000 ||
      ((*(ushort *)(param_1 & 0xfffffffe) & 0x1800) == 0)))) {
    return 2;
  }
  return 4;
}



/* Function: FUN_000116f0 @ 000116f0 */

void FUN_000116f0(undefined4 param_1,short *param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  short sVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  void *__addr;
  uint *puVar6;
  undefined4 *puVar7;
  int iVar8;
  short *psVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  void *__dest;
  int iVar14;
  ushort uVar15;
  uint uVar16;
  ushort uVar17;
  uint uVar18;
  int iVar19;
  undefined2 uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  ushort *puVar24;
  bool bVar25;
  int local_c0;
  __off_t _Stack_bc;
  ushort auStack_b8 [2];
  void *local_b4;
  void *local_b0;
  void *local_ac;
  void *local_a8;
  uint local_a4;
  void *local_a0;
  void *local_9c;
  uint *local_98;
  uint local_94;
  uint *local_90;
  short *local_8c;
  undefined4 local_88;
  uint *local_84;
  undefined1 *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int *local_6c;
  short *local_68;
  uint local_64;
  int local_60;
  size_t local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  short *local_4c;
  size_t local_48;
  uint *local_44;
  int local_40;
  uint *local_3c;
  char acStack_38 [20];
  
  iVar8 = DAT_0001268c;
  local_80 = (undefined1 *)&local_c0;
  local_40 = DAT_00012688 + 0x1170c;
  if (param_2 == (short *)0x0) {
    return;
  }
  local_58 = (uint)param_2 >> 1 & 1;
  local_68 = (short *)(local_58 * 2);
  local_4c = param_2 + local_58;
  local_54 = (int)local_4c + (0xc - (int)param_2) & 0xfffffffe;
  local_8c = local_4c + 2;
  local_88 = param_3;
  local_6c = param_4;
  if (local_58 == 0) {
    sVar2 = *param_2;
  }
  else {
    if (*param_2 != 0x46c0) goto LAB_00011774;
    sVar2 = param_2[local_58];
  }
  if (((sVar2 == 0x4778) && (local_4c[1] == 0x46c0)) && (*(uint *)(local_4c + 2) == DAT_00012690)) {
    psVar9 = local_68;
    if (param_4 != (int *)0x0) {
      psVar9 = local_8c;
    }
    local_60 = DAT_0001268c;
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(psVar9 + 2);
    }
    piVar4 = &local_c0;
    if (**(char **)(local_40 + iVar8) != '\0') {
      sprintf(acStack_38,(char *)(DAT_000126c4 + 0x1266c),param_2);
      MSLogHexEx(param_2,local_54,4,acStack_38);
      piVar4 = (int *)local_80;
    }
    local_80 = (undefined1 *)piVar4;
    psVar9 = local_8c;
    iVar8 = SubstrateMemoryCreate(0,0,local_8c + 2,4);
    *(undefined4 *)(psVar9 + 2) = local_88;
    if (iVar8 != 0) {
      SubstrateMemoryRelease();
    }
    if (**(char **)(local_40 + local_60) == '\0') {
      return;
    }
    sprintf(acStack_38,(char *)(DAT_000126b4 + 0x121dc),param_2);
    MSLogHexEx(param_2,local_54,4,acStack_38);
    return;
  }
LAB_00011774:
  if (local_54 == 0) {
    iVar8 = 0;
    uVar12 = 0;
    local_48 = 0;
  }
  else {
    local_48 = 0;
    do {
      while( true ) {
        iVar8 = 2;
        if ((*(ushort *)((int)param_2 + local_48) & 0xe000) != 0xe000) break;
        if ((*(ushort *)((int)param_2 + local_48) & 0x1800) != 0) {
          iVar8 = 4;
        }
        local_48 = local_48 + iVar8;
        if (local_54 <= local_48) goto LAB_000117cc;
      }
      local_48 = local_48 + 2;
    } while (local_48 < local_54);
LAB_000117cc:
    uVar12 = local_48 + 1 >> 1;
    iVar8 = uVar12 << 1;
  }
  iVar8 = -(iVar8 + 0xeU & 0xfffffff8);
  __dest = (void *)((int)auStack_b8 + iVar8);
  local_60 = DAT_0001268c;
  local_80 = (undefined1 *)&local_c0;
  memcpy(__dest,param_2,local_48);
  if (**(char **)(local_40 + local_60) != '\0') {
    sprintf(acStack_38,(char *)(DAT_000126a0 + 0x11ef4),param_2);
    MSLogHexEx(param_2,local_48 + 2,2,acStack_38);
  }
  if (local_6c != (int *)0x0) {
    uVar5 = local_48;
    if (uVar12 == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = 0;
      do {
        while( true ) {
          uVar15 = *(ushort *)((int)__dest + uVar13 * 2);
          uVar10 = uVar15 & 0xf800;
          if (uVar10 != 0x4800) break;
          uVar5 = uVar5 + 6;
joined_r0x00011c88:
          uVar13 = uVar13 + 1;
joined_r0x00011ed8:
          if (uVar13 == uVar12) goto LAB_000118c4;
        }
        if ((((uVar15 & 0xf000) == 0xd000) && ((uVar15 & 0xe00) != 0xe00)) || (uVar10 == 0xe000)) {
LAB_00011c7c:
          uVar5 = uVar5 + 0xc;
          goto joined_r0x00011c88;
        }
        if (uVar10 == 0xf000) {
          uVar10 = *(ushort *)((int)__dest + uVar13 * 2 + 2);
          uVar17 = uVar10 & 0xd000;
          if (uVar17 != 0x9000) {
            if (uVar17 == 0x8000) {
              if ((uVar15 & 0x300) == 0x300) goto LAB_00011eb4;
            }
            else if (uVar17 != 0xd000) {
LAB_00011eb4:
              if ((uVar10 & 0xd001) != 0xc000) goto LAB_00011880;
            }
          }
          uVar13 = uVar13 + 2;
          uVar5 = uVar5 + 10;
          goto joined_r0x00011ed8;
        }
LAB_00011880:
        if ((uVar15 & 0xf500) != 0xb100) {
          if ((uVar15 & 0xff7f) == 0xf85f) {
            uVar5 = uVar5 + 8;
            uVar13 = uVar13 + 1;
          }
          else {
            if ((uVar15 & 0xff78) == 0x4478) goto LAB_00011c7c;
            if (((uVar15 & 0xe000) == 0xe000) && ((uVar15 & 0x1800) != 0)) {
              uVar13 = uVar13 + 1;
            }
          }
          goto joined_r0x00011c88;
        }
        uVar13 = uVar13 + 1;
        uVar5 = uVar5 + 0x20;
      } while (uVar13 != uVar12);
    }
LAB_000118c4:
    local_64 = uVar5 >> 1 & 1;
    local_5c = uVar5 + (local_64 + 6) * 2;
    *(undefined4 *)((int)&local_c0 + iVar8) = 0xffffffff;
    *(undefined4 *)((int)&_Stack_bc + iVar8) = 0;
    __addr = mmap((void *)0x0,local_5c,3,0x22,*(int *)((int)&local_c0 + iVar8),
                  *(__off_t *)((int)&_Stack_bc + iVar8));
    if (__addr == (void *)0xffffffff) {
      puVar7 = (undefined4 *)__errno();
      MSLog(2,DAT_000126bc + 0x12614,*puVar7);
      *local_6c = 0;
      return;
    }
    uVar12 = local_64;
    if (uVar13 == 0) {
      iVar8 = 0;
    }
    else {
      uVar5 = local_5c >> 1;
      local_70 = 0xbc40;
      local_78 = 0xf386;
      uVar11 = 0;
      local_74 = 0xb440;
      local_7c = 0xf387;
      puVar6 = (uint *)((int)__addr + uVar5 * 2);
      do {
        while( true ) {
          puVar3 = DAT_000126ac;
          iVar8 = uVar11 * 2;
          uVar15 = *(ushort *)((int)__dest + iVar8);
          uVar21 = (uint)uVar15;
          uVar18 = uVar21 & 0xf800;
          if (uVar18 == 0x4800) {
            iVar8 = 0;
            if ((uVar12 & 1) != 0) {
              iVar8 = 2;
            }
            uVar18 = uVar15 >> 8 & 7;
            local_3c = (uint *)((uint)(param_2 + uVar11 + 2) & 0xfffffffd);
            *(ushort *)((int)__addr + uVar12 * 2) =
                 (ushort)(uVar18 << 8) | 0x4800 |
                 (ushort)(byte)((iVar8 + ((uVar5 + 0x7ffffffc) - uVar12) * 2) * 0x400000 >> 0x18);
            puVar6 = puVar6 + -1;
            *puVar6 = (uint)((uint *)((uint)(param_2 + uVar11 + 2) & 0xfffffffd) + (uVar21 & 0xff));
            *(ushort *)((int)__addr + uVar12 * 2 + 2) =
                 (ushort)uVar18 | 0x6800 | (ushort)(uVar18 << 3);
            uVar12 = uVar12 + 2;
            uVar5 = uVar5 - 2;
            goto LAB_000119b8;
          }
          if (((uVar21 & 0xf000) != 0xd000) || ((uVar21 & 0xe00) == 0xe00)) break;
          uVar16 = uVar15 >> 8 & 0xf;
          bVar25 = uVar16 != 0xe;
          uVar18 = (uVar5 + 0x7ffffff8) - uVar12;
          if (bVar25) {
            uVar18 = uVar18 & 0xff;
          }
          if (bVar25) {
            uVar18 = uVar18 | uVar16 << 8;
          }
          if (!bVar25) {
            uVar18 = uVar18 << 0x15;
          }
          puVar6[-1] = (int)param_2 + ((int)(uVar21 << 0x18 | 0x800000) >> 0x17) + 4 + iVar8;
          uVar21 = DAT_00012690;
          if (!bVar25) {
            uVar18 = uVar18 >> 0x15;
          }
          if (bVar25) {
            uVar15 = (ushort)uVar18 | 0xd000;
          }
          else {
            uVar15 = (ushort)uVar18 | 0xe000;
          }
          *(ushort *)((int)__addr + uVar12 * 2) = uVar15;
          puVar6[-2] = uVar21;
LAB_000119a4:
          uVar12 = uVar12 + 1;
          uVar5 = uVar5 - 6;
          puVar6[-3] = DAT_00012694;
          puVar6 = puVar6 + -3;
LAB_000119b8:
          uVar11 = uVar11 + 1;
          if (uVar13 == uVar11) goto LAB_00011a4c;
        }
        if (uVar18 == 0xe000) {
          puVar6[-2] = DAT_00012690;
          *(ushort *)((int)__addr + uVar12 * 2) =
               ~((ushort)~(ushort)((((uVar5 + 0x7ffffff8) - uVar12 & 0x7ff) << 0x13) >> 0x10) >> 3);
          puVar6[-1] = (int)param_2 + ((int)(uVar21 << 0x15 | 0x100000) >> 0x14) + 4 + iVar8;
          goto LAB_000119a4;
        }
        if (uVar18 == 0xf000) {
          uVar10 = *(ushort *)((int)__dest + iVar8 + 2);
          uVar17 = uVar10 & 0xd000;
          if (uVar17 == 0x9000) {
LAB_000122d0:
            uVar11 = uVar11 + 1;
            uVar10 = *(ushort *)((int)__dest + uVar11 * 2);
            uVar18 = (uint)uVar10;
            local_3c = (uint *)((uVar21 & 0x3f) << 0xc | (uVar18 & 0x7ff) << 1 | 1);
            if ((uVar10 & 0x1000) == 0) {
              local_84 = (uint *)(uVar18 << 5);
              local_50 = (uVar21 & 0x400) << 10;
              local_44 = (uint *)((uVar18 & 0x800) << 8 | local_50);
              puVar24 = (ushort *)((int)__addr + uVar12 * 2);
              iVar19 = (int)(((uint)local_44 | uVar18 << 5 & 0x40000 | (uint)local_3c) << 0xb) >>
                       0xb;
              if ((uVar21 & 0x3c0) == 0x380) goto LAB_00012364;
              uVar15 = (ushort)((uVar21 & 0x3c0) << 2) | 0xd000 |
                       ((short)uVar5 + -8) - (short)uVar12 & 0xffU;
            }
            else {
              uVar16 = uVar15 >> 10 & 1;
              local_44 = (uint *)(uVar18 << 0x14);
              local_3c = (uint *)((uint)local_3c | uVar16 << 0x18);
              if (uVar16 == -((int)(uVar18 << 0x12) >> 0x1f)) {
                uVar22 = 0x800000;
              }
              else {
                uVar22 = 0;
              }
              if (uVar16 == -((int)(uVar18 << 0x14) >> 0x1f)) {
                uVar18 = 0x400000;
              }
              else {
                uVar18 = 0;
              }
              puVar24 = (ushort *)((int)__addr + uVar12 * 2);
              iVar19 = (int)(((uint)local_3c | uVar22 | uVar18 | (uVar21 & 0x3c0) << 0xc) << 7) >> 7
              ;
LAB_00012364:
              uVar15 = ((short)uVar5 + -8) - (short)uVar12 & 0x7ffU | 0xe000;
            }
            puVar6[-1] = (int)param_2 + iVar19 + iVar8 + 4;
            uVar18 = DAT_00012690;
            *puVar24 = uVar15;
            puVar6[-2] = uVar18;
            goto LAB_000119a4;
          }
          if (uVar17 == 0x8000) {
            if ((uVar21 & 0x300) != 0x300) goto LAB_000122d0;
LAB_00011cb4:
            if ((uVar10 & 0xd001) != 0xc000) goto LAB_000119f4;
          }
          else if (uVar17 != 0xd000) goto LAB_00011cb4;
          uVar11 = uVar11 + 1;
          uVar18 = (uint)*(ushort *)((int)__dest + uVar11 * 2);
          uVar16 = uVar15 >> 10 & 1;
          if (uVar16 == -((int)(uVar18 << 0x12) >> 0x1f)) {
            uVar22 = 0x800000;
          }
          else {
            uVar22 = 0;
          }
          if (uVar16 == -((int)(uVar18 << 0x14) >> 0x1f)) {
            uVar23 = 0x400000;
          }
          else {
            uVar23 = 0;
          }
          local_94 = (int)param_2 +
                     ((int)((uVar22 | uVar16 << 0x18 | uVar23 | (uVar21 & 0x3ff) << 0xc |
                             (uVar18 & 0x7ff) << 1 | (uVar18 & 0x1fff) >> 0xc) << 7) >> 7) +
                     iVar8 + 4;
          local_50 = (uVar5 - uVar12) + 0x7ffffffc >> 1 & 0xff | 0x4f00;
          local_9c = (void *)0x47f0;
          local_3c = (uint *)(uVar12 * 2);
          local_44 = (uint *)((int)__addr + uVar12 * 2);
          local_84 = local_44;
          local_90 = local_44;
          local_98 = local_44;
          *(undefined2 *)((int)__addr + (int)(uVar12 * 2)) = 0xb480;
          *(short *)((int)local_44 + 2) = (short)local_50;
          *(short *)(local_44 + 1) = 0x46be;
          *(short *)((int)local_44 + 6) = -0x4380;
          *(short *)(local_44 + 2) = 0x47f0;
          puVar6 = puVar6 + -1;
          *puVar6 = local_94;
          uVar12 = uVar12 + 5;
          uVar5 = uVar5 - 2;
          goto LAB_000119b8;
        }
LAB_000119f4:
        if ((uVar21 & 0xf500) == 0xb100) {
          uVar18 = ((uVar5 + 0x7ffffff1) - uVar12) * 2;
          local_44 = puVar6 + -1;
          local_3c = puVar6 + -2;
          bVar25 = (uVar21 & 7) != 7;
          local_50 = DAT_000126a4;
          if (bVar25) {
            local_50 = DAT_000126a8;
          }
          local_98 = (uint *)0xb440;
          if (bVar25) {
            local_98 = (uint *)0xb480;
          }
          local_a4 = uVar21 & 0x800 | 0xffffb100 | ((uVar18 & 0x40) >> 6) << 9 |
                     (uVar18 & 0x3e) << 2 | uVar21 & 7;
          uVar5 = uVar5 - 10;
          puVar6[-1] = (int)param_2 + (uVar15 >> 3 & 0x40 | uVar15 >> 2 & 0x3e | 1) + 4 + iVar8;
          uVar18 = DAT_00012690;
          local_90 = DAT_000126b0;
          local_94 = 0xbc40;
          if (bVar25) {
            local_90 = puVar3;
            local_94 = 0xbc80;
          }
          local_b4 = (void *)((int)__addr + uVar12 * 2);
          local_9c = local_b4;
          local_a0 = local_b4;
          local_a8 = local_b4;
          local_ac = local_b4;
          local_b0 = local_b4;
          local_84 = (uint *)0xf386;
          if (bVar25) {
            local_84 = (uint *)0xf387;
          }
          *(short *)((int)__addr + uVar12 * 2) = (short)local_98;
          if (bVar25) {
            uVar20 = 0x8700;
          }
          else {
            uVar20 = 0x8600;
          }
          puVar6[-2] = uVar18;
          uVar12 = uVar12 + 7;
          puVar6[-3] = DAT_00012694;
          puVar6[-4] = (uint)local_90;
          *(undefined2 *)((int)local_b4 + 2) = 0xf3ef;
          *(undefined2 *)((int)local_b4 + 4) = uVar20;
          puVar6[-5] = local_50;
          *(short *)((int)local_b4 + 6) = (short)local_a4;
          *(short *)((int)local_b4 + 8) = (short)local_84;
          *(undefined2 *)((int)local_b4 + 10) = 0x8c00;
          puVar6 = puVar6 + -5;
          *(short *)((int)local_b4 + 0xc) = (short)local_94;
          goto LAB_000119b8;
        }
        if ((uVar21 & 0xffffff7f) == 0xf85f) {
          uVar10 = *(ushort *)((int)__dest + (uVar11 + 1) * 2);
          local_3c = (uint *)(uint)uVar10;
          iVar8 = 0;
          if ((uVar12 & 1) != 0) {
            iVar8 = 2;
          }
          local_50 = iVar8 + ((uVar5 + 0x7ffffffc) - uVar12) * 2;
          if ((int)local_50 < 0) {
            local_50 = -local_50;
          }
          uVar10 = uVar10 >> 0xc;
          uVar18 = (uint)uVar10 << 0xc;
          local_50 = local_50 | uVar18;
          local_44 = (uint *)((int)__addr + uVar12 * 2);
          local_84 = local_44;
          local_90 = local_44;
          *(undefined2 *)((int)__addr + uVar12 * 2) = 0xf8df;
          uVar12 = uVar12 + 4;
          *(ushort *)(local_44 + 1) = uVar10 | 0xf8d0;
          *(short *)((int)local_44 + 2) = (short)local_50;
          *(short *)((int)local_44 + 6) = (short)uVar18;
          uVar5 = uVar5 - 2;
          if ((uVar15 & 0x80) == 0) {
            uVar18 = -((uint)local_3c & 0xfff);
          }
          else {
            uVar18 = (uint)local_3c & 0xfff;
          }
          puVar6 = puVar6 + -1;
          *puVar6 = uVar18 + ((uint)(param_2 + uVar11 + 2) & 0xfffffffd);
          uVar11 = uVar11 + 1;
          goto LAB_000119b8;
        }
        if ((uVar21 & 0xffffff78) == 0x4478) {
          if ((uVar15 & 0x80) != 0) {
            MSLog(2,DAT_000126c0 + 0x1263c);
            munmap(__addr,local_5c);
            *local_6c = 0;
            return;
          }
          uVar18 = uVar21 & 7;
          bVar25 = (uVar21 & 7) != 7;
          local_3c = (uint *)(uVar12 + 2);
          local_90 = (uint *)0xb440;
          if (bVar25) {
            local_90 = (uint *)0xb480;
          }
          local_84 = (uint *)0xbc40;
          if (bVar25) {
            local_84 = (uint *)0xbc80;
          }
          if (bVar25) {
            uVar21 = 0x38;
            local_50 = 7;
          }
          else {
            uVar21 = 0x30;
            local_50 = 6;
          }
          iVar8 = 0;
          if (((uint)local_3c & 1) != 0) {
            iVar8 = 2;
          }
          iVar14 = uVar5 + 0x7ffffffa;
          uVar16 = (uVar15 >> 4 & 8) >> 3;
          uVar5 = uVar5 - 2;
          local_50 = local_50 | uVar16 << 6 | 0x4600 | uVar18 << 3;
          local_98 = (uint *)(param_2 + uVar11 + 2);
          iVar19 = uVar12 * 2;
          local_94 = uVar18 << 8 | 0x4800 | (iVar8 + (iVar14 - uVar12) * 2 & 0x3ff) >> 2;
          local_44 = (uint *)((int)__addr + uVar12 * 2);
          local_9c = (void *)(uVar21 | uVar18 | 0x4400 | uVar16 << 7);
          uVar12 = uVar12 + 5;
          *(short *)((int)__addr + iVar19) = (short)local_90;
          *(short *)((int)local_44 + 2) = (short)local_50;
          *(short *)((int)__addr + (int)local_3c * 2) = (short)local_94;
          *(short *)((int)local_44 + 6) = (short)local_9c;
          *(short *)(local_44 + 2) = (short)local_84;
          puVar6 = puVar6 + -1;
          *puVar6 = (uint)(param_2 + uVar11 + 2);
          goto LAB_000119b8;
        }
        if (((uVar21 & 0xe000) == 0xe000) && ((uVar15 & 0x1800) != 0)) {
          *(ushort *)((int)__addr + uVar12 * 2) = uVar15;
          *(undefined2 *)((int)__addr + (uVar12 + 1) * 2) =
               *(undefined2 *)((int)__dest + (uVar11 + 1) * 2);
          uVar12 = uVar12 + 2;
          uVar11 = uVar11 + 1;
          goto LAB_000119b8;
        }
        uVar11 = uVar11 + 1;
        *(ushort *)((int)__addr + uVar12 * 2) = uVar15;
        uVar12 = uVar12 + 1;
      } while (uVar13 != uVar11);
LAB_00011a4c:
      iVar8 = uVar13 << 1;
    }
    *(undefined2 *)((int)__addr + uVar12 * 2) = 0x4778;
    *(uint *)((int)__addr + (uVar12 + 2) * 2) = DAT_00012690;
    *(undefined2 *)((int)__addr + (uVar12 + 1) * 2) = 0x46c0;
    *(int *)((int)__addr + (uVar12 + 2) * 2 + 4) = (int)param_2 + iVar8 + 1;
    iVar8 = mprotect(__addr,local_5c,5);
    if (iVar8 == -1) {
      puVar7 = (undefined4 *)__errno();
      MSLog(2,DAT_000126b8 + 0x125ac,*puVar7);
      return;
    }
    cVar1 = **(char **)(local_40 + local_60);
    *local_6c = (int)__addr + local_64 * 2 + 1;
    if (cVar1 != '\0') {
      sprintf(acStack_38,(char *)(DAT_0001269c + 0x11e78));
      MSLogHexEx(__addr,local_5c,2,acStack_38);
    }
  }
  iVar8 = SubstrateMemoryCreate(0,0,param_2,local_48);
  if (local_58 != 0) {
    *param_2 = 0x46c0;
  }
  *(undefined2 *)((int)param_2 + (int)local_68) = 0x4778;
  *(uint *)(local_4c + 2) = DAT_00012690;
  uVar12 = local_48 - local_54 >> 1;
  *(undefined4 *)(local_8c + 2) = local_88;
  local_4c[1] = 0x46c0;
  if (uVar12 != 0) {
    uVar5 = 0;
    psVar9 = local_4c + 5;
    do {
      uVar5 = uVar5 + 1;
      psVar9 = psVar9 + 1;
      *psVar9 = 0x46c0;
    } while (uVar12 != uVar5);
  }
  if (iVar8 != 0) {
    SubstrateMemoryRelease();
  }
  if (**(char **)(local_40 + local_60) != '\0') {
    sprintf(acStack_38,(char *)(DAT_00012698 + 0x11e44),param_2);
    MSLogHexEx(param_2,local_48 + 2,2,acStack_38);
  }
  return;
}



/* Function: MSHookFunction @ 000126c8 */

void MSHookFunction(uint *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  size_t __len;
  void *__addr;
  uint uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  char *pcVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  bool bVar14;
  undefined4 *local_54;
  uint local_44;
  char acStack_40 [16];
  uint local_30;
  uint local_2c [2];
  
  iVar2 = DAT_00012ad0;
  iVar10 = DAT_00012acc + 0x126e0;
  if (**(char **)(iVar10 + DAT_00012ad0) != '\0') {
    MSLog(0,DAT_00012ae0 + 0x128a4,0,param_1,param_2,param_3);
  }
  if (((uint)param_1 & 1) == 0) {
    if (param_1 != (uint *)0x0) {
      uVar11 = *param_1;
      uVar12 = param_1[1];
      local_2c[0] = uVar12;
      local_30 = uVar11;
      if (**(char **)(iVar10 + iVar2) != '\0') {
        sprintf(acStack_40,(char *)(DAT_00012ae4 + 0x12a1c),param_1);
        MSLogHexEx(param_1,0xc,4,acStack_40);
      }
      if (param_3 != (uint *)0x0) {
        if (uVar11 != DAT_00012ad4) {
          puVar13 = &local_30;
          iVar3 = 8;
          uVar12 = uVar11;
          puVar6 = puVar13;
          while( true ) {
            if ((((uVar12 & 0xc000000) == 0x4000000) && ((uVar12 & 0xf0000000) != 0xf0000000)) &&
               ((uVar12 & 0xf0000) == 0xf0000)) {
              if ((uVar12 & 0x2000000) == 0) {
                iVar3 = iVar3 + 8;
              }
              else {
                iVar3 = iVar3 + 0x10;
              }
            }
            if (puVar6 == local_2c) break;
            puVar6 = puVar6 + 1;
            uVar12 = *puVar6;
          }
          __len = iVar3 + 8;
          __addr = mmap((void *)0x0,__len,3,0x22,-1,0);
          if (__addr == (void *)0xffffffff) {
            puVar5 = (undefined4 *)__errno();
            MSLog(2,DAT_00012aec + 0x12ac0,*puVar5);
            *param_3 = 0;
            return;
          }
          puVar8 = param_1 + 2;
          uVar12 = __len >> 2;
          local_54 = (undefined4 *)((int)__addr + uVar12 * 4);
          puVar6 = puVar8;
          iVar3 = 0;
          if ((uVar11 & 0xc000000) == 0x4000000) goto LAB_00012944;
          do {
            *(uint *)((int)__addr + iVar3 * 4) = uVar11;
            iVar9 = iVar3 + 1;
            while( true ) {
              puVar6 = puVar6 + 1;
              if (puVar13 == local_2c) {
                *(uint *)((int)__addr + iVar9 * 4) = DAT_00012ad4;
                *(uint **)((int)__addr + (iVar9 + 1) * 4) = puVar8;
                iVar3 = mprotect(__addr,__len,5);
                if (iVar3 == -1) {
                  puVar5 = (undefined4 *)__errno();
                  MSLog(2,DAT_00012ae8 + 0x12a50,*puVar5);
                  munmap(__addr,__len);
                  *param_3 = 0;
                  return;
                }
                pcVar7 = *(char **)(iVar10 + iVar2);
                *param_3 = (uint)__addr;
                if (*pcVar7 != '\0') {
                  sprintf(acStack_40,(char *)(DAT_00012ad8 + 0x12810),__addr);
                  MSLogHexEx(__addr,__len,4,acStack_40);
                }
                goto LAB_00012828;
              }
              puVar13 = puVar13 + 1;
              uVar11 = *puVar13;
              iVar3 = iVar9;
              if ((uVar11 & 0xc000000) != 0x4000000) break;
LAB_00012944:
              if (((uVar11 & 0xf0000000) == 0xf0000000) || ((uVar11 & 0xf0000) != 0xf0000)) break;
              if ((uVar11 & 0x2000000) == 0) {
                uVar4 = uVar11 >> 0xc & 0xf;
LAB_00012984:
                local_44 = uVar11 & 0xfff0ffff | uVar4 << 0x10;
                bVar14 = false;
              }
              else {
                uVar4 = uVar11 >> 0xc & 0xf;
                if (uVar4 != (uVar11 & 0xf)) goto LAB_00012984;
                bVar14 = 1 < uVar4;
                uVar4 = 1 - uVar4;
                if (bVar14) {
                  uVar4 = 0;
                }
                *(uint *)((int)__addr + iVar3 * 4) = 1 << (uVar4 & 0xff) | 0xe92d0000;
                local_44 = uVar11 & 0xfff0ffff | uVar4 << 0x10;
                iVar3 = iVar3 + 1;
                bVar14 = true;
              }
              uVar11 = ((uVar12 + 0x3ffffffd) - iVar3) * 4;
              uVar1 = (int)uVar11 >> 0x1f;
              *(uint *)((int)__addr + iVar3 * 4) =
                   uVar4 << 0xc | 0xe59f0000 | (uVar11 ^ uVar1) - uVar1;
              *(uint *)((int)__addr + (iVar3 + 1) * 4) = local_44;
              iVar9 = iVar3 + 2;
              if (bVar14) {
                *(uint *)((int)__addr + iVar9 * 4) = 1 << (uVar4 & 0xff) | 0xe8bd0000;
                iVar9 = iVar3 + 3;
              }
              uVar12 = uVar12 - 1;
              local_54 = local_54 + -1;
              *local_54 = puVar6;
            }
          } while( true );
        }
        *param_3 = uVar12;
      }
LAB_00012828:
      iVar3 = SubstrateMemoryCreate(0,0,param_1,8);
      *param_1 = DAT_00012ad4;
      param_1[1] = param_2;
      if (iVar3 != 0) {
        SubstrateMemoryRelease();
      }
      if (**(char **)(iVar10 + iVar2) != '\0') {
        sprintf(acStack_40,(char *)(DAT_00012adc + 0x12874),param_1);
        MSLogHexEx(param_1,0xc,4,acStack_40);
      }
    }
  }
  else {
    FUN_000116f0(0,(uint)param_1 & 0xfffffffe,param_2,param_3);
  }
  return;
}



/* Function: SubstrateMemoryRelease @ 00012af0 */

void SubstrateMemoryRelease(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = mprotect((void *)*param_1,param_1[1],7);
  if (iVar1 == -1) {
    puVar2 = (undefined4 *)__errno();
    MSLog(2,DAT_00012b44 + 0x12b40,*puVar2);
  }
  __clear_cache(*param_1,*param_1 + param_1[1]);
  operator_delete(param_1);
  return;
}



/* Function: SubstrateMemoryCreate @ 00012b48 */

undefined4 * SubstrateMemoryCreate(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  size_t __len;
  void *__addr;
  
  if (param_1 == 0) {
    if (param_4 == 0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      iVar4 = **(int **)(DAT_00012c20 + 0x12b98);
      iVar1 = __aeabi_uidiv(param_3,iVar4);
      __addr = (void *)(iVar4 * iVar1);
      iVar1 = __aeabi_uidiv(param_4 + param_3 + -1,iVar4);
      __len = (iVar1 * iVar4 + iVar4) - (int)__addr;
      puVar3 = operator_new(8);
      *puVar3 = __addr;
      puVar3[1] = __len;
      iVar1 = mprotect(__addr,__len,7);
      if (iVar1 == -1) {
        puVar2 = (undefined4 *)__errno();
        MSLog(2,DAT_00012c24 + 0x12c0c,*puVar2);
        operator_delete(puVar3);
        puVar3 = (undefined4 *)0x0;
      }
    }
  }
  else {
    puVar3 = (undefined4 *)0x0;
    MSLog(2,DAT_00012c1c + 0x12b6c);
  }
  return puVar3;
}



/* Function: MSLog @ 00012c28 */

/* MSLog(MSLogLevel, char const*, ...) */

void MSLog(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,...)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 < 3) {
    uVar1 = *(undefined4 *)(DAT_00012c78 + 0x12c4c + param_1 * 4);
  }
  else {
    uVar1 = 3;
  }
  uStack_8 = param_3;
  uStack_4 = param_4;
  __android_log_vprint(uVar1,DAT_00012c7c + 0x12c60,param_2,&uStack_8);
  return;
}



/* Function: __aeabi_uidiv @ 00012c80 */

uint __aeabi_uidiv(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    __div0();
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



/* Function: __aeabi_uidivmod @ 00012d2c */

void __aeabi_uidivmod(void)

{
  __aeabi_uidiv();
  return;
}



/* Function: __div0 @ 00012d44 */

void __div0(void)

{
  raise(8);
  return;
}



/* Function: __clear_cache @ 00012d54 */

void __clear_cache(void)

{
  software_interrupt(0);
  return;
}



/* Function: _Unwind_VRS_Get @ 00012d6c */

undefined4 _Unwind_VRS_Get(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: _Unwind_VRS_Set @ 00012db8 */

undefined4 _Unwind_VRS_Set(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: FUN_00012e04 @ 00012e04 */

int FUN_00012e04(uint *param_1)

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



/* Function: _Unwind_GetCFA @ 00012e1c */

undefined4 _Unwind_GetCFA(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* Function: _Unwind_Complete @ 00012e24 */

void _Unwind_Complete(void)

{
  return;
}



/* Function: _Unwind_DeleteException @ 00012e28 */

void _Unwind_DeleteException(int param_1)

{
  if (*(code **)(param_1 + 8) == (code *)0x0) {
    return;
  }
  (**(code **)(param_1 + 8))(1,param_1);
  return;
}



/* Function: __aeabi_unwind_cpp_pr2 @ 000132dc */

/* WARNING: Removing unreachable block (ram,0x00012e7c) */
/* WARNING: Removing unreachable block (ram,0x00012ef8) */
/* WARNING: Removing unreachable block (ram,0x00012f18) */

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
LAB_00013240:
    do {
      while( true ) {
        uVar5 = *puVar9;
        if (uVar5 == 0) goto LAB_0001324c;
        uVar10 = puVar9[1];
        puVar7 = puVar9 + 2;
        uVar12 = (uVar10 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        _Unwind_VRS_Get(param_3,0,0xf,0,&local_30);
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
LAB_00013140:
              _Unwind_VRS_Get(param_3,0,0xd,0,&local_30);
              *(uint **)(param_2 + 0x28) = puVar7;
              *(uint *)(param_2 + 0x20) = local_30;
              *(int *)(param_2 + 0x24) = local_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar5 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&local_30);
          if ((uVar5 == local_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            local_30 = FUN_00012e04(puVar7);
            _Unwind_VRS_Set(param_3,0,0xf,0,&local_30);
LAB_00013204:
            uVar4 = 0;
            local_30 = param_2;
            goto LAB_000132c0;
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
              if (local_58 == uVar5) goto LAB_00013140;
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
          _Unwind_VRS_Get(param_3,0,0xd,0,&local_30);
          if ((uVar10 == local_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar9 + 3;
            *(uint *)(param_2 + 0x28) = uVar5;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar7) {
              local_30 = FUN_00012e04(puVar7 + uVar5 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&local_30);
              goto LAB_00013204;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 3;
        }
        puVar9 = puVar7 + uVar5 + 1;
        goto LAB_00013240;
      }
      if (uVar8 == 0) {
        bVar1 = false;
      }
      puVar9 = puVar9 + 3;
    } while (!bVar1);
    uVar5 = FUN_00012e04(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      local_30 = uVar5;
      goto LAB_000132c0;
    }
  }
  else {
    bVar11 = false;
LAB_0001324c:
    iVar3 = __gnu_unwind_execute(param_3,&local_3c);
    if (iVar3 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&local_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&local_30);
      uVar4 = 0xf;
      local_30 = *(uint *)(DAT_000132d8 + 0x132b0);
LAB_000132c0:
      _Unwind_VRS_Set(param_3,0,uVar4,0,&local_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr1 @ 000132e4 */

/* WARNING: Removing unreachable block (ram,0x00012e7c) */
/* WARNING: Removing unreachable block (ram,0x00012efc) */
/* WARNING: Removing unreachable block (ram,0x00012f14) */

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
LAB_00013240:
    do {
      while( true ) {
        if (*puVar10 == 0) goto LAB_0001324c;
        uVar1 = *(ushort *)((int)puVar10 + 2);
        uVar6 = *puVar10;
        puVar8 = puVar10 + 1;
        uVar12 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
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
LAB_00013140:
              _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
              *(uint **)(param_2 + 0x28) = puVar8;
              *(uint *)(param_2 + 0x20) = uStack_30;
              *(int *)(param_2 + 0x24) = aiStack_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar6 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
          if ((uVar6 == uStack_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            uStack_30 = FUN_00012e04(puVar8);
            _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
LAB_00013204:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_000132c0;
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
              if (uStack_58 == uVar6) goto LAB_00013140;
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
          _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
          if ((uVar12 == uStack_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar10 + 2;
            *(uint *)(param_2 + 0x28) = uVar6;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar8) {
              uStack_30 = FUN_00012e04(puVar8 + uVar6 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
              goto LAB_00013204;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar8 < 0) {
          puVar8 = puVar10 + 2;
        }
        puVar10 = puVar8 + uVar6 + 1;
        goto LAB_00013240;
      }
      if (uVar9 == 0) {
        bVar2 = false;
      }
      puVar10 = puVar10 + 2;
    } while (!bVar2);
    uVar6 = FUN_00012e04(puVar8);
    *(uint **)(param_2 + 0x38) = puVar10;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar6;
      goto LAB_000132c0;
    }
  }
  else {
    bVar11 = false;
LAB_0001324c:
    iVar4 = __gnu_unwind_execute(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_000132d8 + 0x132b0);
LAB_000132c0:
      _Unwind_VRS_Set(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr0 @ 000132ec */

/* WARNING: Removing unreachable block (ram,0x00012e98) */
/* WARNING: Removing unreachable block (ram,0x00012efc) */
/* WARNING: Removing unreachable block (ram,0x00012f14) */

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
LAB_00013240:
    do {
      while( true ) {
        if (*puVar9 == 0) goto LAB_0001324c;
        uVar1 = *(ushort *)((int)puVar9 + 2);
        uVar10 = *puVar9;
        puVar7 = puVar9 + 1;
        uVar12 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
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
LAB_00013140:
              _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
              *(uint **)(param_2 + 0x28) = puVar7;
              *(uint *)(param_2 + 0x20) = uStack_30;
              *(int *)(param_2 + 0x24) = aiStack_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
          if ((uVar10 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            uStack_30 = FUN_00012e04(puVar7);
            _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
LAB_00013204:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_000132c0;
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
              if (uStack_58 == uVar10) goto LAB_00013140;
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
          _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
          if ((uVar12 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar9 + 2;
            *(uint *)(param_2 + 0x28) = uVar10;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar7) {
              uStack_30 = FUN_00012e04(puVar7 + uVar10 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
              goto LAB_00013204;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 2;
        }
        puVar9 = puVar7 + uVar10 + 1;
        goto LAB_00013240;
      }
      if (uVar8 == 0) {
        bVar2 = false;
      }
      puVar9 = puVar9 + 2;
    } while (!bVar2);
    uVar8 = FUN_00012e04(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar8;
      goto LAB_000132c0;
    }
  }
  else {
    bVar11 = false;
LAB_0001324c:
    iVar4 = __gnu_unwind_execute(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_000132d8 + 0x132b0);
LAB_000132c0:
      _Unwind_VRS_Set(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: FUN_000132f4 @ 000132f4 */

undefined4 FUN_000132f4(int param_1,int param_2)

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
  
  iVar8 = DAT_000134a8 + 0x13308;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_000134ac) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_000134b4);
    local_2c[0] = *(int *)(iVar8 + DAT_000134b0) - iVar2 >> 3;
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
        uVar3 = FUN_00012e04(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_00012e04(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_00013480;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_00012e04(iVar10);
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
        uVar5 = FUN_00012e04();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_00012e04();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_000134b8;
      if (((uVar9 == 0) || (iVar2 = DAT_000134bc, uVar9 == 1)) || (iVar2 = DAT_000134c0, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_00013480:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}



/* Function: FUN_000134c4 @ 000134c4 */

void FUN_000134c4(uint *param_1)

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



/* Function: __gnu_Unwind_Backtrace @ 00013530 */

int __gnu_Unwind_Backtrace(code *param_1,undefined4 param_2,int param_3)

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
    iVar1 = FUN_000132f4(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_000135ec:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    _Unwind_VRS_Set(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_000135ec;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_000134c4(&local_2c0);
  return iVar1;
}



/* Function: FUN_00013604 @ 00013604 */

int FUN_00013604(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_000132f4(param_1,local_228);
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
    restore_core_regs(&local_264);
  }
  return 9;
}



/* Function: __gnu_Unwind_ForcedUnwind @ 00013720 */

void __gnu_Unwind_ForcedUnwind(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_4 + 0x40) = *(undefined4 *)(param_4 + 0x3c);
  FUN_00013604(param_1,param_4,0);
  return;
}



/* Function: FUN_0001373c @ 0001373c */

undefined4 FUN_0001373c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  int iStack_24;
  int iStack_20;
  
  do {
    iVar1 = FUN_000132f4(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_00013788;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 == 7) {
    uVar4 = restore_core_regs(param_2 + 4);
    iVar3 = (int)((ulonglong)uVar4 >> 0x20);
    iVar1 = (int)uVar4;
    *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(iVar3 + 0x3c);
    uStack_264 = *(undefined4 *)(iVar3 + 4);
    uStack_260 = *(undefined4 *)(iVar3 + 8);
    uStack_25c = *(undefined4 *)(iVar3 + 0xc);
    uStack_258 = *(undefined4 *)(iVar3 + 0x10);
    uStack_254 = *(undefined4 *)(iVar3 + 0x14);
    uStack_250 = *(undefined4 *)(iVar3 + 0x18);
    uStack_24c = *(undefined4 *)(iVar3 + 0x1c);
    uStack_248 = *(undefined4 *)(iVar3 + 0x20);
    uStack_244 = *(undefined4 *)(iVar3 + 0x24);
    uStack_240 = *(undefined4 *)(iVar3 + 0x28);
    uStack_23c = *(undefined4 *)(iVar3 + 0x2c);
    uStack_238 = *(undefined4 *)(iVar3 + 0x30);
    uStack_234 = *(undefined4 *)(iVar3 + 0x34);
    uStack_230 = *(undefined4 *)(iVar3 + 0x38);
    uStack_22c = *(undefined4 *)(iVar3 + 0x3c);
    uStack_228 = *(undefined4 *)(iVar3 + 0x40);
    uStack_268 = 0xffffffff;
    iStack_24 = param_2;
    iStack_20 = param_1;
    do {
      iVar2 = FUN_000132f4(iVar1,uStack_228);
      if (iVar2 != 0) {
        return 9;
      }
      iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&uStack_268);
    } while (iVar2 == 8);
    FUN_000134c4(&uStack_268);
    if (iVar2 == 6) {
      FUN_0001373c(iVar1,iVar3);
    }
    return 9;
  }
LAB_00013788:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: __gnu_Unwind_RaiseException @ 00013794 */

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
    iVar1 = FUN_000132f4(param_1,local_218);
    if (iVar1 != 0) {
      return 9;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(0,param_1,&local_258);
  } while (iVar1 == 8);
  FUN_000134c4(&local_258);
  if (iVar1 == 6) {
    FUN_0001373c(param_1,param_2);
  }
  return 9;
}



/* Function: __gnu_Unwind_Resume_or_Rethrow @ 00013838 */

void __gnu_Unwind_Resume_or_Rethrow(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    __gnu_Unwind_RaiseException();
    return;
  }
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  FUN_00013604(param_1,param_2,0);
  return;
}



/* Function: __gnu_Unwind_Resume @ 00013858 */

void __gnu_Unwind_Resume(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (**(code **)(param_1 + 0x10))(2,param_1,param_2);
    if (iVar1 == 7) {
      restore_core_regs(param_2 + 4);
    }
    else if (iVar1 != 8) goto LAB_000138c0;
    FUN_0001373c(param_1,param_2);
  }
  else {
    FUN_00013604(param_1,param_2,1);
  }
LAB_000138c0:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_VRS_Pop @ 000138c4 */

undefined4 _Unwind_VRS_Pop(uint *param_1,undefined4 param_2,uint param_3,int param_4)

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
        __gnu_Unwind_Save_VFP_D();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        __gnu_Unwind_Save_VFP(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      __gnu_Unwind_Save_VFP_D_16_to_31(param_1 + 0x34);
    }
    if (bVar8) {
      __gnu_Unwind_Save_VFP(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        __gnu_Unwind_Save_VFP_D(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_00013a60;
      __gnu_Unwind_Save_VFP_D_16_to_31(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_00013a60:
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
      __gnu_Unwind_Restore_VFP(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        __gnu_Unwind_Restore_VFP_D(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        __gnu_Unwind_Restore_VFP_D_16_to_31(local_b0);
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
          __gnu_Unwind_Save_WMMXD(param_1 + 0x6c);
        }
        __gnu_Unwind_Save_WMMXD(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        __gnu_Unwind_Restore_WMMXD(auStack_130);
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
        __gnu_Unwind_Save_WMMXC(param_1 + 0x8c);
      }
      __gnu_Unwind_Save_WMMXC(local_30);
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
      __gnu_Unwind_Restore_WMMXC(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: restore_core_regs @ 00013c30 */

undefined8 restore_core_regs(undefined8 *param_1)

{
  return *param_1;
}



/* Function: __gnu_Unwind_Restore_VFP @ 00013c44 */

undefined4 __gnu_Unwind_Restore_VFP(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: __gnu_Unwind_Save_VFP @ 00013c4c */

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



/* Function: __gnu_Unwind_Restore_VFP_D @ 00013c54 */

undefined4 __gnu_Unwind_Restore_VFP_D(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: __gnu_Unwind_Save_VFP_D @ 00013c5c */

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



/* Function: __gnu_Unwind_Restore_VFP_D_16_to_31 @ 00013c64 */

void __gnu_Unwind_Restore_VFP_D_16_to_31(void)

{
  return;
}



/* Function: __gnu_Unwind_Save_VFP_D_16_to_31 @ 00013c6c */

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



/* Function: __gnu_Unwind_Restore_WMMXD @ 00013c74 */

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



/* Function: __gnu_Unwind_Save_WMMXD @ 00013cb8 */

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



/* Function: __gnu_Unwind_Restore_WMMXC @ 00013cfc */

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



/* Function: __gnu_Unwind_Save_WMMXC @ 00013d10 */

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



/* Function: _Unwind_RaiseException @ 00013d24 */

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



/* Function: _Unwind_Resume @ 00013d48 */

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



/* Function: ___Unwind_Resume_or_Rethrow @ 00013d6c */

void ___Unwind_Resume_or_Rethrow
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



/* Function: _Unwind_ForcedUnwind @ 00013d90 */

void _Unwind_ForcedUnwind(void)

{
  __gnu_Unwind_ForcedUnwind();
  return;
}



/* Function: ___Unwind_Backtrace @ 00013db4 */

void ___Unwind_Backtrace(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

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



/* Function: FUN_00013dd8 @ 00013dd8 */

uint FUN_00013dd8(uint *param_1)

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



/* Function: _Unwind_GetTextRelBase @ 00013e30 */

void _Unwind_GetTextRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_GetDataRelBase @ 00013e38 */

void _Unwind_GetDataRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_GetLanguageSpecificData @ 00013e40 */

int _Unwind_GetLanguageSpecificData(void)

{
  int in_r3;
  
  _Unwind_VRS_Get();
  return *(int *)(in_r3 + 0x4c) + (uint)*(byte *)(*(int *)(in_r3 + 0x4c) + 7) * 4 + 8;
}



/* Function: _Unwind_GetRegionStart @ 00013e78 */

undefined4 _Unwind_GetRegionStart(void)

{
  int in_r3;
  
  _Unwind_VRS_Get();
  return *(undefined4 *)(in_r3 + 0x48);
}



/* Function: __gnu_unwind_execute @ 00013ea4 */

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
LAB_00013ebc:
  do {
    while( true ) {
      uVar1 = FUN_00013dd8(param_2);
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
LAB_00013ff4:
      piVar6 = &local_24;
      _Unwind_VRS_Set(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_00013dd8(param_2);
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
      goto LAB_00013ebc;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      _Unwind_VRS_Get(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_00013ff4;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_00013dd8(param_2);
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
          _Unwind_VRS_Get(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_00013dd8(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_00013ff4;
        }
        if (uVar1 == 0xb3) {
          FUN_00013dd8(param_2);
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
        FUN_00013dd8(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_00013dd8(param_2);
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
            FUN_00013dd8(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_00013dd8(param_2);
          }
          goto LAB_000141f8;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_000141f8:
      uVar2 = 1;
    }
    iVar5 = _Unwind_VRS_Pop(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: __gnu_unwind_frame @ 0001421c */

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
  __gnu_unwind_execute(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}



/* Function: munmap @ 00017000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int munmap(void *__addr,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __errno @ 00017004 */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_begin_cleanup @ 00017008 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 0001700c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 00017010 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_finalize @ 00017014 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __android_log_vprint @ 00017018 */

/* WARNING: Control flow encountered bad instruction data */

void __android_log_vprint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: operator.delete @ 0001701c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator_delete(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: mmap @ 00017020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 00017024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strrchr @ 00017028 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dlopen @ 0001702c */

/* WARNING: Control flow encountered bad instruction data */

void dlopen(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 00017030 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_atexit @ 00017034 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 00017038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 0001703c */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sprintf @ 00017040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: operator.new @ 00017048 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * operator_new(uint param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: mprotect @ 0001704c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: raise @ 00017050 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



