package com.lenovo.lps.sus.control;

import android.os.Handler;
import android.os.Message;
import com.lenovo.lps.sus.p007b.EnumC0086b;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.z */
/* JADX INFO: loaded from: classes.dex */
public class C0138z extends Thread {

    /* JADX INFO: renamed from: a */
    private Handler f1551a;

    /* JADX INFO: renamed from: b */
    private String f1552b;

    public C0138z(Handler handler, String str) {
        this.f1551a = null;
        this.f1552b = null;
        this.f1551a = handler;
        this.f1552b = str;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public void run() throws Throwable {
        if (this.f1552b == null) {
            C0098i.m411b(C0092c.f1339b, "myReqAppNewVersionURL == null!!");
            return;
        }
        String strM327a = C0092c.m327a(this.f1552b, (Boolean) true, 5000);
        if (strM327a != null && strM327a.length() > 0 && strM327a.startsWith(C0092c.f1287R)) {
            if (this.f1551a != null) {
                Message message = new Message();
                message.what = EnumC0086b.m293a(EnumC0086b.SUS_REQNEWAPPVERSION_RESPONE_EVENT);
                message.obj = strM327a;
                this.f1551a.sendMessage(message);
                return;
            }
            return;
        }
        if (strM327a != null && ((strM327a == null || strM327a.length() > 0) && !strM327a.contains("<html>"))) {
            strM327a.contains("<head>");
        }
        if (this.f1551a != null) {
            Message message2 = new Message();
            message2.what = EnumC0086b.m293a(EnumC0086b.SUS_QUERY_EXCEPTION_EVENT);
            message2.obj = null;
            this.f1551a.sendMessage(message2);
        }
    }
}
