package com.lenovo.safecenter.systeminfo.service;

/* JADX INFO: loaded from: classes.dex */
public class PhoneSystemInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5628a = PhoneSystemInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static PhoneSystemInfoService f5629b = null;

    private PhoneSystemInfoService() {
    }

    public static PhoneSystemInfoService getInstance() {
        if (f5629b == null) {
            synchronized (PhoneSystemInfoService.class) {
                f5629b = new PhoneSystemInfoService();
            }
        }
        return f5629b;
    }
}
