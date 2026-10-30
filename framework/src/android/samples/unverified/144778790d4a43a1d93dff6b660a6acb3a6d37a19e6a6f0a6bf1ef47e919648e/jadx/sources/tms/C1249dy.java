package tms;

import android.os.RemoteException;
import com.tencent.tmsecure.module.permission.IDummyService;

/* JADX INFO: renamed from: tms.dy */
/* JADX INFO: loaded from: classes.dex */
final class C1249dy implements C1270es.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ boolean f7222a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1270es f7223b;

    C1249dy(C1270es c1270es, boolean z) {
        this.f7223b = c1270es;
        this.f7222a = z;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3172a() {
        this.f7223b.f7277c = this.f7222a;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3173a(IDummyService iDummyService) throws RemoteException {
        iDummyService.setEnable(this.f7222a);
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: b */
    public final void mo3174b() throws RemoteException {
    }
}
