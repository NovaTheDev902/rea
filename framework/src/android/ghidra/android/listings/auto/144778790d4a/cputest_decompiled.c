/* Function: FUN_080482b0 @ 080482b0 */

void FUN_080482b0(void)

{
  (*(code *)PTR_08049594)();
  return;
}



/* Function: puts @ 080482c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_08049598)();
  return iVar1;
}



/* Function: __stack_chk_fail @ 080482d0 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_0804959c)();
  return;
}



/* Function: __libc_init @ 080482e0 */

void __libc_init(void)

{
  (*(code *)PTR___libc_init_080495a0)();
  return;
}



/* Function: __cxa_atexit @ 080482f0 */

void __cxa_atexit(void)

{
  (*(code *)PTR___cxa_atexit_080495a4)();
  return;
}



/* Function: entry @ 08048300 */

void processEntry entry(void)

{
  __libc_init(&stack0x00000000,0,0x804831a,&DAT_0804831f);
  FUN_08048400();
  return;
}



/* Function: _FINI_1 @ 08048330 */

/* WARNING: Removing unreachable block (ram,0x08048348) */

void _FINI_1(void)

{
  if (DAT_080495ac == '\0') {
    DAT_080495ac = '\x01';
  }
  return;
}



/* Function: _INIT_1 @ 08048360 */

/* WARNING: Removing unreachable block (ram,0x0804836f) */

void _INIT_1(void)

{
  return;
}



/* Function: FUN_080483a0 @ 080483a0 */

void FUN_080483a0(undefined4 param_1)

{
  int unaff_EBX;
  
  FUN_080483e5();
  __cxa_atexit(param_1,0,*(undefined4 *)(unaff_EBX + 0x11ff));
  return;
}



/* Function: FUN_080483e5 @ 080483e5 */

void FUN_080483e5(void)

{
  return;
}



/* Function: FUN_08048400 @ 08048400 */

undefined4 FUN_08048400(void)

{
  int unaff_EBX;
  
  FUN_080483e5();
  puts((char *)(unaff_EBX + 0x24));
  return 0x7b;
}



/* Function: puts @ 0804a000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 0804a004 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __libc_init @ 0804a008 */

/* WARNING: Control flow encountered bad instruction data */

void __libc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_atexit @ 0804a00c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



