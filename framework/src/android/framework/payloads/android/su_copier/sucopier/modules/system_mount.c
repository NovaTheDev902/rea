/* Chrysaor native reassembly: sucopier / module system_mount */
/* Ghidra decompile - canonical sample ade8bef0... */

/* === FUN_00009090 @ 0x00009090 === */

void FUN_00009090(int param_1)

{
  if (param_1 == 0) {
    mount((char *)(DAT_000090d4 + 0x90a8),(char *)(DAT_000090d8 + 0x90aa),
          (char *)(DAT_000090dc + 0x90ac),DAT_000090e0,(void *)(DAT_000090d0 + 0x90a4));
  }
  else {
    mount((char *)(DAT_000090e8 + 0x90ca),(char *)(DAT_000090ec + 0x90c4),
          (char *)(DAT_000090f0 + 0x90c6),DAT_000090f4,(void *)(DAT_000090e4 + 0x90c0));
  }
  return;
}

