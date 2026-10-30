package com.lenovo.safecenter.lenovoAntiSpam.views;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.SpannableString;
import android.text.style.AbsoluteSizeSpan;
import android.text.style.ForegroundColorSpan;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.lenovoAntiSpam.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.domain.SignCall;
import com.lenovo.safecenter.lenovoAntiSpam.utils.CheckCenter;
import com.lenovo.safecenter.lenovoAntiSpam.utils.HttpUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class SpamConfirm extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: b */
    private TextView f4275b;

    /* JADX INFO: renamed from: c */
    private TextView f4276c;

    /* JADX INFO: renamed from: d */
    private TextView f4277d;

    /* JADX INFO: renamed from: e */
    private TextView f4278e;

    /* JADX INFO: renamed from: f */
    private TextView f4279f;

    /* JADX INFO: renamed from: g */
    private TextView f4280g;

    /* JADX INFO: renamed from: h */
    private ImageView f4281h;

    /* JADX INFO: renamed from: i */
    private int f4282i;

    /* JADX INFO: renamed from: j */
    private AppDatabase f4283j;
    public int pos = -1;

    /* JADX INFO: renamed from: a */
    Handler f4274a = new Handler() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.SpamConfirm.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 2:
                    Toast.makeText(SpamConfirm.this, C0415R.string.sign_success, 0).show();
                    SpamConfirm.this.finish();
                    break;
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.signdialogupdate);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        initViews();
        this.f4283j = new AppDatabase(this);
    }

    public void initViews() {
        this.f4281h = (ImageView) findViewById(C0415R.id.comfir_closed);
        this.f4275b = (TextView) findViewById(C0415R.id.title);
        this.f4276c = (TextView) findViewById(C0415R.id.sign_txt1);
        this.f4277d = (TextView) findViewById(C0415R.id.sign_txt2);
        this.f4278e = (TextView) findViewById(C0415R.id.sign_txt3);
        this.f4279f = (TextView) findViewById(C0415R.id.sign_txt4);
        this.f4280g = (TextView) findViewById(C0415R.id.sign_txt5);
        this.f4276c.setOnClickListener(this);
        this.f4277d.setOnClickListener(this);
        this.f4278e.setOnClickListener(this);
        this.f4279f.setOnClickListener(this);
        this.f4280g.setOnClickListener(this);
        this.f4281h.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.SpamConfirm.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                SpamConfirm.this.finish();
            }
        });
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.sign_txt1 /* 2131297629 */:
                this.f4282i = 1;
                addSign(1);
                break;
            case C0415R.id.sign_txt2 /* 2131297630 */:
                this.f4282i = 11;
                addSign(11);
                break;
            case C0415R.id.sign_txt3 /* 2131297631 */:
                this.f4282i = 2;
                addSign(2);
                break;
            case C0415R.id.sign_txt4 /* 2131297633 */:
                this.f4282i = 12;
                addSign(12);
                break;
            case C0415R.id.sign_txt5 /* 2131297634 */:
                this.f4282i = 3;
                addSign(3);
                break;
        }
    }

    public String getDescFromType(int stype) {
        if (stype == 1) {
            return getString(C0415R.string.signtype1);
        }
        if (stype == 2) {
            return getString(C0415R.string.signtype2);
        }
        if (stype == 3) {
            return getString(C0415R.string.signtype3);
        }
        if (stype == 11) {
            return getString(C0415R.string.signtype4);
        }
        if (stype == 12) {
            return getString(C0415R.string.signtype5);
        }
        if (stype == 13) {
            return getString(C0415R.string.signtype6);
        }
        return getString(C0415R.string.signtype1);
    }

    /* JADX WARN: Type inference failed for: r2v10, types: [com.lenovo.safecenter.lenovoAntiSpam.views.SpamConfirm$3] */
    public void addSign(int flag) {
        SignCall info = new SignCall();
        info.setNumber(getIntent().getStringExtra(com.lenovo.safecenter.database.AppDatabase.NUMBER));
        info.setAddTime(String.valueOf(System.currentTimeMillis()));
        info.setbType(this.pos > 3 ? 1 : 0);
        info.setsType(flag);
        info.setTotalCall(getIntent().getIntExtra("wastetime", 0));
        Log.i(DatabaseTables.LOG_MESSAGE, "addSignaddSignaddSignaddSign===" + flag);
        this.f4283j.insertSignCall(info);
        if (flag == 3) {
            boolean bool = CheckCenter.insertLocalBlack(this, 2, getIntent().getStringExtra(com.lenovo.safecenter.database.AppDatabase.NUMBER));
            Log.i(DatabaseTables.LOG_MESSAGE, "addSignaddSignaddSignaddSign===" + flag + ">>>>" + bool + com.lenovo.safecenter.database.AppDatabase.NUMBER + getIntent().getStringExtra(com.lenovo.safecenter.database.AppDatabase.NUMBER));
        }
        new Thread() { // from class: com.lenovo.safecenter.lenovoAntiSpam.views.SpamConfirm.3
            @Override // java.lang.Thread, java.lang.Runnable
            public final void run() {
                try {
                    int ff = new HttpUtils().upload_sign(SpamConfirm.this, SpamConfirm.this.getIntent().getStringExtra(com.lenovo.safecenter.database.AppDatabase.NUMBER), String.valueOf(SpamConfirm.this.f4282i));
                    if (ff == 2) {
                        SpamConfirm.this.f4283j.updateSign(SpamConfirm.this.getIntent().getStringExtra(com.lenovo.safecenter.database.AppDatabase.NUMBER));
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
        showToast();
        finish();
    }

    public void showToast() {
        Toast toast = new Toast(this);
        View view = LayoutInflater.from(this).inflate(C0415R.layout.signtoast, (ViewGroup) null);
        toast.setView(view);
        TextView txt1 = (TextView) toast.getView().findViewById(C0415R.id.toast_big);
        TextView txt2 = (TextView) toast.getView().findViewById(C0415R.id.toast_small);
        String txt1_content = String.format(getString(C0415R.string.report_sign), getDescFromType(this.f4282i));
        SpannableString spannable = new SpannableString(txt1_content);
        spannable.setSpan(new AbsoluteSizeSpan(21, true), txt1_content.length() - getDescFromType(this.f4282i).length(), txt1_content.length(), 33);
        txt1.setText(spannable);
        int count = this.f4283j.getSignCount();
        String txt2_content = String.format(getString(C0415R.string.report_count), Integer.valueOf(count));
        SpannableString spannable2 = new SpannableString(txt2_content);
        Log.i("mes", "===" + txt2_content.length() + "===" + String.valueOf(count).length() + "=====" + ((txt2_content.length() - String.valueOf(count).length()) - 1) + "====" + (txt2_content.length() - 1));
        spannable2.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.signblue)), txt2_content.length() - (String.valueOf(count).length() + 1), txt2_content.length() - 1, 33);
        txt2.setText(spannable2);
        toast.setDuration(1);
        Log.i("Gravity", (Const.getScreenWidth() / 2) + "==" + (Const.getScreenHeight() / 2));
        toast.setGravity(17, 0, 0);
        toast.show();
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
        this.f4275b.setText(String.format(getString(C0415R.string.confirm_title), getIntent().getStringExtra(com.lenovo.safecenter.database.AppDatabase.NUMBER)));
    }
}
