package tms;

/* JADX INFO: renamed from: tms.am */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1156am implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1169az f6839a;

    RunnableC1156am(C1169az c1169az) {
        this.f6839a = c1169az;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f6839a.cancelMissCall();
    }
}
