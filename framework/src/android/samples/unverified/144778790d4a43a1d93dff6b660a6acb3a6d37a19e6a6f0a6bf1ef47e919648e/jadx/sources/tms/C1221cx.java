package tms;

import com.tencent.tmsecure.module.tools.IPackageChangedListener;

/* JADX INFO: renamed from: tms.cx */
/* JADX INFO: loaded from: classes.dex */
final class C1221cx implements IPackageChangedListener {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1220cw f7043a;

    C1221cx(C1220cw c1220cw) {
        this.f7043a = c1220cw;
    }

    @Override // com.tencent.tmsecure.module.tools.IPackageChangedListener
    public final void onPackageAdded(String str) {
        this.f7043a.m3079a(new String[]{str});
    }

    @Override // com.tencent.tmsecure.module.tools.IPackageChangedListener
    public final void onPackageReinstall(String str) {
    }

    @Override // com.tencent.tmsecure.module.tools.IPackageChangedListener
    public final void onPackageRemoved(String str) {
    }
}
