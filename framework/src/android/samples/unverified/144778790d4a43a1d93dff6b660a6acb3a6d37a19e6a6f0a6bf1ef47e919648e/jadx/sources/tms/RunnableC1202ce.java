package tms;

import android.database.ContentObserver;
import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.ce */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1202ce implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ CallLogEntity f6982a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1201cd f6983b;

    RunnableC1202ce(C1201cd c1201cd, CallLogEntity callLogEntity) {
        this.f6983b = c1201cd;
        this.f6982a = callLogEntity;
    }

    @Override // java.lang.Runnable
    public final void run() {
        if (this.f6982a.type == 2) {
            C1216cs.a aVar = this.f6983b.f6981b;
            ContentObserver unused = this.f6983b.f6981b.f7010b;
            C1216cs.a.m3049a(aVar, this.f6982a, this.f6983b.f6981b.f7013e);
        } else {
            C1216cs.a aVar2 = this.f6983b.f6981b;
            ContentObserver unused2 = this.f6983b.f6981b.f7010b;
            C1216cs.a.m3049a(aVar2, this.f6982a, this.f6983b.f6981b.f7012d);
        }
    }
}
