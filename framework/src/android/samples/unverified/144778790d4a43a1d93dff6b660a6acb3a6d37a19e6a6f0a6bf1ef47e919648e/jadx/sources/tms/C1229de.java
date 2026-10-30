package tms;

import java.io.File;
import java.lang.reflect.Method;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: renamed from: tms.de */
/* JADX INFO: loaded from: classes.dex */
final class C1229de {

    /* JADX INFO: renamed from: a */
    private Method f7092a;

    /* JADX INFO: renamed from: b */
    private Method f7093b;

    /* JADX INFO: renamed from: c */
    private boolean f7094c;

    /* JADX INFO: renamed from: d */
    private boolean f7095d;

    public C1229de() {
        try {
            Class<?> cls = Class.forName("android.net.TrafficStats");
            this.f7092a = cls.getDeclaredMethod("getUidRxBytes", Integer.TYPE);
            this.f7093b = cls.getDeclaredMethod("getUidTxBytes", Integer.TYPE);
            this.f7094c = true;
        } catch (Exception e) {
            this.f7094c = false;
            e.printStackTrace();
        }
        if (this.f7094c) {
            return;
        }
        this.f7095d = new File("/proc/uid_stat").exists();
    }

    /* JADX INFO: renamed from: a */
    private static long m3102a(int i, String str, String str2) {
        String[] strArrM3593b;
        String[] strArrM3593b2;
        long j = -1;
        File file = new File("/proc/uid_stat/" + i + CookieSpec.PATH_DELIM + str);
        File file2 = new File("/proc/uid_stat/" + i + CookieSpec.PATH_DELIM + str2);
        if (file.exists() && (strArrM3593b2 = C1336v.m3593b(file)) != null && strArrM3593b2.length > 0) {
            j = Long.parseLong(strArrM3593b2[0]);
        }
        if (!file2.exists() || (strArrM3593b = C1336v.m3593b(file2)) == null || strArrM3593b.length <= 0) {
            return j;
        }
        return file.exists() ? j + Long.parseLong(strArrM3593b[0]) : Long.parseLong(strArrM3593b[0]);
    }

    /* JADX INFO: renamed from: a */
    public final long m3103a(int i) {
        if (!this.f7094c) {
            if (this.f7095d) {
                return m3102a(i, "tcp_rcv", "udp_rcv");
            }
            return -1L;
        }
        try {
            return Long.valueOf(this.f7092a.invoke(null, Integer.valueOf(i)).toString()).longValue();
        } catch (Exception e) {
            e.printStackTrace();
            return -1L;
        }
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3104a() {
        return this.f7095d || this.f7094c;
    }

    /* JADX INFO: renamed from: b */
    public final long m3105b(int i) {
        if (!this.f7094c) {
            if (this.f7095d) {
                return m3102a(i, "tcp_snd", "udp_snd");
            }
            return -1L;
        }
        try {
            return Long.valueOf(this.f7093b.invoke(null, Integer.valueOf(i)).toString()).longValue();
        } catch (Exception e) {
            e.printStackTrace();
            return -1L;
        }
    }
}
