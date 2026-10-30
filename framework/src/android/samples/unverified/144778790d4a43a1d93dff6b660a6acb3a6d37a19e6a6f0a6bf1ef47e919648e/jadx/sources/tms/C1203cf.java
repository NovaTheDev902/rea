package tms;

import android.util.Log;
import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: renamed from: tms.cf */
/* JADX INFO: loaded from: classes.dex */
final class C1203cf extends C1167ax.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1216cs.b f6984a;

    C1203cf(C1216cs.b bVar) {
        this.f6984a = bVar;
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: f */
    final boolean mo2967f() {
        Log.i("MMM", "私密来电判断");
        return m2963b() == 2 && this.f6984a.f7016c.contains(((CallLogEntity) m2960a()).phonenum, 0);
    }

    @Override // tms.C1167ax.a
    /* JADX INFO: renamed from: g */
    final void mo2968g() {
        C1216cs.b.m3054a(this.f6984a, this, this.f6984a.f7018e, true, true);
    }
}
