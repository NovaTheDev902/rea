/* Function: strcpy @ 000091fc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_0000ed48)(__dest);
  return pcVar1;
}



/* Function: printf @ 00009208 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_0000ed4c)(__format);
  return iVar1;
}



/* Function: strerror @ 00009214 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strerror_0000ed50)(__errnum);
  return pcVar1;
}



/* Function: __errno @ 00009220 */

void __errno(void)

{
  (*(code *)PTR___errno_0000ed54)();
  return;
}



/* Function: __cxa_begin_cleanup @ 0000922c */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_0000ed58)();
  return;
}



/* Function: memcpy @ 00009238 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0000ed5c)(__dest);
  return pvVar1;
}



/* Function: puts @ 00009244 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_0000ed60)(__s);
  return iVar1;
}



/* Function: malloc @ 00009250 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_0000ed64)(__size);
  return pvVar1;
}



/* Function: socket @ 0000925c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_0000ed68)(__domain);
  return iVar1;
}



/* Function: abort @ 00009268 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_0000ed6c)();
  return;
}



/* Function: __stack_chk_fail @ 00009274 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_0000ed70)();
  return;
}



/* Function: fprintf @ 0000928c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fprintf_0000ed78)(__stream);
  return iVar1;
}



/* Function: inet_addr @ 00009298 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

in_addr_t inet_addr(char *__cp)

{
  in_addr_t iVar1;
  
  iVar1 = (*(code *)PTR_inet_addr_0000ed7c)(__cp);
  return iVar1;
}



/* Function: setsockopt @ 000092a4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t __optlen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setsockopt_0000ed80)(__fd);
  return iVar1;
}



/* Function: strncpy @ 000092b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strncpy_0000ed84)(__dest);
  return pcVar1;
}



/* Function: __cxa_type_match @ 000092bc */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_0000ed88)();
  return;
}



/* Function: memset @ 000092c8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_0000ed8c)(__s);
  return pvVar1;
}



/* Function: inet_ntoa @ 000092d4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * inet_ntoa(in_addr __in)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_inet_ntoa_0000ed90)(__in.s_addr);
  return pcVar1;
}



/* Function: strcmp @ 000092e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_0000ed94)(__s1);
  return iVar1;
}



/* Function: __gnu_Unwind_Find_exidx @ 000092ec */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_0000ed98)();
  return;
}



/* Function: getsockopt @ 000092f8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getsockopt_0000ed9c)(__fd);
  return iVar1;
}



/* Function: exit @ 00009304 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
  (*(code *)PTR_exit_0000eda0)(__status);
  return;
}



/* Function: atoi @ 00009310 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_atoi_0000eda4)(__nptr);
  return iVar1;
}



/* Function: strlen @ 0000931c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_0000eda8)(__s);
  return sVar1;
}



/* Function: close @ 00009328 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_0000edac)(__fd);
  return iVar1;
}



/* Function: raise @ 00009334 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_raise_0000edb0)(__sig);
  return iVar1;
}



/* Function: free @ 00009340 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0000edb4)(__ptr);
  return;
}



/* Function: entry @ 00009350 */

void processEntry entry(void)

{
  (*(code *)PTR___libc_init_0000ed74)();
  return;
}



/* Function: FUN_00009380 @ 00009380 */

void FUN_00009380(void)

{
  int iVar1;
  char *__s1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  
  iVar1 = iptc_first_rule(DAT_0000954c + 0x9398,*(undefined4 *)(DAT_00009548 + 0x9396));
  iVar12 = DAT_00009558;
  iVar4 = DAT_00009554;
  iVar5 = DAT_00009550;
  if (iVar1 != 0) {
    pcVar10 = (char *)(DAT_0000955c + 0x93b2);
    iVar11 = DAT_00009560 + 0x93b8;
    pcVar13 = (char *)(DAT_00009564 + 0x93be);
    iVar6 = DAT_00009568 + 0x93c0;
    do {
      __s1 = (char *)iptc_get_target(iVar1,*(undefined4 *)(iVar4 + 0x93e4));
      iVar2 = strcmp(__s1,(char *)(iVar12 + 0x93f0));
      if (iVar2 == 0) {
        printf(pcVar13,iVar6,*(undefined4 *)(iVar1 + 0x90));
      }
      else {
        uVar3 = iptc_get_target(iVar1,*(undefined4 *)(iVar4 + 0x93e4));
        printf(pcVar10,iVar11,uVar3);
      }
      iVar1 = iptc_next_rule(iVar1,*(undefined4 *)(iVar5 + 0x93d4));
    } while (iVar1 != 0);
  }
  iVar4 = iptc_first_rule(DAT_00009570 + 0x9414,*(undefined4 *)(DAT_0000956c + 0x9412));
  iVar5 = DAT_00009584;
  if (iVar4 != 0) {
    puVar8 = (undefined4 *)(DAT_00009578 + 0x942c);
    pcVar10 = (char *)(DAT_00009574 + 0x9430);
    iVar12 = DAT_00009580 + 0x9432;
    puVar7 = (undefined4 *)(DAT_0000957c + 0x9434);
    do {
      if (*(in_addr_t *)(iVar4 + 4) == 0) {
        uVar3 = iptc_get_target(iVar4,*puVar8);
        printf(pcVar10,iVar12,uVar3);
      }
      else {
        pcVar13 = inet_ntoa((in_addr)*(in_addr_t *)(iVar4 + 4));
        uVar3 = iptc_get_target(iVar4,*puVar7);
        printf((char *)(DAT_0000958c + 0x9450),DAT_00009588 + 0x944c,pcVar13,uVar3);
      }
      iVar4 = iptc_next_rule(iVar4,*(undefined4 *)(iVar5 + 0x9458));
    } while (iVar4 != 0);
  }
  iVar4 = DAT_00009590 + 0x9484;
  puVar7 = (undefined4 *)(DAT_00009594 + 0x9486);
  iVar5 = iptc_first_rule(iVar4,*puVar7);
  if (iVar5 != 0) {
    pcVar10 = (char *)(DAT_00009598 + 0x9496);
    do {
      uVar3 = iptc_get_target(iVar5,*puVar7);
      printf(pcVar10,iVar4,iVar5 + 0x20,uVar3);
      iVar5 = iptc_next_rule(iVar5,*puVar7);
    } while (iVar5 != 0);
  }
  iVar4 = DAT_0000959c + 0x94be;
  puVar7 = (undefined4 *)(DAT_000095a0 + 0x94c0);
  iVar5 = iptc_first_rule(iVar4,*puVar7);
  if (iVar5 != 0) {
    pcVar10 = (char *)(DAT_000095a4 + 0x94d4);
    do {
      uVar9 = *(undefined4 *)(iVar5 + 0x90);
      uVar3 = iptc_get_target(iVar5,*puVar7);
      printf(pcVar10,iVar4,uVar9,uVar3);
      iVar5 = iptc_next_rule(iVar5,*puVar7);
    } while (iVar5 != 0);
  }
  iVar4 = DAT_000095a8 + 0x9500;
  puVar7 = (undefined4 *)(DAT_000095ac + 0x9502);
  iVar5 = iptc_first_rule(iVar4,*puVar7);
  if (iVar5 != 0) {
    pcVar10 = (char *)(DAT_000095b0 + 0x9516);
    do {
      uVar9 = *(undefined4 *)(iVar5 + 0x90);
      uVar3 = iptc_get_target(iVar5,*puVar7);
      printf(pcVar10,iVar4,uVar9,uVar3);
      iVar5 = iptc_next_rule(iVar5,*puVar7);
    } while (iVar5 != 0);
  }
  return;
}



/* Function: FUN_000095b4 @ 000095b4 */

void FUN_000095b4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *__s;
  
  __s = malloc(0xd0);
  memset(__s,0,0xd0);
  *(undefined2 *)((int)__s + 0x58) = 0xa8;
  *(undefined2 *)((int)__s + 0x5a) = 0xd0;
  uVar1 = DAT_0000962c;
  *(undefined2 *)((int)__s + 0x70) = 0x38;
  *(undefined1 *)((int)__s + 0x8f) = 1;
  *(short *)((int)__s + 0x72) = (short)uVar1;
  *(short *)((int)__s + 0x74) = (short)DAT_00009630;
  *(undefined2 *)((int)__s + 0x76) = 0x72;
  iVar2 = DAT_00009634;
  *(undefined4 *)((int)__s + 0x90) = param_1;
  *(undefined4 *)((int)__s + 0x94) = param_1;
  *(undefined1 *)((int)__s + 0xa0) = 1;
  *(undefined2 *)((int)__s + 0xa8) = 0x28;
  memcpy((void *)((int)__s + 0xaa),(void *)(iVar2 + 0x960c),8);
  *(undefined2 *)((int)__s + 200) = 0x65;
  iptc_append_entry(param_2,__s,*(undefined4 *)(DAT_00009638 + 0x9620));
  free(__s);
  return;
}



/* Function: FUN_0000963c @ 0000963c */

void FUN_0000963c(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  void *__s;
  
  __s = malloc(0xd0);
  memset(__s,0,0xd0);
  *(undefined2 *)((int)__s + 0x58) = 0xa8;
  *(undefined2 *)((int)__s + 0x5a) = 0xd0;
  uVar2 = DAT_000096b0;
  *(undefined2 *)((int)__s + 0x70) = 0x38;
  *(undefined1 *)((int)__s + 0x8f) = 1;
  *(short *)((int)__s + 0x72) = (short)uVar2;
  *(short *)((int)__s + 0x74) = (short)DAT_000096b4;
  *(undefined2 *)((int)__s + 0x76) = 0x72;
  *(undefined4 *)((int)__s + 0x90) = param_1;
  *(undefined4 *)((int)__s + 0x94) = param_1;
  *(undefined1 *)((int)__s + 0xa0) = 1;
  *(undefined2 *)((int)__s + 0xa8) = 0x28;
  sVar1 = (short)DAT_000096b8;
  *(short *)((int)__s + 0xaa) = sVar1;
  *(short *)((int)__s + 0xac) = sVar1 + -0x1f5;
  iptc_append_entry(param_2,__s,*(undefined4 *)(DAT_000096bc + 0x96a2));
  free(__s);
  return;
}



/* Function: FUN_000096c0 @ 000096c0 */

void FUN_000096c0(int param_1,int param_2)

{
  int iVar1;
  char *__s2;
  int iVar2;
  char *__s2_00;
  undefined4 uVar3;
  int iVar4;
  char *__s1;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  iVar2 = param_1 + -3;
  if (-1 < iVar2) {
    iVar7 = 0;
    __s2_00 = (char *)(DAT_000097c8 + 0x96e8);
    puVar9 = (undefined4 *)(DAT_000097c0 + 0x96ec);
    puVar6 = (undefined4 *)(DAT_000097c4 + 0x96f0);
    do {
      while( true ) {
        iVar4 = param_2 + param_1 * 4 + iVar7;
        iVar1 = atoi(*(char **)(iVar4 + -0xc));
        uVar3 = *(undefined4 *)(iVar4 + -8);
        __s1 = *(char **)(iVar4 + -4);
        if (iVar1 == 0) break;
        iVar4 = iptc_first_rule(uVar3,*puVar9);
        if (iVar4 != 0) {
          iVar5 = 0;
          while (((*(int *)(iVar4 + 0x90) != iVar1 || (iVar1 != *(int *)(iVar4 + 0x94))) ||
                 (*(char *)(iVar4 + 0xa0) != '\x01'))) {
            iVar4 = iptc_next_rule(iVar4,*puVar6);
            if (iVar4 == 0) goto LAB_0000977a;
            iVar5 = iVar5 + 1;
          }
          if (iVar4 != 0) {
            puVar8 = (undefined4 *)(DAT_000097cc + 0x975c);
            __s2 = (char *)iptc_get_target(iVar4,*puVar8);
            iVar4 = strcmp(__s1,__s2);
            if (iVar4 == 0) break;
            iptc_delete_num_entry(uVar3,iVar5,*puVar8);
          }
        }
LAB_0000977a:
        iVar4 = strcmp(__s1,__s2_00);
        if (iVar4 == 0) {
          FUN_0000963c(iVar1,uVar3);
          break;
        }
        iVar4 = strcmp(__s1,(char *)(DAT_000097d0 + 0x978e));
        if (iVar4 != 0) break;
        FUN_000095b4(iVar1,uVar3);
        iVar7 = iVar7 + -0xc;
        iVar2 = iVar2 + -3;
        if (iVar2 < 0) {
          return;
        }
      }
      iVar7 = iVar7 + -0xc;
      iVar2 = iVar2 + -3;
    } while (-1 < iVar2);
  }
  return;
}



/* Function: FUN_000097d4 @ 000097d4 */

void FUN_000097d4(undefined4 *param_1)

{
  int iVar1;
  void *__s;
  
  __s = malloc(0x98);
  memset(__s,0,0x98);
  *(undefined2 *)((int)__s + 0x58) = 0x70;
  *(undefined2 *)((int)__s + 0x5a) = 0x98;
  iVar1 = DAT_00009834;
  *(undefined4 *)((int)__s + 4) = *param_1;
  *(undefined4 *)((int)__s + 0xc) = 0xffffffff;
  *(undefined2 *)((int)__s + 0x70) = 0x28;
  memcpy((void *)((int)__s + 0x72),(void *)(iVar1 + 0x980e),8);
  *(undefined2 *)((int)__s + 0x90) = 100;
  iptc_insert_entry(DAT_0000983c + 0x9828,__s,0,*(undefined4 *)(DAT_00009838 + 0x9822));
  free(__s);
  return;
}



/* Function: FUN_00009840 @ 00009840 */

void FUN_00009840(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  void *__s;
  
  __s = malloc(0x98);
  memset(__s,0,0x98);
  *(undefined2 *)((int)__s + 0x58) = 0x70;
  *(undefined2 *)((int)__s + 0x5a) = 0x98;
  iVar2 = DAT_0000989c;
  *(undefined4 *)((int)__s + 4) = *param_1;
  *(undefined4 *)((int)__s + 0xc) = 0xffffffff;
  *(undefined2 *)((int)__s + 0x70) = 0x28;
  sVar1 = (short)DAT_000098a0;
  *(short *)((int)__s + 0x72) = sVar1;
  *(short *)((int)__s + 0x74) = sVar1 + -0x1f5;
  iptc_insert_entry(iVar2 + 0x988c,__s,0,*(undefined4 *)(DAT_000098a4 + 0x988e));
  free(__s);
  return;
}



/* Function: FUN_000098a8 @ 000098a8 */

void FUN_000098a8(int param_1,int param_2)

{
  char *__s2;
  int iVar1;
  int iVar2;
  char *__s1;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  in_addr_t local_2c [2];
  
  iVar6 = param_1 + -2;
  if (-1 < iVar6) {
    iVar1 = DAT_0000998c + 0x98c4;
    iVar5 = 0;
    puVar7 = (undefined4 *)(DAT_00009994 + 0x98d2);
    puVar4 = (undefined4 *)(DAT_00009990 + 0x98d4);
    do {
      while( true ) {
        iVar2 = param_2 + param_1 * 4 + iVar5;
        local_2c[0] = inet_addr(*(char **)(iVar2 + -8));
        __s1 = *(char **)(iVar2 + -4);
        if (local_2c[0] == 0) break;
        iVar2 = iptc_first_rule(iVar1,*puVar7);
        if (iVar2 != 0) {
          iVar3 = 0;
          if (*(in_addr_t *)(iVar2 + 4) == local_2c[0]) {
            iVar3 = 0;
          }
          else {
            do {
              iVar2 = iptc_next_rule(iVar2,*puVar4);
              if (iVar2 == 0) goto LAB_00009922;
              iVar3 = iVar3 + 1;
            } while (*(in_addr_t *)(iVar2 + 4) != local_2c[0]);
          }
          puVar8 = (undefined4 *)(DAT_000099a0 + 0x9962);
          __s2 = (char *)iptc_get_target(iVar2,*puVar8);
          iVar2 = strcmp(__s1,__s2);
          if (iVar2 == 0) break;
          iptc_delete_num_entry(DAT_000099a4 + 0x9980,iVar3,*puVar8);
        }
LAB_00009922:
        iVar2 = strcmp(__s1,(char *)(DAT_00009998 + 0x992a));
        if (iVar2 == 0) {
          FUN_00009840(local_2c);
          break;
        }
        iVar2 = strcmp(__s1,(char *)(DAT_0000999c + 0x9938));
        if (iVar2 != 0) break;
        FUN_000097d4(local_2c);
        iVar5 = iVar5 + -8;
        iVar6 = iVar6 + -2;
        if (iVar6 < 0) {
          return;
        }
      }
      iVar5 = iVar5 + -8;
      iVar6 = iVar6 + -2;
    } while (-1 < iVar6);
  }
  return;
}



/* Function: FUN_000099a8 @ 000099a8 */

void FUN_000099a8(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  void *__s;
  
  __s = malloc(0xd0);
  memset(__s,0,0xd0);
  *(undefined2 *)((int)__s + 0x58) = 0xa8;
  *(undefined2 *)((int)__s + 0x5a) = 0xd0;
  uVar1 = DAT_00009a2c;
  *(undefined2 *)((int)__s + 0x70) = 0x38;
  *(undefined1 *)((int)__s + 0x8f) = 1;
  *(short *)((int)__s + 0x72) = (short)uVar1;
  iVar2 = DAT_00009a34;
  *(short *)((int)__s + 0x74) = (short)DAT_00009a30;
  *(undefined2 *)((int)__s + 0x76) = 0x72;
  *(undefined4 *)((int)__s + 0x90) = param_1;
  *(undefined4 *)((int)__s + 0x94) = param_1;
  *(undefined1 *)((int)__s + 0xa0) = 1;
  *(undefined2 *)((int)__s + 0xa8) = 0x28;
  *(undefined1 *)((int)__s + 199) = 2;
  *(short *)((int)__s + 0xaa) = (short)DAT_00009a38;
  *(short *)((int)__s + 0xac) = (short)DAT_00009a3c;
  *(undefined4 *)((int)__s + 0xcc) = 0xffffffff;
  iVar3 = DAT_00009a40;
  *(undefined4 *)((int)__s + 200) = param_1;
  iptc_insert_entry(iVar2 + 0x9a0a,__s,0,*(undefined4 *)(iVar3 + 0x9a1e));
  free(__s);
  return;
}



/* Function: FUN_00009a44 @ 00009a44 */

void FUN_00009a44(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *__s1;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *__s2;
  int iVar7;
  bool bVar8;
  
  param_1 = param_1 + -1;
  if (-1 < param_1) {
    puVar4 = (undefined4 *)(param_2 + param_1 * 4);
    iVar7 = DAT_00009af8 + 0x9a6c;
    puVar6 = (undefined4 *)(DAT_00009afc + 0x9a6e);
    __s2 = (char *)(DAT_00009af4 + 0x9a70);
    do {
      while (iVar1 = atoi((char *)*puVar4), iVar1 != 0) {
        iVar2 = iptc_first_rule(iVar7,*(undefined4 *)(DAT_00009b00 + 0x9a92));
        if (iVar2 != 0) {
          puVar5 = (undefined4 *)(DAT_00009b04 + 0x9aa0);
          do {
            __s1 = (char *)iptc_get_target(iVar2,*puVar6);
            iVar3 = strcmp(__s1,__s2);
            if (((iVar3 == 0) && (*(int *)(iVar2 + 0x90) == iVar1)) &&
               (iVar1 == *(int *)(iVar2 + 0x94))) {
              if (iVar2 != 0) goto LAB_00009a70;
              break;
            }
            iVar2 = iptc_next_rule(iVar2,*puVar5);
          } while (iVar2 != 0);
        }
        FUN_000099a8(iVar1);
        puVar4 = puVar4 + -1;
        bVar8 = param_1 == 0;
        param_1 = param_1 + -1;
        if (bVar8) {
          return;
        }
      }
LAB_00009a70:
      puVar4 = puVar4 + -1;
      bVar8 = param_1 != 0;
      param_1 = param_1 + -1;
    } while (bVar8);
  }
  return;
}



/* Function: FUN_00009b08 @ 00009b08 */

void FUN_00009b08(char *param_1)

{
  int iVar1;
  char *__s1;
  int iVar2;
  void *__s;
  undefined4 *puVar3;
  int iVar4;
  char *__s2;
  
  puVar3 = (undefined4 *)(DAT_00009bdc + 0x9b18);
  iVar1 = iptc_first_rule(DAT_00009be0 + 0x9b1c,*puVar3);
  if (iVar1 == 0) {
LAB_00009b60:
    iVar1 = -1;
  }
  else {
    iVar4 = 0;
    __s2 = (char *)(DAT_00009be4 + 0x9b2a);
    while( true ) {
      __s1 = (char *)iptc_get_target(iVar1,*puVar3);
      iVar2 = strcmp(__s1,__s2);
      if (iVar2 == 0) break;
      iVar1 = iptc_next_rule(iVar1,*puVar3);
      if (iVar1 == 0) goto LAB_00009b60;
      iVar4 = iVar4 + 1;
    }
    iVar1 = 0;
    if (iVar4 != 0) {
      iptc_delete_num_entry(DAT_00009be8 + 0x9b5a,iVar4,*puVar3);
      iVar1 = iVar4;
    }
  }
  iVar4 = strcmp(param_1,(char *)(DAT_00009bec + 0x9b6c));
  if (iVar4 == 0) {
    if (iVar1 == 0) {
      iptc_delete_num_entry(DAT_00009c04 + 0x9bd8,0,*(undefined4 *)(DAT_00009c00 + 0x9bd4));
    }
  }
  else if (iVar1 != 0) {
    __s = malloc(0x98);
    memset(__s,0,0x98);
    *(undefined2 *)((int)__s + 0x58) = 0x70;
    *(undefined2 *)((int)__s + 0x5a) = 0x98;
    *(undefined2 *)((int)__s + 0x70) = 0x28;
    iVar1 = DAT_00009bf4;
    *(short *)((int)__s + 0x72) = (short)DAT_00009bf0;
    *(short *)((int)__s + 0x74) = (short)DAT_00009bf8;
    iptc_insert_entry(iVar1 + 0x9bbc,__s,0,*(undefined4 *)(DAT_00009bfc + 0x9bbe));
    free(__s);
  }
  return;
}



/* Function: FUN_00009c08 @ 00009c08 */

void FUN_00009c08(void)

{
  int iVar1;
  
  iVar1 = iptc_is_chain(DAT_00009c34 + 0x9c14,*(undefined4 *)(DAT_00009c30 + 0x9c12));
  if (iVar1 == 0) {
    puts((char *)(DAT_00009c38 + 0x9c22));
  }
  else {
    puts((char *)(DAT_00009c3c + 0x9c2c));
  }
  return;
}



/* Function: FUN_00009c40 @ 00009c40 */

void FUN_00009c40(void)

{
  int iVar1;
  char *__s1;
  int iVar2;
  undefined4 *puVar3;
  char *__s2;
  
  puVar3 = (undefined4 *)(DAT_00009c8c + 0x9c4a);
  iVar1 = iptc_first_rule(DAT_00009c90 + 0x9c4c,*puVar3);
  if (iVar1 != 0) {
    __s2 = (char *)(DAT_00009c94 + 0x9c5a);
    do {
      __s1 = (char *)iptc_get_target(iVar1,*puVar3);
      iVar2 = strcmp(__s1,__s2);
      if (iVar2 == 0) {
        puts((char *)(DAT_00009c98 + 0x9c7e));
        return;
      }
      iVar1 = iptc_next_rule(iVar1,*puVar3);
    } while (iVar1 != 0);
  }
  puts((char *)(DAT_00009c9c + 0x9c88));
  return;
}



/* Function: FUN_00009ca0 @ 00009ca0 */

void FUN_00009ca0(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *__s1;
  void *__s;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(DAT_00009d54 + 0x9cb0);
  iVar1 = iptc_first_rule(param_1,*puVar4);
  if (iVar1 == 0) {
    __s = malloc(0x98);
    memset(__s,0,0x98);
    *(undefined2 *)((int)__s + 0x58) = 0x70;
    *(undefined2 *)((int)__s + 0x5a) = 0x98;
    *(undefined2 *)((int)__s + 0x70) = 0x28;
    strcpy((char *)((int)__s + 0x72),param_2);
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    while (iVar2 = iptc_next_rule(iVar1,*puVar4), iVar2 != 0) {
      iVar3 = iVar3 + 1;
    }
    __s1 = (char *)iptc_get_target(iVar1,*puVar4);
    iVar1 = strcmp(__s1,param_2);
    if (iVar1 == 0) {
      return;
    }
    __s = malloc(0x98);
    memset(__s,0,0x98);
    *(undefined2 *)((int)__s + 0x58) = 0x70;
    *(undefined2 *)((int)__s + 0x5a) = 0x98;
    *(undefined2 *)((int)__s + 0x70) = 0x28;
    strcpy((char *)((int)__s + 0x72),param_2);
    iVar3 = iVar3 + 1;
  }
  iptc_insert_entry(param_1,__s,iVar3,*(undefined4 *)(DAT_00009d58 + 0x9d16));
  return;
}



/* Function: FUN_00009d5c @ 00009d5c */

void FUN_00009d5c(undefined4 param_1,char *param_2,char *param_3)

{
  void *__s;
  size_t sVar1;
  
  __s = malloc(0x98);
  memset(__s,0,0x98);
  *(undefined2 *)((int)__s + 0x58) = 0x70;
  *(undefined2 *)((int)__s + 0x5a) = 0x98;
  strcpy((char *)((int)__s + 0x20),param_2);
  sVar1 = strlen(param_2);
  memset((void *)((int)__s + 0x40),0xff,sVar1 - 1);
  *(undefined2 *)((int)__s + 0x70) = 0x28;
  strcpy((char *)((int)__s + 0x72),param_3);
  iptc_append_entry(param_1,__s,*(undefined4 *)(DAT_00009dc4 + 0x9db8));
  free(__s);
  return;
}



/* Function: FUN_00009dc8 @ 00009dc8 */

undefined4 FUN_00009dc8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar4 = DAT_00009ed4 + 0x9dd2;
  puVar3 = (undefined4 *)(DAT_00009ed8 + 0x9dd4);
  iVar1 = iptc_is_chain(iVar4,*puVar3,param_3,param_4,param_4);
  uVar2 = 1;
  if (iVar1 == 0) {
    iVar1 = iptc_create_chain(iVar4,*puVar3);
    if (iVar1 != 0) {
      iVar4 = DAT_00009edc + 0x9dfc;
      iVar1 = iptc_is_chain(iVar4,*puVar3);
      if ((iVar1 != 0) || (iVar1 = iptc_create_chain(iVar4,*puVar3), iVar1 != 0)) {
        iVar4 = DAT_00009ee0 + 0x9e18;
        puVar3 = (undefined4 *)(DAT_00009ee4 + 0x9e1a);
        iVar1 = iptc_is_chain(iVar4,*puVar3);
        if ((iVar1 != 0) || (iVar1 = iptc_create_chain(iVar4,*puVar3), iVar1 != 0)) {
          iVar4 = DAT_00009ee8 + 0x9e38;
          puVar3 = (undefined4 *)(DAT_00009eec + 0x9e3a);
          iVar1 = iptc_is_chain(iVar4,*puVar3);
          if ((iVar1 != 0) || (iVar1 = iptc_create_chain(iVar4,*puVar3), iVar1 != 0)) {
            iVar4 = DAT_00009ef0 + 0x9e58;
            puVar3 = (undefined4 *)(DAT_00009ef4 + 0x9e5a);
            iVar1 = iptc_is_chain(iVar4,*puVar3);
            if ((iVar1 == 0) && (iVar1 = iptc_create_chain(iVar4,*puVar3), iVar1 == 0)) {
              return 0;
            }
            iVar1 = DAT_00009ef8 + 0x9e6e;
            iVar4 = DAT_00009f00 + 0x9e74;
            FUN_00009ca0(DAT_00009efc + 0x9e72,iVar1);
            FUN_00009ca0(iVar1,iVar4);
            puVar3 = (undefined4 *)(DAT_00009f04 + 0x9e86);
            puVar5 = (undefined4 *)(DAT_00009f04 + 0x9ea6);
            iVar1 = DAT_00009f08 + 0x9e8c;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 1;
              FUN_00009d5c(iVar4,uVar2,iVar1);
            } while (puVar3 != puVar5);
            puVar3 = (undefined4 *)(DAT_00009f0c + 0x9ec2);
            iVar1 = DAT_00009f0c + 2;
            iVar6 = DAT_00009f10 + 0x9eaa;
            iVar4 = DAT_00009f14 + 0x9eac;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 1;
              FUN_00009d5c(iVar6,uVar2,iVar4);
            } while (puVar3 != (undefined4 *)((int)&DAT_00009ed8 + iVar1));
            FUN_00009b08(DAT_00009f18 + 0x9ebe);
            return 1;
          }
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* Function: FUN_0000a0e8 @ 0000a0e8 */

undefined4 FUN_0000a0e8(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int extraout_r1;
  int *piVar3;
  int iVar4;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    piVar3 = *(int **)(param_1 + 8);
    if (piVar3 != (int *)(param_1 + 8)) {
      iVar4 = 0;
      do {
        if (piVar3[10] == 0) {
          uVar2 = __aeabi_uidiv(iVar4,0x28);
          if (*(uint *)(param_1 + 0x20) <= uVar2) break;
          __aeabi_uidivmod(iVar4,0x28);
          if (extraout_r1 == 0) {
            *(int **)(uVar2 * 4 + *(int *)(param_1 + 0x1c)) = piVar3;
          }
          iVar4 = iVar4 + 1;
        }
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)(param_1 + 8));
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* Function: iptc_next_rule @ 0000a140 */

int iptc_next_rule(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  *(undefined4 *)(DAT_0000a170 + 0xa14e) = *(undefined4 *)(DAT_0000a16c + 0xa14a);
  piVar2 = *(int **)(param_2 + 0x14);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    if (iVar1 == piVar2[2] + 0x54) {
      *(undefined4 *)(param_2 + 0x14) = 0;
      iVar1 = 0;
    }
    else {
      *(int *)(param_2 + 0x14) = iVar1;
      iVar1 = iVar1 + 0x28;
    }
  }
  return iVar1;
}



/* Function: FUN_0000a174 @ 0000a174 */

char * FUN_0000a174(int param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  int local_118 [2];
  undefined4 local_110 [65];
  
  piVar3 = local_118;
  memcpy(local_118,(void *)(DAT_0000a1c4 + 0xa184),0x108);
  iVar2 = 0;
  while (((*piVar3 != 0 && (*piVar3 != *(int *)(DAT_0000a1c8 + 0xa192))) || (piVar3[1] != param_1)))
  {
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 3;
    if (iVar2 == 0x16) {
      pcVar1 = strerror(param_1);
      return pcVar1;
    }
  }
  return (char *)local_110[iVar2 * 3];
}



/* Function: FUN_0000a1cc @ 0000a1cc */

undefined4 FUN_0000a1cc(int param_1)

{
  int iVar1;
  void *__s;
  int extraout_r1;
  undefined4 uVar2;
  size_t __size;
  
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  __aeabi_uidivmod(uVar2,0x28);
  iVar1 = __aeabi_uidiv(uVar2,0x28);
  iVar1 = (uint)(extraout_r1 != 0) + iVar1;
  __size = iVar1 * 4;
  __s = malloc(__size);
  *(void **)(param_1 + 0x1c) = __s;
  if ((__s == (void *)0x0) && (__size != 0)) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    uVar2 = 0xfffffff4;
  }
  else {
    memset(__s,0,__size);
    *(int *)(param_1 + 0x20) = iVar1;
    uVar2 = 1;
  }
  return uVar2;
}



/* Function: FUN_0000a214 @ 0000a214 */

void FUN_0000a214(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = malloc(param_2 + 0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[2] = param_1;
    puVar1[9] = param_2;
  }
  return;
}



/* Function: FUN_0000a244 @ 0000a244 */

undefined4 FUN_0000a244(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  free(*(void **)(param_1 + 0x1c));
  iVar1 = FUN_0000a1cc(param_1);
  if (iVar1 < 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    FUN_0000a0e8(param_1);
    uVar2 = 1;
  }
  return uVar2;
}



/* Function: FUN_0000a26c @ 0000a26c */

void FUN_0000a26c(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1[7] == 3) && (iVar1 = param_1[8], iVar1 != 0)) {
    *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + -1;
  }
  piVar2 = (int *)param_1[1];
  iVar1 = *param_1;
  *(int **)(iVar1 + 4) = piVar2;
  *piVar2 = iVar1;
  *param_1 = DAT_0000a298;
  param_1[1] = DAT_0000a29c;
  free(param_1);
  return;
}



/* Function: FUN_0000a2a0 @ 0000a2a0 */

bool FUN_0000a2a0(int param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 *puVar2;
  short *psVar3;
  
  psVar3 = (short *)(param_1 + 0x28 + (uint)*(ushort *)(param_1 + 0x80));
  sVar1 = *psVar3;
  if (sVar1 == 0x28) {
    memset(psVar3 + 1,0,0x1e);
    *(undefined4 *)(psVar3 + 0x10) = param_2;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0x16;
  }
  return sVar1 == 0x28;
}



/* Function: iptc_commit @ 0000a2d8 */

/* WARNING: Type propagation algorithm not settling */

undefined4 iptc_commit(int *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *__dest;
  void *pvVar4;
  char *__dest_00;
  undefined4 *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  size_t __size;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  int *piVar16;
  int local_48;
  
  *(undefined4 *)(DAT_0000a648 + 0xa2f2) = *(undefined4 *)(DAT_0000a644 + 0xa2ee);
  if (param_1[1] == 0) {
    return 1;
  }
  piVar15 = (int *)param_1[2];
  if (piVar15 == param_1 + 2) {
    iVar14 = 0xb0;
    local_48 = 1;
  }
  else {
    iVar10 = 0;
    iVar8 = 0;
    do {
      piVar15[0x18] = iVar8;
      if (piVar15[10] == 0) {
        iVar8 = iVar8 + 0xb0;
        iVar10 = iVar10 + 1;
      }
      local_48 = iVar10;
      iVar14 = iVar8;
      for (piVar16 = (int *)piVar15[0x15]; piVar16 != piVar15 + 0x15; piVar16 = (int *)*piVar16) {
        piVar16[6] = iVar14;
        piVar16[5] = local_48;
        local_48 = local_48 + 1;
        iVar14 = iVar14 + piVar16[9];
      }
      piVar15[0x1a] = iVar14;
      piVar15[0x19] = local_48;
      piVar15 = (int *)*piVar15;
      iVar8 = iVar14 + 0x98;
      iVar10 = local_48 + 1;
    } while (piVar15 != param_1 + 2);
    iVar14 = iVar14 + 0x148;
    local_48 = local_48 + 2;
    if (local_48 < 0) goto LAB_0000a620;
  }
  __dest = malloc(iVar14 + 0x60U);
  if (__dest != (char *)0x0) {
    memset(__dest,0,iVar14 + 0x60U);
    pvVar4 = malloc(param_1[0x1d] << 4);
    *(void **)(__dest + 0x58) = pvVar4;
    if (pvVar4 == (void *)0x0) {
      puVar5 = (undefined4 *)__errno();
      *puVar5 = 0xc;
    }
    else {
      __size = local_48 * 0x10 + 0x28;
      __dest_00 = malloc(__size);
      if (__dest_00 == (char *)0x0) {
        puVar5 = (undefined4 *)__errno();
        *puVar5 = 0xc;
      }
      else {
        memset(__dest_00,0,__size);
        strcpy(__dest,(char *)(param_1 + 10));
        *(int *)(__dest + 0x28) = iVar14;
        *(int *)(__dest + 0x24) = local_48;
        *(int *)(__dest + 0x54) = param_1[0x1d];
        *(int *)(__dest + 0x20) = param_1[0x12];
        for (piVar16 = (int *)param_1[2]; piVar15 != piVar16; piVar16 = (int *)*piVar16) {
          if (piVar16[10] == 0) {
            iVar10 = piVar16[0x18];
            (__dest + iVar10 + 0xb8)[0] = 'p';
            uVar2 = DAT_0000a64c;
            (__dest + iVar10 + 0xb8)[1] = '\0';
            (__dest + iVar10 + 0xba)[0] = -0x50;
            uVar3 = DAT_0000a650;
            (__dest + iVar10 + 0xba)[1] = '\0';
            *(short *)(__dest + iVar10 + 0xd2) = (short)uVar2;
            *(short *)(__dest + iVar10 + 0xd4) = (short)uVar3;
            (__dest + iVar10 + 0xd6)[0] = 'R';
            (__dest + iVar10 + 0xd6)[1] = '\0';
            (__dest + iVar10 + 0xd0)[0] = '@';
            (__dest + iVar10 + 0xd0)[1] = '\0';
            strcpy(__dest + iVar10 + 0xf0,(char *)(piVar16 + 2));
          }
          else {
            *(int *)(__dest + (piVar16[10] + 9) * 4 + 4) = piVar16[0x18];
            *(int *)(__dest + (piVar16[10] + 0xf) * 4) = piVar16[0x1a];
          }
          for (piVar13 = (int *)piVar16[0x15]; piVar13 != piVar16 + 0x15; piVar13 = (int *)*piVar13)
          {
            if (piVar13[7] == 3) {
              uVar6 = (uint)*(ushort *)(piVar13 + 0x20);
              memset((void *)((int)piVar13 + uVar6 + 0x2a),0,0x1e);
              *(undefined1 *)((int)piVar13 + uVar6 + 0x2a) = 0;
              *(int *)((int)piVar13 + uVar6 + 0x48) = *(int *)(piVar13[8] + 0x60) + 0xb0;
            }
            else if (piVar13[7] == 2) {
              *(int *)((int)piVar13 + *(ushort *)(piVar13 + 0x20) + 0x48) = piVar13[9] + piVar13[6];
            }
            memcpy(__dest + piVar13[6] + 0x60,piVar13 + 10,piVar13[9]);
          }
          iVar10 = piVar16[0x1a];
          (__dest + iVar10 + 0xb8)[0] = 'p';
          (__dest + iVar10 + 0xb8)[1] = '\0';
          (__dest + iVar10 + 0xba)[0] = -0x68;
          (__dest + iVar10 + 0xba)[1] = '\0';
          __dest[iVar10 + 0xd2] = '\0';
          (__dest + iVar10 + 0xd0)[0] = '(';
          (__dest + iVar10 + 0xd0)[1] = '\0';
          if (piVar16[10] == 0) {
            pcVar1 = __dest + iVar10 + 0xf0;
            pcVar1[0] = -5;
            pcVar1[1] = -1;
            pcVar1[2] = -1;
            pcVar1[3] = -1;
          }
          else {
            *(int *)(__dest + iVar10 + 0xf0) = piVar16[0xc];
          }
          memcpy(__dest + iVar10 + 0xc0,piVar16 + 0xe,0x10);
        }
        iVar10 = *(int *)(__dest + 0x28);
        (__dest + iVar10 + 8)[0] = 'p';
        (__dest + iVar10 + 8)[1] = '\0';
        (__dest + iVar10 + 10)[0] = -0x50;
        (__dest + iVar10 + 10)[1] = '\0';
        (__dest + iVar10 + 0x20)[0] = '@';
        (__dest + iVar10 + 0x20)[1] = '\0';
        *(short *)(__dest + iVar10 + 0x22) = (short)DAT_0000a64c;
        *(short *)(__dest + iVar10 + 0x24) = (short)DAT_0000a650;
        (__dest + iVar10 + 0x26)[0] = 'R';
        uVar2 = DAT_0000a654;
        (__dest + iVar10 + 0x26)[1] = '\0';
        (__dest + iVar10 + 0x44)[0] = 'R';
        (__dest + iVar10 + 0x44)[1] = '\0';
        *(undefined4 *)(__dest + iVar10 + 0x40) = uVar2;
        iVar10 = setsockopt(*param_1,0,0x40,__dest,*(int *)(__dest + 0x28) + 0x60);
        if (-1 < iVar10) {
          strcpy(__dest_00,(char *)(param_1 + 10));
          *(int *)(__dest_00 + 0x20) = local_48;
          for (piVar16 = (int *)param_1[2]; piVar15 != piVar16; piVar16 = (int *)*piVar16) {
            if (piVar16[10] != 0) {
              iVar10 = piVar16[0x12];
              if (iVar10 == 1) {
                memcpy(__dest_00 + piVar16[0x19] * 0x10 + 0x28,
                       (void *)(*(int *)(__dest + 0x58) + piVar16[0x13] * 0x10),0x10);
              }
              else if (iVar10 == 0) {
                iVar10 = piVar16[0x19];
                pcVar11 = __dest_00 + (iVar10 + 3) * 0x10;
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x28;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x2c;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar11[0] = '\0';
                pcVar11[1] = '\0';
                pcVar11[2] = '\0';
                pcVar11[3] = '\0';
                pcVar11[4] = '\0';
                pcVar11[5] = '\0';
                pcVar11[6] = '\0';
                pcVar11[7] = '\0';
              }
              else if (iVar10 == 2) {
                iVar10 = piVar16[0x19];
                puVar7 = (uint *)(*(int *)(__dest + 0x58) + piVar16[0x13] * 0x10);
                uVar12 = piVar16[0xe];
                iVar8 = piVar16[0xf];
                uVar6 = *puVar7;
                uVar9 = puVar7[1];
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x28) = uVar6 - uVar12;
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x2c) =
                     (uVar9 - iVar8) - (uint)(uVar6 < uVar12);
                uVar6 = puVar7[2];
                uVar9 = puVar7[3];
                uVar12 = piVar16[0x10];
                iVar8 = piVar16[0x11];
                *(uint *)(__dest_00 + (iVar10 + 3) * 0x10) = uVar6 - uVar12;
                *(uint *)((int)(__dest_00 + (iVar10 + 3) * 0x10) + 4) =
                     (uVar9 - iVar8) - (uint)(uVar6 < uVar12);
              }
              else if (iVar10 == 3) {
                memcpy(__dest_00 + piVar16[0x19] * 0x10 + 0x28,piVar16 + 0xe,0x10);
              }
            }
            for (piVar13 = (int *)piVar16[0x15]; piVar13 != piVar16 + 0x15;
                piVar13 = (int *)*piVar13) {
              iVar10 = piVar13[3];
              if (iVar10 == 1) {
                memcpy(__dest_00 + piVar13[5] * 0x10 + 0x28,
                       (void *)(*(int *)(__dest + 0x58) + piVar13[4] * 0x10),0x10);
              }
              else if (iVar10 == 0) {
                iVar10 = piVar13[5];
                pcVar11 = __dest_00 + (iVar10 + 3) * 0x10;
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x28;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar1 = __dest_00 + iVar10 * 0x10 + 0x2c;
                pcVar1[0] = '\0';
                pcVar1[1] = '\0';
                pcVar1[2] = '\0';
                pcVar1[3] = '\0';
                pcVar11[0] = '\0';
                pcVar11[1] = '\0';
                pcVar11[2] = '\0';
                pcVar11[3] = '\0';
                pcVar11[4] = '\0';
                pcVar11[5] = '\0';
                pcVar11[6] = '\0';
                pcVar11[7] = '\0';
              }
              else if (iVar10 == 2) {
                iVar10 = piVar13[5];
                puVar7 = (uint *)(*(int *)(__dest + 0x58) + piVar13[4] * 0x10);
                uVar6 = piVar13[0x22];
                iVar8 = piVar13[0x23];
                uVar9 = *puVar7;
                uVar12 = puVar7[1];
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x28) = uVar9 - uVar6;
                *(uint *)(__dest_00 + iVar10 * 0x10 + 0x2c) =
                     (uVar12 - iVar8) - (uint)(uVar9 < uVar6);
                uVar6 = piVar13[0x24];
                iVar8 = piVar13[0x25];
                uVar9 = puVar7[2];
                uVar12 = puVar7[3];
                *(uint *)(__dest_00 + (iVar10 + 3) * 0x10) = uVar9 - uVar6;
                *(uint *)((int)(__dest_00 + (iVar10 + 3) * 0x10) + 4) =
                     (uVar12 - iVar8) - (uint)(uVar9 < uVar6);
              }
              else if (iVar10 == 3) {
                memcpy(__dest_00 + piVar13[5] * 0x10 + 0x28,piVar13 + 0x22,0x10);
              }
            }
          }
          iVar10 = setsockopt(*param_1,0,0x41,__dest_00,__size);
          if (-1 < iVar10) {
            free(*(void **)(__dest + 0x58));
            free(__dest);
            free(__dest_00);
            return 1;
          }
        }
        free(__dest_00);
      }
      free(*(void **)(__dest + 0x58));
    }
    free(__dest);
    return 0;
  }
LAB_0000a620:
  puVar5 = (undefined4 *)__errno();
  *puVar5 = 0xc;
  return 0;
}



/* Function: FUN_0000a75c @ 0000a75c */

bool FUN_0000a75c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x58);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar2 + (uint)*(ushort *)(iVar2 + 0x80) + 0x48);
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x48) = 2;
    *(int *)(*(int *)(param_1 + 0x10) + 0x4c) = param_2 + -1;
    memcpy((void *)(*(int *)(param_1 + 0x10) + 0x38),(void *)(iVar2 + 0x88),0x10);
    *(int *)(*(int *)(param_1 + 0x10) + 100) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x68) = *(undefined4 *)(iVar2 + 0x18);
    FUN_0000a26c(iVar2);
    *(int *)(*(int *)(param_1 + 0x10) + 0x50) = *(int *)(*(int *)(param_1 + 0x10) + 0x50) + -1;
  }
  return iVar1 != 0;
}



/* Function: FUN_0000a7ac @ 0000a7ac */

int FUN_0000a7ac(char *param_1,int param_2,uint *param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = *(uint *)(param_4 + 0x20);
  iVar7 = DAT_0000a898 + 0xa7ca;
  if (uVar3 != 0) {
    iVar5 = *(int *)(param_4 + 0x1c);
    uVar1 = uVar3 >> 1;
    while (uVar4 = uVar1, iVar6 = *(int *)(iVar5 + uVar4 * 4), iVar6 != 0) {
      if (param_5 == 0) {
        iVar5 = strcmp(param_1,(char *)(iVar6 + 8));
      }
      else {
        if (param_5 != 1) {
          fprintf((FILE *)(*(int *)(iVar7 + DAT_0000a89c) + 0xa8),(char *)(DAT_0000a8a0 + 0xa830),
                  param_5);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        iVar5 = param_2 - *(int *)(iVar6 + 0x60);
      }
      *param_3 = uVar4;
      if (iVar5 == 0) {
        return iVar6;
      }
      if (iVar5 < 0) {
        if (uVar4 == 0) {
          return iVar6;
        }
        iVar5 = *(int *)(param_4 + 0x1c);
        uVar1 = uVar4 >> 1;
        uVar3 = uVar4;
      }
      else {
        if (*(int *)(param_4 + 0x20) - 1U == uVar4) {
          return iVar6;
        }
        if (param_5 == 0) {
          iVar5 = *(int *)(param_4 + 0x1c);
          iVar2 = strcmp(param_1,(char *)(*(int *)(iVar5 + (uVar4 + 1) * 4) + 8));
LAB_0000a850:
          if (iVar2 < 0) {
            return iVar6;
          }
        }
        else {
          if (param_5 == 1) {
            iVar5 = *(int *)(param_4 + 0x1c);
            iVar2 = param_2 - *(int *)(*(int *)(iVar5 + (uVar4 + 1) * 4) + 0x60);
            goto LAB_0000a850;
          }
          iVar5 = *(int *)(param_4 + 0x1c);
        }
        uVar1 = uVar4 + uVar3 >> 1;
      }
    }
    fprintf((FILE *)(*(int *)(iVar7 + DAT_0000a89c) + 0xa8),(char *)(DAT_0000a8a4 + 0xa88e),uVar4);
  }
  return param_4 + 8;
}



/* Function: FUN_0000a8a8 @ 0000a8a8 */

int * FUN_0000a8a8(char *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_1c;
  
  local_1c = 0;
  piVar2 = *(int **)(param_2 + 8);
  piVar4 = (int *)(param_2 + 8);
  if (piVar4 != piVar2) {
    do {
      piVar3 = piVar2;
      if (piVar2[10] == 0) break;
      iVar1 = strcmp((char *)(piVar2 + 2),param_1);
      if (iVar1 == 0) {
        return piVar2;
      }
      piVar2 = (int *)*piVar2;
      piVar3 = piVar4;
    } while (piVar4 != piVar2);
    piVar2 = (int *)FUN_0000a7ac(param_1,0,&local_1c,param_2,0);
    if (piVar4 == piVar2) {
      piVar2 = piVar3;
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      piVar3 = (int *)piVar2[1];
      for (piVar2 = (int *)*piVar3; piVar3 != piVar2; piVar2 = (int *)*piVar2) {
        iVar1 = strcmp((char *)(piVar2 + 2),param_1);
        if (iVar1 == 0) {
          return piVar2;
        }
        if ((0 < iVar1) && (piVar2[10] == 0)) {
          return (int *)0x0;
        }
        if (piVar2 == piVar4) {
          return (int *)0x0;
        }
      }
    }
  }
  return (int *)0x0;
}



/* Function: iptc_set_policy @ 0000a940 */

undefined4 iptc_set_policy(undefined4 param_1,char *param_2,void *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = *(undefined4 *)(DAT_0000a9c8 + 0xa94e);
  puVar4 = (undefined4 *)(DAT_0000a9cc + 0xa952);
  *puVar4 = uVar3;
  iVar1 = FUN_0000a8a8(param_1,param_4,uVar3,puVar4,param_4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x28) != 0)) {
    iVar2 = strcmp(param_2,(char *)(DAT_0000a9d0 + 0xa96c));
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 0x30) = 0xfffffffe;
    }
    else {
      iVar2 = strcmp(param_2,(char *)(DAT_0000a9d4 + 0xa97a));
      if (iVar2 != 0) {
        puVar4 = (undefined4 *)__errno();
        *puVar4 = 0x16;
        return 0;
      }
      *(undefined4 *)(iVar1 + 0x30) = 0xffffffff;
    }
    if (param_3 == (void *)0x0) {
      *(undefined4 *)(iVar1 + 0x48) = 0;
    }
    else {
      memcpy((void *)(iVar1 + 0x38),param_3,0x10);
      *(undefined4 *)(iVar1 + 0x48) = 3;
    }
    *(undefined4 *)(param_4 + 4) = 1;
    return 1;
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = 2;
  return 0;
}



/* Function: iptc_get_references @ 0000a9d8 */

bool iptc_get_references(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(DAT_0000aa0c + 0xa9e8) = *(undefined4 *)(DAT_0000aa08 + 0xa9e4);
  iVar1 = FUN_0000a8a8(param_2,param_3);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
  }
  else {
    *param_1 = *(undefined4 *)(iVar1 + 0x2c);
  }
  return iVar1 != 0;
}



/* Function: iptc_zero_counter @ 0000aa10 */

undefined4 iptc_zero_counter(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  *(undefined4 *)(DAT_0000aa7c + 0xaa22) = *(undefined4 *)(DAT_0000aa78 + 0xaa1e);
  iVar1 = FUN_0000a8a8(param_1,param_3);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
  }
  else {
    piVar4 = *(int **)(iVar1 + 0x54);
    if (piVar4 != (int *)(iVar1 + 0x54)) {
      iVar3 = 1;
      if (param_2 != 1) {
        do {
          piVar4 = (int *)*piVar4;
          if (piVar4 == (int *)(iVar1 + 0x54)) goto LAB_0000aa48;
          iVar3 = iVar3 + 1;
        } while (param_2 != iVar3);
      }
      if (piVar4 != (int *)0x0) {
        if (piVar4[3] == 1) {
          piVar4[3] = 2;
        }
        *(undefined4 *)(param_3 + 4) = 1;
        return 1;
      }
    }
LAB_0000aa48:
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 7;
  }
  return 0;
}



/* Function: iptc_read_counter @ 0000aa80 */

int * iptc_read_counter(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  *(undefined4 *)(DAT_0000aadc + 0xaa90) = *(undefined4 *)(DAT_0000aad8 + 0xaa8c);
  iVar1 = FUN_0000a8a8(param_1,param_3);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
  }
  else {
    piVar4 = *(int **)(iVar1 + 0x54);
    piVar2 = (int *)(iVar1 + 0x54);
    if (piVar4 != piVar2) {
      iVar1 = 1;
      if (param_2 != 1) {
        do {
          piVar4 = (int *)*piVar4;
          if (piVar4 == piVar2) goto LAB_0000aab6;
          iVar1 = iVar1 + 1;
        } while (param_2 != iVar1);
      }
      piVar2 = piVar4 + 0x22;
      if (piVar4 != (int *)0x0) {
        return piVar2;
      }
    }
LAB_0000aab6:
    puVar3 = (undefined4 *)__errno(piVar2);
    *puVar3 = 7;
  }
  return (int *)0x0;
}



/* Function: iptc_delete_num_entry @ 0000aae0 */

undefined4 iptc_delete_num_entry(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  *(undefined4 *)(DAT_0000ab88 + 0xaaf2) = *(undefined4 *)(DAT_0000ab84 + 0xaaee);
  iVar1 = FUN_0000a8a8(param_1,param_3);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
    return 0;
  }
  uVar7 = *(uint *)(iVar1 + 0x50);
  if (uVar7 <= param_2) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 7;
    return 0;
  }
  uVar3 = param_2 + 1;
  if (uVar7 >> 1 < uVar3) {
    piVar6 = *(int **)(iVar1 + 0x58);
    if (piVar6 != (int *)(iVar1 + 0x54)) {
      iVar5 = 1;
      if (uVar7 - param_2 != 1) {
        do {
          piVar6 = (int *)piVar6[1];
          if (piVar6 == (int *)(iVar1 + 0x54)) goto LAB_0000ab28;
          iVar5 = iVar5 + 1;
        } while (uVar7 - param_2 != iVar5);
      }
      goto LAB_0000ab2a;
    }
  }
  else {
    piVar6 = *(int **)(iVar1 + 0x54);
    if (piVar6 != (int *)(iVar1 + 0x54)) {
      uVar4 = 1;
      if (uVar3 != 1) {
        do {
          piVar6 = (int *)*piVar6;
          if (piVar6 == (int *)(iVar1 + 0x54)) goto LAB_0000ab28;
          uVar4 = uVar4 + 1;
        } while (uVar3 != uVar4);
      }
      goto LAB_0000ab2a;
    }
  }
LAB_0000ab28:
  piVar6 = (int *)0x0;
LAB_0000ab2a:
  if (*(int **)(param_3 + 0x14) == piVar6) {
    *(int *)(param_3 + 0x14) = piVar6[1];
    uVar7 = *(uint *)(iVar1 + 0x50);
  }
  *(uint *)(iVar1 + 0x50) = uVar7 - 1;
  FUN_0000a26c(piVar6);
  *(undefined4 *)(param_3 + 4) = 1;
  return 1;
}



/* Function: iptc_builtin @ 0000ab8c */

bool iptc_builtin(void)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  *(undefined4 *)(DAT_0000abbc + 0xab9a) = *(undefined4 *)(DAT_0000abb8 + 0xab96);
  iVar1 = FUN_0000a8a8();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
    bVar3 = false;
  }
  else {
    bVar3 = *(int *)(iVar1 + 0x28) != 0;
  }
  return bVar3;
}



/* Function: iptc_first_rule @ 0000abc0 */

int iptc_first_rule(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *(undefined4 *)(DAT_0000abfc + 0xabd0) = *(undefined4 *)(DAT_0000abf8 + 0xabcc);
  iVar1 = FUN_0000a8a8();
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    iVar2 = 0;
  }
  else {
    iVar4 = *(int *)(iVar1 + 0x54);
    iVar2 = 0;
    if (iVar4 != iVar1 + 0x54) {
      *(int *)(param_2 + 0x14) = iVar4;
      iVar2 = iVar4 + 0x28;
    }
  }
  return iVar2;
}



/* Function: iptc_is_chain @ 0000ac00 */

bool iptc_is_chain(void)

{
  int iVar1;
  
  *(undefined4 *)(DAT_0000ac1c + 0xac0e) = *(undefined4 *)(DAT_0000ac18 + 0xac0a);
  iVar1 = FUN_0000a8a8();
  return iVar1 != 0;
}



/* Function: FUN_0000ac20 @ 0000ac20 */

undefined4 FUN_0000ac20(int *param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int local_20;
  int local_1c [2];
  
  piVar1 = (int *)FUN_0000a7ac(param_1 + 2,0,local_1c,param_2,0);
  piVar3 = (int *)param_1[1];
  iVar4 = *param_1;
  uVar2 = 0;
  *(int **)(iVar4 + 4) = piVar3;
  *piVar3 = iVar4;
  *param_1 = DAT_0000ac80;
  param_1[1] = DAT_0000ac84;
  if (param_1 == piVar1) {
    FUN_0000a7ac(iVar4 + 8,0,&local_20,param_2,0);
    if (local_1c[0] == local_20) {
      uVar2 = 0;
      *(int *)(local_1c[0] * 4 + *(int *)(param_2 + 0x1c)) = iVar4;
    }
    else {
      uVar2 = FUN_0000a244(param_2);
    }
  }
  return uVar2;
}



/* Function: iptc_delete_chain @ 0000ac88 */

undefined4 iptc_delete_chain(undefined4 param_1,int param_2)

{
  int *__ptr;
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int local_14;
  
  *(undefined4 *)(DAT_0000ad38 + 0xac98) = *(undefined4 *)(DAT_0000ad34 + 0xac94);
  __ptr = (int *)FUN_0000a8a8();
  if (__ptr == (int *)0x0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    uVar2 = 0;
  }
  else {
    iVar1 = iptc_builtin(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = iptc_get_references(&local_14,param_1,param_2);
      uVar2 = 0;
      if (iVar1 != 0) {
        if (local_14 == 0) {
          if (__ptr[0x14] == 0) {
            if (__ptr == *(int **)(param_2 + 0x10)) {
              if (*__ptr == param_2 + 8) {
                *(undefined4 *)(param_2 + 0x10) = 0;
              }
              else {
                *(int *)(param_2 + 0x10) = *__ptr;
              }
            }
            *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
            FUN_0000ac20(__ptr,param_2);
            free(__ptr);
            *(undefined4 *)(param_2 + 4) = 1;
            uVar2 = 1;
          }
          else {
            puVar3 = (undefined4 *)__errno(0);
            *puVar3 = 0x27;
            uVar2 = 0;
          }
        }
        else {
          puVar3 = (undefined4 *)__errno(0);
          *puVar3 = 0x1f;
          uVar2 = 0;
        }
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x16;
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* Function: FUN_0000ad3c @ 0000ad3c */

void FUN_0000ad3c(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int local_24 [2];
  
  piVar3 = param_2 + 2;
  local_24[0] = 1;
  iVar1 = FUN_0000a7ac(piVar3,0,local_24,param_1,0);
  if (local_24[0] == 0) {
    piVar4 = *(int **)(param_1 + 0x1c);
    iVar2 = strcmp((char *)piVar3,(char *)(*piVar4 + 8));
    if (0 < iVar2) goto LAB_0000ad7e;
    *piVar4 = (int)param_2;
    iVar1 = *(int *)(param_1 + 8);
    if (param_1 + 8 != iVar1) goto LAB_0000ad86;
  }
  else {
LAB_0000ad7e:
    if (param_1 + 8 != iVar1) goto LAB_0000ad86;
  }
  iVar1 = *(int *)(param_1 + 8);
LAB_0000ad86:
  if (param_2[10] == 0) {
    piVar5 = *(int **)(iVar1 + 4);
    for (piVar4 = (int *)*piVar5; piVar5 != piVar4; piVar4 = (int *)*piVar4) {
      if ((piVar4[10] == 0) && (iVar1 = strcmp((char *)piVar3,(char *)(piVar4 + 2)), iVar1 < 1)) {
        piVar3 = (int *)piVar4[1];
        iVar1 = *piVar3;
        *(int **)(iVar1 + 4) = param_2;
        *param_2 = iVar1;
        param_2[1] = (int)piVar3;
        *piVar3 = (int)param_2;
        return;
      }
      if ((int *)(param_1 + 8) == piVar4) break;
    }
  }
  piVar3 = *(int **)(param_1 + 0xc);
  *(int **)(param_1 + 0xc) = param_2;
  *param_2 = param_1 + 8;
  param_2[1] = (int)piVar3;
  *piVar3 = (int)param_2;
  return;
}



/* Function: FUN_0000adec @ 0000adec */

void FUN_0000adec(int param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  FUN_0000a75c(param_1,*param_4);
  param_2[0x18] = param_3;
  param_2[0x17] = *param_4;
  if (((param_2[10] == 0) && (iVar1 = strcmp((char *)(param_2 + 2),(char *)(iVar3 + 8)), iVar1 < 1))
     && (*(int *)(iVar3 + 0x28) == 0)) {
    FUN_0000ad3c(param_1,param_2);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xc);
    *(int **)(param_1 + 0xc) = param_2;
    *param_2 = param_1 + 8;
    param_2[1] = (int)piVar2;
    *piVar2 = (int)param_2;
  }
  *(int **)(param_1 + 0x10) = param_2;
  return;
}



/* Function: FUN_0000ae48 @ 0000ae48 */

undefined * FUN_0000ae48(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == -4) {
    puVar1 = (undefined *)(DAT_0000aea4 + 0xae88);
  }
  else if (param_1 < -3) {
    if (param_1 != -5) {
LAB_0000ae6a:
      fprintf((FILE *)(*(int *)(DAT_0000ae90 + 0xae52 + DAT_0000ae98) + 0xa8),
              (char *)(DAT_0000ae9c + 0xae74),param_1);
                    /* WARNING: Subroutine does not return */
      abort();
    }
    puVar1 = &UNK_0000ae8e + DAT_0000aea8;
  }
  else if (param_1 == -2) {
    puVar1 = (undefined *)(DAT_0000aea0 + 0xae82);
  }
  else {
    if (param_1 != -1) goto LAB_0000ae6a;
    puVar1 = (undefined *)(DAT_0000ae94 + 0xae66);
  }
  return puVar1;
}



/* Function: iptc_get_target @ 0000aeac */

int iptc_get_target(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(DAT_0000aefc + 0xaebc) = *(undefined4 *)(DAT_0000aef8 + 0xaeb8);
  iVar2 = *(int *)(param_1 + -0xc);
  if (iVar2 == 1) {
    iVar1 = param_1 + (uint)*(ushort *)(param_1 + 0x58) + 2;
  }
  else if (iVar2 == 0) {
    iVar1 = FUN_0000ae48(*(undefined4 *)(param_1 + (uint)*(ushort *)(param_1 + 0x58) + 0x20));
  }
  else if (iVar2 == 2) {
    iVar1 = DAT_0000af00 + 0xaeec;
  }
  else {
    iVar1 = 0;
    if (iVar2 == 3) {
      iVar1 = *(int *)(param_1 + -8) + 8;
    }
  }
  return iVar1;
}



/* Function: FUN_0000af04 @ 0000af04 */

undefined4 FUN_0000af04(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  size_t sVar3;
  int iVar4;
  char *__s1;
  
  iVar4 = param_2 + 0x28 + (uint)*(ushort *)(param_2 + 0x80);
  __s1 = (char *)(iVar4 + 2);
  if (*(char *)(iVar4 + 2) == '\0') {
    *(undefined4 *)(param_2 + 0x1c) = 2;
    uVar1 = 1;
  }
  else {
    iVar4 = strcmp(__s1,(char *)(DAT_0000afdc + 0xaf24));
    if (iVar4 == 0) {
      uVar1 = FUN_0000a2a0(param_2,0xfffffffe);
    }
    else {
      iVar4 = strcmp(__s1,(char *)(DAT_0000afe0 + 0xaf32));
      if (iVar4 == 0) {
        uVar1 = FUN_0000a2a0(param_2,0xffffffff);
      }
      else {
        iVar4 = strcmp(__s1,(char *)(DAT_0000afe4 + 0xaf40));
        if (iVar4 == 0) {
          uVar1 = FUN_0000a2a0(param_2,0xfffffffc);
        }
        else {
          iVar4 = strcmp(__s1,(char *)(DAT_0000afe8 + 0xaf4e));
          if (iVar4 == 0) {
            uVar1 = FUN_0000a2a0(param_2,0xfffffffb);
          }
          else {
            iVar4 = iptc_builtin(__s1,param_1);
            if (iVar4 == 0) {
              iVar4 = FUN_0000a8a8(__s1,param_1);
              if (iVar4 == 0) {
                sVar3 = strlen(__s1);
                memset(__s1 + sVar3,0,0x1d - sVar3);
                *(undefined4 *)(param_2 + 0x1c) = 1;
                uVar1 = 1;
                *(undefined4 *)(param_1 + 4) = 1;
              }
              else {
                *(int *)(param_2 + 0x20) = iVar4;
                *(undefined4 *)(param_2 + 0x1c) = 3;
                *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + 1;
                uVar1 = 1;
              }
            }
            else {
              puVar2 = (undefined4 *)__errno();
              *puVar2 = 0x16;
              uVar1 = 0;
            }
          }
        }
      }
    }
  }
  return uVar1;
}



/* Function: iptc_delete_entry @ 0000afec */

undefined4 iptc_delete_entry(undefined4 param_1,void *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  void *__ptr;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  void *__dest;
  void *pvVar6;
  ushort *puVar7;
  int *piVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  int iVar14;
  bool bVar15;
  uint local_48;
  int local_34;
  
  iVar14 = DAT_0000b320 + 0xb002;
  *(undefined4 *)(DAT_0000b328 + 0xb00c) = *(undefined4 *)(iVar14 + DAT_0000b324);
  iVar2 = FUN_0000a8a8(param_1,param_4);
  if (iVar2 != 0) {
    __ptr = (void *)FUN_0000a214(iVar2,*(undefined2 *)((int)param_2 + 0x5a));
    if (__ptr == (void *)0x0) {
      puVar4 = (undefined4 *)__errno();
      *puVar4 = 0xc;
      return 0;
    }
    __dest = (void *)((int)__ptr + 0x28);
    memcpy(__dest,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
    *(undefined4 *)((int)__ptr + 0xc) = 0;
    iVar3 = FUN_0000af04(param_4,__ptr);
    if (iVar3 == 0) {
      free(__ptr);
      return 0;
    }
    if ((*(int *)((int)__ptr + 0x1c) == 3) && (iVar3 = *(int *)((int)__ptr + 0x20), iVar3 != 0)) {
      *(int *)(iVar3 + 0x2c) = *(int *)(iVar3 + 0x2c) + -1;
    }
    piVar13 = *(int **)(iVar2 + 0x54);
    if (piVar13 != (int *)(iVar2 + 0x54)) {
      iVar3 = *(int *)((int)__ptr + 0x28);
      do {
        if ((((piVar13[10] == iVar3) && (*(int *)((int)__ptr + 0x2c) == piVar13[0xb])) &&
            (*(int *)((int)__ptr + 0x30) == piVar13[0xc])) &&
           ((*(int *)((int)__ptr + 0x34) == piVar13[0xd] &&
            (*(int *)((int)__ptr + 0x78) == piVar13[0x1e])))) {
          iVar5 = 0;
          pvVar6 = __dest;
          piVar8 = piVar13 + 10;
          do {
            bVar1 = *(byte *)(piVar8 + 0xc);
            if (((bVar1 != *(byte *)((int)pvVar6 + 0x30)) ||
                ((*(byte *)((int)pvVar6 + 0x10) & bVar1) != (bVar1 & *(byte *)(piVar8 + 4)))) ||
               ((bVar1 = *(byte *)(piVar8 + 0x10), bVar1 != *(byte *)((int)pvVar6 + 0x40) ||
                ((*(byte *)((int)pvVar6 + 0x20) & bVar1) != (bVar1 & *(byte *)(piVar8 + 8))))))
            goto LAB_0000b07e;
            iVar5 = iVar5 + 1;
            pvVar6 = (void *)((int)pvVar6 + 1);
            piVar8 = (int *)((int)piVar8 + 1);
          } while (iVar5 != 0x10);
          if (*(int *)((int)__ptr + 0x80) == piVar13[0x20]) {
            local_34 = param_3 + 0x70;
            for (local_48 = 0x70; local_48 < *(ushort *)((int)__ptr + 0x80);
                local_48 = local_48 + uVar10) {
              puVar7 = (ushort *)((int)__dest + local_48);
              puVar9 = (ushort *)((int)piVar13 + (int)puVar7 + (0x98 - ((int)__ptr + 0x98)));
              uVar10 = (uint)*puVar7;
              if ((*puVar9 != uVar10) ||
                 (iVar5 = strcmp((char *)(puVar7 + 1),(char *)(puVar9 + 1)), iVar5 != 0))
              goto LAB_0000b07e;
              for (uVar11 = 0; uVar11 < uVar10 - 0x20; uVar11 = uVar11 + 1) {
                if (((*(byte *)((int)puVar9 + uVar11 + 0x20) ^
                     *(byte *)((int)puVar7 + uVar11 + 0x20)) & *(byte *)(local_34 + uVar11 + 0x20))
                    != 0) goto LAB_0000b07e;
              }
              local_34 = uVar11 + local_34 + 0x20;
            }
            if (((byte *)(local_34 + 0x20) != (byte *)0x0) &&
               (iVar5 = *(int *)((int)__ptr + 0x1c), iVar5 == piVar13[7])) {
              puVar7 = (ushort *)((int)__dest + (uint)*(ushort *)((int)__ptr + 0x80));
              puVar9 = (ushort *)((int)(piVar13 + 10) + (uint)*(ushort *)(piVar13 + 0x20));
              if (iVar5 == 1) {
                uVar10 = (uint)*puVar9;
                if ((uVar10 == *puVar7) &&
                   (iVar5 = strcmp((char *)(puVar7 + 1),(char *)(puVar9 + 1)), iVar5 == 0)) {
                  if (uVar10 == 0x20) goto LAB_0000b23c;
                  bVar1 = *(byte *)(local_34 + 0x20) & ((byte)puVar7[0x10] ^ (byte)puVar9[0x10]);
                  uVar11 = 0;
                  while (bVar1 == 0) {
                    uVar12 = uVar11 + 1;
                    if (uVar10 - 0x20 <= uVar12) goto LAB_0000b23c;
                    bVar1 = (*(byte *)((int)puVar9 + uVar11 + 0x21) ^
                            *(byte *)((int)puVar7 + uVar11 + 0x21)) &
                            *(byte *)(local_34 + uVar12 + 0x20);
                    uVar11 = uVar12;
                  }
                }
              }
              else {
                if (iVar5 == 0) {
                  bVar15 = *(int *)(puVar7 + 0x10) == *(int *)(puVar9 + 0x10);
                }
                else {
                  if (iVar5 == 2) goto LAB_0000b23c;
                  if (iVar5 != 3) {
                    fprintf((FILE *)(*(int *)(iVar14 + DAT_0000b32c) + 0xa8),
                            (char *)(DAT_0000b330 + 0xb274));
                    /* WARNING: Subroutine does not return */
                    abort();
                  }
                  bVar15 = *(int *)((int)__ptr + 0x20) == piVar13[8];
                }
                if (bVar15) {
LAB_0000b23c:
                  if (*(int **)(param_4 + 0x14) == piVar13) {
                    *(int *)(param_4 + 0x14) = piVar13[1];
                  }
                  *(int *)(iVar2 + 0x50) = *(int *)(iVar2 + 0x50) + -1;
                  FUN_0000a26c(piVar13);
                  *(undefined4 *)(param_4 + 4) = 1;
                  free(__ptr);
                  return 1;
                }
              }
            }
          }
        }
LAB_0000b07e:
        piVar13 = (int *)*piVar13;
      } while (piVar13 != (int *)(iVar2 + 0x54));
    }
    free(__ptr);
  }
  puVar4 = (undefined4 *)__errno();
  *puVar4 = 2;
  return 0;
}



/* Function: iptc_append_entry @ 0000b334 */

undefined4 iptc_append_entry(undefined4 param_1,void *param_2,int param_3)

{
  int iVar1;
  int *__ptr;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  *(undefined4 *)(DAT_0000b3c8 + 0xb34a) = *(undefined4 *)(DAT_0000b3c4 + 0xb346);
  iVar1 = FUN_0000a8a8(param_1,param_3);
  if (iVar1 == 0) {
    puVar4 = (undefined4 *)__errno();
    *puVar4 = 2;
    uVar3 = 0;
  }
  else {
    __ptr = (int *)FUN_0000a214(iVar1,*(undefined2 *)((int)param_2 + 0x5a));
    if (__ptr == (int *)0x0) {
      puVar4 = (undefined4 *)__errno();
      *puVar4 = 0xc;
      uVar3 = 0;
    }
    else {
      memcpy(__ptr + 10,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
      __ptr[3] = 3;
      iVar2 = FUN_0000af04(param_3,__ptr);
      if (iVar2 == 0) {
        free(__ptr);
        uVar3 = 0;
      }
      else {
        puVar4 = *(undefined4 **)(iVar1 + 0x58);
        *(int **)(iVar1 + 0x58) = __ptr;
        *__ptr = iVar1 + 0x54;
        __ptr[1] = (int)puVar4;
        *puVar4 = __ptr;
        uVar3 = 1;
        *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + 1;
        *(undefined4 *)(param_3 + 4) = 1;
      }
    }
  }
  return uVar3;
}



/* Function: iptc_replace_entry @ 0000b3cc */

undefined4 iptc_replace_entry(undefined4 param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  int *__ptr;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  *(undefined4 *)(DAT_0000b4b8 + 0xb3e2) = *(undefined4 *)(DAT_0000b4b4 + 0xb3de);
  iVar1 = FUN_0000a8a8(param_1,param_4);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 2;
    return 0;
  }
  uVar5 = *(uint *)(iVar1 + 0x50);
  if (uVar5 <= param_3) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 7;
    return 0;
  }
  uVar4 = param_3 + 1;
  if (uVar5 >> 1 < uVar4) {
    piVar7 = *(int **)(iVar1 + 0x58);
    if (piVar7 != (int *)(iVar1 + 0x54)) {
      iVar6 = 1;
      if (uVar5 - param_3 != 1) {
        do {
          piVar7 = (int *)piVar7[1];
          if (piVar7 == (int *)(iVar1 + 0x54)) goto LAB_0000b41a;
          iVar6 = iVar6 + 1;
        } while (uVar5 - param_3 != iVar6);
      }
      goto LAB_0000b41c;
    }
  }
  else {
    piVar7 = *(int **)(iVar1 + 0x54);
    if (piVar7 != (int *)(iVar1 + 0x54)) {
      uVar5 = 1;
      if (uVar4 != 1) {
        do {
          piVar7 = (int *)*piVar7;
          if (piVar7 == (int *)(iVar1 + 0x54)) goto LAB_0000b41a;
          uVar5 = uVar5 + 1;
        } while (uVar4 != uVar5);
      }
      goto LAB_0000b41c;
    }
  }
LAB_0000b41a:
  piVar7 = (int *)0x0;
LAB_0000b41c:
  __ptr = (int *)FUN_0000a214(iVar1,*(undefined2 *)((int)param_2 + 0x5a));
  if (__ptr == (int *)0x0) {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0xc;
    uVar2 = 0;
  }
  else {
    memcpy(__ptr + 10,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
    __ptr[3] = 3;
    iVar1 = FUN_0000af04(param_4,__ptr);
    if (iVar1 == 0) {
      free(__ptr);
      uVar2 = 0;
    }
    else {
      iVar1 = *piVar7;
      *(int **)(iVar1 + 4) = __ptr;
      *__ptr = iVar1;
      __ptr[1] = (int)piVar7;
      *piVar7 = (int)__ptr;
      FUN_0000a26c(piVar7);
      *(undefined4 *)(param_4 + 4) = 1;
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* Function: iptc_insert_entry @ 0000b4bc */

undefined4 iptc_insert_entry(undefined4 param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  *(undefined4 *)(DAT_0000b5c0 + 0xb4d4) = *(undefined4 *)(DAT_0000b5bc + 0xb4d0);
  iVar1 = FUN_0000a8a8(param_1,param_4);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 2;
    return 0;
  }
  uVar6 = *(uint *)(iVar1 + 0x50);
  if (uVar6 < param_3) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 7;
    return 0;
  }
  piVar8 = (int *)(iVar1 + 0x54);
  if (uVar6 != param_3) {
    uVar5 = param_3 + 1;
    if (uVar6 >> 1 < uVar5) {
      piVar8 = *(int **)(iVar1 + 0x58);
      if (piVar8 != (int *)(iVar1 + 0x54)) {
        iVar3 = 1;
        if (uVar6 - param_3 != 1) {
          do {
            piVar8 = (int *)piVar8[1];
            if (piVar8 == (int *)(iVar1 + 0x54)) {
              piVar8 = (int *)0x0;
              break;
            }
            iVar3 = iVar3 + 1;
          } while (uVar6 - param_3 != iVar3);
        }
        goto LAB_0000b516;
      }
    }
    else {
      piVar8 = *(int **)(iVar1 + 0x54);
      if (piVar8 != (int *)(iVar1 + 0x54)) {
        uVar6 = 1;
        if (uVar5 != 1) {
          do {
            piVar8 = (int *)*piVar8;
            if (piVar8 == (int *)(iVar1 + 0x54)) goto LAB_0000b514;
            uVar6 = uVar6 + 1;
          } while (uVar5 != uVar6);
        }
        goto LAB_0000b516;
      }
    }
LAB_0000b514:
    piVar8 = (int *)0x0;
  }
LAB_0000b516:
  puVar2 = (undefined4 *)FUN_0000a214(iVar1,*(undefined2 *)((int)param_2 + 0x5a));
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0xc;
    uVar4 = 0;
  }
  else {
    memcpy(puVar2 + 10,param_2,(uint)*(ushort *)((int)param_2 + 0x5a));
    puVar2[3] = 3;
    iVar3 = FUN_0000af04(param_4,puVar2);
    if (iVar3 == 0) {
      free(puVar2);
      uVar4 = 0;
    }
    else {
      puVar7 = (undefined4 *)piVar8[1];
      piVar8[1] = (int)puVar2;
      *puVar2 = piVar8;
      puVar2[1] = puVar7;
      *puVar7 = puVar2;
      uVar4 = 1;
      *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + 1;
      *(undefined4 *)(param_4 + 4) = 1;
    }
  }
  return uVar4;
}



/* Function: FUN_0000b5c4 @ 0000b5c4 */

void * FUN_0000b5c4(char *param_1,undefined4 param_2)

{
  void *__s;
  
  __s = malloc(0x70);
  if (__s != (void *)0x0) {
    memset(__s,0,0x70);
    strncpy((char *)((int)__s + 8),param_1,0x1e);
    *(undefined4 *)((int)__s + 0x28) = param_2;
    *(int *)((int)__s + 0x54) = (int)__s + 0x54;
    *(int *)((int)__s + 0x58) = (int)__s + 0x54;
  }
  return __s;
}



/* Function: iptc_create_chain @ 0000b5f8 */

undefined4 iptc_create_chain(char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  size_t sVar5;
  
  iVar1 = DAT_0000b6bc;
  *(undefined4 *)(DAT_0000b6bc + 0xb608) = *(undefined4 *)(DAT_0000b6b8 + 0xb604);
  iVar2 = FUN_0000a8a8();
  if ((((iVar2 == 0) && (iVar2 = strcmp(param_1,(char *)(DAT_0000b6c0 + 0xb626)), iVar2 != 0)) &&
      (iVar2 = strcmp(param_1,(char *)(DAT_0000b6c4 + 0xb634)), iVar2 != 0)) &&
     ((iVar2 = strcmp(param_1,(char *)(DAT_0000b6c8 + 0xb642)), iVar2 != 0 &&
      (iVar2 = strcmp(param_1,(char *)(DAT_0000b6cc + 0xb650)), iVar2 != 0)))) {
    sVar5 = strlen(param_1);
    if (sVar5 + 1 < 0x21) {
      iVar2 = FUN_0000b5c4(param_1,0);
      *(int *)(iVar1 + 0xb60c) = iVar2;
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)__errno(0,0);
        *puVar3 = 0xc;
        uVar4 = 0;
      }
      else {
        *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
        FUN_0000ad3c(param_2);
        if (DAT_0000b6d0 < *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x20) * -0x28) {
          FUN_0000a244(param_2);
        }
        *(undefined4 *)(param_2 + 4) = 1;
        uVar4 = 1;
      }
    }
    else {
      puVar3 = (undefined4 *)__errno();
      *puVar3 = 0x16;
      uVar4 = 0;
    }
  }
  else {
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x11;
    uVar4 = 0;
  }
  return uVar4;
}



/* Function: iptc_free @ 0000b6d4 */

void iptc_free(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *__ptr;
  int *piVar3;
  int *piVar4;
  
  *(undefined4 *)(DAT_0000b754 + 0xb6ea) = *(undefined4 *)(DAT_0000b750 + 0xb6e6);
  close(*param_1);
  piVar3 = *(int **)param_1[2];
  __ptr = (int *)param_1[2];
  while (piVar1 = piVar3, __ptr != param_1 + 2) {
    piVar4 = *(int **)__ptr[0x15];
    piVar3 = (int *)__ptr[0x15];
    while (piVar2 = piVar4, piVar3 != __ptr + 0x15) {
      free(piVar3);
      piVar4 = (int *)*piVar2;
      piVar3 = piVar2;
    }
    free(__ptr);
    piVar3 = (int *)*piVar1;
    __ptr = piVar1;
  }
  param_1[8] = 0;
  free((void *)param_1[7]);
  free((void *)param_1[0x1f]);
  free(param_1);
  return;
}



/* Function: iptc_init @ 0000b758 */

void iptc_init(char *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  size_t sVar4;
  undefined4 *puVar5;
  int __fd;
  int iVar6;
  char *__dest;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  char *__s2;
  uint uVar13;
  short *psVar14;
  int *piVar15;
  int *piVar16;
  void *__src;
  uint uVar17;
  int *piVar18;
  int *local_a4;
  undefined1 auStack_90 [4];
  int local_8c;
  socklen_t local_88;
  socklen_t local_84;
  char acStack_80 [80];
  int local_30;
  int local_2c;
  
  iVar3 = DAT_0000ba9c;
  iVar11 = DAT_0000ba98 + 0xb76e;
  local_2c = **(int **)(iVar11 + DAT_0000ba9c);
  *(undefined4 *)(DAT_0000baa4 + 0xb782) = *(undefined4 *)(iVar11 + DAT_0000baa0);
  sVar4 = strlen(param_1);
  if (sVar4 < 0x1e) {
    __fd = socket(2,3,0xff);
    if (-1 < __fd) {
      __s2 = (char *)(DAT_0000baa8 + 0xb7de);
      do {
        local_88 = 0x54;
        strcpy(acStack_80,param_1);
        iVar6 = getsockopt(__fd,0,0x40,acStack_80,&local_88);
        iVar7 = local_30;
        if (iVar6 < 0) {
          close(__fd);
          local_a4 = (int *)0x0;
          goto LAB_0000b796;
        }
        local_a4 = malloc(0x80);
        if (local_a4 == (int *)0x0) {
          puVar5 = (undefined4 *)__errno();
          *puVar5 = 0xc;
LAB_0000bacc:
          close(__fd);
          local_a4 = (int *)0x0;
          goto LAB_0000b796;
        }
        memset(local_a4,0,0x80);
        piVar10 = local_a4 + 2;
        local_a4[2] = (int)piVar10;
        local_a4[3] = (int)piVar10;
        strcpy((char *)(local_a4 + 10),acStack_80);
        __dest = malloc(iVar7 + 0x28);
        local_a4[0x1f] = (int)__dest;
        if (__dest == (char *)0x0) {
          free(local_a4);
          goto LAB_0000bacc;
        }
        strcpy(__dest,acStack_80);
        *(int *)(local_a4[0x1f] + 0x20) = iVar7;
        *local_a4 = __fd;
        memcpy(local_a4 + 10,acStack_80,0x54);
        *(int *)(local_a4[0x1f] + 0x20) = local_a4[0x1e];
        local_84 = local_a4[0x1e] + 0x28;
        iVar7 = getsockopt(*local_a4,0,0x41,(void *)local_a4[0x1f],&local_84);
        if (-1 < iVar7) {
          local_8c = 0;
          iVar7 = local_a4[0x1f];
          local_a4[9] = 1;
          uVar13 = *(uint *)(iVar7 + 0x20);
          if (uVar13 != 0) {
            uVar17 = 0;
            iVar6 = DAT_0000baac + 0xb89a;
            do {
              iVar7 = iVar7 + 0x28;
              __src = (void *)(iVar7 + uVar17);
              uVar1 = *(ushort *)((int)__src + 0x5a);
              iVar12 = (int)__src - iVar7;
              if (uVar13 == iVar12 + (uint)uVar1) {
                FUN_0000a75c(local_a4,local_8c);
                local_a4[4] = 0;
              }
              else {
                uVar2 = *(ushort *)((int)__src + 0x58);
                iVar8 = strcmp((char *)((int)__src + uVar2 + 2),__s2);
                if (iVar8 == 0) {
                  iVar7 = FUN_0000b5c4((int)__src + uVar2 + 0x20,0);
                  if (iVar7 == 0) {
LAB_0000baba:
                    puVar5 = (undefined4 *)__errno();
                    *puVar5 = 0xfffffff4;
                    break;
                  }
                  local_a4[6] = local_a4[6] + 1;
                  FUN_0000adec(local_a4,iVar7,iVar12,&local_8c);
                }
                else {
                  piVar18 = local_a4 + 0x13;
                  uVar13 = 0;
                  do {
                    if (((1 << (uVar13 & 0xff) & local_a4[0x12]) != 0) &&
                       (__src == (void *)(iVar7 + *piVar18))) {
                      iVar7 = uVar13 + 1;
                      if (iVar7 != 0) {
                        iVar8 = FUN_0000b5c4(*(undefined4 *)(uVar13 * 4 + iVar6),iVar7);
                        if (iVar8 == 0) goto LAB_0000baba;
                        *(int *)(iVar8 + 0x28) = iVar7;
                        FUN_0000adec(local_a4,iVar8,iVar12,&local_8c);
                        piVar18 = (int *)FUN_0000a214(local_a4[4],*(undefined2 *)((int)__src + 0x5a)
                                                     );
                        if (piVar18 != (int *)0x0) goto LAB_0000b8fc;
                        goto LAB_0000ba88;
                      }
                      break;
                    }
                    uVar13 = uVar13 + 1;
                    piVar18 = piVar18 + 1;
                  } while (uVar13 != 5);
                  piVar18 = (int *)FUN_0000a214(local_a4[4],(uint)uVar1);
                  if (piVar18 == (int *)0x0) {
LAB_0000ba88:
                    puVar5 = (undefined4 *)__errno();
                    *puVar5 = 0xc;
                    break;
                  }
LAB_0000b8fc:
                  piVar18[5] = local_8c;
                  piVar18[6] = iVar12;
                  memcpy(piVar18 + 10,__src,(uint)*(ushort *)((int)__src + 0x5a));
                  piVar18[3] = 1;
                  piVar18[4] = piVar18[5];
                  psVar14 = (short *)((int)__src + (uint)*(ushort *)((int)__src + 0x58));
                  if ((char)psVar14[1] == '\0') {
                    if (*psVar14 != 0x28) {
                      puVar5 = (undefined4 *)__errno();
                      *puVar5 = 0x16;
                      break;
                    }
                    if (*(int *)(psVar14 + 0x10) < 0) {
                      piVar18[7] = 0;
                    }
                    else if (*(int *)(psVar14 + 0x10) ==
                             (uint)*(ushort *)((int)__src + 0x5a) + piVar18[6]) {
                      piVar18[7] = 2;
                    }
                    else {
                      piVar18[7] = 3;
                    }
                  }
                  else {
                    piVar18[7] = 1;
                  }
                  iVar7 = local_a4[4];
                  puVar5 = *(undefined4 **)(iVar7 + 0x58);
                  *(int **)(iVar7 + 0x58) = piVar18;
                  *piVar18 = iVar7 + 0x54;
                  piVar18[1] = (int)puVar5;
                  *puVar5 = piVar18;
                  *(int *)(local_a4[4] + 0x50) = *(int *)(local_a4[4] + 0x50) + 1;
                }
              }
              local_8c = local_8c + 1;
              iVar7 = local_a4[0x1f];
              uVar17 = uVar17 + *(ushort *)((int)__src + 0x5a);
              uVar13 = *(uint *)(iVar7 + 0x20);
            } while (uVar17 < uVar13);
          }
          iVar7 = FUN_0000a1cc(local_a4);
          if (-1 < iVar7) {
            FUN_0000a0e8(local_a4);
            for (piVar18 = (int *)local_a4[2]; piVar10 != piVar18; piVar18 = (int *)*piVar18) {
              for (piVar16 = (int *)piVar18[0x15]; piVar16 != piVar18 + 0x15;
                  piVar16 = (int *)*piVar16) {
                if (piVar16[7] == 3) {
                  piVar9 = (int *)local_a4[2];
                  uVar13 = *(uint *)((int)piVar16 + *(ushort *)(piVar16 + 0x20) + 0x48);
                  if (piVar10 == piVar9) goto LAB_0000b9e4;
                  if (local_a4[9] != 0) {
                    piVar9 = (int *)FUN_0000a7ac(0,uVar13,auStack_90,local_a4,1);
                  }
                  piVar15 = *(int **)piVar9[1];
                  while( true ) {
                    if ((int *)piVar9[1] == piVar15) goto LAB_0000b9e4;
                    if (((uint)piVar15[0x18] <= uVar13) && (uVar13 <= (uint)piVar15[0x1a])) break;
                    piVar15 = (int *)*piVar15;
                  }
                  piVar16[8] = (int)piVar15;
                  piVar15[0xb] = piVar15[0xb] + 1;
                }
              }
            }
            goto LAB_0000b796;
          }
        }
LAB_0000b9e4:
        iptc_free(local_a4);
        piVar10 = (int *)__errno();
      } while (*piVar10 == 0xb);
    }
    local_a4 = (int *)0x0;
  }
  else {
    puVar5 = (undefined4 *)__errno();
    *puVar5 = 0x16;
    local_a4 = (int *)0x0;
  }
LAB_0000b796:
  if (local_2c != **(int **)(iVar11 + iVar3)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_a4);
  }
  return;
}



/* Function: __aeabi_uidiv @ 0000baf4 */

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



/* Function: __aeabi_uidivmod @ 0000bba0 */

void __aeabi_uidivmod(void)

{
  __aeabi_uidiv();
  return;
}



/* Function: __div0 @ 0000bbb8 */

void __div0(void)

{
  raise(8);
  return;
}



/* Function: _Unwind_VRS_Get @ 0000bbc8 */

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



/* Function: _Unwind_VRS_Set @ 0000bc14 */

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



/* Function: FUN_0000bc60 @ 0000bc60 */

int FUN_0000bc60(uint *param_1)

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



/* Function: _Unwind_GetCFA @ 0000bc78 */

undefined4 _Unwind_GetCFA(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* Function: _Unwind_Complete @ 0000bc80 */

void _Unwind_Complete(void)

{
  return;
}



/* Function: _Unwind_DeleteException @ 0000bc84 */

void _Unwind_DeleteException(int param_1)

{
  if (*(code **)(param_1 + 8) == (code *)0x0) {
    return;
  }
  (**(code **)(param_1 + 8))(1,param_1);
  return;
}



/* Function: __aeabi_unwind_cpp_pr2 @ 0000c138 */

/* WARNING: Removing unreachable block (ram,0x0000bcd8) */
/* WARNING: Removing unreachable block (ram,0x0000bd54) */
/* WARNING: Removing unreachable block (ram,0x0000bd74) */

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
LAB_0000c09c:
    do {
      while( true ) {
        uVar5 = *puVar9;
        if (uVar5 == 0) goto LAB_0000c0a8;
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
LAB_0000bf9c:
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
            local_30 = FUN_0000bc60(puVar7);
            _Unwind_VRS_Set(param_3,0,0xf,0,&local_30);
LAB_0000c060:
            uVar4 = 0;
            local_30 = param_2;
            goto LAB_0000c11c;
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
              if (local_58 == uVar5) goto LAB_0000bf9c;
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
              local_30 = FUN_0000bc60(puVar7 + uVar5 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&local_30);
              goto LAB_0000c060;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 3;
        }
        puVar9 = puVar7 + uVar5 + 1;
        goto LAB_0000c09c;
      }
      if (uVar8 == 0) {
        bVar1 = false;
      }
      puVar9 = puVar9 + 3;
    } while (!bVar1);
    uVar5 = FUN_0000bc60(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      local_30 = uVar5;
      goto LAB_0000c11c;
    }
  }
  else {
    bVar11 = false;
LAB_0000c0a8:
    iVar3 = __gnu_unwind_execute(param_3,&local_3c);
    if (iVar3 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&local_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&local_30);
      uVar4 = 0xf;
      local_30 = *(uint *)(DAT_0000c134 + 0xc10c);
LAB_0000c11c:
      _Unwind_VRS_Set(param_3,0,uVar4,0,&local_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr1 @ 0000c140 */

/* WARNING: Removing unreachable block (ram,0x0000bcd8) */
/* WARNING: Removing unreachable block (ram,0x0000bd58) */
/* WARNING: Removing unreachable block (ram,0x0000bd70) */

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
LAB_0000c09c:
    do {
      while( true ) {
        if (*puVar10 == 0) goto LAB_0000c0a8;
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
LAB_0000bf9c:
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
            uStack_30 = FUN_0000bc60(puVar8);
            _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
LAB_0000c060:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_0000c11c;
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
              if (uStack_58 == uVar6) goto LAB_0000bf9c;
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
              uStack_30 = FUN_0000bc60(puVar8 + uVar6 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
              goto LAB_0000c060;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar8 < 0) {
          puVar8 = puVar10 + 2;
        }
        puVar10 = puVar8 + uVar6 + 1;
        goto LAB_0000c09c;
      }
      if (uVar9 == 0) {
        bVar2 = false;
      }
      puVar10 = puVar10 + 2;
    } while (!bVar2);
    uVar6 = FUN_0000bc60(puVar8);
    *(uint **)(param_2 + 0x38) = puVar10;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar6;
      goto LAB_0000c11c;
    }
  }
  else {
    bVar11 = false;
LAB_0000c0a8:
    iVar4 = __gnu_unwind_execute(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_0000c134 + 0xc10c);
LAB_0000c11c:
      _Unwind_VRS_Set(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr0 @ 0000c148 */

/* WARNING: Removing unreachable block (ram,0x0000bcf4) */
/* WARNING: Removing unreachable block (ram,0x0000bd58) */
/* WARNING: Removing unreachable block (ram,0x0000bd70) */

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
LAB_0000c09c:
    do {
      while( true ) {
        if (*puVar9 == 0) goto LAB_0000c0a8;
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
LAB_0000bf9c:
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
            uStack_30 = FUN_0000bc60(puVar7);
            _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
LAB_0000c060:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_0000c11c;
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
              if (uStack_58 == uVar10) goto LAB_0000bf9c;
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
              uStack_30 = FUN_0000bc60(puVar7 + uVar10 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
              goto LAB_0000c060;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 2;
        }
        puVar9 = puVar7 + uVar10 + 1;
        goto LAB_0000c09c;
      }
      if (uVar8 == 0) {
        bVar2 = false;
      }
      puVar9 = puVar9 + 2;
    } while (!bVar2);
    uVar8 = FUN_0000bc60(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar8;
      goto LAB_0000c11c;
    }
  }
  else {
    bVar11 = false;
LAB_0000c0a8:
    iVar4 = __gnu_unwind_execute(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_0000c134 + 0xc10c);
LAB_0000c11c:
      _Unwind_VRS_Set(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: FUN_0000c150 @ 0000c150 */

undefined4 FUN_0000c150(int param_1,int param_2)

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
  
  iVar8 = DAT_0000c304 + 0xc164;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_0000c308) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_0000c310);
    local_2c[0] = *(int *)(iVar8 + DAT_0000c30c) - iVar2 >> 3;
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
        uVar3 = FUN_0000bc60(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_0000bc60(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_0000c2dc;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_0000bc60(iVar10);
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
        uVar5 = FUN_0000bc60();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_0000bc60();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_0000c314;
      if (((uVar9 == 0) || (iVar2 = DAT_0000c318, uVar9 == 1)) || (iVar2 = DAT_0000c31c, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_0000c2dc:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}



/* Function: FUN_0000c320 @ 0000c320 */

void FUN_0000c320(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      __gnu_Unwind_Restore_VFP(param_1 + 0x12);
    }
    else {
      FUN_0000cab0();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_0000cac0(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_0000cad0(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_0000cb58(param_1 + 0x8c);
  return;
}



/* Function: __gnu_Unwind_Backtrace @ 0000c38c */

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
    iVar1 = FUN_0000c150(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_0000c448:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    _Unwind_VRS_Set(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_0000c448;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_0000c320(&local_2c0);
  return iVar1;
}



/* Function: FUN_0000c460 @ 0000c460 */

int FUN_0000c460(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_0000c150(param_1,local_228);
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



/* Function: __gnu_Unwind_ForcedUnwind @ 0000c57c */

void __gnu_Unwind_ForcedUnwind(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_4 + 0x40) = *(undefined4 *)(param_4 + 0x3c);
  FUN_0000c460(param_1,param_4,0);
  return;
}



/* Function: FUN_0000c598 @ 0000c598 */

undefined4 FUN_0000c598(int param_1,int param_2)

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
    iVar1 = FUN_0000c150(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_0000c5e4;
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
      iVar2 = FUN_0000c150(iVar1,uStack_228);
      if (iVar2 != 0) {
        return 9;
      }
      iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&uStack_268);
    } while (iVar2 == 8);
    FUN_0000c320(&uStack_268);
    if (iVar2 == 6) {
      FUN_0000c598(iVar1,iVar3);
    }
    return 9;
  }
LAB_0000c5e4:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: __gnu_Unwind_RaiseException @ 0000c5f0 */

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
    iVar1 = FUN_0000c150(param_1,local_218);
    if (iVar1 != 0) {
      return 9;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(0,param_1,&local_258);
  } while (iVar1 == 8);
  FUN_0000c320(&local_258);
  if (iVar1 == 6) {
    FUN_0000c598(param_1,param_2);
  }
  return 9;
}



/* Function: __gnu_Unwind_Resume_or_Rethrow @ 0000c694 */

void __gnu_Unwind_Resume_or_Rethrow(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    __gnu_Unwind_RaiseException();
    return;
  }
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  FUN_0000c460(param_1,param_2,0);
  return;
}



/* Function: __gnu_Unwind_Resume @ 0000c6b4 */

void __gnu_Unwind_Resume(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (**(code **)(param_1 + 0x10))(2,param_1,param_2);
    if (iVar1 == 7) {
      restore_core_regs(param_2 + 4);
    }
    else if (iVar1 != 8) goto LAB_0000c71c;
    FUN_0000c598(param_1,param_2);
  }
  else {
    FUN_0000c460(param_1,param_2,1);
  }
LAB_0000c71c:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_VRS_Pop @ 0000c720 */

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
        FUN_0000cab8();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        __gnu_Unwind_Save_VFP(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_0000cac8(param_1 + 0x34);
    }
    if (bVar8) {
      __gnu_Unwind_Save_VFP(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000cab8(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_0000c8bc;
      FUN_0000cac8(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_0000c8bc:
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
        FUN_0000cab0(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_0000cac0(local_b0);
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
          FUN_0000cb14(param_1 + 0x6c);
        }
        FUN_0000cb14(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_0000cad0(auStack_130);
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
        FUN_0000cb6c(param_1 + 0x8c);
      }
      FUN_0000cb6c(local_30);
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
      FUN_0000cb58(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: restore_core_regs @ 0000ca8c */

undefined8 restore_core_regs(undefined8 *param_1)

{
  return *param_1;
}



/* Function: __gnu_Unwind_Restore_VFP @ 0000caa0 */

undefined4 __gnu_Unwind_Restore_VFP(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: __gnu_Unwind_Save_VFP @ 0000caa8 */

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



/* Function: FUN_0000cab0 @ 0000cab0 */

undefined4 FUN_0000cab0(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0000cab8 @ 0000cab8 */

void FUN_0000cab8(undefined8 *param_1)

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



/* Function: FUN_0000cac0 @ 0000cac0 */

void FUN_0000cac0(void)

{
  return;
}



/* Function: FUN_0000cac8 @ 0000cac8 */

void FUN_0000cac8(undefined8 *param_1)

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



/* Function: FUN_0000cad0 @ 0000cad0 */

int FUN_0000cad0(int param_1)

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



/* Function: FUN_0000cb14 @ 0000cb14 */

int FUN_0000cb14(int param_1)

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



/* Function: FUN_0000cb58 @ 0000cb58 */

int FUN_0000cb58(int param_1)

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



/* Function: FUN_0000cb6c @ 0000cb6c */

int FUN_0000cb6c(int param_1)

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



/* Function: _Unwind_RaiseException @ 0000cb80 */

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



/* Function: _Unwind_Resume @ 0000cba4 */

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



/* Function: ___Unwind_Resume_or_Rethrow @ 0000cbc8 */

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



/* Function: _Unwind_ForcedUnwind @ 0000cbec */

void _Unwind_ForcedUnwind(void)

{
  __gnu_Unwind_ForcedUnwind();
  return;
}



/* Function: ___Unwind_Backtrace @ 0000cc10 */

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



/* Function: FUN_0000cc34 @ 0000cc34 */

uint FUN_0000cc34(uint *param_1)

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



/* Function: _Unwind_GetTextRelBase @ 0000cc8c */

void _Unwind_GetTextRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_GetDataRelBase @ 0000cc94 */

void _Unwind_GetDataRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_GetLanguageSpecificData @ 0000cc9c */

int _Unwind_GetLanguageSpecificData(void)

{
  int in_r3;
  
  _Unwind_VRS_Get();
  return *(int *)(in_r3 + 0x4c) + (uint)*(byte *)(*(int *)(in_r3 + 0x4c) + 7) * 4 + 8;
}



/* Function: _Unwind_GetRegionStart @ 0000ccd4 */

undefined4 _Unwind_GetRegionStart(void)

{
  int in_r3;
  
  _Unwind_VRS_Get();
  return *(undefined4 *)(in_r3 + 0x48);
}



/* Function: __gnu_unwind_execute @ 0000cd00 */

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
LAB_0000cd18:
  do {
    while( true ) {
      uVar1 = FUN_0000cc34(param_2);
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
LAB_0000ce50:
      piVar6 = &local_24;
      _Unwind_VRS_Set(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_0000cc34(param_2);
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
      goto LAB_0000cd18;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      _Unwind_VRS_Get(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_0000ce50;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_0000cc34(param_2);
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
            uVar3 = FUN_0000cc34(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_0000ce50;
        }
        if (uVar1 == 0xb3) {
          FUN_0000cc34(param_2);
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
        FUN_0000cc34(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_0000cc34(param_2);
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
            FUN_0000cc34(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_0000cc34(param_2);
          }
          goto LAB_0000d054;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_0000d054:
      uVar2 = 1;
    }
    iVar5 = _Unwind_VRS_Pop(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: __gnu_unwind_frame @ 0000d078 */

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



/* Function: putchar @ 0000f000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int putchar(int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcpy @ 0000f004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: printf @ 0000f008 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strerror @ 0000f00c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __errno @ 0000f014 */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_begin_cleanup @ 0000f018 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 0000f01c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 0000f020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: puts @ 0000f024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 0000f028 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: socket @ 0000f02c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 0000f030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 0000f034 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __libc_init @ 0000f038 */

/* WARNING: Control flow encountered bad instruction data */

void __libc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fprintf @ 0000f03c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: inet_addr @ 0000f040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

in_addr_t inet_addr(char *__cp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setsockopt @ 0000f044 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t __optlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncpy @ 0000f048 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 0000f04c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 0000f054 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: inet_ntoa @ 0000f058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * inet_ntoa(in_addr __in)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 0000f05c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 0000f060 */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getsockopt @ 0000f064 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: exit @ 0000f068 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: atoi @ 0000f06c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 0000f070 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: close @ 0000f074 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: raise @ 0000f078 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 0000f07c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



