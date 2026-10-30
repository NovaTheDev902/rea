package tms;

import android.content.Context;
import android.net.ConnectivityManager;
import android.util.Log;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;

/* JADX INFO: renamed from: tms.eq */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1268eq implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ Context f7271a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ AbstractC1265en f7272b;

    RunnableC1268eq(AbstractC1265en abstractC1265en, Context context) {
        this.f7272b = abstractC1265en;
        this.f7271a = context;
    }

    @Override // java.lang.Runnable
    public final void run() {
        Log.i(this.f7272b.f7258e, "start check");
        if (((ConnectivityManager) this.f7271a.getSystemService("connectivity")).getNetworkInfo(1).isConnected()) {
            return;
        }
        ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).setWifiEnabled(false);
        AbstractC1265en.f7252b = true;
    }
}
