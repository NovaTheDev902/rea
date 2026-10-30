package com.tencent.tmsecure.common;

import QQPIM.EProduct;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.text.TextUtils;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.io.File;
import java.util.HashMap;
import java.util.Map;
import org.apache.commons.httpclient.cookie.CookiePolicy;
import tms.C1149af;
import tms.C1278f;
import tms.C1313h;
import tms.InterfaceC1326l;

/* JADX INFO: loaded from: classes.dex */
public final class TMSApplication {
    public static final String CON_APOLLO_LIBNAME = "apollo_libname";
    public static final String CON_ARESENGINE_LIBNAME = "aresengine_libname";
    public static final String CON_AUTO_REPORT = "auto_report";
    public static final String CON_BUILD = "build";
    public static final String CON_CHANNEL = "channel";
    public static final String CON_CRYPTOR_LIBNAME = "cryptor_libname";
    public static final String CON_CVERSION = "cversion";
    public static final String CON_HOST_URL = "host_url";
    public static final String CON_HOTFIX = "hotfix";
    public static final String CON_LC = "lc";
    public static final String CON_LOCATION_LIBNAME = "location_libname";
    public static final String CON_PLATFORM = "platform";
    public static final String CON_PLUGIN_DIR = "plugin_dir";
    public static final String CON_PRODUCT = "product";
    public static final String CON_PVERSION = "pversion";
    public static final String CON_SMS_PARSER_LIBNAME = "sms_parser_libname";
    public static final String CON_SOFTVERSION = "softversion";
    public static final String CON_SUB_PLATFORM = "sub_platform";
    public static final String CON_SU_CMD = "su_cmd";
    public static final String CON_VIRUS_SCAN_LIBNAME = "virus_scan_libname";
    public static final String SDK_VERSION = "1.1.2";

    /* JADX INFO: renamed from: a */
    private static Map<String, String> f6041a = new HashMap();

    /* JADX INFO: renamed from: b */
    private static Context f6042b;

    /* JADX INFO: renamed from: c */
    private static Class<? extends TMSService> f6043c;

    static {
        f6041a.put(CON_VIRUS_SCAN_LIBNAME, "ams-1.1.0");
        f6041a.put(CON_CRYPTOR_LIBNAME, "cryptor-1.0.0");
        f6041a.put(CON_ARESENGINE_LIBNAME, "smschecker-1.0.1");
        f6041a.put(CON_LOCATION_LIBNAME, "location-1.0.0");
        f6041a.put(CON_APOLLO_LIBNAME, "apollo-1.1.2");
        f6041a.put(CON_SMS_PARSER_LIBNAME, "smsparser-1.0.0");
        f6041a.put(CON_HOST_URL, "http://pmir.3g.qq.com");
        f6041a.put(CON_SU_CMD, "su");
        f6041a.put(CON_SOFTVERSION, SDK_VERSION);
        f6041a.put(CON_BUILD, "100");
        f6041a.put(CON_LC, "1494D3A83428CD09");
        f6041a.put(CON_CHANNEL, "null");
        f6041a.put(CON_PLATFORM, CookiePolicy.DEFAULT);
        f6041a.put(CON_PVERSION, DatabaseTables.SYSTEM_MARK);
        f6041a.put(CON_CVERSION, "0");
        f6041a.put(CON_HOTFIX, "0");
        f6041a.put(CON_AUTO_REPORT, "true");
        f6041a.put(CON_PLUGIN_DIR, "/sdcard/qqpimsecure_plugins");
        f6041a.put(CON_SUB_PLATFORM, String.valueOf(201));
        f6041a.put(CON_PRODUCT, String.valueOf(13));
    }

    private static boolean checkLisence() {
        return C1278f.m3286a().m3298f();
    }

    public static Context getApplicaionContext() {
        return f6042b.getApplicationContext();
    }

    public static int getIntFromEnvMap(String str) {
        int iIntValue;
        synchronized (TMSApplication.class) {
            String str2 = f6041a.get(str);
            iIntValue = !TextUtils.isEmpty(str2) ? Integer.valueOf(str2).intValue() : 0;
        }
        return iIntValue;
    }

    public static Class<? extends Service> getSecureServiceClass() {
        return f6043c;
    }

    public static String getStrFromEnvMap(String str) {
        String str2;
        synchronized (TMSApplication.class) {
            str2 = f6041a.get(str);
            if (str.equals(CON_SOFTVERSION) && (str2 == null || str2.contains("0.0.0"))) {
                Context applicaionContext = getApplicaionContext();
                try {
                    str2 = applicaionContext.getPackageManager().getPackageInfo(applicaionContext.getPackageName(), 0).versionName;
                } catch (PackageManager.NameNotFoundException e) {
                    e.printStackTrace();
                } catch (Exception e2) {
                    e2.printStackTrace();
                }
            }
        }
        return str2;
    }

    public static <T extends TMSService> void init(Context context, Class<T> cls) {
        init(context, cls, null, null, null);
    }

    public static <T extends TMSService> void init(Context context, Class<T> cls, ITMSApplicaionConfig iTMSApplicaionConfig) {
        init(context, cls, iTMSApplicaionConfig, null, null);
    }

    public static <T extends TMSService> void init(Context context, Class<T> cls, ITMSApplicaionConfig iTMSApplicaionConfig, Runnable runnable) {
        init(context, cls, iTMSApplicaionConfig, null, runnable);
    }

    /* JADX WARN: Multi-variable type inference failed */
    public static <T extends TMSService> void init(Context context, Class<T> cls, ITMSApplicaionConfig iTMSApplicaionConfig, InterfaceC1326l interfaceC1326l, Runnable runnable) {
        f6042b = context.getApplicationContext();
        if (runnable != null) {
            runnable.run();
        }
        f6043c = cls;
        synchronized (TMSApplication.class) {
            String strM3295c = C1278f.m3286a().m3295c();
            Map<String, String> map = f6041a;
            if (strM3295c == null) {
                strM3295c = "null";
            }
            map.put(CON_CHANNEL, strM3295c);
            f6041a.put(CON_PRODUCT, String.valueOf(EProduct.convert(C1278f.m3286a().m3296d()).value()));
            if (iTMSApplicaionConfig != null) {
                f6041a = iTMSApplicaionConfig.config(new HashMap(f6041a));
            }
        }
        if (cls != 0) {
            f6043c = cls;
            f6042b.startService(new Intent(f6042b, f6043c));
        }
        if (interfaceC1326l != null) {
            ScriptHelper.setProvider(interfaceC1326l);
        }
        if (getStrFromEnvMap(CON_AUTO_REPORT).equals("true")) {
            reportChannelInfo();
        }
        saveFirstStartupTime();
    }

    public static <T extends TMSService> void init(Context context, Class<T> cls, InterfaceC1326l interfaceC1326l) {
        init(context, cls, null, interfaceC1326l, null);
    }

    public static void reportChannelInfo() {
        C1313h.m3446a();
    }

    private static void saveFirstStartupTime() {
        C1149af c1149af = new C1149af("tms");
        if (c1149af.m2882a("first_startup_time", -1L) == -1) {
            try {
                c1149af.m2882a("first_startup_time", new File(getApplicaionContext().getPackageManager().getApplicationInfo(getApplicaionContext().getPackageName(), 0).sourceDir).lastModified());
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    public static void setIntToEnvMap(String str, int i) {
        synchronized (TMSApplication.class) {
            f6041a.put(str, String.valueOf(i));
        }
    }

    public static void setStrToEnvMap(String str, String str2) {
        synchronized (TMSApplication.class) {
            f6041a.put(str, str2);
        }
    }
}
