package com.lenovo.safecenter.utils.updateLab;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import com.lenovo.safecenter.utils.update.LeSafeDownLoadApk;

/* JADX INFO: loaded from: classes.dex */
public class WifiConnectedReceiver extends BroadcastReceiver {
    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        Log.i("wu0wu", "WifiConnectedReceiver intent=" + intent.getAction());
        UpdateLabManager.useWifiUpdateVirusLab(context);
        context.startService(new Intent(context, (Class<?>) LeSafeDownLoadApk.class));
    }
}
