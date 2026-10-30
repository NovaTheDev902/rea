package com.lenovo.lps.sus.control;

import com.lenovo.lps.sus.p008c.C0092c;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.ah */
/* JADX INFO: loaded from: classes.dex */
public class C0107ah extends Thread {

    /* JADX INFO: renamed from: a */
    private static String f1424a = null;

    public C0107ah(String str) {
        if (str == null || str.length() <= 0) {
            f1424a = null;
        } else {
            f1424a = str;
        }
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public void run() throws Throwable {
        if (f1424a == null || f1424a.length() <= 0) {
            return;
        }
        C0092c.m327a(f1424a, (Boolean) false, 5000);
    }
}
