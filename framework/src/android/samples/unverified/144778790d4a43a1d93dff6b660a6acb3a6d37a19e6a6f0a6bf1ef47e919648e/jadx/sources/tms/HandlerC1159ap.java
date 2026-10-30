package tms;

import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import com.tencent.tmsecure.module.antitheft.LocationResolver;

/* JADX INFO: renamed from: tms.ap */
/* JADX INFO: loaded from: classes.dex */
public class HandlerC1159ap extends Handler {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ LocationResolver f6848a;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    public HandlerC1159ap(LocationResolver locationResolver, Looper looper) {
        super(looper);
        this.f6848a = locationResolver;
    }

    @Override // android.os.Handler
    public void handleMessage(Message message) {
        synchronized (this.f6848a.f6067h) {
            if (!this.f6848a.m2588b()) {
                this.f6848a.m2586a();
            }
        }
    }
}
