package tms;

import java.util.Comparator;

/* JADX INFO: renamed from: tms.aw */
/* JADX INFO: loaded from: classes.dex */
final class C1166aw implements Comparator<C1172bb.d> {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1172bb.c f6863a;

    C1166aw(C1172bb.c cVar) {
        this.f6863a = cVar;
    }

    @Override // java.util.Comparator
    public final /* synthetic */ int compare(C1172bb.d dVar, C1172bb.d dVar2) {
        return Integer.valueOf(dVar.f6907a).compareTo(Integer.valueOf(dVar2.f6907a));
    }
}
