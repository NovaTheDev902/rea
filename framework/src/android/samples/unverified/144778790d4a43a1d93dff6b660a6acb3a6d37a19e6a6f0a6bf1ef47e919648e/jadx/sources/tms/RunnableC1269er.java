package tms;

import com.tencent.tmsecure.module.netsetting.NetSettingManager;

/* JADX INFO: renamed from: tms.er */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1269er implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ NetSettingManager f7273a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ AbstractC1265en f7274b;

    RunnableC1269er(AbstractC1265en abstractC1265en, NetSettingManager netSettingManager) {
        this.f7274b = abstractC1265en;
        this.f7273a = netSettingManager;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f7273a.setWifiEnabled(false);
        AbstractC1265en.f7252b = true;
    }
}
