/* Chrysaor native reassembly: sucopier / module file_copy */
/* Ghidra decompile - canonical sample ade8bef0... */

/* === FUN_00008f8c @ 0x00008f8c === */

void FUN_00008f8c(char *param_1,char *param_2)

{
  undefined1 *__buf;
  int iVar1;
  int iVar2;
  int __fd;
  int iVar3;
  size_t __n;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined1 *__buf_00;
  int iVar8;
  
  iVar2 = DAT_00009084;
  iVar1 = DAT_00009080;
  iVar8 = DAT_0000907c + 0x8fa2;
  *(undefined4 *)(&stack0xffffffe0 + DAT_00009088 + DAT_00009080) =
       **(undefined4 **)(iVar8 + DAT_00009084);
  __fd = open(param_1,0);
  if (-1 < __fd) {
    iVar3 = open(param_2,0xc1,0x1b6);
    __buf = &stack0xffffffe4 + iVar1;
    if (iVar3 < 0) {
LAB_00009068:
      puVar6 = (undefined4 *)__errno();
      uVar7 = *puVar6;
      close(__fd);
    }
    else {
LAB_00008fd4:
      __n = read(__fd,__buf,0x1000);
      if (0 < (int)__n) {
        iVar4 = write(iVar3,__buf,__n);
        __buf_00 = __buf;
        if (iVar4 < 0) goto LAB_0000900a;
        do {
          __n = __n - iVar4;
          __buf_00 = __buf_00 + iVar4;
          while( true ) {
            if ((int)__n < 1) goto LAB_00008fd4;
            iVar4 = write(iVar3,__buf_00,__n);
            if (-1 < iVar4) break;
LAB_0000900a:
            piVar5 = (int *)__errno();
            if (*piVar5 != 4) goto LAB_00009014;
          }
        } while( true );
      }
      if (__n == 0) {
        iVar3 = close(iVar3);
        if (-1 < iVar3) {
          close(__fd);
          uVar7 = 0;
          goto LAB_00009030;
        }
        goto LAB_00009068;
      }
LAB_00009014:
      puVar6 = (undefined4 *)__errno();
      uVar7 = *puVar6;
      close(__fd);
      close(iVar3);
    }
    puVar6 = (undefined4 *)__errno();
    *puVar6 = uVar7;
  }
  uVar7 = 0xffffffff;
LAB_00009030:
  if (*(int *)(&stack0xffffffe0 + DAT_00009088 + iVar1) == **(int **)(iVar8 + iVar2)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar7);
}

