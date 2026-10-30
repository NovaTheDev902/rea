package puw;

/* JADX INFO: renamed from: puw.d */
/* JADX INFO: loaded from: classes.dex */
public class C1138d {

    /* JADX INFO: renamed from: b */
    private static final char[] f6793b = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    /* JADX INFO: renamed from: a */
    public static final byte[] f6792a = new byte[0];

    /* JADX INFO: renamed from: a */
    public static byte m2864a(char c) {
        if (c >= '0' && c <= '9') {
            return (byte) (c - '0');
        }
        if (c >= 'a' && c <= 'f') {
            return (byte) ((c - 'a') + 10);
        }
        if (c < 'A' || c > 'F') {
            return (byte) 0;
        }
        return (byte) ((c - 'A') + 10);
    }

    /* JADX INFO: renamed from: a */
    public static String m2865a(byte[] bArr) {
        if (bArr == null || bArr.length == 0) {
            return null;
        }
        char[] cArr = new char[bArr.length * 2];
        for (int i = 0; i < bArr.length; i++) {
            byte b = bArr[i];
            cArr[(i * 2) + 1] = f6793b[b & 15];
            cArr[(i * 2) + 0] = f6793b[((byte) (b >>> 4)) & 15];
        }
        return new String(cArr);
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2866a(String str) {
        if (str == null || str.equals("")) {
            return f6792a;
        }
        byte[] bArr = new byte[str.length() / 2];
        for (int i = 0; i < bArr.length; i++) {
            bArr[i] = (byte) ((m2864a(str.charAt(i * 2)) * 16) + m2864a(str.charAt((i * 2) + 1)));
        }
        return bArr;
    }
}
