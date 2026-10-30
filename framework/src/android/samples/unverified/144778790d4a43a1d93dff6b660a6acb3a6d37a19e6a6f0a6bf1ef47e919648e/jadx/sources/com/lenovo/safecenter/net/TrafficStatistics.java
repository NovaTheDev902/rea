package com.lenovo.safecenter.net;

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
import android.view.animation.DecelerateInterpolator;
import android.view.animation.TranslateAnimation;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.doublemode.DoubleCardUtil;
import com.lenovo.safecenter.net.doublemode.NetSetting;
import com.lenovo.safecenter.net.doublemode.TrafficStatisticsDoubleMode;
import com.lenovo.safecenter.net.support.PhoneSimInfo;
import com.lenovo.safecenter.net.support.TrafficDate;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.NewFunctionNoticeManager;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.HashMap;

/* JADX INFO: loaded from: classes.dex */
public class TrafficStatistics extends Activity implements View.OnClickListener, DoubleCardUtil.SettingNumberDialogListener2 {

    /* JADX INFO: renamed from: A */
    private int f4495A;

    /* JADX INFO: renamed from: a */
    private TranslateAnimation f4497a;

    /* JADX INFO: renamed from: b */
    private ImageView f4498b;

    /* JADX INFO: renamed from: c */
    private ImageView f4499c;

    /* JADX INFO: renamed from: d */
    private ImageView f4500d;

    /* JADX INFO: renamed from: e */
    private ImageView f4501e;

    /* JADX INFO: renamed from: f */
    private TextView f4502f;

    /* JADX INFO: renamed from: g */
    private TextView f4503g;

    /* JADX INFO: renamed from: h */
    private TextView f4504h;

    /* JADX INFO: renamed from: i */
    private TextView f4505i;

    /* JADX INFO: renamed from: j */
    private TextView f4506j;

    /* JADX INFO: renamed from: k */
    private TrafficStatsService f4507k;

    /* JADX INFO: renamed from: l */
    private Context f4508l;

    /* JADX INFO: renamed from: m */
    private HashMap<String, TrafficDate> f4509m;

    /* JADX INFO: renamed from: n */
    private int f4510n;

    /* JADX INFO: renamed from: o */
    private LinearLayout f4511o;

    /* JADX INFO: renamed from: p */
    private HorizontalScrollView f4512p;

    /* JADX INFO: renamed from: q */
    private RelativeLayout f4513q;

    /* JADX INFO: renamed from: r */
    private RelativeLayout f4514r;

    /* JADX INFO: renamed from: s */
    private TextView f4515s;

    /* JADX INFO: renamed from: t */
    private TextView f4516t;

    /* JADX INFO: renamed from: u */
    private TextView f4517u;

    /* JADX INFO: renamed from: v */
    private int f4518v;

    /* JADX INFO: renamed from: w */
    private PhoneSimInfo f4519w;

    /* JADX INFO: renamed from: x */
    private int f4520x;

    /* JADX INFO: renamed from: y */
    private long f4521y;

    /* JADX INFO: renamed from: z */
    private SharedPreferences f4522z;
    public final Handler mHandler = new Handler() { // from class: com.lenovo.safecenter.net.TrafficStatistics.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    TrafficStatistics.m1861a(TrafficStatistics.this);
                    break;
                case 3:
                    NetCache.canCorrect = true;
                    break;
                case 5:
                    TrafficStatistics.this.m1862b();
                    TrafficStatistics.this.m1860a();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: B */
    private Runnable f4496B = new Runnable() { // from class: com.lenovo.safecenter.net.TrafficStatistics.4
        @Override // java.lang.Runnable
        public final void run() {
            int screen_width = TrafficStatistics.this.f4520x * 8;
            if (TrafficStatistics.this.f4510n <= 8 || TrafficStatistics.this.f4510n >= 17) {
                if (TrafficStatistics.this.f4510n <= 16 || TrafficStatistics.this.f4510n >= 25) {
                    if (TrafficStatistics.this.f4510n > 24 && TrafficStatistics.this.f4510n < 32) {
                        TrafficStatistics.this.f4512p.scrollBy(screen_width * 3, 0);
                        if (TrafficStatistics.this.f4512p.getScrollX() == screen_width * 3) {
                            TrafficStatistics.this.mHandler.removeCallbacks(this);
                            return;
                        }
                        return;
                    }
                    return;
                }
                TrafficStatistics.this.f4512p.scrollBy(screen_width * 2, 0);
                if (TrafficStatistics.this.f4512p.getScrollX() == screen_width * 2) {
                    TrafficStatistics.this.mHandler.removeCallbacks(this);
                    return;
                } else {
                    TrafficStatistics.this.mHandler.post(this);
                    return;
                }
            }
            TrafficStatistics.this.f4512p.scrollBy(screen_width, 0);
            if (TrafficStatistics.this.f4512p.getScrollX() == screen_width) {
                TrafficStatistics.this.mHandler.removeCallbacks(this);
            } else {
                TrafficStatistics.this.mHandler.post(this);
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1861a(TrafficStatistics x0) {
        int dayCountInMonth = TrafficStatsService.getDayCountInMonth();
        int currentMonth = TrafficStatsService.getCurrentMonth();
        int currentYear = TrafficStatsService.getCurrentYear();
        for (int i = 1; i < dayCountInMonth; i++) {
            RelativeLayout relativeLayout = new RelativeLayout(x0);
            relativeLayout.setLayoutParams(new LinearLayout.LayoutParams(x0.f4520x, -1));
            RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(-2, -2);
            layoutParams.addRule(14, -1);
            layoutParams.addRule(12);
            TextView textView = new TextView(x0);
            textView.setId(1);
            textView.setPadding(0, 0, 0, 0);
            textView.setTextSize(10.0f);
            textView.setText(currentMonth + "." + i);
            relativeLayout.addView(textView, layoutParams);
            RelativeLayout relativeLayout2 = new RelativeLayout(x0);
            relativeLayout2.setBackgroundResource(C0415R.drawable.axis);
            RelativeLayout.LayoutParams layoutParams2 = new RelativeLayout.LayoutParams(x0.f4520x, -1);
            layoutParams2.addRule(2, 1);
            TrafficDate trafficDate = x0.f4509m.get(currentYear + "." + currentMonth + "." + i);
            int i2 = trafficDate == null ? 0 : trafficDate.height;
            int i3 = trafficDate == null ? 0 : trafficDate.total;
            RelativeLayout.LayoutParams layoutParams3 = new RelativeLayout.LayoutParams(-2, i2);
            layoutParams3.addRule(14, -1);
            layoutParams3.addRule(12);
            ImageView imageView = new ImageView(x0);
            imageView.setId(2);
            imageView.setBackgroundResource(C0415R.drawable.fig_histogram_green);
            relativeLayout2.addView(imageView, layoutParams3);
            RelativeLayout.LayoutParams layoutParams4 = new RelativeLayout.LayoutParams(-2, -2);
            layoutParams4.addRule(14, -1);
            layoutParams4.addRule(2, 2);
            TextView textView2 = new TextView(x0);
            textView2.setTextSize(10.0f);
            textView2.setText(TrafficStatsService.formatTraffic(i3, x0));
            relativeLayout2.addView(textView2, layoutParams4);
            relativeLayout.addView(relativeLayout2, layoutParams2);
            x0.f4511o.addView(relativeLayout);
        }
        x0.mHandler.post(x0.f4496B);
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        if (TrafficStatsService.getTrafficMode(this) == 12) {
            Intent i = new Intent(this, (Class<?>) TrafficStatisticsDoubleMode.class);
            startActivity(i);
            finish();
        }
        super.onCreate(savedInstanceState);
        this.f4520x = (int) NetCache.getTraffic_view_width();
        Log.i("testdip", "width = " + this.f4520x);
        setContentView(C0415R.layout.traffic_statistics_m);
        if (TextUtils.isEmpty(NetCache.imsi)) {
            TrafficStatsService.initNetCache(this);
        }
        this.f4508l = this;
        this.f4522z = PreferenceManager.getDefaultSharedPreferences(this.f4508l);
        if (NetCache.traffic_mode == 10) {
            TrafficStatsService.setMonthLimit(this);
        }
        Intent intent = getIntent();
        String key = intent.getStringExtra("key");
        if ("key".equals(key)) {
            MyUtils.showLeSecNotification(this.f4508l);
        }
        this.f4507k = TrafficStatsService.getInstance(this);
        Const.trafficHandler = this.mHandler;
        this.f4519w = TrafficStatsService.getImsiInfo(this);
        this.f4495A = TrafficStatsService.getTrafficMode(this.f4508l);
        this.f4498b = (ImageView) findViewById(C0415R.id.title_back);
        this.f4499c = (ImageView) findViewById(C0415R.id.title_set);
        this.f4502f = (TextView) findViewById(C0415R.id.txt_title);
        this.f4502f.setText(C0415R.string.net_traffic_control);
        this.f4499c.setVisibility(0);
        this.f4503g = (TextView) findViewById(C0415R.id.net_single_today_used);
        this.f4504h = (TextView) findViewById(C0415R.id.net_single_month_used);
        this.f4505i = (TextView) findViewById(C0415R.id.net_single_month_free);
        this.f4498b.setOnClickListener(this);
        this.f4499c.setOnClickListener(this);
        this.f4511o = (LinearLayout) findViewById(C0415R.id.above_layout);
        this.f4512p = (HorizontalScrollView) findViewById(C0415R.id.scrollView);
        this.f4513q = (RelativeLayout) findViewById(C0415R.id.net_intent_netfilter);
        this.f4513q.setOnClickListener(this);
        this.f4514r = (RelativeLayout) findViewById(C0415R.id.net_single_month_free_parent);
        this.f4506j = (TextView) findViewById(C0415R.id.net_single_notification_text);
        this.f4515s = (TextView) findViewById(C0415R.id.net_single_set_package);
        this.f4515s.setOnClickListener(this);
        this.f4500d = (ImageView) findViewById(C0415R.id.net_traffic_anti);
        this.f4516t = (TextView) findViewById(C0415R.id.net_traffic_free_anti_text);
        this.f4501e = (ImageView) findViewById(C0415R.id.iv2);
        this.f4517u = (TextView) findViewById(C0415R.id.net_month_free_desc);
        this.f4512p.getViewTreeObserver().addOnGlobalLayoutListener(new ViewTreeObserver.OnGlobalLayoutListener() { // from class: com.lenovo.safecenter.net.TrafficStatistics.3
            @Override // android.view.ViewTreeObserver.OnGlobalLayoutListener
            public final void onGlobalLayout() {
                int height3 = TrafficStatistics.this.f4512p.getHeight();
                Log.i("viewheight1", "height3 =" + height3);
                if (!TrafficStatistics.this.f4522z.getBoolean("traffc_view_height_changed", false)) {
                    TrafficStatistics.this.f4522z.edit().putInt("traffc_view_height", (height3 * 2) / 3).commit();
                    TrafficStatistics.this.f4522z.edit().putBoolean("traffc_view_height_changed", true).commit();
                    TrafficStatistics.this.f4522z.edit().putBoolean("traffc_view_height_changed_flag", true).commit();
                    Log.i("viewheight1", "touch if");
                }
                TrafficStatistics.this.f4512p.getViewTreeObserver().removeGlobalOnLayoutListener(this);
            }
        });
        if (TrafficStatsService.getTrafficMode(this) == 10 && TextUtils.isEmpty(this.f4519w.sim1IMSI)) {
            this.f4503g.setText("0.00B");
        } else {
            this.f4503g.setText(Formatter.formatShortFileSize(this, Const.getTodayUsedTraffic()));
        }
        m1862b();
        m1860a();
        TrafficStatsService.getExecutorService().execute(new Thread() { // from class: com.lenovo.safecenter.net.TrafficStatistics.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                TrafficStatistics.this.f4507k.insertDayTrafficDate(TrafficStatistics.this.f4508l);
                int mode = TrafficStatsService.getTrafficMode(TrafficStatistics.this.f4508l);
                if (!TrafficStatistics.this.f4522z.getBoolean("traffc_view_height_changed", false)) {
                    try {
                        Thread.sleep(1000L);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    Log.i("viewheight1", "touch sleep");
                }
                if (mode != 13) {
                    PhoneSimInfo info = TrafficStatsService.getImsiInfo(TrafficStatistics.this.f4508l);
                    TrafficStatistics.this.f4509m = TrafficStatistics.this.f4507k.getDayTrafficInMonth(info.sim1IMSI);
                } else {
                    TrafficStatistics.this.f4509m = TrafficStatistics.this.f4507k.getDayTrafficInMonth("dev");
                }
                TrafficStatistics.this.mHandler.sendMessage(TrafficStatistics.this.mHandler.obtainMessage(0));
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: a */
    public void m1860a() {
        this.f4518v = Const.getProgressTrafficMonthUsed();
        this.f4521y = Const.getMonthFreeTraffic();
        if (this.f4521y < 0) {
            this.f4516t.setVisibility(8);
            this.f4501e.setBackgroundResource(C0415R.drawable.net_traffic_out);
            return;
        }
        this.f4501e.setBackgroundResource(C0415R.drawable.net_traffic_background);
        this.f4516t.setVisibility(0);
        this.f4516t.setText((100 - this.f4518v) + "%");
        float flag = this.f4518v / 100.0f;
        if (flag > 0.8f) {
            flag -= 0.1f;
        }
        this.f4497a = new TranslateAnimation(1, 0.0f, 1, 0.0f, 1, 0.0f, 1, flag);
        this.f4497a.setInterpolator(new DecelerateInterpolator());
        this.f4497a.setFillAfter(true);
        this.f4497a.setDuration(1000L);
        this.f4500d.setAnimation(this.f4497a);
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
            case C0415R.id.net_intent_netfilter /* 2131297766 */:
                NewFunctionNoticeManager.removeActionToType(this.f4508l, NewFunctionNoticeManager.TYPE_TRAFFIC_MONITOR, NewFunctionNoticeManager.ACTION_APP_USENET_CONTROL);
                TrafficStatsService.startIntentNetFilter(this.f4508l);
                break;
            case C0415R.id.net_single_set_package /* 2131297781 */:
                if (this.f4515s.getText().equals(getString(C0415R.string.net_set_traffic_package))) {
                    DoubleCardUtil.createSettingNumberDialog(this, this, 6);
                } else if (this.f4515s.getText().equals(getString(C0415R.string.net_correct_desc))) {
                    if (!WflUtils.isNetworkAvailable(this.f4508l)) {
                        DoubleCardUtil.showSetNetWorkDialog(this.f4508l);
                    } else {
                        TrafficStatsService.startIntent2TrafficCorrect(0, this, 0);
                    }
                }
                break;
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        ImageView mNewFeatureIcon = (ImageView) findViewById(C0415R.id.net_app_manager_new_feature_icon);
        if (NewFunctionNoticeManager.hasActionInType(this.f4508l, NewFunctionNoticeManager.TYPE_TRAFFIC_MONITOR, NewFunctionNoticeManager.ACTION_APP_USENET_CONTROL)) {
            mNewFeatureIcon.setVisibility(0);
        } else {
            mNewFeatureIcon.setVisibility(8);
        }
        TrackEvent.trackResume(this);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: b */
    public void m1862b() {
        if (NetCache.traffic_mode == -1) {
            TrafficStatsService.initNetCache(this);
        }
        this.f4518v = Const.getProgressTrafficMonthUsed();
        this.f4521y = Const.getMonthFreeTraffic();
        Log.i("letrafficui", "progress = " + this.f4518v + ",monthFree1 =" + this.f4521y);
        if (this.f4518v < 100) {
            this.f4505i.setTextColor(Color.parseColor("#348213"));
        } else {
            this.f4505i.setTextColor(Color.parseColor("#cd3737"));
        }
        if (this.f4521y < 0 && !"-1".equals(Const.getMonthLimitTraffic())) {
            this.f4517u.setText(C0415R.string.net_month_out_desc);
        } else {
            this.f4517u.setText(C0415R.string.net_month_free);
        }
        if (TextUtils.isEmpty(this.f4519w.sim1IMSI) && this.f4495A == 10) {
            this.f4505i.setText(C0415R.string.net_simcard_error4);
            this.f4506j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_simcard_error2));
        } else if ("-1".equals(Const.getMonthLimitTraffic())) {
            this.f4515s.setVisibility(0);
            this.f4515s.setText(C0415R.string.net_set_traffic_package);
            this.f4505i.setText("—");
            this.f4505i.setTextColor(Color.parseColor("#dc5e2c"));
            this.f4506j.setText(getString(C0415R.string.net_mobile) + C0092c.f1283N + getString(C0415R.string.net_notification_mode12));
        } else {
            this.f4515s.setVisibility(0);
            this.f4515s.setText(C0415R.string.net_correct_desc);
            this.f4514r.setVisibility(0);
            if (this.f4521y < 0) {
                long tmp = -Const.getMonthFreeTraffic();
                this.f4506j.setText(C0415R.string.net_notification_mode9);
                this.f4505i.setText(Formatter.formatFileSize(this, tmp));
            } else if (this.f4518v < 90) {
                this.f4506j.setText(C0415R.string.net_notification_mode7);
                this.f4505i.setText(Formatter.formatFileSize(this, Const.getMonthFreeTraffic()));
            } else {
                this.f4506j.setText(C0415R.string.net_notification_mode8);
                this.f4505i.setText(Formatter.formatFileSize(this, Const.getMonthFreeTraffic()));
            }
        }
        this.f4510n = TrafficStatsService.getDate();
        if (TrafficStatsService.getTrafficMode(this) != 10 || !TextUtils.isEmpty(this.f4519w.sim1IMSI)) {
            this.f4504h.setText(Formatter.formatFileSize(this, Const.getMonthUsedTraffic()));
        } else {
            this.f4504h.setText("0.00B");
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogOK(int[] number, int flag) {
        if (NetCache.traffic_mode != 10 || !TextUtils.isEmpty(WflUtils.getActiveSubscriberId(this))) {
            Const.setMonthLimitTraffic(String.valueOf(number[0]));
        }
        TrafficStatsService.statsTrafficMobile(this.f4508l);
        this.mHandler.sendMessage(this.mHandler.obtainMessage(5));
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogCancel(int[] number, int flag) {
    }
}
