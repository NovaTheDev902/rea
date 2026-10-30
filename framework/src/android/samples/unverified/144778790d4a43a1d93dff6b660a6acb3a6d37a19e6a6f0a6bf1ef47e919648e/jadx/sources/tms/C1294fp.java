package tms;

import android.os.Bundle;
import com.tencent.tmsecure.module.update.IUpdateListener;
import com.tencent.tmsecure.module.update.UpdateInfo;
import java.util.concurrent.atomic.AtomicBoolean;

/* JADX INFO: renamed from: tms.fp */
/* JADX INFO: loaded from: classes.dex */
final class C1294fp implements C1338x.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ IUpdateListener.UpdateListener f7362a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ UpdateInfo f7363b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ AtomicBoolean f7364c;

    /* JADX INFO: renamed from: d */
    final /* synthetic */ C1312gy f7365d;

    C1294fp(C1312gy c1312gy, IUpdateListener.UpdateListener updateListener, UpdateInfo updateInfo, AtomicBoolean atomicBoolean) {
        this.f7365d = c1312gy;
        this.f7362a = updateListener;
        this.f7363b = updateInfo;
        this.f7364c = atomicBoolean;
    }

    @Override // tms.C1338x.a
    /* JADX INFO: renamed from: a */
    public final void mo3343a(Bundle bundle) {
        this.f7362a.onUpdateEvent(this.f7363b, bundle.getInt(C1338x.f7492e));
        this.f7364c.set(true);
    }

    @Override // tms.C1338x.a
    /* JADX INFO: renamed from: b */
    public final void mo3344b(Bundle bundle) {
    }
}
