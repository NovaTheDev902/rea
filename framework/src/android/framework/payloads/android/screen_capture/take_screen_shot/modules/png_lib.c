/* Chrysaor native reassembly: take_screen_shot / module png_lib */
/* Ghidra decompile - canonical sample ade8bef0... */

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

