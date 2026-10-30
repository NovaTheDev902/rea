package com.lenovo.safecenter.net;

import android.app.Activity;
import android.net.ConnectivityManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.cache.NetConstant;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class TrafficDailog extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: n */
    private static boolean f4473n = false;

    /* JADX INFO: renamed from: a */
    private int f4474a;

    /* JADX INFO: renamed from: b */
    private int f4475b;

    /* JADX INFO: renamed from: e */
    private ConnectivityManager f4478e;

    /* JADX INFO: renamed from: g */
    private TextView f4480g;

    /* JADX INFO: renamed from: h */
    private TextView f4481h;

    /* JADX INFO: renamed from: i */
    private TextView f4482i;

    /* JADX INFO: renamed from: j */
    private LinearLayout f4483j;

    /* JADX INFO: renamed from: k */
    private String f4484k;

    /* JADX INFO: renamed from: l */
    private String f4485l;

    /* JADX INFO: renamed from: m */
    private String f4486m;

    /* JADX INFO: renamed from: c */
    private int f4476c = 0;

    /* JADX INFO: renamed from: d */
    private final int f4477d = 20;

    /* JADX INFO: renamed from: f */
    private Handler f4479f = new Handler() { // from class: com.lenovo.safecenter.net.TrafficDailog.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case C0415R.id.net_deny /* 2131297303 */:
                    TrafficDailog.this.f4481h.setText(String.format(TrafficDailog.this.getString(C0415R.string.net_traffic_deny_text), Integer.valueOf(20 - TrafficDailog.this.f4476c)));
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: c */
    static /* synthetic */ int m1855c(TrafficDailog x0) {
        int i = x0.f4476c;
        x0.f4476c = i + 1;
        return i;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.net_traffic_anto_deny_notice);
        this.f4478e = (ConnectivityManager) getSystemService("connectivity");
        this.f4474a = getIntent().getIntExtra(NetConstant.SIM_CARD_POSTION, 0);
        this.f4475b = TrafficStatsService.getTrafficMode(this);
        this.f4485l = getString(C0415R.string.net_traffic_anto_deny_summary);
        this.f4486m = getString(C0415R.string.net_traffic_phone_sim);
        if (this.f4474a != 0) {
            this.f4484k = String.format(this.f4485l, this.f4486m + DatabaseTables.USER_MARK);
        } else if (this.f4475b != 12) {
            this.f4484k = String.format(this.f4485l, "");
        } else {
            this.f4484k = String.format(this.f4485l, this.f4486m + DatabaseTables.SYSTEM_MARK);
        }
        this.f4483j = (LinearLayout) findViewById(C0415R.id.net_traffic_notice_check_parent);
        this.f4483j.setVisibility(8);
        this.f4480g = (TextView) findViewById(C0415R.id.continue_to_use);
        this.f4481h = (TextView) findViewById(C0415R.id.net_deny);
        this.f4482i = (TextView) findViewById(C0415R.id.des);
        this.f4481h.setText(String.format(getString(C0415R.string.net_traffic_deny_text), 20));
        this.f4482i.setText(this.f4484k);
        this.f4480g.setOnClickListener(this);
        this.f4481h.setOnClickListener(this);
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.net.TrafficDailog$2] */
    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        new Thread() { // from class: com.lenovo.safecenter.net.TrafficDailog.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                while (TrafficDailog.this.f4476c < 20) {
                    try {
                        Thread.sleep(1000L);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    TrafficDailog.m1855c(TrafficDailog.this);
                    TrafficDailog.this.f4479f.sendMessage(TrafficDailog.this.f4479f.obtainMessage(C0415R.id.net_deny));
                    if (TrafficStatsService.getBackValue() != -1) {
                        return;
                    }
                }
                if (TrafficStatsService.getBackValue() == -1) {
                    TrafficStatsService.setBackValue(1);
                    if (!TrafficDailog.f4473n) {
                        TrafficDailog.this.f4478e.setMobileDataEnabled(false);
                    }
                    TrafficDailog.this.finish();
                }
            }
        }.start();
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.continue_to_use /* 2131297302 */:
                f4473n = true;
                TrackEvent.reportUserActionClickContinueUseInTrafficOutLimitDisableNet();
                break;
            case C0415R.id.net_deny /* 2131297303 */:
                f4473n = false;
                this.f4478e.setMobileDataEnabled(false);
                TrackEvent.reportUserActionClickDisableNetInTrafficOutLimitDisableNet();
                break;
        }
        finish();
    }
}
