package com.tendcloud.tenddata;

import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import java.util.Map;

/* JADX INFO: renamed from: com.tendcloud.tenddata.x */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0092x implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ String f194a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ String f195b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ Map f196c;

    RunnableC0092x(String str, String str2, Map map) {
        this.f194a = str;
        this.f195b = str2;
        this.f196c = map;
    }

    @Override // java.lang.Runnable
    public void run() {
        try {
            if (TCAgent.f8H && !TextUtils.isEmpty(TCAgent.f13M)) {
                C0061a c0061a = new C0061a();
                c0061a.f44a = this.f194a;
                c0061a.f45b = this.f195b;
                c0061a.f50g = this.f196c;
                Handler handlerM61b = RunnableC0071c.m61b();
                handlerM61b.sendMessage(Message.obtain(handlerM61b, 3, c0061a));
            }
        } catch (Throwable th) {
        }
    }
}
