package com.tendcloud.tenddata;

import android.app.Activity;
import android.os.Message;

/* JADX INFO: renamed from: com.tendcloud.tenddata.ad */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0065ad implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ int f52a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ String f53b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ Activity f54c;

    RunnableC0065ad(int i, String str, Activity activity) {
        this.f52a = i;
        this.f53b = str;
        this.f54c = activity;
    }

    @Override // java.lang.Runnable
    public void run() {
        try {
            if (!TCAgent.f8H) {
                TCAgent.init(this.f54c);
            }
            if (TCAgent.f12L == null) {
                return;
            }
            RunnableC0071c.m61b().sendMessage(Message.obtain(RunnableC0071c.m61b(), this.f52a, this.f53b));
        } catch (Throwable th) {
        }
    }
}
