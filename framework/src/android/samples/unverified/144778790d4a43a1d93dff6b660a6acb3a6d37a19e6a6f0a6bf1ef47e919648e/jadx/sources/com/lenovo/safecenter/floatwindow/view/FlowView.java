package com.lenovo.safecenter.floatwindow.view;

import android.content.Context;
import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.TrafficStats;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.view.ViewStub;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.data.SaveData;
import com.lenovo.safecenter.net.cache.NetCache;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.TrackEvent;
import java.text.DecimalFormat;

/* JADX INFO: loaded from: classes.dex */
public class FlowView extends FrameLayout {

    /* JADX INFO: renamed from: n */
    private static Thread f3641n;

    /* JADX INFO: renamed from: o */
    private static boolean f3642o = true;

    /* JADX INFO: renamed from: p */
    private static long f3643p = 0;

    /* JADX INFO: renamed from: a */
    Handler f3644a;

    /* JADX INFO: renamed from: b */
    Runnable f3645b;

    /* JADX INFO: renamed from: c */
    private Context f3646c;

    /* JADX INFO: renamed from: d */
    private TextView f3647d;

    /* JADX INFO: renamed from: e */
    private ImageView f3648e;

    /* JADX INFO: renamed from: f */
    private FrameLayout f3649f;

    /* JADX INFO: renamed from: g */
    private FrameLayout f3650g;

    /* JADX INFO: renamed from: h */
    private ViewStub f3651h;

    /* JADX INFO: renamed from: i */
    private ImageView f3652i;

    /* JADX INFO: renamed from: j */
    private long f3653j;

    /* JADX INFO: renamed from: k */
    private long f3654k;

    /* JADX INFO: renamed from: l */
    private Drawable f3655l;

    /* JADX INFO: renamed from: m */
    private ProgressBar f3656m;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ String m1529a(FlowView x0) {
        String str;
        long j = x0.f3654k - x0.f3653j;
        long j2 = j > 0 ? j / 3 : 0L;
        int dataCardPosition = TrafficStatsService.getDataCardPosition(x0.f3646c);
        if (dataCardPosition != -1) {
            if (dataCardPosition == 0) {
                if (NetCache.getTraffic_used_progress() >= 100) {
                    x0.f3656m.setProgress(100);
                } else {
                    x0.f3656m.setProgress(0);
                }
            } else if (dataCardPosition != 1 || NetCache.getTraffic_used_progress2() < 100) {
                x0.f3656m.setProgress(0);
            } else {
                x0.f3656m.setProgress(100);
            }
        }
        StringBuilder sb = new StringBuilder();
        DecimalFormat decimalFormat = new DecimalFormat("0");
        if (j2 > Math.pow(1024.0d, 4.0d)) {
            str = decimalFormat.format((((j2 / 1024.0f) / 1024.0f) / 1024.0f) / 1024.0f) + "T";
        } else if (j2 > Math.pow(1024.0d, 3.0d)) {
            str = decimalFormat.format(((j2 / 1024.0f) / 1024.0f) / 1024.0f) + "G";
        } else if (j2 > 1048576) {
            str = decimalFormat.format((j2 / 1024.0f) / 1024.0f) + "M";
        } else {
            str = j2 > 1024 ? decimalFormat.format(j2 / 1024.0f) + "K" : j2 + "B";
        }
        sb.append(str);
        sb.append("/S");
        return sb.toString();
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ Thread m1535c() {
        f3641n = null;
        return null;
    }

    public FlowView(Context context) {
        super(context);
        this.f3644a = new Handler() { // from class: com.lenovo.safecenter.floatwindow.view.FlowView.1
            @Override // android.os.Handler
            public final void handleMessage(Message msg) {
                switch (msg.what) {
                    case 0:
                        FlowView.this.f3653j = TrafficStats.getTotalRxBytes() + TrafficStats.getTotalTxBytes();
                        postDelayed(FlowView.this.f3645b, C0092c.f1328ap);
                        break;
                    case 1:
                        FlowView.this.f3647d.setText(FlowView.m1529a(FlowView.this));
                        FlowView.this.f3644a.sendEmptyMessage(0);
                        break;
                    case 3:
                        if (FlowView.this.f3650g.getVisibility() == 0) {
                            FlowView.this.f3650g.setVisibility(8);
                        }
                        FlowView.this.f3652i.setImageDrawable(FlowView.this.f3655l);
                        break;
                }
            }
        };
        this.f3645b = new Runnable() { // from class: com.lenovo.safecenter.floatwindow.view.FlowView.2
            @Override // java.lang.Runnable
            public final void run() {
                FlowView.this.f3654k = TrafficStats.getTotalRxBytes() + TrafficStats.getTotalTxBytes();
                String rate = FlowView.m1529a(FlowView.this);
                FlowView.this.f3647d.setText(rate);
                FlowView.this.f3644a.sendEmptyMessage(0);
            }
        };
        this.f3646c = context;
        inflate(this.f3646c, C0415R.layout.assist_flow_content, this);
        this.f3647d = (TextView) findViewById(C0415R.id.float_window_flow);
        this.f3648e = (ImageView) findViewById(C0415R.id.flow_window_interruption_free);
        this.f3651h = (ViewStub) findViewById(C0415R.id.flow_window_dialog_viewstub);
        this.f3650g = (FrameLayout) findViewById(C0415R.id.flow_window_interruption_free_container);
        this.f3649f = (FrameLayout) findViewById(C0415R.id.layout_flow_main);
        this.f3652i = (ImageView) findViewById(C0415R.id.flow_window_icon_status_net);
        this.f3656m = (ProgressBar) findViewById(C0415R.id.float_window_progress);
        this.f3648e.setOnClickListener(new ViewOnClickListenerC0570a(this, (byte) 0));
    }

    public void setFlowDrawable(int status) {
        if (status == 1) {
            this.f3652i.setImageResource(C0415R.drawable.assist_flow_wifi);
        } else {
            this.f3652i.setImageResource(C0415R.drawable.assist_flow_mobile);
        }
    }

    public void sendHanderMessage() {
        this.f3644a.sendEmptyMessage(1);
    }

    public void removeHanderMessage() {
        this.f3644a.removeMessages(0);
    }

    public void setViewGone() {
        if (this.f3651h.getVisibility() == 0) {
            this.f3651h.setVisibility(8);
            this.f3649f.setVisibility(0);
            this.f3650g.setVisibility(8);
        }
    }

    public class FlowWindowListener implements View.OnClickListener {
        public FlowWindowListener() {
        }

        @Override // android.view.View.OnClickListener
        public void onClick(View v) {
            if (FlowView.this.f3650g.getVisibility() == 0) {
                FlowView.this.f3650g.setVisibility(8);
            } else {
                FlowView.this.f3650g.setVisibility(0);
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.floatwindow.view.FlowView$a */
    private class ViewOnClickListenerC0570a implements View.OnClickListener {
        private ViewOnClickListenerC0570a() {
        }

        /* synthetic */ ViewOnClickListenerC0570a(FlowView x0, byte b) {
            this();
        }

        @Override // android.view.View.OnClickListener
        public final void onClick(View v) {
            FlowView.this.f3649f.setVisibility(8);
            FlowView.this.f3651h.setVisibility(0);
            TextView text_float_dialog_msg = (TextView) FlowView.this.findViewById(C0415R.id.float_dialog_msg);
            CheckBox float_checkbox = (CheckBox) FlowView.this.findViewById(C0415R.id.float_checkbox);
            Button float_btn_left = (Button) FlowView.this.findViewById(C0415R.id.float_btn_left);
            Button float_btn_right = (Button) FlowView.this.findViewById(C0415R.id.float_btn_right);
            text_float_dialog_msg.setText(FlowView.this.f3646c.getResources().getString(C0415R.string.float_window_dialog_msg_disable));
            float_checkbox.setVisibility(8);
            float_btn_left.setText(FlowView.this.getResources().getString(C0415R.string.ok));
            float_btn_right.setText(FlowView.this.getResources().getString(C0415R.string.cancel));
            float_btn_left.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.floatwindow.view.FlowView.a.1
                @Override // android.view.View.OnClickListener
                public final void onClick(View v2) {
                    FlowView.this.f3651h.setVisibility(8);
                    FlowView.this.f3650g.setVisibility(8);
                    FlowView.this.f3649f.setVisibility(0);
                    if (SecurityService.instance != null) {
                        SecurityService.instance.setFlowVisibility(8);
                    }
                    SaveData.save_flow_status(FlowView.this.f3646c, false);
                    TrackEvent.reportCloseTrafficFloatwindow();
                    Intent i = new Intent();
                    i.setAction("com.lenovo.safecenter.flowrefresh");
                    FlowView.this.f3646c.sendBroadcast(i);
                }
            });
            float_btn_right.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.floatwindow.view.FlowView.a.2
                @Override // android.view.View.OnClickListener
                public final void onClick(View v2) {
                    FlowView.this.setViewGone();
                    ConnectivityManager conectivityManager = (ConnectivityManager) FlowView.this.f3646c.getSystemService("connectivity");
                    if (conectivityManager.getActiveNetworkInfo() == null || conectivityManager.getActiveNetworkInfo().getState() != NetworkInfo.State.CONNECTED) {
                        FlowView.this.f3652i.setImageDrawable(FlowView.this.f3655l);
                    } else {
                        int type = conectivityManager.getActiveNetworkInfo().getType();
                        FlowView.this.setFlowDrawable(type);
                    }
                    TrackEvent.reportCloseTrafficFloatwindow();
                }
            });
        }
    }

    public void setOnclickContent() {
        if (this.f3650g.getVisibility() == 0) {
            this.f3652i.setImageDrawable(this.f3655l);
            this.f3650g.setVisibility(8);
            return;
        }
        this.f3655l = this.f3652i.getDrawable();
        this.f3652i.setImageResource(C0415R.drawable.atat_safe_icon);
        this.f3650g.setVisibility(0);
        if (f3641n == null) {
            f3641n = new Thread() { // from class: com.lenovo.safecenter.floatwindow.view.FlowView.3
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    try {
                        long unused = FlowView.f3643p = System.currentTimeMillis();
                        while (FlowView.f3642o) {
                            Thread.sleep(100L);
                            if (System.currentTimeMillis() - FlowView.f3643p > 2000) {
                                break;
                            }
                        }
                        FlowView.m1535c();
                        FlowView.this.f3644a.sendMessage(FlowView.this.f3644a.obtainMessage(3));
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };
            f3641n.start();
        } else {
            f3643p = System.currentTimeMillis();
        }
    }
}
