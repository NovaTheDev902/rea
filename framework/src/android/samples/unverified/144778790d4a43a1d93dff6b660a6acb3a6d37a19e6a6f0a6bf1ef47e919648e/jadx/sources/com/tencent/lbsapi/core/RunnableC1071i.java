package com.tencent.lbsapi.core;

/* JADX INFO: renamed from: com.tencent.lbsapi.core.i */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1071i implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ QLBSEngine f5972a;

    RunnableC1071i(QLBSEngine qLBSEngine) {
        this.f5972a = qLBSEngine;
    }

    @Override // java.lang.Runnable
    public final void run() {
        if (this.f5972a.f5929m) {
            if (this.f5972a.f5923g != null && this.f5972a.f5925i != null) {
                this.f5972a.f5923g.removeUpdates(this.f5972a.f5925i);
            }
            QLBSEngine.m2514m(this.f5972a);
        }
        this.f5972a.f5921e.removeCallbacks(this.f5972a.f5918b);
        this.f5972a.f5930n = false;
    }
}
