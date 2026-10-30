package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.IBinder;
import android.os.Looper;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.BaseService;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.common.TMSService;
import com.tencent.tmsecure.module.network.INetworkInfoDao;
import com.tencent.tmsecure.module.network.INetworkMonitor;
import com.tencent.tmsecure.module.network.NetDataEntityFactory;
import com.tencent.tmsecure.module.network.TrafficEntity;
import com.tencent.tmsecure.module.networkload.NetworkloadProperties;
import com.tencent.tmsecure.module.update.IUpdateObserver;
import com.tencent.tmsecure.module.update.UpdateConfig;
import com.tencent.tmsecure.module.update.UpdateManager;
import java.io.File;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

/* JADX INFO: renamed from: tms.dt */
/* JADX INFO: loaded from: classes.dex */
public final class C1244dt extends BaseManager {

    /* JADX INFO: renamed from: a */
    private static final String f7193a = null;

    /* JADX INFO: renamed from: d */
    private boolean f7196d;

    /* JADX INFO: renamed from: e */
    private long f7197e;

    /* JADX INFO: renamed from: f */
    private int f7198f;

    /* JADX INFO: renamed from: g */
    private Context f7199g;

    /* JADX INFO: renamed from: h */
    private C1226db f7200h;

    /* JADX INFO: renamed from: b */
    private String f7194b = null;

    /* JADX INFO: renamed from: c */
    private BaseService f7195c = new a(this, 0);

    /* JADX INFO: renamed from: i */
    private final Map<String, C1223cz> f7201i = new HashMap();

    /* JADX INFO: renamed from: j */
    private IUpdateObserver f7202j = new C1227dc(this);

    /* JADX INFO: renamed from: k */
    private C1220cw f7203k = new C1220cw();

    /* JADX INFO: renamed from: tms.dt$a */
    final class a extends BaseService {

        /* JADX INFO: renamed from: a */
        final /* synthetic */ C1244dt f7204a;

        /* JADX INFO: renamed from: b */
        private HandlerThread f7205b;

        /* JADX INFO: renamed from: c */
        private Looper f7206c;

        /* JADX INFO: renamed from: d */
        private Handler f7207d;

        /* JADX INFO: renamed from: e */
        private Runnable f7208e;

        /* JADX INFO: renamed from: f */
        private b f7209f;

        /* JADX INFO: renamed from: tms.dt$a$a, reason: collision with other inner class name */
        final class RunnableC1342a implements Runnable {
            private RunnableC1342a() {
            }

            /* synthetic */ RunnableC1342a(a aVar, byte b) {
                this();
            }

            @Override // java.lang.Runnable
            public final void run() {
                Iterator it = a.this.f7204a.f7201i.values().iterator();
                while (it.hasNext()) {
                    ((C1223cz) it.next()).m3087a();
                }
                if (a.this.f7204a.f7196d) {
                    Handler handler = a.this.f7207d;
                    Runnable runnable = a.this.f7208e;
                    long j = a.this.f7204a.f7197e;
                    Date date = new Date();
                    GregorianCalendar gregorianCalendar = new GregorianCalendar();
                    gregorianCalendar.add(5, 1);
                    gregorianCalendar.set(11, 0);
                    gregorianCalendar.set(12, 0);
                    gregorianCalendar.set(13, 1);
                    gregorianCalendar.set(14, 0);
                    long timeInMillis = gregorianCalendar.getTimeInMillis() - date.getTime();
                    if (timeInMillis <= j) {
                        j = timeInMillis;
                    }
                    handler.postDelayed(runnable, j);
                }
            }
        }

        private a(C1244dt c1244dt) {
            byte b = 0;
            this.f7204a = c1244dt;
            this.f7208e = new RunnableC1342a(this, b);
            this.f7209f = new b(this.f7204a, b);
        }

        /* synthetic */ a(C1244dt c1244dt, byte b) {
            this(c1244dt);
        }

        @Override // com.tencent.tmsecure.common.BaseService
        public final IBinder onBind() {
            return null;
        }

        @Override // com.tencent.tmsecure.common.BaseService
        public final void onCreate(Context context) {
            super.onCreate(context);
            this.f7205b = new HandlerThread(getClass().getName());
            this.f7205b.start();
            this.f7206c = this.f7205b.getLooper();
            this.f7207d = new Handler(this.f7206c);
            this.f7209f.m3207a(this.f7204a.f7199g);
        }

        @Override // com.tencent.tmsecure.common.BaseService
        public final void onDestory() {
            super.onDestory();
            this.f7207d.removeCallbacks(this.f7208e);
            this.f7206c.quit();
            this.f7209f.m3208b(this.f7204a.f7199g);
        }

        @Override // com.tencent.tmsecure.common.BaseService
        public final void onStart(Intent intent) {
            super.onStart(intent);
            this.f7207d.removeCallbacks(this.f7208e);
            this.f7207d.post(this.f7208e);
        }
    }

    /* JADX INFO: renamed from: tms.dt$b */
    final class b extends BroadcastReceiver {

        /* JADX INFO: renamed from: b */
        private boolean f7212b;

        private b() {
        }

        /* synthetic */ b(C1244dt c1244dt, byte b) {
            this();
        }

        /* JADX INFO: renamed from: a */
        public final void m3207a(Context context) {
            if (this.f7212b) {
                return;
            }
            context.registerReceiver(this, new IntentFilter("android.intent.action.TIME_SET"));
            this.f7212b = true;
        }

        /* JADX INFO: renamed from: b */
        public final void m3208b(Context context) {
            if (this.f7212b) {
                context.unregisterReceiver(this);
                this.f7212b = false;
            }
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.TIME_SET")) {
                Iterator it = C1244dt.this.f7201i.values().iterator();
                while (it.hasNext()) {
                    ((C1223cz) it.next()).m3089b();
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static String m3176a() {
        if (new File("/proc/self/net/dev").exists()) {
            return "/proc/self/net/dev";
        }
        return !new File("/proc/net/dev").exists() ? NetConstant.ERROR : "/proc/net/dev";
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: i */
    public int m3181i() throws Throwable {
        try {
            if (C1336v.m3577a(this.f7199g, f7193a, (String) null) == null) {
                return -1;
            }
            this.f7200h.m3093a();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }

    /* JADX INFO: renamed from: a */
    public final void m3182a(int i) {
        this.f7198f = i;
        switch (i) {
            case 0:
                this.f7197e = 300000L;
                break;
            case 1:
                this.f7197e = 30000L;
                break;
            case 2:
                this.f7197e = C0092c.f1328ap;
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3183a(long j) {
        NetworkloadProperties.updateSelfMobileDownloadBytes(j);
    }

    /* JADX INFO: renamed from: a */
    public final void m3184a(boolean z) {
        if (z != this.f7196d) {
            this.f7196d = z;
            synchronized (this.f7201i) {
                Iterator<C1223cz> it = this.f7201i.values().iterator();
                while (it.hasNext()) {
                    it.next().m3088a(this.f7196d);
                }
            }
            if (this.f7196d) {
                TMSService.startService(this.f7195c);
            } else {
                TMSService.stopService(this.f7195c);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3185a(String[] strArr) {
        this.f7203k.m3079a(strArr);
        NetworkloadProperties.updateSelfMobileDownloadBytes(0L);
        NetworkloadProperties.updateSelfMobileUploadBytes(0L);
    }

    /* JADX INFO: renamed from: a */
    public final void m3186a(String[] strArr, boolean z) {
        this.f7203k.m3080a(strArr, z);
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3187a(String str) {
        boolean z = false;
        synchronized (this.f7201i) {
            if (this.f7201i.containsKey(str)) {
                z = this.f7201i.remove(str) != null;
            }
        }
        return z;
    }

    /* JADX WARN: Code duplicated, block: B:11:0x0023  */
    /* JADX INFO: renamed from: a */
    public final boolean m3188a(String str, INetworkInfoDao iNetworkInfoDao) {
        boolean z;
        synchronized (this.f7201i) {
            if (str == null || iNetworkInfoDao == null) {
                z = false;
            } else if (this.f7201i.containsKey(str)) {
                z = false;
            } else {
                C1222cy c1222cy = new C1222cy(iNetworkInfoDao, this.f7200h);
                c1222cy.m3088a(this.f7196d);
                this.f7201i.put(str, c1222cy);
                z = true;
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3189a(String str, NetDataEntityFactory netDataEntityFactory, INetworkInfoDao iNetworkInfoDao) {
        boolean z = false;
        synchronized (this.f7201i) {
            if (str != null && netDataEntityFactory != null && iNetworkInfoDao != null) {
                C1223cz c1223cz = new C1223cz(netDataEntityFactory, iNetworkInfoDao);
                c1223cz.m3088a(this.f7196d);
                z = this.f7201i.put(str, c1223cz) != null;
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: b */
    public final long m3190b() {
        return this.f7197e;
    }

    /* JADX INFO: renamed from: b */
    public final INetworkMonitor m3191b(String str) {
        C1223cz c1223cz;
        synchronized (this.f7201i) {
            c1223cz = this.f7201i.containsKey(str) ? this.f7201i.get(str) : null;
        }
        return c1223cz;
    }

    /* JADX INFO: renamed from: b */
    public final void m3192b(long j) {
        NetworkloadProperties.updateSelfMobileUploadBytes(j);
    }

    /* JADX WARN: Code duplicated, block: B:11:0x0023  */
    /* JADX INFO: renamed from: b */
    public final boolean m3193b(String str, INetworkInfoDao iNetworkInfoDao) {
        boolean z;
        synchronized (this.f7201i) {
            if (str == null || iNetworkInfoDao == null) {
                z = false;
            } else if (this.f7201i.containsKey(str)) {
                z = false;
            } else {
                C1225da c1225da = new C1225da(iNetworkInfoDao, this.f7200h);
                c1225da.m3088a(this.f7196d);
                this.f7201i.put(str, c1225da);
                z = true;
            }
        }
        return z;
    }

    /* JADX INFO: renamed from: c */
    public final int m3194c() {
        return this.f7198f;
    }

    /* JADX INFO: renamed from: c */
    public final TrafficEntity m3195c(String str) {
        return this.f7203k.m3078a(str);
    }

    /* JADX INFO: renamed from: d */
    public final long m3196d(String str) {
        return this.f7203k.m3082b(str);
    }

    /* JADX INFO: renamed from: d */
    public final boolean m3197d() {
        return this.f7196d;
    }

    /* JADX INFO: renamed from: e */
    public final long m3198e(String str) {
        return this.f7203k.m3083c(str);
    }

    /* JADX INFO: renamed from: e */
    public final synchronized void m3199e() {
        if (this.f7196d) {
            Iterator<C1223cz> it = this.f7201i.values().iterator();
            while (it.hasNext()) {
                it.next().notifyConfigChange();
            }
            if (this.f7195c != null) {
                TMSService.startService(this.f7195c);
            }
        }
    }

    /* JADX INFO: renamed from: f */
    public final long m3200f(String str) {
        return this.f7203k.m3084d(str);
    }

    /* JADX INFO: renamed from: f */
    public final boolean m3201f() {
        return this.f7203k.m3081a();
    }

    protected final void finalize() throws Throwable {
        ((UpdateManager) ManagerCreator.getManager(UpdateManager.class)).removeObserver(32);
        super.finalize();
    }

    /* JADX INFO: renamed from: g */
    public final long m3202g() {
        return NetworkloadProperties.getSelfMobileDownloadBytes();
    }

    /* JADX INFO: renamed from: g */
    public final long m3203g(String str) {
        return this.f7203k.m3085e(str);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    /* JADX INFO: renamed from: h */
    public final long m3204h() {
        return NetworkloadProperties.getSelfMobileUploadBytes();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7199g = context;
        C1336v.m3577a(this.f7199g, UpdateConfig.TRAFFIC_MONITOR_CONFIG_NAME, (String) null);
        this.f7194b = m3176a();
        this.f7200h = new C1226db(this.f7194b);
        this.f7200h.m3093a();
        m3182a(0);
        ((UpdateManager) ManagerCreator.getManager(UpdateManager.class)).addObserver(32, this.f7202j);
    }
}
