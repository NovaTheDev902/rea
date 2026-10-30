package com.lenovo.safecenter.antivirus.views;

import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.Untils;

/* JADX INFO: loaded from: classes.dex */
public class NotiSMSActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private String f3245a;

    /* JADX INFO: renamed from: b */
    private String f3246b;

    /* JADX INFO: renamed from: c */
    private String f3247c;

    /* JADX INFO: renamed from: d */
    private String f3248d;

    /* JADX INFO: renamed from: e */
    private PackageManager f3249e;

    /* JADX INFO: renamed from: f */
    private ApplicationInfo f3250f;

    /* JADX INFO: renamed from: g */
    private C0499a f3251g;

    /* JADX INFO: renamed from: h */
    private NotificationManager f3252h;

    /* JADX INFO: renamed from: i */
    private boolean f3253i = false;

    /* JADX INFO: renamed from: b */
    static /* synthetic */ boolean m1411b(NotiSMSActivity x0) {
        x0.f3253i = true;
        return true;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f3249e = getPackageManager();
        Intent smsIntent = getIntent();
        this.f3247c = smsIntent.getStringExtra(DatabaseTables.LOG_MESSAGE);
        this.f3245a = smsIntent.getStringExtra("packageName");
        this.f3252h = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
        this.f3248d = getIntent().getStringExtra("virustype");
        this.f3251g = new C0499a(this);
        registerAction();
        try {
            this.f3250f = this.f3249e.getApplicationInfo(this.f3245a, 8192);
        } catch (PackageManager.NameNotFoundException e) {
            this.f3253i = true;
            e.printStackTrace();
            finish();
        }
        setTitle(C0415R.string.antivirusapp_name);
        setContentView(C0415R.layout.antivirusnoti_sms);
        ImageView imageView = (ImageView) findViewById(C0415R.id.antivirusapp_icon_sms);
        TextView textView = (TextView) findViewById(C0415R.id.antivirusapp_name_sms);
        TextView textView2 = (TextView) findViewById(C0415R.id.antivirusvirus_notifyname);
        TextView textView3 = (TextView) findViewById(C0415R.id.antivirusvirus_notifyadvice);
        TextView textView4 = (TextView) findViewById(C0415R.id.antivirusdes);
        final Button button = (Button) findViewById(C0415R.id.antivirussend);
        final Button button2 = (Button) findViewById(C0415R.id.antivirusunsent);
        try {
            imageView.setBackgroundDrawable(this.f3249e.getApplicationIcon(this.f3245a));
            this.f3246b = (String) this.f3250f.loadLabel(this.f3249e);
        } catch (PackageManager.NameNotFoundException e2) {
            e2.printStackTrace();
            imageView.setImageResource(C0415R.drawable.icon3);
        }
        textView.setText(this.f3246b);
        if (this.f3247c == null || this.f3247c.equals("")) {
            if (getIntent().getStringExtra("virustype").equals(DatabaseTables.SYSTEM_MARK)) {
                this.f3247c = getString(C0415R.string.antivirusvirusnomatch);
            } else {
                this.f3247c = getString(C0415R.string.antivirusvirus_dangerousdesc);
            }
        }
        textView4.setText(this.f3247c);
        if (getIntent().getStringExtra("virustype").equals(DatabaseTables.SYSTEM_MARK)) {
            textView2.setVisibility(8);
            textView3.setText(C0415R.string.antivirusvirus_notifyadvicetwo);
        } else {
            textView2.setVisibility(0);
            String str = String.format(getString(C0415R.string.antivirusvirusname), getIntent().getStringExtra("virusname"));
            SpannableString spannableString = new SpannableString(str);
            spannableString.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.red)), str.length() - getIntent().getStringExtra("virusname").length(), str.length(), 33);
            textView2.setText(spannableString);
            textView3.setText(C0415R.string.antivirusvirus_notifyadvice);
        }
        View.OnClickListener onClickListener = new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.NotiSMSActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (v.getId() == button.getId()) {
                    NotiSMSActivity.this.removePackageActivity(NotiSMSActivity.this.f3245a);
                } else if (v.getId() == button2.getId()) {
                    NotiSMSActivity.this.finish();
                }
            }
        };
        button.setOnClickListener(onClickListener);
        button2.setOnClickListener(onClickListener);
        initVirus();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    public void initVirus() {
        HttpUtils.hasVirus = true;
        String virus_pkgname = HttpUtils.execService("viruspkgname", this);
        if (!virus_pkgname.equalsIgnoreCase("")) {
            boolean isexist = false;
            String[] arr = virus_pkgname.split(",");
            for (String vir : arr) {
                if (vir.equals(this.f3245a)) {
                    isexist = true;
                    break;
                }
            }
            if (!isexist) {
                virus_pkgname = virus_pkgname + "," + this.f3245a;
            }
        } else {
            virus_pkgname = this.f3245a;
        }
        HttpUtils.UpdateConfig("viruspkgname", virus_pkgname, this);
        HttpUtils.UpdateConfig(AppUtils.getVirusDescKey(virus_pkgname), this.f3247c, this);
        LeSafeObservable.get(this).noticeHasVirus();
    }

    public void notifyVirus() {
        try {
            String virus_pkgname = HttpUtils.execService("viruspkgname", this);
            String[] virus_pkgname_split = virus_pkgname.split(",");
            StringBuilder sb = new StringBuilder();
            for (String str : virus_pkgname_split) {
                sb.append(this.f3249e.getApplicationInfo(str, 8192).loadLabel(this.f3249e)).append(Untils.PAUSE);
            }
            Intent showVirus = new Intent(this, (Class<?>) ScanVirusActivity.class);
            Bundle bundle = new Bundle();
            bundle.putString("fromnotify", "notify");
            showVirus.putExtras(bundle);
            showVirus.setFlags(536870912);
            PendingIntent intent = PendingIntent.getActivity(this, 0, showVirus, 0);
            Notification mNotification = new Notification(C0415R.drawable.antiviruswarning, getString(C0415R.string.antivirusvirus_notify), System.currentTimeMillis());
            mNotification.flags = 10;
            String not_str = getString(C0415R.string.antivirusvirus_notifycontent);
            mNotification.setLatestEventInfo(this, getString(C0415R.string.antivirusvirus_notify), String.format(not_str, sb.deleteCharAt(sb.length() - 1).toString()), intent);
            this.f3252h.notify(554, mNotification);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.NotiSMSActivity$a */
    class C0499a extends BroadcastReceiver {

        /* JADX INFO: renamed from: a */
        Context f3257a;

        public C0499a(Context c) {
            this.f3257a = c;
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.PACKAGE_REMOVED")) {
                String pname = intent.getDataString().substring(8);
                if (pname.equals(NotiSMSActivity.this.f3245a)) {
                    NotiSMSActivity.m1411b(NotiSMSActivity.this);
                    NotiSMSActivity.this.finish();
                }
                HttpUtils.removeConfig(AppUtils.getVirusDescKey(pname), context);
            }
        }
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.intent.action.PACKAGE_REMOVED");
        filter.addDataScheme("package");
        registerReceiver(this.f3251g, filter);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f3251g);
        if (!this.f3253i && this.f3248d.equals(DatabaseTables.USER_MARK)) {
            notifyVirus();
        }
    }

    public void removePackageActivity(String pkgName) {
        Uri packageURI = Uri.parse("package:" + pkgName);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        startActivity(uninstallIntent);
    }
}
