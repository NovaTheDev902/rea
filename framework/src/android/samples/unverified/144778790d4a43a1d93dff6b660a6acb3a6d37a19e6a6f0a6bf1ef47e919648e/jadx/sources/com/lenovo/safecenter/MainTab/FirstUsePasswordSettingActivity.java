package com.lenovo.safecenter.MainTab;

import android.R;
import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;

/* JADX INFO: loaded from: classes.dex */
public class FirstUsePasswordSettingActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: b */
    private Button f2709b;

    /* JADX INFO: renamed from: d */
    private String f2711d;

    /* JADX INFO: renamed from: e */
    private EditText f2712e;

    /* JADX INFO: renamed from: f */
    private EditText f2713f;

    /* JADX INFO: renamed from: g */
    private EditText f2714g;

    /* JADX INFO: renamed from: h */
    private View f2715h;

    /* JADX INFO: renamed from: i */
    private View f2716i;

    /* JADX INFO: renamed from: j */
    private View f2717j;

    /* JADX INFO: renamed from: k */
    private String[] f2718k;

    /* JADX INFO: renamed from: l */
    private long f2719l;

    /* JADX INFO: renamed from: m */
    private ImageView f2720m;

    /* JADX INFO: renamed from: n */
    private ImageView f2721n;

    /* JADX INFO: renamed from: a */
    private String f2708a = null;

    /* JADX INFO: renamed from: c */
    private int f2710c = 0;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1240a(FirstUsePasswordSettingActivity x0) {
        Intent intent = new Intent();
        if (Const.ACTION_JUMP_CHILD_MODE.equals(x0.f2708a)) {
            intent.setAction(Const.ACTION_JUMP_CHILD_MODE);
            x0.startActivity(intent);
        } else if (Const.ACTION_JUMP_KID_MODE.equals(x0.f2708a)) {
            WflUtils.jumpKidModeOrDownloadpage(x0);
        } else if (Const.ACTION_JUMP_GUEST_MODE.equals(x0.f2708a)) {
            intent.setAction(Const.ACTION_JUMP_GUEST_MODE);
            x0.startActivity(intent);
        } else if (Const.ACTION_JUMP_RPIVACY_SAFE.equals(x0.f2708a)) {
            WflUtils.jumpPrivatezoneOrDownloadpage(x0);
        } else if (Const.ACTION_JUMP_APP_LOCK.equals(x0.f2708a)) {
            WflUtils.jumpAppLockOrDownloadpage(x0);
        } else if (Const.ACTION_JUMP_PROTECT_THIEF.equals(x0.f2708a)) {
            intent.setAction(Const.ACTION_JUMP_PROTECT_THIEF);
            x0.startActivity(intent);
        } else if (Const.ACTION_JUMP_CHILD_MODE_SWITCH.equals(x0.f2708a) || Const.ACTION_JUMP_GUEST_MODE_SWITCH.equals(x0.f2708a)) {
            LeSafeObservable.get(x0).noticeChangeGuestModeSuccess();
        } else if (Const.ACTION_JUMP_SETTING_PASSWORD.equals(x0.f2708a) || Const.ACTION_MODIFY_PASSWORD_USE_ANSWER.equals(x0.f2708a) || Const.ACTION_MODIFY_PASSWORD_USE_PRE_PASSWORD.equals(x0.f2708a)) {
            LeSafeObservable.get(x0).noticeChangePassword();
        } else if (Const.ACTION_JUMP_SET_GESTURE.equals(x0.f2708a)) {
            intent.setAction(Const.ACTION_JUMP_SET_GESTURE);
            x0.startActivity(intent);
        } else if (Const.ACTION_JUMP_ADMIN_GESTURE.equals(x0.f2708a)) {
            intent.setAction(Const.ACTION_JUMP_ADMIN_GESTURE);
            x0.startActivity(intent);
        }
        x0.finish();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_first_use_password_setting_layout);
        getWindow().setSoftInputMode(34);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.pwd_set);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.FirstUsePasswordSettingActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                FirstUsePasswordSettingActivity.this.finish();
            }
        });
        this.f2718k = getResources().getStringArray(C0415R.array.array_pwd_question);
        this.f2708a = getIntent().getAction();
        Log.i("wu0wu", "FirstUsePasswordSettingActivity mAction=" + this.f2708a);
        this.f2715h = findViewById(C0415R.id.inputPwd_layout);
        this.f2717j = findViewById(C0415R.id.input_pwd_bg);
        this.f2717j.setOnClickListener(this);
        this.f2720m = (ImageView) findViewById(C0415R.id.img_pwd_Set);
        this.f2721n = (ImageView) findViewById(C0415R.id.img_pwd_question);
        this.f2716i = findViewById(C0415R.id.inputQuestion_layout);
        this.f2712e = (EditText) findViewById(C0415R.id.first_inputPwd_editText);
        this.f2713f = (EditText) findViewById(C0415R.id.second_inputPwd_editText);
        this.f2714g = (EditText) findViewById(C0415R.id.answer_editText);
        this.f2709b = (Button) findViewById(C0415R.id.submitBtn);
        this.f2709b.setOnClickListener(this);
        m1239a();
    }

    /* JADX INFO: renamed from: a */
    private void m1239a() {
        switch (this.f2710c) {
            case 0:
                this.f2720m.setBackgroundResource(C0415R.drawable.first_set_password_tab_seleted);
                this.f2721n.setBackgroundResource(C0415R.drawable.first_set_password_tab_normal);
                this.f2709b.setText(C0415R.string.next_step);
                this.f2715h.setVisibility(0);
                this.f2716i.setVisibility(8);
                break;
            case 1:
                this.f2720m.setBackgroundResource(C0415R.drawable.first_set_password_tab_normal);
                this.f2721n.setBackgroundResource(C0415R.drawable.first_set_password_tab_seleted);
                this.f2709b.setText(C0415R.string.Complete);
                this.f2715h.setVisibility(8);
                this.f2716i.setVisibility(0);
                String[] preAnswer = PwdUtil.queryPwdQuestionAndAnswerWithJieMi(this);
                if ((!Const.ACTION_MODIFY_PASSWORD_USE_ANSWER.equals(this.f2708a) && !Const.ACTION_MODIFY_PASSWORD_USE_PRE_PASSWORD.equals(this.f2708a)) || TextUtils.isEmpty(preAnswer[1])) {
                    this.f2714g.setHint(C0415R.string.antispamhand_number_hit);
                } else {
                    this.f2714g.setText(preAnswer[1]);
                }
                ArrayAdapter arrayAdapter = new ArrayAdapter(this, R.layout.simple_spinner_item, this.f2718k);
                arrayAdapter.setDropDownViewResource(R.layout.simple_spinner_dropdown_item);
                Spinner spinner = (Spinner) findViewById(C0415R.id.spinner_question);
                spinner.setAdapter((SpinnerAdapter) arrayAdapter);
                for (int i = 0; i < this.f2718k.length; i++) {
                    if (this.f2718k[i].equals(preAnswer[0])) {
                        spinner.setSelection(i);
                        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.lenovo.safecenter.MainTab.FirstUsePasswordSettingActivity.2
                            @Override // android.widget.AdapterView.OnItemSelectedListener
                            public final void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                                FirstUsePasswordSettingActivity.this.f2719l = id;
                            }

                            @Override // android.widget.AdapterView.OnItemSelectedListener
                            public final void onNothingSelected(AdapterView<?> arg0) {
                            }
                        });
                    }
                    break;
                }
                spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.lenovo.safecenter.MainTab.FirstUsePasswordSettingActivity.2
                    @Override // android.widget.AdapterView.OnItemSelectedListener
                    public final void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                        FirstUsePasswordSettingActivity.this.f2719l = id;
                    }

                    @Override // android.widget.AdapterView.OnItemSelectedListener
                    public final void onNothingSelected(AdapterView<?> arg0) {
                    }
                });
                break;
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.input_pwd_bg /* 2131296305 */:
                InputMethodManager imm = (InputMethodManager) getSystemService("input_method");
                imm.hideSoftInputFromWindow(this.f2717j.getWindowToken(), 0);
                break;
            case C0415R.id.submitBtn /* 2131296318 */:
                switch (this.f2710c) {
                    case 0:
                        String string = this.f2712e.getText().toString();
                        String string2 = this.f2713f.getText().toString();
                        if (string.length() == 6 && string2.length() == 6) {
                            if (!string.equals(string2)) {
                                Toast.makeText(this, getString(C0415R.string.error_diff), 0).show();
                            } else {
                                this.f2711d = string2;
                                this.f2710c = 1;
                                m1239a();
                            }
                        } else if (string.length() != 6) {
                            Toast.makeText(this, getString(C0415R.string.first_pwd_error_insuff), 0).show();
                        } else if (string2.length() != 6) {
                            Toast.makeText(this, getString(C0415R.string.second_pwd_error_insuff), 0).show();
                        }
                        break;
                    case 1:
                        String str = this.f2718k[(int) this.f2719l];
                        String string3 = this.f2714g.getText() == null ? null : this.f2714g.getText().toString();
                        if (TextUtils.isEmpty(str)) {
                            Toast.makeText(this, getString(C0415R.string.password_question_no_null_text), 0).show();
                        } else if (!TextUtils.isEmpty(string3)) {
                            PwdUtil.insertPwdQuestionAndAnswer(this, this.f2711d, str, string3);
                            new CustomDialog.Builder(this).setTitle(getString(C0415R.string.password_notice_title)).setMessage(getString(C0415R.string.password_notice)).setPositiveButton(getString(C0415R.string.known), new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.FirstUsePasswordSettingActivity.3
                                @Override // android.content.DialogInterface.OnClickListener
                                public final void onClick(DialogInterface dialog, int which) {
                                    FirstUsePasswordSettingActivity.m1240a(FirstUsePasswordSettingActivity.this);
                                }
                            }).show();
                        } else {
                            Toast.makeText(this, getString(C0415R.string.password_answer_no_null_text), 0).show();
                        }
                        break;
                }
                break;
        }
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
    }
}
