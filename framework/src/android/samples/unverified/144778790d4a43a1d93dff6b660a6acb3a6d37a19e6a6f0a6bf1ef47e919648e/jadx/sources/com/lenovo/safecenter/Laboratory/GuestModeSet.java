package com.lenovo.safecenter.Laboratory;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.ProgressDialog;
import android.content.ContentResolver;
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
import android.widget.Button;
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
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class GuestModeSet extends Activity {
    public static final int CHANGE_BACKGROUND = 7;
    public static final int CLEAN_HISTORY = 3;
    public static final int DISABLE_OPERATE_SUCCESS = 5;
    public static final int ENABLE_OPERATE_SUCCESS = 4;
    public static final int INIT_DATA = 0;
    public static final int ITEM_OPERATE_FAILED = 6;
    public static final int OPERATE_FAILED = 2;
    public static final int OPERATE_SUCCESS = 1;

    /* JADX INFO: renamed from: b */
    private int f2561b;

    /* JADX INFO: renamed from: c */
    private AppDatabase f2562c;

    /* JADX INFO: renamed from: d */
    private SharedPreferences f2563d;

    /* JADX INFO: renamed from: e */
    private List<AppInfo> f2564e;

    /* JADX INFO: renamed from: f */
    private List<AppInfo> f2565f;

    /* JADX INFO: renamed from: g */
    private ArrayList<AppInfo> f2566g;

    /* JADX INFO: renamed from: h */
    private List<ActivityManager.RunningTaskInfo> f2567h;

    /* JADX INFO: renamed from: i */
    private AppInfo f2568i;

    /* JADX INFO: renamed from: j */
    private ListView f2569j;

    /* JADX INFO: renamed from: k */
    private ProgressBar f2570k;

    /* JADX INFO: renamed from: l */
    private ProgressDialog f2571l;

    /* JADX INFO: renamed from: m */
    private CheckBox f2572m;

    /* JADX INFO: renamed from: n */
    private Button f2573n;

    /* JADX INFO: renamed from: o */
    private TextView f2574o;

    /* JADX INFO: renamed from: p */
    private TextView f2575p;

    /* JADX INFO: renamed from: q */
    private TextView f2576q;

    /* JADX INFO: renamed from: r */
    private ContentResolver f2577r;

    /* JADX INFO: renamed from: s */
    private boolean f2578s;

    /* JADX INFO: renamed from: t */
    private boolean f2579t;

    /* JADX INFO: renamed from: u */
    private boolean f2580u;

    /* JADX INFO: renamed from: a */
    private int f2560a = 10;

    /* JADX INFO: renamed from: v */
    private Handler f2581v = new Handler() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    GuestModeSet.this.f2570k.setVisibility(8);
                    GuestModeSet.this.f2569j.setAdapter((ListAdapter) GuestModeSet.this.new C0359a(GuestModeSet.this, GuestModeSet.this.f2566g));
                    break;
                case 1:
                    try {
                        if (GuestModeSet.this.f2571l != null) {
                            GuestModeSet.this.f2571l.dismiss();
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    GuestModeSet.this.f2579t = GuestModeSet.this.f2579t ? false : true;
                    GuestModeSet.this.f2573n.setEnabled(true);
                    if (GuestModeSet.this.f2579t) {
                        GuestModeSet.this.f2573n.setBackgroundResource(C0415R.drawable.btn_on);
                    } else {
                        GuestModeSet.this.f2573n.setBackgroundResource(C0415R.drawable.btn_off);
                    }
                    LeSafeObservable.get(GuestModeSet.this).noticeChangeGuestModeSuccess();
                    break;
                case 2:
                    try {
                        if (GuestModeSet.this.f2571l != null) {
                            GuestModeSet.this.f2571l.dismiss();
                        }
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                    GuestModeSet.this.f2573n.setEnabled(true);
                    Toast.makeText(GuestModeSet.this, C0415R.string.info_failed, 1).show();
                    LeSafeObservable.get(GuestModeSet.this).noticeChangeChildModeFail();
                    break;
                case 3:
                    GuestModeSet.this.f2572m.setChecked(true);
                    break;
                case 4:
                    try {
                        if (GuestModeSet.this.f2571l != null) {
                            GuestModeSet.this.f2571l.dismiss();
                        }
                    } catch (Exception e3) {
                        e3.printStackTrace();
                    }
                    GuestModeSet.this.f2569j.setEnabled(true);
                    GuestModeSet.this.f2562c.deleteApp(GuestModeSet.this.f2568i.packageName, 1);
                    GuestModeSet.m1204j(GuestModeSet.this);
                    GuestModeSet.this.f2568i.selected = 0;
                    GuestModeSet.this.f2569j.invalidateViews();
                    break;
                case 5:
                    try {
                        if (GuestModeSet.this.f2571l != null) {
                            GuestModeSet.this.f2571l.dismiss();
                        }
                    } catch (Exception e4) {
                        e4.printStackTrace();
                    }
                    GuestModeSet.this.f2569j.setEnabled(true);
                    GuestModeSet.m1205k(GuestModeSet.this);
                    GuestModeSet.this.f2568i.selected = 1;
                    GuestModeSet.this.f2569j.invalidateViews();
                    break;
                case 6:
                    try {
                        if (GuestModeSet.this.f2571l != null) {
                            GuestModeSet.this.f2571l.dismiss();
                        }
                    } catch (Exception e5) {
                        e5.printStackTrace();
                    }
                    GuestModeSet.this.f2569j.setEnabled(true);
                    Toast.makeText(GuestModeSet.this, C0415R.string.info_failed, 1).show();
                    break;
                case 7:
                    GuestModeSet.this.f2575p.setVisibility(8);
                    GuestModeSet.this.f2576q.setVisibility(0);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: w */
    private View.OnClickListener f2582w = new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.8
        /* JADX WARN: Type inference failed for: r0v3, types: [com.lenovo.safecenter.Laboratory.GuestModeSet$8$1] */
        @Override // android.view.View.OnClickListener
        public final void onClick(View v) {
            GuestModeSet.this.f2573n.setEnabled(false);
            GuestModeSet.this.m1194a();
            new Thread() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.8.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    if (GuestModeSet.this.f2579t) {
                        if (SafeCenter.closeGuestMode(GuestModeSet.this, false, GuestModeSet.this.f2562c)) {
                            GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(1));
                            return;
                        } else {
                            Settings.System.putInt(GuestModeSet.this.f2577r, "guest_mode_on", 1);
                            GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(2));
                            return;
                        }
                    }
                    if (SafeCenter.openGuestMode(GuestModeSet.this, GuestModeSet.this.f2578s, GuestModeSet.this.f2562c)) {
                        GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(1));
                        return;
                    }
                    if (GuestModeSet.this.f2578s) {
                        Settings.System.putInt(GuestModeSet.this.f2577r, "child_mode_on", 1);
                    }
                    Settings.System.putInt(GuestModeSet.this.f2577r, "guest_mode_on", 0);
                    GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(2));
                }
            }.start();
        }
    };

    /* JADX INFO: renamed from: x */
    private AdapterView.OnItemClickListener f2583x = new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.9
        /* JADX WARN: Type inference failed for: r1v21, types: [com.lenovo.safecenter.Laboratory.GuestModeSet$9$1] */
        @Override // android.widget.AdapterView.OnItemClickListener
        public final void onItemClick(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
            if (!GuestModeSet.this.f2580u) {
                GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(7));
                return;
            }
            GuestModeSet.this.f2568i = (AppInfo) GuestModeSet.this.f2566g.get(arg2);
            boolean flag = GuestModeSet.this.f2568i.selected == 0;
            if (flag) {
                if (GuestModeSet.this.f2561b < GuestModeSet.this.f2560a) {
                    if (!GuestModeSet.this.f2579t) {
                        if (GuestModeSet.this.f2562c.insertApp(GuestModeSet.this.f2568i, 1) == 1) {
                            GuestModeSet.m1205k(GuestModeSet.this);
                            GuestModeSet.this.f2568i.selected = 1;
                            GuestModeSet.this.f2569j.invalidateViews();
                            return;
                        }
                        return;
                    }
                    GuestModeSet.m1216v(GuestModeSet.this);
                    return;
                }
                GuestModeSet.m1217w(GuestModeSet.this);
                return;
            }
            if (GuestModeSet.this.f2579t) {
                GuestModeSet.this.m1194a();
                GuestModeSet.this.f2569j.setEnabled(false);
                new Thread() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.9.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        if (CMDHelper.enableApp(GuestModeSet.this.getApplicationContext(), GuestModeSet.this.f2568i.packageName)) {
                            GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(4));
                        } else {
                            GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(6));
                        }
                    }
                }.start();
            } else {
                GuestModeSet.this.f2562c.deleteApp(GuestModeSet.this.f2568i.packageName, 1);
                GuestModeSet.m1204j(GuestModeSet.this);
                GuestModeSet.this.f2568i.selected = 0;
                GuestModeSet.this.f2569j.invalidateViews();
            }
        }
    };

    /* JADX INFO: renamed from: j */
    static /* synthetic */ int m1204j(GuestModeSet x0) {
        int i = x0.f2561b;
        x0.f2561b = i - 1;
        return i;
    }

    /* JADX INFO: renamed from: k */
    static /* synthetic */ int m1205k(GuestModeSet x0) {
        int i = x0.f2561b;
        x0.f2561b = i + 1;
        return i;
    }

    /* JADX INFO: renamed from: n */
    static /* synthetic */ void m1208n(GuestModeSet x0) {
        x0.f2566g = new ArrayList<>();
        x0.f2567h = ((ActivityManager) x0.getSystemService("activity")).getRunningTasks(100);
        x0.f2564e = x0.f2562c.queryAllHideApps(1);
        x0.f2561b = x0.f2564e.size();
        x0.f2565f = SafeCenter.getLauncherApp(x0, x0.f2564e);
        Iterator<AppInfo> it = x0.f2564e.iterator();
        while (it.hasNext()) {
            x0.f2566g.add(it.next());
        }
        Iterator<AppInfo> it2 = x0.f2565f.iterator();
        while (it2.hasNext()) {
            x0.f2566g.add(it2.next());
        }
    }

    /* JADX WARN: Type inference failed for: r0v7, types: [com.lenovo.safecenter.Laboratory.GuestModeSet$10] */
    /* JADX INFO: renamed from: v */
    static /* synthetic */ void m1216v(GuestModeSet x0) {
        boolean z;
        Iterator<ActivityManager.RunningTaskInfo> it = x0.f2567h.iterator();
        while (true) {
            if (!it.hasNext()) {
                z = false;
                break;
            }
            ActivityManager.RunningTaskInfo next = it.next();
            if (next.topActivity.getPackageName().equals(x0.f2568i.packageName) || next.baseActivity.getPackageName().equals(x0.f2568i.packageName)) {
                z = true;
                break;
            }
        }
        if (z) {
            new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(x0.f2568i.name + x0.getString(C0415R.string.app_running)).setPositiveButton(C0415R.string.yes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.12
                /* JADX WARN: Type inference failed for: r0v6, types: [com.lenovo.safecenter.Laboratory.GuestModeSet$12$1] */
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    if (GuestModeSet.this.f2562c.insertApp(GuestModeSet.this.f2568i, 1) == 1) {
                        GuestModeSet.this.m1194a();
                        GuestModeSet.this.f2569j.setEnabled(false);
                        new Thread() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.12.1
                            @Override // java.lang.Thread, java.lang.Runnable
                            public final void run() {
                                if (CMDHelper.disableApp(GuestModeSet.this.getApplicationContext(), GuestModeSet.this.f2568i.packageName)) {
                                    GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(5));
                                } else {
                                    GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(6));
                                }
                            }
                        }.start();
                    }
                }
            }).setNegativeButton(C0415R.string.no, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.11
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                }
            }).show();
        } else if (x0.f2562c.insertApp(x0.f2568i, 1) == 1) {
            x0.m1194a();
            x0.f2569j.setEnabled(false);
            new Thread() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.10
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    if (CMDHelper.disableApp(GuestModeSet.this.getApplicationContext(), GuestModeSet.this.f2568i.packageName)) {
                        GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(5));
                    } else {
                        GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(6));
                    }
                }
            }.start();
        }
    }

    /* JADX INFO: renamed from: w */
    static /* synthetic */ void m1217w(GuestModeSet x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.max_hide_apps).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.13
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: x */
    static /* synthetic */ ProgressDialog m1218x(GuestModeSet x0) {
        x0.f2571l = null;
        return null;
    }

    /* JADX WARN: Type inference failed for: r0v47, types: [com.lenovo.safecenter.Laboratory.GuestModeSet$6] */
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.guestmode);
        this.f2580u = WflUtils.isRoot();
        this.f2562c = new AppDatabase(this);
        this.f2563d = PreferenceManager.getDefaultSharedPreferences(this);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(getString(C0415R.string.guest_mode));
        ((ImageView) findViewById(C0415R.id.title_set)).setVisibility(4);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                GuestModeSet.this.finish();
            }
        });
        this.f2575p = (TextView) findViewById(C0415R.id.show_root_info);
        this.f2576q = (TextView) findViewById(C0415R.id.show_root_info_select);
        this.f2574o = (TextView) findViewById(C0415R.id.guestmode_tip);
        if (this.f2580u) {
            this.f2574o.setVisibility(0);
        } else {
            this.f2575p.setVisibility(0);
        }
        this.f2570k = (ProgressBar) findViewById(C0415R.id.guest_progress_bar);
        this.f2569j = (ListView) findViewById(C0415R.id.guestmode_list);
        this.f2569j.setOnItemClickListener(this.f2583x);
        this.f2577r = getContentResolver();
        this.f2578s = Settings.System.getInt(this.f2577r, "child_mode_on", 0) == 1;
        this.f2579t = Settings.System.getInt(this.f2577r, "guest_mode_on", 0) == 1;
        this.f2573n = (Button) findViewById(C0415R.id.mode_switch);
        if (this.f2579t) {
            this.f2573n.setBackgroundResource(C0415R.drawable.btn_on);
        } else {
            this.f2573n.setBackgroundResource(C0415R.drawable.btn_off);
        }
        if (this.f2580u && Const.mDefaultPreference.getBoolean(Const.SWITCH_INJECT_SWITCH, true)) {
            this.f2573n.setOnClickListener(this.f2582w);
        }
        this.f2570k.setVisibility(0);
        new Thread() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.6
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                GuestModeSet.m1208n(GuestModeSet.this);
                Message msg = new Message();
                msg.what = 0;
                GuestModeSet.this.f2581v.sendMessage(msg);
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.GuestModeSet$a */
    private class C0359a extends BaseAdapter {

        /* JADX INFO: renamed from: a */
        Context f2601a;

        /* JADX INFO: renamed from: b */
        List<AppInfo> f2602b;

        public C0359a(Context context, List<AppInfo> list) {
            this.f2601a = context;
            this.f2602b = list;
        }

        @Override // android.widget.Adapter
        public final int getCount() {
            return this.f2602b.size();
        }

        @Override // android.widget.Adapter
        public final Object getItem(int position) {
            return this.f2602b.get(position);
        }

        @Override // android.widget.Adapter
        public final long getItemId(int position) {
            return position;
        }

        @Override // android.widget.Adapter
        public final View getView(int position, View convertView, ViewGroup parent) {
            C0360b holder;
            if (convertView == null) {
                LayoutInflater mInflater = LayoutInflater.from(this.f2601a);
                convertView = mInflater.inflate(C0415R.layout.second_item, (ViewGroup) null);
                holder = GuestModeSet.this.new C0360b();
                holder.f2604a = (ImageView) convertView.findViewById(C0415R.id.app_icon);
                holder.f2605b = (TextView) convertView.findViewById(C0415R.id.app_name);
                holder.f2606c = (ImageView) convertView.findViewById(C0415R.id.itemcheck);
                ((TextView) convertView.findViewById(C0415R.id.app_suggest)).setVisibility(8);
                convertView.setTag(holder);
            } else {
                holder = (C0360b) convertView.getTag();
            }
            AppInfo appInfo = this.f2602b.get(position);
            holder.f2605b.setText(appInfo.name);
            if (appInfo.icon == null) {
                holder.f2604a.setImageDrawable(GuestModeSet.this.getResources().getDrawable(C0415R.drawable.icon3));
            } else {
                holder.f2604a.setImageDrawable(appInfo.icon);
            }
            if (appInfo.selected == 1) {
                holder.f2606c.setBackgroundResource(C0415R.drawable.perm_deny);
            } else {
                holder.f2606c.setBackgroundResource(C0415R.drawable.perm_grant);
            }
            return convertView;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.Laboratory.GuestModeSet$b */
    class C0360b {

        /* JADX INFO: renamed from: a */
        ImageView f2604a;

        /* JADX INFO: renamed from: b */
        TextView f2605b;

        /* JADX INFO: renamed from: c */
        ImageView f2606c;

        C0360b() {
        }
    }

    public void showRebootDialog() {
        CustomDialog.Builder builder = new CustomDialog.Builder(this);
        builder.setTitle(C0415R.string.info);
        if (this.f2579t) {
            builder.setMessage(getString(C0415R.string.close) + getString(C0415R.string.guest_mode) + getString(C0415R.string.hide_sms_info) + getString(C0415R.string.hide_sms_info2));
        } else if (this.f2578s) {
            builder.setMessage(getString(C0415R.string.open) + getString(C0415R.string.guest_mode) + getString(C0415R.string.hide_sms_info3) + getString(C0415R.string.hide_sms_info) + getString(C0415R.string.hide_sms_info1));
        } else {
            builder.setMessage(getString(C0415R.string.open) + getString(C0415R.string.guest_mode) + getString(C0415R.string.hide_sms_info) + getString(C0415R.string.hide_sms_info1));
        }
        builder.setPositiveButton(C0415R.string.yes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.2
            /* JADX WARN: Type inference failed for: r0v1, types: [com.lenovo.safecenter.Laboratory.GuestModeSet$2$1] */
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                GuestModeSet.this.m1194a();
                new Thread() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.2.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        if (GuestModeSet.this.f2579t) {
                            if (SafeCenter.closeGuestMode(GuestModeSet.this, GuestModeSet.this.f2578s, GuestModeSet.this.f2562c)) {
                                GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(1));
                                return;
                            } else {
                                Settings.System.putInt(GuestModeSet.this.f2577r, "guest_mode_on", 1);
                                GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(2));
                                return;
                            }
                        }
                        if (SafeCenter.openGuestMode(GuestModeSet.this, GuestModeSet.this.f2578s, GuestModeSet.this.f2562c)) {
                            GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(1));
                            return;
                        }
                        if (GuestModeSet.this.f2578s) {
                            Settings.System.putInt(GuestModeSet.this.f2577r, "child_mode_on", 1);
                        }
                        Settings.System.putInt(GuestModeSet.this.f2577r, "guest_mode_on", 0);
                        GuestModeSet.this.f2581v.sendMessage(GuestModeSet.this.f2581v.obtainMessage(2));
                    }
                }.start();
            }
        });
        builder.setNegativeButton(C0415R.string.no, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                GuestModeSet.this.f2573n.setEnabled(true);
            }
        });
        builder.setOnCancelListener(new DialogInterface.OnCancelListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.4
            @Override // android.content.DialogInterface.OnCancelListener
            public final void onCancel(DialogInterface dialog) {
                GuestModeSet.this.f2573n.setEnabled(true);
            }
        });
        builder.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1194a() {
        this.f2571l = new ProgressDialog(this);
        this.f2571l.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.Laboratory.GuestModeSet.5
            @Override // android.content.DialogInterface.OnDismissListener
            public final void onDismiss(DialogInterface dialog) {
                GuestModeSet.m1218x(GuestModeSet.this);
            }
        });
        this.f2571l.setProgressStyle(0);
        this.f2571l.setMessage(getString(C0415R.string.exec_state));
        this.f2571l.show();
    }
}
