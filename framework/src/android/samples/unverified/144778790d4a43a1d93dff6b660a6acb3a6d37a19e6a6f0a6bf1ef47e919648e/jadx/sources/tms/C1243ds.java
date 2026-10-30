package tms;

import android.os.RemoteException;
import com.tencent.tmsecure.module.permission.IDummyService;
import com.tencent.tmsecure.module.permission.PermissionTableItem;

/* JADX INFO: renamed from: tms.ds */
/* JADX INFO: loaded from: classes.dex */
final class C1243ds implements C1270es.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ PermissionTableItem f7191a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1270es f7192b;

    C1243ds(C1270es c1270es, PermissionTableItem permissionTableItem) {
        this.f7192b = c1270es;
        this.f7191a = permissionTableItem;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3172a() throws RemoteException {
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3173a(IDummyService iDummyService) throws RemoteException {
        iDummyService.removePermissionTableItem(this.f7191a);
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: b */
    public final void mo3174b() throws RemoteException {
        this.f7192b.f7281g.removeItem(this.f7191a);
    }
}
