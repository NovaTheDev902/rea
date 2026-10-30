package tms;

import android.os.RemoteException;
import com.tencent.tmsecure.module.permission.IDummyService;
import com.tencent.tmsecure.module.permission.PermissionTableItem;

/* JADX INFO: renamed from: tms.dx */
/* JADX INFO: loaded from: classes.dex */
final class C1248dx implements C1270es.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ PermissionTableItem f7220a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1270es f7221b;

    C1248dx(C1270es c1270es, PermissionTableItem permissionTableItem) {
        this.f7221b = c1270es;
        this.f7220a = permissionTableItem;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3172a() throws RemoteException {
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3173a(IDummyService iDummyService) throws RemoteException {
        iDummyService.updatePermissionTable(this.f7220a);
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: b */
    public final void mo3174b() throws RemoteException {
        this.f7221b.f7281g.update(this.f7220a);
    }
}
