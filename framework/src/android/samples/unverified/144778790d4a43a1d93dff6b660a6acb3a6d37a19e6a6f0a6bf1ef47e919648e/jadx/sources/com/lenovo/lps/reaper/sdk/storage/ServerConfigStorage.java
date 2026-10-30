package com.lenovo.lps.reaper.sdk.storage;

import com.lenovo.lps.reaper.sdk.util.Constants;
import com.lenovo.lps.reaper.sdk.util.PlusUtil;
import com.lenovo.lps.reaper.sdk.util.TLog;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class ServerConfigStorage {

    /* JADX INFO: renamed from: a */
    private static HashMap<String, Boolean> f1173a = new HashMap<>();

    /* JADX INFO: renamed from: b */
    private static long f1174b;

    public static synchronized void put(String key, boolean value) {
        if (TLog.isTestMode()) {
            TLog.m240d("ServerConfigStorage", "put ServerConfigStorage: [KEY]" + key + " [VALUE]" + value);
        }
        if (!UpdateConfigStrategy.m234b(key) && !DeviceSendFlag.m228a(key, value) && !DispatchStrategy.m231b(key, value)) {
            CompressStrategy.m226b(key, value);
        }
        f1173a.put(key, Boolean.valueOf(value));
    }

    public static synchronized boolean get(String key, boolean defaultValue) {
        Boolean value = f1173a.get(key);
        if (value != null) {
            defaultValue = value.booleanValue();
        }
        return defaultValue;
    }

    public static void clear() {
        TLog.m244v("ServerConfigStorage", "ServerConfigStorage is Clear");
        f1173a.clear();
        UpdateConfigStrategy.f1184a = 6L;
        DeviceSendFlag.f1179a = true;
        DispatchStrategy.m229a();
        CompressStrategy.m224a();
    }

    public static long getTimestampMills() {
        return f1174b;
    }

    public static void setTimestampMills(long timestamp) {
        TLog.m244v("ServerConfigStorage", "Timestamp is set: " + timestamp);
        f1174b = timestamp;
    }

    public static class UpdateConfigStrategy {

        /* JADX INFO: renamed from: a */
        private static long f1184a = 6;

        public static long getUpdateIntervalHour() {
            return f1184a;
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: b */
        public static boolean m234b(String key) {
            if (key.contains(Constants.ServerConfig.UpdateStrategy.CATEGORY_UPDATE)) {
                try {
                    f1184a = Long.parseLong(key.substring(key.indexOf(Constants.ServerConfig.UpdateStrategy.VALUE_PRE_UPDATE) + Constants.ServerConfig.UpdateStrategy.VALUE_PRE_UPDATE.length()));
                    TLog.m244v("ServerConfigStorage", "UpdateConfigInterval is set to " + f1184a);
                    return true;
                } catch (Exception e) {
                    TLog.m245w("ServerConfigStorage", "UpdateConfigStrategy Update Wrong. " + e.getMessage());
                }
            }
            return false;
        }
    }

    public static class DeviceSendFlag {

        /* JADX INFO: renamed from: a */
        private static boolean f1179a = true;

        /* JADX INFO: renamed from: a */
        static /* synthetic */ boolean m228a(String x0, boolean x1) {
            if (!x0.contains(Constants.ServerConfig.SendFlag.CATEGORY_SENDFLAG)) {
                return false;
            }
            f1179a = x1;
            TLog.m244v("ServerConfigStorage", "SendFlag is set to " + x1);
            return true;
        }

        public static boolean needSend() {
            return f1179a;
        }

        public static void needSend(boolean needSend) {
            f1179a = needSend;
        }
    }

    public static class DispatchStrategy {

        /* JADX INFO: renamed from: a */
        private static int f1180a = 1;

        /* JADX INFO: renamed from: b */
        private static int f1181b = 1;

        /* JADX INFO: renamed from: c */
        private static boolean f1182c = true;

        /* JADX INFO: renamed from: d */
        private static boolean f1183d = true;

        /* JADX INFO: renamed from: a */
        static /* synthetic */ void m229a() {
            f1180a = 1;
            f1181b = 1;
            f1182c = true;
            f1183d = true;
        }

        public static long getThreshold() {
            switch (PlusUtil.NetworkStatus.getNetworkStatus()) {
                case 2:
                    return 1L;
                case 3:
                    return f1181b;
                case 4:
                    return f1180a;
                default:
                    return f1181b;
            }
        }

        public static boolean readyForReport(Constants.DispatchMode dispatchMode) {
            if (PlusUtil.NetworkStatus.isRoaming()) {
                TLog.m240d("ServerConfigStorage", "Now is Roaming");
                return false;
            }
            switch (PlusUtil.NetworkStatus.getNetworkStatus()) {
                case 0:
                    TLog.m240d("ServerConfigStorage", "Now is NOTCONCERN");
                    return true;
                case 1:
                default:
                    return false;
                case 2:
                    return true;
                case 3:
                    if (Constants.DispatchMode.FORCE_DISPATCH.equals(dispatchMode)) {
                        return true;
                    }
                    return f1183d;
                case 4:
                    if (Constants.DispatchMode.FORCE_DISPATCH.equals(dispatchMode)) {
                        return true;
                    }
                    return f1182c;
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX WARN: Code duplicated, block: B:14:0x0097  */
        /* JADX WARN: Unsupported multi-entry loop pattern (BACK_EDGE: B:13:0x007b -> B:14:0x0097). Please report as a decompilation issue!!! */
        /* JADX INFO: renamed from: b */
        public static boolean m231b(String key, boolean value) {
            boolean z = true;
            int index = key.indexOf("Threshold-");
            if (index > 0) {
                try {
                    int eventNumThres = Integer.parseInt(key.substring("Threshold-".length() + index));
                    if (key.contains(Constants.ServerConfig.DispatchStrategy.CATEGORY_DISPATCH_3G4G)) {
                        f1181b = eventNumThres;
                        f1183d = value;
                        TLog.m244v("ServerConfigStorage", "DispatchStrategy 3G4G is set to " + eventNumThres + " [" + value + "]");
                    } else if (key.contains(Constants.ServerConfig.DispatchStrategy.CATEGORY_DISPATCH_2G)) {
                        f1180a = eventNumThres;
                        f1182c = value;
                        TLog.m244v("ServerConfigStorage", "DispatchStrategy 2G is set to " + eventNumThres + " [" + value + "]");
                    } else {
                        z = false;
                    }
                } catch (Exception e) {
                    TLog.m245w("ServerConfigStorage", "DispatchStrategy Update Wrong. " + e.getMessage());
                }
            } else {
                z = false;
            }
            return z;
        }
    }

    public static class CompressStrategy {

        /* JADX INFO: renamed from: a */
        private static int f1175a = 3;

        /* JADX INFO: renamed from: b */
        private static int f1176b = 5;

        /* JADX INFO: renamed from: c */
        private static boolean f1177c = true;

        /* JADX INFO: renamed from: d */
        private static boolean f1178d = true;

        /* JADX INFO: renamed from: a */
        static /* synthetic */ void m224a() {
            f1175a = 3;
            f1176b = 5;
            f1177c = true;
            f1178d = true;
        }

        public static boolean needCompress(int eventNum) {
            switch (PlusUtil.NetworkStatus.getNetworkStatus()) {
                case 3:
                    return f1178d && eventNum >= f1176b;
                case 4:
                    return f1177c && eventNum >= f1175a;
                default:
                    return false;
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX WARN: Code duplicated, block: B:14:0x0097  */
        /* JADX WARN: Unsupported multi-entry loop pattern (BACK_EDGE: B:13:0x007b -> B:14:0x0097). Please report as a decompilation issue!!! */
        /* JADX INFO: renamed from: b */
        public static boolean m226b(String key, boolean value) {
            boolean z = true;
            int index = key.indexOf("Threshold-");
            if (index > 0) {
                try {
                    int eventNumThres = Integer.parseInt(key.substring("Threshold-".length() + index));
                    if (key.contains(Constants.ServerConfig.CompressStrategy.CATEGORY_COMPRESS_3G4G)) {
                        f1176b = eventNumThres;
                        f1178d = value;
                        TLog.m244v("ServerConfigStorage", "CompressStrategy 3G4G is set to " + eventNumThres + " [" + value + "]");
                    } else if (key.contains(Constants.ServerConfig.CompressStrategy.CATEGORY_COMPRESS_2G)) {
                        f1175a = eventNumThres;
                        f1177c = value;
                        TLog.m244v("ServerConfigStorage", "CompressStrategy 2G is set to " + eventNumThres + " [" + value + "]");
                    } else {
                        z = false;
                    }
                } catch (Exception e) {
                    TLog.m245w("ServerConfigStorage", "UpdateCompressStrategy Update Wrong. " + e.getMessage());
                }
            } else {
                z = false;
            }
            return z;
        }
    }
}
