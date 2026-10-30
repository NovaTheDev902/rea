package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.graphics.drawable.BitmapDrawable;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.text.TextUtils;
import android.util.DisplayMetrics;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.util.Tools;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.NewFunctionNoticeManager;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.io.File;
import java.util.Observable;
import java.util.Observer;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class SplashActivity extends Activity implements Observer {

    /* JADX INFO: renamed from: a */
    private SharedPreferences f2814a;

    /* JADX INFO: renamed from: b */
    private LeSafeObservable f2815b;

    /* JADX INFO: renamed from: c */
    private TextView f2816c;

    /* JADX INFO: renamed from: d */
    private Bitmap f2817d;

    /* JADX INFO: renamed from: e */
    private Bitmap f2818e;

    /* JADX INFO: renamed from: f */
    private Bitmap f2819f;

    /* JADX INFO: renamed from: g */
    private Bitmap f2820g;

    /* JADX INFO: renamed from: h */
    private Bitmap f2821h;

    /* JADX INFO: renamed from: i */
    private Bitmap f2822i;

    /* JADX INFO: renamed from: j */
    private boolean f2823j = false;

    /* JADX INFO: renamed from: k */
    private Handler f2824k = new Handler() { // from class: com.lenovo.safecenter.MainTab.SplashActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            if (!SplashActivity.this.isFinishing()) {
                switch (msg.what) {
                    case 1:
                        SplashActivity.this.m1270b();
                        break;
                    case 2:
                        if (!SplashActivity.this.isFinishing()) {
                            SplashActivity.m1267a(SplashActivity.this);
                            if (!Const.mDefaultPreference.getBoolean("firstBoot", true)) {
                                SplashActivity.this.f2816c.setVisibility(8);
                                SplashActivity.this.f2824k.sendMessageDelayed(SplashActivity.this.f2824k.obtainMessage(1), 1000L);
                            } else {
                                SplashActivity.this.f2816c.setVisibility(0);
                            }
                            DataLayerManager.initApplication(SplashActivity.this.getApplicationContext());
                        } else {
                            return;
                        }
                        break;
                }
                super.handleMessage(msg);
            }
        }
    };

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.MainTab.SplashActivity$2] */
    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1267a(SplashActivity x0) {
        new Thread() { // from class: com.lenovo.safecenter.MainTab.SplashActivity.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                if (Const.isFirstInstallFloatwindowShortCut()) {
                    Tools.createFloatwindowShortCut(SplashActivity.this, C0415R.drawable.shortcut_app_icon, C0415R.string.switcher_app_name);
                    Const.setFirstInstallFloatwindowShortCut();
                }
                super.run();
            }
        }.start();
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_splash_layout);
        this.f2814a = PreferenceManager.getDefaultSharedPreferences(getApplicationContext());
        this.f2815b = LeSafeObservable.get(getApplicationContext());
        this.f2815b.addObserver(this);
        this.f2816c = (TextView) findViewById(C0415R.id.splash_initdata);
        this.f2823j = m1268a();
        if (this.f2823j) {
            this.f2817d = BitmapFactory.decodeFile(getFilesDir() + CookieSpec.PATH_DELIM + Const.FILENAME_HOLIDAY_IMG);
            if (this.f2817d == null) {
                this.f2823j = false;
            }
        }
        if (this.f2823j) {
            DisplayMetrics displayMetrics = new DisplayMetrics();
            getWindowManager().getDefaultDisplay().getMetrics(displayMetrics);
            this.f2817d = zoomImg(this.f2817d, displayMetrics.widthPixels, displayMetrics.heightPixels);
            ImageView imageView = (ImageView) findViewById(C0415R.id.splash_icon);
            TextView textView = (TextView) findViewById(C0415R.id.splash_lesafe);
            ImageView imageView2 = (ImageView) findViewById(C0415R.id.splash_detail);
            TextView textView2 = (TextView) findViewById(C0415R.id.splash_copyright);
            imageView.setVisibility(8);
            textView.setVisibility(8);
            imageView2.setVisibility(8);
            textView2.setVisibility(8);
            ((RelativeLayout) findViewById(C0415R.id.splash_bg)).setBackgroundDrawable(new BitmapDrawable(this.f2817d));
        } else {
            this.f2821h = WflUtils.readBitmap(this, C0415R.drawable.icon_trial_version);
        }
        this.f2824k.sendEmptyMessage(2);
    }

    /* JADX INFO: renamed from: a */
    private boolean m1268a() {
        String id = Const.getHolidayImgId();
        try {
            long lStartTime = Long.valueOf(this.f2814a.getString(Const.KEY_HOLIDAY_IMG_STARTTIME, null)).longValue();
            long lEndTime = Long.valueOf(this.f2814a.getString(Const.KEY_HOLIDAY_IMG_ENDTIME, null)).longValue();
            File file = new File(getFilesDir(), Const.FILENAME_HOLIDAY_IMG);
            boolean isFileExists = file.exists();
            long lCurrTime = System.currentTimeMillis();
            return !TextUtils.isEmpty(id) && lCurrTime < lEndTime && lCurrTime > lStartTime && isFileExists;
        } catch (Exception e) {
            return false;
        }
    }

    public static Bitmap zoomImg(Bitmap bm, int newWidth, int newHeight) {
        int width = bm.getWidth();
        int height = bm.getHeight();
        float scaleWidth = newWidth / width;
        float scaleHeight = newHeight / height;
        Matrix matrix = new Matrix();
        matrix.postScale(scaleWidth, scaleHeight);
        Bitmap newbm = Bitmap.createBitmap(bm, 0, 0, width, height, matrix, true);
        return newbm;
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1270b() {
        if (!isFinishing()) {
            try {
                if (getSharedPreferences("antitheft", 0).getBoolean("help" + getPackageManager().getPackageInfo(getPackageName(), 0).versionCode, true)) {
                    NewFunctionNoticeManager.init(this);
                    Intent intent = new Intent(getApplicationContext(), (Class<?>) HelpActivity.class);
                    startActivity(intent);
                    finish();
                } else {
                    Intent intent2 = new Intent(getApplicationContext(), (Class<?>) LeSafeMainActivity.class);
                    startActivity(intent2);
                    finish();
                }
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    @Override // java.util.Observer
    public void update(Observable observable, Object data) {
        if (data instanceof Integer) {
            switch (((Integer) data).intValue()) {
                case 20:
                    this.f2816c.setText(C0415R.string.init_perm);
                    break;
                case 21:
                    this.f2816c.setText(C0415R.string.init_virus);
                    break;
                case 22:
                    m1270b();
                    break;
            }
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        if (this.f2817d != null) {
            this.f2817d.recycle();
        }
        if (this.f2818e != null) {
            this.f2818e.recycle();
        }
        if (this.f2819f != null) {
            this.f2819f.recycle();
        }
        if (this.f2820g != null) {
            this.f2820g.recycle();
        }
        if (this.f2821h != null) {
            this.f2821h.recycle();
        }
        if (this.f2822i != null) {
            this.f2822i.recycle();
        }
        this.f2815b.deleteObserver(this);
        this.f2815b = null;
        super.onDestroy();
    }
}
