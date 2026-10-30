package com.xxGameAssistant.pao;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.widget.TextView;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SplashActivity extends Activity {
    private final int SPLASH_DISPLAY_LENGHT = 3000;
    public ArrayList<String> mPackageString = new ArrayList<>();
    public ArrayList<String> mChannelString = new ArrayList<>();

    /* JADX INFO: renamed from: go */
    public boolean f227go = true;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0099R.layout.activity_splash);
        long start = System.currentTimeMillis();
        new Handler().postDelayed(new Runnable() { // from class: com.xxGameAssistant.pao.SplashActivity.1
            @Override // java.lang.Runnable
            public void run() {
                SplashActivity.this.f227go = false;
                MTApplication.mPackageString = SplashActivity.this.mPackageString;
                MTApplication.mChannelString = SplashActivity.this.mChannelString;
                Intent intent = new Intent(SplashActivity.this, (Class<?>) MainActivity.class);
                SplashActivity.this.startActivity(intent);
                SplashActivity.this.finish();
            }
        }, 3000L);
        ((MTApplication) getApplication()).getThread().start();
        scanAllApp();
        try {
            PackageManager packageManager = getPackageManager();
            PackageInfo packInfo = packageManager.getPackageInfo(getPackageName(), 0);
            String vm = packInfo.versionName;
            TextView tv = (TextView) findViewById(C0099R.id.mt_soft_info);
            tv.setText("版本：" + vm);
            String lianmeng = packageManager.getPackageInfo("com.tencent.pao", 0).versionName;
            Log.d("版本", lianmeng);
            if (lianmeng.equals("1.0.7.0")) {
                MTApplication.mIsNewestVersion = true;
            } else {
                MTApplication.mIsNewestVersion = false;
            }
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        long end2 = System.currentTimeMillis();
        Log.d("time2", new StringBuilder().append(end2 - start).toString());
    }

    @Override // android.app.Activity
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(C0099R.menu.main_surface, menu);
        return true;
    }

    public void scanAllApp() {
        String[] tChannel = getResources().getStringArray(C0099R.array.channel_name);
        String[] tPackage_key = getResources().getStringArray(C0099R.array.package_key);
        PackageManager tPManager = getPackageManager();
        List<PackageInfo> tpInfo = tPManager.getInstalledPackages(0);
        for (PackageInfo tp : tpInfo) {
            if (tp.packageName.compareTo(tPackage_key[0]) == 0) {
                this.mPackageString.add(tp.packageName);
                this.mChannelString.add(tChannel[0]);
            }
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4 && event.getRepeatCount() == 0) {
            finish();
            this.f227go = false;
        }
        return super.onKeyDown(keyCode, event);
    }
}
