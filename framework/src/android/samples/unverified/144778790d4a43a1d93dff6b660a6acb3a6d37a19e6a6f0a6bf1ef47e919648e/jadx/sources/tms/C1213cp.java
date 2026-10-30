package tms;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.cp */
/* JADX INFO: loaded from: classes.dex */
final class C1213cp extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f7004a;

    C1213cp(C1216cs.b bVar) {
        this.f7004a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        boolean z;
        CallLogEntity callLogEntity = (CallLogEntity) m2960a();
        String str = callLogEntity.phonenum;
        if (str == null || str.length() <= 2) {
            return false;
        }
        if (this.f7004a.f7026m) {
            z = callLogEntity.type != 2;
        } else {
            z = callLogEntity.type == 1;
        }
        return z & (callLogEntity.duration <= 5);
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        C1216cs.b.m3054a(this.f7004a, this, null, false, false);
    }
}
