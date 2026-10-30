/* Chrysaor native reassembly: take_screen_shot / module implant */
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

/* === png_zalloc @ 0x00009770 === */

undefined4 png_zalloc(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x130);
  uVar1 = FUN_0000dd90(0xffffffff,param_3);
  if (uVar1 < param_2) {
    FUN_00009c4c(param_1,DAT_000097bc + 0x9798);
    uVar2 = 0;
  }
  else {
    *(uint *)(param_1 + 0x130) = uVar3 | 0x100000;
    uVar2 = FUN_00009e9c(param_1,param_3 * param_2);
    *(uint *)(param_1 + 0x130) = uVar3;
  }
  return uVar2;
}

/* === png_zfree @ 0x000097c0 === */

void png_zfree(void)

{
  FUN_00009e2c();
  return;
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

/* === FUN_00009b4c @ 0x00009b4c === */

void FUN_00009b4c(int param_1)

{
  undefined4 uVar1;
  
  if ((int)((uint)*(byte *)(param_1 + 0x1e0) << 0x1a) < 0) {
    if ((*(uint *)(param_1 + 0x130) & 0x300) == 0x300) {
      return;
    }
  }
  else if (*(int *)(param_1 + 0x130) << 0x14 < 0) {
    return;
  }
  uVar1 = crc32(*(undefined4 *)(param_1 + 0x1d4));
  *(undefined4 *)(param_1 + 0x1d4) = uVar1;
  return;
}

/* === FUN_00009b80 @ 0x00009b80 === */

void FUN_00009b80(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = crc32(0,0,0);
  *(undefined4 *)(param_1 + 0x1d4) = uVar1;
  return;
}

/* === FUN_00009b98 @ 0x00009b98 === */

void FUN_00009b98(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x108) = param_2;
    *(undefined4 *)(param_1 + 0x100) = param_3;
    *(undefined4 *)(param_1 + 0x104) = param_4;
  }
  return;
}

/* === FUN_00009ba8 @ 0x00009ba8 === */

void FUN_00009ba8(undefined4 param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  FILE *__stream;
  char local_24 [16];
  int local_14;
  
  iVar3 = DAT_00009c34 + 0x9bb4;
  local_14 = **(int **)(iVar3 + DAT_00009c38);
  if (*param_2 == '#') {
    iVar2 = 0;
    pcVar1 = param_2;
    do {
      local_24[iVar2] = pcVar1[1];
      if (*pcVar1 == ' ') break;
      iVar2 = iVar2 + 1;
      pcVar1 = pcVar1 + 1;
    } while (iVar2 != 0xf);
    if (iVar2 - 2U < 0xd) {
      local_24[iVar2 + 1] = '\0';
      __stream = (FILE *)(*(int *)(iVar3 + DAT_00009c3c) + 0xa8);
      fprintf(__stream,(char *)(DAT_00009c40 + 0x9bf4),local_24,param_2 + iVar2);
      goto LAB_00009c16;
    }
    iVar2 = *(int *)(iVar3 + DAT_00009c3c);
    pcVar1 = (char *)(DAT_00009c44 + 0x9c06);
  }
  else {
    iVar2 = *(int *)(iVar3 + DAT_00009c3c);
    pcVar1 = (char *)(DAT_00009c48 + 0x9c10);
  }
  __stream = (FILE *)(iVar2 + 0xa8);
  fprintf(__stream,pcVar1);
LAB_00009c16:
  iVar2 = DAT_00009c38;
  fputc(10,__stream);
  if (local_14 != **(int **)(iVar3 + iVar2)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_00009c4c @ 0x00009c4c === */

void FUN_00009c4c(int param_1,char *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    if (((*(uint *)(param_1 + 0x130) & 0xc0000) == 0) || (*param_2 != '#')) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
      do {
        if (param_2[iVar1] == ' ') break;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0xf);
    }
    if (*(code **)(param_1 + 0x104) != (code *)0x0) {
      (**(code **)(param_1 + 0x104))(param_1,param_2 + iVar1);
      return;
    }
  }
  FUN_00009ba8(param_1,param_2 + iVar1);
  return;
}

/* === FUN_00009c98 @ 0x00009c98 === */

void FUN_00009c98(__jmp_buf_tag *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  FILE *__stream;
  int iVar3;
  char acStack_2d [17];
  undefined4 local_1c;
  
  iVar3 = DAT_00009d28 + 0x9ca4;
  local_1c = **(undefined4 **)(iVar3 + DAT_00009d2c);
  if (*param_2 == '#') {
    pcVar2 = (char *)0x0;
    pcVar1 = param_2;
    do {
      (acStack_2d + 1)[(int)pcVar2] = pcVar1[1];
      if (*pcVar1 == ' ') break;
      pcVar2 = pcVar2 + 1;
      pcVar1 = pcVar1 + 1;
    } while (pcVar2 != (char *)0xf);
    if (pcVar2 + -2 < (char *)0xd) {
      acStack_2d[(int)pcVar2] = '\0';
      iVar3 = *(int *)(iVar3 + DAT_00009d30);
      pcVar2 = param_2 + (int)(pcVar2 + 1);
      pcVar1 = (char *)(DAT_00009d34 + 0x9cea);
      param_2 = acStack_2d + 1;
    }
    else {
      iVar3 = *(int *)(iVar3 + DAT_00009d30);
      pcVar1 = (char *)(DAT_00009d38 + 0x9cf8);
    }
    __stream = (FILE *)(iVar3 + 0xa8);
    fprintf(__stream,pcVar1,param_2,pcVar2);
  }
  else {
    __stream = (FILE *)(*(int *)(iVar3 + DAT_00009d30) + 0xa8);
    fprintf(__stream,(char *)(DAT_00009d3c + 0x9d08));
  }
  fputc(10,__stream);
  if (param_1 != (__jmp_buf_tag *)0x0) {
                    /* WARNING: Subroutine does not return */
    longjmp(param_1,1);
  }
                    /* WARNING: Subroutine does not return */
  abort();
}

/* === FUN_00009d40 @ 0x00009d40 === */

void FUN_00009d40(int param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char acStack_25 [17];
  int local_14;
  
  iVar4 = DAT_00009de4 + 0x9d4c;
  local_14 = **(int **)(iVar4 + DAT_00009de8);
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 0x130);
    if ((uVar1 & 0xc0000) != 0) {
      if (*param_2 == '#') {
        iVar3 = 1;
        do {
          if (param_2[iVar3] == ' ') break;
          iVar3 = iVar3 + 1;
        } while (iVar3 != 0xf);
        if ((int)(uVar1 << 0xc) < 0) {
          for (iVar2 = 0; iVar2 < iVar3 + -1; iVar2 = iVar2 + 1) {
            (acStack_25 + 1)[iVar2] = param_2[iVar2 + 1];
          }
          acStack_25[iVar2] = '\0';
          param_2 = acStack_25 + 1;
        }
        else {
          param_2 = param_2 + iVar3;
        }
      }
      else if ((int)(uVar1 << 0xc) < 0) {
        param_2 = acStack_25 + 1;
        acStack_25[1] = 0x30;
        acStack_25[2] = 0;
      }
    }
    if (*(code **)(param_1 + 0x100) != (code *)0x0) {
      (**(code **)(param_1 + 0x100))(param_1,param_2);
    }
  }
  FUN_00009c98(param_1,param_2);
  if (local_14 == **(int **)(iVar4 + DAT_00009de8)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

/* === FUN_00009dec @ 0x00009dec === */

void FUN_00009dec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x308) = param_2;
    *(undefined4 *)(param_1 + 0x30c) = param_3;
    *(undefined4 *)(param_1 + 0x310) = param_4;
  }
  return;
}

/* === FUN_00009e08 @ 0x00009e08 === */

void FUN_00009e08(undefined4 param_1,void *param_2,void *param_3,size_t param_4)

{
  memcpy(param_2,param_3,param_4);
  return;
}

/* === FUN_00009e18 @ 0x00009e18 === */

void FUN_00009e18(int param_1,void *param_2)

{
  if ((param_2 != (void *)0x0) && (param_1 != 0)) {
    free(param_2);
  }
  return;
}

/* === FUN_00009e2c @ 0x00009e2c === */

void FUN_00009e2c(int param_1,int param_2)

{
  if ((param_2 != 0) && (param_1 != 0)) {
    if (*(code **)(param_1 + 0x310) == (code *)0x0) {
      FUN_00009e18();
    }
    else {
      (**(code **)(param_1 + 0x310))();
    }
  }
  return;
}

/* === FUN_00009e4c @ 0x00009e4c === */

void FUN_00009e4c(void *param_1,code *param_2,undefined4 param_3)

{
  if (param_1 != (void *)0x0) {
    if (param_2 == (code *)0x0) {
      free(param_1);
    }
    else {
      *(undefined4 *)(&stack0x00000300 + DAT_00009e74) = param_3;
      (*param_2)(&stack0xfffffff8 + DAT_00009e74,param_1);
    }
  }
  return;
}

/* === FUN_00009e78 @ 0x00009e78 === */

void FUN_00009e78(undefined4 param_1)

{
  FUN_00009e4c(param_1,0,0);
  return;
}

/* === FUN_00009e84 @ 0x00009e84 === */

void * FUN_00009e84(int param_1,size_t param_2)

{
  void *pvVar1;
  
  if ((param_2 == 0) || (param_1 == 0)) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = malloc(param_2);
  }
  return pvVar1;
}

/* === FUN_00009e9c @ 0x00009e9c === */

int FUN_00009e9c(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 == 0) || (param_1 == 0)) {
    iVar1 = 0;
  }
  else {
    if (*(code **)(param_1 + 0x30c) == (code *)0x0) {
      iVar1 = FUN_00009e84(param_1);
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x30c))(param_1);
    }
    if ((iVar1 == 0) && (-1 < *(int *)(param_1 + 0x130) << 0xb)) {
      FUN_00009d40(param_1,DAT_00009ee0 + 0x9ed8);
    }
  }
  return iVar1;
}

/* === FUN_00009ee4 @ 0x00009ee4 === */

undefined4 FUN_00009ee4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar2 = *(uint *)(param_1 + 0x130);
    *(uint *)(param_1 + 0x130) = uVar2 | 0x100000;
    uVar1 = FUN_00009e9c(param_1);
    *(uint *)(param_1 + 0x130) = uVar2;
  }
  return uVar1;
}

/* === FUN_00009f08 @ 0x00009f08 === */

void * FUN_00009f08(undefined4 param_1,size_t param_2)

{
  void *__s;
  
  __s = (void *)FUN_00009e9c();
  if (__s != (void *)0x0) {
    memset(__s,0,param_2);
  }
  return __s;
}

/* === FUN_00009f24 @ 0x00009f24 === */

void * FUN_00009f24(int param_1,code *param_2,undefined4 param_3)

{
  void *__s;
  size_t __size;
  
  if (param_1 == 2) {
    __size = 0x120;
  }
  else {
    if (param_1 != 1) {
      return (void *)0x0;
    }
    __size = 0x358;
  }
  if (param_2 == (code *)0x0) {
    __s = malloc(__size);
  }
  else {
    *(undefined4 *)(&stack0x000002fc + DAT_00009f6c) = param_3;
    __s = (void *)(*param_2)(&stack0xfffffff4 + DAT_00009f6c,__size);
  }
  if (__s != (void *)0x0) {
    memset(__s,0,__size);
  }
  return __s;
}

/* === FUN_00009f70 @ 0x00009f70 === */

void FUN_00009f70(undefined4 param_1)

{
  FUN_00009f24(param_1,0,0);
  return;
}

/* === FUN_00009f7c @ 0x00009f7c === */

void FUN_00009f7c(int param_1,int param_2,void *param_3)

{
  if ((param_2 != 0) && (param_1 != 0)) {
    memcpy((void *)(param_2 + 0x5a),param_3,10);
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x20;
  }
  return;
}

/* === FUN_00009f9c @ 0x00009f9c === */

void FUN_00009f9c(int param_1,uint *param_2,uint param_3,uint param_4,undefined1 param_5,
                 undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  uint uVar1;
  undefined1 uVar2;
  byte bVar3;
  
  if ((param_2 != (uint *)0x0) && (param_1 != 0)) {
    *param_2 = param_3;
    param_2[1] = param_4;
    *(undefined1 *)((int)param_2 + 0x19) = param_6;
    *(undefined1 *)(param_2 + 6) = param_5;
    *(undefined1 *)((int)param_2 + 0x1b) = param_9;
    *(undefined1 *)((int)param_2 + 0x1a) = param_8;
    *(undefined1 *)(param_2 + 7) = param_7;
    FUN_0000953c(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    if ((*(byte *)((int)param_2 + 0x19) == 3) ||
       (-1 < (int)((uint)*(byte *)((int)param_2 + 0x19) << 0x1e))) {
      uVar2 = 1;
    }
    else {
      uVar2 = 3;
    }
    *(undefined1 *)((int)param_2 + 0x1d) = uVar2;
    if ((int)((uint)*(byte *)((int)param_2 + 0x19) << 0x1d) < 0) {
      *(char *)((int)param_2 + 0x1d) = *(char *)((int)param_2 + 0x1d) + '\x01';
    }
    uVar1 = DAT_0000a03c;
    bVar3 = (char)param_2[6] * *(char *)((int)param_2 + 0x1d);
    *(byte *)((int)param_2 + 0x1e) = bVar3;
    if (uVar1 < param_3) {
      param_3 = 0;
    }
    else if (bVar3 < 8) {
      param_3 = param_3 * bVar3 + 7 >> 3;
    }
    else {
      param_3 = param_3 * (bVar3 >> 3);
    }
    param_2[3] = param_3;
  }
  return;
}

/* === FUN_0000a040 @ 0x0000a040 === */

void FUN_0000a040(int param_1)

{
  if (*(code **)(param_1 + 0x210) != (code *)0x0) {
    (**(code **)(param_1 + 0x210))();
  }
  return;
}

/* === FUN_0000a050 @ 0x0000a050 === */

void FUN_0000a050(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = DAT_0000a0a4 + 0xa058;
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x118) = param_2;
    if (param_3 == 0) {
      param_3 = *(int *)(iVar1 + DAT_0000a0a8);
    }
    *(int *)(param_1 + 0x10c) = param_3;
    if (param_4 == 0) {
      *(undefined4 *)(param_1 + 0x210) = *(undefined4 *)(iVar1 + DAT_0000a0ac);
    }
    else {
      *(int *)(param_1 + 0x210) = param_4;
    }
    if (*(int *)(param_1 + 0x110) != 0) {
      iVar1 = DAT_0000a0b0 + 0xa092;
      *(undefined4 *)(param_1 + 0x110) = 0;
      FUN_00009c4c(param_1,iVar1);
      FUN_00009c4c(param_1,DAT_0000a0b4 + 0xa09e);
    }
  }
  return;
}

/* === png_default_flush @ 0x0000a0b8 === */

void png_default_flush(int param_1)

{
  if (param_1 != 0) {
    fflush(*(FILE **)(param_1 + 0x118));
  }
  return;
}

/* === png_default_write_data @ 0x0000a0c8 === */

void png_default_write_data(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  if ((param_1 != 0) &&
     (sVar1 = fwrite(param_2,1,param_3,*(FILE **)(param_1 + 0x118)), sVar1 != param_3)) {
    FUN_00009d40(param_1,DAT_0000a0f0 + 0xa0ec);
  }
  return;
}

/* === FUN_0000a0f4 @ 0x0000a0f4 === */

void FUN_0000a0f4(int param_1)

{
  if (*(code **)(param_1 + 0x10c) == (code *)0x0) {
    FUN_00009d40(param_1,DAT_0000a110 + 0xa10a);
  }
  else {
    (**(code **)(param_1 + 0x10c))();
  }
  return;
}

/* === FUN_0000a118 @ 0x0000a118 === */

void FUN_0000a118(int param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 *local_30;
  int local_1c;
  
  if (param_1 != 0) {
    if (param_2 < 3) {
      if (param_2 == 0) {
        param_2 = 1;
      }
      if (((param_4 == (undefined4 *)0x0) || (param_3 < 0)) || (param_2 == 1)) {
        param_3 = 0;
      }
      *(char *)(param_1 + DAT_0000a34c) = (char)param_3;
      *(char *)(param_1 + 700) = (char)param_2;
      if (param_3 != 0) {
        if (*(int *)(param_1 + 0x2c0) == 0) {
          uVar3 = FUN_00009e9c(param_1,param_3);
          *(undefined4 *)(param_1 + 0x2c0) = uVar3;
          iVar5 = 0;
          do {
            *(undefined1 *)(*(int *)(param_1 + 0x2c0) + iVar5) = 0xff;
            iVar5 = iVar5 + 1;
          } while (iVar5 < param_3);
        }
        if (*(int *)(param_1 + 0x2c4) == 0) {
          uVar3 = FUN_00009e9c(param_1,param_3 * 2);
          *(undefined4 *)(param_1 + 0x2c4) = uVar3;
          uVar3 = FUN_00009e9c(param_1,param_3 * 2);
          *(undefined4 *)(param_1 + 0x2c8) = uVar3;
          iVar5 = 0;
          do {
            iVar7 = *(int *)(param_1 + 0x2c8);
            iVar2 = iVar5 * 2;
            iVar5 = iVar5 + 1;
            *(undefined2 *)(*(int *)(param_1 + 0x2c4) + iVar2) = 0x100;
            *(undefined2 *)(iVar7 + iVar2) = 0x100;
          } while (iVar5 < param_3);
        }
        iVar5 = 0;
        local_1c = 0;
        local_30 = param_4;
        do {
          uVar3 = *local_30;
          uVar4 = local_30[1];
          iVar2 = FUN_0000e758(uVar3,uVar4,DAT_0000a320,DAT_0000a324);
          if (iVar2 == 0) {
            uVar8 = FUN_0000e20c(uVar3,uVar4,DAT_0000a328,DAT_0000a32c);
            FUN_0000de60((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_0000a330,DAT_0000a334);
            uVar1 = FUN_0000e7a8();
            *(undefined2 *)(*(int *)(param_1 + 0x2c8) + iVar5) = uVar1;
            iVar2 = *(int *)(param_1 + 0x2c4);
            uVar8 = FUN_0000e478(DAT_0000a328,DAT_0000a32c,*local_30,local_30[1]);
            FUN_0000de60((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_0000a330,DAT_0000a334);
            uVar1 = FUN_0000e7a8();
            *(undefined2 *)(iVar2 + iVar5) = uVar1;
          }
          else {
            iVar2 = *(int *)(param_1 + 0x2c8);
            *(undefined2 *)(*(int *)(param_1 + 0x2c4) + iVar5) = 0x100;
            *(undefined2 *)(iVar2 + iVar5) = 0x100;
          }
          local_1c = local_1c + 1;
          local_30 = local_30 + 2;
          iVar5 = iVar5 + 2;
        } while (local_1c < param_3);
      }
      if (*(int *)(param_1 + 0x2cc) == 0) {
        uVar3 = FUN_00009e9c(param_1,10);
        *(undefined4 *)(param_1 + 0x2cc) = uVar3;
        uVar3 = FUN_00009e9c(param_1,10);
        *(undefined4 *)(param_1 + 0x2d0) = uVar3;
        iVar5 = 0;
        do {
          iVar2 = *(int *)(param_1 + 0x2d0);
          *(undefined2 *)(*(int *)(param_1 + 0x2cc) + iVar5) = 8;
          *(undefined2 *)(iVar2 + iVar5) = 8;
          iVar5 = iVar5 + 2;
        } while (iVar5 != 10);
      }
      iVar5 = 0;
      puVar6 = param_5;
      do {
        if (param_5 == (undefined4 *)0x0) {
LAB_0000a2aa:
          iVar2 = *(int *)(param_1 + 0x2d0);
          *(undefined2 *)(*(int *)(param_1 + 0x2cc) + iVar5) = 8;
          *(undefined2 *)(iVar2 + iVar5) = 8;
        }
        else {
          uVar3 = *puVar6;
          uVar4 = puVar6[1];
          iVar2 = FUN_0000e758(uVar3,uVar4,DAT_0000a320,DAT_0000a324);
          if (iVar2 != 0) goto LAB_0000a2aa;
          iVar2 = FUN_0000e780(uVar3,uVar4,DAT_0000a338,DAT_0000a33c);
          if (iVar2 != 0) {
            iVar2 = *(int *)(param_1 + 0x2d0);
            uVar8 = FUN_0000e478(DAT_0000a340,DAT_0000a344,uVar3,uVar4);
            FUN_0000de60((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_0000a330,DAT_0000a334);
            uVar1 = FUN_0000e7a8();
            *(undefined2 *)(iVar2 + iVar5) = uVar1;
            iVar2 = *(int *)(param_1 + 0x2cc);
            uVar8 = FUN_0000e20c(*puVar6,puVar6[1],DAT_0000a340,DAT_0000a344);
            FUN_0000de60((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),DAT_0000a330,DAT_0000a334);
            uVar1 = FUN_0000e7a8();
            *(undefined2 *)(iVar2 + iVar5) = uVar1;
          }
        }
        iVar5 = iVar5 + 2;
        puVar6 = puVar6 + 2;
      } while (iVar5 != 10);
    }
    else {
      FUN_00009c4c(param_1,DAT_0000a348 + 0xa132);
    }
  }
  return;
}

/* === FUN_0000a4e0 @ 0x0000a4e0 === */

void FUN_0000a4e0(void *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_118 [260];
  
  deflateEnd((int)param_1 + 0x138);
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x170));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x1b0));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x1ac));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x1b4));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x1b8));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x1bc));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x1c0));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x2d4));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x2c0));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x2c4));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x2c8));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x2cc));
  FUN_00009e2c(param_1,*(undefined4 *)((int)param_1 + 0x2d0));
  memcpy(auStack_118,param_1,0x100);
  uVar4 = *(undefined4 *)((int)param_1 + 0x100);
  uVar3 = *(undefined4 *)((int)param_1 + 0x104);
  uVar1 = *(undefined4 *)((int)param_1 + 0x310);
  uVar2 = *(undefined4 *)((int)param_1 + 0x108);
  memset(param_1,0,0x358);
  *(undefined4 *)((int)param_1 + 0x100) = uVar4;
  *(undefined4 *)((int)param_1 + 0x104) = uVar3;
  *(undefined4 *)((int)param_1 + 0x108) = uVar2;
  *(undefined4 *)((int)param_1 + 0x310) = uVar1;
  memcpy(param_1,auStack_118,0x100);
  return;
}

/* === FUN_0000a5e0 @ 0x0000a5e0 === */

void FUN_0000a5e0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
    local_28 = 0;
    local_24 = 0;
  }
  else {
    iVar2 = *param_1;
    local_24 = *(undefined4 *)(iVar2 + 0x310);
    local_28 = *(undefined4 *)(iVar2 + 0x308);
  }
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
    if (iVar1 != 0) {
      if ((iVar2 != 0) &&
         (FUN_000097c8(iVar2,iVar1,DAT_0000a670,0xffffffff), *(int *)(iVar2 + 0x2e4) != 0)) {
        FUN_00009e2c(iVar2,*(undefined4 *)(iVar2 + 0x2e8));
        *(undefined4 *)(iVar2 + 0x2e8) = 0;
        *(undefined4 *)(iVar2 + 0x2e4) = 0;
      }
      FUN_00009e4c(iVar1,local_24,local_28);
      *param_2 = 0;
    }
  }
  if (iVar2 != 0) {
    FUN_0000a4e0(iVar2);
    FUN_00009e4c(iVar2,local_24,local_28);
    *param_1 = 0;
  }
  return;
}

/* === FUN_0000a674 @ 0x0000a674 === */

void FUN_0000a674(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  uint uVar3;
  int iVar4;
  
  if ((param_1 != 0) && (uVar3 = *(uint *)(param_1 + 0x194), *(uint *)(param_1 + 0x1a8) < uVar3)) {
    uVar2 = 0x138;
    iVar4 = DAT_0000a6f4 + 0xa69a;
    while( true ) {
      iVar1 = deflate(param_1 + 0x138,2,uVar2,uVar3,param_4);
      if (iVar1 != 0) {
        iVar1 = *(int *)(param_1 + 0x150);
        if (*(int *)(param_1 + 0x150) == 0) {
          iVar1 = iVar4;
        }
        FUN_00009d40(param_1,iVar1);
      }
      iVar1 = *(int *)(param_1 + 0x148);
      if (iVar1 != 0) break;
      FUN_0000ca6c(param_1,*(undefined4 *)(param_1 + 0x170));
      uVar3 = *(uint *)(param_1 + 0x174);
      *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
      *(uint *)(param_1 + 0x148) = uVar3;
      uVar2 = extraout_r2;
    }
    if (*(int *)(param_1 + 0x174) != iVar1) {
      FUN_0000ca6c(param_1,*(undefined4 *)(param_1 + 0x170),*(int *)(param_1 + 0x174) - iVar1);
      *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
      *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
    }
    *(undefined4 *)(param_1 + 0x218) = 0;
    FUN_0000a040(param_1);
  }
  return;
}

/* === FUN_0000a6f8 @ 0x0000a6f8 === */

void FUN_0000a6f8(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x1a8) == 0) && (*(char *)(param_1 + 0x1e8) == '\0')) {
      if (-1 < *(int *)(param_1 + 300) << 0x15) {
        FUN_00009d40(param_1,DAT_0000a8d0 + 0xa72a);
      }
      FUN_0000b7a8(param_1);
    }
    if (((*(char *)(param_1 + DAT_0000a8d4) != '\0') && (*(int *)(param_1 + 0x134) << 0x1e < 0)) &&
       (*(byte *)(param_1 + 0x1e8) < 7)) {
                    /* WARNING: Could not emulate address calculation at 0x0000a754 */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(int *)((uint)*(byte *)(param_1 + 0x1e8) * 4 + DAT_0000a8d8 + 0xa756) +
                DAT_0000a8d8 + 0xa756))();
      return;
    }
    *(undefined1 *)(param_1 + 0x1cc) = *(undefined1 *)(param_1 + 0x1ea);
    iVar2 = DAT_0000a8dc;
    iVar3 = *(int *)(param_1 + 0x198);
    *(int *)(param_1 + 0x1c4) = iVar3;
    cVar1 = *(char *)(param_1 + iVar2);
    *(char *)(param_1 + 0x1ce) = cVar1;
    bVar4 = *(char *)(param_1 + 0x1ec) * cVar1;
    *(char *)(param_1 + DAT_0000a8e0) = *(char *)(param_1 + 0x1ec);
    *(byte *)(param_1 + DAT_0000a8e4) = bVar4;
    if (bVar4 < 8) {
      uVar5 = (uint)bVar4 * iVar3 + 7 >> 3;
    }
    else {
      uVar5 = (uint)(bVar4 >> 3) * iVar3;
    }
    *(uint *)(param_1 + 0x1c8) = uVar5;
    FUN_00009e08(param_1,*(int *)(param_1 + 0x1b0) + 1,param_2);
    if (((*(char *)(param_1 + DAT_0000a8d4) == '\0') || (5 < *(byte *)(param_1 + 0x1e8))) ||
       ((-1 < *(int *)(param_1 + 0x134) << 0x1e ||
        (FUN_0000b5dc(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1), *(int *)(param_1 + 0x1c4) != 0
        )))) {
      if (*(int *)(param_1 + 0x134) != 0) {
        FUN_0000b478(param_1);
      }
      if ((*(int *)(param_1 + 0x2f4) << 0x1d < 0) && (*(char *)(param_1 + 0x2fc) == '@')) {
        FUN_0000b3e0(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
      }
      FUN_0000cdc8(param_1,param_1 + 0x1c4);
      if (*(code **)(param_1 + 0x260) != (code *)0x0) {
        (**(code **)(param_1 + 0x260))
                  (param_1,*(undefined4 *)(param_1 + 0x1a8),*(undefined1 *)(param_1 + 0x1e8));
      }
    }
    else {
      FUN_0000cb54(param_1);
    }
  }
  return;
}

/* === FUN_0000a8e8 @ 0x0000a8e8 === */

void FUN_0000a8e8(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int local_24;
  
  if (param_1 != 0) {
    iVar1 = FUN_0000daa8();
    for (local_24 = 0; local_24 < iVar1; local_24 = local_24 + 1) {
      puVar3 = param_2;
      for (uVar4 = 0; uVar4 < *(uint *)(param_1 + 400); uVar4 = uVar4 + 1) {
        uVar2 = *puVar3;
        puVar3 = puVar3 + 1;
        FUN_0000a6f8(param_1,uVar2);
      }
    }
  }
  return;
}

/* === FUN_0000a92c @ 0x0000a92c === */

void FUN_0000a92c(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  char cVar1;
  __jmp_buf_tag *__env;
  int iVar2;
  ulong uVar3;
  __jmp_buf_tag *p_Var4;
  int iVar5;
  int iVar6;
  char acStack_64 [80];
  int local_14;
  
  iVar6 = DAT_0000aacc + 0xa938;
  local_14 = **(int **)(iVar6 + DAT_0000aad0);
  __env = (__jmp_buf_tag *)FUN_00009f24(1,param_6,param_5);
  uVar3 = DAT_0000aad4;
  p_Var4 = (__jmp_buf_tag *)0x0;
  if (__env == (__jmp_buf_tag *)0x0) goto LAB_0000aab6;
  __env[5].__saved_mask.__val[0] = DAT_0000aad4;
  __env[5].__saved_mask.__val[1] = uVar3;
  iVar2 = setjmp(__env);
  if (iVar2 != 0) {
    FUN_00009e2c(__env,__env[2].__saved_mask.__val[7]);
    __env[2].__saved_mask.__val[7] = 0;
    FUN_00009e4c(__env,param_7,param_5);
    p_Var4 = (__jmp_buf_tag *)0x0;
    goto LAB_0000aab6;
  }
  FUN_00009dec(__env,param_5,param_6,param_7);
  FUN_00009b98(__env,param_2,param_3,param_4);
  if (param_1 != (char *)0x0) {
    iVar2 = *(int *)(iVar6 + DAT_0000aad8);
    iVar5 = 0;
    while( true ) {
      if (param_1[iVar5] != *(char *)(iVar2 + iVar5)) {
        __env[1].__saved_mask.__val[0x1e] = __env[1].__saved_mask.__val[0x1e] | 0x20000;
      }
      if (*(char *)(iVar2 + iVar5) == '\0') break;
      iVar5 = iVar5 + 1;
    }
  }
  if (-1 < (int)(__env[1].__saved_mask.__val[0x1e] << 0xe)) goto LAB_0000aa70;
  if (param_1 == (char *)0x0) {
LAB_0000aa42:
    snprintf(acStack_64,0x50,(char *)(DAT_0000aae0 + 0xaa4e),*(undefined4 *)(iVar6 + DAT_0000aad8));
    FUN_00009c4c(__env,acStack_64);
    __env[1].__saved_mask.__val[0x1e] = 0;
    FUN_00009d40(__env,DAT_0000aae4 + 0xaa6e);
  }
  else {
    cVar1 = **(char **)(iVar6 + DAT_0000aad8);
    if (cVar1 != *param_1) {
LAB_0000aa2a:
      snprintf(acStack_64,0x50,(char *)(DAT_0000aadc + 0xaa34),param_1);
      FUN_00009c4c(__env,acStack_64);
      goto LAB_0000aa42;
    }
    if (cVar1 == '1') {
      if (param_1[2] != (*(char **)(iVar6 + DAT_0000aad8))[2]) goto LAB_0000aa2a;
    }
    else if ((cVar1 == '0') && ((byte)param_1[2] < 0x39)) goto LAB_0000aa2a;
  }
LAB_0000aa70:
  __env[2].__saved_mask.__val[8] = 0x2000;
  uVar3 = FUN_00009e9c(__env,__env[2].__saved_mask.__val[8]);
  __env[2].__saved_mask.__val[7] = uVar3;
  FUN_0000a050(__env,0,0,0);
  FUN_0000a118(__env,0,1,0,0);
  iVar2 = setjmp(__env);
  p_Var4 = __env;
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
LAB_0000aab6:
  if (local_14 == **(int **)(iVar6 + DAT_0000aad0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(p_Var4);
}

/* === FUN_0000aae8 @ 0x0000aae8 === */

void FUN_0000aae8(void)

{
  FUN_0000a92c();
  return;
}

/* === FUN_0000aafc @ 0x0000aafc === */

void FUN_0000aafc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_24;
  
  if (param_1 != 0) {
    if (-1 < *(int *)(param_1 + 300) << 0x1d) {
      FUN_00009d40(param_1,DAT_0000ac1c + 0xab1a);
    }
    if (param_2 != 0) {
      if (((*(uint *)(param_2 + 8) & 0x200) != 0) && ((*(uint *)(param_1 + 300) & 0x200) == 0)) {
        FUN_0000c3e4(param_1,param_2 + 0x3c);
      }
      iVar3 = DAT_0000ac20 + 0xab54;
      for (local_24 = 0; local_24 < *(int *)(param_2 + 0x30); local_24 = local_24 + 1) {
        iVar5 = local_24 * 0x10;
        piVar2 = (int *)(*(int *)(param_2 + 0x38) + iVar5);
        iVar1 = *piVar2;
        if (iVar1 < 1) {
          if (iVar1 == 0) {
            FUN_0000bfd8(param_1,piVar2[1],piVar2[2],0,0);
            *(undefined4 *)(*(int *)(param_2 + 0x38) + iVar5) = 0xfffffffe;
          }
          else if (iVar1 == -1) {
            FUN_0000bf64(param_1,piVar2[1],piVar2[2],0);
            goto LAB_0000ab96;
          }
        }
        else {
          FUN_00009c4c(param_1,iVar3);
LAB_0000ab96:
          *(undefined4 *)(*(int *)(param_2 + 0x38) + iVar5) = 0xfffffffd;
        }
      }
      if (*(int *)(param_2 + 0xc0) != 0) {
        for (uVar4 = *(uint *)(param_2 + 0xbc);
            uVar4 < *(uint *)(param_2 + 0xbc) + *(int *)(param_2 + 0xc0) * 0x14;
            uVar4 = uVar4 + 0x14) {
          iVar3 = FUN_00009724(param_1,uVar4);
          if ((((iVar3 != 1) && (*(byte *)(uVar4 + 0x10) != 0)) &&
              ((*(byte *)(uVar4 + 0x10) & 8) != 0)) &&
             (((iVar3 == 3 || ((int)((uint)*(byte *)(uVar4 + 3) << 0x1a) < 0)) ||
              (*(int *)(param_1 + 0x130) << 0xf < 0)))) {
            FUN_0000c3c0(param_1,uVar4,*(undefined4 *)(uVar4 + 8),*(undefined4 *)(uVar4 + 0xc));
          }
        }
      }
    }
    *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 8;
    FUN_0000ca40(param_1);
  }
  return;
}

/* === FUN_0000ac24 @ 0x0000ac24 === */

void FUN_0000ac24(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  if (((param_2 != (undefined4 *)0x0) && (param_1 != 0)) &&
     ((*(uint *)(param_1 + 300) & 0x400) == 0)) {
    FUN_0000bcac(param_1);
    if ((*(int *)(param_1 + 300) << 0x13 < 0) && (*(int *)(param_1 + 0x2f4) != 0)) {
      FUN_00009c4c(param_1,DAT_0000ade0 + 0xac64);
      *(undefined4 *)(param_1 + 0x2f4) = 0;
    }
    FUN_0000d70c(param_1,*param_2,param_2[1],*(undefined1 *)(param_2 + 6),
                 *(undefined1 *)((int)param_2 + 0x19),*(undefined1 *)((int)param_2 + 0x1a),
                 *(undefined1 *)((int)param_2 + 0x1b),*(undefined1 *)(param_2 + 7));
    if ((int)(param_2[2] << 0x1f) < 0) {
      uVar5 = FUN_0000e158(param_2[10]);
      uVar2 = (undefined4)((ulonglong)uVar5 >> 0x20);
      FUN_0000c9e8(param_1,uVar2,(int)uVar5,uVar2);
    }
    if ((int)(param_2[2] << 0x14) < 0) {
      FUN_0000c9ac(param_1,*(undefined1 *)(param_2 + 0xb));
    }
    if ((int)(param_2[2] << 0x13) < 0) {
      FUN_0000c200(param_1,param_2[0x31],0,param_2[0x32],param_2[0x33]);
    }
    if ((int)(param_2[2] << 0x1e) < 0) {
      FUN_0000c900(param_1,param_2 + 0x11,*(undefined1 *)((int)param_2 + 0x19));
    }
    if ((int)(param_2[2] << 0x1d) < 0) {
      uVar5 = FUN_0000e158(param_2[0x20]);
      FUN_0000e158(param_2[0x21]);
      FUN_0000e158(param_2[0x22]);
      FUN_0000e158(param_2[0x23]);
      FUN_0000e158(param_2[0x24]);
      FUN_0000e158(param_2[0x25]);
      FUN_0000e158(param_2[0x26]);
      FUN_0000e158(param_2[0x27]);
      FUN_0000c770(param_1,extraout_r1,(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    }
    if (param_2[0x30] != 0) {
      iVar3 = DAT_0000ade4 + 0xad72;
      for (uVar4 = param_2[0x2f]; uVar4 < (uint)(param_2[0x2f] + param_2[0x30] * 0x14);
          uVar4 = uVar4 + 0x14) {
        iVar1 = FUN_00009724(param_1,uVar4);
        if (((iVar1 != 1) && (*(byte *)(uVar4 + 0x10) != 0)) &&
           (((*(byte *)(uVar4 + 0x10) & 6) == 0 &&
            (((iVar1 == 3 || ((int)((uint)*(byte *)(uVar4 + 3) << 0x1a) < 0)) ||
             (*(int *)(param_1 + 0x130) << 0xf < 0)))))) {
          if (*(int *)(uVar4 + 0xc) == 0) {
            FUN_00009c4c(param_1,iVar3);
          }
          FUN_0000c3c0(param_1,uVar4,*(undefined4 *)(uVar4 + 8),*(undefined4 *)(uVar4 + 0xc));
        }
      }
    }
    *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 0x400;
  }
  return;
}

/* === FUN_0000ade8 @ 0x0000ade8 === */

void FUN_0000ade8(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int local_24;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    FUN_0000ac24(param_1,param_2);
    if (*(int *)(param_2 + 8) << 0x1c < 0) {
      FUN_0000c300(param_1,*(undefined4 *)(param_2 + 0x10),*(undefined2 *)(param_2 + 0x14));
    }
    else if (*(char *)(param_2 + 0x19) == '\x03') {
      FUN_00009d40(param_1,DAT_0000b024 + 0xae20);
    }
    if (*(int *)(param_2 + 8) << 0x1b < 0) {
      if ((*(int *)(param_1 + 0x134) << 0xc < 0) && (iVar3 = 0, *(char *)(param_2 + 0x19) == '\x03')
         ) {
        for (; iVar3 < (int)(uint)*(ushort *)(param_2 + 0x16); iVar3 = iVar3 + 1) {
          pbVar2 = (byte *)(*(int *)(param_2 + 0x4c) + iVar3);
          *pbVar2 = ~*pbVar2;
        }
      }
      FUN_0000c694(param_1,*(undefined4 *)(param_2 + 0x4c),param_2 + 0x50,
                   *(undefined2 *)(param_2 + 0x16),*(undefined1 *)(param_2 + 0x19));
    }
    if (*(int *)(param_2 + 8) << 0x1a < 0) {
      FUN_0000c5bc(param_1,param_2 + 0x5a,*(undefined1 *)(param_2 + 0x19));
    }
    if (*(int *)(param_2 + 8) << 0x19 < 0) {
      FUN_0000c088(param_1,*(undefined4 *)(param_2 + 0x7c),*(undefined2 *)(param_2 + 0x14));
    }
    if (*(int *)(param_2 + 8) << 0x17 < 0) {
      FUN_0000c550(param_1,*(undefined4 *)(param_2 + 100),*(undefined4 *)(param_2 + 0x68),
                   *(undefined1 *)(param_2 + 0x6c));
    }
    if (*(int *)(param_2 + 8) << 0x15 < 0) {
      FUN_0000be2c(param_1,*(undefined4 *)(param_2 + 0xa0),*(undefined4 *)(param_2 + 0xa4),
                   *(undefined4 *)(param_2 + 0xa8),*(undefined1 *)(param_2 + 0xb4),
                   *(undefined1 *)(param_2 + 0xb5),*(undefined4 *)(param_2 + 0xac),
                   *(undefined4 *)(param_2 + 0xb0));
    }
    if (*(int *)(param_2 + 8) << 0x11 < 0) {
      FUN_0000c4c8(param_1,*(undefined1 *)(param_2 + 0xdc),*(undefined4 *)(param_2 + 0xe0),
                   *(undefined4 *)(param_2 + 0xe4),*(undefined4 *)(param_2 + 0xe8),
                   *(undefined4 *)(param_2 + 0xec));
    }
    if (*(int *)(param_2 + 8) << 0x18 < 0) {
      FUN_0000c45c(param_1,*(undefined4 *)(param_2 + 0x70),*(undefined4 *)(param_2 + 0x74),
                   *(undefined1 *)(param_2 + 0x78));
    }
    if ((*(uint *)(param_2 + 8) & 0x200) != 0) {
      FUN_0000c3e4(param_1,param_2 + 0x3c);
      *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 0x200;
    }
    if (*(int *)(param_2 + 8) << 0x12 < 0) {
      for (iVar3 = 0; iVar3 < *(int *)(param_2 + 0xd8); iVar3 = iVar3 + 1) {
        FUN_0000c0f4(param_1,*(int *)(param_2 + 0xd4) + iVar3 * 0x10);
      }
    }
    iVar3 = DAT_0000b028 + 0xaf54;
    for (local_24 = 0; local_24 < *(int *)(param_2 + 0x30); local_24 = local_24 + 1) {
      iVar6 = local_24 * 0x10;
      piVar4 = (int *)(*(int *)(param_2 + 0x38) + iVar6);
      iVar1 = *piVar4;
      if (iVar1 < 1) {
        if (iVar1 == 0) {
          FUN_0000bfd8(param_1,piVar4[1],piVar4[2],0,0);
          *(undefined4 *)(*(int *)(param_2 + 0x38) + iVar6) = 0xfffffffe;
        }
        else if (iVar1 == -1) {
          FUN_0000bf64(param_1,piVar4[1],piVar4[2],0);
          goto LAB_0000afae;
        }
      }
      else {
        FUN_00009c4c(param_1,iVar3);
LAB_0000afae:
        *(undefined4 *)(*(int *)(param_2 + 0x38) + iVar6) = 0xfffffffd;
      }
    }
    if (*(int *)(param_2 + 0xc0) != 0) {
      for (uVar5 = *(uint *)(param_2 + 0xbc);
          uVar5 < *(uint *)(param_2 + 0xbc) + *(int *)(param_2 + 0xc0) * 0x14; uVar5 = uVar5 + 0x14)
      {
        iVar3 = FUN_00009724(param_1,uVar5);
        if ((((iVar3 != 1) && (*(byte *)(uVar5 + 0x10) != 0)) &&
            ((*(byte *)(uVar5 + 0x10) & 6) == 2)) &&
           (((iVar3 == 3 || ((int)((uint)*(byte *)(uVar5 + 3) << 0x1a) < 0)) ||
            (*(int *)(param_1 + 0x130) << 0xf < 0)))) {
          FUN_0000c3c0(param_1,uVar5,*(undefined4 *)(uVar5 + 8),*(undefined4 *)(uVar5 + 0xc));
        }
      }
    }
  }
  return;
}

/* === FUN_0000b02c @ 0x0000b02c === */

void FUN_0000b02c(uint *param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  
  if ((undefined4 *)(param_1[2] & DAT_0000b120) != &DAT_00010800) {
    return;
  }
  puVar4 = param_2;
  if (param_3 == 2) {
    uVar6 = *param_1;
    uVar3 = 0;
    uVar1 = 6;
    for (uVar5 = 0; uVar2 = (undefined1)uVar3, uVar5 < uVar6; uVar5 = uVar5 + 1) {
      uVar3 = uVar3 | ((byte)param_2[uVar5] & 3) << (uVar1 & 0xff);
      if (uVar1 == 0) {
        *puVar4 = (char)uVar3;
        uVar1 = 6;
        puVar4 = puVar4 + 1;
        uVar3 = 0;
      }
      else {
        uVar1 = uVar1 - 2;
      }
    }
    if (uVar1 == 6) goto LAB_0000b0f6;
  }
  else if (param_3 == 4) {
    uVar6 = *param_1;
    uVar3 = 0;
    uVar1 = 4;
    for (uVar5 = 0; uVar2 = (undefined1)uVar3, uVar5 < uVar6; uVar5 = uVar5 + 1) {
      uVar3 = uVar3 | ((byte)param_2[uVar5] & 0xf) << (uVar1 & 0xff);
      if (uVar1 == 0) {
        *puVar4 = (char)uVar3;
        uVar1 = 4;
        puVar4 = puVar4 + 1;
        uVar3 = 0;
      }
      else {
        uVar1 = uVar1 - 4;
      }
    }
    if (uVar1 == 4) goto LAB_0000b0f6;
  }
  else {
    if (param_3 != 1) goto LAB_0000b0f6;
    uVar6 = *param_1;
    uVar3 = 0;
    uVar1 = 0x80;
    for (uVar5 = 0; uVar2 = (undefined1)uVar3, uVar5 < uVar6; uVar5 = uVar5 + 1) {
      if (param_2[uVar5] != '\0') {
        uVar3 = uVar3 | uVar1;
      }
      if (uVar1 < 2) {
        *puVar4 = (char)uVar3;
        uVar1 = 0x80;
        puVar4 = puVar4 + 1;
        uVar3 = 0;
      }
      else {
        uVar1 = (int)uVar1 >> 1;
      }
    }
    if (uVar1 == 0x80) goto LAB_0000b0f6;
  }
  *puVar4 = uVar2;
LAB_0000b0f6:
  *(char *)((int)param_1 + 9) = (char)param_3;
  uVar1 = param_3 * (uint)*(byte *)((int)param_1 + 10);
  *(char *)((int)param_1 + 0xb) = (char)uVar1;
  if ((uVar1 & 0xff) < 8) {
    uVar1 = (uVar1 & 0xff) * *param_1 + 7 >> 3;
  }
  else {
    uVar1 = ((uVar1 & 0xff) >> 3) * *param_1;
  }
  param_1[1] = uVar1;
  return;
}

/* === FUN_0000b124 @ 0x0000b124 === */

void FUN_0000b124(int *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int extraout_r1;
  int extraout_r1_00;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  byte bVar12;
  uint local_38 [4];
  uint local_28 [5];
  
  uVar5 = (uint)*(byte *)(param_1 + 2);
  if (uVar5 != 3) {
    local_28[0] = (uint)*(byte *)((int)param_1 + 9);
    if ((int)(uVar5 << 0x1e) < 0) {
      bVar1 = *param_3;
      local_38[1] = (uint)param_3[1];
      local_28[1] = local_28[0] - local_38[1];
      local_38[2] = (uint)param_3[2];
      local_28[2] = local_28[0] - local_38[2];
      iVar10 = 3;
    }
    else {
      bVar1 = param_3[3];
      iVar10 = 1;
    }
    local_38[0] = (uint)bVar1;
    local_28[0] = local_28[0] - local_38[0];
    iVar11 = iVar10;
    if ((int)(uVar5 << 0x1d) < 0) {
      bVar1 = param_3[4];
      iVar11 = iVar10 + 1;
      local_28[iVar10] = (uint)*(byte *)((int)param_1 + 9) - (uint)bVar1;
      local_38[iVar10] = (uint)bVar1;
    }
    bVar1 = *(byte *)((int)param_1 + 9);
    if (bVar1 < 8) {
      uVar5 = param_1[1];
      if (((param_3[3] != 1) || (bVar4 = 0x55, bVar1 != 2)) &&
         ((bVar1 != 4 || (bVar4 = 0x11, param_3[3] != 3)))) {
        bVar4 = 0xff;
      }
      for (uVar7 = 0; uVar7 < uVar5; uVar7 = uVar7 + 1) {
        bVar1 = *param_2;
        *param_2 = 0;
        uVar6 = -local_28[0];
        for (uVar9 = local_28[0]; (int)-local_38[0] < (int)uVar9; uVar9 = uVar9 + -local_38[0]) {
          if ((int)uVar9 < 1) {
            bVar12 = (byte)((int)(uint)bVar1 >> (uVar6 & 0xff)) & bVar4;
          }
          else {
            bVar12 = bVar1 << (uVar9 & 0xff);
          }
          *param_2 = *param_2 | bVar12;
          uVar6 = uVar6 + local_38[0];
        }
        param_2 = param_2 + 1;
      }
    }
    else {
      iVar10 = *param_1;
      if (bVar1 == 8) {
        for (uVar5 = 0; uVar5 < (uint)(iVar11 * iVar10); uVar5 = uVar5 + 1) {
          FUN_0000de3c(uVar5,iVar11);
          bVar1 = *param_2;
          *param_2 = 0;
          uVar9 = local_28[extraout_r1];
          uVar6 = local_38[extraout_r1];
          iVar2 = -uVar6;
          uVar7 = -uVar9;
          for (; iVar2 < (int)uVar9; uVar9 = uVar9 + iVar2) {
            if ((int)uVar9 < 1) {
              bVar4 = (byte)((int)(uint)bVar1 >> (uVar7 & 0xff));
            }
            else {
              bVar4 = bVar1 << (uVar9 & 0xff);
            }
            *param_2 = *param_2 | bVar4;
            uVar7 = uVar7 + uVar6;
          }
          param_2 = param_2 + 1;
        }
      }
      else {
        for (uVar5 = 0; uVar5 < (uint)(iVar11 * iVar10); uVar5 = uVar5 + 1) {
          FUN_0000de3c(uVar5,iVar11);
          iVar8 = (uint)*param_2 * 0x100 + (uint)param_2[1];
          uVar6 = local_28[extraout_r1_00];
          uVar9 = 0;
          iVar2 = -local_38[extraout_r1_00];
          uVar7 = -uVar6;
          for (; iVar2 < (int)uVar6; uVar6 = uVar6 + iVar2) {
            if ((int)uVar6 < 1) {
              uVar3 = iVar8 >> (uVar7 & 0xff);
            }
            else {
              uVar3 = iVar8 << (uVar6 & 0xff);
            }
            uVar9 = uVar9 | uVar3 & 0xffff;
            uVar7 = uVar7 + local_38[extraout_r1_00];
          }
          *param_2 = (byte)(uVar9 >> 8);
          param_2[1] = (byte)uVar9;
          param_2 = param_2 + 2;
        }
      }
    }
  }
  return;
}

/* === FUN_0000b2cc @ 0x0000b2cc === */

void FUN_0000b2cc(uint *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((char)param_1[2] == '\x06') {
    uVar5 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      for (uVar4 = 0; uVar4 < uVar5; uVar4 = uVar4 + 1) {
        uVar1 = *param_2;
        *param_2 = param_2[1];
        uVar2 = param_2[3];
        param_2[1] = param_2[2];
        param_2[3] = uVar1;
        param_2[2] = uVar2;
        param_2 = param_2 + 4;
      }
    }
    else {
      for (uVar4 = 0; uVar4 < uVar5; uVar4 = uVar4 + 1) {
        uVar1 = *param_2;
        uVar2 = param_2[1];
        *param_2 = param_2[2];
        param_2[1] = param_2[3];
        param_2[2] = param_2[4];
        param_2[3] = param_2[5];
        uVar3 = param_2[6];
        param_2[6] = uVar1;
        param_2[4] = uVar3;
        uVar1 = param_2[7];
        param_2[7] = uVar2;
        param_2[5] = uVar1;
        param_2 = param_2 + 8;
      }
    }
  }
  else if ((char)param_1[2] == '\x04') {
    uVar5 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      for (uVar4 = 0; uVar4 < uVar5; uVar4 = uVar4 + 1) {
        uVar1 = param_2[1];
        param_2[1] = *param_2;
        *param_2 = uVar1;
        param_2 = param_2 + 2;
      }
    }
    else {
      for (uVar4 = 0; uVar4 < uVar5; uVar4 = uVar4 + 1) {
        uVar1 = *param_2;
        *param_2 = param_2[2];
        uVar2 = param_2[3];
        param_2[2] = uVar1;
        param_2[3] = param_2[1];
        param_2[1] = uVar2;
        param_2 = param_2 + 4;
      }
    }
  }
  return;
}

/* === FUN_0000b368 @ 0x0000b368 === */

void FUN_0000b368(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if ((char)param_1[2] == '\x06') {
    uVar2 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1) {
        *(byte *)(param_2 + 3) = ~*(byte *)(param_2 + 3);
        param_2 = param_2 + 4;
      }
    }
    else {
      for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1) {
        *(byte *)(param_2 + 6) = ~*(byte *)(param_2 + 6);
        *(byte *)(param_2 + 7) = ~*(byte *)(param_2 + 7);
        param_2 = param_2 + 8;
      }
    }
  }
  else if ((char)param_1[2] == '\x04') {
    uVar2 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1) {
        *(byte *)(param_2 + 1) = ~*(byte *)(param_2 + 1);
        param_2 = param_2 + 2;
      }
    }
    else {
      for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1) {
        *(byte *)(param_2 + 2) = ~*(byte *)(param_2 + 2);
        *(byte *)(param_2 + 3) = ~*(byte *)(param_2 + 3);
        param_2 = param_2 + 4;
      }
    }
  }
  return;
}

/* === FUN_0000b3e0 @ 0x0000b3e0 === */

void FUN_0000b3e0(uint *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = (uint)(byte)param_1[2];
  if ((int)(uVar3 << 0x1e) < 0) {
    uVar4 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      iVar2 = 3;
      if (uVar3 != 2) {
        if (uVar3 != 6) {
          return;
        }
        iVar2 = 4;
      }
      for (uVar3 = 0; uVar3 < uVar4; uVar3 = uVar3 + 1) {
        *param_2 = *param_2 - param_2[1];
        param_2[2] = param_2[2] - param_2[1];
        param_2 = param_2 + iVar2;
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      iVar2 = 6;
      if (uVar3 != 2) {
        if (uVar3 != 6) {
          return;
        }
        iVar2 = 8;
      }
      for (uVar3 = 0; uVar3 < uVar4; uVar3 = uVar3 + 1) {
        iVar5 = (uint)CONCAT11(*param_2,param_2[1]) - (uint)CONCAT11(param_2[2],param_2[3]);
        *param_2 = (char)((uint)iVar5 >> 8);
        iVar1 = (uint)CONCAT11(param_2[4],param_2[5]) - (uint)CONCAT11(param_2[2],param_2[3]);
        param_2[1] = (char)iVar5;
        param_2[4] = (char)((uint)iVar1 >> 8);
        param_2[5] = (char)iVar1;
        param_2 = param_2 + iVar2;
      }
    }
  }
  return;
}

/* === FUN_0000b478 @ 0x0000b478 === */

void FUN_0000b478(int param_1)

{
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x134) << 0xb < 0) && (*(code **)(param_1 + 0x120) != (code *)0x0)) {
      (**(code **)(param_1 + 0x120))(param_1,param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
    }
    if (*(int *)(param_1 + 0x134) << 0x10 < 0) {
      FUN_0000db98(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1,*(undefined4 *)(param_1 + 0x130));
    }
    if (*(int *)(param_1 + 0x134) << 0xf < 0) {
      FUN_0000db54(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
    }
    if (*(int *)(param_1 + 0x134) << 0x1d < 0) {
      FUN_0000b02c(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1,
                   *(undefined1 *)(param_1 + DAT_0000b5ac));
    }
    if (*(int *)(param_1 + 0x134) << 0x1b < 0) {
      FUN_0000db2c(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
    }
    if (*(int *)(param_1 + 0x134) << 0x1c < 0) {
      FUN_0000b124(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1,param_1 + DAT_0000b5b0);
    }
    if (*(int *)(param_1 + 0x134) << 0xe < 0) {
      FUN_0000b2cc(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
    }
    if (*(int *)(param_1 + 0x134) << 0xc < 0) {
      FUN_0000b368(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
    }
    if (*(int *)(param_1 + 0x134) << 0x1f < 0) {
      FUN_0000dd04(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
    }
    if (*(int *)(param_1 + 0x134) << 0x1a < 0) {
      FUN_0000dacc(param_1 + 0x1c4,*(int *)(param_1 + 0x1b0) + 1);
    }
  }
  return;
}

/* === FUN_0000b5b4 @ 0x0000b5b4 === */

void FUN_0000b5b4(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 0x18);
  param_1[1] = (char)((uint)param_2 >> 0x10);
  param_1[2] = (char)((uint)param_2 >> 8);
  param_1[3] = (char)param_2;
  return;
}

/* === FUN_0000b5c4 @ 0x0000b5c4 === */

void FUN_0000b5c4(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 0x18);
  param_1[1] = (char)((uint)param_2 >> 0x10);
  param_1[2] = (char)((uint)param_2 >> 8);
  param_1[3] = (char)param_2;
  return;
}

/* === FUN_0000b5d4 @ 0x0000b5d4 === */

void FUN_0000b5d4(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 8);
  param_1[1] = (char)param_2;
  return;
}

/* === FUN_0000b5dc @ 0x0000b5dc === */

void FUN_0000b5dc(uint *param_1,undefined1 *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 *local_64;
  int local_50 [4];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  uint local_34 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_34[0] = *(uint *)(DAT_0000b7a4 + 0xb5e8);
  local_34[1] = *(undefined4 *)(DAT_0000b7a4 + 0xb5ec);
  local_34[2] = *(undefined4 *)(DAT_0000b7a4 + 0xb5f0);
  local_34[3] = *(undefined4 *)(DAT_0000b7a4 + 0xb5f4);
  uStack_24 = *(undefined4 *)(DAT_0000b7a4 + 0xb5f8);
  uStack_20 = *(undefined4 *)(DAT_0000b7a4 + 0xb5fc);
  local_1c = *(undefined4 *)(DAT_0000b7a4 + 0xb600);
  local_50[0] = *(int *)(DAT_0000b7a4 + 0xb604);
  local_50[1] = *(undefined4 *)(DAT_0000b7a4 + 0xb608);
  local_50[2] = *(undefined4 *)(DAT_0000b7a4 + 0xb60c);
  local_50[3] = *(undefined4 *)(DAT_0000b7a4 + 0xb610);
  uStack_40 = *(undefined4 *)(DAT_0000b7a4 + 0xb614);
  uStack_3c = *(undefined4 *)(DAT_0000b7a4 + 0xb618);
  local_38 = *(undefined4 *)(DAT_0000b7a4 + 0xb61c);
  if (5 < param_3) {
    return;
  }
  bVar1 = *(byte *)((int)param_1 + 0xb);
  puVar6 = param_2;
  if (bVar1 == 2) {
    uVar4 = *param_1;
    uVar5 = 6;
    uVar7 = 0;
    for (uVar2 = local_34[param_3]; uVar3 = (undefined1)uVar7, uVar2 < uVar4;
        uVar2 = uVar2 + local_50[param_3]) {
      uVar7 = uVar7 | ((int)(uint)(byte)param_2[uVar2 >> 2] >> ((~uVar2 & 3) << 1) & 3U) <<
                      (uVar5 & 0xff);
      if (uVar5 == 0) {
        *puVar6 = (char)uVar7;
        uVar5 = 6;
        puVar6 = puVar6 + 1;
        uVar7 = 0;
      }
      else {
        uVar5 = uVar5 - 2;
      }
    }
    if (uVar5 == 6) goto LAB_0000b770;
  }
  else {
    if (bVar1 == 4) {
      uVar4 = *param_1;
      uVar5 = 4;
      uVar7 = 0;
      for (uVar2 = local_34[param_3]; uVar2 < uVar4; uVar2 = uVar2 + local_50[param_3]) {
        uVar7 = uVar7 | ((int)(uint)(byte)param_2[uVar2 >> 1] >> ((uVar2 & 1) == 0) * '\x04' & 0xfU)
                        << (uVar5 & 0xff);
        if (uVar5 == 0) {
          *puVar6 = (char)uVar7;
          uVar5 = 4;
          puVar6 = puVar6 + 1;
          uVar7 = 0;
        }
        else {
          uVar5 = uVar5 - 4;
        }
      }
      if (uVar5 != 4) {
        *puVar6 = (char)uVar7;
      }
      goto LAB_0000b770;
    }
    uVar4 = *param_1;
    if (bVar1 != 1) {
      uVar2 = (uint)(bVar1 >> 3);
      local_64 = param_2;
      for (uVar7 = local_34[param_3]; uVar7 < uVar4; uVar7 = uVar7 + local_50[param_3]) {
        if (local_64 != param_2 + uVar7 * uVar2) {
          memcpy(local_64,param_2 + uVar7 * uVar2,uVar2);
        }
        local_64 = local_64 + uVar2;
      }
      goto LAB_0000b770;
    }
    uVar7 = 0;
    uVar5 = 7;
    for (uVar2 = local_34[param_3]; uVar3 = (undefined1)uVar7, uVar2 < uVar4;
        uVar2 = uVar2 + local_50[param_3]) {
      uVar7 = uVar7 | ((int)(uint)(byte)param_2[uVar2 >> 3] >> (~uVar2 & 7) & 1U) << (uVar5 & 0xff);
      if (uVar5 == 0) {
        *puVar6 = (char)uVar7;
        uVar5 = 7;
        puVar6 = puVar6 + 1;
        uVar7 = 0;
      }
      else {
        uVar5 = uVar5 - 1;
      }
    }
    if (uVar5 == 7) goto LAB_0000b770;
  }
  *puVar6 = uVar3;
LAB_0000b770:
  uVar4 = FUN_0000dd90(((*param_1 - 1) + local_50[param_3]) - local_34[param_3]);
  bVar1 = *(byte *)((int)param_1 + 0xb);
  *param_1 = uVar4;
  if (bVar1 < 8) {
    uVar4 = uVar4 * bVar1 + 7 >> 3;
  }
  else {
    uVar4 = uVar4 * (bVar1 >> 3);
  }
  param_1[1] = uVar4;
  return;
}

/* === FUN_0000b7a8 @ 0x0000b7a8 === */

void FUN_0000b7a8(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(byte *)(param_1 + 0x1ec) * (uint)*(byte *)(param_1 + DAT_0000b8dc);
  if (uVar4 < 8) {
    uVar4 = uVar4 * *(int *)(param_1 + 0x18c) + 7 >> 3;
  }
  else {
    uVar4 = (uVar4 >> 3) * *(int *)(param_1 + 0x18c);
  }
  puVar2 = (undefined1 *)FUN_00009e9c(param_1,uVar4 + 1);
  *(undefined1 **)(param_1 + 0x1b0) = puVar2;
  *puVar2 = 0;
  if ((int)((uint)*(byte *)(param_1 + 0x1e9) << 0x1b) < 0) {
    puVar2 = (undefined1 *)FUN_00009e9c(param_1,*(int *)(param_1 + 0x19c) + 1);
    *(undefined1 **)(param_1 + 0x1b4) = puVar2;
    *puVar2 = 1;
  }
  iVar1 = DAT_0000b8e0;
  if ((*(byte *)(param_1 + DAT_0000b8e0) & 0xe0) != 0) {
    uVar3 = FUN_00009f08(param_1,uVar4 + 1);
    *(undefined4 *)(param_1 + 0x1ac) = uVar3;
    if ((int)((uint)*(byte *)(param_1 + iVar1) << 0x1a) < 0) {
      puVar2 = (undefined1 *)FUN_00009e9c(param_1,*(int *)(param_1 + 0x19c) + 1);
      *(undefined1 **)(param_1 + 0x1b8) = puVar2;
      *puVar2 = 2;
    }
    if ((int)((uint)*(byte *)(param_1 + DAT_0000b8e0) << 0x19) < 0) {
      puVar2 = (undefined1 *)FUN_00009e9c(param_1,*(int *)(param_1 + 0x19c) + 1);
      *(undefined1 **)(param_1 + 0x1bc) = puVar2;
      *puVar2 = 3;
    }
    if (0x7f < *(byte *)(param_1 + DAT_0000b8e0)) {
      puVar2 = (undefined1 *)FUN_00009e9c(param_1,*(int *)(param_1 + 0x19c) + 1);
      *(undefined1 **)(param_1 + 0x1c0) = puVar2;
      *puVar2 = 4;
    }
  }
  if ((*(char *)(param_1 + DAT_0000b8e4) == '\0') || (*(int *)(param_1 + 0x134) << 0x1e < 0)) {
    *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(param_1 + 400);
    uVar4 = *(uint *)(param_1 + 0x18c);
  }
  else {
    *(uint *)(param_1 + 0x194) = *(int *)(param_1 + 400) + 7U >> 3;
    uVar4 = *(int *)(param_1 + 0x18c) + 7U >> 3;
  }
  *(uint *)(param_1 + 0x198) = uVar4;
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
  return;
}

/* === FUN_0000b8e8 @ 0x0000b8e8 === */

void FUN_0000b8e8(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char acStack_50 [52];
  int local_1c;
  
  iVar7 = DAT_0000babc + 0xb8f4;
  local_1c = **(int **)(iVar7 + DAT_0000bac0);
  param_5[2] = 0;
  param_5[3] = 0;
  param_5[4] = 0;
  *param_5 = 0;
  param_5[1] = 0;
  if (param_4 == -1) {
    param_5[1] = param_3;
    *param_5 = param_2;
  }
  else {
    if (2 < param_4) {
      snprintf(acStack_50,0x32,(char *)(DAT_0000bac4 + 0xb92a));
      FUN_00009c4c(param_1,acStack_50);
    }
    *(int *)(param_1 + 0x13c) = param_3;
    *(undefined4 *)(param_1 + 0x138) = param_2;
    *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
    *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
    iVar8 = DAT_0000bac8 + 0xb956;
    do {
      iVar1 = deflate(param_1 + 0x138,0);
      if (iVar1 != 0) {
        iVar1 = *(int *)(param_1 + 0x150);
        if (*(int *)(param_1 + 0x150) == 0) {
          iVar1 = iVar8;
        }
        FUN_00009d40(param_1,iVar1);
      }
      if (*(int *)(param_1 + 0x148) == 0) {
        iVar1 = param_5[3];
        if (iVar1 <= (int)param_5[2]) {
          pvVar5 = (void *)param_5[4];
          iVar4 = param_5[2] + 4;
          param_5[3] = iVar4;
          iVar4 = iVar4 * 4;
          if (pvVar5 == (void *)0x0) {
            uVar3 = FUN_00009e9c(param_1,iVar4);
            param_5[4] = uVar3;
          }
          else {
            pvVar2 = (void *)FUN_00009e9c(param_1,iVar4);
            param_5[4] = pvVar2;
            memcpy(pvVar2,pvVar5,iVar1 << 2);
            FUN_00009e2c(param_1,pvVar5);
          }
        }
        iVar4 = param_5[2];
        iVar1 = param_5[4];
        uVar3 = FUN_00009e9c(param_1,*(undefined4 *)(param_1 + 0x174));
        *(undefined4 *)(iVar1 + iVar4 * 4) = uVar3;
        memcpy(*(void **)(param_5[2] * 4 + param_5[4]),*(void **)(param_1 + 0x170),
               *(size_t *)(param_1 + 0x174));
        param_5[2] = param_5[2] + 1;
        *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
        *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
      }
    } while (*(int *)(param_1 + 0x13c) != 0);
    iVar8 = DAT_0000bacc + 0xb9f6;
    while( true ) {
      while (iVar1 = deflate(param_1 + 0x138,4), iVar1 == 0) {
        if (*(int *)(param_1 + 0x148) == 0) {
          iVar1 = param_5[3];
          if (iVar1 <= (int)param_5[2]) {
            pvVar5 = (void *)param_5[4];
            iVar4 = param_5[2] + 4;
            param_5[3] = iVar4;
            iVar4 = iVar4 * 4;
            if (pvVar5 == (void *)0x0) {
              uVar3 = FUN_00009e9c(param_1,iVar4);
              param_5[4] = uVar3;
            }
            else {
              pvVar2 = (void *)FUN_00009e9c(param_1,iVar4);
              param_5[4] = pvVar2;
              memcpy(pvVar2,pvVar5,iVar1 << 2);
              FUN_00009e2c(param_1,pvVar5);
            }
          }
          iVar4 = param_5[2];
          iVar1 = param_5[4];
          uVar3 = FUN_00009e9c(param_1,*(undefined4 *)(param_1 + 0x174));
          *(undefined4 *)(iVar1 + iVar4 * 4) = uVar3;
          memcpy(*(void **)(param_5[2] * 4 + param_5[4]),*(void **)(param_1 + 0x170),
                 *(size_t *)(param_1 + 0x174));
          param_5[2] = param_5[2] + 1;
          *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
          *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
        }
      }
      if (iVar1 == 1) break;
      iVar1 = *(int *)(param_1 + 0x150);
      if (*(int *)(param_1 + 0x150) == 0) {
        iVar1 = iVar8;
      }
      FUN_00009d40(param_1,iVar1);
    }
    uVar6 = *(uint *)(param_1 + 0x174);
    param_3 = uVar6 * param_5[2];
    if (*(uint *)(param_1 + 0x148) < uVar6) {
      param_3 = param_3 + (uVar6 - *(uint *)(param_1 + 0x148));
    }
  }
  if (local_1c == **(int **)(iVar7 + DAT_0000bac0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(param_3);
}

/* === FUN_0000bad0 @ 0x0000bad0 === */

void FUN_0000bad0(undefined4 param_1,char *param_2,int *param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  size_t sVar4;
  int iVar5;
  byte bVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  size_t sVar11;
  char acStack_44 [40];
  int local_1c;
  
  iVar8 = DAT_0000bc60 + 0xbadc;
  local_1c = **(int **)(iVar8 + DAT_0000bc64);
  *param_3 = 0;
  if (param_2 == (char *)0x0) {
LAB_0000bb00:
    iVar5 = DAT_0000bc68 + 0xbb06;
  }
  else {
    sVar4 = strlen(param_2);
    if (sVar4 == 0) goto LAB_0000bb00;
    iVar5 = FUN_00009ee4(param_1,sVar4 + 2);
    *param_3 = iVar5;
    if (iVar5 != 0) {
      iVar9 = 0;
      pcVar10 = (char *)(DAT_0000bc6c + 0xbb28);
      while( true ) {
        bVar6 = param_2[iVar9];
        if (bVar6 == 0) break;
        if (((byte)(bVar6 + 0x81) < 0x22) || (bVar6 < 0x20)) {
          snprintf(acStack_44,0x28,pcVar10);
          FUN_00009c4c(param_1,acStack_44);
          bVar6 = 0x20;
        }
        *(byte *)(iVar5 + iVar9) = bVar6;
        iVar9 = iVar9 + 1;
      }
      *(undefined1 *)(iVar5 + iVar9) = 0;
      pcVar10 = (char *)(*param_3 + (sVar4 - 1));
      sVar11 = sVar4;
      if (*pcVar10 == ' ') {
        FUN_00009c4c(param_1,DAT_0000bc74 + 0xbb84);
        for (; pcVar10[sVar11 - sVar4] == ' '; sVar11 = sVar11 - 1) {
          pcVar10[sVar11 - sVar4] = '\0';
        }
      }
      pcVar10 = (char *)*param_3;
      if (*pcVar10 == ' ') {
        FUN_00009c4c(param_1,DAT_0000bc78 + 0xbba8);
        iVar5 = 0;
        do {
          iVar9 = iVar5;
          iVar5 = iVar9 + 1;
        } while (pcVar10[iVar9] == ' ');
        pcVar10 = pcVar10 + iVar9;
        sVar11 = sVar11 - iVar9;
      }
      pcVar7 = (char *)*param_3;
      bVar3 = false;
      bVar2 = false;
      while( true ) {
        cVar1 = *pcVar10;
        if (cVar1 == '\0') break;
        if (bVar2) {
          if (cVar1 != ' ') goto LAB_0000bbf0;
          sVar11 = sVar11 - 1;
          bVar3 = true;
        }
        else if (cVar1 != ' ') {
LAB_0000bbf0:
          *pcVar7 = cVar1;
          bVar2 = false;
          pcVar7 = pcVar7 + 1;
        }
        else {
          *pcVar7 = ' ';
          bVar2 = true;
          pcVar7 = pcVar7 + 1;
        }
        pcVar10 = pcVar10 + 1;
      }
      *pcVar7 = '\0';
      if (bVar3) {
        FUN_00009c4c(param_1,DAT_0000bc7c + 0xbc12);
      }
      if (sVar11 == 0) {
        FUN_00009e2c(param_1,*param_3);
        iVar5 = DAT_0000bc80;
        *param_3 = 0;
        FUN_00009c4c(param_1,iVar5 + 0xbc2a);
      }
      else if (0x4f < sVar11) {
        FUN_00009c4c(param_1,DAT_0000bc84 + 0xbc3e);
        sVar11 = 0x4f;
        *(undefined1 *)(*param_3 + 0x4f) = 0;
      }
      goto LAB_0000bc48;
    }
    iVar5 = DAT_0000bc70 + 0xbb2e;
  }
  FUN_00009c4c(param_1,iVar5);
  sVar11 = 0;
LAB_0000bc48:
  if (local_1c != **(int **)(iVar8 + DAT_0000bc64)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(sVar11);
  }
  return;
}

/* === FUN_0000bc88 @ 0x0000bc88 === */

void FUN_0000bc88(int param_1)

{
  undefined1 auStack_14 [8];
  
  if (param_1 != 0) {
    FUN_0000b5b4(auStack_14,*(undefined4 *)(param_1 + 0x1d4));
    FUN_0000a0f4(param_1,auStack_14,4);
  }
  return;
}

/* === FUN_0000bcac @ 0x0000bcac === */

void FUN_0000bcac(int param_1)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  iVar1 = DAT_0000bd04 + 0xbcb8;
  local_14 = **(int **)(iVar1 + DAT_0000bd08);
  local_1c = *(undefined4 *)(DAT_0000bd0c + 0xbcfa);
  local_18 = *(undefined4 *)(DAT_0000bd0c + 0xbcfe);
  FUN_0000a0f4(param_1,(int)&local_1c + (uint)*(byte *)(param_1 + 0x1f0),
               8 - (uint)*(byte *)(param_1 + 0x1f0));
  if (*(byte *)(param_1 + 0x1f0) < 3) {
    *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 0x1000;
  }
  if (local_14 != **(int **)(iVar1 + DAT_0000bd08)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000bd10 @ 0x0000bd10 === */

void FUN_0000bd10(int param_1,int param_2,int param_3)

{
  if (((param_1 != 0) && (param_3 != 0)) && (param_2 != 0)) {
    FUN_0000a0f4();
    FUN_00009b4c(param_1,param_2,param_3);
  }
  return;
}

/* === FUN_0000bd34 @ 0x0000bd34 === */

void FUN_0000bd34(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*param_2 == 0) {
    for (iVar2 = 0; iVar2 < param_2[2]; iVar2 = iVar2 + 1) {
      iVar1 = iVar2 * 4;
      FUN_0000bd10(param_1,*(undefined4 *)(param_2[4] + iVar1),*(undefined4 *)(param_1 + 0x174));
      FUN_00009e2c(param_1,*(undefined4 *)(param_2[4] + iVar1));
      *(undefined4 *)(param_2[4] + iVar1) = 0;
    }
    if (param_2[3] != 0) {
      FUN_00009e2c(param_1,param_2[4]);
    }
    param_2[4] = 0;
    if (*(uint *)(param_1 + 0x148) < *(uint *)(param_1 + 0x174)) {
      FUN_0000bd10(param_1,*(undefined4 *)(param_1 + 0x170),
                   *(uint *)(param_1 + 0x174) - *(uint *)(param_1 + 0x148));
    }
    deflateReset(param_1 + 0x138);
    *(undefined4 *)(param_1 + 0x164) = 0;
  }
  else {
    FUN_0000bd10(param_1,*param_2,param_2[1]);
  }
  return;
}

/* === FUN_0000bdbc @ 0x0000bdbc === */

void FUN_0000bdbc(int param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  int local_1c;
  
  iVar1 = DAT_0000be24 + 0xbdc8;
  local_1c = **(int **)(iVar1 + DAT_0000be28);
  if (param_1 != 0) {
    FUN_0000b5b4(auStack_24,param_3);
    memcpy(auStack_20,param_2,4);
    FUN_0000a0f4(param_1,auStack_24,8);
    memcpy((void *)(param_1 + 0x1e0),param_2,4);
    FUN_00009b80(param_1);
    FUN_00009b4c(param_1,param_2,4);
  }
  if (local_1c != **(int **)(iVar1 + DAT_0000be28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000be2c @ 0x0000be2c === */

void FUN_0000be2c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,char *param_7,int param_8)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_58;
  int local_54;
  undefined4 local_2c;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 local_20;
  undefined1 local_1f;
  int local_1c;
  
  iVar7 = DAT_0000bf54 + 0xbe3a;
  local_1c = **(int **)(iVar7 + DAT_0000bf58);
  if (3 < param_5) {
    FUN_00009c4c(param_1,DAT_0000bf5c + 0xbe5c);
  }
  iVar1 = FUN_0000bad0(param_1,param_2,&local_2c);
  sVar2 = strlen(param_7);
  iVar4 = sVar2 + (param_6 != 0);
  local_54 = iVar1 + 1 + iVar4 + 10;
  iVar3 = FUN_00009e9c(param_1,param_6 << 2);
  iVar6 = 0;
  for (local_58 = 0; local_58 < param_6; local_58 = local_58 + 1) {
    sVar2 = strlen(*(char **)(param_8 + iVar6));
    iVar5 = sVar2 + (local_58 != param_6 + -1);
    *(int *)(iVar3 + iVar6) = iVar5;
    iVar6 = iVar6 + 4;
    local_54 = local_54 + iVar5;
  }
  FUN_0000bdbc(param_1,*(undefined4 *)(iVar7 + DAT_0000bf60),local_54);
  FUN_0000bd10(param_1,local_2c,iVar1 + 1);
  FUN_0000b5c4(auStack_28,param_3);
  FUN_0000b5c4(auStack_24,param_4);
  local_1f = (undefined1)param_6;
  local_20 = (undefined1)param_5;
  FUN_0000bd10(param_1,auStack_28,10);
  FUN_0000bd10(param_1,param_7,iVar4);
  iVar1 = 0;
  FUN_00009e2c(param_1,local_2c);
  for (local_58 = 0; iVar4 = DAT_0000bf58, local_58 < param_6; local_58 = local_58 + 1) {
    FUN_0000bd10(param_1,*(undefined4 *)(param_8 + iVar1),*(undefined4 *)(iVar3 + iVar1));
    iVar1 = iVar1 + 4;
  }
  FUN_00009e2c(param_1,iVar3);
  FUN_0000bc88(param_1);
  if (local_1c != **(int **)(iVar7 + iVar4)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000bf64 @ 0x0000bf64 === */

void FUN_0000bf64(undefined4 param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  undefined4 local_1c [2];
  
  iVar1 = FUN_0000bad0(param_1,param_2,local_1c);
  iVar3 = DAT_0000bfd0 + 0xbf7a;
  if (iVar1 != 0) {
    if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
      sVar2 = 0;
    }
    else {
      sVar2 = strlen(param_3);
    }
    FUN_0000bdbc(param_1,*(undefined4 *)(iVar3 + DAT_0000bfd4),sVar2 + iVar1 + 1);
    FUN_0000bd10(param_1,local_1c[0],iVar1 + 1);
    if (sVar2 != 0) {
      FUN_0000bd10(param_1,param_3,sVar2);
    }
    FUN_0000bc88(param_1);
    FUN_00009e2c(param_1,local_1c[0]);
  }
  return;
}

/* === FUN_0000bfd8 @ 0x0000bfd8 === */

void FUN_0000bfd8(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,int param_5
                 )

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [8];
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar1 = FUN_0000bad0(param_1,param_2,&local_20);
  iVar4 = DAT_0000c080 + 0xbffc;
  if (iVar1 != 0) {
    if (((param_3 != (char *)0x0) && (param_5 != -1)) && (*param_3 != '\0')) {
      sVar2 = strlen(param_3);
      iVar3 = FUN_0000b8e8(param_1,param_3,sVar2,param_5,&local_34);
      FUN_0000bdbc(param_1,*(undefined4 *)(iVar4 + DAT_0000c084),iVar1 + 2 + iVar3);
      FUN_0000bd10(param_1,local_20,iVar1 + 1);
      FUN_00009e2c(param_1,local_20);
      local_1c[0] = (undefined1)param_5;
      FUN_0000bd10(param_1,local_1c,1);
      FUN_0000bd34(param_1,&local_34);
      FUN_0000bc88(param_1);
      return;
    }
    FUN_0000bf64(param_1,local_20,param_3,0);
  }
  FUN_00009e2c(param_1,local_20);
  return;
}

/* === FUN_0000c088 @ 0x0000c088 === */

void FUN_0000c088(int param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_1c [8];
  
  if ((int)(uint)*(ushort *)(param_1 + 0x1dc) < param_3) {
    FUN_00009c4c(param_1,DAT_0000c0ec + 0xc0a8);
  }
  else {
    FUN_0000bdbc(param_1,*(undefined4 *)(DAT_0000c0e8 + 0xc09c + DAT_0000c0f0),param_3 << 1);
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      FUN_0000b5d4(auStack_1c,*param_2);
      FUN_0000bd10(param_1,auStack_1c,2);
      param_2 = param_2 + 1;
    }
    FUN_0000bc88(param_1);
  }
  return;
}

/* === FUN_0000c0f4 @ 0x0000c0f4 === */

void FUN_0000c0f4(undefined4 param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  int iVar6;
  int local_3c;
  undefined4 local_2c;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 auStack_24 [2];
  undefined1 auStack_22 [2];
  undefined1 auStack_20 [4];
  int local_1c;
  
  iVar6 = DAT_0000c1f4 + 0xc100;
  local_1c = **(int **)(iVar6 + DAT_0000c1f8);
  local_3c = 6;
  if (*(char *)(param_2 + 1) != '\b') {
    local_3c = 10;
  }
  iVar2 = param_2[3];
  iVar3 = FUN_0000bad0(param_1,*param_2,&local_2c);
  if (iVar3 != 0) {
    FUN_0000bdbc(param_1,*(undefined4 *)(iVar6 + DAT_0000c1fc),iVar3 + 2 + local_3c * iVar2);
    FUN_0000bd10(param_1,local_2c,iVar3 + 1);
    FUN_0000bd10(param_1,param_2 + 1,1);
    puVar5 = (undefined2 *)param_2[2];
    while( true ) {
      if ((undefined2 *)(param_2[2] + param_2[3] * 10) <= puVar5) break;
      if (*(char *)(param_2 + 1) == '\b') {
        local_28 = (undefined1)*puVar5;
        local_27 = (undefined1)puVar5[1];
        local_26 = (undefined1)puVar5[2];
        local_25 = (undefined1)puVar5[3];
        uVar1 = puVar5[4];
        puVar4 = auStack_24;
      }
      else {
        FUN_0000b5d4(&local_28);
        FUN_0000b5d4(&local_26,puVar5[1]);
        FUN_0000b5d4(auStack_24,puVar5[2]);
        FUN_0000b5d4(auStack_22,puVar5[3]);
        uVar1 = puVar5[4];
        puVar4 = auStack_20;
      }
      FUN_0000b5d4(puVar4,uVar1);
      FUN_0000bd10(param_1,&local_28,local_3c);
      puVar5 = puVar5 + 5;
    }
    FUN_0000bc88(param_1);
    FUN_00009e2c(param_1,local_2c);
  }
  if (local_1c != **(int **)(iVar6 + DAT_0000c1f8)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000c200 @ 0x0000c200 === */

void FUN_0000c200(undefined4 param_1,undefined4 param_2,int param_3,byte *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c [2];
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_2c = 0;
  local_30 = 0;
  iVar1 = FUN_0000bad0(param_1,param_2,local_1c);
  iVar3 = DAT_0000c2e8 + 0xc228;
  if (iVar1 == 0) {
    return;
  }
  if (param_3 != 0) {
    FUN_00009c4c(param_1,DAT_0000c2ec + 0xc238);
  }
  if (param_4 == (byte *)0x0) {
    param_5 = 0;
LAB_0000c2de:
    local_38 = 0;
LAB_0000c262:
    if ((int)local_38 <= (int)param_5) {
      if ((int)local_38 < (int)param_5) {
        FUN_00009c4c(param_1,DAT_0000c2f8 + 0xc282);
        param_5 = local_38;
      }
      iVar2 = 0;
      if (param_5 != 0) {
        iVar2 = FUN_0000b8e8(param_1,param_4,param_5,0,&local_30);
      }
      FUN_0000bdbc(param_1,*(undefined4 *)(iVar3 + DAT_0000c2fc),iVar2 + iVar1 + 2);
      *(undefined1 *)(local_1c[0] + iVar1 + 1) = 0;
      FUN_0000bd10(param_1,local_1c[0],iVar1 + 2);
      if (iVar2 != 0) {
        FUN_0000bd34(param_1,&local_30);
      }
      FUN_0000bc88(param_1);
      goto LAB_0000c2d2;
    }
    iVar1 = DAT_0000c2f4 + 0xc26e;
  }
  else {
    if ((int)param_5 < 4) goto LAB_0000c2de;
    local_38 = (uint)*param_4 << 0x18 | (uint)param_4[3] | (uint)param_4[1] << 0x10 |
               (uint)param_4[2] << 8;
    if (-1 < (int)local_38) goto LAB_0000c262;
    iVar1 = DAT_0000c2f0 + 0xc262;
  }
  FUN_00009c4c(param_1,iVar1);
LAB_0000c2d2:
  FUN_00009e2c(param_1,local_1c[0]);
  return;
}

/* === FUN_0000c300 @ 0x0000c300 === */

void FUN_0000c300(int param_1,undefined1 *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint local_24;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  iVar2 = DAT_0000c3ac + 0xc30c;
  if (((param_3 == 0) && (-1 < *(int *)(param_1 + 0x2f4) << 0x1f)) || (0x100 < param_3)) {
    if (*(char *)(param_1 + 0x1ea) != '\x03') {
      iVar2 = DAT_0000c3b4 + 0xc33e;
      goto LAB_0000c34c;
    }
    FUN_00009d40(param_1,DAT_0000c3b0 + 0xc334);
  }
  if ((int)((uint)*(byte *)(param_1 + 0x1ea) << 0x1e) < 0) {
    uVar1 = *(undefined4 *)(iVar2 + DAT_0000c3bc);
    *(short *)(param_1 + 0x1dc) = (short)param_3;
    FUN_0000bdbc(param_1,uVar1,param_3 * 3);
    for (local_24 = 0; local_24 < param_3; local_24 = local_24 + 1) {
      local_1c = *param_2;
      local_1b = param_2[1];
      local_1a = param_2[2];
      param_2 = param_2 + 3;
      FUN_0000bd10(param_1,&local_1c,3);
    }
    FUN_0000bc88(param_1);
    *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 2;
    return;
  }
  iVar2 = DAT_0000c3b8 + 0xc34e;
LAB_0000c34c:
  FUN_00009c4c(param_1,iVar2);
  return;
}

/* === FUN_0000c3c0 @ 0x0000c3c0 === */

void FUN_0000c3c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
    FUN_0000bdbc(param_1,param_2,param_4);
    FUN_0000bd10(param_1,param_3,param_4);
    FUN_0000bc88(param_1);
  }
  return;
}

/* === FUN_0000c3e4 @ 0x0000c3e4 === */

void FUN_0000c3e4(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined1 auStack_20 [2];
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  iVar1 = DAT_0000c450 + 0xc3f8;
  if (((((byte)(*(char *)(param_2 + 1) - 1U) < 0xc) && (*(byte *)((int)param_2 + 3) < 0x20)) &&
      (*(byte *)((int)param_2 + 3) != 0)) &&
     ((*(byte *)(param_2 + 2) < 0x18 && (*(byte *)(param_2 + 3) < 0x3d)))) {
    FUN_0000b5d4(auStack_20,*param_2);
    local_1e = *(undefined1 *)(param_2 + 1);
    local_1d = *(undefined1 *)((int)param_2 + 3);
    local_1c = *(undefined1 *)(param_2 + 2);
    local_1b = *(undefined1 *)((int)param_2 + 5);
    local_1a = *(undefined1 *)(param_2 + 3);
    FUN_0000c3c0(param_1,*(undefined4 *)(iVar1 + DAT_0000c458),auStack_20,7);
  }
  else {
    FUN_00009c4c(param_1,DAT_0000c454 + 0xc41a);
  }
  return;
}

/* === FUN_0000c45c @ 0x0000c45c === */

void FUN_0000c45c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 local_20;
  int local_1c;
  
  iVar2 = DAT_0000c4b8 + 0xc46a;
  local_1c = **(int **)(iVar2 + DAT_0000c4bc);
  if (1 < param_4) {
    FUN_00009c4c(param_1,DAT_0000c4c0 + 0xc480);
  }
  FUN_0000b5b4(auStack_28,param_2);
  FUN_0000b5b4(auStack_24,param_3);
  iVar1 = DAT_0000c4bc;
  local_20 = (undefined1)param_4;
  FUN_0000c3c0(param_1,*(undefined4 *)(iVar2 + DAT_0000c4c4),auStack_28,9);
  if (local_1c != **(int **)(iVar2 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000c4c8 @ 0x0000c4c8 === */

void FUN_0000c4c8(undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  size_t sVar1;
  char *__s;
  char *__format;
  int iVar2;
  int *piVar3;
  int iVar4;
  char local_5c [64];
  int local_1c;
  
  iVar2 = DAT_0000c540 + 0xc4d4;
  piVar3 = *(int **)(iVar2 + DAT_0000c544);
  local_1c = *piVar3;
  __format = (char *)(DAT_0000c548 + 0xc4ea);
  local_5c[0] = param_2;
  snprintf(local_5c + 1,0x3f,__format,param_4,param_3,param_4);
  sVar1 = strlen(local_5c + 1);
  iVar4 = sVar1 + 2;
  __s = local_5c + iVar4;
  snprintf(__s,0x40 - iVar4,__format,param_6,param_5,param_6);
  sVar1 = strlen(__s);
  FUN_0000c3c0(param_1,*(undefined4 *)(iVar2 + DAT_0000c54c),local_5c,iVar4 + sVar1);
  if (local_1c != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000c550 @ 0x0000c550 === */

void FUN_0000c550(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 local_20;
  int local_1c;
  
  iVar2 = DAT_0000c5ac + 0xc55e;
  local_1c = **(int **)(iVar2 + DAT_0000c5b0);
  if (1 < param_4) {
    FUN_00009c4c(param_1,DAT_0000c5b4 + 0xc574);
  }
  FUN_0000b5c4(auStack_28,param_2);
  FUN_0000b5c4(auStack_24,param_3);
  iVar1 = DAT_0000c5b0;
  local_20 = (undefined1)param_4;
  FUN_0000c3c0(param_1,*(undefined4 *)(iVar2 + DAT_0000c5b8),auStack_28,9);
  if (local_1c != **(int **)(iVar2 + iVar1)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000c5bc @ 0x0000c5bc === */

void FUN_0000c5bc(int param_1,byte *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte local_20 [2];
  char local_1e [2];
  char local_1c [8];
  
  iVar1 = DAT_0000c684;
  iVar4 = DAT_0000c67c + 0xc5c8;
  if (param_3 == 3) {
    if (((*(ushort *)(param_1 + 0x1dc) == 0) && (*(int *)(param_1 + 0x2f4) << 0x1f < 0)) ||
       ((ushort)*param_2 < *(ushort *)(param_1 + 0x1dc))) {
      local_20[0] = *param_2;
      uVar2 = *(undefined4 *)(iVar4 + DAT_0000c684);
      uVar3 = 1;
      goto LAB_0000c674;
    }
    iVar1 = DAT_0000c680 + 0xc5ec;
  }
  else if (param_3 << 0x1e < 0) {
    FUN_0000b5d4(local_20,*(undefined2 *)(param_2 + 2));
    FUN_0000b5d4(local_1e,*(undefined2 *)(param_2 + 4));
    FUN_0000b5d4(local_1c,*(undefined2 *)(param_2 + 6));
    if ((*(char *)(param_1 + DAT_0000c688) != '\b') ||
       (((local_1e[0] == '\0' && (local_20[0] == 0)) && (local_1c[0] == '\0')))) {
      uVar2 = *(undefined4 *)(iVar4 + DAT_0000c684);
      uVar3 = 6;
LAB_0000c674:
      FUN_0000c3c0(param_1,uVar2,local_20,uVar3);
      return;
    }
    iVar1 = DAT_0000c68c + 0xc63c;
  }
  else {
    if ((int)(uint)*(ushort *)(param_2 + 8) < 1 << *(sbyte *)(param_1 + DAT_0000c688)) {
      FUN_0000b5d4(local_20);
      uVar2 = *(undefined4 *)(iVar4 + iVar1);
      uVar3 = 2;
      goto LAB_0000c674;
    }
    iVar1 = DAT_0000c690 + 0xc65e;
  }
  FUN_00009c4c(param_1,iVar1);
  return;
}

/* === FUN_0000c694 @ 0x0000c694 === */

void FUN_0000c694(int param_1,undefined1 *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  char local_20 [2];
  char local_1e [2];
  char local_1c [8];
  
  iVar1 = DAT_0000c758;
  pcVar3 = local_20;
  iVar4 = DAT_0000c750 + 0xc6a2;
  if (param_5 == 3) {
    if ((0 < param_4) && (param_4 <= (int)(uint)*(ushort *)(param_1 + 0x1dc))) {
      uVar2 = *(undefined4 *)(iVar4 + DAT_0000c758);
      pcVar3 = param_2;
LAB_0000c73c:
      FUN_0000c3c0(param_1,uVar2,pcVar3,param_4);
      return;
    }
    iVar1 = DAT_0000c754 + 0xc6bc;
  }
  else if (param_5 == 0) {
    if ((int)(uint)*(ushort *)(param_3 + 8) < 1 << (uint)*(byte *)(param_1 + DAT_0000c75c)) {
      FUN_0000b5d4(local_20);
      uVar2 = *(undefined4 *)(iVar4 + iVar1);
      param_4 = 2;
      pcVar3 = local_20;
      goto LAB_0000c73c;
    }
    iVar1 = DAT_0000c760 + 0xc6e0;
  }
  else if (param_5 == 2) {
    FUN_0000b5d4(local_20,*(undefined2 *)(param_3 + 2));
    FUN_0000b5d4(local_1e,*(undefined2 *)(param_3 + 4));
    FUN_0000b5d4(local_1c,*(undefined2 *)(param_3 + 6));
    if ((*(char *)(param_1 + DAT_0000c75c) != '\b') ||
       (((local_1e[0] == '\0' && (local_20[0] == '\0')) && (local_1c[0] == '\0')))) {
      uVar2 = *(undefined4 *)(iVar4 + DAT_0000c758);
      param_4 = 6;
      goto LAB_0000c73c;
    }
    iVar1 = DAT_0000c764 + 0xc732;
  }
  else {
    iVar1 = DAT_0000c768 + 0xc748;
  }
  FUN_00009c4c(param_1,iVar1);
  return;
}

/* === FUN_0000c770 @ 0x0000c770 === */

void FUN_0000c770(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                 undefined4 param_17,undefined4 param_18)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  int local_1c;
  
  iVar10 = DAT_0000c8f0 + 0xc77c;
  local_1c = **(int **)(iVar10 + DAT_0000c8f4);
  uVar11 = FUN_0000e20c(param_3,param_4,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar1 = FUN_0000e7a8();
  uVar11 = FUN_0000e20c(param_5,param_6,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar2 = FUN_0000e7a8();
  uVar11 = FUN_0000e20c(param_7,param_8,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar3 = FUN_0000e7a8();
  uVar11 = FUN_0000e20c(param_9,param_10,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar4 = FUN_0000e7a8();
  uVar11 = FUN_0000e20c(param_11,param_12,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar5 = FUN_0000e7a8();
  uVar11 = FUN_0000e20c(param_13,param_14,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar6 = FUN_0000e7a8();
  uVar11 = FUN_0000e20c(param_15,param_16,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar7 = FUN_0000e7a8();
  uVar11 = FUN_0000e20c(param_17,param_18,DAT_0000c8e0,DAT_0000c8e4);
  FUN_0000de60((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),DAT_0000c8e8,DAT_0000c8ec);
  uVar8 = FUN_0000e7a8();
  iVar9 = FUN_00009438(param_1,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8);
  if (iVar9 != 0) {
    FUN_0000b5b4(auStack_3c,uVar1);
    FUN_0000b5b4(auStack_38,uVar2);
    FUN_0000b5b4(auStack_34,uVar3);
    FUN_0000b5b4(auStack_30,uVar4);
    FUN_0000b5b4(auStack_2c,uVar5);
    FUN_0000b5b4(auStack_28,uVar6);
    FUN_0000b5b4(auStack_24,uVar7);
    FUN_0000b5b4(auStack_20,uVar8);
    FUN_0000c3c0(param_1,*(undefined4 *)(iVar10 + DAT_0000c8f8),auStack_3c,0x20);
  }
  if (local_1c != **(int **)(iVar10 + DAT_0000c8f4)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000c900 @ 0x0000c900 === */

void FUN_0000c900(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  byte local_1c [8];
  
  if (param_3 << 0x1e < 0) {
    bVar5 = 8;
    if (param_3 != 3) {
      bVar5 = *(byte *)(param_1 + 0x1ec);
    }
    bVar1 = *param_2;
    if (((((bVar1 == 0) || (bVar5 < bVar1)) || (bVar2 = param_2[1], bVar2 == 0)) ||
        ((bVar5 < bVar2 || (bVar3 = param_2[2], bVar3 == 0)))) || (bVar5 < bVar3)) {
      iVar4 = DAT_0000c99c + 0xc93c;
      goto LAB_0000c97c;
    }
    iVar4 = 3;
    local_1c[0] = bVar1;
    local_1c[1] = bVar2;
    local_1c[2] = bVar3;
  }
  else {
    bVar5 = param_2[3];
    if ((bVar5 == 0) || (*(byte *)(param_1 + 0x1ec) < bVar5)) {
      iVar4 = DAT_0000c9a0 + 0xc95e;
      goto LAB_0000c97c;
    }
    iVar4 = 1;
    local_1c[0] = bVar5;
  }
  if (param_3 << 0x1d < 0) {
    bVar5 = param_2[4];
    if ((bVar5 == 0) || (*(byte *)(param_1 + 0x1ec) < bVar5)) {
      iVar4 = DAT_0000c9a4 + 0xc97e;
LAB_0000c97c:
      FUN_00009c4c(param_1,iVar4);
      return;
    }
    local_1c[iVar4] = bVar5;
    iVar4 = iVar4 + 1;
  }
  FUN_0000c3c0(param_1,*(undefined4 *)(DAT_0000c998 + 0xc90a + DAT_0000c9a8),local_1c,iVar4);
  return;
}

/* === FUN_0000c9ac @ 0x0000c9ac === */

void FUN_0000c9ac(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 local_14 [4];
  
  iVar1 = DAT_0000c9d8 + 0xc9b8;
  if (3 < param_2) {
    FUN_00009c4c(param_1,DAT_0000c9dc + 0xc9c2);
  }
  local_14[0] = (undefined1)param_2;
  FUN_0000c3c0(param_1,*(undefined4 *)(iVar1 + DAT_0000c9e0),local_14,1);
  return;
}

/* === FUN_0000c9e8 @ 0x0000c9e8 === */

void FUN_0000c9e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 auStack_14 [4];
  
  uVar3 = FUN_0000e20c(param_3,param_4,DAT_0000ca28,DAT_0000ca2c);
  FUN_0000de60((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_0000ca30,DAT_0000ca34);
  uVar2 = FUN_0000e7a8();
  iVar1 = DAT_0000ca38;
  FUN_0000b5b4(auStack_14,uVar2);
  FUN_0000c3c0(param_1,*(undefined4 *)(iVar1 + 0xca18 + DAT_0000ca3c),auStack_14,4);
  return;
}

/* === FUN_0000ca40 @ 0x0000ca40 === */

void FUN_0000ca40(int param_1)

{
  FUN_0000c3c0(param_1,*(undefined4 *)(DAT_0000ca64 + 0xca4c + DAT_0000ca68),0,0);
  *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 0x10;
  return;
}

/* === FUN_0000ca6c @ 0x0000ca6c === */

void FUN_0000ca6c(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  char extraout_r1;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = DAT_0000cb40 + 0xca80;
  if ((-1 < *(int *)(param_1 + 300) << 0x1d) && (*(char *)(param_1 + 0x324) == '\0')) {
    uVar4 = (uint)*param_2;
    if (((uVar4 & 0xf) == 8) && ((uVar4 & 0xf0) < 0x71)) {
      if (1 < param_3) {
        if ((*(uint *)(param_1 + 400) <= DAT_0000cb44) &&
           (*(uint *)(param_1 + 0x18c) <= DAT_0000cb44)) {
          uVar3 = ((uint)*(byte *)(param_1 + 0x1ee) * (uint)*(byte *)(param_1 + DAT_0000cb48) *
                   *(uint *)(param_1 + 0x18c) + 0xf >> 3) * *(uint *)(param_1 + 400);
          uVar2 = (uint)(*param_2 >> 4);
          for (uVar6 = 1 << uVar2 + 7; (0xff < uVar6 && (uVar3 < uVar6 || uVar3 - uVar6 == 0));
              uVar6 = uVar6 >> 1) {
            uVar2 = uVar2 - 1;
          }
          uVar3 = uVar2 << 4 & 0xff | 8;
          if (uVar4 != uVar3) {
            *param_2 = (byte)uVar3;
            bVar1 = param_2[1];
            FUN_0000de3c((uVar2 << 4 | 8) * 0x100 + (bVar1 & 0xe0),0x1f);
            param_2[1] = ((char)(bVar1 & 0xe0) + '\x1f') - extraout_r1;
          }
        }
      }
    }
    else {
      FUN_00009d40(param_1,DAT_0000cb4c + 0xcb22);
    }
  }
  FUN_0000c3c0(param_1,*(undefined4 *)(iVar5 + DAT_0000cb50),param_2,param_3);
  *(uint *)(param_1 + 300) = *(uint *)(param_1 + 300) | 4;
  return;
}

/* === FUN_0000cb54 @ 0x0000cb54 === */

void FUN_0000cb54(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_88 [7];
  int local_6c [7];
  int local_50 [4];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int local_34 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  local_34[0] = *(int *)(DAT_0000cd1c + 0xcba0);
  local_34[1] = *(undefined4 *)(DAT_0000cd1c + 0xcba4);
  local_34[2] = *(undefined4 *)(DAT_0000cd1c + 0xcba8);
  local_34[3] = *(undefined4 *)(DAT_0000cd1c + 0xcbac);
  uStack_24 = *(undefined4 *)(DAT_0000cd1c + 0xcbb0);
  uStack_20 = *(undefined4 *)(DAT_0000cd1c + 0xcbb4);
  local_1c = *(undefined4 *)(DAT_0000cd1c + 0xcbb8);
  local_50[0] = *(int *)(DAT_0000cd1c + 0xcbbc);
  local_50[1] = *(undefined4 *)(DAT_0000cd1c + 0xcbc0);
  local_50[2] = *(undefined4 *)(DAT_0000cd1c + 0xcbc4);
  local_50[3] = *(undefined4 *)(DAT_0000cd1c + 0xcbc8);
  uStack_40 = *(undefined4 *)(DAT_0000cd1c + 0xcbcc);
  uStack_3c = *(undefined4 *)(DAT_0000cd1c + 0xcbd0);
  local_38 = *(undefined4 *)(DAT_0000cd1c + 0xcbd4);
  local_6c[0] = *(int *)(DAT_0000cd1c + 0xcbd8);
  local_6c[1] = *(undefined4 *)(DAT_0000cd1c + 0xcbdc);
  local_6c[2] = *(undefined4 *)(DAT_0000cd1c + 0xcbe0);
  local_6c[3] = *(undefined4 *)(DAT_0000cd1c + 0xcbe4);
  local_6c[4] = *(undefined4 *)(DAT_0000cd1c + 0xcbe8);
  local_6c[5] = *(undefined4 *)(DAT_0000cd1c + 0xcbec);
  local_6c[6] = *(undefined4 *)(DAT_0000cd1c + 0xcbf0);
  local_88[0] = *(int *)(DAT_0000cd20 + 0xcbb8);
  local_88[1] = *(undefined4 *)(DAT_0000cd20 + 0xcbbc);
  local_88[2] = *(undefined4 *)(DAT_0000cd20 + 0xcbc0);
  local_88[3] = *(undefined4 *)(DAT_0000cd20 + 0xcbc4);
  local_88[4] = *(undefined4 *)(DAT_0000cd20 + 0xcbc8);
  local_88[5] = *(undefined4 *)(DAT_0000cd20 + 0xcbcc);
  local_88[6] = *(undefined4 *)(DAT_0000cd20 + 0xcbd0);
  uVar3 = *(int *)(param_1 + 0x1a8) + 1;
  *(uint *)(param_1 + 0x1a8) = uVar3;
  if (*(uint *)(param_1 + 0x194) <= uVar3) {
    if (*(char *)(param_1 + DAT_0000cd24) != '\0') {
      *(undefined4 *)(param_1 + 0x1a8) = 0;
      if (*(int *)(param_1 + 0x134) << 0x1e < 0) {
        *(char *)(param_1 + 0x1e8) = *(char *)(param_1 + 0x1e8) + '\x01';
      }
      else {
        uVar3 = (uint)*(byte *)(param_1 + 0x1e8);
        while( true ) {
          uVar1 = uVar3 + 1;
          uVar3 = uVar1 & 0xff;
          if (6 < uVar3) break;
          iVar4 = FUN_0000dd90((*(int *)(param_1 + 0x18c) + -1 + local_50[uVar3]) - local_34[uVar3])
          ;
          *(int *)(param_1 + 0x198) = iVar4;
          iVar2 = FUN_0000dd90((*(int *)(param_1 + 400) + -1 + local_88[uVar3]) - local_6c[uVar3]);
          *(int *)(param_1 + 0x194) = iVar2;
          if ((*(int *)(param_1 + 0x134) << 0x1e < 0) || ((iVar4 != 0 && (iVar2 != 0)))) break;
        }
        *(char *)(param_1 + 0x1e8) = (char)uVar1;
      }
      if (*(byte *)(param_1 + 0x1e8) < 7) {
        if (*(void **)(param_1 + 0x1ac) == (void *)0x0) {
          return;
        }
        uVar3 = (uint)*(byte *)(param_1 + 0x1ec) * (uint)*(byte *)(param_1 + DAT_0000cd28);
        if (uVar3 < 8) {
          uVar3 = uVar3 * *(int *)(param_1 + 0x18c) + 7 >> 3;
        }
        else {
          uVar3 = (uVar3 >> 3) * *(int *)(param_1 + 0x18c);
        }
        memset(*(void **)(param_1 + 0x1ac),0,uVar3 + 1);
        return;
      }
    }
    iVar4 = DAT_0000cd2c + 0xccbe;
    while( true ) {
      while (iVar2 = deflate(param_1 + 0x138,4), iVar2 == 0) {
        if (*(int *)(param_1 + 0x148) == 0) {
          FUN_0000ca6c(param_1,*(undefined4 *)(param_1 + 0x170),*(undefined4 *)(param_1 + 0x174));
          *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
          *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
        }
      }
      if (iVar2 == 1) break;
      iVar2 = *(int *)(param_1 + 0x150);
      if (*(int *)(param_1 + 0x150) == 0) {
        iVar2 = iVar4;
      }
      FUN_00009d40(param_1,iVar2);
    }
    if (*(uint *)(param_1 + 0x148) < *(uint *)(param_1 + 0x174)) {
      FUN_0000ca6c(param_1,*(undefined4 *)(param_1 + 0x170),
                   *(uint *)(param_1 + 0x174) - *(uint *)(param_1 + 0x148));
    }
    deflateReset(param_1 + 0x138);
    *(undefined4 *)(param_1 + 0x164) = 0;
  }
  return;
}

/* === FUN_0000cd30 @ 0x0000cd30 === */

void FUN_0000cd30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0x138) = param_2;
  iVar2 = DAT_0000cdc4;
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x1c8) + 1;
  do {
    iVar1 = deflate(param_1 + 0x138,0);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x150);
      if (*(int *)(param_1 + 0x150) == 0) {
        iVar1 = iVar2 + 0xcd50;
      }
      FUN_00009d40(param_1,iVar1);
    }
    if (*(int *)(param_1 + 0x148) == 0) {
      FUN_0000ca6c(param_1,*(undefined4 *)(param_1 + 0x170),*(undefined4 *)(param_1 + 0x174),0,
                   param_4);
      *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
      *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
    }
  } while (*(int *)(param_1 + 0x13c) != 0);
  iVar2 = *(int *)(param_1 + 0x1ac);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(param_1 + 0x1b0);
    *(int *)(param_1 + 0x1b0) = iVar2;
  }
  FUN_0000cb54(param_1);
  uVar3 = *(int *)(param_1 + 0x218) + 1;
  *(uint *)(param_1 + 0x218) = uVar3;
  if ((*(uint *)(param_1 + 0x214) != 0) && (*(uint *)(param_1 + 0x214) <= uVar3)) {
    FUN_0000a674(param_1);
  }
  return;
}

/* === FUN_0000cdc8 @ 0x0000cdc8 === */

void FUN_0000cdc8(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint local_48;
  undefined1 *local_40;
  
  uVar15 = (uint)*(byte *)(param_1 + DAT_0000d0d8);
  uVar13 = *(uint *)(param_2 + 4);
  uVar7 = (uint)*(byte *)(param_1 + DAT_0000d0dc);
  iVar16 = *(int *)(param_1 + 0x1ac);
  puVar8 = *(undefined1 **)(param_1 + 0x1b0);
  uVar12 = (int)(*(byte *)(param_2 + 0xb) + 7) >> 3;
  local_48 = DAT_0000d0e4;
  if (((int)(uVar15 << 0x1c) < 0) && (uVar15 != 8)) {
    local_48 = 0;
    for (uVar9 = 0; uVar9 < uVar13; uVar9 = uVar9 + 1) {
      uVar4 = (uint)(byte)puVar8[uVar9 + 1];
      if (0x7f < uVar4) {
        uVar4 = 0x100 - uVar4;
      }
      local_48 = local_48 + uVar4;
    }
    if (*(char *)(param_1 + 700) == '\x02') {
      uVar9 = local_48 >> 10 & DAT_0000d0e0;
      uVar4 = local_48 & 0xffff;
      for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
        if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\0') {
          uVar11 = (uint)*(ushort *)((iVar10 + DAT_0000d0e4) * 2 + *(int *)(param_1 + 0x2c4));
          uVar4 = uVar11 * uVar4 >> 8;
          uVar9 = uVar11 * uVar9 >> 8;
        }
      }
      uVar9 = uVar9 * **(ushort **)(param_1 + 0x2cc) >> 3;
      local_48 = DAT_0000d0e4;
      if (uVar9 <= DAT_0000d0e0) {
        local_48 = uVar9 * 0x400 + (uVar4 * **(ushort **)(param_1 + 0x2cc) >> 3);
      }
    }
  }
  if (uVar15 == 0x10) {
    iVar10 = *(int *)(param_1 + 0x1b4);
    for (uVar9 = 0; uVar9 < uVar12; uVar9 = uVar9 + 1) {
      *(undefined1 *)(iVar10 + uVar9 + 1) = puVar8[uVar9 + 1];
    }
    for (uVar9 = uVar12; uVar9 < uVar13; uVar9 = uVar9 + 1) {
      *(undefined1 *)(iVar10 + 1 + uVar9) = puVar8[uVar9 + 1] - puVar8[(uVar9 - uVar12) + 1];
    }
    local_40 = *(undefined1 **)(param_1 + 0x1b4);
LAB_0000d0a4:
    if ((int)(uVar15 << 0x1a) < 0) {
      uVar9 = local_48;
      if (*(char *)(param_1 + 700) == '\x02') {
        uVar9 = local_48 >> 10 & DAT_0000d0e0;
        uVar4 = local_48 & 0xffff;
        for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
          if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\x02') {
            uVar11 = (uint)*(ushort *)((iVar10 + DAT_0000d428) * 2 + *(int *)(param_1 + 0x2c8));
            uVar4 = uVar11 * uVar4 >> 8;
            uVar9 = uVar11 * uVar9 >> 8;
          }
        }
        uVar11 = (uint)*(ushort *)(*(int *)(param_1 + 0x2d0) + 4);
        uVar18 = uVar9 * uVar11 >> 3;
        uVar9 = DAT_0000d428;
        if (uVar18 <= DAT_0000d42c) {
          uVar9 = uVar18 * 0x400 + (uVar4 * uVar11 >> 3);
        }
      }
      iVar10 = *(int *)(param_1 + 0x1b8);
      uVar4 = 0;
      for (uVar11 = 0; uVar11 < uVar13; uVar11 = uVar11 + 1) {
        bVar3 = puVar8[uVar11 + 1] - *(char *)(iVar16 + uVar11 + 1);
        uVar18 = (uint)bVar3;
        *(byte *)(iVar10 + uVar11 + 1) = bVar3;
        if (0x7f < uVar18) {
          uVar18 = 0x100 - uVar18;
        }
        uVar4 = uVar4 + uVar18;
        if (uVar9 < uVar4) break;
      }
      if (*(char *)(param_1 + 700) == '\x02') {
        uVar9 = uVar4 >> 10 & DAT_0000d42c;
        uVar11 = uVar4 & 0xffff;
        for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
          if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\x02') {
            uVar4 = (uint)*(ushort *)((iVar10 + DAT_0000d428) * 2 + *(int *)(param_1 + 0x2c4));
            uVar11 = uVar4 * uVar11 >> 8;
            uVar9 = uVar4 * uVar9 >> 8;
          }
        }
        uVar18 = (uint)*(ushort *)(*(int *)(param_1 + 0x2cc) + 4);
        uVar9 = uVar9 * uVar18 >> 3;
        uVar4 = DAT_0000d428;
        if (uVar9 <= DAT_0000d42c) {
          uVar4 = uVar9 * 0x400 + (uVar11 * uVar18 >> 3);
        }
      }
      if (uVar4 < local_48) {
        local_40 = *(undefined1 **)(param_1 + 0x1b8);
        local_48 = uVar4;
      }
    }
    if (uVar15 != 0x40) goto LAB_0000d266;
    iVar10 = *(int *)(param_1 + 0x1bc);
    for (uVar9 = 0; uVar4 = uVar12, pbVar5 = puVar8 + 1, uVar9 < uVar12; uVar9 = uVar9 + 1) {
      *(byte *)(iVar10 + uVar9 + 1) = puVar8[uVar9 + 1] - (*(byte *)(iVar16 + uVar9 + 1) >> 1);
    }
    for (; uVar4 < uVar13; uVar4 = uVar4 + 1) {
      *(char *)(iVar10 + 1 + uVar4) =
           (puVar8 + 1)[uVar4] -
           (char)((int)((uint)*pbVar5 + (uint)*(byte *)(iVar16 + 1 + uVar4)) >> 1);
      pbVar5 = pbVar5 + 1;
    }
    local_40 = *(undefined1 **)(param_1 + 0x1bc);
LAB_0000d4ce:
    if (-1 < (int)(uVar15 * 0x1000000)) goto LAB_0000d6c6;
    uVar15 = local_48;
    if (*(char *)(param_1 + 700) == '\x02') {
      uVar9 = local_48 & 0xffff;
      uVar15 = local_48 >> 10 & DAT_0000d700;
      for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
        if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\x04') {
          uVar4 = (uint)*(ushort *)((iVar10 + DAT_0000d704) * 2 + *(int *)(param_1 + 0x2c8));
          uVar9 = uVar4 * uVar9 >> 8;
          uVar15 = uVar4 * uVar15 >> 8;
        }
      }
      uVar11 = (uint)*(ushort *)(*(int *)(param_1 + 0x2d0) + 8);
      uVar4 = uVar15 * uVar11 >> 3;
      uVar15 = DAT_0000d704;
      if (uVar4 <= DAT_0000d700) {
        uVar15 = uVar4 * 0x400 + (uVar9 * uVar11 >> 3);
      }
    }
    iVar10 = *(int *)(param_1 + 0x1c0);
    uVar9 = 0;
    for (uVar4 = 0; uVar4 < uVar12; uVar4 = uVar4 + 1) {
      bVar3 = puVar8[uVar4 + 1] - *(char *)(iVar16 + uVar4 + 1);
      uVar11 = (uint)bVar3;
      *(byte *)(iVar10 + uVar4 + 1) = bVar3;
      if (0x7f < uVar11) {
        uVar11 = 0x100 - uVar11;
      }
      uVar9 = uVar9 + uVar11;
    }
    iVar2 = -uVar12;
    for (; uVar12 < uVar13; uVar12 = uVar12 + 1) {
      uVar18 = (uint)*(byte *)(iVar16 + 1 + uVar12);
      uVar4 = (uint)*(byte *)(iVar16 + iVar2 + uVar12 + 1);
      iVar19 = uVar18 - uVar4;
      iVar6 = (byte)puVar8[uVar12 + iVar2 + 1] - uVar4;
      uVar20 = iVar19 + (iVar19 >> 0x1f) ^ iVar19 >> 0x1f;
      uVar21 = iVar6 + (iVar6 >> 0x1f) ^ iVar6 >> 0x1f;
      uVar11 = iVar6 + iVar19 >> 0x1f;
      uVar11 = iVar6 + iVar19 + uVar11 ^ uVar11;
      if ((((int)uVar11 < (int)uVar20) ||
          (uVar17 = (uint)(byte)puVar8[uVar12 + iVar2 + 1], (int)uVar21 < (int)uVar20)) &&
         (uVar17 = uVar18, (int)uVar11 < (int)uVar21)) {
        uVar17 = uVar4;
      }
      uVar4 = (byte)puVar8[uVar12 + 1] - uVar17 & 0xff;
      *(char *)(iVar10 + 1 + uVar12) = (char)((byte)puVar8[uVar12 + 1] - uVar17);
      if (0x7f < uVar4) {
        uVar4 = 0x100 - uVar4;
      }
      uVar9 = uVar9 + uVar4;
      if (uVar15 < uVar9) break;
    }
    if (*(char *)(param_1 + 700) == '\x02') {
      uVar13 = uVar9 >> 10 & DAT_0000d700;
      uVar12 = uVar9 & 0xffff;
      for (iVar16 = 1; iVar16 != uVar7 + 1; iVar16 = iVar16 + 1) {
        if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar16 + -1) == '\x04') {
          uVar15 = (uint)*(ushort *)((iVar16 + DAT_0000d704) * 2 + *(int *)(param_1 + 0x2c4));
          uVar12 = uVar15 * uVar12 >> 8;
          uVar13 = uVar15 * uVar13 >> 8;
        }
      }
      uVar15 = (uint)*(ushort *)(*(int *)(param_1 + 0x2cc) + 8);
      uVar13 = uVar13 * uVar15 >> 3;
      uVar9 = DAT_0000d704;
      if (uVar13 <= DAT_0000d700) {
        uVar9 = uVar13 * 0x400 + (uVar12 * uVar15 >> 3);
      }
    }
    if (local_48 <= uVar9) goto LAB_0000d6c6;
  }
  else {
    local_40 = puVar8;
    if ((int)(uVar15 << 0x1b) < 0) {
      uVar9 = local_48;
      if (*(char *)(param_1 + 700) == '\x02') {
        uVar9 = local_48 >> 10 & DAT_0000d0e0;
        uVar4 = local_48 & 0xffff;
        for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
          if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\x01') {
            uVar11 = (uint)*(ushort *)((iVar10 + DAT_0000d0e4) * 2 + *(int *)(param_1 + 0x2c8));
            uVar4 = uVar11 * uVar4 >> 8;
            uVar9 = uVar11 * uVar9 >> 8;
          }
        }
        uVar11 = (uint)*(ushort *)(*(int *)(param_1 + 0x2d0) + 2);
        uVar18 = uVar9 * uVar11 >> 3;
        uVar9 = DAT_0000d0e4;
        if (uVar18 <= DAT_0000d0e0) {
          uVar9 = uVar18 * 0x400 + (uVar4 * uVar11 >> 3);
        }
      }
      iVar10 = *(int *)(param_1 + 0x1b4);
      uVar4 = 0;
      for (uVar11 = 0; uVar11 < uVar12; uVar11 = uVar11 + 1) {
        uVar18 = (uint)(byte)puVar8[uVar11 + 1];
        *(undefined1 *)(iVar10 + uVar11 + 1) = puVar8[uVar11 + 1];
        if (0x7f < uVar18) {
          uVar18 = 0x100 - uVar18;
        }
        uVar4 = uVar4 + uVar18;
      }
      for (uVar11 = uVar12; uVar11 < uVar13; uVar11 = uVar11 + 1) {
        uVar18 = (uint)(byte)(puVar8[uVar11 + 1] - puVar8[(uVar11 - uVar12) + 1]);
        *(undefined1 *)(iVar10 + 1 + uVar11) = puVar8[uVar11 + 1] - puVar8[(uVar11 - uVar12) + 1];
        if (0x7f < uVar18) {
          uVar18 = 0x100 - uVar18;
        }
        uVar4 = uVar4 + uVar18;
        if (uVar9 < uVar4) break;
      }
      if (*(char *)(param_1 + 700) == '\x02') {
        uVar9 = uVar4 & 0xffff;
        uVar4 = uVar4 >> 10 & DAT_0000d0e0;
        for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
          if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\x01') {
            uVar11 = (uint)*(ushort *)((iVar10 + DAT_0000d0e4) * 2 + *(int *)(param_1 + 0x2c8));
            uVar9 = uVar11 * uVar9 >> 8;
            uVar4 = uVar11 * uVar4 >> 8;
          }
        }
        uVar11 = (uint)*(ushort *)(*(int *)(param_1 + 0x2d0) + 2);
        uVar18 = uVar4 * uVar11 >> 3;
        uVar4 = DAT_0000d0e4;
        if (uVar18 <= DAT_0000d0e0) {
          uVar4 = uVar18 * 0x400 + (uVar9 * uVar11 >> 3);
        }
      }
      if (uVar4 < local_48) {
        local_48 = uVar4;
        local_40 = *(undefined1 **)(param_1 + 0x1b4);
      }
    }
    if (uVar15 != 0x20) goto LAB_0000d0a4;
    iVar10 = *(int *)(param_1 + 0x1b8);
    for (uVar9 = 0; uVar9 < uVar13; uVar9 = uVar9 + 1) {
      *(char *)(iVar10 + uVar9 + 1) = puVar8[uVar9 + 1] - *(char *)(iVar16 + uVar9 + 1);
    }
    local_40 = *(undefined1 **)(param_1 + 0x1b8);
LAB_0000d266:
    if ((int)(uVar15 << 0x19) < 0) {
      uVar9 = local_48;
      if (*(char *)(param_1 + 700) == '\x02') {
        uVar4 = local_48 & 0xffff;
        uVar9 = local_48 >> 10 & DAT_0000d42c;
        for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
          if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\x03') {
            uVar11 = (uint)*(ushort *)((iVar10 + DAT_0000d428) * 2 + *(int *)(param_1 + 0x2c8));
            uVar4 = uVar11 * uVar4 >> 8;
            uVar9 = uVar11 * uVar9 >> 8;
          }
        }
        uVar11 = (uint)*(ushort *)(*(int *)(param_1 + 0x2d0) + 6);
        uVar18 = uVar9 * uVar11 >> 3;
        uVar9 = DAT_0000d428;
        if (uVar18 <= DAT_0000d42c) {
          uVar9 = uVar18 * 0x400 + (uVar4 * uVar11 >> 3);
        }
      }
      iVar10 = *(int *)(param_1 + 0x1bc);
      uVar4 = 0;
      for (uVar11 = 0; pbVar5 = puVar8 + 1, uVar18 = uVar12, uVar11 < uVar12; uVar11 = uVar11 + 1) {
        bVar3 = puVar8[uVar11 + 1] - (*(byte *)(iVar16 + uVar11 + 1) >> 1);
        uVar18 = (uint)bVar3;
        *(byte *)(iVar10 + uVar11 + 1) = bVar3;
        if (0x7f < uVar18) {
          uVar18 = 0x100 - uVar18;
        }
        uVar4 = uVar4 + uVar18;
      }
      for (; uVar18 < uVar13; uVar18 = uVar18 + 1) {
        uVar20 = (uint)(byte)(puVar8 + 1)[uVar18] -
                 ((int)((uint)*pbVar5 + (uint)*(byte *)(iVar16 + 1 + uVar18)) >> 1);
        uVar11 = uVar20 & 0xff;
        *(char *)(iVar10 + 1 + uVar18) = (char)uVar20;
        if (0x7f < uVar11) {
          uVar11 = 0x100 - uVar11;
        }
        uVar4 = uVar4 + uVar11;
        if (uVar9 < uVar4) break;
        pbVar5 = pbVar5 + 1;
      }
      if (*(char *)(param_1 + 700) == '\x02') {
        uVar9 = uVar4 >> 10 & DAT_0000d42c;
        uVar11 = uVar4 & 0xffff;
        for (iVar10 = 1; iVar10 != uVar7 + 1; iVar10 = iVar10 + 1) {
          if (*(char *)(*(int *)(param_1 + 0x2c0) + iVar10 + -1) == '\0') {
            uVar4 = (uint)*(ushort *)((iVar10 + DAT_0000d428) * 2 + *(int *)(param_1 + 0x2c4));
            uVar11 = uVar4 * uVar11 >> 8;
            uVar9 = uVar4 * uVar9 >> 8;
          }
        }
        uVar18 = (uint)*(ushort *)(*(int *)(param_1 + 0x2cc) + 6);
        uVar9 = uVar9 * uVar18 >> 3;
        uVar4 = DAT_0000d428;
        if (uVar9 <= DAT_0000d42c) {
          uVar4 = uVar9 * 0x400 + (uVar11 * uVar18 >> 3);
        }
      }
      if (uVar4 < local_48) {
        local_40 = *(undefined1 **)(param_1 + 0x1bc);
        local_48 = uVar4;
      }
    }
    if (uVar15 != 0x80) goto LAB_0000d4ce;
    iVar10 = *(int *)(param_1 + 0x1c0);
    for (uVar15 = 0; uVar15 < uVar12; uVar15 = uVar15 + 1) {
      *(char *)(iVar10 + uVar15 + 1) = puVar8[uVar15 + 1] - *(char *)(iVar16 + uVar15 + 1);
    }
    iVar2 = -uVar12;
    for (; uVar12 < uVar13; uVar12 = uVar12 + 1) {
      bVar1 = *(byte *)(iVar16 + 1 + uVar12);
      bVar3 = *(byte *)(iVar16 + iVar2 + uVar12 + 1);
      iVar19 = (uint)bVar1 - (uint)bVar3;
      iVar6 = (uint)(byte)puVar8[uVar12 + iVar2 + 1] - (uint)bVar3;
      uVar4 = iVar19 + (iVar19 >> 0x1f) ^ iVar19 >> 0x1f;
      uVar15 = iVar6 + (iVar6 >> 0x1f) ^ iVar6 >> 0x1f;
      uVar9 = iVar6 + iVar19 >> 0x1f;
      uVar9 = iVar6 + iVar19 + uVar9 ^ uVar9;
      if ((((int)uVar9 < (int)uVar4) ||
          (bVar14 = puVar8[uVar12 + iVar2 + 1], (int)uVar15 < (int)uVar4)) &&
         (bVar14 = bVar1, (int)uVar9 < (int)uVar15)) {
        bVar14 = bVar3;
      }
      *(byte *)(iVar10 + 1 + uVar12) = puVar8[uVar12 + 1] - bVar14;
    }
  }
  local_40 = *(undefined1 **)(param_1 + 0x1c0);
LAB_0000d6c6:
  FUN_0000cd30(param_1,local_40);
  if (*(char *)(param_1 + DAT_0000d708) != '\0') {
    for (iVar16 = 1; iVar16 < (int)uVar7; iVar16 = iVar16 + 1) {
      *(undefined1 *)(*(int *)(param_1 + 0x2c0) + iVar16) =
           *(undefined1 *)(*(int *)(param_1 + 0x2c0) + iVar16 + -1);
    }
    *(undefined1 *)(*(int *)(param_1 + 0x2c0) + iVar16) = *local_40;
  }
  return;
}

/* === FUN_0000d70c @ 0x0000d70c === */

void FUN_0000d70c(int param_1,int param_2,undefined4 param_3,char param_4,uint param_5,int param_6,
                 int param_7,uint param_8)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined1 local_44;
  undefined1 local_40;
  undefined1 local_38;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  char local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  int local_1c;
  
  iVar5 = DAT_0000da3c + 0xd718;
  local_1c = **(int **)(iVar5 + DAT_0000da40);
  if (param_5 < 7) {
                    /* WARNING: Could not emulate address calculation at 0x0000d730 */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(int *)(param_5 * 4 + DAT_0000da44 + 0xd732) + DAT_0000da44 + 0xd732))();
    return;
  }
  FUN_00009d40(param_1,DAT_0000da60 + 0xd7c8);
  if (param_6 != 0) {
    FUN_00009c4c(param_1,DAT_0000da64 + 0xd7da);
  }
  if (((((-1 < *(int *)(param_1 + 0x2f4) << 0x1d) || (*(int *)(param_1 + 300) << 0x13 < 0)) ||
       ((param_5 != 6 && (param_5 != 2)))) || (param_7 != 0x40)) && (param_7 != 0)) {
    FUN_00009c4c(param_1,DAT_0000da68 + 0xd80e);
    param_7 = 0;
  }
  if (1 < param_8) {
    FUN_00009c4c(param_1,DAT_0000da6c + 0xd822);
    param_8 = 1;
  }
  *(char *)(param_1 + DAT_0000da70) = param_4;
  local_38 = (undefined1)param_5;
  *(undefined1 *)(param_1 + 0x1ea) = local_38;
  local_40 = (undefined1)param_8;
  *(undefined1 *)(param_1 + DAT_0000da74) = local_40;
  local_44 = (undefined1)param_7;
  *(undefined1 *)(param_1 + 0x2fc) = local_44;
  *(undefined1 *)(param_1 + 0x324) = 0;
  *(int *)(param_1 + 0x18c) = param_2;
  *(undefined4 *)(param_1 + 400) = param_3;
  bVar3 = param_4 * *(char *)(param_1 + 0x1ee);
  *(byte *)(param_1 + DAT_0000da78) = bVar3;
  if (bVar3 < 8) {
    uVar4 = (uint)bVar3 * param_2 + 7 >> 3;
  }
  else {
    uVar4 = (uint)(bVar3 >> 3) * param_2;
  }
  *(uint *)(param_1 + 0x19c) = uVar4;
  *(int *)(param_1 + 0x198) = param_2;
  *(char *)(param_1 + 0x1ec) = param_4;
  *(undefined1 *)(param_1 + DAT_0000da7c) = *(undefined1 *)(param_1 + 0x1ee);
  FUN_0000b5b4(auStack_2c,param_2);
  FUN_0000b5b4(auStack_28,param_3);
  local_23 = local_38;
  local_22 = 0;
  local_21 = local_44;
  local_20 = local_40;
  local_24 = param_4;
  FUN_0000c3c0(param_1,*(undefined4 *)(iVar5 + DAT_0000da80),auStack_2c,0xd);
  iVar2 = DAT_0000da8c;
  uVar1 = *(undefined4 *)(iVar5 + DAT_0000da88);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(iVar5 + DAT_0000da84);
  *(undefined4 *)(param_1 + 0x15c) = uVar1;
  *(int *)(param_1 + 0x160) = param_1;
  if (*(char *)(param_1 + iVar2) == '\0') {
    if ((*(char *)(param_1 + 0x1ea) == '\x03') || (*(byte *)(param_1 + DAT_0000da70) < 8)) {
      *(undefined1 *)(param_1 + DAT_0000da8c) = 8;
    }
    else {
      *(undefined1 *)(param_1 + iVar2) = 0xf8;
    }
  }
  if ((*(uint *)(param_1 + 0x130) & 1) == 0) {
    if (*(char *)(param_1 + DAT_0000da8c) == '\b') {
      *(undefined4 *)(param_1 + 0x188) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x188) = 1;
    }
  }
  if (-1 < *(int *)(param_1 + 0x130) << 0x1e) {
    *(undefined4 *)(param_1 + 0x178) = 0xffffffff;
  }
  if (-1 < *(int *)(param_1 + 0x130) << 0x1d) {
    *(undefined4 *)(param_1 + 0x184) = 8;
  }
  if (-1 < *(int *)(param_1 + 0x130) << 0x1c) {
    *(undefined4 *)(param_1 + 0x180) = 0xf;
  }
  if (-1 < *(int *)(param_1 + 0x130) << 0x1b) {
    *(undefined4 *)(param_1 + 0x17c) = 8;
  }
  iVar2 = deflateInit2_(param_1 + 0x138,*(undefined4 *)(param_1 + 0x178),
                        *(undefined4 *)(param_1 + 0x17c),*(undefined4 *)(param_1 + 0x180),
                        *(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x188),
                        DAT_0000da90 + 0xd9e2,0x38);
  if (iVar2 == 0) goto LAB_0000da1a;
  if (iVar2 == -6) {
    iVar2 = DAT_0000da94 + 0xd9f8;
LAB_0000da0a:
    FUN_00009d40(param_1,iVar2);
  }
  else {
    if (iVar2 == -2) {
      iVar2 = DAT_0000da98 + 0xda02;
      goto LAB_0000da0a;
    }
    if (iVar2 == -4) {
      iVar2 = DAT_0000da9c + 0xda0c;
      goto LAB_0000da0a;
    }
  }
  FUN_00009d40(param_1,DAT_0000daa0 + 0xda18);
LAB_0000da1a:
  piVar6 = *(int **)(iVar5 + DAT_0000da40);
  *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(param_1 + 0x174);
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 300) = 1;
  if (local_1c != *piVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

/* === FUN_0000daa8 @ 0x0000daa8 === */

undefined4 FUN_0000daa8(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(char *)(param_1 + DAT_0000dac8) == '\0')) {
    uVar1 = 1;
  }
  else {
    *(uint *)(param_1 + 0x134) = *(uint *)(param_1 + 0x134) | 2;
    uVar1 = 7;
  }
  return uVar1;
}

/* === FUN_0000dacc @ 0x0000dacc === */

void FUN_0000dacc(int param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 8) == '\0') {
    uVar1 = *(uint *)(param_1 + 4);
    for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1) {
      param_2[uVar2] = ~param_2[uVar2];
    }
  }
  else if (*(ushort *)(param_1 + 8) == DAT_0000db24) {
    uVar2 = *(uint *)(param_1 + 4);
    for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 2) {
      param_2[uVar1] = ~param_2[uVar1];
    }
  }
  else if (*(ushort *)(param_1 + 8) == DAT_0000db28) {
    uVar2 = *(uint *)(param_1 + 4);
    for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 4) {
      *param_2 = ~*param_2;
      param_2[1] = ~param_2[1];
      param_2 = param_2 + 4;
    }
  }
  return;
}

/* === FUN_0000db2c @ 0x0000db2c === */

void FUN_0000db2c(int *param_1,undefined1 *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)((int)param_1 + 9) == '\x10') {
    bVar1 = *(byte *)((int)param_1 + 10);
    iVar3 = *param_1;
    for (uVar4 = 0; uVar4 < (uint)bVar1 * iVar3; uVar4 = uVar4 + 1) {
      uVar2 = param_2[1];
      param_2[1] = *param_2;
      *param_2 = uVar2;
      param_2 = param_2 + 2;
    }
  }
  return;
}

/* === FUN_0000db54 @ 0x0000db54 === */

void FUN_0000db54(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 9);
  if (bVar1 < 8) {
    pbVar2 = param_2 + *(int *)(param_1 + 4);
    if (bVar1 == 1) {
      iVar3 = DAT_0000db8c + 0xdb68;
    }
    else if (bVar1 == 2) {
      iVar3 = DAT_0000db90 + 0xdb72;
    }
    else {
      if (bVar1 != 4) {
        return;
      }
      iVar3 = DAT_0000db94 + 0xdb7c;
    }
    for (; param_2 < pbVar2; param_2 = param_2 + 1) {
      *param_2 = *(byte *)(iVar3 + (uint)*param_2);
    }
  }
  return;
}

/* === FUN_0000db98 @ 0x0000db98 === */

void FUN_0000db98(uint *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  
  cVar2 = (char)param_1[2];
  uVar4 = *param_1;
  if (cVar2 == '\x02') {
LAB_0000dbac:
    if (*(char *)((int)param_1 + 10) != '\x04') goto LAB_0000dc6a;
    if (*(char *)((int)param_1 + 9) == '\b') {
      if (param_3 << 0x18 < 0) {
        uVar7 = 1;
        puVar5 = param_2;
        while( true ) {
          if (uVar4 <= uVar7) break;
          uVar7 = uVar7 + 1;
          puVar5[3] = param_2[4];
          puVar5[4] = param_2[5];
          puVar5[5] = param_2[6];
          param_2 = param_2 + 4;
          puVar5 = puVar5 + 3;
        }
      }
      else {
        puVar5 = param_2;
        for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
          *param_2 = puVar5[1];
          param_2[1] = puVar5[2];
          puVar1 = puVar5 + 3;
          puVar5 = puVar5 + 4;
          param_2[2] = *puVar1;
          param_2 = param_2 + 3;
        }
      }
      *(undefined1 *)((int)param_1 + 0xb) = 0x18;
      iVar6 = 3;
    }
    else {
      if (param_3 << 0x18 < 0) {
        uVar7 = 1;
        puVar5 = param_2;
        while( true ) {
          if (uVar4 <= uVar7) break;
          uVar7 = uVar7 + 1;
          param_2[6] = puVar5[8];
          param_2[7] = puVar5[9];
          param_2[8] = puVar5[10];
          param_2[9] = puVar5[0xb];
          param_2[10] = puVar5[0xc];
          param_2[0xb] = puVar5[0xd];
          param_2 = param_2 + 6;
          puVar5 = puVar5 + 8;
        }
      }
      else {
        puVar5 = param_2;
        for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
          *param_2 = puVar5[2];
          param_2[1] = puVar5[3];
          param_2[2] = puVar5[4];
          param_2[3] = puVar5[5];
          param_2[4] = puVar5[6];
          puVar1 = puVar5 + 7;
          puVar5 = puVar5 + 8;
          param_2[5] = *puVar1;
          param_2 = param_2 + 6;
        }
      }
      *(undefined1 *)((int)param_1 + 0xb) = 0x30;
      iVar6 = 6;
    }
    uVar3 = 3;
    param_1[1] = uVar4 * iVar6;
  }
  else {
    if (cVar2 == '\x06') {
      if (-1 < param_3 << 9) goto LAB_0000dcf6;
      goto LAB_0000dbac;
    }
LAB_0000dc6a:
    if (((cVar2 != '\0') && ((cVar2 != '\x04' || (-1 < param_3 << 9)))) ||
       (*(char *)((int)param_1 + 10) != '\x02')) goto LAB_0000dcf6;
    if (*(char *)((int)param_1 + 9) == '\b') {
      if (param_3 << 0x18 < 0) {
        puVar5 = param_2;
        for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 2;
          param_2[uVar7] = uVar3;
        }
      }
      else {
        puVar5 = param_2;
        for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
          puVar1 = puVar5 + 1;
          puVar5 = puVar5 + 2;
          param_2[uVar7] = *puVar1;
        }
      }
      *(undefined1 *)((int)param_1 + 0xb) = 8;
    }
    else {
      if (param_3 << 0x18 < 0) {
        uVar7 = 1;
        puVar5 = param_2;
        while( true ) {
          if (uVar4 <= uVar7) break;
          uVar7 = uVar7 + 1;
          param_2[2] = puVar5[4];
          param_2[3] = puVar5[5];
          param_2 = param_2 + 2;
          puVar5 = puVar5 + 4;
        }
      }
      else {
        puVar5 = param_2;
        for (uVar7 = 0; uVar7 < uVar4; uVar7 = uVar7 + 1) {
          *param_2 = puVar5[2];
          puVar1 = puVar5 + 3;
          puVar5 = puVar5 + 4;
          param_2[1] = *puVar1;
          param_2 = param_2 + 2;
        }
      }
      *(undefined1 *)((int)param_1 + 0xb) = 0x10;
      uVar4 = uVar4 << 1;
    }
    param_1[1] = uVar4;
    uVar3 = 1;
  }
  *(undefined1 *)((int)param_1 + 10) = uVar3;
LAB_0000dcf6:
  if (param_3 << 9 < 0) {
    *(byte *)(param_1 + 2) = (byte)param_1[2] & 0xfb;
  }
  return;
}

/* === FUN_0000dd04 @ 0x0000dd04 === */

void FUN_0000dd04(uint *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)param_1[2];
  if ((int)(uVar3 << 0x1e) < 0) {
    uVar2 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      if (uVar3 == 2) {
        for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
          uVar1 = param_2[2];
          param_2[2] = *param_2;
          *param_2 = uVar1;
          param_2 = param_2 + 3;
        }
      }
      else if (uVar3 == 6) {
        for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
          uVar1 = param_2[2];
          param_2[2] = *param_2;
          *param_2 = uVar1;
          param_2 = param_2 + 4;
        }
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      if (uVar3 == 2) {
        for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
          uVar1 = param_2[4];
          param_2[4] = *param_2;
          *param_2 = uVar1;
          uVar1 = param_2[5];
          param_2[5] = param_2[1];
          param_2[1] = uVar1;
          param_2 = param_2 + 6;
        }
      }
      else if (uVar3 == 6) {
        for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
          uVar1 = param_2[4];
          param_2[4] = *param_2;
          *param_2 = uVar1;
          uVar1 = param_2[5];
          param_2[5] = param_2[1];
          param_2[1] = uVar1;
          param_2 = param_2 + 8;
        }
      }
    }
  }
  return;
}

/* === FUN_0000dd90 @ 0x0000dd90 === */

uint FUN_0000dd90(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    FUN_0000e7fc();
    return 0;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    return param_1 >> (0x1fU - LZCOUNT(param_2) & 0xff);
  }
  uVar1 = param_2 << (LZCOUNT(param_2) - LZCOUNT(param_1) & 0xffU);
  uVar3 = 1 << (LZCOUNT(param_2) - LZCOUNT(param_1) & 0xffU);
  uVar2 = 0;
  while( true ) {
    if (uVar1 <= param_1) {
      param_1 = param_1 - uVar1;
      uVar2 = uVar2 | uVar3;
    }
    if (uVar1 >> 1 <= param_1) {
      param_1 = param_1 - (uVar1 >> 1);
      uVar2 = uVar2 | uVar3 >> 1;
    }
    if (uVar1 >> 2 <= param_1) {
      param_1 = param_1 - (uVar1 >> 2);
      uVar2 = uVar2 | uVar3 >> 2;
    }
    if (uVar1 >> 3 <= param_1) {
      param_1 = param_1 - (uVar1 >> 3);
      uVar2 = uVar2 | uVar3 >> 3;
    }
    bVar4 = param_1 == 0;
    if (!bVar4) {
      uVar3 = uVar3 >> 4;
      bVar4 = uVar3 == 0;
    }
    if (bVar4) break;
    uVar1 = uVar1 >> 4;
  }
  return uVar2;
}

/* === FUN_0000de3c @ 0x0000de3c === */

void FUN_0000de3c(void)

{
  FUN_0000dd90();
  return;
}

/* === FUN_0000de60 @ 0x0000de60 === */

ulonglong FUN_0000de60(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  uVar9 = param_2 << 1;
  uVar5 = param_4 << 1;
  iVar8 = (int)uVar9 >> 0x15;
  iVar1 = (int)uVar5 >> 0x15;
  if ((((uVar9 == uVar5 && param_1 == param_3 || uVar9 == 0 && param_1 == 0) ||
       uVar5 == 0 && param_3 == 0) || iVar8 == -1) || iVar1 == -1) {
    if (iVar8 == -1 || iVar1 == -1) {
      uVar9 = param_3;
      uVar5 = param_4;
      if (iVar8 == -1) {
        uVar9 = param_1;
        uVar5 = param_2;
      }
      if (iVar8 != -1 || iVar1 != -1) {
        param_3 = uVar9;
        param_4 = uVar5;
      }
      bVar14 = (uVar5 & 0xfffff) == 0;
      bVar15 = uVar9 == 0 && bVar14;
      if (uVar9 == 0 && bVar14) {
        bVar15 = param_3 == 0 && (param_4 & 0xfffff) == 0;
      }
      if (!bVar15 || uVar5 != param_4) {
        uVar5 = uVar5 | 0x80000;
      }
      return CONCAT44(uVar5,uVar9);
    }
    if (uVar9 != uVar5 || param_1 != param_3) {
      if (uVar9 == 0 && param_1 == 0) {
        param_1 = param_3;
        param_2 = param_4;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != param_4) {
      return 0;
    }
    if ((param_2 & 0x7fffffff) >> 0x14 == 0) {
      bVar2 = (byte)(param_1 >> 0x1f);
      uVar9 = param_2 * 2 + (uint)bVar2;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar2)) {
        uVar9 = uVar9 | 0x80000000;
      }
      return CONCAT44(uVar9,param_1 << 1);
    }
    if (uVar9 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_0000e0d0:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar9 = (param_2 & 0x7fffffff) >> 0x14;
  uVar5 = (param_4 & 0x7fffffff) >> 0x14;
  uVar11 = uVar5 - uVar9;
  bVar14 = uVar11 != 0;
  if (uVar5 < uVar9) {
    uVar11 = -uVar11;
  }
  uVar10 = param_1;
  uVar7 = param_2;
  if (bVar14 && uVar9 <= uVar5) {
    uVar9 = uVar9 + uVar11;
    uVar10 = param_3;
    uVar7 = param_4;
    param_3 = param_1;
    param_4 = param_2;
  }
  if (0x36 < uVar11) {
    return CONCAT44(uVar7,uVar10);
  }
  uVar5 = uVar7 & 0xfffff | 0x100000;
  if ((uVar7 & 0x80000000) != 0) {
    bVar14 = uVar10 != 0;
    uVar10 = -uVar10;
    uVar5 = -(uVar5 + bVar14);
  }
  uVar7 = param_4 & 0xfffff | 0x100000;
  if ((param_4 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar7 = -(uVar7 + bVar14);
  }
  if (uVar9 == uVar11) {
    uVar7 = uVar7 ^ 0x100000;
    if (uVar9 == 0) {
      uVar5 = uVar5 ^ 0x100000;
      uVar9 = 1;
    }
    else {
      uVar11 = uVar11 - 1;
    }
  }
  uVar13 = -uVar11 + 0x20;
  if ((int)uVar11 < 0x21) {
    uVar12 = param_3 << (uVar13 & 0xff);
    param_3 = param_3 >> (uVar11 & 0xff);
    uVar4 = uVar10 + param_3;
    uVar6 = uVar7 << (uVar13 & 0xff);
    uVar13 = uVar4 + uVar6;
    uVar5 = uVar5 + CARRY4(uVar10,param_3) + ((int)uVar7 >> (uVar11 & 0xff)) +
            (uint)CARRY4(uVar4,uVar6);
  }
  else {
    uVar12 = uVar7 << (-uVar11 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar12 = uVar12 | 2;
    }
    uVar11 = (int)uVar7 >> (uVar11 - 0x20 & 0xff);
    uVar13 = uVar10 + uVar11;
    uVar5 = uVar5 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar10,uVar11);
  }
  param_2 = uVar5 & 0x80000000;
  uVar11 = uVar5;
  if ((int)uVar5 < 0) {
    bVar14 = uVar12 == 0;
    uVar12 = -uVar12;
    uVar11 = -uVar13;
    uVar13 = -(uVar13 + !bVar14);
    uVar11 = -(uVar5 + (bVar14 <= uVar11));
  }
  if (0xfffff < uVar11) {
    uVar10 = uVar9 - 1;
    if (0x1fffff < uVar11) {
      bVar2 = (byte)uVar11;
      uVar11 = uVar11 >> 1;
      bVar3 = (byte)uVar13;
      uVar13 = (uint)(bVar2 & 1) << 0x1f | uVar13 >> 1;
      uVar12 = (uint)(bVar3 & 1) << 0x1f | uVar12 >> 1;
      uVar10 = uVar9;
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_0000e0d0;
    }
LAB_0000df78:
    bVar14 = 0x7fffffff < uVar12;
    if (uVar12 == 0x80000000) {
      bVar14 = (bool)((byte)uVar13 & 1);
    }
    return CONCAT44(uVar11 + uVar10 * 0x100000 + (uint)CARRY4(uVar13,(uint)bVar14) | param_2,
                    uVar13 + bVar14);
  }
  bVar2 = (byte)(uVar12 >> 0x1f);
  uVar12 = uVar12 << 1;
  uVar10 = uVar13 * 2;
  bVar14 = CARRY4(uVar13,uVar13);
  uVar13 = uVar13 * 2 + (uint)bVar2;
  uVar11 = uVar11 * 2 + (uint)(bVar14 || CARRY4(uVar10,(uint)bVar2));
  uVar10 = uVar9 - 2;
  if ((uVar11 & 0x100000) != 0) goto LAB_0000df78;
  uVar9 = uVar13;
  uVar7 = uVar11;
  if (uVar11 == 0) {
    uVar9 = 0;
    uVar7 = uVar13;
  }
  iVar8 = LZCOUNT(uVar7);
  if (uVar11 == 0) {
    iVar8 = iVar8 + 0x20;
  }
  uVar4 = iVar8 - 0xb;
  bVar15 = SBORROW4(uVar4,0x20);
  uVar6 = iVar8 - 0x2b;
  bVar14 = uVar6 == 0;
  uVar11 = uVar6;
  uVar13 = uVar6;
  if ((int)uVar4 < 0x20) {
    bVar15 = SCARRY4(uVar6,0xc);
    uVar13 = iVar8 - 0x1f;
    bVar14 = uVar13 == 0;
    uVar11 = uVar4;
    if (!bVar14 && -0xd < (int)uVar6) {
      uVar9 = uVar7 << (uVar4 & 0xff);
      uVar7 = uVar7 >> (0xc - uVar13 & 0xff);
      goto LAB_0000dff8;
    }
  }
  if (bVar14 || (int)uVar13 < 0 != bVar15) {
    uVar12 = 0x20 - uVar11;
  }
  uVar7 = uVar7 << (uVar11 & 0xff);
  if (bVar14 || (int)uVar13 < 0 != bVar15) {
    uVar7 = uVar7 | uVar9 >> (uVar12 & 0xff);
    uVar9 = uVar9 << (uVar11 & 0xff);
  }
LAB_0000dff8:
  if ((int)uVar4 <= (int)uVar10) {
    return CONCAT44(uVar7 + (uVar10 - uVar4) * 0x100000 | param_2,uVar9);
  }
  uVar11 = ~(uVar10 - uVar4);
  if ((int)uVar11 < 0x1f) {
    if (uVar11 - 0x13 != 0 && -0xd < (int)(uVar11 - 0x1f)) {
      uVar11 = 0xc - (uVar11 - 0x13);
      return CONCAT44(uVar5,uVar9 >> (0x20 - uVar11 & 0xff) | uVar7 << (uVar11 & 0xff)) &
             0x80000000ffffffff;
    }
    uVar11 = uVar11 + 1;
    return CONCAT44(param_2 | uVar7 >> (uVar11 & 0xff),
                    uVar9 >> (uVar11 & 0xff) | uVar7 << (0x20 - uVar11 & 0xff));
  }
  return CONCAT44(uVar5,uVar7 >> (uVar11 - 0x1f & 0xff)) & 0x80000000ffffffff;
}

/* === FUN_0000e158 @ 0x0000e158 === */

ulonglong FUN_0000e158(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint in_r12;
  bool bVar10;
  bool bVar11;
  
  uVar2 = param_1 << 1;
  bVar10 = uVar2 == 0;
  uVar9 = param_1 & 0x80000000;
  uVar8 = (uint)((int)uVar2 >> 3) >> 1;
  uVar1 = uVar9 | uVar8;
  param_1 = param_1 << 0x1d;
  if (!bVar10) {
    param_4 = uVar2 & 0xff000000;
    bVar10 = param_4 == 0;
  }
  if (!bVar10) {
    bVar10 = param_4 == 0xff000000;
  }
  if (!bVar10) {
    return CONCAT44(uVar1,param_1) ^ 0x3800000000000000;
  }
  if (uVar2 == 0 || param_4 == 0xff000000) {
    return CONCAT44(uVar1,param_1);
  }
  uVar2 = param_1;
  uVar3 = uVar8;
  if (uVar8 == 0) {
    uVar2 = 0;
    uVar3 = param_1;
  }
  iVar6 = LZCOUNT(uVar3);
  if (uVar8 == 0) {
    iVar6 = iVar6 + 0x20;
  }
  uVar7 = iVar6 - 0xb;
  bVar11 = SBORROW4(uVar7,0x20);
  uVar4 = iVar6 - 0x2b;
  bVar10 = uVar4 == 0;
  uVar8 = uVar4;
  uVar5 = uVar4;
  if ((int)uVar7 < 0x20) {
    bVar11 = SCARRY4(uVar4,0xc);
    uVar5 = iVar6 - 0x1f;
    bVar10 = uVar5 == 0;
    uVar8 = uVar7;
    if (!bVar10 && -0xd < (int)uVar4) {
      uVar2 = uVar3 << (uVar7 & 0xff);
      uVar3 = uVar3 >> (0xc - uVar5 & 0xff);
      goto LAB_0000dff8;
    }
  }
  if (bVar10 || (int)uVar5 < 0 != bVar11) {
    in_r12 = 0x20 - uVar8;
  }
  uVar3 = uVar3 << (uVar8 & 0xff);
  if (bVar10 || (int)uVar5 < 0 != bVar11) {
    uVar3 = uVar3 | uVar2 >> (in_r12 & 0xff);
    uVar2 = uVar2 << (uVar8 & 0xff);
  }
LAB_0000dff8:
  if ((int)uVar7 < 0x381) {
    return CONCAT44(uVar3 + (0x380 - uVar7) * 0x100000 | uVar9,uVar2);
  }
  uVar8 = ~(0x380 - uVar7);
  if ((int)uVar8 < 0x1f) {
    if (uVar8 - 0x13 != 0 && -0xd < (int)(uVar8 - 0x1f)) {
      uVar9 = 0xc - (uVar8 - 0x13);
      return CONCAT44(uVar1,uVar2 >> (0x20 - uVar9 & 0xff) | uVar3 << (uVar9 & 0xff)) &
             0x80000000ffffffff;
    }
    uVar8 = uVar8 + 1;
    return CONCAT44(uVar9 | uVar3 >> (uVar8 & 0xff),
                    uVar2 >> (uVar8 & 0xff) | uVar3 << (0x20 - uVar8 & 0xff));
  }
  return CONCAT44(uVar1,uVar3 >> (uVar8 - 0x1f & 0xff)) & 0x80000000ffffffff;
}

/* === FUN_0000e20c @ 0x0000e20c === */

ulonglong FUN_0000e20c(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  uint uVar4;
  uint extraout_r2;
  uint extraout_r3;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint extraout_r12;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  uVar14 = CONCAT44(param_2,param_1);
  uVar10 = 0x7ff;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar11 = uVar6 == 0;
  if (!bVar11) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar11 = unaff_r5 == 0;
  }
  if (!bVar11) {
    bVar11 = uVar6 == 0x7ff;
  }
  if (!bVar11) {
    bVar11 = unaff_r5 == 0x7ff;
  }
  if (bVar11) {
    uVar14 = FUN_0000e3ec();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar10 = extraout_r12;
  }
  uVar4 = (uint)(uVar14 >> 0x20);
  iVar7 = uVar6 + unaff_r5;
  uVar9 = uVar4 ^ param_4;
  uVar4 = uVar4 & ~(uVar10 << 0x15);
  param_4 = param_4 & ~(uVar10 << 0x15);
  uVar6 = uVar4 | 0x100000;
  uVar5 = param_4 | 0x100000;
  if ((uint)uVar14 == 0 && (uVar4 & 0xfffff) == 0 || param_3 == 0 && (param_4 & 0xfffff) == 0) {
    param_3 = (uint)uVar14 | param_3;
    uVar5 = (uVar9 & 0x80000000 | uVar6) ^ uVar5;
    uVar6 = uVar10 >> 1;
    bVar13 = SBORROW4(iVar7,uVar6);
    uVar8 = iVar7 - uVar6;
    bVar11 = uVar8 == 0;
    uVar4 = uVar8;
    if (!bVar11 && (int)uVar6 <= iVar7) {
      bVar13 = SBORROW4(uVar10,uVar8);
      uVar4 = uVar10 - uVar8;
      bVar11 = uVar10 == uVar8;
    }
    if (!bVar11 && (int)uVar4 < 0 == bVar13) {
      return CONCAT44(uVar5 | uVar8 * 0x100000,param_3);
    }
    uVar5 = uVar5 | 0x100000;
    uVar10 = 0;
    bVar13 = SBORROW4(uVar8,1);
    uVar8 = uVar8 - 1;
    bVar11 = uVar8 == 0;
    uVar6 = uVar8;
  }
  else {
    uVar2 = (ulonglong)param_3 * (uVar14 & 0xffffffff);
    uVar14 = (ulonglong)uVar5 * (uVar14 & 0xffffffff) +
             (ulonglong)param_3 * (ulonglong)uVar6 + (uVar2 >> 0x20);
    uVar4 = (uint)uVar14;
    lVar1 = (ulonglong)uVar5 * (ulonglong)uVar6 + (uVar14 >> 0x20);
    uVar10 = (uint)lVar1;
    uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
    if ((int)uVar2 != 0) {
      uVar4 = uVar4 | 1;
    }
    uVar8 = (iVar7 + -0xff) - ((uVar6 < 0x200) + 0x300);
    if (uVar6 < 0x200) {
      bVar3 = (byte)(uVar4 >> 0x1f);
      uVar4 = uVar4 << 1;
      lVar1 = CONCAT44(uVar6 * 2 + (uint)(CARRY4(uVar10,uVar10) || CARRY4(uVar10 * 2,(uint)bVar3)),
                       uVar10 * 2 + (uint)bVar3);
    }
    uVar5 = uVar9 & 0x80000000 | (int)((ulonglong)lVar1 >> 0x20) << 0xb | (uint)lVar1 >> 0x15;
    param_3 = (uint)lVar1 << 0xb | uVar4 >> 0x15;
    uVar10 = uVar4 * 0x800;
    bVar12 = 0xfc < uVar8;
    bVar13 = SBORROW4(uVar8,0xfd);
    uVar9 = uVar8 - 0xfd;
    bVar11 = uVar9 == 0;
    uVar6 = uVar9;
    if (bVar12 && !bVar11) {
      bVar12 = 0x6ff < uVar9;
      bVar13 = SBORROW4(uVar9,0x700);
      uVar6 = uVar8 - 0x7fd;
      bVar11 = uVar9 == 0x700;
    }
    if (!bVar12 || bVar11) {
      bVar11 = 0x7fffffff < uVar10;
      if (uVar10 == 0x80000000) {
        bVar11 = (bool)((byte)(uVar4 >> 0x15) & 1);
      }
      return CONCAT44(uVar5 + uVar8 * 0x100000 + (uint)CARRY4(param_3,(uint)bVar11),param_3 + bVar11
                     );
    }
  }
  if (!bVar11 && (int)uVar6 < 0 == bVar13) {
    return (ulonglong)(uVar5 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if (-0x36 < (int)uVar8) {
    uVar6 = -uVar8;
    uVar4 = uVar6 - 0x20;
    if (0x1f < (int)uVar6) {
      uVar9 = param_3 >> (uVar4 & 0xff) | uVar5 << (0x20 - uVar4 & 0xff);
      uVar6 = (uVar5 >> (uVar4 & 0xff) & ~((uVar5 & 0x80000000) >> (uVar4 & 0xff))) -
              ((int)uVar9 >> 0x1f);
      if ((uVar10 == 0 && param_3 << (0x20 - uVar4 & 0xff) == 0) && (uVar9 & 0x7fffffff) == 0) {
        uVar6 = uVar6 & ~(uVar9 >> 0x1f);
      }
      return CONCAT44(uVar5,uVar6) & 0x80000000ffffffff;
    }
    if (uVar6 - 0x14 != 0 && -0xd < (int)uVar4) {
      uVar4 = 0xc - (uVar6 - 0x14);
      uVar6 = param_3 << (uVar4 & 0xff);
      uVar4 = param_3 >> (0x20 - uVar4 & 0xff) | uVar5 << (uVar4 & 0xff);
      uVar9 = uVar4 + -((int)uVar6 >> 0x1f);
      if (uVar10 == 0 && (uVar6 & 0x7fffffff) == 0) {
        uVar9 = uVar9 & ~(uVar6 >> 0x1f);
      }
      return CONCAT44((uVar5 & 0x80000000) + (uint)CARRY4(uVar4,-((int)uVar6 >> 0x1f)),uVar9);
    }
    uVar4 = param_3 << (uVar8 + 0x20 & 0xff);
    uVar9 = param_3 >> (uVar6 & 0xff) | uVar5 << (uVar8 + 0x20 & 0xff);
    uVar8 = uVar9 + -((int)uVar4 >> 0x1f);
    if (uVar10 == 0 && (uVar4 & 0x7fffffff) == 0) {
      uVar8 = uVar8 & ~(uVar4 >> 0x1f);
    }
    return CONCAT44((uVar5 & 0x80000000) + ((uVar5 & 0x7fffffff) >> (uVar6 & 0xff)) +
                    (uint)CARRY4(uVar9,-((int)uVar4 >> 0x1f)),uVar8);
  }
  return (ulonglong)(uVar5 & 0x80000000) << 0x20;
}

/* === FUN_0000e3ec @ 0x0000e3ec === */

ulonglong FUN_0000e3ec(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint unaff_r4;
  uint uVar4;
  uint uVar5;
  uint in_r12;
  
  uVar4 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 != in_r12 && uVar4 != in_r12) {
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0 || param_3 == 0 && (param_4 & 0x7fffffff) == 0)
    {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    if (unaff_r4 == 0) {
      uVar5 = param_2 & 0x80000000;
      do {
        iVar2 = param_1 >> 0x1f;
        param_1 = param_1 << 1;
        param_2 = param_2 * 2 - iVar2;
      } while ((param_2 & 0x100000) == 0);
      param_2 = param_2 | uVar5;
      if (uVar4 != 0) {
        return CONCAT44(param_2,param_1);
      }
    }
    do {
      iVar2 = param_3 >> 0x1f;
      param_3 = param_3 << 1;
      param_4 = param_4 * 2 - iVar2;
    } while ((param_4 & 0x100000) == 0);
    return CONCAT44(param_2,param_1);
  }
  bVar1 = (param_2 & 0x7fffffff) != 0;
  uVar5 = param_4;
  iVar2 = param_3;
  if (param_1 != 0 || bVar1) {
    uVar5 = param_2;
    iVar2 = param_1;
  }
  uVar3 = uVar5;
  if ((((param_1 != 0 || bVar1) && (param_3 != 0 || (param_4 & 0x7fffffff) != 0)) &&
      ((unaff_r4 != in_r12 || (iVar2 == 0 && (uVar5 & 0xfffff) == 0)))) &&
     ((uVar4 != in_r12 ||
      (iVar2 = param_3, uVar3 = param_4, param_3 == 0 && (param_4 & 0xfffff) == 0)))) {
    return (ulonglong)((uVar5 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
  }
  return CONCAT44(uVar3,iVar2) | 0x7ff8000000000000;
}

/* === FUN_0000e478 @ 0x0000e478 === */

ulonglong FUN_0000e478(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint extraout_r2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint extraout_r12;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined8 uVar16;
  
  uVar16 = CONCAT44(param_2,param_1);
  uVar11 = 0x7ff;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar13 = uVar6 == 0;
  if (!bVar13) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar13 = unaff_r5 == 0;
  }
  if (!bVar13) {
    bVar13 = uVar6 == 0x7ff;
  }
  if (!bVar13) {
    bVar13 = unaff_r5 == 0x7ff;
  }
  if (bVar13) {
    uVar16 = FUN_0000e60c();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar11 = extraout_r12;
  }
  uVar8 = (uint)((ulonglong)uVar16 >> 0x20);
  uVar2 = (uint)uVar16;
  iVar7 = uVar6 - unaff_r5;
  if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
    uVar6 = (uVar8 ^ param_4) & 0x80000000 | uVar8 & 0xfffff;
    bVar14 = SCARRY4(iVar7,uVar11 >> 1);
    uVar8 = iVar7 + (uVar11 >> 1);
    bVar13 = (int)uVar8 < 0;
    bVar15 = uVar8 == 0;
    if (!bVar15 && bVar13 == bVar14) {
      bVar14 = SBORROW4(uVar11,uVar8);
      bVar13 = (int)(uVar11 - uVar8) < 0;
      bVar15 = uVar11 == uVar8;
    }
    if (!bVar15 && bVar13 == bVar14) {
      return CONCAT44(uVar6 | uVar8 * 0x100000,uVar2);
    }
    uVar6 = uVar6 | 0x100000;
    uVar4 = 0;
    bVar15 = SBORROW4(uVar8,1);
    uVar8 = uVar8 - 1;
    bVar13 = uVar8 == 0;
    uVar11 = uVar8;
  }
  else {
    uVar4 = (param_4 & 0xfffff) << 8 | 0x10000000 | param_3 >> 0x18;
    uVar11 = param_3 << 8;
    uVar9 = (uVar8 & 0xfffff) << 8 | 0x10000000 | uVar2 >> 0x18;
    uVar2 = uVar2 * 0x100;
    uVar6 = (uVar8 ^ param_4) & 0x80000000;
    bVar13 = uVar4 <= uVar9;
    if (uVar9 == uVar4) {
      bVar13 = uVar11 <= uVar2;
    }
    iVar7 = iVar7 + (uint)bVar13;
    uVar8 = iVar7 + 0x3fd;
    if (!bVar13) {
      uVar4 = uVar4 >> 1;
      uVar11 = (uint)((byte)(param_3 >> 0x18) & 1) << 0x1f | (param_3 & 0xffffff) << 7;
    }
    uVar10 = uVar2 - uVar11;
    uVar9 = uVar9 - (uVar4 + (uVar2 < uVar11));
    uVar5 = uVar4 >> 1;
    uVar3 = (uint)((byte)uVar4 & 1) << 0x1f | uVar11 >> 1;
    uVar2 = 0x100000;
    uVar11 = 0x80000;
    while( true ) {
      bVar13 = uVar3 <= uVar10;
      if (uVar5 < uVar9 || uVar9 - uVar5 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11;
        uVar9 = uVar9 - (uVar5 + !bVar13);
      }
      uVar4 = uVar5 >> 1;
      uVar3 = (uint)((byte)uVar5 & 1) << 0x1f | uVar3 >> 1;
      bVar13 = uVar3 <= uVar10;
      if (uVar4 < uVar9 || uVar9 - uVar4 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11 >> 1;
        uVar9 = uVar9 - (uVar4 + !bVar13);
      }
      uVar12 = uVar5 >> 2;
      uVar1 = (uint)((byte)uVar4 & 1) << 0x1f | uVar3 >> 1;
      bVar13 = uVar1 <= uVar10;
      if (uVar12 < uVar9 || uVar9 - uVar12 < (uint)bVar13) {
        uVar10 = uVar10 - uVar1;
        uVar2 = uVar2 | uVar11 >> 2;
        uVar9 = uVar9 - (uVar12 + !bVar13);
      }
      uVar5 = uVar5 >> 3;
      uVar3 = (uint)((byte)uVar12 & 1) << 0x1f | uVar1 >> 1;
      bVar13 = uVar3 <= uVar10;
      if (uVar5 < uVar9 || uVar9 - uVar5 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11 >> 3;
        uVar9 = uVar9 - (uVar5 + !bVar13);
      }
      uVar4 = uVar9 | uVar10;
      if (uVar4 == 0) break;
      uVar9 = uVar9 << 4 | uVar10 >> 0x1c;
      uVar10 = uVar10 << 4;
      uVar5 = uVar5 << 3 | uVar3 >> 0x1d;
      uVar3 = (uVar1 >> 1) << 3;
      uVar11 = uVar11 >> 4;
      if (uVar11 == 0) {
        if ((uVar6 & 0x100000) != 0) goto LAB_0000e5b8;
        uVar6 = uVar6 | uVar2;
        uVar2 = 0;
        uVar11 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar2;
      uVar2 = 0;
    }
LAB_0000e5b8:
    bVar14 = 0xfc < uVar8;
    bVar15 = SBORROW4(uVar8,0xfd);
    uVar12 = iVar7 + 0x300;
    bVar13 = uVar12 == 0;
    uVar11 = uVar12;
    if (bVar14 && !bVar13) {
      bVar14 = 0x6ff < uVar12;
      bVar15 = SBORROW4(uVar12,0x700);
      uVar11 = iVar7 - 0x400;
      bVar13 = uVar12 == 0x700;
    }
    if (!bVar14 || bVar13) {
      bVar13 = uVar5 <= uVar9;
      if (uVar9 == uVar5) {
        bVar13 = uVar3 <= uVar10;
      }
      if (uVar9 == uVar5 && uVar10 == uVar3) {
        bVar13 = (bool)((byte)uVar2 & 1);
      }
      return CONCAT44(uVar6 + uVar8 * 0x100000 + (uint)CARRY4(uVar2,(uint)bVar13),uVar2 + bVar13);
    }
  }
  if (!bVar13 && (int)uVar11 < 0 == bVar15) {
    return (ulonglong)(uVar6 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if ((int)uVar8 < -0x35) {
    return (ulonglong)(uVar6 & 0x80000000) << 0x20;
  }
  uVar11 = -uVar8;
  uVar9 = uVar11 - 0x20;
  if (0x1f < (int)uVar11) {
    uVar8 = uVar2 >> (uVar9 & 0xff) | uVar6 << (0x20 - uVar9 & 0xff);
    uVar11 = (uVar6 >> (uVar9 & 0xff) & ~((uVar6 & 0x80000000) >> (uVar9 & 0xff))) -
             ((int)uVar8 >> 0x1f);
    if ((uVar4 == 0 && uVar2 << (0x20 - uVar9 & 0xff) == 0) && (uVar8 & 0x7fffffff) == 0) {
      uVar11 = uVar11 & ~(uVar8 >> 0x1f);
    }
    return CONCAT44(uVar6,uVar11) & 0x80000000ffffffff;
  }
  if (uVar11 - 0x14 != 0 && -0xd < (int)uVar9) {
    uVar8 = 0xc - (uVar11 - 0x14);
    uVar11 = uVar2 << (uVar8 & 0xff);
    uVar2 = uVar2 >> (0x20 - uVar8 & 0xff) | uVar6 << (uVar8 & 0xff);
    uVar8 = uVar2 + -((int)uVar11 >> 0x1f);
    if (uVar4 == 0 && (uVar11 & 0x7fffffff) == 0) {
      uVar8 = uVar8 & ~(uVar11 >> 0x1f);
    }
    return CONCAT44((uVar6 & 0x80000000) + (uint)CARRY4(uVar2,-((int)uVar11 >> 0x1f)),uVar8);
  }
  uVar9 = uVar2 << (uVar8 + 0x20 & 0xff);
  uVar2 = uVar2 >> (uVar11 & 0xff) | uVar6 << (uVar8 + 0x20 & 0xff);
  uVar8 = uVar2 + -((int)uVar9 >> 0x1f);
  if (uVar4 == 0 && (uVar9 & 0x7fffffff) == 0) {
    uVar8 = uVar8 & ~(uVar9 >> 0x1f);
  }
  return CONCAT44((uVar6 & 0x80000000) + ((uVar6 & 0x7fffffff) >> (uVar11 & 0xff)) +
                  (uint)CARRY4(uVar2,-((int)uVar9 >> 0x1f)),uVar8);
}

/* === FUN_0000e60c @ 0x0000e60c === */

ulonglong FUN_0000e60c(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r4;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  
  uVar2 = in_r12 & param_4 >> 0x14;
  uVar3 = param_2;
  if (unaff_r4 != in_r12 || uVar2 != in_r12) {
    if (unaff_r4 == in_r12) {
      if ((param_1 == 0 && (param_2 & 0xfffff) == 0) &&
         (param_1 = param_3, uVar3 = param_4, uVar2 != in_r12)) {
LAB_0000e454:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else if (uVar2 == in_r12) {
      param_1 = param_3;
      uVar3 = param_4;
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
LAB_0000e408:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
    }
    else {
      if ((param_1 != 0 || (param_2 & 0x7fffffff) != 0) &&
          (param_3 != 0 || (param_4 & 0x7fffffff) != 0)) {
        if (unaff_r4 == 0) {
          uVar3 = param_2 & 0x80000000;
          do {
            iVar1 = param_1 >> 0x1f;
            param_1 = param_1 << 1;
            param_2 = param_2 * 2 - iVar1;
          } while ((param_2 & 0x100000) == 0);
          param_2 = param_2 | uVar3;
          if (uVar2 != 0) {
            return CONCAT44(param_2,param_1);
          }
        }
        do {
          iVar1 = param_3 >> 0x1f;
          param_3 = param_3 << 1;
          param_4 = param_4 * 2 - iVar1;
        } while ((param_4 & 0x100000) == 0);
        return CONCAT44(param_2,param_1);
      }
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) goto LAB_0000e454;
      if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) goto LAB_0000e408;
    }
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}

/* === FUN_0000e68c @ 0x0000e68c === */

uint FUN_0000e68c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (((int)(param_2 << 1) >> 0x15 == -1 || (int)(param_4 << 1) >> 0x15 == -1) &&
     ((((int)(param_2 << 1) >> 0x15 == -1 && (param_1 != 0 || (param_2 & 0xfffff) != 0)) ||
      (((int)(param_4 << 1) >> 0x15 == -1 && (param_3 != 0 || (param_4 & 0xfffff) != 0)))))) {
    return 1;
  }
  bVar3 = (param_2 & 0x7fffffff) == 0;
  bVar2 = param_1 == 0 && bVar3;
  if (param_1 == 0 && bVar3) {
    bVar2 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
  }
  if (!bVar2) {
    bVar2 = param_2 == param_4;
  }
  if (!bVar2 || param_1 != param_3) {
    uVar1 = param_2 ^ param_4;
    bVar3 = uVar1 == 0;
    if (-1 < (int)uVar1) {
      bVar3 = param_2 == param_4;
    }
    bVar2 = -1 < (int)uVar1 && param_4 <= param_2;
    if (bVar3) {
      bVar2 = param_3 <= param_1;
    }
    param_4 = (int)param_4 >> 0x1f;
    if (!bVar2) {
      param_4 = ~param_4;
    }
    return param_4 | 1;
  }
  return 0;
}

/* === FUN_0000e714 @ 0x0000e714 === */

void FUN_0000e714(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0000e730(param_3,param_4,param_1,param_2);
  return;
}

/* === FUN_0000e730 @ 0x0000e730 === */

undefined4 FUN_0000e730(undefined4 param_1)

{
  FUN_0000e68c();
  return param_1;
}

/* === FUN_0000e744 @ 0x0000e744 === */

undefined1 FUN_0000e744(void)

{
  undefined1 in_ZR;
  
  FUN_0000e730();
  return in_ZR;
}

/* === FUN_0000e758 @ 0x0000e758 === */

bool FUN_0000e758(void)

{
  undefined1 in_CY;
  
  FUN_0000e730();
  return !(bool)in_CY;
}

/* === FUN_0000e76c @ 0x0000e76c === */

bool FUN_0000e76c(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_0000e730();
  return !(bool)in_CY || (bool)in_ZR;
}

/* === FUN_0000e780 @ 0x0000e780 === */

bool FUN_0000e780(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_0000e714();
  return !(bool)in_CY || (bool)in_ZR;
}

/* === FUN_0000e794 @ 0x0000e794 === */

bool FUN_0000e794(void)

{
  undefined1 in_CY;
  
  FUN_0000e714();
  return !(bool)in_CY;
}

/* === FUN_0000e7a8 @ 0x0000e7a8 === */

uint FUN_0000e7a8(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (SUB41(param_2 >> 0x1f,0)) {
    return 0;
  }
  iVar1 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar1) {
      return 0;
    }
    uVar2 = -(iVar1 >> 0x15) - 0x3e1;
    if (-1 < (int)uVar2) {
      return (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff);
    }
  }
  else if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    return 0;
  }
  return 0xffffffff;
}

/* === FUN_0000e7fc @ 0x0000e7fc === */

void FUN_0000e7fc(void)

{
  raise(8);
  return;
}

/* === FUN_0000ef64 @ 0x0000ef64 === */

void FUN_0000ef64(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      FUN_0000f6e4(param_1 + 0x12);
    }
    else {
      FUN_0000f6f4();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_0000f704(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_0000f714(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_0000f79c(param_1 + 0x8c);
  return;
}

/* === FUN_0000efd0 @ 0x0000efd0 === */

int FUN_0000efd0(code *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 local_2ac;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 local_29c;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 local_28c;
  undefined4 uStack_288;
  undefined4 uStack_284;
  undefined4 local_280;
  undefined1 auStack_80 [16];
  code *local_70;
  undefined1 *local_24 [2];
  
  *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_3 + 0x3c);
  local_2bc = *(undefined4 *)(param_3 + 4);
  uStack_2b8 = *(undefined4 *)(param_3 + 8);
  uStack_2b4 = *(undefined4 *)(param_3 + 0xc);
  uStack_2b0 = *(undefined4 *)(param_3 + 0x10);
  local_2ac = *(undefined4 *)(param_3 + 0x14);
  uStack_2a8 = *(undefined4 *)(param_3 + 0x18);
  uStack_2a4 = *(undefined4 *)(param_3 + 0x1c);
  uStack_2a0 = *(undefined4 *)(param_3 + 0x20);
  local_29c = *(undefined4 *)(param_3 + 0x24);
  uStack_298 = *(undefined4 *)(param_3 + 0x28);
  uStack_294 = *(undefined4 *)(param_3 + 0x2c);
  uStack_290 = *(undefined4 *)(param_3 + 0x30);
  local_28c = *(undefined4 *)(param_3 + 0x34);
  uStack_288 = *(undefined4 *)(param_3 + 0x38);
  uStack_284 = *(undefined4 *)(param_3 + 0x3c);
  local_280 = *(undefined4 *)(param_3 + 0x40);
  local_2c0 = 0xffffffff;
  do {
    iVar1 = FUN_0000ed94(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_0000f08c:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    FUN_0000e858(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_0000f08c;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_0000ef64(&local_2c0);
  return iVar1;
}

/* === FUN_0000f0a4 @ 0x0000f0a4 === */

int FUN_0000f0a4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 auStack_4a8 [56];
  undefined4 local_470;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 local_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 local_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 uStack_22c;
  undefined4 local_228;
  undefined4 local_224;
  
  local_264 = *(undefined4 *)(param_2 + 4);
  uStack_260 = *(undefined4 *)(param_2 + 8);
  uStack_25c = *(undefined4 *)(param_2 + 0xc);
  uStack_258 = *(undefined4 *)(param_2 + 0x10);
  local_254 = *(undefined4 *)(param_2 + 0x14);
  uStack_250 = *(undefined4 *)(param_2 + 0x18);
  uStack_24c = *(undefined4 *)(param_2 + 0x1c);
  uStack_248 = *(undefined4 *)(param_2 + 0x20);
  local_244 = *(undefined4 *)(param_2 + 0x24);
  uStack_240 = *(undefined4 *)(param_2 + 0x28);
  uStack_23c = *(undefined4 *)(param_2 + 0x2c);
  uStack_238 = *(undefined4 *)(param_2 + 0x30);
  local_234 = *(undefined4 *)(param_2 + 0x34);
  local_230 = *(undefined4 *)(param_2 + 0x38);
  uStack_22c = *(undefined4 *)(param_2 + 0x3c);
  local_228 = *(undefined4 *)(param_2 + 0x40);
  iVar3 = 0;
  pcVar4 = *(code **)(param_1 + 0xc);
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  local_268 = 0;
  do {
    iVar1 = FUN_0000ed94(param_1,local_228);
    if (param_3 == 0) {
      uVar5 = 9;
    }
    else {
      uVar5 = 10;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = local_228;
      memcpy(auStack_4a8,&local_268,0x240);
      iVar3 = (**(code **)(param_1 + 0x10))(uVar5,param_1,auStack_4a8);
      local_224 = local_470;
    }
    else {
      uVar5 = uVar5 | 0x10;
      local_224 = local_230;
    }
    iVar2 = (*pcVar4)(1,uVar5,param_1,param_1,&local_268,uVar6);
    if (iVar2 != 0) {
      return 9;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    memcpy(&local_268,auStack_4a8,0x240);
    param_3 = 0;
  } while (iVar3 == 8);
  if (iVar3 == 7) {
    FUN_0000f6d0(&local_264);
  }
  return 9;
}

/* === FUN_0000f1dc @ 0x0000f1dc === */

void FUN_0000f1dc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
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
  undefined4 local_228;
  int iStack_24;
  int iStack_20;
  
  do {
    iVar1 = FUN_0000ed94(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_0000f228;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 != 7) {
LAB_0000f228:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = FUN_0000f6d0(param_2 + 4);
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(iVar3 + 0x3c);
  local_264 = *(undefined4 *)(iVar3 + 4);
  uStack_260 = *(undefined4 *)(iVar3 + 8);
  uStack_25c = *(undefined4 *)(iVar3 + 0xc);
  uStack_258 = *(undefined4 *)(iVar3 + 0x10);
  local_254 = *(undefined4 *)(iVar3 + 0x14);
  uStack_250 = *(undefined4 *)(iVar3 + 0x18);
  uStack_24c = *(undefined4 *)(iVar3 + 0x1c);
  uStack_248 = *(undefined4 *)(iVar3 + 0x20);
  local_244 = *(undefined4 *)(iVar3 + 0x24);
  uStack_240 = *(undefined4 *)(iVar3 + 0x28);
  uStack_23c = *(undefined4 *)(iVar3 + 0x2c);
  uStack_238 = *(undefined4 *)(iVar3 + 0x30);
  local_234 = *(undefined4 *)(iVar3 + 0x34);
  uStack_230 = *(undefined4 *)(iVar3 + 0x38);
  uStack_22c = *(undefined4 *)(iVar3 + 0x3c);
  local_228 = *(undefined4 *)(iVar3 + 0x40);
  local_268 = 0xffffffff;
  iStack_24 = param_2;
  iStack_20 = param_1;
  do {
    iVar2 = FUN_0000ed94(iVar1,local_228);
    if (iVar2 != 0) goto LAB_0000f2cc;
    iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&local_268);
  } while (iVar2 == 8);
  FUN_0000ef64(&local_268);
  if (iVar2 == 6) {
    FUN_0000f1dc(iVar1,iVar3);
  }
LAB_0000f2cc:
                    /* WARNING: Could not recover jumptable at 0x0000f2d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0xf234)(9);
  return;
}

/* === FUN_0000f364 @ 0x0000f364 === */

undefined4 FUN_0000f364(uint *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  undefined4 auStack_1b8 [34];
  undefined4 auStack_130 [32];
  undefined4 local_b0 [32];
  undefined4 local_30 [5];
  
  switch(param_2) {
  case 0:
    if (param_4 != 0) {
      return 2;
    }
    puVar1 = (uint *)param_1[0xe];
    uVar6 = 0;
    do {
      if ((param_3 & 0xffff & 1 << (uVar6 & 0xff)) != 0) {
        param_1[uVar6 + 1] = *puVar1;
        puVar1 = puVar1 + 1;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != 0x10);
    if ((param_3 & 0x2000) != 0) {
      return 0;
    }
    param_1[0xe] = (uint)puVar1;
    return 0;
  case 1:
    if (param_4 != 1 && param_4 != 5) {
      return 2;
    }
    uVar6 = param_3 & 0xffff;
    param_3 = param_3 >> 0x10;
    if (param_4 == 1) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = 0x20;
    }
    uVar2 = uVar6 + param_3;
    if (uVar3 < uVar2) {
      return 2;
    }
    bVar8 = param_4 == 1;
    if (param_3 >= 0x10 && bVar8) {
      return 2;
    }
    uVar3 = uVar6;
    if ((param_3 < 0x10) && (uVar3 = 0, 0x10 < uVar2)) {
      uVar3 = uVar2 - 0x10;
    }
    if (uVar3 != 0 && param_4 != 5) {
      return 2;
    }
    if ((param_3 < 0x10) && (uVar2 = *param_1, (uVar2 & 1) != 0)) {
      *param_1 = uVar2 & 0xfffffffe;
      if (param_4 == 5) {
        *param_1 = uVar2 & 0xfffffffe | 2;
        FUN_0000f6fc();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        FUN_0000f6ec(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_0000f70c(param_1 + 0x34);
    }
    if (bVar8) {
      FUN_0000f6ec(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000f6fc(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_0000f500;
      FUN_0000f70c(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_0000f500:
    uVar2 = param_1[0xe];
    if (0 < (int)uVar6) {
      iVar7 = uVar6 * 2;
      iVar5 = 0;
      while (bVar9 = iVar7 != 0, iVar7 = iVar7 + -1, bVar9) {
        *(undefined4 *)((int)auStack_1b8 + iVar5 + param_3 * 8) = *(undefined4 *)(iVar5 + uVar2);
        iVar5 = iVar5 + 4;
      }
      uVar2 = uVar2 + uVar6 * 8;
    }
    if (0 < (int)uVar3) {
      uVar6 = param_3;
      if (param_3 < 0x10) {
        uVar6 = 0x10;
      }
      iVar7 = uVar3 * 2;
      iVar5 = 0;
      while (bVar9 = iVar7 != 0, iVar7 = iVar7 + -1, bVar9) {
        *(undefined4 *)((int)local_b0 + iVar5 + (uVar6 - 0x10) * 8) = *(undefined4 *)(uVar2 + iVar5)
        ;
        iVar5 = iVar5 + 4;
      }
      uVar2 = uVar2 + uVar3 * 8;
    }
    if (bVar8) {
      uVar2 = uVar2 + 4;
    }
    param_1[0xe] = uVar2;
    if (bVar8) {
      FUN_0000f6e4(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000f6f4(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_0000f704(local_b0);
      }
    }
    return 0;
  case 2:
    return 1;
  case 3:
    if (param_4 == 3) {
      uVar6 = param_3 & 0xffff;
      if (uVar6 + (param_3 >> 0x10) < 0x11) {
        if ((*param_1 & 8) != 0) {
          *param_1 = *param_1 & 0xfffffff7;
          FUN_0000f758(param_1 + 0x6c);
        }
        FUN_0000f758(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_0000f714(auStack_130);
        return 0;
      }
    }
    break;
  case 4:
    bVar8 = param_3 == 0x10;
    if (param_3 < 0x11) {
      bVar8 = param_4 == 0;
    }
    if (bVar8) {
      if ((*param_1 & 0x10) != 0) {
        *param_1 = *param_1 & 0xffffffef;
        FUN_0000f7b0(param_1 + 0x8c);
      }
      FUN_0000f7b0(local_30);
      puVar4 = (undefined4 *)param_1[0xe];
      uVar6 = 0;
      do {
        if ((param_3 & 1 << (uVar6 & 0xff)) != 0) {
          local_30[uVar6] = *puVar4;
          puVar4 = puVar4 + 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 != 4);
      param_1[0xe] = (uint)puVar4;
      FUN_0000f79c(local_30);
      return 0;
    }
  }
  return 2;
}

/* === FUN_0000f6d0 @ 0x0000f6d0 === */

undefined8 FUN_0000f6d0(undefined8 *param_1)

{
  return *param_1;
}

/* === FUN_0000f6e4 @ 0x0000f6e4 === */

undefined4 FUN_0000f6e4(undefined8 *param_1)

{
  return (int)*param_1;
}

/* === FUN_0000f6ec @ 0x0000f6ec === */

void FUN_0000f6ec(undefined8 *param_1)

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

/* === FUN_0000f6f4 @ 0x0000f6f4 === */

undefined4 FUN_0000f6f4(undefined8 *param_1)

{
  return (int)*param_1;
}

/* === FUN_0000f6fc @ 0x0000f6fc === */

void FUN_0000f6fc(undefined8 *param_1)

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

/* === FUN_0000f704 @ 0x0000f704 === */

void FUN_0000f704(void)

{
  return;
}

/* === FUN_0000f70c @ 0x0000f70c === */

void FUN_0000f70c(undefined8 *param_1)

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

/* === FUN_0000f714 @ 0x0000f714 === */

int FUN_0000f714(int param_1)

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

/* === FUN_0000f758 @ 0x0000f758 === */

int FUN_0000f758(int param_1)

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

/* === FUN_0000f79c @ 0x0000f79c === */

int FUN_0000f79c(int param_1)

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

/* === FUN_0000f7b0 @ 0x0000f7b0 === */

int FUN_0000f7b0(int param_1)

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

/* === FUN_0000f878 @ 0x0000f878 === */

uint FUN_0000f878(uint *param_1)

{
  uint uVar1;
  char cVar2;
  
  if ((char)param_1[2] == '\0') {
    if (*(char *)((int)param_1 + 9) == '\0') {
      return 0xb0;
    }
    *(char *)((int)param_1 + 9) = *(char *)((int)param_1 + 9) + -1;
    *param_1 = *(uint *)param_1[1];
    param_1[1] = (uint)((uint *)param_1[1] + 1);
    cVar2 = '\x03';
  }
  else {
    cVar2 = (char)param_1[2] + -1;
  }
  uVar1 = *param_1;
  *(char *)(param_1 + 2) = cVar2;
  *param_1 = uVar1 << 8;
  return uVar1 >> 0x18;
}

/* === FUN_0000f8d0 @ 0x0000f8d0 === */

void FUN_0000f8d0(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}

/* === FUN_0000f918 @ 0x0000f918 === */

undefined4 FUN_0000f918(void)

{
  int in_r3;
  
  FUN_0000e80c();
  return *(undefined4 *)(in_r3 + 0x48);
}

/* === FUN_0000f944 @ 0x0000f944 === */

undefined4 FUN_0000f944(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
LAB_0000f95c:
  do {
    while( true ) {
      uVar1 = FUN_0000f878(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        FUN_0000e80c(param_1,0,0xe,0,&local_24,uVar7,param_3);
        FUN_0000e858(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      FUN_0000e80c(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_0000fa94:
      piVar6 = &local_24;
      FUN_0000e858(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_0000f878(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = FUN_0000f364(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_0000f95c;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      FUN_0000e80c(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_0000fa94;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_0000f878(param_2);
        if (uVar1 == 0) {
          return 9;
        }
        uVar2 = 0;
        if ((uVar1 & 0xf0) != 0) {
          return 9;
        }
      }
      else {
        if (uVar1 == 0xb2) {
          uVar1 = 2;
          FUN_0000e80c(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_0000f878(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_0000fa94;
        }
        if (uVar1 == 0xb3) {
          FUN_0000f878(param_2);
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
        FUN_0000f878(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_0000f878(param_2);
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
            FUN_0000f878(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_0000f878(param_2);
          }
          goto LAB_0000fc98;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_0000fc98:
      uVar2 = 1;
    }
    iVar5 = FUN_0000f364(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}

/* === FUN_0000fcbc @ 0x0000fcbc === */

void FUN_0000fcbc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_0000f944(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}

