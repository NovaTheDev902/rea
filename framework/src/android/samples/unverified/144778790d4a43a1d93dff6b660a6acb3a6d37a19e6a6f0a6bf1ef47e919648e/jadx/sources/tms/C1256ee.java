package tms;

import java.io.File;
import java.io.FilenameFilter;

/* JADX INFO: renamed from: tms.ee */
/* JADX INFO: loaded from: classes.dex */
final class C1256ee implements FilenameFilter {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1293fo f7234a;

    C1256ee(C1293fo c1293fo) {
        this.f7234a = c1293fo;
    }

    @Override // java.io.FilenameFilter
    public final boolean accept(File file, String str) {
        return !this.f7234a.f7345h.containsKey(str) && str.endsWith(".tsp");
    }
}
