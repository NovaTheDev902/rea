package com.lenovo.safecenter.safemode;

import android.app.ProgressDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
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
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class AddContract extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    Button f4999a;

    /* JADX INFO: renamed from: b */
    LinearLayout f5000b;

    /* JADX INFO: renamed from: c */
    private AppDatabase f5001c;

    /* JADX INFO: renamed from: d */
    private List<Contract> f5002d;

    /* JADX INFO: renamed from: e */
    private ListView f5003e;

    /* JADX INFO: renamed from: f */
    private TextView f5004f;

    /* JADX INFO: renamed from: g */
    private ContractHelpUtils f5005g;

    /* JADX INFO: renamed from: h */
    private int f5006h;

    /* JADX INFO: renamed from: i */
    private BaseAdapter f5007i;

    /* JADX INFO: renamed from: k */
    private ProgressDialog f5009k;

    /* JADX INFO: renamed from: l */
    private C0863a f5010l;

    /* JADX INFO: renamed from: j */
    private boolean f5008j = false;

    /* JADX INFO: renamed from: m */
    private int f5011m = 0;

    /* JADX INFO: renamed from: n */
    private Handler f5012n = new Handler() { // from class: com.lenovo.safecenter.safemode.AddContract.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    AddContract.m2068a(AddContract.this);
                    if (AddContract.this.f5009k != null) {
                        try {
                            AddContract.this.f5009k.dismiss();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                    if (AddContract.this.f5002d != null) {
                        if (AddContract.this.f5006h > 1) {
                            if (AddContract.this.f5006h == 2) {
                                AddContract.this.f5007i = new SmsAdapter(AddContract.this, AddContract.this.f5002d);
                            }
                        } else {
                            AddContract.this.f5007i = new CallAdapter(AddContract.this, AddContract.this.f5002d, AddContract.this.f5006h);
                        }
                        AddContract.this.f5003e.setAdapter((ListAdapter) AddContract.this.f5007i);
                    }
                    break;
                case 1:
                    AddContract.m2068a(AddContract.this);
                    if (AddContract.this.f5009k != null) {
                        try {
                            AddContract.this.f5009k.dismiss();
                        } catch (Exception e2) {
                            e2.printStackTrace();
                        }
                    }
                    AddContract.this.finish();
                    break;
                case 3:
                    AddContract.m2068a(AddContract.this);
                    if (AddContract.this.f5009k != null) {
                        try {
                            AddContract.this.f5009k.dismiss();
                        } catch (Exception e3) {
                            e3.printStackTrace();
                        }
                    }
                    ContractHelpUtils.sendBraodcast(AddContract.this, "com.lenovo.securityperson.change");
                    AddContract.this.finish();
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: o */
    private long f5013o = 0;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ boolean m2068a(AddContract x0) {
        x0.f5008j = false;
        return false;
    }

    /* JADX INFO: renamed from: k */
    static /* synthetic */ int m2078k(AddContract x0) {
        int i = x0.f5011m;
        x0.f5011m = i - 1;
        return i;
    }

    /* JADX INFO: renamed from: l */
    static /* synthetic */ int m2079l(AddContract x0) {
        int i = x0.f5011m;
        x0.f5011m = i + 1;
        return i;
    }

    public void setAddBtnText() {
        if (this.f5011m > 0) {
            this.f4999a.setText(String.format(getString(C0415R.string.add_count), Integer.valueOf(this.f5011m)));
        } else {
            this.f4999a.setText(C0415R.string.antispamlocalblack_add);
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.addprivate);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.privacy_mode_set, (Integer) null);
        this.f5000b = (LinearLayout) findViewById(C0415R.id.safemode_lin_operate);
        this.f5000b.setVisibility(0);
        this.f4999a = (Button) findViewById(C0415R.id.safemode_operat_btn);
        if (Const.getScreenHeight() <= 480) {
            this.f4999a.setWidth(130);
            this.f4999a.setHeight(36);
        } else {
            this.f4999a.setWidth(204);
            this.f4999a.setHeight(60);
        }
        this.f5003e = (ListView) findViewById(C0415R.id.safemode_log_list);
        this.f5004f = (TextView) findViewById(C0415R.id.safemode_empty_textview);
        this.f5001c = new AppDatabase(this);
        this.f5005g = new ContractHelpUtils();
        this.f5006h = getIntent().getIntExtra("fromtype", 0);
        onBtnClick();
        if (this.f5004f != null) {
            if (this.f5006h == 0) {
                this.f5004f.setText(C0415R.string.localblack_hasNoData1);
            }
            this.f5003e.setEmptyView(this.f5004f);
        }
        initData();
        this.f5010l = new C0863a(this, b);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f5010l, filter);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    /* JADX WARN: Type inference failed for: r0v6, types: [com.lenovo.safecenter.safemode.AddContract$3] */
    public void initData() {
        this.f5004f.setVisibility(8);
        this.f5009k = new ProgressDialog(this);
        this.f5009k.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5009k.setCanceledOnTouchOutside(false);
        this.f5009k.show();
        this.f5008j = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.AddContract.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                AddContract.this.f5002d = AddContract.this.f5001c.getAllWhiteContract();
                AddContract.this.f5002d = AddContract.this.f5005g.getConNotInWhiteList(AddContract.this.f5002d, AddContract.this, AddContract.this.f5006h);
                AddContract.this.f5012n.sendEmptyMessage(0);
            }
        }.start();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        if (this.f5013o != 0 && System.currentTimeMillis() - this.f5013o > 114000) {
            HttpUtils.private_isOpenSec = false;
            finish();
        } else {
            TrackEvent.trackResume(this);
        }
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        this.f5013o = System.currentTimeMillis();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f5010l);
        this.f5013o = 0L;
        HttpUtils.private_isOpenSec = false;
    }

    public void initCopyDel1(List<Contract> selectlist) {
        for (Contract con : selectlist) {
            String optNumber = con.getPhoneNumber();
            if (this.f5005g.isMobileNO(optNumber)) {
                optNumber = this.f5005g.optNUmber(optNumber);
            }
            List<Contract> call = this.f5005g.getCallContractByNUmber(this, optNumber, con.getPhoneNumber());
            List<Contract> sms = this.f5005g.getSmsByNUmber(this, optNumber, con.getPhoneNumber(), con.getName());
            this.f5001c.insertCall(call);
            this.f5001c.insertSms(sms);
            if (call.size() > 0 || sms.size() > 0) {
                this.f5005g.operateNumber(optNumber, this, sms.size() > 0);
            }
        }
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.AddContract$a */
    private class C0863a extends BroadcastReceiver {
        private C0863a() {
        }

        /* synthetic */ C0863a(AddContract x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                AddContract.this.finish();
            }
        }
    }

    public void onBtnClick() {
        this.f5003e.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.AddContract.4
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                if (!AddContract.this.f5008j) {
                    Contract con = (Contract) AddContract.this.f5003e.getItemAtPosition(position);
                    if (con.isSelect()) {
                        con.setSelect(false);
                        AddContract.m2078k(AddContract.this);
                    } else {
                        con.setSelect(true);
                        AddContract.m2079l(AddContract.this);
                    }
                    AddContract.this.setAddBtnText();
                    AddContract.this.f5003e.invalidateViews();
                    return;
                }
                Toast.makeText(AddContract.this, C0415R.string.waitting, 0).show();
            }
        });
        this.f4999a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.AddContract.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (AddContract.this.f5008j) {
                    Toast.makeText(AddContract.this, C0415R.string.waitting, 0).show();
                    return;
                }
                ArrayList arrayList = new ArrayList();
                for (int i = AddContract.this.f5002d.size() - 1; i >= 0; i--) {
                    if (((Contract) AddContract.this.f5002d.get(i)).isSelect()) {
                        arrayList.add(AddContract.this.f5002d.get(i));
                    }
                }
                if (arrayList.size() > 0) {
                    AddContract.this.initInsert(arrayList);
                } else {
                    Toast.makeText(AddContract.this, C0415R.string.localblack_nullNotice, 0).show();
                }
            }
        });
    }

    public void showDialogAdd(final List<Contract> selectlist) {
        new CustomDialog.Builder(this).setTitle(C0415R.string.safemode_notice).setMessage(C0415R.string.noticecontent).setPositiveButton(C0415R.string.safemode_yes, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.AddContract.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                AddContract.this.initApp_deleteBlack(selectlist);
            }
        }).setNegativeButton(C0415R.string.safemode_no, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.AddContract.6
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                if (selectlist.size() > 1) {
                    AddContract.this.initApp_expectBlack(selectlist);
                } else {
                    AddContract.this.finish();
                }
            }
        }).create().show();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.safemode.AddContract$8] */
    public void initInsert(final List<Contract> selectlist) {
        this.f5009k = new ProgressDialog(this);
        this.f5009k.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5009k.show();
        this.f5008j = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.AddContract.8
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    long time1 = System.currentTimeMillis();
                    List<Contract> list_insert = AddContract.this.f5005g.noContractRepeatList(selectlist);
                    Log.i(AppDatabase.TIME, (System.currentTimeMillis() - time1) + "");
                    AddContract.this.f5001c.insertContract(list_insert);
                    AddContract.this.initCopyDel1(list_insert);
                    AddContract.this.f5012n.sendEmptyMessage(3);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.safemode.AddContract$9] */
    public void initApp_deleteBlack(final List<Contract> selList) {
        this.f5009k = new ProgressDialog(this);
        this.f5009k.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5009k.show();
        this.f5008j = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.AddContract.9
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    List<Contract> list_help = AddContract.this.f5005g.noContractRepeatList(selList);
                    List<Contract> list_B = AddContract.this.f5005g.getBlackFromadd(list_help, AddContract.this);
                    AddContract.this.f5005g.deleteBlack(AddContract.this, list_B);
                    AddContract.this.f5001c.insertContract(list_help);
                    AddContract.this.initCopyDel1(list_help);
                    AddContract.this.f5012n.sendEmptyMessage(3);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.safemode.AddContract$10] */
    public void initApp_expectBlack(final List<Contract> selList) {
        this.f5009k = new ProgressDialog(this);
        this.f5009k.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5009k.show();
        this.f5008j = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.AddContract.10
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    List<Contract> list_help = AddContract.this.f5005g.noContractRepeatList(selList);
                    List<Contract> list_w = AddContract.this.f5005g.getBlackFromadd(list_help, AddContract.this);
                    List<Contract> list_help2 = AddContract.this.f5005g.getAddlist(list_help, list_w);
                    AddContract.this.f5001c.insertContract(list_help2);
                    AddContract.this.initCopyDel1(list_help2);
                    AddContract.this.f5012n.sendEmptyMessage(3);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    /* JADX WARN: Type inference failed for: r0v4, types: [com.lenovo.safecenter.safemode.AddContract$2] */
    public void initCopyDel(final List<Contract> selectlist) {
        this.f5009k = new ProgressDialog(this);
        this.f5009k.setMessage(getResources().getString(C0415R.string.waitting));
        this.f5009k.show();
        this.f5008j = true;
        new Thread() { // from class: com.lenovo.safecenter.safemode.AddContract.2
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    for (Contract con : selectlist) {
                        String optNumber = con.getPhoneNumber();
                        if (AddContract.this.f5005g.isMobileNO(optNumber)) {
                            optNumber = AddContract.this.f5005g.optNUmber(optNumber);
                        }
                        List<Contract> call = AddContract.this.f5005g.getCallContractByNUmber(AddContract.this, optNumber, con.getPhoneNumber());
                        List<Contract> sms = AddContract.this.f5005g.getSmsByNUmber(AddContract.this, optNumber, con.getPhoneNumber(), con.getName());
                        AddContract.this.f5001c.insertCall(call);
                        AddContract.this.f5001c.insertSms(sms);
                        if (call.size() > 0 || sms.size() > 0) {
                            AddContract.this.f5005g.operateNumber(optNumber, AddContract.this, sms.size() > 0);
                        }
                    }
                    AddContract.this.f5012n.sendEmptyMessage(1);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
}
