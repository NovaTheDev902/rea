package tms;

import android.content.Context;
import com.tencent.tmsecure.module.permission.IDummyService;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.ff */
/* JADX INFO: loaded from: classes.dex */
public abstract class AbstractC1284ff {

    /* JADX INFO: renamed from: a */
    public static final int f7315a = 0;

    /* JADX INFO: renamed from: b */
    public static final int f7316b = 1;

    /* JADX INFO: renamed from: c */
    public static final int f7317c = 2;

    /* JADX INFO: renamed from: d */
    public static final String f7318d = "process_id";

    /* JADX INFO: renamed from: e */
    public static final String f7319e = "com.tencent.tmsecure.hookeraction";

    /* JADX INFO: renamed from: f */
    static String f7320f;

    /* JADX INFO: renamed from: g */
    static Context f7321g;

    /* JADX INFO: renamed from: h */
    static List<IDummyService.Stub> f7322h = new ArrayList();

    AbstractC1284ff() {
    }

    /* JADX INFO: renamed from: a */
    public static synchronized void m3303a(Context context) {
        f7321g = context;
    }

    /* JADX INFO: renamed from: a */
    public static synchronized void m3304a(String str) {
        f7320f = str;
    }

    /* JADX INFO: renamed from: c */
    protected static Object[] m3305c() {
        Object[] objArr = new Object[f7322h.size() * 2];
        int i = 0;
        Iterator<IDummyService.Stub> it = f7322h.iterator();
        while (true) {
            int i2 = i;
            if (!it.hasNext()) {
                return objArr;
            }
            IDummyService.Stub next = it.next();
            objArr[i2] = next.getServiceName();
            objArr[i2 + 1] = next;
            i = i2 + 2;
        }
    }

    /* JADX INFO: renamed from: d */
    public static synchronized Context m3306d() {
        return f7321g;
    }

    /* JADX INFO: renamed from: e */
    public static synchronized String m3307e() {
        return f7320f;
    }

    /* JADX INFO: renamed from: a */
    protected void m3308a(IDummyService.Stub stub) {
        f7322h.add(stub);
    }

    /* JADX INFO: renamed from: a */
    public abstract Object[] m3309a();

    /* JADX INFO: renamed from: b */
    public abstract void m3310b();
}
