package tms;

import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PermissionInfo;
import android.content.pm.ResolveInfo;
import android.content.pm.ServiceInfo;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import com.tencent.tmsecure.common.ISDKClient;
import com.tencent.tmsecure.common.SDKClient;
import com.tencent.tmsecure.common.TMSApplication;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.ConcurrentHashMap;

/* JADX INFO: renamed from: tms.w */
/* JADX INFO: loaded from: classes.dex */
final class C1337w {

    /* JADX INFO: renamed from: a */
    private static volatile C1337w f7479a;

    /* JADX INFO: renamed from: d */
    private Context f7482d;

    /* JADX INFO: renamed from: e */
    private Looper f7483e;

    /* JADX INFO: renamed from: f */
    private Handler f7484f;

    /* JADX INFO: renamed from: b */
    private ArrayList<String> f7480b = new ArrayList<>();

    /* JADX INFO: renamed from: c */
    private ConcurrentHashMap<String, ISDKClient> f7481c = new ConcurrentHashMap<>();

    /* JADX INFO: renamed from: g */
    private boolean f7485g = m3613d();

    /* JADX INFO: renamed from: tms.w$a */
    static abstract class a implements ServiceConnection {

        /* JADX INFO: renamed from: a */
        protected ServiceInfo f7486a;

        /* JADX INFO: renamed from: b */
        protected ISDKClient f7487b;

        public a(ServiceInfo serviceInfo) {
            this.f7486a = serviceInfo;
        }
    }

    private C1337w(Context context) {
        this.f7482d = context;
        if (this.f7485g) {
            HandlerThread handlerThread = new HandlerThread(C1337w.class.getName());
            handlerThread.start();
            this.f7483e = handlerThread.getLooper();
            this.f7484f = new Handler(this.f7483e);
        }
    }

    /* JADX INFO: renamed from: a */
    public static C1337w m3609a() {
        if (f7479a == null) {
            synchronized (C1337w.class) {
                if (f7479a == null) {
                    f7479a = new C1337w(TMSApplication.getApplicaionContext());
                }
            }
        }
        return f7479a;
    }

    /* JADX INFO: renamed from: a */
    private boolean m3610a(ServiceInfo serviceInfo) {
        return (serviceInfo == null || this.f7480b.contains(serviceInfo.packageName) || serviceInfo.permission == null || !serviceInfo.permission.equals("com.tencent.tmsecure.permission.RECEIVE_SMS") || !serviceInfo.exported) ? false : true;
    }

    /* JADX INFO: renamed from: b */
    private ISDKClient m3612b(ServiceInfo serviceInfo) {
        ISDKClient iSDKClient = this.f7481c.get(serviceInfo.packageName);
        if (iSDKClient != null) {
            return iSDKClient;
        }
        Intent intent = new Intent();
        intent.setClassName(serviceInfo.packageName, serviceInfo.name);
        Object obj = new Object();
        Context context = this.f7482d;
        C1145ab c1145ab = new C1145ab(this, serviceInfo, obj);
        this.f7484f.post(new RunnableC1146ac(this, intent, c1145ab));
        synchronized (obj) {
            try {
                obj.wait(5000L);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return c1145ab.f7487b;
    }

    /* JADX INFO: renamed from: d */
    private boolean m3613d() {
        boolean z;
        boolean z2;
        boolean z3 = true;
        try {
            PackageInfo packageInfo = this.f7482d.getPackageManager().getPackageInfo(this.f7482d.getPackageName(), 4100);
            String[] strArr = packageInfo.requestedPermissions;
            if (strArr == null) {
                z = false;
                break;
            }
            int length = strArr.length;
            int i = 0;
            while (true) {
                if (i >= length) {
                    z = false;
                    break;
                }
                if (strArr[i].equals("com.tencent.tmsecure.permission.RECEIVE_SMS")) {
                    z = true;
                    break;
                }
                i++;
            }
            PermissionInfo[] permissionInfoArr = packageInfo.permissions;
            if (permissionInfoArr == null) {
                z2 = false;
                break;
            }
            int length2 = permissionInfoArr.length;
            int i2 = 0;
            while (true) {
                if (i2 >= length2) {
                    z2 = false;
                    break;
                }
                if (permissionInfoArr[i2].name.equals("com.tencent.tmsecure.permission.RECEIVE_SMS")) {
                    z2 = true;
                    break;
                }
                i2++;
            }
            if (packageInfo.services != null) {
                for (ServiceInfo serviceInfo : packageInfo.services) {
                    String str = serviceInfo.permission;
                    if (str == null || !str.equals("com.tencent.tmsecure.permission.RECEIVE_SMS") || !serviceInfo.exported) {
                    }
                }
                z3 = false;
            } else {
                z3 = false;
            }
            return z & z2 & z3;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3614a(String str) {
        if (this.f7480b.contains(str)) {
            return;
        }
        this.f7480b.add(str);
    }

    /* JADX INFO: renamed from: b */
    public final ArrayList<ISDKClient> m3615b() {
        ArrayList<ISDKClient> arrayList = new ArrayList<>();
        if (this.f7485g) {
            List<ResolveInfo> listQueryIntentServices = this.f7482d.getPackageManager().queryIntentServices(new Intent("com.tencent.tmsecure.action.SMS_RECEIVED"), 0);
            ArrayList arrayList2 = new ArrayList();
            Iterator<ResolveInfo> it = listQueryIntentServices.iterator();
            while (it.hasNext()) {
                ServiceInfo serviceInfo = it.next().serviceInfo;
                String str = serviceInfo.packageName;
                if (!arrayList2.contains(str) && m3610a(serviceInfo)) {
                    ISDKClient sDKClient = str.equals(this.f7482d.getPackageName()) ? SDKClient.getInstance() : m3612b(serviceInfo);
                    if (sDKClient != null) {
                        arrayList.add(sDKClient);
                    }
                }
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: b */
    public final void m3616b(String str) {
        if (this.f7480b.contains(str)) {
            this.f7480b.remove(str);
        }
    }

    /* JADX INFO: renamed from: c */
    public final int m3617c() {
        int i = 0;
        if (!this.f7485g) {
            return 1;
        }
        Iterator<ResolveInfo> it = this.f7482d.getPackageManager().queryIntentServices(new Intent("com.tencent.tmsecure.action.SMS_RECEIVED"), 0).iterator();
        while (true) {
            int i2 = i;
            if (!it.hasNext()) {
                return i2;
            }
            i = m3610a(it.next().serviceInfo) ? i2 + 1 : i2;
        }
    }
}
