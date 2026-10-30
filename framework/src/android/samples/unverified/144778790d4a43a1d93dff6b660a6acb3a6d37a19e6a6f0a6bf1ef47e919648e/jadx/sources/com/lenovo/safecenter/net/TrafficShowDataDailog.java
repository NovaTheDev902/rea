package com.lenovo.safecenter.net;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class TrafficShowDataDailog extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private TextView f4489a;

    /* JADX INFO: renamed from: b */
    private TextView f4490b;

    /* JADX INFO: renamed from: c */
    private TextView f4491c;

    /* JADX INFO: renamed from: d */
    private TextView f4492d;

    /* JADX INFO: renamed from: e */
    private ImageView f4493e;

    /* JADX INFO: renamed from: f */
    private boolean f4494f;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.net_traffic_anto_deny_notice);
        this.f4494f = TrafficStatsService.getTrafficDaliogNoticeValue(this);
        this.f4489a = (TextView) findViewById(C0415R.id.continue_to_use);
        this.f4490b = (TextView) findViewById(C0415R.id.net_deny);
        this.f4491c = (TextView) findViewById(C0415R.id.net_traffic_dailog_title);
        this.f4492d = (TextView) findViewById(C0415R.id.des);
        this.f4491c.setText(C0415R.string.net_traffic_show_data_noti_title);
        this.f4490b.setText(C0415R.string.net_traffic_lookup);
        this.f4489a.setText(C0415R.string.net_traffic_ignore);
        this.f4492d.setText(C0415R.string.net_traffic_show_data_noti_summary);
        this.f4493e = (ImageView) findViewById(C0415R.id.net_traffic_notice_check);
        m1858a();
        this.f4489a.setOnClickListener(this);
        this.f4490b.setOnClickListener(this);
        this.f4493e.setOnClickListener(this);
    }

    /* JADX INFO: renamed from: a */
    private void m1858a() {
        this.f4493e.setBackgroundResource(this.f4494f ? C0415R.drawable.ic_checkbox_select : C0415R.drawable.ic_checkbox);
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.net_traffic_notice_check /* 2131297300 */:
                this.f4494f = !this.f4494f;
                m1858a();
                TrafficStatsService.setTrafficDaliogNoticeValue(this, this.f4494f);
                TrackEvent.reportUserActionClickNotPromptPopupTrafficUsedStatus();
                break;
            case C0415R.id.continue_to_use /* 2131297302 */:
                TrackEvent.reportUserActionClickIgnorePopupTrafficUsedStatus();
                finish();
                break;
            case C0415R.id.net_deny /* 2131297303 */:
                TrafficStatsService.startIntentTraffic(this);
                TrackEvent.reportUserActionClickLookPopupTrafficUsedStatus();
                finish();
                break;
        }
    }
}
