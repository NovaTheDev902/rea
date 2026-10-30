package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerBattery;
import com.lenovo.safecenter.utils.update.LeSafeUpdate;
import com.lenovo.safecenter.utils.update.LeSafeUpdateInfo;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class AppDownloadActivity extends Activity implements View.OnClickListener {
    public static final String APP_LOCK_FILE_NAME = "LenovoSafeBox455.apk";
    public static final int APP_LOCK_PATCH_VERSIONCODE = 3900369;
    public static final String CHANNEL_KEY_LEBATTERY = "Develop";
    public static final String CHANNEL_KEY_LECLOUD = "leanquan_embed";
    public static final String CHANNEL_KEY_SELF = "self";
    public static final String WIDGET4X1_FILE_NAME = "LenovoSafeWidget115.apk";

    /* JADX INFO: renamed from: a */
    private LeSafeUpdate f2672a;

    /* JADX INFO: renamed from: b */
    private String f2673b;

    /* JADX INFO: renamed from: d */
    private int f2675d;

    /* JADX INFO: renamed from: e */
    private TextView f2676e;

    /* JADX INFO: renamed from: h */
    private String f2679h;

    /* JADX INFO: renamed from: c */
    private boolean f2674c = true;

    /* JADX INFO: renamed from: f */
    private Handler f2677f = new Handler() { // from class: com.lenovo.safecenter.MainTab.AppDownloadActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    Toast.makeText(AppDownloadActivity.this, (String) msg.obj, 0).show();
                    break;
            }
            super.handleMessage(msg);
        }
    };

    /* JADX INFO: renamed from: g */
    private BroadcastReceiver f2678g = new BroadcastReceiver() { // from class: com.lenovo.safecenter.MainTab.AppDownloadActivity.2
        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if ("android.intent.action.PACKAGE_ADDED".equals(action)) {
                Log.i("wu0wu", "AppDownloadActivity ACTION_PACKAGE_ADDED");
                AppDownloadActivity.m1232a(AppDownloadActivity.this);
                if (Const.PACKAGENAME_LE_BATTERY.equals(intent.getData().getSchemeSpecificPart())) {
                    TrackEvent.reportDownloadLeBattery();
                }
            }
        }
    };

    /* JADX INFO: renamed from: i */
    private boolean f2680i = false;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1232a(AppDownloadActivity x0) {
        if (AppUtil.isAppExistence(x0, x0.f2679h)) {
            x0.f2680i = false;
            WflUtils.sendMessageToHandler(0, x0.getString(C0415R.string.installed_text), x0.f2677f);
            if (!x0.f2674c) {
                x0.finish();
            }
            x0.f2676e.setText(x0.getString(C0415R.string.go_));
        }
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.download_app);
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("android.intent.action.PACKAGE_ADDED");
        intentFilter.addDataScheme("package");
        registerReceiver(this.f2678g, intentFilter);
        TextView textView = (TextView) findViewById(C0415R.id.txt_title);
        textView.setText(C0415R.string.safe_backup);
        ImageView imageView = (ImageView) findViewById(C0415R.id.title_back);
        imageView.setVisibility(0);
        imageView.setOnClickListener(this);
        Intent intent = getIntent();
        this.f2675d = intent.getByteExtra("type", (byte) 1);
        this.f2674c = intent.getBooleanExtra("isEntry", true);
        Log.i("AppDownloadActivity", "initView()...type=" + this.f2675d);
        ImageView imageView2 = (ImageView) findViewById(C0415R.id.download_app_img);
        ImageView imageView3 = (ImageView) findViewById(C0415R.id.descrip);
        TextView textView2 = (TextView) findViewById(C0415R.id.tv_name);
        TextView textView3 = (TextView) findViewById(C0415R.id.tv_descrip);
        TextView textView4 = (TextView) findViewById(C0415R.id.download_app_show1);
        TextView textView5 = (TextView) findViewById(C0415R.id.download_app_show2);
        TextView textView6 = (TextView) findViewById(C0415R.id.download_app_show3);
        TextView textView7 = (TextView) findViewById(C0415R.id.download_app_show4);
        TextView textView8 = (TextView) findViewById(C0415R.id.alert_text);
        this.f2676e = (TextView) findViewById(C0415R.id.download_app_downlink);
        this.f2676e.setOnClickListener(this);
        switch (this.f2675d) {
            case 0:
                this.f2673b = CHANNEL_KEY_LEBATTERY;
                RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(-1, -2);
                layoutParams.leftMargin = 40;
                this.f2679h = Const.PACKAGENAME_LE_BATTERY;
                textView.setText(C0415R.string.battery_center);
                imageView2.setBackgroundResource(C0415R.drawable.power_logo);
                imageView3.setBackgroundResource(C0415R.drawable.lebattery_description);
                textView4.setText(C0415R.string.download_app_battery1);
                textView5.setText(C0415R.string.download_app_battery2);
                textView6.setText(C0415R.string.download_app_battery3);
                textView7.setText(C0415R.string.download_app_battery4);
                textView4.setLayoutParams(layoutParams);
                textView5.setLayoutParams(layoutParams);
                textView6.setLayoutParams(layoutParams);
                textView7.setLayoutParams(layoutParams);
                textView8.setVisibility(8);
                this.f2676e.setText(getString(C0415R.string.new_use));
                break;
            case 1:
                this.f2673b = CHANNEL_KEY_LECLOUD;
                RelativeLayout.LayoutParams layoutParams2 = new RelativeLayout.LayoutParams(-2, -2);
                layoutParams2.addRule(13);
                this.f2679h = Const.PACKAGENAME_LE_CLOUD;
                textView.setText(C0415R.string.safe_backup);
                imageView2.setBackgroundResource(C0415R.drawable.lesyn_img_logo);
                textView2.setText(C0415R.string.lecloud);
                textView3.setText(C0415R.string.lecloud_safebackup);
                textView4.setText(C0415R.string.download_app_cloud_sync1);
                textView5.setText(C0415R.string.download_app_cloud_sync2);
                textView6.setText(C0415R.string.download_app_cloud_sync3);
                textView7.setText(C0415R.string.download_app_cloud_sync4);
                textView4.setLayoutParams(layoutParams2);
                textView5.setLayoutParams(layoutParams2);
                textView6.setLayoutParams(layoutParams2);
                textView7.setLayoutParams(layoutParams2);
                textView8.setVisibility(8);
                this.f2676e.setText(getString(C0415R.string.download_app_link));
                break;
            case 3:
                this.f2673b = CHANNEL_KEY_SELF;
                RelativeLayout.LayoutParams layoutParams3 = new RelativeLayout.LayoutParams(-1, -2);
                layoutParams3.leftMargin = 40;
                this.f2679h = Const.PACKAGENAME_APP_LOCK;
                textView.setText(C0415R.string.privacy_safe);
                imageView2.setBackgroundResource(C0415R.drawable.download_app_lock_icon);
                textView2.setText(C0415R.string.privacy_safe);
                textView3.setVisibility(8);
                textView4.setText(C0415R.string.download_app_lock_sync1);
                textView5.setText(C0415R.string.download_app_lock_sync2);
                textView6.setText(C0415R.string.download_app_lock_sync3);
                textView7.setText(C0415R.string.download_app_lock_sync4);
                textView4.setLayoutParams(layoutParams3);
                textView5.setLayoutParams(layoutParams3);
                textView6.setLayoutParams(layoutParams3);
                textView7.setLayoutParams(layoutParams3);
                if (AppUtil.isAppExistence(this, this.f2679h) && mustUpdateAppLock(this)) {
                    textView8.setVisibility(0);
                    textView8.setText(getString(C0415R.string.app_lock_must_update));
                    this.f2676e.setText(getString(C0415R.string.install_text));
                } else {
                    textView8.setVisibility(8);
                    this.f2676e.setText(getString(C0415R.string.new_use));
                }
                break;
            case 4:
                this.f2673b = CHANNEL_KEY_SELF;
                RelativeLayout.LayoutParams layoutParams4 = new RelativeLayout.LayoutParams(-1, -2);
                layoutParams4.leftMargin = 40;
                this.f2679h = Const.PACKAGENAME_KID_MODE;
                textView.setText(C0415R.string.kid_mode);
                imageView2.setBackgroundResource(C0415R.drawable.kid_mode_icon);
                textView2.setText(C0415R.string.kid_mode);
                textView3.setText(C0415R.string.kid_mode_detail);
                textView4.setText(C0415R.string.download_app_kidmode1);
                textView5.setText(C0415R.string.download_app_kidmode2);
                textView6.setText(C0415R.string.download_app_kidmode3);
                textView4.setLayoutParams(layoutParams4);
                textView5.setLayoutParams(layoutParams4);
                textView6.setLayoutParams(layoutParams4);
                textView7.setVisibility(8);
                textView8.setVisibility(8);
                this.f2676e.setText(getString(C0415R.string.new_use));
                break;
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.download_app_downlink /* 2131296979 */:
                if (!TextUtils.isEmpty(this.f2679h)) {
                    if (Const.PACKAGENAME_APP_LOCK.equals(this.f2679h)) {
                        if (AppUtil.isAppExistence(this, this.f2679h)) {
                            if (mustUpdateAppLock(this)) {
                                m1233a(APP_LOCK_FILE_NAME, this, this.f2679h);
                            } else {
                                WflUtils.startPrivatezone(this);
                                finish();
                            }
                        } else {
                            m1233a(APP_LOCK_FILE_NAME, this, this.f2679h);
                        }
                    } else if (AppUtil.isAppExistence(this, this.f2679h)) {
                        if (Const.PACKAGENAME_LE_CLOUD.equals(this.f2679h)) {
                            WflUtils.startLeCloudSyn(this);
                        } else if (Const.PACKAGENAME_LE_BATTERY.equals(this.f2679h)) {
                            DrawerBattery.startLeBattery(this);
                        } else if (Const.PACKAGENAME_KID_MODE.equals(this.f2679h)) {
                            WflUtils.startKidMode(this);
                        }
                        finish();
                    } else if (Const.PACKAGENAME_LE_CLOUD.equals(this.f2679h) || Const.PACKAGENAME_LE_BATTERY.equals(this.f2679h) || Const.PACKAGENAME_KID_MODE.equals(this.f2679h)) {
                        String str = this.f2679h;
                        String str2 = this.f2673b;
                        if (!WflUtils.isNetworkAvailable(this)) {
                            DialogUtil.createManualUpdateDialog(this, 4, null);
                        } else {
                            if (this.f2672a == null) {
                                this.f2672a = new LeSafeUpdate(this, str, 0, str2, false, false, false, new LeSafeUpdate.LeSafeUpdateListenser() { // from class: com.lenovo.safecenter.MainTab.AppDownloadActivity.3
                                    @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                                    public final void onQueryResp(String resultion, LeSafeUpdateInfo lfui) {
                                        Log.i("ydp", "downloadActivity onQueryResp:" + resultion);
                                    }

                                    @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                                    public final void onDownLoadComplete(String path) {
                                        Log.i("ydp", "downloadActivity onDownLoadComplete:" + path);
                                    }

                                    @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                                    public final void onDownLoadException(int errorCode) {
                                        Log.i("ydp", "downloadActivity onDownLoadException:" + errorCode);
                                    }

                                    @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                                    public final void onInstallComplete(boolean succeed) {
                                        Log.i("ydp", "downloadActivity onInstallComplete:" + succeed);
                                    }
                                });
                            }
                            this.f2672a.upDate(true);
                        }
                    }
                }
                break;
            case C0415R.id.base_title_left /* 2131297465 */:
                Intent i = new Intent(this, (Class<?>) LeSafeMainActivity.class);
                i.setFlags(67108864);
                startActivity(i);
                overridePendingTransition(C0415R.anim.slide_out_right, C0415R.anim.slide_in_left);
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    public static boolean mustUpdateAppLock(Context context) {
        return AppUtil.getAppVersionCode(context, Const.PACKAGENAME_APP_LOCK) < 3900369;
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        unregisterReceiver(this.f2678g);
        super.onDestroy();
    }

    public static void startAppDownloadActivity(Context context, int type, boolean isEntry) {
        Intent down = new Intent(context, (Class<?>) AppDownloadActivity.class);
        down.putExtra("type", (byte) type);
        down.putExtra("isEntry", isEntry);
        context.startActivity(down);
    }

    /* JADX INFO: renamed from: a */
    private void m1233a(final String fileName, final Context context, final String packageName) {
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.MainTab.AppDownloadActivity.4
            @Override // java.lang.Runnable
            public final void run() throws Throwable {
                if (AppDownloadActivity.this.f2680i) {
                    WflUtils.sendMessageToHandler(0, AppDownloadActivity.this.getString(C0415R.string.installing_text), AppDownloadActivity.this.f2677f);
                    return;
                }
                WflUtils.sendMessageToHandler(0, AppDownloadActivity.this.getString(C0415R.string.installing_pleasewait_text), AppDownloadActivity.this.f2677f);
                AppDownloadActivity.this.f2680i = true;
                FileOutputStream fos = null;
                File nbFile = null;
                try {
                    try {
                        String filePath = context.getCacheDir() + CookieSpec.PATH_DELIM + fileName;
                        File nbFile2 = new File(filePath);
                        try {
                            if (!nbFile2.exists()) {
                                InputStream open = context.getResources().getAssets().open(fileName);
                                byte[] buffer = new byte[open.available()];
                                open.read(buffer);
                                FileOutputStream fos2 = new FileOutputStream(nbFile2);
                                try {
                                    fos2.write(buffer);
                                    fos = fos2;
                                } catch (Exception e) {
                                    e = e;
                                    nbFile = nbFile2;
                                    fos = fos2;
                                    e.printStackTrace();
                                    if (fos != null) {
                                        try {
                                            fos.close();
                                        } catch (IOException e2) {
                                            e2.printStackTrace();
                                        }
                                    }
                                } catch (Throwable th) {
                                    th = th;
                                    fos = fos2;
                                    if (fos != null) {
                                        try {
                                            fos.close();
                                        } catch (IOException e3) {
                                            e3.printStackTrace();
                                        }
                                    }
                                    throw th;
                                }
                            }
                            if (fos != null) {
                                try {
                                    fos.close();
                                } catch (IOException e4) {
                                    e4.printStackTrace();
                                    nbFile = nbFile2;
                                }
                            }
                            nbFile = nbFile2;
                        } catch (Exception e5) {
                            e = e5;
                            nbFile = nbFile2;
                        } catch (Throwable th2) {
                            th = th2;
                        }
                    } catch (Throwable th3) {
                        th = th3;
                    }
                } catch (Exception e6) {
                    e = e6;
                }
                String command = "chmod 777 /data/data/com.lenovo.safecenter/cache/" + fileName;
                Runtime runtime = Runtime.getRuntime();
                try {
                    runtime.exec(command);
                    runtime.exec("chmod 777 /data/data/com.lenovo.safecenter/cache");
                    Thread.sleep(1000L);
                } catch (Exception e7) {
                    e7.printStackTrace();
                }
                if (nbFile != null && nbFile.exists() && !CMDHelper.installAPK(context, "/data/data/com.lenovo.safecenter/cache/" + fileName, packageName)) {
                    Intent intent = new Intent("android.intent.action.VIEW");
                    intent.setDataAndType(Uri.parse("file:///data/data/com.lenovo.safecenter/cache/" + fileName), "application/vnd.android.package-archive");
                    intent.setFlags(268435456);
                    AppDownloadActivity.this.startActivity(intent);
                    AppDownloadActivity.this.f2680i = false;
                }
            }
        }).start();
    }

    public static void copyAssetsFilesInstall(final String fileName, final String packageName, final Context context, final Handler handler, final int what) {
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.MainTab.AppDownloadActivity.5
            @Override // java.lang.Runnable
            public final void run() throws Throwable {
                WflUtils.sendMessageToHandler(what, context.getString(C0415R.string.installing_pleasewait_text), handler);
                FileOutputStream fos = null;
                File nbFile = null;
                try {
                    try {
                        String filePath = context.getCacheDir() + CookieSpec.PATH_DELIM + fileName;
                        File nbFile2 = new File(filePath);
                        try {
                            if (!nbFile2.exists()) {
                                InputStream open = context.getResources().getAssets().open(fileName);
                                byte[] buffer = new byte[open.available()];
                                open.read(buffer);
                                FileOutputStream fos2 = new FileOutputStream(nbFile2);
                                try {
                                    fos2.write(buffer);
                                    fos = fos2;
                                } catch (Exception e) {
                                    e = e;
                                    nbFile = nbFile2;
                                    fos = fos2;
                                    e.printStackTrace();
                                    if (fos != null) {
                                        try {
                                            fos.close();
                                        } catch (IOException e2) {
                                            e2.printStackTrace();
                                        }
                                    }
                                } catch (Throwable th) {
                                    th = th;
                                    fos = fos2;
                                    if (fos != null) {
                                        try {
                                            fos.close();
                                        } catch (IOException e3) {
                                            e3.printStackTrace();
                                        }
                                    }
                                    throw th;
                                }
                            }
                            if (fos != null) {
                                try {
                                    fos.close();
                                } catch (IOException e4) {
                                    e4.printStackTrace();
                                    nbFile = nbFile2;
                                }
                            }
                            nbFile = nbFile2;
                        } catch (Exception e5) {
                            e = e5;
                            nbFile = nbFile2;
                        } catch (Throwable th2) {
                            th = th2;
                        }
                    } catch (Exception e6) {
                        e = e6;
                    }
                    String command = "chmod 777 /data/data/com.lenovo.safecenter/cache/" + fileName;
                    Runtime runtime = Runtime.getRuntime();
                    try {
                        runtime.exec(command);
                        runtime.exec("chmod 777 /data/data/com.lenovo.safecenter/cache");
                        Thread.sleep(1000L);
                    } catch (Exception e7) {
                    }
                    if (nbFile != null && nbFile.exists() && !CMDHelper.installAPK(context, "/data/data/com.lenovo.safecenter/cache/" + fileName, packageName)) {
                        Intent intent = new Intent("android.intent.action.VIEW");
                        intent.setDataAndType(Uri.parse("file:///data/data/com.lenovo.safecenter/cache/" + fileName), "application/vnd.android.package-archive");
                        intent.setFlags(268435456);
                        context.startActivity(intent);
                    }
                } catch (Throwable th3) {
                    th = th3;
                }
            }
        }).start();
    }

    public static void copyAssetsFilesInstallAtBackgroud(final String fileName, final Context context, final String packageName) {
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.MainTab.AppDownloadActivity.6
            @Override // java.lang.Runnable
            public final void run() throws Throwable {
                FileOutputStream fos = null;
                File nbFile = null;
                try {
                    try {
                        String filePath = context.getCacheDir() + CookieSpec.PATH_DELIM + fileName;
                        File nbFile2 = new File(filePath);
                        try {
                            if (!nbFile2.exists()) {
                                InputStream open = context.getResources().getAssets().open(fileName);
                                byte[] buffer = new byte[open.available()];
                                open.read(buffer);
                                FileOutputStream fos2 = new FileOutputStream(nbFile2);
                                try {
                                    fos2.write(buffer);
                                    fos = fos2;
                                } catch (Exception e) {
                                    e = e;
                                    nbFile = nbFile2;
                                    fos = fos2;
                                    e.printStackTrace();
                                    if (fos != null) {
                                        try {
                                            fos.close();
                                        } catch (IOException e2) {
                                            e2.printStackTrace();
                                        }
                                    }
                                } catch (Throwable th) {
                                    th = th;
                                    fos = fos2;
                                    if (fos != null) {
                                        try {
                                            fos.close();
                                        } catch (IOException e3) {
                                            e3.printStackTrace();
                                        }
                                    }
                                    throw th;
                                }
                            }
                            if (fos != null) {
                                try {
                                    fos.close();
                                } catch (IOException e4) {
                                    e4.printStackTrace();
                                    nbFile = nbFile2;
                                }
                            }
                            nbFile = nbFile2;
                        } catch (Exception e5) {
                            e = e5;
                            nbFile = nbFile2;
                        } catch (Throwable th2) {
                            th = th2;
                        }
                    } catch (Throwable th3) {
                        th = th3;
                    }
                } catch (Exception e6) {
                    e = e6;
                }
                String command = "chmod 777 /data/data/com.lenovo.safecenter/cache/" + fileName;
                Runtime runtime = Runtime.getRuntime();
                try {
                    runtime.exec(command);
                    runtime.exec("chmod 777 /data/data/com.lenovo.safecenter/cache");
                    Thread.sleep(1000L);
                } catch (Exception e7) {
                }
                if (nbFile != null && nbFile.exists()) {
                    if (CMDHelper.installAPK(context, "/data/data/com.lenovo.safecenter/cache/" + fileName, packageName)) {
                        WflUtils.Log("i", "wu0wu", "install at backgroud fileName=" + fileName);
                    } else {
                        WflUtils.Log("i", "wu0wu", "install at backgroud fileName=" + fileName + "is error");
                    }
                }
            }
        }).start();
    }
}
