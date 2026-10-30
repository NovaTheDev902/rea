package tms;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.net.Uri;
import android.os.Build;
import android.os.Environment;
import android.util.DisplayMetrics;
import com.tencent.tmsecure.common.BaseManager;
import com.tencent.tmsecure.module.software.AppEntity;
import com.tencent.tmsecure.module.software.SoftwareUseageInfo;
import com.tencent.tmsecure.utils.Log;
import com.tencent.tmsecure.utils.Logcat;
import com.tencent.tmsecure.utils.ScriptHelper;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.security.cert.Certificate;
import java.security.cert.CertificateEncodingException;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/* JADX INFO: renamed from: tms.gl */
/* JADX INFO: loaded from: classes.dex */
public final class C1307gl extends BaseManager {

    /* JADX INFO: renamed from: c */
    private SharedPreferences.Editor f7398c;

    /* JADX INFO: renamed from: d */
    private SharedPreferences f7399d;

    /* JADX INFO: renamed from: e */
    private C1280fb f7400e;

    /* JADX INFO: renamed from: a */
    private PackageManager f7396a = null;

    /* JADX INFO: renamed from: b */
    private Context f7397b = null;

    /* JADX INFO: renamed from: f */
    private CertificateFactory f7401f = null;

    /* JADX INFO: renamed from: a */
    private static int m3388a(int i) {
        int i2 = (i & 16) != 0 ? 64 : 0;
        return (i & 32) != 0 ? i2 | 4096 : i2;
    }

    /* JADX INFO: renamed from: a */
    private Certificate m3389a(Signature signature) {
        X509Certificate x509Certificate;
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(signature.toByteArray());
        try {
            try {
                x509Certificate = (X509Certificate) this.f7401f.generateCertificate(byteArrayInputStream);
                try {
                    byteArrayInputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } catch (Throwable th) {
                try {
                    byteArrayInputStream.close();
                } catch (IOException e2) {
                    e2.printStackTrace();
                }
                throw th;
            }
        } catch (CertificateException e3) {
            e3.printStackTrace();
            try {
                byteArrayInputStream.close();
            } catch (IOException e4) {
                e4.printStackTrace();
            }
            x509Certificate = null;
        } catch (Exception e5) {
            e5.printStackTrace();
            try {
                byteArrayInputStream.close();
            } catch (IOException e6) {
                e6.printStackTrace();
            }
            x509Certificate = null;
        }
        return x509Certificate;
    }

    /* JADX INFO: renamed from: a */
    private void m3390a(PackageInfo packageInfo, AppEntity appEntity, int i) {
        X509Certificate x509Certificate;
        String strM2878c;
        if (packageInfo == null || appEntity == null) {
            return;
        }
        if ((i & 1) != 0) {
            appEntity.put("pkgName", packageInfo.applicationInfo.packageName);
            appEntity.put("appName", packageInfo.applicationInfo.loadLabel(this.f7396a));
            appEntity.put(AppEntity.KEY_IS_SYSTEM_BOOL, Boolean.valueOf((packageInfo.applicationInfo.flags & 1) != 0));
        }
        if ((i & 2) != 0) {
            appEntity.put("pkgName", packageInfo.applicationInfo.packageName);
            appEntity.put(AppEntity.KEY_IS_SYSTEM_BOOL, Boolean.valueOf((packageInfo.applicationInfo.flags & 1) != 0));
        }
        if ((i & 4) != 0) {
            appEntity.put(AppEntity.KEY_ICON_DRAWABLE, packageInfo.applicationInfo.loadIcon(this.f7396a));
        }
        if ((i & 8) != 0) {
            appEntity.put("version", packageInfo.versionName);
            appEntity.put(AppEntity.KEY_VERSION_CODE_INT, Integer.valueOf(packageInfo.versionCode));
            File file = new File(packageInfo.applicationInfo.sourceDir);
            appEntity.put(AppEntity.KEY_SIZE_LONG, Long.valueOf(file.length()));
            appEntity.put(AppEntity.KEY_LAST_MODIFIED_LONG, Long.valueOf(file.lastModified()));
        }
        if ((i & 16) != 0 && packageInfo != null && packageInfo.signatures != null && packageInfo.signatures.length >= 1 && (x509Certificate = (X509Certificate) m3389a(packageInfo.signatures[0])) != null) {
            try {
                strM2878c = C1148ae.m2878c(x509Certificate.getEncoded());
            } catch (CertificateEncodingException e) {
                e.printStackTrace();
                strM2878c = null;
            }
            appEntity.put(AppEntity.KEY_SIGNATURE_MD5_STR, strM2878c);
        }
        if ((i & 32) != 0) {
            appEntity.put(AppEntity.KEY_PERMISSION_STR_ARRAY, packageInfo.requestedPermissions);
        }
        if ((i & 64) != 0) {
            appEntity.put(AppEntity.KEY_APK_PATH_STR, packageInfo.applicationInfo.sourceDir);
            appEntity.put(AppEntity.KEY_IS_APK_BOOL, false);
        }
    }

    /* JADX INFO: renamed from: b */
    private ArrayList<AppEntity> m3391b(File file, String[] strArr, boolean z, int i, boolean z2) {
        AppEntity appEntity;
        if (file == null) {
            return new ArrayList<>();
        }
        ArrayList arrayList = new ArrayList();
        if (strArr != null) {
            for (String str : strArr) {
                arrayList.add(str);
            }
        }
        List<String> listM3582a = C1336v.m3582a(file, arrayList, z2);
        if (listM3582a == null) {
            return new ArrayList<>();
        }
        ArrayList<AppEntity> arrayList2 = new ArrayList<>();
        for (String str2 : listM3582a) {
            if (str2 != null && !str2.equals("")) {
                AppEntity appEntityM3412c = m3412c(str2, i);
                if (appEntityM3412c == null && z) {
                    AppEntity appEntity2 = new AppEntity();
                    File file2 = new File(str2);
                    String name = file2.getName();
                    if (name != null && !name.equals("")) {
                        name = name.substring(0, name.length() - 4);
                    }
                    appEntity2.put("appName", name);
                    appEntity2.put(AppEntity.KEY_SIZE_LONG, Long.valueOf(file2.length()));
                    appEntity2.put(AppEntity.KEY_APK_PATH_STR, str2);
                    appEntity2.put(AppEntity.KEY_IS_APK_BOOL, true);
                    appEntity = appEntity2;
                } else {
                    appEntity = appEntityM3412c;
                }
                if (appEntity != null) {
                    arrayList2.add(appEntity);
                }
            }
        }
        return arrayList2;
    }

    /* JADX INFO: renamed from: d */
    private PackageInfo m3392d(String str, int i) {
        try {
            return this.f7396a.getPackageInfo(str, i);
        } catch (PackageManager.NameNotFoundException e) {
            Log.m2634e("SoftwareManagerImpl", str + " can't be found");
            return null;
        }
    }

    /* JADX INFO: renamed from: k */
    private static Date m3393k(String str) {
        Date date = new Date();
        try {
            String[] strArrSplit = str.split("[- :.]");
            int iIntValue = Integer.valueOf(strArrSplit[0]).intValue() - 1;
            int iIntValue2 = Integer.valueOf(strArrSplit[1]).intValue();
            int iIntValue3 = Integer.valueOf(strArrSplit[2]).intValue();
            int iIntValue4 = Integer.valueOf(strArrSplit[3]).intValue();
            int iIntValue5 = Integer.valueOf(strArrSplit[4]).intValue();
            date.setMonth(iIntValue);
            date.setDate(iIntValue2);
            date.setHours(iIntValue3);
            date.setMinutes(iIntValue4);
            date.setSeconds(iIntValue5);
            return date;
        } catch (NumberFormatException e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    public final int m3394a(String str, int i) {
        PackageInfo packageInfoM3392d = m3392d(str, 0);
        if (packageInfoM3392d == null) {
            return -1;
        }
        if (i == packageInfoM3392d.versionCode) {
            return 0;
        }
        if (i < packageInfoM3392d.versionCode) {
            return i == 0 ? -2 : 2;
        }
        return 1;
    }

    /* JADX INFO: renamed from: a */
    public final AppEntity m3395a(AppEntity appEntity, int i) {
        PackageInfo packageInfoM3392d = m3392d((String) appEntity.get("pkgName"), m3388a(i));
        if (packageInfoM3392d == null) {
            return null;
        }
        m3390a(packageInfoM3392d, appEntity, i);
        return appEntity;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<AppEntity> m3396a(int i, int i2) {
        List<PackageInfo> installedPackages = this.f7396a.getInstalledPackages(m3388a(i));
        ArrayList<AppEntity> arrayList = new ArrayList<>();
        for (PackageInfo packageInfo : installedPackages) {
            boolean z = (packageInfo.applicationInfo.flags & 1) != 0;
            String str = packageInfo.applicationInfo.packageName;
            if (z || i2 != 1) {
                if (!z || i2 != 0) {
                    if (!str.equals(this.f7397b.getPackageName())) {
                        AppEntity appEntity = new AppEntity();
                        m3390a(packageInfo, appEntity, i);
                        arrayList.add(appEntity);
                    }
                }
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<AppEntity> m3397a(int i, int i2, boolean z) {
        List<PackageInfo> installedPackages = this.f7396a.getInstalledPackages(m3388a(i));
        ArrayList<AppEntity> arrayList = new ArrayList<>();
        for (PackageInfo packageInfo : installedPackages) {
            if ((i2 & 1) != 0 && C1276ey.m3280a(packageInfo, z)) {
                AppEntity appEntity = new AppEntity();
                m3390a(packageInfo, appEntity, i);
                arrayList.add(appEntity);
            }
            if ((i2 & 2) != 0 && C1276ey.m3279a(packageInfo)) {
                AppEntity appEntity2 = new AppEntity();
                m3390a(packageInfo, appEntity2, i);
                arrayList.add(appEntity2);
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<AppEntity> m3398a(File file, String[] strArr, boolean z, int i) {
        return m3391b(file, strArr, z, i, true);
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<AppEntity> m3399a(File file, String[] strArr, boolean z, int i, boolean z2) {
        return m3391b(file, strArr, z, i, z2);
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<SoftwareUseageInfo> m3400a(List<String> list) {
        ArrayList<SoftwareUseageInfo> arrayList = new ArrayList<>();
        Iterator<String> it = list.iterator();
        while (it.hasNext()) {
            SoftwareUseageInfo softwareUseageInfoM3419i = m3419i(it.next());
            if (softwareUseageInfoM3419i != null) {
                arrayList.add(softwareUseageInfoM3419i);
            }
        }
        return arrayList;
    }

    /* JADX INFO: renamed from: a */
    public final ArrayList<AppEntity> m3401a(String[] strArr, boolean z, int i) {
        ArrayList<AppEntity> arrayList = new ArrayList<>();
        File externalStorageDirectory = Environment.getExternalStorageDirectory();
        return (externalStorageDirectory == null || !externalStorageDirectory.exists()) ? arrayList : m3398a(externalStorageDirectory, strArr, z, i);
    }

    /* JADX INFO: renamed from: a */
    public final void m3402a() {
        this.f7398c.clear();
    }

    /* JADX INFO: renamed from: a */
    public final void m3403a(File file) {
        if (file == null || !file.exists()) {
            throw new RuntimeException("the apkfile dosn't exist.");
        }
        Intent intent = new Intent("android.intent.action.VIEW");
        intent.setFlags(268435456);
        intent.setDataAndType(Uri.fromFile(file), "application/vnd.android.package-archive");
        this.f7397b.startActivity(intent);
    }

    /* JADX INFO: renamed from: a */
    public final void m3404a(String str, Activity activity, int i) {
        Intent intent = new Intent("android.intent.action.VIEW");
        intent.setDataAndType(Uri.fromFile(new File(str)), "application/vnd.android.package-archive");
        if (i >= 0) {
            activity.startActivityForResult(intent, 2);
        } else {
            activity.startActivity(intent);
        }
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3405a(String str) {
        return m3392d(str, 0) != null;
    }

    /* JADX INFO: renamed from: a */
    public final boolean m3406a(String str, boolean z) {
        PackageInfo packageInfoM3392d = m3392d(str, 0);
        if (packageInfoM3392d != null) {
            return C1276ey.m3280a(packageInfoM3392d, z);
        }
        return false;
    }

    /* JADX INFO: renamed from: b */
    public final AppEntity m3407b(AppEntity appEntity, int i) {
        List<Object> listM3525a;
        Signature[] signatureArr;
        X509Certificate x509Certificate;
        Object objM2878c;
        try {
            String str = (String) appEntity.get(AppEntity.KEY_APK_PATH_STR);
            PackageInfo packageArchiveInfo = this.f7396a.getPackageArchiveInfo(str, m3388a(i));
            if (packageArchiveInfo == null) {
                return null;
            }
            if ((i & 4) != 0) {
                listM3525a = C1327m.m3525a(this.f7397b, str, true);
            } else {
                listM3525a = (i & 1) != 0 ? C1327m.m3525a(this.f7397b, str, false) : null;
            }
            if ((i & 1) != 0) {
                appEntity.put("pkgName", packageArchiveInfo.packageName);
                appEntity.put(AppEntity.KEY_IS_SYSTEM_BOOL, new Boolean(false));
                if (listM3525a == null || listM3525a.size() <= 0 || listM3525a.get(0) == null) {
                    appEntity.put("appName", this.f7396a.getApplicationLabel(packageArchiveInfo.applicationInfo));
                } else {
                    appEntity.put("appName", listM3525a.get(0));
                }
            }
            if ((i & 2) != 0) {
                appEntity.put("pkgName", packageArchiveInfo.packageName);
                appEntity.put(AppEntity.KEY_IS_SYSTEM_BOOL, new Boolean(false));
            }
            if ((i & 4) != 0) {
                if (listM3525a == null || listM3525a.size() <= 1 || listM3525a.get(1) == null) {
                    appEntity.put(AppEntity.KEY_ICON_DRAWABLE, this.f7396a.getApplicationIcon(packageArchiveInfo.applicationInfo));
                } else {
                    appEntity.put(AppEntity.KEY_ICON_DRAWABLE, listM3525a.get(1));
                }
            }
            if ((i & 8) != 0) {
                appEntity.put("version", packageArchiveInfo.versionName);
                appEntity.put(AppEntity.KEY_VERSION_CODE_INT, Integer.valueOf(packageArchiveInfo.versionCode));
                File file = new File(str);
                appEntity.put(AppEntity.KEY_SIZE_LONG, Long.valueOf(file.length()));
                appEntity.put(AppEntity.KEY_LAST_MODIFIED_LONG, Long.valueOf(file.lastModified()));
            }
            if ((i & 64) != 0) {
                appEntity.put(AppEntity.KEY_APK_PATH_STR, str);
                appEntity.put(AppEntity.KEY_IS_APK_BOOL, true);
            }
            if ((i & 16) != 0) {
                try {
                    Object objM2901a = C1151ah.m2901a("android.content.pm.PackageParser", new Object[]{str});
                    File file2 = new File(str);
                    DisplayMetrics displayMetrics = new DisplayMetrics();
                    displayMetrics.setToDefaults();
                    Object objM2899a = C1151ah.m2899a(objM2901a, "parsePackage", new Object[]{file2, str, displayMetrics, 0});
                    if (objM2899a != null) {
                        C1151ah.m2899a(objM2901a, "collectCertificates", new Object[]{objM2899a, 0});
                        signatureArr = (Signature[]) C1151ah.m2898a(objM2899a, "mSignatures");
                    } else {
                        signatureArr = null;
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (signatureArr != null && signatureArr.length >= 1 && (x509Certificate = (X509Certificate) m3389a(signatureArr[0])) != null) {
                    try {
                        objM2878c = C1148ae.m2878c(x509Certificate.getEncoded());
                    } catch (CertificateEncodingException e2) {
                        e2.printStackTrace();
                        objM2878c = null;
                    }
                    appEntity.put(AppEntity.KEY_SIGNATURE_MD5_STR, objM2878c);
                }
            }
            if ((i & 32) != 0) {
                appEntity.put(AppEntity.KEY_PERMISSION_STR_ARRAY, packageArchiveInfo.requestedPermissions);
            }
            return appEntity;
        } catch (Exception e3) {
            return null;
        }
    }

    /* JADX INFO: renamed from: b */
    public final AppEntity m3408b(String str, int i) {
        AppEntity appEntity = new AppEntity();
        appEntity.put("pkgName", str);
        return m3395a(appEntity, i);
    }

    /* JADX INFO: renamed from: b */
    public final synchronized void m3409b() {
        ArrayList<String> arrayListFilter = Logcat.filter("ActivityManager", null, "Starting", "START");
        HashMap map = new HashMap();
        for (String str : arrayListFilter) {
            int iIndexOf = str.indexOf("cmp=") + 4;
            int iIndexOf2 = str.indexOf(47, iIndexOf);
            if (m3393k(str.substring(0, 18)) != null) {
                String strSubstring = str.substring(iIndexOf, iIndexOf2);
                if (map.containsKey(strSubstring)) {
                    map.put(strSubstring, Integer.valueOf(((Integer) map.get(strSubstring)).intValue() + 1));
                } else {
                    map.put(strSubstring, 1);
                }
            }
        }
        HashMap map2 = new HashMap();
        for (String str2 : map.keySet()) {
            if (map2.containsKey(str2)) {
                map2.get(str2);
            } else {
                SoftwareUseageInfo softwareUseageInfoM3419i = m3419i(str2);
                if (softwareUseageInfoM3419i == null) {
                    softwareUseageInfoM3419i = new SoftwareUseageInfo(str2, new Date(), new Date(), 1);
                } else {
                    softwareUseageInfoM3419i.mUseCount++;
                }
                map2.put(str2, softwareUseageInfoM3419i);
            }
        }
        for (Map.Entry entry : map2.entrySet()) {
            this.f7398c.putString((String) entry.getKey(), SoftwareUseageInfo.getString((SoftwareUseageInfo) entry.getValue()));
        }
        this.f7398c.commit();
        Logcat.clear();
    }

    /* JADX INFO: renamed from: b */
    public final void m3410b(String str, Activity activity, int i) {
        Intent intent = new Intent("android.intent.action.DELETE", Uri.parse("package:" + str));
        if (i >= 0) {
            activity.startActivityForResult(intent, i);
        } else {
            activity.startActivity(intent);
        }
    }

    /* JADX INFO: renamed from: b */
    public final boolean m3411b(String str) {
        if (!C1336v.m3605h(str)) {
            return false;
        }
        if (ScriptHelper.providerSupportPmRelative()) {
            return ScriptHelper.provider().m3521e(str);
        }
        if (ScriptHelper.isSystemUid() || ScriptHelper.canRunAtRoot() == 0) {
            return ScriptHelper.runScriptIfSystemUidOrAsRoot(new StringBuilder().append("pm install -r ").append(str).toString()) == 0;
        }
        return false;
    }

    /* JADX INFO: renamed from: c */
    public final AppEntity m3412c(String str, int i) {
        AppEntity appEntity = new AppEntity();
        appEntity.put(AppEntity.KEY_APK_PATH_STR, str);
        return m3407b(appEntity, i);
    }

    /* JADX INFO: renamed from: c */
    public final boolean m3413c(String str) {
        if (ScriptHelper.providerSupportPmRelative()) {
            return ScriptHelper.provider().m3523f(str);
        }
        if (!ScriptHelper.isSystemUid() && ScriptHelper.canRunAtRoot() != 0) {
            return false;
        }
        if (this.f7400e.m3301a(str)) {
            this.f7400e.m3302b(str);
        }
        return ScriptHelper.runScriptIfSystemUidOrAsRoot(new StringBuilder().append("pm uninstall ").append(str).toString()) == 0;
    }

    /* JADX INFO: renamed from: d */
    public final void m3414d(String str) {
        Intent intent = new Intent();
        int i = Build.VERSION.SDK_INT;
        intent.addFlags(268435456);
        if (i >= 9) {
            try {
                intent.setAction((String) C1151ah.m2900a("android.provider.Settings", "ACTION_APPLICATION_DETAILS_SETTINGS"));
                intent.setData(Uri.fromParts("package", str, null));
            } catch (Exception e) {
                e.printStackTrace();
                return;
            }
        } else {
            intent.setAction("android.intent.action.VIEW");
            intent.setClassName("com.android.settings", "com.android.settings.InstalledAppDetails");
            intent.putExtra("pkg", str);
            intent.putExtra("com.android.settings.ApplicationPkgName", str);
        }
        this.f7397b.startActivity(intent);
    }

    /* JADX INFO: renamed from: e */
    public final boolean m3415e(String str) {
        boolean z = false;
        try {
            Intent launchIntentForPackage = this.f7396a.getLaunchIntentForPackage(str);
            if (launchIntentForPackage != null) {
                launchIntentForPackage.setFlags(270532608);
                this.f7397b.startActivity(launchIntentForPackage);
                z = true;
            } else {
                Log.m2634e("SoftwareManagerImpl", str + " is not a visualble application");
            }
        } catch (Exception e) {
            Log.m2636i("SoftwareManagerImpl", e);
        }
        return z;
    }

    /* JADX INFO: renamed from: f */
    public final boolean m3416f(String str) {
        PackageInfo packageInfoM3392d = m3392d(str, 0);
        if (packageInfoM3392d != null) {
            return C1276ey.m3278a(packageInfoM3392d.applicationInfo);
        }
        return false;
    }

    /* JADX INFO: renamed from: g */
    public final boolean m3417g(String str) throws PackageManager.NameNotFoundException {
        return C1276ey.m3281a(str);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final int getSingletonType() {
        return 2;
    }

    /* JADX INFO: renamed from: h */
    public final boolean m3418h(String str) throws PackageManager.NameNotFoundException {
        return C1276ey.m3283b(str);
    }

    /* JADX INFO: renamed from: i */
    public final SoftwareUseageInfo m3419i(String str) {
        String string = this.f7399d.getString(str, null);
        if (string != null) {
            return SoftwareUseageInfo.fromString(string);
        }
        return null;
    }

    /* JADX INFO: renamed from: j */
    public final boolean m3420j(String str) {
        return this.f7400e.m3301a(str);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f7397b = context;
        this.f7399d = this.f7397b.getSharedPreferences("SoftwareManagerImpl", 0);
        this.f7398c = this.f7399d.edit();
        this.f7400e = new C1280fb();
        this.f7396a = context.getPackageManager();
        try {
            this.f7401f = CertificateFactory.getInstance("X.509");
        } catch (CertificateException e) {
            Log.m2636i("SoftwareManagerImpl", e.getLocalizedMessage());
        }
    }
}
