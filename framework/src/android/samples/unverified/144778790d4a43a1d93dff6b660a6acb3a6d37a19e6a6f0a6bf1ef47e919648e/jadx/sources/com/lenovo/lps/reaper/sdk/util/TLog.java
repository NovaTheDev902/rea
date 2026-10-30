package com.lenovo.lps.reaper.sdk.util;

import android.os.Debug;
import android.util.Log;

/* JADX INFO: loaded from: classes.dex */
public class TLog {

    /* JADX INFO: renamed from: a */
    private static boolean f1205a;

    public static void setTestMode(boolean isTestMode) {
        f1205a = isTestMode;
    }

    public static boolean isTestMode() {
        return f1205a;
    }

    /* JADX INFO: renamed from: v */
    public static void m244v(String tag, String msg) {
        if (f1205a) {
            Log.v(tag, msg);
        }
    }

    /* JADX INFO: renamed from: i */
    public static void m243i(String tag, String msg) {
        if (f1205a) {
            Log.i(tag, msg);
        }
    }

    /* JADX INFO: renamed from: d */
    public static void m240d(String tag, String msg) {
        if (f1205a) {
            Log.d(tag, msg);
        }
    }

    /* JADX INFO: renamed from: w */
    public static void m245w(String tag, String msg) {
        if (f1205a) {
            Log.w(tag, msg);
        }
    }

    /* JADX INFO: renamed from: e */
    public static void m241e(String tag, String msg) {
        Log.e(tag, msg);
    }

    /* JADX INFO: renamed from: e */
    public static void m242e(String tag, String msg, Throwable e) {
        if (f1205a) {
            Log.e(tag, msg, e);
        } else {
            Log.e(tag, msg + ", " + e.getClass() + ", " + e.getMessage());
        }
    }

    public static void startMethodTracing(String fileName) {
        if (f1205a) {
            Debug.startMethodTracing(fileName);
        }
    }

    public static void stopMethodTracing() {
        if (f1205a) {
            Debug.stopMethodTracing();
        }
    }
}
