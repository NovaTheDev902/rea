package tms;

import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bm */
/* JADX INFO: loaded from: classes.dex */
final class C1183bm extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1189bs.b f6923a;

    C1183bm(C1189bs.b bVar) {
        this.f6923a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    public final boolean mo2967f() {
        return m2963b() != 2 && this.f6923a.f6951k.contains(((SmsEntity) m2960a()).phonenum);
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    public final void mo2968g() {
        C1189bs.b.m3016a(this.f6923a, this);
    }
}
