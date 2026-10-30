package com.lenovo.safecenter.encoders;

/* JADX INFO: loaded from: classes.dex */
public class MD5UtilWFL {

    /* JADX INFO: renamed from: a */
    static final byte[] f3555a = {-128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    public String digestHexStr;

    /* JADX INFO: renamed from: b */
    private long[] f3556b = new long[4];

    /* JADX INFO: renamed from: c */
    private long[] f3557c = new long[2];

    /* JADX INFO: renamed from: d */
    private byte[] f3558d = new byte[64];

    /* JADX INFO: renamed from: e */
    private byte[] f3559e = new byte[16];

    public String getMD5ofStr(String inbuf) {
        m1503a();
        m1505a(inbuf.getBytes(), inbuf.length());
        byte[] bArr = new byte[8];
        m1507a(bArr, this.f3557c, 8);
        int i = ((int) (this.f3557c[0] >>> 3)) & 63;
        m1505a(f3555a, i < 56 ? 56 - i : 120 - i);
        m1505a(bArr, 8);
        m1507a(this.f3559e, this.f3556b, 16);
        this.digestHexStr = "";
        for (int i2 = 0; i2 < 16; i2++) {
            this.digestHexStr += byteHEX(this.f3559e[i2]);
        }
        return this.digestHexStr;
    }

    public MD5UtilWFL() {
        m1503a();
    }

    /* JADX INFO: renamed from: a */
    private void m1503a() {
        this.f3557c[0] = 0;
        this.f3557c[1] = 0;
        this.f3556b[0] = 1732584193;
        this.f3556b[1] = 4023233417L;
        this.f3556b[2] = 2562383102L;
        this.f3556b[3] = 271733878;
    }

    /* JADX INFO: renamed from: a */
    private static long m1502a(long a, long b, long c, long d, long x, long s, long ac) {
        long a2 = a + ((b & c) | (((-1) ^ b) & d)) + x + ac;
        return ((long) ((((int) a2) << ((int) s)) | (((int) a2) >>> ((int) (32 - s))))) + b;
    }

    /* JADX INFO: renamed from: b */
    private static long m1508b(long a, long b, long c, long d, long x, long s, long ac) {
        long a2 = a + ((b & d) | (((-1) ^ d) & c)) + x + ac;
        return ((long) ((((int) a2) << ((int) s)) | (((int) a2) >>> ((int) (32 - s))))) + b;
    }

    /* JADX INFO: renamed from: c */
    private static long m1509c(long a, long b, long c, long d, long x, long s, long ac) {
        long a2 = a + ((b ^ c) ^ d) + x + ac;
        return ((long) ((((int) a2) << ((int) s)) | (((int) a2) >>> ((int) (32 - s))))) + b;
    }

    /* JADX INFO: renamed from: d */
    private static long m1510d(long a, long b, long c, long d, long x, long s, long ac) {
        long a2 = a + ((((-1) ^ d) | b) ^ c) + x + ac;
        return ((long) ((((int) a2) << ((int) s)) | (((int) a2) >>> ((int) (32 - s))))) + b;
    }

    /* JADX INFO: renamed from: a */
    private void m1505a(byte[] inbuf, int inputLen) {
        int i;
        byte[] block = new byte[64];
        int index = ((int) (this.f3557c[0] >>> 3)) & 63;
        long[] jArr = this.f3557c;
        long j = jArr[0] + ((long) (inputLen << 3));
        jArr[0] = j;
        if (j < (inputLen << 3)) {
            long[] jArr2 = this.f3557c;
            jArr2[1] = jArr2[1] + 1;
        }
        long[] jArr3 = this.f3557c;
        jArr3[1] = jArr3[1] + ((long) (inputLen >>> 29));
        int partLen = 64 - index;
        if (inputLen >= partLen) {
            m1506a(this.f3558d, inbuf, index, 0, partLen);
            m1504a(this.f3558d);
            i = partLen;
            while (i + 63 < inputLen) {
                m1506a(block, inbuf, 0, i, 64);
                m1504a(block);
                i += 64;
            }
            index = 0;
        } else {
            i = 0;
        }
        m1506a(this.f3558d, inbuf, index, i, inputLen - i);
    }

    /* JADX INFO: renamed from: a */
    private static void m1506a(byte[] output, byte[] input, int outpos, int inpos, int len) {
        for (int i = 0; i < len; i++) {
            output[outpos + i] = input[inpos + i];
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1504a(byte[] block) {
        long a = this.f3556b[0];
        long b = this.f3556b[1];
        long c = this.f3556b[2];
        long d = this.f3556b[3];
        long[] x = new long[16];
        int i = 0;
        for (int i2 = 0; i2 < 64; i2 += 4) {
            x[i] = b2iu(block[i2]) | (b2iu(block[i2 + 1]) << 8) | (b2iu(block[i2 + 2]) << 16) | (b2iu(block[i2 + 3]) << 24);
            i++;
        }
        long a2 = m1502a(a, b, c, d, x[0], 7L, 3614090360L);
        long d2 = m1502a(d, a2, b, c, x[1], 12L, 3905402710L);
        long c2 = m1502a(c, d2, a2, b, x[2], 17L, 606105819L);
        long b2 = m1502a(b, c2, d2, a2, x[3], 22L, 3250441966L);
        long a3 = m1502a(a2, b2, c2, d2, x[4], 7L, 4118548399L);
        long d3 = m1502a(d2, a3, b2, c2, x[5], 12L, 1200080426L);
        long c3 = m1502a(c2, d3, a3, b2, x[6], 17L, 2821735955L);
        long b3 = m1502a(b2, c3, d3, a3, x[7], 22L, 4249261313L);
        long a4 = m1502a(a3, b3, c3, d3, x[8], 7L, 1770035416L);
        long d4 = m1502a(d3, a4, b3, c3, x[9], 12L, 2336552879L);
        long c4 = m1502a(c3, d4, a4, b3, x[10], 17L, 4294925233L);
        long b4 = m1502a(b3, c4, d4, a4, x[11], 22L, 2304563134L);
        long a5 = m1502a(a4, b4, c4, d4, x[12], 7L, 1804603682L);
        long d5 = m1502a(d4, a5, b4, c4, x[13], 12L, 4254626195L);
        long c5 = m1502a(c4, d5, a5, b4, x[14], 17L, 2792965006L);
        long b5 = m1502a(b4, c5, d5, a5, x[15], 22L, 1236535329L);
        long a6 = m1508b(a5, b5, c5, d5, x[1], 5L, 4129170786L);
        long d6 = m1508b(d5, a6, b5, c5, x[6], 9L, 3225465664L);
        long c6 = m1508b(c5, d6, a6, b5, x[11], 14L, 643717713L);
        long b6 = m1508b(b5, c6, d6, a6, x[0], 20L, 3921069994L);
        long a7 = m1508b(a6, b6, c6, d6, x[5], 5L, 3593408605L);
        long d7 = m1508b(d6, a7, b6, c6, x[10], 9L, 38016083L);
        long c7 = m1508b(c6, d7, a7, b6, x[15], 14L, 3634488961L);
        long b7 = m1508b(b6, c7, d7, a7, x[4], 20L, 3889429448L);
        long a8 = m1508b(a7, b7, c7, d7, x[9], 5L, 568446438L);
        long d8 = m1508b(d7, a8, b7, c7, x[14], 9L, 3275163606L);
        long c8 = m1508b(c7, d8, a8, b7, x[3], 14L, 4107603335L);
        long b8 = m1508b(b7, c8, d8, a8, x[8], 20L, 1163531501L);
        long a9 = m1508b(a8, b8, c8, d8, x[13], 5L, 2850285829L);
        long d9 = m1508b(d8, a9, b8, c8, x[2], 9L, 4243563512L);
        long c9 = m1508b(c8, d9, a9, b8, x[7], 14L, 1735328473L);
        long b9 = m1508b(b8, c9, d9, a9, x[12], 20L, 2368359562L);
        long a10 = m1509c(a9, b9, c9, d9, x[5], 4L, 4294588738L);
        long d10 = m1509c(d9, a10, b9, c9, x[8], 11L, 2272392833L);
        long c10 = m1509c(c9, d10, a10, b9, x[11], 16L, 1839030562L);
        long b10 = m1509c(b9, c10, d10, a10, x[14], 23L, 4259657740L);
        long a11 = m1509c(a10, b10, c10, d10, x[1], 4L, 2763975236L);
        long d11 = m1509c(d10, a11, b10, c10, x[4], 11L, 1272893353L);
        long c11 = m1509c(c10, d11, a11, b10, x[7], 16L, 4139469664L);
        long b11 = m1509c(b10, c11, d11, a11, x[10], 23L, 3200236656L);
        long a12 = m1509c(a11, b11, c11, d11, x[13], 4L, 681279174L);
        long d12 = m1509c(d11, a12, b11, c11, x[0], 11L, 3936430074L);
        long c12 = m1509c(c11, d12, a12, b11, x[3], 16L, 3572445317L);
        long b12 = m1509c(b11, c12, d12, a12, x[6], 23L, 76029189L);
        long a13 = m1509c(a12, b12, c12, d12, x[9], 4L, 3654602809L);
        long d13 = m1509c(d12, a13, b12, c12, x[12], 11L, 3873151461L);
        long c13 = m1509c(c12, d13, a13, b12, x[15], 16L, 530742520L);
        long b13 = m1509c(b12, c13, d13, a13, x[2], 23L, 3299628645L);
        long a14 = m1510d(a13, b13, c13, d13, x[0], 6L, 4096336452L);
        long d14 = m1510d(d13, a14, b13, c13, x[7], 10L, 1126891415L);
        long c14 = m1510d(c13, d14, a14, b13, x[14], 15L, 2878612391L);
        long b14 = m1510d(b13, c14, d14, a14, x[5], 21L, 4237533241L);
        long a15 = m1510d(a14, b14, c14, d14, x[12], 6L, 1700485571L);
        long d15 = m1510d(d14, a15, b14, c14, x[3], 10L, 2399980690L);
        long c15 = m1510d(c14, d15, a15, b14, x[10], 15L, 4293915773L);
        long b15 = m1510d(b14, c15, d15, a15, x[1], 21L, 2240044497L);
        long a16 = m1510d(a15, b15, c15, d15, x[8], 6L, 1873313359L);
        long d16 = m1510d(d15, a16, b15, c15, x[15], 10L, 4264355552L);
        long c16 = m1510d(c15, d16, a16, b15, x[6], 15L, 2734768916L);
        long b16 = m1510d(b15, c16, d16, a16, x[13], 21L, 1309151649L);
        long a17 = m1510d(a16, b16, c16, d16, x[4], 6L, 4149444226L);
        long d17 = m1510d(d16, a17, b16, c16, x[11], 10L, 3174756917L);
        long c17 = m1510d(c16, d17, a17, b16, x[2], 15L, 718787259L);
        long b17 = m1510d(b16, c17, d17, a17, x[9], 21L, 3951481745L);
        long[] jArr = this.f3556b;
        jArr[0] = jArr[0] + a17;
        long[] jArr2 = this.f3556b;
        jArr2[1] = jArr2[1] + b17;
        long[] jArr3 = this.f3556b;
        jArr3[2] = jArr3[2] + c17;
        long[] jArr4 = this.f3556b;
        jArr4[3] = jArr4[3] + d17;
    }

    /* JADX INFO: renamed from: a */
    private static void m1507a(byte[] output, long[] input, int len) {
        int i = 0;
        for (int j = 0; j < len; j += 4) {
            output[j] = (byte) (input[i] & 255);
            output[j + 1] = (byte) ((input[i] >>> 8) & 255);
            output[j + 2] = (byte) ((input[i] >>> 16) & 255);
            output[j + 3] = (byte) ((input[i] >>> 24) & 255);
            i++;
        }
    }

    public static long b2iu(byte b) {
        return b < 0 ? b & 255 : b;
    }

    public static String byteHEX(byte ib) {
        char[] Digit = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        char[] ob = {Digit[(ib >>> 4) & 15], Digit[ib & 15]};
        String s = new String(ob);
        return s;
    }
}
