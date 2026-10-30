package com.lenovo.safecenter.broadcast;

import android.app.Service;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.os.IBinder;
import android.util.Log;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.adapter.DaoImpl;
import com.lenovo.safecenter.adapter.DbAdapter;
import com.lenovo.safecenter.database.AppUtil;
import java.io.File;

/* JADX INFO: loaded from: classes.dex */
public class SafePaymentInstallJudgeService extends Service {

    /* JADX INFO: renamed from: a */
    private String f3452a;

    /* JADX INFO: renamed from: b */
    private String f3453b;

    /* JADX INFO: renamed from: c */
    private DaoImpl f3454c;

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.broadcast.SafePaymentInstallJudgeService$1] */
    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        Log.i("ydp", "add app md5 service");
        super.onStart(intent, startId);
        this.f3452a = intent.getExtras().getString(QueryPermissions.PACKAGENAME);
        this.f3454c = new DaoImpl(new DbAdapter(getApplicationContext()));
        new Thread() { // from class: com.lenovo.safecenter.broadcast.SafePaymentInstallJudgeService.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                SafePaymentInstallJudgeService.this.init(SafePaymentInstallJudgeService.this.f3452a);
            }
        }.start();
    }

    public void init(String pName) {
        try {
            ApplicationInfo mAppInfo = getPackageManager().getApplicationInfo(pName, 8192);
            this.f3453b = mAppInfo.loadLabel(getPackageManager()).toString();
            mAppInfo.loadIcon(getPackageManager());
            String md5 = AppUtil.getCretMD5(this, pName);
            File file = new File(mAppInfo.sourceDir);
            long filesize = file.length();
            this.f3454c.insterForUserApp(this.f3453b, pName, md5, String.valueOf(filesize), "true", "true");
            stopSelf();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
