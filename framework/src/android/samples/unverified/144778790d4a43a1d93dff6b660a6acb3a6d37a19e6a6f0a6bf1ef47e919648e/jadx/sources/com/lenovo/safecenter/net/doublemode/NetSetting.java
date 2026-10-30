package com.lenovo.safecenter.net.doublemode;

import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.MultiSIMUtils;
import android.text.TextUtils;
import android.text.format.Formatter;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.CheckedTextView;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.floatwindow.data.SaveData;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.correct.TrafficCorrectSetting;
import com.lenovo.safecenter.net.support.PhoneSimInfo;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.net.support.Utils;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.aresengine.SmsEntity;
import com.tencent.tmsecure.module.network.CorrectionDataInfo;
import com.tencent.tmsecure.module.network.TrafficCorrectionConfig;
import com.tencent.tmsecure.module.network.TrafficCorrectionManager;
import java.util.ArrayList;
import org.apache.commons.httpclient.cookie.CookiePolicy;

/* JADX INFO: loaded from: classes.dex */
public class NetSetting extends Activity implements View.OnClickListener, CompoundButton.OnCheckedChangeListener, DoubleCardUtil.SettingFloatNumberDialogListener, DoubleCardUtil.SettingNumberDialogListener1, DoubleCardUtil.SettingNumberDialogListener2 {
    public static final int NORMAL_SETTINGS_TRAFFIC_LIMIT = 6;
    public static final int SETTINGS_TRAFFIC_LIMIT = 7;

    /* JADX INFO: renamed from: A */
    private Context f4594A;

    /* JADX INFO: renamed from: B */
    private CheckedTextView f4595B;

    /* JADX INFO: renamed from: C */
    private CheckedTextView f4596C;

    /* JADX INFO: renamed from: D */
    private CheckedTextView f4597D;

    /* JADX INFO: renamed from: E */
    private CheckedTextView f4598E;

    /* JADX INFO: renamed from: F */
    private CheckedTextView f4599F;

    /* JADX INFO: renamed from: G */
    private CheckedTextView f4600G;

    /* JADX INFO: renamed from: H */
    private View f4601H;

    /* JADX INFO: renamed from: I */
    private int f4602I;

    /* JADX INFO: renamed from: J */
    private int f4603J;

    /* JADX INFO: renamed from: K */
    private PhoneSimInfo f4604K;

    /* JADX INFO: renamed from: L */
    private C0774b f4605L;

    /* JADX INFO: renamed from: M */
    private RelativeLayout f4606M;

    /* JADX INFO: renamed from: N */
    private EnumC0773a f4607N;

    /* JADX INFO: renamed from: O */
    private MultiSIMUtils f4608O;

    /* JADX INFO: renamed from: P */
    private int f4609P;

    /* JADX INFO: renamed from: Q */
    private String f4610Q;

    /* JADX INFO: renamed from: R */
    private String f4611R;

    /* JADX INFO: renamed from: S */
    private EditText f4612S;

    /* JADX INFO: renamed from: T */
    private EditText f4613T;

    /* JADX INFO: renamed from: U */
    private int f4614U;

    /* JADX INFO: renamed from: V */
    private SharedPreferences f4615V;

    /* JADX INFO: renamed from: W */
    private TextView f4616W;

    /* JADX INFO: renamed from: a */
    private CheckBox f4619a;

    /* JADX INFO: renamed from: b */
    private CheckBox f4620b;

    /* JADX INFO: renamed from: c */
    private CheckBox f4621c;

    /* JADX INFO: renamed from: d */
    private CheckBox f4622d;

    /* JADX INFO: renamed from: e */
    private TextView f4623e;

    /* JADX INFO: renamed from: f */
    private TextView f4624f;

    /* JADX INFO: renamed from: g */
    private TextView f4625g;

    /* JADX INFO: renamed from: h */
    private TextView f4626h;

    /* JADX INFO: renamed from: i */
    private TextView f4627i;

    /* JADX INFO: renamed from: j */
    private RelativeLayout f4628j;

    /* JADX INFO: renamed from: k */
    private RelativeLayout f4629k;

    /* JADX INFO: renamed from: l */
    private RelativeLayout f4630l;

    /* JADX INFO: renamed from: m */
    private RelativeLayout f4631m;

    /* JADX INFO: renamed from: n */
    private RelativeLayout f4632n;

    /* JADX INFO: renamed from: o */
    private RelativeLayout f4633o;

    /* JADX INFO: renamed from: p */
    private RelativeLayout f4634p;

    /* JADX INFO: renamed from: q */
    private RelativeLayout f4635q;

    /* JADX INFO: renamed from: r */
    private TextView f4636r;

    /* JADX INFO: renamed from: s */
    private TextView f4637s;

    /* JADX INFO: renamed from: t */
    private TextView f4638t;

    /* JADX INFO: renamed from: u */
    private TextView f4639u;

    /* JADX INFO: renamed from: v */
    private TextView f4640v;

    /* JADX INFO: renamed from: w */
    private TextView f4641w;

    /* JADX INFO: renamed from: x */
    private TextView f4642x;

    /* JADX INFO: renamed from: y */
    private TextView f4643y;

    /* JADX INFO: renamed from: z */
    private TextView f4644z;
    public final Handler mHandler = new Handler() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            int toast;
            switch (msg.what) {
                case C0415R.string.net_correct_update_config /* 2131560502 */:
                    SmsEntity sms = (SmsEntity) msg.obj;
                    if (NetSetting.this.f4612S == null || NetSetting.this.f4613T == null || NetSetting.this.f4614U != sms.f6027id) {
                        NetSetting.this.m1890a(sms.f6027id);
                    }
                    NetSetting.this.f4612S.setText(sms.body);
                    NetSetting.this.f4613T.setText(sms.phonenum);
                    StringBuilder sb = new StringBuilder();
                    sb.append(NetSetting.this.getString(C0415R.string.net_correct_limit_type)).append("  ").append(NetSetting.this.f4615V.getString(Utils.CITY_DESC, CookiePolicy.DEFAULT)).append(",").append(NetSetting.this.f4615V.getString(Utils.CARRY_DESC, CookiePolicy.DEFAULT));
                    NetSetting.this.f4616W.setText(sb.toString());
                    if (TextUtils.isEmpty(sms.body) || TextUtils.isEmpty(sms.phonenum)) {
                        toast = C0415R.string.net_error_code13;
                    } else {
                        toast = C0415R.string.net_correct_update_config_notice;
                    }
                    Toast.makeText(NetSetting.this.f4594A, toast, 0).show();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: X */
    private View.OnClickListener f4617X = new View.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.2
        @Override // android.view.View.OnClickListener
        public final void onClick(View v) {
            switch (v.getId()) {
                case C0415R.id.net_card_radio_week_sim1 /* 2131297313 */:
                    if (!NetSetting.this.f4595B.isChecked()) {
                        NetSetting.this.f4595B.setChecked(true);
                    }
                    NetSetting.this.f4597D.setChecked(false);
                    NetSetting.this.f4599F.setChecked(false);
                    NetSetting.this.f4602I = 0;
                    break;
                case C0415R.id.net_card_radio_ten_sim1 /* 2131297314 */:
                    if (!NetSetting.this.f4597D.isChecked()) {
                        NetSetting.this.f4597D.setChecked(true);
                    }
                    NetSetting.this.f4595B.setChecked(false);
                    NetSetting.this.f4599F.setChecked(false);
                    NetSetting.this.f4602I = 1;
                    break;
                case C0415R.id.net_card_radio_cancel_sim1 /* 2131297315 */:
                    if (!NetSetting.this.f4599F.isChecked()) {
                        NetSetting.this.f4599F.setChecked(true);
                    }
                    NetSetting.this.f4595B.setChecked(false);
                    NetSetting.this.f4597D.setChecked(false);
                    NetSetting.this.f4602I = 2;
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: Y */
    private View.OnClickListener f4618Y = new View.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.3
        @Override // android.view.View.OnClickListener
        public final void onClick(View v) {
            switch (v.getId()) {
                case C0415R.id.net_card_radio_week_sim2 /* 2131297317 */:
                    if (!NetSetting.this.f4596C.isChecked()) {
                        NetSetting.this.f4596C.setChecked(true);
                    }
                    NetSetting.this.f4598E.setChecked(false);
                    NetSetting.this.f4600G.setChecked(false);
                    NetSetting.this.f4603J = 0;
                    break;
                case C0415R.id.net_card_radio_ten_sim2 /* 2131297318 */:
                    if (!NetSetting.this.f4598E.isChecked()) {
                        NetSetting.this.f4598E.setChecked(true);
                    }
                    NetSetting.this.f4596C.setChecked(false);
                    NetSetting.this.f4600G.setChecked(false);
                    NetSetting.this.f4603J = 1;
                    break;
                case C0415R.id.net_card_radio_cancel_sim2 /* 2131297319 */:
                    if (!NetSetting.this.f4600G.isChecked()) {
                        NetSetting.this.f4600G.setChecked(true);
                    }
                    NetSetting.this.f4596C.setChecked(false);
                    NetSetting.this.f4598E.setChecked(false);
                    NetSetting.this.f4603J = 2;
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.doublemode.NetSetting$a */
    enum EnumC0773a {
        single,
        muti
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.net.doublemode.NetSetting$9] */
    /* JADX INFO: renamed from: d */
    static /* synthetic */ void m1901d(NetSetting x0, final int x1) {
        new Thread() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.9
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                SharedPreferences sp;
                if (x1 == 0) {
                    sp = NetSetting.this.getSharedPreferences(Utils.SIM1_PROPERTIES, 0);
                } else {
                    sp = NetSetting.this.getSharedPreferences(Utils.SIM2_PROPERTIES, 0);
                }
                TrafficCorrectionConfig config = new TrafficCorrectionConfig(sp.getString(Utils.PROVINCE, ""), sp.getString(Utils.CITY, ""), sp.getString(Utils.CARRY, ""), sp.getString(Utils.BRAND, ""));
                TrafficCorrectionManager mTcMgr = (TrafficCorrectionManager) ManagerCreator.getManager(TrafficCorrectionManager.class);
                mTcMgr.setConfig(config);
                ArrayList<CorrectionDataInfo> infoList = new ArrayList<>();
                mTcMgr.startCorrection(infoList);
                CorrectionDataInfo di = infoList.get(0);
                Message msg = new Message();
                msg.what = C0415R.string.net_correct_update_config;
                SmsEntity se = new SmsEntity();
                se.body = di.getMessage();
                se.phonenum = di.getAddress();
                se.f6027id = x1;
                msg.obj = se;
                NetSetting.this.mHandler.sendMessage(msg);
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.traffic_settings);
        this.f4594A = this;
        this.f4604K = TrafficStatsService.getImsiInfo(this);
        this.f4609P = TrafficStatsService.getTrafficMode(this.f4594A);
        this.f4610Q = getString(C0415R.string.net_card3);
        this.f4611R = getString(C0415R.string.net_card4);
        if (this.f4609P == 13) {
            this.f4607N = EnumC0773a.single;
        } else {
            this.f4607N = MyMultiSIMUtils.isMultiSim(this) ? EnumC0773a.muti : EnumC0773a.single;
        }
        if (this.f4607N == EnumC0773a.muti) {
            this.f4608O = MultiSIMUtils.getDefault(this);
        }
        TextView textView = (TextView) findViewById(C0415R.id.txt_title);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(this);
        textView.setText(C0415R.string.net_settings);
        this.f4640v = (TextView) findViewById(C0415R.id.show_no_sim_info);
        if (this.f4609P != 13) {
            if (this.f4607N == EnumC0773a.single && TextUtils.isEmpty(this.f4604K.sim1IMSI)) {
                this.f4640v.setVisibility(0);
            } else if (TextUtils.isEmpty(this.f4604K.sim1IMSI) && TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                this.f4640v.setVisibility(0);
            }
        }
        this.f4623e = (TextView) findViewById(C0415R.id.monthLimitTraffic_card1);
        this.f4624f = (TextView) findViewById(C0415R.id.monthLimitTraffic_card2);
        this.f4625g = (TextView) findViewById(C0415R.id.monthFreeTraffic_notice_card1);
        this.f4626h = (TextView) findViewById(C0415R.id.monthFreeTraffic_notice_card2);
        this.f4628j = (RelativeLayout) findViewById(C0415R.id.monthLimitTrafficLayout);
        this.f4629k = (RelativeLayout) findViewById(C0415R.id.dailyLimitTrafficLayout);
        this.f4628j.setOnClickListener(this);
        this.f4629k.setOnClickListener(this);
        this.f4627i = (TextView) findViewById(C0415R.id.dailyLimitTraffic);
        this.f4630l = (RelativeLayout) findViewById(C0415R.id.net_month_free_click);
        this.f4630l.setOnClickListener(this);
        this.f4631m = (RelativeLayout) findViewById(C0415R.id.traffic_sms_check_Layout);
        this.f4631m.setOnClickListener(this);
        this.f4632n = (RelativeLayout) findViewById(C0415R.id.net_single_month_free_notice);
        this.f4619a = (CheckBox) findViewById(C0415R.id.net_monthfree_single_switch);
        this.f4620b = (CheckBox) findViewById(C0415R.id.net_traffic_window_switch);
        this.f4622d = (CheckBox) findViewById(C0415R.id.net_traffic_window_fixed_switch);
        this.f4606M = (RelativeLayout) findViewById(C0415R.id.net_traffic_window_fixed);
        this.f4621c = (CheckBox) findViewById(C0415R.id.net_traffic_auto_deny_checkbox);
        if ("-1".equals(Const.getMonthLimitTraffic())) {
            this.f4619a.setChecked(false);
        } else {
            this.f4619a.setChecked(Const.getIsNetMonthFreeNoticeOn1());
        }
        this.f4619a.setOnCheckedChangeListener(this);
        this.f4620b.setOnCheckedChangeListener(this);
        this.f4622d.setOnCheckedChangeListener(this);
        this.f4621c.setOnCheckedChangeListener(this);
        this.f4620b.setChecked(SaveData.get_flow_status(this.f4594A));
        this.f4622d.setChecked(SaveData.get_flow_immove_state(this.f4594A));
        if (SaveData.get_flow_status(this.f4594A)) {
            this.f4606M.setVisibility(0);
        } else {
            this.f4606M.setVisibility(8);
        }
        this.f4621c.setChecked(TrafficStatsService.getIsAutoDeny(this.f4594A));
        if (this.f4607N == EnumC0773a.muti) {
            this.f4632n.setVisibility(8);
            if (!TextUtils.isEmpty(this.f4608O.getSubscriberId(0)) || TextUtils.isEmpty(this.f4608O.getSubscriberId(1))) {
            }
        } else {
            TextUtils.isEmpty(WflUtils.getActiveSubscriberId(this));
            this.f4630l.setVisibility(8);
        }
        this.f4636r = (TextView) findViewById(C0415R.id.monthCorrectTraffic_card1);
        this.f4637s = (TextView) findViewById(C0415R.id.monthCorrectTraffic_card2);
        this.f4633o = (RelativeLayout) findViewById(C0415R.id.net_traffic_correct_regular_parent);
        this.f4633o.setOnClickListener(this);
        this.f4634p = (RelativeLayout) findViewById(C0415R.id.net_sim1_location);
        this.f4634p.setOnClickListener(this);
        this.f4635q = (RelativeLayout) findViewById(C0415R.id.net_sim2_location);
        this.f4635q.setOnClickListener(this);
        this.f4638t = (TextView) findViewById(C0415R.id.net_correct_cycle_value_desc1);
        this.f4639u = (TextView) findViewById(C0415R.id.net_correct_cycle_value_desc2);
        this.f4641w = (TextView) findViewById(C0415R.id.net_sim1_top);
        this.f4642x = (TextView) findViewById(C0415R.id.net_sim2_top);
        this.f4643y = (TextView) findViewById(C0415R.id.net_sim1_location_des);
        this.f4644z = (TextView) findViewById(C0415R.id.net_sim2_location_des);
        if (this.f4607N == EnumC0773a.single) {
            this.f4641w.setText(C0415R.string.net_sim_location_set);
            this.f4639u.setVisibility(8);
        } else {
            this.f4641w.setText(getString(C0415R.string.net_card1) + getString(C0415R.string.net_sim_location_set));
            this.f4642x.setText(getString(C0415R.string.net_card2) + getString(C0415R.string.net_sim_location_set));
        }
        this.f4633o.setVisibility(0);
        this.f4634p.setVisibility(0);
        if (this.f4607N == EnumC0773a.single) {
            this.f4635q.setVisibility(8);
        } else if (TextUtils.isEmpty(this.f4604K.sim1IMSI) && TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
            this.f4634p.setVisibility(8);
            this.f4635q.setVisibility(8);
        } else {
            if (TextUtils.isEmpty(this.f4604K.sim1IMSI)) {
                this.f4634p.setVisibility(8);
            }
            if (TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                this.f4635q.setVisibility(8);
            }
        }
        m1889a();
        if (this.f4605L == null) {
            this.f4605L = new C0774b(this, b);
        }
        IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction("com.lenovo.safecenter.flowrefresh");
        registerReceiver(this.f4605L, intentFilter);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.doublemode.NetSetting$b */
    private class C0774b extends BroadcastReceiver {
        private C0774b() {
        }

        /* synthetic */ C0774b(NetSetting x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            boolean flowFlag = SaveData.get_flow_status(NetSetting.this.f4594A);
            if (flowFlag) {
                NetSetting.this.f4620b.setChecked(true);
                NetSetting.this.f4606M.setVisibility(0);
            } else {
                NetSetting.this.f4620b.setChecked(false);
                NetSetting.this.f4606M.setVisibility(8);
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1889a() {
        String package1 = Const.getMonthLimitTraffic();
        String package2 = Const.getMonthLimitTraffic2();
        if (this.f4607N == EnumC0773a.single) {
            this.f4636r.setVisibility(0);
            this.f4637s.setVisibility(4);
            this.f4639u.setVisibility(8);
            this.f4636r.setText(Formatter.formatFileSize(this, Const.getMonthUsedTraffic()));
            Log.i("s3", "month used =" + Const.getMonthUsedTraffic());
            if (TextUtils.isEmpty(this.f4604K.sim1IMSI) && this.f4609P == 10) {
                this.f4623e.setText(C0415R.string.net_simcard_error4);
            } else if ("-1".equals(package1)) {
                this.f4623e.setText(C0415R.string.no_setting_text);
            } else {
                this.f4623e.setText(package1 + getString(C0415R.string.net_m));
            }
            this.f4624f.setVisibility(4);
        } else {
            m1900d();
            if ("-1".equals(package1) && "-1".equals(package2)) {
                this.f4623e.setText(C0415R.string.no_setting_text);
                this.f4624f.setVisibility(4);
                this.f4625g.setText(getString(C0415R.string.net_card1) + getString(C0415R.string.no_open));
                this.f4626h.setText(getString(C0415R.string.net_card2) + getString(C0415R.string.no_open));
            } else if ("-1".equals(package1) && !"-1".equals(package2)) {
                this.f4623e.setText(getString(C0415R.string.net_card3) + getString(C0415R.string.no_setting_text));
                this.f4624f.setVisibility(0);
                this.f4624f.setText(getString(C0415R.string.net_card4) + package2 + getString(C0415R.string.net_m));
                this.f4625g.setText(getString(C0415R.string.net_card1) + getString(C0415R.string.no_open));
                if (Const.getIsNetMonthFreeNoticeOn2()) {
                    this.f4626h.setText(getString(C0415R.string.net_card2) + getString(C0415R.string.open));
                } else {
                    this.f4626h.setText(getString(C0415R.string.net_card2) + getString(C0415R.string.no_open));
                }
            } else if (!"-1".equals(package1) && "-1".equals(package2)) {
                this.f4623e.setText(getString(C0415R.string.net_card3) + package1 + getString(C0415R.string.net_m));
                this.f4624f.setVisibility(0);
                this.f4624f.setText(getString(C0415R.string.net_card4) + getString(C0415R.string.no_setting_text));
                if (Const.getIsNetMonthFreeNoticeOn1()) {
                    this.f4625g.setText(getString(C0415R.string.net_card1) + getString(C0415R.string.open));
                } else {
                    this.f4625g.setText(getString(C0415R.string.net_card1) + getString(C0415R.string.no_open));
                }
                this.f4626h.setText(getString(C0415R.string.net_card2) + getString(C0415R.string.no_open));
            } else {
                this.f4623e.setText(getString(C0415R.string.net_card3) + package1 + getString(C0415R.string.net_m));
                this.f4624f.setVisibility(0);
                this.f4624f.setText(getString(C0415R.string.net_card4) + package2 + getString(C0415R.string.net_m));
                if (Const.getIsNetMonthFreeNoticeOn1()) {
                    this.f4625g.setText(getString(C0415R.string.net_card1) + getString(C0415R.string.open));
                } else {
                    this.f4625g.setText(getString(C0415R.string.net_card1) + getString(C0415R.string.no_open));
                }
                if (Const.getIsNetMonthFreeNoticeOn2()) {
                    this.f4626h.setText(getString(C0415R.string.net_card2) + getString(C0415R.string.open));
                } else {
                    this.f4626h.setText(getString(C0415R.string.net_card2) + getString(C0415R.string.no_open));
                }
            }
            if (TextUtils.isEmpty(this.f4604K.sim1IMSI) && TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                this.f4623e.setText(C0415R.string.net_simcard_error4);
                this.f4624f.setVisibility(4);
                this.f4625g.setText(C0415R.string.no_open);
                this.f4626h.setVisibility(4);
            } else {
                if (TextUtils.isEmpty(this.f4604K.sim1IMSI)) {
                    boolean flag = "-1".equals(package2);
                    String trafficPackage = flag ? getString(C0415R.string.no_setting_text) : package2 + getString(C0415R.string.net_m);
                    this.f4623e.setText(this.f4611R + trafficPackage);
                    this.f4624f.setVisibility(4);
                    if (Const.getIsNetMonthFreeNoticeOn2()) {
                        this.f4625g.setText(this.f4611R + getString(C0415R.string.open));
                    } else {
                        this.f4625g.setText(this.f4611R + getString(C0415R.string.no_open));
                    }
                    if (flag) {
                        this.f4625g.setText(this.f4611R + getString(C0415R.string.no_open));
                    }
                    this.f4626h.setVisibility(4);
                }
                if (TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                    boolean flag2 = "-1".equals(package1);
                    String trafficPackage2 = "-1".equals(package1) ? getString(C0415R.string.no_setting_text) : package1 + getString(C0415R.string.net_m);
                    this.f4623e.setText(this.f4610Q + trafficPackage2);
                    this.f4624f.setVisibility(4);
                    if (Const.getIsNetMonthFreeNoticeOn1()) {
                        this.f4625g.setText(this.f4610Q + getString(C0415R.string.open));
                    } else {
                        this.f4625g.setText(this.f4610Q + getString(C0415R.string.no_open));
                    }
                    if (flag2) {
                        this.f4625g.setText(this.f4610Q + getString(C0415R.string.no_open));
                    }
                    this.f4626h.setVisibility(4);
                }
            }
        }
        long mDailyNotice = Const.getNetEverydayLimit();
        if (mDailyNotice == -1) {
            this.f4627i.setText(C0415R.string.no_setting_text);
        } else {
            this.f4627i.setText(mDailyNotice + getString(C0415R.string.net_m));
        }
        m1898c();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        try {
            StringBuilder builder = TrafficStatsService.getSIMCarryInfo(0, this);
            this.f4643y.setText(builder.toString());
        } catch (Exception e) {
            e.printStackTrace();
            this.f4643y.setText(C0415R.string.no_setting_text);
        }
        try {
            StringBuilder builder2 = TrafficStatsService.getSIMCarryInfo(1, this);
            this.f4644z.setText(builder2.toString());
        } catch (Exception e2) {
            e2.printStackTrace();
            this.f4644z.setText(C0415R.string.no_setting_text);
        }
        boolean flowFlag = SaveData.get_flow_status(this.f4594A);
        if (flowFlag) {
            this.f4620b.setChecked(true);
            this.f4606M.setVisibility(0);
        } else {
            this.f4620b.setChecked(false);
            this.f4606M.setVisibility(8);
        }
        boolean flowFixedFlag = SaveData.get_flow_immove_state(this.f4594A);
        if (flowFixedFlag) {
            this.f4622d.setChecked(true);
        } else {
            this.f4622d.setChecked(false);
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
            case C0415R.id.monthLimitTrafficLayout /* 2131297713 */:
                DoubleCardUtil.createSettingNumberDialog(this, this, 6);
                break;
            case C0415R.id.net_sim1_location /* 2131297716 */:
                NetCache.setNetSettingHandler(this.mHandler);
                m1890a(0);
                break;
            case C0415R.id.net_sim2_location /* 2131297719 */:
                NetCache.setNetSettingHandler(this.mHandler);
                m1890a(1);
                break;
            case C0415R.id.net_traffic_correct_regular_parent /* 2131297722 */:
                if (TextUtils.isEmpty(this.f4604K.sim1IMSI) && TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                    Toast.makeText(this, C0415R.string.net_simcard_error3, 1).show();
                } else {
                    this.f4601H = LayoutInflater.from(this).inflate(C0415R.layout.net_traffic_correct_cycle, (ViewGroup) null);
                    LinearLayout linearLayout = (LinearLayout) this.f4601H.findViewById(C0415R.id.net_sim_parent);
                    LinearLayout linearLayout2 = (LinearLayout) this.f4601H.findViewById(C0415R.id.net_sim2_parent);
                    TextView textView = (TextView) this.f4601H.findViewById(C0415R.id.net_traffic_auto_correct_sim1_title);
                    this.f4595B = (CheckedTextView) this.f4601H.findViewById(C0415R.id.net_card_radio_week_sim1);
                    this.f4596C = (CheckedTextView) this.f4601H.findViewById(C0415R.id.net_card_radio_week_sim2);
                    this.f4597D = (CheckedTextView) this.f4601H.findViewById(C0415R.id.net_card_radio_ten_sim1);
                    this.f4598E = (CheckedTextView) this.f4601H.findViewById(C0415R.id.net_card_radio_ten_sim2);
                    this.f4599F = (CheckedTextView) this.f4601H.findViewById(C0415R.id.net_card_radio_cancel_sim1);
                    this.f4600G = (CheckedTextView) this.f4601H.findViewById(C0415R.id.net_card_radio_cancel_sim2);
                    if (this.f4607N == EnumC0773a.single) {
                        textView.setVisibility(8);
                        linearLayout2.setVisibility(8);
                        this.f4596C.setVisibility(8);
                        this.f4598E.setVisibility(8);
                        this.f4600G.setVisibility(8);
                    } else {
                        if (TextUtils.isEmpty(this.f4604K.sim1IMSI)) {
                            linearLayout.setVisibility(8);
                        }
                        if (TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                            linearLayout2.setVisibility(8);
                        }
                    }
                    Log.i("4.1", "sim1 correct = " + Const.getNetCorrectCycle() + ",sim2 correct =" + Const.getNetCorrectCycle2());
                    if (Const.getNetCorrectCycle() == 0) {
                        this.f4595B.setChecked(true);
                    } else if (Const.getNetCorrectCycle() == 1) {
                        this.f4597D.setChecked(true);
                    } else {
                        this.f4599F.setChecked(true);
                    }
                    if (Const.getNetCorrectCycle2() == 0) {
                        this.f4596C.setChecked(true);
                    } else if (Const.getNetCorrectCycle2() == 1) {
                        this.f4598E.setChecked(true);
                    } else {
                        this.f4600G.setChecked(true);
                    }
                    this.f4602I = Const.getNetCorrectCycle();
                    this.f4603J = Const.getNetCorrectCycle2();
                    this.f4595B.setOnClickListener(this.f4617X);
                    this.f4597D.setOnClickListener(this.f4617X);
                    this.f4599F.setOnClickListener(this.f4617X);
                    this.f4596C.setOnClickListener(this.f4618Y);
                    this.f4598E.setOnClickListener(this.f4618Y);
                    this.f4600G.setOnClickListener(this.f4618Y);
                    CustomDialog.Builder builder = new CustomDialog.Builder(this);
                    builder.setTitle(C0415R.string.net_auto_correct_traffic_set_time);
                    builder.setContentView(this.f4601H);
                    builder.setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.4
                        @Override // android.content.DialogInterface.OnClickListener
                        public final void onClick(DialogInterface dialog, int which) {
                            Log.i("4.1", "int 1 =" + NetSetting.this.f4602I + ",int 2 =" + NetSetting.this.f4603J);
                            if (NetSetting.this.f4607N == EnumC0773a.single) {
                                Const.setNetCorrectCycle(NetSetting.this.f4602I);
                                TrafficStatsService.startAutoTrafficCorrectSim1(NetSetting.this.f4594A);
                            } else {
                                Const.setNetCorrectCycle(NetSetting.this.f4602I);
                                Const.setNetCorrectCycle2(NetSetting.this.f4603J);
                                TrafficStatsService.startAutoTrafficCorrectSim1(NetSetting.this.f4594A);
                                TrafficStatsService.startAutoTrafficCorrectSim2(NetSetting.this.f4594A);
                            }
                            NetSetting.this.m1898c();
                        }
                    });
                    builder.show();
                }
                break;
            case C0415R.id.traffic_sms_check_Layout /* 2131297725 */:
                DoubleCardUtil.createSettingFloatDialog(this, this, 4);
                break;
            case C0415R.id.net_month_free_click /* 2131297728 */:
                DoubleCardUtil.createSettingCheckBoxDialog(this, this, 5);
                break;
            case C0415R.id.dailyLimitTrafficLayout /* 2131297733 */:
                DoubleCardUtil.createSettingNumberDialog2(this, this, 1, null);
                break;
        }
    }

    @Override // android.widget.CompoundButton.OnCheckedChangeListener
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
        int id = buttonView.getId();
        if (id == C0415R.id.net_monthfree_single_switch) {
            if (isChecked && "-1".equals(Const.getMonthLimitTraffic())) {
                DoubleCardUtil.createSettingNumberDialog(this, this, 7);
                if (NetCache.traffic_mode == 10 && TextUtils.isEmpty(WflUtils.getActiveSubscriberId(this))) {
                    this.f4619a.setChecked(false);
                    Const.setIsNetMonthFreeNoticeOn1(false);
                }
            } else {
                Const.setIsNetMonthFreeNoticeOn1(isChecked);
            }
        }
        if (id == C0415R.id.net_traffic_window_switch) {
            if (isChecked) {
                if (SecurityService.instance != null) {
                    SecurityService.instance.setFlowVisibility(0);
                }
                this.f4606M.setVisibility(0);
                SaveData.save_flow_status(this, true);
                TrackEvent.reportTrafficFloatwindowSwitchChanged(true);
            } else {
                if (SecurityService.instance != null) {
                    SecurityService.instance.setFlowVisibility(8);
                }
                this.f4606M.setVisibility(8);
                SaveData.save_flow_status(this, false);
                TrackEvent.reportTrafficFloatwindowSwitchChanged(false);
            }
        }
        if (id == C0415R.id.net_traffic_window_fixed_switch) {
            if (isChecked) {
                if (SecurityService.instance != null) {
                    SecurityService.instance.setFlowIsFixed(true);
                }
                SaveData.save_flow_immove_state(this, true);
            } else {
                if (SecurityService.instance != null) {
                    SecurityService.instance.setFlowIsFixed(false);
                }
                SaveData.save_flow_immove_state(this, false);
            }
        }
        if (id == C0415R.id.net_traffic_auto_deny_checkbox) {
            TrafficStatsService.setIsAutoDeny(this.f4594A, isChecked);
            TrackEvent.reportTrafficOutLimitDisableNetSwitchChanged(isChecked);
        }
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogOK(int[] number, int flag) {
        if (this.f4607N == EnumC0773a.muti) {
            if (!TextUtils.isEmpty(this.f4604K.sim1IMSI)) {
                Const.setMonthLimitTraffic(String.valueOf(number[0]));
            }
            if (!TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                Const.setMonthLimitTraffic2(String.valueOf(number[1]));
            }
        } else {
            if (TrafficStatsService.getTrafficMode(this.f4594A) == 13 || !TextUtils.isEmpty(WflUtils.getActiveSubscriberId(this))) {
                Const.setMonthLimitTraffic(String.valueOf(number[0]));
            }
            if (number[0] == -1) {
                this.f4619a.setChecked(false);
                Const.setIsNetMonthFreeNoticeOn1(false);
            }
        }
        if (flag == 7) {
            if (number[0] == -1) {
                this.f4619a.setChecked(false);
                Const.setIsNetMonthFreeNoticeOn1(false);
            } else {
                this.f4619a.setChecked(true);
                Const.setIsNetMonthFreeNoticeOn1(true);
            }
        }
        TrafficStatsService.statsTrafficMobile(this.f4594A);
        m1889a();
        m1895b();
    }

    /* JADX INFO: renamed from: b */
    private static void m1895b() {
        if (Const.trafficHandler != null) {
            Const.trafficHandler.sendEmptyMessage(5);
        }
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener1
    public void onSettingNumberDialogOK(int number, int id, int postion) {
        switch (id) {
            case 1:
                Log.i("4.1", "number = " + number);
                Const.setNetEverydayLimit(number);
                if (number == -1) {
                    this.f4627i.setText(C0415R.string.no_setting_text);
                } else {
                    this.f4627i.setText(number + getString(C0415R.string.net_m));
                }
                break;
            case 2:
                if (postion == 1) {
                    Const.setMonthLimitTraffic(String.valueOf(number));
                }
                if (postion == 2) {
                    Const.setMonthLimitTraffic2(String.valueOf(number));
                }
                TrafficStatsService.statsTrafficMobile(this.f4594A);
                m1889a();
                m1895b();
                break;
            case 5:
                m1889a();
                break;
        }
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener1
    public void onSettingNumberDialogCancel(int number) {
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingFloatNumberDialogListener
    public void onSettingFloatNumberDialogOK(int id, Float[] number) {
        TrafficStatsService mAppDatabase = TrafficStatsService.getInstance(this.f4594A);
        if (Const.getMonthUsedTraffic() != number[0].floatValue() && number[0].floatValue() != -1.0f) {
            DoubleCardUtil.checkTraffic(number[0], mAppDatabase, this.f4594A, 0);
        }
        if (Const.getMonthUsedTraffic2() != number[1].floatValue() && number[1].floatValue() != -1.0f) {
            DoubleCardUtil.checkTraffic(number[1], mAppDatabase, this.f4594A, 1);
        }
        m1900d();
        m1895b();
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingFloatNumberDialogListener
    public void onSettingFloatNumberDialogCancel(int id, Float[] number) {
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: c */
    public void m1898c() {
        int correct1 = Const.getNetCorrectCycle();
        int correct2 = Const.getNetCorrectCycle2();
        m1891a(correct1, "SIM1:");
        if (correct2 == 0) {
            this.f4639u.setText("SIM2:" + getString(C0415R.string.net_week));
        } else if (correct2 == 1) {
            this.f4639u.setText("SIM2:" + getString(C0415R.string.net_every_ten));
        } else {
            this.f4639u.setText("SIM2:" + getString(C0415R.string.net_cancel));
        }
        if (this.f4609P == 12) {
            if (TextUtils.isEmpty(this.f4604K.sim1IMSI) && TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                this.f4638t.setText(C0415R.string.net_simcard_error4);
                this.f4639u.setVisibility(4);
            } else if (TextUtils.isEmpty(this.f4604K.sim1IMSI)) {
                m1891a(correct2, "SIM2:");
                this.f4639u.setVisibility(4);
            } else if (TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                this.f4639u.setVisibility(4);
            } else {
                this.f4638t.setVisibility(0);
                this.f4639u.setVisibility(0);
            }
        } else {
            this.f4639u.setVisibility(4);
        }
        if (correct1 == 2 && correct2 == 2) {
            this.f4638t.setText(C0415R.string.net_cancel);
            this.f4639u.setVisibility(4);
        }
    }

    /* JADX INFO: renamed from: a */
    private void m1891a(int correct, String sim) {
        if (correct == 0) {
            if (TrafficStatsService.getTrafficMode(this.f4594A) == 12) {
                this.f4638t.setText(sim + getString(C0415R.string.net_week));
                return;
            } else {
                this.f4638t.setText(getString(C0415R.string.net_week));
                return;
            }
        }
        if (correct == 1) {
            if (TrafficStatsService.getTrafficMode(this.f4594A) == 12) {
                this.f4638t.setText(sim + getString(C0415R.string.net_every_ten));
                return;
            } else {
                this.f4638t.setText(getString(C0415R.string.net_every_ten));
                return;
            }
        }
        if (TrafficStatsService.getTrafficMode(this.f4594A) == 12) {
            this.f4638t.setText(sim + getString(C0415R.string.net_cancel));
        } else {
            this.f4638t.setText(getString(C0415R.string.net_cancel));
        }
    }

    /* JADX INFO: renamed from: d */
    private void m1900d() {
        if (this.f4609P == 12) {
            if (TextUtils.isEmpty(this.f4604K.sim1IMSI) && TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                this.f4636r.setText(C0415R.string.net_simcard_error4);
                this.f4637s.setVisibility(4);
                return;
            } else {
                if (TextUtils.isEmpty(this.f4604K.sim1IMSI)) {
                    this.f4636r.setText(this.f4611R + Formatter.formatFileSize(this, Const.getMonthUsedTraffic2()));
                    return;
                }
                if (TextUtils.isEmpty(this.f4604K.sim2IMSI)) {
                    this.f4636r.setText(this.f4610Q + Formatter.formatFileSize(this, Const.getMonthUsedTraffic()));
                    return;
                }
                this.f4636r.setVisibility(0);
                this.f4637s.setVisibility(0);
                this.f4636r.setText(this.f4610Q + Formatter.formatFileSize(this, Const.getMonthUsedTraffic()));
                this.f4637s.setText(this.f4611R + Formatter.formatFileSize(this, Const.getMonthUsedTraffic2()));
                return;
            }
        }
        if (this.f4609P == 10) {
            if (TextUtils.isEmpty(WflUtils.getActiveSubscriberId(this))) {
                this.f4636r.setText(C0415R.string.net_simcard_error4);
            } else {
                this.f4636r.setText(Formatter.formatFileSize(this, Const.getMonthUsedTraffic()));
            }
            this.f4637s.setVisibility(0);
            return;
        }
        this.f4636r.setText(Formatter.formatFileSize(this, Const.getMonthUsedTraffic()));
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogCancel(int[] number, int flag) {
        if (flag == 7 && TrafficStatsService.getTrafficMode(this.f4594A) != 12) {
            this.f4619a.setChecked(false);
            Const.setIsNetMonthFreeNoticeOn1(false);
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f4605L);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1890a(final int card) {
        PhoneSimInfo info = TrafficStatsService.getImsiInfo(this);
        if (card == 0) {
            if (TextUtils.isEmpty(info.sim1IMSI)) {
                if (TrafficStatsService.getTrafficMode(this) == 13 && MyMultiSIMUtils.isMultiSim(this) && !TextUtils.isEmpty(info.sim2IMSI)) {
                    Toast.makeText(this, C0415R.string.net_error_code12, 1).show();
                    return;
                } else {
                    Toast.makeText(this, C0415R.string.net_simcard_error2, 1).show();
                    return;
                }
            }
        } else if (TextUtils.isEmpty(info.sim2IMSI)) {
            Toast.makeText(this, C0415R.string.net_simcard_error2, 1).show();
            return;
        }
        if (card == 0) {
            this.f4615V = getSharedPreferences(Utils.SIM1_PROPERTIES, 0);
        } else {
            this.f4615V = getSharedPreferences(Utils.SIM2_PROPERTIES, 0);
        }
        boolean codeHasChanged = "".equals(this.f4615V.getString(Utils.SMS_MESSAGE, "")) || "".equals(this.f4615V.getString(Utils.SMS_ADDRESS, ""));
        boolean locationHasChanged = this.f4615V.getBoolean(Utils.CONFIG_HAS_SETTED, false);
        if (!locationHasChanged && codeHasChanged) {
            Intent mIntent = new Intent(this, (Class<?>) TrafficCorrectSetting.class);
            mIntent.putExtra("card", card);
            mIntent.putExtra("correct_type", 1);
            startActivity(mIntent);
            return;
        }
        this.f4614U = card;
        View view = LayoutInflater.from(this).inflate(C0415R.layout.net_traffic_correct_info_set, (ViewGroup) null);
        RelativeLayout layout = (RelativeLayout) view.findViewById(C0415R.id.net_correct_sim_info_title);
        layout.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                NetCache.setNetSettingHandler(NetSetting.this.mHandler);
                TrafficStatsService.startIntent2TrafficCorrect(card, NetSetting.this.f4594A, 1);
            }
        });
        this.f4616W = (TextView) view.findViewById(C0415R.id.net_correct_sim_info_summary);
        this.f4612S = (EditText) view.findViewById(C0415R.id.net_correct_sms_content);
        this.f4613T = (EditText) view.findViewById(C0415R.id.net_correct_sms_number);
        this.f4612S.setText(this.f4615V.getString(Utils.SMS_MESSAGE, ""));
        this.f4613T.setText(this.f4615V.getString(Utils.SMS_ADDRESS, ""));
        TextView update = (TextView) view.findViewById(C0415R.id.net_query_correct_text);
        update.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!WflUtils.isNetworkAvailable(NetSetting.this.f4594A)) {
                    Toast.makeText(NetSetting.this.f4594A, C0415R.string.net_correct_update_config_net_error, 0).show();
                } else {
                    NetSetting.m1901d(NetSetting.this, card);
                    Toast.makeText(NetSetting.this.f4594A, C0415R.string.net_correct_update_config_progress, 0).show();
                }
            }
        });
        StringBuilder sb = new StringBuilder();
        sb.append(getString(C0415R.string.net_correct_limit_type)).append("  ").append(this.f4615V.getString(Utils.CITY_DESC, CookiePolicy.DEFAULT)).append(",").append(this.f4615V.getString(Utils.CARRY_DESC, CookiePolicy.DEFAULT));
        this.f4616W.setText(sb.toString());
        CustomDialog.Builder builder = new CustomDialog.Builder(this);
        builder.setContentView(view);
        builder.setColorNegativeButton(false);
        builder.setColorPositiveButton(true);
        builder.setTitle(C0415R.string.net_traffic_sms_query_config_set);
        builder.setPositiveButton(C0415R.string.save, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                String content = NetSetting.this.f4612S.getText().toString();
                String address = NetSetting.this.f4613T.getText().toString();
                if (content == null || "".equals(content) || address == null || "".equals(address)) {
                    Toast.makeText(NetSetting.this.f4594A, C0415R.string.net_correct_update_config_input_null_error, 0).show();
                } else {
                    NetSetting.this.f4615V.edit().putString(Utils.SMS_MESSAGE, content).commit();
                    NetSetting.this.f4615V.edit().putString(Utils.SMS_ADDRESS, address).commit();
                }
            }
        });
        builder.setNegativeButton(C0415R.string.net_correct_cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.net.doublemode.NetSetting.8
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        });
        if (!isFinishing()) {
            builder.show();
        }
    }
}
