/* Function: entry @ 000080c0 */

void processEntry entry(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d54)();
  return;
}



/* Function: FUN_000080f0 @ 000080f0 */

void FUN_000080f0(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008110 @ 00008110 */

void FUN_00008110(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008130 @ 00008130 */

void FUN_00008130(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008150 @ 00008150 */

void FUN_00008150(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008170 @ 00008170 */

uint * FUN_00008170(uint *param_1,uint *param_2,uint param_3,byte param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  byte *pbVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint unaff_r4;
  uint uVar9;
  uint unaff_r5;
  uint uVar10;
  uint unaff_r6;
  uint uVar11;
  uint unaff_r7;
  uint uVar12;
  uint unaff_r8;
  uint uVar13;
  uint unaff_r9;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte in_r12;
  uint uVar19;
  bool bVar20;
  bool bVar21;
  
  HintPreloadData(param_1);
  HintPreloadData(param_2);
  HintPreloadData(param_2 + 8);
  puVar2 = param_1;
  puVar4 = param_2;
  if (3 < param_3) {
    uVar8 = -(int)param_2 & 3;
    if (uVar8 != 0) {
      bVar21 = SUB41(uVar8 >> 1,0);
      uVar19 = (int)param_2 * -0x80000000;
      bVar20 = (int)uVar19 < 0;
      param_3 = param_3 - uVar8;
      if (bVar20) {
        uVar8 = (uint)(byte)*param_2;
        param_2 = (uint *)((int)param_2 + 1);
      }
      if (bVar21) {
        pbVar5 = (byte *)((int)param_2 + 1);
        unaff_r4 = (uint)(byte)*param_2;
        param_2 = (uint *)((int)param_2 + 2);
        uVar19 = (uint)*pbVar5;
      }
      if (bVar20) {
        puVar2 = (uint *)((int)param_1 + 1);
        *(byte *)param_1 = (byte)uVar8;
      }
      if (bVar21) {
        pbVar5 = (byte *)((int)puVar2 + 1);
        *(byte *)puVar2 = (byte)unaff_r4;
        puVar2 = (uint *)((int)puVar2 + 2);
        *pbVar5 = (byte)uVar19;
      }
    }
    param_4 = (byte)uVar8;
    in_r12 = (byte)((uint)puVar2 ^ (uint)param_2);
    if ((((uint)puVar2 ^ (uint)param_2) & 3) == 0) {
      uVar8 = -(int)puVar2 & 0x1c;
      if (uVar8 != 0) {
        if (param_3 < uVar8) {
          uVar8 = param_3 & 0x1c;
        }
        bVar21 = SUB41(uVar8 >> 4,0);
        bVar20 = (int)(uVar8 << 0x1c) < 0;
        if (bVar21) {
          unaff_r4 = *param_2;
          unaff_r5 = param_2[1];
          unaff_r6 = param_2[2];
          unaff_r7 = param_2[3];
          param_2 = param_2 + 4;
        }
        if (bVar20) {
          unaff_r8 = *param_2;
          unaff_r9 = param_2[1];
          param_2 = param_2 + 2;
        }
        puVar4 = puVar2;
        if (bVar21) {
          *puVar2 = unaff_r4;
          puVar2[1] = unaff_r5;
          puVar2[2] = unaff_r6;
          puVar2[3] = unaff_r7;
          puVar4 = puVar2 + 4;
        }
        if (bVar20) {
          *puVar4 = unaff_r8;
          puVar4[1] = unaff_r9;
          puVar4 = puVar4 + 2;
        }
        puVar2 = puVar4;
        if ((uVar8 & 4) != 0) {
          puVar2 = puVar4 + 1;
          *puVar4 = *param_2;
          param_2 = param_2 + 1;
        }
        param_3 = param_3 - uVar8;
      }
      uVar19 = param_3 - 0x20;
      if (0x1f < param_3) {
        uVar15 = uVar19;
        puVar4 = (uint *)(((uint)param_2 & 0xffffffe0) + 0x40);
        do {
          uVar19 = uVar15;
          unaff_r4 = *param_2;
          unaff_r5 = param_2[1];
          unaff_r6 = param_2[2];
          unaff_r7 = param_2[3];
          unaff_r8 = param_2[4];
          unaff_r9 = param_2[5];
          uVar15 = param_2[6];
          uVar17 = param_2[7];
          param_2 = param_2 + 8;
          HintPreloadData(puVar4 + 0x10);
          puVar6 = puVar4;
          if (0x1f < uVar19 && uVar19 - 0x20 != 0) {
            puVar6 = puVar4 + 8;
            uVar8 = *puVar4;
          }
          *puVar2 = unaff_r4;
          puVar2[1] = unaff_r5;
          puVar2[2] = unaff_r6;
          puVar2[3] = unaff_r7;
          puVar2[4] = unaff_r8;
          puVar2[5] = unaff_r9;
          puVar2[6] = uVar15;
          puVar2[7] = uVar17;
          puVar2 = puVar2 + 8;
          uVar15 = uVar19 - 0x20;
          puVar4 = puVar6;
        } while (0x1f < uVar19);
      }
      if ((uVar19 & 0x1f) != 0) {
        bVar20 = (bool)((byte)(uVar19 >> 4) & 1);
        bVar21 = (int)(uVar19 << 0x1c) < 0;
        if (bVar20) {
          unaff_r4 = *param_2;
          unaff_r5 = param_2[1];
          unaff_r6 = param_2[2];
          unaff_r7 = param_2[3];
          param_2 = param_2 + 4;
        }
        if (bVar21) {
          unaff_r8 = *param_2;
          unaff_r9 = param_2[1];
          param_2 = param_2 + 2;
        }
        if (bVar20) {
          *puVar2 = unaff_r4;
          puVar2[1] = unaff_r5;
          puVar2[2] = unaff_r6;
          puVar2[3] = unaff_r7;
          puVar2 = puVar2 + 4;
        }
        if (bVar21) {
          *puVar2 = unaff_r8;
          puVar2[1] = unaff_r9;
          puVar2 = puVar2 + 2;
        }
        bVar20 = (bool)((byte)(uVar19 >> 2) & 1);
        bVar21 = (int)(uVar19 << 0x1e) < 0;
        puVar4 = param_2;
        if (bVar20) {
          puVar4 = param_2 + 1;
          uVar8 = *param_2;
        }
        puVar6 = puVar4;
        if (bVar21) {
          puVar6 = (uint *)((int)puVar4 + 2);
          unaff_r4 = (uint)(ushort)*puVar4;
        }
        puVar4 = puVar2;
        if (bVar20) {
          puVar4 = puVar2 + 1;
          *puVar2 = uVar8;
        }
        puVar2 = puVar4;
        if (bVar21) {
          puVar2 = (uint *)((int)puVar4 + 2);
          *(short *)puVar4 = (short)unaff_r4;
        }
        if ((uVar19 & 1) != 0) {
          *(byte *)puVar2 = (byte)*puVar6;
        }
      }
      return param_1;
    }
    puVar4 = param_2;
    if (3 < param_3) {
      uVar15 = -(int)puVar2 & 3;
      uVar8 = uVar15 * 8;
      uVar17 = uVar15 * -8 + 0x20;
      puVar4 = param_2 + 1;
      uVar19 = *param_2;
      param_3 = param_3 - 4;
      puVar6 = puVar2;
      if ((int)puVar2 * -0x80000000 < 0) {
        puVar6 = (uint *)((int)puVar2 + 1);
        *(byte *)puVar2 = (byte)uVar19;
        uVar19 = uVar19 >> 8;
      }
      if (SUB41(uVar15 >> 1,0)) {
        pbVar5 = (byte *)((int)puVar6 + 1);
        *(byte *)puVar6 = (byte)uVar19;
        puVar6 = (uint *)((int)puVar6 + 2);
        *pbVar5 = (byte)(uVar19 >> 8);
        uVar19 = uVar19 >> 0x10;
      }
      puVar3 = puVar6;
      puVar7 = puVar4;
      if (3 < param_3) {
LAB_000082bc:
        if (((uint)puVar3 & 0x1c) != 0) goto code_r0x000082c4;
        uVar9 = param_3 - 0x20;
        if (0x1f < param_3) {
          if (uVar15 == 3) {
            puVar4 = puVar7 + 1;
            uVar8 = *puVar7;
            do {
              uVar10 = *puVar4;
              uVar11 = puVar4[1];
              uVar12 = puVar4[2];
              uVar13 = puVar4[3];
              uVar14 = puVar4[4];
              uVar16 = puVar4[5];
              uVar18 = puVar4[6];
              HintPreloadData(puVar4 + 0x17);
              bVar21 = 0x1f < uVar9;
              uVar9 = uVar9 - 0x20;
              puVar7 = puVar4 + 7;
              uVar15 = uVar8;
              if (bVar21) {
                puVar7 = puVar4 + 8;
                uVar15 = puVar4[7];
              }
              *puVar3 = uVar19 | uVar8 << 8;
              puVar3[1] = uVar8 >> 0x18 | uVar10 << 8;
              puVar3[2] = uVar10 >> 0x18 | uVar11 << 8;
              puVar3[3] = uVar11 >> 0x18 | uVar12 << 8;
              puVar3[4] = uVar12 >> 0x18 | uVar13 << 8;
              puVar3[5] = uVar13 >> 0x18 | uVar14 << 8;
              puVar3[6] = uVar14 >> 0x18 | uVar16 << 8;
              puVar3[7] = uVar16 >> 0x18 | uVar18 << 8;
              puVar3 = puVar3 + 8;
              uVar19 = uVar18 >> 0x18;
              puVar4 = puVar7;
              uVar8 = uVar15;
            } while (bVar21);
          }
          else if (uVar15 == 1) {
            puVar4 = puVar7 + 1;
            uVar8 = *puVar7;
            do {
              uVar10 = *puVar4;
              uVar11 = puVar4[1];
              uVar12 = puVar4[2];
              uVar13 = puVar4[3];
              uVar14 = puVar4[4];
              uVar16 = puVar4[5];
              uVar18 = puVar4[6];
              HintPreloadData(puVar4 + 0x17);
              bVar21 = 0x1f < uVar9;
              uVar9 = uVar9 - 0x20;
              puVar7 = puVar4 + 7;
              uVar15 = uVar8;
              if (bVar21) {
                puVar7 = puVar4 + 8;
                uVar15 = puVar4[7];
              }
              *puVar3 = uVar19 | uVar8 << 0x18;
              puVar3[1] = uVar8 >> 8 | uVar10 << 0x18;
              puVar3[2] = uVar10 >> 8 | uVar11 << 0x18;
              puVar3[3] = uVar11 >> 8 | uVar12 << 0x18;
              puVar3[4] = uVar12 >> 8 | uVar13 << 0x18;
              puVar3[5] = uVar13 >> 8 | uVar14 << 0x18;
              puVar3[6] = uVar14 >> 8 | uVar16 << 0x18;
              puVar3[7] = uVar16 >> 8 | uVar18 << 0x18;
              puVar3 = puVar3 + 8;
              uVar19 = uVar18 >> 8;
              puVar4 = puVar7;
              uVar8 = uVar15;
            } while (bVar21);
          }
          else {
            puVar4 = puVar7 + 1;
            uVar8 = *puVar7;
            do {
              uVar10 = *puVar4;
              uVar11 = puVar4[1];
              uVar12 = puVar4[2];
              uVar13 = puVar4[3];
              uVar14 = puVar4[4];
              uVar16 = puVar4[5];
              uVar18 = puVar4[6];
              HintPreloadData(puVar4 + 0x17);
              bVar21 = 0x1f < uVar9;
              uVar9 = uVar9 - 0x20;
              puVar7 = puVar4 + 7;
              uVar15 = uVar8;
              if (bVar21) {
                puVar7 = puVar4 + 8;
                uVar15 = puVar4[7];
              }
              *puVar3 = uVar19 | uVar8 << 0x10;
              puVar3[1] = uVar8 >> 0x10 | uVar10 << 0x10;
              puVar3[2] = uVar10 >> 0x10 | uVar11 << 0x10;
              puVar3[3] = uVar11 >> 0x10 | uVar12 << 0x10;
              puVar3[4] = uVar12 >> 0x10 | uVar13 << 0x10;
              puVar3[5] = uVar13 >> 0x10 | uVar14 << 0x10;
              puVar3[6] = uVar14 >> 0x10 | uVar16 << 0x10;
              puVar3[7] = uVar16 >> 0x10 | uVar18 << 0x10;
              puVar3 = puVar3 + 8;
              uVar19 = uVar18 >> 0x10;
              puVar4 = puVar7;
              uVar8 = uVar15;
            } while (bVar21);
          }
        }
        uVar8 = 0x20 - uVar17;
        puVar6 = puVar3;
        puVar4 = puVar7;
        for (param_3 = uVar9 + 0x20; 3 < param_3; param_3 = param_3 - 4) {
          uVar15 = uVar19 | *puVar4 << (uVar17 & 0xff);
          uVar19 = *puVar4 >> (uVar8 & 0xff);
          *puVar6 = uVar15;
          puVar6 = puVar6 + 1;
          puVar4 = puVar4 + 1;
        }
      }
LAB_00008450:
      in_r12 = (byte)uVar8;
      iVar1 = (int)puVar2 * -0x80000000;
      puVar2 = puVar6;
      if (iVar1 < 0) {
        puVar2 = (uint *)((int)puVar6 + 1);
        *(byte *)puVar6 = (byte)uVar19;
        uVar19 = uVar19 >> 8;
      }
      param_4 = (byte)uVar19;
      if ((bool)((byte)(uVar17 >> 4) & 1)) {
        pbVar5 = (byte *)((int)puVar2 + 1);
        *(byte *)puVar2 = param_4;
        param_4 = (byte)(uVar19 >> 8);
        puVar2 = (uint *)((int)puVar2 + 2);
        *pbVar5 = param_4;
      }
    }
  }
  bVar20 = (bool)((byte)(param_3 >> 1) & 1);
  param_3 = param_3 << 0x1f;
  bVar21 = (int)param_3 < 0;
  puVar6 = puVar4;
  if (bVar21) {
    puVar6 = (uint *)((int)puVar4 + 1);
    param_3 = (uint)(byte)*puVar4;
  }
  if (bVar20) {
    param_4 = (byte)*puVar6;
    in_r12 = *(byte *)((int)puVar6 + 1);
  }
  puVar4 = puVar2;
  if (bVar21) {
    puVar4 = (uint *)((int)puVar2 + 1);
    *(byte *)puVar2 = (byte)param_3;
  }
  if (bVar20) {
    *(byte *)puVar4 = param_4;
    *(byte *)((int)puVar4 + 1) = in_r12;
  }
  return param_1;
code_r0x000082c4:
  puVar4 = puVar7 + 1;
  param_3 = param_3 - 4;
  uVar9 = uVar19 | *puVar7 << (uVar17 & 0xff);
  uVar19 = *puVar7 >> uVar8;
  puVar6 = puVar3 + 1;
  *puVar3 = uVar9;
  puVar3 = puVar6;
  puVar7 = puVar4;
  if (param_3 < 4) goto LAB_00008450;
  goto LAB_000082bc;
}



/* Function: FUN_000084a8 @ 000084a8 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * FUN_000084a8(uint *param_1,byte param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = -(int)param_1 & 3U;
  if (param_3 < (-(int)param_1 & 3U)) {
    uVar6 = param_3;
  }
  uVar3 = (uint)param_2 << 0x18 | (uint)param_2 << 0x10;
  uVar4 = uVar3 | uVar3 >> 0x10;
  puVar1 = param_1;
  if ((bool)((byte)(uVar6 >> 1) & 1)) {
    *(byte *)param_1 = param_2;
    puVar1 = (uint *)((int)param_1 + 2);
    *(byte *)((int)param_1 + 1) = param_2;
  }
  puVar2 = puVar1;
  if ((int)(uVar6 << 0x1f) < 0) {
    puVar2 = (uint *)((int)puVar1 + 1);
    *(byte *)puVar1 = param_2;
  }
  uVar5 = param_3 - uVar6;
  if (uVar6 <= param_3 && uVar5 != 0) {
    uVar6 = -(int)puVar2 & 0x1c;
    puVar1 = puVar2;
    if (uVar6 != 0) {
      if (uVar5 < uVar6) {
        uVar6 = uVar5 & 0x1c;
      }
      uVar5 = uVar5 - uVar6;
      if (SUB41(uVar6 >> 4,0)) {
        *puVar2 = uVar4;
        puVar2[1] = uVar4;
        puVar2[2] = uVar4;
        puVar2[3] = uVar4;
        puVar2 = puVar2 + 4;
      }
      if ((int)(uVar6 << 0x1c) < 0) {
        *puVar2 = uVar4;
        puVar2[1] = uVar4;
        puVar2 = puVar2 + 2;
      }
      puVar1 = puVar2;
      if ((bool)((byte)((uVar6 << 0x1c) >> 0x1e) & 1)) {
        puVar1 = puVar2 + 1;
        *puVar2 = uVar4;
      }
    }
    uVar5 = uVar5 - 0x20;
    if (-1 < (int)uVar5) {
      do {
        bVar7 = 0x1f < uVar5;
        uVar5 = uVar5 - 0x20;
        *puVar1 = uVar4;
        puVar1[1] = uVar4;
        puVar1[2] = uVar4;
        puVar1[3] = uVar4;
        puVar1[4] = uVar4;
        puVar1[5] = uVar4;
        puVar1[6] = uVar4;
        puVar1[7] = uVar4;
        puVar1 = puVar1 + 8;
      } while (bVar7);
    }
    if ((bool)((byte)(uVar5 + 0x20 >> 4) & 1)) {
      *puVar1 = uVar4;
      puVar1[1] = uVar4;
      puVar1[2] = uVar4;
      puVar1[3] = uVar4;
      puVar1 = puVar1 + 4;
    }
    if ((int)(uVar5 << 0x1c) < 0) {
      *puVar1 = uVar4;
      puVar1[1] = uVar4;
      puVar1 = puVar1 + 2;
    }
    puVar2 = puVar1;
    if ((bool)((byte)((uVar5 << 0x1c) >> 0x1e) & 1)) {
      puVar2 = puVar1 + 1;
      *puVar1 = uVar4;
    }
    puVar1 = puVar2;
    if ((int)(uVar5 << 0x1e) < 0) {
      puVar1 = (uint *)((int)puVar2 + 2);
      *(short *)puVar2 = (short)(uVar3 >> 0x10);
    }
    if ((bool)((byte)((uVar5 << 0x1e) >> 0x1e) & 1)) {
      *(byte *)puVar1 = param_2;
    }
    return param_1;
  }
  return param_1;
}



/* Function: FUN_00008570 @ 00008570 */

void FUN_00008570(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008590 @ 00008590 */

void FUN_00008590(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_000085b0 @ 000085b0 */

void FUN_000085b0(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_000085d0 @ 000085d0 */

void FUN_000085d0(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_000085f0 @ 000085f0 */

void FUN_000085f0(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008610 @ 00008610 */

void FUN_00008610(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008630 @ 00008630 */

void FUN_00008630(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008650 @ 00008650 */

void FUN_00008650(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008670 @ 00008670 */

void FUN_00008670(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008690 @ 00008690 */

void FUN_00008690(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_000086b0 @ 000086b0 */

void FUN_000086b0(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_000086d0 @ 000086d0 */

void FUN_000086d0(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_000086f0 @ 000086f0 */

void FUN_000086f0(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008710 @ 00008710 */

void FUN_00008710(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008730 @ 00008730 */

void FUN_00008730(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008750 @ 00008750 */

void FUN_00008750(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008790 @ 00008790 */

void FUN_00008790(void)

{
  return;
}



/* Function: FUN_00008798 @ 00008798 */

int FUN_00008798(int *param_1)

{
  int extraout_r1;
  int *extraout_r2;
  undefined1 in_CY;
  
  do {
    (*(code *)&SUB_ffff0fc0)(*param_1,*param_1 + -1);
    param_1 = extraout_r2;
  } while (!(bool)in_CY);
  return extraout_r1 + 1;
}



/* Function: FUN_000087c4 @ 000087c4 */

int FUN_000087c4(int *param_1)

{
  int extraout_r1;
  int *extraout_r2;
  undefined1 in_CY;
  
  do {
    (*(code *)&SUB_ffff0fc0)(*param_1,*param_1 + 1);
    param_1 = extraout_r2;
  } while (!(bool)in_CY);
  return extraout_r1 + -1;
}



/* Function: FUN_000087f0 @ 000087f0 */

void FUN_000087f0(uint param_1)

{
  uint *extraout_r2;
  undefined1 in_CY;
  
  do {
    (*(code *)&SUB_ffff0fc0)(param_1);
    if ((bool)in_CY) {
      return;
    }
    in_CY = param_1 <= *extraout_r2;
  } while (*extraout_r2 == param_1);
  return;
}



/* Function: FUN_00008820 @ 00008820 */

undefined4 FUN_00008820(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = param_1;
  return uVar1;
}



/* Function: FUN_00008880 @ 00008880 */

void FUN_00008880(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_000088a0 @ 000088a0 */

int FUN_000088a0(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  HintPreloadData(param_1);
  HintPreloadData(param_2);
  if (param_1 == param_2 || param_3 == 0) {
    return 0;
  }
  HintPreloadData(param_1 + 8);
  HintPreloadData(param_2 + 8);
  if (-1 < (int)(param_3 - 0xc)) {
    uVar5 = -(int)param_1 & 3;
    if (uVar5 != 0) {
      param_3 = param_3 - uVar5;
      puVar3 = param_2;
      puVar7 = param_1;
      do {
        param_1 = (uint *)((int)puVar7 + 1);
        param_2 = (uint *)((int)puVar3 + 1);
        iVar2 = (uint)(byte)*puVar7 - (uint)(byte)*puVar3;
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar5 = uVar5 - 1;
        puVar3 = param_2;
        puVar7 = param_1;
      } while (uVar5 != 0);
    }
    if ((((uint)param_1 ^ (uint)param_2) & 3) == 0) {
      uVar5 = *param_2;
      param_3 = param_3 - 0x24;
      if (-1 < (int)param_3) {
        do {
          HintPreloadData(param_1 + 0x10);
          HintPreloadData(param_2 + 0x10);
          puVar3 = param_2 + 1;
          uVar10 = *puVar3;
          bVar11 = false;
          puVar7 = param_1 + 1;
          if (*param_1 == uVar5) {
            puVar7 = param_1 + 2;
            puVar3 = param_2 + 2;
            uVar5 = *puVar3;
            bVar11 = param_1[1] == uVar10;
          }
          bVar12 = false;
          puVar6 = puVar7;
          if (bVar11) {
            puVar6 = puVar7 + 1;
            puVar3 = puVar3 + 1;
            uVar10 = *puVar3;
            bVar12 = *puVar7 == uVar5;
          }
          bVar11 = false;
          puVar7 = puVar6;
          if (bVar12) {
            puVar7 = puVar6 + 1;
            puVar3 = puVar3 + 1;
            uVar5 = *puVar3;
            bVar11 = *puVar6 == uVar10;
          }
          bVar12 = false;
          puVar6 = puVar7;
          if (bVar11) {
            puVar6 = puVar7 + 1;
            puVar3 = puVar3 + 1;
            uVar10 = *puVar3;
            bVar12 = *puVar7 == uVar5;
          }
          bVar11 = false;
          puVar7 = puVar6;
          if (bVar12) {
            puVar7 = puVar6 + 1;
            puVar3 = puVar3 + 1;
            uVar5 = *puVar3;
            bVar11 = *puVar6 == uVar10;
          }
          bVar12 = false;
          puVar6 = puVar7;
          if (bVar11) {
            puVar6 = puVar7 + 1;
            puVar3 = puVar3 + 1;
            uVar10 = *puVar3;
            bVar12 = *puVar7 == uVar5;
          }
          bVar11 = false;
          param_2 = puVar3;
          param_1 = puVar6;
          if (bVar12) {
            param_1 = puVar6 + 1;
            param_2 = puVar3 + 1;
            uVar5 = *param_2;
            bVar11 = *puVar6 == uVar10;
          }
          if (!bVar11) goto LAB_000089b4;
          bVar11 = 0x1f < param_3;
          param_3 = param_3 - 0x20;
        } while (bVar11);
      }
      param_3 = param_3 + 0x20;
      puVar3 = param_2;
      puVar7 = param_1;
      if (-1 < (int)param_3) {
        do {
          param_1 = puVar7 + 1;
          param_2 = puVar3 + 1;
          if (*puVar7 != *puVar3) goto LAB_000089b4;
          bVar11 = 3 < param_3;
          param_3 = param_3 - 4;
          puVar3 = param_2;
          puVar7 = param_1;
        } while (bVar11);
      }
      param_3 = param_3 + 4;
      if (param_3 == 0) {
        return 0;
      }
    }
    else {
      uVar5 = (uint)param_2 & 3;
      if (uVar5 == 2) {
        if (-1 < (int)(param_3 - 0x10)) {
          puVar3 = (uint *)((uint)param_2 & 0xfffffffc) + 1;
          uVar5 = *(uint *)((uint)param_2 & 0xfffffffc);
          uVar10 = param_3 - 0x10;
          do {
            param_3 = uVar10;
            HintPreloadData(puVar3 + 0x10);
            HintPreloadData(param_1 + 0x10);
            uVar10 = uVar5 >> 0x10;
            uVar5 = *puVar3;
            bVar11 = false;
            puVar7 = param_1 + 1;
            puVar6 = puVar3 + 1;
            if (*param_1 == (uVar10 | uVar5 << 0x10)) {
              uVar10 = uVar5 >> 0x10;
              puVar6 = puVar3 + 2;
              uVar5 = puVar3[1];
              puVar7 = param_1 + 2;
              bVar11 = param_1[1] == (uVar10 | uVar5 << 0x10);
            }
            bVar12 = false;
            puVar8 = puVar7;
            puVar4 = puVar6;
            if (bVar11) {
              uVar10 = uVar5 >> 0x10;
              puVar4 = puVar6 + 1;
              uVar5 = *puVar6;
              puVar8 = puVar7 + 1;
              bVar12 = *puVar7 == (uVar10 | uVar5 << 0x10);
            }
            bVar11 = false;
            param_1 = puVar8;
            puVar3 = puVar4;
            if (bVar12) {
              uVar10 = uVar5 >> 0x10;
              puVar3 = puVar4 + 1;
              uVar5 = *puVar4;
              param_1 = puVar8 + 1;
              bVar11 = *puVar8 == (uVar10 | uVar5 << 0x10);
            }
            if (!bVar11) {
              param_2 = (uint *)((int)puVar3 + -6);
              param_1 = param_1 + -1;
              param_3 = 4;
              goto LAB_000089c0;
            }
            uVar10 = param_3 - 0x10;
          } while (0xf < param_3);
          param_2 = (uint *)((int)puVar3 + -2);
          if (param_3 == 0) {
            return 0;
          }
        }
      }
      else {
        uVar9 = uVar5 * -8 + 0x20;
        puVar3 = (uint *)((uint)param_2 & 0xfffffffc) + 1;
        uVar10 = *(uint *)((uint)param_2 & 0xfffffffc);
        do {
          param_3 = param_3 - 8;
          uVar1 = uVar10 >> uVar5 * 8;
          uVar10 = *puVar3;
          bVar11 = false;
          puVar7 = param_1 + 1;
          puVar6 = puVar3 + 1;
          if (*param_1 == (uVar1 | uVar10 << (uVar9 & 0xff))) {
            uVar1 = uVar10 >> uVar5 * 8;
            uVar10 = puVar3[1];
            bVar11 = param_1[1] == (uVar1 | uVar10 << (uVar9 & 0xff));
            puVar7 = param_1 + 2;
            puVar6 = puVar3 + 2;
          }
          puVar3 = puVar6;
          param_1 = puVar7;
          if (!bVar11) {
            param_2 = (uint *)((int)puVar3 + (-4 - (uVar9 >> 3)));
            param_1 = param_1 + -1;
            param_3 = 4;
            goto LAB_000089c0;
          }
        } while (7 < param_3);
        param_2 = (uint *)((int)puVar3 - (uVar9 >> 3));
        if (param_3 == 0) {
          return 0;
        }
      }
    }
  }
LAB_000089c0:
  do {
    iVar2 = (uint)(byte)*param_1 - (uint)(byte)*param_2;
    if (iVar2 != 0) {
      return iVar2;
    }
    param_3 = param_3 - 1;
    param_2 = (uint *)((int)param_2 + 1);
    param_1 = (uint *)((int)param_1 + 1);
  } while (param_3 != 0);
  return 0;
LAB_000089b4:
  param_1 = param_1 + -1;
  param_2 = param_2 + -1;
  param_3 = 4;
  goto LAB_000089c0;
}



/* Function: FUN_00008b10 @ 00008b10 */

void FUN_00008b10(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008b40 @ 00008b40 */

void FUN_00008b40(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008b60 @ 00008b60 */

void FUN_00008b60(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008b80 @ 00008b80 */

void FUN_00008b80(int param_1)

{
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00008ba0 @ 00008ba0 */

uint FUN_00008ba0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    FUN_00008d58();
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



/* Function: FUN_00008c4c @ 00008c4c */

void FUN_00008c4c(void)

{
  FUN_00008ba0();
  return;
}



/* Function: FUN_00008c64 @ 00008c64 */

uint FUN_00008c64(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_1 ^ param_2;
  if (param_2 == 0) {
    FUN_00008d58();
    return 0;
  }
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = -param_2;
  }
  if (uVar2 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar4 = param_1;
  if ((int)param_1 < 0) {
    uVar4 = -param_1;
  }
  if (uVar4 <= uVar2) {
    if (uVar4 < uVar2) {
      param_1 = 0;
    }
    if (uVar4 == uVar2) {
      param_1 = (int)uVar5 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar2 & uVar2 - 1) == 0) {
    uVar4 = uVar4 >> (0x1fU - LZCOUNT(uVar2) & 0xff);
    if ((int)uVar5 < 0) {
      uVar4 = -uVar4;
    }
    return uVar4;
  }
  uVar3 = uVar2 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar2 = 1 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar1 = 0;
  while( true ) {
    if (uVar3 <= uVar4) {
      uVar4 = uVar4 - uVar3;
      uVar1 = uVar1 | uVar2;
    }
    if (uVar3 >> 1 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 1);
      uVar1 = uVar1 | uVar2 >> 1;
    }
    if (uVar3 >> 2 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 2);
      uVar1 = uVar1 | uVar2 >> 2;
    }
    if (uVar3 >> 3 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 3);
      uVar1 = uVar1 | uVar2 >> 3;
    }
    bVar6 = uVar4 == 0;
    if (!bVar6) {
      uVar2 = uVar2 >> 4;
      bVar6 = uVar2 == 0;
    }
    if (bVar6) break;
    uVar3 = uVar3 >> 4;
  }
  if ((int)uVar5 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}



/* Function: FUN_00008d40 @ 00008d40 */

void FUN_00008d40(void)

{
  FUN_00008c64();
  return;
}



/* Function: FUN_00008d58 @ 00008d58 */

void FUN_00008d58(void)

{
  return;
}



/* Function: FUN_00008d64 @ 00008d64 */

ulonglong FUN_00008d64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  uVar7 = param_4 ^ 0x80000000;
  uVar10 = param_2 << 1;
  uVar5 = param_4 << 1;
  iVar9 = (int)uVar10 >> 0x15;
  iVar1 = (int)uVar5 >> 0x15;
  if ((((uVar10 == uVar5 && param_1 == param_3 || uVar10 == 0 && param_1 == 0) ||
       uVar5 == 0 && param_3 == 0) || iVar9 == -1) || iVar1 == -1) {
    if (iVar9 == -1 || iVar1 == -1) {
      uVar10 = param_3;
      uVar5 = uVar7;
      if (iVar9 == -1) {
        uVar10 = param_1;
        uVar5 = param_2;
      }
      if (iVar9 != -1 || iVar1 != -1) {
        param_3 = uVar10;
        uVar7 = uVar5;
      }
      bVar14 = (uVar5 & 0xfffff) == 0;
      bVar15 = uVar10 == 0 && bVar14;
      if (uVar10 == 0 && bVar14) {
        bVar15 = param_3 == 0 && (uVar7 & 0xfffff) == 0;
      }
      if (!bVar15 || uVar5 != uVar7) {
        uVar5 = uVar5 | 0x80000;
      }
      return CONCAT44(uVar5,uVar10);
    }
    if (uVar10 != uVar5 || param_1 != param_3) {
      if (uVar10 == 0 && param_1 == 0) {
        param_1 = param_3;
        param_2 = uVar7;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != uVar7) {
      return 0;
    }
    if ((param_2 & 0x7fffffff) >> 0x14 == 0) {
      bVar2 = (byte)(param_1 >> 0x1f);
      uVar10 = param_2 * 2 + (uint)bVar2;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar2)) {
        uVar10 = uVar10 | 0x80000000;
      }
      return CONCAT44(uVar10,param_1 << 1);
    }
    if (uVar10 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_00008fd8:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar10 = (param_2 & 0x7fffffff) >> 0x14;
  uVar5 = (param_4 & 0x7fffffff) >> 0x14;
  uVar12 = uVar5 - uVar10;
  bVar14 = uVar12 != 0;
  if (uVar5 < uVar10) {
    uVar12 = -uVar12;
  }
  uVar11 = param_1;
  uVar8 = param_2;
  if (bVar14 && uVar10 <= uVar5) {
    uVar10 = uVar10 + uVar12;
    uVar11 = param_3;
    uVar8 = uVar7;
    param_3 = param_1;
    uVar7 = param_2;
  }
  if (0x36 < uVar12) {
    return CONCAT44(uVar8,uVar11);
  }
  uVar5 = uVar8 & 0xfffff | 0x100000;
  if ((uVar8 & 0x80000000) != 0) {
    bVar14 = uVar11 != 0;
    uVar11 = -uVar11;
    uVar5 = -(uVar5 + bVar14);
  }
  uVar8 = uVar7 & 0xfffff | 0x100000;
  if ((uVar7 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar8 = -(uVar8 + bVar14);
  }
  if (uVar10 == uVar12) {
    uVar8 = uVar8 ^ 0x100000;
    if (uVar10 == 0) {
      uVar5 = uVar5 ^ 0x100000;
      uVar10 = 1;
    }
    else {
      uVar12 = uVar12 - 1;
    }
  }
  uVar7 = -uVar12 + 0x20;
  if ((int)uVar12 < 0x21) {
    uVar13 = param_3 << (uVar7 & 0xff);
    param_3 = param_3 >> (uVar12 & 0xff);
    uVar4 = uVar11 + param_3;
    uVar6 = uVar8 << (uVar7 & 0xff);
    uVar7 = uVar4 + uVar6;
    uVar5 = uVar5 + CARRY4(uVar11,param_3) + ((int)uVar8 >> (uVar12 & 0xff)) +
            (uint)CARRY4(uVar4,uVar6);
  }
  else {
    uVar13 = uVar8 << (-uVar12 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar13 = uVar13 | 2;
    }
    uVar12 = (int)uVar8 >> (uVar12 - 0x20 & 0xff);
    uVar7 = uVar11 + uVar12;
    uVar5 = uVar5 + ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar11,uVar12);
  }
  param_2 = uVar5 & 0x80000000;
  uVar12 = uVar5;
  if ((int)uVar5 < 0) {
    bVar14 = uVar13 == 0;
    uVar13 = -uVar13;
    uVar12 = -uVar7;
    uVar7 = -(uVar7 + !bVar14);
    uVar12 = -(uVar5 + (bVar14 <= uVar12));
  }
  if (0xfffff < uVar12) {
    uVar11 = uVar10 - 1;
    if (0x1fffff < uVar12) {
      bVar2 = (byte)uVar12;
      uVar12 = uVar12 >> 1;
      bVar3 = (byte)uVar7;
      uVar7 = (uint)(bVar2 & 1) << 0x1f | uVar7 >> 1;
      uVar13 = (uint)(bVar3 & 1) << 0x1f | uVar13 >> 1;
      uVar11 = uVar10;
      if (0xffbfffff < uVar10 * 0x200000) goto LAB_00008fd8;
    }
LAB_00008e80:
    bVar14 = 0x7fffffff < uVar13;
    if (uVar13 == 0x80000000) {
      bVar14 = (bool)((byte)uVar7 & 1);
    }
    return CONCAT44(uVar12 + uVar11 * 0x100000 + (uint)CARRY4(uVar7,(uint)bVar14) | param_2,
                    uVar7 + bVar14);
  }
  bVar2 = (byte)(uVar13 >> 0x1f);
  uVar13 = uVar13 << 1;
  uVar11 = uVar7 * 2;
  bVar14 = CARRY4(uVar7,uVar7);
  uVar7 = uVar7 * 2 + (uint)bVar2;
  uVar12 = uVar12 * 2 + (uint)(bVar14 || CARRY4(uVar11,(uint)bVar2));
  uVar11 = uVar10 - 2;
  if ((uVar12 & 0x100000) != 0) goto LAB_00008e80;
  uVar10 = uVar7;
  uVar8 = uVar12;
  if (uVar12 == 0) {
    uVar10 = 0;
    uVar8 = uVar7;
  }
  iVar9 = LZCOUNT(uVar8);
  if (uVar12 == 0) {
    iVar9 = iVar9 + 0x20;
  }
  uVar4 = iVar9 - 0xb;
  bVar15 = SBORROW4(uVar4,0x20);
  uVar6 = iVar9 - 0x2b;
  bVar14 = uVar6 == 0;
  uVar7 = uVar6;
  uVar12 = uVar6;
  if ((int)uVar4 < 0x20) {
    bVar15 = SCARRY4(uVar6,0xc);
    uVar12 = iVar9 - 0x1f;
    bVar14 = uVar12 == 0;
    uVar7 = uVar4;
    if (!bVar14 && -0xd < (int)uVar6) {
      uVar10 = uVar8 << (uVar4 & 0xff);
      uVar8 = uVar8 >> (0xc - uVar12 & 0xff);
      goto LAB_00008f00;
    }
  }
  if (bVar14 || (int)uVar12 < 0 != bVar15) {
    uVar13 = 0x20 - uVar7;
  }
  uVar8 = uVar8 << (uVar7 & 0xff);
  if (bVar14 || (int)uVar12 < 0 != bVar15) {
    uVar8 = uVar8 | uVar10 >> (uVar13 & 0xff);
    uVar10 = uVar10 << (uVar7 & 0xff);
  }
LAB_00008f00:
  if ((int)uVar4 <= (int)uVar11) {
    return CONCAT44(uVar8 + (uVar11 - uVar4) * 0x100000 | param_2,uVar10);
  }
  uVar7 = ~(uVar11 - uVar4);
  if ((int)uVar7 < 0x1f) {
    if (uVar7 - 0x13 != 0 && -0xd < (int)(uVar7 - 0x1f)) {
      uVar7 = 0xc - (uVar7 - 0x13);
      return CONCAT44(uVar5,uVar10 >> (0x20 - uVar7 & 0xff) | uVar8 << (uVar7 & 0xff)) &
             0x80000000ffffffff;
    }
    uVar7 = uVar7 + 1;
    return CONCAT44(param_2 | uVar8 >> (uVar7 & 0xff),
                    uVar10 >> (uVar7 & 0xff) | uVar8 << (0x20 - uVar7 & 0xff));
  }
  return CONCAT44(uVar5,uVar8 >> (uVar7 - 0x1f & 0xff)) & 0x80000000ffffffff;
}



/* Function: FUN_00008d68 @ 00008d68 */

ulonglong FUN_00008d68(uint param_1,uint param_2,uint param_3,uint param_4)

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
LAB_00008fd8:
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
      if (0xffbfffff < uVar9 * 0x200000) goto LAB_00008fd8;
    }
LAB_00008e80:
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
  if ((uVar11 & 0x100000) != 0) goto LAB_00008e80;
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
      goto LAB_00008f00;
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
LAB_00008f00:
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



/* Function: FUN_00009014 @ 00009014 */

ulonglong FUN_00009014(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint in_r12;
  bool bVar7;
  bool bVar8;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = 0;
  iVar4 = LZCOUNT(param_1);
  uVar5 = iVar4 + 0x15;
  bVar8 = SBORROW4(uVar5,0x20);
  uVar2 = iVar4 - 0xb;
  bVar7 = uVar2 == 0;
  uVar6 = uVar2;
  uVar3 = uVar2;
  if (uVar5 < 0x20) {
    bVar8 = SCARRY4(uVar2,0xc);
    uVar3 = iVar4 + 1;
    bVar7 = uVar3 == 0;
    uVar6 = uVar5;
    if (!bVar7 && -0xd < (int)uVar2) {
      uVar1 = param_1 << uVar5;
      param_1 = param_1 >> (0xc - uVar3 & 0xff);
      goto LAB_00008f00;
    }
  }
  if (bVar7 || (int)uVar3 < 0 != bVar8) {
    in_r12 = 0x20 - uVar6;
  }
  param_1 = param_1 << (uVar6 & 0xff);
  if (bVar7 || (int)uVar3 < 0 != bVar8) {
    param_1 = param_1 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar6 & 0xff);
  }
LAB_00008f00:
  if (uVar5 < 0x433) {
    return CONCAT44(param_1 + (0x432 - uVar5) * 0x100000,uVar1);
  }
  uVar6 = ~(0x432 - uVar5);
  if (0x1e < (int)uVar6) {
    return (ulonglong)(param_1 >> (uVar6 - 0x1f & 0xff));
  }
  if (uVar6 - 0x13 == 0 || (int)(uVar6 - 0x1f) < -0xc) {
    uVar6 = uVar6 + 1;
    return CONCAT44(param_1 >> (uVar6 & 0xff),
                    uVar1 >> (uVar6 & 0xff) | param_1 << (0x20 - uVar6 & 0xff));
  }
  uVar6 = 0xc - (uVar6 - 0x13);
  return (ulonglong)(uVar1 >> (0x20 - uVar6 & 0xff) | param_1 << (uVar6 & 0xff));
}



/* Function: FUN_00009038 @ 00009038 */

ulonglong FUN_00009038(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint in_r12;
  bool bVar9;
  bool bVar10;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar8 = param_1 & 0x80000000;
  uVar2 = param_1;
  if ((int)uVar8 < 0) {
    uVar2 = -param_1;
  }
  uVar1 = 0;
  iVar5 = LZCOUNT(uVar2);
  uVar6 = iVar5 + 0x15;
  bVar10 = SBORROW4(uVar6,0x20);
  uVar3 = iVar5 - 0xb;
  bVar9 = uVar3 == 0;
  uVar7 = uVar3;
  uVar4 = uVar3;
  if (uVar6 < 0x20) {
    bVar10 = SCARRY4(uVar3,0xc);
    uVar4 = iVar5 + 1;
    bVar9 = uVar4 == 0;
    uVar7 = uVar6;
    if (!bVar9 && -0xd < (int)uVar3) {
      uVar1 = uVar2 << uVar6;
      uVar2 = uVar2 >> (0xc - uVar4 & 0xff);
      goto LAB_00008f00;
    }
  }
  if (bVar9 || (int)uVar4 < 0 != bVar10) {
    in_r12 = 0x20 - uVar7;
  }
  uVar2 = uVar2 << (uVar7 & 0xff);
  if (bVar9 || (int)uVar4 < 0 != bVar10) {
    uVar2 = uVar2 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar7 & 0xff);
  }
LAB_00008f00:
  if (uVar6 < 0x433) {
    return CONCAT44(uVar2 + (0x432 - uVar6) * 0x100000 | uVar8,uVar1);
  }
  uVar7 = ~(0x432 - uVar6);
  if (0x1e < (int)uVar7) {
    return CONCAT44(param_1,uVar2 >> (uVar7 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar7 - 0x13 == 0 || (int)(uVar7 - 0x1f) < -0xc) {
    uVar7 = uVar7 + 1;
    return CONCAT44(uVar8 | uVar2 >> (uVar7 & 0xff),
                    uVar1 >> (uVar7 & 0xff) | uVar2 << (0x20 - uVar7 & 0xff));
  }
  uVar8 = 0xc - (uVar7 - 0x13);
  return CONCAT44(param_1,uVar1 >> (0x20 - uVar8 & 0xff) | uVar2 << (uVar8 & 0xff)) &
         0x80000000ffffffff;
}



/* Function: FUN_00009114 @ 00009114 */

ulonglong FUN_00009114(undefined4 param_1,uint param_2,uint param_3,uint param_4)

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
    uVar14 = FUN_000092f4();
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



/* Function: FUN_000092f4 @ 000092f4 */

ulonglong FUN_000092f4(int param_1,uint param_2,int param_3,uint param_4)

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



/* Function: FUN_00009380 @ 00009380 */

ulonglong FUN_00009380(undefined4 param_1,uint param_2,uint param_3,uint param_4)

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
    uVar16 = FUN_00009514();
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
        if ((uVar6 & 0x100000) != 0) goto LAB_000094c0;
        uVar6 = uVar6 | uVar2;
        uVar2 = 0;
        uVar11 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar2;
      uVar2 = 0;
    }
LAB_000094c0:
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



/* Function: FUN_00009514 @ 00009514 */

ulonglong FUN_00009514(int param_1,uint param_2,int param_3,uint param_4)

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
LAB_0000935c:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
      }
    }
    else if (uVar2 == in_r12) {
      param_1 = param_3;
      uVar3 = param_4;
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
LAB_00009310:
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
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) goto LAB_0000935c;
      if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) goto LAB_00009310;
    }
  }
  return CONCAT44(uVar3,param_1) | 0x7ff8000000000000;
}



/* Function: FUN_00009594 @ 00009594 */

uint FUN_00009594(uint param_1,uint param_2,uint param_3,uint param_4)

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



/* Function: FUN_0000961c @ 0000961c */

void FUN_0000961c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00009638(param_3,param_4,param_1,param_2);
  return;
}



/* Function: FUN_00009638 @ 00009638 */

undefined4 FUN_00009638(undefined4 param_1)

{
  FUN_00009594();
  return param_1;
}



/* Function: FUN_0000964c @ 0000964c */

undefined1 FUN_0000964c(void)

{
  undefined1 in_ZR;
  
  FUN_00009638();
  return in_ZR;
}



/* Function: FUN_00009660 @ 00009660 */

bool FUN_00009660(void)

{
  undefined1 in_CY;
  
  FUN_00009638();
  return !(bool)in_CY;
}



/* Function: FUN_00009674 @ 00009674 */

bool FUN_00009674(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_00009638();
  return !(bool)in_CY || (bool)in_ZR;
}



/* Function: FUN_00009688 @ 00009688 */

bool FUN_00009688(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_0000961c();
  return !(bool)in_CY || (bool)in_ZR;
}



/* Function: FUN_0000969c @ 0000969c */

bool FUN_0000969c(void)

{
  undefined1 in_CY;
  
  FUN_0000961c();
  return !(bool)in_CY;
}



/* Function: FUN_000096b0 @ 000096b0 */

uint FUN_000096b0(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar2) {
      return 0;
    }
    uVar1 = iVar2 >> 0x15;
    uVar3 = -uVar1 - 0x3e1;
    if (uVar1 < 0xfffffc20 && uVar3 != 0) {
      uVar1 = (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
      if ((param_2 & 0x80000000) != 0) {
        uVar1 = -uVar1;
      }
      return uVar1;
    }
  }
  else if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    return 0;
  }
  param_2 = param_2 & 0x80000000;
  if (param_2 == 0) {
    param_2 = 0x7fffffff;
  }
  return param_2;
}



/* Function: FUN_0000970c @ 0000970c */

uint FUN_0000970c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_r12;
  bool bVar4;
  bool bVar5;
  
  uVar2 = param_2 * 2;
  bVar5 = uVar2 < 0x70000000;
  uVar3 = uVar2 + 0x90000000;
  uVar1 = uVar3;
  if (!bVar5) {
    in_r12 = uVar2 + 0x8fe00000;
    uVar1 = in_r12;
  }
  bVar4 = uVar1 == 0;
  if (!bVar5 && uVar3 >= 0x200000) {
    bVar4 = in_r12 == 0x1fc00000;
  }
  if (((bVar5 || uVar3 < 0x200000) || 0x1fc00000 < in_r12) || bVar4) {
    if ((param_2 & 0x40000000) != 0) {
      if (((int)uVar2 >> 0x15 == -1) && (param_1 != 0 || (param_2 & 0xfffff) != 0)) {
        return 0x7fc00000;
      }
      return param_2 & 0x80000000 | 0x7f800000;
    }
    if ((int)uVar3 < -0x2e00000) {
      return param_2 & 0x80000000;
    }
    uVar3 = 0x18 - (uVar2 + 0x92e00000 >> 0x15);
    uVar2 = param_1 >> (uVar3 & 0xff);
    if (param_1 << (0x20 - uVar3 & 0xff) != 0) {
      uVar2 = uVar2 | 1;
    }
    uVar1 = param_2 & 0x1fffff | 0x100000;
    param_1 = uVar2 | uVar1 << (0x20 - uVar3 & 0xff);
    uVar3 = (uVar1 >> (uVar3 & 0xff)) << 1;
  }
  uVar2 = (param_2 & 0x80000000 | param_1 >> 0x1d) + uVar3 * 4 + (uint)(0x7fffffff < param_1 * 8);
  if (param_1 * 8 == 0x80000000) {
    uVar2 = uVar2 & 0xfffffffe;
  }
  return uVar2;
}



/* Function: FUN_000097ac @ 000097ac */

undefined8 FUN_000097ac(uint param_1,int param_2,uint param_3,int param_4)

{
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20) +
                  param_1 * param_4 + param_3 * param_2,
                  (int)((ulonglong)param_1 * (ulonglong)param_3));
}



/* Function: FUN_000097c0 @ 000097c0 */

void FUN_000097c0(void)

{
  FUN_0000983c();
  return;
}



/* Function: FUN_000097dc @ 000097dc */

void FUN_000097dc(void)

{
  FUN_000097f8();
  return;
}



/* Function: FUN_000097f8 @ 000097f8 */

void FUN_000097f8(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = FUN_0000b14c();
  lVar2 = lVar2 * CONCAT44(param_4,param_3);
  uVar1 = (uint)lVar2;
  *param_5 = param_1 - uVar1;
  param_5[1] = param_2 - ((int)((ulonglong)lVar2 >> 0x20) + (uint)(param_1 < uVar1));
  return;
}



/* Function: FUN_0000983c @ 0000983c */

void FUN_0000983c(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = FUN_0000acd0();
  lVar2 = lVar2 * CONCAT44(param_4,param_3);
  uVar1 = (uint)lVar2;
  *param_5 = param_1 - uVar1;
  param_5[1] = param_2 - ((int)((ulonglong)lVar2 >> 0x20) + (uint)(param_1 < uVar1));
  return;
}



/* Function: FUN_00009880 @ 00009880 */

int FUN_00009880(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    iVar1 = iVar1 + (int)param_1;
  }
  return iVar1;
}



/* Function: FUN_00009894 @ 00009894 */

undefined4 FUN_00009894(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  bool bVar1;
  
  if (param_2 == 0) {
    bVar1 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar1 = param_4 == 0;
    }
    if (bVar1) {
      *param_5 = *(undefined4 *)(param_1 + param_3 * 4 + 4);
      return 0;
    }
  }
  else if (param_2 < 5) {
    return 1;
  }
  return 2;
}



/* Function: FUN_000098e0 @ 000098e0 */

undefined4 FUN_000098e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  
  local_c = param_4;
  FUN_00009894(param_1,0,param_2,0,&local_c,param_2,param_3);
  return local_c;
}



/* Function: FUN_00009908 @ 00009908 */

undefined4 FUN_00009908(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  bool bVar1;
  
  if (param_2 == 0) {
    bVar1 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar1 = param_4 == 0;
    }
    if (bVar1) {
      *(undefined4 *)(param_1 + param_3 * 4 + 4) = *param_5;
      return 0;
    }
  }
  else if (param_2 < 5) {
    return 1;
  }
  return 2;
}



/* Function: FUN_00009954 @ 00009954 */

void FUN_00009954(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  
  local_c = param_3;
  FUN_00009908(param_1,0,param_2,0,&local_c,param_2,param_3);
  return;
}



/* Function: FUN_00009980 @ 00009980 */

int FUN_00009980(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x40000000) == 0) {
    uVar1 = uVar1 & 0x7fffffff;
  }
  else {
    uVar1 = uVar1 | 0x80000000;
  }
  return (int)param_1 + uVar1;
}



/* Function: FUN_00009998 @ 00009998 */

int FUN_00009998(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == 0) {
LAB_00009a18:
    iVar5 = 0;
  }
  else {
    iVar6 = 0;
    iVar7 = param_2 + -1;
    do {
      while( true ) {
        iVar1 = (iVar7 + iVar6) / 2;
        iVar5 = param_1 + iVar1 * 8;
        uVar2 = FUN_00009980(iVar5);
        uVar4 = 0xffffffff;
        if (iVar1 != param_2 + -1) {
          iVar3 = FUN_00009980(param_1 + (iVar1 + 1) * 8);
          uVar4 = iVar3 - 1;
        }
        if (uVar2 <= param_3) break;
        iVar7 = iVar1 + -1;
        if (iVar1 == iVar6) goto LAB_00009a18;
      }
      iVar6 = iVar1 + 1;
    } while (uVar4 < param_3);
  }
  return iVar5;
}



/* Function: FUN_00009a50 @ 00009a50 */

undefined4 FUN_00009a50(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  int local_38;
  uint *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  int local_2c;
  
  uVar7 = param_1 & 3;
  local_34 = *(uint **)(param_2 + 0x4c) + 1;
  uVar4 = **(uint **)(param_2 + 0x4c);
  if (param_4 == 0) {
    local_38 = uVar4 << 8;
    local_30 = 3;
    local_2f = 0;
    puVar8 = local_34;
  }
  else {
    local_38 = uVar4 << 0x10;
    puVar8 = local_34 + (uVar4 >> 0x10 & 0xff);
    local_30 = 2;
    local_2f = (undefined1)(uVar4 >> 0x10);
  }
  if (uVar7 == 2) {
    puVar8 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar5 = param_2 + 0x58;
    bVar10 = false;
LAB_00009d94:
    do {
      while( true ) {
        uVar4 = *puVar8;
        if (uVar4 == 0) goto LAB_00009da0;
        if (param_4 == 2) {
          uVar12 = puVar8[1];
        }
        else {
          uVar12 = (uint)*(ushort *)((int)puVar8 + 2);
        }
        if (param_4 == 2) {
          puVar6 = puVar8 + 2;
        }
        else {
          uVar4 = (uint)(ushort)*puVar8;
          puVar6 = puVar8 + 1;
        }
        uVar9 = (uVar12 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        uVar13 = FUN_000098e0(param_3,0xf);
        uVar3 = (undefined4)((ulonglong)uVar13 >> 0x20);
        if ((uint)uVar13 < uVar9) {
          bVar1 = false;
        }
        else if ((uint)uVar13 < uVar9 + (uVar4 & 0xfffffffe)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        uVar4 = uVar4 & 1 | (uVar12 & 1) << 1;
        if (uVar4 != 1) break;
        if (uVar7 == 0) {
          if (bVar1) {
            if (puVar6[1] == 0xfffffffe) {
              return 9;
            }
            local_2c = iVar5;
            if ((puVar6[1] != 0xffffffff) && (FUN_00009880(puVar6 + 1), param_2 == 0)) {
              local_2c = 0;
            }
            if (local_2c != 0) {
LAB_00009cd8:
              uVar3 = FUN_000098e0(param_3,0xd);
              *(int *)(param_2 + 0x24) = local_2c;
              *(uint **)(param_2 + 0x28) = puVar6;
              *(undefined4 *)(param_2 + 0x20) = uVar3;
              return 6;
            }
          }
        }
        else {
          iVar11 = *(int *)(param_2 + 0x20);
          iVar2 = FUN_000098e0(param_3,0xd);
          if ((iVar11 == iVar2) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            uVar3 = FUN_00009980(puVar6);
            FUN_00009954(param_3,0xf,uVar3);
            uVar3 = 0;
            goto LAB_00009d70;
          }
        }
        puVar8 = puVar6 + 2;
      }
      if (uVar4 != 0) {
        if (uVar4 != 2) {
          return 9;
        }
        uVar4 = *puVar6 & 0x7fffffff;
        if (uVar7 == 0) {
          if ((bVar1) && ((param_1 & 8) == 0 || uVar4 == 0)) {
            uVar12 = 0;
            puVar8 = puVar6;
            do {
              uVar9 = uVar12;
              puVar8 = puVar8 + 1;
              if (uVar4 <= uVar9) break;
              local_2c = iVar5;
              uVar3 = FUN_00009880(puVar8,uVar3);
              uVar12 = uVar9 + 1;
            } while (param_2 == 0);
            if (uVar9 == uVar4) goto LAB_00009cd8;
          }
        }
        else {
          iVar11 = *(int *)(param_2 + 0x20);
          iVar2 = FUN_000098e0(param_3,0xd);
          if ((iVar11 == iVar2) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar6 + 1;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(uint *)(param_2 + 0x28) = uVar4;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar6) {
              uVar3 = FUN_00009980(puVar6 + uVar4 + 1);
              FUN_00009954(param_3,0xf,uVar3);
              uVar3 = 0;
              goto LAB_00009d70;
            }
            bVar10 = true;
          }
        }
        if ((int)*puVar6 < 0) {
          puVar6 = puVar6 + 1;
        }
        puVar8 = puVar6 + uVar4 + 1;
        goto LAB_00009d94;
      }
      if (uVar7 == 0) {
        bVar1 = false;
      }
      puVar8 = puVar6 + 1;
    } while (!bVar1);
    FUN_00009980(puVar6);
    *(uint **)(param_2 + 0x38) = puVar8;
    if (param_2 == 0) {
      return 9;
    }
    uVar3 = 0xf;
  }
  else {
    bVar10 = false;
LAB_00009da0:
    iVar5 = FUN_0000a918(param_3,&local_38);
    if (iVar5 != 0) {
      return 9;
    }
    if (!bVar10) {
      return 8;
    }
    uVar3 = FUN_000098e0(param_3,0xf);
    FUN_00009954(param_3,0xe,uVar3);
    uVar3 = 0xf;
  }
LAB_00009d70:
  FUN_00009954(param_3,uVar3);
  return 7;
}



/* Function: FUN_00009e18 @ 00009e18 */

undefined8 FUN_00009e18(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_14;
  
  iVar5 = param_2 + -2;
  if (DAT_00009f34 == 0) {
    local_14 = DAT_00009f3c - DAT_00009f38 >> 3;
    iVar1 = DAT_00009f38;
LAB_00009e64:
    iVar5 = FUN_00009998(iVar1,local_14,iVar5);
    if (iVar5 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      uVar4 = 9;
      goto LAB_00009f2c;
    }
    uVar4 = FUN_00009980();
    *(undefined4 *)(param_1 + 0x48) = uVar4;
    if (*(int *)(iVar5 + 4) == 1) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      uVar4 = 5;
      goto LAB_00009f2c;
    }
    if (*(int *)(iVar5 + 4) < 0) {
      *(int *)(param_1 + 0x4c) = iVar5 + 4;
      *(undefined4 *)(param_1 + 0x50) = 1;
    }
    else {
      uVar4 = FUN_00009980();
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x4c) = uVar4;
    }
    if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
      uVar2 = FUN_00009980();
      uVar4 = 0;
      *(undefined4 *)(param_1 + 0x10) = uVar2;
      goto LAB_00009f2c;
    }
    uVar3 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
    if (uVar3 == 0) {
      *(undefined4 *)(param_1 + 0x10) = DAT_00009f40;
      uVar4 = 0;
      goto LAB_00009f2c;
    }
    uVar4 = DAT_00009f44;
    if ((uVar3 == 1) || (uVar4 = DAT_00009f48, uVar3 == 2)) {
      *(undefined4 *)(param_1 + 0x10) = uVar4;
      uVar4 = 0;
      goto LAB_00009f2c;
    }
  }
  else {
    iVar1 = iVar5;
    local_14 = param_2;
    if (iVar5 != 0) goto LAB_00009e64;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  uVar4 = 9;
LAB_00009f2c:
  return CONCAT44(param_1,uVar4);
}



/* Function: FUN_00009f4c @ 00009f4c */

void FUN_00009f4c(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      FUN_0000a6c0(param_1 + 0x12);
    }
    else {
      FUN_0000a6d0();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_0000a6e0(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_0000a6f0(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_0000a778(param_1 + 0x8c);
  return;
}



/* Function: FUN_00009fb8 @ 00009fb8 */

int FUN_00009fb8(code *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_2b0;
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
  undefined4 uStack_280;
  undefined4 local_27c;
  undefined4 uStack_278;
  undefined4 uStack_274;
  undefined4 local_270;
  undefined1 auStack_70 [16];
  code *local_60;
  
  *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_3 + 0x3c);
  local_2ac = *(undefined4 *)(param_3 + 4);
  uStack_2a8 = *(undefined4 *)(param_3 + 8);
  uStack_2a4 = *(undefined4 *)(param_3 + 0xc);
  uStack_2a0 = *(undefined4 *)(param_3 + 0x10);
  local_29c = *(undefined4 *)(param_3 + 0x14);
  uStack_298 = *(undefined4 *)(param_3 + 0x18);
  uStack_294 = *(undefined4 *)(param_3 + 0x1c);
  uStack_290 = *(undefined4 *)(param_3 + 0x20);
  local_28c = *(undefined4 *)(param_3 + 0x24);
  uStack_288 = *(undefined4 *)(param_3 + 0x28);
  uStack_284 = *(undefined4 *)(param_3 + 0x2c);
  uStack_280 = *(undefined4 *)(param_3 + 0x30);
  local_27c = *(undefined4 *)(param_3 + 0x34);
  uStack_278 = *(undefined4 *)(param_3 + 0x38);
  uStack_274 = *(undefined4 *)(param_3 + 0x3c);
  local_270 = *(undefined4 *)(param_3 + 0x40);
  local_2b0 = 0xffffffff;
  do {
    iVar1 = FUN_00009e18(auStack_70,local_270);
    if (iVar1 != 0) {
LAB_0000a068:
      iVar1 = 9;
      break;
    }
    FUN_00009954(&local_2b0,0xc,auStack_70);
    iVar1 = (*param_1)(&local_2b0,param_2);
    if (iVar1 != 0) goto LAB_0000a068;
    iVar1 = (*local_60)(8,auStack_70,&local_2b0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_00009f4c(&local_2b0);
  return iVar1;
}



/* Function: FUN_0000a080 @ 0000a080 */

int FUN_0000a080(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_00009e18(param_1,local_228);
    if (param_3 == 0) {
      uVar5 = 9;
    }
    else {
      uVar5 = 10;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = local_228;
      FUN_00008170(auStack_4a8,&local_268,0x240);
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
    FUN_00008170(&local_268,auStack_4a8,0x240);
    param_3 = 0;
  } while (iVar3 == 8);
  if (iVar3 == 7) {
    FUN_0000a6ac(&local_264);
  }
  return 9;
}



/* Function: FUN_0000a1b8 @ 0000a1b8 */

void FUN_0000a1b8(int param_1,int param_2)

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
    iVar1 = FUN_00009e18(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_0000a204;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 != 7) {
LAB_0000a204:
    FUN_00013a24();
  }
  uVar4 = FUN_0000a6ac(param_2 + 4);
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
    iVar2 = FUN_00009e18(iVar1,local_228);
    if (iVar2 != 0) goto LAB_0000a2a8;
    iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&local_268);
  } while (iVar2 == 8);
  FUN_00009f4c(&local_268);
  if (iVar2 == 6) {
    FUN_0000a1b8(iVar1,iVar3);
  }
LAB_0000a2a8:
                    /* WARNING: Could not recover jumptable at 0x0000a2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0xa210)(9);
  return;
}



/* Function: FUN_0000a340 @ 0000a340 */

undefined4 FUN_0000a340(uint *param_1,undefined4 param_2,uint param_3,int param_4)

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
        FUN_0000a6d8();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        FUN_0000a6c8(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_0000a6e8(param_1 + 0x34);
    }
    if (bVar8) {
      FUN_0000a6c8(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000a6d8(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_0000a4dc;
      FUN_0000a6e8(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_0000a4dc:
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
      FUN_0000a6c0(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000a6d0(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_0000a6e0(local_b0);
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
          FUN_0000a734(param_1 + 0x6c);
        }
        FUN_0000a734(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_0000a6f0(auStack_130);
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
        FUN_0000a78c(param_1 + 0x8c);
      }
      FUN_0000a78c(local_30);
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
      FUN_0000a778(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: FUN_0000a6ac @ 0000a6ac */

undefined8 FUN_0000a6ac(undefined8 *param_1)

{
  return *param_1;
}



/* Function: FUN_0000a6c0 @ 0000a6c0 */

undefined4 FUN_0000a6c0(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0000a6c8 @ 0000a6c8 */

void FUN_0000a6c8(undefined8 *param_1)

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



/* Function: FUN_0000a6d0 @ 0000a6d0 */

undefined4 FUN_0000a6d0(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0000a6d8 @ 0000a6d8 */

void FUN_0000a6d8(undefined8 *param_1)

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



/* Function: FUN_0000a6e0 @ 0000a6e0 */

void FUN_0000a6e0(void)

{
  return;
}



/* Function: FUN_0000a6e8 @ 0000a6e8 */

void FUN_0000a6e8(undefined8 *param_1)

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



/* Function: FUN_0000a6f0 @ 0000a6f0 */

int FUN_0000a6f0(int param_1)

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



/* Function: FUN_0000a734 @ 0000a734 */

int FUN_0000a734(int param_1)

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



/* Function: FUN_0000a778 @ 0000a778 */

int FUN_0000a778(int param_1)

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



/* Function: FUN_0000a78c @ 0000a78c */

int FUN_0000a78c(int param_1)

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



/* Function: FUN_0000a854 @ 0000a854 */

uint FUN_0000a854(uint *param_1)

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



/* Function: FUN_0000a8ac @ 0000a8ac */

undefined4 FUN_0000a8ac(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined8 uVar2;
  undefined4 local_1c;
  
  FUN_00013a24();
  uVar2 = FUN_00013a24();
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  local_1c = extraout_r3;
  FUN_00009894((int)uVar2,0,uVar1,0,&local_1c,uVar1,extraout_r2);
  return local_1c;
}



/* Function: FUN_0000a8e4 @ 0000a8e4 */

undefined4 FUN_0000a8e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  
  uStack_c = param_4;
  FUN_00009894(param_1,0,0xc,0,&uStack_c,0xc,param_3);
  return uStack_c;
}



/* Function: FUN_0000a908 @ 0000a908 */

undefined4 FUN_0000a908(void)

{
  int iVar1;
  
  iVar1 = FUN_0000a8e4();
  return *(undefined4 *)(iVar1 + 0x48);
}



/* Function: FUN_0000a918 @ 0000a918 */

undefined4 FUN_0000a918(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
LAB_0000a930:
  do {
    while( true ) {
      uVar1 = FUN_0000a854(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        FUN_00009894(param_1,0,0xe,0,&local_24,uVar7,param_3);
        FUN_00009908(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      FUN_00009894(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_0000aa68:
      piVar6 = &local_24;
      FUN_00009908(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_0000a854(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = FUN_0000a340(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_0000a930;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      FUN_00009894(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_0000aa68;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_0000a854(param_2);
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
          FUN_00009894(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_0000a854(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_0000aa68;
        }
        if (uVar1 == 0xb3) {
          FUN_0000a854(param_2);
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
        FUN_0000a854(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_0000a854(param_2);
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
            FUN_0000a854(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_0000a854(param_2);
          }
          goto LAB_0000ac6c;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_0000ac6c:
      uVar2 = 1;
    }
    iVar5 = FUN_0000a340(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: FUN_0000ac90 @ 0000ac90 */

void FUN_0000ac90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_0000a918(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}



/* Function: FUN_0000acd0 @ 0000acd0 */

undefined8 FUN_0000acd0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  if ((int)param_2 < 0) {
    bVar12 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + bVar12);
    uVar8 = 0xffffffff;
  }
  else {
    uVar8 = 0;
  }
  if ((int)param_4 < 0) {
    bVar12 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(param_4 + bVar12);
    uVar8 = ~uVar8;
  }
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        param_3 = FUN_00008ba0(1,0);
      }
      iVar4 = LZCOUNT(param_3);
      if (iVar4 == 0) {
        iVar4 = param_2 - param_3;
        uVar6 = 1;
      }
      else {
        param_3 = param_3 << iVar4;
        uVar7 = param_2 >> (0x20U - iVar4 & 0xff);
        uVar2 = param_3 >> 0x10;
        uVar9 = param_1 >> (0x20U - iVar4 & 0xff) | param_2 << iVar4;
        param_1 = param_1 << iVar4;
        FUN_00008c4c(uVar7,uVar2);
        iVar4 = FUN_00008ba0(uVar7,uVar2);
        uVar10 = uVar9 >> 0x10 | extraout_r1_01 << 0x10;
        uVar7 = (param_3 & 0xffff) * iVar4;
        iVar1 = iVar4;
        if (uVar10 < uVar7) {
          bVar12 = CARRY4(uVar10,param_3);
          uVar10 = uVar10 + param_3;
          iVar1 = iVar4 + -1;
          if ((!bVar12) && (uVar10 < uVar7)) {
            iVar1 = iVar4 + -2;
            uVar10 = uVar10 + param_3;
          }
        }
        FUN_00008c4c(uVar10 - uVar7,uVar2);
        uVar2 = FUN_00008ba0(uVar10 - uVar7,uVar2);
        uVar9 = uVar9 & 0xffff | extraout_r1_02 << 0x10;
        uVar7 = (param_3 & 0xffff) * uVar2;
        uVar6 = uVar2;
        if (uVar9 < uVar7) {
          bVar12 = CARRY4(uVar9,param_3);
          uVar9 = uVar9 + param_3;
          uVar6 = uVar2 - 1;
          if ((!bVar12) && (uVar9 < uVar7)) {
            uVar6 = uVar2 - 2;
            uVar9 = uVar9 + param_3;
          }
        }
        iVar4 = uVar9 - uVar7;
        uVar6 = uVar6 | iVar1 << 0x10;
      }
      uVar2 = param_3 >> 0x10;
      FUN_00008c4c(iVar4,uVar2);
      iVar1 = FUN_00008ba0(iVar4,uVar2);
      uVar9 = param_1 >> 0x10 | extraout_r1_03 << 0x10;
      uVar7 = (param_3 & 0xffff) * iVar1;
      iVar4 = iVar1;
      if (uVar9 < uVar7) {
        bVar12 = CARRY4(uVar9,param_3);
        uVar9 = uVar9 + param_3;
        iVar4 = iVar1 + -1;
        if ((!bVar12) && (uVar9 < uVar7)) {
          iVar4 = iVar1 + -2;
          uVar9 = uVar9 + param_3;
        }
      }
      FUN_00008c4c(uVar9 - uVar7,uVar2);
      uVar7 = FUN_00008ba0(uVar9 - uVar7,uVar2);
      uVar10 = param_1 & 0xffff | extraout_r1_04 << 0x10;
      uVar9 = (param_3 & 0xffff) * uVar7;
      uVar2 = uVar7;
      if (uVar10 < uVar9) {
        uVar2 = uVar7 - 1;
        if ((!CARRY4(uVar10,param_3)) && (uVar10 + param_3 < uVar9)) {
          uVar2 = uVar7 - 2;
        }
      }
      uVar2 = uVar2 | iVar4 << 0x10;
      goto LAB_0000b124;
    }
    iVar4 = LZCOUNT(param_3);
    if (iVar4 != 0) {
      param_3 = param_3 << iVar4;
      param_2 = param_1 >> (0x20U - iVar4 & 0xff) | param_2 << iVar4;
    }
    uVar2 = param_3 >> 0x10;
    if (iVar4 != 0) {
      param_1 = param_1 << iVar4;
    }
    FUN_00008c4c(param_2,uVar2);
    iVar1 = FUN_00008ba0(param_2,uVar2);
    uVar9 = param_1 >> 0x10 | extraout_r1 << 0x10;
    uVar7 = (param_3 & 0xffff) * iVar1;
    iVar4 = iVar1;
    if (uVar9 < uVar7) {
      bVar12 = CARRY4(uVar9,param_3);
      uVar9 = uVar9 + param_3;
      iVar4 = iVar1 + -1;
      if ((!bVar12) && (uVar9 < uVar7)) {
        iVar4 = iVar1 + -2;
        uVar9 = uVar9 + param_3;
      }
    }
    FUN_00008c4c(uVar9 - uVar7,uVar2);
    uVar7 = FUN_00008ba0(uVar9 - uVar7,uVar2);
    uVar10 = param_1 & 0xffff | extraout_r1_00 << 0x10;
    uVar9 = (param_3 & 0xffff) * uVar7;
    uVar2 = uVar7;
    if (uVar10 < uVar9) {
      uVar2 = uVar7 - 1;
      if ((!CARRY4(uVar10,param_3)) && (uVar10 + param_3 < uVar9)) {
        uVar2 = uVar7 - 2;
      }
    }
    uVar2 = uVar2 | iVar4 << 0x10;
LAB_0000b114:
    uVar6 = 0;
  }
  else {
    if (param_4 <= param_2) {
      iVar4 = LZCOUNT(param_4);
      if (iVar4 != 0) {
        uVar9 = 0x20 - iVar4;
        uVar7 = param_2 >> (uVar9 & 0xff);
        uVar5 = param_3 >> (uVar9 & 0xff) | param_4 << iVar4;
        uVar2 = uVar5 >> 0x10;
        uVar9 = param_1 >> (uVar9 & 0xff) | param_2 << iVar4;
        FUN_00008c4c(uVar7,uVar2);
        iVar3 = FUN_00008ba0(uVar7,uVar2);
        uVar7 = (uVar5 & 0xffff) * iVar3;
        uVar10 = uVar9 >> 0x10 | extraout_r1_05 << 0x10;
        iVar1 = iVar3;
        if (uVar10 < uVar7) {
          bVar12 = CARRY4(uVar10,uVar5);
          uVar10 = uVar10 + uVar5;
          iVar1 = iVar3 + -1;
          if ((!bVar12) && (uVar10 < uVar7)) {
            iVar1 = iVar3 + -2;
            uVar10 = uVar10 + uVar5;
          }
        }
        FUN_00008c4c(uVar10 - uVar7,uVar2);
        uVar7 = FUN_00008ba0(uVar10 - uVar7,uVar2);
        uVar10 = uVar9 & 0xffff | extraout_r1_06 << 0x10;
        uVar9 = (uVar5 & 0xffff) * uVar7;
        uVar2 = uVar7;
        if (uVar10 < uVar9) {
          bVar12 = CARRY4(uVar10,uVar5);
          uVar10 = uVar10 + uVar5;
          uVar2 = uVar7 - 1;
          if ((!bVar12) && (uVar10 < uVar9)) {
            uVar10 = uVar10 + uVar5;
            uVar2 = uVar7 - 2;
          }
        }
        uVar10 = uVar10 - uVar9;
        uVar2 = uVar2 | iVar1 << 0x10;
        uVar7 = uVar2 >> 0x10;
        uVar9 = (param_3 << iVar4) >> 0x10;
        uVar11 = uVar2 & ~(uVar7 << 0x10);
        uVar6 = param_3 << iVar4 & ~(uVar9 << 0x10);
        uVar5 = uVar11 * uVar6;
        uVar6 = uVar7 * uVar6;
        uVar11 = uVar9 * uVar11;
        iVar1 = uVar7 * uVar9;
        uVar7 = uVar6 + uVar11;
        if (CARRY4(uVar6,uVar11)) {
          iVar1 = iVar1 + 0x10000;
        }
        uVar9 = uVar7 * 0x10000;
        uVar7 = iVar1 + (uVar7 >> 0x10) + (uint)CARRY4(uVar5,uVar9);
        if ((uVar7 < uVar10 || uVar7 == uVar10) &&
           (uVar6 = 0, uVar5 + uVar9 <= param_1 << iVar4 || uVar7 != uVar10)) goto LAB_0000b124;
        uVar2 = uVar2 - 1;
        goto LAB_0000b114;
      }
      bVar12 = param_4 <= param_2;
      if (param_2 <= param_4) {
        bVar12 = param_3 <= param_1;
      }
      if (bVar12) {
        uVar2 = 1;
        uVar6 = 0;
        goto LAB_0000b124;
      }
    }
    uVar6 = 0;
    uVar2 = 0;
  }
LAB_0000b124:
  if (uVar8 != 0) {
    bVar12 = uVar2 != 0;
    uVar2 = -uVar2;
    uVar6 = -(uVar6 + bVar12);
  }
  return CONCAT44(uVar6,uVar2);
}



/* Function: FUN_0000b14c @ 0000b14c */

undefined8 FUN_0000b14c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int extraout_r1_04;
  int extraout_r1_05;
  int extraout_r1_06;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        param_3 = FUN_00008ba0(1,0);
      }
      iVar3 = LZCOUNT(param_3);
      if (iVar3 == 0) {
        iVar3 = param_2 - param_3;
        uVar8 = 1;
      }
      else {
        param_3 = param_3 << iVar3;
        uVar5 = param_2 >> (0x20U - iVar3 & 0xff);
        uVar7 = param_3 >> 0x10;
        uVar6 = param_1 >> (0x20U - iVar3 & 0xff) | param_2 << iVar3;
        param_1 = param_1 << iVar3;
        FUN_00008c4c(uVar5,uVar7);
        iVar3 = FUN_00008ba0(uVar5,uVar7);
        uVar5 = uVar6 >> 0x10 | extraout_r1_01 << 0x10;
        uVar4 = (param_3 & 0xffff) * iVar3;
        iVar1 = iVar3;
        if (uVar5 < uVar4) {
          bVar10 = CARRY4(uVar5,param_3);
          uVar5 = uVar5 + param_3;
          iVar1 = iVar3 + -1;
          if ((!bVar10) && (uVar5 < uVar4)) {
            iVar1 = iVar3 + -2;
            uVar5 = uVar5 + param_3;
          }
        }
        FUN_00008c4c(uVar5 - uVar4,uVar7);
        uVar7 = FUN_00008ba0(uVar5 - uVar4,uVar7);
        uVar6 = uVar6 & 0xffff | extraout_r1_02 << 0x10;
        uVar5 = (param_3 & 0xffff) * uVar7;
        uVar8 = uVar7;
        if (uVar6 < uVar5) {
          bVar10 = CARRY4(uVar6,param_3);
          uVar6 = uVar6 + param_3;
          uVar8 = uVar7 - 1;
          if ((!bVar10) && (uVar6 < uVar5)) {
            uVar8 = uVar7 - 2;
            uVar6 = uVar6 + param_3;
          }
        }
        iVar3 = uVar6 - uVar5;
        uVar8 = uVar8 | iVar1 << 0x10;
      }
      uVar7 = param_3 >> 0x10;
      FUN_00008c4c(iVar3,uVar7);
      iVar1 = FUN_00008ba0(iVar3,uVar7);
      uVar6 = param_1 >> 0x10 | extraout_r1_03 << 0x10;
      uVar5 = (param_3 & 0xffff) * iVar1;
      iVar3 = iVar1;
      if (uVar6 < uVar5) {
        bVar10 = CARRY4(uVar6,param_3);
        uVar6 = uVar6 + param_3;
        iVar3 = iVar1 + -1;
        if ((!bVar10) && (uVar6 < uVar5)) {
          iVar3 = iVar1 + -2;
          uVar6 = uVar6 + param_3;
        }
      }
      FUN_00008c4c(uVar6 - uVar5,uVar7);
      uVar5 = FUN_00008ba0(uVar6 - uVar5,uVar7);
      uVar4 = param_1 & 0xffff | extraout_r1_04 << 0x10;
      uVar6 = (param_3 & 0xffff) * uVar5;
      uVar7 = uVar5;
      if (uVar4 < uVar6) {
        uVar7 = uVar5 - 1;
        if ((!CARRY4(uVar4,param_3)) && (uVar4 + param_3 < uVar6)) {
          uVar7 = uVar5 - 2;
        }
      }
      uVar7 = uVar7 | iVar3 << 0x10;
      goto LAB_0000b548;
    }
    iVar3 = LZCOUNT(param_3);
    uVar6 = param_2;
    uVar5 = param_3;
    uVar7 = param_3;
    if (iVar3 != 0) {
      uVar7 = param_1 >> (0x20U - iVar3 & 0xff);
      uVar5 = param_3 << iVar3;
      uVar6 = uVar7 | param_2 << iVar3;
    }
    uVar4 = uVar5 >> 0x10;
    uVar9 = param_1;
    if (iVar3 != 0) {
      uVar9 = param_1 << iVar3;
    }
    FUN_00008c4c(uVar6,uVar4,uVar7,iVar3,param_1,param_2,param_3);
    iVar1 = FUN_00008ba0(uVar6,uVar4);
    uVar6 = uVar9 >> 0x10 | extraout_r1 << 0x10;
    uVar7 = (uVar5 & 0xffff) * iVar1;
    iVar3 = iVar1;
    if (uVar6 < uVar7) {
      bVar10 = CARRY4(uVar6,uVar5);
      uVar6 = uVar6 + uVar5;
      iVar3 = iVar1 + -1;
      if ((!bVar10) && (uVar6 < uVar7)) {
        iVar3 = iVar1 + -2;
        uVar6 = uVar6 + uVar5;
      }
    }
    FUN_00008c4c(uVar6 - uVar7,uVar4);
    uVar6 = FUN_00008ba0(uVar6 - uVar7,uVar4);
    uVar9 = uVar9 & 0xffff | extraout_r1_00 << 0x10;
    uVar4 = (uVar5 & 0xffff) * uVar6;
    uVar7 = uVar6;
    if (uVar9 < uVar4) {
      uVar7 = uVar6 - 1;
      if ((!CARRY4(uVar9,uVar5)) && (uVar9 + uVar5 < uVar4)) {
        uVar7 = uVar6 - 2;
      }
    }
    uVar7 = uVar7 | iVar3 << 0x10;
LAB_0000b538:
    uVar8 = 0;
  }
  else {
    if (param_4 <= param_2) {
      iVar3 = LZCOUNT(param_4);
      if (iVar3 != 0) {
        uVar4 = 0x20 - iVar3;
        uVar8 = param_3 >> (uVar4 & 0xff) | param_4 << iVar3;
        uVar5 = param_2 >> (uVar4 & 0xff);
        uVar6 = param_1 >> (uVar4 & 0xff);
        uVar7 = uVar8 >> 0x10;
        uVar9 = uVar6 | param_2 << iVar3;
        FUN_00008c4c(uVar5,uVar7,uVar4,uVar6,param_1,param_2,param_3);
        iVar1 = extraout_r1_05;
        iVar2 = FUN_00008ba0(uVar5,uVar7);
        uVar6 = uVar9 >> 0x10 | iVar1 << 0x10;
        param_3 = param_3 << iVar3;
        uVar5 = (uVar8 & 0xffff) * iVar2;
        iVar1 = iVar2;
        if (uVar6 < uVar5) {
          bVar10 = CARRY4(uVar6,uVar8);
          uVar6 = uVar6 + uVar8;
          iVar1 = iVar2 + -1;
          if ((!bVar10) && (uVar6 < uVar5)) {
            iVar1 = iVar2 + -2;
            uVar6 = uVar6 + uVar8;
          }
        }
        FUN_00008c4c(uVar6 - uVar5,uVar7);
        iVar2 = extraout_r1_06;
        uVar5 = FUN_00008ba0(uVar6 - uVar5,uVar7);
        uVar4 = uVar9 & 0xffff | iVar2 << 0x10;
        uVar6 = (uVar8 & 0xffff) * uVar5;
        uVar7 = uVar5;
        if (uVar4 < uVar6) {
          bVar10 = CARRY4(uVar4,uVar8);
          uVar4 = uVar4 + uVar8;
          uVar7 = uVar5 - 1;
          if ((!bVar10) && (uVar4 < uVar6)) {
            uVar4 = uVar4 + uVar8;
            uVar7 = uVar5 - 2;
          }
        }
        uVar4 = uVar4 - uVar6;
        uVar7 = uVar7 | iVar1 << 0x10;
        uVar5 = uVar7 >> 0x10;
        uVar6 = param_3 >> 0x10;
        uVar8 = uVar7 & ~(uVar5 << 0x10);
        param_3 = param_3 & ~(uVar6 << 0x10);
        uVar9 = uVar8 * param_3;
        param_3 = uVar5 * param_3;
        uVar8 = uVar6 * uVar8;
        iVar1 = uVar5 * uVar6;
        uVar5 = param_3 + uVar8;
        if (CARRY4(param_3,uVar8)) {
          iVar1 = iVar1 + 0x10000;
        }
        uVar6 = uVar5 * 0x10000;
        uVar5 = iVar1 + (uVar5 >> 0x10) + (uint)CARRY4(uVar9,uVar6);
        if ((uVar5 < uVar4 || uVar5 == uVar4) &&
           (uVar8 = 0, uVar9 + uVar6 <= param_1 << iVar3 || uVar5 != uVar4)) goto LAB_0000b548;
        uVar7 = uVar7 - 1;
        goto LAB_0000b538;
      }
      bVar10 = param_4 <= param_2;
      if (param_2 <= param_4) {
        bVar10 = param_3 <= param_1;
      }
      if (bVar10) {
        uVar7 = 1;
        uVar8 = 0;
        goto LAB_0000b548;
      }
    }
    uVar8 = 0;
    uVar7 = 0;
  }
LAB_0000b548:
  return CONCAT44(uVar8,uVar7);
}



/* Function: FUN_0000b558 @ 0000b558 */

void FUN_0000b558(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_b0 [4];
  undefined4 uStack_a0;
  undefined4 auStack_9c [32];
  int local_1c;
  
  iVar8 = DAT_0000b660 + 0xb564;
  local_1c = **(int **)(iVar8 + DAT_0000b664);
  local_b0[0] = *(undefined4 *)(DAT_0000b668 + 0xb570);
  local_b0[1] = *(undefined4 *)(DAT_0000b668 + 0xb574);
  local_b0[2] = *(undefined4 *)(DAT_0000b668 + 0xb578);
  local_b0[3] = *(undefined4 *)(DAT_0000b668 + 0xb57c);
  uStack_a0 = *(undefined4 *)(DAT_0000b668 + 0xb580);
  uVar2 = FUN_000080f0(local_b0[3],uStack_a0,auStack_9c,DAT_0000b668 + 0xb584);
  FUN_0000bf28(auStack_9c,DAT_0000b66c + 0xb586,uVar2);
  iVar3 = FUN_0000bba4(auStack_9c,0);
  if (iVar3 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    pcVar4 = (char *)FUN_000113c0(0x200);
    iVar5 = FUN_00008130(iVar3,pcVar4,DAT_0000b670);
    FUN_00008150(iVar3);
    if (0 < iVar5) {
      pcVar4[iVar5] = '\0';
      pcVar6 = pcVar4;
      while (cVar1 = *pcVar6, cVar1 != '\0') {
        if (((((byte)(cVar1 + 0xbfU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) ||
            ((byte)(cVar1 + 0x9fU) < 0x1a)) || (cVar1 == '.')) {
          pcVar6 = pcVar6 + 1;
        }
        else {
          *pcVar6 = '\0';
        }
      }
      puVar7 = local_b0;
      do {
        uVar2 = *puVar7;
        iVar3 = FUN_0000b7e0(uVar2);
        if ((iVar3 == (int)pcVar6 - (int)pcVar4) &&
           (iVar3 = FUN_00010b60(uVar2,pcVar4,(int)pcVar6 - (int)pcVar4), iVar3 == 0)) {
          uVar2 = 0;
          goto LAB_0000b642;
        }
        puVar7 = puVar7 + 1;
      } while (puVar7 != auStack_9c);
    }
    FUN_0000bc44(*(int *)(iVar8 + DAT_0000b674) + 0xa8,DAT_0000b678 + 0xb63a,pcVar4);
    uVar2 = 0xffffffff;
LAB_0000b642:
    FUN_000113dc(pcVar4);
  }
  if (local_1c != **(int **)(iVar8 + DAT_0000b664)) {
    FUN_000107d0(uVar2);
  }
  return;
}



/* Function: FUN_0000b7e0 @ 0000b7e0 */

char * FUN_0000b7e0(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *local_4;
  
  HintPreloadData(param_1);
  HintPreloadData(param_1 + 8);
  pcVar6 = (char *)0x0;
  if (((uint)param_1 & 3) == 0) {
LAB_0000b838:
    puVar1 = param_1 + 1;
    iVar4 = (int)pcVar6 - (int)puVar1;
    uVar3 = *param_1;
    while (HintPreloadData(puVar1 + 0x10), puVar2 = puVar1,
          (uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) == 0) {
      uVar3 = *puVar1;
      puVar2 = puVar1 + 1;
      if ((uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) != 0) break;
      uVar3 = puVar1[1];
      puVar2 = puVar1 + 2;
      if ((uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) != 0) break;
      uVar3 = puVar1[2];
      puVar2 = puVar1 + 3;
      if ((uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) != 0) break;
      uVar3 = puVar1[3];
      puVar2 = puVar1 + 4;
      if ((uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) != 0) break;
      uVar3 = puVar1[4];
      puVar2 = puVar1 + 5;
      if ((uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) != 0) break;
      uVar3 = puVar1[5];
      puVar2 = puVar1 + 6;
      if ((uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) != 0) break;
      puVar2 = puVar1 + 7;
      uVar3 = puVar1[6];
      if ((uVar3 - (DAT_0000b920 >> 7) & DAT_0000b920 & ~uVar3) != 0) break;
      puVar1 = puVar1 + 8;
      uVar3 = *puVar2;
    }
    pcVar5 = (char *)(iVar4 + (int)puVar2);
    pcVar6 = pcVar5;
    if ((((uVar3 & 0xff) != 0) && (pcVar6 = pcVar5 + 1, (uVar3 & 0xff00) != 0)) &&
       (pcVar6 = pcVar5 + 2, (uVar3 & 0xff0000) != 0)) {
      pcVar6 = pcVar5 + 3;
    }
  }
  else if ((char)*param_1 == '\0') {
    pcVar6 = (char *)0x0;
  }
  else {
    local_4 = (char *)((int)param_1 + 1);
    pcVar5 = (char *)0x1;
    do {
      pcVar6 = pcVar5;
      if (((uint)local_4 & 3) == 0) {
        param_1 = (uint *)((int)param_1 + (int)pcVar6);
        goto LAB_0000b838;
      }
      local_4 = (char *)((int)param_1 + (int)(pcVar6 + 1));
      pcVar5 = pcVar6 + 1;
    } while (local_4[-1] != '\0');
  }
  return pcVar6;
}



/* Function: FUN_0000b924 @ 0000b924 */

void FUN_0000b924(char *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  
  iVar1 = DAT_0000baf8;
  puVar9 = &stack0xffffffec + DAT_0000baf8;
  *(undefined4 *)(&stack0x00000000 + DAT_0000baf8) = param_2;
  iVar8 = DAT_0000bb00 + 0xb936;
  puVar6 = *(undefined4 **)(iVar8 + DAT_0000bafc);
  *(char **)(&stack0x0000000c + DAT_0000baf8) = param_1;
  *(undefined4 *)(&stack0xffffffec + DAT_0000bb04 + DAT_0000baf8) = *puVar6;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    iVar2 = FUN_000104c8(*(undefined4 *)(&stack0x0000000c + DAT_0000baf8),0x2f);
    if (iVar2 == 0) {
      iVar2 = FUN_0000de14(DAT_0000bb08 + 0xb96c);
      if (iVar2 == 0) {
        iVar2 = DAT_0000bb0c + 0xb978;
      }
      iVar3 = FUN_0000b7e0(iVar2);
      puVar9 = &stack0xffffffec + (iVar1 - (iVar3 + 0xfU & 0xfffffff8));
      *(undefined1 **)(&stack0x0000002c + iVar1) = puVar9;
      FUN_000105d0(puVar9,iVar2,iVar3 + 1);
      *(undefined1 **)(&stack0x00000008 + iVar1) = &stack0x00000030 + iVar1;
      *(undefined4 *)(&stack0x00000004 + iVar1) = 0;
      goto LAB_0000ba9a;
    }
    *(undefined4 *)(&stack0x0000002c + iVar1) = 0;
    *(undefined4 *)(&stack0x00000008 + iVar1) = *(undefined4 *)(&stack0x0000000c + iVar1);
    *(undefined4 *)(&stack0x00000004 + iVar1) = 0;
    do {
      FUN_00008590(*(undefined4 *)(&stack0x00000008 + iVar1),
                   *(undefined4 *)(&stack0x00000000 + iVar1),**(undefined4 **)(iVar8 + DAT_0000bb1c)
                  );
      piVar4 = (int *)FUN_000113b0();
      iVar2 = *piVar4;
      if (iVar2 < 0x16) {
        if (iVar2 < 0x14) {
          if (iVar2 == 8) {
            iVar2 = 0;
            piVar4 = *(int **)(&stack0x00000000 + iVar1);
            while (*piVar4 != 0) {
              iVar2 = iVar2 + 1;
              piVar4 = piVar4 + 1;
            }
            piVar4 = (int *)(puVar9 + (iVar2 * 4 + 0x16U >> 3) * -8);
            *piVar4 = DAT_0000bb20 + 0xba74;
            iVar3 = *(int *)(&stack0x00000000 + iVar1);
            piVar4[1] = *(int *)(&stack0x00000008 + iVar1);
            FUN_00010b84(iVar3 + 4,piVar4 + 2,iVar2 << 2);
            FUN_00008590(DAT_0000bb24 + 0xba90,piVar4,**(undefined4 **)(iVar8 + DAT_0000bb1c));
            goto LAB_0000bada;
          }
          if (iVar2 == 0xd) {
            *(undefined4 *)(&stack0x00000004 + iVar1) = 1;
          }
          else if (iVar2 != 2) goto LAB_0000bada;
        }
      }
      else if ((iVar2 != 0x24) && (iVar2 != 0x28)) goto LAB_0000bada;
LAB_0000ba9a:
      *(undefined1 **)(&stack0xfffffff0 + iVar1) = &stack0x0000002c + iVar1;
      *(int *)(&stack0x00000010 + iVar1) = DAT_0000bb28 + 0xbaa6;
      *(int *)(&stack0xfffffffc + iVar1) = DAT_0000bb2c + 0xbaa8;
      while( true ) {
        pcVar5 = (char *)FUN_0001060c(*(undefined4 *)(&stack0xfffffff0 + iVar1),
                                      *(undefined4 *)(&stack0x00000010 + iVar1));
        if (pcVar5 == (char *)0x0) {
          if (*(int *)(&stack0x00000004 + iVar1) == 0) {
            piVar4 = (int *)FUN_000113b0();
            if (*piVar4 != 0) goto LAB_0000bada;
            goto LAB_0000bad2;
          }
          puVar6 = (undefined4 *)FUN_000113b0();
          uVar7 = 0xd;
          goto LAB_0000bad8;
        }
        if (*pcVar5 == '\0') {
          iVar2 = 1;
          pcVar5 = *(char **)(&stack0xfffffffc + iVar1);
        }
        else {
          iVar2 = FUN_0000b7e0(pcVar5);
        }
        iVar3 = FUN_0000b7e0(*(undefined4 *)(&stack0x0000000c + iVar1));
        *(int *)(&stack0xfffffff8 + iVar1) = iVar3 + iVar2;
        *(int *)(&stack0xfffffff4 + iVar1) = iVar3;
        if (*(int *)(&stack0xfffffff8 + iVar1) <= DAT_0000bb10) break;
        *(int *)(&stack0x00000014 + iVar1) = DAT_0000bb14 + 0xb9d4;
        *(char **)(&stack0x0000001c + iVar1) = pcVar5;
        *(undefined4 *)(&stack0x00000018 + iVar1) = 8;
        *(int *)(&stack0x00000024 + iVar1) = DAT_0000bb18 + 0xb9dc;
        *(int *)(&stack0x00000020 + iVar1) = iVar2;
        *(undefined4 *)(&stack0x00000028 + iVar1) = 0x10;
        FUN_000086b0(2,&stack0x00000014 + iVar1,3);
      }
      *(undefined1 **)(&stack0x00000010 + iVar1) = &stack0x00000030 + iVar1;
      FUN_00010b84(pcVar5,&stack0x00000030 + iVar1,iVar2);
      iVar3 = *(int *)(&stack0x00000010 + iVar1);
      uVar7 = *(undefined4 *)(&stack0x0000000c + iVar1);
      *(undefined1 *)(iVar3 + iVar2) = 0x2f;
      FUN_00010b84(uVar7,iVar3 + iVar2 + 1,*(undefined4 *)(&stack0xfffffff4 + iVar1));
      *(undefined1 *)(*(int *)(&stack0x00000010 + iVar1) + *(int *)(&stack0xfffffff8 + iVar1) + 1) =
           0;
    } while( true );
  }
LAB_0000bad2:
  puVar6 = (undefined4 *)FUN_000113b0();
  uVar7 = 2;
LAB_0000bad8:
  *puVar6 = uVar7;
LAB_0000bada:
  if (*(int *)(&stack0xffffffec + DAT_0000bb04 + iVar1) != **(int **)(iVar8 + DAT_0000bafc)) {
    FUN_000107d0(0xffffffff);
  }
  return;
}



/* Function: FUN_0000bb34 @ 0000bb34 */

void FUN_0000bb34(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *local_28;
  int local_24 [2];
  int local_8 [2];
  
  local_8[1] = param_4;
  local_8[0] = param_3;
  iVar5 = DAT_0000bb9c + 0xbb42;
  local_24[0] = **(int **)(iVar5 + DAT_0000bba0);
  iVar2 = 1;
  piVar4 = local_8;
  do {
    iVar1 = *piVar4;
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar1 != 0);
  iVar2 = -(iVar2 * 4 + 0xeU & 0xfffffff8);
  puVar3 = (undefined4 *)((int)local_24 + iVar2 + -4);
  *puVar3 = param_2;
  piVar4 = (int *)((int)local_24 + iVar2);
  local_28 = local_8;
  do {
    iVar2 = *local_28;
    local_28 = local_28 + 1;
    *piVar4 = iVar2;
    piVar4 = piVar4 + 1;
  } while (iVar2 != 0);
  FUN_0000b924(param_1,puVar3);
  if (local_24[0] != **(int **)(iVar5 + DAT_0000bba0)) {
    FUN_000107d0();
  }
  return;
}



/* Function: FUN_0000bba4 @ 0000bba4 */

void FUN_0000bba4(undefined4 param_1,uint param_2,undefined2 param_3)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if ((int)(param_2 << 0x19) < 0) {
    uVar1 = param_3;
  }
  FUN_00008610(param_1,param_2 | 0x20000,uVar1);
  return;
}



/* Function: FUN_0000bbd0 @ 0000bbd0 */

void FUN_0000bbd0(undefined4 param_1)

{
  FUN_00010664();
  FUN_000085b0(param_1);
  return;
}



/* Function: FUN_0000bbe0 @ 0000bbe0 */

void FUN_0000bbe0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = (undefined4 *)(DAT_0000bc18 + 0xbbec);
  piVar2 = (int *)(DAT_0000bc1c + 0xbc6a);
  puVar1 = (undefined4 *)(DAT_0000bc18 + 0xbcb8);
  iVar4 = DAT_0000bc20 + 0xbbf8;
  do {
    *piVar2 = (int)puVar3;
    *puVar3 = 0;
    iVar5 = *piVar2;
    puVar3 = puVar3 + 3;
    piVar2 = piVar2 + 0x15;
    *(undefined4 *)(iVar5 + 4) = 0;
  } while (puVar3 != puVar1);
  FUN_0000dac0(*(undefined4 *)(iVar4 + DAT_0000bc24));
  **(undefined4 **)(iVar4 + DAT_0000bc28) = 1;
  return;
}



/* Function: FUN_0000bc2c @ 0000bc2c */

void FUN_0000bc2c(void)

{
  FUN_0000bee8(*(undefined4 *)(DAT_0000bc3c + 0xbc36 + DAT_0000bc40));
  return;
}



/* Function: FUN_0000bc44 @ 0000bc44 */

void FUN_0000bc44(undefined4 param_1,undefined4 param_2)

{
  FUN_0000c6b0(param_1,param_2);
  return;
}



/* Function: FUN_0000bc5c @ 0000bc5c */

void FUN_0000bc5c(undefined4 param_1,undefined4 param_2)

{
  FUN_0000b7e0();
  FUN_0000bc80(param_2);
  return;
}



/* Function: FUN_0000bc80 @ 0000bc80 */

undefined4 FUN_0000bc80(uint *param_1,int *param_2)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  
  if (param_2[2] != 0) {
    if (((-1 < (int)((uint)(ushort)param_1[3] << 0x1c)) || (param_1[4] == 0)) &&
       (iVar3 = FUN_0000da20(param_1), iVar3 != 0)) {
      puVar4 = (undefined4 *)FUN_000113b0();
      *puVar4 = 9;
      return 0xffffffff;
    }
    local_28 = (int *)*param_2;
    iVar3 = *local_28;
    uVar8 = local_28[1];
    local_28 = local_28 + 2;
    if ((int)((uint)(ushort)param_1[3] << 0x1e) < 0) {
      while( true ) {
        while (uVar8 == 0) {
          iVar3 = *local_28;
          puVar1 = (uint *)(local_28 + 1);
          local_28 = local_28 + 2;
          uVar8 = *puVar1;
        }
        iVar5 = (*(code *)param_1[0xb])(param_1[7],iVar3,uVar8);
        if (iVar5 < 1) goto LAB_0000bed2;
        iVar7 = param_2[2];
        param_2[2] = iVar7 - iVar5;
        if (iVar7 - iVar5 == 0) break;
        iVar3 = iVar3 + iVar5;
        uVar8 = uVar8 - iVar5;
      }
    }
    else if ((int)((uint)(ushort)param_1[3] << 0x1f) < 0) {
      local_2c = 0;
      bVar2 = false;
      while( true ) {
        while (uVar8 == 0) {
          bVar2 = false;
          iVar3 = *local_28;
          puVar1 = (uint *)(local_28 + 1);
          local_28 = local_28 + 2;
          uVar8 = *puVar1;
        }
        if (!bVar2) {
          iVar5 = FUN_00010458(iVar3,10,uVar8);
          if (iVar5 == 0) {
            local_2c = uVar8 + 1;
            bVar2 = true;
          }
          else {
            local_2c = (iVar5 + 1) - iVar3;
            bVar2 = true;
          }
        }
        local_24 = local_2c;
        if ((int)uVar8 < (int)local_2c) {
          local_24 = uVar8;
        }
        local_30 = param_1[5] + param_1[2];
        uVar6 = *param_1;
        if (((int)local_30 < (int)local_24) && (param_1[4] < uVar6)) {
          FUN_00008170(uVar6,iVar3,local_30);
          *param_1 = *param_1 + local_30;
          iVar5 = FUN_000115d4(param_1);
          if (iVar5 != 0) goto LAB_0000bed2;
        }
        else if ((int)local_24 < (int)param_1[5]) {
          FUN_00008170(uVar6,iVar3,local_24);
          param_1[2] = param_1[2] - local_24;
          *param_1 = *param_1 + local_24;
          local_30 = local_24;
        }
        else {
          local_30 = (*(code *)param_1[0xb])(param_1[7],iVar3);
          if ((int)local_30 < 1) goto LAB_0000bed2;
        }
        local_2c = local_2c - local_30;
        if (local_2c == 0) {
          iVar5 = FUN_000115d4(param_1);
          if (iVar5 != 0) goto LAB_0000bed2;
          bVar2 = false;
        }
        iVar5 = param_2[2];
        param_2[2] = iVar5 - local_30;
        if (iVar5 - local_30 == 0) break;
        iVar3 = iVar3 + local_30;
        uVar8 = uVar8 - local_30;
      }
    }
    else {
LAB_0000bd16:
      while (uVar8 == 0) {
        iVar3 = *local_28;
        puVar1 = (uint *)(local_28 + 1);
        local_28 = local_28 + 2;
        uVar8 = *puVar1;
      }
      if (((param_1[3] & 0x4200) == 0x4200) && ((int)param_1[2] < (int)uVar8)) {
        local_30 = param_1[5];
        iVar5 = *param_1 - param_1[4];
        do {
          iVar7 = local_30 * 2;
          local_30 = iVar7 + 1;
        } while ((int)local_30 < (int)(uVar8 + iVar5));
        uVar6 = FUN_00011414(param_1[4],iVar7 + 2);
        if (uVar6 == 0) {
LAB_0000bed2:
          *(ushort *)(param_1 + 3) = (ushort)param_1[3] | 0x40;
          return 0xffffffff;
        }
        param_1[4] = uVar6;
        param_1[2] = (param_1[2] - param_1[5]) + local_30;
        param_1[5] = local_30;
        *param_1 = uVar6 + iVar5;
      }
      local_30 = param_1[2];
      if ((param_1[3] & 0x200) == 0) {
        uVar6 = *param_1;
        if (((int)local_30 < (int)uVar8) && (param_1[4] < uVar6)) {
          FUN_00008170(uVar6,iVar3);
          *param_1 = *param_1 + local_30;
          iVar5 = FUN_000115d4(param_1);
          if (iVar5 != 0) goto LAB_0000bed2;
        }
        else {
          if ((int)uVar8 < (int)param_1[5]) {
            FUN_00008170(uVar6,iVar3,uVar8);
            param_1[2] = param_1[2] - uVar8;
            local_24 = *param_1 + uVar8;
            goto LAB_0000bdee;
          }
          local_30 = (*(code *)param_1[0xb])(param_1[7],iVar3);
          if ((int)local_30 < 1) goto LAB_0000bed2;
        }
      }
      else {
        local_24 = uVar8;
        if ((int)local_30 < (int)uVar8) {
          local_24 = local_30;
        }
        FUN_00008170(*param_1,iVar3,local_24);
        param_1[2] = param_1[2] - local_24;
        local_24 = *param_1 + local_24;
LAB_0000bdee:
        *param_1 = local_24;
        local_30 = uVar8;
      }
      iVar5 = param_2[2];
      param_2[2] = iVar5 - local_30;
      if (iVar5 - local_30 != 0) {
        iVar3 = iVar3 + local_30;
        uVar8 = uVar8 - local_30;
        goto LAB_0000bd16;
      }
    }
  }
  return 0;
}



/* Function: FUN_0000bee8 @ 0000bee8 */

uint FUN_0000bee8(code *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  piVar2 = *(int **)(DAT_0000bf20 + 0xbef4 + DAT_0000bf24);
  uVar4 = 0;
  do {
    iVar3 = piVar2[2];
    iVar5 = piVar2[1];
    while (iVar5 = iVar5 + -1, -1 < iVar5) {
      if (*(short *)(iVar3 + 0xc) != 0) {
        uVar1 = (*param_1)(iVar3);
        uVar4 = uVar4 | uVar1;
      }
      iVar3 = iVar3 + 0x54;
    }
    piVar2 = (int *)*piVar2;
  } while (piVar2 != (int *)0x0);
  return uVar4;
}



/* Function: FUN_0000bf28 @ 0000bf28 */

void FUN_0000bf28(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *local_7c [2];
  undefined4 local_74;
  undefined2 local_70;
  undefined2 local_6e;
  undefined1 *local_6c;
  undefined4 local_68;
  undefined4 *local_4c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_4c = &local_28;
  local_24 = 0;
  local_1c = &uStack_8;
  local_6e = 0xffff;
  local_70 = 0x208;
  local_74 = DAT_0000bf6c;
  local_68 = DAT_0000bf6c;
  local_28 = 0;
  local_7c[0] = param_1;
  local_6c = param_1;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0000c6b0(local_7c,param_2);
  *local_7c[0] = 0;
  return;
}



/* Function: FUN_0000bfdc @ 0000bfdc */

void FUN_0000bfdc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00008130((int)*(short *)(param_1 + 0xe));
  if (iVar1 < 0) {
    *(ushort *)(param_1 + 0xc) = (ushort)DAT_0000c000 & *(ushort *)(param_1 + 0xc);
  }
  else {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + iVar1;
  }
  return;
}



/* Function: FUN_0000c004 @ 0000c004 */

void FUN_0000c004(undefined1 *param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  char extraout_r1;
  undefined1 uVar2;
  char *pcVar3;
  int iVar4;
  int *local_158;
  int local_1c [2];
  
  iVar4 = DAT_0000c094 + 0xc010;
  local_1c[0] = **(int **)(iVar4 + DAT_0000c098);
  *param_1 = param_3;
  pcVar3 = param_1 + 2;
  uVar2 = 0x2b;
  if (param_2 < 0) {
    param_2 = -param_2;
    uVar2 = 0x2d;
  }
  param_1[1] = uVar2;
  if (param_2 < 10) {
    *pcVar3 = '0';
    param_1[3] = (char)param_2 + '0';
    pcVar3 = param_1 + 4;
  }
  else {
    piVar1 = local_1c;
    do {
      local_158 = piVar1;
      FUN_00008d40(param_2,10);
      *(char *)((int)local_158 + -1) = extraout_r1 + '0';
      param_2 = FUN_00008c64(param_2,10);
      piVar1 = (int *)((int)local_158 + -1);
    } while (9 < param_2);
    local_158 = (int *)((int)local_158 + -2);
    *(char *)local_158 = (char)param_2 + '0';
    for (; local_158 < local_1c; local_158 = (int *)((int)local_158 + 1)) {
      *pcVar3 = (char)*local_158;
      pcVar3 = pcVar3 + 1;
    }
  }
  if (local_1c[0] != **(int **)(iVar4 + DAT_0000c098)) {
    FUN_000107d0((int)pcVar3 - (int)param_1);
  }
  return;
}



/* Function: FUN_0000c09c @ 0000c09c */

undefined4 FUN_0000c09c(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  iVar3 = *param_2 * 2;
  if (*param_2 == 8) {
    iVar1 = FUN_0001155c(0,0x10,3,0x22,0xffffffff,0);
    iVar2 = *param_2;
    *param_1 = iVar1;
    FUN_00008170(iVar1,iVar4,iVar2);
  }
  else {
    iVar4 = FUN_0001155c(0,iVar3,3,0x22,0xffffffff,0);
    FUN_000114a0(iVar4,*param_1,*param_2);
    FUN_00008670(*param_1,*param_2);
    *param_1 = iVar4;
  }
  FUN_000084a8(*param_1 + *param_2,0,iVar3 - *param_2);
  *param_2 = iVar3;
  return 0;
}



/* Function: FUN_0000c110 @ 0000c110 */

/* WARNING: Removing unreachable block (ram,0x0000c522) */
/* WARNING: Removing unreachable block (ram,0x0000c57e) */

void FUN_0000c110(byte *param_1,undefined4 param_2,int *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte local_24 [8];
  int local_1c;
  
  iVar5 = DAT_0000c3e0 + 0xc11c;
  local_1c = **(int **)(iVar5 + DAT_0000c3e4);
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  local_24[4] = 0;
  local_24[5] = 0;
  local_24[6] = 0;
  local_24[7] = 0;
  do {
    do {
      pbVar6 = param_1;
      if (*pbVar6 == 0) goto LAB_0000c542;
      param_1 = pbVar6 + 1;
    } while (*pbVar6 != 0x25);
    uVar3 = (uint)pbVar6[1];
    uVar2 = uVar3 - 0x20;
    if (uVar2 < 0x5b) {
                    /* WARNING: Could not emulate address calculation at 0x0000c16e */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(int *)(uVar2 * 4 + DAT_0000c3e8 + 0xc134) + DAT_0000c3e8 + 0xc134))();
      return;
    }
    param_1 = pbVar6 + 2;
  } while (uVar3 != 0);
LAB_0000c542:
  iVar4 = 1;
  iVar1 = DAT_0000c59c + 0xc54c;
  while( true ) {
    if (0 < iVar4) {
      if (local_1c != **(int **)(iVar5 + DAT_0000c5a0)) {
        FUN_000107d0();
      }
      return;
    }
    *(undefined4 *)(*param_3 + iVar4 * 4) = param_2;
    if (local_24[iVar4] < 0x19) break;
    iVar4 = iVar4 + 1;
  }
  UNRECOVERED_JUMPTABLE = (code *)(*(int *)((uint)local_24[iVar4] * 4 + iVar1) + iVar1);
                    /* WARNING: Could not emulate address calculation at 0x0000c55c */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE,iVar1,7);
  return;
}



/* Function: FUN_0000c690 @ 0000c690 */

undefined4 FUN_0000c690(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(undefined4 *)(param_2 + 4) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0000bc80();
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 4) = 0;
  }
  return uVar1;
}



/* Function: FUN_0000c6b0 @ 0000c6b0 */

void FUN_0000c6b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint extraout_r2;
  undefined1 *puVar7;
  char *pcVar8;
  
  iVar1 = DAT_0000c9f0;
  *(int *)(&stack0x00000054 + DAT_0000c9f0) = DAT_0000c9f4 + 0xc6bc;
  *(undefined4 *)(&stack0x00000050 + DAT_0000c9f0) = param_2;
  *(undefined4 *)(&stack0x00000018 + DAT_0000c9f0) = param_1;
  *(undefined4 *)(&stack0x00000268 + DAT_0000c9f0) =
       **(undefined4 **)(*(int *)(&stack0x00000054 + DAT_0000c9f0) + DAT_0000c9f8);
  if (((-1 < (int)((uint)*(ushort *)(*(int *)(&stack0x00000018 + DAT_0000c9f0) + 0xc) << 0x1c)) ||
      (*(int *)(*(int *)(&stack0x00000018 + DAT_0000c9f0) + 0x10) == 0)) &&
     (iVar2 = FUN_0000da20(*(undefined4 *)(&stack0x00000018 + DAT_0000c9f0)), iVar2 != 0)) {
    puVar3 = (undefined4 *)FUN_000113b0();
    *puVar3 = 9;
    *(undefined4 *)(&stack0x00000034 + iVar1) = 0xffffffff;
    FUN_0000d8c8();
  }
  iVar2 = *(int *)(&stack0x00000018 + iVar1);
  if (((*(ushort *)(iVar2 + 0xc) & 0x1a) == 10) && (-1 < *(short *)(iVar2 + 0xe))) {
    uVar4 = FUN_0000d980(iVar2,*(undefined4 *)(&stack0x00000050 + iVar1),param_3);
    *(undefined4 *)(&stack0x00000034 + iVar1) = uVar4;
    FUN_0000d8c8();
  }
  *(undefined4 *)(&stack0x000000d8 + iVar1) = 0;
  *(undefined4 *)(&stack0x000000d4 + iVar1) = 0;
  *(undefined4 *)(&stack0x00000044 + iVar1) = DAT_0000c9e8;
  *(undefined4 *)(&stack0x00000048 + iVar1) = DAT_0000c9ec;
  *(undefined4 *)(&stack0x000000f4 + iVar1) = param_3;
  puVar7 = &stack0x00000070 + iVar1;
  *(undefined4 *)(&stack0x00000028 + iVar1) = *(undefined4 *)(&stack0x00000050 + iVar1);
  *(undefined4 *)(&stack0x000000fc + iVar1) = 0;
  *(undefined1 **)(&stack0x00000064 + iVar1) = puVar7;
  *(undefined1 **)(&stack0x000000d0 + iVar1) = puVar7;
  *(undefined4 *)(&stack0x0000003c + iVar1) = 0;
  *(undefined4 *)(&stack0x0000005c + iVar1) = 0;
  *(undefined4 *)(&stack0x00000034 + iVar1) = 0;
  *(undefined1 **)(&stack0x00000020 + iVar1) = puVar7;
  *(int *)(&stack0x00000060 + iVar1) = DAT_0000c9fc + 0xc73a;
  pcVar8 = *(char **)(&stack0x00000028 + iVar1);
  do {
    if (*pcVar8 == '\0') {
      *(undefined4 *)(&stack0x00000010 + iVar1) = 0xffffffff;
LAB_0000c768:
      iVar2 = (int)pcVar8 - *(int *)(&stack0x00000028 + iVar1);
      *(int *)(&stack0x00000000 + iVar1) = iVar2;
      puVar7 = *(undefined1 **)(&stack0x00000064 + iVar1);
      if (iVar2 != 0) {
        puVar3 = *(undefined4 **)(&stack0x00000020 + iVar1);
        uVar4 = *(undefined4 *)(&stack0x00000028 + iVar1);
        puVar7 = &stack0x00000078 + iVar1;
        puVar3[1] = iVar2;
        *puVar3 = uVar4;
        iVar5 = *(int *)(&stack0x000000d4 + iVar1);
        *(int *)(&stack0x000000d8 + iVar1) = iVar2 + *(int *)(&stack0x000000d8 + iVar1);
        *(int *)(&stack0x000000d4 + iVar1) = iVar5 + 1;
        if (7 < iVar5 + 1) {
          iVar2 = FUN_0000c690(*(undefined4 *)(&stack0x00000018 + iVar1));
          if (iVar2 != 0) {
            FUN_0000d8a4();
          }
          puVar7 = *(undefined1 **)(&stack0x00000020 + iVar1);
        }
        *(int *)(&stack0x00000034 + iVar1) =
             *(int *)(&stack0x00000034 + iVar1) + *(int *)(&stack0x00000000 + iVar1);
      }
      if (*(int *)(&stack0x00000010 + iVar1) != 1) {
        FUN_0000d87e();
      }
      *(char **)(&stack0x00000028 + iVar1) = pcVar8 + 1;
      *(undefined1 **)(&stack0x00000010 + iVar1) = puVar7;
      (&stack0x0000010b)[iVar1] = 0;
      *(undefined4 *)(&stack0x00000038 + iVar1) = 0;
      *(undefined4 *)(&stack0x00000000 + iVar1) = 0xffffffff;
      uVar6 = **(byte **)(&stack0x00000028 + iVar1) - 0x20;
      if (0x5a < uVar6) {
        FUN_0000d0ce(0,*(undefined4 *)(&stack0x00000000 + iVar1));
        uVar6 = extraout_r2;
      }
                    /* WARNING: Could not recover jumptable at 0x0000c7ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(int *)(uVar6 * 4 + *(int *)(&stack0x00000060 + iVar1)) +
                *(int *)(&stack0x00000060 + iVar1)))();
      return;
    }
    if (*pcVar8 == '%') {
      *(undefined4 *)(&stack0x00000010 + iVar1) = 1;
      goto LAB_0000c768;
    }
    pcVar8 = pcVar8 + 1;
  } while( true );
}



/* Function: FUN_0000c74c @ 0000c74c */

void FUN_0000c74c(void)

{
  int iVar1;
  uint uVar2;
  uint extraout_r2;
  char *pcVar3;
  int iStack00000014;
  undefined4 *puStack00000024;
  undefined4 in_stack_0000002c;
  undefined4 *in_stack_00000034;
  char *in_stack_0000003c;
  int in_stack_00000074;
  undefined4 *in_stack_00000078;
  int in_stack_000000e8;
  int in_stack_000000ec;
  undefined1 uStack0000011f;
  
  pcVar3 = in_stack_0000003c;
  do {
    if (*pcVar3 == '\0') {
      puStack00000024 = (undefined4 *)0xffffffff;
LAB_0000c768:
      iStack00000014 = (int)pcVar3 - (int)in_stack_0000003c;
      if (iStack00000014 != 0) {
        in_stack_00000078 = (undefined4 *)&stack0x0000008c;
        in_stack_00000034[1] = iStack00000014;
        *in_stack_00000034 = in_stack_0000003c;
        in_stack_000000ec = iStack00000014 + in_stack_000000ec;
        in_stack_000000e8 = in_stack_000000e8 + 1;
        if ((7 < in_stack_000000e8) &&
           (iVar1 = FUN_0000c690(in_stack_0000002c), in_stack_00000078 = in_stack_00000034,
           iVar1 != 0)) {
          FUN_0000d8a4();
        }
      }
      if (puStack00000024 != (undefined4 *)0x1) {
        FUN_0000d87e();
      }
      uStack0000011f = 0;
      iStack00000014 = 0xffffffff;
      uVar2 = (byte)pcVar3[1] - 0x20;
      puStack00000024 = in_stack_00000078;
      if (0x5a < uVar2) {
        FUN_0000d0ce(0,0xffffffff);
        uVar2 = extraout_r2;
      }
                    /* WARNING: Could not recover jumptable at 0x0000c7ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(*(int *)(uVar2 * 4 + in_stack_00000074) + in_stack_00000074))();
      return;
    }
    if (*pcVar3 == '%') {
      puStack00000024 = (undefined4 *)0x1;
      goto LAB_0000c768;
    }
    pcVar3 = pcVar3 + 1;
  } while( true );
}



/* Function: FUN_0000d0ce @ 0000d0ce */

/* WARNING: Removing unreachable block (ram,0x0000d2f2) */
/* WARNING: Removing unreachable block (ram,0x0000d304) */
/* WARNING: Removing unreachable block (ram,0x0000d2c0) */
/* WARNING: Removing unreachable block (ram,0x0000d2da) */
/* WARNING: Removing unreachable block (ram,0x0000d2e6) */
/* WARNING: Removing unreachable block (ram,0x0000d2e8) */
/* WARNING: Removing unreachable block (ram,0x0000d2ea) */
/* WARNING: Removing unreachable block (ram,0x0000d30a) */
/* WARNING: Removing unreachable block (ram,0x0000d32a) */
/* WARNING: Removing unreachable block (ram,0x0000d336) */
/* WARNING: Removing unreachable block (ram,0x0000d338) */
/* WARNING: Removing unreachable block (ram,0x0000d120) */
/* WARNING: Removing unreachable block (ram,0x0000d112) */
/* WARNING: Removing unreachable block (ram,0x0000d89e) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0000d0ce(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r2;
  int in_r3;
  int *piVar4;
  uint unaff_r7;
  int iStack00000014;
  int *in_stack_00000024;
  undefined1 uStack00000028;
  int in_stack_0000002c;
  int *in_stack_00000034;
  int iStack00000038;
  int in_stack_00000048;
  int in_stack_0000004c;
  int iStack00000054;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  int in_stack_00000068;
  int in_stack_00000070;
  int in_stack_000000e8;
  int in_stack_000000ec;
  undefined4 in_stack_0000010c;
  undefined1 *in_stack_00000110;
  int in_stack_00000114;
  int in_stack_00000118;
  undefined1 uStack0000011c;
  undefined1 uStack0000011d;
  char cStack0000011f;
  undefined1 in_stack_00000120;
  int in_stack_0000027c;
  
  _uStack00000028 = in_r3;
  if (in_r3 == 0) {
    FUN_0000d87e();
    return;
  }
  uStack00000028 = (undefined1)in_r3;
  in_stack_00000120 = uStack00000028;
  cStack0000011f = '\0';
  iStack00000054 = 1;
  if ((int)(unaff_r7 << 0x1e) < 0) {
    iStack00000054 = 3;
  }
  if (((unaff_r7 & 0x84) == 0) &&
     (iStack00000038 = in_stack_0000004c - iStack00000054, 0 < iStack00000038)) {
    iVar1 = DAT_0000d1e4 + 0xd188;
    for (; iVar3 = DAT_0000d1e8, 0x10 < iStack00000038; iStack00000038 = iStack00000038 + -0x10) {
      in_stack_00000024[1] = 0x10;
      *in_stack_00000024 = iVar1;
      in_stack_000000ec = in_stack_000000ec + 0x10;
      in_stack_000000e8 = in_stack_000000e8 + 1;
      in_stack_00000024 = in_stack_00000024 + 2;
      if ((7 < in_stack_000000e8) &&
         (iVar3 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
         in_stack_00000024 = in_stack_00000034, iVar3 != 0)) goto code_r0x0000d8a4;
    }
    in_stack_00000024[1] = iStack00000038;
    *in_stack_00000024 = iVar3 + 0xd19c;
    in_stack_00000024 = in_stack_00000024 + 2;
    in_stack_000000ec = iStack00000038 + in_stack_000000ec;
    in_stack_000000e8 = in_stack_000000e8 + 1;
    if ((7 < in_stack_000000e8) &&
       (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
       in_stack_00000024 = in_stack_00000034, iVar1 != 0)) goto code_r0x0000d8a4;
  }
  if (cStack0000011f == '\0') {
    if ((unaff_r7 & 2) != 0) {
      uStack0000011c = 0x30;
      uStack0000011d = uStack00000028;
      in_stack_00000024[1] = 2;
      *in_stack_00000024 = (int)&stack0x0000011c;
      in_stack_000000ec = in_stack_000000ec + 2;
      goto LAB_0000d208;
    }
  }
  else {
    *in_stack_00000024 = (int)&stack0x0000011c + 3;
    in_stack_00000024[1] = 1;
    in_stack_000000ec = in_stack_000000ec + 1;
LAB_0000d208:
    in_stack_00000024 = in_stack_00000024 + 2;
    in_stack_000000e8 = in_stack_000000e8 + 1;
    if ((7 < in_stack_000000e8) &&
       (iVar1 = FUN_0000c690(in_stack_0000002c), in_stack_00000024 = in_stack_00000034, iVar1 != 0))
    goto code_r0x0000d8a4;
  }
  if (((unaff_r7 & 0x84) == 0x80) &&
     (iStack00000038 = in_stack_0000004c - iStack00000054, 0 < iStack00000038)) {
    iVar1 = DAT_0000d5b0 + 0xd284;
    for (; iVar3 = DAT_0000d5b4, 0x10 < iStack00000038; iStack00000038 = iStack00000038 + -0x10) {
      in_stack_00000024[1] = 0x10;
      *in_stack_00000024 = iVar1;
      in_stack_000000ec = in_stack_000000ec + 0x10;
      in_stack_000000e8 = in_stack_000000e8 + 1;
      in_stack_00000024 = in_stack_00000024 + 2;
      if ((7 < in_stack_000000e8) &&
         (iVar3 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
         in_stack_00000024 = in_stack_00000034, iVar3 != 0)) goto code_r0x0000d8a4;
    }
    in_stack_00000024[1] = iStack00000038;
    *in_stack_00000024 = iVar3 + 0xd29c;
    in_stack_000000ec = iStack00000038 + in_stack_000000ec;
    in_stack_000000e8 = in_stack_000000e8 + 1;
    in_stack_00000024 = in_stack_00000024 + 2;
    if ((7 < in_stack_000000e8) &&
       (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
       in_stack_00000024 = in_stack_00000034, iVar1 != 0)) goto code_r0x0000d8a4;
  }
  if ((int)(unaff_r7 << 0x17) < 0) {
    if (_uStack00000028 < 0x66) {
      if ((in_stack_00000114 < 2) && ((unaff_r7 & 1) == 0)) {
        in_stack_00000024[1] = 1;
        *in_stack_00000024 = (int)&stack0x00000120;
        in_stack_000000ec = in_stack_000000ec + 1;
        goto joined_r0x0000d784;
      }
      uStack0000011c = in_stack_00000120;
      uStack0000011d = 0x2e;
      in_stack_00000024[1] = 2;
      *in_stack_00000024 = (int)&stack0x0000011c;
      in_stack_000000ec = in_stack_000000ec + 2;
      in_stack_000000e8 = in_stack_000000e8 + 1;
      in_stack_00000024 = in_stack_00000024 + 2;
      if ((7 < in_stack_000000e8) &&
         (iVar1 = FUN_0000c690(in_stack_0000002c), in_stack_00000024 = in_stack_00000034, iVar1 != 0
         )) goto code_r0x0000d8a4;
      iVar1 = FUN_0000964c(in_stack_00000058,in_stack_0000005c,DAT_0000d8e0,DAT_0000d8e4);
      if (iVar1 == 0) {
        in_stack_00000024[1] = in_stack_00000114 + -1;
        *in_stack_00000024 = (int)&stack0x00000121;
        in_stack_000000ec = in_stack_000000ec + in_stack_00000114 + -1;
joined_r0x0000d784:
        in_stack_000000e8 = in_stack_000000e8 + 1;
        in_stack_00000024 = in_stack_00000024 + 2;
        if ((7 < in_stack_000000e8) &&
           (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
           in_stack_00000024 = in_stack_00000034, iVar1 != 0)) goto code_r0x0000d8a4;
      }
      else {
        iStack00000014 = in_stack_00000114 + -1;
        if (0 < iStack00000014) {
          _uStack00000028 = DAT_0000d8f8 + 0xd768;
          for (; iVar1 = DAT_0000d8fc, 0x10 < iStack00000014;
              iStack00000014 = iStack00000014 + -0x10) {
            in_stack_00000024[1] = 0x10;
            *in_stack_00000024 = _uStack00000028;
            in_stack_000000ec = in_stack_000000ec + 0x10;
            in_stack_000000e8 = in_stack_000000e8 + 1;
            in_stack_00000024 = in_stack_00000024 + 2;
            if ((7 < in_stack_000000e8) &&
               (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
               in_stack_00000024 = in_stack_00000034, iVar1 != 0)) goto code_r0x0000d8a4;
          }
          in_stack_00000024[1] = iStack00000014;
          *in_stack_00000024 = iVar1 + 0xd780;
          in_stack_000000ec = iStack00000014 + in_stack_000000ec;
          goto joined_r0x0000d784;
        }
      }
      *in_stack_00000024 = (int)&stack0x00000100;
      in_stack_00000024[1] = in_stack_00000070;
      in_stack_000000ec = in_stack_00000070 + in_stack_000000ec;
      goto LAB_0000d7ca;
    }
    iVar2 = FUN_0000964c(in_stack_00000058,in_stack_0000005c,DAT_0000d5a8,DAT_0000d5ac);
    iVar3 = DAT_0000d5d0;
    iVar1 = DAT_0000d5c0;
    if (iVar2 == 0) {
      if (in_stack_00000118 < 1) {
        in_stack_00000024[1] = 1;
        *in_stack_00000024 = iVar3 + 0xd45c;
        in_stack_000000ec = in_stack_000000ec + 1;
        in_stack_000000e8 = in_stack_000000e8 + 1;
        piVar4 = in_stack_00000024 + 2;
        if ((7 < in_stack_000000e8) &&
           (iVar1 = FUN_0000c690(in_stack_0000002c), piVar4 = in_stack_00000034, iVar1 != 0))
        goto code_r0x0000d8a4;
        iVar1 = DAT_0000d5d4;
        piVar4[1] = 1;
        *piVar4 = iVar1 + 0xd48a;
        in_stack_000000ec = in_stack_000000ec + 1;
        in_stack_000000e8 = in_stack_000000e8 + 1;
        in_stack_00000024 = piVar4 + 2;
        if ((7 < in_stack_000000e8) &&
           (iVar1 = FUN_0000c690(in_stack_0000002c), in_stack_00000024 = in_stack_00000034,
           iVar1 != 0)) goto code_r0x0000d8a4;
        iStack00000014 = -in_stack_00000118;
        if (in_stack_00000118 != 0 && -1 < iStack00000014) {
          _uStack00000028 = DAT_0000d5d8 + 0xd502;
          for (; iVar1 = DAT_0000d5dc, 0x10 < iStack00000014;
              iStack00000014 = iStack00000014 + -0x10) {
            in_stack_00000024[1] = 0x10;
            *in_stack_00000024 = _uStack00000028;
            in_stack_000000ec = in_stack_000000ec + 0x10;
            in_stack_000000e8 = in_stack_000000e8 + 1;
            in_stack_00000024 = in_stack_00000024 + 2;
            if ((7 < in_stack_000000e8) &&
               (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
               in_stack_00000024 = in_stack_00000034, iVar1 != 0)) goto code_r0x0000d8a4;
          }
          in_stack_00000024[1] = iStack00000014;
          *in_stack_00000024 = iVar1 + 0xd514;
          in_stack_000000ec = iStack00000014 + in_stack_000000ec;
          in_stack_000000e8 = in_stack_000000e8 + 1;
          in_stack_00000024 = in_stack_00000024 + 2;
          if ((7 < in_stack_000000e8) &&
             (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
             in_stack_00000024 = in_stack_00000034, iVar1 != 0)) goto code_r0x0000d8a4;
        }
        in_stack_00000024[1] = in_stack_00000114;
        *in_stack_00000024 = (int)&stack0x00000120;
        in_stack_000000ec = in_stack_00000114 + in_stack_000000ec;
      }
      else if (in_stack_00000118 < in_stack_00000114) {
        in_stack_00000024[1] = in_stack_00000118;
        *in_stack_00000024 = (int)&stack0x00000120;
        in_stack_000000ec = in_stack_00000118 + in_stack_000000ec;
        in_stack_000000e8 = in_stack_000000e8 + 1;
        piVar4 = in_stack_00000024 + 2;
        if ((7 < in_stack_000000e8) &&
           (iVar1 = FUN_0000c690(in_stack_0000002c), piVar4 = in_stack_00000034, iVar1 != 0))
        goto code_r0x0000d8a4;
        iVar1 = in_stack_00000118;
        iVar3 = DAT_0000d8f4 + 0xd668;
        piVar4[1] = 1;
        *piVar4 = iVar3;
        in_stack_000000ec = in_stack_000000ec + 1;
        in_stack_000000e8 = in_stack_000000e8 + 1;
        in_stack_00000024 = piVar4 + 2;
        if ((7 < in_stack_000000e8) &&
           (iVar3 = FUN_0000c690(in_stack_0000002c), in_stack_00000024 = in_stack_00000034,
           iVar3 != 0)) goto code_r0x0000d8a4;
        *in_stack_00000024 = (int)(&stack0x00000120 + iVar1);
        in_stack_00000024[1] = in_stack_00000114 - in_stack_00000118;
        in_stack_000000ec = (in_stack_00000114 + in_stack_000000ec) - in_stack_00000118;
      }
      else {
        in_stack_00000024[1] = in_stack_00000114;
        *in_stack_00000024 = (int)&stack0x00000120;
        in_stack_000000ec = in_stack_00000114 + in_stack_000000ec;
        in_stack_000000e8 = in_stack_000000e8 + 1;
        in_stack_00000024 = in_stack_00000024 + 2;
        if ((7 < in_stack_000000e8) &&
           (iVar1 = FUN_0000c690(in_stack_0000002c), in_stack_00000024 = in_stack_00000034,
           iVar1 != 0)) goto code_r0x0000d8a4;
        iStack00000014 = in_stack_00000118 - in_stack_00000114;
        if (0 < iStack00000014) {
          iVar1 = DAT_0000d8e8 + 0xd5f8;
          for (; iVar3 = DAT_0000d8ec, 0x10 < iStack00000014;
              iStack00000014 = iStack00000014 + -0x10) {
            in_stack_00000024[1] = 0x10;
            *in_stack_00000024 = iVar1;
            in_stack_000000ec = in_stack_000000ec + 0x10;
            in_stack_000000e8 = in_stack_000000e8 + 1;
            in_stack_00000024 = in_stack_00000024 + 2;
            if ((7 < in_stack_000000e8) &&
               (iVar3 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
               in_stack_00000024 = in_stack_00000034, iVar3 != 0)) goto code_r0x0000d8a4;
          }
          in_stack_00000024[1] = iStack00000014;
          *in_stack_00000024 = iVar3 + 0xd60c;
          in_stack_000000ec = iStack00000014 + in_stack_000000ec;
          in_stack_000000e8 = in_stack_000000e8 + 1;
          in_stack_00000024 = in_stack_00000024 + 2;
          if ((7 < in_stack_000000e8) &&
             (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
             in_stack_00000024 = in_stack_00000034, iVar1 != 0)) goto code_r0x0000d8a4;
        }
        if ((unaff_r7 & 1) == 0) goto LAB_0000d7d6;
        in_stack_00000024[1] = 1;
        *in_stack_00000024 = DAT_0000d8f0 + 0xd632;
        in_stack_000000ec = in_stack_000000ec + 1;
      }
      goto LAB_0000d7ca;
    }
    in_stack_00000024[1] = 1;
    *in_stack_00000024 = iVar1 + 0xd370;
    in_stack_000000ec = in_stack_000000ec + 1;
    in_stack_000000e8 = in_stack_000000e8 + 1;
    in_stack_00000024 = in_stack_00000024 + 2;
    if ((7 < in_stack_000000e8) &&
       (iVar1 = FUN_0000c690(in_stack_0000002c), in_stack_00000024 = in_stack_00000034, iVar1 != 0))
    goto code_r0x0000d8a4;
    if ((in_stack_00000114 <= in_stack_00000118) && (-1 < (int)(unaff_r7 << 0x1f)))
    goto LAB_0000d7d6;
    in_stack_00000024[1] = 1;
    in_stack_000000ec = in_stack_000000ec + 1;
    in_stack_000000e8 = in_stack_000000e8 + 1;
    *in_stack_00000024 = DAT_0000d5c4 + 0xd3b6;
    in_stack_00000024 = in_stack_00000024 + 2;
    if ((7 < in_stack_000000e8) &&
       (iVar1 = FUN_0000c690(in_stack_0000002c), in_stack_00000024 = in_stack_00000034, iVar1 != 0))
    goto code_r0x0000d8a4;
    iStack00000014 = in_stack_00000114 + -1;
    if (0 < iStack00000014) {
      iVar1 = DAT_0000d5c8 + 0xd424;
      for (; iVar3 = DAT_0000d5cc, 0x10 < iStack00000014; iStack00000014 = iStack00000014 + -0x10) {
        in_stack_00000024[1] = 0x10;
        *in_stack_00000024 = iVar1;
        in_stack_000000ec = in_stack_000000ec + 0x10;
        in_stack_000000e8 = in_stack_000000e8 + 1;
        in_stack_00000024 = in_stack_00000024 + 2;
        if ((7 < in_stack_000000e8) &&
           (iVar3 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
           in_stack_00000024 = in_stack_00000034, iVar3 != 0)) goto code_r0x0000d8a4;
      }
      in_stack_00000024[1] = iStack00000014;
      *in_stack_00000024 = iVar3 + 0xd438;
      in_stack_000000ec = iStack00000014 + in_stack_000000ec;
      in_stack_000000e8 = in_stack_000000e8 + 1;
      in_stack_00000024 = in_stack_00000024 + 2;
      if (in_stack_000000e8 < 8) goto LAB_0000d7d6;
      goto LAB_0000d440;
    }
  }
  else {
    in_stack_00000024[1] = 1;
    *in_stack_00000024 = (int)&stack0x00000120;
    in_stack_000000ec = in_stack_000000ec + 1;
LAB_0000d7ca:
    in_stack_000000e8 = in_stack_000000e8 + 1;
    in_stack_00000024 = in_stack_00000024 + 2;
    if (7 < in_stack_000000e8) {
LAB_0000d440:
      iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4);
      in_stack_00000024 = in_stack_00000034;
      if (iVar1 != 0) goto code_r0x0000d8a4;
    }
  }
LAB_0000d7d6:
  if (((int)(unaff_r7 << 0x1d) < 0) && (iVar1 = in_stack_0000004c - iStack00000054, 0 < iVar1)) {
    iVar3 = DAT_0000d900 + 0xd81a;
    for (; iVar2 = DAT_0000d904, 0x10 < iVar1; iVar1 = iVar1 + -0x10) {
      in_stack_00000024[1] = 0x10;
      *in_stack_00000024 = iVar3;
      in_stack_000000ec = in_stack_000000ec + 0x10;
      in_stack_000000e8 = in_stack_000000e8 + 1;
      in_stack_00000024 = in_stack_00000024 + 2;
      if ((7 < in_stack_000000e8) &&
         (iVar2 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4),
         in_stack_00000024 = in_stack_00000034, iVar2 != 0)) goto code_r0x0000d8a4;
    }
    in_stack_00000024[1] = iVar1;
    *in_stack_00000024 = iVar2 + 0xd826;
    in_stack_000000ec = iVar1 + in_stack_000000ec;
    in_stack_000000e8 = in_stack_000000e8 + 1;
    if ((7 < in_stack_000000e8) &&
       (iVar1 = FUN_0000c690(in_stack_0000002c,&stack0x000000e4), iVar1 != 0))
    goto code_r0x0000d8a4;
  }
  if (iStack00000054 < in_stack_0000004c) {
    iStack00000054 = in_stack_0000004c;
  }
  in_stack_00000048 = in_stack_00000048 + iStack00000054;
  if ((in_stack_000000ec == 0) || (iVar1 = FUN_0000c690(in_stack_0000002c), iVar1 == 0)) {
    in_stack_000000e8 = 0;
    FUN_0000c74c();
    FUN_000113dc(extraout_r2);
    FUN_0000c74c();
    if ((in_stack_000000ec == 0) || (iVar1 = FUN_0000c690(in_stack_0000002c), iVar1 == 0)) {
      in_stack_000000e8 = 0;
      FUN_0000d8a4();
      return;
    }
  }
code_r0x0000d8a4:
  if ((in_stack_00000110 != (undefined1 *)0x0) && (in_stack_00000110 != &stack0x000000c4)) {
    FUN_00008670(in_stack_00000110,in_stack_0000010c);
    in_stack_00000110 = (undefined1 *)0x0;
  }
  if ((int)((uint)*(ushort *)(in_stack_0000002c + 0xc) << 0x19) < 0) {
    in_stack_00000048 = -1;
  }
  if (in_stack_0000027c != **(int **)(in_stack_00000068 + DAT_0000d908)) {
    FUN_000107d0(in_stack_00000048);
  }
  return;
}



/* Function: FUN_0000d87e @ 0000d87e */

void FUN_0000d87e(void)

{
  int iVar1;
  int in_stack_0000002c;
  undefined4 in_stack_00000048;
  int in_stack_00000068;
  undefined4 in_stack_000000e8;
  int in_stack_000000ec;
  undefined4 in_stack_0000010c;
  undefined1 *in_stack_00000110;
  int in_stack_0000027c;
  
  if ((in_stack_000000ec != 0) && (iVar1 = FUN_0000c690(in_stack_0000002c), iVar1 != 0)) {
    if ((in_stack_00000110 != (undefined1 *)0x0) && (in_stack_00000110 != &stack0x000000c4)) {
      FUN_00008670(in_stack_00000110,in_stack_0000010c);
      in_stack_00000110 = (undefined1 *)0x0;
    }
    if ((int)((uint)*(ushort *)(in_stack_0000002c + 0xc) << 0x19) < 0) {
      in_stack_00000048 = 0xffffffff;
    }
    if (in_stack_0000027c != **(int **)(in_stack_00000068 + DAT_0000d908)) {
      FUN_000107d0(in_stack_00000048);
    }
    return;
  }
  in_stack_000000e8 = 0;
  FUN_0000d8a4();
  return;
}



/* Function: FUN_0000d8a4 @ 0000d8a4 */

void FUN_0000d8a4(void)

{
  int in_stack_0000002c;
  undefined4 in_stack_00000048;
  int in_stack_00000068;
  undefined4 in_stack_0000010c;
  undefined1 *in_stack_00000110;
  int in_stack_0000027c;
  
  if ((in_stack_00000110 != (undefined1 *)0x0) && (in_stack_00000110 != &stack0x000000c4)) {
    FUN_00008670(in_stack_00000110,in_stack_0000010c);
    in_stack_00000110 = (undefined1 *)0x0;
  }
  if ((int)((uint)*(ushort *)(in_stack_0000002c + 0xc) << 0x19) < 0) {
    in_stack_00000048 = 0xffffffff;
  }
  if (in_stack_0000027c != **(int **)(in_stack_00000068 + DAT_0000d908)) {
    FUN_000107d0(in_stack_00000048);
  }
  return;
}



/* Function: FUN_0000d8c8 @ 0000d8c8 */

void FUN_0000d8c8(void)

{
  undefined4 in_stack_00000048;
  int in_stack_00000068;
  int in_stack_0000027c;
  
  if (in_stack_0000027c != **(int **)(in_stack_00000068 + DAT_0000d908)) {
    FUN_000107d0(in_stack_00000048);
  }
  return;
}



/* Function: FUN_0000d980 @ 0000d980 */

void FUN_0000d980(int param_1)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar3 = DAT_0000da14;
  iVar7 = DAT_0000da0c + 0xd98c;
  *(undefined4 *)(&stack0xffffffec + DAT_0000da18 + DAT_0000da14) =
       **(undefined4 **)(iVar7 + DAT_0000da10);
  puVar1 = &stack0xfffffff0 + DAT_0000da14;
  *(undefined4 *)(&stack0x00000044 + DAT_0000da14) = 0;
  *(undefined4 *)(&stack0x00000048 + DAT_0000da14) = 0;
  *(undefined1 **)(&stack0x00000020 + DAT_0000da14) = &stack0x00000044 + DAT_0000da14;
  *(ushort *)(&stack0xfffffffc + DAT_0000da14) = *(ushort *)(param_1 + 0xc) & 0xfffd;
  uVar2 = *(undefined2 *)(param_1 + 0xe);
  uVar6 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(&stack0x00000008 + DAT_0000da14) = 0;
  *(undefined2 *)(&stack0xfffffffe + DAT_0000da14) = uVar2;
  uVar8 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(&stack0x0000000c + DAT_0000da14) = uVar6;
  *(undefined4 *)(&stack0x0000001c + DAT_0000da14) = uVar8;
  *(undefined1 **)(&stack0xfffffff0 + DAT_0000da14) = &stack0x00000050 + DAT_0000da14;
  *(undefined1 **)(&stack0x00000000 + DAT_0000da14) = &stack0x00000050 + DAT_0000da14;
  *(undefined4 *)(&stack0xfffffff8 + DAT_0000da14) = 0x400;
  *(undefined4 *)(&stack0x00000004 + DAT_0000da14) = 0x400;
  iVar4 = FUN_0000c6b0(puVar1);
  if ((-1 < iVar4) && (iVar5 = FUN_000115d4(puVar1), iVar5 != 0)) {
    iVar4 = -1;
  }
  if ((int)((uint)*(ushort *)(&stack0xfffffffc + iVar3) << 0x19) < 0) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x40;
  }
  if (*(int *)(&stack0xffffffec + DAT_0000da18 + iVar3) != **(int **)(iVar7 + DAT_0000da10)) {
    FUN_000107d0(iVar4);
  }
  return;
}



/* Function: FUN_0000da20 @ 0000da20 */

undefined4 FUN_0000da20(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (**(int **)(DAT_0000dab8 + 0xda2c + DAT_0000dabc) == 0) {
    FUN_0000bbe0();
  }
  uVar2 = (uint)*(ushort *)(param_1 + 3);
  if ((int)(uVar2 << 0x1c) < 0) {
LAB_0000da76:
    if (param_1[4] == 0) {
      if ((*(ushort *)(param_1 + 3) & 0x4200) == 0x200) goto LAB_0000dab2;
      FUN_0001168c(param_1);
    }
    if ((int)((uint)*(ushort *)(param_1 + 3) << 0x1f) < 0) {
      param_1[2] = 0;
      param_1[6] = -param_1[5];
    }
    else {
      uVar1 = 0;
      if (-1 < (int)((uint)*(ushort *)(param_1 + 3) << 0x1e)) {
        uVar1 = param_1[5];
      }
      param_1[2] = uVar1;
    }
    uVar1 = 0;
  }
  else {
    if ((int)(uVar2 << 0x1b) < 0) {
      if ((int)(uVar2 << 0x1d) < 0) {
        if (*(undefined4 **)param_1[0xc] != (undefined4 *)0x0) {
          if (*(undefined4 **)param_1[0xc] != param_1 + 0x10) {
            FUN_000113dc();
          }
          *(undefined4 *)param_1[0xc] = 0;
        }
        *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) & 0xffdb;
        param_1[1] = 0;
        *param_1 = param_1[4];
      }
      *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 8;
      goto LAB_0000da76;
    }
LAB_0000dab2:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* Function: FUN_0000dac0 @ 0000dac0 */

void FUN_0000dac0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar6 = DAT_0000db6c + 0xdace;
  iVar7 = **(int **)(iVar6 + DAT_0000db70);
  if (iVar7 < 0x18) {
    return;
  }
  if (**(int **)(iVar6 + DAT_0000db74) != 0) {
    FUN_00010b34();
  }
  puVar8 = *(undefined4 **)(iVar6 + DAT_0000db78);
  puVar5 = (undefined4 *)*puVar8;
  if (puVar5 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_0001155c(0,iVar7,3,0x22,0xffffffff,0);
    if (puVar1 == (undefined4 *)0xffffffff) goto LAB_0000db48;
    puVar1[1] = 1;
    uVar2 = FUN_00008ba0(iVar7 + -0xc,0xc);
    iVar3 = DAT_0000db7c;
    *puVar1 = 0;
    piVar4 = *(int **)(iVar6 + iVar3);
    puVar1[2] = uVar2;
    *puVar8 = puVar1;
    if (*piVar4 != 0) {
      *piVar4 = 0;
    }
  }
  else {
    do {
      puVar1 = puVar5;
      puVar5 = (undefined4 *)*puVar1;
    } while ((undefined4 *)*puVar1 != (undefined4 *)0x0);
    iVar3 = FUN_00008690(puVar1,iVar7,3);
    if (iVar3 != 0) goto LAB_0000db48;
  }
  puVar1[4] = 0;
  puVar1[3] = param_1;
  puVar1[5] = 0;
  FUN_00008690(puVar1,iVar7,1);
LAB_0000db48:
  if (**(int **)(iVar6 + DAT_0000db74) != 0) {
    FUN_00010b24();
  }
  return;
}



/* Function: FUN_0000db80 @ 0000db80 */

void FUN_0000db80(int param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int local_40;
  
  iVar6 = DAT_0000dc5c + 0xdb8c;
  uVar3 = **(undefined4 **)(iVar6 + DAT_0000dc60);
  if (**(int **)(iVar6 + DAT_0000dc64) == 0) {
    puVar5 = (undefined4 *)**(undefined4 **)(iVar6 + DAT_0000dc6c);
    *(int *)(DAT_0000dc68 + 0xdba4) = *(int *)(DAT_0000dc68 + 0xdba4) + 1;
    for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
      local_40 = puVar5[1];
      piVar1 = puVar5 + (local_40 + -1) * 3 + 3;
      while (local_40 = local_40 + -1, -1 < local_40) {
        if ((*piVar1 != 0) && ((param_1 == 0 || (param_1 == piVar1[2])))) {
          pcVar2 = (code *)*piVar1;
          iVar4 = piVar1[1];
          iVar7 = FUN_00008690(puVar5,uVar3,3);
          if (iVar7 == 0) {
            *piVar1 = 0;
            FUN_00008690(puVar5,uVar3,1);
          }
          (*pcVar2)(iVar4);
        }
        piVar1 = piVar1 + -3;
      }
    }
    if ((param_1 == 0) &&
       (iVar7 = *(int *)(DAT_0000dc70 + 0xdc34) + -1, *(int *)(DAT_0000dc70 + 0xdc34) = iVar7,
       iVar7 == 0)) {
      piVar1 = (int *)**(int **)(iVar6 + DAT_0000dc6c);
      while (piVar1 != (int *)0x0) {
        iVar7 = *piVar1;
        FUN_00008670(piVar1,uVar3);
        piVar1 = (int *)iVar7;
      }
      **(undefined4 **)(iVar6 + DAT_0000dc6c) = 0;
    }
  }
  return;
}



/* Function: FUN_0000dc74 @ 0000dc74 */

undefined4 FUN_0000dc74(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = DAT_0000dd64 + 0xdc82;
  iVar8 = **(int **)(iVar7 + DAT_0000dd68);
  if (iVar8 < 0x18) {
    return 0xffffffff;
  }
  if (**(int **)(iVar7 + DAT_0000dd6c) != 0) {
    FUN_00010b34();
  }
  piVar5 = (int *)**(undefined4 **)(iVar7 + DAT_0000dd70);
  if ((piVar5 == (int *)0x0) || (piVar5[2] <= piVar5[1] + 1)) {
    piVar5 = (int *)FUN_0001155c(0,iVar8,3,0x22,0xffffffff,0);
    if (piVar5 != (int *)0xffffffff) {
      if (**(int **)(iVar7 + DAT_0000dd70) == 0) {
        FUN_000084a8(piVar5 + 3,0,0xc);
        piVar5[1] = 1;
      }
      else {
        piVar5[1] = 0;
      }
      iVar3 = FUN_00008ba0(iVar8 + -0xc,0xc);
      iVar1 = DAT_0000dd74;
      iVar2 = DAT_0000dd70;
      piVar5[2] = iVar3;
      piVar4 = *(int **)(iVar7 + iVar2);
      *piVar5 = *piVar4;
      *piVar4 = (int)piVar5;
      if (**(int **)(iVar7 + iVar1) != 0) {
        **(int **)(iVar7 + iVar1) = 0;
      }
      goto LAB_0000dd20;
    }
  }
  else {
    iVar2 = FUN_00008690(piVar5,iVar8,3);
    if (iVar2 == 0) {
LAB_0000dd20:
      iVar2 = piVar5[1];
      piVar5[1] = iVar2 + 1;
      piVar5[iVar2 * 3 + 3] = param_1;
      piVar5[iVar2 * 3 + 4] = param_2;
      piVar5[iVar2 * 3 + 5] = param_3;
      iVar8 = FUN_00008690(piVar5,iVar8,1);
      uVar6 = 0;
      if (iVar8 == 0) goto LAB_0000dd4e;
    }
  }
  uVar6 = 0xffffffff;
LAB_0000dd4e:
  if (**(int **)(iVar7 + DAT_0000dd6c) != 0) {
    FUN_00010b24();
  }
  return uVar6;
}



/* Function: FUN_0000dd78 @ 0000dd78 */

void FUN_0000dd78(undefined4 param_1)

{
  FUN_00010198(param_1,0,10);
  return;
}



/* Function: FUN_0000dd84 @ 0000dd84 */

char * FUN_0000dd84(undefined4 param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  undefined8 uVar9;
  
  FUN_0000db80(0);
  uVar9 = FUN_00008570(param_1);
  pcVar2 = (char *)uVar9;
  if ((pcVar2 != (char *)0x0) &&
     (piVar7 = (int *)**(undefined4 **)(DAT_0000de0c + 0xdd9e + DAT_0000de10), pcVar4 = pcVar2,
     piVar7 != (int *)0x0)) {
    for (; (*pcVar4 != '=' && (*pcVar4 != '\0')); pcVar4 = pcVar4 + 1) {
    }
    for (piVar6 = piVar7; iVar3 = *piVar6, iVar3 != 0; piVar6 = piVar6 + 1) {
      iVar5 = 0;
      while (iVar5 != (int)pcVar4 - (int)pcVar2) {
        pcVar1 = (char *)(iVar3 + iVar5);
        if ((*pcVar1 == '\0') || (pcVar8 = pcVar2 + iVar5, iVar5 = iVar5 + 1, *pcVar8 != *pcVar1))
        goto LAB_0000ddee;
      }
      if (*(char *)(iVar3 + iVar5) == '=') {
        *(int *)((ulonglong)uVar9 >> 0x20) = (int)piVar6 - (int)piVar7 >> 2;
        return (char *)(iVar3 + iVar5) + 1;
      }
LAB_0000ddee:
    }
  }
  return (char *)0x0;
}



/* Function: FUN_0000dd94 @ 0000dd94 */

char * FUN_0000dd94(char *param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  
  if ((param_1 != (char *)0x0) &&
     (piVar6 = (int *)**(undefined4 **)(DAT_0000de0c + 0xdd9e + DAT_0000de10), pcVar3 = param_1,
     piVar6 != (int *)0x0)) {
    for (; (*pcVar3 != '=' && (*pcVar3 != '\0')); pcVar3 = pcVar3 + 1) {
    }
    for (piVar5 = piVar6; iVar2 = *piVar5, iVar2 != 0; piVar5 = piVar5 + 1) {
      iVar4 = 0;
      while (iVar4 != (int)pcVar3 - (int)param_1) {
        pcVar1 = (char *)(iVar2 + iVar4);
        if ((*pcVar1 == '\0') || (pcVar7 = param_1 + iVar4, iVar4 = iVar4 + 1, *pcVar7 != *pcVar1))
        goto LAB_0000ddee;
      }
      if (*(char *)(iVar2 + iVar4) == '=') {
        *param_2 = (int)piVar5 - (int)piVar6 >> 2;
        return (char *)(iVar2 + iVar4) + 1;
      }
LAB_0000ddee:
    }
  }
  return (char *)0x0;
}



/* Function: FUN_0000de14 @ 0000de14 */

void FUN_0000de14(undefined4 param_1)

{
  undefined1 auStack_c [8];
  
  FUN_0000dd94(param_1,auStack_c);
  return;
}



/* Function: FUN_0000de24 @ 0000de24 */

int FUN_0000de24(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 >> 0x10 == 0) {
    param_1 = param_1 << 0x10;
    iVar1 = 0x10;
  }
  if (param_1 >> 0x18 == 0) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if (param_1 >> 0x1c == 0) {
    iVar1 = iVar1 + 4;
    param_1 = param_1 << 4;
  }
  if (param_1 >> 0x1e == 0) {
    iVar1 = iVar1 + 2;
    param_1 = param_1 << 2;
  }
  if ((-1 < (int)param_1) && (iVar1 = iVar1 + 1, -1 < (int)(param_1 << 1))) {
    iVar1 = 0x20;
  }
  return iVar1;
}



/* Function: FUN_0000de60 @ 0000de60 */

int FUN_0000de60(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  if ((uVar2 & 7) == 0) {
    iVar1 = 0;
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = uVar2 >> 0x10;
      iVar1 = 0x10;
    }
    if ((uVar2 & 0xff) == 0) {
      iVar1 = iVar1 + 8;
      uVar2 = uVar2 >> 8;
    }
    if ((uVar2 & 0xf) == 0) {
      iVar1 = iVar1 + 4;
      uVar2 = uVar2 >> 4;
    }
    if ((uVar2 & 3) == 0) {
      iVar1 = iVar1 + 2;
      uVar2 = uVar2 >> 2;
    }
    if (-1 < (int)(uVar2 << 0x1f)) {
      uVar2 = uVar2 >> 1;
      iVar1 = iVar1 + 1;
      if (uVar2 == 0) {
        return 0x20;
      }
    }
    *param_1 = uVar2;
  }
  else {
    iVar1 = 0;
    if (-1 < (int)(uVar2 << 0x1f)) {
      if ((int)(uVar2 << 0x1e) < 0) {
        *param_1 = uVar2 >> 1;
        iVar1 = 1;
      }
      else {
        *param_1 = uVar2 >> 2;
        iVar1 = 2;
      }
    }
  }
  return iVar1;
}



/* Function: FUN_0000debc @ 0000debc */

undefined8 FUN_0000debc(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (DAT_0000def8 & param_2) + DAT_0000defc;
  if (iVar2 < 1) {
    uVar3 = (uint)-iVar2 >> 0x14;
    if (0x13 < uVar3) {
      iVar2 = 0;
      iVar1 = 1;
      if ((int)(uVar3 - 0x14) < 0x1f) {
        iVar1 = 1 << (0x1f - (uVar3 - 0x14) & 0xff);
      }
      goto LAB_0000def4;
    }
    iVar2 = 0x80000 >> (uVar3 & 0xff);
  }
  iVar1 = 0;
LAB_0000def4:
  return CONCAT44(iVar2,iVar1);
}



/* Function: FUN_0000df00 @ 0000df00 */

undefined8 FUN_0000df00(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar7 = DAT_0000dfa0;
  uVar5 = DAT_0000dfa4;
  if (param_1 != DAT_0000dfa8 + 0xdf0a) {
    puVar6 = (uint *)(param_1 + 0x14);
    puVar4 = (uint *)(param_1 + (*(int *)(param_1 + 0x10) + 4) * 4);
    uVar5 = *puVar4;
    iVar1 = FUN_0000de24(uVar5);
    *param_2 = 0x20 - iVar1;
    if (iVar1 < 0xb) {
      uVar7 = 0;
      if (puVar6 < puVar4) {
        uVar7 = puVar4[-1];
      }
      uVar7 = uVar7 >> (0xbU - iVar1 & 0xff) | uVar5 << (iVar1 + 0x15U & 0xff);
      uVar5 = uVar5 >> (0xbU - iVar1 & 0xff) | DAT_0000dfac;
    }
    else {
      uVar3 = 0;
      if (puVar6 < puVar4) {
        puVar4 = puVar4 + -1;
        uVar3 = *puVar4;
      }
      uVar2 = iVar1 - 0xb;
      if (uVar2 == 0) {
        uVar7 = uVar3;
        uVar5 = uVar5 | DAT_0000dfac;
      }
      else {
        uVar7 = 0;
        if (puVar6 < puVar4) {
          uVar7 = puVar4[-1];
        }
        uVar7 = uVar7 >> (0x20 - uVar2 & 0xff) | uVar3 << (uVar2 & 0xff);
        uVar5 = uVar5 << (uVar2 & 0xff) | DAT_0000dfac | uVar3 >> (0x20 - uVar2 & 0xff);
      }
    }
  }
  return CONCAT44(uVar5,uVar7);
}



/* Function: FUN_0000dfb0 @ 0000dfb0 */

undefined4 FUN_0000dfb0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int local_20;
  int local_1c [2];
  
  uVar1 = DAT_0000e010;
  if ((param_1 != DAT_0000e018 + 0xdfbc) && (param_2 != DAT_0000e018 + 0xdfbc)) {
    uVar5 = FUN_0000df00(param_1,local_1c);
    iVar4 = (int)((ulonglong)uVar5 >> 0x20);
    uVar6 = FUN_0000df00(param_2,&local_20);
    iVar3 = (int)((ulonglong)uVar6 >> 0x20);
    iVar2 = (local_1c[0] - local_20) + (*(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10)) * 0x20;
    if (iVar2 < 1) {
      iVar3 = iVar3 + iVar2 * -0x100000;
    }
    else {
      iVar4 = iVar2 * 0x100000 + iVar4;
    }
    uVar1 = FUN_00009380((int)uVar5,iVar4,(int)uVar6,iVar3);
  }
  return uVar1;
}



/* Function: FUN_0000e020 @ 0000e020 */

int FUN_0000e020(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint *local_2c;
  uint local_28;
  
  if (((param_1 == DAT_0000e1b8 + 0xe02c) || (param_2 == DAT_0000e1b8 + 0xe02c)) ||
     (iVar5 = *(int *)(param_2 + 0x10), *(int *)(param_1 + 0x10) < iVar5)) {
    iVar1 = 0;
  }
  else {
    iVar9 = iVar5 + -1;
    iVar3 = (iVar5 + 3) * 4;
    iVar1 = param_2 + iVar3;
    local_2c = (uint *)(param_2 + 0x14);
    puVar2 = (uint *)(iVar1 + 4);
    iVar3 = *(int *)(param_1 + iVar3 + 4);
    puVar10 = (uint *)(param_1 + 0x14);
    iVar1 = FUN_00008ba0(iVar3,*(int *)(iVar1 + 4) + 1);
    if (iVar1 != 0) {
      uVar4 = 0;
      local_28 = 0;
      puVar6 = local_2c;
      puVar8 = puVar10;
      while( true ) {
        uVar11 = *puVar6;
        puVar6 = puVar6 + 1;
        uVar7 = local_28 + iVar1 * (uVar11 & 0xffff);
        uVar11 = (uVar7 >> 0x10) + iVar1 * (uVar11 >> 0x10);
        local_28 = uVar11 >> 0x10;
        uVar12 = (uVar4 + (*puVar8 & 0xffff)) - (uVar7 & 0xffff);
        uVar7 = uVar12 >> 0x10;
        if ((int)uVar12 < 0) {
          uVar7 = DAT_0000e1bc | uVar7;
        }
        uVar7 = ((*puVar8 >> 0x10) - (uVar11 & 0xffff)) + uVar7;
        uVar4 = uVar7 >> 0x10;
        if ((int)uVar7 < 0) {
          uVar4 = uVar4 | DAT_0000e1bc;
        }
        *(short *)puVar8 = (short)uVar12;
        *(short *)((int)puVar8 + 2) = (short)uVar7;
        if (puVar2 < puVar6) break;
        puVar8 = puVar8 + 1;
      }
      if (iVar3 == 0) {
        puVar6 = (uint *)(param_1 + (iVar5 + 3) * 4 + 4);
        while ((puVar6 = puVar6 + -1, puVar10 < puVar6 && (*puVar6 == 0))) {
          iVar9 = iVar9 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar9;
      }
    }
    iVar5 = *(int *)(param_2 + 0x10);
    if (*(int *)(param_1 + 0x10) == iVar5) {
      iVar5 = (iVar5 + 4) * 4;
      puVar6 = (uint *)(param_1 + iVar5 + 4);
      puVar8 = (uint *)(param_2 + iVar5 + 4);
      do {
        puVar6 = puVar6 + -1;
        puVar8 = puVar8 + -1;
        if (*puVar6 != *puVar8) {
          if (*puVar6 < *puVar8) {
            return iVar1;
          }
          break;
        }
      } while (puVar10 < puVar6);
    }
    else if (*(int *)(param_1 + 0x10) - iVar5 < 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    uVar4 = 0;
    puVar6 = puVar10;
    while( true ) {
      uVar7 = *local_2c;
      local_2c = local_2c + 1;
      uVar11 = ((*puVar6 & 0xffff) - (uVar7 & 0xffff)) + uVar4;
      uVar12 = uVar11 >> 0x10;
      if ((int)uVar11 < 0) {
        uVar12 = uVar12 | DAT_0000e1bc;
      }
      uVar12 = ((*puVar6 >> 0x10) - (uVar7 >> 0x10)) + uVar12;
      uVar4 = uVar12 >> 0x10;
      if ((int)uVar12 < 0) {
        uVar4 = uVar4 | DAT_0000e1bc;
      }
      *(short *)((int)puVar6 + 2) = (short)uVar12;
      *(short *)puVar6 = (short)uVar11;
      if (puVar2 < local_2c) break;
      puVar6 = puVar6 + 1;
    }
    iVar5 = param_1 + (iVar9 + 4) * 4;
    puVar2 = (uint *)(iVar5 + 4);
    if (*(int *)(iVar5 + 4) == 0) {
      while ((puVar2 = puVar2 + -1, puVar10 < puVar2 && (*puVar2 == 0))) {
        iVar9 = iVar9 + -1;
      }
      *(int *)(param_1 + 0x10) = iVar9;
    }
  }
  return iVar1;
}



/* Function: FUN_0000e1c0 @ 0000e1c0 */

undefined4 * FUN_0000e1c0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(DAT_0000e20c + 0xe1ca);
  FUN_00010f94(DAT_0000e20c + 0xe1e2);
  puVar1 = (undefined4 *)puVar2[param_1 + 7];
  if (puVar1 == (undefined4 *)0x0) {
    iVar3 = 1 << (param_1 & 0xff);
    puVar1 = (undefined4 *)FUN_000113c0((iVar3 + 5) * 4);
    if (puVar1 == (undefined4 *)0x0) goto LAB_0000e1fe;
    puVar1[1] = param_1;
    puVar1[2] = iVar3;
    puVar2 = puVar1;
  }
  else {
    puVar2[param_1 + 7] = *puVar1;
    puVar2 = puVar1;
  }
  puVar2[4] = 0;
  puVar2[3] = 0;
LAB_0000e1fe:
  FUN_00010e9c(DAT_0000e210 + 0xe21c);
  return puVar2;
}



/* Function: FUN_0000e214 @ 0000e214 */

int FUN_0000e214(uint param_1,uint param_2,int *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_20;
  uint local_1c [2];
  
  iVar1 = FUN_0000e1c0(1);
  if (iVar1 != DAT_0000e2c8 + 0xe22e) {
    local_20 = param_2 & 0xfffff;
    uVar4 = (param_2 & 0x7fffffff) >> 0x14;
    if (uVar4 != 0) {
      local_20 = local_20 | 0x100000;
    }
    local_1c[0] = param_1;
    if (param_1 == 0) {
      iVar6 = FUN_0000de60(&local_20);
      *(undefined4 *)(iVar1 + 0x10) = 1;
      *(uint *)(iVar1 + 0x14) = local_20;
      uVar2 = iVar6 + 0x20;
      iVar6 = 1;
    }
    else {
      uVar2 = FUN_0000de60(local_1c);
      if (uVar2 == 0) {
        *(uint *)(iVar1 + 0x14) = local_1c[0];
      }
      else {
        uVar5 = local_20 << (0x20 - uVar2 & 0xff);
        local_20 = local_20 >> (uVar2 & 0xff);
        *(uint *)(iVar1 + 0x14) = local_1c[0] | uVar5;
      }
      *(uint *)(iVar1 + 0x18) = local_20;
      iVar6 = 2 - (uint)(local_20 == 0);
      *(int *)(iVar1 + 0x10) = iVar6;
    }
    if (uVar4 == 0) {
      *param_3 = uVar2 + DAT_0000e2d0;
      iVar3 = FUN_0000de24(*(undefined4 *)(iVar1 + (iVar6 + 3) * 4 + 4));
      *param_4 = iVar6 * 0x20 - iVar3;
    }
    else {
      *param_3 = uVar4 + DAT_0000e2cc + uVar2;
      *param_4 = 0x35 - uVar2;
    }
  }
  return iVar1;
}



/* Function: FUN_0000e2d4 @ 0000e2d4 */

int FUN_0000e2d4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int local_34;
  uint local_30;
  
  if ((param_1 == DAT_0000e430 + 0xe2e0) || (param_2 == DAT_0000e430 + 0xe2e0)) {
    iVar2 = DAT_0000e438 + 0xe42c;
  }
  else {
    iVar7 = param_1;
    if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
      iVar7 = param_2;
      param_2 = param_1;
    }
    iVar11 = *(int *)(iVar7 + 0x10);
    iVar13 = *(int *)(param_2 + 0x10);
    iVar2 = *(int *)(iVar7 + 4);
    local_34 = iVar13 + iVar11;
    if (*(int *)(iVar7 + 8) < local_34) {
      iVar2 = iVar2 + 1;
    }
    iVar2 = FUN_0000e1c0(iVar2);
    if (iVar2 != DAT_0000e434 + 0xe314) {
      puVar5 = (uint *)(iVar2 + (local_34 + 4) * 4 + 4);
      puVar4 = (uint *)(iVar2 + 0x14);
      for (puVar8 = puVar4; puVar8 < puVar5; puVar8 = puVar8 + 1) {
        *puVar8 = 0;
      }
      puVar8 = (uint *)(iVar7 + (iVar11 + 4) * 4 + 4);
      for (puVar3 = (ushort *)(param_2 + 0x14); puVar3 < (ushort *)(param_2 + (iVar13 + 4) * 4 + 4);
          puVar3 = puVar3 + 2) {
        uVar10 = (uint)*puVar3;
        if (uVar10 != 0) {
          uVar1 = 0;
          puVar6 = puVar4;
          puVar9 = (uint *)(iVar7 + 0x14);
          do {
            uVar12 = *puVar9;
            puVar9 = puVar9 + 1;
            uVar1 = (uVar12 & 0xffff) * uVar10 + (*puVar6 & 0xffff) + uVar1;
            *(ushort *)puVar6 = (ushort)uVar1;
            uVar1 = (uVar12 >> 0x10) * uVar10 + (*puVar6 >> 0x10) + (uVar1 >> 0x10);
            *(ushort *)((int)puVar6 + 2) = (ushort)uVar1;
            uVar1 = uVar1 >> 0x10;
            puVar6 = puVar6 + 1;
          } while (puVar9 < puVar8);
          *puVar6 = uVar1;
        }
        uVar10 = (uint)puVar3[1];
        if (uVar10 != 0) {
          uVar1 = *puVar4;
          local_30 = 0;
          puVar6 = puVar4;
          puVar9 = (uint *)(iVar7 + 0x14);
          do {
            uVar12 = *puVar9;
            puVar9 = puVar9 + 1;
            *(ushort *)puVar6 = (ushort)uVar1;
            local_30 = (uVar12 & 0xffff) * uVar10 + (uint)*(ushort *)((int)puVar6 + 2) + local_30;
            *(ushort *)((int)puVar6 + 2) = (ushort)local_30;
            puVar6 = puVar6 + 1;
            uVar1 = (uVar12 >> 0x10) * uVar10 + (uint)(ushort)*puVar6 + (local_30 >> 0x10);
            local_30 = uVar1 >> 0x10;
          } while (puVar9 < puVar8);
          *puVar6 = uVar1;
        }
        puVar4 = puVar4 + 1;
      }
      while ((0 < local_34 && (puVar5 = puVar5 + -1, *puVar5 == 0))) {
        local_34 = local_34 + -1;
      }
      *(int *)(iVar2 + 0x10) = local_34;
    }
  }
  return iVar2;
}



/* Function: FUN_0000e43c @ 0000e43c */

int FUN_0000e43c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint local_24;
  
  if ((param_1 == DAT_0000e598 + 0xe448) || (param_2 == DAT_0000e598 + 0xe448)) {
    iVar1 = DAT_0000e5a8 + 0xe58a;
  }
  else {
    iVar1 = *(int *)(param_2 + 0x10);
    iVar6 = param_1;
    if (*(int *)(param_1 + 0x10) == iVar1) {
      iVar1 = (iVar1 + 4) * 4;
      puVar7 = (uint *)(param_1 + iVar1 + 4);
      puVar3 = (uint *)(param_2 + iVar1 + 4);
      do {
        puVar7 = puVar7 + -1;
        puVar3 = puVar3 + -1;
        if (*puVar7 != *puVar3) {
          if (*puVar7 < *puVar3) goto LAB_0000e49e;
          uVar9 = 0;
          goto LAB_0000e4a6;
        }
      } while ((uint *)(param_1 + 0x14) < puVar7);
      iVar1 = FUN_0000e1c0(0);
      if (iVar1 != DAT_0000e59c + 0xe492) {
        *(undefined4 *)(iVar1 + 0x10) = 1;
        *(undefined4 *)(iVar1 + 0x14) = 0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x10) - iVar1 < 0) {
LAB_0000e49e:
        uVar9 = 1;
        iVar6 = param_2;
        param_2 = param_1;
      }
      else {
        uVar9 = 0;
      }
LAB_0000e4a6:
      iVar1 = FUN_0000e1c0(*(undefined4 *)(iVar6 + 4));
      if (iVar1 != DAT_0000e5a0 + 0xe4b2) {
        iVar11 = *(int *)(iVar6 + 0x10);
        iVar4 = *(int *)(param_2 + 0x10);
        *(undefined4 *)(iVar1 + 0xc) = uVar9;
        uVar2 = 0;
        puVar3 = (uint *)(iVar6 + 0x14);
        puVar7 = (uint *)(param_2 + 0x14);
        piVar5 = (int *)(iVar1 + 0x14);
        do {
          uVar12 = *puVar3;
          uVar10 = *puVar7;
          uVar8 = ((uVar12 & 0xffff) - (uVar10 & 0xffff)) + uVar2;
          local_24 = uVar8 >> 0x10;
          if ((int)uVar8 < 0) {
            local_24 = DAT_0000e5a4 | local_24;
          }
          puVar3 = puVar3 + 1;
          puVar7 = puVar7 + 1;
          local_24 = ((uVar12 >> 0x10) - (uVar10 >> 0x10)) + local_24;
          uVar2 = local_24 >> 0x10;
          if ((int)local_24 < 0) {
            uVar2 = DAT_0000e5a4 | uVar2;
          }
          *(short *)piVar5 = (short)uVar8;
          *(short *)((int)piVar5 + 2) = (short)local_24;
          uVar8 = DAT_0000e5a4;
          piVar5 = piVar5 + 1;
        } while (puVar7 < (uint *)(param_2 + (iVar4 + 4) * 4 + 4U));
        while (puVar3 < (uint *)(iVar6 + (iVar11 + 4) * 4 + 4U)) {
          uVar12 = uVar2 + (*puVar3 & 0xffff);
          uVar10 = uVar12 >> 0x10;
          if ((int)uVar12 < 0) {
            uVar10 = uVar10 | uVar8;
          }
          uVar10 = uVar10 + (*puVar3 >> 0x10);
          uVar2 = uVar10 >> 0x10;
          puVar3 = puVar3 + 1;
          if ((int)uVar10 < 0) {
            uVar2 = uVar2 | uVar8;
          }
          *(short *)((int)piVar5 + 2) = (short)uVar10;
          *(short *)piVar5 = (short)uVar12;
          piVar5 = piVar5 + 1;
        }
        while (piVar5 = piVar5 + -1, *piVar5 == 0) {
          iVar11 = iVar11 + -1;
        }
        *(int *)(iVar1 + 0x10) = iVar11;
      }
    }
  }
  return iVar1;
}



/* Function: FUN_0000e5ac @ 0000e5ac */

void FUN_0000e5ac(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)(DAT_0000e5d8 + 0xe5b8);
    if (param_1 != puVar1) {
      iVar2 = DAT_0000e5d8 + 0xe5d0;
      FUN_00010f94(iVar2);
      *param_1 = puVar1[param_1[1] + 7];
      puVar1[param_1[1] + 7] = param_1;
      FUN_00010e9c(iVar2);
    }
  }
  return;
}



/* Function: FUN_0000e5dc @ 0000e5dc */

int FUN_0000e5dc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  
  iVar1 = param_1;
  if (param_1 != DAT_0000e680 + 0xe5e8) {
    iVar1 = *(int *)(param_1 + 4);
    iVar6 = *(int *)(param_1 + 0x10) + 1 + (param_2 >> 5);
    for (iVar4 = *(int *)(param_1 + 8); iVar4 < iVar6; iVar4 = iVar4 << 1) {
      iVar1 = iVar1 + 1;
    }
    iVar1 = FUN_0000e1c0(iVar1);
    if (iVar1 != DAT_0000e684 + 0xe60e) {
      puVar5 = (uint *)(iVar1 + 0x14);
      for (iVar4 = 0; iVar4 < (int)(param_2 >> 5); iVar4 = iVar4 + 1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      puVar3 = (uint *)(param_1 + 0x14);
      puVar7 = (uint *)(param_1 + (*(int *)(param_1 + 0x10) + 4) * 4 + 4);
      param_2 = param_2 & 0x1f;
      if (param_2 == 0) {
        do {
          uVar2 = *puVar3;
          puVar3 = puVar3 + 1;
          *puVar5 = uVar2;
          puVar5 = puVar5 + 1;
        } while (puVar3 < puVar7);
      }
      else {
        uVar2 = 0;
        do {
          *puVar5 = uVar2 | *puVar3 << param_2;
          puVar5 = puVar5 + 1;
          uVar2 = *puVar3;
          puVar3 = puVar3 + 1;
          uVar2 = uVar2 >> (0x20 - param_2 & 0xff);
        } while (puVar3 < puVar7);
        *puVar5 = uVar2;
        iVar6 = iVar6 + (uint)(uVar2 != 0);
      }
      *(int *)(iVar1 + 0x10) = iVar6 + -1;
    }
    FUN_0000e5ac(param_1);
  }
  return iVar1;
}



/* Function: FUN_0000e688 @ 0000e688 */

void FUN_0000e688(int *param_1,int param_2)

{
  if (*param_1 != DAT_0000e6b4 + 0xe694) {
    if (param_2 == DAT_0000e6b4 + 0xe694) {
      FUN_0000e5ac();
      *param_1 = param_2;
    }
    else {
      FUN_00008170(*param_1 + 0xc,param_2 + 0xc,(*(int *)(param_2 + 0x10) + 2) * 4);
    }
  }
  return;
}



/* Function: FUN_0000e6b8 @ 0000e6b8 */

int FUN_0000e6b8(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = param_1;
  if (param_1 != DAT_0000e750 + 0xe6c4) {
    iVar6 = *(int *)(param_1 + 0x10);
    puVar3 = (uint *)(param_1 + 0x14);
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      uVar1 = param_3 + param_2 * (*puVar3 & 0xffff);
      uVar5 = param_2 * (*puVar3 >> 0x10) + (uVar1 >> 0x10);
      param_3 = uVar5 >> 0x10;
      *puVar3 = uVar5 * 0x10000 + (uVar1 & 0xffff);
      puVar3 = puVar3 + 1;
    } while (iVar4 < iVar6);
    if (param_3 != 0) {
      if (*(int *)(param_1 + 8) <= iVar6) {
        iVar2 = FUN_0000e1c0(*(int *)(param_1 + 4) + 1);
        if (iVar2 == DAT_0000e754 + 0xe71a) {
          FUN_0000e5ac(param_1);
          return iVar2;
        }
        FUN_00008170(iVar2 + 0xc,param_1 + 0xc,(*(int *)(param_1 + 0x10) + 2) * 4);
        FUN_0000e5ac(param_1);
      }
      *(uint *)(iVar2 + (iVar6 + 4) * 4 + 4) = param_3;
      *(int *)(iVar2 + 0x10) = iVar6 + 1;
    }
  }
  return iVar2;
}



/* Function: FUN_0000e758 @ 0000e758 */

undefined4 * FUN_0000e758(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = param_1;
  if (param_1 != (undefined4 *)(DAT_0000e810 + 0xe764)) {
    if ((param_2 & 3) != 0) {
      param_1 = (undefined4 *)
                FUN_0000e6b8(param_1,*(undefined4 *)
                                      (((param_2 & 3) - 1) * 4 + DAT_0000e814 + 0xe77a),0);
    }
    iVar1 = DAT_0000e818;
    param_2 = param_2 >> 2;
    puVar6 = param_1;
    if (param_2 != 0) {
      puVar6 = (undefined4 *)(DAT_0000e818 + 0xe790);
      puVar4 = *(undefined4 **)(DAT_0000e818 + 0xe7ec);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)FUN_0000e1c0(1);
        uVar2 = DAT_0000e81c;
        if (puVar4 == puVar6) {
          FUN_0000e5ac(param_1);
          return puVar4;
        }
        *(undefined4 **)(iVar1 + 0xe7ec) = puVar4;
        puVar4[5] = uVar2;
        puVar4[4] = 1;
        *puVar4 = 0;
      }
      puVar6 = (undefined4 *)(DAT_0000e820 + 0xe7c4);
      while( true ) {
        do {
          puVar5 = puVar4;
          puVar3 = param_1;
          if ((param_2 & 1) != 0) {
            puVar3 = (undefined4 *)FUN_0000e2d4(param_1,puVar5);
            FUN_0000e5ac(param_1);
          }
          param_2 = param_2 >> 1;
          if (param_2 == 0) {
            return puVar3;
          }
          puVar4 = (undefined4 *)*puVar5;
          param_1 = puVar3;
        } while ((undefined4 *)*puVar5 != (undefined4 *)0x0);
        puVar4 = (undefined4 *)FUN_0000e2d4(puVar5,puVar5);
        if (puVar4 == puVar6) break;
        *puVar5 = puVar4;
        *puVar4 = 0;
      }
      FUN_0000e5ac(puVar3);
    }
  }
  return puVar6;
}



/* Function: FUN_0000f5e8 @ 0000f5e8 */

void FUN_0000f5e8(int param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar2 = FUN_00008c64(param_3 + 8,9);
  iVar4 = 0;
  for (iVar3 = 1; iVar3 < iVar2; iVar3 = iVar3 << 1) {
    iVar4 = iVar4 + 1;
  }
  iVar2 = FUN_0000e1c0(iVar4);
  if (iVar2 != DAT_0000f668 + 63000) {
    *(undefined4 *)(iVar2 + 0x14) = param_4;
    *(undefined4 *)(iVar2 + 0x10) = 1;
    if (param_2 < 10) {
      pbVar5 = (byte *)(param_1 + 10);
      param_2 = 9;
    }
    else {
      pbVar5 = (byte *)(param_1 + 9);
      do {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        iVar2 = FUN_0000e6b8(iVar2,10,bVar1 - 0x30);
      } while (pbVar5 != (byte *)(param_1 + param_2));
      pbVar5 = (byte *)(param_1 + 9) + param_2 + -8;
    }
    for (iVar3 = param_2; iVar3 < param_3; iVar3 = iVar3 + 1) {
      iVar2 = FUN_0000e6b8(iVar2,10,pbVar5[iVar3 - param_2] - 0x30);
    }
  }
  return;
}



/* Function: FUN_0000f670 @ 0000f670 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0000f670(byte *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint extraout_r2;
  int extraout_r2_00;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  int *piVar11;
  int iVar12;
  int extraout_r3;
  int extraout_r3_00;
  byte *extraout_r3_01;
  byte *extraout_r3_02;
  int extraout_r3_03;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  uint *puVar16;
  int *piVar17;
  byte *pbVar18;
  int iVar19;
  byte *pbVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined8 uVar24;
  ulonglong uVar25;
  undefined8 uVar26;
  longlong lVar27;
  byte *local_78;
  int local_70;
  uint local_64;
  undefined4 *local_60;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_30;
  uint local_2c;
  undefined4 local_24;
  int local_20;
  int local_1c [2];
  
  iVar12 = iRam0000f950 + 0xf67e;
  local_24 = 0;
  while (uVar6 = (uint)*param_1, (*(byte *)(**(int **)(iVar12 + DAT_0000f954) + uVar6 + 1) & 8) != 0
        ) {
    param_1 = param_1 + 1;
  }
  if (uVar6 == 0x2d) {
    param_1 = param_1 + 1;
  }
  else if (uVar6 == 0x2b) {
    param_1 = param_1 + 1;
  }
  pbVar20 = (byte *)(uint)*param_1;
  if (pbVar20 == (byte *)0x0) {
    FUN_00010136();
    iVar12 = extraout_r3;
  }
  iVar12 = (int)*(short *)((int)(pbVar20 + 1) * 2 + **(int **)(iVar12 + DAT_0000f958));
  if (iVar12 == 0x69) {
    iVar12 = FUN_00010498(param_1,DAT_0000f95c + 0xf6de,3);
    if (iVar12 == 0) {
      iVar12 = FUN_00010498(param_1 + 3,DAT_0000f960 + 0xf6ee,5);
      pbVar20 = param_1 + 3;
      if (iVar12 == 0) {
        pbVar20 = param_1 + 8;
      }
      param_1 = pbVar20;
      FUN_00010138();
      iVar12 = extraout_r3_00;
      pbVar20 = param_1;
      goto LAB_0000f706;
    }
  }
  else {
LAB_0000f706:
    if ((iVar12 == 0x6e) && (iVar12 = FUN_00010498(param_1,DAT_0000f964 + 0xf714,3), iVar12 == 0)) {
      pbVar20 = (byte *)(uint)param_1[3];
      param_1 = param_1 + 4;
      if (pbVar20 != (byte *)0x28) {
        FUN_00010138();
        param_1 = extraout_r3_01;
      }
      do {
        uVar6 = (uint)*param_1;
        if (uVar6 == 0) {
          FUN_00010138();
          uVar6 = extraout_r2;
          param_1 = extraout_r3_02;
        }
        param_1 = param_1 + 1;
      } while (uVar6 != 0x29);
      FUN_00010138();
    }
  }
  bVar1 = false;
  if (pbVar20 == (byte *)0x30) {
    do {
      param_1 = param_1 + 1;
    } while (*param_1 == 0x30);
    if (*param_1 == 0) {
      FUN_00010138();
    }
    bVar1 = true;
  }
  iVar12 = 0;
  local_58 = 0;
  for (local_50 = 0; uVar6 = (uint)param_1[local_50], local_78 = param_1, iVar15 = local_50,
      0x2f < uVar6; local_50 = local_50 + 1) {
    if (0x39 < uVar6) goto LAB_0000f7a8;
    if (local_50 < 9) {
      local_58 = (uVar6 - 0x30) + local_58 * 10;
    }
    else if (local_50 < 0x10) {
      iVar12 = (uVar6 - 0x30) + iVar12 * 10;
    }
  }
  pbVar20 = param_1 + local_50;
  if (uVar6 == 0x2e) {
    param_1 = pbVar20 + 1;
    uVar6 = (uint)pbVar20[1];
    pbVar18 = pbVar20;
    if (local_50 == 0) {
      while (param_1 = pbVar18 + 1, uVar6 == 0x30) {
        uVar6 = (uint)pbVar18[2];
        pbVar18 = param_1;
      }
      iVar3 = (int)pbVar18 - (int)pbVar20;
      if (uVar6 - 0x31 < 9) {
        iVar22 = 0;
        local_78 = param_1;
        goto LAB_0000f7e8;
      }
      local_50 = 0;
      iVar22 = iVar3;
      goto LAB_0000f7aa;
    }
    iVar22 = 0;
    iVar3 = 0;
    while (uVar6 - 0x30 < 10) {
LAB_0000f7e8:
      iVar13 = uVar6 - 0x30;
      iVar22 = iVar22 + 1;
      if (iVar13 != 0) {
        iVar3 = iVar3 + iVar22;
        iVar23 = iVar15;
        for (iVar21 = 1; iVar15 = iVar23 + 1, iVar21 < iVar22; iVar21 = iVar21 + 1) {
          if (iVar23 < 9) {
            local_58 = local_58 * 10;
          }
          else if (iVar15 < 0x11) {
            iVar12 = iVar12 * 10;
          }
          iVar23 = iVar15;
        }
        if (iVar23 < 9) {
          local_58 = local_58 * 10 + iVar13;
        }
        else if (iVar15 < 0x11) {
          iVar12 = iVar12 * 10 + iVar13;
        }
        iVar22 = 0;
      }
      param_1 = param_1 + 1;
      uVar6 = (uint)*param_1;
    }
  }
  else {
LAB_0000f7a8:
    param_1 = param_1 + local_50;
    iVar22 = 0;
LAB_0000f7aa:
    iVar3 = 0;
  }
  if ((uVar6 == 0x45) || (uVar6 == 0x65)) {
    uVar24 = CONCAT44(param_1,iVar3);
    if ((iVar15 == 0) &&
       ((uVar24 = CONCAT44(param_1,iVar3), iVar22 == 0 && (uVar24 = CONCAT44(param_1,iVar3), !bVar1)
        ))) {
      uVar24 = FUN_00010136();
      iVar22 = extraout_r2_00;
      local_50 = extraout_r3_03;
    }
    iVar13 = (int)((ulonglong)uVar24 >> 0x20);
    iVar3 = (int)uVar24;
    local_64 = (uint)*(byte *)(iVar13 + 1);
    pbVar20 = (byte *)(iVar13 + 1);
    if (local_64 == 0x2b) {
      bVar2 = false;
LAB_0000f88c:
      pbVar20 = (byte *)(iVar13 + 2);
      local_64 = (uint)*pbVar20;
    }
    else {
      if (local_64 == 0x2d) {
        bVar2 = true;
        goto LAB_0000f88c;
      }
      bVar2 = false;
    }
    if (9 < local_64 - 0x30) goto LAB_0000f8d0;
    while (local_64 == 0x30) {
      pbVar20 = pbVar20 + 1;
      local_64 = (uint)*pbVar20;
    }
    uVar6 = local_64 - 0x31;
    local_64 = local_64 - 0x30;
    pbVar18 = pbVar20;
    if (8 < uVar6) goto LAB_0000f8d0;
    while( true ) {
      pbVar18 = pbVar18 + 1;
      uVar6 = (uint)*pbVar18;
      if ((uVar6 < 0x30) || (0x39 < uVar6)) break;
      local_64 = (uVar6 - 0x30) + local_64 * 10;
    }
    if ((8 < (int)pbVar18 - (int)pbVar20) || (local_54 = local_64, DAT_0000f96c < (int)local_64)) {
      local_54 = DAT_0000f96c;
    }
    if (bVar2) {
      local_54 = -local_54;
    }
  }
  else {
LAB_0000f8d0:
    local_54 = 0;
  }
  if (iVar15 == 0) {
    if (iVar22 != 0) {
      FUN_00010138();
    }
    if (!bVar1) {
      FUN_00010136();
    }
    FUN_00010138();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar3 = local_54 - iVar3;
  if (local_50 == 0) {
    local_50 = iVar15;
  }
  iVar22 = iVar15;
  if (0x10 < iVar15) {
    iVar22 = 0x10;
  }
  uVar25 = FUN_00009014(local_58);
  if (9 < iVar22) {
    iVar13 = DAT_0000fc90 + 0xf99e + (iVar22 + -9) * 8;
    uVar24 = FUN_00009114((int)uVar25,(int)(uVar25 >> 0x20),*(undefined4 *)(iVar13 + 0x10),
                          *(undefined4 *)(iVar13 + 0x14));
    uVar26 = FUN_00009014(iVar12);
    uVar25 = FUN_00008d68((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar26,
                          (int)((ulonglong)uVar26 >> 0x20));
  }
  local_2c = (uint)(uVar25 >> 0x20);
  local_30 = (int)uVar25;
  if (iVar15 < 0x10) {
    if (iVar3 == 0) {
      FUN_00010138();
      return;
    }
    if (0 < iVar3) {
      if (iVar3 < 0x17) {
        iVar12 = DAT_0000fc94 + 0xf9de + iVar3 * 8;
        uVar7 = *(undefined4 *)(iVar12 + 0x10);
        uVar14 = *(undefined4 *)(iVar12 + 0x14);
      }
      else {
        iVar12 = -iVar15 + 0xf;
        if (-iVar15 + 0x25 < iVar3) goto LAB_0000fa3e;
        iVar22 = DAT_0000fc98 + 0xf9fe;
        iVar15 = iVar22 + iVar12 * 8;
        uVar25 = FUN_00009114(local_30,local_2c,*(undefined4 *)(iVar15 + 0x10),
                              *(undefined4 *)(iVar15 + 0x14));
        iVar22 = iVar22 + (iVar3 - iVar12) * 8;
        uVar7 = *(undefined4 *)(iVar22 + 0x10);
        uVar14 = *(undefined4 *)(iVar22 + 0x14);
      }
      FUN_00009114((int)uVar25,(int)(uVar25 >> 0x20),uVar7,uVar14);
LAB_0000fa38:
      FUN_00010138();
      return;
    }
    if (-0x17 < iVar3) {
      iVar12 = DAT_0000fc9c + 0xfa2e + iVar3 * -8;
      FUN_00009380(local_30,local_2c,*(undefined4 *)(iVar12 + 0x10),*(undefined4 *)(iVar12 + 0x14));
      goto LAB_0000fa38;
    }
  }
LAB_0000fa3e:
  uVar6 = (iVar15 - iVar22) + iVar3;
  if ((int)uVar6 < 1) {
    if (uVar6 != 0) {
      uVar6 = -uVar6;
      if ((uVar6 & 0xf) != 0) {
        iVar12 = DAT_0000fcc0 + 0xfb32 + (uVar6 & 0xf) * 8;
        uVar25 = FUN_00009380(local_30,local_2c,*(undefined4 *)(iVar12 + 0x10),
                              *(undefined4 *)(iVar12 + 0x14));
      }
      if ((uVar6 & 0xfffffff0) != 0) {
        uVar6 = uVar6 >> 4;
        if (0x1f < uVar6) {
LAB_0000fbe0:
          iVar12 = 0;
          iVar15 = 0;
          local_58 = 0;
          local_54 = 0;
LAB_0000fbe8:
          puVar4 = (undefined4 *)FUN_000113b0();
          *puVar4 = 0x22;
          if (local_54 == 0) {
            FUN_00010138();
            return;
          }
          goto LAB_00010116;
        }
        local_60 = (undefined4 *)(DAT_0000fcc4 + 0xfbcc);
        local_70 = 0;
        while( true ) {
          uVar14 = (undefined4)(uVar25 >> 0x20);
          uVar7 = (undefined4)uVar25;
          if (uVar6 < 2) break;
          if ((uVar6 & 1) != 0) {
            uVar25 = FUN_00009114(uVar7,uVar14,*local_60,local_60[1]);
          }
          uVar6 = uVar6 >> 1;
          local_70 = local_70 + 1;
          local_60 = local_60 + 2;
        }
        iVar12 = DAT_0000fcc8 + 0xfb98 + local_70 * 8;
        uVar5 = *(undefined4 *)(iVar12 + 0x70);
        uVar9 = *(undefined4 *)(iVar12 + 0x74);
        uVar25 = FUN_00009114(uVar7,uVar14,uVar5,uVar9);
        iVar12 = FUN_0000964c((int)uVar25,(int)(uVar25 >> 0x20),DAT_0000fc88,DAT_0000fc8c);
        if (iVar12 != 0) {
          uVar24 = FUN_00008d68(uVar7,uVar14,uVar7,uVar14);
          uVar24 = FUN_00009114((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),uVar5,uVar9);
          iVar12 = FUN_0000964c((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),DAT_0000fc88,
                                DAT_0000fc8c);
          if (iVar12 != 0) goto LAB_0000fbe0;
          uVar25 = 1;
        }
      }
    }
  }
  else {
    if ((uVar6 & 0xf) != 0) {
      iVar12 = DAT_0000fca0 + 0xfa5a + (uVar6 & 0xf) * 8;
      uVar25 = FUN_00009114(local_30,local_2c,*(undefined4 *)(iVar12 + 0x10),
                            *(undefined4 *)(iVar12 + 0x14));
    }
    if ((uVar6 & 0xfffffff0) != 0) {
      if (0x134 < (int)(uVar6 & 0xfffffff0)) {
LAB_0000fa76:
        iVar12 = 0;
        iVar15 = 0;
        local_58 = 0;
        local_54 = 0;
LAB_0000fa82:
        puVar4 = (undefined4 *)FUN_000113b0();
        *puVar4 = 0x22;
        if (local_54 == 0) {
          FUN_00010138();
          return;
        }
        goto LAB_00010116;
      }
      uVar6 = uVar6 >> 4;
      if (uVar6 != 0) {
        puVar4 = (undefined4 *)(DAT_0000fca4 + 0xfaf8);
        local_70 = 0;
        while( true ) {
          iVar12 = (int)(uVar25 >> 0x20);
          if (uVar6 < 2) break;
          if ((uVar6 & 1) != 0) {
            uVar25 = FUN_00009114((int)uVar25,iVar12,*puVar4,puVar4[1]);
          }
          uVar6 = uVar6 >> 1;
          puVar4 = puVar4 + 2;
          local_70 = local_70 + 1;
        }
        iVar22 = DAT_0000fcac + 0xfae6 + local_70 * 8;
        uVar24 = FUN_00009114((int)uVar25,iVar12 + DAT_0000fca8,*(undefined4 *)(iVar22 + 0x48),
                              *(undefined4 *)(iVar22 + 0x4c));
        uVar6 = (uint)((ulonglong)uVar24 >> 0x20);
        uVar8 = DAT_0000fcb0 & uVar6;
        if (DAT_0000fcb4 < uVar8) goto LAB_0000fa76;
        if (DAT_0000fcb8 < uVar8) {
          uVar25 = CONCAT44(DAT_0000fcbc,0xffffffff);
        }
        else {
          uVar25 = CONCAT44(uVar6 + 0x3500000,(int)uVar24);
        }
      }
    }
  }
  local_54 = FUN_0000f5e8(local_78,local_50,iVar15,local_58);
  iVar22 = DAT_0000fccc + 0xfc20;
  while( true ) {
    local_2c = (uint)(uVar25 >> 0x20);
    local_30 = (int)uVar25;
    local_24 = FUN_0000e1c0(*(undefined4 *)(local_54 + 4));
    FUN_0000e688(&local_24,local_54);
    uVar7 = FUN_0000e214(local_30,local_2c,local_1c,&local_20);
    iVar12 = FUN_0000e1c0(1);
    if (iVar12 != iVar22) {
      *(undefined4 *)(iVar12 + 0x14) = 1;
      *(undefined4 *)(iVar12 + 0x10) = 1;
    }
    if (iVar3 < 0) {
      iVar13 = 0;
      iVar15 = -iVar3;
    }
    else {
      iVar15 = 0;
      iVar13 = iVar3;
    }
    if (local_1c[0] < 0) {
      iVar23 = iVar13 - local_1c[0];
      local_78 = (byte *)iVar15;
    }
    else {
      iVar23 = iVar13;
      local_78 = (byte *)(iVar15 + local_1c[0]);
    }
    iVar21 = local_1c[0] + DAT_0000ffe8;
    if (DAT_0000ffec <= local_20 + local_1c[0]) {
      iVar21 = 0x36 - local_20;
    }
    iVar19 = iVar21 + (int)local_78;
    iVar21 = iVar21 + iVar23;
    iVar23 = iVar19;
    if (iVar21 < iVar19) {
      iVar23 = iVar21;
    }
    if ((int)local_78 < iVar23) {
      iVar23 = (int)local_78;
    }
    if (0 < iVar23) {
      local_78 = (byte *)((int)local_78 - iVar23);
      iVar19 = iVar19 - iVar23;
      iVar21 = iVar21 - iVar23;
    }
    local_58 = uVar7;
    if (iVar15 != 0) {
      iVar12 = FUN_0000e758(iVar12);
      local_58 = FUN_0000e2d4(iVar12,uVar7);
      FUN_0000e5ac(uVar7);
    }
    if (0 < iVar19) {
      local_58 = FUN_0000e5dc(local_58,iVar19);
    }
    if (iVar13 != 0) {
      local_24 = FUN_0000e758(local_24,iVar13);
    }
    if (0 < iVar21) {
      local_24 = FUN_0000e5dc(local_24,iVar21);
    }
    if (0 < (int)local_78) {
      iVar12 = FUN_0000e5dc(iVar12);
    }
    iVar15 = FUN_0000e43c(local_58,local_24);
    iVar23 = *(int *)(iVar15 + 0xc);
    iVar13 = DAT_0000fff0 + 0xfd6e;
    *(undefined4 *)(iVar15 + 0xc) = 0;
    if ((iVar15 == iVar13) || (iVar12 == iVar13)) break;
    iVar13 = *(int *)(iVar12 + 0x10);
    if (*(int *)(iVar15 + 0x10) == iVar13) {
      iVar13 = (iVar13 + 4) * 4;
      puVar16 = (uint *)(iVar15 + iVar13 + 4);
      puVar10 = (uint *)(iVar12 + iVar13 + 4);
      while( true ) {
        puVar16 = puVar16 + -1;
        puVar10 = puVar10 + -1;
        if (*puVar16 != *puVar10) break;
        if (puVar16 <= (uint *)(iVar15 + 0x14)) goto LAB_00010158;
      }
      if (*puVar16 < *puVar10) {
LAB_0000fdb6:
        if ((((iVar23 == 0) && (local_30 == 0)) && ((uVar25 & 0xfffff00000000) == 0)) &&
           ((iVar15 = FUN_0000e5dc(iVar15,1), iVar15 != DAT_0000fff4 + 0xfde2 &&
            (*(int *)(iVar15 + 0x10) == *(int *)(iVar12 + 0x10))))) {
          iVar3 = (*(int *)(iVar12 + 0x10) + 4) * 4;
          piVar17 = (int *)(iVar15 + iVar3 + 4);
          piVar11 = (int *)(iVar12 + iVar3 + 4);
          goto LAB_0000fe00;
        }
        goto LAB_00010116;
      }
    }
    else if (*(int *)(iVar15 + 0x10) - iVar13 < 0) goto LAB_0000fdb6;
    uVar24 = FUN_0000dfb0(iVar15,iVar12);
    uVar14 = (undefined4)((ulonglong)uVar24 >> 0x20);
    uVar7 = (undefined4)uVar24;
    iVar13 = FUN_00009674(uVar7,uVar14,DAT_0000ffd0,DAT_0000ffd4);
    if (iVar13 == 0) {
      lVar27 = FUN_00009114(uVar7,uVar14,DAT_0000ffe0,DAT_0000ffe4);
      local_78 = (byte *)((ulonglong)lVar27 >> 0x20);
      if (iVar23 == 0) {
        local_78 = (byte *)((int)local_78 + 0x80000000);
      }
    }
    else if (iVar23 == 0) {
      if (local_30 == 0) {
        if ((uVar25 & 0xfffff00000000) == 0) {
          iVar13 = FUN_00009660(uVar7,uVar14,DAT_0000ffd8,DAT_0000ffdc);
          if (iVar13 == 0) {
            lVar27 = FUN_00009114(uVar7,uVar14,DAT_0000ffe0,DAT_0000ffe4);
          }
          else {
            lVar27 = (ulonglong)DAT_00010008 << 0x20;
          }
          local_78 = (byte *)((int)((ulonglong)lVar27 >> 0x20) + 0x80000000);
          goto LAB_0000ff5e;
        }
      }
      else if (uVar25 == 1) goto LAB_0000fbe8;
      lVar27 = (ulonglong)DAT_00010004 << 0x20;
      local_78 = (byte *)DAT_0001000c;
    }
    else {
      lVar27 = (ulonglong)DAT_00010004 << 0x20;
      local_78 = (byte *)DAT_00010004;
    }
LAB_0000ff5e:
    uVar14 = (undefined4)((ulonglong)lVar27 >> 0x20);
    local_4c = (undefined4)lVar27;
    uVar7 = local_4c;
    uVar6 = DAT_0000fffc & local_2c;
    if (uVar6 == DAT_00010010) {
      iVar13 = local_2c + DAT_00010014;
      uVar24 = FUN_0000debc(local_30,iVar13);
      uVar24 = FUN_00009114(local_4c,local_78,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
      uVar24 = FUN_00008d68(local_30,iVar13,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
      uVar8 = (uint)((ulonglong)uVar24 >> 0x20);
      if ((DAT_0000fffc & uVar8) <= DAT_00010018) {
        uVar25 = CONCAT44(uVar8 + 0x3500000,(int)uVar24);
        goto LAB_0001008e;
      }
      if ((local_2c == DAT_0001001c) && (local_30 == -1)) goto LAB_0000fa82;
      uVar25 = CONCAT44(DAT_0001001c,0xffffffff);
    }
    else {
      uVar24 = CONCAT44(local_78,local_4c);
      if ((uVar6 < 0x3400001) &&
         (iVar13 = FUN_00009688(local_4c,uVar14,DAT_00010168,DAT_0001016c),
         uVar24 = CONCAT44(local_78,local_4c), iVar13 != 0)) {
        FUN_00008d68(local_4c,uVar14,DAT_00010170,DAT_00010174);
        FUN_000096b0();
        uVar24 = FUN_00009038();
        if (iVar23 == 0) {
          uVar24 = CONCAT44((int)((ulonglong)uVar24 >> 0x20) + -0x80000000,(int)uVar24);
        }
      }
      local_78 = (byte *)((ulonglong)uVar24 >> 0x20);
      local_4c = (undefined4)uVar24;
      uVar24 = FUN_0000debc(local_30,local_2c);
      uVar24 = FUN_00009114(local_4c,local_78,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
      uVar25 = FUN_00008d68(local_30,local_2c,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
LAB_0001008e:
      local_2c = (uint)(uVar25 >> 0x20);
      local_30 = (int)uVar25;
      if (uVar6 == (DAT_00010190 & local_2c)) {
        FUN_000096b0(uVar7,uVar14);
        uVar24 = FUN_00009038();
        uVar24 = FUN_00008d64(uVar7,uVar14,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
        uVar14 = (undefined4)((ulonglong)uVar24 >> 0x20);
        uVar7 = (undefined4)uVar24;
        if (((iVar23 == 0) && (local_30 == 0)) && ((uVar25 & 0xfffff00000000) == 0)) {
          iVar13 = FUN_00009660(uVar7,uVar14,DAT_00010188,DAT_0001018c);
        }
        else {
          iVar13 = FUN_00009660(uVar7,uVar14,DAT_00010178,DAT_0001017c);
          if (iVar13 != 0) goto LAB_00010116;
          iVar13 = FUN_0000969c(uVar7,uVar14,DAT_00010180,DAT_00010184);
        }
        if (iVar13 != 0) goto LAB_00010116;
      }
    }
    FUN_0000e5ac(local_58);
    FUN_0000e5ac(local_24);
    FUN_0000e5ac(iVar12);
    FUN_0000e5ac(iVar15);
  }
LAB_00010158:
  if (iVar23 == 0) {
    if (((uVar25 & 0xfffff00000000) == 0) && (local_30 == 0)) goto LAB_00010116;
  }
  else if (((local_2c & 0xfffff) == DAT_0000fff8) && (local_30 == -1)) goto LAB_00010116;
  if (local_30 << 0x1f < 0) {
    if (iVar23 == 0) {
      uVar24 = FUN_0000debc(local_30,local_2c);
      uVar24 = FUN_00008d64(local_30,local_2c,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
      iVar3 = FUN_0000964c((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),DAT_0000ffc8,DAT_0000ffcc);
      if (iVar3 != 0) goto LAB_0000fbe8;
    }
    else {
      uVar24 = FUN_0000debc(local_30,local_2c);
      FUN_00008d68(local_30,local_2c,(int)uVar24,(int)((ulonglong)uVar24 >> 0x20));
    }
  }
LAB_00010116:
  FUN_0000e5ac(local_58);
  FUN_0000e5ac(local_24);
  FUN_0000e5ac(iVar12);
  FUN_0000e5ac(local_54);
  FUN_0000e5ac(iVar15);
  FUN_00010138();
  return;
  while ((int *)(iVar15 + 0x14) < piVar17) {
LAB_0000fe00:
    piVar17 = piVar17 + -1;
    piVar11 = piVar11 + -1;
    if (*piVar17 != *piVar11) break;
  }
  goto LAB_00010116;
}



/* Function: FUN_00010136 @ 00010136 */

undefined8 FUN_00010136(void)

{
  undefined4 in_stack_00000014;
  int in_stack_00000034;
  undefined4 *in_stack_0000003c;
  undefined4 in_stack_00000048;
  int in_stack_0000004c;
  
  if (in_stack_0000003c != (undefined4 *)0x0) {
    *in_stack_0000003c = in_stack_00000014;
  }
  if (in_stack_00000034 != 0) {
    in_stack_0000004c = in_stack_0000004c + -0x80000000;
  }
  return CONCAT44(in_stack_0000004c,in_stack_00000048);
}



/* Function: FUN_00010138 @ 00010138 */

undefined8 FUN_00010138(void)

{
  undefined4 unaff_r4;
  int in_stack_00000034;
  undefined4 *in_stack_0000003c;
  undefined4 in_stack_00000048;
  int in_stack_0000004c;
  
  if (in_stack_0000003c != (undefined4 *)0x0) {
    *in_stack_0000003c = unaff_r4;
  }
  if (in_stack_00000034 != 0) {
    in_stack_0000004c = in_stack_0000004c + -0x80000000;
  }
  return CONCAT44(in_stack_0000004c,in_stack_00000048);
}



/* Function: FUN_00010198 @ 00010198 */

/* WARNING: Removing unreachable block (ram,0x0001037c) */
/* WARNING: Removing unreachable block (ram,0x0001032c) */

longlong FUN_00010198(byte *param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int extraout_r2;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  longlong lVar13;
  longlong lVar14;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  byte *local_30;
  
  lVar13 = CONCAT44(DAT_00010404,DAT_00010400);
  lVar14 = CONCAT44(DAT_0001040c,DAT_00010408);
  iVar7 = DAT_00010450 + 0x101a4;
  pbVar9 = param_1;
  do {
    pbVar8 = pbVar9;
    uVar12 = (uint)*pbVar8;
    pbVar9 = pbVar8 + 1;
  } while ((*(byte *)(**(int **)(iVar7 + DAT_00010454) + uVar12 + 1) & 8) != 0);
  if (uVar12 == 0x2d) {
    uVar12 = (uint)*pbVar9;
    pbVar9 = pbVar8 + 2;
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (uVar12 == 0x2b) {
      uVar12 = (uint)*pbVar9;
      pbVar9 = pbVar8 + 2;
    }
  }
  if ((param_3 == 0x10) || (param_3 == 0)) {
    if ((uVar12 == 0x30) && ((*pbVar9 == 0x58 || (*pbVar9 == 0x78)))) {
      uVar12 = (uint)pbVar9[1];
      param_3 = 0x10;
      pbVar9 = pbVar9 + 2;
LAB_00010272:
      if (!bVar2) {
        iVar11 = 0xf;
        lVar13 = CONCAT44(DAT_0001044c,DAT_00010448);
        goto LAB_000102d0;
      }
      iVar11 = 0;
      lVar14 = CONCAT44(DAT_00010444,DAT_00010440);
      goto LAB_000102ce;
    }
    if (param_3 != 0) goto LAB_00010206;
    if (uVar12 != 0x30) goto LAB_0001024e;
LAB_00010234:
    if (!bVar2) {
      param_3 = 8;
      iVar11 = 7;
      lVar13 = CONCAT44(DAT_00010414,DAT_00010410);
      goto LAB_000102d0;
    }
    param_3 = 8;
    iVar11 = 0;
    lVar14 = CONCAT44(DAT_0001041c,DAT_00010418);
  }
  else {
LAB_00010206:
    if (param_3 == 8) goto LAB_00010234;
    if (param_3 < 9) {
      if (param_3 == 4) {
        if (!bVar2) {
          iVar11 = 3;
          goto LAB_000102d0;
        }
        iVar11 = 0;
      }
      else {
LAB_0001027c:
        if (bVar2) {
          local_48 = DAT_00010438;
          local_44 = DAT_0001043c;
        }
        else {
          local_48 = DAT_00010430;
          local_44 = DAT_00010434;
        }
        FUN_000097c0(local_48,local_44,param_3,param_3 >> 0x1f);
        lVar13 = FUN_000097c0(local_48,local_44,param_3,param_3 >> 0x1f);
        iVar11 = extraout_r2;
        if (!bVar2) goto LAB_000102d0;
        lVar14 = lVar13;
        if (0 < extraout_r2) {
          iVar11 = extraout_r2 - param_3;
          lVar14 = lVar13 + 1;
        }
      }
    }
    else {
      if (param_3 != 10) {
        if (param_3 == 0x10) goto LAB_00010272;
        goto LAB_0001027c;
      }
LAB_0001024e:
      if (!bVar2) {
        param_3 = 10;
        iVar11 = 7;
        lVar13 = CONCAT44(DAT_00010424,DAT_00010420);
        goto LAB_000102d0;
      }
      param_3 = 10;
      iVar11 = -8;
      lVar14 = CONCAT44(DAT_0001042c,DAT_00010428);
    }
  }
LAB_000102ce:
  iVar11 = -iVar11;
  lVar13 = lVar14;
LAB_000102d0:
  iVar3 = DAT_00010454;
  iVar6 = 0;
  lVar14 = 0;
  do {
    uVar5 = (undefined4)((ulonglong)lVar14 >> 0x20);
    uVar10 = uVar12 - 0x30;
    if (9 < uVar10) {
      bVar1 = *(byte *)(**(int **)(iVar7 + iVar3) + uVar12 + 1);
      if ((bVar1 & 3) == 0) {
LAB_000103c8:
        if (param_2 != (undefined4 *)0x0) {
          local_30 = param_1;
          if (iVar6 != 0) {
            local_30 = pbVar9 + -1;
          }
          *param_2 = local_30;
        }
        return lVar14;
      }
      local_4c = 0x37;
      if ((bVar1 & 1) == 0) {
        local_4c = 0x57;
      }
      uVar10 = uVar12 - local_4c;
    }
    if (param_3 <= (int)uVar10) goto LAB_000103c8;
    if (iVar6 != -1) {
      if (bVar2) {
        if ((lVar14 < lVar13) || ((iVar11 < (int)uVar10 && (lVar13 == lVar14)))) {
          puVar4 = (undefined4 *)FUN_000113b0();
          *puVar4 = 0x22;
          lVar14 = CONCAT44(DAT_0001043c,DAT_00010438);
          iVar6 = -1;
        }
        else {
          lVar14 = FUN_000097ac((int)lVar14,uVar5,param_3,param_3 >> 0x1f);
          lVar14 = lVar14 - (int)uVar10;
LAB_000103c0:
          iVar6 = 1;
        }
      }
      else {
        if ((lVar14 <= lVar13) && (((int)uVar10 <= iVar11 || (lVar13 != lVar14)))) {
          lVar14 = FUN_000097ac((int)lVar14,uVar5,param_3,param_3 >> 0x1f);
          lVar14 = lVar14 + (int)uVar10;
          goto LAB_000103c0;
        }
        puVar4 = (undefined4 *)FUN_000113b0();
        *puVar4 = 0x22;
        lVar14 = CONCAT44(DAT_00010434,DAT_00010430);
        iVar6 = -1;
      }
    }
    uVar12 = (uint)*pbVar9;
    pbVar9 = pbVar9 + 1;
  } while( true );
}



/* Function: FUN_00010458 @ 00010458 */

byte * FUN_00010458(byte *param_1,uint param_2,int param_3)

{
  byte *pbVar1;
  
  pbVar1 = param_1 + param_3;
  while( true ) {
    if (pbVar1 <= param_1) {
      return (byte *)0x0;
    }
    if (*param_1 == param_2) {
      return param_1;
    }
    if (pbVar1 <= param_1 + 1) {
      return (byte *)0x0;
    }
    if (param_1[1] == param_2) {
      return param_1 + 1;
    }
    if (pbVar1 <= param_1 + 2) {
      return (byte *)0x0;
    }
    if (param_1[2] == param_2) {
      return param_1 + 2;
    }
    if (pbVar1 <= param_1 + 3) {
      return (byte *)0x0;
    }
    if (param_1[3] == param_2) break;
    param_1 = param_1 + 4;
  }
  return param_1 + 3;
}



/* Function: FUN_00010498 @ 00010498 */

int FUN_00010498(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 != 0) {
    iVar1 = 0;
    do {
      uVar3 = (uint)*(byte *)(DAT_000104c4 + 0x104a6 + (uint)*(byte *)(param_1 + iVar1));
      uVar2 = (uint)*(byte *)(DAT_000104c4 + 0x104a6 + (uint)*(byte *)(param_2 + iVar1));
      if (uVar3 != uVar2) {
        return uVar3 - uVar2;
      }
    } while ((*(byte *)(param_1 + iVar1) != 0) && (iVar1 = iVar1 + 1, param_3 != iVar1));
  }
  return 0;
}



/* Function: FUN_000104c8 @ 000104c8 */

byte * FUN_000104c8(byte *param_1,uint param_2)

{
  while( true ) {
    if (*param_1 == param_2) {
      return param_1;
    }
    if (*param_1 == 0) break;
    param_1 = param_1 + 1;
  }
  return (byte *)0x0;
}



/* Function: FUN_000104ec @ 000104ec */

int FUN_000104ec(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_00010500 + 0x104f8;
  FUN_0001056c(param_1,iVar1,0x100);
  return iVar1;
}



/* Function: FUN_00010504 @ 00010504 */

undefined4 FUN_00010504(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  char extraout_r1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  bVar6 = param_1 < 0;
  if (bVar6) {
    param_1 = -param_1;
  }
  uVar5 = (uint)bVar6;
  iVar3 = 0;
  iVar1 = param_1;
  do {
    iVar1 = FUN_00008ba0(iVar1,10);
    iVar3 = iVar3 + 1;
  } while (iVar1 != 0);
  uVar2 = 0x22;
  uVar4 = iVar3 + param_3 + uVar5;
  if (uVar4 < param_4) {
    *(undefined1 *)(param_2 + uVar4) = 0;
    iVar1 = uVar4 - 1;
    do {
      FUN_00008c4c(param_1,10);
      *(char *)(param_2 + iVar1) = extraout_r1 + '0';
      iVar1 = iVar1 + -1;
      param_1 = FUN_00008ba0(param_1,10);
    } while (param_1 != 0);
    uVar2 = 0;
    if (uVar5 != 0) {
      *(undefined1 *)(param_2 + iVar1) = 0x2d;
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* Function: FUN_0001056c @ 0001056c */

undefined4 FUN_0001056c(int param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  
  FUN_000113b0();
  piVar1 = (int *)(DAT_000105c8 + 0x10580);
  do {
    piVar3 = piVar1;
    if (*piVar3 == 0) goto LAB_000105a2;
    piVar1 = piVar3 + 2;
  } while (*piVar3 != param_1);
  if (piVar3[1] == 0) {
LAB_000105a2:
    uVar2 = FUN_000105d0(param_2,DAT_000105cc + 0x105ac,param_3);
    if (uVar2 < param_3) {
      FUN_00010504(param_1,param_2,uVar2,param_3);
      return 0;
    }
  }
  else {
    uVar2 = FUN_000105d0(param_2,piVar3[1],param_3);
    if (uVar2 < param_3) {
      return 0;
    }
  }
  return 0x22;
}



/* Function: FUN_000105d0 @ 000105d0 */

char * FUN_000105d0(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  pcVar2 = param_2;
  if (param_3 == 0) {
LAB_000105f6:
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  else {
    iVar3 = 0;
    iVar4 = param_3;
    do {
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        *(undefined1 *)(param_1 + iVar3) = 0;
        pcVar2 = param_2 + iVar3;
        goto LAB_000105f6;
      }
      cVar1 = param_2[iVar3];
      *(char *)(param_1 + iVar3) = cVar1;
      iVar3 = iVar3 + 1;
    } while (cVar1 != '\0');
    pcVar2 = param_2 + (param_3 - iVar4);
  }
  return pcVar2 + ~(uint)param_2;
}



/* Function: FUN_0001060c @ 0001060c */

char * FUN_0001060c(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = (char *)*param_1;
  pcVar2 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    return (char *)0x0;
  }
  do {
    pcVar3 = pcVar2;
    pcVar2 = pcVar3 + 1;
    pcVar5 = param_2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      if (cVar1 == *pcVar3) {
        if (*pcVar3 == '\0') {
          pcVar2 = (char *)0x0;
        }
        else {
          *pcVar3 = '\0';
        }
        *param_1 = pcVar2;
        return pcVar4;
      }
    } while (cVar1 != '\0');
  } while( true );
}



/* Function: FUN_00010644 @ 00010644 */

undefined4 FUN_00010644(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000113b0();
  *puVar1 = param_1;
  return 0xffffffff;
}



/* Function: FUN_00010664 @ 00010664 */

void FUN_00010664(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_72 [6];
  undefined1 auStack_6c [80];
  int local_1c;
  
  iVar4 = DAT_000106ec + 0x10670;
  local_1c = **(int **)(iVar4 + DAT_000106f0);
  iVar1 = FUN_00011704(auStack_6c,0x50,DAT_000106f4 + 0x10682,param_1);
  iVar2 = FUN_0000bba4(auStack_6c,DAT_000106f8);
  if (iVar2 < 0) {
    auStack_6c[iVar1 + -6] = 0;
    iVar2 = FUN_000086d0(auStack_6c,DAT_000106fc);
    if (-1 < iVar2) {
      auStack_6c[iVar1 + -6] = 0x2f;
      iVar2 = FUN_0000bba4(auStack_6c,DAT_000106f8);
      if (-1 < iVar2) goto LAB_000106b4;
    }
  }
  else {
LAB_000106b4:
    FUN_000085f0(iVar2,DAT_00010700 + 0x106be,2);
    iVar1 = FUN_00008150(iVar2);
    iVar2 = 0;
    if (iVar1 == 0) goto LAB_000106d6;
  }
  piVar3 = (int *)FUN_000113b0(iVar2);
  iVar2 = -*piVar3;
LAB_000106d6:
  if (local_1c != **(int **)(iVar4 + DAT_000106f0)) {
    FUN_000107d0(iVar2);
  }
  return;
}



/* Function: FUN_00010738 @ 00010738 */

void FUN_00010738(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_30 [28];
  
  iVar1 = DAT_000107b8;
  iVar2 = *param_1;
  uVar3 = FUN_00008790();
  FUN_00010c7c(auStack_30);
  iVar6 = (uVar3 & 0xfffff000) + DAT_000107bc;
  FUN_00010cac(auStack_30,iVar6,0x20000);
  uVar4 = FUN_000085d0();
  iVar7 = DAT_000107c0;
  iVar8 = DAT_000107c0 + 0x1077e;
  FUN_00011174(iVar8,uVar4,auStack_30,iVar6);
  FUN_00010dbc(iVar7 + 0x107ba,iVar8);
  puVar5 = (undefined4 *)FUN_000113b0();
  *puVar5 = 0;
  iVar7 = param_1[1];
  if (iVar7 == 0) {
    iVar7 = DAT_000107c4 + 0x107a4;
  }
  puVar5 = *(undefined4 **)(iVar1 + 0x1079c + DAT_000107cc);
  **(int **)(iVar1 + 0x1079c + DAT_000107c8) = iVar7;
  *puVar5 = param_1 + iVar2 + 2;
  FUN_00010a90();
  return;
}



/* Function: FUN_000107d0 @ 000107d0 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_000107d0(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  iVar2 = DAT_00010864;
  puVar5 = &stack0xfffffff8 + DAT_00010864;
  puVar6 = &stack0xfffffff8 + DAT_00010864;
  *(undefined4 *)(&stack0xfffffff8 + DAT_00010868 + DAT_00010864) =
       **(undefined4 **)(iRam0001085c + 0x107dc + DAT_00010860);
  puVar1 = &stack0x00000008 + DAT_00010864;
  FUN_000084a8(puVar1,0xffffffff,4);
  *(undefined4 *)(&stack0x00000008 + iVar2) = 0xffffffdf;
  FUN_00008730(0,puVar1,0);
  puVar1 = &stack0x0000000c + iVar2;
  iVar3 = FUN_000086f0(DAT_0001086c + 0x1080e,puVar1,DAT_00010870);
  if (iVar3 == -1) {
    FUN_000105d0(puVar1,DAT_00010874 + 0x10820,0x1000);
  }
  else {
    puVar1[iVar3] = 0;
  }
  FUN_000118e8(7,&stack0x0000000c + iVar2,DAT_00010878 + 0x10834);
  FUN_000084a8(puVar5,0,0x10);
  FUN_00008710(6,puVar6,0);
  uVar4 = FUN_00008650();
  FUN_00008880(uVar4,6);
  FUN_00008570(0x7f);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: FUN_0001087c @ 0001087c */

void FUN_0001087c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar1 = DAT_000108c4;
  iVar2 = FUN_0000bba4(DAT_000108c0 + 0x10888,0);
  if (iVar2 != -1) {
    iVar3 = FUN_00008130(iVar2,*(undefined4 *)(iVar1 + 0x1088e + DAT_000108c8),4);
    FUN_00008150(iVar2);
    if (iVar3 == 4) {
      return;
    }
  }
  puVar4 = *(undefined1 **)(iVar1 + 0x1088e + DAT_000108c8);
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 10;
  puVar4[3] = 0xff;
  return;
}



/* Function: FUN_000108cc @ 000108cc */

void FUN_000108cc(void)

{
  FUN_000113dc();
  return;
}



/* Function: FUN_000108d4 @ 000108d4 */

int FUN_000108d4(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = DAT_00010934 + 0x108de;
  FUN_00011110(*(undefined4 *)(iVar2 + DAT_00010938),DAT_0001093c + 0x108e4);
  puVar3 = *(undefined4 **)(iVar2 + DAT_00010940);
  iVar2 = FUN_00010d28(*puVar3);
  if (iVar2 == 0) {
    iVar2 = FUN_000113f8(1,0x70);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)FUN_000113b0();
      *puVar3 = 0xc;
    }
    else {
      *(int *)(iVar2 + 0x24) = iVar2 + 0x28;
      iVar1 = FUN_00011300(*puVar3,iVar2);
      if (iVar1 != 0) {
        FUN_000108cc(iVar2);
        puVar3 = (undefined4 *)FUN_000113b0();
        *puVar3 = 0xc;
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



/* Function: FUN_00010944 @ 00010944 */

void FUN_00010944(void)

{
  FUN_0001124c(*(undefined4 *)(DAT_00010958 + 0x10950 + DAT_0001095c),DAT_00010960 + 0x10954);
  return;
}



/* Function: FUN_00010964 @ 00010964 */

undefined4 * FUN_00010964(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pcVar3 = (code *)(DAT_000109b0 + 0x10972);
  iVar1 = DAT_000109b0 + 2;
  do {
    uVar4 = *(undefined4 *)pcVar3;
    iVar2 = FUN_00010b44(uVar4,param_2);
    if (iVar2 == 0) {
      uVar5 = *(undefined4 *)(pcVar3 + 4);
      *param_1 = uVar4;
      iVar1 = DAT_000109b4;
      param_1[2] = uVar5;
      iVar2 = DAT_000109b8;
      param_1[3] = *(undefined4 *)(pcVar3 + 4);
      param_1[4] = iVar2 + 0x1099a;
      param_1[5] = iVar1 + 0x10996;
      return param_1;
    }
    pcVar3 = pcVar3 + 8;
  } while (pcVar3 != FUN_00010a90 + iVar1);
  return (undefined4 *)0x0;
}



/* Function: FUN_000109bc @ 000109bc */

uint FUN_000109bc(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *local_c;
  
  iVar1 = FUN_000088a0(param_1,DAT_00010a04 + 0x109c8,4);
  if ((((iVar1 == 0) && (*(byte *)(param_1 + 4) - 0x30 < 10)) &&
      (iVar1 = FUN_0001175c(param_1 + 4,&local_c,10), *local_c == '\0')) &&
     (DAT_00010a08 - 1U < (uint)(iVar1 + DAT_00010a08))) {
    return iVar1 + DAT_00010a08;
  }
  puVar2 = (undefined4 *)FUN_000113b0();
  *puVar2 = 2;
  return 0;
}



/* Function: FUN_00010a0c @ 00010a0c */

int * FUN_00010a0c(uint param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (DAT_00010a50 < param_1) {
    FUN_00011704(param_2 + 0xc,0x20,DAT_00010a54 + 0x10a30,param_1 + DAT_00010a58);
    iVar2 = DAT_00010a60;
    iVar1 = DAT_00010a5c;
    *param_2 = (int)(param_2 + 0xc);
    param_2[4] = iVar1 + 0x10a42;
    param_2[5] = iVar2 + 0x10a44;
    param_2[2] = param_1;
    param_2[3] = param_1;
  }
  else {
    puVar3 = (undefined4 *)FUN_000113b0();
    *puVar3 = 2;
    param_2 = (int *)0x0;
  }
  return param_2;
}



/* Function: FUN_00010a64 @ 00010a64 */

int FUN_00010a64(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = FUN_000108d4();
  iVar4 = 0;
  if ((iVar1 != 0) && (iVar2 = FUN_00010964(iVar1,param_1), iVar4 = iVar1, iVar2 == 0)) {
    uVar3 = FUN_000109bc(param_1);
    iVar4 = FUN_00010a0c(uVar3,iVar1);
  }
  return iVar4;
}



/* Function: FUN_00010a90 @ 00010a90 */

undefined4 FUN_00010a90(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(DAT_00010b0c + 0x10a9c + DAT_00010b10);
  uVar1 = 0;
  if (*piVar4 == DAT_00010b14 + 0x10aa6) {
    iVar2 = FUN_0000de14(DAT_00010b18 + 0x10aae);
    if (iVar2 != 0) {
      uVar1 = FUN_0000dd78(iVar2);
      iVar2 = FUN_000104c8(iVar2,0x2c);
      if (iVar2 != 0) {
        uVar3 = FUN_0000dd78(iVar2 + 1);
        iVar2 = FUN_0001155c(0,uVar3,1,1,uVar1,0);
        if (iVar2 != -1) {
          if ((*(int *)(iVar2 + 8) == DAT_00010b1c) && (*(int *)(iVar2 + 0xc) == DAT_00010b20)) {
            *piVar4 = iVar2;
            return 0;
          }
          FUN_00008670(iVar2,uVar3);
        }
      }
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* Function: FUN_00010b24 @ 00010b24 */

void FUN_00010b24(void)

{
  FUN_00010e9c(DAT_00010b30 + 0x10b2c);
  return;
}



/* Function: FUN_00010b34 @ 00010b34 */

void FUN_00010b34(void)

{
  FUN_00010f94(DAT_00010b40 + 0x10b3c);
  return;
}



/* Function: FUN_00010b44 @ 00010b44 */

int FUN_00010b44(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = (uint)*(byte *)(param_1 + iVar2);
    if (uVar1 != *(byte *)(param_2 + iVar2)) {
      return uVar1 - *(byte *)(param_2 + iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (uVar1 != 0);
  return 0;
}



/* Function: FUN_00010b60 @ 00010b60 */

int FUN_00010b60(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    iVar1 = 0;
    do {
      uVar2 = (uint)*(byte *)(param_1 + iVar1);
      if (uVar2 != *(byte *)(param_2 + iVar1)) {
        return uVar2 - *(byte *)(param_2 + iVar1);
      }
    } while ((uVar2 != 0) && (iVar1 = iVar1 + 1, param_3 != iVar1));
  }
  return 0;
}



/* Function: FUN_00010b84 @ 00010b84 */

void FUN_00010b84(uint param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if ((param_2 != param_1) && (param_3 != 0)) {
    if (param_2 < param_1) {
      if (((param_2 | param_1) & 3) != 0) {
        uVar2 = param_3;
        if ((((param_2 ^ param_1) & 3) == 0) && (3 < param_3)) {
          uVar2 = 4 - (param_1 & 3);
        }
        param_3 = param_3 - uVar2;
        uVar4 = 0;
        do {
          *(undefined1 *)(param_2 + uVar4) = *(undefined1 *)(param_1 + uVar4);
          uVar4 = uVar4 + 1;
        } while (uVar2 != uVar4);
        param_2 = param_2 + uVar2;
        param_1 = param_1 + uVar2;
      }
      uVar2 = param_3 >> 2;
      if (uVar2 != 0) {
        iVar5 = 0;
        uVar4 = uVar2;
        do {
          uVar4 = uVar4 - 1;
          *(undefined4 *)(param_2 + iVar5) = *(undefined4 *)(param_1 + iVar5);
          iVar5 = iVar5 + 4;
        } while (uVar4 != 0);
        param_1 = param_1 + uVar2 * 4;
        param_2 = param_2 + uVar2 * 4;
      }
      if ((param_3 & 3) != 0) {
        uVar2 = 0;
        do {
          *(undefined1 *)(param_2 + uVar2) = *(undefined1 *)(param_1 + uVar2);
          uVar2 = uVar2 + 1;
        } while ((param_3 & 3) != uVar2);
      }
    }
    else {
      puVar3 = (undefined4 *)(param_2 + param_3);
      puVar1 = (undefined4 *)(param_1 + param_3);
      if ((((uint)puVar3 | (uint)puVar1) & 3) != 0) {
        uVar2 = param_3;
        if (((((uint)puVar3 ^ (uint)puVar1) & 3) == 0) && (4 < param_3)) {
          uVar2 = (uint)puVar1 & 3;
        }
        param_3 = param_3 - uVar2;
        puVar3 = (undefined4 *)((int)puVar3 + -uVar2);
        puVar1 = (undefined4 *)((int)puVar1 + -uVar2);
        do {
          uVar2 = uVar2 - 1;
          *(undefined1 *)((int)puVar3 + uVar2) = *(undefined1 *)((int)puVar1 + uVar2);
        } while (uVar2 != 0);
      }
      uVar4 = param_3 >> 2;
      puVar6 = puVar3;
      puVar7 = puVar1;
      uVar2 = uVar4;
      if (uVar4 != 0) {
        do {
          uVar2 = uVar2 - 1;
          puVar6[-1] = puVar7[-1];
          puVar6 = puVar6 + -1;
          puVar7 = puVar7 + -1;
        } while (uVar2 != 0);
        puVar1 = puVar1 + -uVar4;
        puVar3 = puVar3 + -uVar4;
      }
      param_3 = param_3 & 3;
      if (param_3 != 0) {
        iVar5 = -param_3;
        do {
          param_3 = param_3 - 1;
          *(undefined1 *)((int)puVar3 + param_3 + iVar5) =
               *(undefined1 *)((int)puVar1 + param_3 + iVar5);
        } while (param_3 != 0);
      }
    }
  }
  return;
}



/* Function: FUN_00010c64 @ 00010c64 */

undefined4 FUN_00010c64(void)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_ffff0fe0)();
  return *(undefined4 *)(iVar1 + 4);
}



/* Function: FUN_00010c7c @ 00010c7c */

undefined4 FUN_00010c7c(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar1 = DAT_00010ca8;
  uVar2 = *(undefined4 *)(DAT_00010ca8 + 0x10c94);
  uVar3 = *(undefined4 *)(DAT_00010ca8 + 0x10c98);
  uVar4 = *(undefined4 *)(DAT_00010ca8 + 0x10c9c);
  puVar5 = (undefined4 *)(DAT_00010ca8 + 0x10ca0);
  *param_1 = *(undefined4 *)(DAT_00010ca8 + 0x10c90);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  uVar2 = *(undefined4 *)(iVar1 + 0x10ca4);
  param_1[4] = *puVar5;
  param_1[5] = uVar2;
  return 0;
}



/* Function: FUN_00010cac @ 00010cac */

undefined4 FUN_00010cac(int param_1,uint param_2,uint param_3)

{
  if ((0x1fff < param_3 && (param_3 & 0xfff) == 0) && ((param_2 & 0xfff) == 0)) {
    *(uint *)(param_1 + 8) = param_3;
    *(uint *)(param_1 + 4) = param_2;
    return 0;
  }
  return 0x16;
}



/* Function: FUN_00010ce8 @ 00010ce8 */

undefined4 FUN_00010ce8(uint *param_1,int *param_2)

{
  if (param_1 == (uint *)0x0) {
    return 0x16;
  }
  *param_1 = 0;
  if ((param_2 != (int *)0x0) && (*param_2 == 1)) {
    *param_1 = *param_1 | 1;
    return 0;
  }
  return 0;
}



/* Function: FUN_00010d28 @ 00010d28 */

undefined4 FUN_00010d28(int param_1)

{
  int iVar1;
  
  if (0x3c < param_1 - 3U) {
    return 0;
  }
  iVar1 = (*(code *)&SUB_ffff0fe0)();
  return *(undefined4 *)(iVar1 + param_1 * 4);
}



/* Function: FUN_00010d58 @ 00010d58 */

undefined4 FUN_00010d58(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == (uint *)0x0) {
    return 0x16;
  }
  if (param_2 != (uint *)0x0) {
    uVar1 = *param_2 & 0xf;
    uVar2 = 0;
    if ((*param_2 & 0x10) != 0) {
      uVar2 = 0x2000;
    }
    if (uVar1 == 1) {
      uVar2 = uVar2 | 0x4000;
    }
    else if (uVar1 == 2) {
      uVar2 = uVar2 | 0x8000;
    }
    else if (uVar1 != 0) {
      return 0x16;
    }
    *param_1 = uVar2;
    return 0;
  }
  *param_1 = 0;
  return 0;
}



/* Function: FUN_00010dbc @ 00010dbc */

void FUN_00010dbc(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 4) = param_2;
  *(int *)(param_2 + 0x38) = param_1;
  *(int *)param_1 = param_1;
  iVar1 = 2;
  do {
    *(undefined4 *)(param_1 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x40);
  software_interrupt(0);
  if (-1 < param_1) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00014d64)();
  return;
}



/* Function: FUN_00010de4 @ 00010de4 */

void FUN_00010de4(void)

{
  software_interrupt(0);
  return;
}



/* Function: FUN_00010df4 @ 00010df4 */

void FUN_00010df4(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_1 & 0x2000;
  iVar1 = FUN_000087f0(uVar3,uVar3 | 1,param_1);
  if (iVar1 != 0) {
    while (uVar2 = FUN_00008820(uVar3 | 2,param_1), uVar2 != uVar3) {
      FUN_00010de4(param_1,uVar3,uVar3 | 2,0);
    }
  }
  return;
}



/* Function: FUN_00010e50 @ 00010e50 */

void FUN_00010e50(void)

{
  software_interrupt(0);
  return;
}



/* Function: FUN_00010e60 @ 00010e60 */

void FUN_00010e60(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  uVar1 = FUN_00008798();
  uVar2 = uVar2 & 0x2000;
  if (uVar1 != (uVar2 | 1)) {
    *param_1 = uVar2;
    FUN_00010e50(param_1,uVar2,1);
    return;
  }
  return;
}



/* Function: FUN_00010e9c @ 00010e9c */

undefined4 FUN_00010e9c(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (uint *)0x0) {
    return 0x16;
  }
  uVar2 = *param_1;
  uVar3 = *param_1;
  if ((uVar2 & 0xc000) == 0) {
    uVar3 = *param_1;
    uVar2 = FUN_00008798();
    uVar3 = uVar3 & 0x2000;
    if (uVar2 != (uVar3 | 1)) {
      *param_1 = uVar3;
      FUN_00010e50(param_1,uVar3,1);
      return 0;
    }
  }
  else {
    iVar1 = FUN_00010c64();
    if (*(uint *)(iVar1 + 0x20) != *param_1 >> 0x10) {
      return 1;
    }
    iVar1 = DAT_00010f90 + 0x10f24;
    FUN_00010df4(iVar1);
    uVar4 = *param_1;
    if ((uVar4 & 0x1ffc) != 0) {
      *param_1 = uVar4 - 4;
      FUN_00010e60(iVar1);
      return 0;
    }
    *param_1 = uVar3 & 0x2000 | uVar2 & 0xc000;
    FUN_00010e60(iVar1);
    if ((uVar4 & 3) == 2) {
      FUN_00010e50(param_1,uVar3 & 0x2000,1);
      return 0;
    }
  }
  return 0;
}



/* Function: FUN_00010f94 @ 00010f94 */

undefined4 FUN_00010f94(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == (uint *)0x0) {
    return 0x16;
  }
  uVar3 = *param_1;
  uVar2 = *param_1 & 0xc000;
  if (uVar2 == 0) {
    uVar2 = *param_1 & 0x2000;
    iVar1 = FUN_000087f0(uVar2,uVar2 | 1,param_1);
    if (iVar1 != 0) {
      while (uVar3 = FUN_00008820(uVar2 | 2,param_1), uVar2 != uVar3) {
        FUN_00010de4(param_1,uVar2,uVar2 | 2,0);
      }
    }
    return 0;
  }
  iVar1 = FUN_00010c64();
  uVar4 = *(uint *)(iVar1 + 0x20);
  if (uVar4 == *param_1 >> 0x10) {
    if (uVar2 == 0x8000) {
      return 0x23;
    }
    iVar1 = DAT_0001110c + 0x110d0;
    FUN_00010df4(iVar1);
    *param_1 = *param_1 + 4 & 0x1ffc | *param_1 & 0xffffe003;
    FUN_00010e60(iVar1);
    return 0;
  }
  uVar2 = uVar3 & 0x2000 | uVar2;
  iVar1 = DAT_00011108 + 0x11038;
  uVar5 = 1;
  do {
    FUN_00010df4(iVar1);
    uVar6 = *param_1;
    if (uVar6 == uVar2) {
      *param_1 = uVar2 | uVar4 << 0x10 | uVar5;
      FUN_00010e60(iVar1);
      return 0;
    }
    if ((uVar6 & 3) == 1) {
      uVar6 = uVar6 ^ 3;
      *param_1 = uVar6;
      FUN_00010e60(iVar1);
      if (uVar2 == uVar6) {
        return 0;
      }
    }
    else {
      FUN_00010e60(iVar1);
    }
    FUN_00010de4(param_1,uVar3 & 0x2000,uVar6,0);
    uVar5 = 2;
  } while( true );
}



/* Function: FUN_00011110 @ 00011110 */

undefined4 FUN_00011110(int *param_1,code *param_2)

{
  if (*param_1 != 0) {
    return 0;
  }
  FUN_00010f94(DAT_0001116c + 0x1113c);
  if (*param_1 == 0) {
    (*param_2)();
    *param_1 = -1;
  }
  FUN_00010e9c(DAT_00011170 + 0x11154);
  return 0;
}



/* Function: FUN_00011174 @ 00011174 */

void FUN_00011174(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_3 == (int *)0x0) {
    param_3 = (int *)((int)&DAT_00011240 + DAT_00011248);
  }
  iVar1 = param_3[1];
  iVar2 = param_3[2];
  iVar3 = param_3[3];
  param_1[2] = *param_3;
  param_1[3] = iVar1;
  param_1[4] = iVar2;
  param_1[5] = iVar3;
  iVar1 = param_3[4];
  iVar2 = param_3[5];
  param_1[8] = param_2;
  param_1[6] = iVar1;
  param_1[7] = iVar2;
  param_1[3] = param_4;
  if (param_1[6] != 0) {
    FUN_00008750(param_2);
  }
  iVar1 = DAT_00011240;
  FUN_00010ce8(param_1 + 9,0);
  param_1[0xd] = 0;
  param_1[10] = 0;
  FUN_00010f94(iVar1 + 0x112e4);
  iVar2 = *(int *)(iVar1 + 0x112e8);
  piVar4 = (int *)(iVar1 + 0x112e8);
  param_1[1] = (int)piVar4;
  iVar1 = DAT_00011244;
  if (iVar2 != 0) {
    *(int **)(iVar2 + 4) = param_1;
    piVar4 = (int *)param_1[1];
    iVar1 = DAT_00011244;
  }
  DAT_00011244 = iVar1;
  *param_1 = iVar2;
  *piVar4 = (int)param_1;
  FUN_00010e9c(iVar1 + 0x1131c);
  return;
}



/* Function: FUN_0001124c @ 0001124c */

undefined4 FUN_0001124c(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar3 = DAT_000112f4;
  FUN_00010f94(DAT_000112f4 + 0x11260);
  iVar2 = DAT_000112f8;
  if (*(int *)(iVar3 + 0x11264) == 0) {
    *(undefined4 *)(iVar3 + 0x11264) = 1;
    *(undefined4 *)(iVar3 + 0x11268) = 0x1f;
  }
  uVar5 = 3;
  do {
    uVar1 = 1 << (uVar5 & 0x1f);
    iVar3 = iVar2 + 0x11290 + ((int)uVar5 >> 5) * 4;
    uVar4 = *(uint *)(iVar3 + 0xc);
    if ((uVar1 & uVar4) == 0) {
      *(uint *)(iVar3 + 0xc) = uVar1 | uVar4;
      *(undefined4 *)(iVar2 + 0x11290 + uVar5 * 4 + 0x14) = param_2;
      *param_1 = uVar5;
      uVar6 = 0;
      goto LAB_000112d4;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0x40);
  uVar6 = 0xc;
LAB_000112d4:
  FUN_00010e9c(DAT_000112fc + 0x112e4);
  return uVar6;
}



/* Function: FUN_00011300 @ 00011300 */

undefined4 FUN_00011300(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = DAT_000113a4;
  if (param_1 - 3 < 0x3d) {
    FUN_00010f94(DAT_000113a4 + 0x11334);
    iVar1 = DAT_000113a8;
    if (*(int *)(iVar2 + 0x11338) == 0) {
      *(undefined4 *)(iVar2 + 0x11338) = 1;
      *(undefined4 *)(iVar2 + 0x1133c) = 0x1f;
    }
    if ((*(uint *)(iVar1 + ((int)param_1 >> 5) * 4 + 0x11360) & 1 << (param_1 & 0x1f)) == 0) {
      uVar3 = 0x16;
    }
    else {
      iVar2 = (*(code *)&SUB_ffff0fe0)();
      *(undefined4 *)(iVar2 + param_1 * 4) = param_2;
      uVar3 = 0;
    }
    FUN_00010e9c(DAT_000113ac + 0x11384);
    return uVar3;
  }
  return 0x16;
}



/* Function: FUN_000113b0 @ 000113b0 */

int FUN_000113b0(void)

{
  int iVar1;
  
  iVar1 = (*DAT_000113bc)();
  return iVar1 + 8;
}



/* Function: FUN_000113c0 @ 000113c0 */

void FUN_000113c0(void)

{
  (**(code **)**(undefined4 **)(DAT_000113d4 + 0x113ca + DAT_000113d8))();
  return;
}



/* Function: FUN_000113dc @ 000113dc */

void FUN_000113dc(void)

{
  (**(code **)(**(int **)(DAT_000113f0 + 0x113e6 + DAT_000113f4) + 4))();
  return;
}



/* Function: FUN_000113f8 @ 000113f8 */

void FUN_000113f8(void)

{
  (**(code **)(**(int **)(DAT_0001140c + 0x11402 + DAT_00011410) + 8))();
  return;
}



/* Function: FUN_00011414 @ 00011414 */

void FUN_00011414(void)

{
  (**(code **)(**(int **)(DAT_00011428 + 0x1141e + DAT_0001142c) + 0xc))();
  return;
}



/* Function: FUN_00011430 @ 00011430 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_00011430(int *param_1,undefined4 param_2,code *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int extraout_r3;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = iRam00011498 + 0x1143c;
  FUN_00010738();
  puVar2 = (undefined4 *)*param_4;
  while( true ) {
    puVar2 = puVar2 + 1;
    if ((code *)*puVar2 == (code *)0x0) break;
    (*(code *)*puVar2)();
  }
  puVar2 = (undefined4 *)param_4[3];
  while( true ) {
    puVar2 = puVar2 + 1;
    if ((code *)*puVar2 == (code *)0x0) break;
    (*(code *)*puVar2)();
  }
  puVar2 = (undefined4 *)param_4[1];
  while( true ) {
    puVar2 = puVar2 + 1;
    if ((code *)*puVar2 == (code *)0x0) break;
    (*(code *)*puVar2)();
  }
  iVar4 = *param_1;
  if (param_4[2] != 0) {
    FUN_0000dc74(*(undefined4 *)(iVar3 + DAT_0001149c),param_4[2],0);
  }
  (*param_3)(iVar4,param_1 + 1,param_1 + 1 + iVar4 + 1);
  uVar1 = FUN_0000dd84();
  *(undefined4 *)(extraout_r3 + 0x1c) = uVar1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: FUN_000114a0 @ 000114a0 */

void FUN_000114a0(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  if ((param_2 <= param_1) && (param_1 - param_2 < param_3)) {
    iVar2 = param_2 + param_3;
    iVar4 = param_1 + param_3;
    HintPreloadData(iVar2 + -1);
    HintPreloadData(iVar4 + -1);
    HintPreloadData(iVar2 + -0x21);
    HintPreloadData(iVar4 + -0x21);
    uVar3 = param_3 & 0x1f;
    iVar5 = iVar2;
    iVar6 = iVar4;
    for (uVar8 = param_3 >> 5; uVar8 != 0; uVar8 = uVar8 - 1) {
      HintPreloadData(iVar5 + -0x41);
      HintPreloadData(iVar6 + -0x41);
      iVar7 = 1;
      do {
        iVar1 = -iVar7;
        iVar7 = iVar7 + 1;
        *(undefined1 *)(iVar6 + iVar1) = *(undefined1 *)(iVar5 + iVar1);
      } while (iVar7 != 0x21);
      iVar6 = iVar6 + -0x20;
      iVar5 = iVar5 + -0x20;
    }
    iVar6 = (param_3 >> 5) * -0x20;
    iVar5 = 0;
    for (; iVar5 = iVar5 + -1, uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)(iVar4 + iVar6 + iVar5) = *(undefined1 *)(iVar2 + iVar6 + iVar5);
    }
    return;
  }
  FUN_00008170();
  return;
}



/* Function: FUN_0001155c @ 0001155c */

undefined4 FUN_0001155c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint in_stack_00000004;
  
  if ((in_stack_00000004 & 0xfff) == 0) {
    uVar2 = FUN_00008b10();
  }
  else {
    puVar1 = (undefined4 *)FUN_000113b0();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* Function: FUN_00011588 @ 00011588 */

undefined4 FUN_00011588(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((int)(short)param_1[3] << 0x1c < 0) && (iVar2 = param_1[4], iVar2 != 0)) {
    iVar3 = *param_1;
    iVar1 = 0;
    *param_1 = iVar2;
    iVar3 = iVar3 - iVar2;
    if (((int)(short)param_1[3] & 3U) == 0) {
      iVar1 = param_1[5];
    }
    param_1[2] = iVar1;
    for (; 0 < iVar3; iVar3 = iVar3 - iVar1) {
      iVar1 = (*(code *)param_1[0xb])(param_1[7],iVar2,iVar3);
      if (iVar1 < 1) {
        *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x40;
        return 0xffffffff;
      }
      iVar2 = iVar2 + iVar1;
    }
  }
  return 0;
}



/* Function: FUN_000115d4 @ 000115d4 */

undefined4 FUN_000115d4(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    uVar1 = FUN_0000bee8(*(undefined4 *)(DAT_00011604 + 0x115dc + DAT_00011608));
  }
  else if ((*(ushort *)(param_1 + 0xc) & 0x18) == 0) {
    puVar2 = (undefined4 *)FUN_000113b0();
    *puVar2 = 9;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_00011588();
  }
  return uVar1;
}



/* Function: FUN_0001160c @ 0001160c */

undefined4 FUN_0001160c(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_80 [16];
  uint local_70;
  int local_48;
  
  iVar2 = DAT_00011680 + 0x11622;
  if ((*(short *)(param_1 + 0xe) < 0) ||
     (iVar1 = FUN_00008b40((int)*(short *)(param_1 + 0xe),auStack_80), iVar1 < 0)) {
    *param_3 = 0;
  }
  else {
    *param_3 = (uint)((local_70 & 0xf000) + DAT_00011684 == 0);
    if (local_48 != 0) {
      *param_2 = local_48;
      *(int *)(param_1 + 0x4c) = local_48;
      if ((local_70 & 0xf000) != 0x8000) {
        return 0x800;
      }
      if (*(int *)(param_1 + 0x28) != *(int *)(iVar2 + DAT_00011688)) {
        return 0x800;
      }
      return 0x400;
    }
  }
  *param_2 = 0x400;
  return 0x800;
}



/* Function: FUN_0001168c @ 0001168c */

void FUN_0001168c(int *param_1)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  int local_20;
  int local_1c [2];
  
  iVar4 = DAT_000116fc + 0x11698;
  if (-1 < (int)((uint)*(ushort *)(param_1 + 3) << 0x1e)) {
    uVar1 = FUN_0001160c(param_1,local_1c,&local_20);
    iVar2 = FUN_000113c0(local_1c[0]);
    if (iVar2 != 0) {
      FUN_0000dac0(*(undefined4 *)(iVar4 + DAT_00011700));
      uVar3 = uVar1 | 0x80;
      *param_1 = iVar2;
      param_1[4] = iVar2;
      param_1[5] = local_1c[0];
      if ((local_20 != 0) && (iVar4 = FUN_00013ae4((int)*(short *)((int)param_1 + 0xe)), iVar4 != 0)
         ) {
        uVar3 = uVar1 | 0x81;
      }
      *(ushort *)(param_1 + 3) = uVar3 | *(ushort *)(param_1 + 3);
      return;
    }
    *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 2;
  }
  *param_1 = (int)param_1 + 0x43;
  param_1[4] = (int)param_1 + 0x43;
  param_1[5] = 1;
  return;
}



/* Function: FUN_00011704 @ 00011704 */

void FUN_00011704(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *local_78 [2];
  int local_70;
  undefined2 local_6c;
  undefined2 local_6a;
  undefined1 *local_68;
  int local_64;
  undefined4 *local_48;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *local_18;
  undefined1 uStack_11;
  undefined4 uStack_4;
  
  local_70 = DAT_00011758;
  if ((-1 < param_2) && (local_70 = param_2, param_2 == 0)) {
    local_70 = 1;
    param_1 = &uStack_11;
  }
  local_48 = &local_24;
  local_20 = 0;
  local_6a = 0xffff;
  local_70 = local_70 + -1;
  local_6c = 0x208;
  local_18 = &uStack_4;
  local_24 = 0;
  local_78[0] = param_1;
  local_68 = param_1;
  local_64 = local_70;
  uStack_4 = param_4;
  FUN_0000c6b0(local_78,param_3);
  *local_78[0] = 0;
  return;
}



/* Function: FUN_0001175c @ 0001175c */

uint FUN_0001175c(byte *param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int extraout_r1;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  byte *local_2c;
  
  iVar12 = DAT_0001186c + 0x1176a;
  pbVar10 = param_1;
  do {
    pbVar9 = pbVar10;
    uVar11 = (uint)*pbVar9;
    pbVar10 = pbVar9 + 1;
  } while ((*(byte *)(**(int **)(iVar12 + DAT_00011870) + uVar11 + 1) & 8) != 0);
  if (uVar11 == 0x2d) {
    uVar11 = (uint)*pbVar10;
    pbVar10 = pbVar9 + 2;
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (uVar11 == 0x2b) {
      uVar11 = (uint)*pbVar10;
      pbVar10 = pbVar9 + 2;
    }
  }
  if ((param_3 == 0x10) || (param_3 == 0)) {
    if ((uVar11 == 0x30) && ((*pbVar10 == 0x58 || (*pbVar10 == 0x78)))) {
      uVar11 = (uint)pbVar10[1];
      param_3 = 0x10;
      pbVar10 = pbVar10 + 2;
    }
    else if ((param_3 == 0) && (param_3 = 8, uVar11 != 0x30)) {
      param_3 = 10;
    }
  }
  uVar4 = FUN_00008ba0(0xffffffff,param_3);
  FUN_00008c4c(0xffffffff,param_3);
  iVar3 = DAT_00011870;
  uVar8 = 0;
  uVar5 = 0;
  do {
    uVar13 = uVar11 - 0x30;
    if (9 < uVar13) {
      bVar1 = *(byte *)(**(int **)(iVar12 + iVar3) + uVar11 + 1);
      if ((bVar1 & 3) == 0) {
LAB_00011846:
        if ((0 < (int)uVar8) && (bVar2)) {
          uVar5 = -uVar5;
        }
        if (param_2 != (undefined4 *)0x0) {
          local_2c = param_1;
          if (uVar8 != 0) {
            local_2c = pbVar10 + -1;
          }
          *param_2 = local_2c;
        }
        return uVar5;
      }
      iVar7 = 0x37;
      if (-1 < (int)((uint)bVar1 << 0x1f)) {
        iVar7 = 0x57;
      }
      uVar13 = uVar11 - iVar7;
    }
    if (param_3 <= (int)uVar13) goto LAB_00011846;
    if (uVar8 != 0xffffffff) {
      if ((uVar4 < uVar5) || ((extraout_r1 < (int)uVar13 && (uVar5 == uVar4)))) {
        puVar6 = (undefined4 *)FUN_000113b0();
        *puVar6 = 0x22;
        uVar5 = 0xffffffff;
        uVar8 = uVar5;
      }
      else {
        uVar8 = 1;
        uVar5 = uVar13 + uVar5 * param_3;
      }
    }
    uVar11 = (uint)*pbVar10;
    pbVar10 = pbVar10 + 1;
  } while( true );
}



/* Function: FUN_00011880 @ 00011880 */

void FUN_00011880(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  if (param_2 == 0) {
    param_2 = DAT_000118dc + 0x11894;
  }
  local_34 = param_1;
  iVar1 = FUN_00010b44(param_2,DAT_000118e0 + 0x1189c);
  iVar1 = 2 - (uint)(iVar1 != 0);
  local_30 = &local_34;
  local_2c = 1;
  local_28 = param_2;
  local_24 = FUN_0000b7e0(param_2);
  local_24 = local_24 + 1;
  local_20 = param_3;
  local_1c = FUN_0000b7e0(param_3);
  local_1c = local_1c + 1;
  (**(code **)(iVar1 * 0xc + DAT_000118e4 + 0x118d2))(iVar1,&local_30);
  return;
}



/* Function: FUN_000118e8 @ 000118e8 */

void FUN_000118e8(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar2 = DAT_00011948;
  piVar4 = *(int **)(DAT_00011940 + 0x118f6 + DAT_00011944);
  uVar3 = *(undefined4 *)(&stack0x00000404 + DAT_00011948);
  *(int *)(&stack0xffffffe4 + DAT_0001194c + DAT_00011948) = *piVar4;
  puVar1 = &stack0xffffffe8 + DAT_00011948;
  *(undefined1 **)(&stack0xffffffe4 + DAT_00011948) = &stack0x00000408 + DAT_00011948;
  FUN_00013b78(puVar1,0x400,uVar3);
  FUN_00011880(param_1,param_2,puVar1);
  if (*(int *)(&stack0xffffffe4 + DAT_0001194c + iVar2) != *piVar4) {
    FUN_000107d0();
  }
  return;
}



/* Function: FUN_000119cc @ 000119cc */

int FUN_000119cc(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = DAT_000119fc + param_1 * 0xc;
  do {
    iVar1 = FUN_000086b0(*(undefined4 *)(iVar3 + 0x119de),param_2,3);
    if (-1 < iVar1) {
      return iVar1;
    }
    piVar2 = (int *)FUN_000113b0();
  } while (*piVar2 == 4);
  return iVar1;
}



/* Function: FUN_00011a00 @ 00011a00 */

undefined4 FUN_00011a00(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_00011a6c;
  if (*(int *)(DAT_00011a6c + 0x11a58) == 0) {
    *(undefined4 *)(DAT_00011a6c + 0x11a60) = 0x10000;
    *(undefined4 *)(iVar1 + 0x11a64) = 0x200000;
    *(undefined4 *)(iVar1 + 0x11a68) = 3;
    FUN_00010f94((int)&DAT_00011a6c + iVar1);
    iVar2 = DAT_00011a70;
    if (*(int *)(iVar1 + 0x11a54) == 0) {
      *(undefined4 *)(iVar1 + 0x11a54) = DAT_00011a74;
      FUN_00010d58(iVar2 + 0x11bec,0);
      *(undefined4 *)(iVar2 + 0x11be8) = *(undefined4 *)(iVar1 + 0x11a68);
    }
    iVar1 = DAT_00011a78;
    FUN_00010e9c(DAT_00011a78 + 0x11ab0);
    uVar3 = FUN_00013df8(0x28);
    *(uint *)(iVar1 + 0x11a9c) = uVar3;
    *(uint *)(iVar1 + 0x11aa0) = uVar3;
    if ((uVar3 - 1 & uVar3) != 0) {
      FUN_00013a24();
    }
  }
  return 0;
}



/* Function: FUN_00011a7c @ 00011a7c */

uint * FUN_00011a7c(uint param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = *(int *)(DAT_00011b14 + 0x11ada) + 0x1f + param_1 & -*(int *)(DAT_00011b14 + 0x11ada);
  if ((param_1 < uVar7) && (uVar3 = FUN_0001155c(0,uVar7,3,0x22,0xffffffff,0), uVar3 != 0xffffffff))
  {
    uVar6 = 0;
    uVar4 = uVar3 + 8 & 7;
    if (uVar4 != 0) {
      uVar6 = 8 - uVar4 & 7;
    }
    uVar4 = (uVar7 - 0x10) - uVar6;
    puVar5 = (uint *)(uVar3 + uVar6);
    *puVar5 = uVar6 | 1;
    puVar5[1] = uVar4 | 2;
    *(undefined4 *)((int)puVar5 + uVar4 + 4) = 7;
    *(undefined4 *)((int)puVar5 + uVar4 + 8) = 0;
    if (uVar3 < *(uint *)(DAT_00011b18 + 0x11af6)) {
      *(uint *)(DAT_00011b18 + 0x11af6) = uVar3;
    }
    iVar2 = DAT_00011b1c;
    uVar7 = uVar7 + *(int *)(DAT_00011b1c + 0x11ca2);
    puVar1 = (uint *)(DAT_00011b1c + 0x11ca6);
    *(uint *)(DAT_00011b1c + 0x11ca2) = uVar7;
    if (*puVar1 < uVar7) {
      *(uint *)(iVar2 + 0x11ca6) = uVar7;
    }
    return puVar5 + 2;
  }
  return (uint *)0x0;
}



/* Function: FUN_00011b20 @ 00011b20 */

int FUN_00011b20(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  iVar4 = DAT_00011e30;
  uVar6 = 0;
  uVar7 = param_1 + 8U & 7;
  if (uVar7 != 0) {
    uVar6 = 8 - uVar7 & 7;
  }
  param_1 = param_1 + uVar6;
  uVar6 = 0;
  uVar7 = param_2 + 8U & 7;
  if (uVar7 != 0) {
    uVar6 = 8 - uVar7 & 7;
  }
  uVar6 = param_2 + uVar6;
  uVar7 = (uVar6 - param_1) - param_3;
  iVar5 = param_1 + param_3;
  puVar9 = (uint *)(DAT_00011e30 + 0x11b5a);
  *(uint *)(param_1 + 4) = param_3 | 3;
  if (uVar6 == *(uint *)(iVar4 + 0x11b72)) {
    *(int *)(iVar4 + 0x11b72) = iVar5;
    uVar7 = uVar7 + *(int *)(iVar4 + 0x11b66);
    *(uint *)(iVar4 + 0x11b66) = uVar7;
    *(uint *)(iVar5 + 4) = uVar7 | 1;
    goto LAB_00011e2a;
  }
  if (uVar6 == *(uint *)(iVar4 + 0x11b6e)) {
    *(int *)(iVar4 + 0x11b6e) = iVar5;
    uVar7 = uVar7 + *(int *)(iVar4 + 0x11b62);
    *(uint *)(iVar4 + 0x11b62) = uVar7;
    *(uint *)(iVar5 + 4) = uVar7 | 1;
    *(uint *)(iVar5 + uVar7) = uVar7;
    goto LAB_00011e2a;
  }
  uVar1 = *(uint *)(uVar6 + 4);
  if ((int)(uVar1 << 0x1e) < 0) {
LAB_00011cf4:
    uVar1 = uVar7 >> 3;
    *(uint *)(uVar6 + 4) = *(uint *)(uVar6 + 4) & 0xfffffffe;
    *(uint *)(iVar5 + 4) = uVar7 | 1;
    *(uint *)(iVar5 + uVar7) = uVar7;
    iVar4 = DAT_00011e54;
    if (uVar1 < 0x20) {
      uVar7 = 1 << (uVar1 & 0xff);
      uVar11 = *(uint *)(DAT_00011e44 + 0x11d14);
      uVar6 = DAT_00011e44 + 0x11d38 + uVar1 * 8;
      if ((uVar7 & uVar11) == 0) {
        *(uint *)(DAT_00011e44 + 0x11d14) = uVar7 | uVar11;
        uVar7 = uVar6;
      }
      else {
        uVar7 = *(uint *)(uVar6 + 8);
        if (uVar7 < *(uint *)(DAT_00011e44 + 0x11d24)) goto LAB_00011e26;
      }
      *(int *)(uVar6 + 8) = iVar5;
      *(int *)(uVar7 + 0xc) = iVar5;
      *(uint *)(iVar5 + 8) = uVar7;
      *(uint *)(iVar5 + 0xc) = uVar6;
      goto LAB_00011e2a;
    }
    uVar1 = uVar7 >> 8;
    uVar6 = 0;
    if ((uVar1 != 0) && (uVar6 = 0x1f, uVar1 <= DAT_00011e48)) {
      uVar6 = uVar1 - 0x100 >> 0x10 & 8;
      iVar3 = uVar1 << uVar6;
      uVar11 = (uint)(iVar3 + DAT_00011e4c) >> 0x10 & 4;
      iVar3 = iVar3 << uVar11;
      uVar1 = (uint)(DAT_00011e50 + iVar3) >> 0x10 & 2;
      iVar3 = (((0xe - uVar6) - uVar11) - uVar1) + ((uint)(iVar3 << uVar1) >> 0xf);
      uVar6 = (uVar7 >> (iVar3 + 7U & 0xff) & 1) + iVar3 * 2;
    }
    *(uint *)(iVar5 + 0x1c) = uVar6;
    uVar1 = *(uint *)(iVar4 + 0x11da0);
    *(undefined4 *)(iVar5 + 0x14) = 0;
    *(undefined4 *)(iVar5 + 0x10) = 0;
    uVar11 = 1 << (uVar6 & 0xff);
    if ((uVar11 & uVar1) == 0) {
      *(uint *)(iVar4 + 0x11da0) = uVar1 | uVar11;
      iVar4 = iVar4 + 0x11d9c + (uVar6 + 0x4a) * 4;
      *(int *)(iVar4 + 4) = iVar5;
      *(int *)(iVar5 + 0x18) = iVar4 + 4;
LAB_00011e02:
      *(int *)(iVar5 + 0xc) = iVar5;
      *(int *)(iVar5 + 8) = iVar5;
      goto LAB_00011e2a;
    }
    uVar1 = 0;
    if (uVar6 != 0x1f) {
      uVar1 = 0x19 - (uVar6 >> 1);
    }
    iVar3 = uVar7 << (uVar1 & 0xff);
    uVar6 = *(uint *)(iVar4 + 0x11d9c + (uVar6 + 0x4a) * 4 + 4);
    while ((*(uint *)(uVar6 + 4) & 0xfffffffc) != uVar7) {
      iVar4 = (4 - (iVar3 >> 0x1f)) * 4;
      if (*(uint *)(iVar4 + uVar6) == 0) {
        if (uVar6 + iVar4 < *(uint *)(DAT_00011e58 + 0x11e0a)) goto LAB_00011e26;
        *(int *)(iVar4 + uVar6) = iVar5;
        *(uint *)(iVar5 + 0x18) = uVar6;
        goto LAB_00011e02;
      }
      iVar3 = iVar3 << 1;
      uVar6 = *(uint *)(iVar4 + uVar6);
    }
    uVar7 = *(uint *)(uVar6 + 8);
    if ((*(uint *)(DAT_00011e5c + 0x11e20) <= uVar6) && (*(uint *)(DAT_00011e5c + 0x11e20) <= uVar7)
       ) {
      *(int *)(uVar6 + 8) = iVar5;
      *(int *)(uVar7 + 0xc) = iVar5;
      *(uint *)(iVar5 + 0xc) = uVar6;
      *(uint *)(iVar5 + 8) = uVar7;
      *(undefined4 *)(iVar5 + 0x18) = 0;
      goto LAB_00011e2a;
    }
  }
  else {
    uVar11 = uVar1 >> 3;
    if (uVar11 < 0x20) {
      uVar8 = *(uint *)(uVar6 + 8);
      uVar2 = *(uint *)(uVar6 + 0xc);
      if ((*(uint *)(uVar8 + 0xc) != uVar6) || (*(uint *)(uVar2 + 8) != uVar6)) goto LAB_00011e26;
      if (uVar8 == uVar2) {
        *puVar9 = *puVar9 & ~(1 << (uVar11 & 0xff));
      }
      else {
        uVar11 = iVar4 + 0x11b7e + uVar11 * 8;
        if (((uVar8 != uVar11) && (uVar8 < *(uint *)(iVar4 + 0x11b6a))) ||
           ((uVar2 != uVar11 && (uVar2 < *(uint *)(DAT_00011e34 + 0x11bfc))))) goto LAB_00011e26;
        *(uint *)(uVar8 + 0xc) = uVar2;
        *(uint *)(uVar2 + 8) = uVar8;
      }
      goto LAB_00011cee;
    }
    uVar11 = *(uint *)(uVar6 + 0xc);
    uVar2 = *(uint *)(uVar6 + 0x18);
    if (uVar11 == uVar6) {
      if (*(uint *)(uVar6 + 0x14) == 0) {
        puVar10 = (undefined4 *)(uVar6 + 0x10);
        uVar11 = *(uint *)(uVar6 + 0x10);
        if (*(uint *)(uVar6 + 0x10) == 0) {
          uVar11 = 0;
          goto LAB_00011c74;
        }
      }
      else {
        puVar10 = (undefined4 *)(uVar6 + 0x14);
        uVar11 = *(uint *)(uVar6 + 0x14);
      }
      while( true ) {
        while (*(uint *)(uVar11 + 0x14) != 0) {
          puVar10 = (undefined4 *)(uVar11 + 0x14);
          uVar11 = *(uint *)(uVar11 + 0x14);
        }
        if (*(uint *)(uVar11 + 0x10) == 0) break;
        puVar10 = (undefined4 *)(uVar11 + 0x10);
        uVar11 = *(uint *)(uVar11 + 0x10);
      }
      if (*(undefined4 **)(DAT_00011e38 + 0x11c72) <= puVar10) {
        *puVar10 = 0;
        goto LAB_00011c74;
      }
    }
    else {
      uVar8 = *(uint *)(uVar6 + 8);
      if (((*(uint *)(uVar8 + 0xc) == uVar6) && (*(uint *)(uVar11 + 8) == uVar6)) &&
         (*(uint *)(iVar4 + 0x11b6a) <= uVar8)) {
        *(uint *)(uVar8 + 0xc) = uVar11;
        *(uint *)(uVar11 + 8) = uVar8;
LAB_00011c74:
        iVar4 = DAT_00011e3c;
        if (uVar2 != 0) {
          uVar8 = *(uint *)(uVar6 + 0x1c);
          iVar3 = DAT_00011e3c + 0x11c86 + (uVar8 + 0x4a) * 4;
          if (uVar6 == *(uint *)(iVar3 + 4)) {
            *(uint *)(iVar3 + 4) = uVar11;
            if (uVar11 == 0) {
              *(uint *)(iVar4 + 0x11c8a) = *(uint *)(iVar4 + 0x11c8a) & ~(1 << (uVar8 & 0xff));
            }
            else {
LAB_00011cc0:
              uVar8 = *(uint *)(DAT_00011e40 + 0x11cd6);
              if (uVar11 < uVar8) goto LAB_00011e26;
              *(uint *)(uVar11 + 0x18) = uVar2;
              uVar2 = *(uint *)(uVar6 + 0x10);
              if (uVar2 != 0) {
                if (uVar2 < uVar8) goto LAB_00011e26;
                *(uint *)(uVar11 + 0x10) = uVar2;
                *(uint *)(uVar2 + 0x18) = uVar11;
              }
              uVar2 = *(uint *)(uVar6 + 0x14);
              if (uVar2 != 0) {
                if (uVar2 < uVar8) goto LAB_00011e26;
                *(uint *)(uVar11 + 0x14) = uVar2;
                *(uint *)(uVar2 + 0x18) = uVar11;
              }
            }
          }
          else {
            if (uVar2 < *(uint *)(DAT_00011e3c + 0x11c96)) goto LAB_00011e26;
            if (*(uint *)(uVar2 + 0x10) == uVar6) {
              *(uint *)(uVar2 + 0x10) = uVar11;
            }
            else {
              *(uint *)(uVar2 + 0x14) = uVar11;
            }
            if (uVar11 != 0) goto LAB_00011cc0;
          }
        }
LAB_00011cee:
        uVar6 = uVar6 + (uVar1 & 0xfffffffc);
        uVar7 = uVar7 + (uVar1 & 0xfffffffc);
        goto LAB_00011cf4;
      }
    }
  }
LAB_00011e26:
  param_1 = FUN_00013a24();
LAB_00011e2a:
  return param_1 + 8;
}



/* Function: FUN_00011e60 @ 00011e60 */

void FUN_00011e60(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  
  iVar1 = DAT_0001208c;
  iVar9 = DAT_00012088;
  uVar5 = *(uint *)(DAT_00012084 + 0x11e88);
  puVar3 = (uint *)(DAT_00012084 + 0x1202c);
  do {
    if ((*puVar3 <= uVar5) && (uVar5 < *puVar3 + puVar3[1])) break;
    puVar3 = (uint *)puVar3[2];
  } while (puVar3 != (uint *)0x0);
  uVar2 = 0;
  puVar4 = (undefined4 *)(*puVar3 + puVar3[1]);
  uVar6 = (int)puVar4 - 0x27U & 7;
  if (uVar6 != 0) {
    uVar2 = 8 - uVar6 & 7;
  }
  uVar2 = (int)puVar4 + (uVar2 - 0x2f);
  if (uVar2 < uVar5 + 0x10) {
    uVar2 = uVar5;
  }
  uVar6 = 0;
  uVar7 = param_1 + 8U & 7;
  if (uVar7 != 0) {
    uVar6 = 8 - uVar7 & 7;
  }
  iVar8 = param_1 + uVar6;
  uVar6 = (param_2 + -0x28) - uVar6;
  *(uint *)(DAT_00012088 + 0x11efc) = uVar6;
  *(int *)(iVar9 + 0x11f08) = iVar8;
  *(uint *)(iVar8 + 4) = uVar6 | 1;
  *(undefined4 *)(iVar8 + uVar6 + 4) = 0x28;
  *(undefined4 *)(iVar9 + 0x11f0c) = *(undefined4 *)(iVar1 + 0x11f5c);
  *(undefined4 *)(uVar2 + 4) = 0x1b;
  uVar10 = *(undefined4 *)(iVar9 + 0x120b0);
  uVar12 = *(undefined4 *)(iVar9 + 0x120b4);
  *(undefined4 *)(uVar2 + 8) = *(undefined4 *)(FUN_000120ac + iVar9);
  *(undefined4 *)(uVar2 + 0xc) = uVar10;
  *(undefined4 *)(uVar2 + 0x10) = uVar12;
  *(undefined4 *)(uVar2 + 0x14) = *(undefined4 *)(iVar9 + 0x120b8);
  *(int *)(FUN_000120ac + iVar9) = param_1;
  *(int *)(iVar9 + 0x120b0) = param_2;
  *(undefined4 *)(iVar9 + 0x120b8) = param_3;
  *(undefined4 **)(iVar9 + 0x120b4) = (undefined4 *)(uVar2 + 8);
  puVar13 = (undefined4 *)(uVar2 + 0x18);
  do {
    puVar13[1] = 7;
    puVar14 = puVar13 + 2;
    puVar13 = puVar13 + 1;
  } while (puVar14 < puVar4);
  if (uVar2 == uVar5) {
    return;
  }
  uVar2 = uVar2 - uVar5;
  puVar3 = (uint *)(uVar5 + uVar2);
  puVar3[1] = puVar3[1] & 0xfffffffe;
  *puVar3 = uVar2;
  uVar6 = uVar2 >> 3;
  *(uint *)(uVar5 + 4) = uVar2 | 1;
  iVar9 = DAT_000120a0;
  if (uVar6 < 0x20) {
    uVar7 = 1 << (uVar6 & 0xff);
    uVar11 = *(uint *)(DAT_00012090 + 0x11f7a);
    uVar2 = DAT_00012090 + 0x11f9e + uVar6 * 8;
    if ((uVar7 & uVar11) == 0) {
      *(uint *)(DAT_00012090 + 0x11f7a) = uVar7 | uVar11;
      uVar6 = uVar2;
    }
    else {
      uVar6 = *(uint *)(uVar2 + 8);
      if (uVar6 < *(uint *)(DAT_00012090 + 0x11f8a)) goto LAB_0001207c;
    }
    *(uint *)(uVar2 + 8) = uVar5;
    *(uint *)(uVar6 + 0xc) = uVar5;
    *(uint *)(uVar5 + 8) = uVar6;
    *(uint *)(uVar5 + 0xc) = uVar2;
  }
  else {
    uVar7 = uVar2 >> 8;
    uVar6 = 0;
    if ((uVar7 != 0) && (uVar6 = 0x1f, uVar7 <= DAT_00012094)) {
      uVar11 = uVar7 - 0x100 >> 0x10 & 8;
      iVar1 = uVar7 << uVar11;
      uVar7 = (uint)(iVar1 + DAT_00012098) >> 0x10 & 4;
      iVar1 = iVar1 << uVar7;
      uVar6 = (uint)(iVar1 + DAT_0001209c) >> 0x10 & 2;
      iVar1 = (((0xe - uVar11) - uVar7) - uVar6) + ((uint)(iVar1 << uVar6) >> 0xf);
      uVar6 = (uVar2 >> (iVar1 + 7U & 0xff) & 1) + iVar1 * 2;
    }
    *(uint *)(uVar5 + 0x1c) = uVar6;
    uVar7 = *(uint *)(iVar9 + 0x11ffa);
    *(undefined4 *)(uVar5 + 0x14) = 0;
    *(undefined4 *)(uVar5 + 0x10) = 0;
    uVar11 = 1 << (uVar6 & 0xff);
    if ((uVar11 & uVar7) == 0) {
      *(uint *)(iVar9 + 0x11ffa) = uVar7 | uVar11;
      iVar9 = iVar9 + 0x11ff6 + (uVar6 + 0x4a) * 4;
      *(uint *)(iVar9 + 4) = uVar5;
      *(int *)(uVar5 + 0x18) = iVar9 + 4;
LAB_00012058:
      *(uint *)(uVar5 + 0xc) = uVar5;
      *(uint *)(uVar5 + 8) = uVar5;
      return;
    }
    uVar7 = 0;
    if (uVar6 != 0x1f) {
      uVar7 = 0x19 - (uVar6 >> 1);
    }
    iVar1 = uVar2 << (uVar7 & 0xff);
    uVar6 = *(uint *)(iVar9 + 0x11ff6 + (uVar6 + 0x4a) * 4 + 4);
    while ((*(uint *)(uVar6 + 4) & 0xfffffffc) != uVar2) {
      iVar9 = (4 - (iVar1 >> 0x1f)) * 4;
      if (*(uint *)(iVar9 + uVar6) == 0) {
        if (uVar6 + iVar9 < *(uint *)(DAT_000120a4 + 0x12060)) goto LAB_0001207c;
        *(uint *)(iVar9 + uVar6) = uVar5;
        *(uint *)(uVar5 + 0x18) = uVar6;
        goto LAB_00012058;
      }
      iVar1 = iVar1 << 1;
      uVar6 = *(uint *)(iVar9 + uVar6);
    }
    uVar2 = *(uint *)(uVar6 + 8);
    if ((*(uint *)(DAT_000120a8 + 0x12076) <= uVar6) && (*(uint *)(DAT_000120a8 + 0x12076) <= uVar2)
       ) {
      *(uint *)(uVar6 + 8) = uVar5;
      *(uint *)(uVar2 + 0xc) = uVar5;
      *(uint *)(uVar5 + 0xc) = uVar6;
      *(uint *)(uVar5 + 8) = uVar2;
      *(undefined4 *)(uVar5 + 0x18) = 0;
      return;
    }
LAB_0001207c:
    FUN_00013a24();
  }
  return;
}



/* Function: FUN_000120ac @ 000120ac */

int FUN_000120ac(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  FUN_00011a00();
  if (((*(int *)(DAT_000123d4 + 0x12274) << 0x1f < 0) &&
      (*(uint *)(DAT_000123d8 + 0x12122) <= param_1)) && (iVar2 = FUN_00011a7c(param_1), iVar2 != 0)
     ) {
    return iVar2;
  }
  iVar2 = DAT_000123e0;
  if (*(int *)(DAT_000123dc + 0x12298) << 0x1d < 0) {
LAB_000121f0:
    uVar11 = *(int *)(DAT_000123f8 + 0x1224a) + 0x29 + param_1 & -*(int *)(DAT_000123f8 + 0x1224a);
    if (param_1 < uVar11) {
      uVar3 = FUN_0001155c(0,uVar11,3,0x22,0xffffffff,0);
      uVar6 = 1;
      if (uVar3 != 0xffffffff) goto LAB_0001226a;
    }
    uVar11 = *(int *)(DAT_00012478 + 0x1249a) + 0x29 + param_1 & -*(int *)(DAT_00012478 + 0x1249a);
    if (DAT_0001247c < uVar11) goto LAB_00012428;
    iVar2 = DAT_00012478 + 0x124ae;
    FUN_00010f94(iVar2);
    uVar3 = FUN_00013b20(uVar11);
    uVar11 = FUN_00013b20(0);
    FUN_00010e9c(iVar2);
    if ((((uVar11 == 0xffffffff) || (uVar3 == 0xffffffff)) || (uVar11 <= uVar3)) ||
       (uVar11 = uVar11 - uVar3, uVar11 <= param_1 + 0x28)) goto LAB_00012428;
    uVar6 = 0;
  }
  else {
    uVar11 = *(uint *)(DAT_000123dc + 0x120fc);
    puVar8 = (uint *)0x0;
    if (uVar11 != 0) {
      puVar8 = (uint *)(DAT_000123dc + 0x122a0);
      do {
        if ((*puVar8 <= uVar11) && (uVar11 < *puVar8 + puVar8[1])) break;
        puVar8 = (uint *)puVar8[2];
      } while (puVar8 != (uint *)0x0);
    }
    FUN_00010f94(DAT_000123e0 + 0x1217a);
    if (puVar8 == (uint *)0x0) {
      uVar3 = FUN_00013b20(0);
      if (uVar3 != 0xffffffff) {
        iVar9 = *(int *)(iVar2 + 0x12162);
        uVar11 = *(int *)(iVar2 + 0x12166) + 0x29 + param_1 & -*(int *)(iVar2 + 0x12166);
        if ((uVar3 & iVar9 - 1U) != 0) {
          uVar11 = (uVar11 - uVar3) + (-iVar9 & uVar3 + iVar9);
        }
        if (uVar11 <= DAT_000123e4) {
          uVar6 = FUN_00013b20(uVar11);
          if (uVar6 != uVar3) goto LAB_00012436;
          goto LAB_000121e0;
        }
      }
LAB_000121ca:
      uVar11 = 0;
LAB_000121cc:
      *(uint *)(DAT_000123f0 + 0x1238a) = *(uint *)(DAT_000123f0 + 0x1238a) | 4;
      uVar3 = 0xffffffff;
    }
    else {
      uVar11 = ((*(int *)(iVar2 + 0x12166) + 0x29) - *(int *)(DAT_000123e8 + 0x12172)) + param_1 &
               -*(int *)(iVar2 + 0x12166);
      if (DAT_000123e4 < uVar11) goto LAB_000121ca;
      uVar6 = FUN_00013b20(uVar11);
      if (uVar6 == *puVar8 + puVar8[1]) {
        uVar3 = uVar6;
        if (uVar6 != 0xffffffff) goto LAB_000121e0;
        goto LAB_000121cc;
      }
LAB_00012436:
      if (uVar6 == 0xffffffff) goto LAB_000121ca;
      uVar3 = uVar6;
      if (((uVar11 <= DAT_000123e4) && (uVar11 < param_1 + 0x29)) &&
         (uVar6 = (*(int *)(DAT_000123ec + 0x121fa) + 0x29 + param_1) - uVar11 &
                  -*(int *)(DAT_000123ec + 0x121fa), uVar6 <= DAT_000123e4)) {
        iVar2 = FUN_00013b20(uVar6);
        if (iVar2 == -1) {
          FUN_00013b20(-uVar11);
          goto LAB_000121ca;
        }
        uVar11 = uVar11 + uVar6;
      }
    }
LAB_000121e0:
    FUN_00010e9c(DAT_000123f4 + 0x1224e);
    uVar6 = 0;
    if (uVar3 == 0xffffffff) goto LAB_000121f0;
  }
LAB_0001226a:
  iVar2 = DAT_000123fc;
  uVar4 = uVar11 + *(int *)((int)&DAT_00012420 + DAT_000123fc);
  *(uint *)((int)&DAT_00012420 + DAT_000123fc) = uVar4;
  if (*(uint *)((int)&DAT_00012424 + iVar2) < uVar4) {
    *(uint *)((int)&DAT_00012424 + iVar2) = uVar4;
  }
  iVar2 = DAT_00012400;
  uVar4 = *(uint *)(DAT_00012400 + 0x122a6);
  puVar8 = (uint *)(DAT_00012400 + 0x1244a);
  if (uVar4 == 0) {
    *(uint *)(DAT_00012400 + 0x1244e) = uVar11;
    iVar9 = DAT_00012404;
    *(uint *)(iVar2 + 0x1244a) = uVar3;
    *(uint *)(iVar2 + 0x12456) = uVar6;
    uVar7 = *(undefined4 *)(iVar9 + 0x122f6);
    *(uint *)(iVar2 + 0x1229e) = uVar3;
    *(undefined4 *)(iVar2 + 0x122ae) = uVar7;
    iVar9 = iVar2 + 0x122b2;
    do {
      *(int *)(iVar9 + 0xc) = iVar9;
      *(int *)(iVar9 + 8) = iVar9;
      iVar1 = DAT_00012408;
      iVar9 = iVar9 + 8;
    } while (iVar9 != iVar2 + 0x123b2);
    uVar4 = 0;
    uVar6 = uVar3 + 8 & 7;
    if (uVar6 != 0) {
      uVar4 = 8 - uVar6 & 7;
    }
    uVar11 = (uVar11 - 0x28) - uVar4;
    iVar9 = uVar3 + uVar4;
    iVar10 = DAT_00012408 + 0x122e6;
    *(uint *)(DAT_00012408 + 0x122f2) = uVar11;
    *(uint *)(iVar9 + 4) = uVar11 | 1;
    iVar2 = DAT_0001240c;
    *(int *)(iVar1 + 0x122fe) = iVar9;
    *(undefined4 *)(iVar9 + uVar11 + 4) = 0x28;
    iVar2 = iVar2 + 0x122f6;
LAB_00012360:
    *(undefined4 *)(iVar10 + 0x1c) = *(undefined4 *)(iVar2 + 0x5c);
  }
  else {
    do {
      if (uVar3 == *puVar8 + puVar8[1]) {
        if ((((puVar8[3] & 8) == 0) && ((puVar8[3] & 1) == uVar6)) &&
           ((*puVar8 <= uVar4 && (uVar4 < uVar3)))) {
          puVar8[1] = puVar8[1] + uVar11;
          iVar2 = DAT_00012414;
          uVar3 = 0;
          uVar6 = *(int *)(DAT_00012410 + 0x12348) + 8U & 7;
          if (uVar6 != 0) {
            uVar3 = 8 - uVar6 & 7;
          }
          iVar9 = *(int *)(DAT_00012410 + 0x12348) + uVar3;
          uVar3 = (uVar11 + *(int *)(DAT_00012410 + 0x1233c)) - uVar3;
          iVar10 = DAT_00012414 + 0x12352;
          *(uint *)(DAT_00012414 + 0x1235e) = uVar3;
          *(uint *)(iVar9 + 4) = uVar3 | 1;
          *(int *)(iVar2 + 0x1236a) = iVar9;
          iVar2 = DAT_00012418;
          *(undefined4 *)(iVar9 + uVar3 + 4) = 0x28;
          iVar2 = iVar2 + 0x12362;
          goto LAB_00012360;
        }
        break;
      }
      puVar8 = (uint *)puVar8[2];
    } while (puVar8 != (uint *)0x0);
    if (uVar3 < *(uint *)(DAT_0001241c + 0x1237e)) {
      *(uint *)(DAT_0001241c + 0x1237e) = uVar3;
    }
    puVar8 = (uint *)(DAT_00012420 + 0x12538);
    do {
      if (*puVar8 == uVar3 + uVar11) {
        if ((-1 < (int)(puVar8[3] << 0x1c)) && ((puVar8[3] & 1) == uVar6)) {
          *puVar8 = uVar3;
          puVar8[1] = puVar8[1] + uVar11;
          iVar2 = FUN_00011b20(uVar3,uVar3 + uVar11,param_1);
          return iVar2;
        }
        break;
      }
      puVar8 = (uint *)puVar8[2];
    } while (puVar8 != (uint *)0x0);
    FUN_00011e60(uVar3,uVar11);
  }
  iVar2 = DAT_00012424;
  if (param_1 < *(uint *)(DAT_00012424 + 0x123c2)) {
    iVar9 = *(int *)(DAT_00012424 + 0x123ce);
    uVar11 = *(uint *)(DAT_00012424 + 0x123c2) - param_1;
    *(uint *)(DAT_00012424 + 0x123c2) = uVar11;
    *(uint *)(iVar2 + 0x123ce) = iVar9 + param_1;
    *(uint *)(iVar9 + param_1 + 4) = uVar11 | 1;
    *(uint *)(iVar9 + 4) = param_1 | 3;
    return iVar9 + 8;
  }
LAB_00012428:
  puVar5 = (undefined4 *)FUN_000113b0();
  *puVar5 = 0xc;
  return 0;
}



/* Function: FUN_00012480 @ 00012480 */

int FUN_00012480(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  int *piVar15;
  int iVar16;
  int *local_34;
  int local_24;
  
  iVar2 = DAT_00012728;
  iVar1 = DAT_00012724;
  local_24 = 0;
  iVar16 = DAT_00012728 + 0x124a2;
  piVar13 = *(int **)(DAT_00012720 + 0x12650);
  piVar15 = (int *)(DAT_00012720 + 0x12648);
  do {
    while( true ) {
      do {
        do {
          local_34 = piVar15;
          piVar15 = piVar13;
          if (piVar15 == (int *)0x0) {
            return local_24;
          }
          iVar5 = *piVar15;
          iVar8 = piVar15[1];
          piVar13 = (int *)piVar15[2];
        } while ((piVar15[3] & 9U) != 1);
        uVar14 = 0;
        uVar9 = iVar5 + 8U & 7;
        if (uVar9 != 0) {
          uVar14 = 8 - uVar9 & 7;
        }
        uVar14 = iVar5 + uVar14;
        uVar9 = *(uint *)(uVar14 + 4);
      } while (((uVar9 & 2) != 0) ||
              (uVar10 = uVar9 & 0xfffffffc, uVar14 + uVar10 < (uint)(iVar5 + iVar8 + -0x28)));
      if (uVar14 == *(uint *)(iVar1 + 0x124b4)) {
        *(undefined4 *)(iVar1 + 0x124b4) = 0;
        *(undefined4 *)(iVar1 + 0x124a8) = 0;
        goto LAB_000125e8;
      }
      uVar11 = *(uint *)(uVar14 + 0xc);
      uVar12 = *(uint *)(uVar14 + 0x18);
      if (uVar11 == uVar14) break;
      uVar6 = *(uint *)(uVar14 + 8);
      if (((*(uint *)(uVar6 + 0xc) != uVar14) || (*(uint *)(uVar11 + 8) != uVar14)) ||
         (uVar6 < *(uint *)(iVar1 + 0x124b0))) goto LAB_0001270a;
      *(uint *)(uVar6 + 0xc) = uVar11;
      *(uint *)(uVar11 + 8) = uVar6;
LAB_0001256e:
      iVar3 = DAT_00012730;
      if (uVar12 != 0) {
        uVar6 = *(uint *)(uVar14 + 0x1c);
        iVar4 = DAT_00012730 + 0x12580 + (uVar6 + 0x4a) * 4;
        if (uVar14 == *(uint *)(iVar4 + 4)) {
          *(uint *)(iVar4 + 4) = uVar11;
          if (uVar11 == 0) {
            *(uint *)(iVar3 + 0x12584) = *(uint *)(iVar3 + 0x12584) & ~(1 << (uVar6 & 0xff));
          }
          else {
LAB_000125ba:
            uVar6 = *(uint *)(DAT_00012734 + 0x125d0);
            if (uVar11 < uVar6) goto LAB_0001270a;
            *(uint *)(uVar11 + 0x18) = uVar12;
            uVar12 = *(uint *)(uVar14 + 0x10);
            if (uVar12 != 0) {
              if (uVar12 < uVar6) goto LAB_0001270a;
              *(uint *)(uVar11 + 0x10) = uVar12;
              *(uint *)(uVar12 + 0x18) = uVar11;
            }
            uVar12 = *(uint *)(uVar14 + 0x14);
            if (uVar12 != 0) {
              if (uVar12 < uVar6) goto LAB_0001270a;
              *(uint *)(uVar11 + 0x14) = uVar12;
              *(uint *)(uVar12 + 0x18) = uVar11;
            }
          }
        }
        else {
          if (uVar12 < *(uint *)(DAT_00012730 + 0x12590)) goto LAB_0001270a;
          if (*(uint *)(uVar12 + 0x10) == uVar14) {
            *(uint *)(uVar12 + 0x10) = uVar11;
          }
          else {
            *(uint *)(uVar12 + 0x14) = uVar11;
          }
          if (uVar11 != 0) goto LAB_000125ba;
        }
      }
LAB_000125e8:
      iVar5 = FUN_00008670(iVar5,iVar8);
      if (iVar5 == 0) {
        local_24 = local_24 + iVar8;
        *(int *)(DAT_00012738 + 0x127b6) = *(int *)(DAT_00012738 + 0x127b6) - iVar8;
        local_34[2] = (int)piVar13;
        piVar15 = local_34;
      }
      else {
        uVar9 = uVar9 >> 8;
        uVar11 = 0;
        if ((uVar9 != 0) && (uVar11 = 0x1f, uVar9 <= DAT_0001273c)) {
          uVar11 = uVar9 - 0x100 >> 0x10 & 8;
          iVar5 = uVar9 << uVar11;
          uVar12 = (uint)(iVar5 + DAT_00012740) >> 0x10 & 4;
          iVar5 = iVar5 << uVar12;
          uVar9 = (uint)(DAT_00012744 + iVar5) >> 0x10 & 2;
          iVar5 = (((0xe - uVar11) - uVar12) - uVar9) + ((uint)(iVar5 << uVar9) >> 0xf);
          uVar11 = (uVar10 >> (iVar5 + 7U & 0xff) & 1) + iVar5 * 2;
        }
        *(uint *)(uVar14 + 0x1c) = uVar11;
        uVar12 = *(uint *)(iVar2 + 0x124a6);
        *(undefined4 *)(uVar14 + 0x14) = 0;
        *(undefined4 *)(uVar14 + 0x10) = 0;
        uVar9 = 1 << (uVar11 & 0xff);
        if ((uVar9 & uVar12) == 0) {
          iVar5 = iVar16 + (uVar11 + 0x4a) * 4;
          *(uint *)(iVar2 + 0x124a6) = uVar12 | uVar9;
          *(uint *)(iVar5 + 4) = uVar14;
          *(int *)(uVar14 + 0x18) = iVar5 + 4;
LAB_000126e6:
          *(uint *)(uVar14 + 0xc) = uVar14;
          *(uint *)(uVar14 + 8) = uVar14;
        }
        else {
          uVar9 = 0;
          if (uVar11 != 0x1f) {
            uVar9 = 0x19 - (uVar11 >> 1);
          }
          iVar5 = uVar10 << (uVar9 & 0xff);
          uVar9 = *(uint *)(iVar16 + (uVar11 + 0x4a) * 4 + 4);
          while ((*(uint *)(uVar9 + 4) & 0xfffffffc) != uVar10) {
            iVar8 = (4 - (iVar5 >> 0x1f)) * 4;
            if (*(uint *)(iVar8 + uVar9) == 0) {
              if (uVar9 + iVar8 < *(uint *)(DAT_00012748 + 0x126ec)) goto LAB_0001270a;
              *(uint *)(iVar8 + uVar9) = uVar14;
              *(uint *)(uVar14 + 0x18) = uVar9;
              goto LAB_000126e6;
            }
            iVar5 = iVar5 << 1;
            uVar9 = *(uint *)(iVar8 + uVar9);
          }
          uVar10 = *(uint *)(uVar9 + 8);
          if ((uVar9 < *(uint *)(DAT_0001274c + 0x12704)) ||
             (uVar10 < *(uint *)(DAT_0001274c + 0x12704))) goto LAB_0001270a;
          *(uint *)(uVar9 + 8) = uVar14;
          *(uint *)(uVar10 + 0xc) = uVar14;
          *(uint *)(uVar14 + 0xc) = uVar9;
          *(uint *)(uVar14 + 8) = uVar10;
          *(undefined4 *)(uVar14 + 0x18) = 0;
        }
      }
    }
    if (*(uint *)(uVar14 + 0x14) == 0) {
      puVar7 = (undefined4 *)(uVar14 + 0x10);
      uVar11 = *(uint *)(uVar14 + 0x10);
      if (*(uint *)(uVar14 + 0x10) == 0) {
        uVar11 = 0;
        goto LAB_0001256e;
      }
    }
    else {
      puVar7 = (undefined4 *)(uVar14 + 0x14);
      uVar11 = *(uint *)(uVar14 + 0x14);
    }
    while( true ) {
      while (*(uint *)(uVar11 + 0x14) != 0) {
        puVar7 = (undefined4 *)(uVar11 + 0x14);
        uVar11 = *(uint *)(uVar11 + 0x14);
      }
      if (*(uint *)(uVar11 + 0x10) == 0) break;
      puVar7 = (undefined4 *)(uVar11 + 0x10);
      uVar11 = *(uint *)(uVar11 + 0x10);
    }
    if (*(undefined4 **)(DAT_0001272c + 0x1256c) <= puVar7) {
      *puVar7 = 0;
      goto LAB_0001256e;
    }
LAB_0001270a:
    FUN_00013a24();
  } while( true );
}



/* Function: FUN_00012750 @ 00012750 */

bool FUN_00012750(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  
  if ((0xffffffbf < param_1) || (uVar4 = *(uint *)(DAT_0001289c + 0x12778), uVar4 == 0)) {
    iVar2 = 0;
    goto LAB_00012884;
  }
  if (param_1 + 0x28 < *(uint *)(DAT_0001289c + 0x1276c)) {
    puVar8 = (uint *)(DAT_0001289c + 0x1291c);
    iVar2 = *(int *)(DAT_000128a0 + 0x127ce);
    do {
      if ((*puVar8 <= uVar4) && (uVar4 < *puVar8 + puVar8[1])) break;
      puVar8 = (uint *)puVar8[2];
    } while (puVar8 != (uint *)0x0);
    uVar10 = puVar8[3];
    iVar6 = uVar10 << 0x1c;
    if (iVar6 < 0) goto LAB_0001286a;
    iVar6 = FUN_00008ba0((*(uint *)(DAT_0001289c + 0x1276c) + iVar2 + -1) - (param_1 + 0x28),iVar2,
                         uVar4,iVar6,param_4);
    uVar4 = (iVar6 + -1) * iVar2;
    if ((int)(uVar10 << 0x1f) < 0) {
      uVar10 = puVar8[1];
      if (uVar4 <= uVar10) {
        uVar5 = *puVar8;
        uVar7 = DAT_000128a4 + 0x12974;
        do {
          if ((uVar5 <= uVar7) && (uVar7 < uVar5 + uVar10)) goto LAB_0001286a;
          uVar7 = *(uint *)(uVar7 + 8);
        } while (uVar7 != 0);
        iVar2 = FUN_00008670(uVar5 + (uVar10 - uVar4),uVar4);
        if (iVar2 == 0) goto LAB_00012818;
      }
      goto LAB_0001286a;
    }
    if (DAT_000128a8 <= uVar4 && uVar4 - DAT_000128a8 != 0) {
      uVar4 = 0x80000000 - iVar2;
    }
    FUN_00010f94(DAT_000128ac + 0x12846);
    uVar10 = FUN_00013b20(0);
    if (uVar10 == *puVar8 + puVar8[1]) {
      iVar2 = FUN_00013b20(-uVar4);
      uVar4 = FUN_00013b20(0);
      if ((uVar10 <= uVar4) || (uVar4 = uVar10 - uVar4, iVar2 == -1)) goto LAB_0001280c;
    }
    else {
LAB_0001280c:
      uVar4 = 0;
    }
    FUN_00010e9c(DAT_000128b0 + 0x1287c);
LAB_00012818:
    iVar2 = DAT_000128b4;
    if (uVar4 != 0) {
      puVar8[1] = puVar8[1] - uVar4;
      *(uint *)(iVar2 + 0x129d8) = *(int *)(iVar2 + 0x129d8) - uVar4;
      iVar1 = DAT_000128bc;
      iVar6 = DAT_000128b8;
      uVar5 = 0;
      uVar10 = *(int *)(iVar2 + 0x12844) + 8U & 7;
      if (uVar10 != 0) {
        uVar5 = 8 - uVar10 & 7;
      }
      iVar3 = *(int *)(iVar2 + 0x12844) + uVar5;
      uVar5 = (*(int *)(iVar2 + 0x12838) - uVar4) - uVar5;
      *(uint *)(DAT_000128b8 + 0x12862) = uVar5;
      *(uint *)(iVar3 + 4) = uVar5 | 1;
      *(undefined4 *)(iVar3 + uVar5 + 4) = 0x28;
      uVar9 = *(undefined4 *)((int)&DAT_000128bc + iVar1);
      *(int *)(iVar6 + 0x1286e) = iVar3;
      *(undefined4 *)(iVar6 + 0x12872) = uVar9;
    }
  }
  else {
LAB_0001286a:
    uVar4 = 0;
  }
  iVar2 = FUN_00012480();
  iVar2 = uVar4 + iVar2;
  if (iVar2 == 0) {
    *(undefined4 *)((int)&DAT_0001289c + DAT_000128c0) = 0xffffffff;
  }
LAB_00012884:
  return iVar2 != 0;
}



/* Function: FUN_000128c4 @ 000128c4 */

void FUN_000128c4(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  int iVar17;
  
  if (param_1 == 0) {
    return;
  }
  if ((((*(int *)(DAT_00012bcc + 0x12924) == 0) && (iVar2 = FUN_00011a00(), iVar2 != 0)) ||
      (*(int *)(DAT_00012bd0 + 0x12a9e) << 0x1e < 0)) &&
     (iVar2 = FUN_00010f94(DAT_00012bd4 + 0x12aac), iVar2 != 0)) {
    return;
  }
  iVar2 = DAT_00012bd8;
  puVar7 = (uint *)(param_1 + -8);
  puVar12 = *(uint **)(DAT_00012bd8 + 0x1291a);
  if ((puVar7 < puVar12) || (uVar3 = *(uint *)(param_1 + -4), -1 < (int)(uVar3 << 0x1e)))
  goto LAB_00012db6;
  uVar9 = uVar3 & 0xfffffffc;
  puVar6 = (uint *)((int)puVar7 + uVar9);
  if ((uVar3 & 1) != 0) goto LAB_00012a9e;
  uVar3 = *puVar7;
  if ((uVar3 & 1) != 0) {
    iVar10 = uVar9 + (uVar3 & 0xfffffffe) + 0x10;
    iVar17 = FUN_00008670((int)puVar7 - (uVar3 & 0xfffffffe),iVar10);
    if (iVar17 == 0) {
      *(int *)(iVar2 + 0x12ab6) = *(int *)(iVar2 + 0x12ab6) - iVar10;
    }
    goto LAB_00012dba;
  }
  puVar7 = (uint *)((int)puVar7 - uVar3);
  if (puVar7 < puVar12) goto LAB_00012db6;
  uVar9 = uVar9 + uVar3;
  if (puVar7 == *(uint **)(DAT_00012bd8 + 0x1291e)) {
    uVar3 = puVar6[1];
    if ((uVar3 & 3) != 3) goto LAB_00012a9e;
    *(uint *)(DAT_00012bd8 + 0x12912) = uVar9;
    puVar6[1] = uVar3 & 0xfffffffe;
LAB_00012af8:
    puVar7[1] = uVar9 | 1;
    *(uint *)((int)puVar7 + uVar9) = uVar9;
    goto LAB_00012dba;
  }
  uVar3 = uVar3 >> 3;
  if (uVar3 < 0x20) {
    puVar5 = (uint *)puVar7[2];
    puVar14 = (uint *)puVar7[3];
    if (((uint *)puVar5[3] == puVar7) && (puVar7 = (uint *)puVar14[2], puVar7 == (uint *)puVar5[3]))
    {
      if (puVar5 == puVar14) {
        *(uint *)(DAT_00012bdc + 0x1298a) =
             *(uint *)(DAT_00012bdc + 0x1298a) & ~(1 << (uVar3 & 0xff));
      }
      else {
        puVar4 = (uint *)(DAT_00012be0 + 0x129bc + uVar3 * 8);
        if (((puVar5 != puVar4) && (puVar5 < puVar12)) ||
           ((puVar14 != puVar4 && (puVar14 < puVar12)))) goto LAB_00012db6;
        puVar5[3] = (uint)puVar14;
        puVar14[2] = (uint)puVar5;
      }
      goto LAB_00012a9e;
    }
  }
  else {
    puVar14 = (uint *)puVar7[3];
    uVar3 = puVar7[6];
    if (puVar14 == puVar7) {
      puVar4 = puVar7 + 5;
      puVar5 = (uint *)puVar7[5];
      if ((uint *)puVar7[5] != (uint *)0x0) goto LAB_000129f0;
      puVar5 = (uint *)puVar14[4];
      puVar8 = puVar5;
      if (puVar5 != (uint *)0x0) {
        do {
          puVar4 = puVar14 + 4;
          puVar5 = puVar8;
LAB_000129f0:
          while ((uint *)puVar5[5] != (uint *)0x0) {
            puVar4 = puVar5 + 5;
            puVar5 = (uint *)puVar5[5];
          }
          puVar8 = (uint *)puVar5[4];
          puVar14 = puVar5;
        } while (puVar8 != (uint *)0x0);
        if (puVar4 < puVar12) goto LAB_00012db6;
        *puVar4 = 0;
      }
    }
    else {
      puVar5 = (uint *)puVar7[2];
      if ((((uint *)puVar5[3] != puVar7) || ((uint *)puVar14[2] != puVar7)) || (puVar5 < puVar12))
      goto LAB_00012db6;
      puVar5[3] = (uint)puVar14;
      puVar14[2] = (uint)puVar5;
      puVar5 = puVar14;
    }
    iVar2 = DAT_00012be4;
    if (uVar3 != 0) {
      uVar11 = puVar7[7];
      puVar16 = (undefined4 *)(uVar11 * 4 + DAT_00012be4 + 0x12b4a);
      if (puVar7 == (uint *)*puVar16) {
        *puVar16 = puVar5;
        if (puVar5 == (uint *)0x0) {
          *(uint *)(iVar2 + 0x12a22) = *(uint *)(iVar2 + 0x12a22) & ~(1 << (uVar11 & 0xff));
        }
        else {
LAB_00012a5c:
          puVar12 = *(uint **)(DAT_00012be8 + 0x12a72);
          if (puVar5 < puVar12) goto LAB_00012db6;
          puVar5[6] = uVar3;
          puVar14 = (uint *)puVar7[4];
          if (puVar14 != (uint *)0x0) {
            if (puVar14 < puVar12) goto LAB_00012db6;
            puVar5[4] = (uint)puVar14;
            puVar14[6] = (uint)puVar5;
          }
          puVar14 = (uint *)puVar7[5];
          if (puVar14 != (uint *)0x0) {
            if (puVar14 < puVar12) goto LAB_00012db6;
            puVar5[5] = (uint)puVar14;
            puVar14[6] = (uint)puVar5;
          }
        }
      }
      else {
        if (uVar3 < *(uint *)(DAT_00012be4 + 0x12a2e)) goto LAB_00012db6;
        if (*(uint **)(uVar3 + 0x10) == puVar7) {
          *(uint **)(uVar3 + 0x10) = puVar5;
        }
        else {
          *(uint **)(uVar3 + 0x14) = puVar5;
        }
        if (puVar5 != (uint *)0x0) goto LAB_00012a5c;
      }
    }
LAB_00012a9e:
    iVar2 = DAT_00012bec;
    if ((puVar7 < puVar6) && (uVar3 = puVar6[1], (uVar3 & 1) != 0)) {
      if ((uVar3 & 2) == 0) {
        if (puVar6 == *(uint **)(DAT_00012bec + 0x12ad4)) {
          piVar1 = (int *)(DAT_00012bec + 0x12ac8);
          puVar12 = *(uint **)(DAT_00012bec + 0x12ad0);
          *(uint **)(DAT_00012bec + 0x12ad4) = puVar7;
          uVar9 = uVar9 + *piVar1;
          *(uint *)(iVar2 + 0x12ac8) = uVar9;
          puVar7[1] = uVar9 | 1;
          if (puVar7 == puVar12) {
            *(undefined4 *)(iVar2 + 0x12ad0) = 0;
            *(undefined4 *)(iVar2 + 0x12ac4) = 0;
          }
          if (*(uint *)(DAT_00012bf0 + 0x12af8) < uVar9) {
            FUN_00012750(0);
          }
          goto LAB_00012dba;
        }
        if (puVar6 == *(uint **)(DAT_00012bec + 0x12ad0)) {
          piVar1 = (int *)(DAT_00012bec + 0x12ac4);
          *(uint **)(DAT_00012bec + 0x12ad0) = puVar7;
          uVar9 = uVar9 + *piVar1;
          *(uint *)(iVar2 + 0x12ac4) = uVar9;
          goto LAB_00012af8;
        }
        uVar11 = uVar3 >> 3;
        if (uVar11 < 0x20) {
          uVar13 = puVar6[2];
          uVar15 = puVar6[3];
          if ((*(uint **)(uVar13 + 0xc) != puVar6) || (*(uint **)(uVar15 + 8) != puVar6))
          goto LAB_00012db6;
          if (uVar13 == uVar15) {
            *(uint *)(DAT_00012bec + 0x12abc) =
                 *(uint *)(DAT_00012bec + 0x12abc) & ~(1 << (uVar11 & 0xff));
          }
          else {
            uVar11 = DAT_00012bec + 0x12ae0 + uVar11 * 8;
            if (((uVar13 != uVar11) && (uVar13 < *(uint *)(DAT_00012bf4 + 0x12b5a))) ||
               ((uVar15 != uVar11 && (uVar15 < *(uint *)(DAT_00012bf8 + 0x12b6a)))))
            goto LAB_00012db6;
            *(uint *)(uVar13 + 0xc) = uVar15;
            *(uint *)(uVar15 + 8) = uVar13;
          }
          goto LAB_00012c7c;
        }
        puVar12 = (uint *)puVar6[3];
        uVar11 = puVar6[6];
        if (puVar12 == puVar6) {
          puVar14 = puVar6 + 5;
          puVar12 = (uint *)puVar6[5];
          if ((uint *)puVar6[5] == (uint *)0x0) {
            puVar14 = puVar6 + 4;
            puVar12 = (uint *)puVar6[4];
            if ((uint *)puVar6[4] == (uint *)0x0) {
              puVar12 = (uint *)0x0;
              goto LAB_00012c02;
            }
          }
          while( true ) {
            while ((uint *)puVar12[5] != (uint *)0x0) {
              puVar14 = puVar12 + 5;
              puVar12 = (uint *)puVar12[5];
            }
            if ((uint *)puVar12[4] == (uint *)0x0) break;
            puVar14 = puVar12 + 4;
            puVar12 = (uint *)puVar12[4];
          }
          if (*(uint **)((int)&DAT_00012bd0 + DAT_00012bfc) <= puVar14) {
            *puVar14 = 0;
            goto LAB_00012c02;
          }
        }
        else {
          uVar15 = puVar6[2];
          if (((*(uint **)(uVar15 + 0xc) == puVar6) && ((uint *)puVar12[2] == puVar6)) &&
             (*(uint *)(DAT_00012bec + 0x12acc) <= uVar15)) {
            *(uint **)(uVar15 + 0xc) = puVar12;
            puVar12[2] = uVar15;
LAB_00012c02:
            iVar2 = DAT_00012dd4;
            if (uVar11 != 0) {
              uVar15 = puVar6[7];
              puVar16 = (undefined4 *)(uVar15 * 4 + DAT_00012dd4 + 0x12d3c);
              if (puVar6 == (uint *)*puVar16) {
                *puVar16 = puVar12;
                if (puVar12 == (uint *)0x0) {
                  *(uint *)(iVar2 + 0x12c14) = *(uint *)(iVar2 + 0x12c14) & ~(1 << (uVar15 & 0xff));
                }
                else {
LAB_00012c4e:
                  puVar14 = *(uint **)(DAT_00012dd8 + 0x12c64);
                  if (puVar12 < puVar14) goto LAB_00012db6;
                  puVar5 = (uint *)puVar6[4];
                  puVar12[6] = uVar11;
                  if (puVar5 != (uint *)0x0) {
                    if (puVar5 < puVar14) goto LAB_00012db6;
                    puVar12[4] = (uint)puVar5;
                    puVar5[6] = (uint)puVar12;
                  }
                  puVar6 = (uint *)puVar6[5];
                  if (puVar6 != (uint *)0x0) {
                    if (puVar6 < puVar14) goto LAB_00012db6;
                    puVar12[5] = (uint)puVar6;
                    puVar6[6] = (uint)puVar12;
                  }
                }
              }
              else {
                if (uVar11 < *(uint *)(DAT_00012dd4 + 0x12c20)) goto LAB_00012db6;
                if (*(uint **)(uVar11 + 0x10) == puVar6) {
                  *(uint **)(uVar11 + 0x10) = puVar12;
                }
                else {
                  *(uint **)(uVar11 + 0x14) = puVar12;
                }
                if (puVar12 != (uint *)0x0) goto LAB_00012c4e;
              }
            }
LAB_00012c7c:
            iVar2 = DAT_00012ddc;
            puVar12 = *(uint **)(DAT_00012ddc + 0x12c9a);
            uVar9 = uVar9 + (uVar3 & 0xfffffffc);
            puVar7[1] = uVar9 | 1;
            *(uint *)((int)puVar7 + uVar9) = uVar9;
            if (puVar7 == puVar12) {
              *(uint *)(iVar2 + 0x12c8e) = uVar9;
              goto LAB_00012dba;
            }
            goto LAB_00012ca0;
          }
        }
      }
      else {
        puVar6[1] = uVar3 & 0xfffffffe;
        *(uint *)((int)puVar7 + uVar9) = uVar9;
        puVar7[1] = uVar9 | 1;
LAB_00012ca0:
        iVar2 = DAT_00012df0;
        uVar3 = uVar9 >> 3;
        if (uVar3 < 0x20) {
          uVar9 = *(uint *)(DAT_00012de0 + 0x12cb0);
          uVar11 = 1 << (uVar3 & 0xff);
          uVar3 = DAT_00012de0 + 0x12cd4 + uVar3 * 8;
          if ((uVar11 & uVar9) == 0) {
            *(uint *)(DAT_00012de0 + 0x12cb0) = uVar11 | uVar9;
            uVar9 = uVar3;
          }
          else {
            uVar9 = *(uint *)(uVar3 + 8);
            if (uVar9 < *(uint *)(DAT_00012de0 + 0x12cc0)) goto LAB_00012db6;
          }
          *(uint **)(uVar3 + 8) = puVar7;
          *(uint **)(uVar9 + 0xc) = puVar7;
          puVar7[2] = uVar9;
          puVar7[3] = uVar3;
          goto LAB_00012dba;
        }
        uVar11 = uVar9 >> 8;
        uVar3 = 0;
        if ((uVar11 != 0) && (uVar3 = 0x1f, uVar11 <= DAT_00012de4)) {
          uVar15 = uVar11 - 0x100 >> 0x10 & 8;
          iVar17 = uVar11 << uVar15;
          uVar11 = (uint)(iVar17 + DAT_00012de8) >> 0x10 & 4;
          iVar17 = iVar17 << uVar11;
          uVar3 = (uint)(iVar17 + DAT_00012dec) >> 0x10 & 2;
          iVar17 = (((0xe - uVar15) - uVar11) - uVar3) + ((uint)(iVar17 << uVar3) >> 0xf);
          uVar3 = (uVar9 >> (iVar17 + 7U & 0xff) & 1) + iVar17 * 2;
        }
        puVar7[7] = uVar3;
        puVar7[5] = 0;
        puVar7[4] = 0;
        uVar11 = *(uint *)(iVar2 + 0x12d38);
        uVar15 = 1 << (uVar3 & 0xff);
        puVar12 = (uint *)(iVar2 + 0x12e60 + uVar3 * 4);
        if ((uVar15 & uVar11) == 0) {
          *puVar12 = (uint)puVar7;
          *(uint *)(iVar2 + 0x12d38) = uVar11 | uVar15;
          puVar7[6] = (uint)puVar12;
LAB_00012d92:
          puVar7[3] = (uint)puVar7;
          puVar7[2] = (uint)puVar7;
          goto LAB_00012dba;
        }
        uVar11 = 0;
        if (uVar3 != 0x1f) {
          uVar11 = 0x19 - (uVar3 >> 1);
        }
        iVar2 = uVar9 << (uVar11 & 0xff);
        uVar3 = *puVar12;
        while ((*(uint *)(uVar3 + 4) & 0xfffffffc) != uVar9) {
          iVar17 = (4 - (iVar2 >> 0x1f)) * 4;
          if (*(uint *)(iVar17 + uVar3) == 0) {
            if (uVar3 + iVar17 < *(uint *)(DAT_00012df4 + 0x12d9a)) goto LAB_00012db6;
            *(uint **)(iVar17 + uVar3) = puVar7;
            puVar7[6] = uVar3;
            goto LAB_00012d92;
          }
          iVar2 = iVar2 << 1;
          uVar3 = *(uint *)(iVar17 + uVar3);
        }
        uVar9 = *(uint *)(uVar3 + 8);
        if ((*(uint *)(DAT_00012df8 + 0x12db0) <= uVar3) &&
           (*(uint *)(DAT_00012df8 + 0x12db0) <= uVar9)) {
          *(uint **)(uVar3 + 8) = puVar7;
          *(uint **)(uVar9 + 0xc) = puVar7;
          puVar7[3] = uVar3;
          puVar7[2] = uVar9;
          puVar7[6] = 0;
          goto LAB_00012dba;
        }
      }
    }
  }
LAB_00012db6:
  FUN_00013a24();
LAB_00012dba:
  if (*(int *)(DAT_00012dfc + 0x12f78) << 0x1e < 0) {
    FUN_00010e9c(DAT_00012dfc + 0x12f7c);
  }
  return;
}



/* Function: FUN_00012e00 @ 00012e00 */

undefined4 * FUN_00012e00(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  undefined4 *local_1c;
  
  uVar5 = param_1 >> 8;
  uVar2 = -param_1;
  uVar1 = 0;
  if ((uVar5 != 0) && (uVar1 = 0x1f, uVar5 <= DAT_000130d0)) {
    uVar8 = uVar5 - 0x100 >> 0x10 & 8;
    iVar10 = uVar5 << uVar8;
    uVar5 = (uint)(iVar10 + DAT_000130d4) >> 0x10 & 4;
    iVar10 = iVar10 << uVar5;
    uVar1 = (uint)(iVar10 + DAT_000130d8) >> 0x10 & 2;
    iVar10 = (((0xe - uVar8) - uVar5) - uVar1) + ((uint)(iVar10 << uVar1) >> 0xf);
    uVar1 = (param_1 >> (iVar10 + 7U & 0xff) & 1) + iVar10 * 2;
  }
  puVar3 = *(undefined4 **)(DAT_000130dc + (uVar1 + 0x4a) * 4 + 0x12e68);
  if (puVar3 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
LAB_00012ed6:
    iVar10 = 1 << (uVar1 & 0xff);
    puVar4 = (undefined4 *)0x0;
    uVar1 = (iVar10 * 2 | iVar10 * -2) & *(uint *)(DAT_000130e0 + 0x12eec);
    if (uVar1 != 0) {
      uVar5 = (uVar1 & -uVar1) - 1;
      uVar11 = uVar5 >> 0xc & 0x10;
      uVar5 = uVar5 >> uVar11;
      uVar1 = uVar5 >> 5 & 8;
      uVar5 = uVar5 >> uVar1;
      uVar12 = uVar5 >> 2 & 4;
      uVar5 = uVar5 >> uVar12;
      uVar13 = uVar5 >> 1 & 2;
      uVar5 = uVar5 >> uVar13;
      uVar8 = uVar5 >> 1 & 1;
      puVar4 = *(undefined4 **)
                (DAT_000130e0 +
                 (uVar8 + uVar11 + uVar1 + uVar12 + uVar13 + (uVar5 >> uVar8) + 0x4a) * 4 + 0x12eec)
      ;
    }
  }
  else {
    uVar5 = 0;
    if (uVar1 != 0x1f) {
      uVar5 = 0x19 - (uVar1 >> 1);
    }
    iVar10 = param_1 << (uVar5 & 0xff);
    puVar6 = (undefined4 *)0x0;
    local_1c = (undefined4 *)0x0;
    while ((puVar4 = puVar3, uVar5 = (puVar4[1] & 0xfffffffc) - param_1, uVar2 <= uVar5 ||
           (puVar6 = puVar4, uVar2 = uVar5, uVar5 != 0))) {
      puVar7 = (undefined4 *)puVar4[5];
      puVar3 = (undefined4 *)puVar4[4 - (iVar10 >> 0x1f)];
      if ((puVar7 == puVar3) || (puVar4 = puVar7, puVar7 == (undefined4 *)0x0)) {
        puVar4 = local_1c;
      }
      if (puVar3 == (undefined4 *)0x0) goto LAB_00012ece;
      iVar10 = iVar10 << 1;
      local_1c = puVar4;
    }
    uVar2 = 0;
LAB_00012ece:
    if (puVar6 == (undefined4 *)0x0) {
      puVar3 = puVar4;
      if (puVar4 != (undefined4 *)0x0) goto LAB_00012f52;
      goto LAB_00012ed6;
    }
  }
  while (puVar3 = puVar4, puVar4 != (undefined4 *)0x0) {
LAB_00012f52:
    uVar1 = (puVar3[1] & 0xfffffffc) - param_1;
    if (uVar1 < uVar2) {
      puVar6 = puVar3;
      uVar2 = uVar1;
    }
    puVar4 = (undefined4 *)puVar3[4];
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)puVar3[5];
    }
  }
  if (puVar6 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(int *)(DAT_000130e4 + 0x12f84) - param_1 <= uVar2) {
    return (undefined4 *)0x0;
  }
  puVar3 = *(undefined4 **)(DAT_000130e4 + 0x12f8c);
  if ((puVar6 < puVar3) || (puVar4 = (undefined4 *)((int)puVar6 + param_1), puVar4 <= puVar6))
  goto LAB_000131e6;
  puVar7 = (undefined4 *)puVar6[3];
  uVar1 = puVar6[6];
  if (puVar7 == puVar6) {
    if ((undefined4 *)puVar6[5] == (undefined4 *)0x0) {
      puVar9 = puVar6 + 4;
      puVar7 = (undefined4 *)puVar6[4];
      if ((undefined4 *)puVar6[4] == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
        goto LAB_00012ff8;
      }
    }
    else {
      puVar9 = puVar6 + 5;
      puVar7 = (undefined4 *)puVar6[5];
    }
    while( true ) {
      while ((undefined4 *)puVar7[5] != (undefined4 *)0x0) {
        puVar9 = puVar7 + 5;
        puVar7 = (undefined4 *)puVar7[5];
      }
      if ((undefined4 *)puVar7[4] == (undefined4 *)0x0) break;
      puVar9 = puVar7 + 4;
      puVar7 = (undefined4 *)puVar7[4];
    }
    if (puVar9 < puVar3) goto LAB_000131e6;
    *puVar9 = 0;
  }
  else {
    puVar9 = (undefined4 *)puVar6[2];
    if ((((undefined4 *)puVar9[3] != puVar6) || ((undefined4 *)puVar7[2] != puVar6)) ||
       (puVar9 < puVar3)) goto LAB_000131e6;
    puVar9[3] = puVar7;
    puVar7[2] = puVar9;
  }
LAB_00012ff8:
  iVar10 = DAT_000130e8;
  if (uVar1 != 0) {
    uVar5 = puVar6[7];
    iVar14 = DAT_000130e8 + 0x13008 + (uVar5 + 0x4a) * 4;
    if (puVar6 == *(undefined4 **)(iVar14 + 4)) {
      *(undefined4 **)(iVar14 + 4) = puVar7;
      if (puVar7 == (undefined4 *)0x0) {
        *(uint *)(iVar10 + 0x1300c) = *(uint *)(iVar10 + 0x1300c) & ~(1 << (uVar5 & 0xff));
      }
      else {
LAB_00013042:
        puVar3 = *(undefined4 **)(DAT_000130ec + 0x13058);
        if (puVar7 < puVar3) goto LAB_000131e6;
        puVar7[6] = uVar1;
        puVar9 = (undefined4 *)puVar6[4];
        if (puVar9 != (undefined4 *)0x0) {
          if (puVar9 < puVar3) goto LAB_000131e6;
          puVar7[4] = puVar9;
          puVar9[6] = puVar7;
        }
        puVar9 = (undefined4 *)puVar6[5];
        if (puVar9 != (undefined4 *)0x0) {
          if (puVar9 < puVar3) goto LAB_000131e6;
          puVar7[5] = puVar9;
          puVar9[6] = puVar7;
        }
      }
    }
    else {
      if (uVar1 < *(uint *)(DAT_000130e8 + 0x13018)) goto LAB_000131e6;
      if (*(undefined4 **)(uVar1 + 0x10) == puVar6) {
        *(undefined4 **)(uVar1 + 0x10) = puVar7;
      }
      else {
        *(undefined4 **)(uVar1 + 0x14) = puVar7;
      }
      if (puVar7 != (undefined4 *)0x0) goto LAB_00013042;
    }
  }
  if (uVar2 < 0x10) {
    uVar2 = uVar2 + param_1;
    puVar6[1] = uVar2 | 3;
    *(uint *)((int)puVar6 + uVar2 + 4) = *(uint *)((int)puVar6 + uVar2 + 4) | 1;
  }
  else {
    uVar1 = uVar2 >> 3;
    puVar6[1] = param_1 | 3;
    puVar4[1] = uVar2 | 1;
    *(uint *)((int)puVar4 + uVar2) = uVar2;
    iVar10 = DAT_000131fc;
    if (uVar1 < 0x20) {
      uVar5 = 1 << (uVar1 & 0xff);
      uVar8 = *(uint *)(DAT_000130f0 + 0x130a8);
      uVar2 = DAT_000130f0 + 0x130cc + uVar1 * 8;
      if ((uVar5 & uVar8) == 0) {
        *(uint *)(DAT_000130f0 + 0x130a8) = uVar5 | uVar8;
        uVar1 = uVar2;
      }
      else {
        uVar1 = *(uint *)(uVar2 + 8);
        if (uVar1 < *(uint *)(DAT_000130f0 + 0x130b8)) goto LAB_000131e6;
      }
      *(undefined4 **)(uVar2 + 8) = puVar4;
      *(undefined4 **)(uVar1 + 0xc) = puVar4;
      puVar4[2] = uVar1;
      puVar4[3] = uVar2;
    }
    else {
      uVar5 = uVar2 >> 8;
      uVar1 = 0;
      if ((uVar5 != 0) && (uVar1 = 0x1f, uVar5 <= DAT_000131f0)) {
        uVar1 = uVar5 - 0x100 >> 0x10 & 8;
        iVar14 = uVar5 << uVar1;
        uVar8 = (uint)(iVar14 + DAT_000131f4) >> 0x10 & 4;
        iVar14 = iVar14 << uVar8;
        uVar5 = (uint)(DAT_000131f8 + iVar14) >> 0x10 & 2;
        iVar14 = (((0xe - uVar1) - uVar8) - uVar5) + ((uint)(iVar14 << uVar5) >> 0xf);
        uVar1 = (uVar2 >> (iVar14 + 7U & 0xff) & 1) + iVar14 * 2;
      }
      puVar4[7] = uVar1;
      uVar5 = *(uint *)(iVar10 + 0x1315c);
      puVar4[5] = 0;
      puVar4[4] = 0;
      uVar8 = 1 << (uVar1 & 0xff);
      if ((uVar8 & uVar5) == 0) {
        *(uint *)(iVar10 + 0x1315c) = uVar5 | uVar8;
        iVar10 = iVar10 + 0x13158 + (uVar1 + 0x4a) * 4;
        *(undefined4 **)(iVar10 + 4) = puVar4;
        puVar4[6] = iVar10 + 4;
LAB_000131be:
        puVar4[3] = puVar4;
        puVar4[2] = puVar4;
      }
      else {
        uVar5 = 0;
        if (uVar1 != 0x1f) {
          uVar5 = 0x19 - (uVar1 >> 1);
        }
        iVar14 = uVar2 << (uVar5 & 0xff);
        uVar1 = *(uint *)(iVar10 + 0x13158 + (uVar1 + 0x4a) * 4 + 4);
        while ((*(uint *)(uVar1 + 4) & 0xfffffffc) != uVar2) {
          iVar10 = (4 - (iVar14 >> 0x1f)) * 4;
          if (*(uint *)(iVar10 + uVar1) == 0) {
            if (uVar1 + iVar10 < *(uint *)(DAT_00013200 + 0x131c6)) goto LAB_000131e6;
            *(undefined4 **)(iVar10 + uVar1) = puVar4;
            puVar4[6] = uVar1;
            goto LAB_000131be;
          }
          iVar14 = iVar14 << 1;
          uVar1 = *(uint *)(iVar10 + uVar1);
        }
        uVar2 = *(uint *)(uVar1 + 8);
        if ((uVar1 < *(uint *)(DAT_00013204 + 0x131dc)) ||
           (uVar2 < *(uint *)(DAT_00013204 + 0x131dc))) {
LAB_000131e6:
          FUN_00013a24();
          return (undefined4 *)0x0;
        }
        *(undefined4 **)(uVar1 + 8) = puVar4;
        *(undefined4 **)(uVar2 + 0xc) = puVar4;
        puVar4[3] = uVar1;
        puVar4[2] = uVar2;
        puVar4[6] = 0;
      }
    }
  }
  return puVar6 + 2;
}



/* Function: FUN_00013208 @ 00013208 */

undefined4 * FUN_00013208(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 extraout_r2;
  uint uVar6;
  int extraout_r2_00;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  uint uStack_44;
  
  puVar19 = (undefined4 *)(iRam000133f0 + 0x13214);
  uVar7 = (*(uint *)(iRam000133f0 + 0x13218) & -*(uint *)(iRam000133f0 + 0x13218)) - 1;
  uVar11 = uVar7 >> 0xc & 0x10;
  uVar7 = uVar7 >> uVar11;
  uVar14 = uVar7 >> 5 & 8;
  uVar7 = uVar7 >> uVar14;
  uVar12 = uVar7 >> 2 & 4;
  uVar7 = uVar7 >> uVar12;
  uVar2 = uVar7 >> 1 & 2;
  uVar7 = uVar7 >> uVar2;
  iVar8 = -((int)(uVar7 << 0x1e) >> 0x1f);
  puVar18 = (undefined4 *)(iVar8 + uVar14 + uVar11 + uVar12 + uVar2);
  puVar4 = (undefined4 *)puVar19[(int)puVar18 + (uVar7 >> iVar8) + 0x4b];
  puVar15 = (undefined4 *)0x3;
  uVar2 = (puVar4[1] & 0xfffffffc) - param_1;
  puVar9 = puVar4;
  while ((puVar13 = (undefined4 *)puVar4[4], puVar13 != (undefined4 *)0x0 ||
         (puVar13 = (undefined4 *)puVar4[5], puVar13 != (undefined4 *)0x0))) {
    puVar19 = (undefined4 *)(puVar13[1] & 0xfffffffc);
    puVar4 = puVar13;
    if ((int)puVar19 - param_1 < uVar2) {
      uVar2 = (int)puVar19 - param_1;
      puVar9 = puVar13;
    }
  }
  puVar13 = (undefined4 *)(iRam000133f4 + 0x13286);
  puVar4 = *(undefined4 **)(iRam000133f4 + 0x13296);
  if ((puVar4 <= puVar9) && (puVar18 = (undefined4 *)((int)puVar9 + param_1), puVar9 < puVar18)) {
    puVar5 = (undefined4 *)puVar9[3];
    puVar13 = (undefined4 *)puVar9[6];
    if (puVar5 == puVar9) {
      if ((undefined4 *)puVar9[5] == (undefined4 *)0x0) {
        puVar15 = puVar9 + 4;
        puVar5 = (undefined4 *)puVar9[4];
        if ((undefined4 *)puVar9[4] == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
          goto LAB_000132f8;
        }
      }
      else {
        puVar15 = puVar9 + 5;
        puVar5 = (undefined4 *)puVar9[5];
      }
      while( true ) {
        while ((undefined4 *)puVar5[5] != (undefined4 *)0x0) {
          puVar15 = puVar5 + 5;
          puVar5 = (undefined4 *)puVar5[5];
        }
        if ((undefined4 *)puVar5[4] == (undefined4 *)0x0) break;
        puVar15 = puVar5 + 4;
        puVar5 = (undefined4 *)puVar5[4];
      }
      if (puVar4 <= puVar15) {
        *puVar15 = 0;
        goto LAB_000132f8;
      }
      puVar19 = (undefined4 *)0x0;
    }
    else {
      puVar15 = (undefined4 *)puVar9[2];
      puVar19 = (undefined4 *)puVar15[3];
      if (((puVar19 == puVar9) && (puVar19 = (undefined4 *)puVar5[2], puVar19 == puVar9)) &&
         (puVar4 <= puVar15)) {
        puVar15[3] = puVar5;
        puVar5[2] = puVar15;
LAB_000132f8:
        iVar8 = iRam000133f8;
        if (puVar13 != (undefined4 *)0x0) {
          uVar7 = puVar9[7];
          puVar4 = (undefined4 *)(iRam000133f8 + 0x1330a + (uVar7 + 0x4a) * 4);
          puVar19 = (undefined4 *)puVar4[1];
          if (puVar9 == puVar19) {
            puVar4[1] = puVar5;
            puVar19 = puVar4;
            if (puVar5 == (undefined4 *)0x0) {
              *(uint *)(iVar8 + 0x1330e) = *(uint *)(iVar8 + 0x1330e) & ~(1 << (uVar7 & 0xff));
            }
            else {
LAB_00013342:
              puVar15 = *(undefined4 **)(iRam000133fc + 0x13358);
              if (puVar5 < puVar15) goto LAB_000133ea;
              puVar5[6] = puVar13;
              puVar13 = (undefined4 *)puVar9[4];
              if (puVar13 != (undefined4 *)0x0) {
                if (puVar13 < puVar15) goto LAB_000133ea;
                puVar5[4] = puVar13;
                puVar13[6] = puVar5;
              }
              puVar13 = (undefined4 *)puVar9[5];
              if (puVar13 != (undefined4 *)0x0) {
                if (puVar13 < puVar15) goto LAB_000133ea;
                puVar5[5] = puVar13;
                puVar13[6] = puVar5;
              }
            }
          }
          else {
            puVar15 = *(undefined4 **)(iRam000133f8 + 0x1331a);
            if (puVar13 < puVar15) goto LAB_000133ea;
            puVar19 = (undefined4 *)puVar13[4];
            if (puVar19 == puVar9) {
              puVar13[4] = puVar5;
            }
            else {
              puVar13[5] = puVar5;
            }
            if (puVar5 != (undefined4 *)0x0) goto LAB_00013342;
          }
        }
        if (uVar2 < 0x10) {
          uVar2 = uVar2 + param_1;
          puVar9[1] = uVar2 | 3;
          *(uint *)((int)puVar9 + uVar2 + 4) = *(uint *)((int)puVar9 + uVar2 + 4) | 1;
          goto LAB_000133e2;
        }
        puVar9[1] = param_1 | 3;
        puVar18[1] = uVar2 | 1;
        iVar8 = iRam00013400;
        *(uint *)((int)puVar18 + uVar2) = uVar2;
        if (*(uint *)(iVar8 + 0x133a2) != 0) {
          uVar7 = *(uint *)(iVar8 + 0x133a2) >> 3;
          puVar13 = (undefined4 *)(iVar8 + 0x133be + uVar7 * 8);
          puVar19 = *(undefined4 **)(iVar8 + 0x1339a);
          iVar1 = *(int *)(iVar8 + 0x133ae);
          uVar7 = 1 << (uVar7 & 0xff);
          if ((uVar7 & (uint)puVar19) == 0) {
            *(uint *)(iVar8 + 0x1339a) = (uint)puVar19 | uVar7;
            puVar15 = puVar13;
          }
          else {
            puVar15 = (undefined4 *)puVar13[2];
            if (puVar15 < *(undefined4 **)(iVar8 + 0x133aa)) goto LAB_000133ea;
          }
          puVar13[2] = iVar1;
          puVar15[3] = iVar1;
          *(undefined4 **)(iVar1 + 8) = puVar15;
          *(undefined4 **)(iVar1 + 0xc) = puVar13;
        }
        iVar8 = iRam00013404;
        *(uint *)(iRam00013404 + 0x133e8) = uVar2;
        *(undefined4 **)(iVar8 + 0x133f4) = puVar18;
LAB_000133e2:
        return puVar9 + 2;
      }
    }
  }
LAB_000133ea:
  FUN_00013a24();
  uVar2 = puVar18[1];
  puVar19[0x1f] = puVar18;
  puVar19[0x1d] = extraout_r2;
  puVar19[0x1c] = puVar13;
  puVar15[0x1b] = extraout_r2;
  puVar13[0x1a] = puVar13;
  if ((((*(int *)(DAT_00013640 + 0x13464) == 0) && (iVar8 = FUN_00011a00(), iVar8 != 0)) ||
      (*(int *)(DAT_00013644 + 0x135de) << 0x1e < 0)) &&
     (iVar8 = FUN_00010f94(DAT_00013648 + 0x135ee), iVar8 != 0)) {
    return (undefined4 *)0x0;
  }
  if (uVar2 < 0xf5) {
    uVar7 = 0x10;
    if (10 < uVar2) {
      uVar7 = uVar2 + 0xb & 0xfffffff8;
    }
    uVar12 = uVar7 >> 3;
    puVar10 = (uint *)(DAT_0001364c + 0x1345e);
    uVar2 = *puVar10;
    uVar11 = uVar2 >> (uVar12 & 0xff);
    if ((uVar11 & 3) == 0) {
      if (*(uint *)(DAT_0001364c + 0x13466) < uVar7) {
        if (uVar11 != 0) {
          iVar8 = 1 << (uVar12 & 0xff);
          uVar11 = (iVar8 * 2 | iVar8 * -2) & uVar11 << (uVar12 & 0xff);
          uVar11 = (uVar11 & -uVar11) - 1;
          uVar12 = uVar11 >> 0xc & 0x10;
          uVar11 = uVar11 >> uVar12;
          uVar6 = uVar11 >> 5 & 8;
          uVar11 = uVar11 >> uVar6;
          uVar16 = uVar11 >> 2 & 4;
          uVar11 = uVar11 >> uVar16;
          uVar14 = uVar11 >> 1 & 2;
          uVar11 = uVar11 >> uVar14;
          uVar17 = uVar11 >> 1 & 1;
          uStack_44 = DAT_0001364c + 0x13482;
          uVar11 = uVar6 + uVar12 + uVar16 + uVar14 + uVar17 + (uVar11 >> uVar17);
          uVar12 = uStack_44 + uVar11 * 8;
          uVar14 = *(uint *)(*(int *)(uVar12 + 8) + 8);
          iVar8 = *(int *)(uVar14 + 0xc);
          if (iVar8 != *(int *)(uVar12 + 8)) goto LAB_00013574;
          if (uVar12 == uVar14) {
            *puVar10 = uVar2 & ~(1 << (uVar11 & 0xff));
          }
          else {
            if (uVar14 < *(uint *)(DAT_0001364c + 0x1346e)) goto LAB_00013574;
            *(uint *)(uVar12 + 8) = uVar14;
            *(uint *)(uVar14 + 0xc) = uVar12;
          }
          iVar1 = DAT_00013650;
          uVar11 = uVar11 * 8 - uVar7;
          *(uint *)(iVar8 + 4) = uVar7 | 3;
          uVar7 = iVar8 + uVar7;
          *(uint *)(uVar7 + 4) = uVar11 | 1;
          *(uint *)(uVar7 + uVar11) = uVar11;
          if (*(uint *)(iVar1 + 0x13546) != 0) {
            uVar2 = *(uint *)(iVar1 + 0x13546) >> 3;
            iVar3 = *(int *)(iVar1 + 0x13552);
            uStack_44 = uStack_44 + uVar2 * 8;
            uVar12 = *(uint *)(iVar1 + 0x1353e);
            uVar2 = 1 << (uVar2 & 0xff);
            if ((uVar2 & uVar12) == 0) {
              *(uint *)(iVar1 + 0x1353e) = uVar2 | uVar12;
              uVar2 = uStack_44;
            }
            else {
              uVar2 = *(uint *)(uStack_44 + 8);
              if (uVar2 < *(uint *)(iVar1 + 0x1354e)) goto LAB_00013574;
            }
            goto LAB_00013578;
          }
          goto LAB_00013582;
        }
        if (*(int *)(DAT_0001364c + 0x13462) != 0) {
          puVar19 = (undefined4 *)FUN_00013208(uVar7);
          goto LAB_000135be;
        }
      }
      goto LAB_000135c2;
    }
    uVar7 = 1;
    uVar12 = (~uVar11 & 1) + uVar12;
    uVar11 = DAT_0001364c + 0x13482 + uVar12 * 8;
    uVar14 = *(uint *)(*(int *)(uVar11 + 8) + 8);
    iVar8 = *(int *)(uVar14 + 0xc);
    if (iVar8 == *(int *)(uVar11 + 8)) {
      if (uVar11 == uVar14) {
        *puVar10 = uVar2 & ~(1 << (uVar12 & 0xff));
      }
      else {
        if (uVar14 < *(uint *)(DAT_0001364c + 0x1346e)) goto LAB_00013574;
        *(uint *)(uVar11 + 8) = uVar14;
        *(uint *)(uVar14 + 0xc) = uVar11;
      }
      uVar12 = uVar12 * 8;
      goto LAB_000135ea;
    }
LAB_00013574:
    uVar11 = FUN_00013a24();
    iVar3 = extraout_r2_00;
LAB_00013578:
    *(int *)(uVar2 + 0xc) = iVar3;
    *(int *)(uStack_44 + 8) = iVar3;
    *(uint *)(iVar3 + 0xc) = uStack_44;
    *(uint *)(iVar3 + 8) = uVar2;
LAB_00013582:
    iVar1 = DAT_00013654;
    *(uint *)(DAT_00013654 + 0x13590) = uVar11;
    *(uint *)(iVar1 + 0x1359c) = uVar7;
  }
  else {
    if (uVar2 < 0xffffffc0) {
      uVar7 = uVar2 + 0xb & 0xfffffff8;
      if (*(int *)(DAT_00013658 + 0x135b4) != 0) {
        puVar19 = (undefined4 *)FUN_00012e00(uVar7);
LAB_000135be:
        if (puVar19 != (undefined4 *)0x0) goto LAB_00013624;
      }
    }
    else {
      uVar7 = 0xffffffff;
    }
LAB_000135c2:
    iVar1 = DAT_0001365c;
    uVar12 = *(uint *)(DAT_0001365c + 0x135d0);
    if (uVar12 < uVar7) {
      if (*(uint *)(DAT_0001365c + 0x135d4) <= uVar7) {
        puVar19 = (undefined4 *)FUN_000120ac(uVar7);
        goto LAB_00013624;
      }
      iVar8 = *(int *)(DAT_0001365c + 0x135e0);
      uVar2 = *(uint *)(DAT_0001365c + 0x135d4) - uVar7;
      *(uint *)(DAT_0001365c + 0x135d4) = uVar2;
      *(uint *)(iVar1 + 0x135e0) = iVar8 + uVar7;
      *(uint *)(iVar8 + uVar7 + 4) = uVar2 | 1;
    }
    else {
      uVar2 = uVar12 - uVar7;
      iVar8 = *(int *)(DAT_0001365c + 0x135dc);
      if (uVar2 < 0x10) {
        *(undefined4 *)(DAT_0001365c + 0x135d0) = 0;
        *(undefined4 *)(iVar1 + 0x135dc) = 0;
LAB_000135ea:
        *(uint *)(iVar8 + 4) = uVar12 | 3;
        *(uint *)(iVar8 + uVar12 + 4) = *(uint *)(iVar8 + uVar12 + 4) | 1;
        goto LAB_00013618;
      }
      iVar3 = iVar8 + uVar7;
      *(uint *)(DAT_0001365c + 0x135d0) = uVar2;
      *(int *)(iVar1 + 0x135dc) = iVar3;
      *(uint *)(iVar3 + 4) = uVar2 | 1;
      *(uint *)(iVar3 + uVar2) = uVar2;
    }
    *(uint *)(iVar8 + 4) = uVar7 | 3;
  }
LAB_00013618:
  puVar19 = (undefined4 *)(iVar8 + 8);
LAB_00013624:
  if (*(int *)(DAT_00013660 + 0x137e2) << 0x1e < 0) {
    FUN_00010e9c(DAT_00013660 + 0x137e6);
  }
  return puVar19;
}



/* Function: FUN_00013408 @ 00013408 */

int FUN_00013408(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int extraout_r2;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_1c;
  
  if ((((*(int *)(DAT_00013640 + 0x13464) == 0) && (iVar2 = FUN_00011a00(), iVar2 != 0)) ||
      (*(int *)(DAT_00013644 + 0x135de) << 0x1e < 0)) &&
     (iVar2 = FUN_00010f94(DAT_00013648 + 0x135ee), iVar2 != 0)) {
    return 0;
  }
  if (param_1 < 0xf5) {
    uVar10 = 0x10;
    if (10 < param_1) {
      uVar10 = param_1 + 0xb & 0xfffffff8;
    }
    uVar4 = uVar10 >> 3;
    puVar9 = (uint *)(DAT_0001364c + 0x1345e);
    uVar8 = *puVar9;
    uVar3 = uVar8 >> (uVar4 & 0xff);
    if ((uVar3 & 3) == 0) {
      if (*(uint *)(DAT_0001364c + 0x13466) < uVar10) {
        if (uVar3 != 0) {
          iVar2 = 1 << (uVar4 & 0xff);
          uVar3 = (iVar2 * 2 | iVar2 * -2) & uVar3 << (uVar4 & 0xff);
          uVar3 = (uVar3 & -uVar3) - 1;
          uVar4 = uVar3 >> 0xc & 0x10;
          uVar3 = uVar3 >> uVar4;
          uVar7 = uVar3 >> 5 & 8;
          uVar3 = uVar3 >> uVar7;
          uVar11 = uVar3 >> 2 & 4;
          uVar3 = uVar3 >> uVar11;
          uVar6 = uVar3 >> 1 & 2;
          uVar3 = uVar3 >> uVar6;
          uVar12 = uVar3 >> 1 & 1;
          local_1c = DAT_0001364c + 0x13482;
          uVar3 = uVar7 + uVar4 + uVar11 + uVar6 + uVar12 + (uVar3 >> uVar12);
          uVar4 = local_1c + uVar3 * 8;
          uVar6 = *(uint *)(*(int *)(uVar4 + 8) + 8);
          iVar2 = *(int *)(uVar6 + 0xc);
          if (iVar2 != *(int *)(uVar4 + 8)) goto LAB_00013574;
          if (uVar4 == uVar6) {
            *puVar9 = uVar8 & ~(1 << (uVar3 & 0xff));
          }
          else {
            if (uVar6 < *(uint *)(DAT_0001364c + 0x1346e)) goto LAB_00013574;
            *(uint *)(uVar4 + 8) = uVar6;
            *(uint *)(uVar6 + 0xc) = uVar4;
          }
          iVar1 = DAT_00013650;
          uVar3 = uVar3 * 8 - uVar10;
          *(uint *)(iVar2 + 4) = uVar10 | 3;
          uVar10 = iVar2 + uVar10;
          *(uint *)(uVar10 + 4) = uVar3 | 1;
          *(uint *)(uVar10 + uVar3) = uVar3;
          if (*(uint *)(iVar1 + 0x13546) != 0) {
            uVar8 = *(uint *)(iVar1 + 0x13546) >> 3;
            iVar5 = *(int *)(iVar1 + 0x13552);
            local_1c = local_1c + uVar8 * 8;
            uVar4 = *(uint *)(iVar1 + 0x1353e);
            uVar8 = 1 << (uVar8 & 0xff);
            if ((uVar8 & uVar4) == 0) {
              *(uint *)(iVar1 + 0x1353e) = uVar8 | uVar4;
              uVar8 = local_1c;
            }
            else {
              uVar8 = *(uint *)(local_1c + 8);
              if (uVar8 < *(uint *)(iVar1 + 0x1354e)) goto LAB_00013574;
            }
            goto LAB_00013578;
          }
          goto LAB_00013582;
        }
        if (*(int *)(DAT_0001364c + 0x13462) != 0) {
          iVar2 = FUN_00013208(uVar10);
          goto LAB_000135be;
        }
      }
      goto LAB_000135c2;
    }
    uVar10 = 1;
    uVar4 = (~uVar3 & 1) + uVar4;
    uVar3 = DAT_0001364c + 0x13482 + uVar4 * 8;
    uVar6 = *(uint *)(*(int *)(uVar3 + 8) + 8);
    iVar2 = *(int *)(uVar6 + 0xc);
    if (iVar2 == *(int *)(uVar3 + 8)) {
      if (uVar3 == uVar6) {
        *puVar9 = uVar8 & ~(1 << (uVar4 & 0xff));
      }
      else {
        if (uVar6 < *(uint *)(DAT_0001364c + 0x1346e)) goto LAB_00013574;
        *(uint *)(uVar3 + 8) = uVar6;
        *(uint *)(uVar6 + 0xc) = uVar3;
      }
      uVar4 = uVar4 * 8;
      goto LAB_000135ea;
    }
LAB_00013574:
    uVar3 = FUN_00013a24();
    iVar5 = extraout_r2;
LAB_00013578:
    *(int *)(uVar8 + 0xc) = iVar5;
    *(int *)(local_1c + 8) = iVar5;
    *(uint *)(iVar5 + 0xc) = local_1c;
    *(uint *)(iVar5 + 8) = uVar8;
LAB_00013582:
    iVar1 = DAT_00013654;
    *(uint *)(DAT_00013654 + 0x13590) = uVar3;
    *(uint *)(iVar1 + 0x1359c) = uVar10;
  }
  else {
    if (param_1 < 0xffffffc0) {
      uVar10 = param_1 + 0xb & 0xfffffff8;
      if (*(int *)(DAT_00013658 + 0x135b4) != 0) {
        iVar2 = FUN_00012e00(uVar10);
LAB_000135be:
        if (iVar2 != 0) goto LAB_00013624;
      }
    }
    else {
      uVar10 = 0xffffffff;
    }
LAB_000135c2:
    iVar1 = DAT_0001365c;
    uVar4 = *(uint *)(DAT_0001365c + 0x135d0);
    if (uVar4 < uVar10) {
      if (*(uint *)(DAT_0001365c + 0x135d4) <= uVar10) {
        iVar2 = FUN_000120ac(uVar10);
        goto LAB_00013624;
      }
      iVar2 = *(int *)(DAT_0001365c + 0x135e0);
      uVar8 = *(uint *)(DAT_0001365c + 0x135d4) - uVar10;
      *(uint *)(DAT_0001365c + 0x135d4) = uVar8;
      *(uint *)(iVar1 + 0x135e0) = iVar2 + uVar10;
      *(uint *)(iVar2 + uVar10 + 4) = uVar8 | 1;
    }
    else {
      uVar8 = uVar4 - uVar10;
      iVar2 = *(int *)(DAT_0001365c + 0x135dc);
      if (uVar8 < 0x10) {
        *(undefined4 *)(DAT_0001365c + 0x135d0) = 0;
        *(undefined4 *)(iVar1 + 0x135dc) = 0;
LAB_000135ea:
        *(uint *)(iVar2 + 4) = uVar4 | 3;
        *(uint *)(iVar2 + uVar4 + 4) = *(uint *)(iVar2 + uVar4 + 4) | 1;
        goto LAB_00013618;
      }
      iVar5 = iVar2 + uVar10;
      *(uint *)(DAT_0001365c + 0x135d0) = uVar8;
      *(int *)(iVar1 + 0x135dc) = iVar5;
      *(uint *)(iVar5 + 4) = uVar8 | 1;
      *(uint *)(iVar5 + uVar8) = uVar8;
    }
    *(uint *)(iVar2 + 4) = uVar10 | 3;
  }
LAB_00013618:
  iVar2 = iVar2 + 8;
LAB_00013624:
  if (*(int *)(DAT_00013660 + 0x137e2) << 0x1e < 0) {
    FUN_00010e9c(DAT_00013660 + 0x137e6);
  }
  return iVar2;
}



/* Function: FUN_00013664 @ 00013664 */

int FUN_00013664(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if ((param_1 == 0) || (uVar1 = FUN_00008ba0(0xffffffff,param_1), param_2 <= uVar1)) {
    iVar3 = FUN_00013408(param_2 * param_1);
    if ((iVar3 != 0) && (((*(uint *)(iVar3 + -4) & 1) != 0 || ((*(uint *)(iVar3 + -8) & 1) == 0))))
    {
      FUN_000084a8(iVar3,0,param_2 * param_1);
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_000113b0();
    *puVar2 = 0xc;
    iVar3 = 0;
  }
  return iVar3;
}



/* Function: FUN_000136b8 @ 000136b8 */

uint * FUN_000136b8(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint unaff_r5;
  uint *local_20;
  
  if (0xffffffbf < param_2) {
    puVar1 = (undefined4 *)FUN_000113b0();
    *puVar1 = 0xc;
    return (uint *)0x0;
  }
  if ((((*(int *)(DAT_0001384c + 0x13728) == 0) && (iVar2 = FUN_00011a00(), iVar2 != 0)) ||
      (unaff_r5 = 0x1b4, *(int *)(DAT_00013850 + 0x138a2) << 0x1e < 0)) &&
     (iVar2 = FUN_00010f94(DAT_00013854 + 0x138b2), iVar2 != 0)) {
    return (uint *)0x0;
  }
  iVar2 = DAT_00013860;
  puVar7 = (uint *)(param_1 + -8);
  uVar4 = *(uint *)(param_1 + -4);
  if (puVar7 < *(uint **)(DAT_00013858 + 0x13720)) {
LAB_000137d8:
    FUN_00013a24();
  }
  else {
    unaff_r5 = uVar4 & 0xfffffffc;
    puVar3 = (uint *)((int)puVar7 + unaff_r5);
    if ((((uint)(puVar7 < puVar3) & uVar4 >> 1 & 1) == 0) || ((puVar3[1] & 1) == 0))
    goto LAB_000137d8;
    uVar6 = 0x10;
    if (10 < param_2) {
      uVar6 = param_2 + 0xb & 0xfffffff8;
    }
    local_20 = puVar7;
    if (((uVar4 & 1) != 0) || ((*puVar7 & 1) == 0)) {
      if (unaff_r5 < uVar6) {
        if ((puVar3 != *(uint **)(DAT_00013860 + 0x137be)) ||
           (uVar5 = unaff_r5 + *(int *)(DAT_00013860 + 0x137b2), uVar5 <= uVar6)) goto LAB_000137dc;
        uVar5 = uVar5 - uVar6;
        *(uint *)(param_1 + -4) = uVar6 | uVar4 & 1 | 2;
        *(uint *)(iVar2 + 0x137be) = (int)puVar7 + uVar6;
        *(uint *)((int)puVar7 + uVar6 + 4) = uVar5 | 1;
        *(uint *)(iVar2 + 0x137b2) = uVar5;
      }
      else {
        uVar5 = unaff_r5 - uVar6;
        if (0xf < uVar5) {
          *(uint *)(param_1 + -4) = uVar6 | uVar4 & 1 | 2;
          *(uint *)((int)puVar7 + uVar6 + 4) = uVar5 | 3;
          iVar2 = (int)puVar7 + uVar6 + 8;
          *(uint *)((int)puVar7 + uVar5 + uVar6 + 4) =
               *(uint *)((int)puVar7 + uVar5 + uVar6 + 4) | 1;
          goto LAB_000137e6;
        }
      }
LAB_000137e2:
      iVar2 = 0;
      goto LAB_000137e6;
    }
    if ((0x1f < uVar6 >> 3) &&
       ((uVar6 + 4 <= unaff_r5 && (unaff_r5 - uVar6 <= (uint)(*(int *)(DAT_0001385c + 0x137bc) * 2))
        ))) goto LAB_000137e2;
  }
LAB_000137dc:
  iVar2 = 0;
  local_20 = (uint *)0x0;
LAB_000137e6:
  if (*(int *)(DAT_00013864 + 0x139a4) << 0x1e < 0) {
    FUN_00010e9c(DAT_00013864 + 0x139a8);
  }
  if (local_20 == (uint *)0x0) {
    local_20 = (uint *)FUN_00013408(param_2);
    if (local_20 != (uint *)0x0) {
      if (((*(uint *)(param_1 + -4) & 1) != 0) || (iVar2 = 8, (*puVar7 & 1) == 0)) {
        iVar2 = 4;
      }
      uVar4 = unaff_r5 - iVar2;
      if (param_2 < unaff_r5 - iVar2) {
        uVar4 = param_2;
      }
      FUN_00008170(local_20,param_1,uVar4);
      FUN_000128c4(param_1);
    }
  }
  else {
    if (iVar2 != 0) {
      FUN_000128c4(iVar2);
    }
    local_20 = local_20 + 2;
  }
  return local_20;
}



/* Function: FUN_00013868 @ 00013868 */

undefined4 FUN_00013868(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_00013408(param_2);
  }
  else if (param_2 == 0) {
    FUN_000128c4();
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_000136b8();
  }
  return uVar1;
}



/* Function: FUN_00013888 @ 00013888 */

uint * FUN_00013888(uint param_1,uint param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int extraout_r1;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int local_1c;
  
  if (param_1 < 9) {
    puVar1 = (uint *)FUN_00013408(param_2);
  }
  else {
    if (param_1 < 0x10) {
      param_1 = 0x10;
    }
    uVar7 = 0x10;
    uVar5 = param_1;
    if ((param_1 - 1 & param_1) != 0) {
      for (; uVar5 = uVar7, uVar7 < param_1; uVar7 = uVar7 << 1) {
      }
    }
    if (param_2 < -uVar5 - 0x40) {
      uVar7 = 0x10;
      if (10 < param_2) {
        uVar7 = param_2 + 0xb & 0xfffffff8;
      }
      iVar3 = FUN_00013408(uVar5 + 0xc + uVar7);
      if ((iVar3 != 0) &&
         ((((*(int *)(DAT_00013a0c + 0x1393a) != 0 || (iVar4 = FUN_00011a00(), iVar4 == 0)) &&
           (-1 < *(int *)(DAT_00013a10 + 0x13ab4) << 0x1e)) ||
          (iVar4 = FUN_00010f94(DAT_00013a14 + 0x13ac2), iVar4 == 0)))) {
        FUN_00008c4c(iVar3,uVar5);
        puVar8 = (uint *)(iVar3 + -8);
        local_1c = 0;
        puVar1 = puVar8;
        if (extraout_r1 != 0) {
          puVar1 = (uint *)((iVar3 + (uVar5 - 1) & -uVar5) - 8);
          if ((uint)((int)puVar1 - (int)puVar8) < 0x10) {
            puVar1 = (uint *)((int)puVar1 + uVar5);
          }
          uVar6 = (int)puVar1 - (int)puVar8;
          uVar5 = (*(uint *)(iVar3 + -4) & 0xfffffffc) - uVar6;
          if (((*(uint *)(iVar3 + -4) & 1) == 0) && ((*puVar8 & 1) != 0)) {
            *puVar1 = uVar6 + *puVar8;
            puVar1[1] = uVar5 | 2;
            local_1c = 0;
          }
          else {
            puVar1[1] = puVar1[1] & 1 | 2 | uVar5;
            *(uint *)((int)puVar1 + uVar5 + 4) = *(uint *)((int)puVar1 + uVar5 + 4) | 1;
            *(uint *)(iVar3 + -4) = *(uint *)(iVar3 + -4) & 1 | 2 | uVar6;
            *(uint *)((int)puVar8 + uVar6 + 4) = *(uint *)((int)puVar8 + uVar6 + 4) | 1;
            local_1c = iVar3;
          }
        }
        uVar5 = puVar1[1];
        if ((((uVar5 & 1) == 0) && ((*puVar1 & 1) != 0)) || ((uVar5 & 0xfffffffc) <= uVar7 + 0x10))
        {
          iVar3 = 0;
        }
        else {
          uVar6 = (uVar5 & 0xfffffffc) - uVar7;
          puVar1[1] = uVar7 | uVar5 & 1 | 2;
          *(uint *)((int)puVar1 + uVar7 + 4) = uVar6 | 3;
          iVar4 = uVar6 + uVar7;
          iVar3 = (int)puVar1 + uVar7 + 8;
          *(uint *)((int)puVar1 + iVar4 + 4) = *(uint *)((int)puVar1 + iVar4 + 4) | 1;
        }
        if (*(int *)(DAT_00013a18 + 0x13b92) << 0x1e < 0) {
          FUN_00010e9c(DAT_00013a18 + 0x13b96);
        }
        if (local_1c != 0) {
          FUN_000128c4(local_1c);
        }
        if (iVar3 != 0) {
          FUN_000128c4(iVar3);
        }
        return puVar1 + 2;
      }
    }
    else {
      puVar2 = (undefined4 *)FUN_000113b0();
      *puVar2 = 0xc;
    }
    puVar1 = (uint *)0x0;
  }
  return puVar1;
}



/* Function: FUN_00013a24 @ 00013a24 */

void FUN_00013a24(void)

{
  undefined4 uVar1;
  code *pcVar2;
  int *extraout_r3;
  int *piVar3;
  int *piVar4;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c [2];
  
  piVar4 = (int *)**(int **)(DAT_00013acc + 0x13a3c + DAT_00013ad0);
  FUN_000084a8(local_1c,0xffffffff,4);
  local_1c[0] = DAT_00013ad4;
  FUN_00008730(2,local_1c,0);
  if (*(int *)(DAT_00013ad8 + 0x13a60) != 0) goto LAB_00013a82;
  if (piVar4 == (int *)0x0) goto LAB_00013a82;
  do {
    piVar3 = piVar4;
    piVar4 = (int *)*piVar3;
  } while ((int *)*piVar3 != (int *)0x0);
  do {
    if ((piVar3[5] == 0) && (pcVar2 = (code *)piVar3[3], pcVar2 != (code *)0x0)) {
      *(undefined4 *)(DAT_00013adc + 0x13a80) = 1;
      (*pcVar2)();
    }
LAB_00013a82:
    *DAT_00013ae0 = 0x27;
    uVar1 = FUN_00008650();
    FUN_00008880(uVar1,6);
    local_24 = 0x10000000;
    local_28 = 0;
    local_2c = 0;
    FUN_00008710(6,&local_2c);
    FUN_00008730(2,local_1c,0);
    uVar1 = FUN_00008650();
    FUN_00008880(uVar1,6);
    FUN_00008570(1);
    piVar3 = extraout_r3;
  } while( true );
}



/* Function: FUN_00013ae4 @ 00013ae4 */

void FUN_00013ae4(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined1 auStack_30 [36];
  int local_c;
  
  piVar2 = *(int **)(DAT_00013b14 + 0x13af0 + DAT_00013b18);
  local_c = *piVar2;
  iVar1 = FUN_00013bc8(param_1,DAT_00013b1c,auStack_30);
  if (local_c != *piVar2) {
    FUN_000107d0(iVar1 == 0);
  }
  return;
}



/* Function: FUN_00013b20 @ 00013b20 */

uint FUN_00013b20(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = DAT_00013b70 + 0x13b2c;
  piVar4 = *(int **)(iVar6 + DAT_00013b74);
  if (*piVar4 == 0) {
    iVar1 = FUN_00008b60(0);
    *piVar4 = iVar1;
  }
  puVar5 = *(uint **)(iVar6 + DAT_00013b74);
  uVar8 = *puVar5 + 0x1f & 0xffffffe0;
  uVar7 = uVar8 + param_1;
  uVar2 = FUN_00008b60(uVar7);
  if (uVar2 != 0xffffffff) {
    if (uVar2 < uVar7) {
      puVar3 = (undefined4 *)FUN_000113b0();
      *puVar3 = 0xc;
      uVar2 = 0xffffffff;
    }
    else {
      *puVar5 = uVar2;
      uVar2 = uVar8;
    }
  }
  return uVar2;
}



/* Function: FUN_00013b78 @ 00013b78 */

void FUN_00013b78(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *local_74 [2];
  int local_6c;
  undefined2 local_68;
  undefined2 local_66;
  undefined1 *local_64;
  int local_60;
  undefined4 *local_44;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 auStack_11 [5];
  
  local_44 = &local_20;
  local_20 = 0;
  local_1c = 0;
  local_6c = DAT_00013bc4;
  if ((-1 < param_2) && (local_6c = param_2, param_2 == 0)) {
    local_6c = 1;
    param_1 = auStack_11;
  }
  local_66 = 0xffff;
  local_6c = local_6c + -1;
  local_68 = 0x208;
  local_74[0] = param_1;
  local_64 = param_1;
  local_60 = local_6c;
  FUN_0000c6b0(local_74,param_3,param_4);
  *local_74[0] = 0;
  return;
}



/* Function: FUN_00013bc8 @ 00013bc8 */

void FUN_00013bc8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00008b80(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00013be4 @ 00013be4 */

void FUN_00013be4(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0x80;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  uVar1 = FUN_0000bba4(param_2,0);
  param_1[3] = uVar1;
  return;
}



/* Function: FUN_00013c04 @ 00013c04 */

uint FUN_00013c04(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x14) < *(int *)(param_1 + 0x10)) {
LAB_00013c3a:
    uVar3 = (uint)*(byte *)(param_1 + *(int *)(param_1 + 0x14) + 0x98);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    do {
      iVar1 = FUN_00008130(*(undefined4 *)(param_1 + 0xc),param_1 + 0x98,0x80);
      if (-1 < iVar1) {
        if (iVar1 != 0) {
          *(int *)(param_1 + 0x10) = iVar1;
          goto LAB_00013c3a;
        }
        break;
      }
      piVar2 = (int *)FUN_000113b0();
    } while (*piVar2 == 4);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* Function: FUN_00013c50 @ 00013c50 */

int * FUN_00013c50(int *param_1)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    while( true ) {
      while( true ) {
        iVar1 = FUN_00013c04(param_1);
        if (iVar1 < 0) {
          FUN_00008150(param_1[3]);
          param_1[3] = -1;
          return (int *)0x0;
        }
        if (param_1[2] == 0) break;
        param_1[2] = (uint)(iVar1 == 10);
      }
      iVar2 = *param_1;
      if (iVar2 < param_1[1]) break;
      param_1[2] = 1;
    }
    if (iVar1 == 10) break;
    *(char *)((int)param_1 + iVar2 + 0x18) = (char)iVar1;
    *param_1 = iVar2 + 1;
  }
  *(undefined1 *)((int)param_1 + iVar2 + 0x18) = 0;
  *param_1 = 0;
  return param_1 + 6;
}



/* Function: FUN_00013ca8 @ 00013ca8 */

int FUN_00013ca8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_128 [280];
  
  iVar1 = FUN_00013be4(auStack_128,DAT_00013cec + 0x13cb4);
  iVar3 = 1;
  if (-1 < iVar1) {
    iVar1 = DAT_00013cf0 + 0x13cd6;
    iVar3 = 0;
    while (iVar2 = FUN_00013c50(auStack_128), iVar2 != 0) {
      iVar2 = FUN_000088a0(iVar2,iVar1,9);
      iVar3 = iVar3 + (uint)(iVar2 == 0);
    }
    if (iVar3 < 1) {
      iVar3 = 1;
    }
  }
  return iVar3;
}



/* Function: FUN_00013cf4 @ 00013cf4 */

int FUN_00013cf4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_130 [284];
  
  iVar1 = FUN_00013be4(auStack_130,DAT_00013d44 + 0x13d00);
  iVar4 = 1;
  if (-1 < iVar1) {
    iVar1 = DAT_00013d48 + 0x13d2e;
    iVar4 = 0;
    while (iVar3 = FUN_00013c50(auStack_130), iVar3 != 0) {
      iVar2 = FUN_000088a0(iVar3,iVar1,3);
      if (iVar2 == 0) {
        iVar4 = iVar4 + (uint)(*(byte *)(iVar3 + 3) - 0x30 < 10);
      }
    }
    if (iVar4 < 1) {
      iVar4 = 1;
    }
  }
  return iVar4;
}



/* Function: FUN_00013d4c @ 00013d4c */

uint FUN_00013d4c(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_12c [12];
  int local_120;
  uint local_14;
  
  iVar1 = FUN_00013be4(auStack_12c,DAT_00013d9c + 0x13d58);
  if (iVar1 < 0) {
    iVar1 = 2;
LAB_00013d94:
    local_14 = -iVar1;
  }
  else {
    iVar1 = DAT_00013da0 + 0x13d8a;
    do {
      iVar2 = FUN_00013c50(auStack_12c);
      if (iVar2 == 0) {
        iVar1 = 3;
        goto LAB_00013d94;
      }
      iVar2 = FUN_00013ea4(iVar2,iVar1,&local_14);
    } while (iVar2 != 1);
    if (-1 < local_120) {
      FUN_00008150();
    }
    local_14 = local_14 >> 2;
  }
  return local_14;
}



/* Function: FUN_00013da4 @ 00013da4 */

uint FUN_00013da4(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_12c [12];
  int local_120;
  uint local_14;
  
  iVar1 = FUN_00013be4(auStack_12c,DAT_00013df0 + 0x13db0);
  if (iVar1 < 0) {
LAB_00013de8:
    local_14 = 0xffffffff;
  }
  else {
    iVar1 = DAT_00013df4 + 0x13de0;
    do {
      iVar2 = FUN_00013c50(auStack_12c);
      if (iVar2 == 0) goto LAB_00013de8;
      iVar2 = FUN_00013ea4(iVar2,iVar1,&local_14);
    } while (iVar2 != 1);
    if (-1 < local_120) {
      FUN_00008150();
    }
    local_14 = local_14 >> 2;
  }
  return local_14;
}



/* Function: FUN_00013df8 @ 00013df8 */

undefined4 FUN_00013df8(uint param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 < 100) {
                    /* WARNING: Could not emulate address calculation at 0x00013e04 */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(*(int *)(param_1 * 4 + DAT_00013e8c + 0x13e06) + DAT_00013e8c + 0x13e06))();
    return uVar1;
  }
  puVar2 = (undefined4 *)FUN_000113b0();
  *puVar2 = 0x26;
  return 0xffffffff;
}



/* Function: FUN_00013ea4 @ 00013ea4 */

void FUN_00013ea4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_84;
  undefined4 local_80;
  undefined2 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_60;
  undefined4 *local_54;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_24;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_54 = &local_30;
  local_2c = 0;
  local_30 = 0;
  local_78 = 4;
  local_84 = param_1;
  local_74 = param_1;
  uStack_8 = param_3;
  uStack_4 = param_4;
  local_80 = FUN_0000b7e0();
  local_24 = &uStack_8;
  local_60 = DAT_00013ee8 + 0x13ed0;
  local_40 = 0;
  local_70 = local_80;
  FUN_00013f58(&local_84,param_2,local_24);
  return;
}



/* Function: FUN_00013eec @ 00013eec */

byte * FUN_00013eec(int param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = (uint)*param_2;
  pbVar1 = param_2 + 1;
  bVar5 = uVar4 == 0x5e;
  if (bVar5) {
    uVar4 = (uint)param_2[1];
    pbVar1 = param_2 + 2;
  }
  iVar2 = 0;
  do {
    *(bool *)(param_1 + iVar2) = bVar5;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x100);
  if (uVar4 == 0) {
    return pbVar1 + -1;
  }
LAB_00013f24:
  do {
    *(char *)(param_1 + uVar4) = '\x01' - bVar5;
    while (uVar3 = (uint)*pbVar1, uVar3 == 0x2d) {
      uVar3 = (uint)pbVar1[1];
      if (((int)uVar3 < (int)uVar4) || (uVar3 == 0x5d)) {
        pbVar1 = pbVar1 + 1;
        uVar4 = 0x2d;
        goto LAB_00013f24;
      }
      pbVar1 = pbVar1 + 2;
      do {
        uVar4 = uVar4 + 1;
        *(char *)(param_1 + uVar4) = '\x01' - bVar5;
      } while ((int)uVar4 < (int)uVar3);
    }
    if (uVar3 == 0x5d) {
      return pbVar1 + 1;
    }
    if (uVar3 == 0) {
      return pbVar1;
    }
    pbVar1 = pbVar1 + 1;
    uVar4 = uVar3;
  } while( true );
}



/* Function: FUN_00013f58 @ 00013f58 */

void FUN_00013f58(int *param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint extraout_r3;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  byte *pbVar11;
  int *piVar12;
  byte *pbVar13;
  int iVar14;
  undefined8 uVar15;
  
  iVar2 = DAT_00014238;
  *(int *)(&stack0x00000008 + DAT_00014238) = DAT_0001423c + 0x13f66;
  *(undefined4 *)(&stack0x00000004 + DAT_00014238) = param_2;
  *(undefined4 *)(&stack0x00000320 + DAT_00014238) =
       **(undefined4 **)(*(int *)(&stack0x00000008 + DAT_00014238) + DAT_00014240);
  *(undefined4 *)(&stack0xfffffffc + DAT_00014238) = 0;
  *(undefined4 *)(&stack0xfffffff8 + DAT_00014238) = 0;
  *(undefined4 *)(&stack0x00000000 + DAT_00014238) = 0;
  *(undefined4 *)(&stack0x00000010 + DAT_00014238) = DAT_00014244;
  *(int *)(&stack0x00000018 + DAT_00014238) = DAT_00014248 + 0x13f80;
code_r0x00013f86:
  do {
    while( true ) {
      pbVar13 = *(byte **)(&stack0x00000004 + iVar2);
      uVar7 = (uint)*pbVar13;
      *(uint *)(&stack0xfffffff4 + iVar2) = uVar7;
      if (uVar7 == 0) {
        FUN_000147b6();
        uVar7 = extraout_r3;
      }
      *(byte **)(&stack0x00000004 + iVar2) = pbVar13 + 1;
      iVar14 = **(int **)(*(int *)(&stack0x00000008 + iVar2) + *(int *)(&stack0x00000010 + iVar2));
      if (-1 < (int)((uint)*(byte *)(iVar14 + uVar7 + 1) << 0x1c)) break;
      while (((0 < param_1[1] || (iVar14 = FUN_00014b18(param_1), iVar14 == 0)) &&
             (pbVar13 = (byte *)*param_1,
             (*(byte *)(**(int **)(*(int *)(&stack0x00000008 + iVar2) +
                                  *(int *)(&stack0x00000010 + iVar2)) + (uint)*pbVar13 + 1) & 8) !=
             0))) {
        iVar14 = param_1[1];
        *(int *)(&stack0xfffffff8 + iVar2) = *(int *)(&stack0xfffffff8 + iVar2) + 1;
        param_1[1] = iVar14 + -1;
        *param_1 = (int)(pbVar13 + 1);
      }
    }
    if (uVar7 != 0x25) {
LAB_000140c4:
      if ((param_1[1] < 1) && (iVar14 = FUN_00014b18(param_1), iVar14 != 0)) goto LAB_000147aa;
      if ((uint)*(byte *)*param_1 != *(uint *)(&stack0xfffffff4 + iVar2)) {
        FUN_000147b6();
        return;
      }
      *param_1 = (int)((byte *)*param_1 + 1);
      iVar14 = *(int *)(&stack0xfffffff8 + iVar2);
      param_1[1] = param_1[1] + -1;
      *(int *)(&stack0xfffffff8 + iVar2) = iVar14 + 1;
      goto code_r0x00013f86;
    }
    uVar7 = 0;
    *(undefined4 *)(&stack0xfffffff0 + iVar2) = 0;
    *(undefined4 *)(&stack0x00000014 + iVar2) = 0x400;
    *(undefined4 *)(&stack0x0000000c + iVar2) = 0x100;
LAB_00013ffa:
    while( true ) {
      uVar8 = (uint)**(byte **)(&stack0x00000004 + iVar2);
      *(byte **)(&stack0x00000004 + iVar2) = *(byte **)(&stack0x00000004 + iVar2) + 1;
      *(uint *)(&stack0xfffffff4 + iVar2) = uVar8;
      if (uVar8 < 0x68) break;
      if (uVar8 == 0x70) {
        iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
        uVar5 = 0x10;
        uVar7 = uVar7 | DAT_0001424c;
        goto LAB_00014254;
      }
      if (uVar8 < 0x71) {
        if (uVar8 == 0x6a) {
          uVar8 = 0x80;
        }
        else if (uVar8 < 0x6b) {
          if (uVar8 != 0x68) {
            if (uVar8 != 0x69) goto LAB_0001421e;
            iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
            uVar5 = 0;
            goto LAB_00014254;
          }
          if (**(char **)(&stack0x00000004 + iVar2) == 'h') {
            *(char **)(&stack0x00000004 + iVar2) = *(char **)(&stack0x00000004 + iVar2) + 1;
            uVar8 = 8;
          }
          else {
            uVar8 = 4;
          }
        }
        else {
          if (uVar8 == 0x6e) {
            if ((int)(uVar7 << 0x15) < 0) goto code_r0x00013f86;
            if ((int)(uVar7 << 0x1c) < 0) {
              *(undefined1 *)*param_3 = (&stack0xfffffff8)[iVar2];
            }
            else if ((int)(uVar7 << 0x1d) < 0) {
              *(undefined2 *)*param_3 = *(undefined2 *)(&stack0xfffffff8 + iVar2);
            }
            else if ((int)(uVar7 << 0x1f) < 0) {
LAB_000141e8:
              *(undefined4 *)*param_3 = *(undefined4 *)(&stack0xfffffff8 + iVar2);
            }
            else if ((int)(uVar7 << 0x19) < 0) {
              *(undefined4 *)*param_3 = *(undefined4 *)(&stack0xfffffff8 + iVar2);
            }
            else {
              if ((int)(uVar7 << 0x17) < 0) goto LAB_000141e8;
              if (-1 < (int)(uVar7 << 0x1b)) {
                *(int **)(&stack0xfffffff0 + iVar2) = param_3 + 1;
                if ((int)(uVar7 << 0x18) < 0) {
                  iVar14 = *(int *)(&stack0xfffffff8 + iVar2);
                  param_3 = (int *)*param_3;
                  *param_3 = iVar14;
                  param_3[1] = iVar14 >> 0x1f;
                }
                else {
                  *(undefined4 *)*param_3 = *(undefined4 *)(&stack0xfffffff8 + iVar2);
                }
                param_3 = *(int **)(&stack0xfffffff0 + iVar2);
                goto code_r0x00013f86;
              }
              iVar14 = *(int *)(&stack0xfffffff8 + iVar2);
              piVar12 = (int *)*param_3;
              *piVar12 = iVar14;
              piVar12[1] = iVar14 >> 0x1f;
            }
            param_3 = param_3 + 1;
            goto code_r0x00013f86;
          }
          if (0x6e < uVar8) goto LAB_00014150;
          if (uVar8 != 0x6c) goto LAB_0001421e;
          if (**(char **)(&stack0x00000004 + iVar2) == 'l') {
            *(char **)(&stack0x00000004 + iVar2) = *(char **)(&stack0x00000004 + iVar2) + 1;
            goto LAB_00014128;
          }
          uVar8 = 1;
        }
      }
      else if (uVar8 == 0x74) {
        uVar8 = *(uint *)(&stack0x0000000c + iVar2);
      }
      else if (uVar8 < 0x75) {
        if (uVar8 != 0x71) {
          if (uVar8 != 0x73) goto LAB_0001421e;
          iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
          uVar5 = 2;
          goto LAB_00014258;
        }
LAB_00014128:
        uVar8 = 0x10;
      }
      else {
        if (uVar8 == 0x78) goto LAB_00014164;
        if (uVar8 != 0x7a) {
          if (uVar8 == 0x75) {
            uVar8 = 0x800;
            goto LAB_00014160;
          }
          goto LAB_0001421e;
        }
        uVar8 = 0x40;
      }
LAB_00014132:
      uVar7 = uVar7 | uVar8;
    }
    if ((100 < uVar8) || (uVar8 == 0x47)) {
LAB_00014170:
      iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
      *(undefined4 *)(&stack0xfffffff4 + iVar2) = 4;
      goto LAB_0001425a;
    }
    if (uVar8 < 0x48) {
      if (0x39 < uVar8) {
        if (uVar8 != 0x44) {
          if (uVar8 == 0x45) goto LAB_00014170;
          goto LAB_0001421e;
        }
        uVar8 = 1;
LAB_00014160:
        uVar7 = uVar7 | uVar8;
        goto LAB_00014250;
      }
      if (uVar8 < 0x30) {
        if (uVar8 == 0x25) goto LAB_000140c4;
        if (uVar8 == 0x2a) {
          uVar8 = *(uint *)(&stack0x00000014 + iVar2);
          goto LAB_00014132;
        }
        if (uVar8 != 0) goto LAB_0001421e;
        goto LAB_000147b0;
      }
      *(int *)(&stack0xfffffff4 + iVar2) = *(int *)(&stack0xfffffff0 + iVar2) * 10;
      *(uint *)(&stack0xfffffff0 + iVar2) = *(int *)(&stack0xfffffff0 + iVar2) * 10 + -0x30 + uVar8;
      goto LAB_00013ffa;
    }
    if (uVar8 == 0x58) {
LAB_00014164:
      uVar7 = uVar7 | 0x8800;
      iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
      uVar5 = 0x10;
      goto LAB_0001422e;
    }
    if (0x58 < uVar8) {
      if (uVar8 == 99) {
        uVar7 = uVar7 | 0x200;
        uVar5 = 0;
        iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
        goto LAB_00014232;
      }
      if (99 < uVar8) goto LAB_00014250;
      if (uVar8 != 0x5b) goto LAB_0001421e;
      uVar5 = FUN_00013eec(&stack0x00000220 + iVar2,*(undefined4 *)(&stack0x00000004 + iVar2));
      *(undefined4 *)(&stack0x00000004 + iVar2) = uVar5;
      uVar7 = uVar7 | 0x200;
      iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
      *(undefined4 *)(&stack0xfffffff4 + iVar2) = 1;
      goto LAB_0001425a;
    }
    if (uVar8 == 0x4c) {
      uVar7 = uVar7 | 2;
      goto LAB_00013ffa;
    }
    if (uVar8 == 0x4f) {
      uVar7 = uVar7 | 1;
LAB_00014150:
      uVar7 = uVar7 | 0x800;
      iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
      uVar5 = 8;
LAB_0001422e:
      *(undefined4 *)(&stack0xfffffffc + iVar2) = uVar5;
      uVar5 = 3;
LAB_00014232:
      *(undefined4 *)(&stack0xfffffff4 + iVar2) = uVar5;
    }
    else {
LAB_0001421e:
      if ((*(byte *)(iVar14 + uVar8 + 1) & 1) != 0) {
        iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
        uVar7 = uVar7 | 1;
        uVar5 = 10;
        goto LAB_0001422e;
      }
LAB_00014250:
      iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
      uVar5 = 10;
LAB_00014254:
      *(undefined4 *)(&stack0xfffffffc + iVar2) = uVar5;
      uVar5 = 3;
LAB_00014258:
      *(undefined4 *)(&stack0xfffffff4 + iVar2) = uVar5;
    }
LAB_0001425a:
    if ((param_1[1] < 1) && (iVar4 = FUN_00014b18(param_1), iVar4 != 0)) goto LAB_000147aa;
    if (-1 < (int)(uVar7 << 0x16)) {
      *(undefined4 *)(&stack0x0000000c + iVar2) =
           *(undefined4 *)(*(int *)(&stack0x00000008 + iVar2) + *(int *)(&stack0x00000010 + iVar2));
      while ((*(byte *)(**(int **)(&stack0x0000000c + iVar2) + (uint)*(byte *)*param_1 + 1) & 8) !=
             0) {
        iVar4 = param_1[1];
        param_1[1] = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          iVar4 = FUN_00014b18(param_1);
          if (iVar4 != 0) goto LAB_000147aa;
        }
        else {
          *param_1 = (int)((byte *)*param_1 + 1);
        }
        *(int *)(&stack0xfffffff8 + iVar2) = *(int *)(&stack0xfffffff8 + iVar2) + 1;
      }
    }
    iVar4 = *(int *)(&stack0xfffffff4 + iVar2);
    if (iVar4 == 2) {
      if (*(int *)(&stack0xfffffff0 + iVar2) == 0) {
        iVar14 = -1;
      }
      if ((int)(uVar7 << 0x15) < 0) {
        *(undefined4 *)(&stack0xfffffff0 + iVar2) = 0;
        piVar12 = *(int **)(*(int *)(&stack0x00000008 + iVar2) + *(int *)(&stack0x00000010 + iVar2))
        ;
        while (pbVar13 = (byte *)*param_1, (*(byte *)(*piVar12 + (uint)*pbVar13 + 1) & 8) == 0) {
          iVar4 = *(int *)(&stack0xfffffff0 + iVar2);
          iVar6 = param_1[1];
          *(int *)(&stack0xfffffff0 + iVar2) = iVar4 + 1;
          param_1[1] = iVar6 + -1;
          *param_1 = (int)(pbVar13 + 1);
          if ((iVar4 + 1 == iVar14) ||
             ((iVar6 + -1 < 1 && (iVar4 = FUN_00014b18(param_1), iVar4 != 0)))) break;
        }
        iVar4 = *(int *)(&stack0xfffffff8 + iVar2) + *(int *)(&stack0xfffffff0 + iVar2);
LAB_0001443c:
        *(int *)(&stack0xfffffff8 + iVar2) = iVar4;
      }
      else {
        pbVar13 = (byte *)*param_3;
        *(int **)(&stack0xfffffff4 + iVar2) = param_3 + 1;
        *(byte **)(&stack0xfffffff0 + iVar2) = pbVar13;
        piVar12 = *(int **)(*(int *)(&stack0x00000008 + iVar2) + *(int *)(&stack0x00000010 + iVar2))
        ;
        while (pbVar11 = (byte *)*param_1, (*(byte *)(*piVar12 + (uint)*pbVar11 + 1) & 8) == 0) {
          iVar14 = iVar14 + -1;
          param_1[1] = param_1[1] + -1;
          *pbVar13 = *pbVar11;
          pbVar13 = pbVar13 + 1;
          *param_1 = (int)(pbVar11 + 1);
          if ((iVar14 == 0) || ((param_1[1] < 1 && (iVar4 = FUN_00014b18(param_1), iVar4 != 0))))
          break;
        }
        *pbVar13 = 0;
        *(byte **)(&stack0xfffffff8 + iVar2) =
             pbVar13 + (*(int *)(&stack0xfffffff8 + iVar2) - *(int *)(&stack0xfffffff0 + iVar2));
        *(int *)(&stack0x00000000 + iVar2) = *(int *)(&stack0x00000000 + iVar2) + 1;
        param_3 = *(int **)(&stack0xfffffff4 + iVar2);
      }
      goto code_r0x00013f86;
    }
    if (iVar4 < 3) {
      if (iVar4 != 1) {
LAB_000142d0:
        if (*(int *)(&stack0xfffffff0 + iVar2) == 0) {
          iVar14 = 1;
        }
        if ((int)(uVar7 << 0x15) < 0) {
          iVar4 = 0;
          while( true ) {
            iVar6 = param_1[1];
            iVar9 = *param_1;
            *(int *)(&stack0xfffffff0 + iVar2) = iVar6;
            if (iVar14 <= iVar6) break;
            *param_1 = iVar9 + iVar6;
            iVar4 = iVar4 + iVar6;
            iVar6 = FUN_00014b18(param_1);
            if (iVar6 != 0) {
              if (iVar4 == 0) goto LAB_000147aa;
              goto LAB_00014310;
            }
            iVar14 = iVar14 - *(int *)(&stack0xfffffff0 + iVar2);
          }
          iVar4 = iVar4 + iVar14;
          param_1[1] = *(int *)(&stack0xfffffff0 + iVar2) - iVar14;
          *param_1 = iVar9 + iVar14;
LAB_00014310:
          iVar4 = iVar4 + *(int *)(&stack0xfffffff8 + iVar2);
          goto LAB_0001443c;
        }
        iVar14 = FUN_000149b0(*param_3,1,iVar14,param_1);
        if (iVar14 == 0) goto LAB_000147aa;
        param_3 = param_3 + 1;
        *(int *)(&stack0xfffffff8 + iVar2) = iVar14 + *(int *)(&stack0xfffffff8 + iVar2);
        *(int *)(&stack0x00000000 + iVar2) = *(int *)(&stack0x00000000 + iVar2) + 1;
        goto code_r0x00013f86;
      }
      if (*(int *)(&stack0xfffffff0 + iVar2) == 0) {
        iVar14 = -1;
      }
      if ((int)(uVar7 << 0x15) < 0) {
        iVar4 = 0;
        *(undefined1 **)(&stack0xfffffff0 + iVar2) = &stack0x00000220 + iVar2;
        while (*(char *)(*(int *)(&stack0xfffffff0 + iVar2) + (uint)*(byte *)*param_1) != '\0') {
          iVar6 = param_1[1];
          iVar4 = iVar4 + 1;
          param_1[1] = iVar6 + -1;
          *param_1 = (int)((byte *)*param_1 + 1);
          if ((iVar4 == iVar14) || ((iVar6 + -1 < 1 && (iVar6 = FUN_00014b18(param_1), iVar6 != 0)))
             ) goto LAB_000143e4;
        }
        if (iVar4 == 0) {
          FUN_000147b6();
          return;
        }
      }
      else {
        iVar4 = *param_3;
        *(int *)(&stack0xfffffff0 + iVar2) = iVar4;
        *(undefined1 **)(&stack0xfffffff4 + iVar2) = &stack0x00000220 + iVar2;
        do {
          pbVar13 = (byte *)*param_1;
          if (*(char *)(*(int *)(&stack0xfffffff4 + iVar2) + (uint)*pbVar13) == '\0')
          goto LAB_000143ce;
          pbVar11 = *(byte **)(&stack0xfffffff0 + iVar2);
          iVar14 = iVar14 + -1;
          param_1[1] = param_1[1] + -1;
          *pbVar11 = *pbVar13;
          *(byte **)(&stack0xfffffff0 + iVar2) = pbVar11 + 1;
          *param_1 = (int)(pbVar13 + 1);
          if (iVar14 == 0) goto LAB_000143ce;
        } while ((0 < param_1[1]) || (iVar6 = FUN_00014b18(param_1), iVar6 == 0));
        if (*(int *)(&stack0xfffffff0 + iVar2) == iVar4) goto LAB_000147aa;
LAB_000143ce:
        iVar4 = (int)*(undefined1 **)(&stack0xfffffff0 + iVar2) - iVar4;
        if (iVar4 == 0) {
          FUN_000147b6();
          return;
        }
        **(undefined1 **)(&stack0xfffffff0 + iVar2) = 0;
        param_3 = param_3 + 1;
        *(int *)(&stack0x00000000 + iVar2) = *(int *)(&stack0x00000000 + iVar2) + 1;
      }
LAB_000143e4:
      pcVar10 = (char *)(*(int *)(&stack0xfffffff8 + iVar2) + iVar4);
    }
    else {
      if (*(int *)(&stack0xfffffff4 + iVar2) != 3) {
        if (*(int *)(&stack0xfffffff4 + iVar2) != 4) goto LAB_000142d0;
        uVar8 = *(int *)(&stack0xfffffff0 + iVar2) - 1U;
        if (DAT_00014764 < *(int *)(&stack0xfffffff0 + iVar2) - 1U) {
          uVar8 = DAT_00014764;
        }
        *(uint *)(&stack0xfffffff0 + iVar2) = uVar8 + 1;
        *(undefined4 *)(&stack0xfffffff4 + iVar2) = 0x14000;
        uVar7 = uVar7 | 0x1d000;
        *(undefined4 *)(&stack0x0000000c + iVar2) = 0x10000;
        pbVar13 = &stack0x0000001c + iVar2;
        *(undefined4 *)(&stack0x00000014 + iVar2) = 0x5000;
        break;
      }
      iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
      *(uint *)(&stack0xfffffff0 + iVar2) = iVar14 - 1U;
      if (DAT_00014764 < iVar14 - 1U) {
        *(uint *)(&stack0xfffffff0 + iVar2) = DAT_00014764;
      }
      uVar7 = uVar7 | 0x15000;
      *(int *)(&stack0x0000000c + iVar2) = DAT_00014768 + 0x144b6;
      iVar14 = 0;
      do {
        *(undefined1 **)(&stack0xfffffff4 + iVar2) = &stack0x0000001c + iVar2;
        pcVar10 = &stack0x0000001c + iVar2 + iVar14;
        bVar3 = *(byte *)*param_1;
        uVar8 = DAT_00014770;
        if (bVar3 < 0x3a) {
          if (bVar3 < 0x38) {
            if (bVar3 == 0x30) {
              if (*(int *)(&stack0xfffffffc + iVar2) == 0) {
                uVar7 = uVar7 | 0x8000;
                *(undefined4 *)(&stack0xfffffffc + iVar2) = 8;
              }
              if ((int)(uVar7 << 0xf) < 0) {
                uVar8 = DAT_0001476c;
              }
            }
            else {
              if (bVar3 < 0x31) {
                if (((bVar3 == 0x2b) || (bVar3 == 0x2d)) && ((int)(uVar7 << 0x13) < 0)) {
                  uVar7 = uVar7 & DAT_00014774 | 0x2000;
                  goto LAB_0001457a;
                }
                goto LAB_000145b0;
              }
              *(int *)(&stack0xfffffffc + iVar2) =
                   (int)*(short *)(*(int *)(&stack0xfffffffc + iVar2) * 2 +
                                  *(int *)(&stack0x0000000c + iVar2));
            }
          }
          else {
            iVar4 = (int)*(short *)(*(int *)(&stack0xfffffffc + iVar2) * 2 +
                                   *(int *)(&stack0x00000018 + iVar2));
            *(int *)(&stack0xfffffffc + iVar2) = iVar4;
            if (iVar4 < 9) goto LAB_000145b0;
          }
LAB_0001451e:
          uVar7 = uVar7 & uVar8;
        }
        else {
          if (bVar3 != 0x58) {
            if (bVar3 < 0x59) {
              if (5 < (byte)(bVar3 + 0xbf)) goto LAB_000145b0;
            }
            else {
              if (bVar3 < 0x61) goto LAB_000145b0;
              if (0x66 < bVar3) {
                if (bVar3 == 0x78) goto LAB_0001455e;
                goto LAB_000145b0;
              }
            }
            if (10 < *(int *)(&stack0xfffffffc + iVar2)) goto LAB_0001451e;
            goto LAB_000145b0;
          }
LAB_0001455e:
          if ((-1 < (int)(uVar7 << 0x10)) ||
             (pcVar10 != &stack0x00000324 + DAT_00014778 + (iVar2 - ((int)(uVar7 << 0x12) >> 0x1f)))
             ) goto LAB_000145b0;
          *(undefined4 *)(&stack0xfffffffc + iVar2) = 0x10;
          uVar7 = uVar7 & DAT_0001477c;
        }
LAB_0001457a:
        (&stack0x0000001c)[iVar14 + iVar2] = bVar3;
        iVar4 = param_1[1];
        param_1[1] = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          iVar4 = FUN_00014b18(param_1);
          if (iVar4 != 0) {
            pcVar10 = (char *)(*(int *)(&stack0xfffffff4 + iVar2) + 1 + iVar14);
            goto LAB_000145b0;
          }
        }
        else {
          *param_1 = *param_1 + 1;
        }
        iVar14 = iVar14 + 1;
      } while (*(int *)(&stack0xfffffff0 + iVar2) + 1 != iVar14);
      pcVar10 = (char *)(iVar14 + *(int *)(&stack0xfffffff4 + iVar2));
LAB_000145b0:
      if ((int)(uVar7 << 0x11) < 0) {
        if (&stack0x0000001c + iVar2 < pcVar10) {
          FUN_00014c80(pcVar10[-1],param_1);
          FUN_000147b6();
          return;
        }
        FUN_000147b6();
        return;
      }
      cVar1 = pcVar10[-1];
      if ((cVar1 == 'X') || (cVar1 == 'x')) {
        FUN_00014c80(cVar1,param_1);
        pcVar10 = pcVar10 + -1;
      }
      if ((uVar7 & 0x400) == 0) {
        *pcVar10 = '\0';
        if ((int)(uVar7 << 0x14) < 0) {
          uVar15 = FUN_000147d8(&stack0x0000001c + iVar2,0,*(undefined4 *)(&stack0xfffffffc + iVar2)
                               );
        }
        else {
          uVar15 = FUN_00010198(&stack0x0000001c + iVar2,0,*(undefined4 *)(&stack0xfffffffc + iVar2)
                               );
        }
        if ((int)(uVar7 << 0x1a) < 0) {
LAB_00014622:
          *(int *)*param_3 = (int)uVar15;
LAB_0001460e:
          param_3 = param_3 + 1;
        }
        else {
          if (((int)(uVar7 << 0x18) < 0) || ((int)(uVar7 << 0x1b) < 0)) {
            *(undefined8 *)*param_3 = uVar15;
            goto LAB_0001460e;
          }
          if ((((int)(uVar7 << 0x19) < 0) || ((int)(uVar7 << 0x17) < 0)) ||
             ((int)(uVar7 << 0x1f) < 0)) goto LAB_00014622;
          if ((int)(uVar7 << 0x1d) < 0) {
            *(short *)*param_3 = (short)uVar15;
            goto LAB_0001460e;
          }
          *(int **)(&stack0xfffffff0 + iVar2) = param_3 + 1;
          if ((int)(uVar7 << 0x1c) < 0) {
            *(char *)*param_3 = (char)uVar15;
          }
          else {
            *(int *)*param_3 = (int)uVar15;
          }
          param_3 = *(int **)(&stack0xfffffff0 + iVar2);
        }
        *(int *)(&stack0x00000000 + iVar2) = *(int *)(&stack0x00000000 + iVar2) + 1;
      }
      pcVar10 = pcVar10 + (*(int *)(&stack0xfffffff8 + iVar2) - (int)(&stack0x0000001c + iVar2));
    }
    *(char **)(&stack0xfffffff8 + iVar2) = pcVar10;
  } while( true );
  while( true ) {
    *pbVar13 = bVar3;
    iVar14 = param_1[1];
    pbVar13 = pbVar13 + 1;
    param_1[1] = iVar14 + -1;
    if (iVar14 + -1 < 1) {
      iVar14 = FUN_00014b18(param_1);
      if (iVar14 != 0) break;
    }
    else {
      *param_1 = *param_1 + 1;
    }
    iVar14 = *(int *)(&stack0xfffffff0 + iVar2);
    *(int *)(&stack0xfffffff0 + iVar2) = iVar14 + -1;
    if (iVar14 + -1 == 0) break;
    bVar3 = *(byte *)*param_1;
    if (bVar3 < 0x3a) {
      uVar8 = DAT_00014780;
      if (bVar3 < 0x30) {
        if (bVar3 != 0x2d) {
          if (bVar3 == 0x2e) {
            uVar8 = DAT_00014784;
            if ((int)(uVar7 << 0x10) < 0) goto LAB_000146b0;
            break;
          }
          if (bVar3 != 0x2b) break;
        }
        uVar8 = DAT_00014774;
        if (-1 < (int)(uVar7 << 0x13)) break;
      }
LAB_000146b0:
      uVar7 = uVar7 & uVar8;
    }
    else {
      if (((bVar3 != 0x45) && (bVar3 != 0x65)) ||
         ((*(uint *)(&stack0xfffffff4 + iVar2) & uVar7) != *(uint *)(&stack0x0000000c + iVar2)))
      break;
      uVar7 = uVar7 & DAT_00014788 | *(uint *)(&stack0x00000014 + iVar2);
    }
  }
  pbVar11 = pbVar13;
  if ((int)(uVar7 << 0x11) < 0) {
    if ((int)(uVar7 << 0xf) < 0) {
      while (&stack0x0000001c + iVar2 < pbVar13) {
        pbVar13 = pbVar13 + -1;
        FUN_00014c80(*pbVar13,param_1);
      }
      FUN_000147b6();
      return;
    }
    pbVar11 = pbVar13 + -1;
    bVar3 = *pbVar11;
    if ((bVar3 != 0x45) && (bVar3 != 0x65)) {
      pbVar11 = pbVar13 + -2;
      FUN_00014c80(bVar3,param_1);
      bVar3 = *pbVar11;
    }
    FUN_00014c80(bVar3,param_1);
  }
  if ((uVar7 & 0x400) == 0) {
    *pbVar11 = 0;
    uVar15 = FUN_0000f670(&stack0x0000001c + iVar2,0);
    if ((int)(uVar7 << 0x1e) < 0) {
      *(undefined8 *)*param_3 = uVar15;
    }
    else {
      *(int **)(&stack0xfffffff0 + iVar2) = param_3 + 1;
      if ((int)(uVar7 << 0x1f) < 0) {
        *(undefined8 *)*param_3 = uVar15;
      }
      else {
        uVar5 = FUN_0000970c();
        *(undefined4 *)*param_3 = uVar5;
      }
    }
    *(int *)(&stack0x00000000 + iVar2) = *(int *)(&stack0x00000000 + iVar2) + 1;
  }
  *(byte **)(&stack0xfffffff8 + iVar2) =
       pbVar11 + (*(int *)(&stack0xfffffff8 + iVar2) - (int)(&stack0x0000001c + iVar2));
  FUN_00013f86();
LAB_000147aa:
  if (*(int *)(&stack0x00000000 + iVar2) == 0) {
LAB_000147b0:
    *(undefined4 *)(&stack0x00000000 + iVar2) = 0xffffffff;
  }
  if (*(int *)(&stack0x00000320 + iVar2) !=
      **(int **)(*(int *)(&stack0x00000008 + iVar2) + DAT_000147d4)) {
    FUN_000107d0(*(undefined4 *)(&stack0x00000000 + iVar2));
  }
  return;
}



/* Function: FUN_00013f86 @ 00013f86 */

void FUN_00013f86(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  undefined1 *extraout_r3;
  uint uVar7;
  byte *pbVar8;
  int *unaff_r4;
  undefined4 *unaff_r5;
  byte *pbVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  uint uVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined8 uVar15;
  byte *pbStack00000004;
  undefined4 *puStack00000008;
  undefined1 uStack0000000c;
  int in_stack_00000010;
  int in_stack_00000014;
  byte *in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000024;
  int in_stack_0000002c;
  int in_stack_00000334;
  
  puVar11 = unaff_r5;
code_r0x00013f86:
  while( true ) {
    puVar6 = (undefined1 *)(uint)*in_stack_00000018;
    puStack00000008 = (undefined4 *)puVar6;
    if (puVar6 == (undefined1 *)0x0) {
      FUN_000147b6();
      puVar6 = extraout_r3;
    }
    in_stack_00000018 = in_stack_00000018 + 1;
    if (-1 < (int)((uint)(byte)puVar6[**(int **)(in_stack_0000001c + in_stack_00000024) + 1] << 0x1c
                  )) break;
    while (((0 < unaff_r4[1] || (iVar2 = FUN_00014b18(unaff_r4), iVar2 == 0)) &&
           ((*(byte *)(**(int **)(in_stack_0000001c + in_stack_00000024) + (uint)*(byte *)*unaff_r4
                      + 1) & 8) != 0))) {
      _uStack0000000c = _uStack0000000c + 1;
      unaff_r4[1] = unaff_r4[1] + -1;
      *unaff_r4 = (int)((byte *)*unaff_r4 + 1);
    }
  }
  if (puVar6 != (undefined1 *)0x25) {
LAB_000140c4:
    if ((unaff_r4[1] < 1) && (iVar2 = FUN_00014b18(unaff_r4), iVar2 != 0)) goto LAB_000147aa;
    if ((undefined4 *)(uint)*(byte *)*unaff_r4 != puStack00000008) {
      FUN_000147b6();
      return;
    }
    *unaff_r4 = (int)((byte *)*unaff_r4 + 1);
    unaff_r4[1] = unaff_r4[1] + -1;
    _uStack0000000c = _uStack0000000c + 1;
    goto code_r0x00013f86;
  }
  uVar12 = 0;
  pbStack00000004 = (byte *)0x0;
LAB_00013ffa:
  while( true ) {
    puStack00000008 = (undefined4 *)(uint)*in_stack_00000018;
    pbVar5 = in_stack_00000018 + 1;
    if (puStack00000008 < (undefined1 *)0x68) break;
    if (puStack00000008 == (undefined4 *)0x70) {
      in_stack_00000010 = 0x10;
      uVar12 = uVar12 | DAT_0001424c;
      goto LAB_00014254;
    }
    if (puStack00000008 < (undefined1 *)0x71) {
      if (puStack00000008 == (undefined4 *)0x6a) {
        uVar7 = 0x80;
        in_stack_00000018 = pbVar5;
      }
      else if (puStack00000008 < (undefined1 *)0x6b) {
        if (puStack00000008 != (undefined4 *)0x68) {
          if (puStack00000008 != (undefined4 *)0x69) goto LAB_0001421e;
          in_stack_00000010 = 0;
          goto LAB_00014254;
        }
        if (*pbVar5 == 0x68) {
          uVar7 = 8;
          in_stack_00000018 = in_stack_00000018 + 2;
        }
        else {
          uVar7 = 4;
          in_stack_00000018 = pbVar5;
        }
      }
      else {
        if (puStack00000008 == (undefined4 *)0x6e) {
          in_stack_00000018 = pbVar5;
          if ((int)(uVar12 << 0x15) < 0) goto code_r0x00013f86;
          if ((int)(uVar12 << 0x1c) < 0) {
            *(undefined1 *)*puVar11 = uStack0000000c;
          }
          else if ((int)(uVar12 << 0x1d) < 0) {
            *(undefined2 *)*puVar11 = _uStack0000000c;
          }
          else if ((int)(uVar12 << 0x1f) < 0) {
LAB_000141e8:
            *(byte **)*puVar11 = _uStack0000000c;
          }
          else if ((int)(uVar12 << 0x19) < 0) {
            *(byte **)*puVar11 = _uStack0000000c;
          }
          else {
            if ((int)(uVar12 << 0x17) < 0) goto LAB_000141e8;
            if (-1 < (int)(uVar12 << 0x1b)) {
              if ((int)(uVar12 << 0x18) < 0) {
                puVar14 = (undefined4 *)*puVar11;
                *puVar14 = _uStack0000000c;
                puVar14[1] = (int)_uStack0000000c >> 0x1f;
                puVar11 = puVar11 + 1;
              }
              else {
                *(byte **)*puVar11 = _uStack0000000c;
                puVar11 = puVar11 + 1;
              }
              goto code_r0x00013f86;
            }
            puVar14 = (undefined4 *)*puVar11;
            *puVar14 = _uStack0000000c;
            puVar14[1] = (int)_uStack0000000c >> 0x1f;
          }
          puVar11 = puVar11 + 1;
          goto code_r0x00013f86;
        }
        if ((undefined1 *)0x6e < puStack00000008) goto LAB_00014150;
        if (puStack00000008 != (undefined4 *)0x6c) goto LAB_0001421e;
        if (*pbVar5 == 0x6c) {
          in_stack_00000018 = in_stack_00000018 + 2;
          goto LAB_00014128;
        }
        uVar7 = 1;
        in_stack_00000018 = pbVar5;
      }
    }
    else if (puStack00000008 == (undefined4 *)0x74) {
      uVar7 = 0x100;
      in_stack_00000018 = pbVar5;
    }
    else if (puStack00000008 < (undefined1 *)0x75) {
      in_stack_00000018 = pbVar5;
      if (puStack00000008 != (undefined4 *)0x71) {
        if (puStack00000008 != (undefined4 *)0x73) goto LAB_0001421e;
        puStack00000008 = (undefined4 *)0x2;
        goto LAB_0001425a;
      }
LAB_00014128:
      uVar7 = 0x10;
    }
    else {
      if (puStack00000008 == (undefined4 *)0x78) goto LAB_00014164;
      if (puStack00000008 != (undefined4 *)0x7a) {
        if (puStack00000008 == (undefined4 *)0x75) {
          uVar7 = 0x800;
          goto LAB_00014160;
        }
        goto LAB_0001421e;
      }
      uVar7 = 0x40;
      in_stack_00000018 = pbVar5;
    }
LAB_00014132:
    uVar12 = uVar12 | uVar7;
  }
  if (((undefined1 *)0x64 < puStack00000008) || (puStack00000008 == (undefined4 *)0x47)) {
LAB_00014170:
    puStack00000008 = (undefined4 *)0x4;
    in_stack_00000018 = pbVar5;
    goto LAB_0001425a;
  }
  if (puStack00000008 < (undefined1 *)0x48) {
    if ((undefined1 *)0x39 < puStack00000008) {
      if (puStack00000008 != (undefined4 *)0x44) {
        if (puStack00000008 == (undefined4 *)0x45) goto LAB_00014170;
        goto LAB_0001421e;
      }
      uVar7 = 1;
LAB_00014160:
      uVar12 = uVar12 | uVar7;
      goto LAB_00014250;
    }
    if (puStack00000008 < (undefined1 *)0x30) {
      in_stack_00000018 = pbVar5;
      if (puStack00000008 == (undefined4 *)0x25) goto LAB_000140c4;
      if (puStack00000008 == (undefined4 *)0x2a) {
        uVar7 = 0x400;
        goto LAB_00014132;
      }
      if (puStack00000008 != (undefined4 *)0x0) goto LAB_0001421e;
      goto LAB_000147b0;
    }
    pbStack00000004 = (byte *)((int)puStack00000008 + (int)pbStack00000004 * 10 + -0x30);
    in_stack_00000018 = pbVar5;
    goto LAB_00013ffa;
  }
  if (puStack00000008 == (undefined4 *)0x58) {
LAB_00014164:
    uVar12 = uVar12 | 0x8800;
    in_stack_00000010 = 0x10;
    goto LAB_0001422e;
  }
  if ((undefined1 *)0x58 < puStack00000008) {
    if (puStack00000008 == (undefined4 *)0x63) {
      uVar12 = uVar12 | 0x200;
      puStack00000008 = (undefined4 *)0x0;
      in_stack_00000018 = pbVar5;
      goto LAB_0001425a;
    }
    if ((undefined1 *)0x63 < puStack00000008) goto LAB_00014250;
    if (puStack00000008 != (undefined4 *)0x5b) goto LAB_0001421e;
    in_stack_00000018 = (byte *)FUN_00013eec(&stack0x00000234,pbVar5);
    uVar12 = uVar12 | 0x200;
    puStack00000008 = (undefined4 *)0x1;
    goto LAB_0001425a;
  }
  if (puStack00000008 == (undefined4 *)0x4c) {
    uVar12 = uVar12 | 2;
    in_stack_00000018 = pbVar5;
    goto LAB_00013ffa;
  }
  if (puStack00000008 == (undefined4 *)0x4f) {
    uVar12 = uVar12 | 1;
LAB_00014150:
    uVar12 = uVar12 | 0x800;
    in_stack_00000010 = 8;
LAB_0001422e:
    puStack00000008 = (undefined4 *)0x3;
    in_stack_00000018 = pbVar5;
  }
  else {
LAB_0001421e:
    if ((*(byte *)((int)puStack00000008 + **(int **)(in_stack_0000001c + in_stack_00000024) + 1) & 1
        ) != 0) {
      uVar12 = uVar12 | 1;
      in_stack_00000010 = 10;
      goto LAB_0001422e;
    }
LAB_00014250:
    in_stack_00000010 = 10;
LAB_00014254:
    puStack00000008 = (undefined4 *)0x3;
    in_stack_00000018 = pbVar5;
  }
LAB_0001425a:
  if ((unaff_r4[1] < 1) && (iVar2 = FUN_00014b18(unaff_r4), iVar2 != 0)) goto LAB_000147aa;
  if (-1 < (int)(uVar12 << 0x16)) {
    piVar13 = *(int **)(in_stack_0000001c + in_stack_00000024);
    while ((*(byte *)(*piVar13 + (uint)*(byte *)*unaff_r4 + 1) & 8) != 0) {
      iVar2 = unaff_r4[1];
      unaff_r4[1] = iVar2 + -1;
      if (iVar2 + -1 < 1) {
        iVar2 = FUN_00014b18(unaff_r4);
        if (iVar2 != 0) goto LAB_000147aa;
      }
      else {
        *unaff_r4 = (int)((byte *)*unaff_r4 + 1);
      }
      _uStack0000000c = _uStack0000000c + 1;
    }
  }
  if (puStack00000008 == (undefined4 *)0x2) {
    pbVar5 = pbStack00000004;
    if (pbStack00000004 == (byte *)0x0) {
      pbVar5 = (byte *)0xffffffff;
    }
    if (-1 < (int)(uVar12 << 0x15)) {
      puStack00000008 = puVar11 + 1;
      pbVar9 = (byte *)*puVar11;
      piVar13 = *(int **)(in_stack_0000001c + in_stack_00000024);
      pbVar10 = pbVar9;
      while (pbVar8 = (byte *)*unaff_r4, (*(byte *)(*piVar13 + (uint)*pbVar8 + 1) & 8) == 0) {
        pbVar5 = pbVar5 + -1;
        unaff_r4[1] = unaff_r4[1] + -1;
        *pbVar10 = *pbVar8;
        pbVar10 = pbVar10 + 1;
        *unaff_r4 = (int)(pbVar8 + 1);
        if ((pbVar5 == (byte *)0x0) ||
           ((unaff_r4[1] < 1 && (iVar2 = FUN_00014b18(unaff_r4), iVar2 != 0)))) break;
      }
      *pbVar10 = 0;
      _uStack0000000c = pbVar10 + ((int)_uStack0000000c - (int)pbVar9);
      in_stack_00000014 = in_stack_00000014 + 1;
      puVar11 = puStack00000008;
      goto code_r0x00013f86;
    }
    pbStack00000004 = (byte *)0x0;
    piVar13 = *(int **)(in_stack_0000001c + in_stack_00000024);
    while (pbVar10 = pbStack00000004, (*(byte *)(*piVar13 + (uint)*(byte *)*unaff_r4 + 1) & 8) == 0)
    {
      iVar2 = unaff_r4[1];
      pbStack00000004 = pbStack00000004 + 1;
      unaff_r4[1] = iVar2 + -1;
      *unaff_r4 = (int)((byte *)*unaff_r4 + 1);
      pbVar10 = pbStack00000004;
      if ((pbStack00000004 == pbVar5) ||
         ((iVar2 + -1 < 1 && (iVar2 = FUN_00014b18(unaff_r4), iVar2 != 0)))) break;
    }
  }
  else {
    if ((int)puStack00000008 < 3) {
      if (puStack00000008 == (undefined4 *)0x1) {
        pbVar5 = pbStack00000004;
        if (pbStack00000004 == (byte *)0x0) {
          pbVar5 = (byte *)0xffffffff;
        }
        if ((int)(uVar12 << 0x15) < 0) {
          pbVar10 = (byte *)0x0;
          while ((&stack0x00000234)[*(byte *)*unaff_r4] != '\0') {
            iVar2 = unaff_r4[1];
            pbVar10 = pbVar10 + 1;
            unaff_r4[1] = iVar2 + -1;
            *unaff_r4 = (int)((byte *)*unaff_r4 + 1);
            if ((pbVar10 == pbVar5) ||
               ((iVar2 + -1 < 1 && (iVar2 = FUN_00014b18(unaff_r4), iVar2 != 0))))
            goto LAB_000143e4;
          }
          if (pbVar10 == (byte *)0x0) {
            FUN_000147b6();
            return;
          }
        }
        else {
          pbVar10 = (byte *)*puVar11;
          puStack00000008 = (undefined4 *)&stack0x00000234;
          pbStack00000004 = pbVar10;
          do {
            pbVar9 = (byte *)*unaff_r4;
            if (*(char *)((int)puStack00000008 + (uint)*pbVar9) == '\0') goto LAB_000143ce;
            pbVar5 = pbVar5 + -1;
            unaff_r4[1] = unaff_r4[1] + -1;
            *pbStack00000004 = *pbVar9;
            pbStack00000004 = pbStack00000004 + 1;
            *unaff_r4 = (int)(pbVar9 + 1);
            if (pbVar5 == (byte *)0x0) goto LAB_000143ce;
          } while ((0 < unaff_r4[1]) || (iVar2 = FUN_00014b18(unaff_r4), iVar2 == 0));
          if (pbStack00000004 == pbVar10) goto LAB_000147aa;
LAB_000143ce:
          pbVar10 = pbStack00000004 + -(int)pbVar10;
          if (pbVar10 == (byte *)0x0) {
            FUN_000147b6();
            return;
          }
          *pbStack00000004 = 0;
          puVar11 = puVar11 + 1;
          in_stack_00000014 = in_stack_00000014 + 1;
        }
LAB_000143e4:
        _uStack0000000c = _uStack0000000c + (int)pbVar10;
        goto code_r0x00013f86;
      }
    }
    else {
      if (puStack00000008 == (undefined4 *)0x3) {
        pbStack00000004 = pbStack00000004 + -1;
        if (DAT_00014764 < pbStack00000004) {
          pbStack00000004 = DAT_00014764;
        }
        iVar2 = DAT_00014768 + 0x144b6;
        uVar12 = uVar12 | 0x15000;
        pbVar5 = (byte *)0x0;
        do {
          puStack00000008 = (undefined4 *)&stack0x00000030;
          pbVar10 = pbVar5 + (int)puStack00000008;
          bVar1 = *(byte *)*unaff_r4;
          uVar7 = DAT_00014770;
          if (bVar1 < 0x3a) {
            if (bVar1 < 0x38) {
              if (bVar1 == 0x30) {
                if (in_stack_00000010 == 0) {
                  uVar12 = uVar12 | 0x8000;
                  in_stack_00000010 = 8;
                }
                if ((int)(uVar12 << 0xf) < 0) {
                  uVar7 = DAT_0001476c;
                }
              }
              else {
                if (bVar1 < 0x31) {
                  if (((bVar1 == 0x2b) || (bVar1 == 0x2d)) && ((int)(uVar12 << 0x13) < 0)) {
                    uVar12 = uVar12 & DAT_00014774 | 0x2000;
                    goto LAB_0001457a;
                  }
                  goto LAB_000145b0;
                }
                in_stack_00000010 = (int)*(short *)(in_stack_00000010 * 2 + iVar2);
              }
            }
            else {
              in_stack_00000010 = (int)*(short *)(in_stack_00000010 * 2 + in_stack_0000002c);
              if (in_stack_00000010 < 9) goto LAB_000145b0;
            }
LAB_0001451e:
            uVar12 = uVar12 & uVar7;
          }
          else {
            if (bVar1 != 0x58) {
              if (bVar1 < 0x59) {
                if (5 < (byte)(bVar1 + 0xbf)) goto LAB_000145b0;
              }
              else {
                if (bVar1 < 0x61) goto LAB_000145b0;
                if (0x66 < bVar1) {
                  if (bVar1 == 0x78) goto LAB_0001455e;
                  goto LAB_000145b0;
                }
              }
              if (10 < in_stack_00000010) goto LAB_0001451e;
              goto LAB_000145b0;
            }
LAB_0001455e:
            if ((-1 < (int)(uVar12 << 0x10)) ||
               (pbVar10 != &stack0x00000338 + (DAT_00014778 - ((int)(uVar12 << 0x12) >> 0x1f))))
            goto LAB_000145b0;
            in_stack_00000010 = 0x10;
            uVar12 = uVar12 & DAT_0001477c;
          }
LAB_0001457a:
          (&stack0x00000030)[(int)pbVar5] = bVar1;
          iVar3 = unaff_r4[1];
          unaff_r4[1] = iVar3 + -1;
          if (iVar3 + -1 < 1) {
            iVar3 = FUN_00014b18(unaff_r4);
            if (iVar3 != 0) {
              pbVar10 = (undefined1 *)((int)puStack00000008 + 1) + (int)pbVar5;
              goto LAB_000145b0;
            }
          }
          else {
            *unaff_r4 = *unaff_r4 + 1;
          }
          pbVar5 = pbVar5 + 1;
        } while (pbStack00000004 + 1 != pbVar5);
        pbVar10 = pbVar5 + (int)puStack00000008;
LAB_000145b0:
        if ((int)(uVar12 << 0x11) < 0) {
          if (&stack0x00000030 < pbVar10) {
            FUN_00014c80(pbVar10[-1],unaff_r4);
            FUN_000147b6();
            return;
          }
          FUN_000147b6();
          return;
        }
        bVar1 = pbVar10[-1];
        if ((bVar1 == 0x58) || (bVar1 == 0x78)) {
          FUN_00014c80(bVar1,unaff_r4);
          pbVar10 = pbVar10 + -1;
        }
        if ((uVar12 & 0x400) == 0) {
          *pbVar10 = 0;
          if ((int)(uVar12 << 0x14) < 0) {
            uVar15 = FUN_000147d8(&stack0x00000030,0,in_stack_00000010);
          }
          else {
            uVar15 = FUN_00010198(&stack0x00000030,0,in_stack_00000010);
          }
          if ((int)(uVar12 << 0x1a) < 0) {
LAB_00014622:
            *(int *)*puVar11 = (int)uVar15;
          }
          else if (((int)(uVar12 << 0x18) < 0) || ((int)(uVar12 << 0x1b) < 0)) {
            *(undefined8 *)*puVar11 = uVar15;
          }
          else {
            if ((((int)(uVar12 << 0x19) < 0) || ((int)(uVar12 << 0x17) < 0)) ||
               ((int)(uVar12 << 0x1f) < 0)) goto LAB_00014622;
            if ((int)(uVar12 << 0x1d) < 0) {
              *(short *)*puVar11 = (short)uVar15;
            }
            else if ((int)(uVar12 << 0x1c) < 0) {
              *(char *)*puVar11 = (char)uVar15;
            }
            else {
              *(int *)*puVar11 = (int)uVar15;
            }
          }
          puVar11 = puVar11 + 1;
          in_stack_00000014 = in_stack_00000014 + 1;
        }
        _uStack0000000c = pbVar10 + ((int)_uStack0000000c - (int)&stack0x00000030);
        goto code_r0x00013f86;
      }
      if (puStack00000008 == (undefined4 *)0x4) {
        pbVar5 = pbStack00000004 + -1;
        if (DAT_00014764 < pbStack00000004 + -1) {
          pbVar5 = DAT_00014764;
        }
        pbStack00000004 = pbVar5 + 1;
        puStack00000008 = (undefined4 *)0x14000;
        uVar12 = uVar12 | 0x1d000;
        pbVar5 = &stack0x00000030;
        goto LAB_00014682;
      }
    }
    if (pbStack00000004 == (byte *)0x0) {
      pbStack00000004 = (byte *)0x1;
    }
    if (-1 < (int)(uVar12 << 0x15)) {
      iVar2 = FUN_000149b0(*puVar11,1,pbStack00000004,unaff_r4);
      if (iVar2 == 0) goto LAB_000147aa;
      _uStack0000000c = _uStack0000000c + iVar2;
      in_stack_00000014 = in_stack_00000014 + 1;
      puVar11 = puVar11 + 1;
      goto code_r0x00013f86;
    }
    pbVar10 = (byte *)0x0;
    while( true ) {
      iVar2 = unaff_r4[1];
      if ((int)pbStack00000004 <= iVar2) break;
      *unaff_r4 = *unaff_r4 + iVar2;
      pbVar10 = pbVar10 + iVar2;
      iVar3 = FUN_00014b18(unaff_r4);
      if (iVar3 != 0) {
        if (pbVar10 == (byte *)0x0) goto LAB_000147aa;
        goto LAB_0001443c;
      }
      pbStack00000004 = pbStack00000004 + -iVar2;
    }
    pbVar10 = pbVar10 + (int)pbStack00000004;
    unaff_r4[1] = iVar2 - (int)pbStack00000004;
    *unaff_r4 = (int)(pbStack00000004 + *unaff_r4);
  }
LAB_0001443c:
  _uStack0000000c = _uStack0000000c + (int)pbVar10;
  goto code_r0x00013f86;
  while( true ) {
    *pbVar5 = bVar1;
    iVar2 = unaff_r4[1];
    pbVar5 = pbVar5 + 1;
    unaff_r4[1] = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      iVar2 = FUN_00014b18(unaff_r4);
      if (iVar2 != 0) break;
    }
    else {
      *unaff_r4 = *unaff_r4 + 1;
    }
    pbStack00000004 = pbStack00000004 + -1;
    if (pbStack00000004 == (byte *)0x0) break;
LAB_00014682:
    bVar1 = *(byte *)*unaff_r4;
    if (bVar1 < 0x3a) {
      uVar7 = DAT_00014780;
      if (bVar1 < 0x30) {
        if (bVar1 != 0x2d) {
          if (bVar1 == 0x2e) {
            uVar7 = DAT_00014784;
            if ((int)(uVar12 << 0x10) < 0) goto LAB_000146b0;
            break;
          }
          if (bVar1 != 0x2b) break;
        }
        uVar7 = DAT_00014774;
        if (-1 < (int)(uVar12 << 0x13)) break;
      }
LAB_000146b0:
      uVar12 = uVar12 & uVar7;
    }
    else {
      if (((bVar1 != 0x45) && (bVar1 != 0x65)) || (((uint)puStack00000008 & uVar12) != 0x10000))
      break;
      uVar12 = uVar12 & DAT_00014788 | 0x5000;
    }
  }
  pbVar10 = pbVar5;
  if ((int)(uVar12 << 0x11) < 0) {
    if ((int)(uVar12 << 0xf) < 0) {
      while (&stack0x00000030 < pbVar5) {
        pbVar5 = pbVar5 + -1;
        FUN_00014c80(*pbVar5,unaff_r4);
      }
      FUN_000147b6();
      return;
    }
    pbVar10 = pbVar5 + -1;
    bVar1 = *pbVar10;
    if ((bVar1 != 0x45) && (bVar1 != 0x65)) {
      pbVar10 = pbVar5 + -2;
      FUN_00014c80(bVar1,unaff_r4);
      bVar1 = *pbVar10;
    }
    FUN_00014c80(bVar1,unaff_r4);
  }
  if ((uVar12 & 0x400) == 0) {
    *pbVar10 = 0;
    uVar15 = FUN_0000f670(&stack0x00000030,0);
    if ((int)(uVar12 << 0x1e) < 0) {
      *(undefined8 *)*puVar11 = uVar15;
    }
    else if ((int)(uVar12 << 0x1f) < 0) {
      *(undefined8 *)*puVar11 = uVar15;
    }
    else {
      uVar4 = FUN_0000970c();
      *(undefined4 *)*puVar11 = uVar4;
    }
    in_stack_00000014 = in_stack_00000014 + 1;
  }
  FUN_00013f86();
LAB_000147aa:
  if (in_stack_00000014 == 0) {
LAB_000147b0:
    in_stack_00000014 = -1;
  }
  if (in_stack_00000334 != **(int **)(in_stack_0000001c + DAT_000147d4)) {
    FUN_000107d0(in_stack_00000014);
  }
  return;
}



/* Function: FUN_000147b6 @ 000147b6 */

void FUN_000147b6(void)

{
  undefined4 in_stack_00000014;
  int in_stack_0000001c;
  int in_stack_00000334;
  
  if (in_stack_00000334 != **(int **)(in_stack_0000001c + DAT_000147d4)) {
    FUN_000107d0(in_stack_00000014);
  }
  return;
}



/* Function: FUN_000147d8 @ 000147d8 */

/* WARNING: Removing unreachable block (ram,0x000148ec) */

ulonglong FUN_000147d8(byte *param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int extraout_r2;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  ulonglong uVar14;
  longlong lVar15;
  int local_4c;
  int local_3c;
  byte *local_30;
  
  uVar14 = CONCAT44(DAT_0001497c,DAT_00014978);
  iVar10 = DAT_00014990 + 0x147e4;
  pbVar12 = param_1;
  do {
    pbVar11 = pbVar12;
    uVar13 = (uint)*pbVar11;
    pbVar12 = pbVar11 + 1;
  } while ((*(byte *)(**(int **)(iVar10 + DAT_00014994) + uVar13 + 1) & 8) != 0);
  if (uVar13 == 0x2d) {
    uVar13 = (uint)*pbVar12;
    pbVar12 = pbVar11 + 2;
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (uVar13 == 0x2b) {
      uVar13 = (uint)*pbVar12;
      pbVar12 = pbVar11 + 2;
    }
  }
  if ((param_3 == 0x10) || (param_3 == 0)) {
    if ((uVar13 != 0x30) || ((*pbVar12 != 0x58 && (*pbVar12 != 0x78)))) {
      if (param_3 != 0) goto LAB_00014848;
      param_3 = 10;
      if (uVar13 == 0x30) goto LAB_0001486a;
      goto LAB_00014856;
    }
    uVar13 = (uint)pbVar12[1];
    param_3 = 0x10;
    pbVar12 = pbVar12 + 2;
  }
  else {
LAB_00014848:
    if (param_3 == 10) {
LAB_00014856:
      local_3c = 5;
      goto LAB_0001489e;
    }
    if (param_3 != 0x10) {
      if (param_3 != 8) {
        uVar14 = FUN_000097dc(0xffffffff,0xffffffff,param_3,param_3 >> 0x1f);
        FUN_000097dc(0xffffffff,0xffffffff,param_3,param_3 >> 0x1f);
        local_3c = extraout_r2;
        goto LAB_0001489e;
      }
LAB_0001486a:
      param_3 = 8;
      local_3c = 7;
      uVar14 = CONCAT44(DAT_0001498c,DAT_00014988);
      goto LAB_0001489e;
    }
  }
  local_3c = 0xf;
  uVar14 = CONCAT44(DAT_00014984,DAT_00014980);
LAB_0001489e:
  iVar4 = DAT_00014994;
  iVar9 = 0;
  uVar3 = 0;
  do {
    iVar8 = (int)(uVar3 >> 0x20);
    iVar7 = (int)uVar3;
    uVar5 = uVar13 - 0x30;
    if (9 < uVar5) {
      bVar1 = *(byte *)(**(int **)(iVar10 + iVar4) + uVar13 + 1);
      if ((bVar1 & 3) == 0) {
LAB_00014942:
        if ((0 < iVar9) && (bVar2)) {
          uVar3 = CONCAT44(-(uint)(iVar7 != 0) - iVar8,-iVar7);
        }
        if (param_2 != (undefined4 *)0x0) {
          local_30 = param_1;
          if (iVar9 != 0) {
            local_30 = pbVar12 + -1;
          }
          *param_2 = local_30;
        }
        return uVar3;
      }
      local_4c = 0x37;
      if ((bVar1 & 1) == 0) {
        local_4c = 0x57;
      }
      uVar5 = uVar13 - local_4c;
    }
    if (param_3 <= (int)uVar5) goto LAB_00014942;
    if (iVar9 != -1) {
      if ((uVar14 < uVar3) || ((local_3c < (int)uVar5 && (uVar14 == uVar3)))) {
        puVar6 = (undefined4 *)FUN_000113b0();
        *puVar6 = 0x22;
        iVar9 = -1;
        uVar3 = 0xffffffffffffffff;
      }
      else {
        lVar15 = FUN_000097ac(iVar7,iVar8,param_3,param_3 >> 0x1f);
        uVar3 = lVar15 + (int)uVar5;
        iVar9 = 1;
      }
    }
    uVar13 = (uint)*pbVar12;
    pbVar12 = pbVar12 + 1;
  } while( true );
}



/* Function: FUN_000149b0 @ 000149b0 */

int FUN_000149b0(int param_1,int param_2,int param_3,int *param_4)

{
  ushort uVar1;
  undefined4 *puVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = param_3 * param_2;
  iVar6 = DAT_00014af0 + 0x149c0;
  if (uVar4 == 0) {
    return 0;
  }
  if (param_4[1] < 0) {
    param_4[1] = 0;
  }
  uVar7 = uVar4;
  if (((int)((uint)*(ushort *)(param_4 + 3) << 0x1e) < 0) && (param_4[0xf] == 0)) {
    if (**(int **)(iVar6 + DAT_00014af4) == 0) {
      FUN_0000bbe0();
    }
    uVar5 = (uint)*(ushort *)(param_4 + 3);
    param_4[1] = 0;
    if ((int)(uVar5 << 0x1a) < 0) {
      return -1;
    }
    if ((int)(uVar5 << 0x1d) < 0) {
      if (*(int **)param_4[0xc] != (int *)0x0) {
        if (*(int **)param_4[0xc] != param_4 + 0x10) {
          FUN_000113dc();
        }
        *(undefined4 *)param_4[0xc] = 0;
      }
    }
    else {
      if (-1 < (int)(uVar5 << 0x1b)) {
        puVar2 = (undefined4 *)FUN_000113b0();
        *puVar2 = 9;
        *(ushort *)(param_4 + 3) = *(ushort *)(param_4 + 3) | 0x40;
        return -1;
      }
      if ((*(ushort *)(param_4 + 3) & 8) != 0) {
        iVar6 = FUN_00011588(param_4);
        if (iVar6 != 0) {
          return -1;
        }
        param_4[2] = 0;
        param_4[6] = 0;
        *(ushort *)(param_4 + 3) = *(ushort *)(param_4 + 3) & 0xfff7;
      }
      *(ushort *)(param_4 + 3) = *(ushort *)(param_4 + 3) | 4;
    }
    if ((*(ushort *)(param_4 + 3) & 3) != 0) {
      FUN_0000bee8(DAT_00014af8 + 0x14a60);
    }
    while( true ) {
      iVar6 = (*(code *)param_4[9])(param_4[7],param_1,uVar7);
      uVar1 = *(ushort *)(param_4 + 3) & (ushort)DAT_00014afc;
      *(ushort *)(param_4 + 3) = uVar1;
      if (iVar6 < 1) break;
      if (uVar7 - iVar6 == 0) {
        return param_3;
      }
      param_1 = param_1 + iVar6;
      uVar7 = uVar7 - iVar6;
    }
    uVar3 = 0x20;
    if (iVar6 != 0) {
      uVar3 = 0x40;
    }
    *(ushort *)(param_4 + 3) = uVar1 | uVar3;
  }
  else {
    while( true ) {
      uVar5 = param_4[1];
      if (uVar7 <= uVar5) {
        FUN_00008170(param_1,*param_4,uVar7);
        param_4[1] = param_4[1] - uVar7;
        *param_4 = *param_4 + uVar7;
        return param_3;
      }
      FUN_00008170(param_1,*param_4,uVar5);
      *param_4 = *param_4 + uVar5;
      uVar7 = uVar7 - uVar5;
      iVar6 = FUN_00014b18(param_4);
      if (iVar6 != 0) break;
      param_1 = param_1 + uVar5;
    }
  }
  iVar6 = FUN_00008ba0(uVar4 - uVar7,param_2);
  return iVar6;
}



/* Function: FUN_00014b18 @ 00014b18 */

undefined4 FUN_00014b18(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  
  if (**(int **)(DAT_00014bf0 + 0x14b24 + DAT_00014bf4) == 0) {
    FUN_0000bbe0();
  }
  uVar6 = (uint)*(ushort *)(param_1 + 3);
  param_1[1] = 0;
  if (-1 < (int)(uVar6 << 0x1a)) {
    if ((int)(uVar6 << 0x1d) < 0) {
      if (*(undefined4 **)param_1[0xc] != (undefined4 *)0x0) {
        if (*(undefined4 **)param_1[0xc] != param_1 + 0x10) {
          FUN_000113dc();
        }
        iVar4 = param_1[0xf];
        *(undefined4 *)param_1[0xc] = 0;
        param_1[1] = iVar4;
        if (iVar4 != 0) {
          *param_1 = param_1[0xe];
          return 0;
        }
      }
    }
    else {
      if (-1 < (int)(uVar6 << 0x1b)) {
        puVar3 = (undefined4 *)FUN_000113b0();
        *puVar3 = 9;
        *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 0x40;
        return 0xffffffff;
      }
      if ((*(ushort *)(param_1 + 3) & 8) != 0) {
        iVar4 = FUN_00011588(param_1);
        if (iVar4 != 0) {
          return 0xffffffff;
        }
        param_1[2] = 0;
        param_1[6] = 0;
        *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) & 0xfff7;
      }
      *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) | 4;
    }
    if (param_1[4] == 0) {
      FUN_0001168c(param_1);
    }
    if ((*(ushort *)(param_1 + 3) & 3) != 0) {
      FUN_0000bee8(DAT_00014bf8 + 0x14bb8);
    }
    *param_1 = param_1[4];
    iVar4 = (*(code *)param_1[9])(param_1[7],param_1[4],param_1[5]);
    uVar2 = DAT_00014bfc;
    param_1[1] = iVar4;
    uVar1 = *(ushort *)(param_1 + 3) & (ushort)uVar2;
    *(ushort *)(param_1 + 3) = uVar1;
    if (0 < iVar4) {
      return 0;
    }
    uVar5 = 0x20;
    if (iVar4 != 0) {
      param_1[1] = 0;
      uVar5 = 0x40;
    }
    *(ushort *)(param_1 + 3) = uVar1 | uVar5;
  }
  return 0xffffffff;
}



/* Function: FUN_00014c00 @ 00014c00 */

undefined4 FUN_00014c00(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)param_1[0xc];
  if (piVar4 == param_1 + 0x10) {
    iVar1 = FUN_000113c0(0x400);
    iVar3 = DAT_00014c7c;
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    *(int *)param_1[0xc] = iVar1;
    puVar2 = (undefined1 *)(iVar1 + iVar3);
    *(undefined4 *)(param_1[0xc] + 4) = 0x400;
    puVar2[2] = *(undefined1 *)((int)param_1 + 0x42);
    puVar2[1] = *(undefined1 *)((int)param_1 + 0x41);
    *puVar2 = (char)*piVar4;
    *param_1 = (int)puVar2;
  }
  else {
    iVar1 = ((undefined4 *)param_1[0xc])[1];
    iVar3 = FUN_00011414(piVar4,iVar1 * 2);
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    FUN_00008170(iVar3 + iVar1,iVar3,iVar1);
    *param_1 = iVar3 + iVar1;
    *(int *)param_1[0xc] = iVar3;
    *(int *)(param_1[0xc] + 4) = iVar1 * 2;
  }
  return 0;
}



/* Function: FUN_00014c80 @ 00014c80 */

uint FUN_00014c80(uint param_1,uint *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  
  if (param_1 == 0xffffffff) {
    return 0xffffffff;
  }
  if (**(int **)(DAT_00014d48 + 0x14c8c + DAT_00014d4c) == 0) {
    FUN_0000bbe0();
  }
  uVar1 = (ushort)param_2[3];
  if ((int)((uint)uVar1 << 0x1d) < 0) {
LAB_00014cc8:
    uVar5 = param_1 & 0xff;
    if (*(int *)param_2[0xc] == 0) {
      *(ushort *)(param_2 + 3) = (ushort)param_2[3] & 0xffdf;
      if ((param_2[4] != 0) && (param_2[4] < *param_2)) {
        pbVar4 = (byte *)(*param_2 - 1);
        uVar3 = (uint)*pbVar4;
        if (uVar3 == uVar5) {
          *param_2 = (uint)pbVar4;
          param_2[1] = param_2[1] + 1;
          return uVar3;
        }
      }
      uVar3 = param_2[1];
      param_2[0xe] = *param_2;
      *(uint **)param_2[0xc] = param_2 + 0x10;
      param_2[0xf] = uVar3;
      *(undefined4 *)(param_2[0xc] + 4) = 3;
      *param_2 = (uint)((int)param_2 + 0x42);
      *(char *)((int)param_2 + 0x42) = (char)param_1;
      uVar3 = 1;
    }
    else {
      if ((((int *)param_2[0xc])[1] <= (int)param_2[1]) &&
         (iVar2 = FUN_00014c00(param_2), iVar2 != 0)) goto LAB_00014d40;
      uVar3 = *param_2;
      *param_2 = uVar3 - 1;
      *(char *)(uVar3 - 1) = (char)param_1;
      uVar3 = param_2[1] + 1;
    }
    param_2[1] = uVar3;
  }
  else {
    if ((int)((uint)uVar1 << 0x1b) < 0) {
      if ((uVar1 & 8) != 0) {
        iVar2 = FUN_00011588(param_2);
        if (iVar2 != 0) goto LAB_00014d40;
        param_2[2] = 0;
        param_2[6] = 0;
        *(ushort *)(param_2 + 3) = (ushort)param_2[3] & 0xfff7;
      }
      *(ushort *)(param_2 + 3) = (ushort)param_2[3] | 4;
      goto LAB_00014cc8;
    }
LAB_00014d40:
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



