package tms;

import android.bluetooth.BluetoothDevice;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;
import com.tencent.tmsecure.module.powersaving.BlueToothHelper;
import java.util.ArrayList;
import java.util.Iterator;

/* JADX INFO: renamed from: tms.eu */
/* JADX INFO: loaded from: classes.dex */
final class C1272eu extends BlueToothHelper.BlueToothObserver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ RunnableC1302ga f7287a;

    C1272eu(RunnableC1302ga runnableC1302ga) {
        this.f7287a = runnableC1302ga;
    }

    @Override // com.tencent.tmsecure.module.powersaving.BlueToothHelper.BlueToothObserver
    public final void ScanFinish(ArrayList<BluetoothDevice> arrayList) {
        boolean z;
        if ((this.f7287a.f7375a.mBlueToothAutoCloseCondition & 2) == 2) {
            if (arrayList.size() != 0) {
                this.f7287a.f7376b.f6208k.postDelayed(this.f7287a.f7376b.f6209l, 300000L);
                return;
            } else {
                ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).disableBluetooth();
                AbstractC1265en.f7254d = true;
                return;
            }
        }
        Iterator<BluetoothDevice> it = arrayList.iterator();
        while (true) {
            if (!it.hasNext()) {
                z = false;
                break;
            } else if (it.next().getBondState() == 12) {
                z = true;
                break;
            }
        }
        if (z) {
            this.f7287a.f7376b.f6208k.postDelayed(this.f7287a.f7376b.f6209l, 300000L);
        } else {
            ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).disableBluetooth();
            AbstractC1265en.f7254d = true;
        }
    }
}
