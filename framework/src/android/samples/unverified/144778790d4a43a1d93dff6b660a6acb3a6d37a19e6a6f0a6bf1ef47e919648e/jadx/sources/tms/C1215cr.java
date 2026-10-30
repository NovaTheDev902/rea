package tms;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.cr */
/* JADX INFO: loaded from: classes.dex */
final class C1215cr extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f7007a;

    C1215cr(C1216cs.b bVar) {
        this.f7007a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        return ((CallLogEntity) m2960a()).type != 2 && m2963b() == 2;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        C1216cs.b.m3054a(this.f7007a, this, this.f7007a.f7017d, false, true);
    }
}
