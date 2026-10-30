package com.tencent.tmsecure.utils;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Build;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.mmsutils.CharacterSets;
import java.io.File;
import tms.C1149af;
import tms.C1336v;

/* JADX INFO: loaded from: classes.dex */
public class EnvUtil {
    /* JADX INFO: renamed from: a */
    private static String[] m2633a(Context context) {
        String[] strArr = new String[4];
        strArr[0] = Build.MODEL;
        strArr[1] = Build.VERSION.RELEASE;
        String str = "";
        try {
            str = C1336v.m3606i("/proc/cpuinfo").split("\\n")[0];
        } catch (Exception e) {
            e.printStackTrace();
        }
        strArr[2] = str;
        strArr[3] = Integer.toString(PhoneInfoUtil.getScreenWidth(context)) + CharacterSets.MIMENAME_ANY_CHARSET + Integer.toString(PhoneInfoUtil.getScreenHeight(context));
        return strArr;
    }

    public static String getDeviceInfoStr(Context context) {
        String str = new String();
        String[] strArrM2633a = m2633a(context);
        String str2 = (((str + "MODEL " + strArrM2633a[0] + C0092c.f1284O) + "ANDROID " + strArrM2633a[1] + C0092c.f1284O) + "CPU " + strArrM2633a[2] + C0092c.f1284O) + "resolution  " + strArrM2633a[3] + C0092c.f1284O;
        String strM2883a = new C1149af("NetInterfaceManager").m2883a("upload_config_des", (String) null);
        return (strM2883a == null || strM2883a.equals("")) ? str2 : str2 + strM2883a;
    }

    public static boolean hadsufile() {
        return new File("/system/xbin/su").exists() || new File("/system/bin/su").exists();
    }

    public static boolean isBuildIn(Context context) {
        try {
            ApplicationInfo applicationInfo = context.getPackageManager().getApplicationInfo(context.getPackageName(), 8192);
            return (applicationInfo == null || (applicationInfo.flags & 1) == 0) ? false : true;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        } catch (Exception e2) {
            return false;
        }
    }
}
