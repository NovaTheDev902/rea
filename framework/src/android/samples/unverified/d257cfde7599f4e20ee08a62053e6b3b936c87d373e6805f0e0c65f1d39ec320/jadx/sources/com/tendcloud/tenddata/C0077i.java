package com.tendcloud.tenddata;

import android.util.Log;

/* JADX INFO: renamed from: com.tendcloud.tenddata.i */
/* JADX INFO: loaded from: classes.dex */
class C0077i implements Thread.UncaughtExceptionHandler {

    /* JADX INFO: renamed from: a */
    private Thread.UncaughtExceptionHandler f112a = Thread.getDefaultUncaughtExceptionHandler();

    C0077i() {
    }

    @Override // java.lang.Thread.UncaughtExceptionHandler
    public void uncaughtException(Thread thread, Throwable th) {
        if (TCAgent.f10J) {
            TCAgent.m21b(th);
            Log.w("TalkingData", "UncaughtException in Thread " + thread.getName(), th);
        }
        if (this.f112a != null) {
            this.f112a.uncaughtException(thread, th);
        }
    }
}
