package tms;

import java.util.Iterator;

/* JADX INFO: renamed from: tms.fg */
/* JADX INFO: loaded from: classes.dex */
final class C1285fg implements C1309gn.a {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1309gn.d f7323a;

    C1285fg(C1309gn.d dVar) {
        this.f7323a = dVar;
    }

    @Override // tms.C1309gn.a
    /* JADX INFO: renamed from: a */
    public final void mo3311a(String str) {
        Iterator it = C1309gn.this.f7410a.iterator();
        while (it.hasNext()) {
            ((C1309gn.b) it.next()).onPackageAdded(str);
        }
    }
}
