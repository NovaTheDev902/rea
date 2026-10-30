package tms;

import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.common.TMSService;

/* JADX INFO: renamed from: tms.k */
/* JADX INFO: loaded from: classes.dex */
public class RunnableC1325k implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ TMSService f7452a;

    public RunnableC1325k(TMSService tMSService) {
        this.f7452a = tMSService;
    }

    @Override // java.lang.Runnable
    public void run() {
        int iM3537b = C1330p.m3532a(TMSApplication.getApplicaionContext()).m3537b();
        C1149af c1149af = new C1149af("wup");
        c1149af.m2889a(C1331q.f7470a, iM3537b == 0, true);
        if (iM3537b == 0) {
            c1149af.m2887a(C1331q.f7471b, System.currentTimeMillis(), true);
        }
    }
}
