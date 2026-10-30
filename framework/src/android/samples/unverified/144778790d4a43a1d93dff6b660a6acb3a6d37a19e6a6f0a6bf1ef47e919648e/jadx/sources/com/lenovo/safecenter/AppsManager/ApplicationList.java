package com.lenovo.safecenter.AppsManager;

import android.R;
import android.app.Activity;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.PermAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.AppInfo;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.List;
import org.apache.commons.httpclient.cookie.CookieSpec;

/* JADX INFO: loaded from: classes.dex */
public class ApplicationList extends Activity implements View.OnClickListener {
    public static final int CHANGE_BACKGROUND = 7;

    /* JADX INFO: renamed from: e */
    private Context f2050e;

    /* JADX INFO: renamed from: f */
    private PackageManager f2051f;

    /* JADX INFO: renamed from: h */
    private ArrayList<AppInfo> f2053h;

    /* JADX INFO: renamed from: i */
    private PermAdapter f2054i;

    /* JADX INFO: renamed from: j */
    private ListView f2055j;

    /* JADX INFO: renamed from: k */
    private TextView f2056k;

    /* JADX INFO: renamed from: l */
    private TextView f2057l;

    /* JADX INFO: renamed from: m */
    private TextView f2058m;

    /* JADX INFO: renamed from: n */
    private TextView f2059n;

    /* JADX INFO: renamed from: o */
    private TextView f2060o;

    /* JADX INFO: renamed from: p */
    private TextView f2061p;

    /* JADX INFO: renamed from: q */
    private TextView f2062q;

    /* JADX INFO: renamed from: r */
    private TextView f2063r;

    /* JADX INFO: renamed from: s */
    private TextView f2064s;

    /* JADX INFO: renamed from: t */
    private ProgressBar f2065t;

    /* JADX INFO: renamed from: u */
    private String f2066u;

    /* JADX INFO: renamed from: v */
    private int f2067v;

    /* JADX INFO: renamed from: w */
    private int f2068w;

    /* JADX INFO: renamed from: x */
    private boolean f2069x;

    /* JADX INFO: renamed from: a */
    private String f2046a = "android.provider.Telephony.SMS_RECEIVED";

    /* JADX INFO: renamed from: b */
    private String f2047b = "android.intent.action.NEW_OUTGOING_CALL";

    /* JADX INFO: renamed from: c */
    private List<ComponentName> f2048c = null;

    /* JADX INFO: renamed from: d */
    private List<ComponentName> f2049d = null;

    /* JADX INFO: renamed from: g */
    private AppDatabase f2052g = null;

    /* JADX INFO: renamed from: y */
    private Handler f2070y = new Handler() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    ApplicationList.m849a(ApplicationList.this);
                    if (ApplicationList.this.f2068w == 0) {
                        MyUtils.showToast(ApplicationList.this.f2050e, ApplicationList.this.getString(C0415R.string.toast_allow_all));
                    } else if (ApplicationList.this.f2068w == ApplicationList.this.f2067v) {
                        MyUtils.showToast(ApplicationList.this.f2050e, ApplicationList.this.getString(C0415R.string.toast_deny_all));
                    }
                    break;
                case 1:
                    ApplicationList.this.f2063r.setVisibility(8);
                    ApplicationList.this.f2064s.setVisibility(0);
                    break;
                case 2:
                    ApplicationList.m849a(ApplicationList.this);
                    String str = "";
                    if (!ApplicationList.this.f2066u.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
                        if (!ApplicationList.this.f2066u.equals("location")) {
                            if (!ApplicationList.this.f2066u.equals(AppDatabase.PERM_TYPE_DEVICE)) {
                                if (ApplicationList.this.f2066u.equals(AppDatabase.DB_APP_CALL)) {
                                    str = String.format(ApplicationList.this.getString(C0415R.string.toast_deny_num), Integer.valueOf(ApplicationList.this.f2068w), ApplicationList.this.getString(C0415R.string.perm_call));
                                }
                            } else {
                                str = String.format(ApplicationList.this.getString(C0415R.string.toast_deny_num), Integer.valueOf(ApplicationList.this.f2068w), ApplicationList.this.getString(C0415R.string.perm_tap_calling));
                            }
                        } else {
                            str = String.format(ApplicationList.this.getString(C0415R.string.toast_deny_num), Integer.valueOf(ApplicationList.this.f2068w), ApplicationList.this.getString(C0415R.string.perm_location_info));
                        }
                    } else {
                        str = String.format(ApplicationList.this.getString(C0415R.string.toast_deny_num), Integer.valueOf(ApplicationList.this.f2068w), ApplicationList.this.getString(C0415R.string.perm_privacy_info));
                    }
                    MyUtils.showToast(ApplicationList.this.f2050e, str);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: z */
    private AdapterView.OnItemClickListener f2071z = new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.3
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
            if (!ApplicationList.this.f2069x) {
                ApplicationList.this.f2070y.sendMessage(ApplicationList.this.f2070y.obtainMessage(1));
                return;
            }
            AppInfo app = (AppInfo) ApplicationList.this.f2053h.get(arg2);
            boolean flag = app.selected == 0;
            if (flag) {
                ApplicationList.m862k(ApplicationList.this);
                ApplicationList.this.f2070y.sendMessage(ApplicationList.this.f2070y.obtainMessage(0));
            } else {
                ApplicationList.m863l(ApplicationList.this);
                ApplicationList.this.f2070y.sendMessage(ApplicationList.this.f2070y.obtainMessage(0));
            }
            ApplicationList.m850a(ApplicationList.this, app, flag);
            ApplicationList.this.f2055j.invalidateViews();
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ int m847a(List x1, String x2) {
        int i = 0;
        while (true) {
            int i2 = i;
            if (i2 >= x1.size()) {
                return -1;
            }
            if (((ComponentName) x1.get(i2)).getPackageName().equals(x2)) {
                return i2;
            }
            i = i2 + 1;
        }
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m849a(ApplicationList x0) {
        String str = "";
        if (!x0.f2069x) {
            x0.f2063r.setVisibility(0);
            return;
        }
        if (x0.f2066u.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
            str = String.format(x0.getString(C0415R.string.deny_apps_count), Integer.valueOf(x0.f2067v), x0.getString(C0415R.string.perm_privacy_info), Integer.valueOf(x0.f2068w));
        } else if (x0.f2066u.equals("location")) {
            str = String.format(x0.getString(C0415R.string.deny_apps_count), Integer.valueOf(x0.f2067v), x0.getString(C0415R.string.perm_location_info), Integer.valueOf(x0.f2068w));
        } else if (x0.f2066u.equals(AppDatabase.PERM_TYPE_DEVICE)) {
            str = String.format(x0.getString(C0415R.string.deny_apps_count), Integer.valueOf(x0.f2067v), x0.getString(C0415R.string.perm_tap_calling), Integer.valueOf(x0.f2068w));
        } else if (x0.f2066u.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
            str = String.format(x0.getString(C0415R.string.deny_apps_count), Integer.valueOf(x0.f2067v), x0.getString(C0415R.string.perm_send_sms), Integer.valueOf(x0.f2068w));
        } else if (x0.f2066u.equals(AppDatabase.DB_APP_CALL)) {
            str = String.format(x0.getString(C0415R.string.deny_apps_count), Integer.valueOf(x0.f2067v), x0.getString(C0415R.string.perm_call), Integer.valueOf(x0.f2068w));
        }
        x0.f2058m.setVisibility(0);
        x0.f2058m.setText(str);
    }

    /* JADX WARN: Type inference failed for: r0v10, types: [com.lenovo.safecenter.AppsManager.ApplicationList$7] */
    /* JADX WARN: Type inference failed for: r0v23, types: [com.lenovo.safecenter.AppsManager.ApplicationList$6] */
    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m850a(ApplicationList x0, AppInfo x1, boolean x2) {
        if (x2) {
            x1.selected = 1;
            x0.f2052g.updateApp(x1, x0.f2066u);
            if (x0.f2066u.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
                x0.m851a(x0.f2048c, x1);
                return;
            }
            if (x0.f2066u.equals(AppDatabase.PERM_TYPE_DEVICE)) {
                x0.m851a(x0.f2049d, x1);
                return;
            } else {
                if (x0.f2066u.equals("location") && x1.packageName.equals("com.wochacha")) {
                    new Thread() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.7
                        @Override // java.lang.Thread, java.lang.Runnable
                        public final void run() {
                            CMDHelper.disableApp(ApplicationList.this.f2050e, "com.wochacha/.DataService");
                        }
                    }.start();
                    return;
                }
                return;
            }
        }
        x1.selected = 0;
        x0.f2052g.updateApp(x1, x0.f2066u);
        if (x0.f2066u.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
            x0.m853b(x0.f2048c, x1);
            return;
        }
        if (x0.f2066u.equals(AppDatabase.PERM_TYPE_DEVICE)) {
            x0.m853b(x0.f2049d, x1);
        } else if (x0.f2066u.equals("location") && x1.packageName.equals("com.wochacha")) {
            new Thread() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.6
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    CMDHelper.enableApp(ApplicationList.this.f2050e, "com.wochacha/.DataService");
                }
            }.start();
        }
    }

    /* JADX INFO: renamed from: k */
    static /* synthetic */ int m862k(ApplicationList x0) {
        int i = x0.f2068w;
        x0.f2068w = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: l */
    static /* synthetic */ int m863l(ApplicationList x0) {
        int i = x0.f2068w;
        x0.f2068w = i - 1;
        return i;
    }

    /* JADX INFO: renamed from: o */
    static /* synthetic */ void m866o(ApplicationList x0) {
        if (x0.f2053h.size() == 0) {
            x0.f2057l.setVisibility(0);
        } else {
            x0.f2057l.setVisibility(8);
            x0.f2055j.setOnItemClickListener(x0.f2071z);
            if (x0.f2069x) {
                x0.f2059n.setEnabled(true);
                x0.f2060o.setEnabled(true);
                x0.f2061p.setEnabled(true);
                x0.f2062q.setEnabled(true);
            }
        }
        x0.f2054i = new PermAdapter(x0, x0.f2053h);
        x0.f2055j.setAdapter((ListAdapter) x0.f2054i);
    }

    /* JADX INFO: renamed from: p */
    static /* synthetic */ void m867p(ApplicationList x0) {
        if (x0.f2066u.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
            x0.f2048c = x0.m848a(x0.f2046a);
        } else if (!x0.f2066u.equals("location") && x0.f2066u.equals(AppDatabase.PERM_TYPE_DEVICE)) {
            x0.f2049d = x0.m848a(x0.f2047b);
        }
        x0.f2053h = x0.f2052g.loadApps(x0, x0.f2066u, x0.f2069x);
        x0.f2067v = x0.f2053h.size();
        int i = 0;
        while (true) {
            int i2 = i;
            if (i2 >= x0.f2067v) {
                return;
            }
            if (x0.f2053h.get(i2).selected == 1) {
                x0.f2068w++;
            }
            i = i2 + 1;
        }
    }

    /* JADX INFO: renamed from: r */
    static /* synthetic */ int m869r(ApplicationList x0) {
        x0.f2068w = 0;
        return 0;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Bundle bn = getIntent().getExtras();
        this.f2066u = bn.getString("permType");
        setContentView(C0415R.layout.second_main);
        this.f2050e = this;
        this.f2069x = WflUtils.isRoot();
        this.f2051f = getPackageManager();
        this.f2052g = new AppDatabase(this);
        this.f2056k = (TextView) findViewById(C0415R.id.txt_title);
        ((ImageView) findViewById(C0415R.id.title_set)).setVisibility(4);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(this);
        this.f2058m = (TextView) findViewById(C0415R.id.deny_apps_des);
        if (this.f2066u.equals(AppDatabase.PERM_TYPE_PRIVCY)) {
            this.f2056k.setText(C0415R.string.privacy_info);
        } else if (this.f2066u.equals("location")) {
            this.f2056k.setText(C0415R.string.location_info);
        } else if (this.f2066u.equals(AppDatabase.PERM_TYPE_DEVICE)) {
            this.f2056k.setText(C0415R.string.tap_calling);
        } else if (this.f2066u.equals(AppDatabase.PERM_TYPE_INSTALLAPP)) {
            this.f2056k.setText(C0415R.string.install_app_notip);
        } else if (this.f2066u.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
            this.f2056k.setText(C0415R.string.sms_background);
        } else if (this.f2066u.equals(AppDatabase.DB_APP_CALL)) {
            this.f2056k.setText(C0415R.string.call_background);
        }
        ((LinearLayout) findViewById(C0415R.id.listView_layout)).setVisibility(0);
        this.f2055j = (ListView) findViewById(C0415R.id.listView);
        this.f2057l = (TextView) findViewById(C0415R.id.txt_empty);
        this.f2065t = (ProgressBar) findViewById(C0415R.id.progress_bar);
        this.f2059n = (TextView) findViewById(C0415R.id.selectall);
        this.f2061p = (TextView) findViewById(C0415R.id.offall);
        this.f2060o = (TextView) findViewById(C0415R.id.infoall);
        this.f2062q = (TextView) findViewById(C0415R.id.suggest);
        this.f2063r = (TextView) findViewById(C0415R.id.show_root_info);
        this.f2064s = (TextView) findViewById(C0415R.id.show_root_info_select);
        if (this.f2066u.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
            this.f2060o.setVisibility(0);
        } else {
            this.f2060o.setVisibility(8);
        }
        this.f2059n.setOnClickListener(this);
        this.f2061p.setOnClickListener(this);
        this.f2060o.setOnClickListener(this);
        this.f2062q.setOnClickListener(this);
        initApps();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.suggest /* 2131297572 */:
                this.f2068w = 0;
                this.f2052g.expertSuggest(this, this.f2053h, true);
                for (int i = 0; i < this.f2067v; i++) {
                    if (this.f2053h.get(i).selected == 1) {
                        this.f2068w++;
                    }
                }
                this.f2055j.invalidateViews();
                this.f2070y.sendMessage(this.f2070y.obtainMessage(2));
                break;
            case C0415R.id.selectall /* 2131297573 */:
                if (this.f2068w != 0) {
                    new CustomDialog.Builder(this).setTitle(C0415R.string.info).setIcon(R.drawable.ic_dialog_alert).setMessage(C0415R.string.allow_all_tip).setColorPositiveButton(false).setColorNegativeButton(true).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.9
                        @Override // android.content.DialogInterface.OnClickListener
                        public final void onClick(DialogInterface dialog, int which) {
                            try {
                                ApplicationList.this.f2052g.updateApp(ApplicationList.this.f2053h, 0);
                                ApplicationList.m869r(ApplicationList.this);
                                ApplicationList.this.f2070y.sendMessage(ApplicationList.this.f2070y.obtainMessage(0));
                                ApplicationList.this.f2055j.invalidateViews();
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                        }
                    }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.8
                        @Override // android.content.DialogInterface.OnClickListener
                        public final void onClick(DialogInterface dialog, int which) {
                        }
                    }).show();
                } else {
                    this.f2070y.sendMessage(this.f2070y.obtainMessage(0));
                }
                break;
            case C0415R.id.offall /* 2131297575 */:
                try {
                    if (this.f2068w != this.f2067v) {
                        this.f2052g.updateApp(this.f2053h, 1);
                        this.f2068w = this.f2067v;
                        this.f2055j.invalidateViews();
                    }
                    this.f2070y.sendMessage(this.f2070y.obtainMessage(0));
                } catch (Exception e) {
                    e.printStackTrace();
                    return;
                }
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        if (this.f2069x) {
            startService(new Intent(this, (Class<?>) SafeCenterService.class));
        }
        sendBroadcast(new Intent("com.lenovo.safecenter.refreshAppsManager"));
        TrackEvent.trackPause(this);
    }

    /* JADX WARN: Type inference failed for: r1v5, types: [com.lenovo.safecenter.AppsManager.ApplicationList$5] */
    public void initApps() {
        this.f2059n.setEnabled(false);
        this.f2060o.setEnabled(false);
        this.f2061p.setEnabled(false);
        this.f2062q.setEnabled(false);
        this.f2065t.setVisibility(0);
        final Handler handler = new Handler() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.4
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                ApplicationList.this.f2065t.setVisibility(8);
                ApplicationList.m849a(ApplicationList.this);
                ApplicationList.m866o(ApplicationList.this);
            }
        };
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.5
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ApplicationList.m867p(ApplicationList.this);
                handler.sendMessage(handler.obtainMessage(0));
            }
        }.start();
    }

    /* JADX INFO: renamed from: a */
    private List<ComponentName> m848a(String broadcast) {
        List<ComponentName> list = new ArrayList<>();
        Intent intent = new Intent(broadcast);
        List<ResolveInfo> resolves = this.f2051f.queryBroadcastReceivers(intent, 600);
        for (ResolveInfo resolve : resolves) {
            ApplicationInfo app = resolve.activityInfo.applicationInfo;
            if ((app.flags & 1) == 0) {
                ComponentName component = new ComponentName(app.packageName, resolve.activityInfo.name);
                list.add(component);
            }
        }
        return list;
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.AppsManager.ApplicationList$10] */
    /* JADX INFO: renamed from: a */
    private void m851a(final List<ComponentName> list, final AppInfo appInfo) {
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.10
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ApplicationList applicationList = ApplicationList.this;
                int index = ApplicationList.m847a(list, appInfo.packageName);
                if (index >= 0) {
                    ComponentName component = (ComponentName) list.get(index);
                    String str = component.getPackageName() + CookieSpec.PATH_DELIM + component.getClassName();
                    CMDHelper.disableApp(ApplicationList.this.f2050e, str);
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.AppsManager.ApplicationList$2] */
    /* JADX INFO: renamed from: b */
    private void m853b(final List<ComponentName> list, final AppInfo appInfo) {
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.ApplicationList.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ApplicationList applicationList = ApplicationList.this;
                int index = ApplicationList.m847a(list, appInfo.packageName);
                if (index >= 0) {
                    ComponentName component = (ComponentName) list.get(index);
                    String str = component.getPackageName() + CookieSpec.PATH_DELIM + component.getClassName();
                    CMDHelper.enableApp(ApplicationList.this.f2050e, str);
                }
            }
        }.start();
    }
}
