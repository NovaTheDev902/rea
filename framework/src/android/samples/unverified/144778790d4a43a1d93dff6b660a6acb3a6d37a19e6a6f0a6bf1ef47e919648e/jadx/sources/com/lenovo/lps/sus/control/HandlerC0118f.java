package com.lenovo.lps.sus.control;

import android.os.Handler;
import android.os.Message;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.f */
/* JADX INFO: loaded from: classes.dex */
final class HandlerC0118f extends Handler {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C0134v f1475a;

    HandlerC0118f(C0134v c0134v) {
        this.f1475a = c0134v;
    }

    @Override // android.os.Handler
    public final void handleMessage(Message message) {
        super.handleMessage(message);
        this.f1475a.m506a(message);
    }
}
