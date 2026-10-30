package tms;

import android.database.ContentObserver;
import android.os.Handler;

/* JADX INFO: renamed from: tms.an */
/* JADX INFO: loaded from: classes.dex */
final class C1157an extends ContentObserver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1172bb f6840a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ C1172bb.c f6841b;

    /* JADX INFO: renamed from: c */
    private long f6842c;

    /* JADX INFO: renamed from: d */
    private Handler f6843d;

    /* JADX INFO: renamed from: e */
    private Runnable f6844e;

    /* JADX WARN: 'super' call moved to the top of the method (can break code semantics) */
    C1157an(C1172bb.c cVar, Handler handler, C1172bb c1172bb) {
        super(handler);
        this.f6841b = cVar;
        this.f6840a = c1172bb;
        this.f6842c = -1L;
        this.f6843d = new Handler(C1172bb.this.f6894e.getMainLooper());
        this.f6844e = new RunnableC1163at(this);
    }

    @Override // android.database.ContentObserver
    public final void onChange(boolean z) {
        super.onChange(z);
        long jCurrentTimeMillis = System.currentTimeMillis();
        if (jCurrentTimeMillis - this.f6842c <= 20000 || !this.f6841b.f6906e) {
            return;
        }
        this.f6842c = jCurrentTimeMillis;
        this.f6843d.removeCallbacks(this.f6844e);
        this.f6843d.postDelayed(this.f6844e, 20000L);
    }
}
