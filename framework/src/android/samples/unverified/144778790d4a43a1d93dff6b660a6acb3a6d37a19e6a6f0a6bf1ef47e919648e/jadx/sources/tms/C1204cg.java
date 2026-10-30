package tms;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.cg */
/* JADX INFO: loaded from: classes.dex */
final class C1204cg extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f6985a;

    C1204cg(C1216cs.b bVar) {
        this.f6985a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        CallLogEntity callLogEntity = (CallLogEntity) m2960a();
        return (m2963b() == 2 || callLogEntity.type == 2 || !this.f6985a.f7014a.contains(callLogEntity.phonenum, 0)) ? false : true;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        C1216cs.b.m3054a(this.f6985a, this, this.f6985a.f7017d, m2963b() == 1, true);
    }
}
