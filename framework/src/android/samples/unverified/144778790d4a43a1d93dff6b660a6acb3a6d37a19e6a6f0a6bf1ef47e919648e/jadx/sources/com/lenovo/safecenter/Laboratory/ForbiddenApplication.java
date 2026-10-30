package com.lenovo.safecenter.Laboratory;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.AppInfo;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.test.SafeCenter;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ForbiddenApplication extends Activity {
    public static final int CHANGE_BACKGROUND = 7;
    public static final int CHANGE_PLAN_MODE = 3;
    public static final int DISABLE_OPERATE_SUCCESS = 5;
    public static final int ENABLE_OPERATE_SUCCESS = 4;
    public static final int INIT_DATA = 0;
    public static final int ITEM_OPERATE_FAILED = 6;
    public static final int OPERATE_FAILED = 2;
    public static final int OPERATE_SUCCESS = 1;

    /* JADX INFO: renamed from: b */
    private int f2508b;

    /* JADX INFO: renamed from: c */
    private AppDatabase f2509c;

    /* JADX INFO: renamed from: d */
    private SharedPreferences f2510d;

    /* JADX INFO: renamed from: e */
    private List<AppInfo> f2511e;

    /* JADX INFO: renamed from: f */
    private List<AppInfo> f2512f;

    /* JADX INFO: renamed from: g */
    private ArrayList<AppInfo> f2513g;

    /* JADX INFO: renamed from: h */
    private List<ActivityManager.RunningTaskInfo> f2514h;

    /* JADX INFO: renamed from: i */
    private AppInfo f2515i;

    /* JADX INFO: renamed from: j */
    private TextView f2516j;

    /* JADX INFO: renamed from: k */
    private TextView f2517k;

    /* JADX INFO: renamed from: l */
    private TextView f2518l;

    /* JADX INFO: renamed from: m */
    private TextView f2519m;

    /* JADX INFO: renamed from: n */
    private TextView f2520n;

    /* JADX INFO: renamed from: o */
    private ListView f2521o;

    /* JADX INFO: renamed from: p */
    private CheckBox f2522p;

    /* JADX INFO: renamed from: q */
    private ImageView f2523q;

    /* JADX INFO: renamed from: r */
    private ProgressBar f2524r;

    /* JADX INFO: renamed from: s */
    private ProgressDialog f2525s;

    /* JADX INFO: renamed from: t */
    private boolean f2526t;

    /* JADX INFO: renamed from: u */
    private boolean f2527u;

    /* JADX INFO: renamed from: v */
    private boolean f2528v;

    /* JADX INFO: renamed from: w */
    private boolean f2529w;

    /* JADX INFO: renamed from: a */
    private int f2507a = 10;

    /* JADX INFO: renamed from: x */
    private Handler f2530x = new Handler() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    ForbiddenApplication.this.f2524r.setVisibility(8);
                    ForbiddenApplication.this.f2521o.setAdapter((ListAdapter) ForbiddenApplication.this.new C0344a(ForbiddenApplication.this, ForbiddenApplication.this.f2513g));
                    break;
                case 1:
                    try {
                        if (ForbiddenApplication.this.f2525s != null) {
                            ForbiddenApplication.this.f2525s.dismiss();
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    ForbiddenApplication.this.f2526t = ForbiddenApplication.this.f2526t ? false : true;
                    ForbiddenApplication.this.f2523q.setEnabled(true);
                    if (ForbiddenApplication.this.f2526t) {
                        ForbiddenApplication.this.f2517k.setText(C0415R.string.opend);
                        ForbiddenApplication.this.f2523q.setImageResource(C0415R.drawable.btn_on);
                    } else {
                        ForbiddenApplication.this.f2517k.setText(C0415R.string.closed);
                        ForbiddenApplication.this.f2523q.setImageResource(C0415R.drawable.btn_off);
                    }
                    LeSafeObservable.get(ForbiddenApplication.this).noticeChangeGuestModeSuccess();
                    break;
                case 2:
                    try {
                        if (ForbiddenApplication.this.f2525s != null) {
                            ForbiddenApplication.this.f2525s.dismiss();
                        }
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                    ForbiddenApplication.this.f2523q.setEnabled(true);
                    Toast.makeText(ForbiddenApplication.this, C0415R.string.info_failed, 1).show();
                    LeSafeObservable.get(ForbiddenApplication.this).noticeChangeChildModeFail();
                    break;
                case 3:
                    try {
                        if (ForbiddenApplication.this.f2525s != null) {
                            ForbiddenApplication.this.f2525s.dismiss();
                        }
                    } catch (Exception e3) {
                        e3.printStackTrace();
                    }
                    ForbiddenApplication.this.f2522p.setEnabled(true);
                    ForbiddenApplication.this.f2522p.setChecked(ForbiddenApplication.this.f2527u);
                    break;
                case 4:
                    try {
                        if (ForbiddenApplication.this.f2525s != null) {
                            ForbiddenApplication.this.f2525s.dismiss();
                        }
                    } catch (Exception e4) {
                        e4.printStackTrace();
                    }
                    ForbiddenApplication.this.f2521o.setEnabled(true);
                    ForbiddenApplication.this.f2509c.deleteApp(ForbiddenApplication.this.f2515i.packageName, 0);
                    ForbiddenApplication.m1178l(ForbiddenApplication.this);
                    ForbiddenApplication.this.f2515i.selected = 0;
                    ForbiddenApplication.this.f2521o.invalidateViews();
                    break;
                case 5:
                    try {
                        if (ForbiddenApplication.this.f2525s != null) {
                            ForbiddenApplication.this.f2525s.dismiss();
                        }
                    } catch (Exception e5) {
                        e5.printStackTrace();
                    }
                    ForbiddenApplication.this.f2521o.setEnabled(true);
                    ForbiddenApplication.m1179m(ForbiddenApplication.this);
                    ForbiddenApplication.this.f2515i.selected = 1;
                    ForbiddenApplication.this.f2521o.invalidateViews();
                    break;
                case 6:
                    try {
                        if (ForbiddenApplication.this.f2525s != null) {
                            ForbiddenApplication.this.f2525s.dismiss();
                        }
                    } catch (Exception e6) {
                        e6.printStackTrace();
                    }
                    ForbiddenApplication.this.f2521o.setEnabled(true);
                    Toast.makeText(ForbiddenApplication.this, C0415R.string.info_failed, 1).show();
                    break;
                case 7:
                    ForbiddenApplication.this.f2519m.setVisibility(8);
                    ForbiddenApplication.this.f2520n.setVisibility(0);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: y */
    private AdapterView.OnItemClickListener f2531y = new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.12
        /* JADX WARN: Type inference failed for: r1v21, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$12$1] */
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
            if (!ForbiddenApplication.this.f2529w) {
                ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(7));
                return;
            }
            ForbiddenApplication.this.f2515i = (AppInfo) ForbiddenApplication.this.f2513g.get(arg2);
            boolean flag = ForbiddenApplication.this.f2515i.selected == 0;
            if (flag) {
                if (ForbiddenApplication.this.f2508b < ForbiddenApplication.this.f2507a) {
                    if (!ForbiddenApplication.this.f2526t) {
                        if (ForbiddenApplication.this.f2509c.insertApp(ForbiddenApplication.this.f2515i, 0) == 1) {
                            ForbiddenApplication.m1179m(ForbiddenApplication.this);
                            ForbiddenApplication.this.f2515i.selected = 1;
                            ForbiddenApplication.this.f2521o.invalidateViews();
                            return;
                        }
                        return;
                    }
                    ForbiddenApplication.m1187u(ForbiddenApplication.this);
                    return;
                }
                ForbiddenApplication.m1188v(ForbiddenApplication.this);
                return;
            }
            if (ForbiddenApplication.this.f2526t) {
                ForbiddenApplication.this.m1164a();
                ForbiddenApplication.this.f2521o.setEnabled(false);
                new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.12.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        if (CMDHelper.enableApp(ForbiddenApplication.this.getApplicationContext(), ForbiddenApplication.this.f2515i.packageName)) {
                            ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(4));
                        } else {
                            ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(6));
                        }
                    }
                }.start();
            } else {
                ForbiddenApplication.this.f2509c.deleteApp(ForbiddenApplication.this.f2515i.packageName, 0);
                ForbiddenApplication.m1178l(ForbiddenApplication.this);
                ForbiddenApplication.this.f2515i.selected = 0;
                ForbiddenApplication.this.f2521o.invalidateViews();
            }
        }
    };

    /* JADX INFO: renamed from: z */
    private View.OnClickListener f2532z = new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.17
        @Override // android.view.View.OnClickListener
        public final void onClick(View v) {
            if (!ForbiddenApplication.this.f2529w) {
                ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(7));
                return;
            }
            if (v.getId() == C0415R.id.antispam_checkbox) {
                ForbiddenApplication.this.f2523q.setEnabled(false);
                ForbiddenApplication.m1190x(ForbiddenApplication.this);
            } else if (v.getId() == C0415R.id.plan_mode_check) {
                ForbiddenApplication.this.f2527u = ForbiddenApplication.this.f2527u ? false : true;
                ForbiddenApplication.m1169c(ForbiddenApplication.this, ForbiddenApplication.this.f2527u);
            }
        }
    };

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$16] */
    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m1169c(ForbiddenApplication x0, boolean x1) {
        x0.f2527u = x1;
        x0.f2510d.edit().putBoolean("plan_mode_preference", x0.f2527u).commit();
        if (x0.f2526t) {
            x0.f2522p.setEnabled(false);
            SafeCenter.setFlyModeEnable(x0, x1);
            new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.16
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    try {
                        Thread.sleep(4000L);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(3));
                }
            }.start();
        }
    }

    /* JADX INFO: renamed from: l */
    static /* synthetic */ int m1178l(ForbiddenApplication x0) {
        int i = x0.f2508b;
        x0.f2508b = i - 1;
        return i;
    }

    /* JADX INFO: renamed from: m */
    static /* synthetic */ int m1179m(ForbiddenApplication x0) {
        int i = x0.f2508b;
        x0.f2508b = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: p */
    static /* synthetic */ void m1182p(ForbiddenApplication x0) {
        x0.f2509c = new AppDatabase(x0);
        x0.f2513g = new ArrayList<>();
        x0.f2514h = ((ActivityManager) x0.getSystemService("activity")).getRunningTasks(100);
        x0.f2511e = x0.f2509c.queryAllHideApps(0);
        x0.f2508b = x0.f2511e.size();
        x0.f2512f = SafeCenter.getLauncherApp(x0, x0.f2511e);
        Iterator<AppInfo> it = x0.f2511e.iterator();
        while (it.hasNext()) {
            x0.f2513g.add(it.next());
        }
        Iterator<AppInfo> it2 = x0.f2512f.iterator();
        while (it2.hasNext()) {
            x0.f2513g.add(it2.next());
        }
    }

    /* JADX WARN: Type inference failed for: r0v7, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$3] */
    /* JADX INFO: renamed from: u */
    static /* synthetic */ void m1187u(ForbiddenApplication x0) {
        boolean z;
        Iterator<ActivityManager.RunningTaskInfo> it = x0.f2514h.iterator();
        while (true) {
            if (!it.hasNext()) {
                z = false;
                break;
            }
            ActivityManager.RunningTaskInfo next = it.next();
            if (next.topActivity.getPackageName().equals(x0.f2515i.packageName) || next.baseActivity.getPackageName().equals(x0.f2515i.packageName)) {
                z = true;
                break;
            }
        }
        if (z) {
            new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(x0.f2515i.name + x0.getString(C0415R.string.app_running)).setPositiveButton(C0415R.string.yes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.5
                /* JADX WARN: Type inference failed for: r0v6, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$5$1] */
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    if (ForbiddenApplication.this.f2509c.insertApp(ForbiddenApplication.this.f2515i, 0) == 1) {
                        ForbiddenApplication.this.m1164a();
                        ForbiddenApplication.this.f2521o.setEnabled(false);
                        new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.5.1
                            @Override // java.lang.Thread, java.lang.Runnable
                            public final void run() {
                                if (CMDHelper.disableApp(ForbiddenApplication.this.getApplicationContext(), ForbiddenApplication.this.f2515i.packageName)) {
                                    ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(5));
                                } else {
                                    ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(6));
                                }
                            }
                        }.start();
                    }
                }
            }).setNegativeButton(C0415R.string.no, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.4
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                }
            }).show();
        } else if (x0.f2509c.insertApp(x0.f2515i, 0) == 1) {
            x0.m1164a();
            x0.f2521o.setEnabled(false);
            new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.3
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    if (CMDHelper.disableApp(ForbiddenApplication.this.getApplicationContext(), ForbiddenApplication.this.f2515i.packageName)) {
                        ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(5));
                    } else {
                        ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(6));
                    }
                }
            }.start();
        }
    }

    /* JADX INFO: renamed from: v */
    static /* synthetic */ void m1188v(ForbiddenApplication x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.max_hide_apps).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX WARN: Type inference failed for: r0v2, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$15] */
    /* JADX WARN: Type inference failed for: r0v3, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$14] */
    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$13] */
    /* JADX INFO: renamed from: x */
    static /* synthetic */ void m1190x(ForbiddenApplication x0) {
        if (x0.f2526t) {
            x0.m1164a();
            new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.13
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    if (SafeCenter.closeChildMode(ForbiddenApplication.this, ForbiddenApplication.this.f2509c)) {
                        if (ForbiddenApplication.this.f2527u) {
                            try {
                                Thread.sleep(4000L);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }
                        ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(1));
                        return;
                    }
                    ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(2));
                }
            }.start();
            return;
        }
        x0.m1164a();
        if (x0.f2528v) {
            new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.14
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    if (SafeCenter.closeGuestMode(ForbiddenApplication.this, true, ForbiddenApplication.this.f2509c)) {
                        ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(1));
                        return;
                    }
                    if (!ForbiddenApplication.this.f2526t) {
                        Settings.System.putInt(ForbiddenApplication.this.getContentResolver(), "child_mode_on", 0);
                    }
                    Settings.System.putInt(ForbiddenApplication.this.getContentResolver(), "guest_mode_on", 1);
                    ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(2));
                }
            }.start();
        } else {
            new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.15
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    if (SafeCenter.openChildMode(ForbiddenApplication.this, ForbiddenApplication.this.f2509c)) {
                        if (ForbiddenApplication.this.f2527u) {
                            try {
                                Thread.sleep(4000L);
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }
                        ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(1));
                        return;
                    }
                    ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(2));
                }
            }.start();
        }
    }

    /* JADX INFO: renamed from: y */
    static /* synthetic */ ProgressDialog m1191y(ForbiddenApplication x0) {
        x0.f2525s = null;
        return null;
    }

    /* JADX WARN: Type inference failed for: r0v47, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$10] */
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.childmode);
        this.f2510d = PreferenceManager.getDefaultSharedPreferences(this);
        this.f2529w = WflUtils.isRoot();
        ((TextView) findViewById(C0415R.id.txt_title)).setText(getString(C0415R.string.child_mode));
        ((ImageView) findViewById(C0415R.id.title_set)).setVisibility(4);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.11
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ForbiddenApplication.this.finish();
            }
        });
        this.f2519m = (TextView) findViewById(C0415R.id.show_root_info);
        this.f2520n = (TextView) findViewById(C0415R.id.show_root_info_select);
        this.f2518l = (TextView) findViewById(C0415R.id.childmode_tip);
        if (this.f2529w) {
            this.f2518l.setVisibility(0);
        } else {
            this.f2519m.setVisibility(0);
        }
        this.f2524r = (ProgressBar) findViewById(C0415R.id.child_progress_bar);
        this.f2521o = (ListView) findViewById(C0415R.id.childmode_list);
        this.f2521o.setOnItemClickListener(this.f2531y);
        this.f2522p = (CheckBox) findViewById(C0415R.id.plan_mode_check);
        this.f2522p.setOnClickListener(this.f2532z);
        if (!this.f2529w) {
            this.f2522p.setEnabled(false);
        }
        this.f2516j = (TextView) findViewById(C0415R.id.antispam_txt);
        this.f2516j.setText(C0415R.string.child_mode);
        this.f2517k = (TextView) findViewById(C0415R.id.antispam_checkboxtxt);
        this.f2523q = (ImageView) findViewById(C0415R.id.antispam_checkbox);
        if (this.f2529w) {
            this.f2523q.setOnClickListener(this.f2532z);
        }
        this.f2524r.setVisibility(0);
        new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.10
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ForbiddenApplication.m1182p(ForbiddenApplication.this);
                ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(0));
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        this.f2526t = Settings.System.getInt(getContentResolver(), "child_mode_on", 0) == 1;
        this.f2528v = Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 1;
        if (this.f2526t) {
            this.f2517k.setText(C0415R.string.opend);
            this.f2523q.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f2517k.setText(C0415R.string.closed);
            this.f2523q.setImageResource(C0415R.drawable.btn_off);
        }
        boolean airplan = Settings.System.getInt(getContentResolver(), "airplane_mode_on", 0) == 1;
        this.f2527u = airplan;
        this.f2510d.edit().putBoolean("plan_mode_preference", this.f2527u).commit();
        this.f2522p.setChecked(this.f2527u);
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1164a() {
        this.f2525s = new ProgressDialog(this);
        this.f2525s.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.2
            @Override // android.content.DialogInterface.OnDismissListener
            public final void onDismiss(DialogInterface dialog) {
                ForbiddenApplication.m1191y(ForbiddenApplication.this);
            }
        });
        this.f2525s.setProgressStyle(0);
        this.f2525s.setMessage(getString(C0415R.string.exec_state));
        this.f2525s.show();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.ForbiddenApplication$a */
    private class C0344a extends BaseAdapter {

        /* JADX INFO: renamed from: a */
        Context f2553a;

        /* JADX INFO: renamed from: b */
        List<AppInfo> f2554b;

        public C0344a(Context context, List<AppInfo> list) {
            this.f2553a = context;
            this.f2554b = list;
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return this.f2554b.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return this.f2554b.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0345b holder;
            if (convertView == null) {
                LayoutInflater mInflater = LayoutInflater.from(this.f2553a);
                convertView = mInflater.inflate(C0415R.layout.second_item, (ViewGroup) null);
                holder = ForbiddenApplication.this.new C0345b();
                holder.f2556a = (ImageView) convertView.findViewById(C0415R.id.app_icon);
                holder.f2557b = (TextView) convertView.findViewById(C0415R.id.app_name);
                holder.f2558c = (ImageView) convertView.findViewById(C0415R.id.itemcheck);
                ((TextView) convertView.findViewById(C0415R.id.app_suggest)).setVisibility(8);
                convertView.setTag(holder);
            } else {
                holder = (C0345b) convertView.getTag();
            }
            AppInfo appInfo = this.f2554b.get(position);
            holder.f2557b.setText(appInfo.name);
            if (appInfo.icon == null) {
                holder.f2556a.setImageDrawable(ForbiddenApplication.this.getResources().getDrawable(C0415R.drawable.icon3));
            } else {
                holder.f2556a.setImageDrawable(appInfo.icon);
            }
            if (appInfo.selected == 1) {
                holder.f2558c.setBackgroundResource(C0415R.drawable.perm_deny);
            } else {
                holder.f2558c.setBackgroundResource(C0415R.drawable.perm_grant);
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.ForbiddenApplication$b */
    class C0345b {

        /* JADX INFO: renamed from: a */
        ImageView f2556a;

        /* JADX INFO: renamed from: b */
        TextView f2557b;

        /* JADX INFO: renamed from: c */
        ImageView f2558c;

        C0345b() {
        }
    }

    public void showRebootDialog() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.info).setMessage(C0415R.string.reboot_info).setPositiveButton(C0415R.string.yes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.9
            /* JADX WARN: Type inference failed for: r0v1, types: [com.lenovo.safecenter.Laboratory.ForbiddenApplication$9$1] */
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ForbiddenApplication.this.m1164a();
                new Thread() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.9.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        if (SafeCenter.closeGuestMode(ForbiddenApplication.this, true, ForbiddenApplication.this.f2509c)) {
                            ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(1));
                            return;
                        }
                        if (!ForbiddenApplication.this.f2526t) {
                            Settings.System.putInt(ForbiddenApplication.this.getContentResolver(), "child_mode_on", 0);
                        }
                        Settings.System.putInt(ForbiddenApplication.this.getContentResolver(), "guest_mode_on", 1);
                        ForbiddenApplication.this.f2530x.sendMessage(ForbiddenApplication.this.f2530x.obtainMessage(2));
                    }
                }.start();
            }
        }).setNegativeButton(C0415R.string.no, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ForbiddenApplication.this.f2523q.setEnabled(true);
            }
        }).setOnCancelListener(new DialogInterface.OnCancelListener() { // from class: com.lenovo.safecenter.Laboratory.ForbiddenApplication.7
            @Override // android.content.DialogInterface.OnCancelListener
            public final void onCancel(DialogInterface dialog) {
                ForbiddenApplication.this.f2523q.setEnabled(true);
            }
        }).show();
    }
}
