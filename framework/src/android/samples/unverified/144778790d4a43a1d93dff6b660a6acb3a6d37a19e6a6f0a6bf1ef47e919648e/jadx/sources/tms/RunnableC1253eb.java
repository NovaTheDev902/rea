package tms;

/* JADX INFO: renamed from: tms.eb */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1253eb implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1250dz f7231a;

    RunnableC1253eb(C1250dz c1250dz) {
        this.f7231a = c1250dz;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f7231a.f7226c.close();
    }
}
