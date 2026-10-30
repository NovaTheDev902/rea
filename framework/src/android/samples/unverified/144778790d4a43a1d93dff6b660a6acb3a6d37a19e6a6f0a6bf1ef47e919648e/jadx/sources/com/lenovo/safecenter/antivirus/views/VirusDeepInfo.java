package com.lenovo.safecenter.antivirus.views;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.p001pm.IPackageStatsObserver;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageStats;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.format.Formatter;
import android.view.View;
import android.widget.AppSecurityPermissions;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.support.DeleteSDFileBroadcast;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import java.io.File;

/* JADX INFO: loaded from: classes.dex */
public class VirusDeepInfo extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private TextView f3342a;

    /* JADX INFO: renamed from: b */
    private TextView f3343b;

    /* JADX INFO: renamed from: c */
    private TextView f3344c;

    /* JADX INFO: renamed from: d */
    private TextView f3345d;

    /* JADX INFO: renamed from: e */
    private TextView f3346e;

    /* JADX INFO: renamed from: f */
    private TextView f3347f;

    /* JADX INFO: renamed from: g */
    private ImageView f3348g;

    /* JADX INFO: renamed from: h */
    private Button f3349h;

    /* JADX INFO: renamed from: i */
    private String f3350i;

    /* JADX INFO: renamed from: j */
    private boolean f3351j;

    /* JADX INFO: renamed from: k */
    private String f3352k;

    /* JADX INFO: renamed from: l */
    private ApplicationInfo f3353l;

    /* JADX INFO: renamed from: m */
    private PackageManager f3354m;

    /* JADX INFO: renamed from: n */
    private BinderC0515b f3355n;

    /* JADX INFO: renamed from: o */
    private PackageStats f3356o;

    /* JADX INFO: renamed from: p */
    private C0514a f3357p;

    /* JADX INFO: renamed from: q */
    private C0516c f3358q;

    /* JADX INFO: renamed from: r */
    private Handler f3359r = new Handler() { // from class: com.lenovo.safecenter.antivirus.views.VirusDeepInfo.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    VirusDeepInfo.m1428a(VirusDeepInfo.this, msg);
                    break;
                case 2:
                    VirusDeepInfo.m1432b(VirusDeepInfo.this, msg);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1428a(VirusDeepInfo x0, Message x1) {
        PackageStats packageStats = (PackageStats) x1.getData().getParcelable("pStats");
        long j = packageStats.cacheSize + packageStats.codeSize + packageStats.dataSize;
        if (x0.f3356o == null) {
            x0.f3356o = packageStats;
            x0.f3344c.setText(String.format(x0.getString(C0415R.string.antivirusvirus_size), x0.m1427a(j)));
        } else if (j != x0.f3356o.cacheSize + x0.f3356o.codeSize + x0.f3356o.dataSize) {
            x0.f3344c.setText(String.format(x0.getString(C0415R.string.antivirusvirus_size), x0.m1427a(j)));
        }
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m1432b(VirusDeepInfo x0, Message x1) {
        x0.f3344c.setText(String.format(x0.getString(C0415R.string.antivirusvirus_size), x0.m1427a(new File(x1.obj.toString()).length())));
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antivirusdeepvirusviewer);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.virus_info, (Integer) null);
        this.f3342a = (TextView) findViewById(C0415R.id.antivirusdeeptext_showtitle);
        this.f3343b = (TextView) findViewById(C0415R.id.antivirusdeeptext_version);
        this.f3344c = (TextView) findViewById(C0415R.id.antivirusdeeptext_size);
        this.f3345d = (TextView) findViewById(C0415R.id.antivirusdeeptext_info);
        this.f3348g = (ImageView) findViewById(C0415R.id.antivirusdeepimage_icon);
        this.f3346e = (TextView) findViewById(C0415R.id.antivirusdeeptext_virusstate);
        this.f3347f = (TextView) findViewById(C0415R.id.antivirusdeeptext_virusadvice);
        this.f3349h = (Button) findViewById(C0415R.id.antivirusdeepvirusinfo_uninstall);
        this.f3350i = getIntent().getStringExtra(QueryPermissions.PACKAGENAME);
        this.f3351j = getIntent().getBooleanExtra("isSD", false);
        this.f3352k = getIntent().getStringExtra("filepath");
        this.f3355n = new BinderC0515b();
        this.f3357p = new C0514a(this);
        this.f3358q = new C0516c(this);
        registerAction();
        this.f3354m = getPackageManager();
        m1430a(this.f3350i, this.f3351j, this.f3352k);
        LinearLayout permsView = (LinearLayout) findViewById(C0415R.id.antivirusdeeppermissions_section);
        if (!this.f3351j) {
            AppSecurityPermissions asp = new AppSecurityPermissions(this, this.f3353l.packageName);
            if (asp.getPermissionCount() > 0) {
                permsView.setVisibility(0);
                LinearLayout securityList = (LinearLayout) permsView.findViewById(C0415R.id.antivirusdeepsecurity_settings_list);
                securityList.addView(asp.getPermissionsView());
            } else {
                permsView.setVisibility(8);
            }
            this.f3349h.setText(C0415R.string.antivirusvirus_uninstall);
        } else {
            permsView.setVisibility(8);
            this.f3349h.setText(C0415R.string.delete);
        }
        this.f3349h.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.VirusDeepInfo.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!VirusDeepInfo.this.f3351j) {
                    VirusDeepInfo.this.removePackageActivity(VirusDeepInfo.this.f3350i);
                } else {
                    VirusDeepInfo.this.deleteApkFromSD(VirusDeepInfo.this.f3352k);
                }
            }
        });
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void removePackageActivity(String pkgName) {
        Uri packageURI = Uri.parse("package:" + pkgName);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        startActivity(uninstallIntent);
    }

    public void deleteApkFromSD(String filePath) {
        Intent intent = new Intent();
        intent.setAction(DeleteSDFileBroadcast.DELETE_SD_FILE);
        intent.putExtra("filePath", filePath);
        sendBroadcast(intent);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.VirusDeepInfo$a */
    class C0514a extends BroadcastReceiver {

        /* JADX INFO: renamed from: a */
        Context f3362a;

        public C0514a(Context c) {
            this.f3362a = c;
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.PACKAGE_REMOVED")) {
                String packageName = intent.getDataString().substring(8);
                if (packageName.equals(VirusDeepInfo.this.f3350i)) {
                    VirusDeepInfo.this.finish();
                }
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.VirusDeepInfo$c */
    class C0516c extends BroadcastReceiver {

        /* JADX INFO: renamed from: a */
        Context f3365a;

        public C0516c(Context c) {
            this.f3365a = c;
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals(DeleteSDFileBroadcast.DELETE_SD_FILE_COMPLETE)) {
                String filePath = intent.getStringExtra("filePath");
                if (filePath.equals(VirusDeepInfo.this.f3352k)) {
                    boolean sucess = intent.getBooleanExtra("sucess", false);
                    if (sucess) {
                        VirusDeepInfo.this.finish();
                    }
                }
            }
        }
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.intent.action.PACKAGE_REMOVED");
        filter.addDataScheme("package");
        registerReceiver(this.f3357p, filter);
        IntentFilter filter2 = new IntentFilter();
        filter2.addAction(DeleteSDFileBroadcast.DELETE_SD_FILE_COMPLETE);
        registerReceiver(this.f3358q, filter2);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f3357p);
        unregisterReceiver(this.f3358q);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        String advice;
        PackageInfo pkgInfo;
        super.onResume();
        String state = getString(C0415R.string.antivirusvirus_state);
        String advice2 = getString(C0415R.string.antivirusvirus_readvice);
        if (getIntent().getStringExtra("desc") == null || getIntent().getStringExtra("desc").equals("")) {
            this.f3345d.setText(C0415R.string.antivirusvirus_dangerousdesc);
        } else {
            this.f3345d.setText(getIntent().getStringExtra("desc"));
        }
        String state2 = String.format(state, getString(C0415R.string.antivirusvirus_statedescone));
        if (this.f3351j) {
            advice = String.format(advice2, getString(C0415R.string.antivirusvirus_advice_delete));
        } else {
            advice = String.format(advice2, getString(C0415R.string.antivirusvirus_readviceone));
        }
        this.f3346e.setText(state2);
        this.f3347f.setText(advice);
        try {
            if (this.f3351j) {
                pkgInfo = this.f3354m.getPackageArchiveInfo(this.f3352k, 64);
            } else {
                pkgInfo = this.f3354m.getPackageInfo(this.f3353l.packageName, 8192);
            }
            this.f3348g.setImageDrawable(this.f3353l.loadIcon(this.f3354m));
            this.f3342a.setText(this.f3353l.loadLabel(this.f3354m));
            if (pkgInfo == null || pkgInfo.versionName == null) {
                this.f3343b.setVisibility(4);
            } else {
                this.f3343b.setVisibility(0);
                this.f3343b.setText(String.format(getString(C0415R.string.antivirusvirus_version), pkgInfo.versionName));
            }
            if (!this.f3351j) {
                if (this.f3353l != null && this.f3353l.packageName != null) {
                    this.f3354m.getPackageSizeInfo(this.f3353l.packageName, this.f3355n);
                }
            } else {
                Message msg = this.f3359r.obtainMessage(2);
                msg.obj = this.f3352k;
                this.f3359r.sendMessage(msg);
            }
            TrackEvent.trackResume(this);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: renamed from: a */
    private boolean m1430a(String packageName, boolean isSD, String filePath) {
        try {
            if (!isSD) {
                this.f3353l = getPackageManager().getApplicationInfo(packageName, 8192);
            } else {
                PackageInfo packageInfo = this.f3354m.getPackageArchiveInfo(filePath, 64);
                this.f3353l = packageInfo.applicationInfo;
            }
            return true;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: a */
    private String m1427a(long size) {
        if (size == -1) {
            return null;
        }
        return Formatter.formatFileSize(this, size);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.VirusDeepInfo$b */
    class BinderC0515b extends IPackageStatsObserver.Stub {
        BinderC0515b() {
        }

        @Override // android.content.p001pm.IPackageStatsObserver
        public final void onGetStatsCompleted(PackageStats pStats, boolean succeeded) {
            Message msg = VirusDeepInfo.this.f3359r.obtainMessage(1);
            Bundle data = new Bundle();
            data.putParcelable("pStats", pStats);
            msg.setData(data);
            VirusDeepInfo.this.f3359r.sendMessage(msg);
        }
    }
}
