/* Chrysaor native reassembly: take_screen_shot / module framebuffer */
/* Ghidra decompile - canonical sample ade8bef0... */

/* === FUN_00009028 @ 0x00009028 === */

undefined4 FUN_00009028(char *param_1,uint *param_2)

{
  int __fd;
  int iVar1;
  size_t __size;
  void *__buf;
  uint uVar2;
  uint local_c0;
  uint local_bc;
  int local_b0;
  int local_ac;
  uint local_a8;
  uint local_a0;
  uint local_9c;
  uint local_94;
  uint local_90;
  uint local_88;
  uint local_84;
  uint local_7c;
  uint local_78;
  
  __fd = open(param_1,0);
  if ((-1 < __fd) && (iVar1 = ioctl(__fd,0x4600,&local_c0), -1 < iVar1)) {
    *param_2 = local_a8;
    param_2[2] = local_c0;
    param_2[3] = local_bc;
    __size = local_bc * local_c0 * (local_a8 >> 3);
    param_2[4] = local_a0;
    param_2[1] = __size;
    param_2[5] = local_9c;
    param_2[8] = local_94;
    param_2[9] = local_90;
    param_2[6] = local_88;
    param_2[7] = local_84;
    param_2[10] = local_7c;
    param_2[0xb] = local_78;
    __buf = malloc(__size);
    if (__buf != (void *)0x0) {
      lseek(__fd,(local_c0 * local_ac + local_b0) * (local_a8 >> 3),0);
      uVar2 = read(__fd,__buf,param_2[1]);
      if (uVar2 == param_2[1]) {
        param_2[0xc] = (uint)__buf;
        close(__fd);
        return 0;
      }
      close(__fd);
      free(__buf);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

/* === FUN_000090ec @ 0x000090ec === */

undefined4 FUN_000090ec(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_44 [56];
  
  iVar1 = FUN_00009028(param_2,auStack_44);
  if (iVar1 == 0) {
    FUN_00009118(auStack_44);
    uVar2 = FUN_0000911c(auStack_44,param_1);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* === FUN_00009118 @ 0x00009118 === */

void FUN_00009118(void)

{
  return;
}

/* === FUN_0000911c @ 0x0000911c === */

int FUN_0000911c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *__ptr;
  int iVar1;
  int iVar2;
  
  __ptr = malloc(param_1[2] * param_1[3] * 3);
  if (__ptr != (void *)0x0) {
    if (*param_1 == 0x10) {
      iVar1 = FUN_000091e4(param_1[0xc],__ptr,param_1[3] * param_1[2],param_1[3],param_4);
    }
    else if ((param_1[4] != 8) || (param_1[10] != 0)) {
      if ((param_1[6] != 8) || (param_1[10] != 0)) {
        if (param_1[4] == 0) {
          iVar1 = FUN_0000928c(param_1[0xc],__ptr,param_1[3] * param_1[2]);
        }
        else {
          if (param_1[6] != 0) goto LAB_00009136;
          iVar1 = FUN_00009268(param_1[0xc],__ptr,param_1[3] * param_1[2]);
        }
      }
      else {
        iVar1 = FUN_00009244(param_1[0xc],__ptr,param_1[3] * param_1[2]);
      }
    }
    else {
      iVar1 = FUN_00009220(param_1[0xc],__ptr,param_1[3] * param_1[2]);
    }
    if ((iVar1 != 0) || (iVar2 = FUN_000092bc(param_2,__ptr,param_1[2],param_1[3]), iVar2 == 0))
    goto LAB_0000913a;
  }
LAB_00009136:
  iVar1 = -1;
LAB_0000913a:
  free(__ptr);
  return iVar1;
}

/* === FUN_000091e4 @ 0x000091e4 === */

undefined4 FUN_000091e4(ushort *param_1,char *param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort *puVar4;
  
  if (param_3 != 0) {
    puVar4 = param_1 + param_3;
    do {
      bVar1 = *(byte *)((int)param_1 + 1);
      *param_2 = (char)bVar1 >> 3;
      uVar2 = *param_1;
      param_2[1] = (char)((int)((uint)uVar2 << 0x15) >> 0x1a);
      uVar3 = *param_1;
      param_2[1] = (char)(((int)((uint)uVar2 << 0x15) >> 0x1a & 0xffU) << 2);
      param_1 = param_1 + 1;
      *param_2 = (char)(((int)((uint)bVar1 << 0x18) >> 0x1b & 0xffU) << 3);
      param_2[2] = (char)uVar3 << 3;
      param_2 = param_2 + 3;
    } while (param_1 != puVar4);
  }
  return 0;
}

/* === FUN_00009220 @ 0x00009220 === */

undefined4 FUN_00009220(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar2 = param_2 + param_3 * 3;
    do {
      *param_2 = *(undefined1 *)(param_1 + 1);
      param_2[1] = *(undefined1 *)(param_1 + 2);
      puVar1 = (undefined1 *)(param_1 + 3);
      param_1 = param_1 + 4;
      param_2[2] = *puVar1;
      param_2 = param_2 + 3;
    } while (param_2 != puVar2);
  }
  return 0;
}

/* === FUN_00009244 @ 0x00009244 === */

undefined4 FUN_00009244(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar2 = param_2 + param_3 * 3;
    do {
      *param_2 = *(undefined1 *)(param_1 + 3);
      param_2[1] = *(undefined1 *)(param_1 + 2);
      puVar1 = (undefined1 *)(param_1 + 1);
      param_1 = param_1 + 4;
      param_2[2] = *puVar1;
      param_2 = param_2 + 3;
    } while (param_2 != puVar2);
  }
  return 0;
}

/* === FUN_00009268 @ 0x00009268 === */

undefined4 FUN_00009268(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar2 = param_2 + param_3 * 3;
    do {
      *param_2 = param_1[2];
      param_2[1] = param_1[1];
      uVar1 = *param_1;
      param_1 = param_1 + 4;
      param_2[2] = uVar1;
      param_2 = param_2 + 3;
    } while (param_2 != puVar2);
  }
  return 0;
}

/* === FUN_0000928c @ 0x0000928c === */

undefined4 FUN_0000928c(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar2 = param_2 + param_3 * 3;
    do {
      *param_2 = *param_1;
      param_2[1] = param_1[1];
      puVar1 = param_1 + 2;
      param_1 = param_1 + 4;
      param_2[2] = *puVar1;
      param_2 = param_2 + 3;
    } while (param_2 != puVar2);
  }
  return 0;
}

/* === FUN_000092bc @ 0x000092bc === */

undefined4 FUN_000092bc(char *param_1,int param_2,int param_3,int param_4)

{
  FILE *__stream;
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_24;
  int local_20;
  void *local_1c;
  
  __stream = fopen(param_1,(char *)(DAT_000093b0 + 0x92ca));
  if (__stream == (FILE *)0x0) {
    puVar1 = (undefined4 *)__errno();
    uVar2 = *puVar1;
  }
  else {
    local_1c = malloc(param_4 << 2);
    if (local_1c != (void *)0x0) {
      if (0 < param_4) {
        iVar4 = 0;
        do {
          iVar3 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(int *)(iVar3 + (int)local_1c) = param_2;
          param_2 = param_2 + param_3 * 3;
        } while (iVar4 != param_4);
      }
      local_20 = FUN_0000aae8(DAT_000093b4 + 0x9302,0,DAT_000093b8 + 0x9304,DAT_000093bc + 0x9306);
      if (local_20 != 0) {
        local_24 = FUN_00009b18();
        if (local_24 != 0) {
          FUN_0000a050(local_20,__stream,DAT_000093c0 + 0x9324,DAT_000093c4 + 0x9326);
          FUN_00009f9c(local_20,local_24,param_3,param_4,8,2,0,0,0);
          FUN_00009f7c(local_20,local_24);
          FUN_0000ade8(local_20,local_24);
          FUN_0000a8e8(local_20,local_1c);
          FUN_0000aafc(local_20,local_24);
          FUN_0000a5e0(&local_20,&local_24);
          fclose(__stream);
          free(local_1c);
          return 0;
        }
        FUN_0000a5e0(&local_20,0);
      }
    }
    fclose(__stream);
    free(local_1c);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

/* === FUN_000093c8 @ 0x000093c8 === */

void FUN_000093c8(undefined4 param_1,void *param_2,size_t param_3)

{
  FILE *__s;
  size_t sVar1;
  
  __s = (FILE *)FUN_000093f0();
  for (; param_3 != 0; param_3 = param_3 - sVar1) {
    sVar1 = fwrite(param_2,1,param_3,__s);
    param_2 = (void *)((int)param_2 + sVar1);
  }
  return;
}

/* === FUN_000093f0 @ 0x000093f0 === */

undefined4 FUN_000093f0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x118);
  }
  return uVar1;
}

/* === FUN_00009400 @ 0x00009400 === */

void FUN_00009400(uint param_1,uint param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_2 & 0xffff) * (param_1 & 0xffff);
  uVar1 = (param_1 >> 0x10) * (param_2 & 0xffff) + (param_2 >> 0x10) * (param_1 & 0xffff) +
          (uVar2 >> 0x10);
  *param_3 = (uVar1 >> 0x10) + (param_2 >> 0x10) * (param_1 >> 0x10);
  *param_4 = uVar1 * 0x10000 | uVar2 & 0xffff;
  return;
}

/* === FUN_00009438 @ 0x00009438 === */

undefined4
FUN_00009438(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)

{
  undefined4 uVar1;
  int local_28;
  int local_24;
  int local_20;
  int local_1c [2];
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (((((param_3 < 1) || (param_2 < 0)) || (param_5 < 0)) || ((param_4 < 0 || (param_7 < 0)))) ||
       ((param_6 < 0 || ((param_9 < 0 || (uVar1 = 1, param_8 < 0)))))) {
      uVar1 = 0;
      FUN_00009c4c(param_1,DAT_00009520 + 0x9480);
    }
    if (DAT_00009524 - param_3 < param_2) {
      uVar1 = 0;
      FUN_00009c4c(param_1,DAT_00009528 + 0x9498);
    }
    if (DAT_00009524 - param_5 < param_4) {
      uVar1 = 0;
      FUN_00009c4c(param_1,DAT_0000952c + 0x94ac);
    }
    if (DAT_00009524 - param_7 < param_6) {
      uVar1 = 0;
      FUN_00009c4c(param_1,DAT_00009530 + 0x94c4);
    }
    if (DAT_00009524 - param_9 < param_8) {
      uVar1 = 0;
      FUN_00009c4c(param_1,DAT_00009534 + 0x94dc);
    }
    FUN_00009400(param_6 - param_4,param_9 - param_5,local_1c,&local_20);
    FUN_00009400(param_7 - param_5,param_8 - param_4,&local_24,&local_28);
    if ((local_1c[0] == local_24) && (local_20 == local_28)) {
      uVar1 = 0;
      FUN_00009c4c(param_1,DAT_00009538 + 0x9518);
    }
  }
  return uVar1;
}

/* === FUN_0000953c @ 0x0000953c === */

void FUN_0000953c(int param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  bool bVar1;
  
  if (param_2 == 0) {
    FUN_00009c4c(param_1,DAT_000096dc + 0x9558);
  }
  if (param_3 == 0) {
    FUN_00009c4c(param_1,DAT_000096e0 + 0x956a);
  }
  bVar1 = param_3 == 0 || param_2 == 0;
  if ((DAT_000096e4 < param_2) || (*(uint *)(param_1 + 0x328) < param_2)) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_000096e8 + 0x9588);
  }
  if ((DAT_000096e4 < param_3) || (*(uint *)(param_1 + 0x32c) < param_3)) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_000096ec + 0x95a6);
  }
  if ((int)param_2 < 0) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_000096f0 + 0x95b8);
  }
  if ((int)param_3 < 0) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_000096f4 + 0x95ca);
  }
  if (DAT_000096f8 < param_2) {
    FUN_00009c4c(param_1,DAT_000096fc + 0x95dc);
  }
  if ((((1 < param_4 - 1U) && (param_4 != 4)) && (param_4 != 0x10)) && (param_4 != 8)) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_00009700 + 0x95fa);
  }
  if (((param_5 == 1) || (param_5 < 0)) || ((6 < param_5 || (param_5 == 5)))) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_00009704 + 0x9616);
  }
  if (param_5 == 3) {
    if (8 < param_4) {
LAB_00009632:
      bVar1 = true;
      FUN_00009c4c(param_1,DAT_00009708 + 0x963c);
    }
  }
  else if ((((param_5 == 4) || (param_5 == 2)) || (param_5 == 6)) && (param_4 < 8))
  goto LAB_00009632;
  if (1 < param_6) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_0000970c + 0x964e);
  }
  if (param_7 != 0) {
    bVar1 = true;
    FUN_00009c4c(param_1,DAT_00009710 + 0x9660);
  }
  if ((*(int *)(param_1 + 300) << 0x13 < 0) && (*(int *)(param_1 + 0x2f4) != 0)) {
    FUN_00009c4c(param_1,DAT_00009714 + 0x967e);
  }
  if (param_8 != 0) {
    if ((((param_8 != 0x40) || (-1 < *(int *)(param_1 + 0x2f4) << 0x1d)) ||
        (*(int *)(param_1 + 300) << 0x13 < 0)) || ((param_5 != 6 && (param_5 != 2)))) {
      bVar1 = true;
      FUN_00009c4c(param_1,DAT_00009718 + 0x96b0);
    }
    if (*(int *)(param_1 + 300) << 0x13 < 0) {
      FUN_00009c4c(param_1,DAT_0000971c + 0x96c4);
      goto LAB_000096cc;
    }
  }
  if (!bVar1) {
    return;
  }
LAB_000096cc:
  FUN_00009d40(param_1,DAT_00009720 + 0x96d4);
  return;
}

/* === FUN_00009724 @ 0x00009724 === */

undefined1 FUN_00009724(int param_1,void *param_2)

{
  undefined1 uVar1;
  int iVar2;
  void *__s2;
  void *pvVar3;
  
  if (((param_2 == (void *)0x0) || (param_1 == 0)) || (iVar2 = *(int *)(param_1 + 0x2e4), iVar2 < 1)
     ) {
LAB_0000976a:
    uVar1 = 0;
  }
  else {
    __s2 = (void *)(*(int *)(param_1 + 0x2e8) + (iVar2 + -1) * 5);
    pvVar3 = (void *)((int)__s2 + iVar2 * -5 + 5);
    while (iVar2 = memcmp(param_2,__s2,4), iVar2 != 0) {
      if (__s2 == pvVar3) goto LAB_0000976a;
      __s2 = (void *)((int)__s2 + -5);
    }
    uVar1 = *(undefined1 *)((int)__s2 + 4);
  }
  return uVar1;
}

/* === FUN_000097c8 @ 0x000097c8 === */

void FUN_000097c8(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x11) < 0) {
      iVar3 = 0;
      if (param_4 == -1) {
        for (; iVar3 < *(int *)(param_2 + 0x30); iVar3 = iVar3 + 1) {
          FUN_000097c8(param_1,param_2,0x4000,iVar3);
        }
        FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0x38));
        *(undefined4 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
      else if ((*(int *)(param_2 + 0x38) != 0) &&
              (*(int *)(*(int *)(param_2 + 0x38) + param_4 * 0x10 + 4) != 0)) {
        FUN_00009e2c(param_1);
        *(undefined4 *)(*(int *)(param_2 + 0x38) + param_4 * 0x10 + 4) = 0;
      }
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x12) < 0) {
      FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0x4c));
      *(undefined4 *)(param_2 + 0x4c) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffffef;
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x17) < 0) {
      *(uint *)(param_2 + 8) = DAT_00009ad4 & *(uint *)(param_2 + 8);
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x18) < 0) {
      FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0xa0));
      FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0xac));
      *(undefined4 *)(param_2 + 0xa0) = 0;
      *(undefined4 *)(param_2 + 0xac) = 0;
      piVar4 = (int *)(param_2 + 0xb0);
      if (*piVar4 != 0) {
        for (iVar3 = 0; iVar3 < (int)(uint)*(byte *)(param_2 + 0xb5); iVar3 = iVar3 + 1) {
          FUN_00009e2c(param_1,*(undefined4 *)(*piVar4 + iVar3 * 4));
          *(undefined4 *)(*piVar4 + iVar3 * 4) = 0;
        }
        FUN_00009e2c(param_1,*piVar4);
        *piVar4 = 0;
      }
      *(uint *)(param_2 + 8) = DAT_00009ad8 & *(uint *)(param_2 + 8);
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x1b) < 0) {
      FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0xc4));
      FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 200));
      *(undefined4 *)(param_2 + 0xc4) = 0;
      *(undefined4 *)(param_2 + 200) = 0;
      *(uint *)(param_2 + 8) = DAT_00009adc & *(uint *)(param_2 + 8);
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x1a) < 0) {
      if (param_4 == -1) {
        piVar4 = (int *)(param_2 + 0xd8);
        iVar3 = 0;
        if (*piVar4 != 0) {
          for (; iVar3 < *piVar4; iVar3 = iVar3 + 1) {
            FUN_000097c8(param_1,param_2,0x20,iVar3);
          }
          FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0xd4));
          *(undefined4 *)(param_2 + 0xd4) = 0;
          *piVar4 = 0;
        }
        *(uint *)(param_2 + 8) = DAT_00009ae0 & *(uint *)(param_2 + 8);
      }
      else {
        piVar4 = (int *)(param_2 + 0xd4);
        if (*piVar4 != 0) {
          iVar3 = param_4 * 0x10;
          FUN_00009e2c(param_1,*(undefined4 *)(*piVar4 + iVar3));
          FUN_00009e2c(param_1,*(undefined4 *)(*piVar4 + iVar3 + 8));
          *(undefined4 *)(*piVar4 + iVar3) = 0;
          *(undefined4 *)(*piVar4 + iVar3 + 8) = 0;
        }
      }
    }
    if (*(int *)(param_1 + 0x338) != 0) {
      FUN_00009e2c(param_1);
      *(undefined4 *)(param_1 + 0x338) = 0;
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x16) < 0) {
      if (param_4 == -1) {
        piVar4 = (int *)(param_2 + 0xc0);
        iVar3 = 0;
        if (*piVar4 != 0) {
          for (; iVar3 < *piVar4; iVar3 = iVar3 + 1) {
            FUN_000097c8(param_1,param_2,0x200,iVar3);
          }
          FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0xbc));
          *(undefined4 *)(param_2 + 0xbc) = 0;
          *piVar4 = 0;
        }
      }
      else {
        iVar3 = *(int *)(param_2 + 0xbc);
        if (iVar3 != 0) {
          FUN_00009e2c(param_1,*(undefined4 *)(iVar3 + param_4 * 0x14 + 8));
          *(undefined4 *)(*(int *)(param_2 + 0xbc) + param_4 * 0x14 + 8) = 0;
        }
      }
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x1c) < 0) {
      FUN_00009e2c(param_1,*(undefined4 *)(param_2 + 0x7c));
      *(undefined4 *)(param_2 + 0x7c) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffffbf;
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x13) < 0) {
      png_zfree(param_1,*(undefined4 *)(param_2 + 0x10));
      *(undefined4 *)(param_2 + 0x10) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffff7;
      *(undefined2 *)(param_2 + 0x14) = 0;
    }
    if ((int)((*(uint *)(param_2 + 0xb8) & param_3) << 0x19) < 0) {
      piVar4 = (int *)(param_2 + 0xf8);
      iVar3 = 0;
      if (*piVar4 != 0) {
        for (; iVar3 < *(int *)(param_2 + 4); iVar3 = iVar3 + 1) {
          FUN_00009e2c(param_1,*(undefined4 *)(*piVar4 + iVar3 * 4));
          *(undefined4 *)(*piVar4 + iVar3 * 4) = 0;
        }
        FUN_00009e2c(param_1,*piVar4);
        *piVar4 = 0;
      }
      *(uint *)(param_2 + 8) = DAT_00009ae4 & *(uint *)(param_2 + 8);
    }
    puVar2 = (uint *)(param_2 + 0xb8);
    if (param_4 == -1) {
      uVar1 = *puVar2 & ~param_3;
    }
    else {
      uVar1 = *puVar2 & ~(DAT_00009ae8 & param_3);
    }
    *puVar2 = uVar1;
  }
  return;
}

/* === FUN_00009aec @ 0x00009aec === */

void FUN_00009aec(int *param_1,uint param_2)

{
  void *__s;
  
  __s = (void *)*param_1;
  if (__s != (void *)0x0) {
    if (param_2 <= DAT_00009b14) {
      FUN_00009e78();
      __s = (void *)FUN_00009f70(2);
      *param_1 = (int)__s;
    }
    memset(__s,0,0x120);
  }
  return;
}

/* === FUN_00009b18 @ 0x00009b18 === */

int FUN_00009b18(int param_1)

{
  int local_c [2];
  
  local_c[0] = 0;
  if ((param_1 != 0) &&
     (local_c[0] = FUN_00009f24(2,*(undefined4 *)(param_1 + 0x30c),*(undefined4 *)(param_1 + 0x308))
     , local_c[0] != 0)) {
    FUN_00009aec(local_c,0x120);
  }
  return local_c[0];
}

