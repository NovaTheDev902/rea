package tms;

import android.os.RemoteException;
import com.tencent.tmsecure.module.permission.AbsDummyServiceCallback;
import com.tencent.tmsecure.module.permission.IDummyService;

/* JADX INFO: renamed from: tms.dq */
/* JADX INFO: loaded from: classes.dex */
final class C1241dq implements C1270es.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ AbsDummyServiceCallback f7187a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1270es f7188b;

    C1241dq(C1270es c1270es, AbsDummyServiceCallback absDummyServiceCallback) {
        this.f7188b = c1270es;
        this.f7187a = absDummyServiceCallback;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3172a() throws RemoteException {
        this.f7188b.f7282h = this.f7187a;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3173a(IDummyService iDummyService) throws RemoteException {
        iDummyService.setDummyServiceCallback(this.f7188b.f7282h);
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: b */
    public final void mo3174b() throws RemoteException {
    }
}
