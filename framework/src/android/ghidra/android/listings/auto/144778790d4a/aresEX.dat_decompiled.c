/* Function: defaultServiceManager @ 00010b24 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::defaultServiceManager(void)

{
  (*(code *)PTR_defaultServiceManager_0001267c)();
  return;
}



/* Function: snprintf @ 00010b3c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_00012684)(__s);
  return iVar1;
}



/* Function: getpid @ 00010b48 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
  __pid_t _Var1;
  
  _Var1 = (*(code *)PTR_getpid_00012688)();
  return _Var1;
}



/* Function: ~String16 @ 00010b54 */

void __thiscall android::String16::~String16(String16 *this)

{
  (*(code *)PTR__String16_0001268c)(this);
  return;
}



/* Function: fclose @ 00010b60 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_00012690)(__stream);
  return iVar1;
}



/* Function: fopen @ 00010b6c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_00012694)(__filename);
  return pFVar1;
}



/* Function: pthread_create @ 00010b78 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_pthread_create_00012698)(__newthread);
  return iVar1;
}



/* Function: decStrong @ 00010b84 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::RefBase::decStrong(void *param_1)

{
  (*(code *)PTR_decStrong_0001269c)(param_1);
  return;
}



/* Function: String16 @ 00010b90 */

void __thiscall android::String16::String16(String16 *this,char *param_1)

{
  (*(code *)PTR_String16_000126a0)(this);
  return;
}



/* Function: fgets @ 00010b9c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_000126a4)(__s);
  return pcVar1;
}



/* Function: strcmp @ 00010ba8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_000126a8)(__s1);
  return iVar1;
}



/* Function: FindClass @ 00010bb4 */

/* _JNIEnv::FindClass(char const*) */

undefined4 processEntry _JNIEnv::FindClass(char *param_1)

{
  undefined4 uVar1;
  undefined4 in_r1;
  
  uVar1 = (**(code **)(*(int *)param_1 + 0x18))(param_1,in_r1);
  return uVar1;
}



/* Function: NewGlobalRef @ 00010bd4 */

/* _JNIEnv::NewGlobalRef(_jobject*) */

undefined4 __thiscall _JNIEnv::NewGlobalRef(_JNIEnv *this,_jobject *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x54))(this,param_1);
  return uVar1;
}



/* Function: NewObject @ 00010bf4 */

/* _JNIEnv::NewObject(_jclass*, _jmethodID*, ...) */

undefined4 _JNIEnv::NewObject(_jclass *param_1,_jmethodID *param_2,...)

{
  undefined4 uVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  uVar1 = (**(code **)(*(int *)param_1 + 0x74))(param_1,param_2,in_r2,&uStack_4);
  return uVar1;
}



/* Function: GetMethodID @ 00010c24 */

/* _JNIEnv::GetMethodID(_jclass*, char const*, char const*) */

undefined4 __thiscall
_JNIEnv::GetMethodID(_JNIEnv *this,_jclass *param_1,char *param_2,char *param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x84))(this,param_1,param_2,param_3);
  return uVar1;
}



/* Function: CallObjectMethod @ 00010c4c */

/* _JNIEnv::CallObjectMethod(_jobject*, _jmethodID*, ...) */

undefined4 _JNIEnv::CallObjectMethod(_jobject *param_1,_jmethodID *param_2,...)

{
  undefined4 uVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  uVar1 = (**(code **)(*(int *)param_1 + 0x8c))(param_1,param_2,in_r2,&uStack_4);
  return uVar1;
}



/* Function: GetStaticMethodID @ 00010c80 */

/* _JNIEnv::GetStaticMethodID(_jclass*, char const*, char const*) */

undefined4 __thiscall
_JNIEnv::GetStaticMethodID(_JNIEnv *this,_jclass *param_1,char *param_2,char *param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x1c4))(this,param_1,param_2,param_3);
  return uVar1;
}



/* Function: CallStaticObjectMethod @ 00010ca8 */

/* _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) */

undefined4 _JNIEnv::CallStaticObjectMethod(_jclass *param_1,_jmethodID *param_2,...)

{
  undefined4 uVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  uVar1 = (**(code **)(*(int *)param_1 + 0x1cc))(param_1,param_2,in_r2,&uStack_4);
  return uVar1;
}



/* Function: NewStringUTF @ 00010cdc */

/* _JNIEnv::NewStringUTF(char const*) */

undefined4 __thiscall _JNIEnv::NewStringUTF(_JNIEnv *this,char *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x29c))(this,param_1);
  return uVar1;
}



/* Function: GetStringUTFChars @ 00010d00 */

/* _JNIEnv::GetStringUTFChars(_jstring*, unsigned char*) */

undefined4 __thiscall _JNIEnv::GetStringUTFChars(_JNIEnv *this,_jstring *param_1,uchar *param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x2a4))(this,param_1,param_2);
  return uVar1;
}



/* Function: GetArrayLength @ 00010d24 */

/* _JNIEnv::GetArrayLength(_jarray*) */

undefined4 __thiscall _JNIEnv::GetArrayLength(_JNIEnv *this,_jarray *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x2ac))(this,param_1);
  return uVar1;
}



/* Function: GetObjectArrayElement @ 00010d48 */

/* _JNIEnv::GetObjectArrayElement(_jobjectArray*, int) */

undefined4 __thiscall
_JNIEnv::GetObjectArrayElement(_JNIEnv *this,_jobjectArray *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x2b4))(this,param_1,param_2);
  return uVar1;
}



/* Function: AttachCurrentThread @ 00010d6c */

/* _JavaVM::AttachCurrentThread(_JNIEnv**, void*) */

undefined4 __thiscall _JavaVM::AttachCurrentThread(_JavaVM *this,_JNIEnv **param_1,void *param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x10))(this,param_1,param_2);
  return uVar1;
}



/* Function: DetachCurrentThread @ 00010d8c */

/* _JavaVM::DetachCurrentThread() */

undefined4 __thiscall _JavaVM::DetachCurrentThread(_JavaVM *this)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*(int *)this + 0x14))(this);
  return uVar1;
}



/* Function: getJavaVM @ 00010da8 */

/* android::AndroidRuntime::getJavaVM() */

undefined4 android::AndroidRuntime::getJavaVM(void)

{
  return **(undefined4 **)(DAT_00010db8 + 0x10dae + DAT_00010dbc);
}



/* Function: changObj @ 00010dc0 */

/* DummyJavaBBinder::changObj(_jobject*) */

void __thiscall DummyJavaBBinder::changObj(DummyJavaBBinder *this,_jobject *param_1)

{
  *(_jobject **)(this + 0x10) = param_1;
  return;
}



/* Function: getProcessNameByPid @ 00010ddc */

int getProcessNameByPid(undefined4 param_1)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  
  snprintf((char *)(DAT_00010e58 + 0x10de8),0xff,(char *)(DAT_00010e5c + 0x10dee),param_1);
  __stream = fopen((char *)(DAT_00010e60 + 0x10dfe),(char *)(DAT_00010e64 + 0x10e04));
  if (__stream == (FILE *)0x0) {
    iVar2 = 0;
  }
  else {
    pcVar1 = fgets((char *)(DAT_00010e68 + 0x10e26),0xff,__stream);
    if (pcVar1 == (char *)0x0) {
      iVar2 = 0;
    }
    else {
      fclose(__stream);
      iVar2 = DAT_00010e6c + 0x10e52;
    }
  }
  return iVar2;
}



/* Function: getClassLoader @ 00010e70 */

undefined4 getClassLoader(void)

{
  _jclass *p_Var1;
  undefined4 uVar2;
  
  p_Var1 = (_jclass *)_JNIEnv::FindClass(*(char **)(DAT_00010ee0 + 0x10e7a));
  snprintf((char *)(DAT_00010ee8 + 0x10e90),0x200,(char *)(DAT_00010eec + 0x10e9a),
           DAT_00010ef0 + 0x10ea0);
  uVar2 = _JNIEnv::GetStaticMethodID
                    (*(_JNIEnv **)(DAT_00010ef4 + 0x10eae),p_Var1,(char *)(DAT_00010ef8 + 0x10eb6),
                     (char *)(DAT_00010efc + 0x10ebc));
  uVar2 = _JNIEnv::CallStaticObjectMethod
                    (*(_jclass **)(DAT_00010f00 + 0x10ec8),(_jmethodID *)p_Var1,uVar2);
  return uVar2;
}



/* Function: thread_process @ 00010f04 */

undefined4 thread_process(char *param_1)

{
  __pid_t _Var1;
  int iVar2;
  int *piVar3;
  _jobject *p_Var4;
  code *pcVar5;
  sp<android::IBinder> asStack_6c [4];
  String16 aSStack_68 [4];
  DummyJavaBBinder *local_64;
  char *local_60;
  _jobject *local_5c;
  _jstring *local_58;
  int local_54;
  sp<android::IServiceManager> asStack_50 [4];
  int local_4c;
  _jarray *local_48;
  undefined4 local_44;
  _jmethodID *local_40;
  undefined4 local_3c;
  _jmethodID *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  _jclass *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  char *local_18;
  _JavaVM *local_14;
  
  local_14 = (_JavaVM *)android::AndroidRuntime::getJavaVM();
  _JavaVM::AttachCurrentThread(local_14,(_JNIEnv **)(DAT_000111d4 + 0x10f1a),(void *)0x0);
  _Var1 = getpid();
  local_18 = (char *)getProcessNameByPid(_Var1);
  local_1c = 0;
  local_20 = _JNIEnv::NewStringUTF
                       (*(_JNIEnv **)(DAT_000111d8 + 0x10f3c),(char *)(DAT_000111dc + 0x10f42));
  local_24 = _JNIEnv::NewStringUTF(*(_JNIEnv **)(DAT_000111e0 + 0x10f52),param_1);
  iVar2 = strcmp(local_18,(char *)(DAT_000111e4 + 0x10f68));
  if (iVar2 == 0) {
    local_1c = 0;
  }
  else {
    iVar2 = strcmp(local_18,(char *)(DAT_000111e8 + 0x10f82));
    if (iVar2 == 0) {
      local_1c = 1;
    }
    else {
      iVar2 = strcmp(local_18,(char *)(DAT_000111ec + 0x10f9c));
      if (iVar2 == 0) {
        local_1c = 2;
      }
    }
  }
  local_28 = (_jclass *)_JNIEnv::FindClass(*(char **)(DAT_000111f0 + 0x10fb2));
  snprintf((char *)(DAT_000111f8 + 0x10fc8),0x200,(char *)(DAT_000111fc + 0x10fd2),
           DAT_00011200 + 0x10fd8,DAT_00011204 + 0x10fde,DAT_00011208 + 0x10fe4,
           DAT_0001120c + 0x10fea);
  local_2c = _JNIEnv::GetMethodID
                       (*(_JNIEnv **)(DAT_00011210 + 0x10ffc),local_28,
                        (char *)(DAT_00011214 + 0x11004),(char *)(DAT_00011218 + 0x1100a));
  snprintf((char *)(DAT_0001121c + 0x11016),0x200,(char *)(DAT_00011220 + 0x11020),
           DAT_00011224 + 0x11026,DAT_00011228 + 0x1102c);
  local_30 = _JNIEnv::GetMethodID
                       (*(_JNIEnv **)(DAT_0001122c + 0x1103e),local_28,
                        (char *)(DAT_00011230 + 0x11046),(char *)(DAT_00011234 + 0x1104c));
  local_34 = getClassLoader();
  local_38 = (_jmethodID *)
             _JNIEnv::NewObject(*(_jclass **)(DAT_00011238 + 0x11060),(_jmethodID *)local_28,
                                local_2c,local_20,local_24,0,local_34);
  local_3c = _JNIEnv::NewStringUTF
                       (*(_JNIEnv **)(DAT_0001123c + 0x11080),(char *)(DAT_00011240 + 0x11086));
  local_40 = (_jmethodID *)
             _JNIEnv::CallObjectMethod
                       (*(_jobject **)(DAT_00011244 + 0x11096),local_38,local_30,local_3c);
  local_44 = _JNIEnv::GetStaticMethodID
                       (*(_JNIEnv **)(DAT_00011248 + 0x110aa),(_jclass *)local_40,
                        (char *)(DAT_0001124c + 0x110b2),(char *)(DAT_00011250 + 0x110b8));
  local_48 = (_jarray *)
             _JNIEnv::CallStaticObjectMethod
                       (*(_jclass **)(DAT_00011254 + 0x110c4),local_40,local_44,local_1c);
  local_4c = _JNIEnv::GetArrayLength(*(_JNIEnv **)(DAT_00011258 + 0x110d8),local_48);
  android::defaultServiceManager();
  for (local_54 = 0; local_54 < local_4c; local_54 = local_54 + 2) {
    local_58 = (_jstring *)
               _JNIEnv::GetObjectArrayElement
                         (*(_JNIEnv **)(DAT_0001125c + 0x110fa),(_jobjectArray *)local_48,local_54);
    local_5c = (_jobject *)
               _JNIEnv::GetObjectArrayElement
                         (*(_JNIEnv **)(DAT_00011260 + 0x11112),(_jobjectArray *)local_48,
                          local_54 + 1);
    local_60 = (char *)_JNIEnv::GetStringUTFChars
                                 (*(_JNIEnv **)(DAT_00011264 + 0x1112c),local_58,(uchar *)0x0);
    piVar3 = (int *)android::sp<android::IServiceManager>::operator->(asStack_50);
    pcVar5 = *(code **)(*piVar3 + 0x10);
    android::String16::String16(aSStack_68,local_60);
    (*pcVar5)(asStack_6c,piVar3,aSStack_68);
    local_64 = (DummyJavaBBinder *)android::sp<android::IBinder>::get(asStack_6c);
    android::sp<android::IBinder>::~sp(asStack_6c);
    android::String16::~String16(aSStack_68);
    p_Var4 = (_jobject *)_JNIEnv::NewGlobalRef(*(_JNIEnv **)(DAT_00011268 + 0x11188),local_5c);
    DummyJavaBBinder::changObj(local_64,p_Var4);
  }
  _JavaVM::DetachCurrentThread(local_14);
  android::sp<android::IServiceManager>::~sp(asStack_50);
  return 0;
}



/* Function: hook @ 0001126c */

void hook(undefined4 param_1,void *param_2)

{
  pthread_t apStack_c [2];
  
  pthread_create(apStack_c,(pthread_attr_t *)0x0,
                 *(__start_routine **)(DAT_00011290 + 0x11276 + DAT_00011294),param_2);
  return;
}



/* Function: ~sp @ 00011298 */

/* android::sp<android::IServiceManager>::~sp() */

sp<android::IServiceManager> * __thiscall
android::sp<android::IServiceManager>::~sp(sp<android::IServiceManager> *this)

{
  if (*(int *)this != 0) {
    android::RefBase::decStrong((void *)(*(int *)this + *(int *)(**(int **)this + -0xc)));
  }
  return this;
}



/* Function: operator-> @ 000112cc */

/* android::sp<android::IServiceManager>::TEMPNAMEPLACEHOLDERVALUE() const */

undefined4 __thiscall
android::sp<android::IServiceManager>::operator->(sp<android::IServiceManager> *this)

{
  return *(undefined4 *)this;
}



/* Function: ~sp @ 000112dc */

/* android::sp<android::IBinder>::~sp() */

sp<android::IBinder> * __thiscall android::sp<android::IBinder>::~sp(sp<android::IBinder> *this)

{
  if (*(int *)this != 0) {
    android::RefBase::decStrong((void *)(*(int *)this + *(int *)(**(int **)this + -0xc)));
  }
  return this;
}



/* Function: get @ 00011310 */

/* android::sp<android::IBinder>::get() const */

undefined4 __thiscall android::sp<android::IBinder>::get(sp<android::IBinder> *this)

{
  return *(undefined4 *)this;
}



/* Function: __aeabi_atexit @ 00011320 */

void __aeabi_atexit(undefined4 param_1,undefined4 param_2)

{
  (*(code *)PTR___cxa_atexit_00012680)(param_2,param_1);
  return;
}



/* Function: __aeabi_unwind_cpp_pr0 @ 00013000 */

/* WARNING: Control flow encountered bad instruction data */

void __aeabi_unwind_cpp_pr0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: defaultServiceManager @ 00013004 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::defaultServiceManager(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_atexit @ 00013008 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: snprintf @ 0001300c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getpid @ 00013010 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t getpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: ~String16 @ 00013014 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::String16::~String16(String16 *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fclose @ 00013018 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fopen @ 0001301c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: pthread_create @ 00013020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,
                  void *__arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: decStrong @ 00013024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void android::RefBase::decStrong(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: String16 @ 00013028 */

/* WARNING: Control flow encountered bad instruction data */

void __thiscall android::String16::String16(String16 *this,char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: fgets @ 0001302c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 00013034 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



