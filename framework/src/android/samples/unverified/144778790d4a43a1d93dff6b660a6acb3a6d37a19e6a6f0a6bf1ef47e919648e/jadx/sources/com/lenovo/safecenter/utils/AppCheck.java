package com.lenovo.safecenter.utils;

import android.app.ActivityManager;
import android.app.ActivityManagerNative;
import android.app.IActivityManager;
import android.app.IThumbnailReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ResolveInfo;
import android.os.Build;
import android.os.RemoteException;
import android.provider.Settings;
import android.util.Log;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class AppCheck {
    public static final String ACTION_ACTIVITY_SWITCH = "com.lenovo.safecenter.activityswitch";
    public static final String ACTION_ACTIVITY_SWITCH_2 = "com.lenovo.safecenter.activityswitch2";

    /* JADX INFO: renamed from: d */
    private static AppCheck f5697d;

    /* JADX INFO: renamed from: i */
    private static List<String> f5698i;
    public static boolean isRun = true;

    /* JADX INFO: renamed from: b */
    private ActivityManager f5700b;

    /* JADX INFO: renamed from: c */
    private Context f5701c;

    /* JADX INFO: renamed from: e */
    private String f5702e = "";

    /* JADX INFO: renamed from: f */
    private String f5703f = "";

    /* JADX INFO: renamed from: g */
    private String f5704g = "";

    /* JADX INFO: renamed from: h */
    private String f5705h = "";

    /* JADX INFO: renamed from: a */
    private IActivityManager f5699a = ActivityManagerNative.getDefault();

    private AppCheck(Context c) {
        this.f5701c = c;
        this.f5700b = (ActivityManager) c.getSystemService("activity");
    }

    public static AppCheck getDefault(Context c) {
        if (f5697d == null) {
            f5697d = new AppCheck(c);
        }
        if (f5698i == null) {
            f5698i = new ArrayList();
            Intent it = new Intent("android.intent.action.MAIN");
            it.addCategory("android.intent.category.HOME");
            List<ResolveInfo> resolveList = c.getPackageManager().queryIntentActivities(it, 0);
            for (ResolveInfo resolveInfo : resolveList) {
                Log.i("ydp", "mDesktops:  " + resolveInfo.activityInfo.packageName);
                f5698i.add(resolveInfo.activityInfo.packageName);
            }
        }
        return f5697d;
    }

    public void execute() {
        isRun = true;
        new C1018a().start();
    }

    public void cancel() {
        isRun = false;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.utils.AppCheck$a */
    class C1018a extends Thread {
        C1018a() {
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public final void run() {
            if (Build.VERSION.SDK_INT < 14) {
                Log.i("AppCheck", "doInBackground-->  <14");
                while (AppCheck.isRun) {
                    try {
                        Thread.sleep(1000L);
                        List<ActivityManager.RunningTaskInfo> rti = AppCheck.this.f5699a.getTasks(1, 0, (IThumbnailReceiver) null);
                        if (rti.size() > 0) {
                            AppCheck.this.f5705h = rti.get(0).topActivity.getPackageName();
                            if (!AppCheck.this.f5703f.equals(AppCheck.this.f5705h)) {
                                m2360a("runningTask", AppCheck.this.f5705h, AppCheck.this.f5703f);
                                m2360a("recentTask", AppCheck.this.f5705h, AppCheck.this.f5703f);
                                AppCheck.this.f5703f = AppCheck.this.f5705h;
                            }
                        }
                    } catch (RemoteException e) {
                        e.printStackTrace();
                    } catch (InterruptedException e2) {
                        e2.printStackTrace();
                    } catch (SecurityException e3) {
                        Log.i("AppCheck", "doInBackground error:" + e3);
                    }
                }
                return;
            }
            Log.i("AppCheck", "doInBackground-->  >14");
            while (AppCheck.isRun) {
                try {
                    Thread.sleep(1000L);
                    List<ActivityManager.RunningTaskInfo> rti2 = AppCheck.this.f5699a.getTasks(1, 0, (IThumbnailReceiver) null);
                    if (rti2.size() > 0) {
                        AppCheck.this.f5705h = rti2.get(0).topActivity.getPackageName();
                        if (!AppCheck.this.f5703f.equals(AppCheck.this.f5705h)) {
                            Log.i("AppCheck", "old" + AppCheck.this.f5703f + "------------new:" + AppCheck.this.f5705h);
                            m2360a("runningTask", AppCheck.this.f5705h, AppCheck.this.f5703f);
                            AppCheck.this.f5703f = AppCheck.this.f5705h;
                        }
                    }
                    List<ActivityManager.RecentTaskInfo> recentTasks = AppCheck.this.f5700b.getRecentTasks(1, 1);
                    if (recentTasks != null && recentTasks.size() > 0) {
                        AppCheck.this.f5702e = recentTasks.get(0).baseIntent.getComponent().getPackageName();
                        if (!AppCheck.this.f5704g.equals(AppCheck.this.f5702e)) {
                            m2360a("recentTask", AppCheck.this.f5702e, AppCheck.this.f5704g);
                            AppCheck.this.f5704g = AppCheck.this.f5702e;
                        }
                    }
                } catch (RemoteException e4) {
                    e4.printStackTrace();
                } catch (InterruptedException e5) {
                    e5.printStackTrace();
                } catch (SecurityException e6) {
                    Log.i("AppCheck", "doInBackground error:" + e6);
                }
            }
        }

        /* JADX INFO: renamed from: a */
        private void m2360a(Object... values) {
            String action;
            if (values[0].equals("runningTask")) {
                action = AppCheck.ACTION_ACTIVITY_SWITCH;
            } else {
                action = AppCheck.ACTION_ACTIVITY_SWITCH_2;
            }
            Log.i("AppCheck", values[0] + "------------action:" + action + " " + values[1] + " " + values[2]);
            Intent i = new Intent(action);
            i.putExtra("newPkg", (String) values[1]);
            i.putExtra("oldPkg", (String) values[2]);
            AppCheck.this.f5701c.sendBroadcast(i);
            Settings.System.putString(AppCheck.this.f5701c.getContentResolver(), "safe_input_method", "com.android.inputmethod.latin/.LatinIME");
            Log.i("AppCheck", values[0] + "------------end");
        }
    }
}
