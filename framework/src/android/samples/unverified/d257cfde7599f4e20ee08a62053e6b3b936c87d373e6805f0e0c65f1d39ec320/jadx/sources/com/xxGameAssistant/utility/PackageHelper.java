package com.xxGameAssistant.utility;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.ComponentName;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import com.tendcloud.tenddata.C0073e;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class PackageHelper {
    Activity mActivity;

    public enum PH_FLAG {
        just_invalid,
        act_is_null,
        app_open_succeed,
        app_not_exist;

        /* JADX INFO: renamed from: values, reason: to resolve conflict with enum method */
        public static PH_FLAG[] valuesCustom() {
            PH_FLAG[] ph_flagArrValuesCustom = values();
            int length = ph_flagArrValuesCustom.length;
            PH_FLAG[] ph_flagArr = new PH_FLAG[length];
            System.arraycopy(ph_flagArrValuesCustom, 0, ph_flagArr, 0, length);
            return ph_flagArr;
        }
    }

    public PackageHelper(Activity activity) {
        this.mActivity = activity;
    }

    public PH_FLAG openApp(String packageName) {
        PH_FLAG ph_flag = PH_FLAG.just_invalid;
        if (this.mActivity == null) {
            PH_FLAG flag = PH_FLAG.act_is_null;
            return flag;
        }
        PackageManager packageManager = this.mActivity.getPackageManager();
        try {
            PackageInfo packageInfo = packageManager.getPackageInfo(packageName, 0);
            Intent resolveIntent = new Intent("android.intent.action.MAIN", (Uri) null);
            resolveIntent.addCategory("android.intent.category.LAUNCHER");
            resolveIntent.setPackage(packageInfo.packageName);
            List<ResolveInfo> apps = packageManager.queryIntentActivities(resolveIntent, 0);
            ResolveInfo reolveInfo = apps.iterator().next();
            if (reolveInfo != null) {
                String newPackageName = reolveInfo.activityInfo.packageName;
                String className = reolveInfo.activityInfo.name;
                Intent intent = new Intent("android.intent.action.MAIN");
                intent.addCategory("android.intent.category.LAUNCHER");
                ComponentName cn = new ComponentName(newPackageName, className);
                intent.setComponent(cn);
                intent.setFlags(268435456);
                this.mActivity.startActivity(intent);
                PH_FLAG flag2 = PH_FLAG.app_open_succeed;
                return flag2;
            }
            PH_FLAG flag3 = PH_FLAG.app_not_exist;
            return flag3;
        } catch (PackageManager.NameNotFoundException e) {
            PH_FLAG flag4 = PH_FLAG.app_not_exist;
            e.printStackTrace();
            return flag4;
        }
    }

    public Boolean isAppRunning(String packageName) throws Exception {
        if (this.mActivity == null) {
            throw new Exception("Activity not set, do init first");
        }
        ActivityManager am = (ActivityManager) this.mActivity.getSystemService(C0073e.f108g);
        List<ActivityManager.RunningAppProcessInfo> procList = am.getRunningAppProcesses();
        for (ActivityManager.RunningAppProcessInfo info : procList) {
            for (String pkgName : info.pkgList) {
                if (pkgName.equals(packageName)) {
                    return true;
                }
            }
        }
        return false;
    }
}
