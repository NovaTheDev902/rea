package com.tencent.tmsecure.module.powersaving;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1303gc;
import tms.C1304gd;

/* JADX INFO: loaded from: classes.dex */
public final class PowerSavingManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1304gd f6212a;

    /* JADX INFO: renamed from: b */
    private C1303gc f6213b;

    public final synchronized IBatteryInfoHelper getBatteryInfoHelper() {
        IBatteryInfoHelper iBatteryInfoHelperM3356b;
        if (isExpired()) {
            if (this.f6213b == null) {
                this.f6213b = new C1303gc();
            }
            iBatteryInfoHelperM3356b = this.f6213b;
        } else {
            iBatteryInfoHelperM3356b = this.f6212a.m3356b();
        }
        return iBatteryInfoHelperM3356b;
    }

    public final int getBatteryLevel() {
        if (isExpired()) {
            return 100;
        }
        return this.f6212a.m3353a();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6212a = new C1304gd();
        this.f6212a.onCreate(context);
        setImpl(this.f6212a);
    }

    public final void registerPowerSavingEventListener(PowerSavingEventListener powerSavingEventListener) {
        if (isExpired()) {
            return;
        }
        this.f6212a.m3355a(powerSavingEventListener);
    }

    public final void setPowerSavingConfig(PowerSavingConfig powerSavingConfig, boolean z) {
        if (isExpired()) {
            return;
        }
        this.f6212a.m3354a(powerSavingConfig, z);
    }

    public final void unRegisterPowerSavingEventListener(PowerSavingEventListener powerSavingEventListener) {
        if (isExpired()) {
            return;
        }
        this.f6212a.m3357b(powerSavingEventListener);
    }
}
