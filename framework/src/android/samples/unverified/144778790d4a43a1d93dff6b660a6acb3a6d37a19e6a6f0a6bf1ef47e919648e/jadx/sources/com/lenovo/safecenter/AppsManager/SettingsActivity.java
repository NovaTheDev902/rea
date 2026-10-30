package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.Laboratory.SafeHomePage;
import com.lenovo.safecenter.MainTab.AppDownloadActivity;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.floatwindow.data.SaveData;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.Observable;
import java.util.Observer;

/* JADX INFO: loaded from: classes.dex */
public class SettingsActivity extends Activity implements View.OnClickListener, Observer {
    public static final int DIALOG_RETRIEVE_PASSWORD = 1;

    /* JADX INFO: renamed from: a */
    private TextView f2345a;

    /* JADX INFO: renamed from: b */
    private ImageView f2346b;

    /* JADX INFO: renamed from: c */
    private ImageView f2347c;

    /* JADX INFO: renamed from: d */
    private ImageView f2348d;

    /* JADX INFO: renamed from: e */
    private ImageView f2349e;

    /* JADX INFO: renamed from: f */
    private ImageView f2350f;

    /* JADX INFO: renamed from: g */
    private ImageView f2351g;

    /* JADX INFO: renamed from: h */
    private ImageView f2352h;

    /* JADX INFO: renamed from: i */
    private boolean f2353i;

    /* JADX INFO: renamed from: j */
    private boolean f2354j;

    /* JADX INFO: renamed from: k */
    private boolean f2355k;

    /* JADX INFO: renamed from: l */
    private C0296a f2356l;

    /* JADX INFO: renamed from: m */
    private ProgressDialog f2357m;

    /* JADX INFO: renamed from: n */
    private RelativeLayout f2358n;

    /* JADX INFO: renamed from: o */
    private Handler f2359o = new Handler() { // from class: com.lenovo.safecenter.AppsManager.SettingsActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    if (SettingsActivity.this.f2353i) {
                        SettingsActivity.this.f2347c.setImageResource(C0415R.drawable.btn_on);
                    } else {
                        SettingsActivity.this.f2347c.setImageResource(C0415R.drawable.btn_off);
                    }
                    break;
                case 1:
                    if (SettingsActivity.this.f2354j) {
                        SettingsActivity.this.f2348d.setImageResource(C0415R.drawable.btn_on);
                    } else {
                        SettingsActivity.this.f2348d.setImageResource(C0415R.drawable.btn_off);
                    }
                    break;
                case 2:
                    try {
                        if (SettingsActivity.this.f2357m != null) {
                            SettingsActivity.this.f2357m.dismiss();
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    SettingsActivity.this.f2355k = SettingsActivity.this.f2355k ? false : true;
                    Const.mDefaultPreference.edit().putBoolean(Const.SWITCH_INJECT_SWITCH, SettingsActivity.this.f2355k).commit();
                    if (SettingsActivity.this.f2355k) {
                        SettingsActivity.this.f2350f.setImageResource(C0415R.drawable.btn_on);
                    } else {
                        SettingsActivity.this.f2350f.setImageResource(C0415R.drawable.btn_off);
                    }
                    break;
                case 3:
                    InputMethodManager m = (InputMethodManager) SettingsActivity.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
                case 4:
                    Toast.makeText(SettingsActivity.this, (String) msg.obj, 1).show();
                    break;
                case 5:
                    if (Const.mDefaultPreference.getBoolean(SafeHomePage.SAFE_HOME_PAGE_KEY, false)) {
                        SettingsActivity.this.f2351g.setImageResource(C0415R.drawable.btn_off);
                        SafeHomePage.getDefault(SettingsActivity.this).unRegister();
                        TrackEvent.reportSafeHomePageSwitchChange(false);
                    } else {
                        SettingsActivity.this.f2351g.setImageResource(C0415R.drawable.btn_on);
                        SafeHomePage.getDefault(SettingsActivity.this).register();
                        TrackEvent.reportSafeHomePageSwitchChange(true);
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: p */
    private BroadcastReceiver f2360p = new BroadcastReceiver() { // from class: com.lenovo.safecenter.AppsManager.SettingsActivity.2
        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            String action = intent.getAction();
            if ("android.intent.action.PACKAGE_ADDED".equals(action) && Const.PACKAGENAME_LE_WIDGET4X1.equals(intent.getData().getSchemeSpecificPart())) {
                WflUtils.sendMessageToHandler(4, context.getString(C0415R.string.installed_wigdet4x1_decrip), SettingsActivity.this.f2359o);
                SettingsActivity.this.f2362r.setVisibility(8);
            }
        }
    };

    /* JADX INFO: renamed from: q */
    private LeSafeObservable f2361q;

    /* JADX INFO: renamed from: r */
    private ViewGroup f2362r;

    /* JADX INFO: renamed from: m */
    static /* synthetic */ ProgressDialog m999m(SettingsActivity x0) {
        x0.f2357m = null;
        return null;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.settings);
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("android.intent.action.PACKAGE_ADDED");
        intentFilter.addDataScheme("package");
        registerReceiver(this.f2360p, intentFilter);
        this.f2361q = LeSafeObservable.get(getApplicationContext());
        this.f2361q.addObserver(this);
        this.f2362r = (ViewGroup) findViewById(C0415R.id.widget4x1_parent);
        if (AppUtil.isAppExistence(this, Const.PACKAGENAME_LE_WIDGET4X1)) {
            this.f2362r.setVisibility(8);
        } else {
            this.f2362r.setVisibility(0);
        }
        if (Const.isShowTaost()) {
            findViewById(C0415R.id.tap_switch_lin).setVisibility(0);
        } else {
            findViewById(C0415R.id.tap_switch_lin).setVisibility(8);
        }
        this.f2345a = (TextView) findViewById(C0415R.id.txt_title);
        this.f2345a.setText(C0415R.string.set);
        this.f2346b = (ImageView) findViewById(C0415R.id.title_back);
        this.f2347c = (ImageView) findViewById(C0415R.id.anti_tap_switch);
        this.f2348d = (ImageView) findViewById(C0415R.id.switch_block);
        this.f2349e = (ImageView) findViewById(C0415R.id.flow_switch);
        this.f2358n = (RelativeLayout) findViewById(C0415R.id.flow_window_fixed_layout);
        this.f2352h = (ImageView) findViewById(C0415R.id.flow__fixed_switch);
        this.f2351g = (ImageView) findViewById(C0415R.id.home_page_btn);
        this.f2350f = (ImageView) findViewById(C0415R.id.inject_switch);
        ((ImageView) findViewById(C0415R.id.title_set)).setVisibility(4);
        this.f2353i = Const.mDefaultPreference.getBoolean(Const.SWITCH_ANTI_TAPPING, true);
        this.f2354j = Const.mDefaultPreference.getBoolean(Const.SWITCH_BLOCK_NOTIFY, true);
        this.f2355k = Const.mDefaultPreference.getBoolean(Const.SWITCH_INJECT_SWITCH, true);
        if (this.f2355k) {
            this.f2350f.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f2350f.setImageResource(C0415R.drawable.btn_off);
        }
        if (this.f2353i) {
            this.f2347c.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f2347c.setImageResource(C0415R.drawable.btn_off);
        }
        if (this.f2354j) {
            this.f2348d.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f2348d.setImageResource(C0415R.drawable.btn_off);
        }
        if (Const.mDefaultPreference.getBoolean(SafeHomePage.SAFE_HOME_PAGE_KEY, false)) {
            this.f2351g.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f2351g.setImageResource(C0415R.drawable.btn_off);
        }
        this.f2362r.setOnClickListener(this);
        this.f2346b.setOnClickListener(this);
        this.f2350f.setOnClickListener(this);
        this.f2347c.setOnClickListener(this);
        this.f2348d.setOnClickListener(this);
        this.f2349e.setOnClickListener(this);
        this.f2352h.setOnClickListener(this);
        this.f2351g.setOnClickListener(this);
        ((RelativeLayout) findViewById(C0415R.id.shortcut_add_parent)).setOnClickListener(this);
        RelativeLayout relativeLayout = (RelativeLayout) findViewById(C0415R.id.modify_password_layout);
        RelativeLayout relativeLayout2 = (RelativeLayout) findViewById(C0415R.id.retrieve_password_layout);
        relativeLayout.setOnClickListener(this);
        relativeLayout2.setOnClickListener(this);
        if (SaveData.get_flow_status(this)) {
            this.f2349e.setImageResource(C0415R.drawable.btn_on);
            this.f2358n.setVisibility(0);
        } else {
            this.f2349e.setImageResource(C0415R.drawable.btn_off);
            this.f2358n.setVisibility(8);
        }
        if (SaveData.get_flow_immove_state(this)) {
            this.f2352h.setImageResource(C0415R.drawable.btn_on);
            if (SecurityService.instance != null) {
                SecurityService.instance.setFlowIsFixed(true);
            }
        } else {
            this.f2352h.setImageResource(C0415R.drawable.btn_off);
            if (SecurityService.instance != null) {
                SecurityService.instance.setFlowIsFixed(false);
            }
        }
        TrafficStatsService.nacServerIsExist();
        m985a();
        if (this.f2356l == null) {
            this.f2356l = new C0296a(this, b);
        }
        IntentFilter intentFilter2 = new IntentFilter();
        intentFilter2.addAction("com.lenovo.safecenter.flowrefresh");
        registerReceiver(this.f2356l, intentFilter2);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        DialogUtil.dismissShowPwdDialog();
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        boolean flowFlag = SaveData.get_flow_status(this);
        if (flowFlag) {
            this.f2349e.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f2349e.setImageResource(C0415R.drawable.btn_off);
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        unregisterReceiver(this.f2360p);
        unregisterReceiver(this.f2356l);
        super.onDestroy();
    }

    /* JADX INFO: renamed from: a */
    private void m985a() {
        TextView textView = (TextView) findViewById(C0415R.id.tv_modify_password);
        if (PwdUtil.hasPassword(this)) {
            textView.setText(C0415R.string.modify_password);
        } else {
            textView.setText(C0415R.string.setting_password_text);
        }
        RelativeLayout relativeLayout = (RelativeLayout) findViewById(C0415R.id.retrieve_password_layout);
        TextView textView2 = (TextView) findViewById(C0415R.id.tv_retrieve_password);
        if (!TextUtils.isEmpty(PwdUtil.queryPwdQuestionAndAnswer(this)[0])) {
            relativeLayout.setVisibility(0);
            relativeLayout.setClickable(true);
            textView2.setTextColor(getResources().getColor(C0415R.color.black2));
            return;
        }
        relativeLayout.setVisibility(8);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) throws Throwable {
        switch (v.getId()) {
            case C0415R.id.modify_password_layout /* 2131297584 */:
                if (PwdUtil.hasPassword(this)) {
                    this.f2359o.sendEmptyMessageDelayed(3, 500L);
                    DialogUtil.showPwdDialog(Const.ACTION_MODIFY_PASSWORD_USE_PRE_PASSWORD, this);
                } else {
                    WflUtils.startSettingPasswordActivity(this, Const.ACTION_JUMP_SETTING_PASSWORD);
                }
                break;
            case C0415R.id.retrieve_password_layout /* 2131297586 */:
                this.f2359o.sendEmptyMessageDelayed(3, 500L);
                String[] questions = PwdUtil.queryPwdQuestionAndAnswer(this);
                DialogUtil.showPasswordQuestionDialog(this, 1, questions[0], questions[1]);
                break;
            case C0415R.id.inject_switch /* 2131297588 */:
                this.f2357m = new ProgressDialog(this);
                this.f2357m.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.AppsManager.SettingsActivity.3
                    @Override // android.content.DialogInterface.OnDismissListener
                    public final void onDismiss(DialogInterface dialog) {
                        SettingsActivity.m999m(SettingsActivity.this);
                    }
                });
                this.f2357m.setProgressStyle(0);
                this.f2357m.setMessage(getString(C0415R.string.exec_state));
                this.f2357m.show();
                if (this.f2355k) {
                    CMDHelper.guestModeClient(SafeCenterService.SYSTEM_SERVICE, 0, 0, 0);
                    CMDHelper.guestModeClient(SafeCenterService.PHONE_SERVICE, 0, 0, 0);
                    CMDHelper.guestModeClient(SafeCenterService.ACORE_SERVICE, 0, 0, 0);
                } else {
                    CMDHelper.guestModeClient(SafeCenterService.SYSTEM_SERVICE, 0, 1, 0);
                    CMDHelper.guestModeClient(SafeCenterService.PHONE_SERVICE, 0, 1, 0);
                    CMDHelper.guestModeClient(SafeCenterService.ACORE_SERVICE, 0, 1, 0);
                }
                this.f2359o.sendMessageDelayed(this.f2359o.obtainMessage(2), 2000L);
                break;
            case C0415R.id.anti_tap_switch /* 2131297591 */:
                this.f2353i = this.f2353i ? false : true;
                Const.mDefaultPreference.edit().putBoolean(Const.SWITCH_ANTI_TAPPING, this.f2353i).commit();
                this.f2359o.sendMessage(this.f2359o.obtainMessage(0));
                break;
            case C0415R.id.switch_block /* 2131297592 */:
                this.f2354j = this.f2354j ? false : true;
                Const.mDefaultPreference.edit().putBoolean(Const.SWITCH_BLOCK_NOTIFY, this.f2354j).commit();
                this.f2359o.sendMessage(this.f2359o.obtainMessage(1));
                break;
            case C0415R.id.home_page_btn /* 2131297595 */:
                this.f2359o.sendMessage(this.f2359o.obtainMessage(5));
                break;
            case C0415R.id.flow_switch /* 2131297597 */:
                boolean flowFlag = SaveData.get_flow_status(this);
                if (flowFlag) {
                    this.f2349e.setImageResource(C0415R.drawable.btn_off);
                    if (SecurityService.instance != null) {
                        SecurityService.instance.setFlowVisibility(8);
                    }
                    SaveData.save_flow_status(this, false);
                    this.f2358n.setVisibility(8);
                    TrackEvent.reportTrafficFloatwindowSwitchChanged(false);
                } else {
                    this.f2349e.setImageResource(C0415R.drawable.btn_on);
                    if (SecurityService.instance != null) {
                        SecurityService.instance.setFlowVisibility(0);
                    }
                    SaveData.save_flow_status(this, true);
                    this.f2358n.setVisibility(0);
                    TrackEvent.reportTrafficFloatwindowSwitchChanged(true);
                }
                break;
            case C0415R.id.flow__fixed_switch /* 2131297601 */:
                boolean flowFixedFlag = SaveData.get_flow_immove_state(this);
                if (flowFixedFlag) {
                    this.f2352h.setImageResource(C0415R.drawable.btn_off);
                    if (SecurityService.instance != null) {
                        SecurityService.instance.setFlowIsFixed(false);
                    }
                    SaveData.save_flow_immove_state(this, false);
                } else {
                    this.f2352h.setImageResource(C0415R.drawable.btn_on);
                    if (SecurityService.instance != null) {
                        SecurityService.instance.setFlowIsFixed(true);
                    }
                    SaveData.save_flow_immove_state(this, true);
                }
                break;
            case C0415R.id.shortcut_add_parent /* 2131297604 */:
                Utils.createShortCut(this, C0415R.drawable.onkey_shutcut_green, C0415R.string.one_key_widget_clean, true);
                break;
            case C0415R.id.widget4x1_parent /* 2131297606 */:
                AppDownloadActivity.copyAssetsFilesInstall(AppDownloadActivity.WIDGET4X1_FILE_NAME, Const.PACKAGENAME_LE_WIDGET4X1, this, this.f2359o, 4);
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    @Override // java.util.Observer
    public void update(Observable observable, Object data) {
        if (data instanceof Integer) {
            switch (((Integer) data).intValue()) {
                case 10:
                    m985a();
                    break;
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.AppsManager.SettingsActivity$a */
    private class C0296a extends BroadcastReceiver {
        private C0296a() {
        }

        /* synthetic */ C0296a(SettingsActivity x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            boolean flowFlag = SaveData.get_flow_status(SettingsActivity.this);
            if (flowFlag) {
                SettingsActivity.this.f2349e.setImageResource(C0415R.drawable.btn_on);
                SettingsActivity.this.f2358n.setVisibility(0);
            } else {
                SettingsActivity.this.f2349e.setImageResource(C0415R.drawable.btn_off);
                SettingsActivity.this.f2358n.setVisibility(8);
            }
        }
    }
}
