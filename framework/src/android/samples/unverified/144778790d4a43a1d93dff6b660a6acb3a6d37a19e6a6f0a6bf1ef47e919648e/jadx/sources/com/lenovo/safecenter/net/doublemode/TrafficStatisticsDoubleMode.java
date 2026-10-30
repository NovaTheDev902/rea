package com.lenovo.safecenter.net.doublemode;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.text.TextUtils;
import android.text.format.Formatter;
import android.util.Log;
import android.view.View;
import android.view.ViewTreeObserver;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.support.PhoneSimInfo;
import com.lenovo.safecenter.net.support.TrafficDate;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.NewFunctionNoticeManager;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class TrafficStatisticsDoubleMode extends Activity implements View.OnClickListener, DoubleCardUtil.SettingNumberDialogListener1, DoubleCardUtil.SettingNumberDialogListener2 {

    /* JADX INFO: renamed from: A */
    private int f4661A;

    /* JADX INFO: renamed from: B */
    private int f4662B;

    /* JADX INFO: renamed from: C */
    private int f4663C;

    /* JADX INFO: renamed from: D */
    private PhoneSimInfo f4664D;

    /* JADX INFO: renamed from: E */
    private EnumC0781a f4665E;

    /* JADX INFO: renamed from: F */
    private PhoneSimInfo f4666F;

    /* JADX INFO: renamed from: G */
    private int f4667G;

    /* JADX INFO: renamed from: H */
    private SharedPreferences f4668H;

    /* JADX INFO: renamed from: a */
    private ImageView f4672a;

    /* JADX INFO: renamed from: b */
    private ImageView f4673b;

    /* JADX INFO: renamed from: c */
    private TextView f4674c;

    /* JADX INFO: renamed from: d */
    private TextView f4675d;

    /* JADX INFO: renamed from: e */
    private TextView f4676e;

    /* JADX INFO: renamed from: f */
    private TextView f4677f;

    /* JADX INFO: renamed from: g */
    private TextView f4678g;

    /* JADX INFO: renamed from: h */
    private TextView f4679h;

    /* JADX INFO: renamed from: i */
    private TextView f4680i;

    /* JADX INFO: renamed from: j */
    private TextView f4681j;

    /* JADX INFO: renamed from: k */
    private TextView f4682k;

    /* JADX INFO: renamed from: l */
    private TextView f4683l;

    /* JADX INFO: renamed from: m */
    private HashMap<String, TrafficDate> f4684m;

    /* JADX INFO: renamed from: n */
    private HashMap<String, TrafficDate> f4685n;

    /* JADX INFO: renamed from: o */
    private LinearLayout f4686o;

    /* JADX INFO: renamed from: p */
    private TextView f4687p;

    /* JADX INFO: renamed from: q */
    private TextView f4688q;

    /* JADX INFO: renamed from: r */
    private TextView f4689r;

    /* JADX INFO: renamed from: s */
    private TextView f4690s;

    /* JADX INFO: renamed from: t */
    private HorizontalScrollView f4691t;

    /* JADX INFO: renamed from: u */
    private RelativeLayout f4692u;

    /* JADX INFO: renamed from: v */
    private TrafficStatsService f4693v;

    /* JADX INFO: renamed from: w */
    private Context f4694w;

    /* JADX INFO: renamed from: x */
    private View f4695x;

    /* JADX INFO: renamed from: y */
    private View f4696y;

    /* JADX INFO: renamed from: z */
    private int f4697z;
    public final Handler mHandler = new Handler() { // from class: com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    TrafficStatisticsDoubleMode.this.drawDayTrafficIsNotSetup(0);
                    TrafficStatisticsDoubleMode.this.f4665E = EnumC0781a.card1;
                    break;
                case 1:
                    TrafficStatisticsDoubleMode.this.drawDayTrafficIsNotSetup(1);
                    TrafficStatisticsDoubleMode.this.f4665E = EnumC0781a.card2;
                    break;
                case 3:
                    NetCache.canCorrect = true;
                    break;
                case 5:
                    TrafficStatisticsDoubleMode.this.m1919a();
                    TrafficStatisticsDoubleMode.this.m1929d();
                    break;
                case 6:
                    int pos = ((Integer) msg.obj).intValue();
                    TrafficStatisticsDoubleMode.this.m1920a(pos, 1);
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: I */
    private boolean f4669I = true;

    /* JADX INFO: renamed from: J */
    private boolean f4670J = false;

    /* JADX INFO: renamed from: K */
    private Runnable f4671K = new Runnable() { // from class: com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode.4
        @Override // java.lang.Runnable
        public final void run() {
            int screen_width = TrafficStatisticsDoubleMode.this.f4667G * 8;
            if (TrafficStatisticsDoubleMode.this.f4697z <= 8 || TrafficStatisticsDoubleMode.this.f4697z >= 17) {
                if (TrafficStatisticsDoubleMode.this.f4697z <= 16 || TrafficStatisticsDoubleMode.this.f4697z >= 25) {
                    if (TrafficStatisticsDoubleMode.this.f4697z > 24 && TrafficStatisticsDoubleMode.this.f4697z < 32) {
                        TrafficStatisticsDoubleMode.this.f4691t.scrollBy(screen_width * 3, 0);
                        if (TrafficStatisticsDoubleMode.this.f4691t.getScrollX() == screen_width * 3) {
                            TrafficStatisticsDoubleMode.this.mHandler.removeCallbacks(this);
                            return;
                        }
                        return;
                    }
                    return;
                }
                TrafficStatisticsDoubleMode.this.f4691t.scrollBy(screen_width * 2, 0);
                if (TrafficStatisticsDoubleMode.this.f4691t.getScrollX() == screen_width * 2) {
                    TrafficStatisticsDoubleMode.this.mHandler.removeCallbacks(this);
                    return;
                } else {
                    TrafficStatisticsDoubleMode.this.mHandler.post(this);
                    return;
                }
            }
            TrafficStatisticsDoubleMode.this.f4691t.scrollBy(screen_width, 0);
            if (TrafficStatisticsDoubleMode.this.f4691t.getScrollX() == screen_width) {
                TrafficStatisticsDoubleMode.this.mHandler.removeCallbacks(this);
            } else {
                TrafficStatisticsDoubleMode.this.mHandler.post(this);
            }
        }
    };

    /* JADX INFO: renamed from: com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode$a */
    enum EnumC0781a {
        card1,
        card2
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.f4694w = this;
        Const.trafficHandler = this.mHandler;
        TrafficStatsService.setMonthLimit(this);
        this.f4667G = (int) NetCache.getTraffic_view_width();
        setContentView(C0415R.layout.traffic_statistics_double_mode);
        if (TextUtils.isEmpty(NetCache.imsi) || TextUtils.isEmpty(NetCache.imsi2)) {
            TrafficStatsService.initNetCache(this);
        }
        this.f4666F = TrafficStatsService.getImsiInfo(this);
        Log.i("airtest", "imsi 1 = " + this.f4666F.sim1IMSI + "imsi 2 = " + this.f4666F.sim2IMSI);
        this.f4668H = PreferenceManager.getDefaultSharedPreferences(this.f4694w);
        this.f4669I = this.f4668H.getBoolean("THREAD_SLEEPED", false);
        this.f4670J = this.f4668H.getInt("traffc_view_height", -1) == -1;
        this.f4664D = TrafficStatsService.getImsiInfo(this);
        this.f4672a = (ImageView) findViewById(C0415R.id.title_back);
        this.f4673b = (ImageView) findViewById(C0415R.id.title_set);
        this.f4674c = (TextView) findViewById(C0415R.id.txt_title);
        this.f4674c.setText(C0415R.string.net_traffic_control);
        this.f4673b.setVisibility(0);
        this.f4675d = (TextView) findViewById(C0415R.id.net_card1_today_used);
        this.f4676e = (TextView) findViewById(C0415R.id.net_card2_today_used);
        this.f4677f = (TextView) findViewById(C0415R.id.net_card1_month_used);
        this.f4678g = (TextView) findViewById(C0415R.id.net_card2_month_used);
        this.f4679h = (TextView) findViewById(C0415R.id.net_card1_button);
        this.f4680i = (TextView) findViewById(C0415R.id.net_card2_button);
        this.f4686o = (LinearLayout) findViewById(C0415R.id.above_layout);
        this.f4691t = (HorizontalScrollView) findViewById(C0415R.id.scrollView);
        this.f4692u = (RelativeLayout) findViewById(C0415R.id.net_intent_netfilter);
        this.f4681j = (TextView) findViewById(C0415R.id.net_notification_text);
        this.f4687p = (TextView) findViewById(C0415R.id.net_set_package);
        this.f4682k = (TextView) findViewById(C0415R.id.net_card1_month_free);
        this.f4683l = (TextView) findViewById(C0415R.id.net_card2_month_free);
        this.f4682k.setOnClickListener(this);
        this.f4683l.setOnClickListener(this);
        this.f4672a.setOnClickListener(this);
        this.f4673b.setOnClickListener(this);
        this.f4687p.setOnClickListener(this);
        this.f4679h.setOnClickListener(this);
        this.f4680i.setOnClickListener(this);
        this.f4692u.setOnClickListener(this);
        this.f4695x = findViewById(C0415R.id.net_card1_line);
        this.f4696y = findViewById(C0415R.id.net_card2_line);
        this.f4688q = (TextView) findViewById(C0415R.id.card1_text);
        this.f4689r = (TextView) findViewById(C0415R.id.card2_text);
        this.f4690s = (TextView) findViewById(C0415R.id.parent_left);
        this.f4661A = TrafficStatsService.getDataCardPosition(this);
        NetCache.data_id_postion = this.f4661A;
        if (this.f4661A == 1) {
            this.f4665E = EnumC0781a.card2;
        } else {
            this.f4665E = EnumC0781a.card1;
        }
        if (!WflUtils.isMobileNetwork(this.f4694w)) {
            this.f4690s.setVisibility(4);
        } else if (this.f4661A == 1) {
            this.f4689r.setBackgroundResource(C0415R.drawable.net_current_sim_background);
        } else {
            this.f4688q.setBackgroundResource(C0415R.drawable.net_current_sim_background);
        }
        this.f4686o.getViewTreeObserver().addOnGlobalLayoutListener(new ViewTreeObserver.OnGlobalLayoutListener() { // from class: com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode.2
            @Override // android.view.ViewTreeObserver.OnGlobalLayoutListener
            public final void onGlobalLayout() {
                int height3 = TrafficStatisticsDoubleMode.this.f4686o.getHeight();
                Log.i("viewheight1", "height3 =" + height3);
                boolean flag2 = false;
                if (TrafficStatisticsDoubleMode.this.f4668H.getBoolean("traffc_view_height_changed_reset", true) && height3 <= 150) {
                    flag2 = true;
                    TrafficStatisticsDoubleMode.this.f4668H.edit().putBoolean("traffc_view_height_changed_reset", false).commit();
                    TrafficStatisticsDoubleMode.this.f4668H.edit().putInt("traffc_view_height", (height3 * 2) / 3).commit();
                    TrafficStatisticsDoubleMode.this.f4668H.edit().putBoolean("traffc_view_height_changed_flag", true).commit();
                    Log.i("viewheight1", "touch if");
                }
                Log.i("viewheight1", "flag  = " + flag2);
                if (TrafficStatisticsDoubleMode.this.f4668H.getInt("traffc_view_height", -1) == -1) {
                    TrafficStatisticsDoubleMode.this.f4668H.edit().putInt("traffc_view_height", (height3 * 2) / 3).commit();
                    TrafficStatisticsDoubleMode.this.f4668H.edit().putBoolean("traffc_view_height_changed_flag", true).commit();
                    Log.i("viewheight1", "touch if @@@@@@@@");
                }
                TrafficStatisticsDoubleMode.this.f4686o.getViewTreeObserver().removeGlobalOnLayoutListener(this);
            }
        });
        if (TextUtils.isEmpty(this.f4666F.sim1IMSI)) {
            this.f4675d.setText("0.00B");
        } else {
            this.f4675d.setText(Formatter.formatShortFileSize(this, Const.getTodayUsedTraffic()));
        }
        if (TextUtils.isEmpty(this.f4666F.sim2IMSI)) {
            this.f4676e.setText("0.00B");
        } else {
            this.f4676e.setText(Formatter.formatShortFileSize(this, Const.getTodayUsedTraffic2()));
        }
        m1919a();
        m1929d();
        m1920a(this.f4661A, 0);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1919a() {
        this.f4662B = Const.getProgressTrafficMonthUsed();
        this.f4663C = Const.getProgressTrafficMonthUsed2();
        long monthFree1 = Const.getMonthFreeTraffic();
        long monthFree2 = Const.getMonthFreeTraffic2();
        if (this.f4662B < 100) {
            this.f4682k.setTextColor(Color.parseColor("#348213"));
        } else {
            this.f4682k.setTextColor(Color.parseColor("#cd3737"));
        }
        if (this.f4663C < 100) {
            this.f4683l.setTextColor(Color.parseColor("#348213"));
        } else {
            this.f4683l.setTextColor(Color.parseColor("#cd3737"));
        }
        if (this.f4665E == EnumC0781a.card1) {
            m1931e();
        } else {
            m1932f();
        }
        if (monthFree1 >= 0) {
            this.f4682k.setText(Formatter.formatFileSize(this, monthFree1));
        } else {
            this.f4682k.setText("-" + Formatter.formatFileSize(this, -monthFree1));
        }
        if (monthFree2 >= 0) {
            this.f4683l.setText(Formatter.formatFileSize(this, monthFree2));
        } else {
            this.f4683l.setText("-" + Formatter.formatFileSize(this, -monthFree2));
        }
        Log.i("4.0", "Const.getMonthLimitTraffic() =" + Const.getMonthLimitTraffic() + "Const.getMonthLimitTraffic2() =" + Const.getMonthLimitTraffic2() + "Const.getHasNoticed2SetMonthLimit() =" + Const.getHasNoticed2SetMonthLimit());
        if (TextUtils.isEmpty(this.f4664D.sim1IMSI) && TextUtils.isEmpty(this.f4664D.sim2IMSI)) {
            this.f4682k.setTextColor(Color.parseColor("#2c96d6"));
            this.f4682k.setText(C0415R.string.net_simcard_error4);
            this.f4683l.setTextColor(Color.parseColor("#2c96d6"));
            this.f4683l.setText(C0415R.string.net_simcard_error4);
            this.f4695x.setVisibility(8);
            this.f4696y.setVisibility(8);
            this.f4687p.setText(C0415R.string.net_set_traffic_package);
            this.f4681j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_simcard_error3));
            return;
        }
        if (!TextUtils.isEmpty(this.f4664D.sim1IMSI) && !TextUtils.isEmpty(this.f4664D.sim2IMSI)) {
            if ("-1".equals(Const.getMonthLimitTraffic()) && "-1".equals(Const.getMonthLimitTraffic2())) {
                this.f4682k.setTextColor(Color.parseColor("#dc5e2c"));
                this.f4682k.setText("—");
                this.f4683l.setTextColor(Color.parseColor("#dc5e2c"));
                this.f4683l.setText("—");
                this.f4695x.setVisibility(8);
                this.f4696y.setVisibility(8);
                this.f4687p.setText(C0415R.string.net_set_traffic_package);
                this.f4681j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_noti_package_set_des));
                return;
            }
            if ("-1".equals(Const.getMonthLimitTraffic())) {
                this.f4687p.setText(C0415R.string.net_correct_desc);
                this.f4682k.setText(C0415R.string.net_package_des1);
                this.f4682k.setClickable(true);
                this.f4696y.setVisibility(8);
                this.f4695x.setVisibility(0);
                this.f4682k.setOnClickListener(this);
                m1927c();
                return;
            }
            if ("-1".equals(Const.getMonthLimitTraffic2())) {
                this.f4687p.setText(C0415R.string.net_correct_desc);
                this.f4683l.setText(C0415R.string.net_package_des1);
                this.f4683l.setClickable(true);
                this.f4695x.setVisibility(8);
                this.f4696y.setVisibility(0);
                this.f4683l.setOnClickListener(this);
                m1924b();
                return;
            }
            this.f4687p.setText(C0415R.string.net_correct_desc);
            this.f4695x.setVisibility(8);
            this.f4696y.setVisibility(8);
            if (this.f4662B < 90 && this.f4663C < 90) {
                this.f4681j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_notification_mode3));
                return;
            }
            if (this.f4662B >= 90 && this.f4663C >= 90) {
                this.f4681j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_notification_mode4));
                return;
            }
            String formaString = getString(C0415R.string.net_notification_mode5);
            if (this.f4662B >= 90) {
                String finalInfo = getString(C0415R.string.net_mobile) + C0092c.f1283N + String.format(formaString, getString(C0415R.string.net_card1), getString(C0415R.string.net_card2));
                this.f4681j.setText(finalInfo);
                return;
            } else {
                String finalInfo2 = getString(C0415R.string.net_mobile) + C0092c.f1283N + String.format(formaString, getString(C0415R.string.net_card2), getString(C0415R.string.net_card1));
                this.f4681j.setText(finalInfo2);
                return;
            }
        }
        if (TextUtils.isEmpty(this.f4664D.sim1IMSI)) {
            this.f4682k.setTextColor(Color.parseColor("#2c96d6"));
            this.f4682k.setText(C0415R.string.net_simcard_error4);
            if ("-1".equals(Const.getMonthLimitTraffic2())) {
                this.f4683l.setText(C0415R.string.net_package_des1);
                this.f4683l.setClickable(true);
                this.f4695x.setVisibility(8);
                this.f4696y.setVisibility(0);
                this.f4683l.setOnClickListener(this);
                this.f4681j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_notification_mode12));
                this.f4687p.setText(C0415R.string.net_set_traffic_package);
                return;
            }
            this.f4696y.setVisibility(8);
            m1927c();
            this.f4687p.setText(C0415R.string.net_correct_desc);
            return;
        }
        this.f4683l.setTextColor(Color.parseColor("#2c96d6"));
        this.f4683l.setText(C0415R.string.net_simcard_error4);
        if ("-1".equals(Const.getMonthLimitTraffic())) {
            this.f4682k.setText(C0415R.string.net_package_des1);
            this.f4682k.setClickable(true);
            this.f4696y.setVisibility(8);
            this.f4695x.setVisibility(0);
            this.f4682k.setOnClickListener(this);
            this.f4681j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_notification_mode12));
            this.f4687p.setText(C0415R.string.net_set_traffic_package);
            return;
        }
        this.f4695x.setVisibility(8);
        m1924b();
        this.f4687p.setText(C0415R.string.net_correct_desc);
    }

    /* JADX INFO: renamed from: b */
    private void m1924b() {
        if (this.f4662B < 90) {
            this.f4681j.setText(getString(C0415R.string.net_mobile) + ":SIM1" + getString(C0415R.string.net_notification_mode7));
        } else {
            this.f4681j.setText(getString(C0415R.string.net_mobile) + ":SIM1" + getString(C0415R.string.net_notification_mode8));
        }
    }

    /* JADX INFO: renamed from: c */
    private void m1927c() {
        if (this.f4663C < 90) {
            this.f4681j.setText(getString(C0415R.string.net_mobile) + ":SIM2" + getString(C0415R.string.net_notification_mode7));
        } else {
            this.f4681j.setText(getString(C0415R.string.net_mobile) + ":SIM2" + getString(C0415R.string.net_notification_mode8));
        }
    }

    protected void drawDayTrafficIsNotSetup(int cardPostion) {
        this.f4686o.removeAllViews();
        int count = TrafficStatsService.getDayCountInMonth();
        int month = TrafficStatsService.getCurrentMonth();
        int year = TrafficStatsService.getCurrentYear();
        for (int i = 1; i < count; i++) {
            RelativeLayout relativeLayout = new RelativeLayout(this);
            relativeLayout.setLayoutParams(new LinearLayout.LayoutParams(this.f4667G, -1));
            RelativeLayout.LayoutParams re = new RelativeLayout.LayoutParams(-2, -2);
            re.addRule(14, -1);
            re.addRule(12);
            TextView text = new TextView(this);
            text.setId(1);
            text.setPadding(0, 0, 0, 0);
            text.setTextSize(10.0f);
            text.setText(month + "." + i);
            relativeLayout.addView(text, re);
            RelativeLayout li = new RelativeLayout(this);
            li.setBackgroundResource(C0415R.drawable.axis);
            RelativeLayout.LayoutParams ri = new RelativeLayout.LayoutParams(this.f4667G, -1);
            ri.addRule(2, 1);
            TrafficDate trafficDate = cardPostion == 0 ? this.f4684m.get(year + "." + month + "." + i) : this.f4685n.get(year + "." + month + "." + i);
            int height = trafficDate == null ? 0 : trafficDate.height;
            int total = trafficDate == null ? 0 : trafficDate.total;
            RelativeLayout.LayoutParams ri1 = new RelativeLayout.LayoutParams(-2, height);
            ri1.addRule(14, -1);
            ri1.addRule(12);
            ImageView img_green = new ImageView(this);
            img_green.setId(2);
            img_green.setBackgroundResource(C0415R.drawable.fig_histogram_green);
            li.addView(img_green, ri1);
            RelativeLayout.LayoutParams tr = new RelativeLayout.LayoutParams(-2, -2);
            tr.addRule(14, -1);
            tr.addRule(2, 2);
            TextView textTra = new TextView(this);
            textTra.setTextSize(10.0f);
            textTra.setText(TrafficStatsService.formatTraffic(total, this));
            li.addView(textTra, tr);
            relativeLayout.addView(li, ri);
            this.f4686o.addView(relativeLayout);
        }
        this.mHandler.post(this.f4671K);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        Intent intent = getIntent();
        String key = intent.getStringExtra("key");
        Log.i("s3", "key =" + key);
        if ("key".equals(key)) {
            MyUtils.showLeSecNotification(this.f4694w);
        }
        ImageView mNewFeatureIcon = (ImageView) findViewById(C0415R.id.net_app_manager_new_feature_icon);
        if (NewFunctionNoticeManager.hasActionInType(this.f4694w, NewFunctionNoticeManager.TYPE_TRAFFIC_MONITOR, NewFunctionNoticeManager.ACTION_APP_USENET_CONTROL)) {
            mNewFeatureIcon.setVisibility(0);
        } else {
            mNewFeatureIcon.setVisibility(8);
        }
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: d */
    public void m1929d() {
        this.f4697z = TrafficStatsService.getDate();
        if (TextUtils.isEmpty(this.f4666F.sim1IMSI)) {
            this.f4677f.setText("0.00B");
        } else {
            this.f4677f.setText(Formatter.formatFileSize(this, Const.getMonthUsedTraffic()));
        }
        if (TextUtils.isEmpty(this.f4666F.sim2IMSI)) {
            this.f4678g.setText("0.00B");
        } else {
            this.f4678g.setText(Formatter.formatFileSize(this, Const.getMonthUsedTraffic2()));
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1920a(final int postion, final int flag) {
        TrafficStatsService.getExecutorService().execute(new Thread() { // from class: com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    TrafficStatisticsDoubleMode.this.f4693v = TrafficStatsService.getInstance(TrafficStatisticsDoubleMode.this.f4694w);
                    if (TrafficStatisticsDoubleMode.this.f4670J || !TrafficStatisticsDoubleMode.this.f4669I) {
                        Thread.sleep(1000L);
                        TrafficStatisticsDoubleMode.this.f4668H.edit().putBoolean("THREAD_SLEEPED", true).commit();
                        Log.i("viewheight1", "touch sleep");
                    }
                    TrafficStatisticsDoubleMode.this.f4693v.insertDayTrafficDate(TrafficStatisticsDoubleMode.this.f4694w);
                    PhoneSimInfo info = TrafficStatsService.getImsiInfo(TrafficStatisticsDoubleMode.this.f4694w);
                    switch (postion) {
                        case 0:
                            TrafficStatisticsDoubleMode.this.f4684m = TrafficStatisticsDoubleMode.this.f4693v.getDayTrafficInMonth(info.sim1IMSI);
                            TrafficStatisticsDoubleMode.this.mHandler.sendMessage(TrafficStatisticsDoubleMode.this.mHandler.obtainMessage(0));
                            break;
                        case 1:
                            TrafficStatisticsDoubleMode.this.f4685n = TrafficStatisticsDoubleMode.this.f4693v.getDayTrafficInMonth(info.sim2IMSI);
                            TrafficStatisticsDoubleMode.this.mHandler.sendMessage(TrafficStatisticsDoubleMode.this.mHandler.obtainMessage(1));
                            break;
                        case 3:
                            TrafficStatisticsDoubleMode.this.f4684m = TrafficStatisticsDoubleMode.this.f4693v.getDayTrafficInMonth(info.sim1IMSI);
                            TrafficStatisticsDoubleMode.this.mHandler.sendMessage(TrafficStatisticsDoubleMode.this.mHandler.obtainMessage(0));
                            break;
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    Log.i("sqlexception", "touch net sqlexception" + e.getMessage());
                    if (flag == 0) {
                        Message msg = new Message();
                        msg.what = 6;
                        msg.obj = Integer.valueOf(postion);
                        TrafficStatisticsDoubleMode.this.mHandler.sendMessage(msg);
                        return;
                    }
                    TrafficStatisticsDoubleMode.this.finish();
                }
            }
        });
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
            case C0415R.id.title_set /* 2131297710 */:
                Intent mSettingIntent = new Intent(this, (Class<?>) NetSetting.class);
                startActivity(mSettingIntent);
                break;
            case C0415R.id.net_card1_month_free /* 2131297757 */:
                if (this.f4682k.getText().equals(getString(C0415R.string.net_package_des1))) {
                    DoubleCardUtil.showDailog(this, 0, this, C0415R.id.net_card1_month_free);
                } else if (this.f4682k.getText().equals(getString(C0415R.string.net_correct_desc))) {
                    TrafficStatsService.startIntent2TrafficCorrect(0, this, 0);
                }
                break;
            case C0415R.id.net_card2_month_free /* 2131297759 */:
                if (this.f4683l.getText().equals(getString(C0415R.string.net_package_des1))) {
                    DoubleCardUtil.showDailog(this, 1, this, C0415R.id.net_card2_month_free);
                } else if (this.f4683l.getText().equals(getString(C0415R.string.net_correct_desc))) {
                    TrafficStatsService.startIntent2TrafficCorrect(1, this, 0);
                }
                break;
            case C0415R.id.net_set_package /* 2131297761 */:
                if (this.f4687p.getText().equals(getString(C0415R.string.net_set_traffic_package))) {
                    DoubleCardUtil.createSettingNumberDialog(this, this, 6);
                } else if (!WflUtils.isNetworkAvailable(this.f4694w)) {
                    DoubleCardUtil.showSetNetWorkDialog(this.f4694w);
                } else {
                    DoubleCardUtil.showCorrectDialog(this.f4694w);
                }
                break;
            case C0415R.id.net_card1_button /* 2131297762 */:
                this.f4686o.removeAllViews();
                if (this.f4684m != null) {
                    this.mHandler.sendMessage(this.mHandler.obtainMessage(0));
                } else {
                    m1920a(0, 0);
                }
                m1931e();
                break;
            case C0415R.id.net_card2_button /* 2131297763 */:
                this.f4686o.removeAllViews();
                if (this.f4685n != null) {
                    this.mHandler.sendMessage(this.mHandler.obtainMessage(1));
                } else {
                    m1920a(1, 0);
                }
                m1932f();
                break;
            case C0415R.id.net_intent_netfilter /* 2131297766 */:
                NewFunctionNoticeManager.removeActionToType(this.f4694w, NewFunctionNoticeManager.TYPE_TRAFFIC_MONITOR, NewFunctionNoticeManager.ACTION_APP_USENET_CONTROL);
                TrafficStatsService.startIntentNetFilter(this.f4694w);
                break;
        }
    }

    /* JADX INFO: renamed from: e */
    private void m1931e() {
        this.f4679h.setBackgroundResource(C0415R.drawable.net_current_card_selected);
        this.f4680i.setBackgroundResource(C0415R.drawable.net_current_card);
    }

    /* JADX INFO: renamed from: f */
    private void m1932f() {
        this.f4680i.setBackgroundResource(C0415R.drawable.net_current_card_selected);
        this.f4679h.setBackgroundResource(C0415R.drawable.net_current_card);
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogOK(int[] number, int flag) {
        if (Const.SDK_VERSION >= 14 && MyMultiSIMUtils.isMultiSim(this)) {
            if (!TextUtils.isEmpty(this.f4664D.sim1IMSI)) {
                Const.setMonthLimitTraffic(String.valueOf(number[0]));
            }
            if (!TextUtils.isEmpty(this.f4664D.sim2IMSI)) {
                Const.setMonthLimitTraffic2(String.valueOf(number[1]));
            }
        }
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode.5
            @Override // java.lang.Runnable
            public final void run() {
                TrafficStatsService.statsTrafficMobile(TrafficStatisticsDoubleMode.this.f4694w);
                TrafficStatisticsDoubleMode.this.mHandler.sendMessage(TrafficStatisticsDoubleMode.this.mHandler.obtainMessage(5));
            }
        }).start();
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener1
    public void onSettingNumberDialogOK(int number, int id, int postion) {
        if (postion == 0) {
            Const.setMonthLimitTraffic(String.valueOf(number));
        } else {
            Const.setMonthLimitTraffic2(String.valueOf(number));
        }
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode.6
            @Override // java.lang.Runnable
            public final void run() {
                TrafficStatsService.statsTrafficMobile(TrafficStatisticsDoubleMode.this.f4694w);
                TrafficStatisticsDoubleMode.this.mHandler.sendMessage(TrafficStatisticsDoubleMode.this.mHandler.obtainMessage(5));
            }
        }).start();
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener1
    public void onSettingNumberDialogCancel(int number) {
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogCancel(int[] number, int flag) {
    }
}
