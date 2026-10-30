package com.lenovo.lps.sus.p009d;

import android.content.Context;
import android.os.Handler;
import com.lenovo.lps.sus.control.C0111am;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import java.io.File;

/* JADX INFO: renamed from: com.lenovo.lps.sus.d.c */
/* JADX INFO: loaded from: classes.dex */
public class C0141c {

    /* JADX INFO: renamed from: a */
    private C0111am f1572a = null;

    /* JADX INFO: renamed from: b */
    private Context f1573b = null;

    /* JADX INFO: renamed from: c */
    private C0144f f1574c = null;

    /* JADX INFO: renamed from: d */
    private long f1575d = 0;

    /* JADX INFO: renamed from: e */
    private int f1576e = 0;

    /* JADX INFO: renamed from: f */
    private int f1577f = 0;

    /* JADX INFO: renamed from: g */
    private int f1578g = 0;

    /* JADX INFO: renamed from: h */
    private long f1579h = 0;

    /* JADX INFO: renamed from: i */
    private long f1580i = 0;

    /* JADX INFO: renamed from: j */
    private Handler f1581j = new HandlerC0142d(this);

    /* JADX INFO: renamed from: a */
    public void m553a() {
        C0098i.m409a(C0092c.f1339b, "CustomDownloadManager finish");
        if (this.f1574c != null) {
            this.f1574c.m557a((InterfaceC0139a) null);
            this.f1574c.m556a();
            this.f1574c = null;
        }
    }

    /* JADX INFO: renamed from: a */
    public boolean m554a(int i, int i2, Context context, C0111am c0111am, String str, String str2, String str3, long j) {
        this.f1573b = context;
        this.f1572a = c0111am;
        if (this.f1573b == null || this.f1572a == null || str == null || str2 == null || str2.length() == 0 || str3 == null || str3.length() == 0 || 0 >= j) {
            return false;
        }
        File file = new File(str);
        if (!file.exists()) {
            C0098i.m411b(C0092c.f1339b, "The folder isn't exit! path=" + C0092c.m372i());
            return false;
        }
        Context context2 = this.f1573b;
        if (this.f1574c != null) {
            this.f1574c.m557a((InterfaceC0139a) null);
            this.f1574c.m556a();
            this.f1574c = null;
        }
        this.f1579h = System.currentTimeMillis();
        this.f1580i = this.f1579h;
        this.f1576e = 0;
        this.f1577f = 0;
        this.f1578g = 0;
        this.f1574c = new C0144f(context2, i, "userAgent", str3, j, file, str2, new C0143e(this));
        this.f1574c.start();
        return true;
    }
}
