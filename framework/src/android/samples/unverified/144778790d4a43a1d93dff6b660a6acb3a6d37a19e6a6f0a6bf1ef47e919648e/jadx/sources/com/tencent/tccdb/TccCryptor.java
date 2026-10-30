package com.tencent.tccdb;

import android.content.Context;
import com.tencent.tmsecure.common.TMSApplication;
import tms.C1147ad;

/* JADX INFO: loaded from: classes.dex */
public class TccCryptor {
    static {
        C1147ad.m2873a(TMSApplication.getApplicaionContext(), TMSApplication.getStrFromEnvMap(TMSApplication.CON_CRYPTOR_LIBNAME));
    }

    public static int EndianSwap(int i) {
        return (i << 24) | ((65280 & i) << 8) | ((16711680 & i) >>> 8) | (i >>> 24);
    }

    public static native byte[] decrypt(Context context, byte[] bArr, byte[] bArr2);

    public static String encrypt(Context context, String str, String str2) {
        return new String(encrypt(context, str.getBytes(), str2 == null ? null : str2.getBytes()));
    }

    public static native byte[] encrypt(Context context, byte[] bArr, byte[] bArr2);

    public static native byte[] makePassword(Context context, byte[] bArr);
}
