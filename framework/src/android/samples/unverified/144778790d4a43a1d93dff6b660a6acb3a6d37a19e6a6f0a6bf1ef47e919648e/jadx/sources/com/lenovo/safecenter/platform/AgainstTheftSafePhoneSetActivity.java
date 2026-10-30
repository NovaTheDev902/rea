package com.lenovo.safecenter.platform;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public class AgainstTheftSafePhoneSetActivity extends Activity {

    /* JADX INFO: renamed from: a */
    TextView f4876a;

    /* JADX INFO: renamed from: b */
    EditText f4877b;

    /* JADX INFO: renamed from: c */
    private SharedPreferences f4878c;

    /* JADX INFO: renamed from: d */
    private String f4879d;

    /* JADX INFO: renamed from: e */
    private String f4880e;

    /* JADX INFO: renamed from: f */
    private int f4881f;

    /* JADX INFO: renamed from: g */
    private TelephonyManager f4882g;

    /* JADX INFO: renamed from: h */
    private ActivityManager f4883h;

    /* JADX INFO: renamed from: i */
    private boolean f4884i = false;

    /* JADX INFO: renamed from: d */
    static /* synthetic */ void m2014d(AgainstTheftSafePhoneSetActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.send_sms_info).setPositiveButton(C0415R.string.send_on, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafePhoneSetActivity.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
                String password = PwdUtil.getPasswordWithJieMi(AgainstTheftSafePhoneSetActivity.this.getApplicationContext());
                DoubleCardUtils.sendMessage(AgainstTheftSafePhoneSetActivity.this.getApplicationContext(), AgainstTheftSafePhoneSetActivity.this.f4880e, AgainstTheftSafePhoneSetActivity.this.getString(C0415R.string.distant_com) + " " + password + AgainstTheftSafePhoneSetActivity.this.getString(C0415R.string.command_content), true);
                Const.isTariff = false;
                Toast.makeText(AgainstTheftSafePhoneSetActivity.this.getApplicationContext(), C0415R.string.setting_pwdok, 1).show();
                AgainstTheftSafePhoneSetActivity.m2019i(AgainstTheftSafePhoneSetActivity.this);
            }
        }).setNegativeButton(C0415R.string.send_off_, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafePhoneSetActivity.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Toast.makeText(AgainstTheftSafePhoneSetActivity.this.getApplicationContext(), C0415R.string.setting_pwdok, 1).show();
                AgainstTheftSafePhoneSetActivity.m2019i(AgainstTheftSafePhoneSetActivity.this);
            }
        }).show();
    }

    /* JADX INFO: renamed from: h */
    static /* synthetic */ void m2018h(AgainstTheftSafePhoneSetActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.error).setMessage(C0415R.string.phonenumber_error).setNegativeButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafePhoneSetActivity.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: i */
    static /* synthetic */ void m2019i(AgainstTheftSafePhoneSetActivity x0) {
        if (!x0.getIntent().getBooleanExtra("first_set_phone", false)) {
            x0.finish();
            return;
        }
        x0.f4881f = x0.f4882g.getSimState();
        if (x0.f4881f == 5 || x0.f4881f == 2 || x0.f4881f == 3) {
            x0.f4878c.edit().putString("ORG_SIM_NUMBER", x0.f4882g.getSubscriberId()).commit();
            x0.f4878c.edit().putBoolean("sim_alarm_sms", true).commit();
            x0.f4878c.edit().putBoolean("sim_alarm_screen", true).commit();
        } else {
            x0.f4878c.edit().putBoolean("sim_alarm_sms", false).commit();
            x0.f4878c.edit().putBoolean("sim_alarm_screen", false).commit();
        }
        if (x0.getIntent().getBooleanExtra("to_angist", false)) {
            x0.startActivity(new Intent(x0, (Class<?>) AgainstTheftSet.class));
        }
        x0.finish();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_antitheft_safephone_layout);
        getWindow().setSoftInputMode(34);
        this.f4882g = (TelephonyManager) getSystemService("phone");
        TextView topBar = (TextView) findViewById(C0415R.id.txt_title);
        topBar.setText(C0415R.string.safe_phone_number_set);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafePhoneSetActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AgainstTheftSafePhoneSetActivity.this.finish();
            }
        });
        this.f4883h = (ActivityManager) getSystemService("activity");
        this.f4878c = getSharedPreferences("antitheft", 0);
        this.f4879d = Const.getSafePhoneNumber();
        this.f4884i = getIntent().getBooleanExtra("firstsetphone", false);
        this.f4877b = (EditText) findViewById(C0415R.id.set_safephone_edittext);
        Log.i("ydp", this.f4879d + "++++++++++++++");
        this.f4877b.setText(this.f4879d);
        this.f4876a = (TextView) findViewById(C0415R.id.okbtn);
        this.f4876a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafePhoneSetActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AgainstTheftSafePhoneSetActivity.this.f4880e = AgainstTheftSafePhoneSetActivity.this.f4877b.getText().toString();
                if (AgainstTheftSafePhoneSetActivity.this.f4880e.length() != 0) {
                    if (AgainstTheftSafePhoneSetActivity.this.isMobileNO(AgainstTheftSafePhoneSetActivity.this.f4880e)) {
                        Const.setSafePhoneNumber(AgainstTheftSafePhoneSetActivity.this.f4880e);
                        if (AgainstTheftSafePhoneSetActivity.this.f4879d.equals(AgainstTheftSafePhoneSetActivity.this.f4880e)) {
                            Toast.makeText(AgainstTheftSafePhoneSetActivity.this.getApplicationContext(), C0415R.string.no_edit, 1).show();
                            AgainstTheftSafePhoneSetActivity.this.finish();
                            return;
                        }
                        AgainstTheftSafePhoneSetActivity.m2014d(AgainstTheftSafePhoneSetActivity.this);
                        if (AgainstTheftSafePhoneSetActivity.this.f4884i) {
                            AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putBoolean("sim_alarm_sms", true).commit();
                            AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putBoolean("sim_alarm_screen", true).commit();
                            Const.setProtecThiefSwitchState(true);
                            if (!MyMultiSIMUtils.isMultiSim(AgainstTheftSafePhoneSetActivity.this)) {
                                AgainstTheftSafePhoneSetActivity.this.f4881f = AgainstTheftSafePhoneSetActivity.this.f4882g.getSimState();
                                if (AgainstTheftSafePhoneSetActivity.this.f4881f == 5) {
                                    String simSerialNumber = AgainstTheftSafePhoneSetActivity.this.f4882g.getSubscriberId();
                                    if (simSerialNumber == null) {
                                        simSerialNumber = AgainstTheftSafePhoneSetActivity.this.f4882g.getSubscriberId();
                                    }
                                    AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putString("ORG_SIM_NUMBER", simSerialNumber).commit();
                                    return;
                                }
                                return;
                            }
                            int[] states = MyMultiSIMUtils.getAllSimState(AgainstTheftSafePhoneSetActivity.this);
                            int simState0 = states[0];
                            int simState1 = states[1];
                            boolean sim1Ready = simState0 == 5;
                            boolean sim2Ready = simState1 == 5;
                            if (sim1Ready || sim2Ready) {
                                Log.i("boot", "sim0" + simState0 + "sim1" + simState1);
                                String simSerialNumber1 = MyUtils.getSimSerialNumber(0, sim1Ready, AgainstTheftSafePhoneSetActivity.this);
                                String simSerialNumber2 = MyUtils.getSimSerialNumber(1, sim2Ready, AgainstTheftSafePhoneSetActivity.this);
                                if (simSerialNumber1 != null) {
                                    AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putString("ORG_SIM_NUMBER1", simSerialNumber1).commit();
                                } else {
                                    AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putString("ORG_SIM_NUMBER1", "").commit();
                                }
                                if (simSerialNumber2 != null) {
                                    AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putString("ORG_SIM_NUMBER2", simSerialNumber2).commit();
                                    return;
                                } else {
                                    AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putString("ORG_SIM_NUMBER2", "").commit();
                                    return;
                                }
                            }
                            return;
                        }
                        return;
                    }
                    AgainstTheftSafePhoneSetActivity.m2018h(AgainstTheftSafePhoneSetActivity.this);
                    return;
                }
                Const.setSafePhoneNumber("");
                AgainstTheftSafePhoneSetActivity.this.f4878c.edit().putBoolean("sim_alarm_sms", false).commit();
                AgainstTheftSafePhoneSetActivity.this.finish();
            }
        });
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        Log.i("ydp", "result pkg" + this.f4883h.getRunningTasks(1).get(0).topActivity.getPackageName());
        if (!this.f4883h.getRunningTasks(1).get(0).topActivity.getPackageName().equals(getPackageName())) {
            setResult(100);
            finish();
        }
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    public boolean isMobileNO(String mobiles) {
        Pattern p = Pattern.compile("^((\\+86)|(86))?((13[0-9])|(15[^4,\\D])|(18[0-9]))\\d{8}$");
        Matcher m = p.matcher(mobiles);
        return m.matches();
    }
}
