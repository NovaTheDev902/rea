package tms;

import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bj */
/* JADX INFO: loaded from: classes.dex */
final class C1180bj extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1189bs.b f6920a;

    C1180bj(C1189bs.b bVar) {
        this.f6920a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    public final boolean mo2967f() {
        return m2963b() != 2 && this.f6920a.f6944d.contains(((SmsEntity) m2960a()).phonenum, 1);
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    public final void mo2968g() {
        C1189bs.b.m3016a(this.f6920a, this);
    }
}
