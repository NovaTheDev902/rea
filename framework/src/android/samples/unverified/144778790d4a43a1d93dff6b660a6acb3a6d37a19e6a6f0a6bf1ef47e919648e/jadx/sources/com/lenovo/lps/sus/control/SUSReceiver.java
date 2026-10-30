package com.lenovo.lps.sus.control;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import com.lenovo.lps.sus.p007b.EnumC0086b;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import com.lenovo.safecenter.database.AppDatabase;

/* JADX INFO: loaded from: classes.dex */
public class SUSReceiver extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    private static Handler f1406a = null;

    /* JADX INFO: renamed from: a */
    public static void m438a(Handler handler) {
        f1406a = handler;
    }

    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        String action;
        if (intent == null || intent.getAction() == null || (action = intent.getAction()) == null || !"com.lenovo.lps.sus.ACTION_UPDATE".equals(action)) {
            return;
        }
        Bundle extras = intent.getExtras();
        String string = extras.getString("filename");
        String string2 = extras.getString(AppDatabase.APP_PKG_NAME);
        String strM365g = C0092c.m365g(context);
        if (string2 == null || strM365g == null || !strM365g.equals(string2)) {
            return;
        }
        Message message = new Message();
        if (f1406a != null) {
            message.what = EnumC0086b.m293a(EnumC0086b.SUS_INSTALLAPK_EVENT);
            message.obj = string;
            f1406a.sendMessage(message);
            C0098i.m409a(C0092c.f1339b, "SUSReceiver sendMessage SUS_INSTALLAPK_EVENT");
        }
    }
}
