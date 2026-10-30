package com.tencent.lbsapi.p013a;

import android.content.Context;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

/* JADX INFO: renamed from: com.tencent.lbsapi.a.f */
/* JADX INFO: loaded from: classes.dex */
public class C1062f {

    /* JADX INFO: renamed from: a */
    private static ThreadPoolExecutor f5913a = null;

    /* JADX INFO: renamed from: b */
    private InterfaceC1058b f5914b;

    public C1062f(InterfaceC1058b interfaceC1058b) {
        this.f5914b = null;
        this.f5914b = interfaceC1058b;
    }

    /* JADX INFO: renamed from: a */
    protected synchronized ThreadPoolExecutor m2497a() {
        if (f5913a == null) {
            f5913a = new ThreadPoolExecutor(2, 6, 60L, TimeUnit.SECONDS, new ArrayBlockingQueue(12));
        }
        return f5913a;
    }

    /* JADX INFO: renamed from: a */
    public boolean m2498a(Context context, int i, String str, byte[] bArr) {
        if (bArr == null) {
            return false;
        }
        try {
            C1057a c1057a = new C1057a();
            c1057a.m2489a(bArr);
            c1057a.m2485a(i);
            c1057a.m2487a(this.f5914b);
            c1057a.m2488a(str);
            c1057a.m2486a(context);
            m2497a().execute(c1057a);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    /* JADX INFO: renamed from: b */
    public synchronized void m2499b() {
        if (f5913a != null) {
            f5913a.shutdownNow();
            f5913a = null;
        }
    }
}
