package com.tencent.tmsecure.common;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

/* JADX INFO: loaded from: classes.dex */
public abstract class TMSBootReceiver extends BroadcastReceiver {
    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        TMSApplication.getApplicaionContext().startService(new Intent(context, TMSApplication.getSecureServiceClass()));
    }
}
