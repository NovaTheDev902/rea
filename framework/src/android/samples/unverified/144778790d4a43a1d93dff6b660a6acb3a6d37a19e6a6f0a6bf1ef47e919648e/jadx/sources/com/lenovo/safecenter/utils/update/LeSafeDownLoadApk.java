package com.lenovo.safecenter.utils.update;

import android.app.Service;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.preference.PreferenceManager;
import android.util.Log;
import com.lenovo.lps.sus.SUS;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.WflUtils;
import java.io.File;

/* JADX INFO: loaded from: classes.dex */
public class LeSafeDownLoadApk extends Service {

    /* JADX INFO: renamed from: a */
    private PackageManager f5833a;

    /* JADX INFO: renamed from: b */
    private LeSafeUpdate f5834b;

    /* JADX INFO: renamed from: c */
    private SharedPreferences f5835c;

    /* JADX INFO: renamed from: d */
    private int f5836d = 0;

    /* JADX INFO: renamed from: e */
    private boolean f5837e = false;

    /* JADX INFO: renamed from: f */
    private Handler f5838f = new Handler() { // from class: com.lenovo.safecenter.utils.update.LeSafeDownLoadApk.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    if (LeSafeDownLoadApk.this.f5834b == null) {
                        LeSafeDownLoadApk.this.f5834b = new LeSafeUpdate(LeSafeDownLoadApk.this, LeSafeDownLoadApk.this.getPackageName(), LeSafeDownLoadApk.this.f5836d, Const.SUS_CHANNEL, false, true, true, new LeSafeUpdate.LeSafeUpdateListenser() { // from class: com.lenovo.safecenter.utils.update.LeSafeDownLoadApk.2.1
                            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                            public final void onQueryResp(String resultion, LeSafeUpdateInfo lfui) {
                                Log.i("ydp", "LeSafeDownLoadApk resultion " + resultion);
                                if (!resultion.equals(C0092c.f1288S)) {
                                    if (LeSafeDownLoadApk.this.f5837e) {
                                        Const.updateAPK = true;
                                        Log.i("ydp", "onQueryResp haveUpdateFile");
                                    }
                                    LeSafeDownLoadApk.this.stopSelf();
                                }
                            }

                            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                            public final void onInstallComplete(boolean succeed) {
                            }

                            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                            public final void onDownLoadException(int errorCode) {
                                Log.i("ydp", "LeSafeDownLoadApk onDownLoadException " + errorCode);
                                if (LeSafeDownLoadApk.this.f5837e) {
                                    Const.updateAPK = true;
                                    Log.i("ydp", "onDownLoadException haveUpdateFile");
                                }
                                LeSafeDownLoadApk.this.stopSelf();
                            }

                            @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                            public final void onDownLoadComplete(String path) {
                                Const.updateAPK = true;
                                LeSafeDownLoadApk.this.f5835c.edit().putString("update_apk_path", path).commit();
                                Log.i("ydp", "LeSafeDownLoadApk DownLoadComplete " + path);
                                LeSafeDownLoadApk.this.stopSelf();
                            }
                        });
                    }
                    LeSafeDownLoadApk.this.f5834b.upDate(true, false);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: c */
    static /* synthetic */ boolean m2458c(LeSafeDownLoadApk x0) {
        x0.f5837e = true;
        return true;
    }

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override // android.app.Service
    public void onCreate() {
        super.onCreate();
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.utils.update.LeSafeDownLoadApk$1] */
    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        super.onStart(intent, startId);
        this.f5833a = getPackageManager();
        this.f5835c = PreferenceManager.getDefaultSharedPreferences(this);
        if (WflUtils.isWifiNetwork(this)) {
            Log.i("ydp", "wifi Connected");
            new Thread() { // from class: com.lenovo.safecenter.utils.update.LeSafeDownLoadApk.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    PackageInfo pi;
                    try {
                        PackageInfo packageinfo = LeSafeDownLoadApk.this.getPackageManager().getPackageInfo(LeSafeDownLoadApk.this.getPackageName(), 0);
                        LeSafeDownLoadApk.this.f5836d = packageinfo.versionCode;
                        File apks = LeSafeDownLoadApk.this.getCacheDir();
                        if (apks.exists()) {
                            File[] f = apks.listFiles();
                            for (File file : f) {
                                if (file.getName().toLowerCase().endsWith(".apk") && (pi = LeSafeDownLoadApk.this.f5833a.getPackageArchiveInfo(file.getPath(), 1)) != null && pi.packageName.equals(LeSafeDownLoadApk.this.getPackageName())) {
                                    if (pi.versionCode > LeSafeDownLoadApk.this.f5836d) {
                                        LeSafeDownLoadApk.this.f5836d = pi.versionCode;
                                        LeSafeDownLoadApk.m2458c(LeSafeDownLoadApk.this);
                                        LeSafeDownLoadApk.this.f5835c.edit().putString("update_apk_path", file.getPath()).commit();
                                        Log.i("ydp", "haveUpdateFile " + LeSafeDownLoadApk.this.f5836d);
                                        break;
                                    }
                                    file.delete();
                                    Log.i("ydp", "delete low version file");
                                    break;
                                }
                            }
                            LeSafeDownLoadApk.this.f5838f.sendMessage(LeSafeDownLoadApk.this.f5838f.obtainMessage(1));
                        }
                    } catch (PackageManager.NameNotFoundException e) {
                        e.printStackTrace();
                    }
                }
            }.start();
        } else {
            Log.i("ydp", "wifi unconnected");
            SUS.finish();
            stopSelf();
        }
    }
}
