package com.tencent.tmsecure.utils;

/* JADX INFO: loaded from: classes.dex */
public class StringUtil {
    /* JADX INFO: renamed from: a */
    private static byte m2643a(char c) {
        return (byte) "0123456789ABCDEF".indexOf(c);
    }

    public static String assertNotNullString(String str) {
        return str == null ? "" : str;
    }

    public static final String bytesToHexString(byte[] bArr) {
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

    public static byte[] hexStringToByte(String str) {
        int length = str.length() / 2;
        byte[] bArr = new byte[length];
        char[] charArray = str.toCharArray();
        for (int i = 0; i < length; i++) {
            int i2 = i * 2;
            bArr[i] = (byte) (m2643a(charArray[i2 + 1]) | (m2643a(charArray[i2]) << 4));
        }
        return bArr;
    }
}
