package com.tencent.tmsecure.utils;

import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Looper;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import com.tencent.tmsecure.common.TMSApplication;
import tms.HandlerC1320hg;

/* JADX INFO: loaded from: classes.dex */
public class WifiUtil {
    public static final String TEST_URL = "http://www.baidu.com/";

    /* JADX INFO: renamed from: a */
    private static final String f6299a = ".baidu.";

    /* JADX INFO: renamed from: b */
    private static final String f6300b = "百度";
    public static String sRedirectLocation;

    public interface IWifiApproveCheckCallBack {
        void onWifiApproveCheckFinished(boolean z, boolean z2);
    }

    public static int calculateSignalLevel(int i) {
        if (isWifiNetwork()) {
            return WifiManager.calculateSignalLevel(((WifiManager) TMSApplication.getApplicaionContext().getSystemService(SettingUtil.WIFI)).getConnectionInfo().getRssi(), i);
        }
        return -1;
    }

    public static String getSSID() {
        WifiInfo connectionInfo;
        WifiManager wifiManager = (WifiManager) TMSApplication.getApplicaionContext().getSystemService(SettingUtil.WIFI);
        return (wifiManager == null || (connectionInfo = wifiManager.getConnectionInfo()) == null) ? "" : connectionInfo.getSSID();
    }

    public static boolean isWifiNetwork() {
        NetworkInfo activeNetworkInfo = ((ConnectivityManager) TMSApplication.getApplicaionContext().getSystemService("connectivity")).getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.getType() == 1;
    }

    public static void needWifiApprove(IWifiApproveCheckCallBack iWifiApproveCheckCallBack) {
        new HandlerC1320hg(Looper.getMainLooper(), iWifiApproveCheckCallBack).sendEmptyMessage(0);
    }
}
