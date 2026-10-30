package com.tencent.lbsapi.core;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.Random;

/* JADX INFO: renamed from: com.tencent.lbsapi.core.c */
/* JADX INFO: loaded from: classes.dex */
public class C1065c {

    /* JADX INFO: renamed from: a */
    public static final int f5946a = 79764919;

    /* JADX INFO: renamed from: b */
    public static final int f5947b = 2;

    /* JADX INFO: renamed from: c */
    public static final int f5948c = 7;

    /* JADX INFO: renamed from: d */
    private byte[] f5949d;

    /* JADX INFO: renamed from: e */
    private byte[] f5950e;

    /* JADX INFO: renamed from: f */
    private byte[] f5951f;

    /* JADX INFO: renamed from: g */
    private int f5952g;

    /* JADX INFO: renamed from: h */
    private int f5953h;

    /* JADX INFO: renamed from: i */
    private int f5954i;

    /* JADX INFO: renamed from: j */
    private int f5955j;

    /* JADX INFO: renamed from: k */
    private byte[] f5956k;

    /* JADX INFO: renamed from: m */
    private int f5958m;

    /* JADX INFO: renamed from: l */
    private boolean f5957l = true;

    /* JADX INFO: renamed from: n */
    private Random f5959n = new Random();

    /* JADX INFO: renamed from: a */
    public static long m2540a(byte[] bArr, int i, int i2) {
        long j = 0;
        int i3 = i2 > 8 ? i + 8 : i + i2;
        while (i < i3) {
            j = (j << 8) | ((long) (bArr[i] & 255));
            i++;
        }
        return (j >>> 32) | (4294967295L & j);
    }

    /* JADX INFO: renamed from: a */
    private void m2541a() {
        this.f5954i = 0;
        while (this.f5954i < 8) {
            if (this.f5957l) {
                byte[] bArr = this.f5949d;
                int i = this.f5954i;
                bArr[i] = (byte) (bArr[i] ^ this.f5950e[this.f5954i]);
            } else {
                byte[] bArr2 = this.f5949d;
                int i2 = this.f5954i;
                bArr2[i2] = (byte) (bArr2[i2] ^ this.f5951f[this.f5953h + this.f5954i]);
            }
            this.f5954i++;
        }
        System.arraycopy(m2542a(this.f5949d), 0, this.f5951f, this.f5952g, 8);
        this.f5954i = 0;
        while (this.f5954i < 8) {
            byte[] bArr3 = this.f5951f;
            int i3 = this.f5952g + this.f5954i;
            bArr3[i3] = (byte) (bArr3[i3] ^ this.f5950e[this.f5954i]);
            this.f5954i++;
        }
        System.arraycopy(this.f5949d, 0, this.f5950e, 0, 8);
        this.f5953h = this.f5952g;
        this.f5952g += 8;
        this.f5954i = 0;
        this.f5957l = false;
    }

    /* JADX INFO: renamed from: a */
    private byte[] m2542a(byte[] bArr) {
        int i = 16;
        try {
            long jM2540a = m2540a(bArr, 0, 4);
            long jM2540a2 = m2540a(bArr, 4, 4);
            long jM2540a3 = m2540a(this.f5956k, 0, 4);
            long jM2540a4 = m2540a(this.f5956k, 4, 4);
            long jM2540a5 = m2540a(this.f5956k, 8, 4);
            long jM2540a6 = m2540a(this.f5956k, 12, 4);
            long j = 0;
            while (true) {
                int i2 = i - 1;
                if (i <= 0) {
                    ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream(8);
                    DataOutputStream dataOutputStream = new DataOutputStream(byteArrayOutputStream);
                    dataOutputStream.writeInt((int) jM2540a);
                    dataOutputStream.writeInt((int) jM2540a2);
                    dataOutputStream.close();
                    return byteArrayOutputStream.toByteArray();
                }
                j = (j + 2654435769L) & 4294967295L;
                jM2540a = (jM2540a + ((((jM2540a2 << 4) + jM2540a3) ^ (jM2540a2 + j)) ^ ((jM2540a2 >>> 5) + jM2540a4))) & 4294967295L;
                jM2540a2 = (jM2540a2 + ((((jM2540a << 4) + jM2540a5) ^ (jM2540a + j)) ^ ((jM2540a >>> 5) + jM2540a6))) & 4294967295L;
                i = i2;
            }
        } catch (IOException e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    private byte[] m2543a(byte[] bArr, int i) {
        int i2 = 16;
        try {
            long jM2540a = m2540a(bArr, i, 4);
            long jM2540a2 = m2540a(bArr, i + 4, 4);
            long jM2540a3 = m2540a(this.f5956k, 0, 4);
            long jM2540a4 = m2540a(this.f5956k, 4, 4);
            long jM2540a5 = m2540a(this.f5956k, 8, 4);
            long jM2540a6 = m2540a(this.f5956k, 12, 4);
            long j = 3816266640L;
            while (true) {
                int i3 = i2 - 1;
                if (i2 <= 0) {
                    ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream(8);
                    DataOutputStream dataOutputStream = new DataOutputStream(byteArrayOutputStream);
                    dataOutputStream.writeInt((int) jM2540a);
                    dataOutputStream.writeInt((int) jM2540a2);
                    dataOutputStream.close();
                    return byteArrayOutputStream.toByteArray();
                }
                jM2540a2 = (jM2540a2 - ((((jM2540a << 4) + jM2540a5) ^ (jM2540a + j)) ^ ((jM2540a >>> 5) + jM2540a6))) & 4294967295L;
                jM2540a = (jM2540a - ((((jM2540a2 << 4) + jM2540a3) ^ (jM2540a2 + j)) ^ ((jM2540a2 >>> 5) + jM2540a4))) & 4294967295L;
                j = (j - 2654435769L) & 4294967295L;
                i2 = i3;
            }
        } catch (IOException e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: b */
    private boolean m2544b(byte[] bArr, int i, int i2) {
        this.f5954i = 0;
        while (this.f5954i < 8) {
            if (this.f5958m + this.f5954i >= i2) {
                return true;
            }
            byte[] bArr2 = this.f5950e;
            int i3 = this.f5954i;
            bArr2[i3] = (byte) (bArr2[i3] ^ bArr[(this.f5952g + i) + this.f5954i]);
            this.f5954i++;
        }
        this.f5950e = m2543a(this.f5950e, 0);
        if (this.f5950e == null) {
            return false;
        }
        this.f5958m += 8;
        this.f5952g += 8;
        this.f5954i = 0;
        return true;
    }

    /* JADX INFO: renamed from: a */
    public byte[] m2545a(byte[] bArr, int i, int i2, byte[] bArr2) {
        this.f5953h = 0;
        this.f5952g = 0;
        this.f5956k = bArr2;
        byte[] bArr3 = new byte[i + 8];
        if (i2 % 8 != 0 || i2 < 16) {
            return null;
        }
        this.f5950e = m2543a(bArr, i);
        this.f5954i = this.f5950e[0] & 7;
        int i3 = (i2 - this.f5954i) - 10;
        if (i3 < 0) {
            return null;
        }
        for (int i4 = i; i4 < bArr3.length; i4++) {
            bArr3[i4] = 0;
        }
        this.f5951f = new byte[i3];
        this.f5953h = 0;
        this.f5952g = 8;
        this.f5958m = 8;
        this.f5954i++;
        this.f5955j = 1;
        byte[] bArr4 = bArr3;
        while (this.f5955j <= 2) {
            if (this.f5954i < 8) {
                this.f5954i++;
                this.f5955j++;
            }
            if (this.f5954i == 8) {
                if (!m2544b(bArr, i, i2)) {
                    return null;
                }
                bArr4 = bArr;
            }
        }
        int i5 = i3;
        byte[] bArr5 = bArr4;
        int i6 = 0;
        byte[] bArr6 = bArr5;
        while (i5 != 0) {
            if (this.f5954i < 8) {
                this.f5951f[i6] = (byte) (bArr6[(this.f5953h + i) + this.f5954i] ^ this.f5950e[this.f5954i]);
                i6++;
                i5--;
                this.f5954i++;
            }
            if (this.f5954i == 8) {
                this.f5953h = this.f5952g - 8;
                if (!m2544b(bArr, i, i2)) {
                    return null;
                }
                bArr6 = bArr;
            }
        }
        this.f5955j = 1;
        byte[] bArr7 = bArr6;
        while (this.f5955j < 8) {
            if (this.f5954i < 8) {
                if ((bArr7[(this.f5953h + i) + this.f5954i] ^ this.f5950e[this.f5954i]) != 0) {
                    return null;
                }
                this.f5954i++;
            }
            if (this.f5954i == 8) {
                this.f5953h = this.f5952g;
                if (!m2544b(bArr, i, i2)) {
                    return null;
                }
                bArr7 = bArr;
            }
            this.f5955j++;
        }
        return this.f5951f;
    }

    /* JADX INFO: renamed from: a */
    public byte[] m2546a(byte[] bArr, byte[] bArr2) {
        return m2545a(bArr, 0, bArr.length, bArr2);
    }

    /* JADX INFO: renamed from: b */
    public byte[] m2547b(byte[] bArr, int i, int i2, byte[] bArr2) {
        this.f5949d = new byte[8];
        this.f5950e = new byte[8];
        this.f5954i = 1;
        this.f5955j = 0;
        this.f5953h = 0;
        this.f5952g = 0;
        this.f5956k = bArr2;
        this.f5957l = true;
        this.f5954i = (i2 + 10) % 8;
        if (this.f5954i != 0) {
            this.f5954i = 8 - this.f5954i;
        }
        this.f5951f = new byte[this.f5954i + i2 + 10];
        this.f5949d[0] = (byte) ((this.f5959n.nextInt() & 248) | this.f5954i);
        for (int i3 = 1; i3 <= this.f5954i; i3++) {
            this.f5949d[i3] = (byte) (this.f5959n.nextInt() & 255);
        }
        this.f5954i++;
        for (int i4 = 0; i4 < 8; i4++) {
            this.f5950e[i4] = 0;
        }
        this.f5955j = 1;
        while (this.f5955j <= 2) {
            if (this.f5954i < 8) {
                byte[] bArr3 = this.f5949d;
                int i5 = this.f5954i;
                this.f5954i = i5 + 1;
                bArr3[i5] = (byte) (this.f5959n.nextInt() & 255);
                this.f5955j++;
            }
            if (this.f5954i == 8) {
                m2541a();
            }
        }
        int i6 = i;
        int i7 = i2;
        while (i7 > 0) {
            if (this.f5954i < 8) {
                byte[] bArr4 = this.f5949d;
                int i8 = this.f5954i;
                this.f5954i = i8 + 1;
                i6++;
                bArr4[i8] = bArr[i6];
                i7--;
            } else {
                i6 = i6;
                i7 = i7;
            }
            if (this.f5954i == 8) {
                m2541a();
            }
        }
        this.f5955j = 1;
        while (this.f5955j <= 7) {
            if (this.f5954i < 8) {
                byte[] bArr5 = this.f5949d;
                int i9 = this.f5954i;
                this.f5954i = i9 + 1;
                bArr5[i9] = 0;
                this.f5955j++;
            }
            if (this.f5954i == 8) {
                m2541a();
            }
        }
        return this.f5951f;
    }

    /* JADX INFO: renamed from: b */
    public byte[] m2548b(byte[] bArr, byte[] bArr2) {
        return m2547b(bArr, 0, bArr.length, bArr2);
    }
}
