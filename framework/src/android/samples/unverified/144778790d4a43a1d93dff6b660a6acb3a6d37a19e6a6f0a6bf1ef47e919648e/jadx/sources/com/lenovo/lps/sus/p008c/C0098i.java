package com.lenovo.lps.sus.p008c;

import android.util.Log;

/* JADX INFO: renamed from: com.lenovo.lps.sus.c.i */
/* JADX INFO: loaded from: classes.dex */
public final class C0098i {

    /* JADX INFO: renamed from: a */
    private static boolean f1370a = false;

    /* JADX INFO: renamed from: a */
    public static void m409a(String str, String str2) {
        if (f1370a) {
            Log.d(str, str2);
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m410a(boolean z) {
        f1370a = z;
    }

    /* JADX INFO: renamed from: b */
    public static void m411b(String str, String str2) {
        if (f1370a) {
            Log.e(str, str2);
        }
    }

    /* JADX INFO: renamed from: c */
    public static void m412c(String str, String str2) {
        if (f1370a) {
            Log.v(str, str2);
        }
    }
}
