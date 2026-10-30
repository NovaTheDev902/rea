package com.lenovo.safecenter.antivirus.views;

import android.app.NotificationManager;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.domain.Virus;
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.antivirus.utils.ScanUtils;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ShowVirusActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private ExpandableListView f3311a;

    /* JADX INFO: renamed from: b */
    private Button f3312b;

    /* JADX INFO: renamed from: c */
    private List<Virus> f3313c = new ArrayList();

    /* JADX INFO: renamed from: d */
    private List<Virus> f3314d = new ArrayList();

    /* JADX INFO: renamed from: e */
    private List<List<Virus>> f3315e = new ArrayList();

    /* JADX INFO: renamed from: f */
    private List<String> f3316f = new ArrayList();

    /* JADX INFO: renamed from: g */
    private ArrayList<String> f3317g;

    /* JADX INFO: renamed from: h */
    private PackageManager f3318h;

    /* JADX INFO: renamed from: i */
    private C0510a f3319i;

    /* JADX INFO: renamed from: j */
    private C0511b f3320j;

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ShowVirusActivity$a */
    class C0510a extends BroadcastReceiver {

        /* JADX INFO: renamed from: a */
        Context f3323a;

        public C0510a(Context c) {
            this.f3323a = c;
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.PACKAGE_REMOVED")) {
                String packageName = intent.getDataString().substring(8);
                for (int i = 0; i < ShowVirusActivity.this.f3315e.size(); i++) {
                    for (int k = 0; k < ((List) ShowVirusActivity.this.f3315e.get(i)).size(); k++) {
                        if (((Virus) ((List) ShowVirusActivity.this.f3315e.get(i)).get(k)).getPackageName().equals(packageName)) {
                            ((Virus) ((List) ShowVirusActivity.this.f3315e.get(i)).get(k)).setOperate(true);
                            ShowVirusActivity.this.f3311a.invalidateViews();
                        }
                    }
                }
                HttpUtils.removeConfig(AppUtils.getVirusDescKey(packageName), context);
            }
        }
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.intent.action.PACKAGE_REMOVED");
        filter.addDataScheme("package");
        registerReceiver(this.f3319i, filter);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antivirusshowvirus);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antivirusapp_name, (Integer) null);
        NotificationManager nm = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
        nm.cancel(555);
        this.f3311a = (ExpandableListView) findViewById(C0415R.id.antiviruslist);
        this.f3311a.setGroupIndicator(null);
        this.f3318h = getPackageManager();
        if (getIntent().getStringArrayListExtra("virusPackageNameList") != null) {
            this.f3317g = getIntent().getStringArrayListExtra("virusPackageNameList");
        } else {
            this.f3317g = new ArrayList<>();
            String virus_pkgname = HttpUtils.execService("viruspkgname", this);
            String[] virus_pkgname_split = virus_pkgname.split(",");
            for (String str : virus_pkgname_split) {
                this.f3317g.add(str);
            }
        }
        List<String> errorList = new ArrayList<>();
        for (String virusPackageName : this.f3317g) {
            try {
                ApplicationInfo mAppInfo = this.f3318h.getApplicationInfo(virusPackageName, 8192);
                Virus virus = new Virus(virusPackageName, mAppInfo.loadLabel(this.f3318h).toString(), false);
                virus.setVirusName(mAppInfo.loadLabel(getPackageManager()).toString());
                virus.setType(0);
                String desc = HttpUtils.execService(AppUtils.getVirusDescKey(virusPackageName), this);
                if (desc == null || desc.length() == 0) {
                    desc = getString(C0415R.string.antivirusvirusdesc_default);
                }
                virus.setVirusDesc(desc);
                this.f3313c.add(virus);
            } catch (Exception e) {
                e.printStackTrace();
                if (virusPackageName != null) {
                    errorList.add(virusPackageName);
                    new ScanUtils().ExecError(virusPackageName, this);
                }
            }
        }
        if (this.f3317g.size() > 0 && errorList.size() > 0) {
            this.f3317g.removeAll(errorList);
        }
        if (this.f3317g.size() > 0) {
            this.f3312b = (Button) findViewById(C0415R.id.antivirusagainscan);
            this.f3319i = new C0510a(this);
            registerAction();
            if (this.f3313c.size() > 0) {
                String sureVirus = getString(C0415R.string.antivirusvirus_suredesc);
                this.f3316f.add(String.format(sureVirus, Integer.valueOf(this.f3313c.size())));
                this.f3315e.add(this.f3313c);
            }
            if (this.f3314d.size() > 0) {
                String unsureVirus = getString(C0415R.string.antivirusvirus_unsuredesc);
                this.f3316f.add(String.format(unsureVirus, Integer.valueOf(this.f3314d.size())));
                this.f3315e.add(this.f3314d);
            }
            this.f3312b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ShowVirusActivity.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (ShowVirusActivity.this.f3312b.getText().toString().equals(ShowVirusActivity.this.getString(C0415R.string.done))) {
                        ShowVirusActivity.this.finish();
                        return;
                    }
                    for (int k = 0; k < ((List) ShowVirusActivity.this.f3315e.get(0)).size(); k++) {
                        if (!((Virus) ((List) ShowVirusActivity.this.f3315e.get(0)).get(k)).isOperate()) {
                            ShowVirusActivity.this.removePackageActivity(((Virus) ((List) ShowVirusActivity.this.f3315e.get(0)).get(k)).getPackageName());
                        }
                    }
                }
            });
            this.f3320j = new C0511b(this);
            this.f3311a.setAdapter(this.f3320j);
            for (int j = 0; j < this.f3316f.size(); j++) {
                this.f3311a.expandGroup(j);
            }
            onBtnClick();
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void onBtnClick() {
        this.f3311a.setOnChildClickListener(new ExpandableListView.OnChildClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ShowVirusActivity.2
            @Override // android.widget.ExpandableListView.OnChildClickListener
            public final boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
                Virus vir = (Virus) ((List) ShowVirusActivity.this.f3315e.get(groupPosition)).get(childPosition);
                if (!vir.isOperate()) {
                    Intent intent = new Intent(ShowVirusActivity.this, (Class<?>) VirusInfo.class);
                    intent.putExtra(QueryPermissions.PACKAGENAME, vir.getPackageName());
                    intent.putExtra("desc", vir.getVirusDesc());
                    intent.putExtra("type", vir.getType());
                    ShowVirusActivity.this.startActivity(intent);
                    return false;
                }
                return false;
            }
        });
    }

    public void forwardAppInfo(String pkgName) {
        ComponentName comp = new ComponentName("com.android.settings", "com.android.settings.InstalledAppDetails");
        Intent intent = new Intent();
        intent.setAction("android.intent.action.VIEW");
        intent.setComponent(comp);
        intent.putExtra("pkg", pkgName);
        startActivity(intent);
    }

    @Override // android.app.Activity
    protected void onStart() {
        super.onStart();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        boolean allOperate = true;
        for (int k = 0; k < this.f3315e.get(0).size(); k++) {
            if (!this.f3315e.get(0).get(k).isOperate()) {
                allOperate = false;
                break;
            }
        }
        if (allOperate) {
            this.f3312b.setText(C0415R.string.done);
        }
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f3319i);
        Log.i("onDestroy", (!HttpUtils.hasVirus) + "====" + getIntent().getStringExtra("fromnotify"));
        if (!HttpUtils.hasVirus && getIntent().getStringExtra("fromnotify") != null && !HttpUtils.isOpen) {
            Intent forceBroadcast = new Intent();
            forceBroadcast.setAction("action.forcestop.antivirus");
            sendBroadcast(forceBroadcast);
        }
    }

    public void removePackageActivity(String pkgName) {
        Uri packageURI = Uri.parse("package:" + pkgName);
        Intent uninstallIntent = new Intent("android.intent.action.DELETE", packageURI);
        startActivity(uninstallIntent);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ShowVirusActivity$b */
    private class C0511b extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: b */
        private Context f3326b;

        /* JADX INFO: renamed from: c */
        private LayoutInflater f3327c;

        public C0511b(Context context) {
            this.f3327c = LayoutInflater.from(context);
            this.f3326b = context;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getChild(int groupPosition, int childPosition) {
            return ((List) ShowVirusActivity.this.f3315e.get(groupPosition)).get(childPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getChildId(int groupPosition, int childPosition) {
            return childPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return ((List) ShowVirusActivity.this.f3315e.get(groupPosition)).size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            a holder;
            Drawable drawable;
            if (convertView == null) {
                convertView = this.f3327c.inflate(C0415R.layout.antivirusshowviruwitem, (ViewGroup) null);
                holder = new a();
                holder.f3332a = (TextView) convertView.findViewById(C0415R.id.antivirusappname);
                holder.f3333b = (TextView) convertView.findViewById(C0415R.id.antivirusvirusname);
                holder.f3335d = (ImageView) convertView.findViewById(C0415R.id.antivirusviruscheckbox);
                holder.f3336e = (ImageView) convertView.findViewById(C0415R.id.antivirusdeletebox);
                holder.f3338g = (TextView) convertView.findViewById(C0415R.id.antivirusshowdesc);
                holder.f3334c = (TextView) convertView.findViewById(C0415R.id.antivirusvirusadvice);
                holder.f3337f = (ImageView) convertView.findViewById(C0415R.id.antiviruspkg_icon);
                convertView.setTag(holder);
            } else {
                holder = (a) convertView.getTag();
            }
            final Virus virus = (Virus) ((List) ShowVirusActivity.this.f3315e.get(groupPosition)).get(childPosition);
            holder.f3332a.setText(virus.getAppName());
            if (virus.getType() == 0) {
                String virusname = ShowVirusActivity.this.getString(C0415R.string.antivirusvirusname);
                holder.f3333b.setText(String.format(virusname, virus.getVirusName()));
            } else {
                String virusname2 = ShowVirusActivity.this.getString(C0415R.string.antivirusvirus_carefuluse);
                holder.f3333b.setText(String.format(virusname2, virus.getVirusName()));
            }
            ShowVirusActivity.this.getResources().getDrawable(C0415R.drawable.icon3);
            try {
                ApplicationInfo appInfo = ShowVirusActivity.this.getPackageManager().getApplicationInfo(virus.getPackageName(), 8192);
                drawable = appInfo.loadIcon(ShowVirusActivity.this.getPackageManager());
            } catch (Exception e) {
                e.printStackTrace();
                drawable = ShowVirusActivity.this.getResources().getDrawable(C0415R.drawable.icon3);
            }
            holder.f3337f.setImageDrawable(drawable);
            if (virus.isOperate()) {
                holder.f3338g.setTextColor(this.f3326b.getResources().getColor(C0415R.color.gray2));
                holder.f3338g.setClickable(false);
                holder.f3338g.setEnabled(false);
            } else {
                Log.i("type", "type==" + virus.getType());
                if (virus.getType() == 0 || virus.getType() == 1) {
                    holder.f3338g.setText(C0415R.string.uninstall);
                    holder.f3338g.setClickable(true);
                }
            }
            holder.f3335d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ShowVirusActivity.b.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ShowVirusActivity.this.forwardAppInfo(virus.getPackageName());
                }
            });
            holder.f3338g.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.ShowVirusActivity.b.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    ShowVirusActivity.this.removePackageActivity(virus.getPackageName());
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return ShowVirusActivity.this.f3316f.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return ShowVirusActivity.this.f3316f.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            b holder;
            if (convertView == null) {
                convertView = this.f3327c.inflate(C0415R.layout.antivirusshowviruwparent, (ViewGroup) null);
                holder = new b();
                holder.f3340a = (TextView) convertView.findViewById(C0415R.id.antivirusvirus_type);
                convertView.setTag(holder);
            } else {
                holder = (b) convertView.getTag();
            }
            holder.f3340a.setText((CharSequence) ShowVirusActivity.this.f3316f.get(groupPosition));
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

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ShowVirusActivity$b$b */
        class b {

            /* JADX INFO: renamed from: a */
            TextView f3340a;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.antivirus.views.ShowVirusActivity$b$a */
        class a {

            /* JADX INFO: renamed from: a */
            TextView f3332a;

            /* JADX INFO: renamed from: b */
            TextView f3333b;

            /* JADX INFO: renamed from: c */
            TextView f3334c;

            /* JADX INFO: renamed from: d */
            ImageView f3335d;

            /* JADX INFO: renamed from: e */
            ImageView f3336e;

            /* JADX INFO: renamed from: f */
            ImageView f3337f;

            /* JADX INFO: renamed from: g */
            TextView f3338g;

            a() {
            }
        }
    }
}
