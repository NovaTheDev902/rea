package tms;

import com.tencent.tmsecure.module.aresengine.FilterResult;
import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bz */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1196bz implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ FilterResult f6970a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1195by f6971b;

    RunnableC1196bz(C1195by c1195by, FilterResult filterResult) {
        this.f6971b = c1195by;
        this.f6970a = filterResult;
    }

    @Override // java.lang.Runnable
    public final void run() {
        SmsEntity smsEntityConvert = (SmsEntity) this.f6970a.mData;
        this.f6971b.f6969a.f6997b.remove(smsEntityConvert);
        if (this.f6971b.f6969a.f7000e != null) {
            smsEntityConvert = this.f6971b.f6969a.f7000e.convert(smsEntityConvert);
        }
        this.f6971b.f6969a.f6998c.insert(smsEntityConvert, this.f6970a);
    }
}
