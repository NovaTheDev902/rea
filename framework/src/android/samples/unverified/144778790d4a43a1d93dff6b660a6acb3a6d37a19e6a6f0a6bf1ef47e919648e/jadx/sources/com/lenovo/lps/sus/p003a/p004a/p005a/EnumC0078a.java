package com.lenovo.lps.sus.p003a.p004a.p005a;

/* JADX INFO: renamed from: com.lenovo.lps.sus.a.a.a.a */
/* JADX INFO: loaded from: classes.dex */
public enum EnumC0078a {
    BASE64("01"),
    DES("02"),
    AES("03"),
    PBE("04");


    /* JADX INFO: renamed from: e */
    private final String f1212e;

    EnumC0078a(String str) {
        this.f1212e = str;
    }

    /* JADX INFO: renamed from: b */
    public static EnumC0078a[] m248b() {
        EnumC0078a[] enumC0078aArrValues = values();
        int length = enumC0078aArrValues.length;
        EnumC0078a[] enumC0078aArr = new EnumC0078a[length];
        System.arraycopy(enumC0078aArrValues, 0, enumC0078aArr, 0, length);
        return enumC0078aArr;
    }

    /* JADX INFO: renamed from: a */
    public final String m249a() {
        return this.f1212e;
    }
}
