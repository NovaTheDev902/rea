package com.lenovo.safecenter.safemode;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.Preference;
import android.preference.PreferenceCategory;
import android.preference.PreferenceManager;
import android.preference.PreferenceScreen;
import android.provider.Settings;
import android.text.SpannableString;
import android.text.TextUtils;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.platform.BaseTitlePreferenceActivity;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public class ContractSetting extends BaseTitlePreferenceActivity {

    /* JADX INFO: renamed from: a */
    Preference f5031a;

    /* JADX INFO: renamed from: b */
    Preference f5032b;

    /* JADX INFO: renamed from: c */
    Preference f5033c;

    /* JADX INFO: renamed from: d */
    Preference f5034d;

    /* JADX INFO: renamed from: e */
    Preference f5035e;

    /* JADX INFO: renamed from: f */
    Preference f5036f;

    /* JADX INFO: renamed from: g */
    Preference f5037g;

    /* JADX INFO: renamed from: h */
    SharedPreferences f5038h;

    /* JADX INFO: renamed from: i */
    SharedPreferences f5039i;

    /* JADX INFO: renamed from: m */
    private int f5043m;

    /* JADX INFO: renamed from: n */
    private int f5044n;

    /* JADX INFO: renamed from: o */
    private List<Map<String, Object>> f5045o;

    /* JADX INFO: renamed from: s */
    private C0889a f5049s;

    /* JADX INFO: renamed from: j */
    private int f5040j = 0;

    /* JADX INFO: renamed from: k */
    private int f5041k = 0;

    /* JADX INFO: renamed from: l */
    private int f5042l = 0;

    /* JADX INFO: renamed from: p */
    private int[] f5046p = {C0415R.string.no_notify, C0415R.string.callnotify, C0415R.string.notify1, C0415R.string.notify2};

    /* JADX INFO: renamed from: q */
    private int[] f5047q = {C0415R.string.call_notify1, C0415R.string.call_notify2, C0415R.string.call_notify3};

    /* JADX INFO: renamed from: r */
    private Handler f5048r = new Handler() { // from class: com.lenovo.safecenter.safemode.ContractSetting.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            int i = msg.what;
        }
    };

    /* JADX INFO: renamed from: e */
    static /* synthetic */ void m2093e(ContractSetting x0) {
        View viewInflate = LayoutInflater.from(x0).inflate(C0415R.layout.replaymes, (ViewGroup) null);
        ((LinearLayout) viewInflate.findViewById(C0415R.id.input_bottom_layout)).setVisibility(8);
        ((TextView) viewInflate.findViewById(C0415R.id.txt_message)).setText(C0415R.string.con_setting_size);
        final EditText editText = (EditText) viewInflate.findViewById(C0415R.id.edt_input_pwd);
        editText.setText(x0.f5038h.getString("replypri_content", x0.getString(C0415R.string.no_replaysms)));
        editText.setInputType(144);
        new CustomDialog.Builder(x0).setTitle(C0415R.string.replymes_dialogtitle).setContentView(viewInflate).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.19
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (!TextUtils.isEmpty(editText.getText().toString().trim())) {
                    if (editText.getText().toString().trim().length() > 50) {
                        Toast.makeText(ContractSetting.this, C0415R.string.msg_long_error, 0).show();
                        return;
                    } else {
                        ContractSetting.this.f5038h.edit().putString("replypri_content", editText.getText().toString()).commit();
                        dialog.dismiss();
                        return;
                    }
                }
                Toast.makeText(ContractSetting.this, C0415R.string.setting_pwdfail, 0).show();
            }
        }, false).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.12
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
        x0.f5048r.sendEmptyMessageDelayed(1, 1000L);
    }

    /* JADX INFO: renamed from: f */
    static /* synthetic */ void m2094f(ContractSetting x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.smsnotifymode_title).setSingleChoiceItems(C0415R.array.sms_mode, Integer.parseInt(x0.f5038h.getString("sms_mode", DatabaseTables.SYSTEM_MARK)), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.23
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ContractSetting.this.f5044n = which;
            }
        }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.22
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ContractSetting.this.f5035e.setSummary(ContractSetting.this.getSpan(ContractSetting.this.getString(ContractSetting.this.f5046p[ContractSetting.this.f5044n]), C0415R.color.gray2));
                ContractSetting.this.f5038h.edit().putString("sms_mode", String.valueOf(ContractSetting.this.f5044n)).commit();
                if (ContractSetting.this.f5044n == 0) {
                    ContractSetting.this.f5031a.setEnabled(false);
                } else {
                    ContractSetting.this.f5031a.setEnabled(true);
                }
            }
        }).show();
    }

    /* JADX INFO: renamed from: g */
    static /* synthetic */ void m2095g(ContractSetting x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.callnotifymode_title).setSingleChoiceItems(C0415R.array.call_mode, Settings.System.getInt(x0.getContentResolver(), "privateCall_mode_on", 0), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.21
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ContractSetting.this.f5043m = which;
            }
        }).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.20
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                ContractSetting.this.f5034d.setSummary(ContractSetting.this.getSpan(ContractSetting.this.getString(ContractSetting.this.f5047q[ContractSetting.this.f5043m]), C0415R.color.gray2));
                Settings.System.putInt(ContractSetting.this.getContentResolver(), "privateCall_mode_on", ContractSetting.this.f5043m);
                if (ContractSetting.this.f5043m != 0) {
                    if (ContractSetting.this.f5043m != 1) {
                        if (ContractSetting.this.f5043m == 2) {
                            ContractSetting.this.f5036f.setEnabled(true);
                            ContractSetting.this.f5032b.setEnabled(true);
                            ContractSetting.this.f5036f.setTitle(ContractSetting.this.getSpan(ContractSetting.this.getString(C0415R.string.replymes_title), C0415R.color.black2));
                            return;
                        }
                        return;
                    }
                    ContractSetting.this.f5036f.setEnabled(false);
                    ContractSetting.this.f5032b.setEnabled(true);
                    ContractSetting.this.f5036f.setTitle(ContractSetting.this.getSpan(ContractSetting.this.getString(C0415R.string.replymes_title), C0415R.color.gray2));
                    return;
                }
                ContractSetting.this.f5036f.setEnabled(false);
                ContractSetting.this.f5032b.setEnabled(true);
                ContractSetting.this.f5036f.setTitle(ContractSetting.this.getSpan(ContractSetting.this.getString(C0415R.string.replymes_title), C0415R.color.gray2));
            }
        }).show();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.safemode_settings, null);
        setPreferenceScreen(createPrefence());
        getListView().setBackgroundDrawable(getResources().getDrawable(C0415R.drawable.blue));
        this.f5039i = PreferenceManager.getDefaultSharedPreferences(this);
        this.f5038h = this.f5033c.getSharedPreferences();
        this.f5044n = Integer.parseInt(this.f5038h.getString("sms_mode", DatabaseTables.SYSTEM_MARK));
        this.f5035e.setSummary(getSpan(getString(this.f5046p[this.f5044n]), C0415R.color.gray2));
        this.f5043m = Settings.System.getInt(getContentResolver(), "privateCall_mode_on", 0);
        this.f5034d.setSummary(getSpan(getString(this.f5047q[this.f5043m]), C0415R.color.gray2));
        this.f5049s = new C0889a(this, (byte) 0);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f5049s, filter);
        Log.i(AppDatabase.CONTENT, "DataHelpUtils===" + DataHelpUtils.execService("changeimg", this));
        if (this.f5044n == 0) {
            this.f5031a.setEnabled(false);
        }
        if (Settings.System.getInt(getContentResolver(), "privateCall_mode_on", 0) == 0 || Settings.System.getInt(getContentResolver(), "privateCall_mode_on", 0) == 1) {
            this.f5036f.setEnabled(false);
            this.f5032b.setEnabled(true);
            this.f5036f.setTitle(getSpan(getString(C0415R.string.replymes_title), C0415R.color.gray2));
        } else if (Settings.System.getInt(getContentResolver(), "privateCall_mode_on", 0) == 2) {
            this.f5036f.setEnabled(true);
            this.f5032b.setEnabled(true);
            this.f5036f.setTitle(getSpan(getString(C0415R.string.replymes_title), C0415R.color.black2));
        }
        onChang();
    }

    public SpannableString getSpan(int resID) {
        SpannableString spannable = new SpannableString(getString(resID));
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.black4)), 0, getString(resID).length(), 0);
        return spannable;
    }

    public PreferenceScreen createPrefence() {
        PreferenceScreen root = getPreferenceManager().createPreferenceScreen(this);
        PreferenceCategory mainCategory = new PreferenceCategory(this);
        mainCategory.setTitle(getSpan(C0415R.string.private_settitile));
        root.addPreference(mainCategory);
        this.f5033c = new Preference(this);
        this.f5033c.setLayoutResource(C0415R.layout.pref_list_item);
        this.f5033c.setWidgetLayoutResource(C0415R.layout.pref_widget_more);
        this.f5033c.setKey("changename");
        this.f5033c.setTitle(C0415R.string.changename_title);
        mainCategory.addPreference(this.f5033c);
        this.f5037g = new Preference(this);
        this.f5037g.setKey("error_pwd");
        this.f5037g.setLayoutResource(C0415R.layout.pref_list_item);
        this.f5037g.setWidgetLayoutResource(C0415R.layout.pref_widget_more);
        this.f5037g.setTitle(C0415R.string.error_pwdtitle);
        mainCategory.addPreference(this.f5037g);
        PreferenceCategory categoryset = new PreferenceCategory(this);
        categoryset.setTitle(getSpan(C0415R.string.smsmodesetting));
        root.addPreference(categoryset);
        this.f5035e = new Preference(this);
        this.f5035e.setKey("smsnotifymode");
        this.f5035e.setLayoutResource(C0415R.layout.pref_list_item);
        this.f5035e.setWidgetLayoutResource(C0415R.layout.pref_widget_more);
        this.f5035e.setTitle(C0415R.string.smsnotifymode_title);
        categoryset.addPreference(this.f5035e);
        this.f5031a = new Preference(this);
        this.f5031a.setKey("smsnotify");
        this.f5031a.setLayoutResource(C0415R.layout.pref_list_item);
        this.f5031a.setWidgetLayoutResource(C0415R.layout.pref_widget_more);
        this.f5031a.setTitle(C0415R.string.callnotify);
        categoryset.addPreference(this.f5031a);
        PreferenceCategory categoryMode = new PreferenceCategory(this);
        categoryMode.setTitle(getSpan(C0415R.string.callmodesetting));
        root.addPreference(categoryMode);
        this.f5034d = new Preference(this);
        this.f5034d.setKey("callnotifymode");
        this.f5034d.setLayoutResource(C0415R.layout.pref_list_item);
        this.f5034d.setWidgetLayoutResource(C0415R.layout.pref_widget_more);
        this.f5034d.setTitle(C0415R.string.callnotifymode_title);
        categoryMode.addPreference(this.f5034d);
        this.f5036f = new Preference(this);
        this.f5036f.setKey("replymes");
        this.f5036f.setLayoutResource(C0415R.layout.pref_list_item);
        this.f5036f.setWidgetLayoutResource(C0415R.layout.pref_widget_more);
        categoryMode.addPreference(this.f5036f);
        this.f5032b = new Preference(this);
        this.f5032b.setKey("callnotify");
        this.f5032b.setTitle(C0415R.string.callnotify);
        this.f5032b.setLayoutResource(C0415R.layout.pref_list_item);
        this.f5032b.setWidgetLayoutResource(C0415R.layout.pref_widget_more);
        categoryMode.addPreference(this.f5032b);
        return root;
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.ContractSetting$a */
    private class C0889a extends BroadcastReceiver {
        private C0889a() {
        }

        /* synthetic */ C0889a(ContractSetting x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                ContractSetting.this.finish();
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitlePreferenceActivity, android.preference.PreferenceActivity, android.app.ListActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f5049s);
    }

    public SpannableString getSpan(String str, int color) {
        SpannableString spannable = new SpannableString(str);
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(color)), 0, str.length(), 0);
        return spannable;
    }

    public void onChang() {
        this.f5036f.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.24
            @Override // android.preference.Preference.OnPreferenceClickListener
            public final boolean onPreferenceClick(Preference preference) {
                ContractSetting.m2093e(ContractSetting.this);
                return true;
            }
        });
        this.f5035e.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.25
            @Override // android.preference.Preference.OnPreferenceClickListener
            public final boolean onPreferenceClick(Preference preference) {
                ContractSetting.m2094f(ContractSetting.this);
                return true;
            }
        });
        this.f5034d.setOnPreferenceClickListener(new Preference.OnPreferenceClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.2
            @Override // android.preference.Preference.OnPreferenceClickListener
            public final boolean onPreferenceClick(Preference preference) {
                ContractSetting.m2095g(ContractSetting.this);
                return true;
            }
        });
    }

    @Override // android.preference.PreferenceActivity
    public boolean onPreferenceTreeClick(PreferenceScreen preferenceScreen, Preference preference) {
        Log.i(AppDatabase.CONTENT, preference.getKey());
        if (preference.getKey().equals("changepwd")) {
            showChangePwdDialog();
        } else if (preference.getKey().equals("smsnotify")) {
            startActivity(new Intent(this, (Class<?>) EditSettingActivity.class).putExtra(DatabaseTables.APPLICATIONS_FLAG, 2));
        } else if (preference.getKey().equals("callnotify")) {
            startActivity(new Intent(this, (Class<?>) EditSettingActivity.class).putExtra(DatabaseTables.APPLICATIONS_FLAG, 3));
        } else if (preference.getKey().equals("changename")) {
            startActivity(new Intent(this, (Class<?>) EditSettingActivity.class).putExtra(DatabaseTables.APPLICATIONS_FLAG, 1));
        } else if (preference.getKey().equals("changeimg")) {
            if (DataHelpUtils.execService("changeimg", this).equals("") || DataHelpUtils.execService("changeimg", this).equals("0")) {
                this.f5040j = 0;
            } else {
                this.f5040j = 1;
            }
            showDialogImage();
        } else if (preference.getKey().equals("smsimg")) {
            if (DataHelpUtils.execService("changesmsimg", this).equals("") || DataHelpUtils.execService("changesmsimg", this).equals("0")) {
                this.f5042l = 0;
            } else {
                this.f5042l = 1;
            }
            showDialogImageSms();
        } else if (preference.getKey().equals("callimg")) {
            if (DataHelpUtils.execService("changecallimg", this).equals("") || DataHelpUtils.execService("changecallimg", this).equals("0")) {
                this.f5041k = 0;
            } else {
                this.f5041k = 1;
            }
            showDialogImageCall();
        } else if (preference.getKey().equals("error_pwd")) {
            showChangePwdDialog();
        }
        return super.onPreferenceTreeClick(preferenceScreen, preference);
    }

    public void showChangePwdDialog() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_error_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        final EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        if (!DataHelpUtils.execService("pwd", this).equals("")) {
            pwd.setText(DataHelpUtils.execService("pwd", this));
            pwd2.setText(DataHelpUtils.execService("pwd", this));
        }
        new CustomDialog.Builder(this).setTitle(C0415R.string.changpwd_title).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (TextUtils.isEmpty(pwd.getText().toString().trim()) && TextUtils.isEmpty(pwd2.getText().toString().trim())) {
                    Toast.makeText(ContractSetting.this, C0415R.string.error_tips_null, 0).show();
                    return;
                }
                if (!TextUtils.isEmpty(pwd.getText().toString().trim()) && !TextUtils.isEmpty(pwd2.getText().toString().trim()) && pwd.getText().toString().length() == 6 && pwd.getText().toString().equals(pwd2.getText().toString())) {
                    if (PwdUtil.checkPassword(ContractSetting.this.getApplicationContext(), pwd2.getText().toString())) {
                        pwd2.setText("");
                        pwd.setText("");
                        Toast.makeText(ContractSetting.this, C0415R.string.error_password_set, 0).show();
                        return;
                    } else {
                        DataHelpUtils.UpdateConfig("pwd", pwd.getText().toString(), ContractSetting.this);
                        Toast.makeText(ContractSetting.this, C0415R.string.setting_pwdok, 0).show();
                        dialog.dismiss();
                        return;
                    }
                }
                if (pwd.getText().toString().trim().length() < 6 || pwd2.getText().toString().trim().length() < 6) {
                    Toast.makeText(ContractSetting.this, C0415R.string.safemode_input_pwd, 0).show();
                } else {
                    Toast.makeText(ContractSetting.this, C0415R.string.error_diff, 0).show();
                }
            }
        }, false).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
        this.f5048r.sendEmptyMessageDelayed(1, 1000L);
    }

    public void showChangeNotifyDialog(final int type) {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_input_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        final EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        TextView txt1 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title1);
        TextView txt2 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title2);
        txt1.setText(C0415R.string.dialog_title1);
        txt2.setVisibility(8);
        pwd2.setVisibility(8);
        txt2.setText(C0415R.string.dialog_title2);
        pwd2.setInputType(144);
        if (type == 0) {
            if (DataHelpUtils.execService("smsnotifytitle", this).equals("")) {
                pwd.setText(C0415R.string.newsms);
                pwd2.setText(C0415R.string.notify);
            } else {
                pwd.setText(DataHelpUtils.execService("smsnotifytitle", this));
                pwd2.setText(DataHelpUtils.execService("smsnotifycontent", this));
            }
        } else if (type == 1) {
            if (DataHelpUtils.execService("callnotifytitle", this).equals("")) {
                pwd.setText(C0415R.string.newcall);
                pwd2.setText(C0415R.string.notify);
            } else {
                pwd.setText(DataHelpUtils.execService("callnotifytitle", this));
                pwd2.setText(DataHelpUtils.execService("callnotifycontent", this));
            }
        }
        new CustomDialog.Builder(this).setTitle(C0415R.string.dialog_title).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (!TextUtils.isEmpty(pwd.getText().toString().trim())) {
                    if (type == 1) {
                        DataHelpUtils.UpdateConfig("callnotifytitle", pwd.getText().toString(), ContractSetting.this);
                        DataHelpUtils.UpdateConfig("callnotifycontent", pwd2.getText().toString(), ContractSetting.this);
                    } else if (type == 0) {
                        DataHelpUtils.UpdateConfig("smsnotifytitle", pwd.getText().toString(), ContractSetting.this);
                        DataHelpUtils.UpdateConfig("smsnotifycontent", pwd2.getText().toString(), ContractSetting.this);
                    }
                    dialog.dismiss();
                    Toast.makeText(ContractSetting.this, C0415R.string.setting_pwdok, 0).show();
                    return;
                }
                Toast.makeText(ContractSetting.this, C0415R.string.setting_pwdfail, 0).show();
            }
        }, false).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
        this.f5048r.sendEmptyMessageDelayed(1, 1000L);
    }

    public int getWordCount(String s) {
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            int ascii = Character.codePointAt(s, i);
            if (ascii >= 0 && ascii <= 255) {
                length++;
            } else {
                length += 2;
            }
        }
        return length;
    }

    public void showChangeNameDialog() {
        View view = LayoutInflater.from(this).inflate(C0415R.layout.safemode_input_password, (ViewGroup) null);
        final EditText pwd = (EditText) view.findViewById(C0415R.id.safemode_input_pwd);
        EditText pwd2 = (EditText) view.findViewById(C0415R.id.safemode_input_pwd_again);
        TextView txt1 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title1);
        TextView txt2 = (TextView) view.findViewById(C0415R.id.safemode_dailog_title2);
        txt1.setText(C0415R.string.changedes_txt1);
        txt2.setText(C0415R.string.changedes_txt2);
        pwd2.setInputType(144);
        txt2.setVisibility(8);
        pwd2.setVisibility(8);
        if (DataHelpUtils.execService("changeNametitle", this).equals("")) {
            pwd.setText(C0415R.string.privacy_safe);
        } else {
            pwd.setText(DataHelpUtils.execService("changeNametitle", this));
        }
        new CustomDialog.Builder(this).setTitle(C0415R.string.changename_title).setContentView(view).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (!TextUtils.isEmpty(pwd.getText().toString().trim())) {
                    if (ContractSetting.this.getWordCount(pwd.getText().toString()) <= 8) {
                        DataHelpUtils.UpdateConfig("changeNametitle", pwd.getText().toString(), ContractSetting.this);
                        Toast.makeText(ContractSetting.this, C0415R.string.setting_pwdok, 0).show();
                        dialog.dismiss();
                        return;
                    }
                    Toast.makeText(ContractSetting.this, C0415R.string.long_whire, 0).show();
                    return;
                }
                Toast.makeText(ContractSetting.this, C0415R.string.setting_pwdfail, 0).show();
            }
        }, false).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
        this.f5048r.sendEmptyMessageDelayed(1, 1000L);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public List<Map<String, Object>> m2081a() {
        List<Map<String, Object>> list = new ArrayList<>();
        Map<String, Object> map = new HashMap<>();
        Log.i(AppDatabase.CONTENT, String.valueOf(this.f5040j) + "==getData");
        if (this.f5042l == 0) {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        map.put("img", Integer.valueOf(C0415R.drawable.smsnotify_show_black));
        list.add(map);
        Map<String, Object> map2 = new HashMap<>();
        if (this.f5042l == 1) {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        map2.put("img", Integer.valueOf(C0415R.drawable.notify_hide_black));
        list.add(map2);
        return list;
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public List<Map<String, Object>> m2086b() {
        List<Map<String, Object>> list = new ArrayList<>();
        Map<String, Object> map = new HashMap<>();
        Log.i(AppDatabase.CONTENT, String.valueOf(this.f5040j) + "==getData");
        if (this.f5041k == 0) {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        map.put("img", Integer.valueOf(C0415R.drawable.callnotify_show_black));
        list.add(map);
        Map<String, Object> map2 = new HashMap<>();
        if (this.f5041k == 1) {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        map2.put("img", Integer.valueOf(C0415R.drawable.notify_hide_black));
        list.add(map2);
        return list;
    }

    public void showDialogImage() {
        this.f5045o = m2088c();
        MyAdapter myAdapter = new MyAdapter(this);
        final ListView listview = new ListView(this);
        listview.setCacheColorHint(getResources().getColor(C0415R.color.transparent_background));
        listview.setAdapter((ListAdapter) myAdapter);
        listview.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.9
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                ContractSetting.this.f5040j = position;
                ContractSetting.this.f5045o = ContractSetting.this.m2088c();
                listview.invalidateViews();
            }
        });
        new CustomDialog.Builder(this).setTitle(C0415R.string.changeimage_title).setContentView(listview).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.11
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Log.i(AppDatabase.CONTENT, String.valueOf(ContractSetting.this.f5040j));
                DataHelpUtils.UpdateConfig("changeimg", String.valueOf(ContractSetting.this.f5040j), ContractSetting.this);
                dialog.dismiss();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.10
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        }).show();
    }

    public void showDialogImageCall() {
        this.f5045o = m2086b();
        MyAdapter myAdapter = new MyAdapter(this);
        final ListView listview = new ListView(this);
        listview.setCacheColorHint(getResources().getColor(C0415R.color.transparent_background));
        listview.setAdapter((ListAdapter) myAdapter);
        listview.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.13
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                ContractSetting.this.f5041k = position;
                ContractSetting.this.f5045o = ContractSetting.this.m2086b();
                listview.invalidateViews();
            }
        });
        new CustomDialog.Builder(this).setTitle(C0415R.string.callimg_notify).setContentView(listview).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.15
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Log.i(AppDatabase.CONTENT, String.valueOf(ContractSetting.this.f5041k));
                DataHelpUtils.UpdateConfig("changecallimg", String.valueOf(ContractSetting.this.f5041k), ContractSetting.this);
                dialog.dismiss();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.14
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        }).show();
    }

    public void showDialogImageSms() {
        this.f5045o = m2081a();
        MyAdapter myAdapter = new MyAdapter(this);
        final ListView listview = new ListView(this);
        listview.setAdapter((ListAdapter) myAdapter);
        listview.setCacheColorHint(getResources().getColor(C0415R.color.transparent_background));
        listview.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.16
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                ContractSetting.this.f5042l = position;
                ContractSetting.this.f5045o = ContractSetting.this.m2081a();
                listview.invalidateViews();
            }
        });
        new CustomDialog.Builder(this).setTitle(C0415R.string.smsimg_notify).setContentView(listview).setPositiveButton(C0415R.string.sumbit, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.18
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Log.i(AppDatabase.CONTENT, String.valueOf(ContractSetting.this.f5042l));
                DataHelpUtils.UpdateConfig("changesmsimg", String.valueOf(ContractSetting.this.f5042l), ContractSetting.this);
                dialog.dismiss();
            }
        }).setNegativeButton(C0415R.string.safemode_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ContractSetting.17
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        }).show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: c */
    public List<Map<String, Object>> m2088c() {
        List<Map<String, Object>> list = new ArrayList<>();
        Map<String, Object> map = new HashMap<>();
        Log.i(AppDatabase.CONTENT, String.valueOf(this.f5040j) + "==getData");
        if (this.f5040j == 0) {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        map.put("img", Integer.valueOf(C0415R.drawable.home_page_drawer_privacy_safe));
        list.add(map);
        Map<String, Object> map2 = new HashMap<>();
        if (this.f5040j == 1) {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_on));
        } else {
            map2.put("imgon", Integer.valueOf(C0415R.drawable.btn_radio_off));
        }
        map2.put("img", Integer.valueOf(C0415R.drawable.safemode_hide));
        list.add(map2);
        return list;
    }

    public final class ViewHolder {
        public ImageView img;
        public ImageView imgon;

        public ViewHolder() {
        }
    }

    public class MyAdapter extends BaseAdapter {

        /* JADX INFO: renamed from: b */
        private LayoutInflater f5086b;

        public MyAdapter(Context context) {
            this.f5086b = LayoutInflater.from(context);
        }

        @Override // android.widget.Adapter
        public int getCount() {
            return ContractSetting.this.f5045o.size();
        }

        @Override // android.widget.Adapter
        public Object getItem(int arg0) {
            return null;
        }

        @Override // android.widget.Adapter
        public long getItemId(int arg0) {
            return 0L;
        }

        @Override // android.widget.Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            ViewHolder holder;
            if (convertView == null) {
                holder = ContractSetting.this.new ViewHolder();
                convertView = this.f5086b.inflate(C0415R.layout.vlist2, (ViewGroup) null);
                holder.img = (ImageView) convertView.findViewById(C0415R.id.changeimg_img);
                holder.imgon = (ImageView) convertView.findViewById(C0415R.id.changeimg_on);
                convertView.setTag(holder);
            } else {
                holder = (ViewHolder) convertView.getTag();
            }
            holder.img.setBackgroundResource(((Integer) ((Map) ContractSetting.this.f5045o.get(position)).get("img")).intValue());
            holder.imgon.setBackgroundResource(((Integer) ((Map) ContractSetting.this.f5045o.get(position)).get("imgon")).intValue());
            return convertView;
        }
    }
}
