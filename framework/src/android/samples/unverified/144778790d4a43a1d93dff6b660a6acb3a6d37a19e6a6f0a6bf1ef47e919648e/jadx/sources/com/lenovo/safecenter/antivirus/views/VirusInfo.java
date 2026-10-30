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
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class VirusInfo extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private TextView f3367a;

    /* JADX INFO: renamed from: b */
    private TextView f3368b;

    /* JADX INFO: renamed from: c */
    private TextView f3369c;

    /* JADX INFO: renamed from: d */
    private TextView f3370d;

    /* JADX INFO: renamed from: e */
    private TextView f3371e;

    /* JADX INFO: renamed from: f */
    private TextView f3372f;

    /* JADX INFO: renamed from: g */
    private ImageView f3373g;

    /* JADX INFO: renamed from: h */
    private Button f3374h;

    /* JADX INFO: renamed from: i */
    private String f3375i;

    /* JADX INFO: renamed from: j */
    private ApplicationInfo f3376j;

    /* JADX INFO: renamed from: k */
    private PackageManager f3377k;

    /* JADX INFO: renamed from: l */
    private BinderC0520b f3378l;

    /* JADX INFO: renamed from: m */
    private PackageStats f3379m;

    /* JADX INFO: renamed from: n */
    private C0519a f3380n;

    /* JADX INFO: renamed from: o */
    private Handler f3381o = new Handler() { // from class: com.lenovo.safecenter.antivirus.views.VirusInfo.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    VirusInfo.m1437a(VirusInfo.this, msg);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1437a(VirusInfo x0, Message x1) {
        PackageStats packageStats = (PackageStats) x1.getData().getParcelable("pStats");
        long j = packageStats.cacheSize + packageStats.codeSize + packageStats.dataSize;
        if (x0.f3379m == null) {
            x0.f3379m = packageStats;
            x0.f3369c.setText(String.format(x0.getString(C0415R.string.antivirusvirus_size), x0.m1435a(j)));
        } else if (j != x0.f3379m.cacheSize + x0.f3379m.codeSize + x0.f3379m.dataSize) {
            x0.f3369c.setText(String.format(x0.getString(C0415R.string.antivirusvirus_size), x0.m1435a(j)));
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antivirusvirusviewer);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.virus_info, (Integer) null);
        this.f3367a = (TextView) findViewById(C0415R.id.antivirustext_showtitle);
        this.f3368b = (TextView) findViewById(C0415R.id.antivirustext_version);
        this.f3369c = (TextView) findViewById(C0415R.id.antivirustext_size);
        this.f3370d = (TextView) findViewById(C0415R.id.antivirustext_info);
        this.f3373g = (ImageView) findViewById(C0415R.id.antivirusimage_icon);
        this.f3371e = (TextView) findViewById(C0415R.id.antivirustext_virusstate);
        this.f3372f = (TextView) findViewById(C0415R.id.antivirustext_virusadvice);
        this.f3374h = (Button) findViewById(C0415R.id.antivirusvirusinfo_uninstall);
        this.f3375i = getIntent().getStringExtra(QueryPermissions.PACKAGENAME);
        this.f3378l = new BinderC0520b();
        this.f3380n = new C0519a(this);
        registerAction();
        this.f3377k = getPackageManager();
        m1438a(this.f3375i);
        LinearLayout permsView = (LinearLayout) findViewById(C0415R.id.antiviruspermissions_section);
        AppSecurityPermissions asp = new AppSecurityPermissions(this, this.f3376j.packageName);
        if (asp.getPermissionCount() > 0) {
            permsView.setVisibility(0);
            LinearLayout securityList = (LinearLayout) permsView.findViewById(C0415R.id.antivirussecurity_settings_list);
            securityList.addView(asp.getPermissionsView());
        } else {
            permsView.setVisibility(8);
        }
        this.f3374h.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.VirusInfo.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                VirusInfo.this.removePackageActivity(VirusInfo.this.f3375i);
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

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.VirusInfo$a */
    class C0519a extends BroadcastReceiver {

        /* JADX INFO: renamed from: a */
        Context f3384a;

        public C0519a(Context c) {
            this.f3384a = c;
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.PACKAGE_REMOVED")) {
                String packageName = intent.getDataString().substring(8);
                if (packageName.equals(VirusInfo.this.f3375i)) {
                    VirusInfo.this.finish();
                }
                HttpUtils.removeConfig(AppUtils.getVirusDescKey(packageName), context);
            }
        }
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.intent.action.PACKAGE_REMOVED");
        filter.addDataScheme("package");
        registerReceiver(this.f3380n, filter);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f3380n);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        String state = getString(C0415R.string.antivirusvirus_state);
        String advice = getString(C0415R.string.antivirusvirus_readvice);
        if (getIntent().getIntExtra("type", 1) == 0) {
            if (getIntent().getStringExtra("desc") == null || getIntent().getStringExtra("desc").equals("")) {
                this.f3370d.setText(C0415R.string.antivirusvirus_dangerousdesc);
            } else {
                this.f3370d.setText(getIntent().getStringExtra("desc"));
            }
            String state2 = String.format(state, getString(C0415R.string.antivirusvirus_statedescone));
            String advice2 = String.format(advice, getString(C0415R.string.antivirusvirus_readviceone));
            this.f3371e.setText(state2);
            this.f3372f.setText(advice2);
        } else {
            if (getIntent().getStringExtra("desc") == null || getIntent().getStringExtra("desc").equals("")) {
                this.f3370d.setText(C0415R.string.antivirusvirusnomatch);
            } else {
                this.f3370d.setText(getIntent().getStringExtra("desc"));
            }
            String state3 = String.format(state, getString(C0415R.string.antivirusvirus_statedesctwo));
            String advice3 = String.format(advice, getString(C0415R.string.antivirusvirus_readvicetwo));
            this.f3371e.setText(state3);
            this.f3372f.setText(advice3);
        }
        try {
            PackageInfo pkgInfo = this.f3377k.getPackageInfo(this.f3376j.packageName, 8192);
            try {
                this.f3373g.setImageDrawable(this.f3376j.loadIcon(this.f3377k));
            } catch (Exception e) {
                this.f3373g.setImageResource(C0415R.drawable.icon3);
                e.printStackTrace();
            }
            this.f3367a.setText(this.f3376j.loadLabel(this.f3377k));
            if (pkgInfo == null || pkgInfo.versionName == null) {
                this.f3368b.setVisibility(4);
            } else {
                this.f3368b.setVisibility(0);
                this.f3368b.setText(String.format(getString(C0415R.string.antivirusvirus_version), pkgInfo.versionName));
            }
            if (this.f3376j != null && this.f3376j.packageName != null) {
                this.f3377k.getPackageSizeInfo(this.f3376j.packageName, this.f3378l);
            }
            TrackEvent.trackResume(this);
        } catch (PackageManager.NameNotFoundException e2) {
            e2.printStackTrace();
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: renamed from: a */
    private boolean m1438a(String packageName) {
        try {
            this.f3376j = getPackageManager().getApplicationInfo(packageName, 8192);
            return true;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    /* JADX INFO: renamed from: a */
    private String m1435a(long size) {
        if (size == -1) {
            return null;
        }
        return Formatter.formatFileSize(this, size);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.VirusInfo$b */
    class BinderC0520b extends IPackageStatsObserver.Stub {
        BinderC0520b() {
        }

        @Override // android.content.p001pm.IPackageStatsObserver
        public final void onGetStatsCompleted(PackageStats pStats, boolean succeeded) {
            Message msg = VirusInfo.this.f3381o.obtainMessage(1);
            Bundle data = new Bundle();
            data.putParcelable("pStats", pStats);
            msg.setData(data);
            VirusInfo.this.f3381o.sendMessage(msg);
        }
    }
}
