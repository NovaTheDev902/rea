package com.lenovo.performancecenter.performance;

import android.R;
import android.app.Activity;
import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.framework.PerformanceDatabaseHelper;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class PerfWhitelistActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private LinearLayout f1742a;

    /* JADX INFO: renamed from: b */
    private LinearLayout f1743b;

    /* JADX INFO: renamed from: c */
    private ListView f1744c;

    /* JADX INFO: renamed from: d */
    private C0183b f1745d;

    /* JADX INFO: renamed from: e */
    private ImageView f1746e;

    /* JADX INFO: renamed from: f */
    private TextView f1747f;

    /* JADX INFO: renamed from: g */
    private ArrayList<C0182a> f1748g;

    /* JADX INFO: renamed from: h */
    private int f1749h;

    /* JADX INFO: renamed from: i */
    private HashMap<String, int[]> f1750i;

    /* JADX INFO: renamed from: j */
    private PackageManager f1751j;

    /* JADX INFO: renamed from: k */
    private SQLiteDatabase f1752k;

    /* JADX INFO: renamed from: l */
    private PerformanceDatabaseHelper f1753l;

    /* JADX INFO: renamed from: m */
    private ArrayList<String> f1754m;

    /* JADX INFO: renamed from: n */
    private ArrayList<String> f1755n;

    /* JADX INFO: renamed from: o */
    private Context f1756o;

    /* JADX INFO: renamed from: p */
    private AdapterView.OnItemClickListener f1757p = new AdapterView.OnItemClickListener() { // from class: com.lenovo.performancecenter.performance.PerfWhitelistActivity.1
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            C0182a appInfo = (C0182a) PerfWhitelistActivity.this.f1748g.get(position);
            if (position == 0 || position == PerfWhitelistActivity.this.f1749h) {
                return;
            }
            int state = appInfo.f1765d;
            appInfo.f1765d = state == 1 ? 0 : 1;
            String pkgName = appInfo.f1763b;
            int toState = appInfo.f1765d;
            PerfWhitelistActivity.this.f1750i.put(pkgName, new int[]{toState});
            C0184c vh = (C0184c) view.getTag();
            vh.f1775d.setChecked(toState == 1);
            if (PerfWhitelistActivity.this.f1754m.contains(pkgName) || PerfWhitelistActivity.this.f1755n.contains(pkgName)) {
                vh.f1776e.setVisibility(toState == 1 ? 4 : 0);
            } else {
                vh.f1776e.setVisibility(4);
            }
        }
    };

    /* JADX INFO: renamed from: q */
    private Handler f1758q = new Handler() { // from class: com.lenovo.performancecenter.performance.PerfWhitelistActivity.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    PerfWhitelistActivity.this.f1742a.setVisibility(8);
                    if (PerfWhitelistActivity.this.f1748g.size() == 0) {
                        PerfWhitelistActivity.this.f1743b.setVisibility(0);
                    } else {
                        PerfWhitelistActivity.this.f1745d.notifyDataSetChanged();
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: i */
    static /* synthetic */ ArrayList m663i(PerfWhitelistActivity x0) {
        ArrayList arrayList = new ArrayList();
        ArrayList arrayList2 = new ArrayList();
        ArrayList arrayList3 = new ArrayList();
        ArrayList arrayList4 = new ArrayList();
        List<ApplicationInfo> installedApplications = x0.f1751j.getInstalledApplications(0);
        ArrayList<String> installedAppInLauncher = ScanApplicationInfo.getInstalledAppInLauncher(x0.getApplicationContext());
        ArrayList<String> arrayListM653a = x0.m653a();
        for (ApplicationInfo applicationInfo : installedApplications) {
            String str = applicationInfo.packageName;
            if (installedAppInLauncher.contains(str) && !DataLayerManager.getLenovoHighLevelPkg(x0.f1756o).contains(str)) {
                boolean z = !((applicationInfo.flags & 1) <= 0);
                String str2 = ((Object) applicationInfo.loadLabel(x0.f1751j)) + "";
                Bitmap bitmapDrawableToBitmap = DataLayerManager.drawableToBitmap(applicationInfo.loadIcon(x0.f1751j));
                if (arrayListM653a.contains(str)) {
                    if (z) {
                        arrayList.add(x0.new C0182a(str, 1, 1, str2, bitmapDrawableToBitmap));
                    } else {
                        arrayList2.add(x0.new C0182a(str, 0, 1, str2, bitmapDrawableToBitmap));
                    }
                } else if (z) {
                    arrayList3.add(x0.new C0182a(str, 1, 0, str2, bitmapDrawableToBitmap));
                } else {
                    arrayList4.add(x0.new C0182a(str, 0, 0, str2, bitmapDrawableToBitmap));
                }
            }
        }
        arrayList.addAll(arrayList3);
        arrayList2.addAll(arrayList4);
        if (arrayList.size() != 0) {
            arrayList.add(0, x0.new C0182a(true, "系统应用（" + arrayList.size() + "）"));
        }
        if (arrayList2.size() != 0) {
            arrayList2.add(0, x0.new C0182a(true, "用户应用（" + arrayList2.size() + "）"));
        }
        arrayList2.trimToSize();
        arrayList.trimToSize();
        x0.f1749h = arrayList2.size();
        ArrayList arrayList5 = new ArrayList();
        arrayList5.addAll(arrayList2);
        arrayList5.addAll(arrayList);
        arrayList5.trimToSize();
        return arrayList5;
    }

    /* JADX WARN: Type inference failed for: r0v31, types: [com.lenovo.performancecenter.performance.PerfWhitelistActivity$3] */
    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.rf_perf_white_list);
        this.f1746e = (ImageView) findViewById(C0415R.id.title_back);
        this.f1747f = (TextView) findViewById(C0415R.id.txt_title);
        this.f1747f.setText(C0415R.string.title_hlmd);
        this.f1746e.setOnClickListener(this);
        this.f1742a = (LinearLayout) findViewById(C0415R.id.progress_bar);
        this.f1743b = (LinearLayout) findViewById(C0415R.id.layout_empty);
        this.f1744c = (ListView) findViewById(C0415R.id.ignoreList);
        this.f1756o = this;
        this.f1742a.setVisibility(0);
        this.f1751j = getPackageManager();
        this.f1748g = new ArrayList<>();
        this.f1749h = 0;
        this.f1750i = new HashMap<>();
        this.f1754m = DataLayerManager.getWhiteListNotKill(getApplicationContext());
        this.f1755n = DataLayerManager.getWhiteListSuggestNotKill();
        this.f1745d = new C0183b(this);
        this.f1744c.setAdapter((ListAdapter) this.f1745d);
        this.f1744c.setOnItemClickListener(this.f1757p);
        if (this.f1753l == null) {
            this.f1753l = new PerformanceDatabaseHelper(this);
        }
        if (this.f1752k == null) {
            this.f1752k = this.f1753l.getReadableDatabase();
        }
        new Thread() { // from class: com.lenovo.performancecenter.performance.PerfWhitelistActivity.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                PerfWhitelistActivity.this.f1748g = PerfWhitelistActivity.m663i(PerfWhitelistActivity.this);
                Message msg = PerfWhitelistActivity.this.f1758q.obtainMessage(1);
                PerfWhitelistActivity.this.f1758q.sendMessage(msg);
            }
        }.start();
    }

    @Override // android.app.Activity
    public void onStart() {
        super.onStart();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    /* JADX INFO: renamed from: a */
    private ArrayList<String> m653a() {
        Cursor cursor;
        ArrayList<String> listProtected = new ArrayList<>();
        if (this.f1752k != null && (cursor = this.f1752k.rawQuery("SELECT * FROM ApplicationsInfo where state = 1 ", null)) != null) {
            if (cursor.getCount() > 0) {
                cursor.moveToFirst();
                while (!cursor.isAfterLast()) {
                    String pkgName = cursor.getString(cursor.getColumnIndex("pkgName"));
                    listProtected.add(pkgName);
                    cursor.moveToNext();
                }
            }
            cursor.close();
        }
        return listProtected;
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.PerfWhitelistActivity$a */
    class C0182a {

        /* JADX INFO: renamed from: b */
        private String f1763b;

        /* JADX INFO: renamed from: c */
        private int f1764c;

        /* JADX INFO: renamed from: d */
        private int f1765d;

        /* JADX INFO: renamed from: e */
        private String f1766e;

        /* JADX INFO: renamed from: f */
        private Bitmap f1767f;

        /* JADX INFO: renamed from: g */
        private boolean f1768g;

        /* JADX INFO: renamed from: h */
        private String f1769h;

        public C0182a(String pkgName, int flag, int state, String appName, Bitmap icon) {
            this.f1763b = pkgName;
            this.f1764c = flag;
            this.f1765d = state;
            this.f1766e = appName;
            this.f1767f = icon;
        }

        public C0182a(Boolean isTitle, String titleName) {
            this.f1768g = isTitle.booleanValue();
            this.f1769h = titleName;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.PerfWhitelistActivity$b */
    class C0183b extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f1771b;

        public C0183b(Context context) {
            this.f1771b = (LayoutInflater) context.getSystemService("layout_inflater");
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return PerfWhitelistActivity.this.f1748g.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return PerfWhitelistActivity.this.f1748g.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0184c holder;
            if (convertView == null) {
                holder = PerfWhitelistActivity.this.new C0184c();
                if (position != 0 && position != PerfWhitelistActivity.this.f1749h) {
                    convertView = this.f1771b.inflate(C0415R.layout.list_checkbox_item_other, (ViewGroup) null);
                    holder.f1774c = (TextView) convertView.findViewById(C0415R.id.title);
                    holder.f1773b = (ImageView) convertView.findViewById(C0415R.id.icon);
                    holder.f1776e = (TextView) convertView.findViewById(C0415R.id.textSuggest);
                    holder.f1775d = (CheckBox) convertView.findViewById(C0415R.id.checkboxWidget);
                    holder.f1775d.setButtonDrawable(C0415R.drawable.selector_lock);
                } else {
                    convertView = this.f1771b.inflate(C0415R.layout.list_checkbox_item_title, (ViewGroup) null);
                    holder.f1774c = (TextView) convertView.findViewById(R.id.title);
                }
                convertView.setTag(holder);
            } else {
                holder = (C0184c) convertView.getTag();
            }
            C0182a appInfo = (C0182a) PerfWhitelistActivity.this.f1748g.get(position);
            Log.i("PerfWhitelist", "pkgName == " + appInfo.f1763b + " " + position + " titlePosition == " + PerfWhitelistActivity.this.f1749h);
            if (position == 0 || position == PerfWhitelistActivity.this.f1749h) {
                holder.f1774c.setText(appInfo.f1769h);
            } else {
                holder.f1774c.setText(appInfo.f1766e);
                if (holder.f1773b != null) {
                    holder.f1773b.setImageBitmap(appInfo.f1767f);
                }
                if (holder.f1775d != null) {
                    holder.f1775d.setChecked(appInfo.f1765d == 1);
                }
                if (PerfWhitelistActivity.this.f1754m.contains(appInfo.f1763b) || PerfWhitelistActivity.this.f1755n.contains(appInfo.f1763b)) {
                    holder.f1776e.setVisibility(appInfo.f1765d == 1 ? 4 : 0);
                } else {
                    holder.f1776e.setVisibility(4);
                }
            }
            return convertView;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getItemViewType(int position) {
            return (position == 0 || position == PerfWhitelistActivity.this.f1749h) ? 0 : 1;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getViewTypeCount() {
            return 2;
        }
    }

    @Override // android.app.Activity
    public void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        if (this.f1752k != null) {
            this.f1752k.close();
            this.f1752k = null;
        }
        if (this.f1753l != null) {
            this.f1753l.close();
            this.f1753l = null;
        }
        if (this.f1748g != null) {
            this.f1748g.clear();
        }
        super.onDestroy();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.title_back) {
            DataLayerManager.updateApplicationList(this, this.f1750i);
            finish();
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            DataLayerManager.updateApplicationList(this, this.f1750i);
            finish();
        }
        return super.onKeyDown(keyCode, event);
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.PerfWhitelistActivity$c */
    class C0184c {

        /* JADX INFO: renamed from: b */
        private ImageView f1773b;

        /* JADX INFO: renamed from: c */
        private TextView f1774c;

        /* JADX INFO: renamed from: d */
        private CheckBox f1775d;

        /* JADX INFO: renamed from: e */
        private TextView f1776e;

        C0184c() {
        }
    }
}
