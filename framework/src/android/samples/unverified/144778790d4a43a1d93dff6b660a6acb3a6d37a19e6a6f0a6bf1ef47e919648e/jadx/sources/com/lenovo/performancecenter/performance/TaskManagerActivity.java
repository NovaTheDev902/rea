package com.lenovo.performancecenter.performance;

import android.R;
import android.app.Activity;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.format.Formatter;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.util.RootPassage;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.TrackEvent;
import java.lang.ref.SoftReference;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class TaskManagerActivity extends Activity implements View.OnClickListener {
    public static final String TAG = "TaskManagerActivity";

    /* JADX INFO: renamed from: a */
    private ImageView f1832a;

    /* JADX INFO: renamed from: b */
    private TextView f1833b;

    /* JADX INFO: renamed from: c */
    private TextView f1834c;

    /* JADX INFO: renamed from: d */
    private LinearLayout f1835d;

    /* JADX INFO: renamed from: e */
    private LinearLayout f1836e;

    /* JADX INFO: renamed from: f */
    private ListView f1837f;

    /* JADX INFO: renamed from: g */
    private C0195a f1838g;

    /* JADX INFO: renamed from: h */
    private Button f1839h;

    /* JADX INFO: renamed from: i */
    private List<AppInfo> f1840i;

    /* JADX INFO: renamed from: j */
    private ArrayList<AppInfo> f1841j;

    /* JADX INFO: renamed from: k */
    private ArrayList<AppInfo> f1842k;

    /* JADX INFO: renamed from: l */
    private ArrayList<String> f1843l;

    /* JADX INFO: renamed from: m */
    private int f1844m;

    /* JADX INFO: renamed from: n */
    private Context f1845n;

    /* JADX INFO: renamed from: o */
    private AdapterView.OnItemClickListener f1846o = new AdapterView.OnItemClickListener() { // from class: com.lenovo.performancecenter.performance.TaskManagerActivity.1
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            int currentAppCount;
            int userSize = TaskManagerActivity.this.f1841j.size();
            if (position != 0 && position != userSize) {
                C0196b vh = (C0196b) view.getTag();
                String pkgName = vh.f1858f;
                TaskManagerActivity.this.f1840i.remove(position);
                if (position <= userSize) {
                    TaskManagerActivity.this.f1841j.remove(position);
                    if (TaskManagerActivity.this.f1841j.size() == 1) {
                        TaskManagerActivity.this.f1840i.remove(0);
                        TaskManagerActivity.this.f1841j.remove(0);
                    }
                } else {
                    TaskManagerActivity.this.f1842k.remove(position - userSize);
                    if (TaskManagerActivity.this.f1842k.size() == 1) {
                        TaskManagerActivity.this.f1840i.remove(userSize);
                        TaskManagerActivity.this.f1842k.remove(0);
                    }
                }
                TaskManagerActivity.this.f1838g.notifyDataSetChanged();
                TaskManagerActivity.this.f1844m -= vh.f1859g;
                if (TaskManagerActivity.this.f1841j.size() != 0 || TaskManagerActivity.this.f1842k.size() != 0) {
                    currentAppCount = (TaskManagerActivity.this.f1841j.size() == 0 || TaskManagerActivity.this.f1842k.size() == 0) ? TaskManagerActivity.this.f1840i.size() - 1 : TaskManagerActivity.this.f1840i.size() - 2;
                } else {
                    currentAppCount = 0;
                }
                TaskManagerActivity.this.f1834c.setText(TaskManagerActivity.this.getString(C0415R.string.task_manager_title, new Object[]{Integer.valueOf(currentAppCount), Formatter.formatFileSize(TaskManagerActivity.this.f1845n, TaskManagerActivity.this.f1844m)}));
                if (currentAppCount == 0) {
                    TaskManagerActivity.this.f1834c.setVisibility(8);
                    TaskManagerActivity.this.f1836e.setVisibility(0);
                }
                RootPassage.execRootCmd(pkgName, " -fs ", TaskManagerActivity.this.f1845n);
            }
        }
    };

    /* JADX INFO: renamed from: p */
    private Handler f1847p = new Handler() { // from class: com.lenovo.performancecenter.performance.TaskManagerActivity.3
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    TaskManagerActivity.this.f1835d.setVisibility(8);
                    int runningAppCount = msg.arg1;
                    if (runningAppCount == 0) {
                        TaskManagerActivity.this.f1834c.setVisibility(8);
                        TaskManagerActivity.this.f1836e.setVisibility(0);
                    } else {
                        TaskManagerActivity.this.f1834c.setVisibility(0);
                        TaskManagerActivity.this.f1834c.setText(TaskManagerActivity.this.getString(C0415R.string.task_manager_title, new Object[]{Integer.valueOf(runningAppCount), Formatter.formatFileSize(TaskManagerActivity.this.f1845n, TaskManagerActivity.this.f1844m)}));
                        TaskManagerActivity.this.f1836e.setVisibility(8);
                        TaskManagerActivity.this.f1838g.notifyDataSetChanged();
                    }
                    break;
            }
        }
    };

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.rf_perf_stop_apps);
        this.f1832a = (ImageView) findViewById(C0415R.id.title_back);
        this.f1833b = (TextView) findViewById(C0415R.id.txt_title);
        this.f1833b.setText(C0415R.string.stop_application);
        this.f1832a.setOnClickListener(this);
        this.f1834c = (TextView) findViewById(C0415R.id.task_manager_title);
        this.f1835d = (LinearLayout) findViewById(C0415R.id.progress_bar);
        this.f1836e = (LinearLayout) findViewById(C0415R.id.linear_empty);
        this.f1837f = (ListView) findViewById(C0415R.id.ignoreList);
        this.f1839h = (Button) findViewById(C0415R.id.one_key_delete);
        this.f1839h.setOnClickListener(this);
        this.f1845n = this;
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.performancecenter.performance.TaskManagerActivity$2] */
    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1835d.setVisibility(0);
        this.f1840i = new ArrayList();
        this.f1841j = new ArrayList<>();
        this.f1842k = new ArrayList<>();
        this.f1844m = 0;
        this.f1843l = new ArrayList<>();
        new Thread() { // from class: com.lenovo.performancecenter.performance.TaskManagerActivity.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                PackageManager pm = TaskManagerActivity.this.getPackageManager();
                Log.i(TaskManagerActivity.TAG, System.currentTimeMillis() + "initListData start");
                int totalDisplayAppCount = TaskManagerActivity.this.m719a(pm);
                Log.i(TaskManagerActivity.TAG, System.currentTimeMillis() + "initListData end");
                Message msg = TaskManagerActivity.this.f1847p.obtainMessage(1);
                msg.arg1 = totalDisplayAppCount;
                TaskManagerActivity.this.f1847p.sendMessage(msg);
            }
        }.start();
        this.f1838g = new C0195a(this);
        this.f1837f.setAdapter((ListAdapter) this.f1838g);
        this.f1837f.setOnItemClickListener(this.f1846o);
        TrackEvent.trackResume(this);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public int m719a(PackageManager pm) {
        HashMap<String, int[]> runningAppMap;
        long interval = System.currentTimeMillis() - Utils.getLastKillTime(this.f1845n);
        int totalDisplayAppCount = 0;
        if (interval <= Utils.CLICK_INTERVAL && interval > 0) {
            runningAppMap = new HashMap<>();
        } else {
            Log.i(TAG, System.currentTimeMillis() + "readRunningAppCountIncludingHidden start");
            runningAppMap = ScanApplicationInfo.getRunningAppInfoJustInLauncher(this.f1845n);
            Log.i(TAG, System.currentTimeMillis() + "readRunningAppCountIncludingHidden end");
        }
        for (Map.Entry<String, int[]> element : runningAppMap.entrySet()) {
            String pkgName = element.getKey();
            this.f1843l.add(pkgName);
            if (element.getValue()[2] == 1) {
                try {
                    ApplicationInfo appInfo = pm.getApplicationInfo(pkgName, 0);
                    SoftReference<Bitmap> bitMap = new SoftReference<>(DataLayerManager.drawableToBitmap(appInfo.loadIcon(pm)));
                    String appName = ((Object) appInfo.loadLabel(pm)) + "";
                    int flag = (appInfo.flags & 1) <= 0 ? 0 : 1;
                    AppInfo info = new AppInfo(pkgName, appName, null, bitMap.get(), 0, flag);
                    info.memory = element.getValue()[1];
                    this.f1844m += info.memory;
                    totalDisplayAppCount++;
                    if (info.flag == 0) {
                        this.f1841j.add(info);
                    } else {
                        this.f1842k.add(info);
                    }
                } catch (PackageManager.NameNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }
        if (this.f1841j.size() > 0) {
            AppInfo userTitle = new AppInfo(true, true, getString(C0415R.string.title_ignore_white_list_user_app));
            this.f1841j.add(0, userTitle);
        }
        if (this.f1842k.size() > 0) {
            AppInfo systemTitle = new AppInfo(true, false, getString(C0415R.string.title_ignore_white_list_system_app));
            this.f1842k.add(0, systemTitle);
        }
        this.f1841j.trimToSize();
        this.f1842k.trimToSize();
        this.f1840i.addAll(this.f1841j);
        this.f1840i.addAll(this.f1842k);
        return totalDisplayAppCount;
    }

    @Override // android.app.Activity
    public void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.one_key_delete /* 2131297479 */:
                this.f1834c.setVisibility(8);
                this.f1836e.setVisibility(0);
                RootPassage.execRootCmd(null, this.f1843l, " -fs ", this.f1845n);
                Utils.recordKillTimeAndPosition(this.f1845n, System.currentTimeMillis(), 2);
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    @Override // android.app.Activity
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.TaskManagerActivity$a */
    class C0195a extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f1852b;

        public C0195a(Context context) {
            this.f1852b = (LayoutInflater) context.getSystemService("layout_inflater");
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return TaskManagerActivity.this.f1840i.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return TaskManagerActivity.this.f1840i.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0196b holder;
            if (convertView == null) {
                holder = TaskManagerActivity.this.new C0196b();
                if (position != 0 && position != TaskManagerActivity.this.f1841j.size()) {
                    convertView = this.f1852b.inflate(C0415R.layout.rf_perf_taskmanager_detial, (ViewGroup) null);
                    holder.f1855c = (TextView) convertView.findViewById(C0415R.id.title);
                    holder.f1856d = (TextView) convertView.findViewById(C0415R.id.memory);
                    holder.f1854b = (ImageView) convertView.findViewById(C0415R.id.icon);
                    holder.f1857e = (ImageView) convertView.findViewById(C0415R.id.appDelete);
                } else {
                    convertView = this.f1852b.inflate(C0415R.layout.list_checkbox_item_title, (ViewGroup) null);
                    holder.f1855c = (TextView) convertView.findViewById(R.id.title);
                }
                convertView.setTag(holder);
            } else {
                holder = (C0196b) convertView.getTag();
            }
            AppInfo aInfo = (AppInfo) TaskManagerActivity.this.f1840i.get(position);
            if (aInfo != null) {
                if (aInfo.isTitle) {
                    String title = aInfo.isUserApp ? aInfo.title.replaceAll("%1\\$s", (TaskManagerActivity.this.f1841j.size() - 1) + "") : aInfo.title.replaceAll("%1\\$s", (TaskManagerActivity.this.f1842k.size() - 1) + "");
                    holder.f1855c.setText(title);
                } else {
                    holder.f1858f = aInfo.pkgName;
                    holder.f1859g = aInfo.memory;
                    if (aInfo.appIcon != null) {
                        holder.f1854b.setImageBitmap(aInfo.appIcon);
                    }
                    if (aInfo.appName != null) {
                        holder.f1855c.setText(aInfo.appName);
                    }
                    holder.f1856d.setText(Formatter.formatFileSize(TaskManagerActivity.this.f1845n, aInfo.memory));
                    holder.f1857e.setVisibility(0);
                }
            }
            return convertView;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getItemViewType(int position) {
            return (position == 0 || position == TaskManagerActivity.this.f1841j.size()) ? 0 : 1;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getViewTypeCount() {
            return 2;
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        if (this.f1840i != null) {
            this.f1840i.clear();
        }
        super.onDestroy();
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.TaskManagerActivity$b */
    class C0196b {

        /* JADX INFO: renamed from: b */
        private ImageView f1854b;

        /* JADX INFO: renamed from: c */
        private TextView f1855c;

        /* JADX INFO: renamed from: d */
        private TextView f1856d;

        /* JADX INFO: renamed from: e */
        private ImageView f1857e;

        /* JADX INFO: renamed from: f */
        private String f1858f;

        /* JADX INFO: renamed from: g */
        private int f1859g;

        C0196b() {
        }
    }
}
