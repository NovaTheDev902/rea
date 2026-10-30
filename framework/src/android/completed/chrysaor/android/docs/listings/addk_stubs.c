/* Decompiled stubs: addk */
/* Ghidra headless export - Chrysaor canonical sample */

/* === strcpy @ 00008818 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000aa10)(__dest);
  return pcVar1;
}


/* === waitpid @ 00008824 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t waitpid(__pid_t __pid,int *__stat_loc,int __options)

{
  __pid_t _Var1;
  
                    /* WARNING: Could not recover jumptable at 0x0000882c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  _Var1 = (*(code *)PTR_LAB_0000aa14)(__pid);
  return _Var1;
}


/* === printf @ 00008830 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008838. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000aa18)(__format);
  return iVar1;
}


/* === strerror @ 0000883c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strerror(int __errnum)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008844. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000aa1c)(__errnum);
  return pcVar1;
}


/* === snprintf @ 00008848 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008850. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000aa20)(__s);
  return iVar1;
}


/* === __errno @ 00008854 === */

void __errno(void)

{
                    /* WARNING: Could not recover jumptable at 0x0000885c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000aa24)();
  return;
}


/* === fgets @ 00008860 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008868. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000aa28)(__s);
  return pcVar1;
}


/* === memcpy @ 0000886c === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008874. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_LAB_0000aa2c)(__dest);
  return pvVar1;
}


/* === puts @ 00008878 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000aa30)(__s);
  return iVar1;
}


/* === malloc @ 00008884 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0000888c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_LAB_0000aa34)(__size);
  return pvVar1;
}


/* === strtoul @ 00008890 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008898. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR_LAB_0000aa38)(__nptr);
  return uVar1;
}


/* === __libc_init @ 0000889c === */

void __libc_init(void)

{
                    /* WARNING: Could not recover jumptable at 0x000088a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000aa3c)();
  return;
}


/* === fprintf @ 000088a8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fprintf(FILE *__stream,char *__format,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000aa40)(__stream);
  return iVar1;
}


/* === strstr @ 000088b4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000aa44)(__haystack);
  return pcVar1;
}


/* === strtok @ 000088c0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strtok(char *__s,char *__delim)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR_LAB_0000aa48)(__s);
  return pcVar1;
}


/* === fopen @ 000088cc === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fopen(char *__filename,char *__modes)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR_LAB_0000aa4c)(__filename);
  return pFVar1;
}


/* === memset @ 000088d8 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR_LAB_0000aa50)(__s);
  return pvVar1;
}


/* === fclose @ 000088e4 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000aa54)(__stream);
  return iVar1;
}


/* === ptrace @ 000088f0 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long ptrace(__ptrace_request __request,...)

{
  long lVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000088f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*(code *)PTR_LAB_0000aa58)(__request);
  return lVar1;
}


/* === exit @ 000088fc === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Could not recover jumptable at 0x00008904. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000aa5c)(__status);
  return;
}


/* === atoi @ 00008908 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int atoi(char *__nptr)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00008910. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_0000aa60)(__nptr);
  return iVar1;
}


/* === free @ 00008914 === */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Could not recover jumptable at 0x0000891c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0000aa64)(__ptr);
  return;
}


/* === _start @ 00008920 === */

void processEntry _start(void)

{
  __libc_init();
  return;
}


/* === get_libarary_addr @ 00008950 === */

void * get_libarary_addr(pid_t pid,char *module_name)

{
  char *pcVar1;
  char acStack_434 [1024];
  char acStack_34 [32];
  FILE *local_14;
  Elf32_Ehdr *local_10;
  char *local_c;
  
                    /* Unresolved local var: FILE * fp@[???]
                       Unresolved local var: long addr@[???]
                       Unresolved local var: char * pch@[???]
                       Unresolved local var: char[32] filename@[???]
                       Unresolved local var: char[1024] line@[???] */
  local_10 = (Elf32_Ehdr *)0x0;
  if (pid < 0) {
    snprintf(acStack_34,0x20,(char *)(DAT_00008ab4 + 0x8994),pid);
  }
  else {
    snprintf(acStack_34,0x20,(char *)(DAT_00008ab8 + 0x89b8),pid);
  }
  local_14 = fopen(acStack_34,(char *)(DAT_00008abc + 0x89d4));
  if (local_14 != (FILE *)0x0) {
    do {
      pcVar1 = fgets(acStack_434,0x400,local_14);
      if (pcVar1 == (char *)0x0) goto LAB_00008a9c;
      pcVar1 = strstr(acStack_434,module_name);
    } while (pcVar1 == (char *)0x0);
    local_c = strtok(acStack_434,(char *)(DAT_00008ac0 + 0x8a30));
    local_10 = (Elf32_Ehdr *)strtoul(local_c,(char **)0x0,0x10);
    if (local_10 == &Elf32_Ehdr_00008000) {
      local_10 = (Elf32_Ehdr *)0x0;
    }
LAB_00008a9c:
    fclose(local_14);
  }
  return local_10;
}


/* === get_remote_module_addr @ 00008ac4 === */

void * get_remote_module_addr(pid_t target_pid,char *module_name,void *param_3)

{
  void *pvVar1;
  void *pvVar2;
  
                    /* Unresolved local var: void * local_handle@[???]
                       Unresolved local var: void * remote_handle@[???] */
  pvVar1 = get_libarary_addr(-1,module_name);
  pvVar2 = get_libarary_addr(target_pid,module_name);
  return (void *)(((int)param_3 + (int)pvVar2) - (int)pvVar1);
}


/* === inject_process @ 00008b24 === */

int inject_process(pid_t pid,char *library_path,char *function_name,void *param,size_t param_size)

{
  int iVar1;
  uint32_t local_fc [10];
  undefined4 local_d4;
  undefined4 local_d0;
  void *local_cc;
  void *local_c8;
  void *local_c4;
  undefined1 auStack_c0 [60];
  undefined4 local_84;
  undefined4 local_80;
  pt_regs local_78;
  int local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *local_20;
  uint8_t *local_1c;
  void *local_18;
  int local_14;
  
                    /* Unresolved local var: pt_regs regs@[???]
                       Unresolved local var: pt_regs saved_regs@[???]
                       Unresolved local var: Hook hook@[???]
                       Unresolved local var: uint8_t * map_base@[???]
                       Unresolved local var: uint8_t * dlopen_param1_ptr@[???]
                       Unresolved local var: uint8_t * dlsym_param2_ptr@[???]
                       Unresolved local var: uint8_t * saved_r0_pc_ptr@[???]
                       Unresolved local var: uint8_t * inject_param_ptr@[???]
                       Unresolved local var: uint8_t * remote_code_ptr@[???]
                       Unresolved local var: uint8_t * local_code_ptr@[???]
                       Unresolved local var: uint32_t code_length@[???]
                       Unresolved local var: long[10] parameters@[???] */
  iVar1 = DAT_00008f88 + 0x8b3c;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = (void *)0x0;
  local_c8 = (void *)0x0;
  local_c4 = (void *)0x0;
  local_cc = get_remote_module_addr
                       (pid,(char *)(DAT_00008f8c + 0x8b80),*(void **)(iVar1 + DAT_00008f90));
  local_c8 = get_remote_module_addr
                       (pid,(char *)(DAT_00008f94 + 0x8ba8),*(void **)(iVar1 + DAT_00008f98));
  local_c4 = get_remote_module_addr
                       (pid,(char *)(DAT_00008f9c + 0x8bd0),*(void **)(iVar1 + DAT_00008fa0));
  printf((char *)(DAT_00008fa4 + 0x8bf4),pid);
  ptrace_attach(pid);
  ptrace_getregs(pid,&local_78);
  memcpy(auStack_c0,&local_78,0x48);
  printf((char *)(DAT_00008fa8 + 0x8c3c),local_c4);
  local_fc[0] = 0;
  local_fc[1] = 0x4000;
  local_fc[2] = 7;
  local_fc[3] = 0x22;
  local_fc[4] = 0;
  local_fc[5] = 0;
  puts((char *)(DAT_00008fac + 0x8c80));
  ptrace_call(pid,(uint32_t)local_c4,local_fc,6,&local_78);
  ptrace_getregs(pid,&local_78);
  printf((char *)(DAT_00008fb0 + 0x8cd0),local_78.uregs[0],local_78.uregs[0xf]);
  local_30 = local_78.uregs[0];
  printf((char *)(DAT_00008fb4 + 0x8cf0),local_cc,local_c8);
  local_1c = (uint8_t *)(local_30 + 0x3c00);
  local_18 = *(void **)(iVar1 + DAT_00008fb8);
  **(undefined4 **)(iVar1 + DAT_00008fbc) = local_cc;
  **(undefined4 **)(iVar1 + DAT_00008fc0) = local_c8;
  printf((char *)(DAT_00008fc4 + 0x8d40),local_18,*(undefined4 *)(iVar1 + DAT_00008fc8));
  local_14 = *(int *)(iVar1 + DAT_00008fc8) - *(int *)(iVar1 + DAT_00008fb8);
  local_2c = (char *)((int)local_18 + local_14 + 0x20);
  local_28 = local_2c + 0x100;
  local_24 = local_2c + 0x200;
  local_20 = local_2c + 0x300;
  strcpy(local_2c,library_path);
  **(int **)(iVar1 + DAT_00008fcc) = (int)(local_2c + (int)local_1c) - (int)local_18;
  printf((char *)(DAT_00008fd0 + 0x8dec),**(undefined4 **)(iVar1 + DAT_00008fcc));
  strcpy(local_28,function_name);
  **(int **)(iVar1 + DAT_00008fd4) = (int)(local_28 + (int)local_1c) - (int)local_18;
  printf((char *)(DAT_00008fd8 + 0x8e38),**(undefined4 **)(iVar1 + DAT_00008fd4));
  **(undefined4 **)(iVar1 + DAT_00008fdc) = local_80;
  memcpy(local_24,auStack_c0,0x40);
  **(int **)(iVar1 + DAT_00008fe0) = (int)(local_24 + (int)local_1c) - (int)local_18;
  printf((char *)(DAT_00008fe4 + 0x8ea0),**(undefined4 **)(iVar1 + DAT_00008fe0));
  memcpy(local_20,param,param_size);
  **(int **)(iVar1 + DAT_00008fe8) = (int)(local_20 + (int)local_1c) - (int)local_18;
  printf((char *)(DAT_00008fec + 0x8ef0),**(undefined4 **)(iVar1 + DAT_00008fe8));
  printf((char *)(DAT_00008ff0 + 0x8f04),local_1c);
  poke_text(pid,local_1c,local_18,0x400);
  memcpy(&local_78,auStack_c0,0x48);
  local_78.uregs[0xd] = (long)local_1c;
  local_78.uregs[0xf] = (long)local_1c;
  printf((char *)(DAT_00008ff4 + 0x8f58),local_84);
  ptrace_setregs(pid,&local_78);
  ptrace_detach(pid);
  return 0;
}


/* === die @ 00008ff8 === */

void die(int ln,char *file)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  char acStack_110 [260];
  
                    /* Unresolved local var: char[256] temp@[???] */
  iVar3 = DAT_00009078 + 0x9010;
  piVar1 = (int *)__errno();
  pcVar2 = strerror(*piVar1);
  snprintf(acStack_110,0x100,(char *)(DAT_0000907c + 0x9050),ln,file,pcVar2);
  fprintf((FILE *)(*(int *)(iVar3 + DAT_00009080) + 0xa8),acStack_110);
                    /* WARNING: Subroutine does not return */
  exit(-1);
}


/* === main @ 00009084 === */

int main(int argc,char **argv)

{
  int pid;
  
                    /* Unresolved local var: int pid@[???] */
  if (argc == 4) {
    pid = atoi(argv[1]);
    inject_process(pid,argv[2],argv[3],(void *)(DAT_00009124 + 0x9110),4);
  }
  else {
    printf((char *)(DAT_00009120 + 0x90b0));
  }
  return 0;
}


/* === ptrace_attach @ 00009128 === */

void ptrace_attach(pid_t pid)

{
  long lVar1;
  int iStack_c;
  
                    /* Unresolved local var: int state@[???] */
  lVar1 = ptrace(PTRACE_ATTACH,pid,0,0);
  if (lVar1 < 0) {
    die(0xf,(char *)(DAT_000091d0 + 0x9168));
  }
  waitpid(pid,&iStack_c,0);
  lVar1 = ptrace(PTRACE_SYSCALL,pid,0,0);
  if (lVar1 < 0) {
    die(0x13,(char *)(DAT_000091d4 + 0x91b0));
  }
  waitpid(pid,&iStack_c,0);
  return;
}


/* === ptrace_getregs @ 000091d8 === */

void ptrace_getregs(pid_t pid,pt_regs *regs)

{
  long lVar1;
  
  lVar1 = ptrace(PTRACE_GETREGS,pid,0,regs);
  if (lVar1 < 0) {
    die(0x1a,(char *)(DAT_00009228 + 0x921c));
  }
  return;
}


/* === ptrace_setregs @ 0000922c === */

void ptrace_setregs(pid_t pid,pt_regs *regs)

{
  long lVar1;
  
  lVar1 = ptrace(PTRACE_SETREGS,pid,0,regs);
  if (lVar1 < 0) {
    die(0x20,(char *)(DAT_0000927c + 0x9270));
  }
  return;
}


/* === ptrace_cont @ 00009280 === */

void ptrace_cont(pid_t pid)

{
  long lVar1;
  
  lVar1 = ptrace(PTRACE_CONT,pid,0,0);
  if (lVar1 < 0) {
    die(0x26,(char *)(DAT_000092cc + 0x92c0));
  }
  return;
}


/* === ptrace_detach @ 000092d0 === */

void ptrace_detach(pid_t pid)

{
  long lVar1;
  
  lVar1 = ptrace(PTRACE_DETACH,pid,0,0);
  if (lVar1 < 0) {
    die(0x2c,(char *)(DAT_0000931c + 0x9310));
  }
  return;
}


/* === ptrace_call @ 00009320 === */

void ptrace_call(pid_t pid,uint32_t addr,uint32_t *params,uint32_t params_num,pt_regs *regs)

{
  uint local_14;
  uint local_10;
  int local_c;
  
                    /* Unresolved local var: uint32_t i@[???]
                       Unresolved local var: int status@[???]
                       Unresolved local var: int id@[???] */
  for (local_10 = 0; (local_10 < params_num && (local_10 < 4)); local_10 = local_10 + 1) {
    regs->uregs[local_10] = params[local_10];
  }
  if (local_10 < params_num) {
    regs->uregs[0xd] = regs->uregs[0xd] + (params_num - local_10) * -4;
    poke_text(pid,(uint8_t *)regs->uregs[0xd],params + local_10,(params_num - local_10) * 4);
  }
  regs->uregs[0xf] = addr;
  if ((regs->uregs[0xf] & 1U) == 0) {
    regs->uregs[0x10] = regs->uregs[0x10] & 0xffffffdf;
  }
  else {
    regs->uregs[0xf] = regs->uregs[0xf] & 0xfffffffe;
    regs->uregs[0x10] = regs->uregs[0x10] | 0x20;
  }
  regs->uregs[0xe] = 0;
  ptrace_setregs(pid,regs);
  ptrace_cont(pid);
  local_c = 0;
  do {
    do {
      local_c = waitpid(pid,(int *)&local_14,2);
      printf((char *)(DAT_000094fc + 0x94c8),local_c,(int)(local_14 & 0xff00) >> 8);
    } while (local_c != pid);
  } while ((int)(local_14 & 0xff00) >> 8 != 0xb);
  return;
}


/* === poke_text @ 00009500 === */

void poke_text(pid_t pid,uint8_t *addr,void *buf,size_t blen)

{
  void *__s;
  long lVar1;
  size_t __size;
  uint local_14;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: size_t alen@[???]
                       Unresolved local var: char * ptr@[???] */
  __size = (blen & 0xfffffffc) + 4;
  __s = malloc(__size);
  if (__s == (void *)0x0) {
    die(0x77,(char *)(DAT_0000960c + 0x9568));
  }
  memset(__s,0,__size);
  memcpy(__s,buf,blen);
  for (local_14 = 0; local_14 < blen; local_14 = local_14 + 4) {
    lVar1 = ptrace(PTRACE_POKETEXT,pid,addr + local_14,*(undefined4 *)((int)__s + local_14));
    if (lVar1 < 0) {
      die(0x7f,(char *)(DAT_00009610 + 0x95dc));
    }
  }
  free(__s);
  return;
}


/* === peek_text @ 00009614 === */

void peek_text(pid_t pid,size_t addr,void *buf,size_t blen)

{
  long local_10;
  uint local_c;
  
                    /* Unresolved local var: int i@[???]
                       Unresolved local var: size_t word@[???] */
  local_10 = 0;
  for (local_c = 0; local_c < blen; local_c = local_c + 4) {
    local_10 = ptrace(PTRACE_PEEKTEXT,pid,local_c + addr,0);
    memcpy((void *)((int)buf + local_c),&local_10,4);
  }
  return;
}


/* === _inject_start_s @ 0000aa9c === */

undefined8 _inject_start_s(void)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = (*_dlopen_addr_s)(_dlopen_param1_s,_dlopen_param2_s);
  if (iVar1 != 0) {
    pcVar2 = (code *)(*_dlsym_addr_s)(iVar1,_dlsym_param2_s);
    (*pcVar2)(_inject_function_param_s);
  }
  return *_saved_r0_pc_s;
}


/* === mmap @ 0000b000 === */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * mmap(void *__addr,size_t __len,int __prot,int __flags,int __fd,__off_t __offset)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === dlopen @ 0000b004 === */

/* WARNING: Control flow encountered bad instruction data */

void dlopen(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* === dlsym @ 0000b00c === */

/* WARNING: Control flow encountered bad instruction data */

void dlsym(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

