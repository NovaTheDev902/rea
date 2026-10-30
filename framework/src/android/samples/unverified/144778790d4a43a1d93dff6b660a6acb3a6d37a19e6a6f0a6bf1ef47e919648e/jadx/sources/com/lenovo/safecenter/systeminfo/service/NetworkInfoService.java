package com.lenovo.safecenter.systeminfo.service;

import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiManager;
import android.telephony.TelephonyManager;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.lenovo.safecenter.utils.Const;

/* JADX INFO: loaded from: classes.dex */
public class NetworkInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5624a = NetworkInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static NetworkInfoService f5625b = null;

    private NetworkInfoService() {
    }

    public static NetworkInfoService getInstance() {
        if (f5625b == null) {
            synchronized (NetworkInfoService.class) {
                f5625b = new NetworkInfoService();
            }
        }
        return f5625b;
    }

    public String getNetworkType() {
        int type = m2305a().getNetworkType();
        switch (type) {
            case 0:
                String typeString = Const.mContext.getString(C0415R.string.none_know_nettype);
                return typeString;
            case 1:
                return "GPRS";
            case 2:
                return "EDGE";
            case 3:
                return "UMTS";
            case 4:
                return "CDMA";
            case 5:
                return "EVDO_0";
            case 6:
                return "EVDO_A";
            case 7:
                return "1xRTT";
            case 8:
                return "HSDPA";
            case 9:
                return "HSUPA";
            case 10:
                return "HSPA";
            case 11:
                return "IDEN";
            default:
                String typeString2 = Const.mContext.getString(C0415R.string.none_know_nettype);
                return typeString2;
        }
    }

    public String getNetWorkCountryIso() {
        return m2305a().getNetworkCountryIso();
    }

    public String getNetWorkOperator() {
        return m2305a().getNetworkOperator();
    }

    public String getNetWorkOperatorName() {
        int simState = m2305a().getSimState();
        switch (simState) {
            case 0:
                return Const.mContext.getString(C0415R.string.localblack_noName);
            case 1:
                return Const.mContext.getString(C0415R.string.no_sim_insert);
            case 2:
            case 3:
            case 4:
            default:
                return null;
            case 5:
                String deviceIdString = m2305a().getDeviceId();
                if (deviceIdString == null) {
                    return Const.mContext.getString(C0415R.string.no_sim_insert);
                }
                String networkOperatorName = m2305a().getNetworkOperatorName();
                if ("Android".equals(networkOperatorName)) {
                    return Const.mContext.getString(C0415R.string.localblack_noName);
                }
                return networkOperatorName;
        }
    }

    public String getNetworkInfo() {
        StringBuffer buffer = new StringBuffer();
        buffer.append(Const.mContext.getString(C0415R.string.simcard_type)).append(getNetWorkOperatorName()).append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.network_type)).append(getNetworkType());
        return buffer.toString();
    }

    public boolean isOnline() {
        ConnectivityManager manager = (ConnectivityManager) Const.mContext.getSystemService("connectivity");
        NetworkInfo info = manager.getActiveNetworkInfo();
        return info != null && info.isConnected();
    }

    public String getWifiInfo() {
        WifiManager wifiManager = (WifiManager) Const.mContext.getSystemService(SettingUtil.WIFI);
        StringBuffer buffer = new StringBuffer("WLAN状态：");
        if (wifiManager.isWifiEnabled()) {
            buffer.append(Const.mContext.getString(C0415R.string.opend));
        } else {
            buffer.append(Const.mContext.getString(C0415R.string.no_open));
        }
        return buffer.toString();
    }

    public int getPhoneType() {
        return m2305a().getPhoneType();
    }

    public String getConnectTypeName() {
        if (!isOnline()) {
            return "OFFLINE";
        }
        ConnectivityManager manager = (ConnectivityManager) Const.mContext.getSystemService("connectivity");
        NetworkInfo info = manager.getActiveNetworkInfo();
        if (info != null) {
            return info.getTypeName();
        }
        return "OFFLINE";
    }

    /* JADX INFO: renamed from: a */
    private static TelephonyManager m2305a() {
        TelephonyManager manager = (TelephonyManager) Const.mContext.getSystemService("phone");
        return manager;
    }
}
