package tms;

import android.os.SystemClock;
import com.tencent.tmsecure.exception.BadExpiryDataException;
import com.tencent.tmsecure.utils.SDKUtil;
import java.lang.reflect.Array;
import java.security.SecureRandom;

/* JADX INFO: renamed from: tms.bo */
/* JADX INFO: loaded from: classes.dex */
final class C1185bo {

    /* JADX INFO: renamed from: a */
    private int f6934a;

    /* JADX INFO: renamed from: b */
    private long f6935b;

    /* JADX INFO: renamed from: c */
    private long f6936c;

    C1185bo(boolean z) {
        int iNextInt;
        int i;
        C1329o.m3531a(C1278f.class);
        SecureRandom secureRandom = new SecureRandom(("" + SystemClock.uptimeMillis() + (((long) SDKUtil.getSDKVersion()) * ((long) System.getProperty("os.version", "wtf").hashCode()))).getBytes());
        do {
            iNextInt = secureRandom.nextInt(900) + 101;
        } while (m3006a(iNextInt));
        this.f6934a = iNextInt;
        int i2 = this.f6934a;
        int[] iArr = new int[100];
        double dSqrt = Math.sqrt(i2);
        int i3 = ((int) dSqrt) - 1;
        while ((i3 + 1) * (i3 + 1) <= i2) {
            i3++;
        }
        iArr[0] = i3;
        if (i3 * i3 == i2) {
            return;
        }
        int i4 = 1;
        int[] iArr2 = {0, 1, 0, -iArr[0], 1};
        int[][] iArr3 = (int[][]) Array.newInstance((Class<?>) Integer.TYPE, 100, 5);
        int i5 = 0;
        int i6 = 0;
        while (true) {
            if (i4 >= 100) {
                i = i5;
                break;
            }
            if (iArr2[1] < 0) {
                iArr2[1] = -iArr2[1];
                iArr2[2] = -iArr2[2];
                iArr2[3] = -iArr2[3];
                iArr2[4] = -iArr2[4];
            }
            int iM3005a = m3005a(m3005a(m3005a(iArr2[1], Math.abs(iArr2[2])), Math.abs(iArr2[3])), Math.abs(iArr2[4]));
            if (iM3005a > 1) {
                iArr2[1] = iArr2[1] / iM3005a;
                iArr2[2] = iArr2[2] / iM3005a;
                iArr2[3] = iArr2[3] / iM3005a;
                iArr2[4] = iArr2[4] / iM3005a;
            }
            i5 = 0;
            while (i5 < i6) {
                int[] iArr4 = iArr3[i5];
                if (iArr4[1] == iArr2[1] && iArr4[2] == iArr2[2] && iArr4[3] == iArr2[3] && iArr4[4] == iArr2[4]) {
                    break;
                } else {
                    i5++;
                }
            }
            if (i5 < i6) {
                i = i5;
                break;
            }
            iArr3[i6][1] = iArr2[1];
            iArr3[i6][2] = iArr2[2];
            iArr3[i6][3] = iArr2[3];
            iArr3[i6][4] = iArr2[4];
            i6++;
            iArr[i4] = (int) Math.floor((((double) iArr2[1]) + (((double) iArr2[2]) * dSqrt)) / (((double) iArr2[3]) + (((double) iArr2[4]) * dSqrt)));
            int i7 = iArr[i4];
            iArr2[1] = iArr2[1] - (iArr2[3] * i7);
            iArr2[2] = iArr2[2] - (i7 * iArr2[4]);
            int i8 = (iArr2[1] * iArr2[3]) - ((iArr2[2] * iArr2[4]) * i2);
            int i9 = (iArr2[1] * iArr2[4]) - (iArr2[2] * iArr2[3]);
            int i10 = (iArr2[1] * iArr2[1]) - ((iArr2[2] * iArr2[2]) * i2);
            iArr2[1] = i8;
            iArr2[2] = i9;
            iArr2[3] = i10;
            iArr2[4] = 0;
            i4++;
        }
        int i11 = i4 - 1;
        long j = 0;
        long j2 = 1;
        int i12 = 1;
        boolean z2 = false;
        while (true) {
            if (j >= 200 && z2) {
                C1329o.m3531a(getClass(), C1278f.class);
                this.f6935b = j;
                this.f6936c = j2;
                m3007b();
                return;
            }
            int i13 = i12 + 1;
            j = 0;
            j2 = 1;
            int i14 = i13 - 1;
            while (i14 >= 0) {
                long j3 = j2 + (((long) (i13 <= i11 ? iArr[i14] : iArr[((i14 - i) % i11) + i])) * j);
                i14--;
                j2 = j;
                j = j3;
            }
            if (j >= 1000000) {
                throw new RuntimeException();
            }
            long j4 = j * j;
            long j5 = j2 * j2;
            long j6 = ((long) i2) * j5;
            long j7 = 1000 * j4;
            z2 = (j < 200 || 999 * j6 >= j7 || j7 >= j6 * 1001 || z2 || ((!z || j4 >= ((long) i2) * j5) && (z || j4 <= j5 * ((long) i2)))) ? z2 : true;
            i12 = i13;
        }
    }

    /* JADX INFO: renamed from: a */
    private static final int m3005a(int i, int i2) {
        int i3 = i2;
        int i4 = i;
        while (i4 != 0) {
            if (i3 == 0) {
                return i4;
            }
            if (i4 < i3) {
                int i5 = i4;
                i4 = i3;
                i3 = i5;
            } else {
                while (true) {
                    int i6 = i4 % i3;
                    if (i6 == 0) {
                        return i3;
                    }
                    i4 = i3;
                    i3 = i6;
                }
            }
        }
        return i3;
    }

    /* JADX INFO: renamed from: a */
    private static final boolean m3006a(int i) {
        int iSqrt = ((int) Math.sqrt(i)) - 1;
        while ((iSqrt + 1) * (iSqrt + 1) <= i) {
            iSqrt++;
        }
        return iSqrt * iSqrt == i;
    }

    /* JADX INFO: renamed from: b */
    private void m3007b() throws BadExpiryDataException {
        long j = this.f6934a;
        long j2 = this.f6935b;
        long j3 = this.f6936c;
        if (j2 < 200) {
            throw new BadExpiryDataException();
        }
        long j4 = j * j3 * j3;
        long j5 = j4 * 1000;
        long j6 = j2 * j2 * 1000;
        if (j6 <= j5 - j4 || j6 >= j4 + j5) {
            throw new BadExpiryDataException();
        }
    }

    /* JADX INFO: renamed from: a */
    final boolean m3008a() {
        m3007b();
        long j = this.f6934a;
        long j2 = this.f6935b;
        long j3 = this.f6936c;
        return j2 * j2 < j * (j3 * j3);
    }
}
