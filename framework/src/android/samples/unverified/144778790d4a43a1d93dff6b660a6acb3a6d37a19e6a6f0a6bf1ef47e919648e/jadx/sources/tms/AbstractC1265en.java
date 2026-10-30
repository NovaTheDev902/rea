package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.net.NetworkInfo;
import android.net.wifi.WifiManager;
import android.os.Handler;
import android.util.Log;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;
import com.tencent.tmsecure.module.network.NetworkManager;
import com.tencent.tmsecure.module.powersaving.BlueToothHelper;
import com.tencent.tmsecure.module.powersaving.PowerSavingConfig;

/* JADX INFO: renamed from: tms.en */
/* JADX INFO: loaded from: classes.dex */
abstract class AbstractC1265en extends BroadcastReceiver {

    /* JADX INFO: renamed from: a */
    static int f7251a;

    /* JADX INFO: renamed from: b */
    static boolean f7252b;

    /* JADX INFO: renamed from: c */
    static boolean f7253c;

    /* JADX INFO: renamed from: d */
    static boolean f7254d;

    /* JADX INFO: renamed from: m */
    private static boolean f7255m;

    /* JADX INFO: renamed from: q */
    private static boolean f7256q = true;

    /* JADX INFO: renamed from: r */
    private static boolean f7257r;

    /* JADX INFO: renamed from: l */
    private boolean f7265l;

    /* JADX INFO: renamed from: n */
    private Runnable f7266n;

    /* JADX INFO: renamed from: o */
    private Handler f7267o;

    /* JADX INFO: renamed from: e */
    private String f7258e = "AbsPowerSavingBroadcastReceiver";

    /* JADX INFO: renamed from: f */
    private Runnable f7259f = null;

    /* JADX INFO: renamed from: g */
    private Runnable f7260g = null;

    /* JADX INFO: renamed from: h */
    private Handler f7261h = null;

    /* JADX INFO: renamed from: i */
    private Handler f7262i = null;

    /* JADX INFO: renamed from: j */
    private boolean f7263j = false;

    /* JADX INFO: renamed from: k */
    private boolean f7264k = false;

    /* JADX INFO: renamed from: p */
    private final int f7268p = 300000;

    AbstractC1265en() {
        NetSettingManager netSettingManager = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
        f7255m = netSettingManager.isWifiEnabled();
        f7253c = netSettingManager.getMobileDataConnectivity();
        f7257r = netSettingManager.isBluetoothEnabled();
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m3232a(AbstractC1265en abstractC1265en) {
        abstractC1265en.f7263j = false;
        return false;
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ boolean m3233b(AbstractC1265en abstractC1265en) {
        abstractC1265en.f7264k = false;
        return false;
    }

    /* JADX INFO: renamed from: a */
    public abstract void mo3235a(Intent intent);

    /* JADX INFO: renamed from: a */
    public abstract void mo3236a(boolean z);

    /* JADX INFO: renamed from: a */
    public abstract boolean mo3237a();

    /* JADX INFO: renamed from: b */
    public abstract PowerSavingConfig mo3238b();

    /* JADX INFO: renamed from: b */
    public abstract void mo3239b(Intent intent);

    /* JADX INFO: renamed from: b */
    public abstract void mo3240b(boolean z);

    /* JADX INFO: renamed from: c */
    public abstract void mo3241c(Intent intent);

    /* JADX INFO: renamed from: c */
    public abstract void mo3242c(boolean z);

    /* JADX INFO: renamed from: d */
    public abstract void mo3243d(Intent intent);

    /* JADX INFO: renamed from: d */
    public abstract void mo3244d(boolean z);

    /* JADX INFO: renamed from: e */
    public abstract void mo3245e(boolean z);

    /* JADX INFO: renamed from: f */
    public abstract void mo3246f(boolean z);

    @Override // android.content.BroadcastReceiver
    public void onReceive(Context context, Intent intent) {
        String action = intent.getAction();
        if ("android.intent.action.SCREEN_OFF".equals(action) || "android.intent.action.SCREEN_ON".equals(action)) {
            PowerSavingConfig powerSavingConfigMo3238b = mo3238b();
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                Log.i(this.f7258e, "Screen off");
                ((NetworkManager) ManagerCreator.getManager(NetworkManager.class)).setInterval(0);
                if (mo3237a()) {
                    return;
                }
                if ((powerSavingConfigMo3238b.mWifiAutoCloseCondition & 8) == 8 && f7255m) {
                    Log.i(this.f7258e, "start disable wifi");
                    if (this.f7261h == null) {
                        this.f7261h = new Handler();
                    }
                    if (this.f7259f == null) {
                        this.f7259f = new RunnableC1266eo(this);
                    }
                    this.f7261h.postDelayed(this.f7259f, powerSavingConfigMo3238b.mWifiAutoCloseScreenTime);
                    this.f7263j = true;
                }
                if ((powerSavingConfigMo3238b.mMobileNetWorkAutoCloseCondition & 2) == 2 && f7256q) {
                    if (this.f7262i == null) {
                        this.f7262i = new Handler();
                    }
                    if (this.f7260g == null) {
                        this.f7260g = new RunnableC1267ep(this);
                    }
                    this.f7262i.postDelayed(this.f7260g, powerSavingConfigMo3238b.mWifiAutoCloseScreenTime);
                    this.f7264k = true;
                    return;
                }
                return;
            }
            if (intent.getAction().equals("android.intent.action.SCREEN_ON")) {
                Log.i(this.f7258e, "Screen on");
                if (this.f7263j) {
                    this.f7261h.removeCallbacks(this.f7259f);
                    this.f7263j = false;
                }
                if (!mo3237a() && (powerSavingConfigMo3238b.mWifiAutoOpenCondition & 4) == 4 && f7255m) {
                    Log.i(this.f7258e, "start enable wifi");
                    NetSettingManager netSettingManager = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
                    if (!netSettingManager.isWifiEnabled()) {
                        netSettingManager.setWifiEnabled(true);
                        f7252b = true;
                    }
                }
                if (this.f7264k) {
                    this.f7262i.removeCallbacks(this.f7260g);
                    this.f7264k = false;
                }
                if (!mo3237a() && (powerSavingConfigMo3238b.mMobileNetWorkAutoOpenCondition & 4) == 4 && f7256q) {
                    NetSettingManager netSettingManager2 = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
                    if (!netSettingManager2.getMobileDataConnectivity()) {
                        netSettingManager2.setMobileDataConnectivity(true);
                        f7253c = true;
                    }
                }
                if (!mo3237a() && (powerSavingConfigMo3238b.mBlueToothAutoOpenCondition & 4) == 4 && f7257r) {
                    ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).enableBluetooth();
                    f7254d = true;
                    return;
                }
                return;
            }
            return;
        }
        if ("android.intent.action.BATTERY_CHANGED".equals(action)) {
            if (intent.getAction().equals("android.intent.action.BATTERY_CHANGED")) {
                int intExtra = (intent.getIntExtra("level", 0) * 100) / intent.getIntExtra("scale", 100);
                if (intExtra > 100) {
                    intExtra = 100;
                }
                if (f7251a != intExtra) {
                    f7251a = intExtra;
                    mo3235a(intent);
                }
                int intExtra2 = intent.getIntExtra("status", 1);
                PowerSavingConfig powerSavingConfigMo3238b2 = mo3238b();
                if (intExtra2 != 2) {
                    if (intExtra2 == 5) {
                        Log.i(this.f7258e, "receive full msg");
                        if (this.f7265l) {
                            Log.i(this.f7258e, "full!");
                            this.f7265l = false;
                            mo3243d(intent);
                            return;
                        }
                        return;
                    }
                    if (intExtra2 == 4 || intExtra2 == 3) {
                        Log.i(this.f7258e, "receive stop msg::" + intExtra2);
                        if (this.f7265l) {
                            Log.i(this.f7258e, "stop!");
                            this.f7265l = false;
                            mo3241c(intent);
                            return;
                        }
                        return;
                    }
                    return;
                }
                Log.i(this.f7258e, "start charge");
                if (this.f7265l) {
                    return;
                }
                this.f7265l = true;
                mo3239b(intent);
                if (mo3237a()) {
                    return;
                }
                if ((powerSavingConfigMo3238b2.mWifiAutoOpenCondition & 2) == 2 && f7255m) {
                    NetSettingManager netSettingManager3 = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
                    if (!netSettingManager3.isWifiEnabled()) {
                        netSettingManager3.setWifiEnabled(true);
                        f7252b = true;
                    }
                }
                if ((powerSavingConfigMo3238b2.mMobileNetWorkAutoOpenCondition & 2) == 2 && f7256q) {
                    ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).setMobileDataConnectivity(true);
                    f7253c = true;
                }
                if ((powerSavingConfigMo3238b2.mBlueToothAutoOpenCondition & 2) == 2 && f7257r) {
                    ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).enableBluetooth();
                    f7254d = true;
                    return;
                }
                return;
            }
            return;
        }
        if ("android.net.wifi.WIFI_STATE_CHANGED".equals(action) || "android.net.wifi.RSSI_CHANGED".equals(action)) {
            PowerSavingConfig powerSavingConfigMo3238b3 = mo3238b();
            if (!intent.getAction().equals("android.net.wifi.WIFI_STATE_CHANGED")) {
                if (intent.getAction().equals("android.net.wifi.RSSI_CHANGED") && !mo3237a() && (powerSavingConfigMo3238b3.mWifiAutoCloseCondition & 4) == 4) {
                    if (this.f7267o != null && this.f7266n != null) {
                        this.f7267o.removeCallbacks(this.f7266n);
                        this.f7267o = null;
                        this.f7266n = null;
                    }
                    NetSettingManager netSettingManager4 = (NetSettingManager) ManagerCreator.getManager(NetSettingManager.class);
                    int i = 100 / powerSavingConfigMo3238b3.mWifiLowSignalThreshold;
                    int wifiRssi = netSettingManager4.getWifiRssi();
                    if (netSettingManager4.getWifiState() != 2 && netSettingManager4.getWifiState() != 0 && WifiManager.calculateSignalLevel(wifiRssi, i) == 0) {
                        this.f7267o = new Handler();
                        this.f7266n = new RunnableC1269er(this, netSettingManager4);
                        this.f7267o.postDelayed(this.f7266n, 300000L);
                    }
                    Log.i(this.f7258e, "wifi rssi::" + wifiRssi);
                    return;
                }
                return;
            }
            int intExtra3 = intent.getIntExtra("wifi_state", 0);
            if (intExtra3 == 2) {
                Log.i(this.f7258e, "open wifi");
                if (!f7252b) {
                    f7255m = true;
                }
                if (mo3237a() || (powerSavingConfigMo3238b3.mWifiAutoCloseCondition & 2) != 2) {
                    return;
                }
                new Handler().postDelayed(new RunnableC1268eq(this, context), powerSavingConfigMo3238b3.mWifiOverTimeDuration);
                return;
            }
            if (intExtra3 == 3) {
                Log.i(this.f7258e, "open wifi");
                mo3240b(f7252b);
                if (f7252b) {
                    f7252b = false;
                    return;
                } else {
                    f7255m = true;
                    return;
                }
            }
            if (intExtra3 == 1) {
                Log.i(this.f7258e, "close wifi");
                mo3236a(f7252b);
                if (f7252b) {
                    f7252b = false;
                    return;
                } else {
                    f7255m = false;
                    return;
                }
            }
            return;
        }
        if ("android.net.conn.CONNECTIVITY_CHANGE".equals(action)) {
            if (intent.getAction().equals("android.net.conn.CONNECTIVITY_CHANGE")) {
                NetworkInfo networkInfo = (NetworkInfo) intent.getParcelableExtra("networkInfo");
                if (networkInfo.getType() == 0) {
                    NetworkInfo.State state = networkInfo.getState();
                    if (state == NetworkInfo.State.CONNECTED) {
                        Log.i(this.f7258e, "open gprs");
                        mo3244d(f7253c);
                        if (f7253c) {
                            f7253c = false;
                            return;
                        } else {
                            f7256q = true;
                            return;
                        }
                    }
                    if (state == NetworkInfo.State.DISCONNECTED) {
                        Log.i(this.f7258e, "close gprs");
                        mo3242c(f7253c);
                        if (f7253c) {
                            f7253c = false;
                            return;
                        } else {
                            f7256q = false;
                            return;
                        }
                    }
                    return;
                }
                return;
            }
            return;
        }
        if ("android.bluetooth.adapter.action.STATE_CHANGED".equals(action) || "android.bluetooth.device.action.ACL_CONNECTED".equals(action) || "android.bluetooth.device.action.ACL_DISCONNECTED".equals(action)) {
            PowerSavingConfig powerSavingConfigMo3238b4 = mo3238b();
            if (!"android.bluetooth.adapter.action.STATE_CHANGED".equals(intent.getAction())) {
                if ("android.bluetooth.device.action.ACL_CONNECTED".equals(intent.getAction())) {
                    Log.i(this.f7258e, "ACTION_ACL_CONNECTED");
                    BlueToothHelper.m2619a(context).f6202a = true;
                    return;
                } else {
                    if ("android.bluetooth.device.action.ACL_DISCONNECTED".equals(intent.getAction())) {
                        Log.i(this.f7258e, "ACTION_ACL_DISCONNECTED");
                        BlueToothHelper.m2619a(context).f6202a = false;
                        return;
                    }
                    return;
                }
            }
            int bluetoothState = ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).getBluetoothState();
            if (bluetoothState == 11) {
                if (mo3237a() || (powerSavingConfigMo3238b4.mBlueToothAutoCloseCondition & 1) == 1) {
                    return;
                }
                BlueToothHelper.m2619a(context).m2627a(powerSavingConfigMo3238b4);
                return;
            }
            if (bluetoothState == 13) {
                BlueToothHelper.m2619a(context).m2626a();
                return;
            }
            if (bluetoothState == 12) {
                mo3246f(f7254d);
                if (f7254d) {
                    f7254d = false;
                    return;
                } else {
                    f7257r = true;
                    return;
                }
            }
            if (bluetoothState == 10) {
                mo3245e(f7254d);
                if (f7254d) {
                    f7254d = false;
                } else {
                    f7257r = false;
                }
            }
        }
    }
}
