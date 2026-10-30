package com.tencent.lbsapi.core;

import java.security.MessageDigest;

/* JADX INFO: loaded from: classes.dex */
public class QLBSJNI {
    static {
        System.loadLibrary("lbs");
    }

    public static byte[] md5String(String str) {
        try {
            byte[] bytes = str.getBytes();
            MessageDigest messageDigest = MessageDigest.getInstance("MD5");
            messageDigest.update(bytes);
            return messageDigest.digest();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    public native byte[] decode(byte[] bArr, String str, String str2);

    public native byte[] encode(byte[] bArr, String str, String str2);
}
