package com.lenovo.lps.reaper.sdk.util;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.telephony.TelephonyManager;
import com.lenovo.lps.reaper.sdk.sdac.DeviceDataImpl;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import ledroid.root.LedroidServiceLauncher;

/* JADX INFO: loaded from: classes.dex */
public class PlusUtil {

    public static class NetworkStatus {

        /* JADX INFO: renamed from: a */
        private static int f1196a;

        /* JADX INFO: renamed from: b */
        private static boolean f1197b = false;

        public static int getNetworkStatus() {
            return f1196a;
        }

        public static boolean isRoaming() {
            return f1197b;
        }

        public static void setNetworkStatus(Context context) {
            TelephonyManager telephonyManager = (TelephonyManager) context.getSystemService("phone");
            f1197b = telephonyManager.isNetworkRoaming();
            ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService("connectivity");
            NetworkInfo networkInfo = connectivityManager.getActiveNetworkInfo();
            if (networkInfo == null || !networkInfo.isAvailable()) {
                f1196a = 1;
                return;
            }
            int netType = networkInfo.getType();
            int netSubtype = networkInfo.getSubtype();
            if (netType == 1) {
                f1196a = 2;
                return;
            }
            if (netType == 0) {
                if (networkInfo.isConnected()) {
                    if (netSubtype != 1 && netSubtype != 2 && netSubtype != 4) {
                        f1196a = 3;
                        return;
                    } else {
                        f1196a = 4;
                        return;
                    }
                }
                return;
            }
            f1196a = 0;
        }
    }

    public static class DeviceIdentify {

        /* JADX INFO: renamed from: a */
        private static String f1192a = "000000000000";

        /* JADX INFO: renamed from: b */
        private static String f1193b = "mac";

        /* JADX INFO: renamed from: c */
        private static Context f1194c;

        /* JADX INFO: renamed from: d */
        private static BroadcastReceiver f1195d;

        public static void initialDeviceIdentify(Context context) {
            String lowerCase;
            boolean z = true;
            f1194c = context;
            String imei = new DeviceDataImpl().getIMEI(context, 1);
            if (imei != null && imei.length() > 0 && !"00000000".equals(imei)) {
                m237a(imei.toUpperCase(), "imei");
                return;
            }
            String lowerCase2 = Build.MANUFACTURER.toLowerCase();
            if ((lowerCase2 == null || !lowerCase2.contains(LedroidServiceLauncher.SERVICE_NAME)) && ((lowerCase = Build.MODEL.toLowerCase()) == null || !lowerCase.contains(LedroidServiceLauncher.SERVICE_NAME))) {
                z = false;
            }
            if (z) {
                String sn = Build.VERSION.SDK_INT >= 9 ? Build.SERIAL : null;
                TLog.m244v("SN: ", sn);
                if (sn != null && sn.length() > 0 && !sn.toLowerCase().equals("unknown")) {
                    m237a(sn.toUpperCase(), "sn");
                    return;
                }
            }
            IntentFilter intentFilter = new IntentFilter("android.net.wifi.WIFI_STATE_CHANGED");
            if (m239b() || f1195d != null) {
                return;
            }
            f1195d = new BroadcastReceiver() { // from class: com.lenovo.lps.reaper.sdk.util.PlusUtil.DeviceIdentify.1
                @Override // android.content.BroadcastReceiver
                public final void onReceive(Context context2, Intent intent) {
                    if (3 == intent.getIntExtra("wifi_state", -1)) {
                        DeviceIdentify.m239b();
                        context2.unregisterReceiver(this);
                    }
                }
            };
            f1194c.registerReceiver(f1195d, intentFilter);
        }

        public static void setOffWifiListener() {
            if (f1195d != null) {
                try {
                    f1194c.unregisterReceiver(f1195d);
                } catch (Exception e) {
                    TLog.m240d(Constants.SharedPreference.PLUSUTIL, e.getMessage());
                }
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: b */
        public static boolean m239b() {
            SharedPreferences sharedPreferences = f1194c.getSharedPreferences(Constants.SharedPreference.PLUSUTIL, 0);
            if (sharedPreferences.contains("mac")) {
                m237a(sharedPreferences.getString("mac", f1192a), "mac");
                return true;
            }
            WifiManager wifi = (WifiManager) f1194c.getSystemService(SettingUtil.WIFI);
            WifiInfo info = wifi.getConnectionInfo();
            String macAddress = info.getMacAddress();
            if (macAddress == null) {
                return false;
            }
            TLog.m244v("MAC: ", macAddress);
            sharedPreferences.edit().putString("mac", macAddress.replace(C0092c.f1283N, "").toUpperCase()).commit();
            m237a(sharedPreferences.getString("mac", f1192a), "mac");
            return true;
        }

        public static String getDeviceID() {
            return f1192a;
        }

        public static String getDeviceType() {
            return f1193b;
        }

        /* JADX INFO: renamed from: a */
        private static void m237a(String deviceId, String deviceIdType) {
            f1192a = AnalyticsTrackerUtils.encode(deviceId);
            f1193b = deviceIdType;
            TLog.m243i(Constants.SharedPreference.PLUSUTIL, "DeviceType&Id is Set to: " + getDeviceType() + getDeviceID());
        }
    }
}
