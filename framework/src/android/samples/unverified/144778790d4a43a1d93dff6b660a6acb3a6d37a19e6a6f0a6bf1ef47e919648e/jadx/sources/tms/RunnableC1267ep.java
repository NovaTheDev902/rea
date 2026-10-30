package tms;

import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;

/* JADX INFO: renamed from: tms.ep */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC1267ep implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ AbstractC1265en f7270a;

    RunnableC1267ep(AbstractC1265en abstractC1265en) {
        this.f7270a = abstractC1265en;
    }

    @Override // java.lang.Runnable
    public final void run() {
        AbstractC1265en.f7253c = true;
        AbstractC1265en.m3233b(this.f7270a);
        ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).setMobileDataConnectivity(false);
    }
}
