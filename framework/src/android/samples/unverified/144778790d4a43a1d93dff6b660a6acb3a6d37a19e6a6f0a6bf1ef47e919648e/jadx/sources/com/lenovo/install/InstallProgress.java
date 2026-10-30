package com.lenovo.install;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageParser;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.performance.DataLayerManagerAccelerate;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.notificationintercept.InterceptUtils;
import com.lenovo.safecenter.support.CMDHelper;
import com.tencent.tmsecure.utils.Log;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class InstallProgress extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: c */
    private PackageParser.Package f1040c;

    /* JADX INFO: renamed from: d */
    private ImageView f1041d;

    /* JADX INFO: renamed from: e */
    private ImageView f1042e;

    /* JADX INFO: renamed from: f */
    private ImageView f1043f;

    /* JADX INFO: renamed from: g */
    private ImageView f1044g;

    /* JADX INFO: renamed from: h */
    private ImageView f1045h;

    /* JADX INFO: renamed from: i */
    private TextView f1046i;

    /* JADX INFO: renamed from: j */
    private TextView f1047j;

    /* JADX INFO: renamed from: k */
    private TextView f1048k;

    /* JADX INFO: renamed from: l */
    private TextView f1049l;

    /* JADX INFO: renamed from: m */
    private TextView f1050m;

    /* JADX INFO: renamed from: n */
    private TextView f1051n;

    /* JADX INFO: renamed from: o */
    private RelativeLayout f1052o;

    /* JADX INFO: renamed from: p */
    private RelativeLayout f1053p;

    /* JADX INFO: renamed from: q */
    private boolean f1054q;

    /* JADX INFO: renamed from: r */
    private Intent f1055r;

    /* JADX INFO: renamed from: a */
    private int f1038a = 0;

    /* JADX INFO: renamed from: b */
    private HandlerC0063a f1039b = new HandlerC0063a();

    /* JADX INFO: renamed from: s */
    private boolean f1056s = true;

    /* JADX INFO: renamed from: t */
    private boolean f1057t = true;

    /* JADX INFO: renamed from: com.lenovo.install.InstallProgress$a */
    class HandlerC0063a extends Handler {
        HandlerC0063a() {
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            List<ResolveInfo> list;
            switch (msg.what) {
                case 1:
                    InstallProgress.this.findViewById(C0415R.id.layout_installt).setVisibility(8);
                    if (InstallProgress.this.f1054q) {
                        if (!InstallProgress.this.getIntent().getBooleanExtra("has_boot", false) || InstallProgress.this.getBootAppInfoFromRealAllCls(InstallProgress.this, InstallProgress.this.f1040c.packageName) == null) {
                            InstallProgress.this.f1053p.setVisibility(8);
                        } else if (DataLayerManagerAccelerate.isManageTheBoot(InstallProgress.this, InstallProgress.this.f1040c.packageName)) {
                            InstallProgress.this.f1053p.setVisibility(0);
                        }
                        InstallProgress.this.f1049l.setText(C0415R.string.install_success);
                        InstallProgress.this.f1049l.setTextColor(InstallProgress.this.getResources().getColor(C0415R.color.green5));
                        InstallProgress.this.f1047j.setEnabled(true);
                        InstallProgress.this.f1047j.setTextColor(InstallProgress.this.getResources().getColor(C0415R.color.white));
                        InstallProgress.this.f1055r = InstallProgress.this.getPackageManager().getLaunchIntentForPackage(InstallProgress.this.f1040c.packageName);
                        boolean enabled = false;
                        if (InstallProgress.this.f1055r != null && (list = InstallProgress.this.getPackageManager().queryIntentActivities(InstallProgress.this.f1055r, 0)) != null && list.size() > 0) {
                            enabled = true;
                        }
                        if (enabled) {
                            InstallProgress.this.f1048k.setEnabled(true);
                            InstallProgress.this.f1048k.setTextColor(InstallProgress.this.getResources().getColor(C0415R.color.white));
                        }
                        InstallProgress.this.initBoot(InstallProgress.this.f1040c.packageName);
                        if (InterceptUtils.notificationFilter(InstallProgress.this, InstallProgress.this.f1040c.packageName)) {
                            InstallProgress.this.f1052o.setVisibility(8);
                        } else {
                            InstallProgress.this.f1052o.setVisibility(0);
                            InstallProgress.this.initAdv(InstallProgress.this.f1040c.packageName);
                        }
                    } else {
                        InstallProgress.this.findViewById(C0415R.id.layout_installt).setVisibility(8);
                        InstallProgress.this.f1049l.setText(C0415R.string.install_fail);
                        InstallProgress.this.f1049l.setTextColor(InstallProgress.this.getResources().getColor(C0415R.color.red1));
                        InstallProgress.this.f1048k.setVisibility(8);
                        InstallProgress.this.f1047j.setEnabled(true);
                        InstallProgress.this.f1047j.setText(C0415R.string.ok);
                        InstallProgress.this.f1047j.setTextColor(InstallProgress.this.getResources().getColor(C0415R.color.white));
                    }
                    break;
                case 2:
                    InstallProgress.this.startActivity(InstallProgress.this.f1055r);
                    InstallProgress.this.finish();
                    break;
            }
        }
    }

    /* JADX WARN: Type inference failed for: r2v9, types: [com.lenovo.install.InstallProgress$1] */
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.installprogress);
        findView();
        try {
            this.f1040c = PackageUtil.getPackageInfo(Uri.parse(getIntent().getStringExtra("uri")));
            PackageUtil.AppSnippet as = PackageUtil.getAppSnippet(this, this.f1040c.applicationInfo, Uri.parse(getIntent().getStringExtra("uri")));
            this.f1041d.setImageDrawable(as.f1061b);
            this.f1046i.setText(as.f1060a);
            new Thread() { // from class: com.lenovo.install.InstallProgress.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    HttpUtils.isInstall = true;
                    InstallProgress.this.f1054q = CMDHelper.installAPK(InstallProgress.this, Uri.parse(InstallProgress.this.getIntent().getStringExtra("uri")).getPath(), InstallProgress.this.f1040c.packageName);
                    InstallProgress.this.f1039b.sendEmptyMessage(1);
                }
            }.start();
        } catch (Exception e) {
            e.printStackTrace();
            finish();
        }
    }

    public void translate(ImageView view) {
        Animation animation = AnimationUtils.loadAnimation(this, C0415R.anim.scanvirus_in_install);
        animation.setDuration(1000L);
        animation.setRepeatCount(-1);
        view.startAnimation(animation);
    }

    public void findView() {
        this.f1041d = (ImageView) findViewById(C0415R.id.appicon);
        this.f1046i = (TextView) findViewById(C0415R.id.appname);
        this.f1052o = (RelativeLayout) findViewById(C0415R.id.adver_lin);
        this.f1053p = (RelativeLayout) findViewById(C0415R.id.boot_lin);
        this.f1047j = (TextView) findViewById(C0415R.id.btn_cancel);
        this.f1048k = (TextView) findViewById(C0415R.id.btn_install);
        this.f1049l = (TextView) findViewById(C0415R.id.txt_install);
        this.f1049l.setText(C0415R.string.installing);
        this.f1042e = (ImageView) findViewById(C0415R.id.noti_icon);
        this.f1043f = (ImageView) findViewById(C0415R.id.boot_icon);
        this.f1044g = (ImageView) findViewById(C0415R.id.imageview03);
        this.f1045h = (ImageView) findViewById(C0415R.id.imageview04);
        this.f1047j.setEnabled(false);
        this.f1048k.setEnabled(false);
        this.f1043f.setOnClickListener(this);
        this.f1042e.setOnClickListener(this);
        this.f1047j.setOnClickListener(this);
        this.f1048k.setOnClickListener(this);
        this.f1050m = (TextView) findViewById(C0415R.id.boot);
        this.f1051n = (TextView) findViewById(C0415R.id.adv);
        findViewById(C0415R.id.virus_warning).setVisibility(getIntent().getBooleanExtra("has_virus", false) ? 0 : 8);
        translate(this.f1045h);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.btn_cancel /* 2131296947 */:
                updateData(this.f1040c.packageName);
                finish();
                break;
            case C0415R.id.btn_install /* 2131297135 */:
                updateData(this.f1040c.packageName);
                Log.m2636i("www", this.f1055r.getComponent().getPackageName() + "===" + this.f1055r.getComponent().getClassName());
                startActivity(this.f1055r);
                finish();
                break;
            case C0415R.id.boot_icon /* 2131297163 */:
                if (this.f1056s) {
                    this.f1056s = false;
                    this.f1043f.setImageResource(C0415R.drawable.dark_off);
                    this.f1050m.setText(C0415R.string.install_boot_stitle_off);
                    DataLayerManagerAccelerate.setAppBoot(this, getBootAppInfoFromRealAllCls(this, this.f1040c.packageName), false);
                } else {
                    this.f1056s = true;
                    this.f1043f.setImageResource(C0415R.drawable.dark_on);
                    this.f1050m.setText(C0415R.string.install_boot_stitle_on);
                    DataLayerManagerAccelerate.setAppBoot(this, getBootAppInfoFromRealAllCls(this, this.f1040c.packageName), true);
                }
                break;
            case C0415R.id.noti_icon /* 2131297167 */:
                if (this.f1057t) {
                    this.f1057t = false;
                    this.f1042e.setImageResource(C0415R.drawable.dark_off);
                    this.f1051n.setText(C0415R.string.install_adv_stitle_off);
                } else {
                    this.f1057t = true;
                    this.f1042e.setImageResource(C0415R.drawable.dark_on);
                    this.f1051n.setText(C0415R.string.install_adv_stitle_on);
                }
                break;
        }
    }

    public void updateData(String pkgName) {
        if (this.f1052o.getVisibility() == 0) {
            if (this.f1057t) {
                InterceptUtils.notificationAllow(this, pkgName);
            } else {
                InterceptUtils.notificationForbid(this, pkgName);
            }
        }
    }

    public void initBoot(String pkgName) {
        if (getIntent().getBooleanExtra("has_boot", false)) {
            if (DataLayerManagerAccelerate.isAppCanBoot(this, pkgName)) {
                this.f1056s = true;
                this.f1043f.setImageResource(C0415R.drawable.dark_on);
                this.f1050m.setText(C0415R.string.install_boot_stitle_on);
            } else {
                this.f1056s = false;
                this.f1043f.setImageResource(C0415R.drawable.dark_off);
                this.f1050m.setText(C0415R.string.install_boot_stitle_off);
            }
        }
    }

    public void initAdv(String pkgName) {
        if (InterceptUtils.getNotificationAllow(this, pkgName)) {
            this.f1057t = true;
            this.f1042e.setImageResource(C0415R.drawable.dark_on);
            this.f1051n.setText(C0415R.string.install_adv_stitle_on);
        } else {
            this.f1057t = false;
            this.f1042e.setImageResource(C0415R.drawable.dark_off);
            this.f1051n.setText(C0415R.string.install_adv_stitle_off);
        }
    }

    public String[] getBootAppInfoFromRealAllCls(Context context, String pkgname) {
        String[] strs = new String[2];
        PackageManager packageManager = context.getPackageManager();
        Intent intent = new Intent("android.intent.action.BOOT_COMPLETED");
        List<ResolveInfo> resolves = packageManager.queryBroadcastReceivers(intent, 600);
        for (ResolveInfo resolve : resolves) {
            ApplicationInfo app = resolve.activityInfo.applicationInfo;
            if ((app.flags & 1) == 0 && app.packageName.equals(pkgname)) {
                packageManager.getComponentEnabledSetting(new ComponentName(app.packageName, resolve.activityInfo.name));
                strs[0] = app.packageName;
                strs[1] = resolve.activityInfo.name;
                return strs;
            }
        }
        return null;
    }
}
