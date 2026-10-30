package com.lenovo.lps.sus.control;

import android.content.Context;
import android.widget.Toast;
import com.lenovo.lps.sus.EventType;
import com.lenovo.lps.sus.SUSListener;
import com.lenovo.lps.sus.p007b.C0089e;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;

/* JADX INFO: renamed from: com.lenovo.lps.sus.control.ae */
/* JADX INFO: loaded from: classes.dex */
public final class C0104ae {

    /* JADX INFO: renamed from: a */
    private static int f1412a = 0;

    /* JADX INFO: renamed from: b */
    private static C0134v f1413b = null;

    /* JADX INFO: renamed from: c */
    private static SUSListener f1414c = null;

    /* JADX INFO: renamed from: d */
    private static Boolean f1415d = false;

    /* JADX INFO: renamed from: e */
    private static Boolean f1416e = false;

    /* JADX INFO: renamed from: f */
    private static Boolean f1417f = false;

    /* JADX INFO: renamed from: g */
    private static Boolean f1418g = false;

    /* JADX INFO: renamed from: h */
    private static String f1419h = null;

    /* JADX INFO: renamed from: i */
    private static long f1420i = 0;

    /* JADX INFO: renamed from: j */
    private static long f1421j = 0;

    /* JADX INFO: renamed from: a */
    public static void m439a(int i) {
        C0092c.m330a(i);
    }

    /* JADX INFO: renamed from: a */
    public static void m440a(EventType eventType) {
        if (f1413b == null || eventType == null) {
            return;
        }
        f1413b.m507a(eventType);
    }

    /* JADX INFO: renamed from: a */
    public static void m441a(SUSListener sUSListener) {
        f1414c = sUSListener;
        if (f1413b != null) {
            f1413b.m508a(sUSListener);
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m442a(String str) {
        C0092c.m345b(str);
    }

    /* JADX INFO: renamed from: a */
    public static void m443a(String str, long j, long j2) {
        f1419h = str;
        f1420i = j;
        f1421j = j2;
        if (f1413b != null) {
            f1413b.m512a(str, j, j2);
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m444a(boolean z) {
        f1415d = Boolean.valueOf(z);
    }

    /* JADX INFO: renamed from: a */
    public static boolean m445a() {
        return 1 == m464j();
    }

    /* JADX INFO: renamed from: a */
    public static boolean m446a(Context context, EnumC0113ap enumC0113ap, C0089e c0089e) {
        String strM343b;
        String strM343b2;
        if (context == null) {
            System.out.println("The context is illegal!");
            C0098i.m411b(C0092c.f1339b, "The context is illegal!");
            return false;
        }
        C0098i.m409a(C0092c.f1339b, String.format("SUS input params: context=%s; updateTransactionType=%s", String.valueOf(context), String.valueOf(enumC0113ap)));
        if (!C0092c.m385o(context)) {
            System.out.println("Network unavailable!");
            C0098i.m409a(C0092c.f1339b, "Network unavailable!");
            if (m445a()) {
                if (!C0092c.m395u() && C0092c.m351c() && !m457f() && !m459g()) {
                    C0092c.m360e(false);
                }
            } else if (C0092c.m351c() && !m457f() && !m459g() && context != null && (strM343b2 = C0092c.m343b(context, "SUS_MSG_FAIL_NETWORKUNAVAILABLE")) != null && strM343b2.length() > 0) {
                Toast.makeText(context, strM343b2, 1).show();
            }
            if (f1414c == null) {
                return false;
            }
            f1414c.onUpdateNotification(EventType.SUS_FAIL_NETWORKUNAVAILABLE, "Network unavailable!");
            return false;
        }
        if (f1415d.booleanValue() && !C0092c.m377k(context)) {
            System.out.println("isn't wlan connect");
            C0098i.m409a(C0092c.f1339b, "isn't wlan connect");
            if (C0092c.m351c() && !m457f() && !m459g() && context != null && (strM343b = C0092c.m343b(context, "SUS_MSG_FAIL_NOWLANCONNECTED")) != null && strM343b.length() > 0) {
                Toast.makeText(context, strM343b, 1).show();
            }
            if (f1414c == null) {
                return false;
            }
            f1414c.onUpdateNotification(EventType.SUS_FAIL_NOWLANCONNECTED, "Please open the WLAN!");
            return false;
        }
        if (m463i()) {
            f1413b = new C0134v(context);
            if (f1413b == null) {
                System.out.println("UpdateTransaction fail!");
                C0098i.m411b(C0092c.f1339b, "UpdateTransaction fail!");
                m447b();
                return false;
            }
            m441a(f1414c);
            m443a(f1419h, f1420i, f1421j);
            f1413b.m509a(enumC0113ap, c0089e);
            return true;
        }
        System.out.println("Update pengding!");
        C0098i.m409a(C0092c.f1339b, "Update pengding!");
        if (!C0092c.m395u() && C0092c.m351c() && !m457f() && !m459g()) {
            C0092c.m360e(false);
        }
        if (f1414c == null) {
            return false;
        }
        f1414c.onUpdateNotification(EventType.SUS_WARNING_PENDING, "Update pengding!");
        return false;
    }

    /* JADX INFO: renamed from: b */
    public static void m447b() {
        C0098i.m409a(C0092c.f1339b, "SUSController finish entry");
        if (m445a()) {
            m465k();
        }
        if (f1413b != null) {
            C0098i.m409a(C0092c.f1339b, "SUSController call dismissDialog");
            if (C0092c.m397w()) {
                C0111am.m474c();
            } else if (C0092c.m396v()) {
                SUSCustdefNotificationActivity.m416b();
            } else {
                SUSNotificationActivity.m424a();
            }
            C0098i.m409a(C0092c.f1339b, "SUSController call myUpdateTransaction finish");
            f1413b.m504a();
            f1413b = null;
        }
        C0098i.m409a(C0092c.f1339b, "SUSController finish end");
    }

    /* JADX INFO: renamed from: b */
    public static void m448b(String str) {
        C0092c.m349c(str);
    }

    /* JADX INFO: renamed from: b */
    public static void m449b(boolean z) {
        C0098i.m410a(z);
    }

    /* JADX INFO: renamed from: c */
    public static void m450c(boolean z) {
        C0092c.m334a(z);
    }

    /* JADX INFO: renamed from: c */
    public static boolean m451c() {
        return f1415d.booleanValue();
    }

    /* JADX INFO: renamed from: d */
    public static void m452d() {
        C0092c.m370h(true);
        f1416e = true;
    }

    /* JADX INFO: renamed from: d */
    public static void m453d(boolean z) {
        f1416e = Boolean.valueOf(z);
    }

    /* JADX INFO: renamed from: e */
    public static void m454e() {
        C0092c.m370h(false);
        f1416e = false;
    }

    /* JADX INFO: renamed from: e */
    public static void m455e(boolean z) {
        f1417f = Boolean.valueOf(z);
    }

    /* JADX INFO: renamed from: f */
    public static void m456f(boolean z) {
        f1418g = Boolean.valueOf(z);
    }

    /* JADX INFO: renamed from: f */
    public static boolean m457f() {
        return f1416e.booleanValue();
    }

    /* JADX INFO: renamed from: g */
    public static void m458g(boolean z) {
        C0092c.m363f(z);
    }

    /* JADX INFO: renamed from: g */
    public static boolean m459g() {
        return f1417f.booleanValue();
    }

    /* JADX INFO: renamed from: h */
    public static void m460h(boolean z) {
        C0092c.m367g(z);
    }

    /* JADX INFO: renamed from: h */
    public static boolean m461h() {
        return f1418g.booleanValue();
    }

    /* JADX INFO: renamed from: i */
    public static void m462i(boolean z) {
        C0092c.m350c(z);
    }

    /* JADX INFO: renamed from: i */
    public static boolean m463i() {
        if (f1412a > 0) {
            return false;
        }
        if (f1412a == 0) {
            f1412a++;
            return true;
        }
        System.out.println("updateTransactionRefNum < 0 !!!");
        return false;
    }

    /* JADX INFO: renamed from: j */
    public static int m464j() {
        return f1412a;
    }

    /* JADX INFO: renamed from: k */
    public static boolean m465k() {
        if (f1412a > 0) {
            f1412a--;
            return true;
        }
        System.out.println("updateTransactionRefNum <= 0 !!!");
        return false;
    }

    /* JADX INFO: renamed from: l */
    public static Context m466l() {
        if (f1413b != null) {
            return f1413b.m528u();
        }
        return null;
    }
}
