package com.tencent.tmsecure.common;

import android.content.Context;
import android.content.Intent;
import android.os.IBinder;

/* JADX INFO: loaded from: classes.dex */
public abstract class BaseService {

    /* JADX INFO: renamed from: a */
    private IBinder f6029a;

    public final boolean equals(Object obj) {
        return obj != null && getClass() == obj.getClass();
    }

    protected synchronized IBinder getBinder() {
        if (this.f6029a == null) {
            this.f6029a = onBind();
        }
        return this.f6029a;
    }

    public abstract IBinder onBind();

    public void onCreate(Context context) {
    }

    public void onDestory() {
    }

    public void onStart(Intent intent) {
    }

    protected final void stopSelf() {
        TMSService.stopService(this);
    }
}
