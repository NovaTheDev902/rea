package com.lenovo.safecenter.lenovoAntiSpam;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.Preference;
import android.preference.PreferenceCategory;
import android.preference.PreferenceScreen;
import android.provider.Settings;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.utils.CheckCenter;
import com.lenovo.safecenter.lenovoAntiSpam.utils.HttpUtils;
import com.lenovo.safecenter.lenovoAntiSpam.utils.SafeCenter;
import com.lenovo.safecenter.lenovoAntiSpam.utils.SmsCheckUtils;
import com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalBlackActivity;
import com.lenovo.safecenter.lenovoAntiSpam.views.ManLocalWhiteActivity;
import com.lenovo.safecenter.lenovoAntiSpam.views.NightPreActivity;
import com.lenovo.safecenter.platform.BaseTitlePreferenceActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class MainActivity extends BaseTitlePreferenceActivity {

    /* JADX INFO: renamed from: a */
    private C0582b f3754a;

    /* JADX INFO: renamed from: b */
    private C0582b f3755b;

    /* JADX INFO: renamed from: c */
    private C0582b f3756c;

    /* JADX INFO: renamed from: d */
    private C0582b f3757d;

    /* JADX INFO: renamed from: e */
    private C0582b f3758e;

    /* JADX INFO: renamed from: f */
    private C0585e f3759f;

    /* JADX INFO: renamed from: g */
    private C0583c f3760g;

    /* JADX INFO: renamed from: h */
    private C0584d f3761h;

    /* JADX INFO: renamed from: i */
    private Handler f3762i = new HandlerC0581a(this, 0);

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.MainActivity$d */
    class C0584d extends BroadcastReceiver {
        C0584d() {
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            Log.i("onReceive", intent.getAction());
            if (intent.getAction().equals("com.lenovo.antispam.notify")) {
                Log.i("onReceive", intent.getAction());
                MainActivity.this.f3762i.sendEmptyMessage(1);
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.MainActivity$a */
    private class HandlerC0581a extends Handler {
        private HandlerC0581a() {
        }

        /* synthetic */ HandlerC0581a(MainActivity x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    MainActivity.this.updateStatus();
                    break;
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        } else if (v.getId() == C0415R.id.base_title_right) {
            startActivity(new Intent(this, (Class<?>) NightPreActivity.class));
        }
    }

    public void registerAction() {
        IntentFilter filter = new IntentFilter();
        filter.addAction("com.lenovo.antispam.notify");
        registerReceiver(this.f3761h, filter);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) throws Throwable {
        super.onCreate(savedInstanceState);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.antispamapp_name, Integer.valueOf(C0415R.drawable.rf_perf_title_right));
        PreferenceScreen preferenceScreenCreatePreferenceScreen = getPreferenceManager().createPreferenceScreen(this);
        this.f3759f = new C0585e(this);
        this.f3759f.setKey("harss_preference");
        this.f3760g = new C0583c(this);
        this.f3760g.setKey("ss");
        this.f3760g.setSelectable(false);
        preferenceScreenCreatePreferenceScreen.addPreference(this.f3760g);
        PreferenceCategory preferenceCategory = new PreferenceCategory(this);
        preferenceCategory.setTitle(getString(C0415R.string.safe_log));
        preferenceScreenCreatePreferenceScreen.addPreference(preferenceCategory);
        this.f3754a = new C0582b(this);
        this.f3754a.setKey("callsafelog");
        this.f3754a.m1597a(getString(C0415R.string.antispammanlogdesc));
        this.f3754a.m1596a(C0415R.drawable.antispamlog);
        Intent intent = new Intent();
        intent.setAction("com.lenovo.safecenter.view.DisplayLogTab");
        intent.putExtra("logType", "callharass");
        this.f3754a.setIntent(intent);
        preferenceCategory.addPreference(this.f3754a);
        PreferenceCategory preferenceCategory2 = new PreferenceCategory(this);
        preferenceCategory2.setTitle(C0415R.string.antispammancallcategory);
        preferenceScreenCreatePreferenceScreen.addPreference(preferenceCategory2);
        this.f3756c = new C0582b(this);
        this.f3756c.setKey("backcallpreference");
        this.f3756c.m1597a(getString(C0415R.string.antispammancallblack));
        this.f3756c.m1598b(-7829368);
        this.f3756c.m1599b(getString(C0415R.string.antispammanblackcalldesc));
        this.f3756c.m1596a(C0415R.drawable.antispamblack);
        Intent intent2 = new Intent(this, (Class<?>) ManLocalBlackActivity.class);
        intent2.putExtra("type", 1);
        this.f3756c.setIntent(intent2);
        preferenceCategory2.addPreference(this.f3756c);
        this.f3757d = new C0582b(this);
        this.f3757d.setKey("whitepreference");
        this.f3757d.m1597a(getString(C0415R.string.antispammanwhite));
        this.f3757d.m1598b(-7829368);
        this.f3757d.m1599b(getString(C0415R.string.antispammanwhitedesc));
        this.f3757d.m1596a(C0415R.drawable.antispamwhite);
        this.f3757d.setIntent(new Intent(this, (Class<?>) ManLocalWhiteActivity.class));
        preferenceCategory2.addPreference(this.f3757d);
        this.f3758e = new C0582b(this);
        this.f3758e.setKey("backsmspreference");
        this.f3758e.m1597a(getString(C0415R.string.antispammansmsblack));
        this.f3758e.m1598b(-7829368);
        this.f3758e.m1599b(getString(C0415R.string.antispammanblacksmsdesc));
        this.f3758e.m1596a(C0415R.drawable.antispammansmsblack);
        Intent intent3 = new Intent(this, (Class<?>) ManLocalBlackActivity.class);
        intent3.putExtra("type", 0);
        this.f3758e.setIntent(intent3);
        new PreferenceCategory(this).setTitle(C0415R.string.antispamsetting);
        this.f3755b = new C0582b(this);
        this.f3755b.setKey("setpre");
        this.f3755b.m1597a(getString(C0415R.string.antispamsetting));
        this.f3755b.m1598b(-7829368);
        this.f3755b.m1599b(getString(C0415R.string.antispamsettingdesc));
        this.f3755b.m1596a(C0415R.drawable.antispamsetting);
        this.f3755b.setIntent(new Intent(this, (Class<?>) NightPreActivity.class));
        setPreferenceScreen(preferenceScreenCreatePreferenceScreen);
        this.f3761h = new C0584d();
        registerAction();
        SharedPreferences preferences = getSharedPreferences("isFirst", 0);
        boolean flag = preferences.getBoolean("flag11", true);
        if (flag) {
            SafeCenter.setPathUrl(this);
            SmsCheckUtils.init(this);
            HttpUtils utils = new HttpUtils();
            utils.UpdateConfig("systime", "2011.02.13", this);
            SharedPreferences.Editor editor = preferences.edit();
            editor.putBoolean("flag11", false);
            editor.commit();
            new AppDatabase(this).initWhiteSMS();
        }
    }

    public boolean getHarssStatus() {
        SharedPreferences preferences = getSharedPreferences("HarssStatus", 1);
        return preferences.getBoolean("status", true);
    }

    public void updateHarssStatus(boolean bool) {
        SharedPreferences preferences = getSharedPreferences("HarssStatus", 1);
        SharedPreferences.Editor editor = preferences.edit();
        editor.putBoolean("status", bool);
        editor.commit();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.ListActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f3761h);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        updateStatus();
        if (Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 1) {
            this.f3756c.setEnabled(false);
            this.f3757d.setEnabled(false);
            this.f3758e.setEnabled(false);
        } else {
            this.f3756c.setEnabled(true);
            this.f3757d.setEnabled(true);
            this.f3758e.setEnabled(true);
        }
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    public void updateStatus() {
        String smsstr = getString(C0415R.string.antispamsafelogdesc) + CheckCenter.getHarassCount(this, "0") + getString(C0415R.string.antispamsafelogdesc2);
        String str = getString(C0415R.string.antispamsafelogdesc1) + CheckCenter.getHarassCount(this, DatabaseTables.SYSTEM_MARK) + getString(C0415R.string.antispamsafelogdesc2);
        if (Settings.System.getInt(getContentResolver(), "guest_mode_on", 0) == 1) {
            smsstr = getString(C0415R.string.antispamsafelogdesc) + "0" + getString(C0415R.string.antispamsafelogdesc2);
            str = getString(C0415R.string.antispamsafelogdesc1) + "0" + getString(C0415R.string.antispamsafelogdesc2);
        }
        Log.i("onResume", "onResume==end" + str);
        if (CheckCenter.getHarassCount(this, "0") > 0 || CheckCenter.getHarassCount(this, DatabaseTables.SYSTEM_MARK) > 0) {
            this.f3754a.m1598b(Color.parseColor("#29b1ef"));
        } else {
            this.f3754a.m1598b(-7829368);
        }
        this.f3754a.m1599b(str + "," + smsstr);
        this.f3754a.notifyChanged();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.MainActivity$e */
    private class C0585e extends Preference {

        /* JADX INFO: renamed from: b */
        private Context f3775b;

        public C0585e(Context context) {
            super(context);
            this.f3775b = context;
        }

        @Override // android.preference.Preference
        protected final View onCreateView(ViewGroup parent) {
            super.onCreateView(parent);
            View view = LayoutInflater.from(this.f3775b).inflate(C0415R.layout.title, (ViewGroup) null);
            TextView name = (TextView) view.findViewById(C0415R.id.txt_title);
            name.setText(C0415R.string.antispamapp_name);
            return view;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.MainActivity$c */
    private class C0583c extends Preference {

        /* JADX INFO: renamed from: b */
        private Context f3770b;

        /* JADX INFO: renamed from: a */
        static /* synthetic */ void m1600a(C0583c x0) {
            new CustomDialog.Builder(MainActivity.this).setTitle(C0415R.string.info).setMessage(C0415R.string.disable_antispam_tip).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.MainActivity.c.2
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    Const.setProtectHarassSwitchState(false);
                    MainActivity.this.f3760g.notifyChanged();
                    LeSafeObservable.get(MainActivity.this).noticeRefreshProtectHarassDetail();
                }
            }).setNegativeButton(C0415R.string.cancel, (DialogInterface.OnClickListener) null).show();
        }

        public C0583c(Context context) {
            super(context);
            this.f3770b = context;
        }

        @Override // android.preference.Preference
        protected final void notifyChanged() {
            super.notifyChanged();
        }

        @Override // android.preference.Preference
        protected final View onCreateView(ViewGroup parent) {
            super.onCreateView(parent);
            View view = LayoutInflater.from(this.f3770b).inflate(C0415R.layout.antispamswitch, (ViewGroup) null);
            ImageView cc = (ImageView) view.findViewById(C0415R.id.antispam_checkbox);
            TextView txt = (TextView) view.findViewById(C0415R.id.antispam_checkboxtxt);
            cc.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.MainActivity.c.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v) {
                    if (Const.getProtectHarassSwitchState()) {
                        C0583c.m1600a(C0583c.this);
                        return;
                    }
                    Const.setProtectHarassSwitchState(true);
                    MainActivity.this.f3760g.notifyChanged();
                    LeSafeObservable.get(MainActivity.this).noticeRefreshProtectHarassDetail();
                }
            });
            if (Const.getProtectHarassSwitchState()) {
                cc.setImageResource(C0415R.drawable.btn_on);
                txt.setText(C0415R.string.opend);
            } else {
                txt.setTextColor(-65536);
                txt.setText(C0415R.string.closed);
                cc.setImageResource(C0415R.drawable.btn_off);
            }
            return view;
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.MainActivity$b */
    private class C0582b extends Preference {

        /* JADX INFO: renamed from: a */
        String f3764a;

        /* JADX INFO: renamed from: b */
        String f3765b;

        /* JADX INFO: renamed from: c */
        int f3766c;

        /* JADX INFO: renamed from: d */
        int f3767d;

        public C0582b(Context context) {
            super(context);
        }

        @Override // android.preference.Preference
        protected final View onCreateView(ViewGroup parent) {
            super.onCreateView(parent);
            View view = MainActivity.this.getLayoutInflater().inflate(C0415R.layout.main_item, (ViewGroup) null);
            ImageView icon = (ImageView) view.findViewById(C0415R.id.icon_before);
            TextView name = (TextView) view.findViewById(C0415R.id.tt1);
            TextView discription = (TextView) view.findViewById(C0415R.id.tt3);
            name.setText(this.f3764a);
            discription.setTextColor(this.f3767d);
            discription.setText(this.f3765b);
            icon.setBackgroundResource(this.f3766c);
            return view;
        }

        /* JADX INFO: renamed from: a */
        public final void m1597a(String title) {
            this.f3764a = title;
        }

        /* JADX INFO: renamed from: b */
        public final void m1599b(String message) {
            this.f3765b = message;
        }

        /* JADX INFO: renamed from: a */
        public final void m1596a(int iconId) {
            this.f3766c = iconId;
        }

        @Override // android.preference.Preference
        protected final void notifyChanged() {
            super.notifyChanged();
        }

        /* JADX INFO: renamed from: b */
        public final void m1598b(int color) {
            this.f3767d = color;
        }
    }
}
