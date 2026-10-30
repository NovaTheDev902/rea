package com.tencent.tmsecure.module.plugin;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

/* JADX INFO: loaded from: classes.dex */
public abstract class AbsPluginService extends Service {
    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }
}
