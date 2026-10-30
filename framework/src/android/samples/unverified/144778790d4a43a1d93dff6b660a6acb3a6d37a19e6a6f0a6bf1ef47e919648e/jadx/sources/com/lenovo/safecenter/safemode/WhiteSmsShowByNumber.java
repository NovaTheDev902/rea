package com.lenovo.safecenter.safemode;

import android.app.NotificationManager;
import android.content.BroadcastReceiver;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.adapter.whiteSmsbyNumberAdapter;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.mmsutils.PushReceiver;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.platform.DoubleCardUtils;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.support.HttpUtils;
import com.lenovo.safecenter.support.SecurityService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.Constant;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import com.lenovo.safecenter.utils.DataHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import com.tencent.tmsecure.module.software.AppEntity;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class WhiteSmsShowByNumber extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    Button f5307a;

    /* JADX INFO: renamed from: b */
    Button f5308b;

    /* JADX INFO: renamed from: c */
    EditText f5309c;

    /* JADX INFO: renamed from: d */
    LinearLayout f5310d;

    /* JADX INFO: renamed from: e */
    private ListView f5311e;

    /* JADX INFO: renamed from: f */
    private TextView f5312f;

    /* JADX INFO: renamed from: g */
    private TextView f5313g;

    /* JADX INFO: renamed from: h */
    private List<Contract> f5314h;

    /* JADX INFO: renamed from: i */
    private AppDatabase f5315i;

    /* JADX INFO: renamed from: j */
    private whiteSmsbyNumberAdapter f5316j;

    /* JADX INFO: renamed from: k */
    private String f5317k;

    /* JADX INFO: renamed from: l */
    private ContractHelpUtils f5318l;

    /* JADX INFO: renamed from: n */
    private C0963a f5320n;

    /* JADX INFO: renamed from: o */
    private String f5321o;

    /* JADX INFO: renamed from: p */
    private Contract f5322p;

    /* JADX INFO: renamed from: m */
    private int f5319m = 0;
    public Handler hand = new Handler() { // from class: com.lenovo.safecenter.safemode.WhiteSmsShowByNumber.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    if (msg.getData().getString(AppDatabase.NUMBER).equals(WhiteSmsShowByNumber.this.f5317k)) {
                        WhiteSmsShowByNumber.this.initData();
                        WhiteSmsShowByNumber.this.f5315i.updateSmsStatus(WhiteSmsShowByNumber.this.f5317k, 0);
                        WhiteSmsShowByNumber.this.f5311e.setSelectionFromTop(WhiteSmsShowByNumber.this.f5314h.size() - 1, 0);
                    } else if (DataHelpUtils.getActivityByName("WhiteSms") != null) {
                        WhiteSms activity = (WhiteSms) DataHelpUtils.getActivityByName("WhiteSms");
                        activity.hand.sendEmptyMessage(1);
                    }
                    NotificationManager nmanager = (NotificationManager) WhiteSmsShowByNumber.this.getSystemService(DatabaseTables.LOG_NOTIFICATION);
                    nmanager.cancel(Constant.SMS_NOTI_ID);
                    break;
                case 5:
                    if (WhiteSmsShowByNumber.this.f5314h.size() > 0) {
                        WhiteSmsShowByNumber.this.f5311e.setSelectionFromTop(WhiteSmsShowByNumber.this.f5314h.size() - 1, 0);
                    }
                    break;
            }
        }
    };

    /* JADX INFO: renamed from: q */
    private long f5323q = 0;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2183a(WhiteSmsShowByNumber x0, final Contract x1) {
        String[] strArr = {x0.getString(C0415R.string.delete_sms), x0.getString(C0415R.string.safemode_callto)};
        if (x1.getSmstype() != 1) {
            strArr = new String[]{x0.getString(C0415R.string.delete_sms)};
        }
        String name = x1.getName();
        if (TextUtils.isEmpty(x1.getName())) {
            name = x1.getPhoneNumber();
        }
        new CustomDialog.Builder(x0).setTitle(name).setItems(strArr, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSmsShowByNumber.5
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                switch (which) {
                    case 0:
                        WhiteSmsShowByNumber.this.f5315i.deleteSms(x1.getId());
                        WhiteSmsShowByNumber.this.f5314h.remove(WhiteSmsShowByNumber.this.f5319m);
                        if (WhiteSmsShowByNumber.this.f5314h.size() == 0) {
                            WhiteSmsShowByNumber.this.initData();
                        }
                        WhiteSmsShowByNumber.this.f5311e.invalidateViews();
                        break;
                    case 1:
                        try {
                            Intent callIntent = new Intent("android.intent.action.CALL", Uri.parse("tel:" + x1.getPhoneNumber()));
                            WhiteSmsShowByNumber.this.startActivity(callIntent);
                        } catch (Exception e) {
                            Toast.makeText(WhiteSmsShowByNumber.this, C0415R.string.opensms_error, 0).show();
                            e.printStackTrace();
                            return;
                        }
                        break;
                    case 2:
                        SecurityService.beginTime = System.currentTimeMillis();
                        WhiteSmsShowByNumber.this.f5318l.backToSms(x1, WhiteSmsShowByNumber.this);
                        WhiteSmsShowByNumber.this.f5315i.deleteSms(x1.getId());
                        WhiteSmsShowByNumber.this.f5314h.remove(WhiteSmsShowByNumber.this.f5319m);
                        if (WhiteSmsShowByNumber.this.f5314h.size() == 0) {
                            WhiteSmsShowByNumber.this.initData();
                        }
                        WhiteSmsShowByNumber.this.f5311e.invalidateViews();
                        break;
                }
            }
        }).create().show();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        byte b = 0;
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.whitesmsshowlist);
        getWindow().setSoftInputMode(34);
        this.f5311e = (ListView) findViewById(C0415R.id.safemode_log_list);
        this.f5311e.setDivider(null);
        this.f5312f = (TextView) findViewById(C0415R.id.safemode_empty_textview);
        this.f5307a = (Button) findViewById(C0415R.id.safemode_operat_btn);
        this.f5309c = (EditText) findViewById(C0415R.id.safemode_send_textview);
        this.f5313g = (TextView) findViewById(C0415R.id.txtdesc);
        this.f5313g.setVisibility(8);
        this.f5309c.setVisibility(0);
        this.f5308b = (Button) findViewById(C0415R.id.safemode_operat_btn1);
        this.f5310d = (LinearLayout) findViewById(C0415R.id.safemode_lin_operate);
        this.f5310d.setVisibility(0);
        this.f5307a.setText(C0415R.string.replay_sms_card1);
        this.f5317k = getIntent().getStringExtra(AppDatabase.NUMBER);
        this.f5318l = new ContractHelpUtils();
        this.f5315i = new AppDatabase(this);
        this.f5322p = DataHelpUtils.getContractModel(this, this.f5317k);
        onBtnClick();
        DataHelpUtils.allActivity.add(this);
        int[] states = MyMultiSIMUtils.getAllSimState(this);
        if (MyMultiSIMUtils.isMultiSim(this)) {
            this.f5308b.setVisibility(0);
            if (states[0] == 5 || states[0] == 2 || states[0] == 3) {
                this.f5307a.setEnabled(true);
            } else {
                this.f5307a.setEnabled(false);
            }
            if (states[1] == 5 || states[1] == 2 || states[1] == 3) {
                this.f5308b.setEnabled(true);
            } else {
                this.f5308b.setEnabled(false);
            }
        } else {
            this.f5307a.setText(C0415R.string.replay_sms2);
            this.f5308b.setVisibility(8);
        }
        this.f5320n = new C0963a(this, b);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f5320n, filter);
        this.f5314h = this.f5315i.getwhiteSmsInfo(this.f5317k);
        if (this.f5314h.size() >= 0) {
            if (this.f5314h.size() > 0 && !TextUtils.isEmpty(this.f5314h.get(0).getName())) {
                this.f5321o = this.f5314h.get(0).getName();
                setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), getSubStr(this.f5314h.get(0).getName(), 14), (Integer) null);
            } else if (this.f5322p == null || TextUtils.isEmpty(this.f5322p.getName())) {
                this.f5321o = this.f5317k;
                setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), this.f5317k, (Integer) null);
            } else {
                this.f5321o = this.f5322p.getName();
                setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), getSubStr(this.f5322p.getName(), 14), (Integer) null);
            }
            this.f5311e.setEmptyView(this.f5312f);
            this.f5316j = new whiteSmsbyNumberAdapter(this, this.f5314h);
            this.f5311e.setAdapter((ListAdapter) this.f5316j);
            this.hand.sendEmptyMessage(5);
        }
    }

    public String getSubStr(String str, int size) {
        if (getWordCount(str) > size) {
            return str.substring(0, 6) + "...";
        }
        return str;
    }

    public int getWordCount(String s) {
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            int ascii = Character.codePointAt(s, i);
            if (ascii >= 0 && ascii <= 255) {
                length++;
            } else {
                length += 2;
            }
        }
        return length;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.WhiteSmsShowByNumber$a */
    private class C0963a extends BroadcastReceiver {
        private C0963a() {
        }

        /* synthetic */ C0963a(WhiteSmsShowByNumber x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                WhiteSmsShowByNumber.this.finish();
            }
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        super.onResume();
        if (this.f5323q != 0 && System.currentTimeMillis() - this.f5323q > 112000) {
            HttpUtils.private_isOpenSec = false;
            finish();
        } else {
            this.f5315i.updateSmsStatus(this.f5317k, 0);
            TrackEvent.trackResume(this);
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        if (DataHelpUtils.getActivityByName("SofeModeMain") != null) {
            SofeModeMain activity = (SofeModeMain) DataHelpUtils.getActivityByName("SofeModeMain");
            activity.hand.sendEmptyMessage(1);
        }
        if (DataHelpUtils.getActivityByName("WhiteSmsShowByNumber") != null) {
            DataHelpUtils.allActivity.remove(this);
        }
        unregisterReceiver(this.f5320n);
        HttpUtils.private_isOpenSec = false;
        this.f5323q = 0L;
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        this.f5323q = System.currentTimeMillis();
    }

    public void initData() {
        this.f5314h = this.f5315i.getwhiteSmsInfo(this.f5317k);
        this.f5316j = new whiteSmsbyNumberAdapter(this, this.f5314h);
        this.f5311e.setAdapter((ListAdapter) this.f5316j);
    }

    public void onBtnClick() {
        this.f5311e.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSmsShowByNumber.2
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                WhiteSmsShowByNumber.this.f5319m = position;
                Contract con = (Contract) WhiteSmsShowByNumber.this.f5311e.getItemAtPosition(position);
                WhiteSmsShowByNumber.m2183a(WhiteSmsShowByNumber.this, con);
            }
        });
        this.f5307a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSmsShowByNumber.3
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (WhiteSmsShowByNumber.this.f5309c.getText() != null && !WhiteSmsShowByNumber.this.f5309c.getText().toString().equals("")) {
                    String content = WhiteSmsShowByNumber.this.f5309c.getText().toString();
                    if (MyMultiSIMUtils.isMultiSim(WhiteSmsShowByNumber.this)) {
                        if (Settings.System.getInt(WhiteSmsShowByNumber.this.getContentResolver(), "airplane_mode_on", 0) == 0) {
                            DoubleCardUtils.privateSendMessage(WhiteSmsShowByNumber.this, WhiteSmsShowByNumber.this.f5317k, content, true, 0);
                        } else {
                            Toast.makeText(WhiteSmsShowByNumber.this, WhiteSmsShowByNumber.this.getString(C0415R.string.net_notavilable), 0).show();
                            return;
                        }
                    } else if (Settings.System.getInt(WhiteSmsShowByNumber.this.getContentResolver(), "airplane_mode_on", 0) == 0) {
                        DoubleCardUtils.sendMessage(WhiteSmsShowByNumber.this, WhiteSmsShowByNumber.this.f5317k, content, true);
                    } else {
                        Toast.makeText(WhiteSmsShowByNumber.this, WhiteSmsShowByNumber.this.getString(C0415R.string.net_notavilable), 0).show();
                        return;
                    }
                    Const.isTariff = false;
                    Contract sms = new Contract();
                    sms.setSmsContent(content);
                    sms.setSmstype(2);
                    sms.setDate(String.valueOf(System.currentTimeMillis()));
                    sms.setPhoneNumber(WhiteSmsShowByNumber.this.f5317k);
                    sms.setIsRead(0);
                    sms.setName(WhiteSmsShowByNumber.this.f5321o);
                    WhiteSmsShowByNumber.this.f5315i.insertSms(sms);
                    SecurityService.beginTime = System.currentTimeMillis();
                    WhiteSmsShowByNumber.this.initData();
                    WhiteSmsShowByNumber.this.hand.sendEmptyMessage(5);
                    if (WhiteSmsShowByNumber.this.f5322p == null) {
                        WhiteSmsShowByNumber.this.backToSms(sms, WhiteSmsShowByNumber.this);
                    }
                    Log.i(AppEntity.KEY_SIZE_LONG, WhiteSmsShowByNumber.this.f5314h.size() + "666" + content);
                    WhiteSmsShowByNumber.this.f5309c.setText("");
                }
            }
        });
        this.f5308b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.WhiteSmsShowByNumber.4
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (!TextUtils.isEmpty(WhiteSmsShowByNumber.this.f5309c.getText())) {
                    if (Settings.System.getInt(WhiteSmsShowByNumber.this.getContentResolver(), "airplane_mode_on", 0) == 0) {
                        DoubleCardUtils.privateSendMessage(WhiteSmsShowByNumber.this, WhiteSmsShowByNumber.this.f5317k, WhiteSmsShowByNumber.this.f5309c.getText().toString(), true, 1);
                        Const.isTariff = false;
                        Contract sms = new Contract();
                        sms.setSmsContent(WhiteSmsShowByNumber.this.f5309c.getText().toString());
                        sms.setSmstype(2);
                        sms.setDate(String.valueOf(System.currentTimeMillis()));
                        sms.setPhoneNumber(WhiteSmsShowByNumber.this.f5317k);
                        sms.setIsRead(0);
                        sms.setName(WhiteSmsShowByNumber.this.f5321o);
                        WhiteSmsShowByNumber.this.f5315i.insertSms(sms);
                        SecurityService.beginTime = System.currentTimeMillis();
                        WhiteSmsShowByNumber.this.initData();
                        WhiteSmsShowByNumber.this.hand.sendEmptyMessage(5);
                        if (WhiteSmsShowByNumber.this.f5322p == null) {
                            WhiteSmsShowByNumber.this.backToSms(sms, WhiteSmsShowByNumber.this);
                        }
                        WhiteSmsShowByNumber.this.f5309c.setText("");
                        return;
                    }
                    Toast.makeText(WhiteSmsShowByNumber.this, WhiteSmsShowByNumber.this.getString(C0415R.string.net_notavilable), 0).show();
                }
            }
        });
    }

    public void backToSms(Contract con, Context context) {
        ContentValues values = new ContentValues();
        values.put("address", con.getPhoneNumber());
        values.put("date", String.valueOf(con.getDate()));
        values.put(PushReceiver.READ, (Integer) 1);
        values.put("status", (Integer) (-1));
        values.put("type", Integer.valueOf(con.getSmstype()));
        values.put(PushReceiver.BODY, con.getSmsContent());
        context.getContentResolver().insert(Uri.parse("content://sms"), values);
    }
}
