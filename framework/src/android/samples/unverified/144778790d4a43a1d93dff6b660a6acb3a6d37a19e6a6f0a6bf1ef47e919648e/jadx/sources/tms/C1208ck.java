package tms;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.ck */
/* JADX INFO: loaded from: classes.dex */
final class C1208ck extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f6988a;

    C1208ck(C1216cs.b bVar) {
        this.f6988a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        CallLogEntity callLogEntity = (CallLogEntity) m2960a();
        return (m2963b() == 2 || callLogEntity.type == 2 || !this.f6988a.f7019f.contains(callLogEntity.phonenum)) ? false : true;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        C1216cs.b.m3054a(this.f6988a, this, this.f6988a.f7017d, m2963b() == 1, true);
    }
}
