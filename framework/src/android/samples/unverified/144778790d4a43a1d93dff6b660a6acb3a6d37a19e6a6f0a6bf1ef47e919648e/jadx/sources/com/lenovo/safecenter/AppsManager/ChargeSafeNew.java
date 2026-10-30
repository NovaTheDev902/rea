package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.NewLogsAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.CallUtil;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.SmsUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import java.util.List;
import java.util.Observable;
import java.util.Observer;

/* JADX INFO: loaded from: classes.dex */
public class ChargeSafeNew extends Activity implements View.OnClickListener, Observer {

    /* JADX INFO: renamed from: a */
    private LeSafeObservable f2135a;

    /* JADX INFO: renamed from: b */
    private List<SafeLog> f2136b;

    /* JADX INFO: renamed from: c */
    private TextView f2137c;

    /* JADX INFO: renamed from: d */
    private TextView f2138d;

    /* JADX INFO: renamed from: e */
    private TextView f2139e;

    /* JADX INFO: renamed from: f */
    private TextView f2140f;

    /* JADX INFO: renamed from: g */
    private TextView f2141g;

    /* JADX INFO: renamed from: h */
    private ListView f2142h;

    /* JADX INFO: renamed from: i */
    private ImageView f2143i;

    /* JADX INFO: renamed from: j */
    private ImageView f2144j;

    /* JADX INFO: renamed from: k */
    private LinearLayout f2145k;

    /* JADX INFO: renamed from: l */
    private RelativeLayout f2146l;

    /* JADX INFO: renamed from: m */
    private RelativeLayout f2147m;

    /* JADX INFO: renamed from: n */
    private RelativeLayout f2148n;

    /* JADX INFO: renamed from: o */
    private RelativeLayout f2149o;

    /* JADX INFO: renamed from: q */
    private boolean f2151q;

    /* JADX INFO: renamed from: p */
    private int f2150p = 0;

    /* JADX INFO: renamed from: r */
    private Handler f2152r = new Handler() { // from class: com.lenovo.safecenter.AppsManager.ChargeSafeNew.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    ChargeSafeNew.this.f2141g.setText(String.format(ChargeSafeNew.this.getString(C0415R.string.trust_app_num), Integer.valueOf(ChargeSafeNew.this.f2150p)));
                    if (ChargeSafeNew.this.f2136b.size() == 0) {
                        ChargeSafeNew.this.f2138d.setVisibility(0);
                        ChargeSafeNew.this.f2146l.setVisibility(8);
                    } else {
                        ChargeSafeNew.this.f2138d.setVisibility(8);
                        ChargeSafeNew.this.f2146l.setVisibility(0);
                        ChargeSafeNew.this.f2142h.setAdapter((ListAdapter) new NewLogsAdapter(ChargeSafeNew.this, ChargeSafeNew.this.f2136b));
                    }
                    break;
                case 1:
                    ChargeSafeNew.this.f2141g.setText(String.format(ChargeSafeNew.this.getString(C0415R.string.trust_app_num), Integer.valueOf(ChargeSafeNew.this.f2150p)));
                    break;
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.chargesafe);
        this.f2151q = WflUtils.isRoot();
        this.f2137c = (TextView) findViewById(C0415R.id.txt_title);
        this.f2137c.setText(C0415R.string.charge_safe);
        this.f2138d = (TextView) findViewById(C0415R.id.txt_empty);
        this.f2142h = (ListView) findViewById(C0415R.id.listView);
        this.f2142h.setEnabled(false);
        this.f2143i = (ImageView) findViewById(C0415R.id.title_back);
        this.f2144j = (ImageView) findViewById(C0415R.id.title_set);
        this.f2144j.setVisibility(0);
        this.f2145k = (LinearLayout) findViewById(C0415R.id.more_logs);
        this.f2139e = (TextView) findViewById(C0415R.id.this_month_use_send_sms_num);
        this.f2140f = (TextView) findViewById(C0415R.id.this_month_use_call_duration);
        this.f2141g = (TextView) findViewById(C0415R.id.trustapps_text);
        m893a();
        m895b();
        this.f2146l = (RelativeLayout) findViewById(C0415R.id.logs_layout);
        this.f2147m = (RelativeLayout) findViewById(C0415R.id.sendmsg_layout);
        this.f2148n = (RelativeLayout) findViewById(C0415R.id.call_layout);
        this.f2149o = (RelativeLayout) findViewById(C0415R.id.trustapp_layout);
        this.f2143i.setOnClickListener(this);
        this.f2144j.setOnClickListener(this);
        this.f2145k.setOnClickListener(this);
        this.f2147m.setOnClickListener(this);
        this.f2148n.setOnClickListener(this);
        this.f2149o.setOnClickListener(this);
        this.f2135a = LeSafeObservable.get(getApplicationContext());
        this.f2135a.addObserver(this);
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.AppsManager.ChargeSafeNew.2
            @Override // java.lang.Runnable
            public final void run() {
                SmsUtil.statisticsSmsSent(ChargeSafeNew.this);
                CallUtil.statisticsCallDurationByType(ChargeSafeNew.this);
            }
        }).start();
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.AppsManager.ChargeSafeNew$3] */
    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        new Thread() { // from class: com.lenovo.safecenter.AppsManager.ChargeSafeNew.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                AppDatabase database = new AppDatabase(ChargeSafeNew.this);
                if (Const.getScreenHeight() > 800) {
                    ChargeSafeNew.this.f2136b = database.getTopThreeLogs(AppDatabase.DB_LOG_TARIFF, 4);
                } else {
                    ChargeSafeNew.this.f2136b = database.getTopThreeLogs(AppDatabase.DB_LOG_TARIFF, 3);
                }
                if (ChargeSafeNew.this.f2151q) {
                    ChargeSafeNew.this.f2150p = database.getTrustedApps(AppDatabase.DB_APP_SENDMESSAGE);
                }
                ChargeSafeNew.this.f2152r.sendMessage(ChargeSafeNew.this.f2152r.obtainMessage(0));
            }
        }.start();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.call_layout /* 2131296765 */:
                Intent it2 = new Intent(this, (Class<?>) ApplicationList.class);
                it2.putExtra("permType", AppDatabase.DB_APP_CALL);
                startActivity(it2);
                break;
            case C0415R.id.sendmsg_layout /* 2131296880 */:
                Intent it1 = new Intent(this, (Class<?>) MessageBlackList.class);
                startActivity(it1);
                break;
            case C0415R.id.trustapp_layout /* 2131296883 */:
                Intent it = new Intent(this, (Class<?>) AppsManager.class);
                it.putExtra("permType", AppDatabase.DB_APP_SENDMESSAGE);
                startActivityForResult(it, 0);
                break;
            case C0415R.id.more_logs /* 2131296887 */:
                Intent it0 = new Intent(this, (Class<?>) DisplayLog.class);
                it0.putExtra("from", "0");
                startActivityForResult(it0, 1);
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
            case C0415R.id.title_set /* 2131297710 */:
                startActivity(new Intent(this, (Class<?>) SmsSettingsActivity.class));
                break;
        }
    }

    @Override // android.app.Activity
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        switch (resultCode) {
            case 1:
                this.f2136b.clear();
                this.f2152r.sendMessage(this.f2152r.obtainMessage(0));
                break;
        }
    }

    /* JADX INFO: renamed from: a */
    private void m893a() {
        try {
            int usedMonthSmsNum = Const.getSmsSendNumCurrMonth();
            int monthLimit = Const.getMonthLimitSMS();
            String monthusedDecribe = getString(C0415R.string.thismonth_send_sms_num) + usedMonthSmsNum + getString(C0415R.string.article) + "\n";
            if (monthLimit == 0) {
                this.f2139e.setText(monthusedDecribe + getString(C0415R.string.no_sms_package));
            } else if (usedMonthSmsNum > monthLimit) {
                String decribe = monthusedDecribe + getString(C0415R.string.exceed_text) + (usedMonthSmsNum - monthLimit) + getString(C0415R.string.article);
                SpannableString spannable = new SpannableString(decribe);
                spannable.setSpan(new ForegroundColorSpan(-65536), monthusedDecribe.length(), decribe.length(), 0);
                this.f2139e.setText(spannable);
            } else {
                this.f2139e.setText(monthusedDecribe + getString(C0415R.string.remaining_text) + (monthLimit - usedMonthSmsNum) + getString(C0415R.string.article));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /* JADX INFO: renamed from: b */
    private void m895b() {
        try {
            int callIncommingDuration = Const.getCallIncommingDurationCurrMonth();
            int callOutgoingDuration = Const.getCallOutgoingDurationCurrMonth();
            this.f2140f.setText(getString(C0415R.string.outgoing_call) + WflUtils.convertTimeFormat(this, callOutgoingDuration) + "\n" + getString(C0415R.string.answer_call) + WflUtils.convertTimeFormat(this, callIncommingDuration));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override // java.util.Observer
    public void update(Observable observable, Object data) {
        if (data instanceof Integer) {
            switch (((Integer) data).intValue()) {
                case 3:
                    m893a();
                    break;
                case 4:
                    m895b();
                    break;
            }
        }
    }
}
