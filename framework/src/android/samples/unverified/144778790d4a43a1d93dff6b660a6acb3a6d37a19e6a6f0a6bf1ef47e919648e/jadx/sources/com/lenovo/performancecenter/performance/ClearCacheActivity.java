package com.lenovo.performancecenter.performance;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.format.Formatter;
import android.util.Log;
import android.view.KeyEvent;
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
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.service.object.ApplicationDataInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ClearCacheActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private PackageManager f1678a;

    /* JADX INFO: renamed from: b */
    private List<DataLayerManager.CacheInfo> f1679b;

    /* JADX INFO: renamed from: c */
    private long f1680c;

    /* JADX INFO: renamed from: d */
    private TextView f1681d;

    /* JADX INFO: renamed from: e */
    private LinearLayout f1682e;

    /* JADX INFO: renamed from: f */
    private LinearLayout f1683f;

    /* JADX INFO: renamed from: g */
    private ListView f1684g;

    /* JADX INFO: renamed from: h */
    private Button f1685h;

    /* JADX INFO: renamed from: i */
    private C0169a f1686i;

    /* JADX INFO: renamed from: j */
    private ImageView f1687j;

    /* JADX INFO: renamed from: k */
    private TextView f1688k;

    /* JADX INFO: renamed from: l */
    private Handler f1689l = new Handler() { // from class: com.lenovo.performancecenter.performance.ClearCacheActivity.3
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    Log.i("ClearCacheActivity", "AppHasCacheSize == " + ClearCacheActivity.this.f1679b.size());
                    ClearCacheActivity.this.f1682e.setVisibility(8);
                    if (ClearCacheActivity.this.f1679b.isEmpty()) {
                        ClearCacheActivity.this.f1681d.setVisibility(8);
                        ClearCacheActivity.this.f1683f.setVisibility(0);
                    } else {
                        ClearCacheActivity clearCacheActivity = ClearCacheActivity.this;
                        ClearCacheActivity clearCacheActivity2 = ClearCacheActivity.this;
                        clearCacheActivity.f1680c = ClearCacheActivity.m609a(ClearCacheActivity.this.f1679b);
                        ClearCacheActivity.this.f1681d.setVisibility(0);
                        ClearCacheActivity.this.f1681d.setText(ClearCacheActivity.this.getString(C0415R.string.clear_cache_total_size, new Object[]{Formatter.formatFileSize(ClearCacheActivity.this.getApplicationContext(), ClearCacheActivity.this.f1680c)}));
                        ClearCacheActivity.this.f1683f.setVisibility(8);
                        ClearCacheActivity.this.f1686i.notifyDataSetChanged();
                    }
                    break;
                case 2:
                    if (ClearCacheActivity.this.f1679b.isEmpty()) {
                        ClearCacheActivity.this.f1681d.setVisibility(8);
                        ClearCacheActivity.this.f1683f.setVisibility(0);
                    } else {
                        ClearCacheActivity.this.f1681d.setVisibility(0);
                        ClearCacheActivity.this.f1681d.setText(ClearCacheActivity.this.getString(C0415R.string.clear_cache_total_size, new Object[]{Formatter.formatFileSize(ClearCacheActivity.this.getApplicationContext(), ClearCacheActivity.this.f1680c)}));
                    }
                    break;
                case 3:
                    ClearCacheActivity.this.f1680c = 0L;
                    ClearCacheActivity.this.f1681d.setVisibility(8);
                    ClearCacheActivity.this.f1683f.setVisibility(0);
                    break;
                case 4:
                    ClearCacheActivity.this.f1682e.setVisibility(8);
                    ClearCacheActivity.this.f1681d.setVisibility(8);
                    ClearCacheActivity.this.f1683f.setVisibility(0);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ long m609a(List x1) {
        long j = 0;
        Iterator it = x1.iterator();
        while (true) {
            long j2 = j;
            if (!it.hasNext()) {
                return j2;
            }
            j = j2 + ((DataLayerManager.CacheInfo) it.next()).appCacheSize;
        }
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.rf_perf_clear_cache);
        this.f1687j = (ImageView) findViewById(C0415R.id.title_back);
        this.f1688k = (TextView) findViewById(C0415R.id.txt_title);
        this.f1688k.setText(C0415R.string.title_clear_cache);
        this.f1687j.setOnClickListener(this);
        this.f1678a = getPackageManager();
        this.f1681d = (TextView) findViewById(C0415R.id.total_cache_size);
        this.f1682e = (LinearLayout) findViewById(C0415R.id.progress_bar);
        this.f1683f = (LinearLayout) findViewById(C0415R.id.cache_size_empty);
        this.f1684g = (ListView) findViewById(C0415R.id.ignoreList);
        this.f1685h = (Button) findViewById(C0415R.id.one_key_delete);
        this.f1685h.setOnClickListener(this);
    }

    @Override // android.app.Activity
    public void onStart() {
        super.onStart();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1682e.setVisibility(0);
        this.f1681d.setVisibility(8);
        this.f1680c = 0L;
        this.f1679b = new ArrayList();
        new Thread(new Runnable() { // from class: com.lenovo.performancecenter.performance.ClearCacheActivity.1
            @Override // java.lang.Runnable
            public final void run() {
                ApplicationDataInfo appDataInfo = new ApplicationDataInfo(ClearCacheActivity.this.getApplicationContext());
                ClearCacheActivity.this.f1679b = appDataInfo.getCacheInfo(ClearCacheActivity.this.getApplicationContext(), ClearCacheActivity.this.f1678a);
                ClearCacheActivity.this.f1689l.sendEmptyMessage(1);
            }
        }).start();
        this.f1686i = new C0169a(this);
        this.f1684g.setAdapter((ListAdapter) this.f1686i);
        this.f1684g.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.performancecenter.performance.ClearCacheActivity.2
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                DataLayerManager.CacheInfo appInfo = (DataLayerManager.CacheInfo) ClearCacheActivity.this.f1679b.get(position);
                String pkgName = appInfo.pkgName;
                if (WflUtils.isRoot()) {
                    long cacheSize = appInfo.appCacheSize;
                    ApplicationDataInfo.clearSeperateCache(ClearCacheActivity.this.getApplicationContext(), pkgName);
                    ClearCacheActivity.this.f1679b.remove(position);
                    ClearCacheActivity.this.f1686i.notifyDataSetChanged();
                    Toast.makeText(ClearCacheActivity.this, "清理“" + appInfo.appName + "”缓存" + appInfo.cacheSize, 0).show();
                    ClearCacheActivity.this.f1680c -= cacheSize;
                    ClearCacheActivity.this.f1689l.sendEmptyMessage(2);
                    return;
                }
                Uri uri = Uri.parse("package:" + pkgName);
                Intent intent = new Intent("android.settings.APPLICATION_DETAILS_SETTINGS", uri);
                ClearCacheActivity.this.startActivity(intent);
            }
        });
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            Log.i("ClearCacheActivity", "onKeyDown()...");
            finish();
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override // android.app.Activity
    public void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.one_key_delete) {
            this.f1682e.setVisibility(0);
            ApplicationDataInfo.clearAllCache(getPackageManager());
            this.f1680c = 0L;
            this.f1679b.clear();
            this.f1686i.notifyDataSetChanged();
            Message msg = this.f1689l.obtainMessage(4);
            this.f1689l.sendMessage(msg);
            return;
        }
        if (v.getId() == C0415R.id.title_back) {
            finish();
        }
    }

    @Override // android.app.Activity
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.ClearCacheActivity$a */
    class C0169a extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f1694b;

        public C0169a(Context context) {
            this.f1694b = (LayoutInflater) context.getSystemService("layout_inflater");
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return ClearCacheActivity.this.f1679b.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return ClearCacheActivity.this.f1679b.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0170b holder;
            if (convertView == null) {
                convertView = this.f1694b.inflate(C0415R.layout.rf_perf_clearcache_details, (ViewGroup) null);
                holder = ClearCacheActivity.this.new C0170b();
                holder.f1697c = (TextView) convertView.findViewById(C0415R.id.name);
                holder.f1696b = (ImageView) convertView.findViewById(C0415R.id.icon);
                holder.f1698d = (TextView) convertView.findViewById(C0415R.id.mem);
                convertView.setTag(holder);
            } else {
                holder = (C0170b) convertView.getTag();
            }
            DataLayerManager.CacheInfo aInfo = (DataLayerManager.CacheInfo) ClearCacheActivity.this.f1679b.get(position);
            if (aInfo != null) {
                if (aInfo.appName != null) {
                    holder.f1697c.setText(aInfo.appName);
                }
                if (aInfo.cacheSize != null) {
                    holder.f1698d.setText(aInfo.cacheSize);
                }
                if (aInfo.appIcon != null) {
                    holder.f1696b.setImageBitmap(aInfo.appIcon);
                }
            }
            return convertView;
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        if (this.f1679b != null) {
            this.f1679b.clear();
        }
        super.onDestroy();
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.ClearCacheActivity$b */
    class C0170b {

        /* JADX INFO: renamed from: b */
        private ImageView f1696b;

        /* JADX INFO: renamed from: c */
        private TextView f1697c;

        /* JADX INFO: renamed from: d */
        private TextView f1698d;

        C0170b() {
        }
    }
}
