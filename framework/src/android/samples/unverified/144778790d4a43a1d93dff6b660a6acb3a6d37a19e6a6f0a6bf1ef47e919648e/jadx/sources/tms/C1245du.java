package tms;

import android.os.RemoteException;
import com.tencent.tmsecure.module.permission.IDummyService;
import com.tencent.tmsecure.module.permission.PermissionTableItem;

/* JADX INFO: renamed from: tms.du */
/* JADX INFO: loaded from: classes.dex */
final class C1245du implements C1270es.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ int f7213a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ int f7214b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ int f7215c;

    /* JADX INFO: renamed from: d */
    final /* synthetic */ C1270es f7216d;

    C1245du(C1270es c1270es, int i, int i2, int i3) {
        this.f7216d = c1270es;
        this.f7213a = i;
        this.f7214b = i2;
        this.f7215c = i3;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3172a() throws RemoteException {
        PermissionTableItem itemByUid = this.f7216d.f7281g.getItemByUid(this.f7213a);
        if (itemByUid == null) {
            return;
        }
        itemByUid.mRids[this.f7214b] = this.f7215c;
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: a */
    public final void mo3173a(IDummyService iDummyService) throws RemoteException {
        iDummyService.updatePermissionTable(this.f7213a, this.f7214b, this.f7215c);
    }

    @Override // tms.C1270es.a
    /* JADX INFO: renamed from: b */
    public final void mo3174b() throws RemoteException {
        this.f7216d.f7281g.update(this.f7213a, this.f7214b, this.f7215c);
    }
}
