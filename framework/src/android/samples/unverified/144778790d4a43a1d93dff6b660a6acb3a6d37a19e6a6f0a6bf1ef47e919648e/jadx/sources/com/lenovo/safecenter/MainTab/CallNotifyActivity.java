package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.safemode.SofeModeMain;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class CallNotifyActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private String f2698a;

    /* JADX INFO: renamed from: b */
    private int f2699b;

    /* JADX INFO: renamed from: c */
    private TextView f2700c;

    /* JADX INFO: renamed from: d */
    private TextView f2701d;

    /* JADX INFO: renamed from: e */
    private TextView f2702e;

    /* JADX INFO: renamed from: f */
    private TextView f2703f;

    /* JADX INFO: renamed from: g */
    private EditText f2704g;

    /* JADX INFO: renamed from: h */
    private Handler f2705h = new Handler() { // from class: com.lenovo.safecenter.MainTab.CallNotifyActivity.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    InputMethodManager m = (InputMethodManager) CallNotifyActivity.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
                case 1:
                    CallNotifyActivity.this.finish();
                    break;
            }
        }
    };

    /* JADX WARN: Type inference failed for: r1v38, types: [com.lenovo.safecenter.MainTab.CallNotifyActivity$1] */
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Intent it = getIntent();
        if (it != null) {
            this.f2699b = it.getIntExtra("style", 0);
            Log.i("style", "style==" + this.f2699b);
        }
        this.f2698a = PwdUtil.getPassword(this);
        if (this.f2698a == null || this.f2698a.length() == 0) {
            setContentView(C0415R.layout.dialog_info);
        } else {
            setContentView(C0415R.layout.input_password);
            new Thread() { // from class: com.lenovo.safecenter.MainTab.CallNotifyActivity.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    CallNotifyActivity.this.f2705h.sendEmptyMessageDelayed(0, 500L);
                }
            }.start();
        }
        ((LinearLayout) findViewById(C0415R.id.input_password_layout)).setBackgroundResource(C0415R.drawable.dialog_center);
        if (this.f2698a != null && this.f2698a.length() != 0) {
            findViewById(C0415R.id.input_title_layout).setVisibility(0);
            ((TextView) findViewById(C0415R.id.txt_message)).setText(C0415R.string.input_privacy_pwd);
            this.f2704g = (EditText) findViewById(C0415R.id.edt_input_pwd);
            this.f2700c = (TextView) findViewById(C0415R.id.input_pwd_ok);
            this.f2700c.setVisibility(0);
            this.f2700c.setOnClickListener(this);
            this.f2701d = (TextView) findViewById(C0415R.id.input_pwd_cancel);
            this.f2701d.setVisibility(0);
            this.f2701d.setOnClickListener(this);
            return;
        }
        this.f2703f = (Button) findViewById(C0415R.id.dialog_ok);
        this.f2702e = (Button) findViewById(C0415R.id.dialog_cancel);
        this.f2703f.setOnClickListener(this);
        this.f2702e.setOnClickListener(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        if (this.f2703f != null && v.getId() == this.f2703f.getId()) {
            startActivity(new Intent(this, (Class<?>) LeSafeMainActivity.class));
            finish();
            return;
        }
        if (this.f2700c != null && v.getId() == this.f2700c.getId()) {
            String pwd = this.f2704g.getText().toString();
            if (PwdUtil.checkPassword(getApplicationContext(), pwd)) {
                switch (this.f2699b) {
                    case 500:
                        Intent callIntent = new Intent(this, (Class<?>) SofeModeMain.class);
                        callIntent.putExtra("Type", SofeModeMain.TS_CALL);
                        callIntent.putExtra("pwd", this.f2698a);
                        startActivity(callIntent);
                        finish();
                        break;
                }
                return;
            }
            if (pwd.length() == 0) {
                Toast.makeText(this, C0415R.string.error_tips_null, 0).show();
                return;
            } else {
                Toast.makeText(this, C0415R.string.pwd_error, 0).show();
                return;
            }
        }
        if (this.f2701d != null && v.getId() == this.f2701d.getId()) {
            finish();
        }
    }
}
