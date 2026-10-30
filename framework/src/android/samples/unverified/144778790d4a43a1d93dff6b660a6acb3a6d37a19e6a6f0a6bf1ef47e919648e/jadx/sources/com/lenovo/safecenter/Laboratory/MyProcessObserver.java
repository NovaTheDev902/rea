package com.lenovo.safecenter.Laboratory;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.text.TextUtils;
import android.util.Log;
import android.widget.RemoteViews;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.broadcast.SafePaymenUninstallService;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.support.SafePaymentApp;
import com.lenovo.safecenter.utils.AppCheck;
import com.lenovo.safecenter.utils.Const;
import java.io.File;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class MyProcessObserver {
    public static final int SAFEPAYMENT_NOTIFY_ID = 888;

    /* JADX INFO: renamed from: e */
    private static MyProcessObserver f2608e;

    /* JADX INFO: renamed from: a */
    SharedPreferences f2610a;

    /* JADX INFO: renamed from: b */
    NotificationManager f2611b;

    /* JADX INFO: renamed from: c */
    private Context f2612c;

    /* JADX INFO: renamed from: d */
    private PackageManager f2613d;

    /* JADX INFO: renamed from: f */
    private DaoImpl f2614f;

    /* JADX INFO: renamed from: g */
    private SafePaymentApp f2615g;

    /* JADX INFO: renamed from: h */
    private SafePaymentApp f2616h;
    public static String NOTIFY_PKGNAME = "";

    /* JADX INFO: renamed from: k */
    private static BroadcastReceiver f2609k = null;

    /* JADX INFO: renamed from: j */
    private String f2618j = "";

    /* JADX INFO: renamed from: l */
    private Handler f2619l = new Handler() { // from class: com.lenovo.safecenter.Laboratory.MyProcessObserver.3
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    Log.e("ydp", "handler ok");
                    MyProcessObserver.this.showNotify(true, "", "");
                    break;
                case 2:
                    Log.e("ydp", "handler no");
                    Intent intent = new Intent(MyProcessObserver.this.f2612c, (Class<?>) SafePaymentDialogActivity.class);
                    String[] strs = (String[]) msg.obj;
                    intent.putExtra("pkgName", strs[0]);
                    intent.putExtra("safeAppName", strs[1]);
                    intent.setFlags(335577088);
                    MyProcessObserver.this.f2612c.startActivity(intent);
                    MyProcessObserver.this.showNotify(false, strs[1], strs[0]);
                    break;
                case 3:
                    Notification notification = new Notification();
                    RemoteViews rv = new RemoteViews(MyProcessObserver.this.f2612c.getPackageName(), C0415R.layout.safepayment_notify);
                    notification.flags = 10;
                    notification.icon = C0415R.drawable.safepayment_notify_genuine_state;
                    notification.tickerText = MyProcessObserver.this.f2612c.getString(C0415R.string.safepayment_notify_out_tickertext_genuine) + msg.obj;
                    rv.setTextViewText(C0415R.id.content, MyProcessObserver.this.f2612c.getString(C0415R.string.safepayment_notify_content_genuine));
                    notification.contentView = rv;
                    notification.contentIntent = PendingIntent.getService(MyProcessObserver.this.f2612c, 0, new Intent(), 0);
                    MyProcessObserver.this.f2611b.notify(MyProcessObserver.SAFEPAYMENT_NOTIFY_ID, notification);
                    MyProcessObserver.this.f2611b.cancel(MyProcessObserver.SAFEPAYMENT_NOTIFY_ID);
                    break;
                case 4:
                    String[] pkgAndAppName = (String[]) msg.obj;
                    Notification notification2 = new Notification();
                    RemoteViews rv2 = new RemoteViews(MyProcessObserver.this.f2612c.getPackageName(), C0415R.layout.safepayment_notify);
                    notification2.flags = 24;
                    notification2.icon = C0415R.drawable.safepayment_notify_pirate_state;
                    notification2.tickerText = MyProcessObserver.this.f2612c.getString(C0415R.string.safepayment_notify_out_tickertext_pirate);
                    rv2.setTextViewText(C0415R.id.content, String.format(MyProcessObserver.this.f2612c.getString(C0415R.string.safepayment_notify_content_pirate), pkgAndAppName[1]));
                    notification2.contentView = rv2;
                    MyProcessObserver.NOTIFY_PKGNAME = pkgAndAppName[0];
                    Intent uninstallService = new Intent(MyProcessObserver.this.f2612c, (Class<?>) SafePaymenUninstallService.class);
                    uninstallService.setFlags(268435456);
                    uninstallService.putExtra("pkgName", pkgAndAppName[0]);
                    notification2.contentIntent = PendingIntent.getService(MyProcessObserver.this.f2612c, 0, uninstallService, 0);
                    MyProcessObserver.this.f2611b.notify(MyProcessObserver.SAFEPAYMENT_NOTIFY_ID, notification2);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: i */
    private HashMap<String, Boolean> f2617i = new HashMap<>();

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1220a(MyProcessObserver x0, String x1) {
        try {
            Log.e("ydp", "insterApp pkgName:" + x1);
            ApplicationInfo applicationInfo = x0.f2612c.getPackageManager().getApplicationInfo(x1, 8192);
            String string = applicationInfo.loadLabel(x0.f2612c.getPackageManager()).toString();
            applicationInfo.loadIcon(x0.f2612c.getPackageManager());
            x0.f2614f.insterForUserApp(string, x1, AppUtil.getCretMD5(x0.f2612c, x1), String.valueOf(new File(applicationInfo.sourceDir).length()), "true", "true");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1221a(MyProcessObserver x0, String x1, String x2) {
        Log.e("ydp", "checkApp pkgName:" + x1);
        x0.f2615g = x0.f2614f.queryByPackageNameForSafeApp(x1);
        if (x0.f2615g == null) {
            x0.clearNotify(x1, x2);
        } else {
            Log.e("ydp", "checkApp --pkgName-- pkgName:" + x1);
            x0.m1222a(x1, x2);
        }
    }

    public static MyProcessObserver getDefault(Context context) {
        if (f2608e == null) {
            f2608e = new MyProcessObserver(context);
        }
        return f2608e;
    }

    public MyProcessObserver(Context context) {
        this.f2612c = context;
        this.f2613d = context.getPackageManager();
        this.f2611b = (NotificationManager) context.getSystemService(DatabaseTables.LOG_NOTIFICATION);
        this.f2614f = new DaoImpl(new DbAdapter(context));
        this.f2610a = PreferenceManager.getDefaultSharedPreferences(context);
        f2609k = new BroadcastReceiver() { // from class: com.lenovo.safecenter.Laboratory.MyProcessObserver.1
            @Override // android.content.BroadcastReceiver
            public final void onReceive(Context context2, Intent intent) {
                String newPkg = intent.getStringExtra("newPkg");
                String oldPkg = intent.getStringExtra("oldPkg");
                if (!TextUtils.isEmpty(newPkg)) {
                    Log.i("ydp", "pkg---->" + newPkg);
                    MyProcessObserver.m1221a(MyProcessObserver.this, newPkg, oldPkg);
                }
            }
        };
    }

    public boolean register() {
        try {
            this.f2610a.edit().putBoolean(Const.KEY_IS_SAFEPAYMEN_ON, true).commit();
            this.f2612c.registerReceiver(f2609k, new IntentFilter(AppCheck.ACTION_ACTIVITY_SWITCH_2));
            return true;
        } catch (Exception e) {
            Log.e("ydp", "registerProcessObserver error:" + e);
            return false;
        }
    }

    public boolean unRegister() {
        try {
            this.f2610a.edit().putBoolean(Const.KEY_IS_SAFEPAYMEN_ON, false).commit();
            this.f2612c.unregisterReceiver(f2609k);
            return true;
        } catch (Exception e) {
            Log.e("ydp", "unregisterProcessObserver error:" + e);
            return false;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX WARN: Type inference failed for: r1v20, types: [com.lenovo.safecenter.Laboratory.MyProcessObserver$2] */
    /* JADX INFO: renamed from: a */
    public void m1222a(final String pkgName, final String clearPkgName) {
        try {
            this.f2616h = this.f2614f.queryByPackageNameForUserApp(pkgName);
            if (this.f2616h == null) {
                if (this.f2617i.get(pkgName) == null) {
                    this.f2617i.put(pkgName, true);
                    new Thread() { // from class: com.lenovo.safecenter.Laboratory.MyProcessObserver.2
                        @Override // java.lang.Thread, java.lang.Runnable
                        public final void run() {
                            Log.e("ydp", "insterApp ---:" + pkgName);
                            MyProcessObserver.m1220a(MyProcessObserver.this, pkgName);
                            MyProcessObserver.this.m1222a(pkgName, clearPkgName);
                        }
                    }.start();
                }
            } else if (this.f2615g.getApp_md5().contains(this.f2616h.getApp_md5())) {
                this.f2618j = this.f2616h.getApp_packagename();
                this.f2619l.sendMessage(this.f2619l.obtainMessage(1));
            } else if (!clearPkgName.equals(this.f2612c.getPackageName())) {
                Message m = new Message();
                m.obj = new String[]{pkgName, this.f2615g.getApp_name()};
                m.what = 2;
                this.f2619l.sendMessage(m);
            }
        } catch (Exception e) {
        }
    }

    public void showNotify(boolean genuine, String appName, String pkgName) {
        Notification notification = new Notification();
        RemoteViews rv = new RemoteViews(this.f2612c.getPackageName(), C0415R.layout.safepayment_notify);
        if (genuine) {
            notification.flags = 10;
            notification.icon = C0415R.drawable.safepayment_notify_genuine_state;
            notification.tickerText = this.f2612c.getString(C0415R.string.safepayment_notify_tickertext_genuine);
            notification.contentIntent = PendingIntent.getService(this.f2612c, 0, new Intent(), 0);
            rv.setTextViewText(C0415R.id.content, this.f2612c.getString(C0415R.string.safepayment_notify_content_genuine));
            rv.setTextColor(C0415R.id.content, this.f2612c.getResources().getColor(C0415R.color.black1));
        } else {
            notification.flags = 24;
            notification.icon = C0415R.drawable.safepayment_notify_pirate_state;
            notification.tickerText = this.f2612c.getString(C0415R.string.safepayment_notify_tickertext_pirate);
            rv.setTextViewText(C0415R.id.content, String.format(this.f2612c.getString(C0415R.string.safepayment_notify_content_pirate), appName));
            rv.setTextColor(C0415R.id.content, this.f2612c.getResources().getColor(C0415R.color.red));
            Intent uninstallService = new Intent(this.f2612c, (Class<?>) SafePaymenUninstallService.class);
            uninstallService.setFlags(268435456);
            uninstallService.putExtra("pkgName", pkgName);
            NOTIFY_PKGNAME = pkgName;
            notification.contentIntent = PendingIntent.getService(this.f2612c, 0, uninstallService, 0);
        }
        notification.contentView = rv;
        this.f2611b.notify(SAFEPAYMENT_NOTIFY_ID, notification);
    }

    public void clearNotify(String PkgName, String clearPkgName) {
        Log.i("safepaymen", "clearNotify Pkg:" + clearPkgName);
        this.f2615g = this.f2614f.queryByPackageNameForSafeApp(clearPkgName);
        if (this.f2615g != null) {
            m1224b(PkgName, clearPkgName);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX WARN: Type inference failed for: r2v30, types: [com.lenovo.safecenter.Laboratory.MyProcessObserver$4] */
    /* JADX INFO: renamed from: b */
    public void m1224b(final String PkgName, final String clearPkgName) {
        Log.i("safepaymen", "clearNotifyCheckMD5 Pkg:" + clearPkgName);
        this.f2616h = this.f2614f.queryByPackageNameForUserApp(clearPkgName);
        if (this.f2616h == null) {
            if (this.f2617i.get(clearPkgName) == null) {
                this.f2617i.put(clearPkgName, true);
                new Thread() { // from class: com.lenovo.safecenter.Laboratory.MyProcessObserver.4
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        MyProcessObserver.m1220a(MyProcessObserver.this, clearPkgName);
                        MyProcessObserver.this.m1224b(PkgName, clearPkgName);
                    }
                }.start();
                return;
            }
            return;
        }
        if (this.f2615g.getApp_md5().contains(this.f2616h.getApp_md5())) {
            Log.i("safepaymen", "clearNotify 3" + clearPkgName);
            Message m = new Message();
            m.obj = "";
            try {
                m.obj = this.f2613d.getPackageInfo(this.f2616h.getApp_packagename(), 1).applicationInfo.loadLabel(this.f2613d).toString();
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
            m.what = 3;
            this.f2619l.sendMessage(m);
        } else {
            Log.i("safepaymen", "clearNotify 4" + clearPkgName);
            if (!PkgName.equals("com.android.packageinstaller") && !PkgName.equals(this.f2612c.getPackageName())) {
                Message m2 = new Message();
                m2.obj = new String[]{clearPkgName, this.f2615g.getApp_name()};
                m2.what = 4;
                this.f2619l.sendMessage(m2);
            }
        }
        this.f2618j = "";
    }
}
