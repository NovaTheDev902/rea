package tms;

import android.os.RemoteException;
import com.tencent.tmsecure.module.permission.IDummyService;
import com.tencent.tmsecure.module.permission.PermissionTableItem;

/* JADX INFO: renamed from: tms.dr */
/* JADX INFO: loaded from: classes.dex */
final class C1242dr implements C1270es.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ PermissionTableItem f7189a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1270es f7190b;

    C1242dr(C1270es c1270es, PermissionTableItem permissionTableItem) {
        this.f7190b = c1270es;
        this.f7189a = permissionTableItem;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3172a() throws RemoteException {
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3173a(IDummyService iDummyService) throws RemoteException {
        iDummyService.addPermissionTableItem(this.f7189a);
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: b */
    public final void mo3174b() throws RemoteException {
        this.f7190b.f7281g.addItem(this.f7189a);
    }
}
