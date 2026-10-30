/* Function: ipcData @ 000118c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcData(void)

{
  (*(code *)PTR_ipcData_00014170)();
  return;
}



/* Function: ipcDataSize @ 000118cc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcDataSize(void)

{
  (*(code *)PTR_ipcDataSize_00014174)();
  return;
}



/* Function: __android_log_print @ 000118d8 */

void __android_log_print(void)

{
  (*(code *)PTR___android_log_print_00014178)();
  return;
}



/* Function: Parcel @ 000118e4 */

void __thiscall android::Parcel::Parcel(Parcel *this)

{
  (*(code *)PTR_Parcel_0001417c)(this);
  return;
}



/* Function: setData @ 000118f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setData(uchar *param_1,uint param_2)

{
  (*(code *)PTR_setData_00014180)(param_1);
  return;
}



/* Function: readInt32 @ 000118fc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt32(void)

{
  (*(code *)PTR_readInt32_00014184)();
  return;
}



/* Function: dataPosition @ 00011908 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::dataPosition(void)

{
  (*(code *)PTR_dataPosition_00014188)();
  return;
}



/* Function: readString16 @ 00011914 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString16(void)

{
  (*(code *)PTR_readString16_0001418c)();
  return;
}



/* Function: ~String16 @ 00011920 */

void __thiscall android::String16::~String16(String16 *this)

{
  (*(code *)PTR__String16_00014190)(this);
  return;
}



/* Function: ~Parcel @ 0001192c */

void __thiscall android::Parcel::~Parcel(Parcel *this)

{
  (*(code *)PTR__Parcel_00014194)(this);
  return;
}



/* Function: setDataPosition @ 00011938 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setDataPosition(uint param_1)

{
  (*(code *)PTR_setDataPosition_00014198)(param_1);
  return;
}



/* Function: readObject @ 00011944 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readObject(bool param_1)

{
  (*(code *)PTR_readObject_0001419c)(param_1);
  return;
}



/* Function: memset @ 00011950 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_000141a0)(__s);
  return pvVar1;
}



/* Function: strcmp @ 0001195c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_000141a4)(__s1);
  return iVar1;
}



/* Function: strstr @ 00011968 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strstr_000141a8)(__haystack);
  return pcVar1;
}



/* Function: memcpy @ 00011974 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_000141ac)(__dest);
  return pvVar1;
}



/* Function: __stack_chk_fail @ 00011980 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_000141b0)();
  return;
}



/* Function: self @ 0001198c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::self(void)

{
  (*(code *)PTR_self_000141b4)();
  return;
}



/* Function: sendReply @ 00011998 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::sendReply(Parcel *param_1,uint param_2)

{
  (*(code *)PTR_sendReply_000141b8)(param_1);
  return;
}



/* Function: pthread_key_create @ 000119a4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_key_create_000141bc)(__key);
  return iVar1;
}



/* Function: strcpy @ 000119b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_000141c0)(__dest);
  return pcVar1;
}



/* Function: pthread_create @ 000119bc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_000141c4)(__newthread);
  return iVar1;
}



/* Function: pthread_getspecific @ 000119c8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_pthread_getspecific_000141c8)(__key);
  return pvVar1;
}



/* Function: pthread_setspecific @ 000119d4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_setspecific_000141cc)(__key);
  return iVar1;
}



/* Function: ioctl @ 000119e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ioctl_000141d0)(__fd);
  return iVar1;
}



/* Function: malloc @ 000119ec */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_000141d4)(__size);
  return pvVar1;
}



/* Function: lseek @ 000119f8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
  __off_t _Var1;
  
  _Var1 = (*(code *)PTR_lseek_000141d8)(__fd);
  return _Var1;
}



/* Function: free @ 00011a04 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_000141dc)(__ptr);
  return;
}



/* Function: __errno @ 00011a10 */

void __errno(void)

{
  (*(code *)PTR___errno_000141e0)();
  return;
}



/* Function: read @ 00011a1c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_000141e4)(__fd);
  return sVar1;
}



/* Function: sysconf @ 00011a28 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_sysconf_000141e8)(__name);
  return lVar1;
}



/* Function: open @ 00011a34 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_000141ec)(__file);
  return iVar1;
}



/* Function: close @ 00011a40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_000141f0)(__fd);
  return iVar1;
}



/* Function: mprotect @ 00011a4c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mprotect_000141f4)(__addr);
  return iVar1;
}



/* Function: snprintf @ 00011a58 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_000141f8)(__s);
  return iVar1;
}



/* Function: fopen @ 00011a64 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_000141fc)(__filename);
  return pFVar1;
}



/* Function: strtok @ 00011a70 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strtok_00014200)(__s);
  return pcVar1;
}



/* Function: strtoul @ 00011a7c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
  uVar1 = (*(code *)PTR_strtoul_00014204)(__nptr);
  return uVar1;
}



/* Function: fgets @ 00011a88 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_00014208)(__s);
  return pcVar1;
}



/* Function: fclose @ 00011a94 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_0001420c)(__stream);
  return iVar1;
}



/* Function: fseek @ 00011aa0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fseek_00014210)(__stream);
  return iVar1;
}



/* Function: sscanf @ 00011aac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sscanf_00014214)(__s);
  return iVar1;
}



/* Function: strlen @ 00011ab8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00014218)(__s);
  return sVar1;
}



/* Function: socket @ 00011ac4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_0001421c)(__domain);
  return iVar1;
}



/* Function: bind @ 00011ad0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_bind_00014220)(__fd);
  return iVar1;
}



/* Function: listen @ 00011adc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_listen_00014224)(__fd);
  return iVar1;
}



/* Function: accept @ 00011ae8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_accept_00014228)(__fd);
  return iVar1;
}



/* Function: connect @ 00011af4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_connect_0001422c)(__fd);
  return iVar1;
}



/* Function: write @ 00011b00 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_00014230)(__fd);
  return sVar1;
}



/* Function: __cxa_finalize @ 00011b0c */

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_00014234)();
  return;
}



/* Function: set_cell_location_reply @ 00011b28 */

/* android::set_cell_location_reply(unsigned char*, unsigned int&) */

undefined4 android::set_cell_location_reply(uchar *param_1,uint *param_2)

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
  return 0;
}



/* Function: set_sendsms_reply @ 00011b38 */

/* android::set_sendsms_reply(unsigned char*, unsigned int&) */

undefined4 android::set_sendsms_reply(uchar *param_1,uint *param_2)

{
  *param_2 = 4;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  return 0;
}



/* Function: print_parcel @ 00011b44 */

/* android::print_parcel(android::Parcel const&) */

void android::print_parcel(Parcel *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = android::Parcel::ipcData();
  uVar2 = android::Parcel::ipcDataSize();
  iVar4 = DAT_00011b84 + 0x11b62;
  iVar5 = DAT_00011b88 + 0x11b64;
  for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
    __android_log_print(6,iVar4,iVar5,uVar3,*(undefined1 *)(iVar1 + uVar3),
                        *(undefined1 *)(iVar1 + uVar3));
  }
  return;
}



/* Function: set_deviceid_reply @ 00011b8c */

/* android::set_deviceid_reply(unsigned char*, unsigned int&) */

undefined4 android::set_deviceid_reply(uchar *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  Parcel aPStack_4c [48];
  int local_1c [2];
  
  android::Parcel::Parcel(aPStack_4c);
  android::Parcel::setData((uchar *)aPStack_4c,(uint)param_1);
  print_parcel(aPStack_4c);
  android::Parcel::readInt32();
  iVar1 = android::Parcel::dataPosition();
  android::Parcel::readString16();
  uVar2 = *(uint *)(local_1c[0] + -0xc);
  for (iVar3 = 0; iVar3 < (int)((uVar2 >> 1) - 1); iVar3 = iVar3 + 1) {
    if (param_1[iVar3 + iVar1 + 4] != '\0') {
      param_1[iVar3 + iVar1 + 4] = param_1[iVar3 + iVar1 + 4] + '\x01';
    }
  }
  android::Parcel::setData((uchar *)aPStack_4c,(uint)param_1);
  print_parcel(aPStack_4c);
  android::String16::~String16((String16 *)local_1c);
  android::Parcel::~Parcel(aPStack_4c);
  return 0;
}



/* Function: set_contentprivider_query_reply @ 00011c08 */

/* android::set_contentprivider_query_reply(unsigned char*, unsigned int) */

int android::set_contentprivider_query_reply(uchar *param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  Parcel aPStack_4c [48];
  String16 aSStack_1c [8];
  
  __android_log_print(6,DAT_00011cc0 + 0x11c18,DAT_00011cbc + 0x11c1a);
  android::Parcel::Parcel(aPStack_4c);
  android::Parcel::setData((uchar *)aPStack_4c,(uint)param_1);
  android::Parcel::setDataPosition((uint)aPStack_4c);
  iVar2 = android::Parcel::readInt32();
  if ((iVar2 == 0) && (*(int *)param_1 == 0)) {
    bVar1 = SUB41(aPStack_4c,0);
    if (*(int *)(param_1 + 4) == 1) {
      android::Parcel::readInt32();
      android::Parcel::readObject(bVar1);
      iVar3 = android::Parcel::readInt32();
      if (-1 < iVar3) {
        for (iVar5 = 0; iVar5 != iVar3; iVar5 = iVar5 + 1) {
          android::Parcel::readString16();
          android::String16::~String16(aSStack_1c);
        }
        android::Parcel::readInt32();
        iVar3 = android::Parcel::dataPosition();
        puVar4 = param_1 + iVar3;
        puVar4[0] = '\0';
        puVar4[1] = '\0';
        puVar4[2] = '\0';
        puVar4[3] = '\0';
      }
    }
    else {
      android::Parcel::readObject(bVar1);
      iVar3 = android::Parcel::dataPosition();
      puVar4 = param_1 + iVar3;
      puVar4[0] = '\0';
      puVar4[1] = '\0';
      puVar4[2] = '\0';
      puVar4[3] = '\0';
      puVar4[4] = '\0';
      puVar4[5] = '\0';
      puVar4[6] = '\0';
      puVar4[7] = '\0';
    }
  }
  android::Parcel::~Parcel(aPStack_4c);
  return iVar2;
}



/* Function: modify_reply @ 00011cc4 */

undefined4 modify_reply(uchar *param_1,uint param_2,int param_3)

{
  uint local_14 [2];
  
  local_14[0] = param_2;
  __android_log_print(6,DAT_00011d1c + 0x11cd8,DAT_00011d18 + 0x11cd6,param_3);
  if (param_3 == 0xb) {
    android::set_sendsms_reply(param_1,local_14);
  }
  else if (param_3 < 0xc) {
    if (param_3 - 1U < 3) {
      android::set_contentprivider_query_reply(param_1,local_14[0]);
    }
  }
  else if (param_3 == 0x14) {
    android::set_cell_location_reply(param_1,local_14);
  }
  return 0;
}



/* Function: parse_requestdata @ 00011d20 */

void parse_requestdata(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  Parcel *this;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  short *psVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  int iVar12;
  size_t __n;
  int iVar13;
  int iVar14;
  
  iVar1 = DAT_0001203c;
  *(undefined4 *)(&stack0xfffffff4 + DAT_0001203c) = param_2;
  iVar12 = DAT_00012044 + 0x11d34;
  puVar7 = *(undefined4 **)(iVar12 + DAT_00012040);
  *(undefined4 *)(&stack0xfffffff8 + DAT_0001203c) = param_4;
  uVar2 = *puVar7;
  this = (Parcel *)(&stack0x00000008 + DAT_0001203c);
  *(undefined4 *)(&stack0xfffffffc + DAT_0001203c) =
       *(undefined4 *)(&stack0x00000364 + DAT_0001203c);
  *(undefined4 *)(&stack0x00000348 + DAT_0001203c) = uVar2;
  *(undefined4 *)(&stack0xfffffff0 + DAT_0001203c) = param_3;
  *(undefined4 *)(&stack0x00000000 + DAT_0001203c) =
       *(undefined4 *)(&stack0x00000368 + DAT_0001203c);
  android::Parcel::Parcel(this);
  puVar11 = &stack0x00000248 + iVar1;
  memset(puVar11,0,0x100);
  if ((*(int *)(&stack0xfffffff0 + iVar1) == 0) || (*(int *)(&stack0xfffffff4 + iVar1) == 0)) {
    __android_log_print(6,DAT_00012048 + 0x11d6e,DAT_0001204c + 0x11d70,
                        *(undefined4 *)(&stack0xfffffff0 + iVar1));
    uVar2 = 0;
    goto LAB_0001213a;
  }
  android::Parcel::setData((uchar *)this,*(uint *)(&stack0xfffffff4 + iVar1));
  android::Parcel::setDataPosition((uint)this);
  android::Parcel::readInt32();
  android::Parcel::readString16();
  psVar8 = *(short **)(&stack0x00000044 + iVar1);
  if (psVar8 != (short *)0x0) {
    for (; (*psVar8 != 0 && (puVar11 != &stack0xffffffec + DAT_00012050 + iVar1));
        puVar11 = puVar11 + 1) {
      *puVar11 = (char)*psVar8;
      psVar8 = psVar8 + 1;
    }
  }
  *puVar11 = 0;
  pcVar5 = &stack0x00000248 + iVar1;
  iVar3 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012054));
  if (iVar3 == 0) {
    puVar11 = &stack0x00000048 + iVar1;
    memset(puVar11,0,0x100);
    if (param_1 != 1) goto LAB_00012132;
    iVar3 = android::Parcel::readInt32();
    android::Parcel::readString16();
    psVar8 = *(short **)(&stack0x00000040 + iVar1);
    if (psVar8 != (short *)0x0) {
      for (; (*psVar8 != 0 && (puVar11 != &stack0x000000c7 + iVar1)); puVar11 = puVar11 + 1) {
        *puVar11 = (char)*psVar8;
        psVar8 = psVar8 + 1;
      }
    }
    *puVar11 = 0;
    pcVar5 = &stack0x00000048 + iVar1;
    iVar13 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012058));
    if (((iVar13 == 0) ||
        (iVar13 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_0001205c)), iVar13 == 0)) ||
       (iVar13 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012060)), iVar13 == 0)) {
      puVar11 = &stack0x00000040;
      goto LAB_00011fa4;
    }
    uVar2 = 1;
    pcVar4 = strstr(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012064));
    if (pcVar4 == (char *)0x0) {
      uVar2 = 2;
      pcVar4 = strstr(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012068));
      if (pcVar4 == (char *)0x0) {
        uVar2 = 0;
        pcVar5 = strstr(pcVar5,(char *)(DAT_0001206c + 0x11e6e));
        if (pcVar5 != (char *)0x0) {
          uVar2 = 3;
        }
      }
    }
    if (iVar3 == 3) {
      uVar6 = android::Parcel::readInt32();
      *(undefined1 **)(&stack0xfffffff0 + iVar1) = &stack0x00000008 + iVar1;
      *(undefined4 *)(&stack0xfffffff4 + iVar1) = uVar6;
      for (iVar3 = 0; iVar3 < *(int *)(&stack0xfffffff4 + iVar1); iVar3 = iVar3 + 1) {
        android::Parcel::readString16();
        android::String16::~String16((String16 *)(&stack0x00000038 + iVar1));
      }
      android::Parcel::readString16();
      puVar11 = &stack0x00000148 + iVar1;
      memset(puVar11,0,0x100);
      psVar8 = *(short **)(&stack0x0000003c + iVar1);
      if (psVar8 != (short *)0x0) {
        for (; (*psVar8 != 0 && (puVar11 != &stack0x000001c7 + iVar1)); puVar11 = puVar11 + 1) {
          *puVar11 = (char)*psVar8;
          psVar8 = psVar8 + 1;
        }
      }
      *puVar11 = 0;
      pcVar5 = strstr(&stack0x00000148 + iVar1,(char *)**(undefined4 **)(iVar12 + DAT_00012070));
      if (pcVar5 != (char *)0x0) {
        uVar2 = 3;
      }
      pcVar5 = strstr(&stack0x00000148 + iVar1,(char *)**(undefined4 **)(iVar12 + DAT_00012064));
      if (pcVar5 == (char *)0x0) {
        pcVar5 = strstr(&stack0x00000148 + iVar1,(char *)**(undefined4 **)(iVar12 + DAT_00012068));
        if (pcVar5 != (char *)0x0) {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 1;
      }
      android::String16::~String16((String16 *)(&stack0x0000003c + iVar1));
    }
    android::String16::~String16((String16 *)(&stack0x00000040 + iVar1));
  }
  else {
    iVar3 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012074));
    if (((iVar3 == 0) ||
        (iVar3 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012078)), iVar3 == 0)) ||
       (iVar3 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_0001207c)), iVar3 == 0)) {
      uVar2 = android::Parcel::dataPosition();
      puVar11 = &stack0x00000148 + iVar1;
      **(undefined4 **)(&stack0x00000000 + iVar1) = uVar2;
      android::Parcel::readString16();
      memset(puVar11,0,0x100);
      psVar8 = *(short **)(&stack0x0000003c + iVar1);
      if (psVar8 != (short *)0x0) {
        for (; (*psVar8 != 0 && (puVar11 != &stack0x000001c7 + iVar1)); puVar11 = puVar11 + 1) {
          *puVar11 = (char)*psVar8;
          psVar8 = psVar8 + 1;
        }
      }
      *puVar11 = 0;
      __n = ((*(uint *)((int)*(void **)(&stack0x0000003c + iVar1) + -0xc) >> 1) - 1) * 2;
      if ((int)__n < 2) {
        puVar11 = &stack0x0000003c;
LAB_00011fa4:
        android::String16::~String16((String16 *)(puVar11 + iVar1));
        goto LAB_00012132;
      }
      if (__n - DAT_00012080 != 0 && (int)DAT_00012080 <= (int)__n) {
        __n = DAT_00012080;
      }
      memcpy(*(void **)(&stack0xfffffff8 + iVar1),*(void **)(&stack0x0000003c + iVar1),__n);
      iVar3 = *(int *)(&stack0xfffffff8 + iVar1);
      *(undefined1 *)(iVar3 + __n) = 0x2c;
      iVar14 = __n + 2;
      puVar11 = &stack0x00000008 + iVar1;
      ((undefined1 *)(iVar3 + __n))[1] = 0;
      android::Parcel::readInt32();
      iVar3 = android::Parcel::dataPosition();
      *(int *)(&stack0xfffffff4 + iVar1) = iVar3;
      iVar13 = 1;
      if (0x8c < (uint)(*(int *)(&stack0xfffffff0 + iVar1) - iVar3)) {
        iVar13 = android::Parcel::readInt32();
        uVar2 = android::Parcel::dataPosition();
        *(undefined4 *)(&stack0xfffffff0 + iVar1) = uVar2;
        android::Parcel::setDataPosition((uint)puVar11);
        android::Parcel::readString16();
        if ((*(uint *)(*(int *)(&stack0x00000038 + iVar1) + -0xc) >> 1) - 1 < 0x15) {
          android::Parcel::setDataPosition((uint)puVar11);
          if (6 < iVar13) {
            iVar13 = 6;
          }
        }
        else {
          android::Parcel::setDataPosition((uint)puVar11);
          iVar13 = 1;
        }
        android::String16::~String16((String16 *)(&stack0x00000038 + iVar1));
      }
      *(undefined1 **)(&stack0xfffffff0 + iVar1) = &stack0x00000048 + iVar1;
      for (iVar3 = 0; iVar3 < iVar13; iVar3 = iVar3 + 1) {
        android::Parcel::readString16();
        memset(*(void **)(&stack0xfffffff0 + iVar1),0,0x100);
        psVar8 = *(short **)(&stack0x00000038 + iVar1);
        puVar11 = *(undefined1 **)(&stack0xfffffff0 + iVar1);
        if (psVar8 != (short *)0x0) {
          for (; (*psVar8 != 0 && (puVar11 != &stack0x000000c7 + iVar1)); puVar11 = puVar11 + 1) {
            *puVar11 = (char)*psVar8;
            psVar8 = psVar8 + 1;
          }
        }
        *puVar11 = 0;
        uVar9 = ((*(uint *)((int)*(void **)(&stack0x00000038 + iVar1) + -0xc) >> 1) - 1) * 2;
        uVar10 = 0x400U - iVar14;
        if ((int)uVar9 < (int)(0x400U - iVar14)) {
          uVar10 = uVar9;
        }
        uVar10 = uVar10 & (int)~uVar10 >> 0x1f;
        *(uint *)(&stack0xfffffff4 + iVar1) = uVar10;
        memcpy((void *)(*(int *)(&stack0xfffffff8 + iVar1) + iVar14),
               *(void **)(&stack0x00000038 + iVar1),uVar10);
        iVar14 = iVar14 + *(int *)(&stack0xfffffff4 + iVar1);
        android::String16::~String16((String16 *)(&stack0x00000038 + iVar1));
      }
      **(int **)(&stack0xfffffffc + iVar1) = iVar14;
      android::String16::~String16((String16 *)(&stack0x0000003c + iVar1));
      uVar2 = 0xb;
    }
    else {
      iVar3 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012184));
      if (iVar3 == 0) {
        uVar2 = 0x14;
        if (1 < param_1 - 0x1bU) {
LAB_00012132:
          uVar2 = 0;
        }
      }
      else {
        iVar3 = strcmp(pcVar5,(char *)**(undefined4 **)(iVar12 + DAT_00012188));
        if ((iVar3 != 0) || ((uVar2 = 0x26, param_1 != 1 && (uVar2 = 0x27, param_1 != 4))))
        goto LAB_00012132;
      }
    }
  }
  android::String16::~String16((String16 *)(&stack0x00000044 + iVar1));
LAB_0001213a:
  android::Parcel::~Parcel((Parcel *)(&stack0x00000008 + iVar1));
  if (*(int *)(&stack0x00000348 + iVar1) == **(int **)(iVar12 + DAT_0001218c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}



/* Function: hook_sendReply @ 00012190 */

void hook_sendReply(void)

{
  Parcel *pPVar1;
  Parcel aPStack_38 [48];
  
  android::Parcel::Parcel(aPStack_38);
  pPVar1 = (Parcel *)android::IPCThreadState::self();
  android::IPCThreadState::sendReply(pPVar1,(uint)aPStack_38);
  android::Parcel::~Parcel(aPStack_38);
  return;
}



/* Function: hook_entry @ 000121b0 */

undefined4 hook_entry(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  pthread_key_t *__key;
  char *__dest;
  pthread_t apStack_1c [2];
  
  uVar1 = get_module_base(0xffffffff,DAT_0001222c + 0x121be);
  __android_log_print(3,DAT_00012230 + 0x121cc,DAT_00012234 + 0x121ce,uVar1);
  __key = (pthread_key_t *)(DAT_00012238 + 0x121dc);
  iVar3 = DAT_0001223c + 0x121de;
  do {
    iVar2 = pthread_key_create(__key,(__destr_function *)0x0);
  } while (iVar2 != 0);
  uVar1 = elf_hook(DAT_00012244 + 0x121f8,uVar1,DAT_00012248 + 0x121f6,
                   *(undefined4 *)(iVar3 + DAT_00012240));
  __android_log_print(3,DAT_0001224c + 0x12204,DAT_00012250 + 0x12206,uVar1);
  __dest = *(char **)(iVar3 + DAT_00012254);
  strcpy(__dest,param_1);
  pthread_create(apStack_1c,(pthread_attr_t *)0x0,*(__start_routine **)(iVar3 + DAT_00012258),__dest
                );
  return 0;
}



/* Function: FUN_0001225c @ 0001225c */

uint * FUN_0001225c(uint *param_1)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  pthread_key_t *ppVar4;
  
  uVar3 = *param_1;
  if ((uVar3 & 0xff) < 0x11) {
    if (DAT_00012308 < (int)uVar3) {
      if (DAT_00012314 < (int)uVar3) {
        if (uVar3 == DAT_00012318) {
          return param_1 + 0xb;
        }
        if (uVar3 == DAT_00012318 + 1) {
          ppVar4 = (pthread_key_t *)(DAT_0001231c + 0x122dc);
          pvVar1 = pthread_getspecific(*ppVar4);
          if (0 < (int)pvVar1) {
            modify_reply(param_1[9],param_1[7]);
            pthread_setspecific(*ppVar4,(void *)0x0);
          }
          return param_1 + 0xb;
        }
      }
      else {
        if (DAT_00012314 + -1 <= (int)uVar3) {
          return param_1 + 3;
        }
        if (uVar3 == DAT_00012314 - 5U) {
          return param_1 + 3;
        }
      }
    }
    else {
      if (DAT_00012308 + -1 <= (int)uVar3) {
        return param_1 + 3;
      }
      uVar2 = DAT_00012310;
      if ((int)uVar3 <= DAT_0001230c) {
        if (DAT_0001230c + -3 <= (int)uVar3) {
          return param_1 + 2;
        }
        if (uVar3 == DAT_0001230c - 5U) {
          return param_1 + 2;
        }
        uVar2 = DAT_0001230c - 4;
      }
      if (uVar3 == uVar2) {
        return param_1 + 2;
      }
    }
  }
  else {
    __android_log_print(3,DAT_00012300 + 0x12274,DAT_00012304 + 0x12276);
  }
  return param_1 + 1;
}



/* Function: FUN_00012320 @ 00012320 */

void FUN_00012320(uint *param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  int iVar10;
  int *piVar11;
  
  iVar1 = DAT_000124a8;
  iVar10 = DAT_000124a0 + 0x1232c;
  piVar11 = (int *)(&stack0xffffffec + DAT_000124a8);
  *(undefined4 *)(&stack0xffffffec + DAT_000124ac + DAT_000124a8) =
       **(undefined4 **)(iVar10 + DAT_000124a4);
  uVar7 = *param_1;
  puVar9 = param_1 + 1;
  if (uVar7 == DAT_000124b0) {
    puVar9 = param_1 + 2;
    iVar3 = DAT_000124b4 + 0x1234c;
    iVar5 = DAT_000124b8 + 0x1234e;
    uVar7 = param_1[1];
LAB_00012360:
    __android_log_print(3,iVar3,iVar5,uVar7);
  }
  else {
    if (0x11 < (uVar7 & 0xff)) {
      iVar3 = DAT_000124bc + 0x12360;
      iVar5 = DAT_000124c0 + 0x12362;
      goto LAB_00012360;
    }
    if (DAT_000124c4 < (int)uVar7) {
      if (uVar7 == DAT_000124d0) {
        *(undefined4 *)(&stack0x00000004 + DAT_000124a8) = 0;
        uVar7 = param_1[6];
        iVar3 = **(int **)(iVar10 + DAT_000124d8);
        *(uint *)(&stack0xfffffff4 + DAT_000124a8) = uVar7;
        *(uint *)(&stack0x00000000 + DAT_000124a8) = uVar7;
        if ((iVar3 == 1) &&
           (**(int **)(iVar10 + DAT_000124dc) != *(int *)(&stack0xfffffff4 + DAT_000124a8))) {
          uVar7 = param_1[3];
          uVar4 = param_1[9];
          uVar6 = param_1[7];
          *(undefined1 **)(&stack0xfffffff8 + DAT_000124a8) = &stack0x00000008 + DAT_000124a8;
          *(undefined1 **)(&stack0xfffffff0 + DAT_000124a8) = &stack0x00000000 + DAT_000124a8;
          *(undefined1 **)(&stack0xffffffec + DAT_000124a8) = &stack0x00000004 + DAT_000124a8;
          iVar3 = parse_requestdata(uVar7,uVar4,uVar6,
                                    *(undefined4 *)(&stack0xfffffff8 + DAT_000124a8));
          if (iVar3 != 0) {
            if (2 < iVar3 - 1U) {
              iVar5 = is_block(iVar3,*(undefined4 *)(&stack0xfffffff4 + iVar1),
                               *(undefined4 *)(&stack0xfffffff8 + iVar1),
                               *(undefined4 *)(&stack0x00000004 + iVar1));
              if (iVar5 < 1) goto LAB_00012480;
              if ((iVar3 == 0x28) || (iVar3 == 0x14)) goto LAB_00012464;
              if (iVar3 == 0xb) goto LAB_0001247a;
            }
LAB_0001247e:
            *param_2 = iVar3;
          }
        }
        else if ((DAT_000124e0 < *(uint *)(&stack0xfffffff4 + DAT_000124a8)) &&
                ((iVar3 = is_whitelist(*(uint *)(&stack0xfffffff4 + DAT_000124a8)), iVar3 == 0 &&
                 (**(int **)(iVar10 + DAT_000124dc) != *(int *)(&stack0xfffffff4 + iVar1))))) {
          uVar7 = param_1[3];
          uVar4 = param_1[9];
          uVar6 = param_1[7];
          *(undefined1 **)(&stack0xfffffff8 + iVar1) = &stack0x00000008 + iVar1;
          *(undefined1 **)(&stack0xfffffff0 + iVar1) = &stack0x00000000 + iVar1;
          uVar8 = *(undefined4 *)(&stack0xfffffff8 + iVar1);
          *piVar11 = (int)(&stack0x00000004 + iVar1);
          iVar3 = parse_requestdata(uVar7,uVar4,uVar6,uVar8);
          if ((iVar3 != 0) &&
             (iVar5 = is_block(iVar3,*(undefined4 *)(&stack0xfffffff4 + iVar1),
                               *(undefined4 *)(&stack0xfffffff8 + iVar1),
                               *(undefined4 *)(&stack0x00000004 + iVar1)), 0 < iVar5)) {
            if ((iVar3 == 0x28) || (iVar3 == 0x14)) {
LAB_00012464:
              uVar7 = 0x5e;
            }
            else {
              if (iVar3 != 0xb) goto LAB_0001247e;
              __android_log_print(3,DAT_000124e4 + 0x12476,DAT_000124e8 + 0x12478);
LAB_0001247a:
              uVar7 = 0x52;
            }
            param_1[7] = uVar7;
            goto LAB_0001247e;
          }
        }
LAB_00012480:
        puVar2 = param_1 + 0xb;
        goto LAB_00012484;
      }
      puVar2 = param_1 + 0xb;
      if ((uVar7 == DAT_000124d0 + 1) || (puVar2 = param_1 + 4, uVar7 == DAT_000124d4))
      goto LAB_00012484;
    }
    else {
      puVar2 = param_1 + 3;
      if (((DAT_000124c4 + -3 <= (int)uVar7) || (puVar2 = param_1 + 2, uVar7 == DAT_000124c8)) ||
         (((int)DAT_000124c8 <= (int)uVar7 && (uVar7 + DAT_000124cc < 2)))) goto LAB_00012484;
    }
  }
  puVar2 = puVar9;
LAB_00012484:
  if (*(int *)(&stack0xffffffec + DAT_000124ac + iVar1) == **(int **)(iVar10 + DAT_000124a4)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar2);
}



/* Function: hooked_ioctl @ 000124f0 */

int hooked_ioctl(int param_1,ulong param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  pthread_key_t *ppVar3;
  uint uVar4;
  bool bVar5;
  void *local_1c [2];
  
  bVar5 = param_2 + DAT_00012570 == 0;
  if ((param_3 != (int *)0x0 && bVar5) && (uVar1 = param_3[2], uVar1 != 0)) {
    uVar4 = uVar1 + *param_3;
    while (uVar1 < uVar4) {
      uVar1 = FUN_0001225c();
    }
  }
  iVar2 = ioctl(param_1,param_2,param_3);
  if (((-1 < iVar2) && (param_3 != (int *)0x0 && bVar5)) && (uVar1 = param_3[5], uVar1 != 0)) {
    uVar4 = uVar1 + param_3[4];
    ppVar3 = (pthread_key_t *)(DAT_00012574 + 0x1254c);
    while (uVar1 < uVar4) {
      local_1c[0] = (void *)0x0;
      uVar1 = FUN_00012320(uVar1,local_1c);
      if (0 < (int)local_1c[0]) {
        pthread_setspecific(*ppVar3,local_1c[0]);
      }
    }
  }
  return iVar2;
}



/* Function: read_relocation_table @ 00012578 */

undefined4 read_relocation_table(int param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  undefined4 uVar5;
  
  uVar5 = 0x16;
  if (param_2 != 0) {
    pvVar1 = malloc(*(size_t *)(param_2 + 0x14));
    *param_3 = pvVar1;
    _Var2 = lseek(param_1,*(__off_t *)(param_2 + 0x10),0);
    if (_Var2 < 0) {
      free((void *)*param_3);
      puVar3 = (undefined4 *)__errno();
      uVar5 = *puVar3;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,*(size_t *)(param_2 + 0x14));
      uVar5 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar3 = (undefined4 *)__errno();
        uVar5 = 0x16;
        *puVar3 = 0x16;
      }
    }
  }
  return uVar5;
}



/* Function: read_symbol_table @ 000125cc */

undefined4 read_symbol_table(int param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  undefined4 uVar5;
  
  uVar5 = 0x16;
  if (param_2 != 0) {
    pvVar1 = malloc(*(size_t *)(param_2 + 0x14));
    *param_3 = pvVar1;
    _Var2 = lseek(param_1,*(__off_t *)(param_2 + 0x10),0);
    if (_Var2 < 0) {
      free((void *)*param_3);
      puVar3 = (undefined4 *)__errno();
      uVar5 = *puVar3;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,*(size_t *)(param_2 + 0x14));
      uVar5 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar3 = (undefined4 *)__errno();
        uVar5 = 0x16;
        *puVar3 = 0x16;
      }
    }
  }
  return uVar5;
}



/* Function: read_string_table @ 00012620 */

undefined4 read_string_table(int param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  undefined4 uVar5;
  
  uVar5 = 0x16;
  if (param_2 != 0) {
    pvVar1 = malloc(*(size_t *)(param_2 + 0x14));
    *param_3 = pvVar1;
    _Var2 = lseek(param_1,*(__off_t *)(param_2 + 0x10),0);
    if (_Var2 < 0) {
      free((void *)*param_3);
      puVar3 = (undefined4 *)__errno();
      uVar5 = *puVar3;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,*(size_t *)(param_2 + 0x14));
      uVar5 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar3 = (undefined4 *)__errno();
        uVar5 = 0x16;
        *puVar3 = 0x16;
      }
    }
  }
  return uVar5;
}



/* Function: read_section_table @ 00012674 */

undefined4 read_section_table(int param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  undefined4 uVar5;
  size_t __size;
  
  uVar5 = 0x16;
  if (param_2 != 0) {
    __size = (uint)*(ushort *)(param_2 + 0x30) * 0x28;
    pvVar1 = malloc(__size);
    *param_3 = pvVar1;
    _Var2 = lseek(param_1,*(__off_t *)(param_2 + 0x20),0);
    if (_Var2 < 0) {
      free((void *)*param_3);
      puVar3 = (undefined4 *)__errno();
      uVar5 = *puVar3;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,__size);
      uVar5 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar3 = (undefined4 *)__errno();
        uVar5 = 0x16;
        *puVar3 = 0x16;
      }
    }
  }
  return uVar5;
}



/* Function: read_header @ 000126d0 */

undefined4 read_header(int param_1,undefined4 *param_2)

{
  void *pvVar1;
  __off_t _Var2;
  undefined4 *puVar3;
  ssize_t sVar4;
  undefined4 uVar5;
  
  pvVar1 = malloc(0x34);
  *param_2 = pvVar1;
  _Var2 = lseek(param_1,0,0);
  if (_Var2 < 0) {
    free((void *)*param_2);
    puVar3 = (undefined4 *)__errno();
    uVar5 = *puVar3;
  }
  else {
    sVar4 = read(param_1,(void *)*param_2,0x34);
    uVar5 = 0;
    if (sVar4 < 1) {
      free((void *)*param_2);
      puVar3 = (undefined4 *)__errno();
      uVar5 = 0x16;
      *puVar3 = 0x16;
    }
  }
  return uVar5;
}



/* Function: section_by_name @ 0001271c */

undefined4 section_by_name(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *__dest;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  void *local_24;
  void *local_20;
  void *local_1c [2];
  
  iVar6 = DAT_0001282c + 0x1272c;
  __android_log_print(3,iVar6,DAT_00012830 + 0x12730,param_2);
  local_1c[0] = (void *)0x0;
  local_20 = (void *)0x0;
  local_24 = (void *)0x0;
  *param_3 = 0;
  iVar2 = read_header(param_1,local_1c);
  if (((iVar2 == 0) && (iVar2 = read_section_table(param_1,local_1c[0],&local_20), iVar2 == 0)) &&
     (iVar3 = read_string_table(param_1,(void *)((int)local_20 +
                                                (uint)*(ushort *)((int)local_1c[0] + 0x32) * 0x28),
                                &local_24), iVar1 = DAT_0001283c, iVar2 = DAT_00012838, iVar3 == 0))
  {
    __android_log_print(3,iVar6,DAT_00012834 + 0x12788,*(undefined2 *)((int)local_1c[0] + 0x30));
    iVar6 = 0;
    for (uVar7 = 0; uVar7 < *(ushort *)((int)local_1c[0] + 0x30); uVar7 = uVar7 + 1) {
      __android_log_print(3,iVar2 + 0x12794,iVar1 + 0x12796,uVar7,
                          (int)local_24 + *(int *)((int)local_20 + iVar6));
      iVar3 = strcmp(param_2,(char *)((int)local_24 + *(int *)((int)local_20 + iVar6)));
      if (iVar3 == 0) {
        __dest = malloc(0x28);
        *param_3 = __dest;
        if (__dest == (void *)0x0) {
          free(local_1c[0]);
          free(local_20);
          free(local_24);
          goto LAB_000127e2;
        }
        memcpy(__dest,(void *)((int)local_20 + iVar6),0x28);
        break;
      }
      iVar6 = iVar6 + 0x28;
    }
    if (local_1c[0] != (void *)0x0) {
      free(local_1c[0]);
    }
    if (local_20 != (void *)0x0) {
      free(local_20);
    }
    uVar5 = 0;
    if (local_24 != (void *)0x0) {
      free(local_24);
      uVar5 = 0;
    }
  }
  else {
LAB_000127e2:
    puVar4 = (undefined4 *)__errno();
    uVar5 = *puVar4;
  }
  return uVar5;
}



/* Function: section_by_type @ 00012840 */

undefined4 section_by_type(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  void *local_18;
  void *local_14;
  
  __android_log_print(3,DAT_000128dc + 0x12852,DAT_000128e0 + 0x12856,param_2);
  *param_3 = 0;
  local_14 = (void *)0x0;
  local_18 = (void *)0x0;
  iVar1 = read_header(param_1,&local_14);
  if ((iVar1 == 0) && (iVar1 = read_section_table(param_1,local_14,&local_18), iVar1 == 0)) {
    pvVar2 = local_18;
    for (uVar5 = 0; uVar5 < *(ushort *)((int)local_14 + 0x30); uVar5 = uVar5 + 1) {
      if (param_2 == *(int *)((int)pvVar2 + 4)) {
        pvVar2 = malloc(0x28);
        *param_3 = pvVar2;
        if (pvVar2 == (void *)0x0) {
          free(local_14);
          free(local_18);
          goto LAB_000128b0;
        }
        memcpy(pvVar2,(void *)((int)local_18 + uVar5 * 0x28),0x28);
        break;
      }
      pvVar2 = (void *)((int)pvVar2 + 0x28);
    }
    free(local_14);
    free(local_18);
    uVar4 = 0;
  }
  else {
LAB_000128b0:
    puVar3 = (undefined4 *)__errno();
    uVar4 = *puVar3;
  }
  return uVar4;
}



/* Function: section_by_index @ 000128e4 */

undefined4 section_by_index(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  void *__dest;
  undefined4 *puVar2;
  void *local_18;
  void *local_14;
  
  local_14 = (void *)0x0;
  local_18 = (void *)0x0;
  *param_3 = 0;
  iVar1 = read_header(param_1,&local_14);
  if ((iVar1 == 0) && (iVar1 = read_section_table(param_1,local_14,&local_18), iVar1 == 0)) {
    if (*(ushort *)((int)local_14 + 0x30) <= param_2) {
      return 0x16;
    }
    __dest = malloc(0x28);
    *param_3 = __dest;
    if (__dest != (void *)0x0) {
      memcpy(__dest,(void *)((int)local_18 + param_2 * 0x28),0x28);
      free(local_14);
      free(local_18);
      return 0;
    }
    free(local_14);
    free(local_18);
  }
  puVar2 = (undefined4 *)__errno();
  return *puVar2;
}



/* Function: symbol_by_name @ 00012958 */

undefined4
symbol_by_name(undefined4 param_1,int param_2,char *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  void *__dest;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *local_24;
  void *local_20;
  void *local_1c [2];
  
  __android_log_print(3,DAT_00012a24 + 0x1296e,DAT_00012a20 + 0x12970,param_3);
  local_1c[0] = (void *)0x0;
  local_20 = (void *)0x0;
  local_24 = (void *)0x0;
  *param_4 = 0;
  *param_5 = 0;
  iVar1 = section_by_index(param_1,*(undefined4 *)(param_2 + 0x18),local_1c);
  if (((iVar1 == 0) && (iVar1 = read_string_table(param_1,local_1c[0],&local_20), iVar1 == 0)) &&
     (iVar1 = read_symbol_table(param_1,param_2,&local_24), iVar1 == 0)) {
    uVar4 = *(uint *)(param_2 + 0x14);
    for (uVar5 = 0; uVar5 < uVar4 >> 4; uVar5 = uVar5 + 1) {
      iVar1 = strcmp(param_3,(char *)((int)local_20 + *(int *)((int)local_24 + uVar5 * 0x10)));
      if (iVar1 == 0) {
        __dest = malloc(0x10);
        *param_4 = __dest;
        if (__dest == (void *)0x0) {
          free(local_1c[0]);
          free(local_20);
          free(local_24);
          goto LAB_000129e8;
        }
        memcpy(__dest,(void *)((int)local_24 + uVar5 * 0x10),0x10);
        *param_5 = uVar5;
        break;
      }
    }
    free(local_1c[0]);
    free(local_20);
    free(local_24);
    uVar3 = 0;
  }
  else {
LAB_000129e8:
    puVar2 = (undefined4 *)__errno();
    uVar3 = *puVar2;
  }
  return uVar3;
}



/* Function: elf_hook @ 00012a28 */

undefined4 elf_hook(char *param_1,int param_2,int param_3,int param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  uint local_2c;
  void *local_28;
  void *local_24;
  void *local_20;
  void *local_1c [2];
  
  iVar9 = DAT_00012b60 + 0x12a34;
  if (((param_3 != 0) && (param_2 != 0)) && (param_4 != 0)) {
    local_1c[0] = (void *)0x0;
    plVar6 = (long *)(DAT_00012b64 + 0x12a54);
    local_20 = (void *)0x0;
    local_24 = (void *)0x0;
    local_28 = (void *)0x0;
    if (*plVar6 == 0) {
      lVar1 = sysconf(0x27);
      *plVar6 = lVar1;
    }
    iVar2 = open(param_1,0);
    if (-1 < iVar2) {
      iVar3 = section_by_type(iVar2,0xb,local_1c);
      if (((iVar3 == 0) &&
          (iVar3 = symbol_by_name(iVar2,local_1c[0],param_3,&local_28,&local_2c), iVar3 == 0)) &&
         ((iVar3 = section_by_name(iVar2,DAT_00012b68 + 0x12a9e,&local_20), iVar3 == 0 &&
          (iVar3 = section_by_name(iVar2,DAT_00012b6c + 0x12aae,&local_24), iVar3 == 0)))) {
        __android_log_print(3,DAT_00012b78 + 0x12aec,DAT_00012b7c + 0x12aee);
        free(local_1c[0]);
        free(local_28);
        uVar4 = *(uint *)((int)local_20 + 0x14);
        iVar3 = *(int *)((int)local_20 + 0xc);
        free(local_20);
        close(iVar2);
        iVar2 = DAT_00012b84;
        piVar7 = (int *)(param_2 + iVar3);
        for (uVar5 = 0; uVar5 < uVar4 >> 3; uVar5 = uVar5 + 1) {
          if ((uint)piVar7[1] >> 8 == local_2c) {
            iVar3 = *piVar7;
            **(uint **)(iVar9 + DAT_00012b80) = param_2 + iVar3;
            uVar8 = *(undefined4 *)(param_2 + *piVar7);
            iVar9 = mprotect((void *)(-*(size_t *)(iVar2 + 0x12b36) & param_2 + iVar3),
                             *(size_t *)(iVar2 + 0x12b36),7);
            if (iVar9 == -1) {
              return 0;
            }
            *(int *)(param_2 + *piVar7) = param_4;
            return uVar8;
          }
          piVar7 = piVar7 + 2;
        }
      }
      else {
        __android_log_print(3,DAT_00012b70 + 0x12abe,DAT_00012b74 + 0x12ac0);
        free(local_1c[0]);
        free(local_20);
        free(local_24);
        free(local_28);
        close(iVar2);
      }
    }
  }
  return 0;
}



/* Function: insert_data_notification @ 00012b88 */

undefined4 insert_data_notification(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00012bb0 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_00012bb4) + 1;
  }
  *(uint *)(uVar1 * 4 + *(int *)(DAT_00012ba8 + 0x12b90 + DAT_00012bac)) = param_1;
  return 0;
}



/* Function: is_whitelist_notification @ 00012bb8 */

bool is_whitelist_notification(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00012be4 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_00012be8) + 1;
  }
  return *(uint *)(uVar1 * 4 + *(int *)(DAT_00012bdc + 0x12bc0 + DAT_00012be0)) == param_1;
}



/* Function: insert_data @ 00012bec */

undefined4 insert_data(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_00012c14 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_00012c18) + 1;
  }
  *(uint *)(uVar1 * 4 + *(int *)(DAT_00012c0c + 0x12bf4 + DAT_00012c10)) = param_1;
  return 0;
}



/* Function: get_module_base @ 00012c1c */

void get_module_base(int param_1,char *param_2)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  ulong uVar5;
  
  iVar1 = DAT_00012cc4;
  iVar4 = DAT_00012ccc + 0x12c30;
  *(undefined4 *)(&stack0xffffffec + DAT_00012cd0 + DAT_00012cc4) =
       **(undefined4 **)(iVar4 + DAT_00012cc8);
  if (param_1 < 0) {
    pcVar3 = (char *)(DAT_00012cd8 + 0x12c44);
  }
  else {
    pcVar3 = (char *)(DAT_00012cdc + 0x12c4a);
  }
  snprintf(&stack0xffffffec + DAT_00012cd4 + DAT_00012cc4,0x20,pcVar3);
  uVar5 = 0;
  __stream = fopen(&stack0xffffffec + DAT_00012cd4 + iVar1,(char *)(DAT_00012ce0 + 0x12c58));
  if (__stream != (FILE *)0x0) {
    pcVar3 = &stack0xfffffff0 + iVar1;
    do {
      pcVar2 = fgets(pcVar3,0x400,__stream);
      if (pcVar2 == (char *)0x0) goto LAB_00012ca0;
      pcVar2 = strstr(pcVar3,param_2);
    } while (pcVar2 == (char *)0x0);
    pcVar3 = strtok(pcVar3,(char *)(DAT_00012ce4 + 0x12c7a));
    uVar5 = strtoul(pcVar3,(char **)0x0,0x10);
    if (uVar5 == 0x8000) {
LAB_00012ca0:
      uVar5 = 0;
    }
    fclose(__stream);
  }
  if (*(int *)(&stack0xffffffec + DAT_00012cd0 + iVar1) == **(int **)(iVar4 + DAT_00012cc8)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}



/* Function: is_whitelist_powercenter @ 00012cec */

bool is_whitelist_powercenter(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_00012d30 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_00012d38) + 1;
  }
  iVar2 = *(int *)(DAT_00012d34 + 0x12cfa + DAT_00012d3c);
  __android_log_print(6,DAT_00012d40 + 0x12d1a,DAT_00012d44 + 0x12d1e,param_1,uVar1,
                      *(undefined4 *)(uVar1 * 4 + iVar2));
  return *(uint *)(uVar1 * 4 + iVar2) == param_1;
}



/* Function: insert_data_powercenter @ 00012d48 */

undefined4 insert_data_powercenter(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00012d84;
  __android_log_print(6,DAT_00012d7c + 0x12d58,DAT_00012d80 + 0x12d56);
  uVar2 = DAT_00012d8c & param_1;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | DAT_00012d90) + 1;
  }
  *(uint *)(uVar2 * 4 + *(int *)(iVar1 + 0x12d62 + DAT_00012d88)) = param_1;
  return 0;
}



/* Function: init_whitelist @ 00012d94 */

void init_whitelist(void)

{
  int iVar1;
  FILE *__stream;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 local_2c;
  char acStack_28 [12];
  int local_1c;
  
  iVar4 = DAT_00012e18 + 0x12da0;
  local_1c = **(int **)(iVar4 + DAT_00012e1c);
  __stream = fopen((char *)(DAT_00012e24 + 0x12dae),(char *)(DAT_00012e20 + 0x12daa));
  iVar1 = DAT_00012e30;
  if (__stream == (FILE *)0x0) {
    __android_log_print(6,DAT_00012e28 + 0x12dbe,DAT_00012e2c + 0x12dc0);
    uVar2 = 0;
  }
  else {
    fseek(__stream,0,0);
    while (pcVar3 = fgets(acStack_28,10,__stream), pcVar3 != (char *)0x0) {
      sscanf(acStack_28,(char *)(iVar1 + 0x12ddc),&local_2c);
      insert_data(local_2c);
    }
    fclose(__stream);
    uVar2 = 1;
  }
  if (local_1c != **(int **)(iVar4 + DAT_00012e1c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



/* Function: is_whitelist @ 00012e34 */

bool is_whitelist(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_00012e70 + 0x12e40;
  iVar4 = *(int *)(iVar3 + DAT_00012e74);
  if (*(int *)(iVar4 + 0x400) == 0) {
    uVar1 = init_whitelist();
    *(undefined4 *)(iVar4 + 0x400) = uVar1;
  }
  uVar2 = DAT_00012e78 & param_1;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | DAT_00012e7c) + 1;
  }
  return *(uint *)(uVar2 * 4 + *(int *)(iVar3 + DAT_00012e74)) == param_1;
}



/* Function: makeAddr @ 00012e80 */

undefined4 makeAddr(char *param_1,undefined2 *param_2,int *param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  sVar1 = strlen(param_1);
  if ((int)sVar1 < 0x6b) {
    *(undefined1 *)(param_2 + 1) = 0;
    strcpy((char *)((int)param_2 + 3),param_1);
    *param_2 = 1;
    uVar2 = 0;
    *param_3 = sVar1 + 3;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* Function: create_server @ 00012eb0 */

void create_server(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  
  iVar1 = DAT_0001313c;
  iVar8 = DAT_00013144 + 0x12ec4;
  iVar9 = DAT_0001314c + 0x12ed0;
  *(undefined4 *)(&stack0xffffffec + DAT_00013148 + DAT_0001313c) =
       **(undefined4 **)(iVar8 + DAT_00013140);
  iVar3 = DAT_00013150 + DAT_0001313c;
  __android_log_print(6,iVar9,DAT_00013154 + 0x12ed4,param_1);
  iVar2 = makeAddr(param_1,(sockaddr *)(&stack0xffffffec + iVar3),&stack0x00000004 + iVar1);
  if (-1 < iVar2) {
    iVar2 = socket(1,1,1);
    *(int *)(&stack0xfffffff0 + iVar1) = iVar2;
    if (iVar2 < 0) {
      __android_log_print(6,iVar9,DAT_00013158 + 0x12f08);
    }
    else {
      iVar3 = bind(*(int *)(&stack0xfffffff0 + iVar1),(sockaddr *)(&stack0xffffffec + iVar3),
                   *(socklen_t *)(&stack0x00000004 + iVar1));
      if (iVar3 < 0) {
        iVar3 = DAT_0001315c + 0x12f20;
      }
      else {
        iVar3 = listen(*(int *)(&stack0xfffffff0 + iVar1),1);
        if (-1 < iVar3) {
          *(undefined1 **)(&stack0x00000000 + iVar1) = &stack0x0000000c + iVar1;
          *(undefined1 **)(&stack0xfffffffc + iVar1) = &stack0x00000010 + iVar1;
          do {
            do {
              while( true ) {
                iVar3 = accept(*(int *)(&stack0xfffffff0 + iVar1),(sockaddr *)0x0,(socklen_t *)0x0);
                *(int *)(&stack0xfffffff8 + iVar1) = iVar3;
                if (-1 < iVar3) break;
                __android_log_print(6,DAT_00013164 + 0x12f68,DAT_00013168 + 0x12f6a);
              }
              sVar4 = read(*(int *)(&stack0xfffffff8 + iVar1),&stack0x00000008 + iVar1,0x400);
              iVar3 = DAT_00013170;
            } while (sVar4 < 0);
            if (sVar4 < 5) {
              if ((sVar4 == 0) && (*(int *)(DAT_000131d4 + 0x130e0) != 0)) {
                iVar3 = *(int *)(iVar8 + DAT_00013194);
                puVar10 = *(undefined4 **)(iVar8 + DAT_00013188);
                if (*(int *)*puVar10 == iVar3) {
                  __android_log_print(6,DAT_000131d8 + 0x130fe,DAT_000131dc + 0x13100);
                }
                else {
                  __android_log_print(6,DAT_000131e0 + 0x1310e,DAT_000131e4 + 0x13110);
                  *(int *)*puVar10 = iVar3;
                }
              }
            }
            else {
              iVar2 = *(int *)(&stack0x00000008 + iVar1);
              if (sVar4 == 0xc) {
                if (iVar2 == 1) {
                  **(undefined4 **)(iVar8 + DAT_0001316c) =
                       *(undefined4 *)(&stack0x0000000c + iVar1);
                  iVar3 = iVar3 + 0x12fa2;
                  __android_log_print(6,iVar3,DAT_00013174 + 0x12fa6);
                  iVar2 = DAT_0001317c;
                  uVar6 = *(undefined4 *)(&stack0x00000010 + iVar1);
                  **(undefined4 **)(iVar8 + DAT_00013178) = uVar6;
                  iVar2 = iVar2 + 0x12fb8;
                }
                else {
                  if (iVar2 != 0) {
                    if (iVar2 == 2) {
                      __android_log_print(6,DAT_000131ac + 0x1303c,DAT_000131b0 + 0x1303e);
                      uVar5 = *(uint *)(&stack0x00000010 + iVar1);
                      if (*(int *)(&stack0x0000000c + iVar1) == 1) {
                        uVar7 = DAT_000131b8 & uVar5;
                        if ((int)uVar7 < 0) {
                          uVar7 = (uVar7 - 1 | DAT_000131bc) + 1;
                        }
                        *(uint *)(uVar7 * 4 + *(int *)(iVar8 + DAT_000131b4)) = uVar5;
                      }
                      else {
                        uVar5 = uVar5 & DAT_000131b8;
                        if ((int)uVar5 < 0) {
                          uVar5 = (uVar5 - 1 | DAT_000131bc) + 1;
                        }
                        *(undefined4 *)(uVar5 * 4 + *(int *)(iVar8 + DAT_000131b4)) = 0;
                      }
                      goto LAB_00013116;
                    }
                    goto LAB_0001307c;
                  }
                  iVar11 = *(int *)(&stack0x0000000c + iVar1);
                  iVar3 = DAT_00013180 + 0x12fc6;
                  __android_log_print(6,iVar3,DAT_00013184 + 0x12fca,iVar11);
                  iVar9 = DAT_000131a0;
                  iVar2 = DAT_00013190;
                  *(int *)(&stack0xfffffff4 + iVar1) = DAT_00013188;
                  if (iVar11 == 0) {
                    *(undefined4 *)(DAT_0001319c + 0x13008) = 0;
                    __android_log_print(6,iVar3,iVar9 + 0x1300c);
                    puVar10 = *(undefined4 **)(iVar8 + *(int *)(&stack0xfffffff4 + iVar1));
                    *(undefined4 *)*puVar10 = *(undefined4 *)(iVar8 + DAT_000131a4);
                    iVar2 = DAT_000131a8 + 0x13022;
                  }
                  else {
                    *(undefined4 *)(DAT_0001318c + 0x12fe2) = 1;
                    __android_log_print(6,iVar3,iVar2 + 0x12fe6);
                    puVar10 = *(undefined4 **)(iVar8 + *(int *)(&stack0xfffffff4 + iVar1));
                    iVar2 = DAT_00013198 + 0x12ffc;
                    *(undefined4 *)*puVar10 = *(undefined4 *)(iVar8 + DAT_00013194);
                  }
                  uVar6 = *(undefined4 *)*puVar10;
                }
                __android_log_print(6,iVar3,iVar2,uVar6);
              }
              else {
LAB_0001307c:
                if (iVar2 == 10) {
                  __android_log_print(6,DAT_000131c0 + 0x1308a,DAT_000131c4 + 0x1308c);
                  iVar3 = **(int **)(&stack0x00000000 + iVar1);
                  **(int **)(iVar8 + DAT_000131c8) = iVar3;
                  if (iVar3 == 0) {
                    memset(*(void **)(iVar8 + DAT_000131cc),0,DAT_000131d0);
                  }
                  else if (iVar3 == 1) {
                    memset(*(void **)(iVar8 + DAT_000131cc),0,DAT_000131d0);
                    puVar10 = *(undefined4 **)(&stack0xfffffffc + iVar1);
                    *(undefined4 *)(&stack0xfffffff4 + iVar1) = *puVar10;
                    for (iVar3 = 0; iVar3 < *(int *)(&stack0xfffffff4 + iVar1); iVar3 = iVar3 + 1) {
                      puVar10 = puVar10 + 1;
                      insert_data_powercenter(*puVar10);
                    }
                  }
                }
              }
            }
LAB_00013116:
            close(*(int *)(&stack0xfffffff8 + iVar1));
          } while( true );
        }
        iVar3 = DAT_00013160 + 0x12f32;
      }
      __android_log_print(6,iVar9,iVar3);
      close(*(int *)(&stack0xfffffff0 + iVar1));
    }
  }
  if (*(int *)(&stack0xffffffec + DAT_00013148 + iVar1) == **(int **)(iVar8 + DAT_00013140)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}



/* Function: is_block @ 000131ec */

void is_block(int param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  int iVar1;
  void *__s;
  int iVar2;
  ssize_t sVar3;
  size_t __n;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_1a4;
  undefined4 local_198;
  int local_194;
  socklen_t local_190;
  undefined4 local_18c;
  int local_188;
  int local_184;
  int local_180 [61];
  sockaddr asStack_8c [7];
  int local_1c;
  
  iVar7 = DAT_000133e8 + 0x131f8;
  local_1c = **(int **)(iVar7 + DAT_000133ec);
  local_198 = param_2;
  local_194 = param_1;
  memset(&local_18c,0,0x100);
  iVar1 = makeAddr(DAT_000133f0 + 0x13220,asStack_8c,&local_190);
  uVar4 = 0;
  if (iVar1 < 0) goto LAB_000133d0;
  iVar1 = socket(1,1,1);
  if (iVar1 < 0) {
    __android_log_print(6,DAT_000133f4 + 0x13246,DAT_000133f8 + 0x13248);
    goto LAB_000133d0;
  }
  __s = malloc(param_4 + 0x10);
  iVar5 = DAT_000133fc;
  memset(__s,0,param_4 + 0x10);
  iVar5 = iVar5 + 0x13268;
  __android_log_print(6,iVar5,DAT_00013400 + 0x1326c,local_194);
  iVar2 = connect(iVar1,asStack_8c,local_190);
  if (iVar2 < 0) {
    iVar2 = DAT_00013404 + 0x1328a;
LAB_00013342:
    __android_log_print(6,iVar5,iVar2);
    uVar4 = 0;
  }
  else {
    memcpy(__s,&local_198,4);
    if (local_194 == 10) {
      local_194 = 1;
    }
    else if (((((local_194 == 0x16) || (local_194 == 0x14)) || (local_194 == 0x19)) ||
             ((local_194 == 0x18 || (local_194 == 0x25)))) ||
            ((local_194 == 0x1a || (local_194 == 0x15)))) {
      local_194 = 5;
    }
    else if (((local_194 == 0x24) || (local_194 == 0x26)) || (local_194 == 0x2a)) {
      local_194 = 0x30;
    }
    else if ((local_194 == 0x21) || (local_194 == 0x1b)) {
      local_194 = 0xc;
    }
    else if ((local_194 == 0x2f) || (local_194 == 0x1c)) {
      local_194 = 7;
    }
    else if (local_194 == 0x1e) {
      local_194 = 3;
    }
    else if (local_194 == 0x1f) {
      local_194 = 4;
    }
    else if (local_194 == 0x20) {
      local_194 = 9;
    }
    else if (local_194 == 0x2b) {
      local_194 = 8;
    }
    memcpy((void *)((int)__s + 4),&local_194,4);
    if ((0 < (int)param_4) || (__n = 8, param_3 != (void *)0x0)) {
      memcpy((void *)((int)__s + 8),param_3,param_4);
      __n = param_4 + 8;
    }
    sVar3 = write(iVar1,__s,__n);
    if (sVar3 < 0) {
      iVar5 = DAT_00013408 + 0x13340;
      iVar2 = DAT_0001340c + 0x13342;
      goto LAB_00013342;
    }
    sVar3 = read(iVar1,&local_18c,0x100);
    if (sVar3 < 0) {
      iVar5 = DAT_00013410 + 0x13364;
      iVar2 = DAT_00013414 + 0x13366;
      goto LAB_00013342;
    }
    iVar5 = DAT_00013418 + 0x13370;
    __android_log_print(6,iVar5,DAT_0001341c + 0x13374,local_18c);
    uVar4 = local_18c;
    if ((4 < sVar3) && (__android_log_print(6,iVar5,DAT_00013420 + 0x1338a), local_188 != 0)) {
      memset(*(void **)(iVar7 + DAT_00013424),0,DAT_00013428);
      piVar6 = &local_184;
      for (local_1a4 = 0; local_1a4 < local_184; local_1a4 = local_1a4 + 1) {
        piVar6 = piVar6 + 1;
        insert_data_notification(*piVar6);
      }
    }
  }
  close(iVar1);
  free(__s);
LAB_000133d0:
  if (local_1c == **(int **)(iVar7 + DAT_000133ec)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}



/* Function: __aeabi_unwind_cpp_pr0 @ 00015000 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ipcData @ 00015004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ipcDataSize @ 00015008 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcDataSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __android_log_print @ 0001500c */

/* WARNING: Control flow encountered bad instruction data */

void __android_log_print(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: Parcel @ 00015010 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::Parcel::Parcel(Parcel *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setData @ 00015014 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setData(uchar *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readInt32 @ 00015018 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dataPosition @ 0001501c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::dataPosition(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readString16 @ 00015020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~String16 @ 00015024 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::String16::~String16(String16 *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~Parcel @ 00015028 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::Parcel::~Parcel(Parcel *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setDataPosition @ 0001502c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setDataPosition(uint param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readObject @ 00015030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readObject(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 00015034 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 00015038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strstr @ 0001503c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 00015040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 00015048 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: self @ 0001504c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::self(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sendReply @ 00015050 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::sendReply(Parcel *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_key_create @ 00015054 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcpy @ 00015058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_create @ 0001505c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_getspecific @ 00015060 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_setspecific @ 00015064 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_unwind_cpp_pr1 @ 00015068 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ioctl @ 0001506c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 00015070 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: lseek @ 00015074 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 00015078 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __errno @ 0001507c */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: read @ 00015080 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sysconf @ 00015084 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: open @ 00015088 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: close @ 0001508c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: mprotect @ 00015090 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: snprintf @ 00015094 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fopen @ 00015098 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtok @ 0001509c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtoul @ 000150a0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fgets @ 000150a4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fclose @ 000150a8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fseek @ 000150ac */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sscanf @ 000150b0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 000150b4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: socket @ 000150b8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: bind @ 000150bc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: listen @ 000150c0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: accept @ 000150c4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: connect @ 000150c8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: write @ 000150cc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_finalize @ 000150d0 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



