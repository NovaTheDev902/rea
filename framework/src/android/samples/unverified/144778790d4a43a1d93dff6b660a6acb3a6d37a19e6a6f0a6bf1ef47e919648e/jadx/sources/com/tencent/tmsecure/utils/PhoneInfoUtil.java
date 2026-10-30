package com.tencent.tmsecure.utils;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Environment;
import android.os.StatFs;
import android.telephony.TelephonyManager;
import com.lenovo.safecenter.floatwindow.util.SettingUtil;
import java.io.File;
import tms.C1336v;
import tms.RunnableC1318he;

/* JADX INFO: loaded from: classes.dex */
public final class PhoneInfoUtil {
    public static final int CHINA_MOBILE = 0;
    public static final int CHINA_TELECOM = 2;
    public static final int CHINA_UNICOM = 1;
    public static final int NO_NETOP = -2;
    public static final int OTHER = -1;

    public interface CPUScaleListener {
        void onFinish(float f);
    }

    public static class SizeInfo {

        /* JADX INFO: renamed from: a */
        public long f6278a;

        /* JADX INFO: renamed from: b */
        public long f6279b;

        public int percent() {
            if (this.f6279b > 0) {
                return (int) (((this.f6279b - this.f6278a) / this.f6279b) * 100.0f);
            }
            return 0;
        }
    }

    public static void Call(Context context, String str) {
        Intent intent = new Intent("android.intent.action.DIAL", Uri.parse("tel:" + str));
        intent.setFlags(268435456);
        context.startActivity(intent);
    }

    public static int dip2px(Context context, float f) {
        return (int) ((context.getResources().getDisplayMetrics().density * f) + 0.5f);
    }

    public static String getAndoidId() {
        return "android_id";
    }

    public static synchronized void getCPUscale(CPUScaleListener cPUScaleListener) {
        new Thread(new RunnableC1318he(cPUScaleListener)).start();
    }

    public static String getICCID(Context context) {
        return ((TelephonyManager) context.getSystemService("phone")).getSimSerialNumber();
    }

    public static String getIMEI(Context context) {
        return ((TelephonyManager) context.getSystemService("phone")).getDeviceId();
    }

    public static String getIMSI(Context context) {
        return ((TelephonyManager) context.getSystemService("phone")).getSubscriberId();
    }

    public static String getMAC(Context context) {
        WifiInfo connectionInfo = ((WifiManager) context.getSystemService(SettingUtil.WIFI)).getConnectionInfo();
        if (connectionInfo != null) {
            return connectionInfo.getMacAddress();
        }
        return null;
    }

    public static String getMSISDN(Context context) {
        return ((TelephonyManager) context.getSystemService("phone")).getLine1Number();
    }

    public static String getModelName() {
        return Build.MODEL;
    }

    public static int getNetworkOperatorCode(Context context) {
        TelephonyManager telephonyManager = (TelephonyManager) context.getSystemService("phone");
        if (!hasSIM(context)) {
            return -2;
        }
        String networkOperator = telephonyManager.getNetworkOperator();
        if (networkOperator.equals("46000") || networkOperator.equals("46002") || networkOperator.equals("46007")) {
            return 0;
        }
        if (networkOperator.equals("46001")) {
            return 1;
        }
        if (networkOperator.equals("46003")) {
            return 2;
        }
        return !networkOperator.equals("") ? -1 : -2;
    }

    public static void getPhoneStorageSize(SizeInfo sizeInfo) {
        getSizeInfo(Environment.getDataDirectory(), sizeInfo);
    }

    public static String getProductName() {
        return Build.PRODUCT;
    }

    public static int getScreenHeight(Context context) {
        return context.getResources().getDisplayMetrics().heightPixels;
    }

    public static int getScreenWidth(Context context) {
        return context.getResources().getDisplayMetrics().widthPixels;
    }

    public static void getSizeInfo(File file, SizeInfo sizeInfo) {
        StatFs statFs = new StatFs(file.getPath());
        long blockSize = statFs.getBlockSize();
        sizeInfo.f6278a = ((long) statFs.getAvailableBlocks()) * blockSize;
        sizeInfo.f6279b = ((long) statFs.getBlockCount()) * blockSize;
    }

    public static void getStorageCardSize(SizeInfo sizeInfo) {
        if (C1336v.m3585a()) {
            getSizeInfo(Environment.getExternalStorageDirectory(), sizeInfo);
        } else {
            sizeInfo.f6278a = 0L;
            sizeInfo.f6279b = 0L;
        }
    }

    public static boolean hasSIM(Context context) {
        return ((TelephonyManager) context.getSystemService("phone")).getSimState() != 1;
    }

    public static int px2dip(Context context, float f) {
        return (int) ((f / context.getResources().getDisplayMetrics().density) + 0.5f);
    }
}
