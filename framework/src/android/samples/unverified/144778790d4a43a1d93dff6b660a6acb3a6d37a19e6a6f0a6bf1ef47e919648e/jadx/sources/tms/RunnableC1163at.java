package tms;

/* JADX INFO: renamed from: tms.at */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1163at implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1157an f6854a;

    RunnableC1163at(C1157an c1157an) {
        this.f6854a = c1157an;
    }

    @Override // java.lang.Runnable
    public final void run() {
        synchronized (this.f6854a.f6841b.f6903b) {
            this.f6854a.f6841b.m2988a();
        }
    }
}
