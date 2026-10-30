package com.tencent.tmsecure.module.powersaving;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.IntentFilter;
import android.os.Handler;
import java.util.ArrayList;
import tms.C1300fz;
import tms.RunnableC1302ga;

/* JADX INFO: loaded from: classes.dex */
public class BlueToothHelper {

    /* JADX INFO: renamed from: g */
    private static final int f6197g = 300000;

    /* JADX INFO: renamed from: h */
    private static final int f6198h = 1;

    /* JADX INFO: renamed from: i */
    private static final int f6199i = 2;

    /* JADX INFO: renamed from: j */
    private static final int f6200j = 3;

    /* JADX INFO: renamed from: n */
    private static BlueToothHelper f6201n;

    /* JADX INFO: renamed from: e */
    private Context f6206e;

    /* JADX INFO: renamed from: f */
    private BlueToothObserver f6207f;

    /* JADX INFO: renamed from: k */
    private Handler f6208k;

    /* JADX INFO: renamed from: l */
    private Runnable f6209l;

    /* JADX INFO: renamed from: m */
    private boolean f6210m;

    /* JADX INFO: renamed from: b */
    private String f6203b = "BlueToothHelper";

    /* JADX INFO: renamed from: a */
    public boolean f6202a = false;

    /* JADX INFO: renamed from: o */
    private BroadcastReceiver f6211o = new C1300fz(this);

    /* JADX INFO: renamed from: c */
    private BluetoothAdapter f6204c = BluetoothAdapter.getDefaultAdapter();

    /* JADX INFO: renamed from: d */
    private ArrayList<BluetoothDevice> f6205d = new ArrayList<>();

    public static class BlueToothObserver {
        public void ScanFinish(ArrayList<BluetoothDevice> arrayList) {
        }
    }

    private BlueToothHelper(Context context) {
        this.f6206e = context;
    }

    /* JADX INFO: renamed from: a */
    public static synchronized BlueToothHelper m2619a(Context context) {
        if (f6201n == null) {
            f6201n = new BlueToothHelper(context);
        }
        return f6201n;
    }

    /* JADX INFO: renamed from: a */
    public int m2625a(BlueToothObserver blueToothObserver) {
        if (this.f6204c == null || !this.f6204c.isEnabled()) {
            return 1;
        }
        if (this.f6204c.isDiscovering()) {
            return 2;
        }
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("android.bluetooth.device.action.FOUND");
        intentFilter.addAction("android.bluetooth.adapter.action.DISCOVERY_FINISHED");
        intentFilter.addAction("android.bluetooth.adapter.action.DISCOVERY_STARTED");
        intentFilter.addAction("android.bluetooth.adapter.action.STATE_CHANGED");
        this.f6206e.registerReceiver(this.f6211o, intentFilter);
        this.f6204c.startDiscovery();
        this.f6207f = blueToothObserver;
        return 3;
    }

    /* JADX INFO: renamed from: a */
    public void m2626a() {
        if (this.f6208k != null && this.f6209l != null) {
            this.f6208k.removeCallbacks(this.f6209l);
        }
        this.f6208k = null;
        this.f6209l = null;
        this.f6210m = false;
    }

    /* JADX INFO: renamed from: a */
    public void m2627a(PowerSavingConfig powerSavingConfig) {
        if (this.f6210m) {
            return;
        }
        this.f6208k = new Handler();
        this.f6209l = new RunnableC1302ga(this, powerSavingConfig);
        this.f6208k.postDelayed(this.f6209l, 300000L);
        this.f6210m = true;
    }
}
