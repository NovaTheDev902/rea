package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.NetworkInfo;

/* JADX INFO: renamed from: tms.fs */
/* JADX INFO: loaded from: classes.dex */
final class C1297fs extends BroadcastReceiver {
    C1297fs() {
    }

    @Override // android.content.BroadcastReceiver
    public final void onReceive(Context context, Intent intent) {
        NetworkInfo networkInfo;
        if (intent == null || (networkInfo = (NetworkInfo) intent.getParcelableExtra("networkInfo")) == null || !networkInfo.isConnected() || C1313h.f7428a) {
            return;
        }
        C1313h.m3446a();
    }
}
