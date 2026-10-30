package com.tencent.tmsecure.utils;

import java.io.UnsupportedEncodingException;

/* JADX INFO: loaded from: classes.dex */
public class Base64 {
    public static final int CRLF = 4;
    public static final int DEFAULT = 0;
    public static final int NO_CLOSE = 16;
    public static final int NO_PADDING = 1;
    public static final int NO_WRAP = 2;
    public static final int URL_SAFE = 8;

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f6254a;

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.Base64$a */
    static abstract class AbstractC1078a {

        /* JADX INFO: renamed from: a */
        public byte[] f6255a;

        /* JADX INFO: renamed from: b */
        public int f6256b;

        AbstractC1078a() {
        }
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.Base64$b */
    static class C1079b extends AbstractC1078a {

        /* JADX INFO: renamed from: c */
        private static final int[] f6257c = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

        /* JADX INFO: renamed from: d */
        private static final int[] f6258d = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -2, -1, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, 63, -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

        /* JADX INFO: renamed from: e */
        private int f6259e;

        /* JADX INFO: renamed from: f */
        private int f6260f;

        /* JADX INFO: renamed from: g */
        private final int[] f6261g;

        public C1079b(int i, byte[] bArr) {
            this.f6255a = bArr;
            this.f6261g = (i & 8) == 0 ? f6257c : f6258d;
            this.f6259e = 0;
            this.f6260f = 0;
        }

        /* JADX INFO: renamed from: a */
        public final boolean m2631a(byte[] bArr, int i, int i2) {
            int i3;
            if (this.f6259e == 6) {
                return false;
            }
            int i4 = i2 + i;
            int i5 = this.f6259e;
            int i6 = this.f6260f;
            int i7 = 0;
            byte[] bArr2 = this.f6255a;
            int[] iArr = this.f6261g;
            int i8 = i;
            while (true) {
                if (i8 < i4) {
                    if (i5 == 0) {
                        while (i8 + 4 <= i4 && (i6 = (iArr[bArr[i8] & 255] << 18) | (iArr[bArr[i8 + 1] & 255] << 12) | (iArr[bArr[i8 + 2] & 255] << 6) | iArr[bArr[i8 + 3] & 255]) >= 0) {
                            bArr2[i7 + 2] = (byte) i6;
                            bArr2[i7 + 1] = (byte) (i6 >> 8);
                            bArr2[i7] = (byte) (i6 >> 16);
                            i7 += 3;
                            i8 += 4;
                        }
                        if (i8 >= i4) {
                            i3 = i6;
                        }
                    }
                    int i9 = i8 + 1;
                    int i10 = iArr[bArr[i8] & 255];
                    switch (i5) {
                        case 0:
                            if (i10 >= 0) {
                                i5++;
                                i6 = i10;
                            } else if (i10 != -1) {
                                this.f6259e = 6;
                                return false;
                            }
                            i5 = i5;
                            i8 = i9;
                            break;
                        case 1:
                            if (i10 >= 0) {
                                i6 = (i6 << 6) | i10;
                                i5++;
                            } else if (i10 != -1) {
                                this.f6259e = 6;
                                return false;
                            }
                            i5 = i5;
                            i8 = i9;
                            break;
                        case 2:
                            if (i10 >= 0) {
                                i6 = (i6 << 6) | i10;
                                i5++;
                            } else if (i10 == -2) {
                                bArr2[i7] = (byte) (i6 >> 4);
                                i5 = 4;
                                i7++;
                            } else if (i10 != -1) {
                                this.f6259e = 6;
                                return false;
                            }
                            i5 = i5;
                            i8 = i9;
                            break;
                        case 3:
                            if (i10 >= 0) {
                                i6 = (i6 << 6) | i10;
                                bArr2[i7 + 2] = (byte) i6;
                                bArr2[i7 + 1] = (byte) (i6 >> 8);
                                bArr2[i7] = (byte) (i6 >> 16);
                                i7 += 3;
                                i5 = 0;
                            } else if (i10 == -2) {
                                bArr2[i7 + 1] = (byte) (i6 >> 2);
                                bArr2[i7] = (byte) (i6 >> 10);
                                i7 += 2;
                                i5 = 5;
                            } else if (i10 != -1) {
                                this.f6259e = 6;
                                return false;
                            }
                            i5 = i5;
                            i8 = i9;
                            break;
                        case 4:
                            if (i10 == -2) {
                                i5++;
                            } else if (i10 != -1) {
                                this.f6259e = 6;
                                return false;
                            }
                            i5 = i5;
                            i8 = i9;
                            break;
                        case 5:
                            if (i10 != -1) {
                                this.f6259e = 6;
                                return false;
                            }
                            i5 = i5;
                            i8 = i9;
                            break;
                        default:
                            i5 = i5;
                            i8 = i9;
                            break;
                    }
                } else {
                    i3 = i6;
                }
            }
            switch (i5) {
                case 1:
                    this.f6259e = 6;
                    return false;
                case 2:
                    bArr2[i7] = (byte) (i3 >> 4);
                    i7++;
                    break;
                case 3:
                    int i11 = i7 + 1;
                    bArr2[i7] = (byte) (i3 >> 10);
                    i7 = i11 + 1;
                    bArr2[i11] = (byte) (i3 >> 2);
                    break;
                case 4:
                    this.f6259e = 6;
                    return false;
            }
            this.f6259e = i5;
            this.f6256b = i7;
            return true;
        }
    }

    /* JADX INFO: renamed from: com.tencent.tmsecure.utils.Base64$c */
    static class C1080c extends AbstractC1078a {

        /* JADX INFO: renamed from: g */
        static final /* synthetic */ boolean f6262g;

        /* JADX INFO: renamed from: h */
        private static final byte[] f6263h;

        /* JADX INFO: renamed from: i */
        private static final byte[] f6264i;

        /* JADX INFO: renamed from: c */
        int f6265c;

        /* JADX INFO: renamed from: d */
        public final boolean f6266d;

        /* JADX INFO: renamed from: e */
        public final boolean f6267e;

        /* JADX INFO: renamed from: f */
        public final boolean f6268f;

        /* JADX INFO: renamed from: j */
        private final byte[] f6269j;

        /* JADX INFO: renamed from: k */
        private int f6270k;

        /* JADX INFO: renamed from: l */
        private final byte[] f6271l;

        static {
            f6262g = !Base64.class.desiredAssertionStatus();
            f6263h = new byte[]{65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 43, 47};
            f6264i = new byte[]{65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 45, 95};
        }

        public C1080c(int i) {
            this.f6255a = null;
            this.f6266d = (i & 1) == 0;
            this.f6267e = (i & 2) == 0;
            this.f6268f = (i & 4) != 0;
            this.f6271l = (i & 8) == 0 ? f6263h : f6264i;
            this.f6269j = new byte[2];
            this.f6265c = 0;
            this.f6270k = this.f6267e ? 19 : -1;
        }

        /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
        /* JADX WARN: Code duplicated, block: B:4:0x000f  */
        /* JADX INFO: renamed from: a */
        public final boolean m2632a(byte[] bArr, int i, int i2) {
            int i3;
            int i4;
            int i5;
            int i6;
            byte b;
            byte b2;
            int i7;
            byte b3;
            int i8;
            byte[] bArr2 = this.f6271l;
            byte[] bArr3 = this.f6255a;
            int i9 = 0;
            int i10 = this.f6270k;
            int i11 = i2 + i;
            switch (this.f6265c) {
                case 0:
                    i4 = -1;
                    i3 = i;
                    break;
                case 1:
                    if (i + 2 > i11) {
                        i4 = -1;
                        i3 = i;
                    } else {
                        int i12 = i + 1;
                        int i13 = ((this.f6269j[0] & 255) << 16) | ((bArr[i] & 255) << 8) | (bArr[i12] & 255);
                        this.f6265c = 0;
                        i4 = i13;
                        i3 = i12 + 1;
                    }
                    break;
                case 2:
                    if (i + 1 > i11) {
                        i4 = -1;
                        i3 = i;
                    } else {
                        i3 = i + 1;
                        int i14 = ((this.f6269j[0] & 255) << 16) | ((this.f6269j[1] & 255) << 8) | (bArr[i] & 255);
                        this.f6265c = 0;
                        i4 = i14;
                    }
                    break;
                default:
                    i4 = -1;
                    i3 = i;
                    break;
            }
            if (i4 != -1) {
                bArr3[0] = bArr2[(i4 >> 18) & 63];
                bArr3[1] = bArr2[(i4 >> 12) & 63];
                bArr3[2] = bArr2[(i4 >> 6) & 63];
                int i15 = 4;
                bArr3[3] = bArr2[i4 & 63];
                int i16 = i10 - 1;
                if (i16 == 0) {
                    if (this.f6268f) {
                        i15 = 5;
                        bArr3[4] = 13;
                    }
                    i9 = i15 + 1;
                    bArr3[i15] = 10;
                    i5 = 19;
                } else {
                    i5 = i16;
                    i9 = 4;
                }
            } else {
                i5 = i10;
            }
            while (i3 + 3 <= i11) {
                int i17 = ((bArr[i3] & 255) << 16) | ((bArr[i3 + 1] & 255) << 8) | (bArr[i3 + 2] & 255);
                bArr3[i9] = bArr2[(i17 >> 18) & 63];
                bArr3[i9 + 1] = bArr2[(i17 >> 12) & 63];
                bArr3[i9 + 2] = bArr2[(i17 >> 6) & 63];
                bArr3[i9 + 3] = bArr2[i17 & 63];
                i3 += 3;
                int i18 = i9 + 4;
                int i19 = i5 - 1;
                if (i19 == 0) {
                    if (this.f6268f) {
                        i8 = i18 + 1;
                        bArr3[i18] = 13;
                    } else {
                        i8 = i18;
                    }
                    i9 = i8 + 1;
                    bArr3[i8] = 10;
                    i5 = 19;
                } else {
                    i5 = i19;
                    i9 = i18;
                }
            }
            if (i3 - this.f6265c == i11 - 1) {
                int i20 = 0;
                if (this.f6265c > 0) {
                    i20 = 1;
                    b3 = this.f6269j[0];
                } else {
                    b3 = bArr[i3];
                    i3++;
                }
                int i21 = (b3 & 255) << 4;
                this.f6265c -= i20;
                int i22 = i9 + 1;
                bArr3[i9] = bArr2[(i21 >> 6) & 63];
                int i23 = i22 + 1;
                bArr3[i22] = bArr2[i21 & 63];
                if (this.f6266d) {
                    int i24 = i23 + 1;
                    bArr3[i23] = 61;
                    i23 = i24 + 1;
                    bArr3[i24] = 61;
                }
                if (this.f6267e) {
                    if (this.f6268f) {
                        bArr3[i23] = 13;
                        i23++;
                    }
                    bArr3[i23] = 10;
                    i23++;
                }
                i9 = i23;
            } else if (i3 - this.f6265c == i11 - 2) {
                int i25 = 0;
                if (this.f6265c > 1) {
                    i25 = 1;
                    b = this.f6269j[0];
                } else {
                    b = bArr[i3];
                    i3++;
                }
                int i26 = (b & 255) << 10;
                if (this.f6265c > 0) {
                    b2 = this.f6269j[i25];
                    i25++;
                } else {
                    b2 = bArr[i3];
                    i3++;
                }
                int i27 = ((b2 & 255) << 2) | i26;
                this.f6265c -= i25;
                int i28 = i9 + 1;
                bArr3[i9] = bArr2[(i27 >> 12) & 63];
                int i29 = i28 + 1;
                bArr3[i28] = bArr2[(i27 >> 6) & 63];
                int i30 = i29 + 1;
                bArr3[i29] = bArr2[i27 & 63];
                if (this.f6266d) {
                    i7 = i30 + 1;
                    bArr3[i30] = 61;
                } else {
                    i7 = i30;
                }
                if (this.f6267e) {
                    if (this.f6268f) {
                        bArr3[i7] = 13;
                        i7++;
                    }
                    bArr3[i7] = 10;
                    i7++;
                }
                i9 = i7;
            } else if (this.f6267e && i9 > 0 && i5 != 19) {
                if (this.f6268f) {
                    i6 = i9 + 1;
                    bArr3[i9] = 13;
                } else {
                    i6 = i9;
                }
                i9 = i6 + 1;
                bArr3[i6] = 10;
            }
            if (!f6262g && this.f6265c != 0) {
                throw new AssertionError();
            }
            if (!f6262g && i3 != i11) {
                throw new AssertionError();
            }
            this.f6256b = i9;
            this.f6270k = i5;
            return true;
        }
    }

    static {
        f6254a = !Base64.class.desiredAssertionStatus();
    }

    private Base64() {
    }

    public static byte[] decode(String str, int i) {
        return decode(str.getBytes(), i);
    }

    public static byte[] decode(byte[] bArr, int i) {
        return decode(bArr, 0, bArr.length, i);
    }

    public static byte[] decode(byte[] bArr, int i, int i2, int i3) {
        C1079b c1079b = new C1079b(i3, new byte[(i2 * 3) / 4]);
        if (!c1079b.m2631a(bArr, i, i2)) {
            throw new IllegalArgumentException("bad base-64");
        }
        if (c1079b.f6256b == c1079b.f6255a.length) {
            return c1079b.f6255a;
        }
        byte[] bArr2 = new byte[c1079b.f6256b];
        System.arraycopy(c1079b.f6255a, 0, bArr2, 0, c1079b.f6256b);
        return bArr2;
    }

    public static byte[] encode(byte[] bArr, int i) {
        return encode(bArr, 0, bArr.length, i);
    }

    public static byte[] encode(byte[] bArr, int i, int i2, int i3) {
        C1080c c1080c = new C1080c(i3);
        int i4 = (i2 / 3) * 4;
        if (!c1080c.f6266d) {
            switch (i2 % 3) {
                case 1:
                    i4 += 2;
                    break;
                case 2:
                    i4 += 3;
                    break;
            }
        } else if (i2 % 3 > 0) {
            i4 += 4;
        }
        if (c1080c.f6267e && i2 > 0) {
            i4 += (c1080c.f6268f ? 2 : 1) * (((i2 - 1) / 57) + 1);
        }
        c1080c.f6255a = new byte[i4];
        c1080c.m2632a(bArr, i, i2);
        if (f6254a || c1080c.f6256b == i4) {
            return c1080c.f6255a;
        }
        throw new AssertionError();
    }

    public static String encodeToString(byte[] bArr, int i) {
        try {
            return new String(encode(bArr, i), "US-ASCII");
        } catch (UnsupportedEncodingException e) {
            throw new AssertionError(e);
        }
    }

    public static String encodeToString(byte[] bArr, int i, int i2, int i3) {
        try {
            return new String(encode(bArr, i, i2, i3), "US-ASCII");
        } catch (UnsupportedEncodingException e) {
            throw new AssertionError(e);
        }
    }
}
