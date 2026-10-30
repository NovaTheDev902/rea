package tms;

import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: renamed from: tms.bk */
/* JADX INFO: loaded from: classes.dex */
final class C1181bk extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1189bs.b f6921a;

    C1181bk(C1189bs.b bVar) {
        this.f6921a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    public final boolean mo2967f() {
        return m2963b() != 2 && this.f6921a.f6945e.contains(((SmsEntity) m2960a()).phonenum, 1);
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    public final void mo2968g() {
        C1189bs.b.m3016a(this.f6921a, this);
    }
}
