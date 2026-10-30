package com.lenovo.lps.sus.p009d;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import com.lenovo.lps.sus.control.C0104ae;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import com.lenovo.safecenter.database.AppDatabase;

/* JADX INFO: renamed from: com.lenovo.lps.sus.d.d */
/* JADX INFO: loaded from: classes.dex */
final class HandlerC0142d extends Handler {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C0141c f1582a;

    HandlerC0142d(C0141c c0141c) {
        this.f1582a = c0141c;
    }

    @Override // android.os.Handler
    public final void handleMessage(Message message) {
        if (message == null) {
        }
        switch (message.what) {
            case 1:
                int i = message.getData().getInt("progress");
                if (this.f1582a.f1572a != null && !C0092c.m398x() && !C0104ae.m459g()) {
                    C0098i.m409a(C0092c.f1339b, "notifyUpdate");
                    this.f1582a.f1572a.m488a(i);
                    break;
                }
                break;
            case 2:
                Intent intent = new Intent("com.lenovo.lps.sus.ACTION_UPDATE");
                Bundle bundle = new Bundle();
                bundle.putString("filename", (String) message.obj);
                bundle.putString(AppDatabase.APP_PKG_NAME, this.f1582a.f1573b != null ? C0092c.m365g(this.f1582a.f1573b) : null);
                intent.putExtras(bundle);
                if (this.f1582a.f1573b != null) {
                    this.f1582a.f1573b.sendBroadcast(intent);
                }
                if (this.f1582a.f1572a != null && !C0092c.m398x() && !C0104ae.m459g()) {
                    this.f1582a.f1572a.m492b();
                    break;
                }
                break;
            case 3:
                boolean zBooleanValue = ((Boolean) message.obj).booleanValue();
                if (this.f1582a.f1572a != null) {
                    this.f1582a.f1572a.m491a(zBooleanValue);
                }
                break;
        }
    }
}
