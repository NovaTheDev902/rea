package tms;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: renamed from: tms.r */
/* JADX INFO: loaded from: classes.dex */
public class C1332r {
    /* JADX INFO: renamed from: a */
    private static byte m3547a(char c) {
        return (byte) "0123456789ABCDEF".indexOf(c);
    }

    /* JADX INFO: renamed from: a */
    public static final String m3548a(byte[] bArr) {
        StringBuffer stringBuffer = new StringBuffer(bArr.length);
        for (byte b : bArr) {
            String hexString = Integer.toHexString(b & 255);
            if (hexString.length() < 2) {
                stringBuffer.append(0);
            }
            stringBuffer.append(hexString.toUpperCase());
        }
        return stringBuffer.toString();
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m3549a(int i) {
        return new byte[]{(byte) (i & 255), (byte) ((i >> 8) & 255), (byte) ((i >> 16) & 255), (byte) ((i >> 24) & 255)};
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m3550a(InputStream inputStream) {
        byte[] byteArray;
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
        try {
            byte[] bArr = new byte[1024];
            while (true) {
                int i = inputStream.read(bArr);
                if (i == -1) {
                    break;
                }
                byteArrayOutputStream.write(bArr, 0, i);
            }
            byteArray = byteArrayOutputStream.toByteArray();
        } catch (IOException e) {
            e.printStackTrace();
            byteArray = new byte[0];
        } finally {
            try {
                byteArrayOutputStream.close();
            } catch (IOException e2) {
                e2.printStackTrace();
            }
        }
        return byteArray;
    }

    /* JADX INFO: renamed from: a */
    public static byte[] m3551a(String str) {
        int length = str.length() / 2;
        byte[] bArr = new byte[length];
        char[] charArray = str.toCharArray();
        for (int i = 0; i < length; i++) {
            int i2 = i * 2;
            bArr[i] = (byte) (m3547a(charArray[i2 + 1]) | (m3547a(charArray[i2]) << 4));
        }
        return bArr;
    }

    /* JADX INFO: renamed from: b */
    public static int m3552b(byte[] bArr) {
        if (bArr.length != 4) {
            return 0;
        }
        return (bArr[0] & 255) | ((bArr[1] & 255) << 8) | ((bArr[2] & 255) << 16) | ((bArr[3] & 255) << 24);
    }
}
