package com.lenovo.safecenter.broadcast;

import android.app.Service;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.IBinder;
import android.util.Log;

/* JADX INFO: loaded from: classes.dex */
public class SafePaymenUninstallService extends Service {
    @Override // android.app.Service
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override // android.app.Service
    public void onStart(Intent intent, int startId) {
        super.onStart(intent, startId);
        String pkgName = intent.getStringExtra("pkgName");
        if (!m1473a(pkgName)) {
            Log.i("safepayment", "pkgname null uninstall error!!!!!");
            stopSelf();
            return;
        }
        Uri packageURI = Uri.parse("package:" + pkgName);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        uninstallIntent.setFlags(268435456);
        startActivity(uninstallIntent);
        stopSelf();
    }

    /* JADX INFO: renamed from: a */
    private boolean m1473a(String pkgName) {
        PackageInfo packageInfo;
        try {
            packageInfo = getPackageManager().getPackageInfo(pkgName, 0);
        } catch (PackageManager.NameNotFoundException e) {
            packageInfo = null;
            e.printStackTrace();
        }
        return packageInfo != null;
    }
}
