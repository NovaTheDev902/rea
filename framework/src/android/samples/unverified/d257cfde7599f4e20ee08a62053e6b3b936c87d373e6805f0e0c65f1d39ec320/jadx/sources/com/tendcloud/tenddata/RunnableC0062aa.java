package com.tendcloud.tenddata;

/* JADX INFO: renamed from: com.tendcloud.tenddata.aa */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0062aa implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ Throwable f51a;

    RunnableC0062aa(Throwable th) {
        this.f51a = th;
    }

    @Override // java.lang.Runnable
    public void run() {
        try {
            if (TCAgent.f8H && TCAgent.f12L != null) {
                TCAgent.m21b(this.f51a);
            }
        } catch (Throwable th) {
        }
    }
}
