package tms;

/* JADX INFO: renamed from: tms.fe */
/* JADX INFO: loaded from: classes.dex */
final class C1283fe extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ String f7313a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1309gn.b f7314b;

    C1283fe(C1309gn.b bVar, String str) {
        this.f7314b = bVar;
        this.f7313a = str;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        this.f7314b.f7413a.onPackageReinstall(this.f7313a);
    }
}
