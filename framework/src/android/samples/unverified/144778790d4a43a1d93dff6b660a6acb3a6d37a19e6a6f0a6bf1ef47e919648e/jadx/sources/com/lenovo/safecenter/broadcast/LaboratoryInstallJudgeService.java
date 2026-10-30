package com.lenovo.safecenter.broadcast;

import android.app.Service;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.IBinder;
import android.util.Log;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.database.AppUtil;

/* JADX INFO: loaded from: classes.dex */
public class LaboratoryInstallJudgeService extends Service {

    /* JADX INFO: renamed from: a */
    private String f3416a;

    /* JADX INFO: renamed from: b */
    private SharedPreferences f3417b;

    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.broadcast.LaboratoryInstallJudgeService$1] */
    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        Log.i("ydp", "add app md5 service");
        super.onStart(intent, startId);
        this.f3416a = intent.getExtras().getString(QueryPermissions.PACKAGENAME);
        this.f3417b = getSharedPreferences("laboratory_otherakp", 3);
        new Thread() { // from class: com.lenovo.safecenter.broadcast.LaboratoryInstallJudgeService.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                LaboratoryInstallJudgeService.this.init(LaboratoryInstallJudgeService.this.f3416a);
            }
        }.start();
    }

    public void init(String pName) {
        try {
            String md5 = AppUtil.getCretMD5(this, pName);
            if (md5.equals("8DDB342F2DA5408402D7568AF21E29F9")) {
                this.f3417b.edit().putBoolean(pName, true).commit();
            }
            stopSelf();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
