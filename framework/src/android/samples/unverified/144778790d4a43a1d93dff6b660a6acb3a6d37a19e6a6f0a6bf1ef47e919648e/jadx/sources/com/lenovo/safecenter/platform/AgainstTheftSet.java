package com.lenovo.safecenter.platform;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.telephony.TelephonyManager;
import android.util.Log;
import android.view.View;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class AgainstTheftSet extends Activity {
    public static boolean sendMail = false;

    /* JADX INFO: renamed from: a */
    CustomDialog f4890a;

    /* JADX INFO: renamed from: b */
    private CheckBox f4891b;

    /* JADX INFO: renamed from: c */
    private CheckBox f4892c;

    /* JADX INFO: renamed from: d */
    private ImageView f4893d;

    /* JADX INFO: renamed from: e */
    private boolean f4894e;

    /* JADX INFO: renamed from: f */
    private boolean f4895f;

    /* JADX INFO: renamed from: g */
    private boolean f4896g;

    /* JADX INFO: renamed from: h */
    private TextView f4897h;

    /* JADX INFO: renamed from: i */
    private TextView f4898i;

    /* JADX INFO: renamed from: j */
    private TextView f4899j;

    /* JADX INFO: renamed from: k */
    private SharedPreferences f4900k;

    /* JADX INFO: renamed from: l */
    private String f4901l;

    /* JADX INFO: renamed from: m */
    private String f4902m;

    /* JADX INFO: renamed from: n */
    private RelativeLayout f4903n;

    /* JADX INFO: renamed from: o */
    private RelativeLayout f4904o;

    /* JADX INFO: renamed from: p */
    private LinearLayout f4905p;

    /* JADX INFO: renamed from: q */
    private TelephonyManager f4906q;

    /* JADX INFO: renamed from: r */
    private int f4907r;

    /* JADX INFO: renamed from: s */
    private TextView f4908s;

    /* JADX INFO: renamed from: t */
    private ActivityManager f4909t;

    /* JADX INFO: renamed from: u */
    private C0843a f4910u;

    /* JADX INFO: renamed from: v */
    private Handler f4911v = new Handler() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.13
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    AgainstTheftSet.sendMail = false;
                    AgainstTheftSet.this.m2032a();
                    Toast.makeText(AgainstTheftSet.this.getApplicationContext(), AgainstTheftSet.this.getApplicationContext().getString(C0415R.string.mail_send) + AgainstTheftSet.this.getApplicationContext().getString(C0415R.string.backup_to_phone_ok_activity), 1).show();
                    break;
                case 2:
                    AgainstTheftSet.sendMail = false;
                    AgainstTheftSet.this.m2032a();
                    Toast.makeText(AgainstTheftSet.this.getApplicationContext(), C0415R.string.backup_to_phone_no_activity, 1).show();
                    break;
                case 3:
                    AgainstTheftSet.sendMail = true;
                    AgainstTheftSet.this.m2032a();
                    Toast.makeText(AgainstTheftSet.this.getApplicationContext(), C0415R.string.sending, 1).show();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: e */
    static /* synthetic */ void m2026e(AgainstTheftSet x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.disable_antitheft_tip).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Const.setProtecThiefSwitchState(false);
                AgainstTheftSet.this.stopService(new Intent("com.lenovo.antitheft.ALARM"));
                AgainstTheftSet.this.f4900k.edit().putBoolean("all", false).commit();
                AgainstTheftSet.this.f4900k.edit().putBoolean("locked", false).commit();
                AgainstTheftSet.this.f4900k.edit().putBoolean("alarm", false).commit();
                AgainstTheftSet.this.f4900k.edit().putBoolean("sim_changed_locked_screen", false).commit();
                AgainstTheftSet.this.m2033a(false);
                AgainstTheftSet.this.f4893d.setImageResource(C0415R.drawable.btn_off);
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).setColorPositiveButton(false).setColorNegativeButton(true).show();
    }

    /* JADX INFO: renamed from: g */
    static /* synthetic */ void m2028g(AgainstTheftSet x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.first_set_safephone).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).setPositiveButton(C0415R.string.set_now, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Intent i = new Intent(AgainstTheftSet.this.getApplicationContext(), (Class<?>) AgainstTheftSafePhoneSetActivity.class);
                i.setFlags(1073741824);
                i.putExtra("firstsetphone", true);
                AgainstTheftSet.this.startActivityForResult(i, 0);
            }
        }).setColorPositiveButton(true).setColorNegativeButton(false).show();
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.platform.AgainstTheftSet$a */
    private class C0843a extends BroadcastReceiver {
        private C0843a() {
        }

        /* synthetic */ C0843a(AgainstTheftSet x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                AgainstTheftSet.this.finish();
            }
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f4910u);
    }

    @Override // android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.againsttheftset_main);
        m2023b();
        this.f4910u = new C0843a(this, (byte) 0);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f4910u, filter);
    }

    /* JADX INFO: renamed from: b */
    private void m2023b() {
        Log.i("ydp", "init~");
        this.f4906q = (TelephonyManager) getSystemService("phone");
        this.f4909t = (ActivityManager) getSystemService("activity");
        this.f4900k = getSharedPreferences("antitheft", 0);
        TextView topBar = (TextView) findViewById(C0415R.id.txt_title);
        topBar.setText(C0415R.string.theft);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AgainstTheftSet.this.finish();
            }
        });
        this.f4903n = (RelativeLayout) findViewById(C0415R.id.safephone_parent);
        this.f4904o = (RelativeLayout) findViewById(C0415R.id.backup_mail_parent);
        this.f4905p = (LinearLayout) findViewById(C0415R.id.linearLayout1);
        this.f4891b = (CheckBox) findViewById(C0415R.id.checkBox_sim_alarm_sms);
        this.f4892c = (CheckBox) findViewById(C0415R.id.checkBox_sim_alarm_screen);
        this.f4893d = (ImageView) findViewById(C0415R.id.a_switch_protect_thief);
        this.f4897h = (TextView) findViewById(C0415R.id.detail_safephone);
        this.f4898i = (TextView) findViewById(C0415R.id.detail_backup_mail);
        this.f4899j = (TextView) findViewById(C0415R.id.detail_protect_thief);
        this.f4901l = Const.getSafePhoneNumber();
        this.f4902m = Const.getSafeMail();
        this.f4908s = (TextView) findViewById(C0415R.id.backup_now_btn);
        if (this.f4902m.equals("")) {
            this.f4908s.setVisibility(8);
        } else {
            this.f4908s.setVisibility(0);
        }
        m2032a();
        this.f4908s.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.6
            /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.platform.AgainstTheftSet$6$1] */
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                new Thread() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.6.1
                    @Override // java.lang.Thread, java.lang.Runnable
                    public final void run() {
                        if (MyUtils.getNetWorksState(AgainstTheftSet.this)) {
                            AgainstTheftSet.this.f4911v.sendEmptyMessage(3);
                        }
                        AgainstTheftSet.this.f4911v.sendEmptyMessage(MyUtils.backupToMail(AgainstTheftSet.this.getApplicationContext(), "", Const.getSafeMail()));
                    }
                }.start();
            }
        });
        this.f4894e = this.f4900k.getBoolean(Const.KEY_IS_PROTECT_THIEF_ON, false);
        this.f4895f = this.f4900k.getBoolean("sim_alarm_sms", false);
        this.f4896g = this.f4900k.getBoolean("sim_alarm_screen", false);
        this.f4907r = this.f4906q.getSimState();
        if (this.f4894e) {
            this.f4893d.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f4893d.setImageResource(C0415R.drawable.btn_off);
        }
        m2033a(this.f4894e);
        this.f4891b.setChecked(this.f4895f);
        this.f4892c.setChecked(this.f4896g);
        if (this.f4901l.equals("")) {
            this.f4897h.setText(C0415R.string.safe_phone_number_save_no);
            this.f4897h.setTextColor(getResources().getColor(C0415R.color.red));
        } else {
            this.f4897h.setText(this.f4901l);
            this.f4897h.setTextColor(C0415R.color.gray2);
        }
        if (this.f4902m.equals("")) {
            this.f4898i.setText(C0415R.string.safe_mail_address_save_no);
            this.f4898i.setTextColor(getResources().getColor(C0415R.color.red));
        } else {
            this.f4898i.setText(this.f4902m);
            this.f4898i.setTextColor(C0415R.color.gray2);
        }
        this.f4903n.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!MyMultiSIMUtils.isMultiSim(AgainstTheftSet.this)) {
                    AgainstTheftSet.this.f4907r = AgainstTheftSet.this.f4906q.getSimState();
                    Log.d("test", "SimState: " + AgainstTheftSet.this.f4907r);
                    if (AgainstTheftSet.this.f4907r == 1 || AgainstTheftSet.this.f4907r == 0) {
                        if (AgainstTheftSet.this.f4890a == null) {
                            AgainstTheftSet.this.f4890a = new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(C0415R.string.insert_sim).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).create();
                        }
                        if (!AgainstTheftSet.this.f4890a.isShowing()) {
                            AgainstTheftSet.this.f4890a.show();
                            return;
                        }
                        return;
                    }
                    Intent i = new Intent(AgainstTheftSet.this.getApplicationContext(), (Class<?>) AgainstTheftSafePhoneSetActivity.class);
                    i.setFlags(1073741824);
                    AgainstTheftSet.this.startActivityForResult(i, 0);
                    return;
                }
                int[] states = MyMultiSIMUtils.getAllSimState(AgainstTheftSet.this);
                int simState0 = states[0];
                int simState1 = states[1];
                boolean sim1Ready = simState0 == 5 || simState0 == 2 || simState0 == 3;
                boolean sim2Ready = simState1 == 5 || simState1 == 2 || simState1 == 3;
                if (sim1Ready || sim2Ready) {
                    Intent i2 = new Intent(AgainstTheftSet.this.getApplicationContext(), (Class<?>) AgainstTheftSafePhoneSetActivity.class);
                    i2.setFlags(1073741824);
                    AgainstTheftSet.this.startActivityForResult(i2, 0);
                } else {
                    if (AgainstTheftSet.this.f4890a == null) {
                        AgainstTheftSet.this.f4890a = new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(C0415R.string.insert_sim).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).create();
                    }
                    if (!AgainstTheftSet.this.f4890a.isShowing()) {
                        AgainstTheftSet.this.f4890a.show();
                    }
                }
            }
        });
        this.f4904o.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.8
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                Intent i = new Intent(AgainstTheftSet.this.getApplicationContext(), (Class<?>) AgainstTheftSafeMailSetActivity.class);
                i.setFlags(1073741824);
                AgainstTheftSet.this.startActivityForResult(i, 0);
            }
        });
        this.f4905p.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.9
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                Intent i = new Intent(AgainstTheftSet.this.getApplicationContext(), (Class<?>) AgainstTheftPromptActivity.class);
                i.setFlags(1073741824);
                AgainstTheftSet.this.startActivityForResult(i, 0);
            }
        });
        this.f4893d.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.10
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                String msg;
                String msg2;
                Log.e("ydp", "checkBox_thief click!" + AgainstTheftSet.this.f4900k.getBoolean(Const.KEY_IS_PROTECT_THIEF_ON, false));
                if (AgainstTheftSet.this.f4900k.getBoolean(Const.KEY_IS_PROTECT_THIEF_ON, false)) {
                    AgainstTheftSet.m2026e(AgainstTheftSet.this);
                    return;
                }
                if (!MyMultiSIMUtils.isMultiSim(AgainstTheftSet.this)) {
                    AgainstTheftSet.this.f4907r = AgainstTheftSet.this.f4906q.getSimState();
                    Log.d("test", "SimState: " + AgainstTheftSet.this.f4907r);
                    if (AgainstTheftSet.this.f4907r == 5) {
                        if (AgainstTheftSet.this.f4901l.equals("")) {
                            AgainstTheftSet.m2028g(AgainstTheftSet.this);
                            return;
                        }
                        Const.setProtecThiefSwitchState(true);
                        AgainstTheftSet.this.f4893d.setImageResource(C0415R.drawable.btn_on);
                        AgainstTheftSet.this.m2033a(true);
                        return;
                    }
                    if (AgainstTheftSet.this.f4890a == null) {
                        if (AgainstTheftSet.this.f4907r == 2 || AgainstTheftSet.this.f4907r == 3) {
                            msg = AgainstTheftSet.this.getString(C0415R.string.sim_pin);
                        } else {
                            msg = AgainstTheftSet.this.getString(C0415R.string.insert_sim);
                        }
                        AgainstTheftSet.this.f4890a = new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(msg).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).create();
                    }
                    if (!AgainstTheftSet.this.f4890a.isShowing()) {
                        AgainstTheftSet.this.f4890a.show();
                        return;
                    }
                    return;
                }
                int[] states = MyMultiSIMUtils.getAllSimState(AgainstTheftSet.this);
                int simState0 = states[0];
                int simState1 = states[1];
                boolean sim1Ready = simState0 == 5;
                boolean sim2Ready = simState1 == 5;
                if (sim1Ready || sim2Ready) {
                    if (AgainstTheftSet.this.f4901l.equals("")) {
                        AgainstTheftSet.m2028g(AgainstTheftSet.this);
                        return;
                    }
                    Const.setProtecThiefSwitchState(true);
                    AgainstTheftSet.this.f4893d.setImageResource(C0415R.drawable.btn_on);
                    AgainstTheftSet.this.m2033a(true);
                    return;
                }
                if (AgainstTheftSet.this.f4890a == null) {
                    if (simState0 == 2 || simState0 == 3 || simState1 == 2 || simState1 == 3) {
                        msg2 = AgainstTheftSet.this.getString(C0415R.string.sim_pin);
                    } else {
                        msg2 = AgainstTheftSet.this.getString(C0415R.string.insert_sim);
                    }
                    AgainstTheftSet.this.f4890a = new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(msg2).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).create();
                }
                if (!AgainstTheftSet.this.f4890a.isShowing()) {
                    AgainstTheftSet.this.f4890a.show();
                }
            }
        });
        this.f4891b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.11
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                String msg;
                if (!AgainstTheftSet.this.f4891b.isChecked()) {
                    AgainstTheftSet.this.f4900k.edit().putBoolean("sim_alarm_sms", false).commit();
                    return;
                }
                if (!MyMultiSIMUtils.isMultiSim(AgainstTheftSet.this)) {
                    AgainstTheftSet.this.f4907r = AgainstTheftSet.this.f4906q.getSimState();
                    if (!AgainstTheftSet.this.f4901l.equals("")) {
                        if (AgainstTheftSet.this.f4907r == 5 || AgainstTheftSet.this.f4907r == 2 || AgainstTheftSet.this.f4907r == 3) {
                            AgainstTheftSet.this.f4900k.edit().putBoolean("sim_alarm_sms", true).commit();
                            String simSerialNumber = AgainstTheftSet.this.f4906q.getSubscriberId();
                            while (simSerialNumber == null) {
                                simSerialNumber = AgainstTheftSet.this.f4906q.getSubscriberId();
                            }
                            AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER", simSerialNumber).commit();
                            return;
                        }
                        AgainstTheftSet.this.f4891b.setChecked(false);
                        new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(C0415R.string.insert_sim).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).show();
                        return;
                    }
                    Toast.makeText(AgainstTheftSet.this.getApplicationContext(), C0415R.string.safe_phone_number_save_no, 0).show();
                    AgainstTheftSet.this.f4891b.setChecked(false);
                    return;
                }
                int[] states = MyMultiSIMUtils.getAllSimState(AgainstTheftSet.this);
                int simState0 = states[0];
                int simState1 = states[1];
                boolean sim1Ready = simState0 == 5;
                boolean sim2Ready = simState1 == 5;
                if (sim1Ready || sim2Ready) {
                    if (!AgainstTheftSet.this.f4901l.equals("")) {
                        AgainstTheftSet.this.f4900k.edit().putBoolean("sim_alarm_sms", true).commit();
                        Log.i("boot", "myutil  sim0" + simState0 + "sim1" + simState1);
                        String simSerialNumber1 = MyUtils.getSimSerialNumber(0, sim1Ready, AgainstTheftSet.this);
                        String simSerialNumber2 = MyUtils.getSimSerialNumber(1, sim2Ready, AgainstTheftSet.this);
                        if (simSerialNumber1 != null) {
                            AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER1", simSerialNumber1).commit();
                        } else {
                            AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER1", "").commit();
                        }
                        if (simSerialNumber2 != null) {
                            AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER2", simSerialNumber2).commit();
                            return;
                        } else {
                            AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER2", "").commit();
                            return;
                        }
                    }
                    Toast.makeText(AgainstTheftSet.this.getApplicationContext(), C0415R.string.safe_phone_number_save_no, 0).show();
                    AgainstTheftSet.this.f4891b.setChecked(false);
                    return;
                }
                AgainstTheftSet.this.f4891b.setChecked(false);
                if (simState0 == 2 || simState0 == 3 || simState1 == 2 || simState1 == 3) {
                    msg = AgainstTheftSet.this.getString(C0415R.string.sim_pin);
                } else {
                    msg = AgainstTheftSet.this.getString(C0415R.string.insert_sim);
                }
                new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(msg).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).show();
            }
        });
        this.f4892c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSet.12
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                String msg;
                if (!AgainstTheftSet.this.f4892c.isChecked()) {
                    AgainstTheftSet.this.f4900k.edit().putBoolean("sim_alarm_screen", false).commit();
                    return;
                }
                if (!MyMultiSIMUtils.isMultiSim(AgainstTheftSet.this)) {
                    AgainstTheftSet.this.f4907r = AgainstTheftSet.this.f4906q.getSimState();
                    if (AgainstTheftSet.this.f4907r == 5 || AgainstTheftSet.this.f4907r == 2 || AgainstTheftSet.this.f4907r == 3) {
                        AgainstTheftSet.this.f4900k.edit().putBoolean("sim_alarm_screen", true).commit();
                        String simSerialNumber = AgainstTheftSet.this.f4906q.getSubscriberId();
                        if (simSerialNumber == null) {
                            simSerialNumber = AgainstTheftSet.this.f4906q.getSubscriberId();
                        }
                        AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER", simSerialNumber).commit();
                        return;
                    }
                    AgainstTheftSet.this.f4892c.setChecked(false);
                    new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(C0415R.string.insert_sim).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).show();
                    return;
                }
                int[] states = MyMultiSIMUtils.getAllSimState(AgainstTheftSet.this);
                int simState0 = states[0];
                int simState1 = states[1];
                boolean sim1Ready = simState0 == 5;
                boolean sim2Ready = simState1 == 5;
                if (!sim1Ready && !sim2Ready) {
                    AgainstTheftSet.this.f4892c.setChecked(false);
                    if (simState0 == 2 || simState0 == 3 || simState1 == 2 || simState1 == 3) {
                        msg = AgainstTheftSet.this.getString(C0415R.string.sim_pin);
                    } else {
                        msg = AgainstTheftSet.this.getString(C0415R.string.insert_sim);
                    }
                    new CustomDialog.Builder(AgainstTheftSet.this).setTitle(C0415R.string.info).setMessage(msg).setNeutralButton(C0415R.string.sumbit, (DialogInterface.OnClickListener) null).show();
                    return;
                }
                Log.i("boot", "sim0" + simState0 + "sim1" + simState1);
                AgainstTheftSet.this.f4900k.edit().putBoolean("sim_alarm_screen", true).commit();
                String simSerialNumber1 = MyUtils.getSimSerialNumber(0, sim1Ready, AgainstTheftSet.this);
                String simSerialNumber2 = MyUtils.getSimSerialNumber(1, sim2Ready, AgainstTheftSet.this);
                if (simSerialNumber1 != null) {
                    AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER1", simSerialNumber1).commit();
                } else {
                    AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER1", "").commit();
                }
                if (simSerialNumber2 != null) {
                    AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER2", simSerialNumber2).commit();
                } else {
                    AgainstTheftSet.this.f4900k.edit().putString("ORG_SIM_NUMBER2", "").commit();
                }
            }
        });
    }

    /* JADX INFO: renamed from: a */
    final void m2032a() {
        if (sendMail) {
            this.f4908s.setEnabled(false);
            this.f4908s.setTextColor(getResources().getColor(C0415R.color.gray2));
        } else {
            this.f4908s.setEnabled(true);
            this.f4908s.setTextColor(getResources().getColor(C0415R.color.blue_btn));
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        LeSafeObservable.get(getApplicationContext()).noticeRefreshProtectThiefDetail();
        TrackEvent.trackPause(this);
        if (!this.f4909t.getRunningTasks(1).get(0).topActivity.getPackageName().equals(getPackageName())) {
            finish();
        }
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        m2023b();
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onRestart() {
        super.onRestart();
    }

    /* JADX INFO: renamed from: a */
    final void m2033a(boolean b) {
        Log.i("ydp", "updateswitch");
        if (b) {
            this.f4899j.setText(C0415R.string.opend);
            this.f4899j.setTextColor(getResources().getColor(C0415R.color.gray2));
        } else {
            this.f4899j.setText(C0415R.string.closed);
            this.f4899j.setTextColor(-65536);
        }
    }

    @Override // android.app.Activity
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        Log.i("ydp", "requestCode:" + requestCode + "resultCode:" + resultCode);
        if (resultCode == 100) {
            finish();
        }
    }
}
