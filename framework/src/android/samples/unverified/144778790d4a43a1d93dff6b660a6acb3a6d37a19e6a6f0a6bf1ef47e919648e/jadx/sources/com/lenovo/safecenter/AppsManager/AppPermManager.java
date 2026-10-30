package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.ContentResolver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.providers.querypermissions.QueryPermissions;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class AppPermManager extends Activity implements View.OnClickListener {
    public static final int CHANGE_BACKGROUND = 8;

    /* JADX INFO: renamed from: A */
    private TextView f1982A;

    /* JADX INFO: renamed from: B */
    private RelativeLayout[] f1983B;

    /* JADX INFO: renamed from: C */
    private View f1984C;

    /* JADX INFO: renamed from: D */
    private LinearLayout f1985D;

    /* JADX INFO: renamed from: E */
    private LinearLayout f1986E;

    /* JADX INFO: renamed from: F */
    private LinearLayout f1987F;

    /* JADX INFO: renamed from: G */
    private String f1988G;

    /* JADX INFO: renamed from: H */
    private String[] f1989H;

    /* JADX INFO: renamed from: I */
    private String[] f1990I;

    /* JADX INFO: renamed from: J */
    private List<String> f1991J;

    /* JADX INFO: renamed from: K */
    private List<SafeLog> f1992K;

    /* JADX INFO: renamed from: L */
    private String f1993L;

    /* JADX INFO: renamed from: M */
    private String f1994M;

    /* JADX INFO: renamed from: N */
    private String f1995N;

    /* JADX INFO: renamed from: O */
    private String f1996O;

    /* JADX INFO: renamed from: P */
    private String f1997P;

    /* JADX INFO: renamed from: Q */
    private String f1998Q;

    /* JADX INFO: renamed from: R */
    private boolean f1999R;

    /* JADX INFO: renamed from: S */
    private boolean f2000S;

    /* JADX INFO: renamed from: T */
    private boolean f2001T;

    /* JADX INFO: renamed from: U */
    private boolean f2002U;

    /* JADX INFO: renamed from: V */
    private boolean f2003V;

    /* JADX INFO: renamed from: W */
    private boolean f2004W;

    /* JADX INFO: renamed from: X */
    private boolean f2005X;

    /* JADX INFO: renamed from: Y */
    private int f2006Y;

    /* JADX INFO: renamed from: Z */
    private int f2007Z;

    /* JADX INFO: renamed from: a */
    private AppDatabase f2008a;

    /* JADX INFO: renamed from: aa */
    private Handler f2009aa = new Handler() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    try {
                        AppPermManager.this.f1984C.setVisibility(8);
                        if (((String) AppPermManager.this.f1991J.get(AppPermManager.this.f2007Z)).equals("0")) {
                            AppPermManager.this.f2012d[AppPermManager.this.f2007Z].setText(AppPermManager.this.f1996O + AppPermManager.this.f1990I[AppPermManager.this.f2007Z]);
                            AppPermManager.this.f2013e[AppPermManager.this.f2007Z].setBackgroundResource(C0415R.drawable.perm_grant);
                        } else if (((String) AppPermManager.this.f1991J.get(AppPermManager.this.f2007Z)).equals(DatabaseTables.SYSTEM_MARK)) {
                            AppPermManager.this.f2012d[AppPermManager.this.f2007Z].setText(AppPermManager.this.f1997P + AppPermManager.this.f1990I[AppPermManager.this.f2007Z]);
                            AppPermManager.this.f2013e[AppPermManager.this.f2007Z].setBackgroundResource(C0415R.drawable.perm_deny);
                        } else if (((String) AppPermManager.this.f1991J.get(AppPermManager.this.f2007Z)).equals(DatabaseTables.USER_MARK)) {
                            AppPermManager.this.f2012d[AppPermManager.this.f2007Z].setText(AppPermManager.this.f1998Q + AppPermManager.this.f1990I[AppPermManager.this.f2007Z]);
                            AppPermManager.this.f2013e[AppPermManager.this.f2007Z].setBackgroundResource(C0415R.drawable.perm_prompt);
                        }
                    } catch (Exception e1) {
                        e1.printStackTrace();
                        return;
                    }
                    break;
                case 1:
                    if (AppPermManager.this.f2005X) {
                        if (((String) AppPermManager.this.f1991J.get(AppPermManager.this.f2007Z)).equals("0")) {
                            AppPermManager.this.f2017i.setText(AppPermManager.this.f1996O + AppPermManager.this.f1990I[AppPermManager.this.f2007Z]);
                            AppPermManager.this.f2028t.setBackgroundResource(C0415R.drawable.perm_grant);
                        } else {
                            AppPermManager.this.f2017i.setText(AppPermManager.this.f1997P + AppPermManager.this.f1990I[AppPermManager.this.f2007Z]);
                            AppPermManager.this.f2028t.setBackgroundResource(C0415R.drawable.perm_deny);
                        }
                    } else {
                        MyUtils.alert(AppPermManager.this, C0415R.string.error, AppPermManager.this.getString(C0415R.string.info_failed));
                    }
                    break;
                case 2:
                    try {
                        if (AppPermManager.this.f2003V) {
                            AppPermManager.this.f2033y.setBackgroundResource(C0415R.drawable.btn_on);
                            AppPermManager.this.f1984C.setVisibility(8);
                            AppPermManager.m835o(AppPermManager.this);
                            TrackEvent.reportTrustApp(AppPermManager.this.f1994M);
                        } else {
                            AppPermManager.this.f2033y.setBackgroundResource(C0415R.drawable.btn_off);
                            AppPermManager.this.f1984C.setVisibility(8);
                            AppPermManager.m835o(AppPermManager.this);
                        }
                    } catch (Exception e2) {
                        e2.printStackTrace();
                        return;
                    }
                    break;
                case 3:
                    for (int i = 0; i < AppPermManager.this.f1989H.length; i++) {
                        try {
                            if (!AppPermManager.this.f1989H[i].equals(AppDatabase.DB_APP_INTERNET)) {
                                AppPermManager.this.f2012d[i].setText(AppPermManager.this.f1996O + AppPermManager.this.f1990I[i]);
                                AppPermManager.this.f2013e[i].setBackgroundResource(C0415R.drawable.perm_grant);
                            }
                        } catch (Exception e) {
                            e.printStackTrace();
                            return;
                        }
                    }
                    break;
                case 4:
                    for (int i2 = 0; i2 < AppPermManager.this.f1989H.length; i2++) {
                        try {
                            if (!AppPermManager.this.f1989H[i2].equals(AppDatabase.DB_APP_INTERNET)) {
                                AppPermManager.this.f2012d[i2].setText(AppPermManager.this.f1997P + AppPermManager.this.f1990I[i2]);
                                AppPermManager.this.f2013e[i2].setBackgroundResource(C0415R.drawable.perm_deny);
                            }
                        } catch (Exception e3) {
                            e3.printStackTrace();
                            return;
                        }
                        break;
                    }
                    break;
                case 5:
                    if (AppPermManager.this.f2032x.getVisibility() == 8) {
                        AppPermManager.this.f2032x.setVisibility(0);
                    } else {
                        AppPermManager.this.f2032x.setVisibility(8);
                    }
                    break;
                case 6:
                    if (msg.arg1 == 2) {
                        try {
                            AppPermManager.this.f2011c.dismiss();
                        } catch (Exception e4) {
                            e4.printStackTrace();
                        }
                        Toast.makeText(AppPermManager.this, C0415R.string.localblack_successNotice, 0).show();
                        AppPermManager.this.f2008a.updateApp_isupload(AppPermManager.this.f1994M, 1);
                        AppPermManager.this.f2029u.setText(C0415R.string.hadupload_log);
                        AppPermManager.this.f2029u.setEnabled(false);
                    } else if (msg.arg1 == 3) {
                        try {
                            AppPermManager.this.f2011c.dismiss();
                        } catch (Exception e5) {
                            e5.printStackTrace();
                        }
                        Toast.makeText(AppPermManager.this, C0415R.string.neterror, 0).show();
                        AppPermManager.this.f2029u.setEnabled(true);
                    }
                    break;
                case 7:
                    try {
                        AppPermManager.this.f1984C.setVisibility(8);
                        for (int i3 = 0; i3 < AppPermManager.this.f1989H.length; i3++) {
                            if (((String) AppPermManager.this.f1991J.get(i3)).equals("0")) {
                                AppPermManager.this.f2012d[i3].setText(AppPermManager.this.f1996O + AppPermManager.this.f1990I[i3]);
                                AppPermManager.this.f2013e[i3].setBackgroundResource(C0415R.drawable.perm_grant);
                            } else if (((String) AppPermManager.this.f1991J.get(i3)).equals(DatabaseTables.SYSTEM_MARK)) {
                                AppPermManager.this.f2012d[i3].setText(AppPermManager.this.f1997P + AppPermManager.this.f1990I[i3]);
                                AppPermManager.this.f2013e[i3].setBackgroundResource(C0415R.drawable.perm_deny);
                            } else if (((String) AppPermManager.this.f1991J.get(i3)).equals(DatabaseTables.USER_MARK)) {
                                AppPermManager.this.f2012d[i3].setText(AppPermManager.this.f1998Q + AppPermManager.this.f1990I[i3]);
                                AppPermManager.this.f2013e[i3].setBackgroundResource(C0415R.drawable.perm_prompt);
                            }
                        }
                    } catch (Exception e6) {
                        e6.printStackTrace();
                        return;
                    }
                    break;
                case 8:
                    AppPermManager.this.f2034z.setVisibility(8);
                    AppPermManager.this.f1982A.setVisibility(0);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: b */
    private C0225a f2010b;

    /* JADX INFO: renamed from: c */
    private ProgressDialog f2011c;

    /* JADX INFO: renamed from: d */
    private TextView[] f2012d;

    /* JADX INFO: renamed from: e */
    private ImageView[] f2013e;

    /* JADX INFO: renamed from: f */
    private int[] f2014f;

    /* JADX INFO: renamed from: g */
    private TextView f2015g;

    /* JADX INFO: renamed from: h */
    private TextView f2016h;

    /* JADX INFO: renamed from: i */
    private TextView f2017i;

    /* JADX INFO: renamed from: j */
    private TextView f2018j;

    /* JADX INFO: renamed from: k */
    private TextView f2019k;

    /* JADX INFO: renamed from: l */
    private TextView f2020l;

    /* JADX INFO: renamed from: m */
    private TextView f2021m;

    /* JADX INFO: renamed from: n */
    private TextView f2022n;

    /* JADX INFO: renamed from: o */
    private TextView f2023o;

    /* JADX INFO: renamed from: p */
    private TextView f2024p;

    /* JADX INFO: renamed from: q */
    private TextView f2025q;

    /* JADX INFO: renamed from: r */
    private TextView f2026r;

    /* JADX INFO: renamed from: s */
    private ImageView f2027s;

    /* JADX INFO: renamed from: t */
    private ImageView f2028t;

    /* JADX INFO: renamed from: u */
    private TextView f2029u;

    /* JADX INFO: renamed from: v */
    private TextView f2030v;

    /* JADX INFO: renamed from: w */
    private TextView f2031w;

    /* JADX INFO: renamed from: x */
    private LinearLayout f2032x;

    /* JADX INFO: renamed from: y */
    private ImageView f2033y;

    /* JADX INFO: renamed from: z */
    private TextView f2034z;

    /* JADX INFO: renamed from: E */
    static /* synthetic */ void m798E(AppPermManager x0) {
        int i = 0;
        while (true) {
            int i2 = i;
            if (i2 >= x0.f1992K.size()) {
                x0.f2002U = true;
                return;
            }
            SafeLog safeLog = x0.f1992K.get(i2);
            View viewInflate = LayoutInflater.from(x0).inflate(C0415R.layout.new_loglist_item, (ViewGroup) null);
            viewInflate.setBackgroundResource(C0415R.drawable.setting_list_normal);
            ((TextView) viewInflate.findViewById(C0415R.id.log_time)).setVisibility(8);
            ((LinearLayout) viewInflate.findViewById(C0415R.id.event_layout)).setVisibility(8);
            TextView textView = (TextView) viewInflate.findViewById(C0415R.id.event_title);
            if (safeLog.logSelected == 1) {
                textView.setText(x0.getString(C0415R.string.when_calling) + AppUtil.getDescriptionByPid(x0, Integer.valueOf(safeLog.type).intValue()));
            } else {
                textView.setText(AppUtil.getDescriptionByPid(x0, Integer.valueOf(safeLog.type).intValue()));
            }
            ((TextView) viewInflate.findViewById(C0415R.id.event_timestamp)).setText(x0.getString(C0415R.string.last_time) + MyUtils.formatTime(safeLog.time, x0));
            if (safeLog.number == null) {
                ((TextView) viewInflate.findViewById(C0415R.id.event_package)).setVisibility(8);
            } else {
                ((TextView) viewInflate.findViewById(C0415R.id.event_package)).setText(safeLog.number);
            }
            if (safeLog.action == 0) {
                ((TextView) viewInflate.findViewById(C0415R.id.event_action)).setText(x0.getString(C0415R.string.allow_total) + "  " + safeLog.f5496id + x0.getString(C0415R.string.times));
                ((TextView) viewInflate.findViewById(C0415R.id.event_action)).setTextColor(x0.getResources().getColor(C0415R.color.green_allow));
            } else {
                ((TextView) viewInflate.findViewById(C0415R.id.event_action)).setText(x0.getString(C0415R.string.forbid_total) + "  " + safeLog.f5496id + x0.getString(C0415R.string.times));
                ((TextView) viewInflate.findViewById(C0415R.id.event_action)).setTextColor(x0.getResources().getColor(C0415R.color.red_forbid));
            }
            x0.f2032x.addView(viewInflate);
            i = i2 + 1;
        }
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.AppsManager.AppPermManager$7] */
    /* JADX INFO: renamed from: H */
    static /* synthetic */ void m801H(AppPermManager x0) {
        x0.f2011c = new ProgressDialog(x0);
        x0.f2011c.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.8
            @Override // android.content.DialogInterface.OnDismissListener
            public final void onDismiss(DialogInterface dialog) {
                AppPermManager.m803J(AppPermManager.this);
            }
        });
        x0.f2011c.setProgressStyle(0);
        x0.f2011c.setMessage(x0.getString(C0415R.string.exec_state));
        x0.f2011c.show();
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.7
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                SafeLog log = (SafeLog) AppPermManager.this.f1992K.get(0);
                String type = log.type;
                if (type.equals("0") || type.equals(DatabaseTables.SYSTEM_MARK)) {
                    if (HttpUtils.reportTariffLog(AppPermManager.this.getBaseContext(), AppPermManager.this.f1994M, log.type, log.appName, MyUtils.formatReportTime(log.time, AppPermManager.this.getBaseContext()), log.number, log.content) == 2) {
                        Message msg = AppPermManager.this.f2009aa.obtainMessage(6);
                        msg.arg1 = 2;
                        AppPermManager.this.f2009aa.sendMessage(msg);
                        return;
                    } else {
                        Message msg2 = AppPermManager.this.f2009aa.obtainMessage(6);
                        msg2.arg1 = 3;
                        AppPermManager.this.f2009aa.sendMessage(msg2);
                        return;
                    }
                }
                if (HttpUtils.reportPermissionLog(AppPermManager.this.getBaseContext(), AppPermManager.this.f1994M, log.type, log.appName, MyUtils.formatReportTime(log.time, AppPermManager.this.getBaseContext())) == 2) {
                    Message msg3 = AppPermManager.this.f2009aa.obtainMessage(6);
                    msg3.arg1 = 2;
                    AppPermManager.this.f2009aa.sendMessage(msg3);
                } else {
                    Message msg4 = AppPermManager.this.f2009aa.obtainMessage(6);
                    msg4.arg1 = 3;
                    AppPermManager.this.f2009aa.sendMessage(msg4);
                }
            }
        }.start();
    }

    /* JADX INFO: renamed from: J */
    static /* synthetic */ ProgressDialog m803J(AppPermManager x0) {
        x0.f2011c = null;
        return null;
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m810a(AppPermManager x0, int x1, int x2, int x3, int x4) {
        x0.f1983B[x1] = (RelativeLayout) x0.findViewById(x2);
        x0.f2012d[x1] = (TextView) x0.findViewById(x3);
        x0.f2013e[x1] = (ImageView) x0.findViewById(x4);
        x0.f1983B[x1].setVisibility(0);
        x0.f2013e[x1].setVisibility(0);
        x0.f1983B[x1].setOnClickListener(x0);
        x0.f2013e[x1].setOnClickListener(x0);
        if (!x0.f2001T) {
            x0.f2012d[x1].setText(x0.f1996O + x0.f1990I[x1]);
            x0.f2013e[x1].setBackgroundResource(C0415R.drawable.perm_grant);
            return;
        }
        if (x0.f1991J.get(x1).equals("0")) {
            x0.f2012d[x1].setText(x0.f1996O + x0.f1990I[x1]);
            x0.f2013e[x1].setBackgroundResource(C0415R.drawable.perm_grant);
        } else if (x0.f1991J.get(x1).equals(DatabaseTables.SYSTEM_MARK)) {
            x0.f2012d[x1].setText(x0.f1997P + x0.f1990I[x1]);
            x0.f2013e[x1].setBackgroundResource(C0415R.drawable.perm_deny);
        } else if (x0.f1991J.get(x1).equals(DatabaseTables.USER_MARK)) {
            x0.f2012d[x1].setText(x0.f1998Q + x0.f1990I[x1]);
            x0.f2013e[x1].setBackgroundResource(C0415R.drawable.perm_prompt);
        }
    }

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m811a(AppPermManager x0, TextView x1, int x2) {
        if (x2 == 0) {
            x1.setVisibility(0);
            x1.setTextColor(x0.getResources().getColor(C0415R.color.green_allow));
            x1.setText(C0415R.string.suggest_allow);
        } else {
            if (x2 != 1) {
                x1.setVisibility(4);
                return;
            }
            x1.setVisibility(0);
            x1.setTextColor(x0.getResources().getColor(C0415R.color.red_forbid));
            x1.setText(C0415R.string.suggest_forbid);
        }
    }

    /* JADX INFO: renamed from: o */
    static /* synthetic */ void m835o(AppPermManager x0) {
        int i = 0;
        try {
            if (x0.f2004W) {
                x0.f2018j.setText(C0415R.string.tariff_perm_manage);
            } else {
                x0.f2018j.setText(x0.getString(C0415R.string.anti_tariff_closed) + x0.getString(C0415R.string.anti_tariff_perm) + x0.getString(C0415R.string.perm_control_fail));
            }
            if (x0.f1999R) {
                x0.f2019k.setText(C0415R.string.privacy_perm_manage);
            } else {
                x0.f2019k.setText(x0.getString(C0415R.string.anti_privacy_closed) + x0.getString(C0415R.string.anti_privacy_perm) + x0.getString(C0415R.string.perm_control_fail));
            }
            if (x0.f2003V) {
                x0.f2031w.setText(C0415R.string.full_trust);
            } else {
                x0.f2031w.setText(C0415R.string.real_time_monitor);
            }
            if (x0.f2003V || !(x0.f2004W || x0.f1999R)) {
                x0.m808a(x0.getResources().getColor(C0415R.color.gray2));
                x0.m820b(x0.getResources().getColor(C0415R.color.gray2));
                while (i < x0.f1989H.length) {
                    x0.f1983B[i].setEnabled(false);
                    x0.f2013e[i].setClickable(false);
                    i++;
                }
                return;
            }
            if (x0.f2004W) {
                x0.m808a(x0.getResources().getColor(C0415R.color.black1));
                for (int i2 = 0; i2 < x0.f1989H.length; i2++) {
                    if (AppUtil.isTariffType(x0.f1989H[i2])) {
                        x0.f1983B[i2].setEnabled(true);
                        x0.f2013e[i2].setClickable(true);
                    }
                }
            } else {
                x0.m808a(x0.getResources().getColor(C0415R.color.gray2));
                for (int i3 = 0; i3 < x0.f1989H.length; i3++) {
                    if (AppUtil.isTariffType(x0.f1989H[i3])) {
                        x0.f1983B[i3].setEnabled(false);
                        x0.f2013e[i3].setClickable(false);
                    }
                }
            }
            if (x0.f1999R) {
                x0.m820b(x0.getResources().getColor(C0415R.color.black1));
                while (i < x0.f1989H.length) {
                    if (!AppUtil.isTariffType(x0.f1989H[i])) {
                        x0.f1983B[i].setEnabled(true);
                        x0.f2013e[i].setClickable(true);
                    }
                    i++;
                }
                return;
            }
            x0.m820b(x0.getResources().getColor(C0415R.color.gray2));
            while (i < x0.f1989H.length) {
                if (!AppUtil.isTariffType(x0.f1989H[i])) {
                    x0.f1983B[i].setEnabled(false);
                    x0.f2013e[i].setClickable(false);
                }
                i++;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.apppermmanager);
        this.f2001T = WflUtils.isRoot();
        this.f1993L = getIntent().getStringExtra("permType");
        this.f1994M = getIntent().getStringExtra(QueryPermissions.PACKAGENAME);
        this.f1995N = getIntent().getStringExtra("from");
        this.f1996O = getString(C0415R.string.allow);
        this.f1997P = getString(C0415R.string.forbid);
        this.f1998Q = getString(C0415R.string.notify);
        this.f2015g = (TextView) findViewById(C0415R.id.txt_title);
        this.f2015g.setText(C0415R.string.appmandesc);
        ((ImageView) findViewById(C0415R.id.title_set)).setVisibility(4);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (AppPermManager.this.f2000S != AppPermManager.this.f2003V) {
                    AppPermManager.this.setResult(4);
                } else {
                    AppPermManager.this.setResult(3);
                }
                AppPermManager.this.finish();
            }
        });
        this.f2016h = (TextView) findViewById(C0415R.id.perm_app_name);
        this.f2027s = (ImageView) findViewById(C0415R.id.perm_app_icon);
        this.f2018j = (TextView) findViewById(C0415R.id.tariff_group);
        this.f2019k = (TextView) findViewById(C0415R.id.privacy_group);
        this.f2020l = (TextView) findViewById(C0415R.id.app_no_log);
        this.f2017i = (TextView) findViewById(C0415R.id.txt_internet_state);
        this.f2028t = (ImageView) findViewById(C0415R.id.img_internet_state);
        this.f2033y = (ImageView) findViewById(C0415R.id.trust_app_switch);
        this.f2032x = (LinearLayout) findViewById(C0415R.id.recent_logs_layout);
        this.f2034z = (TextView) findViewById(C0415R.id.show_root_info);
        this.f1982A = (TextView) findViewById(C0415R.id.show_root_info_select);
        this.f2021m = (TextView) findViewById(C0415R.id.txt_internet_per);
        this.f2022n = (TextView) findViewById(C0415R.id.txt_sendsms_per);
        this.f2023o = (TextView) findViewById(C0415R.id.txt_call_per);
        this.f2024p = (TextView) findViewById(C0415R.id.txt_privacy_per);
        this.f2025q = (TextView) findViewById(C0415R.id.txt_location_per);
        this.f2026r = (TextView) findViewById(C0415R.id.txt_device_per);
        this.f2029u = (TextView) findViewById(C0415R.id.app_report);
        this.f2030v = (TextView) findViewById(C0415R.id.app_uninstall);
        this.f2031w = (TextView) findViewById(C0415R.id.perm_app_des);
        this.f1984C = findViewById(C0415R.id.send_msg_choose);
        this.f1985D = (LinearLayout) findViewById(C0415R.id.send_msg_allow);
        this.f1986E = (LinearLayout) findViewById(C0415R.id.send_msg_deny);
        this.f1987F = (LinearLayout) findViewById(C0415R.id.send_msg_tip);
        this.f2030v.setOnClickListener(this);
        this.f2034z.setVisibility(8);
        this.f2028t.setOnClickListener(this);
        this.f2033y.setOnClickListener(this);
        this.f2029u.setOnClickListener(this);
        this.f1984C.setOnClickListener(this);
        this.f1985D.setOnClickListener(this);
        this.f1986E.setOnClickListener(this);
        this.f1987F.setOnClickListener(this);
        if (!this.f2001T) {
            this.f2034z.setVisibility(0);
        }
        this.f2008a = new AppDatabase(this);
        PackageManager packageManager = getPackageManager();
        try {
            ApplicationInfo applicationInfo = packageManager.getApplicationInfo(this.f1994M, 8192);
            this.f2016h.setText(applicationInfo.loadLabel(packageManager).toString());
            this.f2027s.setBackgroundDrawable(applicationInfo.loadIcon(packageManager));
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        if (this.f2001T) {
            this.f2003V = this.f2008a.isAppTrusted(this.f1994M, this.f1993L);
        }
        this.f2000S = this.f2003V;
        if (this.f2003V) {
            this.f2033y.setBackgroundResource(C0415R.drawable.btn_on);
        } else {
            this.f2033y.setBackgroundResource(C0415R.drawable.btn_off);
        }
        initApps();
        this.f2010b = new C0225a(this, b);
        IntentFilter filter = new IntentFilter("android.intent.action.PACKAGE_REMOVED");
        filter.addDataScheme("package");
        registerReceiver(this.f2010b, filter);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f2010b);
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            if (this.f2000S != this.f2003V) {
                setResult(4);
            } else {
                setResult(3);
            }
            finish();
        }
        return super.onKeyDown(keyCode, event);
    }

    /* JADX INFO: renamed from: a */
    private void m808a(int color) {
        this.f2021m.setTextColor(color);
        this.f2022n.setTextColor(color);
        this.f2023o.setTextColor(color);
    }

    /* JADX INFO: renamed from: b */
    private void m820b(int color) {
        this.f2024p.setTextColor(color);
        this.f2025q.setTextColor(color);
        this.f2026r.setTextColor(color);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    /* JADX WARN: Type inference failed for: r1v1, types: [com.lenovo.safecenter.AppsManager.AppPermManager$4] */
    public synchronized void initApps() {
        final Handler handler = new Handler() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.3
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                for (int i = 0; i < AppPermManager.this.f1989H.length; i++) {
                    try {
                        if (AppPermManager.this.f1989H[i].equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                            if (AppPermManager.this.f2018j.getVisibility() != 0) {
                                AppPermManager.this.f2018j.setVisibility(0);
                            }
                            AppPermManager.m810a(AppPermManager.this, i, C0415R.id.perm_sendsms_layout, C0415R.id.txt_sendsms_state, C0415R.id.img_sendsms_state);
                            AppPermManager.m811a(AppPermManager.this, (TextView) AppPermManager.this.findViewById(C0415R.id.sendsms_suggest), AppPermManager.this.f2014f[i]);
                        } else if (AppPermManager.this.f1989H[i].equals(AppDatabase.DB_APP_CALL)) {
                            if (AppPermManager.this.f2018j.getVisibility() != 0) {
                                AppPermManager.this.f2018j.setVisibility(0);
                            }
                            AppPermManager.m810a(AppPermManager.this, i, C0415R.id.perm_call_layout, C0415R.id.txt_call_state, C0415R.id.img_call_state);
                            AppPermManager.m811a(AppPermManager.this, (TextView) AppPermManager.this.findViewById(C0415R.id.call_suggest), AppPermManager.this.f2014f[i]);
                        } else if (AppPermManager.this.f1989H[i].equals(AppDatabase.PERM_TYPE_PRIVCY)) {
                            if (AppPermManager.this.f2019k.getVisibility() != 0) {
                                AppPermManager.this.f2019k.setVisibility(0);
                            }
                            AppPermManager.m810a(AppPermManager.this, i, C0415R.id.perm_privacy_layout, C0415R.id.txt_privacy_state, C0415R.id.img_privacy_state);
                            AppPermManager.m811a(AppPermManager.this, (TextView) AppPermManager.this.findViewById(C0415R.id.privacy_suggest), AppPermManager.this.f2014f[i]);
                        } else if (AppPermManager.this.f1989H[i].equals("location")) {
                            if (AppPermManager.this.f2019k.getVisibility() != 0) {
                                AppPermManager.this.f2019k.setVisibility(0);
                            }
                            AppPermManager.m810a(AppPermManager.this, i, C0415R.id.perm_location_layout, C0415R.id.txt_location_state, C0415R.id.img_location_state);
                            AppPermManager.m811a(AppPermManager.this, (TextView) AppPermManager.this.findViewById(C0415R.id.location_suggest), AppPermManager.this.f2014f[i]);
                        } else if (AppPermManager.this.f1989H[i].equals(AppDatabase.PERM_TYPE_DEVICE)) {
                            if (AppPermManager.this.f2019k.getVisibility() != 0) {
                                AppPermManager.this.f2019k.setVisibility(0);
                            }
                            AppPermManager.m810a(AppPermManager.this, i, C0415R.id.perm_device_layout, C0415R.id.txt_device_state, C0415R.id.img_device_state);
                            AppPermManager.m811a(AppPermManager.this, (TextView) AppPermManager.this.findViewById(C0415R.id.device_suggest), AppPermManager.this.f2014f[i]);
                        }
                        if (AppPermManager.this.f1992K.size() == 0) {
                            AppPermManager.this.f2020l.setVisibility(0);
                            AppPermManager.this.f2029u.setEnabled(false);
                        } else {
                            AppPermManager.this.f2020l.setVisibility(8);
                            if (AppPermManager.this.f2008a.getApp_isupload(AppPermManager.this.f1994M) == 0) {
                                AppPermManager.this.f2029u.setEnabled(true);
                            } else {
                                AppPermManager.this.f2029u.setText(C0415R.string.hadupload_log);
                                AppPermManager.this.f2029u.setEnabled(false);
                            }
                            if (!AppPermManager.this.f2002U) {
                                AppPermManager.m798E(AppPermManager.this);
                            }
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                        return;
                    }
                }
                AppPermManager.m835o(AppPermManager.this);
                if (AppPermManager.this.f1988G.equals("")) {
                    AppPermManager.this.f2033y.setVisibility(8);
                } else {
                    AppPermManager.this.f2033y.setVisibility(0);
                }
            }
        };
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.4
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    AppPermManager.this.f2004W = Const.getProtectTrafficSwitchState();
                    AppPermManager.this.f1999R = Const.getProtectPeepSwitchState();
                    AppPermManager.this.f2006Y = AppPermManager.this.f2008a.getUid(AppPermManager.this.f1994M);
                    AppPermManager.this.f1988G = AppPermManager.this.f2008a.queryAllPermType(AppPermManager.this.f1994M, AppPermManager.this.f1993L);
                    AppPermManager.this.f1989H = AppPermManager.this.f1988G.split(",");
                    int len = AppPermManager.this.f1989H.length;
                    AppPermManager.this.f1991J = new ArrayList(len);
                    AppPermManager.this.f1983B = new RelativeLayout[len];
                    AppPermManager.this.f2012d = new TextView[len];
                    AppPermManager.this.f2013e = new ImageView[len];
                    AppPermManager.this.f1990I = new String[len];
                    AppPermManager.this.f2014f = new int[len];
                    ContentResolver resolver = AppPermManager.this.getContentResolver();
                    HashMap<String, String> map = AppUtil.getAppPermissionConfigurs(resolver, AppPermManager.this.f1994M);
                    for (int i = 0; i < len; i++) {
                        AppPermManager.this.f1991J.add(AppPermManager.this.f2008a.queryPerEnable(AppPermManager.this.f1994M, AppPermManager.this.f1989H[i]));
                        AppPermManager.this.f1990I[i] = AppPermManager.this.f2008a.getAllPermDescription(AppPermManager.this.getBaseContext(), AppPermManager.this.f1994M, AppPermManager.this.f1989H[i]);
                        AppPermManager.this.f2014f[i] = Integer.valueOf(map.get(AppPermManager.this.f1989H[i])).intValue();
                    }
                    AppPermManager.this.f1992K = AppPermManager.this.f2008a.getRecentLogs(AppPermManager.this.f1994M, AppPermManager.this.f1993L);
                    handler.sendMessage(handler.obtainMessage(0));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (!this.f2001T) {
            this.f2009aa.sendMessage(this.f2009aa.obtainMessage(8));
        }
        switch (v.getId()) {
            case C0415R.id.app_report /* 2131296743 */:
                new CustomDialog.Builder(this).setTitle(C0415R.string.info).setMessage(getString(C0415R.string.report_sure)).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.6

                    /* JADX INFO: renamed from: a */
                    final /* synthetic */ int f2041a = 0;

                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                        if (this.f2041a == 0) {
                            AppPermManager.m801H(AppPermManager.this);
                        }
                    }
                }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.AppPermManager.5
                    @Override // android.content.DialogInterface.OnClickListener
                    public final void onClick(DialogInterface dialog, int which) {
                    }
                }).show();
                break;
            case C0415R.id.app_uninstall /* 2131296744 */:
                startActivity(new Intent("android.intent.action.DELETE", Uri.parse("package:" + this.f1994M)));
                break;
            case C0415R.id.trust_app_switch /* 2131296747 */:
                this.f2003V = !this.f2003V;
                try {
                    if (this.f2003V) {
                        this.f2008a.updateAppTrust(this.f1994M, this.f1993L, 1);
                        this.f2009aa.sendMessage(this.f2009aa.obtainMessage(2));
                        for (int i = 0; i < this.f1989H.length; i++) {
                            this.f1991J.set(i, "0");
                        }
                        this.f2009aa.sendMessage(this.f2009aa.obtainMessage(3));
                    } else {
                        this.f2008a.updateAppTrust(this.f1994M, this.f1993L, 0);
                        this.f2009aa.sendMessage(this.f2009aa.obtainMessage(2));
                        for (int i2 = 0; i2 < this.f1989H.length; i2++) {
                            if (this.f2014f[i2] > -1) {
                                this.f1991J.set(i2, Integer.toString(this.f2014f[i2]));
                            } else if (this.f1989H[i2].equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                                this.f1991J.set(i2, DatabaseTables.USER_MARK);
                            } else if (this.f1989H[i2].equals(AppDatabase.PERM_TYPE_PRIVCY)) {
                                this.f1991J.set(i2, DatabaseTables.SYSTEM_MARK);
                            } else {
                                this.f1991J.set(i2, "0");
                            }
                        }
                        this.f2009aa.sendMessage(this.f2009aa.obtainMessage(7));
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    return;
                }
                break;
            case C0415R.id.send_msg_allow /* 2131296762 */:
                m809a(this.f2007Z, 0);
                this.f2009aa.sendMessage(this.f2009aa.obtainMessage(0));
                break;
            case C0415R.id.send_msg_tip /* 2131296763 */:
                m809a(this.f2007Z, 2);
                this.f2009aa.sendMessage(this.f2009aa.obtainMessage(0));
                break;
            case C0415R.id.send_msg_deny /* 2131296764 */:
                m809a(this.f2007Z, 1);
                this.f2009aa.sendMessage(this.f2009aa.obtainMessage(0));
                break;
            default:
                for (int i3 = 0; i3 < this.f1989H.length; i3++) {
                    if (v == this.f1983B[i3] || v == this.f2013e[i3]) {
                        String type = this.f1989H[i3];
                        this.f2007Z = i3;
                        if (type.equals(AppDatabase.DB_APP_SENDMESSAGE)) {
                            if (this.f1984C.isShown()) {
                                this.f1984C.setVisibility(8);
                            } else {
                                this.f1984C.setVisibility(0);
                            }
                        } else {
                            if (this.f1991J.get(i3).equals(DatabaseTables.SYSTEM_MARK)) {
                                this.f1991J.set(i3, "0");
                                Log.i("test", this.f2006Y + "on ok--" + type);
                            } else {
                                this.f1991J.set(i3, DatabaseTables.SYSTEM_MARK);
                                Log.i("test", this.f2006Y + "off ok--" + type);
                            }
                            if (this.f1984C.isShown()) {
                                this.f1984C.setVisibility(8);
                            }
                            this.f2009aa.sendMessage(this.f2009aa.obtainMessage(0));
                        }
                    }
                }
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private void m809a(int pos, int selected) {
        if (selected == 2) {
            this.f1991J.set(pos, DatabaseTables.USER_MARK);
            Log.i("test", this.f2006Y + "tip ok--" + AppDatabase.DB_APP_SENDMESSAGE);
        } else if (selected == 1) {
            this.f1991J.set(pos, DatabaseTables.SYSTEM_MARK);
            Log.i("test", this.f2006Y + "off ok--" + AppDatabase.DB_APP_SENDMESSAGE);
        } else if (selected == 0) {
            this.f1991J.set(pos, "0");
            Log.i("test", this.f2006Y + "on ok--" + AppDatabase.DB_APP_SENDMESSAGE);
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        for (int i = 0; i < this.f1989H.length; i++) {
            try {
                String type = this.f1989H[i];
                int select = Integer.valueOf(this.f1991J.get(i)).intValue();
                this.f2008a.updateApp(select, this.f2006Y, type);
            } catch (Exception e) {
            }
        }
        if (this.f2001T) {
            startService(new Intent(this, (Class<?>) SafeCenterService.class));
        }
        if (this.f1995N != null) {
            sendBroadcast(new Intent("com.lenovo.safecenter.refreshAppsManager"));
        }
        TrackEvent.trackPause(this);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.AppPermManager$a */
    private class C0225a extends BroadcastReceiver {
        private C0225a() {
        }

        /* synthetic */ C0225a(AppPermManager x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.PACKAGE_REMOVED")) {
                String packageName = intent.getDataString().substring(8);
                if (packageName.equals(AppPermManager.this.f1994M)) {
                    TrackEvent.reportUninstallApp(AppPermManager.this.f1994M);
                    AppPermManager.this.finish();
                }
            }
        }
    }
}
