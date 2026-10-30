package tms;

import android.content.p001pm.IPackageDataObserver;
import android.os.RemoteException;
import java.util.concurrent.atomic.AtomicBoolean;

/* JADX INFO: renamed from: tms.dn */
/* JADX INFO: loaded from: classes.dex */
final class BinderC1238dn extends IPackageDataObserver.Stub {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ AtomicBoolean f7145a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ Object f7146b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ C1237dm f7147c;

    BinderC1238dn(C1237dm c1237dm, AtomicBoolean atomicBoolean, Object obj) {
        this.f7147c = c1237dm;
        this.f7145a = atomicBoolean;
        this.f7146b = obj;
    }

    @Override // android.content.p001pm.IPackageDataObserver
    public final void onRemoveCompleted(String str, boolean z) throws RemoteException {
        this.f7145a.set(z);
        synchronized (this.f7146b) {
            this.f7146b.notify();
        }
    }
}
