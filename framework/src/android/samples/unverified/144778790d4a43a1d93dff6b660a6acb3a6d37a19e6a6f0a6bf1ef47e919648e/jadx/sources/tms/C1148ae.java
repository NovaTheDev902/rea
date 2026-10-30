package tms;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/* JADX INFO: renamed from: tms.ae */
/* JADX INFO: loaded from: classes.dex */
public class C1148ae {

    /* JADX INFO: renamed from: a */
    private static final char[] f6821a = "0123456789abcdef".toCharArray();

    /* JADX INFO: renamed from: a */
    public static byte[] m2874a(int i) {
        return new byte[]{(byte) ((i >> 24) & 255), (byte) ((i >> 16) & 255), (byte) ((i >> 8) & 255), (byte) (i & 255)};
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2875a(String str) {
        return m2876a(str.getBytes());
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m2876a(byte[] bArr) {
        try {
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            messageDigest.update(bArr);
            return messageDigest.digest();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    /* JADX INFO: renamed from: b */
    public static String m2877b(byte[] bArr) {
        StringBuilder sb = new StringBuilder(bArr.length * 3);
        for (byte b : bArr) {
            int i = b & 255;
            sb.append(f6821a[i >> 4]);
            sb.append(f6821a[i & 15]);
        }
        return sb.toString().toUpperCase();
    }

    /* JADX INFO: renamed from: c */
    public static String m2878c(byte[] bArr) {
        return m2877b(m2876a(bArr));
    }
}
