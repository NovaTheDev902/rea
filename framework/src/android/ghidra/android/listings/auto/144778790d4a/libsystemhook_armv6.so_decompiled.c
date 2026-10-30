/* Function: ipcData @ 00011f34 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcData(void)

{
  (*(code *)PTR_ipcData_00015194)();
  return;
}



/* Function: ipcDataSize @ 00011f40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcDataSize(void)

{
  (*(code *)PTR_ipcDataSize_00015198)();
  return;
}



/* Function: __android_log_print @ 00011f4c */

void __android_log_print(void)

{
  (*(code *)PTR___android_log_print_0001519c)();
  return;
}



/* Function: Parcel @ 00011f58 */

void __thiscall android::Parcel::Parcel(Parcel *this)

{
  (*(code *)PTR_Parcel_000151a0)(this);
  return;
}



/* Function: setData @ 00011f64 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setData(uchar *param_1,uint param_2)

{
  (*(code *)PTR_setData_000151a4)(param_1);
  return;
}



/* Function: readInt32 @ 00011f70 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt32(void)

{
  (*(code *)PTR_readInt32_000151a8)();
  return;
}



/* Function: readString16 @ 00011f7c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString16(void)

{
  (*(code *)PTR_readString16_000151ac)();
  return;
}



/* Function: ~String16 @ 00011f88 */

void __thiscall android::String16::~String16(String16 *this)

{
  (*(code *)PTR__String16_000151b0)(this);
  return;
}



/* Function: dataPosition @ 00011f94 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::dataPosition(void)

{
  (*(code *)PTR_dataPosition_000151b4)();
  return;
}



/* Function: ~Parcel @ 00011fa0 */

void __thiscall android::Parcel::~Parcel(Parcel *this)

{
  (*(code *)PTR__Parcel_000151b8)(this);
  return;
}



/* Function: readInt64 @ 00011fac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt64(void)

{
  (*(code *)PTR_readInt64_000151bc)();
  return;
}



/* Function: setDataPosition @ 00011fb8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setDataPosition(uint param_1)

{
  (*(code *)PTR_setDataPosition_000151c0)(param_1);
  return;
}



/* Function: readString8 @ 00011fc4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString8(void)

{
  (*(code *)PTR_readString8_000151c4)();
  return;
}



/* Function: ~String8 @ 00011fd0 */

void __thiscall android::String8::~String8(String8 *this)

{
  (*(code *)PTR__String8_000151c8)(this);
  return;
}



/* Function: memset @ 00011fdc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_000151cc)(__s);
  return pvVar1;
}



/* Function: strcmp @ 00011fe8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_000151d0)(__s1);
  return iVar1;
}



/* Function: readObject @ 00011ff4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readObject(bool param_1)

{
  (*(code *)PTR_readObject_000151d4)(param_1);
  return;
}



/* Function: memcpy @ 00012000 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_000151d8)(__dest);
  return pvVar1;
}



/* Function: __stack_chk_fail @ 0001200c */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_000151dc)();
  return;
}



/* Function: writeNoException @ 00012018 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::writeNoException(void)

{
  (*(code *)PTR_writeNoException_000151e0)();
  return;
}



/* Function: writeInt32 @ 00012024 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::writeInt32(int param_1)

{
  (*(code *)PTR_writeInt32_000151e4)(param_1);
  return;
}



/* Function: self @ 00012030 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::self(void)

{
  (*(code *)PTR_self_000151e8)();
  return;
}



/* Function: sendReply @ 0001203c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::sendReply(Parcel *param_1,uint param_2)

{
  (*(code *)PTR_sendReply_000151ec)(param_1);
  return;
}



/* Function: pthread_key_create @ 00012048 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_key_create_000151f0)(__key);
  return iVar1;
}



/* Function: strcpy @ 00012054 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_000151f4)(__dest);
  return pcVar1;
}



/* Function: pthread_create @ 00012060 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_000151f8)(__newthread);
  return iVar1;
}



/* Function: pthread_getspecific @ 0001206c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_pthread_getspecific_000151fc)(__key);
  return pvVar1;
}



/* Function: pthread_setspecific @ 00012078 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_setspecific_00015200)(__key);
  return iVar1;
}



/* Function: ioctl @ 00012084 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ioctl_00015204)(__fd);
  return iVar1;
}



/* Function: malloc @ 00012090 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_00015208)(__size);
  return pvVar1;
}



/* Function: lseek @ 0001209c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
  __off_t _Var1;
  
  _Var1 = (*(code *)PTR_lseek_0001520c)(__fd);
  return _Var1;
}



/* Function: free @ 000120a8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_00015210)(__ptr);
  return;
}



/* Function: __errno @ 000120b4 */

void __errno(void)

{
  (*(code *)PTR___errno_00015214)();
  return;
}



/* Function: read @ 000120c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_read_00015218)(__fd);
  return sVar1;
}



/* Function: sysconf @ 000120cc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
  long lVar1;
  
  lVar1 = (*(code *)PTR_sysconf_0001521c)(__name);
  return lVar1;
}



/* Function: open @ 000120d8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_open_00015220)(__file);
  return iVar1;
}



/* Function: close @ 000120e4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_close_00015224)(__fd);
  return iVar1;
}



/* Function: mprotect @ 000120f0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_mprotect_00015228)(__addr);
  return iVar1;
}



/* Function: snprintf @ 000120fc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_0001522c)(__s);
  return iVar1;
}



/* Function: fopen @ 00012108 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_00015230)(__filename);
  return pFVar1;
}



/* Function: strstr @ 00012114 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strstr_00015234)(__haystack);
  return pcVar1;
}



/* Function: strtok @ 00012120 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strtok_00015238)(__s);
  return pcVar1;
}



/* Function: strtoul @ 0001212c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
  uVar1 = (*(code *)PTR_strtoul_0001523c)(__nptr);
  return uVar1;
}



/* Function: fgets @ 00012138 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_00015240)(__s);
  return pcVar1;
}



/* Function: fclose @ 00012144 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_00015244)(__stream);
  return iVar1;
}



/* Function: fseek @ 00012150 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fseek_00015248)(__stream);
  return iVar1;
}



/* Function: sscanf @ 0001215c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sscanf_0001524c)(__s);
  return iVar1;
}



/* Function: strlen @ 00012168 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00015250)(__s);
  return sVar1;
}



/* Function: socket @ 00012174 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_socket_00015254)(__domain);
  return iVar1;
}



/* Function: bind @ 00012180 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_bind_00015258)(__fd);
  return iVar1;
}



/* Function: listen @ 0001218c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_listen_0001525c)(__fd);
  return iVar1;
}



/* Function: accept @ 00012198 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_accept_00015260)(__fd);
  return iVar1;
}



/* Function: connect @ 000121a4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_connect_00015264)(__fd);
  return iVar1;
}



/* Function: write @ 000121b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = (*(code *)PTR_write_00015268)(__fd);
  return sVar1;
}



/* Function: __cxa_finalize @ 000121bc */

void __cxa_finalize(void)

{
  (*(code *)PTR___cxa_finalize_0001526c)();
  return;
}



/* Function: print_parcel @ 000121d8 */

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
  iVar4 = DAT_00012218 + 0x121f6;
  iVar5 = DAT_0001221c + 0x121f8;
  for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
    __android_log_print(6,iVar4,iVar5,uVar3,*(undefined1 *)(iVar1 + uVar3),
                        *(undefined1 *)(iVar1 + uVar3));
  }
  return;
}



/* Function: set_writenoexception_reply @ 00012220 */

/* android::set_writenoexception_reply(unsigned char*, unsigned int&) */

undefined4 android::set_writenoexception_reply(uchar *param_1,uint *param_2)

{
  __android_log_print(6,DAT_00012244 + 0x12230,DAT_00012240 + 0x1222e);
  *param_2 = 4;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  return 0;
}



/* Function: set_location_reply @ 00012248 */

/* android::set_location_reply(unsigned char*, unsigned int&) */

undefined4 android::set_location_reply(uchar *param_1,uint *param_2)

{
  __android_log_print(6,DAT_00012270 + 0x12258,DAT_0001226c + 0x12256);
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



/* Function: set_notification_reply @ 00012274 */

/* android::set_notification_reply(unsigned char*, unsigned int&) */

undefined4 android::set_notification_reply(uchar *param_1,uint *param_2)

{
  __android_log_print(6,DAT_000122a0 + 0x12284,DAT_0001229c + 0x12282);
  *param_2 = 0xc;
  param_1[0] = '\0';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\x01';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  return 0;
}



/* Function: set_getlastknownlocation_reply @ 000122a4 */

/* android::set_getlastknownlocation_reply(unsigned int*) */

undefined4 android::set_getlastknownlocation_reply(uint *param_1)

{
  __android_log_print(6,DAT_000122c0 + 0x122b0,DAT_000122c4 + 0x122b2);
  param_1[1] = 0;
  return 0;
}



/* Function: set_getallproviders_location_reply @ 000122c8 */

/* android::set_getallproviders_location_reply(unsigned int*) */

undefined4 android::set_getallproviders_location_reply(uint *param_1)

{
  __android_log_print(6,DAT_000122e4 + 0x122d4,DAT_000122e8 + 0x122d6);
  *param_1 = 1;
  return 0;
}



/* Function: set_location_providerdisable_reply @ 000122ec */

/* android::set_location_providerdisable_reply(unsigned int*) */

undefined4 android::set_location_providerdisable_reply(uint *param_1)

{
  __android_log_print(6,DAT_00012308 + 0x122f8,DAT_0001230c + 0x122fa);
  *param_1 = 0;
  param_1[1] = 0;
  return 0;
}



/* Function: set_device_permission_deny_reply @ 00012310 */

/* android::set_device_permission_deny_reply(unsigned int*) */

undefined4 android::set_device_permission_deny_reply(uint *param_1)

{
  __android_log_print(6,DAT_0001232c + 0x1231c,DAT_00012330 + 0x1231e);
  param_1[1] = 0;
  return 0;
}



/* Function: set_permission_deny_reply @ 00012334 */

/* android::set_permission_deny_reply(unsigned int*) */

undefined4 android::set_permission_deny_reply(uint *param_1)

{
  __android_log_print(6,DAT_00012350 + 0x12340,DAT_00012354 + 0x12342);
  *param_1 = 1;
  param_1[1] = 1;
  return 0;
}



/* Function: set_getactivenetworkinfo_reply @ 00012358 */

/* android::set_getactivenetworkinfo_reply(unsigned char*, unsigned int) */

undefined4 android::set_getactivenetworkinfo_reply(uchar *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  Parcel aPStack_50 [48];
  int local_20;
  int local_1c;
  String16 aSStack_18 [4];
  String16 aSStack_14 [4];
  
  android::Parcel::Parcel(aPStack_50);
  android::Parcel::setData((uchar *)aPStack_50,(uint)param_1);
  android::Parcel::readInt32();
  android::Parcel::readInt32();
  android::Parcel::readInt32();
  android::Parcel::readString16();
  android::String16::~String16(aSStack_14);
  android::Parcel::readString16();
  android::String16::~String16(aSStack_18);
  iVar1 = android::Parcel::dataPosition();
  android::Parcel::readString16();
  uVar2 = *(uint *)(local_1c + -0xc);
  for (iVar3 = 0; iVar3 < (int)((uVar2 >> 1) - 1); iVar3 = iVar3 + 1) {
    param_1[iVar3 + iVar1 + 4] = param_1[iVar3 + iVar1 + 4] + '\x01';
  }
  iVar1 = android::Parcel::dataPosition();
  android::Parcel::readString16();
  uVar2 = *(uint *)(local_20 + -0xc);
  for (iVar3 = 0; iVar3 < (int)((uVar2 >> 1) - 1); iVar3 = iVar3 + 1) {
    param_1[iVar3 + iVar1 + 4] = param_1[iVar3 + iVar1 + 4] + '\x01';
  }
  android::String16::~String16((String16 *)&local_20);
  android::String16::~String16((String16 *)&local_1c);
  android::Parcel::~Parcel(aPStack_50);
  return 1;
}



/* Function: set_getwifiscan_reply @ 00012414 */

/* android::set_getwifiscan_reply(unsigned char*, unsigned int) */

undefined4 android::set_getwifiscan_reply(uchar *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  Parcel aPStack_50 [48];
  String16 aSStack_20 [4];
  int local_1c [2];
  
  __android_log_print(6,DAT_000124d4 + 0x12426,DAT_000124d0 + 0x12428);
  android::Parcel::Parcel(aPStack_50);
  android::Parcel::setData((uchar *)aPStack_50,(uint)param_1);
  android::Parcel::readInt32();
  iVar1 = android::Parcel::readInt32();
  for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
    android::Parcel::readInt32();
    android::Parcel::readInt32();
    android::Parcel::readInt32();
    android::Parcel::readInt32();
    android::Parcel::readString16();
    uVar2 = *(uint *)(local_1c[0] + -0xc);
    for (iVar3 = 0; iVar3 < (int)(((uVar2 >> 1) - 1) * 2); iVar3 = iVar3 + 1) {
      if (param_1[iVar3 + 4] != '\0') {
        param_1[iVar3 + 4] = '\0';
      }
    }
    android::Parcel::readString16();
    android::Parcel::readInt32();
    android::Parcel::readInt32();
    android::Parcel::readInt64();
    android::String16::~String16(aSStack_20);
    android::String16::~String16((String16 *)local_1c);
  }
  android::Parcel::~Parcel(aPStack_50);
  return 0;
}



/* Function: set_getconnectioninfo_reply @ 000124d8 */

/* android::set_getconnectioninfo_reply(unsigned char*, unsigned int) */

undefined4 android::set_getconnectioninfo_reply(uchar *param_1,uint param_2)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  Parcel aPStack_58 [48];
  int local_28;
  int local_24;
  int local_20;
  int local_1c [2];
  
  android::Parcel::Parcel(aPStack_58);
  android::Parcel::setData((uchar *)aPStack_58,(uint)param_1);
  uVar4 = 1;
  if (param_1[0x14] == '\0') goto LAB_000126a0;
  iVar5 = DAT_000126ac + 0x1250e;
  __android_log_print(6,iVar5,DAT_000126b0 + 0x12510,param_1[0x20]);
  __android_log_print(6,iVar5,DAT_000126b4 + 0x12524,param_1[0x24]);
  if (param_1[0x20] == '\x01') {
    android::Parcel::setDataPosition((uint)aPStack_58);
    iVar5 = android::Parcel::dataPosition();
    android::Parcel::readString8();
    iVar2 = *(int *)(local_1c[0] + -0xc);
    for (iVar3 = 0; iVar3 < iVar2 + -1; iVar3 = iVar3 + 1) {
      if (param_1[iVar3 + iVar5 + 4] != '\0') {
        param_1[iVar3 + iVar5 + 4] = param_1[iVar3 + iVar5 + 4] + '\x01';
      }
    }
LAB_000125de:
    android::String8::~String8((String8 *)local_1c);
  }
  else {
    if (param_1[0x24] == '\x01') {
      android::Parcel::setDataPosition((uint)aPStack_58);
      iVar5 = android::Parcel::dataPosition();
      android::Parcel::readString8();
      iVar2 = *(int *)(local_1c[0] + -0xc);
      for (iVar3 = 0; iVar3 < iVar2 + -1; iVar3 = iVar3 + 1) {
        if (param_1[iVar3 + iVar5 + 4] != '\0') {
          param_1[iVar3 + iVar5 + 4] = param_1[iVar3 + iVar5 + 4] + '\x01';
        }
      }
      iVar5 = android::Parcel::dataPosition();
      android::Parcel::readString16();
      uVar6 = *(uint *)(local_20 + -0xc);
      for (iVar2 = 0; iVar2 < (int)(((uVar6 >> 1) - 1) * 2); iVar2 = iVar2 + 1) {
        if (param_1[iVar2 + iVar5 + 4] != '\0') {
          param_1[iVar2 + iVar5 + 4] = param_1[iVar2 + iVar5 + 4] + '\x01';
        }
      }
      android::String16::~String16((String16 *)&local_20);
      goto LAB_000125de;
    }
    android::Parcel::setDataPosition((uint)aPStack_58);
    iVar5 = android::Parcel::dataPosition();
    android::Parcel::readString16();
    uVar6 = *(uint *)(local_20 + -0xc);
    for (iVar2 = 0; iVar2 < (int)(((uVar6 >> 1) - 1) * 2); iVar2 = iVar2 + 1) {
      if (param_1[iVar2 + iVar5 + 4] != '\0') {
        param_1[iVar2 + iVar5 + 4] = param_1[iVar2 + iVar5 + 4] + '\x01';
      }
    }
    android::String16::~String16((String16 *)&local_20);
  }
  iVar5 = android::Parcel::dataPosition();
  android::Parcel::readString16();
  uVar6 = *(uint *)(local_24 + -0xc);
  for (iVar2 = 0; iVar2 < (int)(((uVar6 >> 1) - 1) * 2); iVar2 = iVar2 + 1) {
    if (param_1[iVar2 + iVar5 + 4] != '\0') {
      param_1[iVar2 + iVar5 + 4] = param_1[iVar2 + iVar5 + 4] + '\x01';
    }
  }
  iVar5 = android::Parcel::dataPosition();
  android::Parcel::readString16();
  uVar6 = *(uint *)(local_28 + -0xc);
  for (iVar2 = 0; iVar2 < (int)(((uVar6 >> 1) - 1) * 2); iVar2 = iVar2 + 1) {
    uVar1 = param_1[iVar2 + iVar5 + 4];
    if ((uVar1 != '\0') && (uVar1 != ':')) {
      param_1[iVar2 + iVar5 + 4] = uVar1 + '\x01';
    }
  }
  android::String16::~String16((String16 *)&local_28);
  android::String16::~String16((String16 *)&local_24);
  uVar4 = 0;
LAB_000126a0:
  android::Parcel::~Parcel(aPStack_58);
  return uVar4;
}



/* Function: modify_reply @ 000126b8 */

undefined4 modify_reply(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 - 5U < 0x2d) {
                    /* WARNING: Could not emulate address calculation at 0x000126ca */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)((param_3 - 5U) * 4 + DAT_00012710 + 0x126cc) +
                      DAT_00012710 + 0x126cc))();
    return uVar1;
  }
  return 0;
}



/* Function: parse_requestdata @ 00012714 */

void parse_requestdata(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  Parcel *this;
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  size_t __n;
  int iVar8;
  int *piVar9;
  
  iVar2 = DAT_00012a4c;
  *(undefined4 *)(&stack0xfffffff4 + DAT_00012a4c) = param_2;
  *(undefined4 *)(&stack0xfffffffc + DAT_00012a4c) = param_4;
  iVar8 = DAT_00012a54 + 0x1272a;
  *(undefined4 *)(&stack0xfffffff8 + DAT_00012a4c) = param_3;
  uVar6 = **(undefined4 **)(iVar8 + DAT_00012a58);
  *(undefined4 *)(&stack0x00000000 + DAT_00012a4c) =
       *(undefined4 *)(&stack0x00000464 + DAT_00012a4c);
  *(undefined4 *)(&stack0xffffffec + DAT_00012a5c + DAT_00012a4c) = uVar6;
  this = (Parcel *)(&stack0x00000008 + DAT_00012a4c);
  piVar9 = *(int **)(&stack0xffffffec + DAT_00012a50 + DAT_00012a4c);
  android::Parcel::Parcel(this);
  *(undefined1 **)(&stack0xfffffff0 + iVar2) = &stack0x00000348 + iVar2;
  memset(&stack0x00000348 + iVar2,0,0x100);
  if ((*(int *)(&stack0xfffffff8 + iVar2) == 0) || (*(int *)(&stack0xfffffff4 + iVar2) == 0)) {
    uVar6 = 0;
    goto LAB_00012c90;
  }
  android::Parcel::setData((uchar *)this,*(uint *)(&stack0xfffffff4 + iVar2));
  android::Parcel::setDataPosition((uint)this);
  android::Parcel::readInt32();
  android::Parcel::readString16();
  psVar5 = *(short **)(&stack0x00000044 + iVar2);
  puVar7 = *(undefined1 **)(&stack0xfffffff0 + iVar2);
  if (psVar5 != (short *)0x0) {
    iVar3 = DAT_00012a60 + iVar2;
    for (; (*psVar5 != 0 && (puVar7 != &stack0xffffffec + iVar3)); puVar7 = puVar7 + 1) {
      *puVar7 = (char)*psVar5;
      psVar5 = psVar5 + 1;
    }
  }
  iVar3 = DAT_00012a64;
  *puVar7 = 0;
  pcVar1 = &stack0x00000348 + iVar2;
  iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + iVar3));
  if (iVar3 == 0) {
    if (param_1 != 0x35) {
      if (param_1 == 3) {
        if (DAT_00012a90 < *piVar9) {
          puVar7 = &stack0x00000248 + iVar2;
          memset(puVar7,0,0x100);
          android::Parcel::readObject((bool)((char)&stack0x00000008 + (char)iVar2));
          android::Parcel::readString16();
          psVar5 = *(short **)(&stack0x00000040 + iVar2);
          if (psVar5 != (short *)0x0) {
            for (; (*psVar5 != 0 && (puVar7 != &stack0xffffffec + DAT_00012a68 + iVar2));
                puVar7 = puVar7 + 1) {
              *puVar7 = (char)*psVar5;
              psVar5 = psVar5 + 1;
            }
          }
          *puVar7 = 0;
          pcVar1 = &stack0x00000248 + iVar2;
          iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a94));
          if (iVar3 == 0) {
            puVar7 = &stack0x00000148 + iVar2;
            memset(puVar7,0,0x100);
            memset(&stack0x00000048 + iVar2,0,0x100);
            android::Parcel::readInt32();
            android::Parcel::readString16();
            psVar5 = *(short **)(&stack0x0000003c + iVar2);
            if (psVar5 != (short *)0x0) {
              for (; (*psVar5 != 0 && (puVar7 != &stack0x000001c7 + iVar2)); puVar7 = puVar7 + 1) {
                *puVar7 = (char)*psVar5;
                psVar5 = psVar5 + 1;
              }
            }
            *puVar7 = 0;
            iVar3 = strcmp(&stack0x00000148 + iVar2,(char *)(DAT_00012a98 + 0x12974));
            if (iVar3 == 0) {
              android::Parcel::readInt32();
              android::Parcel::readString16();
              psVar5 = *(short **)(&stack0x00000038 + iVar2);
              puVar7 = &stack0x00000048 + iVar2;
              if (psVar5 != (short *)0x0) {
                for (; (*psVar5 != 0 && (puVar7 != &stack0x000000c7 + iVar2)); puVar7 = puVar7 + 1)
                {
                  *puVar7 = (char)*psVar5;
                  psVar5 = psVar5 + 1;
                }
              }
              *puVar7 = 0;
              __android_log_print(6,DAT_00012aa0 + 0x129b6,DAT_00012a9c + 0x129b4,
                                  &stack0x00000048 + iVar2);
              __n = ((*(uint *)((int)*(void **)(&stack0x00000038 + iVar2) + -0xc) >> 1) - 1) * 2;
              if (0x400 < (int)__n) {
                __n = DAT_00012aa4;
              }
              memcpy(*(void **)(&stack0xfffffffc + iVar2),*(void **)(&stack0x00000038 + iVar2),__n);
              android::String16::~String16((String16 *)(&stack0x00000038 + iVar2));
            }
            else {
              __n = ((*(uint *)((int)*(void **)(&stack0x0000003c + iVar2) + -0xc) >> 1) - 1) * 2;
              if (0x400 < (int)__n) {
                __n = DAT_00012aa4;
              }
              memcpy(*(void **)(&stack0xfffffffc + iVar2),*(void **)(&stack0x0000003c + iVar2),__n);
              __android_log_print(6,DAT_00012aa8 + 0x12a0c,DAT_00012aac + 0x12a0e,
                                  &stack0x00000148 + iVar2);
            }
            **(size_t **)(&stack0x00000000 + iVar2) = __n;
            android::String16::~String16((String16 *)(&stack0x0000003c + iVar2));
            uVar6 = 8;
          }
          else {
            uVar6 = 0x1c;
            iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012ab0));
            if (iVar3 != 0) {
              uVar6 = 0;
              iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012ab4));
              if (iVar3 == 0) {
                uVar6 = 0x2f;
              }
            }
          }
          goto LAB_00012a46;
        }
      }
      else {
        if (param_1 != 0xc) {
          uVar6 = 0;
          if (param_1 == 0x4a) {
            uVar6 = 0x12;
          }
          goto LAB_00012c8a;
        }
        if (DAT_00012cec < *piVar9) {
          puVar7 = &stack0x00000048 + iVar2;
          memset(puVar7,0,0x100);
          android::Parcel::readObject((bool)((char)&stack0x00000008 + (char)iVar2));
          android::Parcel::readString16();
          psVar5 = *(short **)(&stack0x00000038 + iVar2);
          if (psVar5 != (short *)0x0) {
            for (; (*psVar5 != 0 && (puVar7 != &stack0x000000c7 + iVar2)); puVar7 = puVar7 + 1) {
              *puVar7 = (char)*psVar5;
              psVar5 = psVar5 + 1;
            }
          }
          *puVar7 = 0;
          uVar6 = 0;
          iVar3 = strcmp(&stack0x00000048 + iVar2,(char *)**(undefined4 **)(iVar8 + DAT_00012cf0));
          if (iVar3 == 0) {
            uVar6 = 0x2e;
          }
          goto LAB_00012c46;
        }
      }
      goto LAB_00012c88;
    }
    puVar7 = &stack0x00000248 + iVar2;
    memset(puVar7,0,0x100);
    android::Parcel::readString16();
    psVar5 = *(short **)(&stack0x00000040 + iVar2);
    if (psVar5 != (short *)0x0) {
      for (; (*psVar5 != 0 && (puVar7 != &stack0xffffffec + DAT_00012a68 + iVar2));
          puVar7 = puVar7 + 1) {
        *puVar7 = (char)*psVar5;
        psVar5 = psVar5 + 1;
      }
    }
    *puVar7 = 0;
    iVar3 = android::Parcel::readInt32();
    iVar4 = android::Parcel::readInt32();
    *piVar9 = iVar4;
    if (iVar3 < 1) {
LAB_000128c2:
      uVar6 = 0;
    }
    else {
      pcVar1 = &stack0x00000248 + iVar2;
      uVar6 = 0x18;
      iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a6c));
      if (iVar3 != 0) {
        uVar6 = 0x19;
        iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a70));
        if (iVar3 != 0) {
          iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a74));
          uVar6 = 0x1a;
          if (iVar3 != 0) {
            uVar6 = 0x1f;
            iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a78));
            if (iVar3 != 0) {
              uVar6 = 0x20;
              iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a7c));
              if (iVar3 != 0) {
                iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a80));
                uVar6 = 10;
                if (iVar3 != 0) {
                  uVar6 = 0x2b;
                  iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a84));
                  if (iVar3 != 0) {
                    uVar6 = 0x2c;
                    iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a88));
                    if (iVar3 != 0) {
                      iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012a8c));
                      uVar6 = 0x2d;
                      if (iVar3 != 0) goto LAB_000128c2;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_00012a46:
    puVar7 = &stack0x00000040;
LAB_00012c48:
    android::String16::~String16((String16 *)(puVar7 + iVar2));
  }
  else {
    iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012cf4));
    if (iVar3 == 0) {
      if (DAT_00012cec < *piVar9) {
        if (param_1 == 5) {
          __android_log_print(6,DAT_00012cf8 + 0x12b4e,DAT_00012cfc + 0x12b50);
          uVar6 = 0x16;
        }
        else if (param_1 == 0x10) {
          __android_log_print(6,DAT_00012d00 + 0x12b64,DAT_00012d04 + 0x12b66);
          uVar6 = 5;
        }
        else if (param_1 == 9) {
          __android_log_print(6,DAT_00012d08 + 0x12b7a,DAT_00012d0c + 0x12b7c);
          uVar6 = 0x15;
        }
        else {
          if (param_1 != 0x11) goto LAB_00012c88;
          __android_log_print(6,DAT_00012d10 + 0x12b92,DAT_00012d14 + 0x12b94);
          uVar6 = 0x25;
        }
        goto LAB_00012c8a;
      }
    }
    else {
      iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012d18));
      if (iVar3 != 0) {
        iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012d24));
        if (iVar3 != 0) {
          iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012d30));
          if (iVar3 == 0) {
            if ((*piVar9 <= DAT_00012cec) || ((param_1 != 4 && (param_1 != 6)))) goto LAB_00012c88;
            uVar6 = 0xf;
          }
          else {
            iVar3 = strcmp(pcVar1,(char *)**(undefined4 **)(iVar8 + DAT_00012d34));
            if ((iVar3 != 0) || (uVar6 = 0x31, param_1 != 1)) goto LAB_00012c88;
          }
          goto LAB_00012c8a;
        }
        puVar7 = &stack0x00000048 + iVar2;
        memset(puVar7,0,0x100);
        android::Parcel::readString16();
        psVar5 = *(short **)(&stack0x00000038 + iVar2);
        if (psVar5 != (short *)0x0) {
          for (; (*psVar5 != 0 && (puVar7 != &stack0x000000c7 + iVar2)); puVar7 = puVar7 + 1) {
            *puVar7 = (char)*psVar5;
            psVar5 = psVar5 + 1;
          }
        }
        *puVar7 = 0;
        android::Parcel::readInt32();
        iVar4 = android::Parcel::readInt32();
        iVar3 = DAT_00012d28;
        *piVar9 = iVar4;
        uVar6 = 0;
        iVar3 = strcmp(&stack0x00000048 + iVar2,(char *)**(undefined4 **)(iVar8 + iVar3));
        if (iVar3 == 0) {
          uVar6 = 7;
        }
        iVar3 = strcmp(&stack0x00000048 + iVar2,(char *)**(undefined4 **)(iVar8 + DAT_00012d2c));
        if (iVar3 == 0) {
          uVar6 = 6;
        }
LAB_00012c46:
        puVar7 = &stack0x00000038;
        goto LAB_00012c48;
      }
      if (DAT_00012cec < *piVar9) {
        if (param_1 == 8) {
          __android_log_print(6,DAT_00012d1c + 0x12bc0,DAT_00012d20 + 0x12bc2);
          uVar6 = 0x24;
        }
        else {
          uVar6 = 0x2a;
          if (param_1 != 0xc) goto LAB_00012c88;
        }
        goto LAB_00012c8a;
      }
    }
LAB_00012c88:
    uVar6 = 0;
  }
LAB_00012c8a:
  android::String16::~String16((String16 *)(&stack0x00000044 + iVar2));
LAB_00012c90:
  android::Parcel::~Parcel((Parcel *)(&stack0x00000008 + iVar2));
  if (*(int *)(&stack0xffffffec + DAT_00012d3c + iVar2) == **(int **)(iVar8 + DAT_00012d38)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar6);
}



/* Function: hook_sendNotificationReply @ 00012d44 */

void hook_sendNotificationReply(void)

{
  Parcel *pPVar1;
  Parcel aPStack_38 [48];
  
  android::Parcel::Parcel(aPStack_38);
  android::Parcel::writeNoException();
  android::Parcel::writeInt32((int)aPStack_38);
  android::Parcel::writeInt32((int)aPStack_38);
  pPVar1 = (Parcel *)android::IPCThreadState::self();
  android::IPCThreadState::sendReply(pPVar1,(uint)aPStack_38);
  android::Parcel::~Parcel(aPStack_38);
  return;
}



/* Function: hook_sendReply @ 00012d7c */

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



/* Function: hook_entry @ 00012d9c */

undefined4 hook_entry(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  pthread_key_t *__key;
  char *__dest;
  pthread_t apStack_1c [2];
  
  uVar1 = get_module_base(0xffffffff,DAT_00012e18 + 0x12daa);
  __android_log_print(3,DAT_00012e1c + 0x12db8,DAT_00012e20 + 0x12dba,uVar1);
  __key = (pthread_key_t *)(DAT_00012e24 + 0x12dc8);
  iVar3 = DAT_00012e28 + 0x12dca;
  do {
    iVar2 = pthread_key_create(__key,(__destr_function *)0x0);
  } while (iVar2 != 0);
  uVar1 = elf_hook(DAT_00012e30 + 0x12de4,uVar1,DAT_00012e34 + 0x12de2,
                   *(undefined4 *)(iVar3 + DAT_00012e2c));
  __android_log_print(3,DAT_00012e38 + 0x12df0,DAT_00012e3c + 0x12df2,uVar1);
  __dest = *(char **)(iVar3 + DAT_00012e40);
  strcpy(__dest,param_1);
  pthread_create(apStack_1c,(pthread_attr_t *)0x0,*(__start_routine **)(iVar3 + DAT_00012e44),__dest
                );
  return 0;
}



/* Function: FUN_00012e48 @ 00012e48 */

uint * FUN_00012e48(uint *param_1)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  pthread_key_t *ppVar4;
  
  uVar3 = *param_1;
  if ((uVar3 & 0xff) < 0x11) {
    if (DAT_00012ef4 < (int)uVar3) {
      if (DAT_00012f00 < (int)uVar3) {
        if (uVar3 == DAT_00012f04) {
          return param_1 + 0xb;
        }
        if (uVar3 == DAT_00012f04 + 1) {
          ppVar4 = (pthread_key_t *)(DAT_00012f08 + 0x12ec8);
          pvVar1 = pthread_getspecific(*ppVar4);
          if (0 < (int)pvVar1) {
            modify_reply(param_1[9],param_1[7]);
            pthread_setspecific(*ppVar4,(void *)0x0);
          }
          return param_1 + 0xb;
        }
      }
      else {
        if (DAT_00012f00 + -1 <= (int)uVar3) {
          return param_1 + 3;
        }
        if (uVar3 == DAT_00012f00 - 5U) {
          return param_1 + 3;
        }
      }
    }
    else {
      if (DAT_00012ef4 + -1 <= (int)uVar3) {
        return param_1 + 3;
      }
      uVar2 = DAT_00012efc;
      if ((int)uVar3 <= DAT_00012ef8) {
        if (DAT_00012ef8 + -3 <= (int)uVar3) {
          return param_1 + 2;
        }
        if (uVar3 == DAT_00012ef8 - 5U) {
          return param_1 + 2;
        }
        uVar2 = DAT_00012ef8 - 4;
      }
      if (uVar3 == uVar2) {
        return param_1 + 2;
      }
    }
  }
  else {
    __android_log_print(3,DAT_00012eec + 0x12e60,DAT_00012ef0 + 0x12e62);
  }
  return param_1 + 1;
}



/* Function: FUN_00012f0c @ 00012f0c */

void FUN_00012f0c(uint *param_1,int *param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  bool bVar11;
  
  iVar1 = DAT_000130c0;
  iVar9 = DAT_000130b8 + 0x12f18;
  puVar10 = (uint *)(&stack0xffffffec + DAT_000130c0);
  *(undefined4 *)(&stack0xffffffec + DAT_000130c4 + DAT_000130c0) =
       **(undefined4 **)(iVar9 + DAT_000130bc);
  uVar7 = *param_1;
  puVar8 = param_1 + 1;
  if (uVar7 == DAT_000130c8) {
    puVar8 = param_1 + 2;
    iVar3 = DAT_000130cc + 0x12f38;
    iVar5 = DAT_000130d0 + 0x12f3a;
    uVar7 = param_1[1];
LAB_00012f4c:
    __android_log_print(3,iVar3,iVar5,uVar7);
  }
  else {
    if (0x11 < (uVar7 & 0xff)) {
      iVar3 = DAT_000130d4 + 0x12f4c;
      iVar5 = DAT_000130d8 + 0x12f4e;
      goto LAB_00012f4c;
    }
    if (DAT_000130dc < (int)uVar7) {
      if (uVar7 == DAT_000130e8) {
        *(undefined4 *)(&stack0x00000004 + DAT_000130c0) = 0;
        *(uint *)(&stack0x00000000 + DAT_000130c0) = param_1[6];
        uVar7 = param_1[3];
        uVar4 = param_1[9];
        uVar6 = param_1[7];
        *(undefined1 **)(&stack0xfffffff4 + DAT_000130c0) = &stack0x00000008 + DAT_000130c0;
        *(undefined1 **)(&stack0xfffffff0 + DAT_000130c0) = &stack0x00000000 + DAT_000130c0;
        *(undefined1 **)(&stack0xffffffec + DAT_000130c0) = &stack0x00000004 + DAT_000130c0;
        iVar3 = parse_requestdata(uVar7,uVar4,uVar6,*(undefined4 *)(&stack0xfffffff4 + DAT_000130c0)
                                 );
        if (((iVar3 == 0) || (uVar7 = *(uint *)(&stack0x00000000 + iVar1), uVar7 <= DAT_000130f0))
           || (**(uint **)(iVar9 + DAT_000130f4) == uVar7)) goto LAB_00013098;
        *puVar10 = uVar7;
        __android_log_print(3,DAT_000130f8 + 0x12fe0,DAT_000130fc + 0x12fe2,iVar3);
        bVar11 = iVar3 == 0xf;
        *(uint *)(&stack0xfffffff8 + iVar1) = (uint)bVar11;
        if ((iVar3 == 0x12 || bVar11) || (iVar3 == 0x2e)) {
          *(uint *)(&stack0xfffffff4 + iVar1) = param_1[9];
          *(uint *)(&stack0x00000004 + iVar1) = param_1[7];
          if (iVar3 != 0x12 && !bVar11) goto LAB_00013032;
          iVar5 = is_whitelist_notification(*(undefined4 *)(&stack0x00000000 + iVar1));
          if ((iVar5 != 0) ||
             (iVar5 = is_block(iVar3,*(undefined4 *)(&stack0x00000000 + iVar1),
                               *(undefined4 *)(&stack0xfffffff4 + iVar1),
                               *(undefined4 *)(&stack0x00000004 + iVar1)), iVar5 == 0))
          goto LAB_00013098;
          if (*(int *)(&stack0xfffffff8 + iVar1) == 0) {
LAB_00013092:
            uVar7 = 0x44;
          }
          else {
            uVar7 = 0x4c;
          }
          goto LAB_00013094;
        }
LAB_00013032:
        if ((iVar3 == 0x31) && (**(int **)(iVar9 + DAT_00013100) == 1)) {
          iVar5 = is_whitelist_powercenter(*(undefined4 *)(&stack0x00000000 + iVar1));
          uVar7 = 0x3c;
          if (iVar5 == 0) goto LAB_00013094;
        }
        else {
          iVar5 = is_whitelist(*(undefined4 *)(&stack0x00000000 + iVar1));
          if ((iVar5 == 0) &&
             (iVar5 = is_block(iVar3,*(undefined4 *)(&stack0x00000000 + iVar1),
                               *(undefined4 *)(&stack0xfffffff4 + iVar1),
                               *(undefined4 *)(&stack0x00000004 + iVar1)), iVar5 != 0)) {
            uVar7 = 0x46;
            if (iVar3 == 0x24) {
LAB_00013094:
              param_1[7] = uVar7;
            }
            else {
              if ((((iVar3 == 0x16) || (iVar3 == 0x25)) || (iVar3 == 5)) || (iVar3 == 0x15)) {
                uVar7 = 0x4e;
                goto LAB_00013094;
              }
              if (((iVar3 == 0x1c) || (iVar3 == 8)) || ((iVar3 == 0x2e || (iVar3 == 0x2f))))
              goto LAB_00013092;
            }
            *param_2 = iVar3;
          }
        }
LAB_00013098:
        puVar2 = param_1 + 0xb;
        goto LAB_0001309c;
      }
      puVar2 = param_1 + 0xb;
      if ((uVar7 == DAT_000130e8 + 1) || (puVar2 = param_1 + 4, uVar7 == DAT_000130ec))
      goto LAB_0001309c;
    }
    else {
      puVar2 = param_1 + 3;
      if (((DAT_000130dc + -3 <= (int)uVar7) || (puVar2 = param_1 + 2, uVar7 == DAT_000130e0)) ||
         (((int)DAT_000130e0 <= (int)uVar7 && (uVar7 + DAT_000130e4 < 2)))) goto LAB_0001309c;
    }
  }
  puVar2 = puVar8;
LAB_0001309c:
  if (*(int *)(&stack0xffffffec + DAT_000130c4 + iVar1) == **(int **)(iVar9 + DAT_000130bc)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(puVar2);
}



/* Function: hooked_ioctl @ 00013108 */

int hooked_ioctl(int param_1,ulong param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  pthread_key_t *ppVar3;
  uint uVar4;
  bool bVar5;
  void *local_1c [2];
  
  bVar5 = param_2 + DAT_00013188 == 0;
  if ((param_3 != (int *)0x0 && bVar5) && (uVar1 = param_3[2], uVar1 != 0)) {
    uVar4 = uVar1 + *param_3;
    while (uVar1 < uVar4) {
      uVar1 = FUN_00012e48();
    }
  }
  iVar2 = ioctl(param_1,param_2,param_3);
  if (((-1 < iVar2) && (param_3 != (int *)0x0 && bVar5)) && (uVar1 = param_3[5], uVar1 != 0)) {
    uVar4 = uVar1 + param_3[4];
    ppVar3 = (pthread_key_t *)(DAT_0001318c + 0x13164);
    while (uVar1 < uVar4) {
      local_1c[0] = (void *)0x0;
      uVar1 = FUN_00012f0c(uVar1,local_1c);
      if (0 < (int)local_1c[0]) {
        pthread_setspecific(*ppVar3,local_1c[0]);
      }
    }
  }
  return iVar2;
}



/* Function: read_relocation_table @ 00013190 */

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



/* Function: read_symbol_table @ 000131e4 */

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



/* Function: read_string_table @ 00013238 */

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



/* Function: read_section_table @ 0001328c */

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



/* Function: read_header @ 000132e8 */

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



/* Function: section_by_name @ 00013334 */

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
  
  iVar6 = DAT_00013444 + 0x13344;
  __android_log_print(3,iVar6,DAT_00013448 + 0x13348,param_2);
  local_1c[0] = (void *)0x0;
  local_20 = (void *)0x0;
  local_24 = (void *)0x0;
  *param_3 = 0;
  iVar2 = read_header(param_1,local_1c);
  if (((iVar2 == 0) && (iVar2 = read_section_table(param_1,local_1c[0],&local_20), iVar2 == 0)) &&
     (iVar3 = read_string_table(param_1,(void *)((int)local_20 +
                                                (uint)*(ushort *)((int)local_1c[0] + 0x32) * 0x28),
                                &local_24), iVar1 = DAT_00013454, iVar2 = DAT_00013450, iVar3 == 0))
  {
    __android_log_print(3,iVar6,DAT_0001344c + 0x133a0,*(undefined2 *)((int)local_1c[0] + 0x30));
    iVar6 = 0;
    for (uVar7 = 0; uVar7 < *(ushort *)((int)local_1c[0] + 0x30); uVar7 = uVar7 + 1) {
      __android_log_print(3,iVar2 + 0x133ac,iVar1 + 0x133ae,uVar7,
                          (int)local_24 + *(int *)((int)local_20 + iVar6));
      iVar3 = strcmp(param_2,(char *)((int)local_24 + *(int *)((int)local_20 + iVar6)));
      if (iVar3 == 0) {
        __dest = malloc(0x28);
        *param_3 = __dest;
        if (__dest == (void *)0x0) {
          free(local_1c[0]);
          free(local_20);
          free(local_24);
          goto LAB_000133fa;
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
LAB_000133fa:
    puVar4 = (undefined4 *)__errno();
    uVar5 = *puVar4;
  }
  return uVar5;
}



/* Function: section_by_type @ 00013458 */

undefined4 section_by_type(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  void *local_18;
  void *local_14;
  
  __android_log_print(3,DAT_000134f4 + 0x1346a,DAT_000134f8 + 0x1346e,param_2);
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
          goto LAB_000134c8;
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
LAB_000134c8:
    puVar3 = (undefined4 *)__errno();
    uVar4 = *puVar3;
  }
  return uVar4;
}



/* Function: section_by_index @ 000134fc */

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



/* Function: symbol_by_name @ 00013570 */

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
  
  __android_log_print(3,DAT_0001363c + 0x13586,DAT_00013638 + 0x13588,param_3);
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
          goto LAB_00013600;
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
LAB_00013600:
    puVar2 = (undefined4 *)__errno();
    uVar3 = *puVar2;
  }
  return uVar3;
}



/* Function: elf_hook @ 00013640 */

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
  
  iVar9 = DAT_00013778 + 0x1364c;
  if (((param_3 != 0) && (param_2 != 0)) && (param_4 != 0)) {
    local_1c[0] = (void *)0x0;
    plVar6 = (long *)(DAT_0001377c + 0x1366c);
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
         ((iVar3 = section_by_name(iVar2,DAT_00013780 + 0x136b6,&local_20), iVar3 == 0 &&
          (iVar3 = section_by_name(iVar2,DAT_00013784 + 0x136c6,&local_24), iVar3 == 0)))) {
        __android_log_print(3,DAT_00013790 + 0x13704,DAT_00013794 + 0x13706);
        free(local_1c[0]);
        free(local_28);
        uVar4 = *(uint *)((int)local_20 + 0x14);
        iVar3 = *(int *)((int)local_20 + 0xc);
        free(local_20);
        close(iVar2);
        iVar2 = DAT_0001379c;
        piVar7 = (int *)(param_2 + iVar3);
        for (uVar5 = 0; uVar5 < uVar4 >> 3; uVar5 = uVar5 + 1) {
          if ((uint)piVar7[1] >> 8 == local_2c) {
            iVar3 = *piVar7;
            **(uint **)(iVar9 + DAT_00013798) = param_2 + iVar3;
            uVar8 = *(undefined4 *)(param_2 + *piVar7);
            iVar9 = mprotect((void *)(-*(size_t *)(iVar2 + 0x1374e) & param_2 + iVar3),
                             *(size_t *)(iVar2 + 0x1374e),7);
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
        __android_log_print(3,DAT_00013788 + 0x136d6,DAT_0001378c + 0x136d8);
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



/* Function: insert_data_notification @ 000137a0 */

undefined4 insert_data_notification(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_000137c8 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_000137cc) + 1;
  }
  *(uint *)(uVar1 * 4 + *(int *)(DAT_000137c0 + 0x137a8 + DAT_000137c4)) = param_1;
  return 0;
}



/* Function: is_whitelist_notification @ 000137d0 */

bool is_whitelist_notification(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_000137fc & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_00013800) + 1;
  }
  return *(uint *)(uVar1 * 4 + *(int *)(DAT_000137f4 + 0x137d8 + DAT_000137f8)) == param_1;
}



/* Function: insert_data @ 00013804 */

undefined4 insert_data(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_0001382c & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_00013830) + 1;
  }
  *(uint *)(uVar1 * 4 + *(int *)(DAT_00013824 + 0x1380c + DAT_00013828)) = param_1;
  return 0;
}



/* Function: get_module_base @ 00013834 */

void get_module_base(int param_1,char *param_2)

{
  int iVar1;
  FILE *__stream;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  ulong uVar5;
  
  iVar1 = DAT_000138dc;
  iVar4 = DAT_000138e4 + 0x13848;
  *(undefined4 *)(&stack0xffffffec + DAT_000138e8 + DAT_000138dc) =
       **(undefined4 **)(iVar4 + DAT_000138e0);
  if (param_1 < 0) {
    pcVar3 = (char *)(DAT_000138f0 + 0x1385c);
  }
  else {
    pcVar3 = (char *)(DAT_000138f4 + 0x13862);
  }
  snprintf(&stack0xffffffec + DAT_000138ec + DAT_000138dc,0x20,pcVar3);
  uVar5 = 0;
  __stream = fopen(&stack0xffffffec + DAT_000138ec + iVar1,(char *)(DAT_000138f8 + 0x13870));
  if (__stream != (FILE *)0x0) {
    pcVar3 = &stack0xfffffff0 + iVar1;
    do {
      pcVar2 = fgets(pcVar3,0x400,__stream);
      if (pcVar2 == (char *)0x0) goto LAB_000138b8;
      pcVar2 = strstr(pcVar3,param_2);
    } while (pcVar2 == (char *)0x0);
    pcVar3 = strtok(pcVar3,(char *)(DAT_000138fc + 0x13892));
    uVar5 = strtoul(pcVar3,(char **)0x0,0x10);
    if (uVar5 == 0x8000) {
LAB_000138b8:
      uVar5 = 0;
    }
    fclose(__stream);
  }
  if (*(int *)(&stack0xffffffec + DAT_000138e8 + iVar1) == **(int **)(iVar4 + DAT_000138e0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar5);
}



/* Function: is_whitelist_powercenter @ 00013904 */

bool is_whitelist_powercenter(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = DAT_00013948 & param_1;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | DAT_00013950) + 1;
  }
  iVar2 = *(int *)(DAT_0001394c + 0x13912 + DAT_00013954);
  __android_log_print(6,DAT_00013958 + 0x13932,DAT_0001395c + 0x13936,param_1,uVar1,
                      *(undefined4 *)(uVar1 * 4 + iVar2));
  return *(uint *)(uVar1 * 4 + iVar2) == param_1;
}



/* Function: insert_data_powercenter @ 00013960 */

undefined4 insert_data_powercenter(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0001399c;
  __android_log_print(6,DAT_00013994 + 0x13970,DAT_00013998 + 0x1396e);
  uVar2 = DAT_000139a4 & param_1;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | DAT_000139a8) + 1;
  }
  *(uint *)(uVar2 * 4 + *(int *)(iVar1 + 0x1397a + DAT_000139a0)) = param_1;
  return 0;
}



/* Function: init_whitelist @ 000139ac */

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
  
  iVar4 = DAT_00013a30 + 0x139b8;
  local_1c = **(int **)(iVar4 + DAT_00013a34);
  __stream = fopen((char *)(DAT_00013a3c + 0x139c6),(char *)(DAT_00013a38 + 0x139c2));
  iVar1 = DAT_00013a48;
  if (__stream == (FILE *)0x0) {
    __android_log_print(6,DAT_00013a40 + 0x139d6,DAT_00013a44 + 0x139d8);
    uVar2 = 0;
  }
  else {
    fseek(__stream,0,0);
    while (pcVar3 = fgets(acStack_28,10,__stream), pcVar3 != (char *)0x0) {
      sscanf(acStack_28,(char *)(iVar1 + 0x139f4),&local_2c);
      insert_data(local_2c);
    }
    fclose(__stream);
    uVar2 = 1;
  }
  if (local_1c != **(int **)(iVar4 + DAT_00013a34)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



/* Function: is_whitelist @ 00013a4c */

bool is_whitelist(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_00013a88 + 0x13a58;
  iVar4 = *(int *)(iVar3 + DAT_00013a8c);
  if (*(int *)(iVar4 + 0x400) == 0) {
    uVar1 = init_whitelist();
    *(undefined4 *)(iVar4 + 0x400) = uVar1;
  }
  uVar2 = DAT_00013a90 & param_1;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | DAT_00013a94) + 1;
  }
  return *(uint *)(uVar2 * 4 + *(int *)(iVar3 + DAT_00013a8c)) == param_1;
}



/* Function: makeAddr @ 00013a98 */

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



/* Function: create_server @ 00013ac8 */

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
  
  iVar1 = DAT_00013d54;
  iVar8 = DAT_00013d5c + 0x13adc;
  iVar9 = DAT_00013d64 + 0x13ae8;
  *(undefined4 *)(&stack0xffffffec + DAT_00013d60 + DAT_00013d54) =
       **(undefined4 **)(iVar8 + DAT_00013d58);
  iVar3 = DAT_00013d68 + DAT_00013d54;
  __android_log_print(6,iVar9,DAT_00013d6c + 0x13aec,param_1);
  iVar2 = makeAddr(param_1,(sockaddr *)(&stack0xffffffec + iVar3),&stack0x00000004 + iVar1);
  if (-1 < iVar2) {
    iVar2 = socket(1,1,1);
    *(int *)(&stack0xfffffff0 + iVar1) = iVar2;
    if (iVar2 < 0) {
      __android_log_print(6,iVar9,DAT_00013d70 + 0x13b20);
    }
    else {
      iVar3 = bind(*(int *)(&stack0xfffffff0 + iVar1),(sockaddr *)(&stack0xffffffec + iVar3),
                   *(socklen_t *)(&stack0x00000004 + iVar1));
      if (iVar3 < 0) {
        iVar3 = DAT_00013d74 + 0x13b38;
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
                __android_log_print(6,DAT_00013d7c + 0x13b80,DAT_00013d80 + 0x13b82);
              }
              sVar4 = read(*(int *)(&stack0xfffffff8 + iVar1),&stack0x00000008 + iVar1,0x400);
              iVar3 = DAT_00013d88;
            } while (sVar4 < 0);
            if (sVar4 < 5) {
              if ((sVar4 == 0) && (*(int *)(DAT_00013dec + 0x13cf8) != 0)) {
                iVar3 = *(int *)(iVar8 + DAT_00013dac);
                puVar10 = *(undefined4 **)(iVar8 + DAT_00013da0);
                if (*(int *)*puVar10 == iVar3) {
                  __android_log_print(6,DAT_00013df0 + 0x13d16,DAT_00013df4 + 0x13d18);
                }
                else {
                  __android_log_print(6,DAT_00013df8 + 0x13d26,DAT_00013dfc + 0x13d28);
                  *(int *)*puVar10 = iVar3;
                }
              }
            }
            else {
              iVar2 = *(int *)(&stack0x00000008 + iVar1);
              if (sVar4 == 0xc) {
                if (iVar2 == 1) {
                  **(undefined4 **)(iVar8 + DAT_00013d84) =
                       *(undefined4 *)(&stack0x0000000c + iVar1);
                  iVar3 = iVar3 + 0x13bba;
                  __android_log_print(6,iVar3,DAT_00013d8c + 0x13bbe);
                  iVar2 = DAT_00013d94;
                  uVar6 = *(undefined4 *)(&stack0x00000010 + iVar1);
                  **(undefined4 **)(iVar8 + DAT_00013d90) = uVar6;
                  iVar2 = iVar2 + 0x13bd0;
                }
                else {
                  if (iVar2 != 0) {
                    if (iVar2 == 2) {
                      __android_log_print(6,DAT_00013dc4 + 0x13c54,DAT_00013dc8 + 0x13c56);
                      uVar5 = *(uint *)(&stack0x00000010 + iVar1);
                      if (*(int *)(&stack0x0000000c + iVar1) == 1) {
                        uVar7 = DAT_00013dd0 & uVar5;
                        if ((int)uVar7 < 0) {
                          uVar7 = (uVar7 - 1 | DAT_00013dd4) + 1;
                        }
                        *(uint *)(uVar7 * 4 + *(int *)(iVar8 + DAT_00013dcc)) = uVar5;
                      }
                      else {
                        uVar5 = uVar5 & DAT_00013dd0;
                        if ((int)uVar5 < 0) {
                          uVar5 = (uVar5 - 1 | DAT_00013dd4) + 1;
                        }
                        *(undefined4 *)(uVar5 * 4 + *(int *)(iVar8 + DAT_00013dcc)) = 0;
                      }
                      goto LAB_00013d2e;
                    }
                    goto LAB_00013c94;
                  }
                  iVar11 = *(int *)(&stack0x0000000c + iVar1);
                  iVar3 = DAT_00013d98 + 0x13bde;
                  __android_log_print(6,iVar3,DAT_00013d9c + 0x13be2,iVar11);
                  iVar9 = DAT_00013db8;
                  iVar2 = DAT_00013da8;
                  *(int *)(&stack0xfffffff4 + iVar1) = DAT_00013da0;
                  if (iVar11 == 0) {
                    *(undefined4 *)(DAT_00013db4 + 0x13c20) = 0;
                    __android_log_print(6,iVar3,iVar9 + 0x13c24);
                    puVar10 = *(undefined4 **)(iVar8 + *(int *)(&stack0xfffffff4 + iVar1));
                    *(undefined4 *)*puVar10 = *(undefined4 *)(iVar8 + DAT_00013dbc);
                    iVar2 = DAT_00013dc0 + 0x13c3a;
                  }
                  else {
                    *(undefined4 *)(DAT_00013da4 + 0x13bfa) = 1;
                    __android_log_print(6,iVar3,iVar2 + 0x13bfe);
                    puVar10 = *(undefined4 **)(iVar8 + *(int *)(&stack0xfffffff4 + iVar1));
                    iVar2 = DAT_00013db0 + 0x13c14;
                    *(undefined4 *)*puVar10 = *(undefined4 *)(iVar8 + DAT_00013dac);
                  }
                  uVar6 = *(undefined4 *)*puVar10;
                }
                __android_log_print(6,iVar3,iVar2,uVar6);
              }
              else {
LAB_00013c94:
                if (iVar2 == 10) {
                  __android_log_print(6,DAT_00013dd8 + 0x13ca2,DAT_00013ddc + 0x13ca4);
                  iVar3 = **(int **)(&stack0x00000000 + iVar1);
                  **(int **)(iVar8 + DAT_00013de0) = iVar3;
                  if (iVar3 == 0) {
                    memset(*(void **)(iVar8 + DAT_00013de4),0,DAT_00013de8);
                  }
                  else if (iVar3 == 1) {
                    memset(*(void **)(iVar8 + DAT_00013de4),0,DAT_00013de8);
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
LAB_00013d2e:
            close(*(int *)(&stack0xfffffff8 + iVar1));
          } while( true );
        }
        iVar3 = DAT_00013d78 + 0x13b4a;
      }
      __android_log_print(6,iVar9,iVar3);
      close(*(int *)(&stack0xfffffff0 + iVar1));
    }
  }
  if (*(int *)(&stack0xffffffec + DAT_00013d60 + iVar1) == **(int **)(iVar8 + DAT_00013d58)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}



/* Function: is_block @ 00013e04 */

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
  
  iVar7 = DAT_00014000 + 0x13e10;
  local_1c = **(int **)(iVar7 + DAT_00014004);
  local_198 = param_2;
  local_194 = param_1;
  memset(&local_18c,0,0x100);
  iVar1 = makeAddr(DAT_00014008 + 0x13e38,asStack_8c,&local_190);
  uVar4 = 0;
  if (iVar1 < 0) goto LAB_00013fe8;
  iVar1 = socket(1,1,1);
  if (iVar1 < 0) {
    __android_log_print(6,DAT_0001400c + 0x13e5e,DAT_00014010 + 0x13e60);
    goto LAB_00013fe8;
  }
  __s = malloc(param_4 + 0x10);
  iVar5 = DAT_00014014;
  memset(__s,0,param_4 + 0x10);
  iVar5 = iVar5 + 0x13e80;
  __android_log_print(6,iVar5,DAT_00014018 + 0x13e84,local_194);
  iVar2 = connect(iVar1,asStack_8c,local_190);
  if (iVar2 < 0) {
    iVar2 = DAT_0001401c + 0x13ea2;
LAB_00013f5a:
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
      iVar5 = DAT_00014020 + 0x13f58;
      iVar2 = DAT_00014024 + 0x13f5a;
      goto LAB_00013f5a;
    }
    sVar3 = read(iVar1,&local_18c,0x100);
    if (sVar3 < 0) {
      iVar5 = DAT_00014028 + 0x13f7c;
      iVar2 = DAT_0001402c + 0x13f7e;
      goto LAB_00013f5a;
    }
    iVar5 = DAT_00014030 + 0x13f88;
    __android_log_print(6,iVar5,DAT_00014034 + 0x13f8c,local_18c);
    uVar4 = local_18c;
    if ((4 < sVar3) && (__android_log_print(6,iVar5,DAT_00014038 + 0x13fa2), local_188 != 0)) {
      memset(*(void **)(iVar7 + DAT_0001403c),0,DAT_00014040);
      piVar6 = &local_184;
      for (local_1a4 = 0; local_1a4 < local_184; local_1a4 = local_1a4 + 1) {
        piVar6 = piVar6 + 1;
        insert_data_notification(*piVar6);
      }
    }
  }
  close(iVar1);
  free(__s);
LAB_00013fe8:
  if (local_1c == **(int **)(iVar7 + DAT_00014004)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}



/* Function: ipcData @ 00016000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ipcDataSize @ 00016004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::ipcDataSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __android_log_print @ 00016008 */

/* WARNING: Control flow encountered bad instruction data */

void __android_log_print(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __aeabi_unwind_cpp_pr0 @ 0001600c */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: Parcel @ 00016010 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::Parcel::Parcel(Parcel *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setData @ 00016014 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setData(uchar *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readInt32 @ 00016018 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readString16 @ 0001601c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~String16 @ 00016020 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::String16::~String16(String16 *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dataPosition @ 00016024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::dataPosition(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~Parcel @ 00016028 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::Parcel::~Parcel(Parcel *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readInt64 @ 0001602c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readInt64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setDataPosition @ 00016030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::setDataPosition(uint param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readString8 @ 00016034 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readString8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~String8 @ 00016038 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::String8::~String8(String8 *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 0001603c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 00016040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: readObject @ 00016044 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::readObject(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 00016048 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 00016050 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

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



/* Function: writeNoException @ 00016058 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::writeNoException(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: writeInt32 @ 0001605c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::Parcel::writeInt32(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: self @ 00016060 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::self(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sendReply @ 00016064 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::IPCThreadState::sendReply(Parcel *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_key_create @ 00016068 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcpy @ 0001606c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_create @ 00016070 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_getspecific @ 00016074 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * pthread_getspecific(pthread_key_t __key)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_setspecific @ 00016078 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ioctl @ 0001607c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 00016080 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: lseek @ 00016084 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off_t lseek(int __fd,__off_t __offset,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 00016088 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __errno @ 0001608c */

/* WARNING: Control flow encountered bad instruction data */

void __errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: read @ 00016090 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sysconf @ 00016094 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long sysconf(int __name)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: open @ 00016098 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int open(char *__file,int __oflag,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: close @ 0001609c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int close(int __fd)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: mprotect @ 000160a0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mprotect(void *__addr,size_t __len,int __prot)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: snprintf @ 000160a4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fopen @ 000160a8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strstr @ 000160ac */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtok @ 000160b0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strtoul @ 000160b4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fgets @ 000160b8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fclose @ 000160bc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fseek @ 000160c0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fseek(FILE *__stream,long __off,int __whence)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sscanf @ 000160c4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strlen @ 000160c8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: socket @ 000160cc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int socket(int __domain,int __type,int __protocol)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: bind @ 000160d0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bind(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: listen @ 000160d4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int listen(int __fd,int __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: accept @ 000160d8 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int accept(int __fd,sockaddr *__addr,socklen_t *__addr_len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: connect @ 000160dc */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int connect(int __fd,sockaddr *__addr,socklen_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: write @ 000160e0 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t write(int __fd,void *__buf,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_finalize @ 000160e4 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



