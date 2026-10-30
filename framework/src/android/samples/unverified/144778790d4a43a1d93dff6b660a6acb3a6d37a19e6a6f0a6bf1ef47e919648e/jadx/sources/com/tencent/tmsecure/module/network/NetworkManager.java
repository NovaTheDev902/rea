package com.tencent.tmsecure.module.network;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1244dt;
import tms.C1246dv;

/* JADX INFO: loaded from: classes.dex */
public final class NetworkManager extends BaseManager {
    public static final int INTERVAL_FOR_BACKGROUND = 0;
    public static final int INTERVAL_FOR_REALTIME = 2;
    public static final int INTERVAL_FOR_UI = 1;

    /* JADX INFO: renamed from: a */
    private C1244dt f6101a;

    /* JADX INFO: renamed from: b */
    private C1246dv f6102b;

    public final boolean addDefaultMobileMonitor(String str, INetworkInfoDao iNetworkInfoDao) {
        if (isExpired()) {
            return false;
        }
        return this.f6101a.m3188a(str, iNetworkInfoDao);
    }

    public final boolean addDefaultWifiMonitor(String str, INetworkInfoDao iNetworkInfoDao) {
        if (isExpired()) {
            return false;
        }
        return this.f6101a.m3193b(str, iNetworkInfoDao);
    }

    public final boolean addMonitor(String str, NetDataEntityFactory netDataEntityFactory, INetworkInfoDao iNetworkInfoDao) {
        if (isExpired()) {
            return false;
        }
        return this.f6101a.m3189a(str, netDataEntityFactory, iNetworkInfoDao);
    }

    public final void clearTrafficInfo(String[] strArr) {
        if (isExpired()) {
            return;
        }
        this.f6101a.m3185a(strArr);
    }

    public final INetworkMonitor findMonitor(String str) {
        if (!isExpired()) {
            return this.f6101a.m3191b(str);
        }
        if (this.f6102b == null) {
            this.f6102b = new C1246dv();
        }
        return this.f6102b;
    }

    public final long getInterval() {
        return this.f6101a.m3190b();
    }

    public final int getIntervalType() {
        return this.f6101a.m3194c();
    }

    public final long getMobileRxBytes(String str) {
        if (isExpired()) {
            return 0L;
        }
        return this.f6101a.m3196d(str);
    }

    public final long getMobileTxBytes(String str) {
        if (isExpired()) {
            return 0L;
        }
        return this.f6101a.m3198e(str);
    }

    public final long getSelfMobileDownloadBytes() {
        if (isExpired()) {
            return 0L;
        }
        return this.f6101a.m3202g();
    }

    public final long getSelfMobileUploadBytes() {
        if (isExpired()) {
            return 0L;
        }
        return this.f6101a.m3204h();
    }

    public final TrafficEntity getTrafficEntity(String str) {
        return isExpired() ? new TrafficEntity() : this.f6101a.m3195c(str);
    }

    public final long getWIFIRxBytes(String str) {
        if (isExpired()) {
            return 0L;
        }
        return this.f6101a.m3200f(str);
    }

    public final long getWIFITxBytes(String str) {
        if (isExpired()) {
            return 0L;
        }
        return this.f6101a.m3203g(str);
    }

    public final boolean isEnable() {
        if (isExpired()) {
            return false;
        }
        return this.f6101a.m3197d();
    }

    public final boolean isSupportTrafficState() {
        if (isExpired()) {
            return false;
        }
        return this.f6101a.m3201f();
    }

    public final void notifyConfigChange() {
        if (isExpired()) {
            return;
        }
        this.f6101a.m3199e();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6101a = new C1244dt();
        this.f6101a.onCreate(context);
        setImpl(this.f6101a);
    }

    public final void refreshTrafficInfo(String[] strArr, boolean z) {
        if (isExpired()) {
            return;
        }
        this.f6101a.m3186a(strArr, z);
    }

    public final boolean removeMonitor(String str) {
        if (isExpired()) {
            return false;
        }
        return this.f6101a.m3187a(str);
    }

    public final void setEnable(boolean z) {
        if (isExpired()) {
            return;
        }
        this.f6101a.m3184a(z);
    }

    public final void setInterval(int i) {
        if (isExpired()) {
            return;
        }
        this.f6101a.m3182a(i);
    }

    public final void updateSelfMobileDownloadBytes(long j) {
        if (isExpired()) {
            return;
        }
        this.f6101a.m3183a(j);
    }

    public final void updateSelfMobileUploadBytes(long j) {
        if (isExpired()) {
            return;
        }
        this.f6101a.m3192b(j);
    }
}
