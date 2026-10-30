package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import com.lenovo.lps.sus.p008c.C0092c;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.phoneservice.IpDialHeaders;
import com.tencent.tmsecure.module.phoneservice.IpDialManagerSetting;
import com.tencent.tmsecure.module.phoneservice.IpDialPhoneNumber;
import com.tencent.tmsecure.module.phoneservice.IpDialProvinceCity;
import com.tencent.tmsecure.module.phoneservice.LocationManager;
import com.tencent.tmsecure.utils.Log;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/* JADX INFO: renamed from: tms.fi */
/* JADX INFO: loaded from: classes.dex */
public final class C1287fi extends BaseManager {

    /* JADX INFO: renamed from: a */
    C1149af f7325a;

    /* JADX INFO: renamed from: b */
    IpDialManagerSetting f7326b;

    /* JADX INFO: renamed from: c */
    LocationManager f7327c;

    /* JADX INFO: renamed from: b */
    private IpDialManagerSetting m3312b() {
        IpDialManagerSetting ipDialManagerSetting = new IpDialManagerSetting();
        String strM2883a = this.f7325a.m2883a("ip_dial_setting", (String) null);
        if (strM2883a != null) {
            try {
                ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(C1332r.m3551a(strM2883a));
                ObjectInputStream objectInputStream = new ObjectInputStream(byteArrayInputStream);
                ipDialManagerSetting.copyFrom((IpDialManagerSetting) objectInputStream.readObject());
                objectInputStream.close();
                byteArrayInputStream.close();
            } catch (Exception e) {
                Log.m2636i("IpDialManagerImpl", e.getMessage());
            }
        }
        m3313b("call [getIpDialSettingFromDB]");
        return ipDialManagerSetting;
    }

    /* JADX INFO: renamed from: b */
    private void m3313b(String str) {
        Log.m2636i("IpDialManagerImpl", str);
        Log.m2636i("IpDialManagerImpl", "SETTING Dial Mode: " + this.f7326b.getIpDialMode());
        Log.m2636i("IpDialManagerImpl", "SETTING Ip Head: " + this.f7326b.getIpHeader());
        Log.m2636i("IpDialManagerImpl", "SETTING Local Phone:" + this.f7326b.getLocalPhoneLocation().getProvince() + this.f7326b.getLocalPhoneLocation().getCity());
        Log.m2636i("IpDialManagerImpl", "SETTING Excluded Area: " + this.f7326b.getExcludedAreaList().listToString());
        Log.m2636i("IpDialManagerImpl", "SETTING Excluded Phone: " + this.f7326b.getExcludedPhoneNumberList().listToString());
    }

    /* JADX INFO: renamed from: c */
    private String m3314c(String str) {
        String ipHeader = this.f7326b.getIpHeader();
        return (str == null || ipHeader == null || str.startsWith(ipHeader)) ? str : ipHeader + str;
    }

    /* JADX INFO: renamed from: a */
    public final IpDialManagerSetting m3315a() {
        return new IpDialManagerSetting(this.f7326b);
    }

    /* JADX INFO: renamed from: a */
    public final String m3316a(String str) {
        boolean z;
        if (str != null && str.length() > 5) {
            int length = this.f7326b.f6175b != null ? this.f7326b.f6175b.length() : 5;
            String strSubstring = str.substring(0, length);
            if (IpDialHeaders.IP_HEADER_17911.equals(strSubstring) || IpDialHeaders.IP_HEADER_17951.equals(strSubstring) || IpDialHeaders.IP_HEADER_10193.equals(strSubstring) || IpDialHeaders.IP_HEADER_17910.equals(strSubstring) || IpDialHeaders.IP_HEADER_12520.equals(strSubstring) || IpDialHeaders.IP_HEADER_12583.equals(strSubstring) || IpDialHeaders.IP_HEADER_96688.equals(strSubstring) || IpDialHeaders.IP_HEADER_17901.equals(strSubstring) || IpDialHeaders.IP_HEADER_12593.equals(strSubstring) || IpDialHeaders.IP_HEADER_17909.equals(strSubstring)) {
                z = true;
            } else {
                z = this.f7326b.f6175b != null && this.f7326b.f6175b.equals(strSubstring);
            }
            if (z) {
                Log.m2636i("IpDialManagerImpl", str + "has IP header, remove the header(" + str.substring(0, length) + ")");
                str = str.substring(length);
            } else {
                Log.m2636i("IpDialManagerImpl", str + "don't has IP header, go to next step!");
            }
        }
        StringBuffer stringBuffer = new StringBuffer();
        StringBuffer stringBuffer2 = new StringBuffer();
        this.f7327c.getLocation(stringBuffer, stringBuffer2, new StringBuffer(), str);
        String[] strArrSplit = stringBuffer2.toString().split(" ");
        IpDialProvinceCity ipDialProvinceCity = new IpDialProvinceCity();
        if (strArrSplit.length > 1) {
            ipDialProvinceCity.setProvince(strArrSplit[0].trim());
            ipDialProvinceCity.setCity(strArrSplit[1].trim());
        } else {
            ipDialProvinceCity.setProvince(strArrSplit[0].trim());
        }
        boolean zExisted = this.f7326b.getExcludedAreaList().existed(ipDialProvinceCity);
        Log.m2636i("IpDialManagerImpl", str + " is {" + stringBuffer2.toString() + C0092c.f1286Q);
        Log.m2636i("IpDialManagerImpl", str + (zExisted ? " existed" : " not existed") + " in EXCLUDED-AREA list!");
        if (!zExisted) {
            boolean zExisted2 = this.f7326b.getExcludedPhoneNumberList().existed(new IpDialPhoneNumber("", str));
            Log.m2636i("IpDialManagerImpl", str + (zExisted2 ? " existed" : " not existed") + " in EXCLUDED-PHONE list!");
            if (!zExisted2) {
                m3313b("call [getDialPhoneNumber]");
                switch (this.f7326b.getIpDialMode()) {
                    case 0:
                        Log.m2636i("IpDialManagerImpl", "use IP-DIAL-MODE when dialing long-distance calls.");
                        if (str != null && str.length() <= 8) {
                            Log.m2636i("IpDialManagerImpl", str + "'s length less than 8, so do nothing!");
                            return str;
                        }
                        StringBuffer stringBuffer3 = new StringBuffer();
                        StringBuffer stringBuffer4 = new StringBuffer();
                        this.f7327c.getLocation(stringBuffer3, stringBuffer4, new StringBuffer(), str);
                        String strReplace = stringBuffer4.toString().trim().replace(" ", "");
                        String str2 = this.f7326b.getLocalPhoneLocation().getProvince() + this.f7326b.getLocalPhoneLocation().getCity();
                        Log.m2636i("IpDialManagerImpl", "LocationTrime{" + strReplace + "} compare localPhone{" + str2 + C0092c.f1286Q);
                        if ((strReplace.length() > 0 && strReplace.compareTo(str2) == 0) || str.startsWith("400") || str.startsWith("800")) {
                            Log.m2636i("IpDialManagerImpl", "WHEN-DIAL-LONG-DISTANCE-CALL: You are dialing local call");
                            return str;
                        }
                        Log.m2636i("IpDialManagerImpl", "WHEN-DIAL-LONG-DISTANCE-CALL: You are dialing IP call");
                        return m3314c(str);
                    case 1:
                        Log.m2636i("IpDialManagerImpl", "use IP-DIAL-MODE when dialing any calls.");
                        return m3314c(str);
                    case 2:
                        Log.m2636i("IpDialManagerImpl", "not use IP-DIAL-MODE.");
                        return str;
                    default:
                        return str;
                }
            }
        }
        Log.m2636i("IpDialManagerImpl", str + " is in excluded area or phone list.");
        return str;
    }

    /* JADX INFO: renamed from: a */
    public final void m3317a(IpDialManagerSetting ipDialManagerSetting) {
        if (ipDialManagerSetting != null) {
            synchronized (ipDialManagerSetting) {
                this.f7326b.copyFrom(ipDialManagerSetting);
                try {
                    ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
                    ObjectOutputStream objectOutputStream = new ObjectOutputStream(byteArrayOutputStream);
                    objectOutputStream.writeObject(this.f7326b);
                    objectOutputStream.flush();
                    String strM3548a = C1332r.m3548a(byteArrayOutputStream.toByteArray());
                    objectOutputStream.close();
                    this.f7325a.m2888a("ip_dial_setting", strM3548a, true);
                } catch (Exception e) {
                    Log.m2636i("IpDialManagerImpl", e.getMessage());
                }
            }
            m3313b("call [SetIpDialSetting]");
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3318a(String str, BroadcastReceiver broadcastReceiver) {
        if (str != null) {
            broadcastReceiver.setResultData(str);
        }
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7325a = new C1149af("IpDialProperty");
        this.f7327c = (LocationManager) ManagerCreator.getManager(LocationManager.class);
        this.f7326b = new IpDialManagerSetting();
        this.f7326b.copyFrom(m3312b());
    }
}
