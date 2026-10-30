package com.lenovo.safecenter.Laboratory;

import android.app.ActivityManager;
import android.content.ActivityNotFoundException;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;
import com.lenovo.performancecenter.service.object.ApplicationDataInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.support.CMDHelper;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import org.apache.commons.httpclient.HttpState;

/* JADX INFO: loaded from: classes.dex */
public class SafeHomePage {
    public static final String SAFE_HOME_PAGE = "http://hao.lenovo.com/?c=360";
    public static final String SAFE_HOME_PAGE_KEY = "safehomepage_on";

    /* JADX INFO: renamed from: a */
    private static SafeHomePage f2629a;

    /* JADX INFO: renamed from: f */
    private static Map<String, String[]> f2632f;

    /* JADX INFO: renamed from: g */
    private static List f2633g;

    /* JADX INFO: renamed from: h */
    private static List<String> f2634h;

    /* JADX INFO: renamed from: b */
    private Context f2635b;

    /* JADX INFO: renamed from: e */
    private ActivityManager f2636e;

    /* JADX INFO: renamed from: c */
    private static BroadcastReceiver f2630c = null;

    /* JADX INFO: renamed from: d */
    private static String f2631d = "SafeHomePage";
    public static boolean open = false;

    public static SafeHomePage getDefault(Context context) {
        if (f2629a == null) {
            f2629a = new SafeHomePage(context);
        }
        return f2629a;
    }

    public void reLoad(String pkg) {
        f2633g.clear();
        PackageManager pm = this.f2635b.getPackageManager();
        Intent it = new Intent("android.intent.action.MAIN");
        it.addCategory("android.intent.category.HOME");
        List<ResolveInfo> resolveList = pm.queryIntentActivities(it, 0);
        Iterator<ResolveInfo> it2 = resolveList.iterator();
        while (it2.hasNext()) {
            f2633g.add(it2.next().activityInfo.packageName);
        }
        Log.i(f2631d, "mDesktops size:" + f2633g.size());
        Intent i = new Intent("android.intent.action.VIEW");
        i.setData(Uri.parse("http://m.idea123.cn"));
        i.setFlags(335544320);
        List<ResolveInfo> r = this.f2635b.getPackageManager().queryIntentActivities(i, 65600);
        for (ResolveInfo resolveInfo : r) {
            if (pkg.equals(resolveInfo.activityInfo.packageName)) {
                f2632f.put(resolveInfo.activityInfo.packageName, new String[]{resolveInfo.activityInfo.name, new ComponentName(resolveInfo.activityInfo.applicationInfo.packageName, resolveInfo.activityInfo.name).flattenToShortString(), HttpState.PREEMPTIVE_DEFAULT});
                Log.i(f2631d, "add new browser:" + pkg);
            }
        }
    }

    private SafeHomePage() {
    }

    private SafeHomePage(Context context) {
        this.f2635b = context;
    }

    public boolean register() {
        try {
            CMDHelper.editHomePage(this.f2635b, true);
            ApplicationDataInfo.clearSeperateCache(this.f2635b, SafeHomePageBroadcast.BROWSER_PKG);
            return true;
        } catch (Exception e) {
            Log.e(f2631d, "register error:" + e);
            return false;
        }
    }

    public boolean unRegister() {
        try {
            CMDHelper.editHomePage(this.f2635b, false);
            return true;
        } catch (Exception e) {
            Log.e(f2631d, "unregister error:" + e);
            return false;
        }
    }

    public Map<String, String[]> getBrowsers() {
        return f2632f;
    }

    public List getmDesktops() {
        return f2633g;
    }

    public List<String> getOpenedBrowsers() {
        return f2634h;
    }

    public void showIndex(String pkg) {
        Log.i(f2631d, "showIndex---------------");
        open = true;
        try {
            Intent i = new Intent("android.intent.action.VIEW");
            i.setFlags(335609856);
            i.setClassName(pkg, f2632f.get(pkg)[0]);
            i.setData(Uri.parse(SAFE_HOME_PAGE));
            Looper.prepare();
            this.f2635b.startActivity(i);
            Toast.makeText(this.f2635b, C0415R.string.safe_homepage, 0).show();
            Looper.loop();
        } catch (ActivityNotFoundException e) {
        } catch (SecurityException e2) {
            String cmd = "am start -a android.intent.action.VIEW -d http://hao.lenovo.com/?c=360 -n " + f2632f.get(pkg)[1] + " -f 0x14000000";
            if (CMDHelper.exeCmd(this.f2635b, cmd)) {
                Looper.prepare();
                Toast.makeText(this.f2635b, C0415R.string.safe_homepage, 0).show();
                Looper.loop();
            }
        }
    }

    public void checkAppRunState(String pkg) {
        try {
            List<ActivityManager.RunningTaskInfo> runningTasks = this.f2636e.getRunningTasks(20);
            for (ActivityManager.RunningTaskInfo runningTaskInfo : runningTasks) {
                if (pkg.equals(runningTaskInfo.topActivity.getPackageName())) {
                    return;
                }
            }
            open = false;
            Log.i(f2631d, "checkAppRunState false---------------");
        } catch (SecurityException e) {
            Log.i(f2631d, "checkAppRunState SecurityException---------------");
        }
    }
}
