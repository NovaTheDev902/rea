package com.tencent.lbsapi.core;

import com.lenovo.performancecenter.coreui.util.Utils;

/* JADX INFO: renamed from: com.tencent.lbsapi.core.g */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1069g implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ QLBSEngine f5970a;

    RunnableC1069g(QLBSEngine qLBSEngine) {
        this.f5970a = qLBSEngine;
    }

    @Override // java.lang.Runnable
    public final void run() {
        if (!this.f5970a.f5930n && this.f5970a.f5929m) {
            this.f5970a.f5930n = true;
            this.f5970a.f5921e.postDelayed(this.f5970a.f5918b, Utils.CLICK_INTERVAL);
        }
        if (this.f5970a.f5937u == 0 && this.f5970a.f5938v == 900000000 && this.f5970a.f5941y.size() == 0) {
            if (this.f5970a.f5920d != null) {
                this.f5970a.f5920d.onLocationNotification(0);
                QLBSEngine.m2510i(this.f5970a);
            }
        } else if (this.f5970a.f5920d != null) {
            this.f5970a.f5920d.onLocationNotification(1);
            QLBSEngine.m2510i(this.f5970a);
        }
        this.f5970a.f5921e.removeCallbacks(this.f5970a.f5917a);
        QLBSEngine.m2511j(this.f5970a);
    }
}
