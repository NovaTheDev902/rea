package com.lenovo.performancecenter.performance;

import android.R;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
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
import com.lenovo.performancecenter.framework.DataLayerManager;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.framework.PerformanceDatabaseHelper;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.platform.BaseTitlePreferenceActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import java.lang.ref.SoftReference;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class IgnorePreferenceActivity extends BaseTitlePreferenceActivity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private Button f1720a;

    /* JADX INFO: renamed from: b */
    private ListView f1721b;

    /* JADX INFO: renamed from: c */
    private List<AppInfo> f1722c;

    /* JADX INFO: renamed from: d */
    private ArrayList<AppInfo> f1723d;

    /* JADX INFO: renamed from: e */
    private ArrayList<AppInfo> f1724e;

    /* JADX INFO: renamed from: f */
    private PackageManager f1725f;

    /* JADX INFO: renamed from: g */
    private SQLiteDatabase f1726g;

    /* JADX INFO: renamed from: h */
    private PerformanceDatabaseHelper f1727h;

    /* JADX INFO: renamed from: i */
    private LinearLayout f1728i;

    /* JADX INFO: renamed from: j */
    private C0177a f1729j;

    /* JADX INFO: renamed from: k */
    private ArrayList<String> f1730k;

    /* JADX INFO: renamed from: l */
    private Handler f1731l = new Handler() { // from class: com.lenovo.performancecenter.performance.IgnorePreferenceActivity.3
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    IgnorePreferenceActivity.this.f1728i.setVisibility(8);
                    IgnorePreferenceActivity.this.f1729j.notifyDataSetChanged();
                    break;
                case 2:
                    IgnorePreferenceActivity.this.f1729j.notifyDataSetChanged();
                    break;
                case 3:
                    IgnorePreferenceActivity.this.onResume();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: f */
    static /* synthetic */ void m642f(IgnorePreferenceActivity x0) {
        SoftReference softReference;
        String str;
        x0.f1730k = DataLayerManager.getWhiteListNotKill(x0);
        x0.f1724e = new ArrayList<>();
        x0.f1723d = new ArrayList<>();
        if (x0.f1726g != null) {
            Cursor cursorRawQuery = x0.f1726g.rawQuery("SELECT DISTINCT * FROM ApplicationsInfo where state = 1 ", null);
            if (cursorRawQuery != null && cursorRawQuery.getCount() > 0) {
                ArrayList arrayList = new ArrayList();
                ArrayList arrayList2 = new ArrayList();
                cursorRawQuery.moveToFirst();
                while (!cursorRawQuery.isAfterLast()) {
                    int i = cursorRawQuery.getInt(cursorRawQuery.getColumnIndex(DatabaseTables.APPLICATIONS_FLAG));
                    String string = cursorRawQuery.getString(cursorRawQuery.getColumnIndex("pkgName"));
                    String string2 = cursorRawQuery.getString(cursorRawQuery.getColumnIndex("appName"));
                    SoftReference softReference2 = new SoftReference(BitmapFactory.decodeResource(x0.getResources(), C0415R.drawable.antispamicon));
                    try {
                        string2 = ((Object) x0.f1725f.getApplicationInfo(string, 0).loadLabel(x0.f1725f)) + "";
                        softReference = new SoftReference(DataLayerManager.drawableToBitmap(x0.f1725f.getApplicationIcon(string)));
                        str = string2;
                    } catch (PackageManager.NameNotFoundException e) {
                        e.printStackTrace();
                        softReference = softReference2;
                        str = string2;
                    }
                    AppInfo appInfo = new AppInfo(string, str, cursorRawQuery.getString(cursorRawQuery.getColumnIndex(DatabaseTables.APPLICATIONS_PROC_NAME)), (Bitmap) softReference.get(), 1, i);
                    if (x0.f1730k.contains(string)) {
                        appInfo.canRemove = false;
                        if (appInfo.flag == 0) {
                            arrayList.add(appInfo);
                        } else {
                            arrayList2.add(appInfo);
                        }
                    } else {
                        appInfo.canRemove = true;
                        if (appInfo.flag == 0) {
                            x0.f1724e.add(appInfo);
                        } else {
                            x0.f1723d.add(appInfo);
                        }
                    }
                    cursorRawQuery.moveToNext();
                }
                x0.f1724e.addAll(arrayList);
                x0.f1723d.addAll(arrayList2);
            }
            AppInfo appInfo2 = new AppInfo(true, true, x0.getString(C0415R.string.title_ignore_white_list_user_app));
            AppInfo appInfo3 = new AppInfo(true, false, x0.getString(C0415R.string.title_ignore_white_list_system_app));
            if (x0.f1724e.size() > 0) {
                x0.f1724e.add(0, appInfo2);
                x0.f1722c.addAll(x0.f1724e);
            }
            if (x0.f1723d.size() > 0) {
                x0.f1723d.add(0, appInfo3);
            }
            x0.f1724e.trimToSize();
            x0.f1723d.trimToSize();
            x0.f1722c.addAll(x0.f1723d);
            if (cursorRawQuery != null) {
                cursorRawQuery.close();
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.title_ignore_white_list, null);
        this.f1725f = getPackageManager();
        setContentView(C0415R.layout.rf_perf_ignore_apps);
        this.f1728i = (LinearLayout) findViewById(C0415R.id.progress_bar);
        this.f1721b = (ListView) findViewById(C0415R.id.ignoreList);
        this.f1720a = (Button) findViewById(C0415R.id.add);
        this.f1720a.setOnClickListener(this);
    }

    @Override // android.app.Activity
    public void onStart() {
        super.onStart();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.performancecenter.performance.IgnorePreferenceActivity$2] */
    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        this.f1728i.setVisibility(0);
        this.f1722c = new ArrayList();
        if (this.f1727h == null) {
            this.f1727h = new PerformanceDatabaseHelper(this);
        }
        if (this.f1726g == null) {
            this.f1726g = this.f1727h.getReadableDatabase();
        }
        new Thread() { // from class: com.lenovo.performancecenter.performance.IgnorePreferenceActivity.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                IgnorePreferenceActivity.m642f(IgnorePreferenceActivity.this);
                Message msg = IgnorePreferenceActivity.this.f1731l.obtainMessage(1);
                msg.arg1 = 0;
                IgnorePreferenceActivity.this.f1731l.sendMessage(msg);
            }
        }.start();
        this.f1729j = new C0177a(this);
        this.f1721b.setAdapter((ListAdapter) this.f1729j);
        this.f1721b.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.performancecenter.performance.IgnorePreferenceActivity.1
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                C0178b vh;
                String pkgName;
                try {
                    int userSize = IgnorePreferenceActivity.this.f1724e.size();
                    if (position != 0 && position != userSize && (pkgName = (vh = (C0178b) view.getTag()).f1740d) != null && !IgnorePreferenceActivity.this.f1730k.contains(pkgName)) {
                        IgnorePreferenceActivity.this.f1722c.remove(position);
                        if (position <= userSize) {
                            IgnorePreferenceActivity.this.f1724e.remove(position);
                            if (IgnorePreferenceActivity.this.f1724e.size() == 1) {
                                IgnorePreferenceActivity.this.f1722c.remove(0);
                                IgnorePreferenceActivity.this.f1724e.remove(0);
                            }
                        } else {
                            IgnorePreferenceActivity.this.f1723d.remove(position - userSize);
                            if (IgnorePreferenceActivity.this.f1723d.size() == 1) {
                                IgnorePreferenceActivity.this.f1722c.remove(userSize);
                                IgnorePreferenceActivity.this.f1723d.remove(0);
                            }
                        }
                        IgnorePreferenceActivity.this.f1729j.notifyDataSetChanged();
                        DataLayerManager.updateApplication(IgnorePreferenceActivity.this, vh.f1740d, 0);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            m637a();
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override // android.app.Activity
    public void onPause() {
        super.onPause();
        if (this.f1726g != null) {
            this.f1726g.close();
            this.f1726g = null;
        }
        if (this.f1727h != null) {
            this.f1727h.close();
            this.f1727h = null;
        }
        TrackEvent.trackPause(this);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.add) {
            Intent intent = new Intent(this, (Class<?>) WhiteListSelectActivity.class);
            startActivity(intent);
        } else if (v.getId() == C0415R.id.base_title_left) {
            m637a();
        }
    }

    /* JADX INFO: renamed from: a */
    private void m637a() {
        Intent intent = new Intent(this, (Class<?>) PhoneAccelerateActivity.class);
        startActivity(intent);
        finish();
    }

    @Override // android.preference.PreferenceActivity, android.app.Activity
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.IgnorePreferenceActivity$a */
    class C0177a extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f1736b;

        public C0177a(Context context) {
            this.f1736b = (LayoutInflater) context.getSystemService("layout_inflater");
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return IgnorePreferenceActivity.this.f1722c.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return IgnorePreferenceActivity.this.f1722c.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0178b holder;
            if (convertView == null) {
                if (position != 0 && position != IgnorePreferenceActivity.this.f1724e.size()) {
                    convertView = this.f1736b.inflate(C0415R.layout.list_checkbox_item_other, (ViewGroup) null);
                    holder = IgnorePreferenceActivity.this.new C0178b();
                    holder.f1739c = (TextView) convertView.findViewById(C0415R.id.title);
                    holder.f1738b = (ImageView) convertView.findViewById(C0415R.id.icon);
                    holder.f1741e = (ImageView) convertView.findViewById(C0415R.id.appDelete);
                } else {
                    convertView = this.f1736b.inflate(C0415R.layout.list_checkbox_item_title, (ViewGroup) null);
                    holder = IgnorePreferenceActivity.this.new C0178b();
                    holder.f1739c = (TextView) convertView.findViewById(R.id.title);
                }
                convertView.setTag(holder);
            } else {
                holder = (C0178b) convertView.getTag();
            }
            AppInfo aInfo = (AppInfo) IgnorePreferenceActivity.this.f1722c.get(position);
            if (aInfo != null) {
                if (aInfo.isTitle) {
                    String title = aInfo.isUserApp ? aInfo.title.replaceAll("%1\\$s", (IgnorePreferenceActivity.this.f1724e.size() - 1) + "") : aInfo.title.replaceAll("%1\\$s", (IgnorePreferenceActivity.this.f1723d.size() - 1) + "");
                    holder.f1739c.setText(title);
                } else {
                    holder.f1740d = aInfo.pkgName;
                    if (aInfo.appName != null) {
                        holder.f1739c.setText(aInfo.appName);
                    }
                    if (aInfo.appIcon != null) {
                        holder.f1738b.setImageBitmap(aInfo.appIcon);
                    }
                    if (aInfo.canRemove) {
                        holder.f1741e.setVisibility(0);
                    } else {
                        holder.f1741e.setVisibility(8);
                        convertView.setClickable(false);
                    }
                }
            }
            return convertView;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getItemViewType(int position) {
            return (position == 0 || position == IgnorePreferenceActivity.this.f1724e.size()) ? 0 : 1;
        }

        @Override // android.widget.BaseAdapter, android.widget.Adapter
        public final int getViewTypeCount() {
            return 2;
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.ListActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        if (this.f1722c != null) {
            this.f1722c.clear();
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.IgnorePreferenceActivity$b */
    class C0178b {

        /* JADX INFO: renamed from: b */
        private ImageView f1738b;

        /* JADX INFO: renamed from: c */
        private TextView f1739c;

        /* JADX INFO: renamed from: d */
        private String f1740d;

        /* JADX INFO: renamed from: e */
        private ImageView f1741e;

        C0178b() {
        }
    }
}
