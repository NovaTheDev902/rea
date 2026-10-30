package com.tencent.tmsecure.module.netsetting;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1236dl;

/* JADX INFO: loaded from: classes.dex */
public class NetSettingManager extends BaseManager {
    public static final int APN_TYPE_NET = 0;
    public static final int APN_TYPE_NULL = -1;
    public static final int APN_TYPE_WAP = 1;

    /* JADX INFO: renamed from: a */
    private C1236dl f6098a;

    public boolean disableBluetooth() {
        if (isExpired()) {
            return false;
        }
        return this.f6098a.m3160g();
    }

    public boolean enableBluetooth() {
        if (isExpired()) {
            return false;
        }
        return this.f6098a.m3159f();
    }

    public int getAPNType(String str) {
        return this.f6098a.m3149a(str);
    }

    public boolean getApnState() {
        return this.f6098a.m3166m();
    }

    public int getBluetoothState() {
        return this.f6098a.m3161h();
    }

    public String getCurUsedApn() {
        return this.f6098a.m3164k();
    }

    public int getCurUsedApnType() {
        return this.f6098a.m3165l();
    }

    public boolean getMobileDataConnectivity() {
        return this.f6098a.m3162i();
    }

    public int getWifiRssi() {
        return this.f6098a.m3157d();
    }

    public int getWifiState() {
        return this.f6098a.m3155c();
    }

    public boolean isBluetoothEnabled() {
        return this.f6098a.m3158e();
    }

    public boolean isMobileDataConnectivityActive() {
        return this.f6098a.m3163j();
    }

    public boolean isWifiActive() {
        return this.f6098a.m3150a();
    }

    public boolean isWifiEnabled() {
        return this.f6098a.m3153b();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public void onCreate(Context context) {
        this.f6098a = new C1236dl();
        this.f6098a.onCreate(context);
        setImpl(this.f6098a);
    }

    public boolean setApnState(boolean z) {
        if (isExpired()) {
            return false;
        }
        return this.f6098a.m3156c(z);
    }

    public boolean setMobileDataConnectivity(boolean z) {
        if (isExpired()) {
            return false;
        }
        return this.f6098a.m3154b(z);
    }

    public boolean setWifiEnabled(boolean z) {
        if (isExpired()) {
            return false;
        }
        return this.f6098a.m3152a(z);
    }

    public boolean switchTo(int i) {
        if (isExpired()) {
            return false;
        }
        return this.f6098a.m3151a(i);
    }
}
