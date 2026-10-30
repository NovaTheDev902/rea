package com.tencent.lbsapi.core;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

/* JADX INFO: renamed from: com.tencent.lbsapi.core.h */
/* JADX INFO: loaded from: classes.dex */
final class C1070h extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ QLBSEngine f5971a;

    C1070h(QLBSEngine qLBSEngine) {
        this.f5971a = qLBSEngine;
    }

    @Override // android.content.BroadcastReceiver
    public final void onReceive(Context context, Intent intent) {
        QLBSEngine.m2500a(this.f5971a);
    }
}
