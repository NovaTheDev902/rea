package com.lenovo.safecenter.platform;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public class AgainstTheftSafeMailSetActivity extends Activity {

    /* JADX INFO: renamed from: a */
    TextView f4868a;

    /* JADX INFO: renamed from: b */
    EditText f4869b;

    /* JADX INFO: renamed from: c */
    private String f4870c;

    /* JADX INFO: renamed from: d */
    private String f4871d;

    /* JADX INFO: renamed from: e */
    private ActivityManager f4872e;

    /* JADX INFO: renamed from: c */
    static /* synthetic */ void m2008c(AgainstTheftSafeMailSetActivity x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.error).setMessage(C0415R.string.mail_error).setNegativeButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafeMailSetActivity.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface arg0, int arg1) {
            }
        }).show();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_antitheft_safemail_layout);
        getWindow().setSoftInputMode(34);
        TextView topBar = (TextView) findViewById(C0415R.id.txt_title);
        topBar.setText(C0415R.string.backup_mail_set);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafeMailSetActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AgainstTheftSafeMailSetActivity.this.finish();
            }
        });
        this.f4872e = (ActivityManager) getSystemService("activity");
        this.f4870c = Const.getSafeMail();
        this.f4869b = (EditText) findViewById(C0415R.id.set_safemail_edittext);
        this.f4869b.setText(this.f4870c);
        this.f4868a = (TextView) findViewById(C0415R.id.okbtn);
        this.f4868a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.platform.AgainstTheftSafeMailSetActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AgainstTheftSafeMailSetActivity.this.f4871d = AgainstTheftSafeMailSetActivity.this.f4869b.getText().toString();
                if (AgainstTheftSafeMailSetActivity.this.f4870c.equals(AgainstTheftSafeMailSetActivity.this.f4871d) && !AgainstTheftSafeMailSetActivity.this.f4871d.equals("")) {
                    Toast.makeText(AgainstTheftSafeMailSetActivity.this.getApplicationContext(), C0415R.string.no_edit, 1).show();
                    AgainstTheftSafeMailSetActivity.this.finish();
                }
                if (AgainstTheftSafeMailSetActivity.this.f4871d.length() == 0 || AgainstTheftSafeMailSetActivity.this.isMailNO(AgainstTheftSafeMailSetActivity.this.f4871d)) {
                    Const.setSafeMail(AgainstTheftSafeMailSetActivity.this.f4871d);
                    if (AgainstTheftSafeMailSetActivity.this.f4871d.equals("")) {
                        AgainstTheftSafeMailSetActivity.this.finish();
                    }
                    if (!AgainstTheftSafeMailSetActivity.this.f4870c.equals(AgainstTheftSafeMailSetActivity.this.f4871d) && !AgainstTheftSafeMailSetActivity.this.f4871d.equals("")) {
                        AgainstTheftSafeMailSetActivity.this.finish();
                        return;
                    }
                    return;
                }
                AgainstTheftSafeMailSetActivity.m2008c(AgainstTheftSafeMailSetActivity.this);
            }
        });
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        if (!this.f4872e.getRunningTasks(1).get(0).topActivity.getPackageName().equals(getPackageName())) {
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

    public boolean isMailNO(String mail) {
        Pattern p = Pattern.compile("^[\\w-]+(\\.[\\w-]+)*@[\\w-]+(\\.[\\w-]+)+$");
        Matcher m = p.matcher(mail);
        return m.matches();
    }
}
