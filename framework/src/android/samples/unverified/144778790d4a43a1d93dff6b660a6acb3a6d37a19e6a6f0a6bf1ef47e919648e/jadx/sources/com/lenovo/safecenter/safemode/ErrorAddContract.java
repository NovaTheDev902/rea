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
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.CallAdapter;
import com.lenovo.safecenter.adapter.SmsAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ErrorAddContract extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    Button f5103a;

    /* JADX INFO: renamed from: b */
    LinearLayout f5104b;

    /* JADX INFO: renamed from: c */
    private List<Contract> f5105c;

    /* JADX INFO: renamed from: d */
    private ListView f5106d;

    /* JADX INFO: renamed from: e */
    private TextView f5107e;

    /* JADX INFO: renamed from: f */
    private ContractHelpUtils f5108f;

    /* JADX INFO: renamed from: g */
    private int f5109g;

    /* JADX INFO: renamed from: h */
    private BaseAdapter f5110h;

    /* JADX INFO: renamed from: j */
    private ProgressDialog f5112j;

    /* JADX INFO: renamed from: k */
    private C0897a f5113k;

    /* JADX INFO: renamed from: i */
    private boolean f5111i = false;

    /* JADX INFO: renamed from: l */
    private int f5114l = 0;

    /* JADX INFO: renamed from: m */
    private Handler f5115m = new Handler() { // from class: com.lenovo.safecenter.safemode.ErrorAddContract.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    ErrorAddContract.m2111a(ErrorAddContract.this);
                    if (ErrorAddContract.this.f5112j != null) {
                        try {
                            ErrorAddContract.this.f5112j.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    if (ErrorAddContract.this.f5105c != null) {
                        if (ErrorAddContract.this.f5109g > 1) {
                            if (ErrorAddContract.this.f5109g == 2) {
                                ErrorAddContract.this.f5110h = new SmsAdapter(ErrorAddContract.this, ErrorAddContract.this.f5105c);
                            }
                        } else {
                            ErrorAddContract.this.f5110h = new CallAdapter(ErrorAddContract.this, ErrorAddContract.this.f5105c, ErrorAddContract.this.f5109g);
                        }
                        ErrorAddContract.this.f5106d.setAdapter((ListAdapter) ErrorAddContract.this.f5110h);
                    }
                    break;
                case 1:
                    ErrorAddContract.m2111a(ErrorAddContract.this);
                    if (ErrorAddContract.this.f5112j != null) {
                        try {
                            ErrorAddContract.this.f5112j.dismiss();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                    ErrorAddContract.this.finish();
                    break;
                case 3:
                    ErrorAddContract.m2111a(ErrorAddContract.this);
                    if (ErrorAddContract.this.f5112j != null) {
                        try {
                            ErrorAddContract.this.f5112j.dismiss();
                        } catch (Exception e3) {
                            e3.printStackTrace();
                        }
                    }
                    ContractHelpUtils.sendBraodcast(ErrorAddContract.this, "com.lenovo.securityperson.change");
                    ErrorAddContract.this.finish();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m2111a(ErrorAddContract x0) {
        x0.f5111i = false;
        return false;
    }

    /* JADX INFO: renamed from: j */
    static /* synthetic */ int m2120j(ErrorAddContract x0) {
        int i = x0.f5114l;
        x0.f5114l = i - 1;
        return i;
    }

    /* JADX INFO: renamed from: k */
    static /* synthetic */ int m2121k(ErrorAddContract x0) {
        int i = x0.f5114l;
        x0.f5114l = i + 1;
        return i;
    }

    public void setAddBtnText() {
        if (this.f5114l > 0) {
            this.f5103a.setText(String.format(getString(C0415R.string.add_count), Integer.valueOf(this.f5114l)));
        } else {
            this.f5103a.setText(C0415R.string.antispamlocalblack_add);
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.addprivate);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.privacy_mode_set, (Integer) null);
        this.f5104b = (LinearLayout) findViewById(C0415R.id.safemode_lin_operate);
        this.f5104b.setVisibility(0);
        this.f5103a = (Button) findViewById(C0415R.id.safemode_operat_btn);
        this.f5103a.setWidth(204);
        this.f5103a.setHeight(60);
        this.f5106d = (ListView) findViewById(C0415R.id.safemode_log_list);
        this.f5107e = (TextView) findViewById(C0415R.id.safemode_empty_textview);
        this.f5108f = new ContractHelpUtils();
        this.f5109g = getIntent().getIntExtra("fromtype", 0);
        onBtnClick();
        if (this.f5107e != null) {
            this.f5106d.setEmptyView(this.f5107e);
        }
        initData();
        this.f5113k = new C0897a(this, b);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f5113k, filter);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    /* JADX WARN: Type inference failed for: r0v6, types: [com.lenovo.safecenter.safemode.ErrorAddContract$2] */
    public void initData() {
        this.f5107e.setVisibility(8);
        this.f5112j = new ProgressDialog(this);
        this.f5112j.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5112j.setCanceledOnTouchOutside(false);
        this.f5112j.show();
        this.f5111i = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.ErrorAddContract.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                ErrorAddContract.this.f5105c = new ArrayList();
                ErrorAddContract.this.f5105c = ErrorAddContract.this.f5108f.getConNotInWhiteList(ErrorAddContract.this.f5105c, ErrorAddContract.this, ErrorAddContract.this.f5109g);
                ErrorAddContract.this.f5115m.sendEmptyMessage(0);
            }
        }.start();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f5113k);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.ErrorAddContract$a */
    private class C0897a extends BroadcastReceiver {
        private C0897a() {
        }

        /* synthetic */ C0897a(ErrorAddContract x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                ErrorAddContract.this.finish();
            }
        }
    }

    public void onBtnClick() {
        this.f5106d.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorAddContract.3
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if (!ErrorAddContract.this.f5111i) {
                    Contract con = (Contract) ErrorAddContract.this.f5106d.getItemAtPosition(position);
                    if (con.isSelect()) {
                        con.setSelect(false);
                        ErrorAddContract.m2120j(ErrorAddContract.this);
                    } else {
                        con.setSelect(true);
                        ErrorAddContract.m2121k(ErrorAddContract.this);
                    }
                    ErrorAddContract.this.setAddBtnText();
                    ErrorAddContract.this.f5106d.invalidateViews();
                    return;
                }
                Toast.makeText(ErrorAddContract.this, C0415R.string.waitting, 0).show();
            }
        });
        this.f5103a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.ErrorAddContract.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (ErrorAddContract.this.f5111i) {
                    Toast.makeText(ErrorAddContract.this, C0415R.string.waitting, 0).show();
                    return;
                }
                ArrayList arrayList = new ArrayList();
                for (int i = ErrorAddContract.this.f5105c.size() - 1; i >= 0; i--) {
                    if (((Contract) ErrorAddContract.this.f5105c.get(i)).isSelect()) {
                        arrayList.add(ErrorAddContract.this.f5105c.get(i));
                    }
                }
                if (arrayList.size() > 0) {
                    ErrorWhiteContract.list.addAll(arrayList);
                    ErrorAddContract.this.finish();
                } else {
                    Toast.makeText(ErrorAddContract.this, C0415R.string.localblack_nullNotice, 0).show();
                }
            }
        });
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.safemode.ErrorAddContract$5] */
    public void initInsert(final List<Contract> selectlist) {
        this.f5112j = new ProgressDialog(this);
        this.f5112j.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5112j.show();
        this.f5111i = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.ErrorAddContract.5
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    long time1 = System.currentTimeMillis();
                    List<Contract> list_insert = ErrorAddContract.this.f5108f.noContractRepeatList(selectlist);
                    Log.i(AppDatabase.TIME, (System.currentTimeMillis() - time1) + "");
                    ErrorWhiteContract.list = list_insert;
                    ErrorAddContract.this.f5115m.sendEmptyMessage(3);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.safemode.ErrorAddContract$6] */
    public void initCopyDel(final List<Contract> selectlist) {
        this.f5112j = new ProgressDialog(this);
        this.f5112j.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5112j.show();
        this.f5111i = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.ErrorAddContract.6
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    for (Contract con : selectlist) {
                        String optNumber = con.getPhoneNumber();
                        if (ErrorAddContract.this.f5108f.isMobileNO(optNumber)) {
                            optNumber = ErrorAddContract.this.f5108f.optNUmber(optNumber);
                        }
                        ErrorAddContract.this.f5108f.operateNumber(optNumber, ErrorAddContract.this, false);
                    }
                    ErrorAddContract.this.f5115m.sendEmptyMessage(1);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
}
