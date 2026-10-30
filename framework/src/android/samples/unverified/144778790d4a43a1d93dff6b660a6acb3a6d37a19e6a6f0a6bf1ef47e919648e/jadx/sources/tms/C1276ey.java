package tms;

import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Environment;
import com.tencent.tmsecure.utils.SDKUtil;
import com.tencent.tmsecure.utils.ScriptHelper;

/* JADX INFO: renamed from: tms.ey */
/* JADX INFO: loaded from: classes.dex */
final class C1276ey {

    /* JADX INFO: renamed from: a */
    private static int f7297a;

    /* JADX INFO: renamed from: b */
    private static int f7298b;

    /* JADX INFO: renamed from: c */
    private static int f7299c;

    /* JADX INFO: renamed from: d */
    private static int f7300d = -1;

    static {
        f7297a = -1;
        f7298b = -1;
        f7299c = -1;
        C1151ah.m2902a("android.content.pm.IPackageManager$Stub");
        f7299c = C1151ah.m2897a("TRANSACTION_getInstallLocation", -1);
        f7298b = C1151ah.m2897a("TRANSACTION_setInstallLocation", -1);
        f7297a = C1151ah.m2897a("TRANSACTION_movePackage", -1);
    }

    /* JADX INFO: renamed from: a */
    private static synchronized int m3277a() {
        String strRunScript;
        int i;
        if (f7300d == -1 && (strRunScript = ScriptHelper.runScript(String.format("service call package %d", Integer.valueOf(f7299c)))) != null) {
            String[] strArrSplit = strRunScript.split("[ ]+");
            if (strArrSplit.length > 3) {
                try {
                    f7300d = Integer.valueOf(strArrSplit[2]).intValue();
                } catch (NumberFormatException e) {
                    f7300d = 0;
                }
            }
        }
        i = f7300d;
        return i;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m3278a(ApplicationInfo applicationInfo) {
        return (applicationInfo.flags & 262144) != 0;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m3279a(PackageInfo packageInfo) {
        if (SDKUtil.getSDKVersion() < 14 || !m3282b()) {
            return m3278a(packageInfo.applicationInfo);
        }
        return false;
    }

    /* JADX WARN: Code duplicated, block: B:34:0x005e  */
    /* JADX INFO: renamed from: a */
    public static boolean m3280a(PackageInfo packageInfo, boolean z) {
        int iM2896a;
        boolean z2 = true;
        if (SDKUtil.getSDKVersion() >= 14 && m3282b()) {
            return false;
        }
        if (m3278a(packageInfo.applicationInfo)) {
            z2 = false;
        } else {
            if ((packageInfo.applicationInfo.flags & 1) != 0) {
                z2 = false;
            } else {
                if (((packageInfo.applicationInfo.flags & 536870912) != 0) || ((iM2896a = C1151ah.m2896a(packageInfo, "installLocation", 1)) != 2 && iM2896a != 0 && ((iM2896a != -1 || m3277a() != 2) && !ScriptHelper.providerSupportPmRelative() && !ScriptHelper.isSystemUid() && (!z || ScriptHelper.canRunAtRoot() != 0)))) {
                    z2 = false;
                }
            }
        }
        return z2;
    }

    /* JADX INFO: renamed from: a */
    public static boolean m3281a(String str) throws PackageManager.NameNotFoundException {
        if (ScriptHelper.providerSupportPmRelative()) {
            return ScriptHelper.provider().m3515c(str);
        }
        return ScriptHelper.runScriptIfSystemUidOrAsRoot(String.format("service call package %d s16 %s i32 1", Integer.valueOf(f7297a), str)) == 0;
    }

    /* JADX INFO: renamed from: b */
    private static boolean m3282b() {
        try {
            return ((Boolean) Environment.class.getMethod("isExternalStorageEmulated", new Class[0]).invoke(null, new Object[0])).booleanValue();
        } catch (Exception e) {
            e.printStackTrace();
            return true;
        }
    }

    /* JADX INFO: renamed from: b */
    public static boolean m3283b(String str) throws PackageManager.NameNotFoundException {
        if (ScriptHelper.providerSupportPmRelative()) {
            return ScriptHelper.provider().m3519d(str);
        }
        return ScriptHelper.runScriptIfSystemUidOrAsRoot(String.format("service call package %d s16 %s i32 2", Integer.valueOf(f7297a), str)) == 0;
    }
}
