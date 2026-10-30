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
import org.apache.commons.httpclient.HttpStatus;

/* JADX INFO: loaded from: classes.dex */
public class SMSNotifyActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private String f2804a;

    /* JADX INFO: renamed from: b */
    private int f2805b;

    /* JADX INFO: renamed from: c */
    private TextView f2806c;

    /* JADX INFO: renamed from: d */
    private TextView f2807d;

    /* JADX INFO: renamed from: e */
    private TextView f2808e;

    /* JADX INFO: renamed from: f */
    private TextView f2809f;

    /* JADX INFO: renamed from: g */
    private EditText f2810g;

    /* JADX INFO: renamed from: h */
    private Handler f2811h = new Handler() { // from class: com.lenovo.safecenter.MainTab.SMSNotifyActivity.2
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    InputMethodManager m = (InputMethodManager) SMSNotifyActivity.this.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
                case 1:
                    SMSNotifyActivity.this.finish();
                    break;
            }
        }
    };

    /* JADX WARN: Type inference failed for: r1v38, types: [com.lenovo.safecenter.MainTab.SMSNotifyActivity$1] */
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Intent it = getIntent();
        if (it != null) {
            this.f2805b = it.getIntExtra("style", 0);
            Log.i("style", "style==" + this.f2805b);
        }
        this.f2804a = PwdUtil.getPassword(this);
        if (this.f2804a == null || this.f2804a.length() == 0) {
            setContentView(C0415R.layout.dialog_info);
        } else {
            setContentView(C0415R.layout.input_password);
            new Thread() { // from class: com.lenovo.safecenter.MainTab.SMSNotifyActivity.1
                @Override // java.lang.Thread, java.lang.Runnable
                public final void run() {
                    SMSNotifyActivity.this.f2811h.sendEmptyMessageDelayed(0, 500L);
                }
            }.start();
        }
        ((LinearLayout) findViewById(C0415R.id.input_password_layout)).setBackgroundResource(C0415R.drawable.dialog_center);
        if (this.f2804a != null && this.f2804a.length() != 0) {
            findViewById(C0415R.id.input_title_layout).setVisibility(0);
            ((TextView) findViewById(C0415R.id.txt_message)).setText(C0415R.string.input_privacy_pwd);
            this.f2810g = (EditText) findViewById(C0415R.id.edt_input_pwd);
            this.f2806c = (TextView) findViewById(C0415R.id.input_pwd_ok);
            this.f2806c.setVisibility(0);
            this.f2806c.setOnClickListener(this);
            this.f2807d = (TextView) findViewById(C0415R.id.input_pwd_cancel);
            this.f2807d.setVisibility(0);
            this.f2807d.setOnClickListener(this);
            return;
        }
        this.f2809f = (Button) findViewById(C0415R.id.dialog_ok);
        this.f2808e = (Button) findViewById(C0415R.id.dialog_cancel);
        this.f2809f.setOnClickListener(this);
        this.f2808e.setOnClickListener(this);
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
        if (this.f2809f != null && v.getId() == this.f2809f.getId()) {
            startActivity(new Intent(this, (Class<?>) LeSafeMainActivity.class));
            finish();
            return;
        }
        if (this.f2806c != null && v.getId() == this.f2806c.getId()) {
            String pwd = this.f2810g.getText().toString();
            if (PwdUtil.checkPassword(getApplicationContext(), pwd)) {
                switch (this.f2805b) {
                    case HttpStatus.SC_HTTP_VERSION_NOT_SUPPORTED /* 505 */:
                        Intent mIntent = new Intent(this, (Class<?>) SofeModeMain.class);
                        mIntent.putExtra("Type", SofeModeMain.TS_SMS);
                        mIntent.putExtra("pwd", this.f2804a);
                        startActivity(mIntent);
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
        if (this.f2807d != null && v.getId() == this.f2807d.getId()) {
            finish();
        }
    }
}
