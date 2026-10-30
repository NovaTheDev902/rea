package tms;

/* JADX INFO: renamed from: tms.fd */
/* JADX INFO: loaded from: classes.dex */
final class C1282fd extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ String f7311a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1309gn.b f7312b;

    C1282fd(C1309gn.b bVar, String str) {
        this.f7312b = bVar;
        this.f7311a = str;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        this.f7312b.f7413a.onPackageRemoved(this.f7311a);
    }
}
