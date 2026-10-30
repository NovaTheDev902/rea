package tms;

import android.content.Intent;

/* JADX INFO: renamed from: tms.ac */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1146ac implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ Intent f6818a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1337w.a f6819b;

    /* JADX INFO: renamed from: c */
    final /* synthetic */ C1337w f6820c;

    RunnableC1146ac(C1337w c1337w, Intent intent, C1337w.a aVar) {
        this.f6820c = c1337w;
        this.f6818a = intent;
        this.f6819b = aVar;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f6820c.f7482d.bindService(this.f6818a, this.f6819b, 1);
    }
}
