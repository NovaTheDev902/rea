package tms;

/* JADX INFO: renamed from: tms.fm */
/* JADX INFO: loaded from: classes.dex */
final class C1291fm extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1309gn.a f7333a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ String f7334b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ C1309gn.d f7335c;

    C1291fm(C1309gn.d dVar, C1309gn.a aVar, String str) {
        this.f7335c = dVar;
        this.f7333a = aVar;
        this.f7334b = str;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        super.run();
        synchronized (C1309gn.this.f7410a) {
            this.f7333a.mo3311a(this.f7334b);
        }
    }
}
