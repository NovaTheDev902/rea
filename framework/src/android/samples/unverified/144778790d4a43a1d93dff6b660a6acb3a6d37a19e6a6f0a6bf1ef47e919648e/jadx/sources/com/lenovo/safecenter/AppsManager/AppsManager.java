package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.FrameLayout;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.support.AppPerInfo;
import com.lenovo.safecenter.support.ProcessInfo;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class AppsManager extends Activity {

    /* JADX INFO: renamed from: a */
    private ListView f2087a;

    /* JADX INFO: renamed from: b */
    private List<AppPerInfo> f2088b;

    /* JADX INFO: renamed from: c */
    private List<ProcessInfo> f2089c;

    /* JADX INFO: renamed from: d */
    private PackageManager f2090d;

    /* JADX INFO: renamed from: e */
    private AppDatabase f2091e;

    /* JADX INFO: renamed from: f */
    private myAdapter f2092f;

    /* JADX INFO: renamed from: g */
    private ProgressBar f2093g;

    /* JADX INFO: renamed from: h */
    private TextView f2094h;

    /* JADX INFO: renamed from: i */
    private TextView f2095i;

    /* JADX INFO: renamed from: j */
    private TextView f2096j;

    /* JADX INFO: renamed from: k */
    private LinearLayout f2097k;

    /* JADX INFO: renamed from: l */
    private GridView f2098l;

    /* JADX INFO: renamed from: m */
    private TextView f2099m;

    /* JADX INFO: renamed from: n */
    private TextView f2100n;

    /* JADX INFO: renamed from: o */
    private ActivityManager f2101o;

    /* JADX INFO: renamed from: p */
    private DisplayMetrics f2102p;

    /* JADX INFO: renamed from: q */
    private int f2103q;

    /* JADX INFO: renamed from: r */
    private GridAdapter f2104r;

    /* JADX INFO: renamed from: t */
    private C0243a f2106t;

    /* JADX INFO: renamed from: v */
    private boolean f2108v;

    /* JADX INFO: renamed from: w */
    private boolean f2109w;

    /* JADX INFO: renamed from: x */
    private int f2110x;

    /* JADX INFO: renamed from: s */
    private int f2105s = -1;

    /* JADX INFO: renamed from: u */
    private String f2107u = AppDatabase.PERM_TYPE_PRIVCY;

    /* JADX INFO: renamed from: y */
    private Handler f2111y = new Handler() { // from class: com.lenovo.safecenter.AppsManager.AppsManager.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    AppsManager.this.f2100n.setText(String.format(AppsManager.this.getString(C0415R.string.trusted_apps_count), Integer.valueOf(AppsManager.this.f2110x), Integer.valueOf(AppsManager.this.f2088b.size() - AppsManager.this.f2110x)));
                    AppsManager.this.f2093g.setVisibility(8);
                    AppsManager.this.f2092f = AppsManager.this.new myAdapter(AppsManager.this, AppsManager.this.f2088b);
                    AppsManager.this.f2087a.setAdapter((ListAdapter) AppsManager.this.f2092f);
                    if (AppsManager.this.f2088b.size() == 0) {
                        AppsManager.this.f2095i.setVisibility(0);
                    } else {
                        AppsManager.this.f2095i.setVisibility(8);
                    }
                    break;
                case 2:
                    AppsManager.this.f2100n.setText(String.format(AppsManager.this.getString(C0415R.string.trusted_apps_count), Integer.valueOf(AppsManager.this.f2110x), Integer.valueOf(AppsManager.this.f2088b.size() - AppsManager.this.f2110x)));
                    break;
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        if (getIntent() != null) {
            this.f2107u = getIntent().getStringExtra("permType");
        }
        setContentView(C0415R.layout.testperssion);
        this.f2109w = WflUtils.isRoot();
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.trust_apps);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.AppsManager.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (AppsManager.this.f2108v) {
                    AppsManager.this.setResult(0);
                }
                AppsManager.this.finish();
            }
        });
        this.f2099m = (TextView) findViewById(C0415R.id.unroot_tip);
        this.f2100n = (TextView) findViewById(C0415R.id.trusted_apps_des);
        if (this.f2109w) {
            this.f2100n.setVisibility(0);
        } else {
            this.f2099m.setVisibility(0);
            this.f2099m.setText(getString(C0415R.string.unobtain_root2));
        }
        this.f2087a = (ListView) findViewById(C0415R.id.perssion_listView);
        this.f2094h = (TextView) findViewById(C0415R.id.process_empty);
        this.f2095i = (TextView) findViewById(C0415R.id.app_empty);
        this.f2096j = (TextView) findViewById(C0415R.id.onkillkey);
        this.f2098l = (GridView) findViewById(C0415R.id.process_gridview);
        this.f2093g = (ProgressBar) findViewById(C0415R.id.pkg_progressbar);
        this.f2097k = (LinearLayout) findViewById(C0415R.id.gridlin);
        this.f2090d = getPackageManager();
        this.f2091e = new AppDatabase(this);
        this.f2101o = (ActivityManager) getSystemService("activity");
        this.f2102p = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(this.f2102p);
        this.f2103q = 50;
        this.f2098l.setEmptyView(this.f2094h);
        onClick();
        initData();
        this.f2106t = new C0243a(this, b);
        IntentFilter filter = new IntentFilter("com.lenovo.safecenter.refreshAppsManager");
        registerReceiver(this.f2106t, filter);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            if (this.f2108v) {
                setResult(0);
            }
            finish();
        }
        return super.onKeyDown(keyCode, event);
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

    @Override // android.app.Activity
    protected void onDestroy() {
        unregisterReceiver(this.f2106t);
        this.f2106t = null;
        super.onDestroy();
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.AppsManager.AppsManager$3] */
    public void initData() {
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.AppsManager.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                AppsManager.this.f2088b = AppsManager.this.f2091e.getAppPers(AppsManager.this.f2107u);
                AppsManager.this.f2110x = AppsManager.this.f2091e.getTrustedApps(AppsManager.this.f2107u);
                AppsManager.this.f2111y.sendMessage(AppsManager.this.f2111y.obtainMessage(0));
            }
        }.start();
    }

    public void notifyUpdate() {
        int num = this.f2089c.size() % 2 == 0 ? this.f2089c.size() / 2 : (this.f2089c.size() / 2) + 1;
        if (num <= 6) {
            int width = this.f2103q * 6;
            FrameLayout.LayoutParams lp = (FrameLayout.LayoutParams) this.f2097k.getLayoutParams();
            lp.width = width;
            this.f2097k.setLayoutParams(lp);
            this.f2098l.setNumColumns(6);
            Log.i("ww", (this.f2089c.size() / 2) + "==" + width + "itemWidth=" + this.f2103q + "processList.size()==" + this.f2089c.size() + "dm.widthPixels" + this.f2102p.widthPixels + "num==" + num);
            return;
        }
        this.f2098l.setNumColumns(num);
        int width2 = this.f2103q * num;
        FrameLayout.LayoutParams lp2 = (FrameLayout.LayoutParams) this.f2097k.getLayoutParams();
        lp2.width = width2;
        this.f2097k.setLayoutParams(lp2);
        Log.i("ww", (this.f2089c.size() / 2) + "==" + width2 + "itemWidth=" + this.f2103q + "processList.size()==" + this.f2089c.size() + "dm.widthPixels" + this.f2102p.widthPixels + "num==" + num);
    }

    public void onClick() {
        this.f2087a.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.AppsManager.AppsManager.4
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                AppsManager.this.f2105s = position;
                Intent it = new Intent(AppsManager.this, (Class<?>) AppPermManager.class);
                it.putExtra("permType", AppsManager.this.f2107u);
                it.putExtra(QueryPermissions.PACKAGENAME, ((AppPerInfo) AppsManager.this.f2088b.get(position)).pkgName);
                AppsManager.this.startActivityForResult(it, 0);
            }
        });
        this.f2098l.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.AppsManager.AppsManager.5
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if (AppsManager.this.f2089c.size() > 0) {
                    AppsManager.this.f2101o.killBackgroundProcesses(((ProcessInfo) AppsManager.this.f2089c.get(position)).getAppInfo().packageName);
                    AppsManager.this.f2089c.remove(position);
                    AppsManager.this.notifyUpdate();
                    AppsManager.this.f2104r.notifyDataSetChanged();
                    AppsManager.this.f2111y.sendEmptyMessageDelayed(1, 500L);
                }
            }
        });
        this.f2096j.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.AppsManager.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AppsManager.this.f2089c.size();
                for (int i = AppsManager.this.f2089c.size() - 1; i >= 0; i--) {
                    ApplicationInfo appInfo = ((ProcessInfo) AppsManager.this.f2089c.get(i)).getAppInfo();
                    AppsManager.this.f2101o.killBackgroundProcesses(appInfo.packageName);
                    AppsManager.this.f2089c.remove(i);
                    AppsManager.this.f2104r.notifyDataSetChanged();
                }
                AppsManager.this.f2111y.sendEmptyMessageDelayed(1, 1000L);
            }
        });
    }

    @Override // android.app.Activity
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (this.f2105s != -1) {
            if (resultCode == 3) {
                AppPerInfo newInfo = this.f2091e.getAppPerInfo(this.f2088b.get(this.f2105s).pkgName, this.f2107u);
                if (newInfo != null) {
                    this.f2088b.get(this.f2105s).forbidCount = newInfo.forbidCount;
                    this.f2088b.get(this.f2105s).forbidmes = newInfo.forbidmes;
                    this.f2088b.get(this.f2105s).hasNotice = newInfo.hasNotice;
                    this.f2088b.get(this.f2105s).isTrust = newInfo.isTrust;
                    this.f2088b.get(this.f2105s).totalCount = newInfo.totalCount;
                    this.f2088b.get(this.f2105s).totaldmes = newInfo.totaldmes;
                    this.f2088b.get(this.f2105s).isUpload = newInfo.isUpload;
                    this.f2087a.invalidateViews();
                    return;
                }
                return;
            }
            if (resultCode == 4) {
                this.f2108v = true;
                this.f2110x = this.f2091e.getTrustedApps(this.f2107u);
                this.f2111y.sendMessage(this.f2111y.obtainMessage(2));
                AppPerInfo newInfo2 = this.f2091e.getAppPerInfo(this.f2088b.get(this.f2105s).pkgName, this.f2107u);
                if (newInfo2 != null) {
                    this.f2088b.get(this.f2105s).forbidCount = newInfo2.forbidCount;
                    this.f2088b.get(this.f2105s).forbidmes = newInfo2.forbidmes;
                    this.f2088b.get(this.f2105s).hasNotice = newInfo2.hasNotice;
                    this.f2088b.get(this.f2105s).isTrust = newInfo2.isTrust;
                    this.f2088b.get(this.f2105s).totalCount = newInfo2.totalCount;
                    this.f2088b.get(this.f2105s).totaldmes = newInfo2.totaldmes;
                    this.f2088b.get(this.f2105s).isUpload = newInfo2.isUpload;
                    this.f2087a.invalidateViews();
                }
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.AppsManager$a */
    private class C0243a extends BroadcastReceiver {
        private C0243a() {
        }

        /* synthetic */ C0243a(AppsManager x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            AppsManager.this.initData();
        }
    }

    public List<ProcessInfo> getFilteredApps() {
        List<ProcessInfo> processList = new ArrayList<>();
        List<ApplicationInfo> pAppList = getPackageManager().getInstalledApplications(8192);
        List<ActivityManager.RunningAppProcessInfo> procList = this.f2101o.getRunningAppProcesses();
        if (procList == null || procList.size() == 0) {
            return null;
        }
        HashMap<String, ActivityManager.RunningAppProcessInfo> runningMap = new HashMap<>();
        for (ActivityManager.RunningAppProcessInfo appProcInfo : procList) {
            if (appProcInfo != null && appProcInfo.pkgList != null) {
                int size = appProcInfo.pkgList.length;
                for (int i = 0; i < size; i++) {
                    runningMap.put(appProcInfo.pkgList[i], appProcInfo);
                }
            }
        }
        for (ApplicationInfo appInfo : pAppList) {
            if (appInfo != null && AppUtil.isThirdpartApp(appInfo) && runningMap.get(appInfo.packageName) != null) {
                ProcessInfo info = new ProcessInfo();
                info.setAppInfo(appInfo);
                try {
                    int[] pids = {runningMap.get(appInfo.packageName).pid};
                    info.setSize("");
                    info.setState(runningMap.get(appInfo.packageName).importance);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (!appInfo.packageName.equals(TrafficStatsService.PACKAGE_NAME)) {
                    processList.add(info);
                }
            }
        }
        return processList;
    }

    public class GridAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: a */
        Context f2118a;

        /* JADX INFO: renamed from: b */
        List<ProcessInfo> f2119b;

        /* JADX INFO: renamed from: c */
        C0242a f2120c;

        public GridAdapter(Context context, List<ProcessInfo> Plist) {
            this.f2118a = context;
            this.f2119b = Plist;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f2119b.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f2119b.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f2118a).inflate(C0415R.layout.processitem, (ViewGroup) null);
                this.f2120c = new C0242a();
                this.f2120c.f2122a = (ImageView) convertView.findViewById(C0415R.id.itemImage);
                this.f2120c.f2123b = (TextView) convertView.findViewById(C0415R.id.itemText);
                convertView.setTag(this.f2120c);
            } else {
                this.f2120c = (C0242a) convertView.getTag();
            }
            ProcessInfo info = this.f2119b.get(position);
            this.f2120c.f2122a.setImageDrawable(info.getAppInfo().loadIcon(this.f2118a.getPackageManager()));
            this.f2120c.f2123b.setText(info.getAppInfo().loadLabel(this.f2118a.getPackageManager()));
            this.f2120c.f2123b.setVisibility(8);
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.AppsManager$GridAdapter$a */
        class C0242a {

            /* JADX INFO: renamed from: a */
            ImageView f2122a;

            /* JADX INFO: renamed from: b */
            TextView f2123b;

            C0242a() {
            }
        }
    }

    public class myAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f2127b;

        /* JADX INFO: renamed from: c */
        private List<AppPerInfo> f2128c;

        public myAdapter(Context context, List<AppPerInfo> list) {
            this.f2127b = context;
            this.f2128c = list;
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return this.f2128c.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int position) {
            return this.f2128c.get(position);
        }

        @Override // android.widget.Adapter
        public long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            C0244a holder;
            String appMes;
            if (convertView == null) {
                convertView = LayoutInflater.from(this.f2127b).inflate(C0415R.layout.testperssionitem, (ViewGroup) null);
                holder = new C0244a(this, (byte) 0);
                holder.f2129a = (TextView) convertView.findViewById(C0415R.id.pkg_name);
                holder.f2130b = (TextView) convertView.findViewById(C0415R.id.pkg_mes);
                holder.f2131c = (TextView) convertView.findViewById(C0415R.id.pkg_trust);
                holder.f2132d = (ImageView) convertView.findViewById(C0415R.id.pkg_icon);
                holder.f2133e = (ImageView) convertView.findViewById(C0415R.id.img_upload);
                convertView.setTag(holder);
            } else {
                holder = (C0244a) convertView.getTag();
            }
            try {
                AppPerInfo info = this.f2128c.get(position);
                ApplicationInfo mAppInfo = AppsManager.this.f2090d.getApplicationInfo(info.pkgName, 8192);
                Log.i("info", info.forbidCount + "//" + info.totalCount + "===" + info.pkgName + "pm==" + AppsManager.this.f2090d + "===mAppInfo" + mAppInfo + "===mAppInfo.loadLabel(pm)" + ((Object) mAppInfo.loadLabel(AppsManager.this.f2090d)) + "holder:" + holder.f2129a);
                holder.f2129a.setText(mAppInfo.loadLabel(AppsManager.this.f2090d));
                holder.f2132d.setImageDrawable(mAppInfo.loadIcon(AppsManager.this.f2090d));
                if (AppsManager.this.f2109w) {
                    if (info.forbidCount == 0) {
                        appMes = this.f2127b.getString(C0415R.string.allow_all);
                    } else if (info.forbidCount == info.totalCount) {
                        appMes = this.f2127b.getString(C0415R.string.forbid_all);
                    } else {
                        StringBuffer sb = new StringBuffer();
                        sb.append(this.f2127b.getString(C0415R.string.forbid));
                        String[] apptypes = info.forbidmes.split(",");
                        for (String apptype : apptypes) {
                            sb.append(AppUtil.getDescriptionByType(this.f2127b, AppsManager.this.f2091e, info.pkgName, apptype)).append(", ");
                        }
                        appMes = "" + sb.deleteCharAt(sb.length() - 2).toString();
                    }
                    holder.f2130b.setText(appMes);
                    if (info.isTrust) {
                        holder.f2131c.setVisibility(0);
                        holder.f2130b.setText(C0415R.string.not_control);
                    } else {
                        holder.f2131c.setVisibility(8);
                    }
                } else {
                    holder.f2130b.setText(this.f2127b.getString(C0415R.string.allow_all));
                    holder.f2131c.setVisibility(8);
                }
                if (info.isUpload == 1) {
                    holder.f2133e.setVisibility(0);
                } else {
                    holder.f2133e.setVisibility(8);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            return convertView;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.AppsManager$myAdapter$a */
        private class C0244a {

            /* JADX INFO: renamed from: a */
            TextView f2129a;

            /* JADX INFO: renamed from: b */
            TextView f2130b;

            /* JADX INFO: renamed from: c */
            TextView f2131c;

            /* JADX INFO: renamed from: d */
            ImageView f2132d;

            /* JADX INFO: renamed from: e */
            ImageView f2133e;

            private C0244a() {
            }

            /* synthetic */ C0244a(myAdapter x0, byte b) {
                this();
            }
        }
    }
}
