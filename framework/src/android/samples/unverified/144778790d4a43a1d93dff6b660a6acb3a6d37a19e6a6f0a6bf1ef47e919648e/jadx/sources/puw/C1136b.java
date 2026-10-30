package puw;

/* JADX INFO: renamed from: puw.b */
/* JADX INFO: loaded from: classes.dex */
public class C1136b {

    /* JADX INFO: renamed from: b */
    private static final char[] f6791b = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    /* JADX INFO: renamed from: a */
    public static final byte[] f6790a = new byte[0];

    /* JADX INFO: renamed from: a */
    public static String m2856a(byte[] bArr) {
        if (bArr == null || bArr.length == 0) {
            return null;
        }
        char[] cArr = new char[bArr.length * 2];
        for (int i = 0; i < bArr.length; i++) {
            byte b = bArr[i];
            cArr[(i * 2) + 1] = f6791b[b & 15];
            cArr[(i * 2) + 0] = f6791b[((byte) (b >>> 4)) & 15];
        }
        return new String(cArr);
    }
}
