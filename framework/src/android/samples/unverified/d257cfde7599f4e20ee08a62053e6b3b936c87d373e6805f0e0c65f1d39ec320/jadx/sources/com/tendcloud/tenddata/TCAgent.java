package com.tendcloud.tenddata;

import android.app.Activity;
import android.content.Context;
import android.location.Location;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.preference.PreferenceManager;
import android.text.TextUtils;
import android.util.Log;
import java.io.Closeable;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.TimeZone;
import java.util.UUID;

/* JADX INFO: loaded from: classes.dex */
public final class TCAgent {

    /* JADX INFO: renamed from: A */
    private static final int f1A = 5000;

    /* JADX INFO: renamed from: B */
    private static final int f2B = 2;

    /* JADX INFO: renamed from: D */
    private static final int f4D = 1;

    /* JADX INFO: renamed from: E */
    private static final int f5E = 2;

    /* JADX INFO: renamed from: F */
    private static final int f6F = 3;

    /* JADX INFO: renamed from: G */
    private static final int f7G = 4;

    /* JADX INFO: renamed from: K */
    private static Context f11K = null;

    /* JADX INFO: renamed from: L */
    private static String f12L = null;

    /* JADX INFO: renamed from: M */
    private static String f13M = null;

    /* JADX INFO: renamed from: N */
    private static long f14N = 0;

    /* JADX INFO: renamed from: a */
    protected static final int f18a = 300000;

    /* JADX INFO: renamed from: b */
    protected static final int f19b = 0;

    /* JADX INFO: renamed from: c */
    protected static final int f20c = 5;

    /* JADX INFO: renamed from: d */
    protected static final int f21d = 6;

    /* JADX INFO: renamed from: e */
    protected static final int f22e = 7;

    /* JADX INFO: renamed from: f */
    static Long[][] f23f = null;

    /* JADX INFO: renamed from: g */
    static boolean f24g = false;

    /* JADX INFO: renamed from: k */
    private static final String f28k = "Android+TD+V1.0.11";

    /* JADX INFO: renamed from: l */
    private static final String f29l = "TDpref.profile.key";

    /* JADX INFO: renamed from: m */
    private static final String f30m = "TDpref.session.key";

    /* JADX INFO: renamed from: n */
    private static final String f31n = "TDpref.lastactivity.key";

    /* JADX INFO: renamed from: o */
    private static final String f32o = "TDpref.start.key";

    /* JADX INFO: renamed from: p */
    private static final String f33p = "TDpref.lastsessionstart.key";

    /* JADX INFO: renamed from: q */
    private static final String f34q = "TDpref.init.key";

    /* JADX INFO: renamed from: r */
    private static final String f35r = "TDpref.actstart.key";

    /* JADX INFO: renamed from: s */
    private static final String f36s = "TDpref.end.key";

    /* JADX INFO: renamed from: t */
    private static final String f37t = "TDpref.sendtime.key";

    /* JADX INFO: renamed from: u */
    private static final String f38u = "TDpref.apps_send_time.key";

    /* JADX INFO: renamed from: v */
    private static final String f39v = "TD_APP_ID";

    /* JADX INFO: renamed from: w */
    private static final String f40w = "TD_CHANNEL_ID";

    /* JADX INFO: renamed from: x */
    private static final long f41x = 30;

    /* JADX INFO: renamed from: y */
    private static final int f42y = 1000;

    /* JADX INFO: renamed from: z */
    private static final int f43z = 0;

    /* JADX INFO: renamed from: C */
    private static long f3C = 0;

    /* JADX INFO: renamed from: j */
    static int f27j = 0;

    /* JADX INFO: renamed from: i */
    static final boolean f26i = false;

    /* JADX INFO: renamed from: H */
    private static volatile boolean f8H = f26i;

    /* JADX INFO: renamed from: h */
    static final String f25h = "TalkingData";

    /* JADX INFO: renamed from: I */
    private static String f9I = f25h;

    /* JADX INFO: renamed from: J */
    private static boolean f10J = f26i;

    /* JADX INFO: renamed from: O */
    private static boolean f15O = f26i;

    /* JADX INFO: renamed from: P */
    private static int f16P = 0;

    /* JADX INFO: renamed from: Q */
    private static boolean f17Q = f26i;

    static {
        m46p();
    }

    /* JADX INFO: renamed from: a */
    private static String m2a(Bundle bundle, String str) {
        Iterator<String> it = bundle.keySet().iterator();
        while (it.hasNext()) {
            if (it.next().equalsIgnoreCase(str)) {
                return String.valueOf(bundle.get(str));
            }
        }
        return "";
    }

    /* JADX INFO: renamed from: a */
    static void m3a() {
        m51u();
        f23f = (Long[][]) null;
    }

    /* JADX INFO: renamed from: a */
    public static void m4a(int i) {
        f27j = i;
    }

    /* JADX INFO: renamed from: a */
    public static void m5a(int i, long j) {
        Message messageObtain = Message.obtain(RunnableC0071c.m61b(), i);
        Handler handlerM61b = RunnableC0071c.m61b();
        handlerM61b.removeMessages(i);
        handlerM61b.sendMessageDelayed(messageObtain, j);
    }

    /* JADX INFO: renamed from: a */
    static void m6a(long j) {
        m11a(f32o, j);
    }

    /* JADX INFO: renamed from: a */
    private static void m7a(Activity activity, String str, int i) {
        C0079k.m71a(new RunnableC0065ad(i, str, activity));
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Code duplicated, block: B:5:0x000f  */
    /* JADX INFO: renamed from: a */
    static void m8a(Message message) {
        boolean z = f26i;
        boolean z2 = true;
        try {
            C0085q.m136a(m25c());
            switch (message.what) {
                case 1:
                    if (f16P >= 2) {
                        m5a(5, 1000L);
                    }
                    f16P = 0;
                    f15O = true;
                    m24b(message);
                    if (SystemClock.elapsedRealtime() - f3C < 1000) {
                        RunnableC0071c.m61b().removeMessages(6);
                        z2 = false;
                    } else if (!m34e()) {
                        m5a(5, 0L);
                        z2 = false;
                    } else {
                        z2 = false;
                    }
                    break;
                case 2:
                    f15O = true;
                    m29c(message);
                    m5a(6, 5000L);
                    f3C = SystemClock.elapsedRealtime();
                    z2 = false;
                    break;
                case 3:
                    m32d(message);
                    z2 = false;
                    break;
                case 4:
                    C0061a c0061a = (C0061a) message.obj;
                    C0085q.m127a(c0061a.f46c, c0061a.f47d);
                    m33e(c0061a.f46c);
                    z2 = false;
                    break;
                case 5:
                    if (!f15O) {
                        f16P++;
                    }
                    z = true;
                    z2 = false;
                    break;
                case 6:
                    z = true;
                    break;
                case 7:
                    z = true;
                    z2 = false;
                    break;
                default:
                    z2 = false;
                    break;
            }
            C0085q.m143b();
            if (z) {
                RunnableC0071c.m59a().m65c();
                if (f16P >= 2 || z2) {
                    return;
                }
                m5a(5, 300000L);
            }
        } catch (Throwable th) {
        }
    }

    /* JADX INFO: renamed from: a */
    static void m9a(Closeable closeable) {
        if (closeable != null) {
            try {
                closeable.close();
            } catch (Throwable th) {
            }
        }
    }

    /* JADX INFO: renamed from: a */
    static void m10a(String str) {
        m12a(f30m, str);
    }

    /* JADX INFO: renamed from: a */
    private static void m11a(String str, long j) {
        PreferenceManager.getDefaultSharedPreferences(f11K).edit().putLong(str, j).commit();
    }

    /* JADX INFO: renamed from: a */
    private static void m12a(String str, String str2) {
        PreferenceManager.getDefaultSharedPreferences(f11K).edit().putString(str, str2).commit();
    }

    /* JADX INFO: renamed from: a */
    private static void m13a(StringBuilder sb, StackTraceElement[] stackTraceElementArr, Throwable th, int i) {
        StackTraceElement[] stackTrace = th.getStackTrace();
        int length = stackTrace.length - 1;
        int length2 = stackTraceElementArr.length - 1;
        while (length >= 0 && length2 >= 0 && stackTrace[length].equals(stackTraceElementArr[length2])) {
            length2--;
            length--;
        }
        int i2 = length <= 50 ? length : 50;
        sb.append("Caused by : " + th + "\r\n");
        for (int i3 = 0; i3 <= i2; i3++) {
            sb.append("\t" + stackTrace[i3] + "\r\n");
        }
        if (i < 5 && th.getCause() != null) {
            m13a(sb, stackTrace, th, i + 1);
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m15a(boolean z) {
        f24g = z;
    }

    /* JADX INFO: renamed from: b */
    private static long m17b(String str, long j) {
        return PreferenceManager.getDefaultSharedPreferences(f11K).getLong(str, j);
    }

    /* JADX INFO: renamed from: b */
    private static String m18b(String str, String str2) {
        return PreferenceManager.getDefaultSharedPreferences(f11K).getString(str, str2);
    }

    /* JADX INFO: renamed from: b */
    static void m19b(long j) {
        m11a(f33p, j);
    }

    /* JADX INFO: renamed from: b */
    static void m20b(String str) {
        m12a(f31n, str);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public static void m21b(Throwable th) {
        if (f8H) {
            C0061a c0061a = new C0061a();
            c0061a.f46c = System.currentTimeMillis();
            c0061a.f47d = m27c(th);
            while (th.getCause() != null) {
                th = th.getCause();
            }
            StackTraceElement[] stackTrace = th.getStackTrace();
            StringBuilder sb = new StringBuilder();
            sb.append(th.getClass().getName()).append(":");
            for (int i = 0; i < 3 && i < stackTrace.length; i++) {
                sb.append(stackTrace[i].toString()).append(":");
            }
            c0061a.f48e = C0089u.m179b(sb.toString());
            RunnableC0071c.m61b().sendMessage(Message.obtain(RunnableC0071c.m61b(), 4, c0061a));
        }
    }

    /* JADX INFO: renamed from: b */
    static void m22b(boolean z) {
        m11a(f29l, z ? 1L : 0L);
    }

    /* JADX INFO: renamed from: b */
    public static boolean m23b() {
        if (System.currentTimeMillis() / 86400000 != m17b(f38u, 0L)) {
            return true;
        }
        return f26i;
    }

    /* JADX INFO: renamed from: b */
    private static boolean m24b(Message message) {
        boolean z;
        String str = (String) message.obj;
        long jElapsedRealtime = SystemClock.elapsedRealtime();
        long jCurrentTimeMillis = System.currentTimeMillis();
        long jM38h = m38h();
        long jM42l = m42l();
        long j = jM42l > jM38h ? jM42l : jM38h;
        long j2 = j - jM38h;
        if (j2 < 500) {
            j2 = -1000;
        }
        String strM37g = m37g();
        if (jCurrentTimeMillis - j > 30000) {
            if (!TextUtils.isEmpty(f13M)) {
                C0085q.m138a(f13M, ((int) j2) / f42y);
            }
            f13M = UUID.randomUUID().toString();
            m10a(f13M);
            m6a(jCurrentTimeMillis);
            long jM39i = m39i();
            long j3 = jCurrentTimeMillis - jM39i;
            if (0 == jM39i) {
                j3 = 0;
            }
            m19b(jCurrentTimeMillis);
            C0085q.m128a(f13M, jCurrentTimeMillis, j3, C0089u.m177a() ? 1 : -1);
            strM37g = "";
            z = true;
        } else {
            z = false;
        }
        m31d(jCurrentTimeMillis);
        m20b(str);
        f14N = C0085q.m130a(f13M, str, jCurrentTimeMillis, 0, strM37g, jElapsedRealtime);
        return z;
    }

    /* JADX INFO: renamed from: c */
    protected static Context m25c() {
        return f11K;
    }

    /* JADX INFO: renamed from: c */
    private static String m27c(Throwable th) {
        StringBuilder sb = new StringBuilder();
        sb.append(th.toString());
        sb.append("\r\n");
        StackTraceElement[] stackTrace = th.getStackTrace();
        int length = stackTrace.length <= 50 ? stackTrace.length : 50;
        for (int i = 0; i < length; i++) {
            sb.append("\t" + stackTrace[i] + "\r\n");
        }
        Throwable cause = th.getCause();
        if (cause != null) {
            m13a(sb, stackTrace, cause, 1);
        }
        return sb.toString();
    }

    /* JADX INFO: renamed from: c */
    static void m28c(long j) {
        m11a(f34q, j);
    }

    /* JADX INFO: renamed from: c */
    private static void m29c(Message message) {
        long jCurrentTimeMillis = System.currentTimeMillis();
        long jElapsedRealtime = SystemClock.elapsedRealtime();
        if (f14N != -1) {
            C0085q.m135a(f14N, jElapsedRealtime);
        }
        m33e(jCurrentTimeMillis);
    }

    /* JADX INFO: renamed from: d */
    public static String m30d() {
        return f12L;
    }

    /* JADX INFO: renamed from: d */
    static void m31d(long j) {
        m11a(f35r, j);
    }

    /* JADX INFO: renamed from: d */
    private static void m32d(Message message) {
        C0061a c0061a = (C0061a) message.obj;
        C0085q.m139a(f13M, c0061a.f44a, c0061a.f45b, c0061a.f49f, c0061a.f50g);
    }

    /* JADX INFO: renamed from: e */
    static void m33e(long j) {
        m11a(f36s, j);
    }

    /* JADX INFO: renamed from: e */
    static boolean m34e() {
        if (m17b(f29l, 1L) != 0) {
            return true;
        }
        return f26i;
    }

    /* JADX INFO: renamed from: f */
    static String m35f() {
        return m18b(f30m, (String) null);
    }

    /* JADX INFO: renamed from: f */
    static void m36f(long j) {
        m11a(f37t, j);
    }

    /* JADX INFO: renamed from: g */
    static String m37g() {
        return m18b(f31n, "");
    }

    public static synchronized String getDeviceId(Context context) {
        C0089u.f176a = context.getApplicationContext();
        return C0089u.m186e();
    }

    /* JADX INFO: renamed from: h */
    static long m38h() {
        return m17b(f32o, 0L);
    }

    /* JADX INFO: renamed from: i */
    static long m39i() {
        return m17b(f33p, 0L);
    }

    public static void init(Context context) {
        f11K = context.getApplicationContext();
        try {
            Bundle bundle = f11K.getPackageManager().getApplicationInfo(f11K.getPackageName(), 128).metaData;
            String strM2a = m2a(bundle, f39v);
            String strM2a2 = m2a(bundle, f40w);
            if (TextUtils.isEmpty(strM2a)) {
                Log.e(f25h, "TD_APP_ID not found in AndroidManifest.xml!");
            } else {
                Log.i(f25h, "TD_APP_ID in AndroidManifest.xml is:" + strM2a + ".");
                Log.i(f25h, "TD_CHANNEL_ID in AndroidManifest.xml is:" + strM2a2 + ".");
                if (strM2a2 == null) {
                    strM2a2 = f25h;
                }
                init(context, strM2a, strM2a2);
            }
        } catch (Throwable th) {
            Log.e(f25h, "Failed to load meta-data", th);
        }
    }

    public static synchronized void init(Context context, String str, String str2) {
        if (!f8H) {
            f11K = context.getApplicationContext();
            C0089u.f176a = f11K;
            if (C0089u.m178a("android.permission.INTERNET")) {
                f12L = str;
                f9I = str2;
                if (Build.VERSION.SDK_INT >= 14 && (context instanceof Activity)) {
                    ((Activity) context).getApplication().registerActivityLifecycleCallbacks(new C0066ae());
                    f17Q = true;
                }
                C0079k.m71a(new RunnableC0064ac());
            } else {
                Log.e(f25h, "stop working...application do not have permission to send data, you must add <uses-permission android:name=\"android.permission.INTERNET\"/> to your AndroidManifest.xml.");
            }
            f8H = true;
        }
    }

    /* JADX INFO: renamed from: j */
    static long m40j() {
        return m17b(f34q, 0L);
    }

    /* JADX INFO: renamed from: k */
    static long m41k() {
        return m17b(f35r, 0L);
    }

    /* JADX INFO: renamed from: l */
    static long m42l() {
        return m17b(f36s, 0L);
    }

    /* JADX INFO: renamed from: m */
    static long m43m() {
        return m17b(f37t, 0L);
    }

    /* JADX INFO: renamed from: n */
    static C0078j m44n() {
        if (f11K == null) {
            return null;
        }
        C0078j c0078j = new C0078j();
        c0078j.f113a = f11K.getPackageName();
        c0078j.f114b = C0089u.m208t();
        c0078j.f115c = C0089u.m207s();
        c0078j.f116d = m40j();
        c0078j.f117e = f28k;
        c0078j.f118f = f9I;
        c0078j.f120h = C0089u.m211w();
        c0078j.f121i = C0089u.m212x();
        return c0078j;
    }

    /* JADX INFO: renamed from: o */
    static C0093y m45o() {
        Location location = null;
        if (f11K == null) {
            return null;
        }
        C0093y c0093y = new C0093y();
        c0093y.f197a = C0089u.m196j();
        c0093y.f198b = C0089u.m199k();
        List<Location> listM206r = C0089u.m206r();
        StringBuffer stringBuffer = new StringBuffer();
        for (Location location2 : listM206r) {
            stringBuffer.append(location2.getLatitude()).append(',').append(location2.getLongitude()).append(',').append(location2.getAltitude()).append(',').append(location2.getTime()).append(',').append(location2.getAccuracy()).append(',').append(location2.getBearing()).append(',').append(location2.getSpeed()).append(',').append((int) ((short) location2.getProvider().hashCode())).append(':');
            if (location != null && location2.getTime() <= location.getTime()) {
                location2 = location;
            }
            location = location2;
        }
        C0074f c0074f = new C0074f();
        if (location != null) {
            c0074f.f111b = location.getLatitude();
            c0074f.f110a = location.getLongitude();
        }
        c0093y.f199c = c0074f;
        c0093y.f200d = Build.CPU_ABI;
        c0093y.f201e = C0089u.m159C();
        c0093y.f202f = C0089u.m157A();
        c0093y.f203g = C0089u.m204p();
        c0093y.f204h = C0089u.m158B();
        c0093y.f205i = ((TimeZone.getDefault().getRawOffset() / f42y) / 60) / 60;
        c0093y.f206j = "Android+" + Build.VERSION.RELEASE;
        c0093y.f207k = C0089u.m181b() ? 0 : 1;
        c0093y.f208l = C0089u.m160D();
        c0093y.f211o = C0089u.m201m();
        c0093y.f210n = C0089u.m202n();
        c0093y.f212p = stringBuffer.toString();
        c0093y.f216t = C0089u.m195i();
        C0090v c0090vM205q = C0089u.m205q();
        c0093y.f217u = c0090vM205q.f186c;
        c0093y.f218v = c0090vM205q.f187d;
        c0093y.f219w = c0090vM205q.f188e;
        return c0093y;
    }

    public static void onError(Context context, Throwable th) {
        if (th == null) {
            return;
        }
        C0079k.m71a(new RunnableC0062aa(th));
    }

    public static void onEvent(Context context, String str) {
        onEvent(context, str, "");
    }

    public static void onEvent(Context context, String str, String str2) {
        onEvent(context, str, str2, null);
    }

    public static void onEvent(Context context, String str, String str2, Map map) {
        C0079k.m71a(new RunnableC0092x(str, str2, map));
    }

    public static void onPageEnd(Activity activity, String str) {
        m7a(activity, str, 2);
    }

    public static void onPageStart(Activity activity, String str) {
        m7a(activity, str, 1);
    }

    public static void onPause(Activity activity) {
        if (f17Q) {
            return;
        }
        onPageEnd(activity, activity.getLocalClassName());
    }

    public static void onResume(Activity activity) {
        if (f17Q) {
            return;
        }
        onPageStart(activity, activity.getLocalClassName());
    }

    /* JADX INFO: renamed from: p */
    public static void m46p() {
        Thread.setDefaultUncaughtExceptionHandler(new C0077i());
    }

    public static void setReportUncaughtExceptions(boolean z) {
        f10J = z;
    }

    /* JADX INFO: renamed from: u */
    private static void m51u() {
        m11a(f38u, System.currentTimeMillis() / 86400000);
    }
}
