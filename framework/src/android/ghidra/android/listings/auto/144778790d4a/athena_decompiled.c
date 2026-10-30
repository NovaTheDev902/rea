/* Function: strcpy @ 00009170 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_0000c7f8)(__dest);
  return pcVar1;
}



/* Function: printf @ 0000917c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_0000c7fc)(__format);
  return iVar1;
}



/* Function: recv @ 00009188 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t recv(int __fd,void *__buf,size_t __n,int __flags)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_recv_0000c800)(__fd);
  return sVar1;
}



/* Function: strerror @ 00009194 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strerror_0000c804)(__errnum);
  return pcVar1;
}



/* Function: __errno @ 000091a0 */

void __errno(void)

{
  (*(code *)PTR___errno_0000c808)();
  return;
}



/* Function: __cxa_begin_cleanup @ 000091ac */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_0000c80c)();
  return;
}



/* Function: getpid @ 000091b8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_getpid_0000c810)();
  return _Var1;
}



/* Function: memcpy @ 000091c4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0000c814)(__dest);
  return pvVar1;
}



/* Function: setitimer @ 000091d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setitimer(__itimer_which_t __which,itimerval *__new,itimerval *__old)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setitimer_0000c818)(__which);
  return iVar1;
}



/* Function: dup2 @ 000091dc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup2(int __fd,int __fd2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_dup2_0000c81c)(__fd);
  return iVar1;
}



/* Function: execle @ 000091e8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int execle(char *__path,char *__arg,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_execle_0000c820)(__path);
  return iVar1;
}



/* Function: malloc @ 000091f4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_0000c824)(__size);
  return pvVar1;
}



/* Function: socket @ 00009200 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_0000c828)(__domain);
  return iVar1;
}



/* Function: readdir @ 0000920c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

dirent * readdir(DIR *__dirp)

{
  dirent *pdVar1;
  
  pdVar1 = (dirent *)(*(code *)PTR_readdir_0000c82c)(__dirp);
  return pdVar1;
}



/* Function: send @ 00009218 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t send(int __fd,void *__buf,size_t __n,int __flags)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_send_0000c830)(__fd);
  return sVar1;
}



/* Function: abort @ 00009224 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_0000c834)();
  return;
}



/* Function: __stack_chk_fail @ 00009230 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_0000c838)();
  return;
}



/* Function: pipe @ 0000923c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pipe(int *__pipedes)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pipe_0000c83c)(__pipedes);
  return iVar1;
}



/* Function: accept @ 00009248 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_accept_0000c840)(__fd);
  return iVar1;
}



/* Function: write @ 00009260 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_0000c848)(__fd);
  return sVar1;
}



/* Function: fprintf @ 0000926c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fprintf_0000c84c)(__stream);
  return iVar1;
}



/* Function: kill @ 00009278 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int kill(__pid_t __pid,int __sig)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_kill_0000c850)(__pid);
  return iVar1;
}



/* Function: bind @ 00009284 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_bind_0000c854)(__fd);
  return iVar1;
}



/* Function: bsd_signal @ 00009290 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t bsd_signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
  p_Var1 = (__sighandler_t)(*(code *)PTR_bsd_signal_0000c858)(__sig);
  return p_Var1;
}



/* Function: read @ 0000929c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_0000c85c)(__fd);
  return sVar1;
}



/* Function: strncmp @ 000092a8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strncmp_0000c860)(__s1);
  return iVar1;
}



/* Function: unlink @ 000092b4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_unlink_0000c864)(__name);
  return iVar1;
}



/* Function: __cxa_type_match @ 000092c0 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_0000c868)();
  return;
}



/* Function: realloc @ 000092cc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_realloc_0000c86c)(__ptr);
  return pvVar1;
}



/* Function: strtok @ 000092d8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strtok_0000c870)(__s);
  return pcVar1;
}



/* Function: listen @ 000092e4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_listen_0000c874)(__fd);
  return iVar1;
}



/* Function: fork @ 000092f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t fork(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_fork_0000c878)();
  return _Var1;
}



/* Function: getppid @ 000092fc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getppid(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_getppid_0000c87c)();
  return _Var1;
}



/* Function: opendir @ 00009308 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * opendir(char *__name)

{
  DIR *pDVar1;
  
  pDVar1 = (DIR *)(*(code *)PTR_opendir_0000c880)(__name);
  return pDVar1;
}



/* Function: strcmp @ 00009314 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_0000c884)(__s1);
  return iVar1;
}



/* Function: __gnu_Unwind_Find_exidx @ 00009320 */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_0000c888)();
  return;
}



/* Function: sprintf @ 0000932c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sprintf_0000c88c)(__s);
  return iVar1;
}



/* Function: getsockopt @ 00009338 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_getsockopt_0000c890)(__fd);
  return iVar1;
}



/* Function: fwrite @ 00009344 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_0000c894)(__ptr);
  return sVar1;
}



/* Function: exit @ 00009350 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
  (*(code *)PTR_exit_0000c898)(__status);
  return;
}



/* Function: atoi @ 0000935c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_atoi_0000c89c)(__nptr);
  return iVar1;
}



/* Function: strlen @ 00009368 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_0000c8a0)(__s);
  return sVar1;
}



/* Function: open @ 00009374 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_0000c8a4)(__file);
  return iVar1;
}



/* Function: closedir @ 00009380 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int closedir(DIR *__dirp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_closedir_0000c8a8)(__dirp);
  return iVar1;
}



/* Function: close @ 0000938c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_0000c8ac)(__fd);
  return iVar1;
}



/* Function: raise @ 00009398 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_raise_0000c8b0)(__sig);
  return iVar1;
}



/* Function: free @ 000093a4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_0000c8b4)(__ptr);
  return;
}



/* Function: entry @ 000093b0 */

void processEntry entry(void)

{
  (*(code *)PTR___libc_init_0000c844)();
  return;
}



/* Function: FUN_000093e0 @ 000093e0 */

void FUN_000093e0(int param_1,int *param_2)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_2;
  iVar2 = DAT_0000940c + 0x93f0;
  sVar1 = send(param_1,param_2,iVar3 + 4U,0);
  if (iVar3 + 4U != sVar1) {
    fprintf((FILE *)(*(int *)(iVar2 + DAT_00009410) + 0xa8),(char *)(DAT_00009414 + 0x9404),param_1)
    ;
  }
  return;
}



/* Function: FUN_00009418 @ 00009418 */

void * FUN_00009418(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *__buf;
  ssize_t sVar1;
  char *__format;
  int extraout_r3;
  int iVar2;
  int iVar3;
  int iVar4;
  
  __buf = malloc(0xc);
  iVar3 = DAT_00009494 + 0x9432;
  sVar1 = recv(param_1,__buf,0xc,0);
  if (sVar1 == 0xc) {
    iVar4 = *(int *)((int)__buf + 8);
    __buf = realloc(__buf,iVar4 + 0xd);
    sVar1 = recv(param_1,(void *)((int)__buf + 0xc),*(size_t *)((int)__buf + 8),0);
    iVar2 = *(int *)((int)__buf + 8);
    if (sVar1 == iVar2) {
      *(undefined1 *)((int)__buf + (iVar4 + 0xc) * 0xc) = 0;
      return __buf;
    }
    iVar3 = *(int *)(iVar3 + DAT_00009498);
    __format = (char *)(DAT_000094a0 + 0x9490);
  }
  else {
    iVar3 = *(int *)(iVar3 + DAT_00009498);
    __format = (char *)(DAT_0000949c + 0x9476);
    iVar2 = extraout_r3;
  }
  fprintf((FILE *)(iVar3 + 0xa8),__format,param_1,iVar2,param_4);
  free(__buf);
  return (void *)0x0;
}



/* Function: FUN_000094a4 @ 000094a4 */

bool FUN_000094a4(int param_1,int param_2)

{
  size_t __n;
  int iVar1;
  char *__s;
  bool bVar2;
  
  __s = *(char **)(DAT_000094d0 + 0x94b0);
  __n = strlen(__s);
  bVar2 = false;
  if ((int)__n <= param_2) {
    iVar1 = strncmp((char *)(param_1 + (param_2 - __n)),__s,__n);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



/* Function: FUN_000094d4 @ 000094d4 */

int * FUN_000094d4(int param_1)

{
  int iVar1;
  ssize_t sVar2;
  size_t sVar3;
  int *piVar4;
  int iVar5;
  int extraout_r1;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  itimerval local_38;
  
  iVar12 = DAT_0000964c + 0x94ec;
  bsd_signal(0xe,*(__sighandler_t *)(iVar12 + DAT_00009650));
  uVar9 = *(undefined4 *)(param_1 + 4);
  local_38.it_value.tv_sec = __aeabi_uidiv(uVar9,1000);
  __aeabi_uidivmod(uVar9,1000);
  iVar1 = DAT_00009654;
  local_38.it_value.tv_usec = extraout_r1 * 1000;
  local_38.it_interval.tv_sec = 0;
  local_38.it_interval.tv_usec = 0;
  setitimer(ITIMER_REAL,&local_38,(itimerval *)0x0);
  sVar2 = write(*(int *)(iVar1 + 0x952e),(void *)(param_1 + 0xc),*(size_t *)(param_1 + 8));
  if (sVar2 == *(int *)(param_1 + 8)) {
    pcVar6 = *(char **)(DAT_00009658 + 0x9548);
    sVar3 = strlen(pcVar6);
    write(*(int *)(iVar1 + 0x952e),pcVar6,sVar3);
    piVar4 = malloc(DAT_0000965c);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)__errno();
      pcVar6 = strerror(*piVar4);
      fprintf((FILE *)(*(int *)(iVar12 + DAT_00009664) + 0xa8),(char *)(DAT_00009670 + 0x9644),
              pcVar6);
    }
    else {
      iVar11 = 1;
      piVar10 = piVar4 + 1;
      iVar7 = 0;
      iVar8 = 0x400;
      while( true ) {
        do {
          sVar2 = read(*(int *)(iVar1 + 0x9532),(void *)((int)piVar10 + iVar7),iVar8 - iVar7);
          if (sVar2 < 1) {
            free(piVar4);
                    /* WARNING: Subroutine does not return */
            exit(-1);
          }
          iVar7 = sVar2 + iVar7;
          iVar5 = FUN_000094a4(piVar10,iVar7);
          if (iVar5 != 0) {
            sVar3 = strlen(*(char **)(DAT_00009660 + 0x95c4));
            *piVar4 = iVar7 - sVar3;
            return piVar4;
          }
        } while (iVar8 != iVar7);
        iVar11 = iVar11 + 1;
        piVar4 = realloc(piVar4,iVar11 * 0x400 + 4);
        if (piVar4 == (int *)0x0) break;
        piVar10 = piVar4 + 1;
        iVar7 = iVar8;
        iVar8 = iVar11 * 0x400;
      }
      piVar4 = (int *)__errno();
      pcVar6 = strerror(*piVar4);
      fprintf((FILE *)(*(int *)(iVar12 + DAT_00009664) + 0xa8),(char *)(DAT_0000966c + 0x9618),
              pcVar6);
    }
  }
  else {
    piVar4 = (int *)__errno();
    pcVar6 = strerror(*piVar4);
    fprintf((FILE *)(*(int *)(iVar12 + DAT_00009664) + 0xa8),(char *)(DAT_00009668 + 0x95f6),pcVar6)
    ;
  }
  return (int *)0x0;
}



/* Function: FUN_00009674 @ 00009674 */

undefined4 FUN_00009674(void)

{
  int iVar1;
  void *__ptr;
  __pid_t _Var2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  char *__s2;
  int local_1c;
  
  local_1c = 5;
  __ptr = malloc(0x528);
  _Var2 = getpid();
  FUN_00009b80(_Var2,__ptr,&local_1c,1);
  iVar1 = local_1c;
  if (0 < local_1c) {
    iVar6 = 0;
    __s2 = (char *)(DAT_000096d8 + 0x96a8);
    pvVar4 = __ptr;
    do {
      iVar3 = strcmp((char *)((int)pvVar4 + 8),__s2);
      if (iVar3 != 0) {
        uVar5 = *(undefined4 *)((int)pvVar4 + 4);
        goto LAB_000096c6;
      }
      iVar6 = iVar6 + 1;
      pvVar4 = (void *)((int)pvVar4 + 0x108);
    } while (iVar6 != iVar1);
  }
  uVar5 = 0;
LAB_000096c6:
  free(__ptr);
  return uVar5;
}



/* Function: signalRoutine @ 000096dc */

void signalRoutine(int param_1)

{
  __pid_t __pid;
  
  __pid = FUN_00009674();
  if ((param_1 == 0xe) && (0 < __pid)) {
    printf((char *)(DAT_00009704 + 0x96f8),__pid);
    kill(__pid,9);
  }
  return;
}



/* Function: FUN_00009708 @ 00009708 */

undefined4 FUN_00009708(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined1 auStack_20 [4];
  int local_1c;
  socklen_t local_14 [2];
  
  iVar1 = DAT_00009760;
  if (*(char *)(DAT_00009760 + 0x9722) == '\0') {
    local_14[0] = 0xc;
    iVar2 = getsockopt(param_1,1,0x11,auStack_20,local_14);
    if (iVar2 < 0) {
      piVar3 = (int *)__errno();
      pcVar4 = strerror(*piVar3);
      printf((char *)(DAT_00009768 + 0x975a),pcVar4);
      return 0;
    }
    if (local_1c != *(int *)(iVar1 + 0x9726)) {
      printf((char *)(DAT_00009764 + 0x9742));
      return 0;
    }
  }
  return 1;
}



/* Function: FUN_00009a64 @ 00009a64 */

void FUN_00009a64(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  int __fd;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *__s;
  
  iVar2 = DAT_00009b58;
  iVar1 = DAT_00009b54;
  iVar6 = DAT_00009b5c + 0x9a80;
  pcVar7 = &stack0xffffffe4 + DAT_00009b54;
  *(undefined4 *)(&stack0xffffffe0 + DAT_00009b60 + DAT_00009b54) =
       **(undefined4 **)(iVar6 + DAT_00009b58);
  sprintf(pcVar7,(char *)(DAT_00009b64 + 0x9a90),param_1);
  iVar3 = open(pcVar7,0);
  if (-1 < iVar3) {
    sVar4 = read(iVar3,pcVar7,DAT_00009b68);
    close(iVar3);
    iVar3 = DAT_00009b6c;
    if (-1 < sVar4) {
      memcpy(param_2 + 2,pcVar7,0x100);
      __s = &stack0xffffffe0 + iVar3 + iVar1;
      sprintf(__s,(char *)(DAT_00009b70 + 0x9ad2),param_1);
      __fd = open(__s,0);
      uVar5 = read(__fd,__s,DAT_00009b68);
      iVar3 = DAT_00009b74;
      close(__fd);
      pcVar7 = (char *)(iVar3 + 0x9afa);
      __s[uVar5 & (int)~uVar5 >> 0x1f] = '\0';
      strtok(__s,pcVar7);
      strtok((char *)0x0,(char *)(DAT_00009b78 + 0x9b0e));
      strtok((char *)0x0,pcVar7);
      pcVar7 = strtok((char *)0x0,pcVar7);
      if (pcVar7 != (char *)0x0) {
        param_2[1] = param_1;
        iVar3 = atoi(pcVar7);
        *param_2 = iVar3;
      }
    }
  }
  if (*(int *)(&stack0xffffffe0 + DAT_00009b60 + iVar1) == **(int **)(iVar6 + iVar2)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00009b80 @ 00009b80 */

void FUN_00009b80(int param_1,int param_2,int *param_3,int param_4)

{
  size_t sVar1;
  DIR *__dirp;
  dirent *pdVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *__src;
  int *local_2c;
  
  local_2c = malloc(DAT_00009c84);
  iVar7 = 1;
  __dirp = opendir((char *)(DAT_00009c88 + 0x9ba8));
  sVar1 = DAT_00009c84;
  iVar5 = 0;
LAB_00009bb4:
  pdVar2 = readdir(__dirp);
  if (pdVar2 != (dirent *)0x0) {
    while( true ) {
      if ((9 < (byte)pdVar2->d_name[8] - 0x30) ||
         (iVar3 = atoi(pdVar2->d_name + 8), iVar3 <= param_1)) goto LAB_00009bb4;
      FUN_00009a64(iVar3,local_2c + iVar5 * 0x42);
      iVar3 = iVar7 * 100;
      iVar5 = iVar5 + 1;
      if (iVar3 - iVar5 == 0) break;
      pdVar2 = readdir(__dirp);
      if (pdVar2 == (dirent *)0x0) goto LAB_00009bfa;
    }
    iVar7 = iVar7 + 1;
    local_2c = realloc(local_2c,iVar7 * sVar1);
    iVar5 = iVar3;
    goto LAB_00009bb4;
  }
LAB_00009bfa:
  closedir(__dirp);
  iVar7 = 0;
  if (0 < iVar5) {
    iVar3 = 0;
    __src = local_2c;
    do {
      iVar6 = *__src;
      if (iVar6 == param_1) {
        if (*param_3 <= iVar7) break;
        iVar4 = iVar7 * 0x108;
        iVar7 = iVar7 + 1;
        memcpy((void *)(param_2 + iVar4),__src,0x108);
        param_1 = iVar6;
        if (param_4 != 0) {
          param_1 = __src[1];
        }
      }
      if (iVar3 + 1 == iVar5) break;
      __src = __src + 0x42;
      iVar3 = iVar3 + 1;
    } while( true );
  }
  *param_3 = iVar7;
  free(local_2c);
  return;
}



/* Function: __aeabi_uidiv @ 00009c8c */

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



/* Function: __aeabi_uidivmod @ 00009d38 */

void __aeabi_uidivmod(void)

{
  __aeabi_uidiv();
  return;
}



/* Function: __div0 @ 00009d50 */

void __div0(void)

{
  raise(8);
  return;
}



/* Function: _Unwind_VRS_Get @ 00009d60 */

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



/* Function: _Unwind_VRS_Set @ 00009dac */

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



/* Function: FUN_00009df8 @ 00009df8 */

int FUN_00009df8(uint *param_1)

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



/* Function: _Unwind_GetCFA @ 00009e10 */

undefined4 _Unwind_GetCFA(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* Function: _Unwind_Complete @ 00009e18 */

void _Unwind_Complete(void)

{
  return;
}



/* Function: _Unwind_DeleteException @ 00009e1c */

void _Unwind_DeleteException(int param_1)

{
  if (*(code **)(param_1 + 8) == (code *)0x0) {
    return;
  }
  (**(code **)(param_1 + 8))(1,param_1);
  return;
}



/* Function: __aeabi_unwind_cpp_pr2 @ 0000a2d0 */

/* WARNING: Removing unreachable block (ram,0x00009e70) */
/* WARNING: Removing unreachable block (ram,0x00009eec) */
/* WARNING: Removing unreachable block (ram,0x00009f0c) */

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
LAB_0000a234:
    do {
      while( true ) {
        uVar5 = *puVar9;
        if (uVar5 == 0) goto LAB_0000a240;
        uVar10 = puVar9[1];
        puVar7 = puVar9 + 2;
        uVar12 = (uVar10 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
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
LAB_0000a134:
              _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
              *(uint **)(param_2 + 0x28) = puVar7;
              *(uint *)(param_2 + 0x20) = uStack_30;
              *(int *)(param_2 + 0x24) = aiStack_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar5 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
          if ((uVar5 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            uStack_30 = FUN_00009df8(puVar7);
            _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
LAB_0000a1f8:
            uVar4 = 0;
            uStack_30 = param_2;
            goto LAB_0000a2b4;
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
              if (uStack_58 == uVar5) goto LAB_0000a134;
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
          _Unwind_VRS_Get(param_3,0,0xd,0,&uStack_30);
          if ((uVar10 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar9 + 3;
            *(uint *)(param_2 + 0x28) = uVar5;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar7) {
              uStack_30 = FUN_00009df8(puVar7 + uVar5 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
              goto LAB_0000a1f8;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 3;
        }
        puVar9 = puVar7 + uVar5 + 1;
        goto LAB_0000a234;
      }
      if (uVar8 == 0) {
        bVar1 = false;
      }
      puVar9 = puVar9 + 3;
    } while (!bVar1);
    uVar5 = FUN_00009df8(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      uStack_30 = uVar5;
      goto LAB_0000a2b4;
    }
  }
  else {
    bVar11 = false;
LAB_0000a240:
    iVar3 = __gnu_unwind_execute(param_3,&iStack_3c);
    if (iVar3 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&uStack_30);
      uVar4 = 0xf;
      uStack_30 = *(uint *)(DAT_0000a2cc + 0xa2a4);
LAB_0000a2b4:
      _Unwind_VRS_Set(param_3,0,uVar4,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr1 @ 0000a2d8 */

/* WARNING: Removing unreachable block (ram,0x00009e70) */
/* WARNING: Removing unreachable block (ram,0x00009ef0) */
/* WARNING: Removing unreachable block (ram,0x00009f08) */

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
  uint local_58;
  int local_3c;
  uint *local_38;
  undefined1 local_34;
  undefined1 local_33;
  uint local_30;
  int local_2c [2];
  
  uVar9 = param_1 & 3;
  local_38 = *(uint **)(param_2 + 0x4c) + 1;
  uVar6 = **(uint **)(param_2 + 0x4c);
  local_3c = uVar6 << 0x10;
  puVar10 = local_38 + (uVar6 >> 0x10 & 0xff);
  local_34 = 2;
  local_33 = (undefined1)(uVar6 >> 0x10);
  if (uVar9 == 2) {
    puVar10 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar4 = param_2 + 0x58;
    bVar11 = false;
LAB_0000a234:
    do {
      while( true ) {
        if (*puVar10 == 0) goto LAB_0000a240;
        uVar1 = *(ushort *)((int)puVar10 + 2);
        uVar6 = *puVar10;
        puVar8 = puVar10 + 1;
        uVar12 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        _Unwind_VRS_Get(param_3,0,0xf,0,&local_30);
        if (local_30 < uVar12) {
          bVar2 = false;
        }
        else if (local_30 < uVar12 + ((ushort)uVar6 & 0xfffffffe)) {
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
            local_2c[0] = iVar4;
            if (uVar6 != 0xffffffff) {
              if (uVar6 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(undefined4 *)((int)puVar10 + uVar6 + 8);
              }
              iVar3 = __cxa_type_match(param_2,uVar5,*puVar8 >> 0x1f,local_2c);
              if (iVar3 == 0) {
                local_2c[0] = 0;
              }
            }
            if (local_2c[0] != 0) {
LAB_0000a134:
              _Unwind_VRS_Get(param_3,0,0xd,0,&local_30);
              *(uint **)(param_2 + 0x28) = puVar8;
              *(uint *)(param_2 + 0x20) = local_30;
              *(int *)(param_2 + 0x24) = local_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar6 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&local_30);
          if ((uVar6 == local_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            local_30 = FUN_00009df8(puVar8);
            _Unwind_VRS_Set(param_3,0,0xf,0,&local_30);
LAB_0000a1f8:
            uVar5 = 0;
            local_30 = param_2;
            goto LAB_0000a2b4;
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
            local_58 = 0;
            puVar7 = puVar8;
            do {
              if (local_58 == uVar6) goto LAB_0000a134;
              puVar7 = puVar7 + 1;
              local_58 = local_58 + 1;
              uVar5 = 0;
              if (*puVar7 != 0) {
                uVar5 = *(undefined4 *)((int)puVar7 + *puVar7);
              }
              local_2c[0] = iVar4;
              iVar3 = __cxa_type_match(param_2,uVar5,0,local_2c);
            } while (iVar3 == 0);
          }
        }
        else {
          uVar12 = *(uint *)(param_2 + 0x20);
          _Unwind_VRS_Get(param_3,0,0xd,0,&local_30);
          if ((uVar12 == local_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar10 + 2;
            *(uint *)(param_2 + 0x28) = uVar6;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar8) {
              local_30 = FUN_00009df8(puVar8 + uVar6 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&local_30);
              goto LAB_0000a1f8;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar8 < 0) {
          puVar8 = puVar10 + 2;
        }
        puVar10 = puVar8 + uVar6 + 1;
        goto LAB_0000a234;
      }
      if (uVar9 == 0) {
        bVar2 = false;
      }
      puVar10 = puVar10 + 2;
    } while (!bVar2);
    uVar6 = FUN_00009df8(puVar8);
    *(uint **)(param_2 + 0x38) = puVar10;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      local_30 = uVar6;
      goto LAB_0000a2b4;
    }
  }
  else {
    bVar11 = false;
LAB_0000a240:
    iVar4 = __gnu_unwind_execute(param_3,&local_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&local_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&local_30);
      uVar5 = 0xf;
      local_30 = *(uint *)(DAT_0000a2cc + 0xa2a4);
LAB_0000a2b4:
      _Unwind_VRS_Set(param_3,0,uVar5,0,&local_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr0 @ 0000a2e0 */

/* WARNING: Removing unreachable block (ram,0x00009e8c) */
/* WARNING: Removing unreachable block (ram,0x00009ef0) */
/* WARNING: Removing unreachable block (ram,0x00009f08) */

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
LAB_0000a234:
    do {
      while( true ) {
        if (*puVar9 == 0) goto LAB_0000a240;
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
LAB_0000a134:
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
            uStack_30 = FUN_00009df8(puVar7);
            _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
LAB_0000a1f8:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_0000a2b4;
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
              if (uStack_58 == uVar10) goto LAB_0000a134;
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
              uStack_30 = FUN_00009df8(puVar7 + uVar10 + 1);
              _Unwind_VRS_Set(param_3,0,0xf,0,&uStack_30);
              goto LAB_0000a1f8;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 2;
        }
        puVar9 = puVar7 + uVar10 + 1;
        goto LAB_0000a234;
      }
      if (uVar8 == 0) {
        bVar2 = false;
      }
      puVar9 = puVar9 + 2;
    } while (!bVar2);
    uVar8 = FUN_00009df8(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar8;
      goto LAB_0000a2b4;
    }
  }
  else {
    bVar11 = false;
LAB_0000a240:
    iVar4 = __gnu_unwind_execute(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      _Unwind_VRS_Get(param_3,0,0xf,0,&uStack_30);
      _Unwind_VRS_Set(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_0000a2cc + 0xa2a4);
LAB_0000a2b4:
      _Unwind_VRS_Set(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: FUN_0000a2e8 @ 0000a2e8 */

undefined4 FUN_0000a2e8(int param_1,int param_2)

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
  
  iVar8 = DAT_0000a49c + 0xa2fc;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_0000a4a0) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_0000a4a8);
    local_2c[0] = *(int *)(iVar8 + DAT_0000a4a4) - iVar2 >> 3;
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
        uVar3 = FUN_00009df8(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_00009df8(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_0000a474;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_00009df8(iVar10);
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
        uVar5 = FUN_00009df8();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_00009df8();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_0000a4ac;
      if (((uVar9 == 0) || (iVar2 = DAT_0000a4b0, uVar9 == 1)) || (iVar2 = DAT_0000a4b4, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_0000a474:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}



/* Function: FUN_0000a4b8 @ 0000a4b8 */

void FUN_0000a4b8(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      __gnu_Unwind_Restore_VFP(param_1 + 0x12);
    }
    else {
      FUN_0000ac48();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_0000ac58(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_0000ac68(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_0000acf0(param_1 + 0x8c);
  return;
}



/* Function: __gnu_Unwind_Backtrace @ 0000a524 */

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
    iVar1 = FUN_0000a2e8(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_0000a5e0:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    _Unwind_VRS_Set(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_0000a5e0;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_0000a4b8(&local_2c0);
  return iVar1;
}



/* Function: FUN_0000a5f8 @ 0000a5f8 */

int FUN_0000a5f8(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_0000a2e8(param_1,local_228);
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



/* Function: __gnu_Unwind_ForcedUnwind @ 0000a714 */

void __gnu_Unwind_ForcedUnwind(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_4 + 0x40) = *(undefined4 *)(param_4 + 0x3c);
  FUN_0000a5f8(param_1,param_4,0);
  return;
}



/* Function: FUN_0000a730 @ 0000a730 */

undefined4 FUN_0000a730(int param_1,int param_2)

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
    iVar1 = FUN_0000a2e8(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_0000a77c;
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
      iVar2 = FUN_0000a2e8(iVar1,uStack_228);
      if (iVar2 != 0) {
        return 9;
      }
      iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&uStack_268);
    } while (iVar2 == 8);
    FUN_0000a4b8(&uStack_268);
    if (iVar2 == 6) {
      FUN_0000a730(iVar1,iVar3);
    }
    return 9;
  }
LAB_0000a77c:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: __gnu_Unwind_RaiseException @ 0000a788 */

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
    iVar1 = FUN_0000a2e8(param_1,local_218);
    if (iVar1 != 0) {
      return 9;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(0,param_1,&local_258);
  } while (iVar1 == 8);
  FUN_0000a4b8(&local_258);
  if (iVar1 == 6) {
    FUN_0000a730(param_1,param_2);
  }
  return 9;
}



/* Function: __gnu_Unwind_Resume_or_Rethrow @ 0000a82c */

void __gnu_Unwind_Resume_or_Rethrow(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    __gnu_Unwind_RaiseException();
    return;
  }
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  FUN_0000a5f8(param_1,param_2,0);
  return;
}



/* Function: __gnu_Unwind_Resume @ 0000a84c */

void __gnu_Unwind_Resume(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (**(code **)(param_1 + 0x10))(2,param_1,param_2);
    if (iVar1 == 7) {
      restore_core_regs(param_2 + 4);
    }
    else if (iVar1 != 8) goto LAB_0000a8b4;
    FUN_0000a730(param_1,param_2);
  }
  else {
    FUN_0000a5f8(param_1,param_2,1);
  }
LAB_0000a8b4:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_VRS_Pop @ 0000a8b8 */

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
        FUN_0000ac50();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        __gnu_Unwind_Save_VFP(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_0000ac60(param_1 + 0x34);
    }
    if (bVar8) {
      __gnu_Unwind_Save_VFP(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000ac50(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_0000aa54;
      FUN_0000ac60(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_0000aa54:
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
        FUN_0000ac48(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_0000ac58(local_b0);
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
          FUN_0000acac(param_1 + 0x6c);
        }
        FUN_0000acac(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_0000ac68(auStack_130);
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
        FUN_0000ad04(param_1 + 0x8c);
      }
      FUN_0000ad04(local_30);
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
      FUN_0000acf0(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: restore_core_regs @ 0000ac24 */

undefined8 restore_core_regs(undefined8 *param_1)

{
  return *param_1;
}



/* Function: __gnu_Unwind_Restore_VFP @ 0000ac38 */

undefined4 __gnu_Unwind_Restore_VFP(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: __gnu_Unwind_Save_VFP @ 0000ac40 */

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



/* Function: FUN_0000ac48 @ 0000ac48 */

undefined4 FUN_0000ac48(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0000ac50 @ 0000ac50 */

void FUN_0000ac50(undefined8 *param_1)

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



/* Function: FUN_0000ac58 @ 0000ac58 */

void FUN_0000ac58(void)

{
  return;
}



/* Function: FUN_0000ac60 @ 0000ac60 */

void FUN_0000ac60(undefined8 *param_1)

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



/* Function: FUN_0000ac68 @ 0000ac68 */

int FUN_0000ac68(int param_1)

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



/* Function: FUN_0000acac @ 0000acac */

int FUN_0000acac(int param_1)

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



/* Function: FUN_0000acf0 @ 0000acf0 */

int FUN_0000acf0(int param_1)

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



/* Function: FUN_0000ad04 @ 0000ad04 */

int FUN_0000ad04(int param_1)

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



/* Function: _Unwind_RaiseException @ 0000ad18 */

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



/* Function: _Unwind_Resume @ 0000ad3c */

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



/* Function: ___Unwind_Resume_or_Rethrow @ 0000ad60 */

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



/* Function: _Unwind_ForcedUnwind @ 0000ad84 */

void _Unwind_ForcedUnwind(void)

{
  __gnu_Unwind_ForcedUnwind();
  return;
}



/* Function: ___Unwind_Backtrace @ 0000ada8 */

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



/* Function: FUN_0000adcc @ 0000adcc */

uint FUN_0000adcc(uint *param_1)

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



/* Function: _Unwind_GetTextRelBase @ 0000ae24 */

void _Unwind_GetTextRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_GetDataRelBase @ 0000ae2c */

void _Unwind_GetDataRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_GetLanguageSpecificData @ 0000ae34 */

int _Unwind_GetLanguageSpecificData(void)

{
  int in_r3;
  
  _Unwind_VRS_Get();
  return *(int *)(in_r3 + 0x4c) + (uint)*(byte *)(*(int *)(in_r3 + 0x4c) + 7) * 4 + 8;
}



/* Function: _Unwind_GetRegionStart @ 0000ae6c */

undefined4 _Unwind_GetRegionStart(void)

{
  int in_r3;
  
  _Unwind_VRS_Get();
  return *(undefined4 *)(in_r3 + 0x48);
}



/* Function: __gnu_unwind_execute @ 0000ae98 */

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
LAB_0000aeb0:
  do {
    while( true ) {
      uVar1 = FUN_0000adcc(param_2);
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
LAB_0000afe8:
      piVar6 = &local_24;
      _Unwind_VRS_Set(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_0000adcc(param_2);
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
      goto LAB_0000aeb0;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      _Unwind_VRS_Get(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_0000afe8;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_0000adcc(param_2);
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
            uVar3 = FUN_0000adcc(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_0000afe8;
        }
        if (uVar1 == 0xb3) {
          FUN_0000adcc(param_2);
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
        FUN_0000adcc(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_0000adcc(param_2);
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
            FUN_0000adcc(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_0000adcc(param_2);
          }
          goto LAB_0000b1ec;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_0000b1ec:
      uVar2 = 1;
    }
    iVar5 = _Unwind_VRS_Pop(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: __gnu_unwind_frame @ 0000b210 */

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



/* Function: strcpy @ 0000d000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: printf @ 0000d004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: recv @ 0000d008 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t recv(int __fd,void *__buf,size_t __n,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strerror @ 0000d00c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __errno @ 0000d014 */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_begin_cleanup @ 0000d018 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getpid @ 0000d01c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 0000d020 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 0000d024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setitimer @ 0000d028 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setitimer(__itimer_which_t __which,itimerval *__new,itimerval *__old)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dup2 @ 0000d02c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup2(int __fd,int __fd2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: execle @ 0000d030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int execle(char *__path,char *__arg,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 0000d034 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: socket @ 0000d038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readdir @ 0000d03c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

dirent * readdir(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: send @ 0000d040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t send(int __fd,void *__buf,size_t __n,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 0000d044 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 0000d048 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pipe @ 0000d04c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pipe(int *__pipedes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: accept @ 0000d050 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __libc_init @ 0000d054 */

/* WARNING: Control flow encountered bad instruction data */

void __libc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: write @ 0000d058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fprintf @ 0000d05c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: kill @ 0000d060 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int kill(__pid_t __pid,int __sig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: bind @ 0000d064 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: bsd_signal @ 0000d068 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t bsd_signal(int __sig,__sighandler_t __handler)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: read @ 0000d06c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strncmp @ 0000d070 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: unlink @ 0000d074 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 0000d078 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: realloc @ 0000d07c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtok @ 0000d080 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: listen @ 0000d084 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fork @ 0000d08c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t fork(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getppid @ 0000d090 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getppid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: opendir @ 0000d094 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIR * opendir(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 0000d098 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 0000d09c */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sprintf @ 0000d0a0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getsockopt @ 0000d0a4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int getsockopt(int __fd,int __level,int __optname,void *__optval,socklen_t *__optlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fwrite @ 0000d0a8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: exit @ 0000d0ac */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: atoi @ 0000d0b0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 0000d0b4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: open @ 0000d0b8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: closedir @ 0000d0bc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int closedir(DIR *__dirp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: close @ 0000d0c0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: raise @ 0000d0c4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 0000d0c8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



