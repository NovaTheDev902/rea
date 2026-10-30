package com.lenovo.performancecenter.performance;

import android.R;
import android.content.Context;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
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
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.framework.PerformanceDatabaseHelper;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.platform.BaseTitlePreferenceActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import java.lang.ref.SoftReference;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class WhiteListSelectActivity extends BaseTitlePreferenceActivity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private Button f1860a;

    /* JADX INFO: renamed from: b */
    private ListView f1861b;

    /* JADX INFO: renamed from: c */
    private LinearLayout f1862c;

    /* JADX INFO: renamed from: d */
    private List<C0200a> f1863d;

    /* JADX INFO: renamed from: e */
    private ArrayList<C0200a> f1864e;

    /* JADX INFO: renamed from: f */
    private ArrayList<C0200a> f1865f;

    /* JADX INFO: renamed from: g */
    private PackageManager f1866g;

    /* JADX INFO: renamed from: h */
    private SQLiteDatabase f1867h;

    /* JADX INFO: renamed from: i */
    private PerformanceDatabaseHelper f1868i;

    /* JADX INFO: renamed from: k */
    private LinearLayout f1870k;

    /* JADX INFO: renamed from: l */
    private C0201b f1871l;

    /* JADX INFO: renamed from: m */
    private ArrayList<String> f1872m;

    /* JADX INFO: renamed from: j */
    private HashMap<String, SelectedItem> f1869j = new HashMap<>();

    /* JADX INFO: renamed from: n */
    private Handler f1873n = new Handler() { // from class: com.lenovo.performancecenter.performance.WhiteListSelectActivity.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    WhiteListSelectActivity.this.f1870k.setVisibility(8);
                    WhiteListSelectActivity.this.f1871l.notifyDataSetChanged();
                    if (WhiteListSelectActivity.this.f1863d.size() == 0) {
                        WhiteListSelectActivity.this.f1862c.setVisibility(0);
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: g */
    static /* synthetic */ void m750g(WhiteListSelectActivity x0) {
        x0.f1865f = new ArrayList<>();
        x0.f1864e = new ArrayList<>();
        ArrayList<C0200a> arrayList = new ArrayList();
        if (x0.f1867h != null) {
            Cursor cursorRawQuery = x0.f1867h.rawQuery("SELECT DISTINCT * FROM ApplicationsInfo where state = 0 ", null);
            if (cursorRawQuery != null && cursorRawQuery.getCount() > 0) {
                cursorRawQuery.moveToFirst();
                while (!cursorRawQuery.isAfterLast()) {
                    int i = cursorRawQuery.getInt(cursorRawQuery.getColumnIndex(DatabaseTables.APPLICATIONS_FLAG));
                    String string = cursorRawQuery.getString(cursorRawQuery.getColumnIndex("pkgName"));
                    String string2 = cursorRawQuery.getString(cursorRawQuery.getColumnIndex("appName"));
                    SoftReference softReference = new SoftReference(BitmapFactory.decodeResource(x0.getResources(), C0415R.drawable.antispamicon));
                    try {
                        string2 = ((Object) x0.f1866g.getApplicationInfo(string, 0).loadLabel(x0.f1866g)) + "";
                        softReference = new SoftReference(DataLayerManager.drawableToBitmap(x0.f1866g.getApplicationIcon(string)));
                    } catch (PackageManager.NameNotFoundException e) {
                        e.printStackTrace();
                    }
                    arrayList.add(x0.new C0200a(string, string2, cursorRawQuery.getString(cursorRawQuery.getColumnIndex(DatabaseTables.APPLICATIONS_PROC_NAME)), (Bitmap) softReference.get(), cursorRawQuery.getInt(cursorRawQuery.getColumnIndex("state")), i));
                    cursorRawQuery.moveToNext();
                }
            }
            ArrayList<String> installedAppInLauncher = ScanApplicationInfo.getInstalledAppInLauncher(x0.getApplicationContext());
            for (C0200a c0200a : arrayList) {
                if (installedAppInLauncher.contains(c0200a.f1880d)) {
                    if (c0200a.f1883g == 0) {
                        x0.f1865f.add(c0200a);
                    } else {
                        x0.f1864e.add(c0200a);
                    }
                }
            }
            int size = x0.f1865f.size();
            int size2 = x0.f1864e.size();
            if (size != 0) {
                x0.f1865f.add(0, x0.new C0200a(x0.getString(C0415R.string.title_ignore_white_list_user_app, new Object[]{Integer.valueOf(size)})));
            }
            if (size2 != 0) {
                x0.f1864e.add(0, x0.new C0200a(x0.getString(C0415R.string.title_ignore_white_list_system_app, new Object[]{Integer.valueOf(size2)})));
            }
            x0.f1865f.trimToSize();
            x0.f1864e.trimToSize();
            x0.f1863d.addAll(x0.f1865f);
            x0.f1863d.addAll(x0.f1864e);
            if (cursorRawQuery != null) {
                cursorRawQuery.close();
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.title_ignore_white_list_add, null);
        this.f1866g = getPackageManager();
        setContentView(C0415R.layout.rf_perf_white_list);
        this.f1870k = (LinearLayout) findViewById(C0415R.id.progress_bar);
        this.f1861b = (ListView) findViewById(C0415R.id.ignoreList);
        this.f1862c = (LinearLayout) findViewById(C0415R.id.layout_empty);
        this.f1860a = (Button) findViewById(C0415R.id.add);
        this.f1860a.setOnClickListener(this);
    }

    @Override // android.app.Activity
    public void onStart() {
        super.onStart();
    }

    /* JADX WARN: Type inference failed for: r0v8, types: [com.lenovo.performancecenter.performance.WhiteListSelectActivity$3] */
    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1870k.setVisibility(0);
        this.f1872m = new ArrayList<>();
        this.f1863d = new ArrayList();
        this.f1871l = new C0201b(this);
        this.f1861b.setAdapter((ListAdapter) this.f1871l);
        this.f1861b.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.performancecenter.performance.WhiteListSelectActivity.1
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if (position != 0 && position != WhiteListSelectActivity.this.f1865f.size()) {
                    C0200a appInfo = (C0200a) WhiteListSelectActivity.this.f1863d.get(position);
                    int state = appInfo.f1882f;
                    appInfo.f1882f = state == 1 ? 0 : 1;
                    C0202c vh = (C0202c) view.getTag();
                    String pkgName = appInfo.f1880d;
                    int toState = appInfo.f1882f;
                    if (appInfo.f1882f == 1) {
                        if (!WhiteListSelectActivity.this.f1872m.contains(pkgName)) {
                            WhiteListSelectActivity.this.f1872m.add(pkgName);
                        } else {
                            return;
                        }
                    } else {
                        WhiteListSelectActivity.this.f1872m.remove(pkgName);
                    }
                    vh.f1891d.setChecked(toState == 1);
                }
            }
        });
        if (this.f1868i == null) {
            this.f1868i = new PerformanceDatabaseHelper(this);
        }
        if (this.f1867h == null) {
            this.f1867h = this.f1868i.getReadableDatabase();
        }
        new Thread() { // from class: com.lenovo.performancecenter.performance.WhiteListSelectActivity.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                WhiteListSelectActivity.m750g(WhiteListSelectActivity.this);
                Message msg = WhiteListSelectActivity.this.f1873n.obtainMessage(1);
                WhiteListSelectActivity.this.f1873n.sendMessage(msg);
            }
        }.start();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            Log.i("IgnoreFragment", "onKeyDown()...");
            finish();
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override // android.app.Activity
    public void onPause() {
        super.onPause();
        if (this.f1867h != null) {
            this.f1867h.close();
            this.f1867h = null;
        }
        if (this.f1868i != null) {
            this.f1868i.close();
            this.f1868i = null;
        }
        TrackEvent.trackPause(this);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.add) {
            DataLayerManager.updateApplicationList(this, this.f1872m, 1);
            finish();
        } else if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    @Override // android.preference.PreferenceActivity, android.app.Activity
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.WhiteListSelectActivity$b */
    class C0201b extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f1887b;

        public C0201b(Context context) {
            this.f1887b = (LayoutInflater) context.getSystemService("layout_inflater");
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return WhiteListSelectActivity.this.f1863d.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return WhiteListSelectActivity.this.f1863d.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0202c holder;
            if (convertView == null) {
                if (position != 0 && position != WhiteListSelectActivity.this.f1865f.size()) {
                    convertView = this.f1887b.inflate(C0415R.layout.list_checkbox_item_other, (ViewGroup) null);
                    holder = WhiteListSelectActivity.this.new C0202c();
                    holder.f1890c = (TextView) convertView.findViewById(C0415R.id.title);
                    holder.f1889b = (ImageView) convertView.findViewById(C0415R.id.icon);
                    holder.f1891d = (CheckBox) convertView.findViewById(C0415R.id.checkboxWidget);
                    holder.f1891d.setVisibility(0);
                } else {
                    convertView = this.f1887b.inflate(C0415R.layout.list_checkbox_item_title, (ViewGroup) null);
                    holder = WhiteListSelectActivity.this.new C0202c();
                    holder.f1890c = (TextView) convertView.findViewById(R.id.title);
                }
                convertView.setTag(holder);
            } else {
                holder = (C0202c) convertView.getTag();
            }
            C0200a aInfo = (C0200a) WhiteListSelectActivity.this.f1863d.get(position);
            if (aInfo != null) {
                if (!aInfo.f1884h) {
                    if (aInfo.f1878b != null) {
                        holder.f1890c.setText(aInfo.f1878b);
                    }
                    if (aInfo.f1879c != null) {
                        holder.f1889b.setImageBitmap(aInfo.f1879c);
                    }
                    holder.f1891d.setChecked(aInfo.f1882f == 1);
                } else {
                    holder.f1890c.setText(aInfo.f1885i);
                }
            }
            return convertView;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getItemViewType(int position) {
            return (position == 0 || position == WhiteListSelectActivity.this.f1865f.size()) ? 0 : 1;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getViewTypeCount() {
            return 2;
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.ListActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        if (this.f1863d != null) {
            this.f1863d.clear();
        }
        if (this.f1869j != null) {
            this.f1869j.clear();
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.WhiteListSelectActivity$c */
    class C0202c {

        /* JADX INFO: renamed from: b */
        private ImageView f1889b;

        /* JADX INFO: renamed from: c */
        private TextView f1890c;

        /* JADX INFO: renamed from: d */
        private CheckBox f1891d;

        C0202c() {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.WhiteListSelectActivity$a */
    class C0200a {

        /* JADX INFO: renamed from: b */
        private String f1878b;

        /* JADX INFO: renamed from: c */
        private Bitmap f1879c;

        /* JADX INFO: renamed from: d */
        private String f1880d;

        /* JADX INFO: renamed from: e */
        private String f1881e;

        /* JADX INFO: renamed from: f */
        private int f1882f;

        /* JADX INFO: renamed from: g */
        private int f1883g;

        /* JADX INFO: renamed from: h */
        private boolean f1884h;

        /* JADX INFO: renamed from: i */
        private String f1885i;

        public C0200a(String title) {
            this.f1884h = true;
            this.f1885i = title;
        }

        public C0200a(String pkgName, String appName, String procName, Bitmap appIcon, int state, int flag) {
            this.f1880d = pkgName;
            this.f1878b = appName;
            this.f1881e = procName;
            this.f1879c = appIcon;
            this.f1882f = state;
            this.f1883g = flag;
        }
    }
}
