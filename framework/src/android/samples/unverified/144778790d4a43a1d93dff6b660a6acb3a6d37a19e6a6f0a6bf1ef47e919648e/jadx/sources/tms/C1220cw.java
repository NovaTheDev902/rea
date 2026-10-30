package tms;

import android.content.Context;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.netsetting.NetSettingManager;
import com.tencent.tmsecure.module.network.TrafficEntity;
import com.tencent.tmsecure.module.tools.PackageChangedManager;

/* JADX INFO: renamed from: tms.cw */
/* JADX INFO: loaded from: classes.dex */
final class C1220cw {

    /* JADX INFO: renamed from: a */
    private Context f7039a = TMSApplication.getApplicaionContext();

    /* JADX INFO: renamed from: b */
    private SharedPreferences f7040b = this.f7039a.getSharedPreferences("traffic_xml", 0);

    /* JADX INFO: renamed from: c */
    private SharedPreferences.Editor f7041c = this.f7040b.edit();

    /* JADX INFO: renamed from: d */
    private C1229de f7042d = new C1229de();

    public C1220cw() {
        ((PackageChangedManager) ManagerCreator.getManager(PackageChangedManager.class)).addListener(new C1221cx(this));
    }

    /* JADX INFO: renamed from: f */
    private int m3077f(String str) {
        ApplicationInfo applicationInfo;
        try {
            applicationInfo = this.f7039a.getPackageManager().getApplicationInfo(str, 0);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            applicationInfo = null;
        }
        if (applicationInfo != null) {
            return applicationInfo.uid;
        }
        return -1;
    }

    /* JADX INFO: renamed from: a */
    public final TrafficEntity m3078a(String str) {
        int iM3077f = m3077f(str);
        String string = this.f7040b.getString(str, null);
        if (iM3077f == -1 || string == null || "EMPTY".equals(string)) {
            return null;
        }
        return TrafficEntity.fromString(string);
    }

    /* JADX INFO: renamed from: a */
    public final void m3079a(String[] strArr) {
        for (String str : strArr) {
            int iM3077f = m3077f(str);
            TrafficEntity trafficEntityM3078a = m3078a(str);
            if (iM3077f == -1 || trafficEntityM3078a == null) {
                this.f7041c.putString(str, "EMPTY");
            } else {
                trafficEntityM3078a.mLastUpValue = this.f7042d.m3105b(iM3077f);
                trafficEntityM3078a.mLastDownValue = this.f7042d.m3103a(iM3077f);
                trafficEntityM3078a.mMobileDownValue = 0L;
                trafficEntityM3078a.mMobileUpValue = 0L;
                trafficEntityM3078a.mWIFIDownValue = 0L;
                trafficEntityM3078a.mWIFIUpValue = 0L;
                this.f7041c.putString(str, TrafficEntity.toString(trafficEntityM3078a));
            }
        }
        this.f7041c.commit();
    }

    /* JADX INFO: renamed from: a */
    public final void m3080a(String[] strArr, boolean z) {
        boolean z2;
        TrafficEntity trafficEntity;
        String str = ((NetSettingManager) ManagerCreator.getManager(NetSettingManager.class)).isWifiActive() ? SettingUtil.WIFI : "mobile";
        String string = this.f7040b.getString("last_connection_type", null);
        if (string == null) {
            string = str;
        } else if (str.equals(string) && !z) {
            return;
        }
        for (String str2 : strArr) {
            TrafficEntity trafficEntityM3078a = m3078a(str2);
            int iM3077f = m3077f(str2);
            if (trafficEntityM3078a != null || iM3077f == -1) {
                z2 = false;
                trafficEntity = trafficEntityM3078a;
            } else {
                TrafficEntity trafficEntity2 = new TrafficEntity();
                trafficEntity2.mPkg = str2;
                z2 = true;
                trafficEntity = trafficEntity2;
            }
            if (trafficEntity != null) {
                String string2 = string == null ? this.f7040b.getString("last_connection_type", null) : string;
                long jM3105b = this.f7042d.m3105b(iM3077f);
                long jM3103a = this.f7042d.m3103a(iM3077f);
                if (z2) {
                    trafficEntity.mLastDownValue = jM3103a;
                    trafficEntity.mLastUpValue = jM3105b;
                }
                if (jM3105b == -1 && (trafficEntity.mMobileUpValue > 0 || trafficEntity.mWIFIUpValue > 0)) {
                    jM3105b = 0;
                }
                if (jM3103a == -1 && (trafficEntity.mMobileDownValue > 0 || trafficEntity.mWIFIDownValue > 0)) {
                    jM3103a = 0;
                }
                long j = jM3105b - trafficEntity.mLastUpValue;
                long j2 = jM3103a - trafficEntity.mLastDownValue;
                if (j < 0) {
                    j = jM3105b;
                }
                if (j2 < 0) {
                    j2 = jM3105b;
                }
                if (jM3105b == -1 || jM3103a == -1) {
                    trafficEntity.mMobileDownValue = 0L;
                    trafficEntity.mMobileUpValue = 0L;
                    trafficEntity.mWIFIDownValue = 0L;
                    trafficEntity.mWIFIUpValue = 0L;
                } else if (string2.equals("mobile")) {
                    trafficEntity.mMobileDownValue = j2 + trafficEntity.mMobileDownValue;
                    trafficEntity.mMobileUpValue += j;
                } else if (string2.equals(SettingUtil.WIFI)) {
                    trafficEntity.mWIFIDownValue = j2 + trafficEntity.mWIFIDownValue;
                    trafficEntity.mWIFIUpValue += j;
                }
                trafficEntity.mLastUpValue = jM3105b;
                trafficEntity.mLastDownValue = jM3103a;
                this.f7041c.putString(str2, TrafficEntity.toString(trafficEntity));
            }
        }
        this.f7041c.putString("last_connection_type", str);
        this.f7041c.commit();
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3081a() {
        return this.f7042d.m3104a();
    }

    /* JADX INFO: renamed from: b */
    public final long m3082b(String str) {
        TrafficEntity trafficEntityM3078a = m3078a(str);
        if (trafficEntityM3078a != null) {
            return trafficEntityM3078a.mMobileDownValue;
        }
        return -1L;
    }

    /* JADX INFO: renamed from: c */
    public final long m3083c(String str) {
        TrafficEntity trafficEntityM3078a = m3078a(str);
        if (trafficEntityM3078a != null) {
            return trafficEntityM3078a.mMobileUpValue;
        }
        return -1L;
    }

    /* JADX INFO: renamed from: d */
    public final long m3084d(String str) {
        TrafficEntity trafficEntityM3078a = m3078a(str);
        if (trafficEntityM3078a != null) {
            return trafficEntityM3078a.mWIFIDownValue;
        }
        return -1L;
    }

    /* JADX INFO: renamed from: e */
    public final long m3085e(String str) {
        TrafficEntity trafficEntityM3078a = m3078a(str);
        if (trafficEntityM3078a != null) {
            return trafficEntityM3078a.mWIFIUpValue;
        }
        return -1L;
    }
}
