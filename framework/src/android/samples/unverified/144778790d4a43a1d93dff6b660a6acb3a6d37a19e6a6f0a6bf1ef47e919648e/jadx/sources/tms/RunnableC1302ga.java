package tms;

import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;
import com.tencent.tmsecure.module.powersaving.BlueToothHelper;
import com.tencent.tmsecure.module.powersaving.PowerSavingConfig;

/* JADX INFO: renamed from: tms.ga */
/* JADX INFO: loaded from: classes.dex */
public class RunnableC1302ga implements Runnable {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ PowerSavingConfig f7375a;

    /* JADX INFO: renamed from: b */
    final /* synthetic */ BlueToothHelper f7376b;

    public RunnableC1302ga(BlueToothHelper blueToothHelper, PowerSavingConfig powerSavingConfig) {
        this.f7376b = blueToothHelper;
        this.f7375a = powerSavingConfig;
    }

    @Override // java.lang.Runnable
    public void run() {
        if ((this.f7375a.mBlueToothAutoCloseCondition & 2) == 2 || (this.f7375a.mBlueToothAutoCloseCondition & 4) == 4) {
            this.f7376b.m2625a(new C1272eu(this));
            return;
        }
        if ((this.f7375a.mBlueToothAutoCloseCondition & 8) == 8) {
            if (this.f7376b.f6202a) {
                this.f7376b.f6208k.postDelayed(this.f7376b.f6209l, 300000L);
            } else {
                ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).disableBluetooth();
                AbstractC1265en.f7254d = true;
            }
        }
    }
}
