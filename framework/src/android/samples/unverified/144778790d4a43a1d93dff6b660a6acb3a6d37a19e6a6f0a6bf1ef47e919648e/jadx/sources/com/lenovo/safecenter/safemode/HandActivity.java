package com.lenovo.safecenter.safemode;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.util.Log;
import android.util.Patterns;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class HandActivity extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private EditText f5153a;

    /* JADX INFO: renamed from: b */
    private EditText f5154b;

    /* JADX INFO: renamed from: c */
    private Button f5155c;

    /* JADX INFO: renamed from: d */
    private AppDatabase f5156d;

    /* JADX INFO: renamed from: e */
    private ContractHelpUtils f5157e;

    /* JADX INFO: renamed from: f */
    private C0910a f5158f;

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.handblack);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.privacy_mode_set, (Integer) null);
        this.f5153a = (EditText) findViewById(C0415R.id.safemode_hand_number_value);
        this.f5154b = (EditText) findViewById(C0415R.id.safemode_hand_name_value);
        this.f5155c = (Button) findViewById(C0415R.id.safemode_hand_numbre_add);
        this.f5156d = new AppDatabase(this);
        this.f5157e = new ContractHelpUtils();
        onBtnClick();
        this.f5158f = new C0910a(this, (byte) 0);
        IntentFilter filter = new IntentFilter("android.intent.action.SCREEN_OFF");
        registerReceiver(this.f5158f, filter);
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
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

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
        unregisterReceiver(this.f5158f);
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.safemode.HandActivity$a */
    private class C0910a extends BroadcastReceiver {
        private C0910a() {
        }

        /* synthetic */ C0910a(HandActivity x0, byte b) {
            this();
        }

        @Override // android.content.BroadcastReceiver
        public final void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals("android.intent.action.SCREEN_OFF")) {
                HandActivity.this.finish();
            }
        }
    }

    /* JADX WARN: Type inference failed for: r0v0, types: [com.lenovo.safecenter.safemode.HandActivity$1] */
    public void initCopyDel(final Contract con) {
        new Thread() { // from class: com.lenovo.safecenter.safemode.HandActivity.1
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    String optNumber = con.getPhoneNumber();
                    if (HandActivity.this.f5157e.isMobileNO(optNumber)) {
                        optNumber = HandActivity.this.f5157e.optNUmber(optNumber);
                    }
                    List<Contract> call = HandActivity.this.f5157e.getCallContractByNUmber(HandActivity.this, optNumber, con.getPhoneNumber());
                    List<Contract> sms = HandActivity.this.f5157e.getSmsByNUmber(HandActivity.this, optNumber, con.getPhoneNumber(), con.getName());
                    HandActivity.this.f5156d.insertCall(call);
                    HandActivity.this.f5156d.insertSms(sms);
                    if (call.size() > 0 || sms.size() > 0) {
                        HandActivity.this.f5157e.operateNumber(optNumber, HandActivity.this, sms.size() > 0);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void onBtnClick() {
        this.f5155c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.safemode.HandActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (HandActivity.this.f5153a.getText() != null && !HandActivity.this.f5153a.getText().toString().equalsIgnoreCase("")) {
                    String number = HandActivity.this.f5153a.getText().toString();
                    Log.i("match", number + "==" + Patterns.PHONE.matcher(number).matches());
                    if (Patterns.PHONE.matcher(number).matches()) {
                        if (HandActivity.this.f5156d.getWhiteContract(number) == null) {
                            String name = null;
                            if (HandActivity.this.f5154b.getText() != null && !HandActivity.this.f5154b.getText().toString().equalsIgnoreCase("")) {
                                name = HandActivity.this.f5154b.getText().toString();
                            }
                            Contract con = new Contract();
                            con.setName(name);
                            con.setPhoneNumber(number);
                            con.setRealnumber(HandActivity.this.f5157e.getRealPhoneNumber(number));
                            HandActivity.this.f5156d.insertContract(con);
                            ContractHelpUtils.sendBraodcast(HandActivity.this, "com.lenovo.securityperson.change");
                            Toast.makeText(HandActivity.this, C0415R.string.info_success, 0).show();
                            HandActivity.this.initCopyDel(con);
                            HandActivity.this.finish();
                            return;
                        }
                        Toast.makeText(HandActivity.this, C0415R.string.hand_number_error1, 0).show();
                        return;
                    }
                    Toast.makeText(HandActivity.this, C0415R.string.hand_number_error, 0).show();
                    return;
                }
                Toast.makeText(HandActivity.this, C0415R.string.hand_number_null, 0).show();
            }
        });
    }
}
