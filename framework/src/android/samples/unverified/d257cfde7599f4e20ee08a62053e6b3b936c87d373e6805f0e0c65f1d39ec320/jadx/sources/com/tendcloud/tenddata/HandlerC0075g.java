package com.tendcloud.tenddata;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

/* JADX INFO: renamed from: com.tendcloud.tenddata.g */
/* JADX INFO: loaded from: classes.dex */
final class HandlerC0075g extends Handler {
    HandlerC0075g(Looper looper) {
        super(looper);
    }

    @Override // android.os.Handler
    public void handleMessage(Message message) {
        TCAgent.m8a(message);
    }
}
