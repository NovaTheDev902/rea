package com.lenovo.safecenter.safemode;

import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListAdapter;
import android.widget.ListView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.ManwhiteSmsAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ManWhiteSms extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private Button f5163a;

    /* JADX INFO: renamed from: b */
    private Button f5164b;

    /* JADX INFO: renamed from: c */
    private Button f5165c;

    /* JADX INFO: renamed from: d */
    private int f5166d;

    /* JADX INFO: renamed from: e */
    private ListView f5167e;

    /* JADX INFO: renamed from: f */
    private List<Contract> f5168f;

    /* JADX INFO: renamed from: g */
    private ManwhiteSmsAdapter f5169g;

    /* JADX INFO: renamed from: h */
    private AppDatabase f5170h;

    /* JADX INFO: renamed from: i */
    private boolean f5171i;

    /* JADX INFO: renamed from: j */
    private ProgressDialog f5172j;

    /* JADX INFO: renamed from: l */
    private C0917b f5174l;

    /* JADX INFO: renamed from: k */
    private boolean f5173k = false;

    /* JADX INFO: renamed from: m */
    private Handler f5175m = new HandlerC0916a(this, 0);

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m2133a(ManWhiteSms x0) {
        x0.f5173k = false;
        return false;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.ManWhiteSms$a */
    private class HandlerC0916a extends Handler {
        private HandlerC0916a() {
        }

        /* synthetic */ HandlerC0916a(ManWhiteSms x0, byte b) {
            this();
        }

        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    ManWhiteSms.m2133a(ManWhiteSms.this);
                    if (ManWhiteSms.this.f5172j != null) {
                        try {
                            ManWhiteSms.this.f5172j.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    ManWhiteSms.this.finish();
                    break;
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.ManWhiteSms$b */
    private class C0917b extends BroadcastReceiver {
        private C0917b() {
        }

        /* synthetic */ C0917b(ManWhiteSms x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                ManWhiteSms.this.finish();
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f5174l);
        HttpUtils.private_isOpenSec = false;
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.manwhitesms);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.privacy_safe, (Integer) null);
        this.f5167e = (ListView) findViewById(C0415R.id.safemode_man_whitelist);
        this.f5163a = (Button) findViewById(C0415R.id.safemode_white_del);
        this.f5164b = (Button) findViewById(C0415R.id.safemode_white_select);
        this.f5165c = (Button) findViewById(C0415R.id.safemode_white_back);
        this.f5170h = new AppDatabase(this);
        this.f5171i = false;
        this.f5166d = getIntent().getIntExtra("type", 0);
        if (this.f5166d == 0) {
            this.f5163a.setText(C0415R.string.menu_del);
        } else if (this.f5166d == 1) {
            this.f5163a.setText(C0415R.string.menu_recover);
        }
        initData();
        onBtnClick();
        this.f5174l = new C0917b(this, b);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f5174l, filter);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void initData() {
        this.f5168f = this.f5170h.getwhiteSms();
        if (this.f5168f != null) {
            this.f5169g = new ManwhiteSmsAdapter(this, this.f5168f);
            this.f5167e.setAdapter((ListAdapter) this.f5169g);
        }
    }

    public void onBtnClick() {
        this.f5167e.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.ManWhiteSms.1
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Contract con = (Contract) ManWhiteSms.this.f5167e.getItemAtPosition(position);
                if (con.isSelect()) {
                    con.setSelect(false);
                } else {
                    con.setSelect(true);
                }
                ManWhiteSms.this.f5167e.invalidateViews();
            }
        });
        this.f5165c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ManWhiteSms.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ManWhiteSms.this.finish();
            }
        });
        this.f5164b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ManWhiteSms.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!ManWhiteSms.this.f5171i) {
                    ManWhiteSms.this.f5171i = true;
                } else {
                    ManWhiteSms.this.f5171i = false;
                }
                for (Contract con : ManWhiteSms.this.f5168f) {
                    if (ManWhiteSms.this.f5171i) {
                        con.setSelect(true);
                        ManWhiteSms.this.f5164b.setText(C0415R.string.cancelselect);
                        Log.i("txt", ((Object) ManWhiteSms.this.f5164b.getText()) + "!isAllSelect");
                    } else {
                        con.setSelect(false);
                        ManWhiteSms.this.f5164b.setText(C0415R.string.selectall);
                        Log.i("txt", ((Object) ManWhiteSms.this.f5164b.getText()) + "isAllSelect");
                    }
                }
                ManWhiteSms.this.f5167e.invalidateViews();
            }
        });
        this.f5163a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ManWhiteSms.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!ManWhiteSms.this.f5173k) {
                    List<String> numbers = new ArrayList<>();
                    for (Contract con : ManWhiteSms.this.f5168f) {
                        if (con.isSelect()) {
                            numbers.add(con.getPhoneNumber());
                        }
                    }
                    if (numbers.size() > 0) {
                        if (ManWhiteSms.this.f5166d == 0) {
                            ManWhiteSms.this.f5170h.deleteSmsByNo(numbers);
                            ManWhiteSms.this.finish();
                        } else if (ManWhiteSms.this.f5166d == 1) {
                            ManWhiteSms.this.init_recovery(numbers);
                        }
                        SofeModeMain activity = (SofeModeMain) DataHelpUtils.getActivityByName("SofeModeMain");
                        activity.hand.sendEmptyMessage(1);
                    }
                }
            }
        });
    }

    /* JADX WARN: Type inference failed for: r0v5, types: [com.lenovo.safecenter.safemode.ManWhiteSms$5] */
    public void init_recovery(final List<String> select_numbers) {
        this.f5172j = new ProgressDialog(this);
        this.f5172j.setProgressStyle(0);
        this.f5172j.setMessage(getResources().getString(C0415R.string.running));
        this.f5172j.show();
        this.f5173k = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.ManWhiteSms.5
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ManWhiteSms.this.f5170h.getwhiteSmsByNumbers(select_numbers);
                ManWhiteSms.this.f5170h.deleteSmsByNo(select_numbers);
                ManWhiteSms.this.f5175m.sendEmptyMessage(0);
            }
        }.start();
    }
}
