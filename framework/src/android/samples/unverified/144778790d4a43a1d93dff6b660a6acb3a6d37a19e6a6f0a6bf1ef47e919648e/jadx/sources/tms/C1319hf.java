package tms;

import com.tencent.tmsecure.utils.ScriptHelper;

/* JADX INFO: renamed from: tms.hf */
/* JADX INFO: loaded from: classes.dex */
public final class C1319hf extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ ScriptHelper.Callback f7447a;

    public C1319hf(ScriptHelper.Callback callback) {
        this.f7447a = callback;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        this.f7447a.onFinish(ScriptHelper.canRunAtRoot(1));
    }
}
