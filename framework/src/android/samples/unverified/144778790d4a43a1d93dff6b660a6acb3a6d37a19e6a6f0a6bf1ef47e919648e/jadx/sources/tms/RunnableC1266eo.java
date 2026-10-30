package tms;

import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;

/* JADX INFO: renamed from: tms.eo */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1266eo implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ AbstractC1265en f7269a;

    RunnableC1266eo(AbstractC1265en abstractC1265en) {
        this.f7269a = abstractC1265en;
    }

    @Override // java.lang.Runnable
    public final void run() {
        ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).setWifiEnabled(false);
        AbstractC1265en.f7252b = true;
        AbstractC1265en.m3232a(this.f7269a);
    }
}
