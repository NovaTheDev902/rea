package com.tendcloud.tenddata;

import android.os.Handler;
import android.os.HandlerThread;
import android.os.SystemClock;
import android.util.Log;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: com.tendcloud.tenddata.c */
/* JADX INFO: loaded from: classes.dex */
final class RunnableC0071c implements Runnable {

    /* JADX INFO: renamed from: a */
    private static final int f84a = 1;

    /* JADX INFO: renamed from: b */
    private static final int f85b = 20480;

    /* JADX INFO: renamed from: c */
    private static final int f86c = 10000;

    /* JADX INFO: renamed from: d */
    private static final HandlerThread f87d = new HandlerThread("ProcessingThread");

    /* JADX INFO: renamed from: e */
    private static RunnableC0071c f88e = null;

    /* JADX INFO: renamed from: f */
    private static Handler f89f = null;

    /* JADX INFO: renamed from: i */
    private long f92i;

    /* JADX INFO: renamed from: g */
    private int f90g = 0;

    /* JADX INFO: renamed from: h */
    private boolean f91h = false;

    /* JADX INFO: renamed from: j */
    private int f93j = 0;

    static {
        f87d.start();
    }

    private RunnableC0071c() {
    }

    /* JADX INFO: renamed from: a */
    static synchronized RunnableC0071c m59a() {
        if (f88e == null) {
            m62e();
        }
        return f88e;
    }

    /* JADX INFO: renamed from: a */
    private void m60a(C0069ah c0069ah) {
        Log.d("TalkingData", "Send Success, Clear Data");
        C0085q.m136a(TCAgent.m25c());
        List<C0068ag> list = c0069ah.f68e;
        C0085q.m144b(c0069ah.f69f);
        C0085q.m147c(c0069ah.f70g);
        C0085q.m150d(c0069ah.f71h);
        for (C0068ag c0068ag : list) {
            switch (c0068ag.f60a) {
                case 1:
                    TCAgent.m22b(false);
                    break;
                case 2:
                    C0070b c0070b = c0068ag.f61b;
                    if (c0070b.f78c == 1) {
                        C0085q.m137a(c0070b.f76a);
                    } else if (c0070b.f78c == 3) {
                        C0085q.m145b(c0070b.f76a);
                        C0085q.m148c(c0070b.f76a);
                        C0085q.m151d(c0070b.f76a);
                    }
                    break;
            }
        }
        C0085q.m143b();
        if (c0069ah.f72i != null) {
            TCAgent.m3a();
        }
    }

    /* JADX INFO: renamed from: b */
    static synchronized Handler m61b() {
        if (f89f == null) {
            m62e();
        }
        return f89f;
    }

    /* JADX INFO: renamed from: e */
    private static void m62e() {
        if (f88e == null) {
            f88e = new RunnableC0071c();
            new Thread(f88e).start();
        }
        if (f89f == null) {
            f89f = new HandlerC0075g(f87d.getLooper());
        }
    }

    /* JADX INFO: renamed from: f */
    private synchronized boolean m63f() {
        boolean zM75a = false;
        synchronized (this) {
            if (TCAgent.m25c() != null && SystemClock.elapsedRealtime() - this.f92i >= 10000) {
                C0069ah c0069ahM64g = m64g();
                if (c0069ahM64g == null) {
                    zM75a = true;
                } else if (this.f90g > 1) {
                    this.f91h = false;
                    m61b().hasMessages(5);
                    m61b().removeMessages(5);
                    TCAgent.m5a(5, 300000L);
                    this.f90g = 0;
                } else {
                    Log.d("TalkingData", "Post data to server...");
                    zM75a = C0083o.m75a(c0069ahM64g);
                    Log.d("TalkingData", "server return success:" + zM75a);
                    if (zM75a) {
                        this.f90g = 0;
                        m60a(c0069ahM64g);
                        TCAgent.m36f(System.currentTimeMillis());
                    } else {
                        this.f90g++;
                        this.f91h = true;
                    }
                    this.f92i = SystemClock.elapsedRealtime();
                }
            }
        }
        return zM75a;
    }

    /* JADX INFO: renamed from: g */
    private C0069ah m64g() {
        int iMo56a;
        boolean z;
        C0069ah c0069ah = new C0069ah();
        c0069ah.f64a = C0089u.m186e();
        c0069ah.f65b = TCAgent.m30d();
        c0069ah.f66c = TCAgent.m44n();
        c0069ah.f67d = TCAgent.m45o();
        c0069ah.f72i = TCAgent.f23f;
        int iMo58a = c0069ah.mo58a() + 3 + 0;
        if (TCAgent.m34e()) {
            C0068ag c0068ag = new C0068ag();
            c0068ag.f60a = 1;
            c0068ag.f62c = C0089u.m161E();
            c0069ah.f68e.add(c0068ag);
            iMo56a = iMo58a + c0068ag.f62c.mo56a() + C0084p.m81c(c0068ag.f60a);
            z = true;
        } else {
            iMo56a = iMo58a;
            z = false;
        }
        C0085q.m136a(TCAgent.m25c());
        c0069ah.f71h = C0085q.m152e(C0086r.f174e);
        List<C0070b> listM149d = C0085q.m149d();
        ArrayList arrayList = new ArrayList();
        int i = iMo56a;
        int i2 = 0;
        for (C0070b c0070b : listM149d) {
            i2++;
            c0070b.f80h = C0085q.m132a(c0070b.f76a, c0069ah.f69f);
            c0070b.f81i = C0085q.m142b(c0070b.f76a, c0069ah.f70g);
            C0068ag c0068ag2 = new C0068ag();
            c0068ag2.f60a = 2;
            c0068ag2.f61b = c0070b;
            int iMo56a2 = c0070b.mo56a();
            if (iMo56a2 + i > f85b && i2 != 1) {
                this.f91h = true;
                break;
            }
            i += iMo56a2;
            arrayList.add(c0070b);
            if (c0070b.f78c != 2 || c0070b.f80h.size() != 0 || c0070b.f81i.size() != 0) {
                c0069ah.f68e.add(c0068ag2);
            }
        }
        c0069ah.f69f = C0085q.m131a(arrayList);
        c0069ah.f70g = C0085q.m141b(arrayList);
        if (c0069ah.f71h > 0) {
            Iterator it = C0085q.m153e(c0069ah.f71h).iterator();
            while (it.hasNext()) {
                c0069ah.f68e.add((C0068ag) it.next());
            }
        }
        C0085q.m143b();
        if (z || c0069ah.f68e.size() != 0) {
            return c0069ah;
        }
        return null;
    }

    /* JADX INFO: renamed from: c */
    synchronized void m65c() {
        if (!C0089u.m177a()) {
            Log.w("TalkingData", "network is disabled.");
        } else if (TCAgent.f27j == 0 && TCAgent.f24g && !C0089u.m181b()) {
            Log.w("TalkingData", "wifi is not connected.");
        } else if (this.f93j <= 1) {
            this.f93j++;
            notify();
        }
    }

    /* JADX INFO: renamed from: d */
    public boolean m66d() {
        if (TCAgent.m25c() == null) {
            return false;
        }
        C0085q.m136a(TCAgent.m25c());
        List listM149d = C0085q.m149d();
        C0085q.m143b();
        return listM149d.size() > 0;
    }

    @Override // java.lang.Runnable
    public void run() {
        try {
            synchronized (this) {
                while (true) {
                    if (this.f93j == 0 || !C0089u.m177a()) {
                        try {
                            wait();
                        } catch (InterruptedException e) {
                        }
                    }
                    try {
                        this.f93j--;
                        if (m63f()) {
                        }
                        if (this.f91h) {
                            TCAgent.m5a(5, 10000L);
                            this.f91h = false;
                        }
                    } catch (IOException e2) {
                    }
                }
            }
        } catch (Throwable th) {
        }
    }
}
