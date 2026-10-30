package tms;

import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.media.AudioManager;
import android.provider.Settings;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;
import com.tencent.tmsecure.module.powersaving.IBatteryInfoHelper;
import com.tencent.tmsecure.module.powersaving.PowerSavingConfig;
import com.tencent.tmsecure.module.powersaving.PowerSavingEventListener;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: renamed from: tms.gd */
/* JADX INFO: loaded from: classes.dex */
public class C1304gd extends BaseManager {

    /* JADX INFO: renamed from: a */
    private PowerSavingConfig f7377a;

    /* JADX INFO: renamed from: c */
    private Context f7379c;

    /* JADX INFO: renamed from: d */
    private IBatteryInfoHelper f7380d;

    /* JADX INFO: renamed from: b */
    private boolean f7378b = true;

    /* JADX INFO: renamed from: e */
    private AbstractC1265en f7381e = new C1273ev(this);

    /* JADX INFO: renamed from: f */
    private List<WeakReference<PowerSavingEventListener>> f7382f = new ArrayList();

    /* JADX INFO: renamed from: a */
    private void m3347a(boolean z) {
        ((AudioManager) this.f7379c.getSystemService("audio")).setVibrateSetting(0, z ? 1 : 0);
    }

    /* JADX INFO: renamed from: b */
    private void m3350b(boolean z) {
        Settings.System.putInt(this.f7379c.getContentResolver(), "haptic_feedback_enabled", z ? 1 : 0);
    }

    /* JADX INFO: renamed from: c */
    private void m3352c(boolean z) {
        Settings.System.putInt(this.f7379c.getContentResolver(), "airplane_mode_on", z ? 1 : 0);
        Intent intent = new Intent("android.intent.action.AIRPLANE_MODE");
        intent.putExtra("state", z);
        this.f7379c.sendBroadcast(intent);
    }

    /* JADX INFO: renamed from: a */
    public int m3353a() {
        return AbstractC1265en.f7251a;
    }

    /* JADX INFO: renamed from: a */
    public void m3354a(PowerSavingConfig powerSavingConfig, boolean z) {
        if (powerSavingConfig == null) {
            return;
        }
        this.f7377a = powerSavingConfig;
        this.f7378b = z;
        if (powerSavingConfig.mBrightness <= 0) {
            C1328n.m3530d(this.f7379c.getContentResolver());
        } else {
            C1328n.m3529c(this.f7379c.getContentResolver());
            C1328n.m3526a(powerSavingConfig.mBrightness, this.f7379c.getContentResolver());
        }
        Settings.System.putInt(this.f7379c.getContentResolver(), "screen_off_timeout", powerSavingConfig.mScreenOffTime);
        this.f7379c.getContentResolver().notifyChange(Settings.System.getUriFor("screen_off_timeout"), null);
        if (powerSavingConfig.mHapticFeedbackStateOperation == 1) {
            m3350b(true);
        } else if (powerSavingConfig.mHapticFeedbackStateOperation == 2) {
            m3350b(false);
        }
        if (powerSavingConfig.mVibrateStateOperation == 1) {
            m3347a(true);
        } else if (powerSavingConfig.mVibrateStateOperation == 2) {
            m3347a(false);
        }
        if (powerSavingConfig.mAutoSyncStateOperation == 1) {
            ContentResolver.setMasterSyncAutomatically(true);
        } else if (powerSavingConfig.mAutoSyncStateOperation == 2) {
            ContentResolver.setMasterSyncAutomatically(false);
        }
        NetSettingManager netSettingManager = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
        boolean z2 = Settings.System.getInt(this.f7379c.getContentResolver(), "airplane_mode_on", 0) == 1;
        if (powerSavingConfig.mAirplaneModeStateOperation != 1) {
            if (powerSavingConfig.mAirplaneModeStateOperation == 2 && z2) {
                m3352c(false);
            }
            if (powerSavingConfig.mWifiStateOperation == 1 && !netSettingManager.isWifiEnabled()) {
                netSettingManager.setWifiEnabled(true);
                AbstractC1265en.f7252b = true;
            } else if (powerSavingConfig.mWifiStateOperation == 2 && netSettingManager.isWifiEnabled()) {
                netSettingManager.setWifiEnabled(false);
                AbstractC1265en.f7252b = true;
            }
            NetSettingManager netSettingManager2 = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
            if (powerSavingConfig.mMobileNetWorkStateOperation == 1 && !netSettingManager2.getMobileDataConnectivity()) {
                ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).setMobileDataConnectivity(true);
                AbstractC1265en.f7253c = true;
            } else if (powerSavingConfig.mMobileNetWorkStateOperation == 2 && netSettingManager2.getMobileDataConnectivity()) {
                ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).setMobileDataConnectivity(false);
                AbstractC1265en.f7253c = true;
            }
            if (powerSavingConfig.mBlueToothStateOperation == 1 && !netSettingManager.isBluetoothEnabled()) {
                netSettingManager.enableBluetooth();
                AbstractC1265en.f7254d = true;
            } else if (powerSavingConfig.mBlueToothStateOperation == 2 && netSettingManager.isBluetoothEnabled()) {
                netSettingManager.disableBluetooth();
                AbstractC1265en.f7254d = true;
            }
        } else if (z2) {
            if (netSettingManager.isWifiEnabled()) {
                netSettingManager.setWifiEnabled(false);
                AbstractC1265en.f7252b = true;
            }
            if (((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).getMobileDataConnectivity()) {
                ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).setMobileDataConnectivity(false);
                AbstractC1265en.f7253c = true;
            }
            if (netSettingManager.isBluetoothEnabled()) {
                netSettingManager.disableBluetooth();
                AbstractC1265en.f7254d = true;
            }
        } else {
            m3352c(true);
        }
        int i = PowerSavingConfig.ANIMATION_STATE_SETTINGS[powerSavingConfig.mAnimationState];
        new C1274ew();
        float[] fArrM3271a = C1274ew.m3271a();
        if (fArrM3271a != null && fArrM3271a.length >= 1) {
            fArrM3271a[0] = i % 10;
        }
        if (fArrM3271a != null && fArrM3271a.length >= 2) {
            fArrM3271a[1] = (i / 10) % 10;
        }
        C1274ew.m3270a(fArrM3271a);
    }

    /* JADX INFO: renamed from: a */
    public void m3355a(PowerSavingEventListener powerSavingEventListener) {
        this.f7382f.add(new WeakReference<>(powerSavingEventListener));
    }

    /* JADX INFO: renamed from: b */
    public synchronized IBatteryInfoHelper m3356b() {
        if (this.f7380d == null) {
            this.f7380d = new C1271et(this.f7379c);
        }
        return this.f7380d;
    }

    /* JADX INFO: renamed from: b */
    public void m3357b(PowerSavingEventListener powerSavingEventListener) {
        if (powerSavingEventListener == null) {
            return;
        }
        synchronized (this.f7382f) {
            int i = 0;
            while (true) {
                int i2 = i;
                if (i2 >= this.f7382f.size()) {
                    break;
                }
                WeakReference<PowerSavingEventListener> weakReference = this.f7382f.get(i2);
                if (weakReference.get() == powerSavingEventListener) {
                    this.f7382f.remove(weakReference);
                    break;
                }
                i = i2 + 1;
            }
        }
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public void onCreate(Context context) {
        this.f7379c = context;
        IntentFilter intentFilter = new IntentFilter("android.intent.action.SCREEN_OFF");
        intentFilter.addAction("android.intent.action.SCREEN_ON");
        intentFilter.addAction("android.intent.action.BATTERY_CHANGED");
        intentFilter.addAction("android.net.wifi.WIFI_STATE_CHANGED");
        intentFilter.addAction("android.net.wifi.RSSI_CHANGED");
        intentFilter.addAction("android.net.conn.CONNECTIVITY_CHANGE");
        intentFilter.addAction("android.bluetooth.adapter.action.STATE_CHANGED");
        intentFilter.addAction("android.bluetooth.device.action.ACL_CONNECTED");
        intentFilter.addAction("android.bluetooth.device.action.ACL_DISCONNECTED");
        this.f7379c.registerReceiver(this.f7381e, intentFilter);
    }
}
