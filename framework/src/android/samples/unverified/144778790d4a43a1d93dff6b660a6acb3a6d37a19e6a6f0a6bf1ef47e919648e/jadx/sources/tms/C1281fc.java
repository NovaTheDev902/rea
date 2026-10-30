package tms;

/* JADX INFO: renamed from: tms.fc */
/* JADX INFO: loaded from: classes.dex */
final class C1281fc extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ String f7309a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1309gn.b f7310b;

    C1281fc(C1309gn.b bVar, String str) {
        this.f7310b = bVar;
        this.f7309a = str;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        this.f7310b.f7413a.onPackageAdded(this.f7309a);
    }
}
