package tms;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;

/* JADX INFO: renamed from: tms.fn */
/* JADX INFO: loaded from: classes.dex */
final class HandlerC1292fn extends Handler {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1310gv f7336a;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    HandlerC1292fn(C1310gv c1310gv, Looper looper) {
        super(looper);
        this.f7336a = c1310gv;
    }

    @Override // android.os.Handler
    public final void handleMessage(Message message) {
        Runnable runnable = (Runnable) message.obj;
        if (runnable != null) {
            new Thread(runnable).start();
        }
    }
}
