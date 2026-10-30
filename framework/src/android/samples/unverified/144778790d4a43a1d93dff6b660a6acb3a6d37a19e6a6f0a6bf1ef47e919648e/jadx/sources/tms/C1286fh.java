package tms;

import java.util.Iterator;

/* JADX INFO: renamed from: tms.fh */
/* JADX INFO: loaded from: classes.dex */
final class C1286fh implements C1309gn.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1309gn.d f7324a;

    C1286fh(C1309gn.d dVar) {
        this.f7324a = dVar;
    }

    @Override // tms.C1309gn.a
    /* JADX INFO: renamed from: a */
    public final void mo3311a(String str) {
        Iterator it = C1309gn.this.f7410a.iterator();
        while (it.hasNext()) {
            ((C1309gn.b) it.next()).onPackageRemoved(str);
        }
    }
}
