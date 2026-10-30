package tms;

import android.content.BroadcastReceiver;

/* JADX INFO: renamed from: tms.h */
/* JADX INFO: loaded from: classes.dex */
public class C1313h {

    /* JADX INFO: renamed from: a */
    private static volatile boolean f7428a = false;

    /* JADX INFO: renamed from: b */
    private static volatile boolean f7429b = false;

    /* JADX INFO: renamed from: c */
    private static BroadcastReceiver f7430c = new C1297fs();

    C1313h() {
    }

    /* JADX INFO: renamed from: a */
    public static synchronized void m3446a() {
        if (!f7428a) {
            f7428a = true;
            C1149af c1149af = new C1149af("tms");
            if (!c1149af.m2890a("reportlc", false)) {
                new C1298ft(c1149af).start();
            }
        }
    }

    /* JADX INFO: renamed from: e */
    static /* synthetic */ boolean m3451e() {
        f7428a = false;
        return false;
    }
}
