package com.lenovo.safecenter.antivirus.views;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.text.SpannableString;
import android.text.format.Formatter;
import android.text.style.AbsoluteSizeSpan;
import android.text.style.ForegroundColorSpan;
import android.text.style.StyleSpan;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.TranslateAnimation;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.MainActivity;
import com.lenovo.safecenter.antivirus.domain.Appinfo;
import com.lenovo.safecenter.antivirus.domain.PermAdapter;
import com.lenovo.safecenter.antivirus.domain.ScanInfo;
import com.lenovo.safecenter.antivirus.domain.Virus;
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.antivirus.utils.ScanUtils;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.Untils;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ScanVirusActivity extends BaseTitleActivity {
    public static final String TAG = "FullSystemScanActivity";

    /* JADX INFO: renamed from: A */
    private ImageView f3259A;

    /* JADX INFO: renamed from: C */
    private NotificationManager f3261C;

    /* JADX INFO: renamed from: d */
    private TextView f3265d;

    /* JADX INFO: renamed from: e */
    private TextView f3266e;

    /* JADX INFO: renamed from: f */
    private RelativeLayout f3267f;

    /* JADX INFO: renamed from: g */
    private TextView f3268g;

    /* JADX INFO: renamed from: h */
    private ListView f3269h;

    /* JADX INFO: renamed from: i */
    private C0506a f3270i;

    /* JADX INFO: renamed from: j */
    private ExpandableListView f3271j;

    /* JADX INFO: renamed from: k */
    private TextView f3272k;

    /* JADX INFO: renamed from: l */
    private C0507b f3273l;

    /* JADX INFO: renamed from: m */
    private List<Virus> f3274m;

    /* JADX INFO: renamed from: o */
    private ArrayList<String> f3276o;

    /* JADX INFO: renamed from: p */
    private PermAdapter f3277p;

    /* JADX INFO: renamed from: q */
    private Button f3278q;

    /* JADX INFO: renamed from: r */
    private Button f3279r;

    /* JADX INFO: renamed from: s */
    private LinearLayout f3280s;

    /* JADX INFO: renamed from: t */
    private LinearLayout f3281t;

    /* JADX INFO: renamed from: u */
    private LinearLayout f3282u;

    /* JADX INFO: renamed from: v */
    private LinearLayout f3283v;

    /* JADX INFO: renamed from: w */
    private LinearLayout f3284w;

    /* JADX INFO: renamed from: y */
    private ImageView f3286y;

    /* JADX INFO: renamed from: z */
    private TranslateAnimation f3287z;

    /* JADX INFO: renamed from: a */
    private int f3262a = 0;

    /* JADX INFO: renamed from: b */
    private List<List<Virus>> f3263b = new ArrayList();

    /* JADX INFO: renamed from: c */
    private List<String> f3264c = new ArrayList();

    /* JADX INFO: renamed from: n */
    private List<ScanInfo> f3275n = new ArrayList();

    /* JADX INFO: renamed from: x */
    private List<Appinfo> f3285x = new ArrayList();

    /* JADX INFO: renamed from: B */
    private Handler f3260B = new Handler() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            super.handleMessage(msg);
            switch (msg.what) {
                case 9:
                    String v_str = HttpUtils.execService("viruspkgname", ScanVirusActivity.this);
                    if (!v_str.equals("")) {
                        ScanVirusActivity.this.f3276o.clear();
                        ScanVirusActivity.this.f3262a = v_str.split(",").length;
                        String[] arr$ = v_str.split(",");
                        for (String str : arr$) {
                            ScanVirusActivity.this.f3276o.add(str);
                        }
                        ScanVirusActivity.this.f3268g.setVisibility(8);
                        ScanVirusActivity.this.f3265d.setVisibility(0);
                        ScanVirusActivity.this.f3262a = ScanVirusActivity.this.f3276o.size();
                        ScanVirusActivity.this.setView();
                    } else {
                        Toast.makeText(ScanVirusActivity.this, C0415R.string.done, 0).show();
                        ScanVirusActivity.this.finish();
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ScanVirusActivity$a */
    class C0506a extends BroadcastReceiver {

        /* JADX INFO: renamed from: a */
        Context f3294a;

        public C0506a(Context c) {
            this.f3294a = c;
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.PACKAGE_REMOVED")) {
                String packageName = intent.getDataString().substring(8);
                for (int i = 0; i < ScanVirusActivity.this.f3263b.size(); i++) {
                    for (int k = 0; k < ((List) ScanVirusActivity.this.f3263b.get(i)).size(); k++) {
                        if (((Virus) ((List) ScanVirusActivity.this.f3263b.get(i)).get(k)).getPackageName().equals(packageName)) {
                            ((Virus) ((List) ScanVirusActivity.this.f3263b.get(i)).get(k)).setOperate(true);
                            ScanVirusActivity.this.f3271j.invalidateViews();
                        }
                    }
                }
                for (int i2 = ScanVirusActivity.this.f3276o.size() - 1; i2 >= 0; i2--) {
                    if (((String) ScanVirusActivity.this.f3276o.get(i2)).equals(packageName)) {
                        ScanVirusActivity.this.f3276o.remove(i2);
                    }
                }
                if (ScanVirusActivity.this.f3262a > 0 && ScanVirusActivity.this.f3276o.size() == 0) {
                    ScanVirusActivity.this.f3271j.setVisibility(0);
                    ScanVirusActivity.this.f3278q.setText(C0415R.string.Complete);
                    ScanVirusActivity.this.f3265d.setText(C0415R.string.detail3_killed_virus_home_page);
                    ScanVirusActivity.this.f3286y.setBackgroundResource(C0415R.drawable.virus_status_green1);
                } else {
                    ScanVirusActivity.this.setDealTxt();
                }
                HttpUtils.removeConfig(AppUtils.getVirusDescKey(packageName), context);
            }
        }
    }

    public void setDealTxt() {
        String detail = String.format(getString(C0415R.string.detail3_has_virus_home_page), Integer.valueOf(this.f3276o.size()));
        SpannableString spannable = new SpannableString(detail);
        if (Const.getScreenHeight() == 480) {
            spannable.setSpan(new AbsoluteSizeSpan(30), 0, String.valueOf(this.f3276o.size()).length() + 0, 33);
        } else {
            spannable.setSpan(new AbsoluteSizeSpan(48), 0, String.valueOf(this.f3276o.size()).length() + 0, 33);
        }
        spannable.setSpan(new ForegroundColorSpan(-65536), 0, String.valueOf(this.f3276o.size()).length() + 0, 0);
        spannable.setSpan(new StyleSpan(2), 0, String.valueOf(this.f3276o.size()).length() + 0, 33);
        this.f3265d.setText(spannable);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        this.f3270i = new C0506a(this);
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antivirusfull_system_scan);
        this.f3261C = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
        this.f3261C.cancel(554);
        this.f3286y = (ImageView) findViewById(C0415R.id.antivirusfulldisk_icon);
        this.f3286y.setBackgroundResource(C0415R.drawable.virus_status_green1);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antivirusapp_name, (Integer) null);
        this.f3266e = (TextView) findViewById(C0415R.id.novirus_txt);
        this.f3267f = (RelativeLayout) findViewById(C0415R.id.novirus_layout);
        this.f3271j = (ExpandableListView) findViewById(C0415R.id.viruslistview);
        this.f3284w = (LinearLayout) findViewById(C0415R.id.pro_lin);
        this.f3276o = new ArrayList<>();
        this.f3278q = (Button) findViewById(C0415R.id.antivirusbutton_pause001);
        this.f3279r = (Button) findViewById(C0415R.id.antivirusbutton_stop002);
        this.f3268g = (TextView) findViewById(C0415R.id.antivirusscaning);
        this.f3265d = (TextView) findViewById(C0415R.id.antivirusscaningapp);
        this.f3269h = (ListView) findViewById(C0415R.id.scanlistview);
        this.f3272k = (TextView) findViewById(C0415R.id.antivirushasScaned);
        this.f3280s = (LinearLayout) findViewById(C0415R.id.antivirusresult_view);
        this.f3282u = (LinearLayout) findViewById(C0415R.id.antivirusscan_btn);
        this.f3281t = (LinearLayout) findViewById(C0415R.id.antivirusdeal_btn);
        this.f3283v = (LinearLayout) findViewById(C0415R.id.antivirusdeal_novirus);
        this.f3280s.setVisibility(8);
        this.f3281t.setVisibility(0);
        this.f3283v.setVisibility(8);
        this.f3268g.setVisibility(8);
        this.f3284w.setVisibility(8);
        this.f3279r.setVisibility(8);
        this.f3277p = new PermAdapter(this, this.f3275n, true);
        this.f3269h.setAdapter((ListAdapter) this.f3277p);
        ScanUtils.isNetScan_cancel = false;
        this.f3282u.setVisibility(8);
        onBtnClick();
        registerAction();
        this.f3278q.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (ScanVirusActivity.this.f3276o.size() == 0) {
                    if (!ScanVirusActivity.this.getIntent().getBooleanExtra("from_healthcheck", false)) {
                        ScanVirusActivity.this.finish();
                        ScanVirusActivity.this.startActivity(new Intent(ScanVirusActivity.this, (Class<?>) MainActivity.class));
                    } else {
                        ScanVirusActivity.this.finish();
                    }
                }
                for (String name : ScanVirusActivity.this.f3276o) {
                    ScanVirusActivity.this.uninstall(name);
                }
            }
        });
        this.f3278q.setText(C0415R.string.clear);
        setScanAnimation();
        this.f3260B.sendEmptyMessage(9);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            if (this.f3276o.size() > 0 && !getIntent().getBooleanExtra("from_healthcheck", false)) {
                m1414a();
            } else {
                finish();
            }
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            if (this.f3276o.size() > 0 && !getIntent().getBooleanExtra("from_healthcheck", false)) {
                m1414a();
                return true;
            }
            finish();
            return true;
        }
        return true;
    }

    /* JADX INFO: renamed from: a */
    private void m1414a() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.info).setMessage(C0415R.string.hasvirus_back).setColorNegativeButton(true).setColorPositiveButton(false).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                ScanVirusActivity.this.finish();
                ScanVirusActivity.this.startActivity(new Intent(ScanVirusActivity.this, (Class<?>) MainActivity.class));
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    public void uninstall(String pkgname) {
        Uri packageURI = Uri.parse("package:" + pkgname);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        startActivity(uninstallIntent);
    }

    public void setView() {
        this.f3269h.setVisibility(8);
        this.f3280s.setVisibility(8);
        findViewById(C0415R.id.antivirusnetscan_btn).setVisibility(8);
        this.f3282u.setVisibility(8);
        this.f3272k.setVisibility(8);
        setDealTxt();
        if (this.f3276o.size() > 0) {
            this.f3271j.setVisibility(0);
            this.f3271j.setGroupIndicator(null);
            Log.i("msg", "==============" + this.f3276o.size());
            getVirus();
            if (this.f3263b.size() > 0) {
                this.f3273l = new C0507b(this);
                this.f3271j.setAdapter(this.f3273l);
                this.f3271j.expandGroup(0);
            }
        } else {
            this.f3271j.setVisibility(8);
            this.f3266e.setVisibility(8);
            this.f3267f.setVisibility(8);
            this.f3269h.setVisibility(0);
        }
        if (this.f3276o.size() <= 0) {
            this.f3283v.setVisibility(0);
            if (PreferenceManager.getDefaultSharedPreferences(this).getInt("netScan_switch", 1) == 1 && ScanUtils.isNetworkAvailable(this) && !ScanUtils.isNetScan_cancel) {
                stopAnimation();
                this.f3286y.setBackgroundResource(C0415R.drawable.virus_status_green1);
                this.f3269h.setVisibility(8);
                this.f3266e.setVisibility(0);
                this.f3267f.setVisibility(0);
                this.f3266e.setText(String.format(getString(C0415R.string.scanfinish), Integer.valueOf(this.f3262a), 11, Formatter.formatFileSize(this, this.f3285x.size() * 40)));
                return;
            }
            return;
        }
        stopAnimation();
        this.f3286y.setBackgroundResource(C0415R.drawable.virus_status_red1);
        this.f3281t.setVisibility(0);
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.intent.action.PACKAGE_REMOVED");
        filter.addDataScheme("package");
        registerReceiver(this.f3270i, filter);
    }

    public List<Virus> getVirus() {
        this.f3274m = new ArrayList();
        List<String> errorList = new ArrayList<>();
        for (String virusPackageName : this.f3276o) {
            try {
                ApplicationInfo mAppInfo = getPackageManager().getApplicationInfo(virusPackageName, 8192);
                Virus virus = new Virus(virusPackageName, mAppInfo.loadLabel(getPackageManager()).toString(), false);
                try {
                    virus.setType(0);
                    virus.setVirusName(mAppInfo.loadLabel(getPackageManager()).toString());
                    String desc = HttpUtils.execService(AppUtils.getVirusDescKey(virusPackageName), this);
                    if (desc == null || desc.length() == 0) {
                        desc = getString(C0415R.string.antivirusvirusdesc_default);
                    }
                    virus.setVirusDesc(desc);
                    this.f3274m.add(virus);
                } catch (Exception e) {
                    e = e;
                    if (virusPackageName != null) {
                        errorList.add(virusPackageName);
                        Log.i("p_name", "==============errorListPackageName==" + virusPackageName);
                        new ScanUtils().ExecError(virusPackageName, this);
                    }
                    e.printStackTrace();
                }
            } catch (Exception e2) {
                e = e2;
            }
        }
        if (this.f3276o.size() > 0 && errorList.size() > 0) {
            this.f3276o.removeAll(errorList);
        }
        if (this.f3274m.size() > 0) {
            Log.i("msg", "==============" + this.f3274m.size());
            String sureVirus = getString(C0415R.string.antivirusvirus_suredesc);
            this.f3264c.add(String.format(sureVirus, Integer.valueOf(this.f3274m.size())));
            this.f3263b.add(this.f3274m);
        }
        return this.f3274m;
    }

    public void onBtnClick() {
        this.f3271j.setOnChildClickListener(new ExpandableListView.OnChildClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.5
            @Override // android.widget.ExpandableListView.OnChildClickListener
            public final boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
                Virus vir = (Virus) ((List) ScanVirusActivity.this.f3263b.get(groupPosition)).get(childPosition);
                if (!vir.isOperate()) {
                    Intent intent = new Intent(ScanVirusActivity.this, (Class<?>) VirusInfo.class);
                    intent.putExtra(QueryPermissions.PACKAGENAME, vir.getPackageName());
                    intent.putExtra("desc", vir.getVirusDesc());
                    intent.putExtra("type", vir.getType());
                    ScanVirusActivity.this.startActivity(intent);
                    return false;
                }
                return false;
            }
        });
    }

    @Override // android.app.Activity
    protected void onStart() {
        super.onStart();
        Log.i("mm", "onStart");
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onRestart() {
        super.onRestart();
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        Log.i("mm", "onPause");
        TrackEvent.trackPause(this);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        Log.i("mm", "onStop");
    }

    /* JADX WARN: Type inference failed for: r0v1, types: [com.lenovo.safecenter.antivirus.views.ScanVirusActivity$6] */
    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f3270i);
        new Thread() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.6
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ScanVirusActivity.this.notifyVirus();
            }
        }.start();
    }

    public void notifyVirus() {
        try {
            String virus_pkgname = HttpUtils.execService("viruspkgname", this);
            String[] virus_pkgname_split = virus_pkgname.split(",");
            StringBuilder sb = new StringBuilder();
            for (String str : virus_pkgname_split) {
                sb.append(getPackageManager().getApplicationInfo(str, 8192).loadLabel(getPackageManager())).append(Untils.PAUSE);
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
            this.f3261C.notify(554, mNotification);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ScanVirusActivity$b */
    private class C0507b extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f3297b;

        public C0507b(Context context) {
            this.f3297b = LayoutInflater.from(context);
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getChild(int groupPosition, int childPosition) {
            return ((List) ScanVirusActivity.this.f3263b.get(groupPosition)).get(childPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getChildId(int groupPosition, int childPosition) {
            return childPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return ((List) ScanVirusActivity.this.f3263b.get(groupPosition)).size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            a holder;
            Drawable drawable;
            if (convertView == null) {
                convertView = this.f3297b.inflate(C0415R.layout.antivirusshowviruwitem, (ViewGroup) null);
                holder = new a();
                holder.f3302a = (TextView) convertView.findViewById(C0415R.id.antivirusappname);
                holder.f3303b = (TextView) convertView.findViewById(C0415R.id.antivirusvirusname);
                holder.f3304c = (ImageView) convertView.findViewById(C0415R.id.antivirusviruscheckbox);
                holder.f3307f = (TextView) convertView.findViewById(C0415R.id.antivirusshowdesc);
                holder.f3305d = (ImageView) convertView.findViewById(C0415R.id.antiviruspkg_icon);
                holder.f3306e = (ImageView) convertView.findViewById(C0415R.id.del_icon);
                convertView.setTag(holder);
            } else {
                holder = (a) convertView.getTag();
            }
            final Virus virus = (Virus) ((List) ScanVirusActivity.this.f3263b.get(groupPosition)).get(childPosition);
            holder.f3302a.setText(virus.getAppName());
            if (virus.getType() == 0) {
                String virusname = ScanVirusActivity.this.getString(C0415R.string.antivirusvirusname);
                holder.f3303b.setText(String.format(virusname, virus.getVirusName()));
            } else {
                String virusname2 = ScanVirusActivity.this.getString(C0415R.string.antivirusvirus_carefuluse);
                holder.f3303b.setText(String.format(virusname2, virus.getVirusName()));
            }
            ScanVirusActivity.this.getResources().getDrawable(C0415R.drawable.icon3);
            try {
                ApplicationInfo appInfo = ScanVirusActivity.this.getPackageManager().getApplicationInfo(virus.getPackageName(), 8192);
                drawable = appInfo.loadIcon(ScanVirusActivity.this.getPackageManager());
            } catch (Exception e) {
                e.printStackTrace();
                drawable = ScanVirusActivity.this.getResources().getDrawable(C0415R.drawable.icon3);
            }
            holder.f3305d.setImageDrawable(drawable);
            if (virus.isOperate()) {
                holder.f3307f.setText(C0415R.string.uninstall);
                holder.f3306e.setVisibility(0);
                holder.f3307f.setVisibility(8);
                holder.f3307f.setEnabled(false);
            } else {
                holder.f3306e.setVisibility(8);
                holder.f3307f.setVisibility(0);
                holder.f3307f.setEnabled(true);
                Log.i("type", "type==" + virus.getType());
                if (virus.getType() == 0 || virus.getType() == 1) {
                    holder.f3307f.setText(C0415R.string.uninstall);
                    holder.f3307f.setEnabled(true);
                }
            }
            holder.f3304c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.b.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ScanVirusActivity.this.forwardAppInfo(virus.getPackageName());
                }
            });
            holder.f3307f.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ScanVirusActivity.b.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ScanVirusActivity.this.removePackageActivity(virus.getPackageName());
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return ScanVirusActivity.this.f3264c.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return ScanVirusActivity.this.f3264c.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            b holder;
            if (convertView == null) {
                convertView = this.f3297b.inflate(C0415R.layout.antivirusshowviruwparent, (ViewGroup) null);
                holder = new b();
                holder.f3309a = (TextView) convertView.findViewById(C0415R.id.antivirusvirus_type);
                convertView.setTag(holder);
            } else {
                holder = (b) convertView.getTag();
            }
            holder.f3309a.setText((CharSequence) ScanVirusActivity.this.f3264c.get(groupPosition));
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean hasStableIds() {
            return false;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean isChildSelectable(int groupPosition, int childPosition) {
            return true;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ScanVirusActivity$b$b */
        class b {

            /* JADX INFO: renamed from: a */
            TextView f3309a;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ScanVirusActivity$b$a */
        class a {

            /* JADX INFO: renamed from: a */
            TextView f3302a;

            /* JADX INFO: renamed from: b */
            TextView f3303b;

            /* JADX INFO: renamed from: c */
            ImageView f3304c;

            /* JADX INFO: renamed from: d */
            ImageView f3305d;

            /* JADX INFO: renamed from: e */
            ImageView f3306e;

            /* JADX INFO: renamed from: f */
            TextView f3307f;

            a() {
            }
        }
    }

    public void forwardAppInfo(String pkgName) {
        ComponentName comp = new ComponentName("com.android.settings", "com.android.settings.InstalledAppDetails");
        Intent intent = new Intent();
        intent.setAction("android.intent.action.VIEW");
        intent.setComponent(comp);
        intent.putExtra("pkg", pkgName);
        startActivity(intent);
    }

    public void removePackageActivity(String pkgName) {
        Uri packageURI = Uri.parse("package:" + pkgName);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        startActivity(uninstallIntent);
    }

    public void setScanAnimation() {
        this.f3259A = (ImageView) findViewById(C0415R.id.zoom_icon1);
        this.f3287z = new TranslateAnimation(20.0f, 20.0f, 0.0f, 70.0f);
        this.f3287z.setDuration(1500L);
        this.f3287z.setRepeatCount(-1);
        this.f3287z.setRepeatMode(2);
        this.f3287z.setFillAfter(true);
    }

    public void startAnimation() {
        this.f3259A.setAnimation(this.f3287z);
        this.f3259A.setVisibility(0);
        this.f3287z.start();
    }

    public void stopAnimation() {
        this.f3259A.clearAnimation();
        this.f3259A.setVisibility(8);
    }
}
