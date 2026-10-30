package tms;

import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import com.tencent.tmsecure.module.powersaving.BlueToothHelper;
import com.tencent.tmsecure.utils.Log;

/* JADX INFO: renamed from: tms.fz */
/* JADX INFO: loaded from: classes.dex */
public class C1300fz extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    final /* synthetic */ BlueToothHelper f7374a;

    public C1300fz(BlueToothHelper blueToothHelper) {
        this.f7374a = blueToothHelper;
    }

    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();
        if ("android.bluetooth.adapter.action.DISCOVERY_STARTED".equals(action)) {
            Log.m2636i(this.f7374a.f6203b, "start to scan");
            this.f7374a.f6205d.clear();
            return;
        }
        if ("android.bluetooth.device.action.FOUND".equals(action)) {
            Log.m2636i(this.f7374a.f6203b, "found device");
            this.f7374a.f6205d.add((BluetoothDevice) intent.getParcelableExtra("android.bluetooth.device.extra.DEVICE"));
        } else if ("android.bluetooth.adapter.action.DISCOVERY_FINISHED".equals(action)) {
            Log.m2636i(this.f7374a.f6203b, "scan finish");
            if (this.f7374a.f6207f != null) {
                this.f7374a.f6207f.ScanFinish(this.f7374a.f6205d);
            }
        }
    }
}
