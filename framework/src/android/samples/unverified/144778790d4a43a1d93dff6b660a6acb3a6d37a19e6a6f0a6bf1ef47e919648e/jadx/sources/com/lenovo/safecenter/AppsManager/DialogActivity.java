package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.Laboratory.ForbiddenApplication;
import com.lenovo.safecenter.Laboratory.GuestModeSet;
import com.lenovo.safecenter.MainTab.FirstUsePasswordSettingActivity;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.test.SafeCenter;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;

/* JADX INFO: loaded from: classes.dex */
public class DialogActivity extends Activity implements View.OnClickListener {
    public static final int OPERATE_FAILED = 2;
    public static final int OPERATE_SUCCESS = 1;

    /* JADX INFO: renamed from: a */
    private Context f2197a;

    /* JADX INFO: renamed from: b */
    private AppDatabase f2198b;

    /* JADX INFO: renamed from: c */
    private SharedPreferences f2199c;

    /* JADX INFO: renamed from: d */
    private String f2200d;

    /* JADX INFO: renamed from: e */
    private int f2201e;

    /* JADX INFO: renamed from: f */
    private TextView f2202f;

    /* JADX INFO: renamed from: g */
    private TextView f2203g;

    /* JADX INFO: renamed from: h */
    private TextView f2204h;

    /* JADX INFO: renamed from: i */
    private TextView f2205i;

    /* JADX INFO: renamed from: j */
    private TextView f2206j;

    /* JADX INFO: renamed from: k */
    private EditText f2207k;

    /* JADX INFO: renamed from: l */
    private ProgressBar f2208l;

    /* JADX INFO: renamed from: m */
    private boolean f2209m;

    /* JADX INFO: renamed from: n */
    private boolean f2210n;

    /* JADX INFO: renamed from: o */
    private Handler f2211o = new Handler() { // from class: com.lenovo.safecenter.AppsManager.DialogActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    InputMethodManager m = (InputMethodManager) DialogActivity.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
                case 1:
                    LeSafeObservable.get(DialogActivity.this.f2197a).noticeChangeGuestModeSuccess();
                    if (DialogActivity.this.f2208l != null) {
                        DialogActivity.this.f2208l.setVisibility(4);
                    }
                    if (Settings.System.getInt(DialogActivity.this.getContentResolver(), "guest_mode_on", 0) == 1) {
                        Toast.makeText(DialogActivity.this.f2197a, C0415R.string.hide_contacts2, 0).show();
                    }
                    DialogActivity.this.finish();
                    break;
                case 2:
                    LeSafeObservable.get(DialogActivity.this.f2197a).noticeChangeChildModeFail();
                    if (DialogActivity.this.f2208l != null) {
                        DialogActivity.this.f2208l.setVisibility(4);
                    }
                    DialogActivity.this.f2203g.setEnabled(true);
                    DialogActivity.this.f2204h.setEnabled(true);
                    DialogActivity.this.f2207k.setEnabled(true);
                    Toast.makeText(DialogActivity.this.f2197a, C0415R.string.info_failed, 1).show();
                    break;
                case 5:
                    if (DialogActivity.this.f2208l != null) {
                        DialogActivity.this.f2208l.setVisibility(4);
                    }
                    Toast.makeText(DialogActivity.this.f2197a, DialogActivity.this.getString(C0415R.string.closed) + DialogActivity.this.getString(C0415R.string.guest_mode), 0).show();
                    DialogActivity.this.finish();
                    break;
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        this.f2197a = this;
        Intent it = getIntent();
        if (it != null) {
            this.f2201e = it.getIntExtra("style", 0);
        }
        this.f2198b = new AppDatabase(this);
        this.f2199c = PreferenceManager.getDefaultSharedPreferences(this);
        this.f2200d = PwdUtil.getPassword(this);
        this.f2198b.close();
        if (this.f2200d == null || this.f2200d.length() == 0) {
            setContentView(C0415R.layout.dialog_info);
        } else {
            setContentView(C0415R.layout.input_password);
            this.f2211o.sendEmptyMessageDelayed(0, 500L);
        }
        ((LinearLayout) findViewById(C0415R.id.input_password_layout)).setBackgroundResource(C0415R.drawable.dialog_center);
        if (this.f2200d != null && this.f2200d.length() != 0) {
            ((RelativeLayout) findViewById(C0415R.id.input_title_layout)).setVisibility(0);
            ((LinearLayout) findViewById(C0415R.id.input_password_layout)).setBackgroundResource(C0415R.drawable.dialog_center);
            this.f2202f = (TextView) findViewById(C0415R.id.txt_message);
            this.f2202f.setText(C0415R.string.input_privacy_pwd);
            this.f2208l = (ProgressBar) findViewById(C0415R.id.input_noti_progress);
            this.f2207k = (EditText) findViewById(C0415R.id.edt_input_pwd);
            this.f2207k.setEnabled(true);
            this.f2203g = (TextView) findViewById(C0415R.id.input_pwd_ok);
            this.f2203g.setVisibility(0);
            this.f2203g.setOnClickListener(this);
            this.f2204h = (TextView) findViewById(C0415R.id.input_pwd_cancel);
            this.f2204h.setVisibility(0);
            this.f2204h.setOnClickListener(this);
            return;
        }
        this.f2206j = (TextView) findViewById(C0415R.id.dialog_ok);
        this.f2205i = (TextView) findViewById(C0415R.id.dialog_cancel);
        this.f2206j.setOnClickListener(this);
        this.f2205i.setOnClickListener(this);
    }

    @Override // android.app.Activity
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        this.f2201e = intent.getIntExtra("style", 0);
    }

    /* JADX WARN: Type inference failed for: r3v30, types: [com.lenovo.safecenter.AppsManager.DialogActivity$3] */
    /* JADX WARN: Type inference failed for: r3v39, types: [com.lenovo.safecenter.AppsManager.DialogActivity$2] */
    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.dialog_cancel /* 2131296943 */:
            case C0415R.id.input_pwd_cancel /* 2131297106 */:
                finish();
                break;
            case C0415R.id.dialog_ok /* 2131296944 */:
                startActivity(new Intent(this, (Class<?>) FirstUsePasswordSettingActivity.class));
                finish();
                break;
            case C0415R.id.input_pwd_ok /* 2131297107 */:
                String pwd = this.f2207k.getText().toString();
                if (PwdUtil.checkPassword(getApplicationContext(), pwd)) {
                    InputMethodManager m = (InputMethodManager) getSystemService("input_method");
                    if (m.isActive()) {
                        m.toggleSoftInput(0, 2);
                    }
                    this.f2209m = Settings.System.getInt(getApplicationContext().getContentResolver(), "child_mode_on", 0) == 1;
                    this.f2210n = Settings.System.getInt(getApplicationContext().getContentResolver(), "guest_mode_on", 0) == 1;
                    switch (this.f2201e) {
                        case 0:
                            if (this.f2209m) {
                                startActivity(new Intent(this, (Class<?>) ForbiddenApplication.class));
                                finish();
                            } else if (this.f2210n) {
                                startActivity(new Intent(this, (Class<?>) GuestModeSet.class));
                                finish();
                            }
                            break;
                        case 1:
                            if (this.f2210n) {
                                m924a(false, true);
                            } else if (AppUtil.isAppExistence(this.f2197a, Const.PACKAGENAME_KID_MODE)) {
                                WflUtils.startKidMode(this.f2197a);
                                finish();
                            } else {
                                if (this.f2208l != null) {
                                    this.f2208l.setVisibility(0);
                                }
                                this.f2203g.setEnabled(false);
                                this.f2204h.setEnabled(false);
                                this.f2207k.setEnabled(false);
                                new Thread() { // from class: com.lenovo.safecenter.AppsManager.DialogActivity.2
                                    @Override // java.lang.Thread, java.lang.Runnable
                                    public final void run() {
                                        if (SafeCenter.openChildMode(DialogActivity.this.f2197a, DialogActivity.this.f2198b)) {
                                            if (DialogActivity.this.f2199c.getBoolean("plan_mode_preference", true)) {
                                                try {
                                                    Thread.sleep(4000L);
                                                } catch (InterruptedException e) {
                                                    e.printStackTrace();
                                                }
                                            }
                                            DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(1));
                                            return;
                                        }
                                        DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(2));
                                    }
                                }.start();
                            }
                            break;
                        case 2:
                            if (this.f2208l != null) {
                                this.f2208l.setVisibility(0);
                            }
                            this.f2203g.setEnabled(false);
                            this.f2204h.setEnabled(false);
                            this.f2207k.setEnabled(false);
                            new Thread() { // from class: com.lenovo.safecenter.AppsManager.DialogActivity.3
                                @Override // java.lang.Thread, java.lang.Runnable
                                public final void run() {
                                    if (SafeCenter.closeChildMode(DialogActivity.this.f2197a, DialogActivity.this.f2198b)) {
                                        if (DialogActivity.this.f2199c.getBoolean("plan_mode_preference", true)) {
                                            try {
                                                Thread.sleep(4000L);
                                            } catch (InterruptedException e) {
                                                e.printStackTrace();
                                            }
                                        }
                                        DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(1));
                                        return;
                                    }
                                    DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(2));
                                }
                            }.start();
                            break;
                        case 4:
                            m924a(true, false);
                            break;
                        case 5:
                            m924a(false, false);
                            break;
                        case 10:
                            startActivity(new Intent(this, (Class<?>) ForbiddenApplication.class));
                            finish();
                            break;
                        case 11:
                            startActivity(new Intent(this, (Class<?>) GuestModeSet.class));
                            finish();
                            break;
                    }
                } else {
                    if (pwd.length() == 0) {
                        this.f2202f.setText(C0415R.string.error_tips_null);
                        Animation shake = AnimationUtils.loadAnimation(this, C0415R.anim.shake);
                        this.f2207k.startAnimation(shake);
                    } else {
                        Animation shake2 = AnimationUtils.loadAnimation(this, C0415R.anim.shake);
                        this.f2207k.startAnimation(shake2);
                        this.f2207k.setText("");
                        this.f2202f.setText(C0415R.string.pwd_error_tips);
                    }
                    break;
                }
                break;
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    public void showRebootDialog(final boolean enableGuestMode, final boolean enableChildMode) {
        boolean child_mode_on = Settings.System.getInt(getContentResolver(), "child_mode_on", 0) == 1;
        CustomDialog.Builder builder = new CustomDialog.Builder(this);
        builder.setTitle(C0415R.string.info);
        if (enableChildMode) {
            builder.setMessage(C0415R.string.reboot_info);
        } else if (enableGuestMode) {
            if (child_mode_on) {
                builder.setMessage(getString(C0415R.string.open) + getString(C0415R.string.guest_mode) + getString(C0415R.string.hide_sms_info3) + getString(C0415R.string.hide_sms_info) + getString(C0415R.string.hide_sms_info1));
            } else {
                builder.setMessage(getString(C0415R.string.open) + getString(C0415R.string.guest_mode) + getString(C0415R.string.hide_sms_info) + getString(C0415R.string.hide_sms_info1));
            }
        } else {
            builder.setMessage(getString(C0415R.string.close) + getString(C0415R.string.guest_mode) + getString(C0415R.string.hide_sms_info) + getString(C0415R.string.hide_sms_info2));
        }
        builder.setPositiveButton(C0415R.string.yes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.DialogActivity.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                DialogActivity.this.m924a(enableGuestMode, enableChildMode);
            }
        });
        builder.setNegativeButton(C0415R.string.no, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.AppsManager.DialogActivity.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                DialogActivity.this.finish();
            }
        });
        builder.setOnCancelListener(new DialogInterface.OnCancelListener() { // from class: com.lenovo.safecenter.AppsManager.DialogActivity.6
            @Override // android.content.DialogInterface.OnCancelListener
            public final void onCancel(DialogInterface dialog) {
                DialogActivity.this.finish();
            }
        });
        builder.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX WARN: Type inference failed for: r1v4, types: [com.lenovo.safecenter.AppsManager.DialogActivity$7] */
    /* JADX INFO: renamed from: a */
    public void m924a(final boolean enableGuestMode, final boolean enableChildMode) {
        final ContentResolver resolver = getContentResolver();
        if (this.f2208l != null) {
            this.f2208l.setVisibility(0);
        }
        this.f2203g.setEnabled(false);
        this.f2204h.setEnabled(false);
        this.f2207k.setEnabled(false);
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.DialogActivity.7
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                if (enableChildMode) {
                    if (AppUtil.isAppExistence(DialogActivity.this.f2197a, Const.PACKAGENAME_KID_MODE)) {
                        if (SafeCenter.closeGuestMode(DialogActivity.this.f2197a, false, DialogActivity.this.f2198b)) {
                            DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(5));
                        }
                        WflUtils.startKidMode(DialogActivity.this.f2197a);
                        return;
                    } else {
                        if (SafeCenter.closeGuestMode(DialogActivity.this.f2197a, enableChildMode, DialogActivity.this.f2198b)) {
                            DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(5));
                            return;
                        }
                        if (!DialogActivity.this.f2209m) {
                            Settings.System.putInt(resolver, "child_mode_on", 0);
                        }
                        Settings.System.putInt(resolver, "guest_mode_on", 1);
                        DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(2));
                        return;
                    }
                }
                if (enableGuestMode) {
                    if (SafeCenter.openGuestMode(DialogActivity.this.f2197a, DialogActivity.this.f2209m, DialogActivity.this.f2198b)) {
                        DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(1));
                        return;
                    }
                    if (DialogActivity.this.f2209m) {
                        Settings.System.putInt(resolver, "child_mode_on", 1);
                    }
                    Settings.System.putInt(resolver, "guest_mode_on", 0);
                    DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(2));
                    return;
                }
                if (SafeCenter.closeGuestMode(DialogActivity.this.f2197a, DialogActivity.this.f2209m, DialogActivity.this.f2198b)) {
                    DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(5));
                } else {
                    Settings.System.putInt(resolver, "guest_mode_on", 1);
                    DialogActivity.this.f2211o.sendMessage(DialogActivity.this.f2211o.obtainMessage(2));
                }
            }
        }.start();
    }
}
