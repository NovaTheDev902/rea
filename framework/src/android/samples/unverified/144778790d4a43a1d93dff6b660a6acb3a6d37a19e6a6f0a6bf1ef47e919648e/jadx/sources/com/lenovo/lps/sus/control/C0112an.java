package com.lenovo.lps.sus.control;

import android.os.Handler;
import android.os.Message;
import com.lenovo.lps.sus.p007b.EnumC0086b;
import com.lenovo.lps.sus.p008c.C0092c;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.an */
/* JADX INFO: loaded from: classes.dex */
public class C0112an extends Thread {

    /* JADX INFO: renamed from: a */
    private Handler f1459a;

    public C0112an(Handler handler) {
        this.f1459a = null;
        this.f1459a = handler;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public void run() throws Throwable {
        String strM327a = C0092c.m327a(C0092c.f1292W, (Boolean) true, 3000);
        String str = (strM327a == null || strM327a.length() <= 0 || !"OK".equals(strM327a)) ? "FAIL" : C0092c.f1288S;
        Message message = new Message();
        if (this.f1459a != null) {
            message.what = EnumC0086b.m293a(EnumC0086b.SUS_TESTSUSSERVER_EVENT);
            message.obj = str;
            this.f1459a.sendMessage(message);
        }
    }
}
