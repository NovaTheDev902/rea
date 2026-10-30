package tms;

import android.content.p001pm.IPackageStatsObserver;
import android.content.pm.PackageStats;
import android.os.RemoteException;
import java.util.concurrent.atomic.AtomicReference;

/* JADX INFO: renamed from: tms.dp */
/* JADX INFO: loaded from: classes.dex */
final class BinderC1240dp extends IPackageStatsObserver.Stub {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ AtomicReference f7184a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ Object f7185b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ C1237dm f7186c;

    BinderC1240dp(C1237dm c1237dm, AtomicReference atomicReference, Object obj) {
        this.f7186c = c1237dm;
        this.f7184a = atomicReference;
        this.f7185b = obj;
    }

    @Override // android.content.p001pm.IPackageStatsObserver
    public final void onGetStatsCompleted(PackageStats packageStats, boolean z) throws RemoteException {
        this.f7184a.set(packageStats);
        synchronized (this.f7185b) {
            this.f7185b.notify();
        }
    }
}
