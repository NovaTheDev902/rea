package tms;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.IBinder;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.BaseService;
import com.tencent.tmsecure.common.TMSService;
import com.tencent.tmsecure.module.tools.IPackageChangedListener;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: renamed from: tms.gn */
/* JADX INFO: loaded from: classes.dex */
public final class C1309gn extends BaseManager {

    /* JADX INFO: renamed from: a */
    private List<b> f7410a = new ArrayList();

    /* JADX INFO: renamed from: b */
    private Context f7411b;

    /* JADX INFO: renamed from: c */
    private BaseService f7412c;

    /* JADX INFO: renamed from: tms.gn$a */
    interface a {
        /* JADX INFO: renamed from: a */
        void mo3311a(String str);
    }

    /* JADX INFO: renamed from: tms.gn$b */
    static final class b implements IPackageChangedListener {

        /* JADX INFO: renamed from: a */
        private IPackageChangedListener f7413a;

        public b(IPackageChangedListener iPackageChangedListener) {
            this.f7413a = iPackageChangedListener;
        }

        public final boolean equals(Object obj) {
            if (obj == null || !(obj instanceof b)) {
                return false;
            }
            return this.f7413a.getClass().equals(((b) obj).f7413a.getClass());
        }

        @Override // com.tencent.tmsecure.module.tools.IPackageChangedListener
        public final void onPackageAdded(String str) {
            new C1281fc(this, str).start();
        }

        @Override // com.tencent.tmsecure.module.tools.IPackageChangedListener
        public final void onPackageReinstall(String str) {
            new C1283fe(this, str).start();
        }

        @Override // com.tencent.tmsecure.module.tools.IPackageChangedListener
        public final void onPackageRemoved(String str) {
            new C1282fd(this, str).start();
        }
    }

    /* JADX INFO: renamed from: tms.gn$c */
    final class c extends BaseService {

        /* JADX INFO: renamed from: b */
        private d f7415b;

        private c() {
        }

        /* synthetic */ c(C1309gn c1309gn, byte b) {
            this();
        }

        @Override // com.tencent.tmsecure.common.BaseService
        public final IBinder onBind() {
            return null;
        }

        @Override // com.tencent.tmsecure.common.BaseService
        public final void onCreate(Context context) {
            super.onCreate(context);
            this.f7415b = new d(C1309gn.this, (byte) 0);
            this.f7415b.m3433a();
        }

        @Override // com.tencent.tmsecure.common.BaseService
        public final void onDestory() {
            this.f7415b.m3434b();
            super.onDestory();
        }
    }

    /* JADX INFO: renamed from: tms.gn$d */
    final class d extends BroadcastReceiver {

        /* JADX INFO: renamed from: b */
        private a f7417b;

        /* JADX INFO: renamed from: c */
        private a f7418c;

        /* JADX INFO: renamed from: d */
        private a f7419d;

        private d() {
            this.f7417b = new C1285fg(this);
            this.f7418c = new C1286fh(this);
            this.f7419d = new C1290fl(this);
        }

        /* synthetic */ d(C1309gn c1309gn, byte b) {
            this();
        }

        /* JADX INFO: renamed from: a */
        private void m3432a(a aVar, String str) {
            new C1291fm(this, aVar, str).start();
        }

        /* JADX INFO: renamed from: a */
        public final void m3433a() {
            IntentFilter intentFilter = new IntentFilter();
            intentFilter.addAction("android.intent.action.PACKAGE_REPLACED");
            intentFilter.addAction("android.intent.action.PACKAGE_ADDED");
            intentFilter.addAction("android.intent.action.PACKAGE_REMOVED");
            intentFilter.setPriority(Integer.MAX_VALUE);
            intentFilter.addDataScheme("package");
            C1309gn.this.f7411b.registerReceiver(this, intentFilter);
        }

        /* JADX INFO: renamed from: b */
        public final void m3434b() {
            C1309gn.this.f7411b.unregisterReceiver(this);
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            Bundle extras = intent.getExtras();
            byte b = -1;
            if (extras != null && extras.containsKey("android.intent.extra.REPLACING")) {
                b = extras.getBoolean("android.intent.extra.REPLACING") ? (byte) 0 : (byte) 1;
            }
            if (action.equals("android.intent.action.PACKAGE_ADDED") && b != 0) {
                m3432a(this.f7417b, intent.getDataString().substring(8));
                return;
            }
            if (action.equals("android.intent.action.PACKAGE_REMOVED") && b != 0) {
                m3432a(this.f7418c, intent.getDataString().substring(8));
            } else if (action.equals("android.intent.action.PACKAGE_REPLACED")) {
                m3432a(this.f7419d, intent.getDataString().substring(8));
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final IPackageChangedListener m3429a(IPackageChangedListener iPackageChangedListener) {
        synchronized (this.f7410a) {
            b bVar = iPackageChangedListener != null ? new b(iPackageChangedListener) : null;
            if (bVar == null || this.f7410a.contains(bVar)) {
                return null;
            }
            this.f7410a.add(bVar);
            return iPackageChangedListener;
        }
    }

    /* JADX INFO: renamed from: b */
    public final IPackageChangedListener m3430b(IPackageChangedListener iPackageChangedListener) {
        b bVar = new b(iPackageChangedListener);
        synchronized (this.f7410a) {
            if (this.f7410a.contains(bVar)) {
                this.f7410a.remove(bVar);
            } else {
                iPackageChangedListener = null;
            }
        }
        return iPackageChangedListener;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7411b = context;
        this.f7412c = new c(this, (byte) 0);
        TMSService.startService(this.f7412c, null);
    }
}
