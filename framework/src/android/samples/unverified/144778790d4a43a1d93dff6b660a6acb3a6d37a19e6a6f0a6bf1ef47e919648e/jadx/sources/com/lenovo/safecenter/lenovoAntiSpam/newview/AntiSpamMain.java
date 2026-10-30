package com.lenovo.safecenter.lenovoAntiSpam.newview;

import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.text.style.StyleSpan;
import android.util.Log;
import android.view.GestureDetector;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.Button;
import android.widget.ExpandableListView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.MainTab.LeSafeMainActivity;
import com.lenovo.safecenter.antivirus.utils.ScanUtils;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.utils.CheckCenter;
import com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.SafeCenter;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class AntiSpamMain extends BaseTitleActivity {

    /* JADX INFO: renamed from: b */
    private TextView f3828b;

    /* JADX INFO: renamed from: c */
    private TextView f3829c;

    /* JADX INFO: renamed from: d */
    private TextView f3830d;

    /* JADX INFO: renamed from: e */
    private TextView f3831e;

    /* JADX INFO: renamed from: f */
    private TextView f3832f;

    /* JADX INFO: renamed from: g */
    private ExpandableListView f3833g;

    /* JADX INFO: renamed from: h */
    private LinearLayout f3834h;

    /* JADX INFO: renamed from: i */
    private LinearLayout f3835i;

    /* JADX INFO: renamed from: j */
    private ImageView f3836j;

    /* JADX INFO: renamed from: k */
    private ImageView f3837k;

    /* JADX INFO: renamed from: l */
    private List<SafeLog> f3838l;

    /* JADX INFO: renamed from: m */
    private AppDatabase f3839m;

    /* JADX INFO: renamed from: n */
    private PopupWindow f3840n;

    /* JADX INFO: renamed from: o */
    private C0612a f3841o;

    /* JADX INFO: renamed from: p */
    private ProgressDialog f3842p;

    /* JADX INFO: renamed from: r */
    private C0614c f3844r;

    /* JADX INFO: renamed from: s */
    private RelativeLayout f3845s;

    /* JADX INFO: renamed from: u */
    private GestureDetector f3847u;

    /* JADX INFO: renamed from: v */
    private View.OnTouchListener f3848v;

    /* JADX INFO: renamed from: w */
    private View f3849w;

    /* JADX INFO: renamed from: x */
    private Button f3850x;

    /* JADX INFO: renamed from: q */
    private int f3843q = 0;

    /* JADX INFO: renamed from: t */
    private int f3846t = -1;

    /* JADX INFO: renamed from: a */
    Handler f3827a = new Handler() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            try {
                if (AntiSpamMain.this.f3842p != null) {
                    AntiSpamMain.this.f3842p.dismiss();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            switch (msg.what) {
                case 2:
                    AntiSpamMain.this.showReport_success();
                    AntiSpamMain.this.f3841o.notifyDataSetChanged();
                    break;
                case 3:
                    if (ScanUtils.isNetworkAvailable(AntiSpamMain.this)) {
                        Toast.makeText(AntiSpamMain.this, C0415R.string.neterror, 0).show();
                    } else {
                        AntiSpamMain.this.showReport_fail();
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1603a(AntiSpamMain x0, String x1) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(x1).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.9
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                AntiSpamMain.m1611h(AntiSpamMain.this);
                Toast.makeText(AntiSpamMain.this, C0415R.string.del_sucess, 0).show();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: e */
    static /* synthetic */ PopupWindow m1608e(AntiSpamMain x0) {
        x0.f3840n = null;
        return null;
    }

    /* JADX INFO: renamed from: h */
    static /* synthetic */ void m1611h(AntiSpamMain x0) {
        x0.f3839m.deleteLogForTable(AppDatabase.DB_LOG_HARASS, x0.f3843q + "");
        x0.f3838l.clear();
        x0.changeBtn();
        x0.f3841o.notifyDataSetChanged();
        x0.updateStatus();
    }

    /* JADX INFO: renamed from: k */
    static /* synthetic */ void m1614k(AntiSpamMain x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(C0415R.string.del_info).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                AntiSpamMain.this.deleteLog();
                Toast.makeText(AntiSpamMain.this, C0415R.string.del_sucess, 0).show();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.22
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: l */
    static /* synthetic */ void m1615l(AntiSpamMain x0) {
        String str = x0.f3838l.get(x0.f3846t).number;
        ContentValues contentValues = new ContentValues();
        contentValues.put("address", x0.f3838l.get(x0.f3846t).number);
        contentValues.put("date", x0.f3838l.get(x0.f3846t).time);
        contentValues.put(PushReceiver.READ, (Integer) 1);
        contentValues.put("status", (Integer) (-1));
        contentValues.put("type", (Integer) 1);
        contentValues.put(PushReceiver.BODY, x0.f3838l.get(x0.f3846t).content);
        x0.getContentResolver().insert(Uri.parse("content://sms"), contentValues);
        x0.f3839m.deleteHarassLog(x0.f3838l.get(x0.f3846t).f5496id);
        x0.f3838l.remove(x0.f3846t);
        x0.changeBtn();
        x0.f3841o.notifyDataSetChanged();
        x0.updateStatus();
        if (x0.f3846t < x0.f3838l.size()) {
            x0.f3833g.collapseGroup(x0.f3846t);
        }
        if (x0.isStarnge(str)) {
            CheckCenter.insertWhitePerson(x0, str);
            Toast.makeText(x0, C0415R.string.h_del4, 0).show();
        } else if (isLocalBlack(x0, str)) {
            x0.showDelLocalBlack(str);
        }
    }

    public void showReport_success() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.notify).setMessage(C0415R.string.report_success).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.12
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        }).show();
    }

    public void showReport_fail() {
        new CustomDialog.Builder(this).setTitle(C0415R.string.notify).setMessage(C0415R.string.report_fail).setPositiveButton(C0415R.string.set_net_text, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.19
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ComponentName component = new ComponentName("com.android.settings", "com.android.settings.Settings");
                Intent intent = new Intent();
                intent.setComponent(component);
                AntiSpamMain.this.startActivity(intent);
                dialog.cancel();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.18
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        }).show();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain$c */
    class C0614c extends BroadcastReceiver {
        C0614c() {
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            Log.i("onReceive", intent.getAction());
            if (intent.getAction().equals("com.lenovo.antispam.notify")) {
                Log.i("onReceive", intent.getAction());
                if (AntiSpamMain.this.f3843q != 0) {
                    if (AntiSpamMain.this.f3843q == 1) {
                        AntiSpamMain.this.initData(1);
                    }
                } else {
                    AntiSpamMain.this.initData(0);
                }
                AntiSpamMain.this.updateStatus();
                AntiSpamMain.this.setHarassSet();
                return;
            }
            if (intent.getAction().equals("com.lenovo.antispam.clearlogs")) {
                AntiSpamMain.this.f3838l.clear();
                AntiSpamMain.this.updateStatus();
            }
        }
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("com.lenovo.antispam.notify");
        filter.addAction("com.lenovo.antispam.clearlogs");
        registerReceiver(this.f3844r, filter);
    }

    public void updateStatus() {
        if (CheckCenter.getHarassCount(this, DatabaseTables.SYSTEM_MARK) > 0) {
            this.f3831e.setText(getString(C0415R.string.harass_call) + String.format(getString(C0415R.string.harss_countshow), Integer.valueOf(CheckCenter.getHarassCount(this, DatabaseTables.SYSTEM_MARK))));
            if (this.f3843q == 1) {
                this.f3839m.updatehasSee(DatabaseTables.SYSTEM_MARK);
                SafeCenterService.harass_call_count = 0;
                Const.saveHarassLogsCount(this);
                MyUtils.showLeSecNotification(this);
            }
        } else {
            this.f3831e.setText(C0415R.string.harass_call);
        }
        if (CheckCenter.getHarassCount(this, "0") > 0) {
            this.f3830d.setText(getString(C0415R.string.harass_sms) + String.format(getString(C0415R.string.harss_countshow), Integer.valueOf(CheckCenter.getHarassCount(this, "0"))));
            if (this.f3843q == 0) {
                this.f3839m.updatehasSee("0");
                SafeCenterService.harass_msg_count = 0;
                Const.saveHarassLogsCount(this);
                MyUtils.showLeSecNotification(this);
                return;
            }
            return;
        }
        this.f3830d.setText(C0415R.string.harass_sms);
    }

    public void showpopupWindow() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.harass_poplistview, (ViewGroup) null);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_harass_set)).setOnClickListener(this);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_black)).setOnClickListener(this);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_white)).setOnClickListener(this);
        ((LinearLayout) view.findViewById(C0415R.id.popwindow_night)).setOnClickListener(this);
        this.f3840n = new PopupWindow(view, -2, -2, true);
        this.f3840n.setAnimationStyle(C0415R.style.PopupAnimation);
        this.f3840n.setBackgroundDrawable(new BitmapDrawable());
        this.f3840n.setFocusable(true);
        this.f3840n.setOutsideTouchable(true);
        this.f3840n.showAsDropDown(findViewById(C0415R.id.base_titlebar), Const.getScreenWidth(), 0);
        this.f3840n.update();
        this.f3840n.setOnDismissListener(new PopupWindow.OnDismissListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.20
            @Override // android.widget.PopupWindow.OnDismissListener
            public final void onDismiss() {
                AntiSpamMain.m1608e(AntiSpamMain.this);
            }
        });
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.antispam_main);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispamapp_name, Integer.valueOf(C0415R.drawable.rf_perf_title_right));
        findViews();
        this.f3844r = new C0614c();
        this.f3839m = new AppDatabase(this);
        setOnclick();
        try {
            this.f3843q = getIntent().getIntExtra("type", 0);
        } catch (Exception e) {
        }
        this.f3847u = new GestureDetector(new C0613b());
        this.f3848v = new View.OnTouchListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.21
            @Override // android.view.View.OnTouchListener
            public final boolean onTouch(View v, MotionEvent event) {
                return AntiSpamMain.this.f3847u.onTouchEvent(event);
            }
        };
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        try {
            unregisterReceiver(this.f3844r);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            try {
                if (getIntent().getStringExtra("key") != null) {
                    startActivity(new Intent(this, (Class<?>) LeSafeMainActivity.class));
                    finish();
                } else {
                    finish();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        registerAction();
        initData(this.f3843q);
        updateStatus();
        setHarassSet();
        TrackEvent.trackResume(this);
    }

    public int getHarassType(int type) {
        if (type == 1) {
            if (Const.getHarassCount(this, 1) == 0) {
                SharedPreferences mDefaultPreference = PreferenceManager.getDefaultSharedPreferences(this);
                SharedPreferences.Editor editor = mDefaultPreference.edit();
                editor.putInt("total_harass_call", this.f3839m.getHarassLogCount(DatabaseTables.SYSTEM_MARK)).commit();
            }
            return Const.getHarassCount(this, 1);
        }
        if (type != 0) {
            return 0;
        }
        if (Const.getHarassCount(this, 0) == 0) {
            SharedPreferences mDefaultPreference2 = PreferenceManager.getDefaultSharedPreferences(this);
            SharedPreferences.Editor editor2 = mDefaultPreference2.edit();
            editor2.putInt("total_harass_sms", this.f3839m.getHarassLogCount("0")).commit();
        }
        return Const.getHarassCount(this, 0);
    }

    public void initData(int type) {
        if (type == 0) {
            this.f3838l = this.f3839m.loadHarassLog("0");
            this.f3841o = new C0612a(this);
            this.f3835i.setBackgroundResource(C0415R.drawable.tab_select);
            this.f3834h.setBackgroundResource(C0415R.drawable.tab_normal);
            this.f3836j.setImageResource(C0415R.drawable.antispam_smsclick);
            this.f3837k.setImageResource(C0415R.drawable.antispam_callnormal);
            this.f3830d.setTextColor(getResources().getColor(C0415R.color.blue));
            this.f3831e.setTextColor(getResources().getColor(C0415R.color.black4));
            this.f3832f.setText(C0415R.string.no_harass_sms);
            this.f3850x.setText(C0415R.string.menu_del);
        } else if (type == 1) {
            this.f3838l = this.f3839m.loadHarassLog(DatabaseTables.SYSTEM_MARK);
            this.f3841o = new C0612a(this);
            this.f3830d.setTextColor(getResources().getColor(C0415R.color.black4));
            this.f3831e.setTextColor(getResources().getColor(C0415R.color.blue));
            this.f3834h.setBackgroundResource(C0415R.drawable.tab_select);
            this.f3835i.setBackgroundResource(C0415R.drawable.tab_normal);
            this.f3837k.setImageResource(C0415R.drawable.antispam_callclick);
            this.f3836j.setImageResource(C0415R.drawable.antispam_smsnormal);
            this.f3832f.setText(C0415R.string.no_harass_call);
            this.f3850x.setText(C0415R.string.menu_recover);
        }
        changeBtn();
        this.f3833g.setAdapter(this.f3841o);
    }

    public void changeBtn() {
        try {
            if (this.f3838l.size() > 0) {
                if (this.f3838l.size() < 2) {
                    if (this.f3833g.getFooterViewsCount() == 1) {
                        this.f3833g.removeFooterView(this.f3849w);
                    }
                } else if (this.f3833g.getFooterViewsCount() == 0) {
                    this.f3833g.addFooterView(this.f3849w);
                }
            }
        } catch (Exception e) {
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            try {
                if (getIntent().getStringExtra("key") != null) {
                    startActivity(new Intent(this, (Class<?>) LeSafeMainActivity.class));
                    finish();
                } else {
                    finish();
                }
                return;
            } catch (Exception e) {
                e.printStackTrace();
                return;
            }
        }
        if (v.getId() == C0415R.id.base_title_right) {
            startActivity(new Intent(this, (Class<?>) HarassSet.class));
            return;
        }
        if (v.getId() == C0415R.id.popwindow_harass_set) {
            startActivity(new Intent(this, (Class<?>) HarassSet.class));
            return;
        }
        if (v.getId() == C0415R.id.popwindow_black) {
            Intent intent = new Intent(this, (Class<?>) WhiteABlackMain.class);
            intent.putExtra("type", 1);
            startActivity(intent);
        } else if (v.getId() == C0415R.id.popwindow_white) {
            startActivity(new Intent(this, (Class<?>) SignActivity.class));
        } else if (v.getId() == C0415R.id.popwindow_night) {
            startActivity(new Intent(this, (Class<?>) NightPreActivity.class));
        }
    }

    public static String formatNumber(String number) {
        if (number != null && number.contains("-")) {
            number = number.replace("-", "");
        }
        if (number != null && number.startsWith("+86")) {
            return number.substring(3);
        }
        return number;
    }

    public boolean isStarnge(String number) {
        String number2 = formatNumber(number);
        return (SecurityService.secutityPerson.contains(number2) || SafeCenter.getAllLocalBlack(this).contains(number2) || SafeCenter.getAllNetBlack(this).contains(number2) || SecurityService.whitePerson.contains(number2)) ? false : true;
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
    }

    public void setOnclick() {
        this.f3833g.setOnGroupExpandListener(new ExpandableListView.OnGroupExpandListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.3
            @Override // android.widget.ExpandableListView.OnGroupExpandListener
            public final void onGroupExpand(int groupPosition) {
                AntiSpamMain.this.f3846t = groupPosition;
                if (groupPosition == AntiSpamMain.this.f3838l.size() - 1) {
                    AntiSpamMain.this.f3833g.setTranscriptMode(2);
                } else {
                    AntiSpamMain.this.f3833g.setTranscriptMode(1);
                }
                for (int i = 0; i < AntiSpamMain.this.f3841o.getGroupCount(); i++) {
                    if (groupPosition != i) {
                        AntiSpamMain.this.f3833g.collapseGroup(i);
                    }
                }
            }
        });
        this.f3834h.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AntiSpamMain.this.f3843q = 1;
                AntiSpamMain.this.initData(1);
                AntiSpamMain.this.updateStatus();
            }
        });
        this.f3835i.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AntiSpamMain.this.f3843q = 0;
                AntiSpamMain.this.initData(0);
                AntiSpamMain.this.updateStatus();
            }
        });
        this.f3845s.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AntiSpamMain.this.startActivity(new Intent(AntiSpamMain.this, (Class<?>) SignActivity.class));
            }
        });
    }

    public void findViews() {
        this.f3828b = (TextView) findViewById(C0415R.id.antispam_harssdesc);
        this.f3829c = (TextView) findViewById(C0415R.id.antispam_harssdesc1);
        this.f3830d = (TextView) findViewById(C0415R.id.antispam_sms);
        this.f3831e = (TextView) findViewById(C0415R.id.antispam_call);
        this.f3832f = (TextView) findViewById(C0415R.id.antispam_empty);
        this.f3833g = (ExpandableListView) findViewById(C0415R.id.antispam_logs);
        this.f3834h = (LinearLayout) findViewById(C0415R.id.antispam_calllin);
        this.f3835i = (LinearLayout) findViewById(C0415R.id.antispam_smslin);
        this.f3836j = (ImageView) findViewById(C0415R.id.antispam_smsicon);
        this.f3837k = (ImageView) findViewById(C0415R.id.antispam_callicon);
        this.f3845s = (RelativeLayout) findViewById(C0415R.id.antispam_mainlin3);
        this.f3833g.setEmptyView(this.f3832f);
        this.f3833g.setDivider(getResources().getDrawable(C0415R.drawable.space_line));
        this.f3833g.setGroupIndicator(null);
        this.f3849w = LayoutInflater.from(this).inflate(C0415R.layout.harsslog_del, (ViewGroup) null);
        if (Const.SDK_VERSION >= 14) {
            this.f3833g.addFooterView(this.f3849w);
        }
        this.f3850x = (Button) this.f3849w.findViewById(C0415R.id.harss_dellog);
        this.f3850x.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (AntiSpamMain.this.f3838l.size() > 0) {
                    if (AntiSpamMain.this.f3843q != 0) {
                        if (AntiSpamMain.this.f3843q == 1) {
                            AntiSpamMain.m1603a(AntiSpamMain.this, AntiSpamMain.this.getString(C0415R.string.del_harsscall));
                            return;
                        }
                        return;
                    }
                    AntiSpamMain.m1603a(AntiSpamMain.this, AntiSpamMain.this.getString(C0415R.string.del_harsssms));
                }
            }
        });
    }

    public void deleteLog() {
        this.f3839m.deleteHarassLog(this.f3838l.get(this.f3846t).f5496id);
        this.f3838l.remove(this.f3846t);
        changeBtn();
        this.f3841o.notifyDataSetChanged();
        updateStatus();
        if (this.f3846t < this.f3838l.size()) {
            this.f3833g.collapseGroup(this.f3846t);
        }
    }

    public void showReportDialog() {
        if (this.f3843q == 0) {
            new CustomDialog.Builder(this).setTitle(C0415R.string.notify).setMessage(C0415R.string.report_tonet).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.11
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    AntiSpamMain.this.report();
                }
            }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.10
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                }
            }).show();
        } else if (this.f3843q == 1) {
            new CustomDialog.Builder(this).setTitle(C0415R.string.notify).setMessage(C0415R.string.report_tonet1).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.14
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    AntiSpamMain.this.report();
                }
            }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.13
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                }
            }).show();
        }
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain$15] */
    public void report() {
        this.f3842p = new ProgressDialog(this);
        this.f3842p.setProgressStyle(0);
        this.f3842p.setMessage(getString(C0415R.string.exec_state));
        this.f3842p.setCanceledOnTouchOutside(false);
        this.f3842p.show();
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.15
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    if (AntiSpamMain.this.reportHarssLog() == 2) {
                        ((SafeLog) AntiSpamMain.this.f3838l.get(AntiSpamMain.this.f3846t)).isUpload = 1;
                        AntiSpamMain.this.f3839m.updateSafeLogUpload((SafeLog) AntiSpamMain.this.f3838l.get(AntiSpamMain.this.f3846t), AppDatabase.DB_LOG_HARASS);
                        Message msg = new Message();
                        msg.what = 2;
                        AntiSpamMain.this.f3827a.sendMessage(msg);
                    } else {
                        Message msg2 = new Message();
                        msg2.what = 3;
                        AntiSpamMain.this.f3827a.sendMessage(msg2);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public int reportHarssLog() {
        if (this.f3846t == -1) {
            return 1;
        }
        if (this.f3843q == 0) {
            return HttpUtils.reportHarssLog(this, MyUtils.replaceString(this.f3838l.get(this.f3846t).number), "0", MyUtils.replaceString(this.f3838l.get(this.f3846t).content));
        }
        if (this.f3843q == 1) {
            return HttpUtils.reportHarssLog(this, MyUtils.replaceString(this.f3838l.get(this.f3846t).number), DatabaseTables.SYSTEM_MARK, MyUtils.replaceString(this.f3838l.get(this.f3846t).content));
        }
        return 1;
    }

    public String getStr_fromtype(int fromtype) {
        Log.i("msg", "fromtype===" + fromtype);
        if (fromtype == 3) {
            if (this.f3843q == 0) {
                return getString(C0415R.string.cause1);
            }
            return getString(C0415R.string.cause2);
        }
        if (fromtype == 2) {
            if (this.f3843q == 0) {
                return getString(C0415R.string.cause1);
            }
            return getString(C0415R.string.cause6);
        }
        if (fromtype == 5) {
            return getString(C0415R.string.cause7);
        }
        if (fromtype == 6) {
            return getString(C0415R.string.cause1);
        }
        if (fromtype == 7) {
            return getString(C0415R.string.cause3);
        }
        if (fromtype == 8) {
            return getString(C0415R.string.cause4);
        }
        if (fromtype == 9) {
            return getString(C0415R.string.cause5);
        }
        return getString(C0415R.string.cause1);
    }

    public SpannableString changgeword(int fromtype) {
        String text = String.format(getString(C0415R.string.causeprex), getStr_fromtype(fromtype));
        SpannableString spannable = new SpannableString(text);
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.colorcause)), text.length() - getStr_fromtype(fromtype).length(), text.length(), 33);
        spannable.setSpan(new StyleSpan(1), 0, text.length() - getStr_fromtype(fromtype).length(), 33);
        return spannable;
    }

    public void callTo() {
        Intent callIntent = new Intent("android.intent.action.CALL", Uri.parse("tel:" + this.f3838l.get(this.f3846t).number));
        startActivity(callIntent);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain$a */
    class C0612a extends BaseExpandableListAdapter {

        /* JADX INFO: renamed from: a */
        Context f3874a;

        /* JADX INFO: renamed from: b */
        b f3875b;

        /* JADX INFO: renamed from: c */
        a f3876c;

        /* JADX INFO: renamed from: e */
        private LayoutInflater f3878e;

        public C0612a(Context context) {
            this.f3878e = LayoutInflater.from(context);
            this.f3874a = context;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getChild(int groupPosition, int childPosition) {
            return null;
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getChildId(int groupPosition, int childPosition) {
            return childPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getChildrenCount(int groupPosition) {
            return 1;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
            if (AntiSpamMain.this.f3843q != 0) {
                if (AntiSpamMain.this.f3843q == 1) {
                    if (convertView == null) {
                        convertView = this.f3878e.inflate(C0415R.layout.dealitemequal, (ViewGroup) null);
                        this.f3876c = new a();
                        this.f3876c.f3882a = (TextView) convertView.findViewById(C0415R.id.deal1);
                        this.f3876c.f3883b = (TextView) convertView.findViewById(C0415R.id.deal2);
                        this.f3876c.f3884c = (TextView) convertView.findViewById(C0415R.id.deal3);
                        convertView.setTag(this.f3876c);
                    } else {
                        this.f3876c = (a) convertView.getTag();
                    }
                }
            } else if (convertView == null) {
                convertView = this.f3878e.inflate(C0415R.layout.dealitem, (ViewGroup) null);
                this.f3876c = new a();
                this.f3876c.f3882a = (TextView) convertView.findViewById(C0415R.id.deal1);
                this.f3876c.f3883b = (TextView) convertView.findViewById(C0415R.id.deal2);
                this.f3876c.f3884c = (TextView) convertView.findViewById(C0415R.id.deal3);
                this.f3876c.f3886e = (LinearLayout) convertView.findViewById(C0415R.id.causelin);
                this.f3876c.f3885d = (TextView) convertView.findViewById(C0415R.id.showcause);
                convertView.setTag(this.f3876c);
            } else {
                this.f3876c = (a) convertView.getTag();
            }
            if (AntiSpamMain.this.f3843q == 0) {
                this.f3876c.f3886e.setVisibility(0);
                this.f3876c.f3885d.setText(AntiSpamMain.this.changgeword(((SafeLog) AntiSpamMain.this.f3838l.get(groupPosition)).fromtype));
            }
            if (((SafeLog) AntiSpamMain.this.f3838l.get(groupPosition)).isUpload == 1) {
                this.f3876c.f3884c.setText(C0415R.string.hadupload_log);
            } else {
                this.f3876c.f3884c.setText(C0415R.string.antispamlocalblack_upload);
            }
            if (AntiSpamMain.this.f3843q != 0) {
                if (AntiSpamMain.this.f3843q == 1) {
                    this.f3876c.f3883b.setText(C0415R.string.safemode_callto);
                }
            } else {
                this.f3876c.f3883b.setText(C0415R.string.recovery_sms);
            }
            this.f3876c.f3882a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.a.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    AntiSpamMain.m1614k(AntiSpamMain.this);
                }
            });
            this.f3876c.f3883b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.a.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (AntiSpamMain.this.f3843q != 0) {
                        if (AntiSpamMain.this.f3843q == 1) {
                            AntiSpamMain.this.callTo();
                            return;
                        }
                        return;
                    }
                    AntiSpamMain.m1615l(AntiSpamMain.this);
                }
            });
            this.f3876c.f3884c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.a.3
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (((SafeLog) AntiSpamMain.this.f3838l.get(AntiSpamMain.this.f3846t)).isUpload != 1) {
                        AntiSpamMain.this.showReportDialog();
                    } else {
                        Toast.makeText(AntiSpamMain.this, C0415R.string.havedup, 0).show();
                    }
                }
            });
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final Object getGroup(int groupPosition) {
            return AntiSpamMain.this.f3838l.get(groupPosition);
        }

        @Override // android.widget.ExpandableListAdapter
        public final int getGroupCount() {
            return AntiSpamMain.this.f3838l.size();
        }

        @Override // android.widget.ExpandableListAdapter
        public final long getGroupId(int groupPosition) {
            return groupPosition;
        }

        @Override // android.widget.ExpandableListAdapter
        public final View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
            if (convertView == null) {
                convertView = this.f3878e.inflate(C0415R.layout.antispammain_parent, (ViewGroup) null);
                this.f3875b = new b();
                this.f3875b.f3888a = (ImageView) convertView.findViewById(C0415R.id.antispamsmscheck);
                this.f3875b.f3889b = (TextView) convertView.findViewById(C0415R.id.antispamsmsname);
                this.f3875b.f3890c = (TextView) convertView.findViewById(C0415R.id.antispamsmsnumber);
                this.f3875b.f3891d = (TextView) convertView.findViewById(C0415R.id.antispamsmscontent);
                this.f3875b.f3892e = (TextView) convertView.findViewById(C0415R.id.antispamsmscontent1);
                convertView.setTag(this.f3875b);
            } else {
                this.f3875b = (b) convertView.getTag();
            }
            SafeLog log = (SafeLog) AntiSpamMain.this.f3838l.get(groupPosition);
            this.f3875b.f3889b.setText(log.number);
            this.f3875b.f3890c.setText(AppDatabase.formatTime(log.time, AntiSpamMain.this));
            if (AntiSpamMain.this.f3843q != 0) {
                if (AntiSpamMain.this.f3843q == 1) {
                    this.f3875b.f3891d.setText(AntiSpamMain.this.changgeword(log.fromtype));
                }
            } else if (!isExpanded) {
                this.f3875b.f3891d.setText(log.content);
                this.f3875b.f3892e.setVisibility(8);
                this.f3875b.f3891d.setVisibility(0);
            } else {
                this.f3875b.f3892e.setText(log.content);
                this.f3875b.f3891d.setVisibility(8);
                this.f3875b.f3892e.setVisibility(0);
            }
            if (log.isUpload == 1) {
                this.f3875b.f3888a.setVisibility(0);
                this.f3875b.f3888a.setImageResource(C0415R.drawable.upload);
            } else {
                this.f3875b.f3888a.setVisibility(8);
            }
            return convertView;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean hasStableIds() {
            return false;
        }

        @Override // android.widget.ExpandableListAdapter
        public final boolean isChildSelectable(int groupPosition, int childPosition) {
            return false;
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain$a$b */
        class b {

            /* JADX INFO: renamed from: a */
            ImageView f3888a;

            /* JADX INFO: renamed from: b */
            TextView f3889b;

            /* JADX INFO: renamed from: c */
            TextView f3890c;

            /* JADX INFO: renamed from: d */
            TextView f3891d;

            /* JADX INFO: renamed from: e */
            TextView f3892e;

            b() {
            }
        }

        /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain$a$a */
        class a {

            /* JADX INFO: renamed from: a */
            TextView f3882a;

            /* JADX INFO: renamed from: b */
            TextView f3883b;

            /* JADX INFO: renamed from: c */
            TextView f3884c;

            /* JADX INFO: renamed from: d */
            TextView f3885d;

            /* JADX INFO: renamed from: e */
            LinearLayout f3886e;

            a() {
            }
        }
    }

    public void setHarassSet() {
        if (Settings.System.getInt(getContentResolver(), "intercall_mode_type", 0) == 0) {
            this.f3828b.setVisibility(8);
            this.f3829c.setVisibility(0);
        } else {
            this.f3828b.setVisibility(0);
            this.f3829c.setVisibility(8);
            this.f3828b.setText(String.format(getString(C0415R.string.harss_totalshow), Integer.valueOf(getHarassType(0)), Integer.valueOf(getHarassType(1))));
        }
    }

    public static boolean delLocalBlack(Context context, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            int i = resolver.delete(uri, " PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0)", null);
            return i > 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

    public static boolean isLocalBlack(Context context, String number) {
        try {
            ContentResolver resolver = context.getContentResolver();
            Uri uri = Uri.parse("content://com.lenovo.safecenter.LocalBlackProvider/localblack");
            Cursor cursor = resolver.query(uri, null, "PHONE_NUMBERS_EQUAL(phonenumber,'" + number + "',0)", null, null);
            int count = cursor.getCount();
            cursor.close();
            return count > 0;
        } catch (Exception e) {
            return false;
        }
    }

    public void showDelLocalBlack(final String phoneNumber) {
        new CustomDialog.Builder(this).setTitle(C0415R.string.notify).setMessage(String.format(getString(C0415R.string.h_del2), phoneNumber)).setPositiveButton(C0415R.string.h_del5, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.17
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                AntiSpamMain.delLocalBlack(AntiSpamMain.this, phoneNumber);
                Toast.makeText(AntiSpamMain.this, C0415R.string.h_del3, 0).show();
            }
        }).setNegativeButton(C0415R.string.h_del6, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain.16
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain$b */
    class C0613b extends GestureDetector.SimpleOnGestureListener {
        C0613b() {
        }

        @Override // android.view.GestureDetector.SimpleOnGestureListener, android.view.GestureDetector.OnGestureListener
        public final boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
            try {
                if (Math.abs(e1.getY() - e2.getY()) <= 250.0f) {
                    if (e1.getX() - e2.getX() <= 120.0f || Math.abs(velocityX) <= 200.0f || AntiSpamMain.this.f3843q == 1) {
                        if (e2.getX() - e1.getX() > 120.0f && Math.abs(velocityX) > 200.0f && AntiSpamMain.this.f3843q != 0) {
                            Log.i("test ", "left");
                            AntiSpamMain.this.f3843q = 0;
                            AntiSpamMain.this.initData(0);
                            AntiSpamMain.this.updateStatus();
                        }
                    } else {
                        Log.i("test ", "right");
                        AntiSpamMain.this.f3843q = 1;
                        AntiSpamMain.this.initData(1);
                        AntiSpamMain.this.updateStatus();
                    }
                }
            } catch (Exception e) {
            }
            return false;
        }
    }

    @Override // android.app.Activity, android.view.Window.Callback
    public boolean dispatchTouchEvent(MotionEvent event) {
        if (this.f3847u.onTouchEvent(event)) {
            event.setAction(3);
        }
        return super.dispatchTouchEvent(event);
    }
}
