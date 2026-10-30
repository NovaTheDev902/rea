package tms;

import android.content.Context;
import android.content.pm.PackageManager;
import android.os.IBinder;
import android.os.RemoteException;
import android.text.TextUtils;
import android.util.SparseArray;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.common.TMSApplication;
import com.tencent.tmsecure.module.permission.AbsDummyServiceCallback;
import com.tencent.tmsecure.module.permission.IDummyService;
import com.tencent.tmsecure.module.permission.IDummyServiceCallback;
import com.tencent.tmsecure.module.permission.NativeInterface;
import com.tencent.tmsecure.module.permission.PermissionControlConfig;
import com.tencent.tmsecure.module.permission.PermissionManager;
import com.tencent.tmsecure.module.permission.PermissionRequestIDs;
import com.tencent.tmsecure.module.permission.PermissionTableItem;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: renamed from: tms.es */
/* JADX INFO: loaded from: classes.dex */
public final class C1270es extends BaseManager {

    /* JADX INFO: renamed from: a */
    static final /* synthetic */ boolean f7275a;

    /* JADX INFO: renamed from: b */
    private static final SparseArray<String> f7276b;

    /* JADX INFO: renamed from: c */
    private boolean f7277c;

    /* JADX INFO: renamed from: d */
    private boolean f7278d;

    /* JADX INFO: renamed from: e */
    private Context f7279e;

    /* JADX INFO: renamed from: f */
    private HashMap<Integer, IDummyService> f7280f;

    /* JADX INFO: renamed from: g */
    private PermissionControlConfig f7281g;

    /* JADX INFO: renamed from: h */
    private IDummyServiceCallback f7282h;

    /* JADX INFO: renamed from: tms.es$a */
    interface a {
        /* JADX INFO: renamed from: a */
        void mo3172a() throws RemoteException;

        /* JADX INFO: renamed from: a */
        void mo3173a(IDummyService iDummyService) throws RemoteException;

        /* JADX INFO: renamed from: b */
        void mo3174b() throws RemoteException;
    }

    static {
        f7275a = !C1270es.class.desiredAssertionStatus();
        f7276b = new SparseArray<>();
        f7276b.put(0, "activity");
        f7276b.put(1, "isms");
    }

    /* JADX INFO: renamed from: a */
    private void m3249a(PermissionManager.IInitStepObserver iInitStepObserver) {
        boolean z = System.getProperty("os.name").toLowerCase().contains("linux") && System.getProperty("os.arch").toLowerCase().contains("arm");
        iInitStepObserver.onReached(0, z);
        if (z) {
            boolean z2 = ScriptHelper.canRunAtRoot() == 0;
            iInitStepObserver.onReached(1, z2);
            if (z2) {
                ArrayList arrayList = new ArrayList();
                File file = new File("/data/data.sys.zip");
                String str = this.f7279e.getFilesDir().getParentFile().toString() + File.separator + "lib" + File.separator;
                String str2 = "lib" + TMSApplication.getStrFromEnvMap(TMSApplication.CON_APOLLO_LIBNAME) + ".so";
                File file2 = new File(str + str2);
                if (!file2.exists()) {
                    file2 = new File("/system/lib/" + str2);
                }
                if (!file2.exists()) {
                    iInitStepObserver.onReached(6, false);
                    return;
                }
                ScriptHelper.runScriptAsRoot("mount -o remount rw /data", "chmod 777 /data", "rm /data/data.sys.dex");
                if (!file.exists() || file.length() != file2.length()) {
                    ScriptHelper.runScriptAsRoot("cat " + file2.getAbsolutePath() + " > " + file.getAbsolutePath());
                }
                ScriptHelper.runScriptAsRoot("chmod 777 " + file.getAbsolutePath());
                File file3 = new File(C1336v.m3577a(this.f7279e, "godEX.dat", this.f7279e.getDir(QueryPermissions.PERMISSION, 0).getAbsolutePath()));
                File file4 = new File(C1336v.m3577a(this.f7279e, "aresEX.dat", this.f7279e.getDir(QueryPermissions.PERMISSION, 0).getAbsolutePath()));
                C1336v.m3583a(file3);
                C1336v.m3583a(file4);
                File file5 = new File(C1336v.m3577a(this.f7279e, "godEX.dat", this.f7279e.getDir(QueryPermissions.PERMISSION, 0).getAbsolutePath()));
                File file6 = new File(C1336v.m3577a(this.f7279e, "aresEX.dat", this.f7279e.getDir(QueryPermissions.PERMISSION, 0).getAbsolutePath()));
                if (file5.exists() && file6.exists()) {
                    arrayList.add("chmod 755 " + file5.getAbsolutePath());
                    arrayList.add("chmod 755 " + file6.getAbsolutePath());
                }
                ScriptHelper.runScriptAsRoot(arrayList);
                int[] iArrM3253a = m3253a("com.android.phone", "system_server");
                if (iArrM3253a.length > 1) {
                    int i = iArrM3253a[0];
                    int i2 = iArrM3253a[1];
                    String absolutePath = file5.getAbsolutePath();
                    String absolutePath2 = file6.getAbsolutePath();
                    String strValueOf = String.valueOf(NativeInterface.dlopenAddr());
                    String strValueOf2 = String.valueOf(NativeInterface.dlsymAddr());
                    int i3 = TrafficStatsService.ANDROID_PHONE_UID;
                    try {
                        i3 = TMSApplication.getApplicaionContext().getPackageManager().getApplicationInfo("com.android.phone", 0).uid;
                    } catch (PackageManager.NameNotFoundException e) {
                        e.printStackTrace();
                    }
                    String str3 = i3 + "." + i3;
                    arrayList.clear();
                    if (C1336v.m3605h("/data/data/com.android.phone/permission")) {
                        arrayList.add("chmod 777 /data/data/com.android.phone/permission");
                        arrayList.add("chown " + str3 + " /data/data/com.android.phone/permission");
                    } else {
                        arrayList.add("mkdir /data/data/com.android.phone/permission");
                        arrayList.add("chmod 777 /data/data/com.android.phone/permission");
                        arrayList.add("chown " + str3 + " /data/data/com.android.phone/permission");
                    }
                    ScriptHelper.runScriptAsRoot(arrayList);
                    ScriptHelper.runScriptAsRoot(String.format("%s %d %s hook 100 %s %s %s", absolutePath, Integer.valueOf(i), absolutePath2, "/data/data/com.android.phone/permission", strValueOf, strValueOf2));
                    ScriptHelper.runScriptAsRoot(String.format("%s %d %s hook 100 %s %s %s", absolutePath, Integer.valueOf(i2), absolutePath2, "/data", strValueOf, strValueOf2));
                }
                boolean z3 = false;
                int i4 = 5;
                while (i4 >= 0) {
                    i4--;
                    z3 = m3257f() == 7777;
                    if (z3) {
                        break;
                    }
                    Thread.currentThread();
                    try {
                        Thread.sleep(1500L);
                    } catch (InterruptedException e2) {
                        e2.printStackTrace();
                    }
                }
                if (!z3) {
                    iInitStepObserver.onReached(4, false);
                } else {
                    this.f7280f = m3256e();
                    iInitStepObserver.onReached(4, true);
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private final void m3250a(a aVar) {
        if (this.f7278d) {
            try {
                aVar.mo3172a();
                synchronized (C1270es.class) {
                    Iterator<IDummyService> it = this.f7280f.values().iterator();
                    while (it.hasNext()) {
                        aVar.mo3173a(it.next());
                    }
                }
                aVar.mo3174b();
            } catch (RemoteException e) {
                e.printStackTrace();
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public static final int[] m3252a(List<String> list) {
        int[] iArr = new int[PermissionRequestIDs.getCount()];
        for (int i = 0; i < iArr.length; i++) {
            iArr[i] = 65535;
        }
        if (list.contains("android.permission.CALL_PHONE") || list.contains("android.permission.CALL_PRIVILEGED")) {
            iArr[0] = 2;
        }
        if (list.contains("android.permission.SEND_SMS")) {
            iArr[1] = 2;
        }
        if (list.contains("android.permission.READ_CONTACTS") || list.contains("android.permission.WRITE_CONTACTS")) {
            iArr[2] = 2;
            iArr[3] = 2;
        }
        if (list.contains("android.permission.READ_SMS") || list.contains("android.permission.WRITE_SMS")) {
            iArr[4] = 2;
        }
        if (list.contains("android.permission.READ_PHONE_STATE")) {
            iArr[6] = 0;
            iArr[7] = 0;
            iArr[8] = 0;
        }
        if (list.contains("android.permission.INTERNET")) {
            iArr[9] = 0;
        }
        if (list.contains("android.permission.ACCESS_FINE_LOCATION")) {
            iArr[12] = 2;
        }
        if (list.contains("android.permission.RECORD_AUDIO") && list.contains("android.permission.READ_PHONE_STATE")) {
            iArr[13] = 2;
        }
        iArr[14] = 2;
        return iArr;
    }

    /* JADX INFO: renamed from: a */
    public static int[] m3253a(String... strArr) {
        int i = -1;
        int[] iArr = new int[strArr.length];
        for (int i2 = 0; i2 < iArr.length; i2++) {
            iArr[i2] = -1;
        }
        StringBuilder sb = new StringBuilder();
        ArrayList arrayList = new ArrayList();
        arrayList.add("ps");
        ScriptHelper.runScript(sb, arrayList);
        String[] strArrSplit = sb.toString().split("\n");
        if (strArrSplit.length > 0) {
            int i3 = 0;
            int i4 = -1;
            while (true) {
                if (i3 >= strArrSplit.length) {
                    i = i4;
                    break;
                }
                if (!TextUtils.isEmpty(strArrSplit[i3].trim()) && strArrSplit[i3].toLowerCase().contains("pid")) {
                    String[] strArrSplit2 = strArrSplit[i3].trim().split("[\\s ]+");
                    for (int i5 = 0; i5 < strArrSplit2.length; i5++) {
                        if (strArrSplit2[i5].equalsIgnoreCase("pid")) {
                            i4 = i5;
                            break;
                        }
                    }
                    if (i4 != -1) {
                        i = i4;
                        break;
                    }
                }
                i3++;
            }
        }
        if (i >= 0) {
            for (int i6 = 1; i6 < strArrSplit.length; i6++) {
                String strTrim = strArrSplit[i6].trim();
                for (int i7 = 0; i7 < strArr.length; i7++) {
                    if (strTrim.contains(strArr[i7])) {
                        iArr[i7] = Integer.parseInt(strTrim.split("[\\s ]+")[i]);
                        break;
                    }
                }
            }
        }
        return iArr;
    }

    /* JADX INFO: renamed from: a */
    public static Object[] m3254a(int i) {
        return null;
    }

    /* JADX INFO: renamed from: e */
    private static HashMap<Integer, IDummyService> m3256e() {
        HashMap<Integer, IDummyService> map = new HashMap<>();
        int size = f7276b.size();
        for (int i = 0; i < size; i++) {
            int iKeyAt = f7276b.keyAt(i);
            String strValueAt = f7276b.valueAt(i);
            IBinder iBinderM2904a = C1152ai.m2904a(strValueAt);
            while (iBinderM2904a == null) {
                Thread.currentThread();
                try {
                    Thread.sleep(500L);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                iBinderM2904a = C1152ai.m2904a(strValueAt);
            }
            map.put(Integer.valueOf(iKeyAt), IDummyService.Proxy.asInterface(iBinderM2904a));
        }
        return map;
    }

    /* JADX INFO: renamed from: f */
    private int m3257f() {
        Iterator<IDummyService> it = m3256e().values().iterator();
        while (it.hasNext()) {
            int iPingDummyService = it.next().pingDummyService(8, this.f7279e.getPackageName());
            if (iPingDummyService != 7777) {
                return iPingDummyService;
            }
        }
        return IDummyService.f6146k;
    }

    /* JADX INFO: renamed from: a */
    public final PermissionControlConfig m3258a() {
        return this.f7281g;
    }

    /* JADX INFO: renamed from: a */
    public final void m3259a(int i, int i2, int i3) {
        m3250a(new C1245du(this, i, i2, i3));
    }

    /* JADX INFO: renamed from: a */
    public final void m3260a(AbsDummyServiceCallback absDummyServiceCallback) {
        m3250a(new C1241dq(this, absDummyServiceCallback));
    }

    /* JADX INFO: renamed from: a */
    public final synchronized void m3261a(PermissionManager.IInitStepObserver iInitStepObserver, PermissionControlConfig permissionControlConfig) {
        if (!f7275a && (iInitStepObserver == null || permissionControlConfig == null)) {
            throw new AssertionError();
        }
        if (!this.f7278d) {
            this.f7280f = null;
            switch (m3257f()) {
                case IDummyService.f6149n /* 1111 */:
                    iInitStepObserver.onReached(3, true);
                    break;
                case IDummyService.f6146k /* 7777 */:
                    this.f7280f = m3256e();
                    break;
                case IDummyService.f6147l /* 8888 */:
                case IDummyService.f6148m /* 9999 */:
                    if (iInitStepObserver.onReached(2, false)) {
                        ScriptHelper.runScriptAsRoot("reboot");
                        ScriptHelper.runScript("kill -9 " + m3253a("/system/bin/servicemanager")[0]);
                    }
                    break;
                default:
                    m3249a(iInitStepObserver);
                    break;
            }
            if (this.f7280f == null || this.f7280f.values().size() <= 0) {
                iInitStepObserver.onReached(6, false);
            } else {
                this.f7281g = permissionControlConfig;
                try {
                    for (IDummyService iDummyService : this.f7280f.values()) {
                        iDummyService.setPermissionTable(this.f7281g);
                        iDummyService.setEnable(true);
                    }
                } catch (RemoteException e) {
                    e.printStackTrace();
                }
                iInitStepObserver.onReached(6, true);
                this.f7278d = true;
                this.f7277c = true;
            }
        }
    }

    /* JADX INFO: renamed from: a */
    public final void m3262a(PermissionTableItem permissionTableItem) {
        m3250a(new C1242dr(this, permissionTableItem));
    }

    /* JADX INFO: renamed from: a */
    public final synchronized void m3263a(boolean z) {
        if (this.f7277c != z) {
            m3250a(new C1249dy(this, z));
        }
    }

    /* JADX INFO: renamed from: b */
    public final void m3264b(PermissionTableItem permissionTableItem) {
        m3250a(new C1243ds(this, permissionTableItem));
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3265b() {
        return this.f7278d && this.f7277c;
    }

    /* JADX INFO: renamed from: c */
    public final void m3266c(PermissionTableItem permissionTableItem) {
        m3250a(new C1248dx(this, permissionTableItem));
    }

    /* JADX INFO: renamed from: c */
    public final boolean m3267c() {
        return this.f7278d;
    }

    /* JADX INFO: renamed from: d */
    public final boolean m3268d() {
        return (System.getProperty("os.name").toLowerCase().contains("linux") && System.getProperty("os.arch").toLowerCase().contains("arm")) && ScriptHelper.canRunAtRoot() == 0;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 1;
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7279e = context;
    }
}
