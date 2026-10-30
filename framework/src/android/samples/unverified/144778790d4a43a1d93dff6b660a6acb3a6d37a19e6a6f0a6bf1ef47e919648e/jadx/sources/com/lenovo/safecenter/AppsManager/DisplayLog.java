package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.LeSafeMainActivity;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class DisplayLog extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: c */
    private static List<SafeLog> f2224c;

    /* JADX INFO: renamed from: a */
    private AppDatabase f2225a;

    /* JADX INFO: renamed from: b */
    private PackageManager f2226b;

    /* JADX INFO: renamed from: d */
    private ProgressDialog f2227d;

    /* JADX INFO: renamed from: e */
    private ProgressBar f2228e;

    /* JADX INFO: renamed from: f */
    private TextView f2229f;

    /* JADX INFO: renamed from: g */
    private TextView f2230g;

    /* JADX INFO: renamed from: h */
    private TextView f2231h;

    /* JADX INFO: renamed from: i */
    private TextView f2232i;

    /* JADX INFO: renamed from: j */
    private ListView f2233j;

    /* JADX INFO: renamed from: l */
    private int f2235l;

    /* JADX INFO: renamed from: m */
    private String f2236m;

    /* JADX INFO: renamed from: n */
    private boolean f2237n;

    /* JADX INFO: renamed from: o */
    private boolean f2238o;

    /* JADX INFO: renamed from: k */
    private LogAdapter f2234k = null;

    /* JADX INFO: renamed from: p */
    private Handler f2239p = new Handler() { // from class: com.lenovo.safecenter.AppsManager.DisplayLog.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    DisplayLog.this.setAdapter();
                    break;
                case 2:
                    try {
                        if (DisplayLog.this.f2227d != null) {
                            DisplayLog.this.f2227d.dismiss();
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    DisplayLog.this.f2230g.setVisibility(0);
                    DisplayLog.this.f2234k.notifyDataSetChanged();
                    DisplayLog.this.f2232i.setEnabled(false);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: q */
    private AdapterView.OnItemClickListener f2240q = new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.AppsManager.DisplayLog.3
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            Intent intent = new Intent(DisplayLog.this, (Class<?>) AppPermManager.class);
            SafeLog log = (SafeLog) DisplayLog.f2224c.get(position);
            if (log.logDay == null) {
                try {
                    DisplayLog.this.getPackageManager().getApplicationInfo(log.packageName, 0);
                    intent.putExtra("permType", DisplayLog.this.f2236m);
                    intent.putExtra(QueryPermissions.PACKAGENAME, log.packageName);
                    intent.putExtra("from", "displaylog");
                    DisplayLog.this.startActivityForResult(intent, 0);
                } catch (PackageManager.NameNotFoundException e) {
                    e.printStackTrace();
                    Toast.makeText(DisplayLog.this.getApplicationContext(), C0415R.string.not_to_appmanager, 0).show();
                }
            }
        }
    };

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.AppsManager.DisplayLog$7] */
    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m936a(DisplayLog x0, final String x1) {
        x0.f2227d = new ProgressDialog(x0);
        x0.f2227d.setProgressStyle(0);
        x0.f2227d.setMessage(x0.getString(C0415R.string.exec_state));
        x0.f2227d.show();
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.DisplayLog.7
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                DisplayLog.this.f2225a.deleteLogItemsforTable(x1, DisplayLog.f2224c);
                DisplayLog.f2224c.clear();
                DisplayLog.this.f2239p.sendMessage(DisplayLog.this.f2239p.obtainMessage(2));
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.mydisplaylog);
        this.f2229f = (TextView) findViewById(C0415R.id.txt_title);
        ((ImageView) findViewById(C0415R.id.title_set)).setVisibility(4);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.DisplayLog.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                try {
                    if (DisplayLog.this.getIntent().getStringExtra("key") == null) {
                        if (!DisplayLog.this.f2237n) {
                            if (DisplayLog.f2224c.size() == 0) {
                                DisplayLog.this.setResult(1);
                            }
                        } else {
                            DisplayLog.this.setResult(0);
                        }
                    } else {
                        DisplayLog.this.startActivity(new Intent(DisplayLog.this, (Class<?>) LeSafeMainActivity.class));
                        DisplayLog.this.finish();
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
                DisplayLog.this.finish();
            }
        });
        this.f2228e = (ProgressBar) findViewById(C0415R.id.log_progress_bar);
        this.f2230g = (TextView) findViewById(C0415R.id.log_txt_empty);
        this.f2231h = (TextView) findViewById(C0415R.id.to_app_manager);
        this.f2232i = (TextView) findViewById(C0415R.id.btn_clean_logs);
        this.f2232i.setEnabled(false);
        this.f2232i.setOnClickListener(this);
        this.f2233j = (ListView) findViewById(C0415R.id.log_listview);
        this.f2233j.setOnItemClickListener(this.f2240q);
        this.f2233j.setItemsCanFocus(false);
        this.f2226b = getPackageManager();
        this.f2225a = new AppDatabase(this);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            try {
                if (getIntent().getStringExtra("key") != null) {
                    startActivity(new Intent(this, (Class<?>) LeSafeMainActivity.class));
                    finish();
                } else if (this.f2237n) {
                    setResult(0);
                } else if (f2224c.size() == 0) {
                    setResult(1);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            finish();
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.btn_clean_logs) {
            new CustomDialog.Builder(this).setTitle(C0415R.string.info).setMessage(C0415R.string.clean_logs_sure).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.DisplayLog.6
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface arg0, int arg1) {
                    if (DisplayLog.this.f2235l == 0) {
                        DisplayLog.m936a(DisplayLog.this, AppDatabase.DB_LOG_TARIFF);
                    } else {
                        DisplayLog.m936a(DisplayLog.this, AppDatabase.DB_LOG_PRIVACY);
                    }
                }
            }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.DisplayLog.5
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface arg0, int arg1) {
                }
            }).show();
        }
    }

    /* JADX WARN: Type inference failed for: r7v5, types: [com.lenovo.safecenter.AppsManager.DisplayLog$4] */
    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        if (!this.f2238o && getIntent() != null) {
            String from = getIntent().getStringExtra("from");
            if (from != null) {
                this.f2235l = Integer.parseInt(from);
            }
            String key = getIntent().getStringExtra("key");
            if (key != null) {
                long tariffTime = 0;
                long privacyTime = 0;
                if (SafeCenterService.charge_count > 0 && Const.lastSafeLogs.get("tariff") != null) {
                    tariffTime = Long.parseLong(Const.lastSafeLogs.get("tariff").time);
                }
                if (SafeCenterService.privacy_count > 0 && Const.lastSafeLogs.get(AppDatabase.PERM_TYPE_PRIVCY) != null) {
                    privacyTime = Long.parseLong(Const.lastSafeLogs.get(AppDatabase.PERM_TYPE_PRIVCY).time);
                }
                if (tariffTime > privacyTime) {
                    this.f2235l = 0;
                } else {
                    this.f2235l = 1;
                }
            }
            if (this.f2235l == 0) {
                this.f2236m = AppDatabase.DB_APP_SENDMESSAGE;
                this.f2229f.setText(C0415R.string.tariff_record);
                this.f2231h.setText(String.format(getString(C0415R.string.to_app_manager), getString(C0415R.string.tariff_perm_manage)));
                SafeCenterService.send_sms_count = 0;
                SafeCenterService.call_count = 0;
                Const.saveChargeLogsCount(this);
                MyUtils.showLeSecNotification(this);
            } else if (this.f2235l == 1) {
                this.f2236m = AppDatabase.PERM_TYPE_PRIVCY;
                this.f2229f.setText(C0415R.string.privacy_record);
                this.f2231h.setText(String.format(getString(C0415R.string.to_app_manager), getString(C0415R.string.privacy_perm_manage)));
                SafeCenterService.privacy_count = 0;
                Const.savePrivacyLogsCount(this);
                MyUtils.showLeSecNotification(this);
            }
            final int i = this.f2235l;
            new Thread() { // from class: com.lenovo.safecenter.AppsManager.DisplayLog.4
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    if (i == 0) {
                        List unused = DisplayLog.f2224c = DisplayLog.this.f2225a.getLog(AppDatabase.DB_LOG_TARIFF);
                        DisplayLog.this.f2239p.sendMessage(DisplayLog.this.f2239p.obtainMessage(0));
                    }
                    if (i == 1) {
                        List unused2 = DisplayLog.f2224c = DisplayLog.this.f2225a.getLog(AppDatabase.DB_LOG_PRIVACY);
                        DisplayLog.this.f2239p.sendMessage(DisplayLog.this.f2239p.obtainMessage(0));
                    }
                }
            }.start();
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    protected void setAdapter() {
        this.f2228e.setVisibility(8);
        if (f2224c.size() == 0) {
            this.f2230g.setVisibility(0);
            return;
        }
        this.f2230g.setVisibility(8);
        this.f2232i.setEnabled(true);
        this.f2234k = new LogAdapter(f2224c);
        this.f2233j.setAdapter((ListAdapter) this.f2234k);
    }

    public class LogAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f2251b;

        /* JADX INFO: renamed from: c */
        private List<SafeLog> f2252c;

        public LogAdapter(List<SafeLog> mList) {
            this.f2251b = LayoutInflater.from(DisplayLog.this);
            this.f2252c = mList;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f2252c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return Integer.valueOf(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0276a holder;
            Drawable appDrawable;
            if (convertView == null) {
                convertView = this.f2251b.inflate(C0415R.layout.new_loglist_item, (ViewGroup) null);
                holder = DisplayLog.this.new C0276a();
                holder.f2253a = (ImageView) convertView.findViewById(C0415R.id.package_icon);
                holder.f2254b = (ImageView) convertView.findViewById(C0415R.id.upload_icon);
                holder.f2255c = (TextView) convertView.findViewById(C0415R.id.log_time);
                holder.f2256d = (TextView) convertView.findViewById(C0415R.id.event_title);
                holder.f2257e = (TextView) convertView.findViewById(C0415R.id.event_action);
                holder.f2258f = (TextView) convertView.findViewById(C0415R.id.event_package);
                holder.f2259g = (TextView) convertView.findViewById(C0415R.id.event_timestamp);
                holder.f2260h = (TextView) convertView.findViewById(C0415R.id.event_number);
                holder.f2261i = (TextView) convertView.findViewById(C0415R.id.event_content);
                holder.f2262j = (LinearLayout) convertView.findViewById(C0415R.id.log_layout);
                holder.f2263k = (LinearLayout) convertView.findViewById(C0415R.id.event_layout);
                convertView.setTag(holder);
            } else {
                holder = (C0276a) convertView.getTag();
            }
            try {
                SafeLog safeLog = this.f2252c.get(position);
                String pkgname = safeLog.packageName;
                if (safeLog.logDay != null) {
                    holder.f2255c.setVisibility(0);
                    holder.f2255c.setText(safeLog.logDay);
                    holder.f2262j.setVisibility(8);
                } else {
                    holder.f2255c.setVisibility(8);
                    holder.f2262j.setVisibility(0);
                    if (safeLog.logSelected == 1) {
                        holder.f2256d.setText(DisplayLog.this.getString(C0415R.string.when_calling) + AppUtil.getDescriptionByPid(DisplayLog.this, Integer.valueOf(safeLog.type).intValue()));
                    } else {
                        holder.f2256d.setText(AppUtil.getDescriptionByPid(DisplayLog.this, Integer.valueOf(safeLog.type).intValue()));
                    }
                    if (safeLog.number != null) {
                        holder.f2260h.setVisibility(0);
                        holder.f2260h.setText(safeLog.number);
                    }
                    if (safeLog.content != null) {
                        holder.f2261i.setVisibility(0);
                        holder.f2261i.setText(safeLog.content);
                    }
                    String str = safeLog.action == 0 ? DisplayLog.this.getString(C0415R.string.allow) : DisplayLog.this.getString(C0415R.string.forbid);
                    holder.f2257e.setTextColor(safeLog.action == 0 ? DisplayLog.this.getResources().getColor(C0415R.color.green_allow) : DisplayLog.this.getResources().getColor(C0415R.color.red_forbid));
                    holder.f2254b.setVisibility(8);
                    holder.f2257e.setText(str);
                    holder.f2259g.setText(MyUtils.formatAllTime(safeLog.time, DisplayLog.this));
                    if (pkgname != null && !"".equals(pkgname)) {
                        try {
                            appDrawable = DisplayLog.this.f2226b.getApplicationIcon(pkgname);
                            ApplicationInfo info = DisplayLog.this.f2226b.getApplicationInfo(pkgname, 0);
                            holder.f2258f.setText(info.loadLabel(DisplayLog.this.f2226b).toString());
                        } catch (PackageManager.NameNotFoundException e) {
                            e.printStackTrace();
                            appDrawable = DisplayLog.this.getResources().getDrawable(C0415R.drawable.icon3);
                            holder.f2258f.setText(safeLog.appName);
                        }
                    } else {
                        appDrawable = DisplayLog.this.getResources().getDrawable(C0415R.drawable.icon3);
                        holder.f2258f.setText(safeLog.appName);
                    }
                    holder.f2253a.setImageDrawable(appDrawable);
                }
            } catch (Exception e2) {
                e2.printStackTrace();
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.DisplayLog$a */
    class C0276a {

        /* JADX INFO: renamed from: a */
        ImageView f2253a;

        /* JADX INFO: renamed from: b */
        ImageView f2254b;

        /* JADX INFO: renamed from: c */
        TextView f2255c;

        /* JADX INFO: renamed from: d */
        TextView f2256d;

        /* JADX INFO: renamed from: e */
        TextView f2257e;

        /* JADX INFO: renamed from: f */
        TextView f2258f;

        /* JADX INFO: renamed from: g */
        TextView f2259g;

        /* JADX INFO: renamed from: h */
        TextView f2260h;

        /* JADX INFO: renamed from: i */
        TextView f2261i;

        /* JADX INFO: renamed from: j */
        LinearLayout f2262j;

        /* JADX INFO: renamed from: k */
        LinearLayout f2263k;

        C0276a() {
        }
    }

    @Override // android.app.Activity
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == 3) {
            this.f2238o = true;
        } else if (resultCode == 4) {
            this.f2237n = true;
        }
    }
}
