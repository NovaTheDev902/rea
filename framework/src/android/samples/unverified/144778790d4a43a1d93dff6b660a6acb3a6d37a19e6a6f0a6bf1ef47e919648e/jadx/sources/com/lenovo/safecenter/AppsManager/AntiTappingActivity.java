package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.KeyEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class AntiTappingActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private PackageManager f1964a;

    /* JADX INFO: renamed from: b */
    private String[] f1965b;

    /* JADX INFO: renamed from: c */
    private String[] f1966c;

    /* JADX INFO: renamed from: d */
    private int[] f1967d;

    /* JADX INFO: renamed from: e */
    private ListView f1968e;

    /* JADX INFO: renamed from: f */
    private TextView f1969f;

    /* JADX INFO: renamed from: g */
    private Intent f1970g;

    /* JADX INFO: renamed from: h */
    private Handler f1971h = new Handler() { // from class: com.lenovo.safecenter.AppsManager.AntiTappingActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            C0215a adapter = AntiTappingActivity.this.new C0215a(AntiTappingActivity.this, AntiTappingActivity.this.f1965b);
            AntiTappingActivity.this.f1968e.setAdapter((ListAdapter) adapter);
        }
    };

    /* JADX INFO: renamed from: i */
    private AdapterView.OnItemClickListener f1972i = new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.AppsManager.AntiTappingActivity.3
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
            String pkgname = AntiTappingActivity.this.f1965b[arg2];
            try {
                AntiTappingActivity.this.getPackageManager().getApplicationInfo(pkgname, 0);
                AntiTappingActivity.this.f1970g.putExtra(QueryPermissions.PACKAGENAME, pkgname);
                AntiTappingActivity.this.f1970g.putExtra("permType", AppDatabase.PERM_TYPE_PRIVCY);
                AntiTappingActivity.this.startActivity(AntiTappingActivity.this.f1970g);
                if (AntiTappingActivity.this.f1965b.length == 1) {
                    AntiTappingActivity.this.finish();
                }
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
                Toast.makeText(AntiTappingActivity.this.getApplicationContext(), C0415R.string.not_to_appmanager, 0).show();
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.noti_tapping);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        this.f1968e = (ListView) findViewById(C0415R.id.listView);
        this.f1968e.setOnItemClickListener(this.f1972i);
        this.f1969f = (TextView) findViewById(C0415R.id.btn_known);
        this.f1969f.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.AntiTappingActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AntiTappingActivity.this.finish();
            }
        });
        TrackEvent.reportInterceptRecord();
        this.f1964a = getPackageManager();
        Intent intent = getIntent();
        if (intent != null) {
            this.f1965b = intent.getStringArrayExtra("pkgnames");
            this.f1966c = intent.getStringArrayExtra("pernames");
            this.f1967d = intent.getIntArrayExtra("actions");
        }
        this.f1971h.sendMessage(this.f1971h.obtainMessage(0));
        this.f1970g = new Intent(this, (Class<?>) AppPermManager.class);
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            keyCode = -1;
        }
        return super.onKeyDown(keyCode, event);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.AntiTappingActivity$a */
    private class C0215a extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private Context f1977b;

        /* JADX INFO: renamed from: c */
        private String[] f1978c;

        public C0215a(Context context, String[] list) {
            this.f1977b = context;
            this.f1978c = list;
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return this.f1978c.length;
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return Integer.valueOf(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0216b holder;
            if (convertView == null) {
                LinearLayout layout = new LinearLayout(this.f1977b);
                layout.setOrientation(0);
                layout.setGravity(16);
                layout.setPadding(0, 12, 0, 12);
                ImageView imageView = new ImageView(this.f1977b);
                imageView.setPadding(18, 0, 0, 0);
                layout.addView(imageView, new LinearLayout.LayoutParams(58, 58));
                TextView textView = new TextView(this.f1977b);
                textView.setPadding(18, 0, 0, 0);
                textView.setTextColor(AntiTappingActivity.this.getResources().getColor(C0415R.color.black2));
                textView.setTextSize(18.0f);
                layout.addView(textView, new LinearLayout.LayoutParams(-1, -2));
                convertView = layout;
                holder = AntiTappingActivity.this.new C0216b();
                holder.f1979a = imageView;
                holder.f1980b = textView;
                convertView.setTag(holder);
            } else {
                holder = (C0216b) convertView.getTag();
            }
            String name = "";
            try {
                ApplicationInfo appInfo = AntiTappingActivity.this.f1964a.getApplicationInfo(AntiTappingActivity.this.f1965b[position], 0);
                holder.f1979a.setImageDrawable(appInfo.loadIcon(AntiTappingActivity.this.f1964a));
                name = appInfo.loadLabel(AntiTappingActivity.this.f1964a).toString();
            } catch (PackageManager.NameNotFoundException e) {
                holder.f1979a.setImageResource(C0415R.drawable.icon3);
            }
            String content = name + "\n" + AntiTappingActivity.this.getString(C0415R.string.when_calling) + AppUtil.getPerDescription(this.f1977b, AntiTappingActivity.this.f1966c[position]);
            if (AntiTappingActivity.this.f1967d[position] == 0) {
                String allow = AntiTappingActivity.this.getString(C0415R.string.allow) + "  ";
                holder.f1980b.setText(allow + content);
                MyUtils.setSpannableString(holder.f1980b, allow + content, 0, allow.length(), AntiTappingActivity.this.getResources().getColor(C0415R.color.green_allow));
            } else {
                String str = AntiTappingActivity.this.getString(C0415R.string.notice1) + "  ";
                String forbid = str.substring(1, str.length());
                holder.f1980b.setText(forbid + content);
                MyUtils.setSpannableString(holder.f1980b, forbid + content, 0, forbid.length(), AntiTappingActivity.this.getResources().getColor(C0415R.color.red_forbid));
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.AntiTappingActivity$b */
    class C0216b {

        /* JADX INFO: renamed from: a */
        ImageView f1979a;

        /* JADX INFO: renamed from: b */
        TextView f1980b;

        C0216b() {
        }
    }
}
