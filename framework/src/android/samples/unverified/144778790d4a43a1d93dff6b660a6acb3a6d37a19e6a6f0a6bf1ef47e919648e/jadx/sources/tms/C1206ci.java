package tms;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.ci */
/* JADX INFO: loaded from: classes.dex */
final class C1206ci extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f6987a;

    C1206ci(C1216cs.b bVar) {
        this.f6987a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        CallLogEntity callLogEntity = (CallLogEntity) m2960a();
        return (m2963b() == 2 || callLogEntity.type == 2 || !this.f6987a.f7021h.contains(callLogEntity.phonenum)) ? false : true;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        C1216cs.b.m3054a(this.f6987a, this, this.f6987a.f7017d, m2963b() == 1, true);
    }
}
