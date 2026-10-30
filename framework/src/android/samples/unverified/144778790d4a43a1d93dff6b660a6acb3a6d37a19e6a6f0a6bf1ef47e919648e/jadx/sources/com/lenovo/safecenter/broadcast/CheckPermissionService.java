package com.lenovo.safecenter.broadcast;

import android.app.ActivityManager;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.IBinder;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.lenovoAntiSpam.utils.HttpUtils;
import com.lenovo.safecenter.lenovoAntiSpam.utils.SafeCenter;
import com.lenovo.safecenter.lenovoAntiSpam.utils.SmsCheckUtils;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.notificationintercept.InterceptUtils;
import com.lenovo.safecenter.notificationintercept.UrlOptionUtils;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.WhiteAppsList;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class CheckPermissionService extends Service {

    /* JADX INFO: renamed from: a */
    private Context f3391a;

    /* JADX INFO: renamed from: b */
    private Intent f3392b;

    /* JADX WARN: Code duplicated, block: B:55:0x01c3  */
    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1444a(CheckPermissionService x0, Context x1) throws Throwable {
        boolean z = true;
        SharedPreferences defaultSharedPreferences = PreferenceManager.getDefaultSharedPreferences(x1);
        SharedPreferences.Editor editorEdit = defaultSharedPreferences.edit();
        AppDatabase appDatabase = new AppDatabase(x1);
        boolean z2 = defaultSharedPreferences.getBoolean("firstBoot", true);
        Log.d("test", "init flag: " + z2);
        boolean zNacServerIsExist = TrafficStatsService.nacServerIsExist();
        if (z2) {
            try {
                LeSafeObservable.get(x1).noticeLoadPermissions();
                x1.sendBroadcast(new Intent("action.antivirus.init"));
                try {
                    Const.setPreInstalledVersion(x0.getPackageManager().getPackageArchiveInfo("/system/app/LenovoSafeCenter.apk", 1).versionCode > 3830725);
                } catch (Exception e) {
                    e.printStackTrace();
                    Const.setPreInstalledVersion(false);
                }
                WhiteAppsList.writeWhiteApksToFile(x1);
                Const.LENOVO_APKS = WhiteAppsList.getWhiteList(x1, "lenovoapks");
                AppUtil.batchOperateDBForBoot(x1, appDatabase, Const.getPreInstalledVersion());
                Settings.Secure.putInt(x1.getContentResolver(), "controlsms", 1);
            } catch (Exception e2) {
                e2.printStackTrace();
            }
            editorEdit.putBoolean("firstBoot", false);
            editorEdit.commit();
        }
        SharedPreferences sharedPreferences = x1.getSharedPreferences("isFirst", 0);
        if (sharedPreferences.getBoolean("flag11", true)) {
            Settings.System.putInt(x1.getContentResolver(), "intercall_mode_type", 0);
            LeSafeObservable.get(x1).noticeLoadVirusDB();
            SafeCenter.setPathUrl(x1);
            SmsCheckUtils.init(x1);
            new HttpUtils().UpdateConfig("systime", "2011.09.27", x1);
            SharedPreferences.Editor editorEdit2 = sharedPreferences.edit();
            editorEdit2.putBoolean("flag11", false);
            editorEdit2.commit();
            new com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase(x1).initWhiteSMS();
        }
        LeSafeObservable.get(x1).noticeLoadFinish();
        if (zNacServerIsExist) {
            Const.obtainRoot();
            if (!Const.isObtainRoot()) {
                if (!new File(x0.f3391a.getFilesDir() + "/mount").exists()) {
                    CMDHelper.whiteMountToFiles(x0.f3391a);
                    try {
                        Thread.sleep(1000L);
                    } catch (InterruptedException e3) {
                        e3.printStackTrace();
                    }
                }
                CMDHelper.updateCmcc(x0.f3391a);
                Const.obtainRoot();
            }
            String strCheckSu = CMDHelper.checkSu(x0.f3391a);
            if (strCheckSu != null) {
                CMDHelper.SocketClient(x0.f3391a, strCheckSu);
            }
        } else {
            if (Const.isObtainRoot()) {
                z = false;
            } else {
                Const.obtainRoot();
                if (Const.isObtainRoot()) {
                    z = false;
                } else {
                    Const.obtainSu();
                }
            }
            if (Const.isObtainRoot()) {
                TrackEvent.reportRootEnable();
                if (!new File(x0.f3391a.getFilesDir() + "/mount").exists()) {
                    CMDHelper.whiteMountToFiles(x0.f3391a);
                    try {
                        Thread.sleep(1000L);
                    } catch (InterruptedException e4) {
                        e4.printStackTrace();
                    }
                }
                if (z) {
                    CMDHelper.updateCmcc(x0.f3391a);
                }
            }
        }
        Log.d("test", "modifyMyCmcc obtain root: " + Const.isObtainRoot());
        CMDHelper.init(x1);
        TrafficStatsService.createShell(x1);
        if (zNacServerIsExist || Const.isObtainRoot()) {
            x1.startService(new Intent(x1, (Class<?>) SafeCenterService.class));
            m1443a(x1);
            appDatabase.enableNohideApp(Const.PACKAGENAME_LE_BATTERY);
        }
    }

    /* JADX WARN: Code duplicated, block: B:18:0x00d4 A[Catch: IOException -> 0x00de, TRY_LEAVE, TryCatch #5 {IOException -> 0x00de, blocks: (B:16:0x00cf, B:18:0x00d4), top: B:62:0x00cf }] */
    /* JADX WARN: Code duplicated, block: B:29:0x00ef A[Catch: IOException -> 0x00f3, TRY_LEAVE, TryCatch #2 {IOException -> 0x00f3, blocks: (B:27:0x00ea, B:29:0x00ef), top: B:59:0x00ea }] */
    /* JADX WARN: Code duplicated, block: B:37:0x00ff A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:38:0x0101 A[Catch: IOException -> 0x0105, TRY_LEAVE, TryCatch #0 {IOException -> 0x0105, blocks: (B:36:0x00fc, B:38:0x0101), top: B:55:0x00fc }] */
    /* JADX WARN: Code duplicated, block: B:55:0x00fc A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1445a(CheckPermissionService x0, Context x1, PackageManager x2, String x3, int x4, String x5, ApplicationInfo x6) throws Throwable {
        FileOutputStream fileOutputStreamOpenFileOutput;
        FileOutputStream fileOutputStreamOpenFileOutput2 = null;
        ArrayList arrayList = new ArrayList();
        arrayList.add(TrafficStatsService.PACKAGE_NAME);
        arrayList.add("com.lenovo.ideafriend");
        AppDatabase appDatabase = new AppDatabase(x0.f3391a);
        if (!WhiteAppsList.contains(WhiteAppsList.md5s, x3) && !WhiteAppsList.contains(arrayList, x5)) {
            if (TextUtils.isEmpty(Const.LENOVO_APKS)) {
                Const.LENOVO_APKS = WhiteAppsList.getWhiteList(x0.f3391a, "lenovoapks");
            }
            if (Const.LENOVO_APKS.contains(x5 + "\n")) {
                return;
            }
            AppUtil.batchOperateDB(appDatabase, x0.f3391a, x2, x6);
            if (Const.isObtainRoot()) {
                x0.startService(new Intent(x1, (Class<?>) SafeCenterService.class));
            }
            x0.f3391a.sendBroadcast(new Intent("com.lenovo.safecenter.refreshAppsManager"));
            return;
        }
        Context context = x0.f3391a;
        try {
            if (TextUtils.isEmpty(Const.LENOVO_APKS)) {
                Const.LENOVO_APKS = WhiteAppsList.getWhiteList(x0.f3391a, "lenovoapks");
            }
            if (TextUtils.isEmpty(Const.WHITE_LIST)) {
                Const.WHITE_LIST = WhiteAppsList.getWhiteList(x0.f3391a, "whitelist");
            }
            Const.LENOVO_APKS += x5;
            Const.LENOVO_APKS += "\n";
            fileOutputStreamOpenFileOutput = context.openFileOutput("lenovoapks", 0);
            try {
                try {
                    fileOutputStreamOpenFileOutput.write(Const.LENOVO_APKS.getBytes());
                    Const.WHITE_LIST += Integer.toString(x4);
                    Const.WHITE_LIST += "\n";
                    fileOutputStreamOpenFileOutput2 = context.openFileOutput("whitelist", 0);
                    fileOutputStreamOpenFileOutput2.write(Const.WHITE_LIST.getBytes());
                    CMDHelper.initWhiteList(x0.f3391a);
                    if (fileOutputStreamOpenFileOutput != null) {
                        try {
                            fileOutputStreamOpenFileOutput.close();
                            if (fileOutputStreamOpenFileOutput2 != null) {
                                fileOutputStreamOpenFileOutput2.close();
                            }
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    } else if (fileOutputStreamOpenFileOutput2 != null) {
                        fileOutputStreamOpenFileOutput2.close();
                    }
                } catch (Exception e2) {
                    e = e2;
                    e.printStackTrace();
                    if (fileOutputStreamOpenFileOutput != null) {
                        try {
                            fileOutputStreamOpenFileOutput.close();
                            if (fileOutputStreamOpenFileOutput2 != null) {
                                fileOutputStreamOpenFileOutput2.close();
                            }
                        } catch (IOException e3) {
                            e3.printStackTrace();
                        }
                    } else if (fileOutputStreamOpenFileOutput2 != null) {
                        fileOutputStreamOpenFileOutput2.close();
                    }
                }
            } catch (Throwable th) {
                th = th;
                if (fileOutputStreamOpenFileOutput != null) {
                    try {
                        fileOutputStreamOpenFileOutput.close();
                        if (fileOutputStreamOpenFileOutput2 != null) {
                            fileOutputStreamOpenFileOutput2.close();
                        }
                    } catch (IOException e4) {
                        e4.printStackTrace();
                        throw th;
                    }
                } else if (fileOutputStreamOpenFileOutput2 != null) {
                    fileOutputStreamOpenFileOutput2.close();
                }
                throw th;
            }
        } catch (Exception e5) {
            e = e5;
            fileOutputStreamOpenFileOutput = null;
        } catch (Throwable th2) {
            th = th2;
            fileOutputStreamOpenFileOutput = null;
            if (fileOutputStreamOpenFileOutput != null) {
                fileOutputStreamOpenFileOutput.close();
                if (fileOutputStreamOpenFileOutput2 != null) {
                    fileOutputStreamOpenFileOutput2.close();
                }
            } else if (fileOutputStreamOpenFileOutput2 != null) {
                fileOutputStreamOpenFileOutput2.close();
            }
            throw th;
        }
        CMDHelper.guestModeClient(SafeCenterService.SYSTEM_SERVICE, 2, 0, x4);
    }

    /* JADX WARN: Code duplicated, block: B:16:0x00a3 A[Catch: IOException -> 0x00b2, TRY_LEAVE, TryCatch #3 {IOException -> 0x00b2, blocks: (B:14:0x009e, B:16:0x00a3), top: B:60:0x009e }] */
    /* JADX WARN: Code duplicated, block: B:28:0x00c3 A[Catch: IOException -> 0x00c7, TRY_LEAVE, TryCatch #2 {IOException -> 0x00c7, blocks: (B:26:0x00be, B:28:0x00c3), top: B:58:0x00be }] */
    /* JADX WARN: Code duplicated, block: B:36:0x00d3 A[DONT_INVERT] */
    /* JADX WARN: Code duplicated, block: B:37:0x00d5 A[Catch: IOException -> 0x00d9, TRY_LEAVE, TryCatch #0 {IOException -> 0x00d9, blocks: (B:35:0x00d0, B:37:0x00d5), top: B:54:0x00d0 }] */
    /* JADX WARN: Code duplicated, block: B:54:0x00d0 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Type inference failed for: r1v0 */
    /* JADX WARN: Type inference failed for: r1v10 */
    /* JADX WARN: Type inference failed for: r1v3, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r1v5 */
    /* JADX WARN: Type inference failed for: r1v7 */
    /* JADX WARN: Type inference failed for: r2v16, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r2v3, types: [java.lang.String] */
    /* JADX WARN: Type inference failed for: r2v4 */
    /* JADX WARN: Type inference failed for: r2v5 */
    /* JADX WARN: Type inference failed for: r2v6, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r2v7 */
    /* JADX WARN: Type inference failed for: r2v8, types: [java.io.FileOutputStream] */
    /* JADX WARN: Type inference failed for: r2v9 */
    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1446a(CheckPermissionService checkPermissionService, Context context, boolean z, int i, String str) throws Throwable {
        ?? r1 = 0;
        fileOutputStreamOpenFileOutput = null;
        FileOutputStream fileOutputStreamOpenFileOutput = null;
        r1 = 0;
        AppDatabase appDatabase = new AppDatabase(context);
        if (z) {
            try {
                PackageManager packageManager = checkPermissionService.f3391a.getPackageManager();
                ApplicationInfo applicationInfo = packageManager.getApplicationInfo(str, 8192);
                if (TextUtils.isEmpty(Const.LENOVO_APKS)) {
                    Const.LENOVO_APKS = WhiteAppsList.getWhiteList(context, "lenovoapks");
                }
                if (!Const.LENOVO_APKS.contains(str + "\n")) {
                    AppUtil.batchOperateDB(appDatabase, checkPermissionService.f3391a, packageManager, applicationInfo);
                }
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
        } else {
            appDatabase.deleteDbForUninstall(str);
            appDatabase.deleteApp(str, 0);
            appDatabase.deleteApp(str, 1);
            ?? OpenFileOutput = "com.lenovo.safecenter.refreshAppsManager";
            context.sendBroadcast(new Intent("com.lenovo.safecenter.refreshAppsManager"));
            Context context2 = checkPermissionService.f3391a;
            try {
                try {
                    if (TextUtils.isEmpty(Const.LENOVO_APKS)) {
                        Const.LENOVO_APKS = WhiteAppsList.getWhiteList(checkPermissionService.f3391a, "lenovoapks");
                    }
                    if (TextUtils.isEmpty(Const.WHITE_LIST)) {
                        Const.WHITE_LIST = WhiteAppsList.getWhiteList(checkPermissionService.f3391a, "whitelist");
                    }
                    String strReplace = Const.WHITE_LIST.replace(i + "\n", "");
                    Const.WHITE_LIST = strReplace;
                    OpenFileOutput = context2.openFileOutput("whitelist", 0);
                    try {
                        OpenFileOutput.write(strReplace.getBytes());
                        CMDHelper.initWhiteList(context2);
                        String strReplace2 = Const.LENOVO_APKS.replace(str + "\n", "");
                        Const.LENOVO_APKS = strReplace2;
                        fileOutputStreamOpenFileOutput = context2.openFileOutput("lenovoapks", 0);
                        fileOutputStreamOpenFileOutput.write(strReplace2.getBytes());
                        if (OpenFileOutput != 0) {
                            try {
                                OpenFileOutput.close();
                                if (fileOutputStreamOpenFileOutput != null) {
                                    fileOutputStreamOpenFileOutput.close();
                                }
                            } catch (IOException e2) {
                                e2.printStackTrace();
                            }
                        } else if (fileOutputStreamOpenFileOutput != null) {
                            fileOutputStreamOpenFileOutput.close();
                        }
                    } catch (Exception e3) {
                        e = e3;
                        e.printStackTrace();
                        if (OpenFileOutput != 0) {
                            try {
                                OpenFileOutput.close();
                                if (fileOutputStreamOpenFileOutput != null) {
                                    fileOutputStreamOpenFileOutput.close();
                                }
                            } catch (IOException e4) {
                                e4.printStackTrace();
                            }
                        } else if (fileOutputStreamOpenFileOutput != null) {
                            fileOutputStreamOpenFileOutput.close();
                        }
                    }
                } catch (Throwable th) {
                    th = th;
                    if (OpenFileOutput != 0) {
                        try {
                            OpenFileOutput.close();
                            if (r1 != 0) {
                                r1.close();
                            }
                        } catch (IOException e5) {
                            e5.printStackTrace();
                            throw th;
                        }
                    } else if (r1 != 0) {
                        r1.close();
                    }
                    throw th;
                }
            } catch (Exception e6) {
                e = e6;
                OpenFileOutput = 0;
            } catch (Throwable th2) {
                th = th2;
                OpenFileOutput = 0;
                if (OpenFileOutput != 0) {
                    OpenFileOutput.close();
                    if (r1 != 0) {
                        r1.close();
                    }
                } else if (r1 != 0) {
                    r1.close();
                }
                throw th;
            }
            r1 = 2;
            CMDHelper.guestModeClient(SafeCenterService.SYSTEM_SERVICE, 2, 1, i);
        }
        DataLayerManager.insertBootResolveInfo(checkPermissionService.f3391a, str);
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    /* JADX WARN: Type inference failed for: r2v7, types: [com.lenovo.safecenter.broadcast.CheckPermissionService$3] */
    /* JADX WARN: Type inference failed for: r2v8, types: [com.lenovo.safecenter.broadcast.CheckPermissionService$2] */
    /* JADX WARN: Type inference failed for: r2v9, types: [com.lenovo.safecenter.broadcast.CheckPermissionService$1] */
    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        try {
            super.onStart(intent, startId);
            this.f3391a = this;
            this.f3392b = intent;
            String type = this.f3392b.getStringExtra("type");
            if (type.equals("init_app")) {
                new Thread() { // from class: com.lenovo.safecenter.broadcast.CheckPermissionService.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() throws Throwable {
                        CheckPermissionService.m1444a(CheckPermissionService.this, CheckPermissionService.this.f3391a);
                        if (UrlOptionUtils.isAppFirstInit(CheckPermissionService.this)) {
                            UrlOptionUtils.adSwitch(CheckPermissionService.this, true);
                            InterceptUtils.initWhiteListUid(CheckPermissionService.this.f3391a, "");
                        }
                        CheckPermissionService.this.stopSelf();
                    }
                }.start();
            } else if (type.equals("add_app")) {
                new Thread() { // from class: com.lenovo.safecenter.broadcast.CheckPermissionService.2
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() throws Throwable {
                        int uid = CheckPermissionService.this.f3392b.getIntExtra("uid", 0);
                        String pkgName = CheckPermissionService.this.f3392b.getStringExtra(QueryPermissions.PACKAGENAME);
                        boolean replacing = CheckPermissionService.this.f3392b.getBooleanExtra("replacing", false);
                        if (Const.PACKAGENAME_APP_LOCK.equals(pkgName)) {
                            Intent it = new Intent("com.lenovo.safebox.WATCH_APP_SERVICE");
                            it.putExtra("controler", false);
                            CheckPermissionService.this.f3391a.startService(it);
                        }
                        try {
                            DaoImpl di = new DaoImpl(new DbAdapter(CheckPermissionService.this.f3391a));
                            PackageManager pm = CheckPermissionService.this.f3391a.getPackageManager();
                            ApplicationInfo mAppInfo = pm.getApplicationInfo(pkgName, 8192);
                            String app_name = mAppInfo.loadLabel(pm).toString();
                            mAppInfo.loadIcon(pm);
                            String md5 = AppUtil.getCretMD5(CheckPermissionService.this.f3391a, pkgName);
                            Log.d("test", "md5: " + md5);
                            File file = new File(mAppInfo.sourceDir);
                            long filesize = file.length();
                            di.insterForUserApp(app_name, pkgName, md5, String.valueOf(filesize), "true", "true");
                            if (!replacing) {
                                CheckPermissionService.m1445a(CheckPermissionService.this, CheckPermissionService.this.f3391a, pm, md5, uid, pkgName, mAppInfo);
                            }
                        } catch (PackageManager.NameNotFoundException e) {
                            e.printStackTrace();
                        }
                        CheckPermissionService.this.stopSelf();
                    }
                }.start();
            } else if (type.equals("del_app")) {
                new Thread() { // from class: com.lenovo.safecenter.broadcast.CheckPermissionService.3
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() throws Throwable {
                        int uid = CheckPermissionService.this.f3392b.getIntExtra("uid", 0);
                        String pkgName = CheckPermissionService.this.f3392b.getStringExtra(QueryPermissions.PACKAGENAME);
                        boolean replacing = CheckPermissionService.this.f3392b.getBooleanExtra("replacing", false);
                        try {
                            CheckPermissionService.m1446a(CheckPermissionService.this, CheckPermissionService.this.f3391a, replacing, uid, pkgName);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        CheckPermissionService.this.stopSelf();
                    }
                }.start();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override // android.app.Service
    public void onDestroy() {
        super.onDestroy();
    }

    /* JADX INFO: renamed from: a */
    private static void m1443a(Context context) {
        List<ActivityManager.RunningAppProcessInfo> list;
        AppDatabase database = new AppDatabase(context);
        List<String> receiveSmsPkgs = database.getReceiveSmsPkgs();
        if (receiveSmsPkgs.size() > 0 && (list = ((ActivityManager) context.getSystemService("activity")).getRunningAppProcesses()) != null) {
            String cmd = "";
            for (int i = 0; i < list.size(); i++) {
                String pkg = list.get(i).pkgList[0];
                if (receiveSmsPkgs.contains(pkg)) {
                    int pid = list.get(i).pid;
                    cmd = cmd + "kill " + pid + " &\n";
                }
            }
            CMDHelper.exeCmd(context, cmd);
        }
    }
}
