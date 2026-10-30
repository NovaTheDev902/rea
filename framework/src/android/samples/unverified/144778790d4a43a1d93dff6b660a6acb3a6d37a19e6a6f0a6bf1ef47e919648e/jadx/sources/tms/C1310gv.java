package tms;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import com.tencent.tmsecure.common.BaseManager;

/* JADX INFO: renamed from: tms.gv */
/* JADX INFO: loaded from: classes.dex */
public final class C1310gv extends BaseManager {

    /* JADX INFO: renamed from: a */
    private Handler f7420a;

    /* JADX INFO: renamed from: a */
    public final boolean m3435a(Runnable runnable, long j) {
        if (runnable == null) {
            return false;
        }
        Message messageObtainMessage = this.f7420a.obtainMessage();
        messageObtainMessage.obj = runnable;
        return this.f7420a.sendMessageDelayed(messageObtainMessage, j);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7420a = new HandlerC1292fn(this, context.getMainLooper());
    }
}
