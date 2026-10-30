package com.lenovo.safecenter.platform;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public class AgainstTheftPromptActivity extends Activity {

    /* JADX INFO: renamed from: a */
    CustomDialog f4855a;

    /* JADX INFO: renamed from: b */
    private TextView f4856b;

    /* JADX INFO: renamed from: c */
    private EditText f4857c;

    /* JADX INFO: renamed from: d */
    private String f4858d;

    /* JADX INFO: renamed from: e */
    private ImageView f4859e;

    /* JADX INFO: renamed from: f */
    private ActivityManager f4860f;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m2002a(AgainstTheftPromptActivity x0) {
        View viewInflate = LayoutInflater.from(x0.getApplicationContext()).inflate(C0415R.layout.dialog_send_sms_prompt, (ViewGroup) null);
        x0.f4857c = (EditText) viewInflate.findViewById(C0415R.id.dialog_send_prom_phone_number);
        if (x0.f4858d.equals("")) {
            x0.f4857c.setHint(C0415R.string.input_phone_number);
        } else {
            x0.f4857c.setText(x0.f4858d);
        }
        if (x0.f4855a == null) {
            x0.f4855a = new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setContentView(viewInflate).setPositiveButton(C0415R.string.send_on, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftPromptActivity.5
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface arg0, int arg1) {
                    if (AgainstTheftPromptActivity.this.isMobileNO(AgainstTheftPromptActivity.this.f4857c.getText().toString())) {
                        String password = PwdUtil.getPasswordWithJieMi(AgainstTheftPromptActivity.this);
                        DoubleCardUtils.sendMessage(AgainstTheftPromptActivity.this.getApplicationContext(), AgainstTheftPromptActivity.this.f4857c.getText().toString(), AgainstTheftPromptActivity.this.getString(C0415R.string.distant_com) + " " + password + AgainstTheftPromptActivity.this.getString(C0415R.string.command_content), true);
                        Const.isTariff = false;
                    } else {
                        AgainstTheftPromptActivity.m2004c(AgainstTheftPromptActivity.this);
                        AgainstTheftPromptActivity.this.f4855a = null;
                    }
                }
            }).setNegativeButton(C0415R.string.send_off_, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftPromptActivity.4
                @Override // android.content.DialogInterface.OnClickListener
                public final void onClick(DialogInterface dialog, int which) {
                    AgainstTheftPromptActivity.this.f4855a = null;
                }
            }).create();
            x0.f4855a.setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftPromptActivity.6
                @Override // android.content.DialogInterface.OnDismissListener
                public final void onDismiss(DialogInterface dialog) {
                    AgainstTheftPromptActivity.this.f4855a = null;
                }
            });
        }
        if (x0.f4855a.isShowing()) {
            return;
        }
        x0.f4855a.show();
    }

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m2004c(AgainstTheftPromptActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.error).setMessage(C0415R.string.phonenumber_error).setNeutralButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftPromptActivity.7
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_antitheft_prompt_layout);
        TextView topBar = (TextView) findViewById(C0415R.id.txt_title);
        topBar.setText(C0415R.string.remind);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftPromptActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AgainstTheftPromptActivity.this.finish();
            }
        });
        this.f4860f = (ActivityManager) getSystemService("activity");
        this.f4858d = Const.getSafePhoneNumber();
        this.f4856b = (TextView) findViewById(C0415R.id.sendsms_btn);
        this.f4856b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftPromptActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AgainstTheftPromptActivity.m2002a(AgainstTheftPromptActivity.this);
            }
        });
        this.f4859e = (ImageView) findViewById(C0415R.id.antitheft_safephone_imageView);
        this.f4859e.setOnLongClickListener(new View.OnLongClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftPromptActivity.3
            @Override // android.view.View.OnLongClickListener
            public final boolean onLongClick(View v) {
                AgainstTheftPromptActivity.this.startActivity(new Intent("com.lenovo.antivirus.gifmain"));
                return true;
            }
        });
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        if (!this.f4860f.getRunningTasks(1).get(0).topActivity.getPackageName().equals(getPackageName())) {
            setResult(100);
            finish();
        }
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    public boolean isMobileNO(String mobiles) {
        Pattern p = Pattern.compile("^((\\+86)|(86))?((13[0-9])|(15[^4,\\D])|(18[0-9]))\\d{8}$");
        Matcher m = p.matcher(mobiles);
        return m.matches();
    }
}
