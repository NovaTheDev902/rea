package seC.dujmehn.kiit;

import java.lang.reflect.InvocationTargetException;

/* JADX INFO: renamed from: seC.dujmehn.kiit.r */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0260r implements Runnable {

    /* JADX INFO: renamed from: q */
    final /* synthetic */ CharSequence f82q;

    /* JADX INFO: renamed from: r */
    final /* synthetic */ STKIITIuhlysu.C02582 f83r;

    RunnableC0260r(STKIITIuhlysu.C02582 c02582, CharSequence charSequence) {
        this.f83r = c02582;
        this.f82q = charSequence;
    }

    @Override // java.lang.Runnable
    public final void run() throws IllegalAccessException, InvocationTargetException {
        STKIITIuhlysu.C02582.m60q(this.f83r, this.f82q);
    }
}
