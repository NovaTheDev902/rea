package tms;

import java.io.File;
import java.io.FileFilter;
import java.util.List;

/* JADX INFO: renamed from: tms.fu */
/* JADX INFO: loaded from: classes.dex */
final class C1299fu implements FileFilter {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ List f7371a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ boolean f7372b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ List f7373c;

    C1299fu(List list, boolean z, List list2) {
        this.f7371a = list;
        this.f7372b = z;
        this.f7373c = list2;
    }

    @Override // java.io.FileFilter
    public final boolean accept(File file) {
        if (file.isDirectory() && (this.f7371a == null || !this.f7371a.contains(file.getAbsolutePath()))) {
            return true;
        }
        if (file.getAbsolutePath().toLowerCase().endsWith(".apk") || (this.f7372b && C1336v.m3602f(file))) {
            this.f7373c.add(file.getAbsolutePath());
        }
        return false;
    }
}
