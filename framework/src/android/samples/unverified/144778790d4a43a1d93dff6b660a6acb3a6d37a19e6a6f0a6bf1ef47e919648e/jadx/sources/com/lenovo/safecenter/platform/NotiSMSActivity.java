package com.lenovo.safecenter.platform;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.KeyEvent;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.MyUtils;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class NotiSMSActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private String f4967a;

    /* JADX INFO: renamed from: b */
    private String f4968b;

    /* JADX INFO: renamed from: c */
    private String f4969c;

    /* JADX INFO: renamed from: d */
    private String f4970d;

    /* JADX INFO: renamed from: e */
    private String f4971e;

    /* JADX INFO: renamed from: f */
    private String f4972f;

    /* JADX INFO: renamed from: g */
    private PackageManager f4973g;

    /* JADX INFO: renamed from: h */
    private Context f4974h;

    /* JADX INFO: renamed from: i */
    private AppDatabase f4975i;

    /* JADX INFO: renamed from: j */
    private ProgressBar f4976j;

    /* JADX INFO: renamed from: n */
    private TextView f4980n;

    /* JADX INFO: renamed from: k */
    private long f4977k = System.currentTimeMillis();

    /* JADX INFO: renamed from: l */
    private int f4978l = 0;

    /* JADX INFO: renamed from: m */
    private int f4979m = 10;

    /* JADX INFO: renamed from: o */
    private Handler f4981o = new Handler() { // from class: com.lenovo.safecenter.platform.NotiSMSActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    NotiSMSActivity.this.finish();
                    Toast.makeText(NotiSMSActivity.this, C0415R.string.upsuccess, 0).show();
                    break;
                case 1:
                    NotiSMSActivity.this.finish();
                    Toast.makeText(NotiSMSActivity.this, C0415R.string.neterror, 0).show();
                    break;
                case 3:
                    NotiSMSActivity.this.finish();
                    break;
                case 4:
                    NotiSMSActivity.this.finish();
                    Toast.makeText(NotiSMSActivity.this, NotiSMSActivity.this.getString(C0415R.string.net_notavilable), 0).show();
                    break;
                case 5:
                    Toast.makeText(NotiSMSActivity.this, NotiSMSActivity.this.getString(C0415R.string.phonenum_null), 0).show();
                    break;
                case 6:
                    Toast.makeText(NotiSMSActivity.this, NotiSMSActivity.this.getString(C0415R.string.sms_content_null), 0).show();
                    break;
                case 7:
                    NotiSMSActivity.this.f4980n.setText(String.format(NotiSMSActivity.this.getString(C0415R.string.send_off2), Integer.valueOf(NotiSMSActivity.this.f4979m - NotiSMSActivity.this.f4978l)));
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: d */
    static /* synthetic */ int m2055d(NotiSMSActivity x0) {
        int i = x0.f4978l;
        x0.f4978l = i + 1;
        return i;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.noti_sms);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        this.f4973g = getPackageManager();
        this.f4974h = this;
        this.f4975i = new AppDatabase(this);
        Intent smsIntent = getIntent();
        this.f4971e = smsIntent.getStringExtra(DatabaseTables.LOG_MESSAGE);
        this.f4967a = smsIntent.getStringExtra("phoneNumber");
        this.f4968b = smsIntent.getStringExtra(AppDatabase.CONTENT);
        this.f4969c = smsIntent.getStringExtra("packageName");
        this.f4972f = smsIntent.getStringExtra("valueName");
        ImageView imageView = (ImageView) findViewById(C0415R.id.app_icon_sms);
        TextView textView = (TextView) findViewById(C0415R.id.app_name_sms);
        TextView textView2 = (TextView) findViewById(C0415R.id.des);
        EditText editText = (EditText) findViewById(C0415R.id.smscontent);
        final TextView textView3 = (TextView) findViewById(C0415R.id.send);
        final TextView textView4 = (TextView) findViewById(C0415R.id.unsend_report);
        this.f4976j = (ProgressBar) findViewById(C0415R.id.noti_progress);
        this.f4980n = (TextView) findViewById(C0415R.id.unsend);
        this.f4980n.setText(String.format(getString(C0415R.string.send_off2), Integer.valueOf(this.f4979m)));
        if (this.f4969c == null) {
            this.f4970d = getText(C0415R.string.unknownapp).toString();
            imageView.setBackgroundResource(C0415R.drawable.icon3);
        } else {
            try {
                this.f4970d = this.f4973g.getApplicationInfo(this.f4969c, 0).loadLabel(this.f4973g).toString();
                imageView.setBackgroundDrawable(this.f4973g.getApplicationIcon(this.f4969c));
                if (this.f4975i.getApp_isupload(this.f4969c) == 1) {
                    textView4.setText(C0415R.string.hadupload_log);
                    textView4.setEnabled(false);
                } else {
                    textView4.setText(C0415R.string.report);
                    textView4.setEnabled(true);
                }
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
        }
        textView.setText(this.f4970d);
        textView2.setText(this.f4971e);
        editText.setText(getString(C0415R.string.smscontent) + this.f4968b);
        View.OnClickListener onClickListener = new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.NotiSMSActivity.3
            /* JADX WARN: Type inference failed for: r0v10, types: [com.lenovo.safecenter.platform.NotiSMSActivity$3$1] */
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                textView3.setEnabled(false);
                NotiSMSActivity.this.f4980n.setEnabled(false);
                textView4.setEnabled(false);
                switch (v.getId()) {
                    case C0415R.id.send /* 2131297347 */:
                        SafeCenterService.setBackValue(NotiSMSActivity.this.f4972f, 0);
                        NotiSMSActivity.this.finish();
                        break;
                    case C0415R.id.unsend /* 2131297348 */:
                        SafeCenterService.setBackValue(NotiSMSActivity.this.f4972f, 1);
                        NotiSMSActivity.this.finish();
                        break;
                    case C0415R.id.unsend_report /* 2131297349 */:
                        if (SafeCenterService.getBackValue(NotiSMSActivity.this.f4972f) == -1) {
                            SafeCenterService.setBackValue(NotiSMSActivity.this.f4972f, 1);
                        }
                        NotiSMSActivity.this.f4976j.setVisibility(0);
                        new Thread() { // from class: com.lenovo.safecenter.platform.NotiSMSActivity.3.1
                            @Override // java.lang.Thread, java.lang.Runnable
                            public final void run() {
                                if (HttpUtils.reportTariffLog(NotiSMSActivity.this.f4974h, NotiSMSActivity.this.f4969c, "0", NotiSMSActivity.this.f4970d, MyUtils.formatReportTime(Long.toString(NotiSMSActivity.this.f4977k), NotiSMSActivity.this.f4974h), NotiSMSActivity.this.f4967a, NotiSMSActivity.this.f4968b) == 2) {
                                    NotiSMSActivity.this.f4975i.updateApp_isupload(NotiSMSActivity.this.f4969c, 1);
                                    NotiSMSActivity.this.f4981o.sendMessage(NotiSMSActivity.this.f4981o.obtainMessage(0));
                                } else {
                                    NotiSMSActivity.this.f4981o.sendMessage(NotiSMSActivity.this.f4981o.obtainMessage(1));
                                }
                            }
                        }.start();
                        break;
                }
            }
        };
        textView3.setOnClickListener(onClickListener);
        this.f4980n.setOnClickListener(onClickListener);
        textView4.setOnClickListener(onClickListener);
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        TrackEvent.trackPause(this);
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.platform.NotiSMSActivity$2] */
    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
        new Thread() { // from class: com.lenovo.safecenter.platform.NotiSMSActivity.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                while (NotiSMSActivity.this.f4978l < NotiSMSActivity.this.f4979m) {
                    try {
                        Thread.sleep(1000L);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    NotiSMSActivity.m2055d(NotiSMSActivity.this);
                    NotiSMSActivity.this.f4981o.sendMessage(NotiSMSActivity.this.f4981o.obtainMessage(7));
                    if (SafeCenterService.getBackValue(NotiSMSActivity.this.f4972f) != -1) {
                        return;
                    }
                }
                if (SafeCenterService.getBackValue(NotiSMSActivity.this.f4972f) == -1) {
                    SafeCenterService.setBackValue(NotiSMSActivity.this.f4972f, 1);
                    NotiSMSActivity.this.finish();
                }
            }
        }.start();
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (keyCode == 4) {
            keyCode = -1;
        }
        return super.onKeyDown(keyCode, event);
    }
}
