package tms;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.co */
/* JADX INFO: loaded from: classes.dex */
final class C1212co extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f7003a;

    C1212co(C1216cs.b bVar) {
        this.f7003a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        return (((CallLogEntity) m2960a()).type == 2 || m2963b() == 3) ? false : true;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        C1216cs.b.m3054a(this.f7003a, this, this.f7003a.f7017d, m2963b() == 1, true);
    }
}
