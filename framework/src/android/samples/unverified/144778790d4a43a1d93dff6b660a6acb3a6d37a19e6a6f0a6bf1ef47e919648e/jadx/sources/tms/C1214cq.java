package tms;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.cq */
/* JADX INFO: loaded from: classes.dex */
final class C1214cq extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f7005a;

    /* JADX INFO: renamed from: b */
    private final int f7006b = 8000;

    C1214cq(C1216cs.b bVar) {
        this.f7005a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        long jLongValue = ((Long) m2964c()[0]).longValue();
        CallLogEntity callLogEntity = (CallLogEntity) m2960a();
        long j = jLongValue - callLogEntity.date;
        if (this.f7005a.f7020g != null) {
            return this.f7005a.f7020g.isShortCall(callLogEntity, j);
        }
        return !this.f7005a.f7026m && m2963b() == 2 && callLogEntity.type == 3 && callLogEntity.duration <= 8000 && jLongValue - callLogEntity.date <= 8000;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        CallLogEntity callLogEntity = (CallLogEntity) m2960a();
        callLogEntity.duration = ((Long) m2964c()[0]).longValue() - callLogEntity.date;
        this.f7005a.f7022i.cancelMissCall();
        C1216cs.b.m3054a(this.f7005a, this, this.f7005a.f7017d, true, false);
    }
}
