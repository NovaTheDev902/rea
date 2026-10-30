package com.tencent.tmsecure.module.phoneservice;

import android.content.BroadcastReceiver;
import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1287fi;

/* JADX INFO: loaded from: classes.dex */
public final class IpDialManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1287fi f6172a;

    public final void doIpCall(String str, BroadcastReceiver broadcastReceiver) {
        if (isExpired()) {
            return;
        }
        this.f6172a.m3318a(str, broadcastReceiver);
    }

    public final String getDialPhoneNumber(String str) {
        return isExpired() ? str : this.f6172a.m3316a(str);
    }

    public final IpDialManagerSetting getIpDialSetting() {
        return isExpired() ? new IpDialManagerSetting() : this.f6172a.m3315a();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6172a = new C1287fi();
        this.f6172a.onCreate(context);
        setImpl(this.f6172a);
    }

    public final void setIpDialSetting(IpDialManagerSetting ipDialManagerSetting) {
        if (isExpired()) {
            return;
        }
        this.f6172a.m3317a(ipDialManagerSetting);
    }
}
