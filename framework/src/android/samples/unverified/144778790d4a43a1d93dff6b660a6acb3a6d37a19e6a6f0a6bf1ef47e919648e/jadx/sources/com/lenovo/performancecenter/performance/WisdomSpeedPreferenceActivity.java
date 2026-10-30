package com.lenovo.performancecenter.performance;

import android.app.NotificationManager;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.widget.CheckBoxPreference;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.performancecenter.framework.PolicyService;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class WisdomSpeedPreferenceActivity extends BaseTitleActivity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private CheckBoxPreference f1892a;

    /* JADX INFO: renamed from: b */
    private ArrayList<C0209c> f1893b;

    /* JADX INFO: renamed from: c */
    private PolicyService f1894c;

    /* JADX INFO: renamed from: e */
    private ListView f1896e;

    /* JADX INFO: renamed from: g */
    private boolean f1898g;

    /* JADX INFO: renamed from: j */
    private NotificationManager f1901j;

    /* JADX INFO: renamed from: l */
    private String[] f1903l;

    /* JADX INFO: renamed from: m */
    private int[] f1904m;

    /* JADX INFO: renamed from: n */
    private C0207a f1905n;

    /* JADX INFO: renamed from: d */
    private boolean f1895d = false;

    /* JADX INFO: renamed from: f */
    private final boolean f1897f = false;

    /* JADX INFO: renamed from: h */
    private long f1899h = 20;

    /* JADX INFO: renamed from: i */
    private long f1900i = 20;

    /* JADX INFO: renamed from: k */
    private ServiceConnection f1902k = new ServiceConnection() { // from class: com.lenovo.performancecenter.performance.WisdomSpeedPreferenceActivity.2
        @Override // android.content.ServiceConnection
        public final void onServiceConnected(ComponentName className, IBinder service) {
            PolicyService.LocalBinder binder = (PolicyService.LocalBinder) service;
            WisdomSpeedPreferenceActivity.this.f1894c = binder.getService();
            WisdomSpeedPreferenceActivity.this.f1895d = true;
        }

        @Override // android.content.ServiceConnection
        public final void onServiceDisconnected(ComponentName arg0) {
            WisdomSpeedPreferenceActivity.this.f1895d = false;
        }
    };

    /* JADX INFO: renamed from: o */
    private Handler f1906o = new Handler() { // from class: com.lenovo.performancecenter.performance.WisdomSpeedPreferenceActivity.3
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    WisdomSpeedPreferenceActivity.this.f1905n.notifyDataSetChanged();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m767a(WisdomSpeedPreferenceActivity x0, int x1) {
        SharedPreferences.Editor editorEdit = x0.getSharedPreferences(ScanApplicationInfo.POLICY_SETTINGS, 0).edit();
        editorEdit.putLong(ScanApplicationInfo.POLICY_TIME, x1);
        editorEdit.commit();
        if (x0.f1895d) {
            x0.f1894c.updateConfiguration(ScanApplicationInfo.POLICY_TIME, Long.valueOf(x1), x0);
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.app_setup_phone);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.title_wisdom_clean, (Integer) null);
        this.f1901j = (NotificationManager) getSystemService(DatabaseTables.LOG_NOTIFICATION);
        this.f1896e = (ListView) findViewById(C0415R.id.listview);
        SharedPreferences pref = getSharedPreferences(ScanApplicationInfo.POLICY_SETTINGS, 0);
        this.f1898g = pref.getBoolean(ScanApplicationInfo.POLICY_SWITCH, false);
        this.f1892a = (CheckBoxPreference) findViewById(C0415R.id.btnLeemSwitch);
        m769a(this.f1898g);
        this.f1892a.setOnCheckedChangeListener(new CheckBoxPreference.OnCheckedChangeListener() { // from class: com.lenovo.performancecenter.performance.WisdomSpeedPreferenceActivity.1
            @Override // com.lenovo.performancecenter.coreui.widget.CheckBoxPreference.OnCheckedChangeListener
            public final void onCheckedChanged(CheckBoxPreference buttonView, boolean isChecked) {
                WisdomSpeedPreferenceActivity.this.m769a(isChecked);
                SharedPreferences pref2 = WisdomSpeedPreferenceActivity.this.getSharedPreferences(ScanApplicationInfo.POLICY_SETTINGS, 0);
                SharedPreferences.Editor edit = pref2.edit();
                edit.putBoolean(ScanApplicationInfo.POLICY_SWITCH, isChecked);
                edit.commit();
                if (WisdomSpeedPreferenceActivity.this.f1895d) {
                    WisdomSpeedPreferenceActivity.this.f1894c.updateConfiguration(ScanApplicationInfo.POLICY_SWITCH, Boolean.valueOf(isChecked), WisdomSpeedPreferenceActivity.this);
                }
                WisdomSpeedPreferenceActivity.this.f1898g = isChecked;
            }
        });
    }

    @Override // android.app.Activity
    protected void onStart() {
        super.onStart();
        Intent intent = new Intent(this, (Class<?>) PolicyService.class);
        bindService(intent, this.f1902k, 1);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            Log.i("WisdomSpeedFragment", "onKeyDown()...");
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        super.onClick(v);
        switch (v.getId()) {
            case C0415R.id.base_title_left /* 2131297465 */:
                finish();
                break;
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f1893b = new ArrayList<>();
        int i = (int) getSharedPreferences(ScanApplicationInfo.POLICY_SETTINGS, 0).getLong(ScanApplicationInfo.POLICY_TIME, this.f1899h);
        this.f1903l = getResources().getStringArray(C0415R.array.check_time_entry);
        this.f1904m = getResources().getIntArray(C0415R.array.check_time_entry_value);
        int length = this.f1903l.length;
        if (length == this.f1904m.length) {
            for (int i2 = 0; i2 < length; i2++) {
                this.f1893b.add(new C0209c(this.f1903l[i2], this.f1904m[i2], i == this.f1904m[i2] ? 1 : 0));
            }
        }
        this.f1905n = new C0207a(this);
        this.f1896e.setAdapter((ListAdapter) this.f1905n);
        this.f1896e.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.performancecenter.performance.WisdomSpeedPreferenceActivity.4
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                for (C0209c info : WisdomSpeedPreferenceActivity.this.f1893b) {
                    info.f1918c = 0;
                }
                ((C0209c) WisdomSpeedPreferenceActivity.this.f1893b.get(position)).f1918c = 1;
                WisdomSpeedPreferenceActivity.this.f1906o.sendEmptyMessage(0);
                WisdomSpeedPreferenceActivity.m767a(WisdomSpeedPreferenceActivity.this, ((C0209c) WisdomSpeedPreferenceActivity.this.f1893b.get(position)).f1917b);
            }
        });
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        if (this.f1895d) {
            unbindService(this.f1902k);
            this.f1895d = false;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m769a(boolean flag) {
        this.f1896e.setEnabled(flag);
        this.f1892a.setEnableed(flag);
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.WisdomSpeedPreferenceActivity$a */
    class C0207a extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f1912b;

        public C0207a(Context context) {
            this.f1912b = (LayoutInflater) context.getSystemService("layout_inflater");
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return WisdomSpeedPreferenceActivity.this.f1893b.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return WisdomSpeedPreferenceActivity.this.f1893b.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0208b holder;
            if (convertView == null) {
                convertView = this.f1912b.inflate(C0415R.layout.rf_perf_time_details, (ViewGroup) null);
                holder = WisdomSpeedPreferenceActivity.this.new C0208b();
                holder.f1914b = (TextView) convertView.findViewById(C0415R.id.time_name);
                holder.f1915c = (ImageView) convertView.findViewById(C0415R.id.time_radio);
                convertView.setTag(holder);
            } else {
                holder = (C0208b) convertView.getTag();
            }
            C0209c aInfo = (C0209c) WisdomSpeedPreferenceActivity.this.f1893b.get(position);
            if (aInfo != null) {
                synchronized (aInfo) {
                    if (aInfo.f1916a != null) {
                        holder.f1914b.setText(aInfo.f1916a);
                    }
                    if (aInfo.f1918c == 1) {
                        holder.f1915c.setImageResource(C0415R.drawable.radio_on);
                    } else {
                        holder.f1915c.setImageResource(C0415R.drawable.radio_off);
                    }
                }
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.WisdomSpeedPreferenceActivity$b */
    class C0208b {

        /* JADX INFO: renamed from: b */
        private TextView f1914b;

        /* JADX INFO: renamed from: c */
        private ImageView f1915c;

        C0208b() {
        }
    }

    /* JADX INFO: renamed from: com.lenovo.performancecenter.performance.WisdomSpeedPreferenceActivity$c */
    class C0209c {

        /* JADX INFO: renamed from: a */
        String f1916a;

        /* JADX INFO: renamed from: b */
        int f1917b;

        /* JADX INFO: renamed from: c */
        int f1918c;

        public C0209c(String name, int value, int state) {
            this.f1916a = name;
            this.f1917b = value;
            this.f1918c = state;
        }
    }
}
