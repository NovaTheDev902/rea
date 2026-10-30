package com.lenovo.safecenter.net.cache;

import android.os.Handler;

/* JADX INFO: loaded from: classes.dex */
public class NetCache {

    /* JADX INFO: renamed from: a */
    private static float f4527a;

    /* JADX INFO: renamed from: b */
    private static float f4528b;

    /* JADX INFO: renamed from: c */
    private static float f4529c;

    /* JADX INFO: renamed from: d */
    private static long f4530d;
    public static int data_id_postion;

    /* JADX INFO: renamed from: e */
    private static String f4531e;

    /* JADX INFO: renamed from: f */
    private static String f4532f;

    /* JADX INFO: renamed from: g */
    private static long f4533g;

    /* JADX INFO: renamed from: h */
    private static Handler f4534h;

    /* JADX INFO: renamed from: i */
    private static long f4535i;
    public static String imsi;
    public static String imsi2;
    public static boolean isProvideMuti;
    public static int lastCorrectCard = 0;
    public static boolean canCorrect = true;
    public static boolean is_net_flush_cast = false;
    public static int traffic_mode = -1;

    public static long getBoot_time() {
        return f4533g;
    }

    public static void setBoot_time(long boot_time) {
        f4533g = boot_time;
    }

    public static String getCached_imsi() {
        return f4531e;
    }

    public static void setCached_imsi(String cached_imsi) {
        f4531e = cached_imsi;
    }

    public static String getCached_imsi2() {
        return f4532f;
    }

    public static void setCached_imsi2(String cached_imsi2) {
        f4532f = cached_imsi2;
    }

    public static long getTraffic_used_progress() {
        return f4530d;
    }

    public static void setTraffic_used_progress(long traffic_used_progress) {
        f4530d = traffic_used_progress;
    }

    public static long getTraffic_used_progress2() {
        return f4535i;
    }

    public static void setTraffic_used_progress2(long traffic_used_progress2) {
        f4535i = traffic_used_progress2;
    }

    public static float getTraffic_view_text_size() {
        return f4529c;
    }

    public static void setTraffic_view_text_size(float traffic_view_text_size) {
        f4529c = traffic_view_text_size;
    }

    public static float getTraffic_view_width() {
        return f4527a;
    }

    public static void setTraffic_view_width(float traffic_view_width) {
        f4527a = traffic_view_width;
    }

    public static float getTraffic_view_height() {
        return f4528b;
    }

    public static void setTraffic_view_height(float traffic_view_height) {
        f4528b = traffic_view_height;
    }

    public static Handler getNetSettingHandler() {
        return f4534h;
    }

    public static void setNetSettingHandler(Handler netSettingHandler) {
        f4534h = netSettingHandler;
    }
}
