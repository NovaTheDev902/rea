package tms;

import android.content.IntentFilter;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.wupsession.WupSessionManager;

/* JADX INFO: renamed from: tms.ft */
/* JADX INFO: loaded from: classes.dex */
final class C1298ft extends Thread {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ C1149af f7370a;

    C1298ft(C1149af c1149af) {
        this.f7370a = c1149af;
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public final void run() {
        if (C1313h.f7429b) {
            TMSApplication.getApplicaionContext().unregisterReceiver(C1313h.f7430c);
            boolean unused = C1313h.f7429b = false;
        }
        try {
            Thread.sleep(NetConstant.SLEEP_SECONDS_TEN);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        if (((WupSessionManager) ManagerCreator.getManager(WupSessionManager.class)).reportChannelInfo() == 0) {
            this.f7370a.m2889a("reportlc", true, true);
        } else if (!C1313h.f7429b) {
            TMSApplication.getApplicaionContext().registerReceiver(C1313h.f7430c, new IntentFilter("android.net.conn.CONNECTIVITY_CHANGE"));
            boolean unused2 = C1313h.f7429b = true;
        }
        C1313h.m3451e();
    }
}
