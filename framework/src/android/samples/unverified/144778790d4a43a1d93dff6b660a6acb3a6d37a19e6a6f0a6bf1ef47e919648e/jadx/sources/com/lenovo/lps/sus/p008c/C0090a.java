package com.lenovo.lps.sus.p008c;

import android.content.Context;
import android.content.SharedPreferences;
import com.lenovo.lps.reaper.sdk.AnalyticsTracker;

/* JADX INFO: renamed from: com.lenovo.lps.sus.c.a */
/* JADX INFO: loaded from: classes.dex */
public final class C0090a {

    /* JADX INFO: renamed from: a */
    public static final String f1264a = "SUS_REAPER";

    /* JADX INFO: renamed from: b */
    public static final String f1265b = "SUS_REAPER_ENABLEFLAG";

    /* JADX INFO: renamed from: c */
    private static boolean f1266c = false;

    /* JADX INFO: renamed from: d */
    private static boolean f1267d = false;

    /* JADX INFO: renamed from: e */
    private static boolean f1268e = false;

    /* JADX INFO: renamed from: a */
    public static void m308a() {
        if (!f1267d || f1266c) {
            return;
        }
        if (!f1268e) {
            AnalyticsTracker.getInstance().setParam(5, "SPECIAL_TOKEN", "BIYZAZFWBJ6I");
        }
        AnalyticsTracker.getInstance().trackEvent("SUSInfo", "AbortUpdateByUserSetting", C0092c.f1340c, 0);
    }

    /* JADX INFO: renamed from: a */
    public static void m309a(Context context, String str, String str2, String str3) {
        if (context == null) {
            return;
        }
        f1266c = m312a(context);
        if (f1266c) {
            f1267d = false;
        } else {
            f1267d = m314b(context);
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m310a(Context context, boolean z) {
        if (context == null) {
            return;
        }
        SharedPreferences.Editor editorEdit = context.getSharedPreferences(f1264a, 0).edit();
        editorEdit.putBoolean(f1265b, z);
        editorEdit.commit();
    }

    /* JADX INFO: renamed from: a */
    public static void m311a(String str) {
        if (!f1267d || f1266c) {
            return;
        }
        Throwable th = new Throwable(str);
        if (!f1268e) {
            AnalyticsTracker.getInstance().setParam(5, "SPECIAL_TOKEN", "BIYZAZFWBJ6I");
        }
        AnalyticsTracker.getInstance().trackThrowable(th);
    }

    /* JADX INFO: renamed from: a */
    public static boolean m312a(Context context) {
        if (context == null) {
            return false;
        }
        return context.getSharedPreferences(f1264a, 0).getBoolean(f1265b, false);
    }

    /* JADX INFO: renamed from: b */
    public static void m313b() {
        if (!f1267d || f1266c) {
            return;
        }
        if (!f1268e) {
            AnalyticsTracker.getInstance().setParam(5, "SPECIAL_TOKEN", "BIYZAZFWBJ6I");
        }
        AnalyticsTracker.getInstance().trackEvent("SUSInterface", "menu_start", C0092c.f1340c, 0);
    }

    /* JADX INFO: renamed from: b */
    private static boolean m314b(Context context) {
        boolean zIsTrackerInitialized = false;
        f1268e = false;
        boolean zM356d = C0092c.m356d(context);
        C0098i.m409a(C0092c.f1339b, "isHasAnalyticSDK=" + zM356d);
        try {
            Class<?> cls = Class.forName("com.lenovo.lps.reaper.sdk.AnalyticsTracker");
            if (cls != null) {
                if (cls.getMethod("isTrackerInitialized", new Class[0]) != null) {
                    zIsTrackerInitialized = AnalyticsTracker.getInstance().isTrackerInitialized();
                    C0098i.m409a(C0092c.f1339b, "Reapersdk init by app, flag=" + zIsTrackerInitialized);
                }
                if (!zIsTrackerInitialized && zM356d) {
                    AnalyticsTracker.getInstance().initialize(context);
                    C0098i.m409a(C0092c.f1339b, "execute AnalyticsTracker.getInstance().initialize()");
                    if (cls.getMethod("isTrackerInitialized", new Class[0]) != null) {
                        zIsTrackerInitialized = AnalyticsTracker.getInstance().isTrackerInitialized();
                        if (zIsTrackerInitialized) {
                            f1268e = true;
                        }
                        C0098i.m409a(C0092c.f1339b, "Reapersdk init by sus, isTrackerInitialized flag=" + zIsTrackerInitialized);
                    }
                }
            }
        } catch (Exception e) {
        }
        return zIsTrackerInitialized;
    }

    /* JADX INFO: renamed from: c */
    public static void m315c() {
        if (!f1267d || f1266c) {
            return;
        }
        if (!f1268e) {
            AnalyticsTracker.getInstance().setParam(5, "SPECIAL_TOKEN", "BIYZAZFWBJ6I");
        }
        AnalyticsTracker.getInstance().trackEvent("SUSQueryResult", C0092c.f1288S, C0092c.f1340c, 0);
    }

    /* JADX INFO: renamed from: d */
    public static void m316d() {
        if (!f1267d || f1266c) {
            return;
        }
        if (!f1268e) {
            AnalyticsTracker.getInstance().setParam(5, "SPECIAL_TOKEN", "BIYZAZFWBJ6I");
        }
        AnalyticsTracker.getInstance().trackEvent("UserAction", "NewVersionPrompt_UserSetting", C0092c.f1340c, 0);
    }

    /* JADX INFO: renamed from: e */
    public static void m317e() {
        if (!f1267d || f1266c) {
            return;
        }
        if (!f1268e) {
            AnalyticsTracker.getInstance().setParam(5, "SPECIAL_TOKEN", "BIYZAZFWBJ6I");
        }
        AnalyticsTracker.getInstance().trackEvent("UserAction", "SelectButton", C0092c.f1340c, 0);
    }

    /* JADX INFO: renamed from: f */
    public static boolean m318f() {
        try {
            Class<?> cls = Class.forName("com.lenovo.lps.reaper.sdk.AnalyticsTracker");
            return (cls == null || cls.getMethod("isTrackerInitialized", new Class[0]) == null) ? false : true;
        } catch (ClassNotFoundException e) {
            return false;
        } catch (IllegalArgumentException e2) {
            return false;
        } catch (NoSuchMethodException e3) {
            return false;
        } catch (SecurityException e4) {
            return false;
        }
    }
}
