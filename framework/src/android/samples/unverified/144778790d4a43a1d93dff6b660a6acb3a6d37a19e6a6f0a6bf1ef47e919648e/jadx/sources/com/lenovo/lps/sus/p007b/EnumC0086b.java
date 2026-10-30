package com.lenovo.lps.sus.p007b;

import java.util.HashMap;
import java.util.Map;

/* JADX INFO: renamed from: com.lenovo.lps.sus.b.b */
/* JADX INFO: loaded from: classes.dex */
public enum EnumC0086b {
    SUS_STARTUPDATE_EVENT(0),
    SUS_UPDATE_PROMPT_EVENT(1),
    SUS_INSTALLAPK_EVENT(2),
    SUS_REQNEWAPPVERSION_RESPONE_EVENT(3),
    SUS_USER_REQUPDATE_EVENT(4),
    SUS_USER_CHANGESETTINGS_EVENT(5),
    SUS_QUERY_EXCEPTION_EVENT(6),
    SUS_DOWNLOAD_EXCEPTION_EVENT(7),
    SUS_TESTSUSSERVER_EVENT(8),
    SUS_FINISH_EVENT(9),
    SUS_UPDATE_USERACTION_EVENT(10),
    SUS_REPORT_SILENCEINSTALLRESULT_EVENT(11),
    SUS_NOTIFICATION_INSTALL_EVENT(12);


    /* JADX INFO: renamed from: o */
    static Map f1251o = new HashMap();

    /* JADX INFO: renamed from: n */
    int f1253n;

    EnumC0086b(int i) {
        this.f1253n = i;
    }

    /* JADX INFO: renamed from: a */
    public static int m293a(EnumC0086b enumC0086b) {
        if (f1251o.size() == 0) {
            m297c();
        }
        return enumC0086b.ordinal();
    }

    /* JADX INFO: renamed from: a */
    public static EnumC0086b m294a(int i) {
        if (f1251o.size() == 0) {
            m297c();
        }
        return (EnumC0086b) f1251o.get(Integer.valueOf(i));
    }

    /* JADX INFO: renamed from: b */
    public static EnumC0086b[] m296b() {
        EnumC0086b[] enumC0086bArrValues = values();
        int length = enumC0086bArrValues.length;
        EnumC0086b[] enumC0086bArr = new EnumC0086b[length];
        System.arraycopy(enumC0086bArrValues, 0, enumC0086bArr, 0, length);
        return enumC0086bArr;
    }

    /* JADX INFO: renamed from: c */
    private static void m297c() {
        for (EnumC0086b enumC0086b : m296b()) {
            f1251o.put(Integer.valueOf(enumC0086b.m298a()), enumC0086b);
        }
    }

    /* JADX INFO: renamed from: a */
    public final int m298a() {
        return this.f1253n;
    }
}
