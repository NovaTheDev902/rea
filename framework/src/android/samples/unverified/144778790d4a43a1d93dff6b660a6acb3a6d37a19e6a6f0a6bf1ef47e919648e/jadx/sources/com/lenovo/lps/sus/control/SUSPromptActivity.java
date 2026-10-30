package com.lenovo.lps.sus.control;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.os.Handler;
import android.provider.Settings;
import android.text.method.ScrollingMovementMethod;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.TextView;
import com.lenovo.lps.sus.EventType;
import com.lenovo.lps.sus.p007b.C0087c;
import com.lenovo.lps.sus.p007b.EnumC0088d;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import com.lenovo.providers.querypermissions.QueryPermissions;
import java.net.URLDecoder;

/* JADX INFO: loaded from: classes.dex */
public class SUSPromptActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private static String f1392a = "SUS_VERSIONUPDATE";

    /* JADX INFO: renamed from: b */
    private static String f1393b = "layout";

    /* JADX INFO: renamed from: c */
    private static String f1394c = "sus_updateinfo_dialog";

    /* JADX INFO: renamed from: d */
    private static String f1395d = QueryPermissions.f1958ID;

    /* JADX INFO: renamed from: e */
    private static String f1396e = "SUS_newversioninfo";

    /* JADX INFO: renamed from: f */
    private static String f1397f = "SUS_versiondescribe";

    /* JADX INFO: renamed from: g */
    private static String f1398g = "versioninfo";

    /* JADX INFO: renamed from: h */
    private static String f1399h = "newversioncode";

    /* JADX INFO: renamed from: i */
    private static Handler f1400i = null;

    /* JADX INFO: renamed from: j */
    private static AlertDialog f1401j = null;

    /* JADX INFO: renamed from: k */
    private Context f1402k = null;

    /* JADX INFO: renamed from: l */
    private boolean f1403l = true;

    /* JADX INFO: renamed from: m */
    private boolean f1404m = false;

    /* JADX INFO: renamed from: n */
    private int f1405n = 0;

    /* JADX INFO: renamed from: a */
    public static void m431a() {
        if (f1401j != null) {
            f1401j.dismiss();
        }
    }

    /* JADX INFO: renamed from: a */
    public static void m432a(Handler handler) {
        f1400i = handler;
    }

    @Override // android.app.Activity
    public void finish() {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity finish isAbortUpdateFlag=" + this.f1403l);
        if (this.f1404m && !this.f1403l) {
            C0104ae.m440a(EventType.SUS_UPDATEPROMPT_USER_CONFIRM);
        } else if (this.f1403l) {
            this.f1403l = false;
            C0104ae.m440a(EventType.SUS_UPDATEPROMPT_USER_CANCEL);
        }
        super.finish();
    }

    @Override // android.app.Activity, android.content.ComponentCallbacks
    public void onConfigurationChanged(Configuration configuration) {
        super.onConfigurationChanged(configuration);
        new Settings.System();
        int i = configuration.orientation;
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle bundle) {
        CheckBox checkBox;
        TextView textView;
        TextView textView2;
        super.onCreate(bundle);
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity .onCreate() begin");
        Intent intent = getIntent();
        requestWindowFeature(1);
        String stringExtra = intent.getStringExtra(f1398g);
        String stringExtra2 = intent.getStringExtra("UPDATE_DESC");
        int intExtra = intent.getIntExtra(f1399h, 0);
        String strDecode = (stringExtra2 == null || stringExtra2.length() <= 0) ? stringExtra2 : URLDecoder.decode(stringExtra2);
        boolean booleanExtra = intent.getBooleanExtra("showUserSettingsEnable", false);
        this.f1402k = this;
        this.f1405n = getResources().getConfiguration().orientation;
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onCreate() orientation=" + this.f1405n);
        this.f1404m = false;
        EnumC0088d enumC0088dM299c = C0087c.m299c(intent.getIntExtra("usersettings", 0));
        View viewInflate = LayoutInflater.from(this).inflate(C0092c.m323a(this, f1393b, f1394c), (ViewGroup) null);
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle(C0092c.m343b(this, f1392a));
        builder.setView(viewInflate);
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity popupPromptionDialog create");
        builder.setPositiveButton(C0092c.m343b(this, "SUS_UPDATE"), new DialogInterfaceOnClickListenerC0099a(this));
        builder.setNegativeButton(C0092c.m343b(this, "SUS_CANCEL"), new DialogInterfaceOnClickListenerC0133u(this));
        builder.setOnKeyListener(new DialogInterfaceOnKeyListenerC0131s(this));
        f1401j = builder.create();
        f1401j.setCancelable(false);
        f1401j.setOnCancelListener(new DialogInterfaceOnCancelListenerC0129q(this));
        f1401j.setOnDismissListener(new DialogInterfaceOnDismissListenerC0127o(this));
        if (f1401j == null) {
            C0098i.m409a(C0092c.f1339b, "null == myCustomDialog!!!");
            C0104ae.m447b();
            return;
        }
        f1401j.show();
        if (stringExtra != null && stringExtra.length() > 0 && (textView2 = (TextView) f1401j.findViewById(C0092c.m323a(this, f1395d, f1396e))) != null) {
            textView2.setText(stringExtra);
        }
        if (!C0104ae.m461h() && strDecode != null && strDecode.length() > 0 && (textView = (TextView) f1401j.findViewById(C0092c.m323a(this, f1395d, f1397f))) != null) {
            textView.setText(strDecode);
            textView.setMovementMethod(ScrollingMovementMethod.getInstance());
        }
        if (!booleanExtra) {
            CheckBox checkBox2 = (CheckBox) f1401j.findViewById(C0092c.m323a(this, QueryPermissions.f1958ID, "usersettings_newverprompt_checkbox"));
            if (checkBox2 != null) {
                checkBox2.setVisibility(8);
                return;
            }
            return;
        }
        if (!C0092c.m355d() || (checkBox = (CheckBox) f1401j.findViewById(C0092c.m323a(this, QueryPermissions.f1958ID, "usersettings_newverprompt_checkbox"))) == null) {
            return;
        }
        checkBox.setText("  " + C0092c.m343b(this, "SUS_SETTINGS_NEWVERPROMPT"));
        if (EnumC0088d.UPDATEACTION_NEWVERPROMPT == enumC0088dM299c) {
            checkBox.setChecked(true);
        } else {
            checkBox.setChecked(false);
        }
        checkBox.setOnCheckedChangeListener(new C0103ad(this, intExtra));
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onDestroy myContext=" + this.f1402k);
        Integer numValueOf = Integer.valueOf(getResources().getConfiguration().orientation);
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onDestroy() orientation=" + this.f1405n + "; currentOrientation=" + numValueOf);
        if (numValueOf.equals(Integer.valueOf(this.f1405n)) && this.f1403l) {
            this.f1403l = false;
            C0104ae.m447b();
        }
        if (this.f1402k != null) {
            this.f1402k = null;
        }
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onDestroy myCustomDialog=" + f1401j);
        if (f1401j != null) {
            f1401j.dismiss();
            f1401j = null;
        }
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onPause() {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onPause");
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onRestart() {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onRestart");
        super.onRestart();
    }

    @Override // android.app.Activity
    protected void onResume() {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onResume");
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onStart() {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onStart");
        super.onStart();
    }

    @Override // android.app.Activity
    protected void onStop() {
        C0098i.m409a(C0092c.f1339b, "SUSPromptActivity onStop");
        super.onStop();
    }
}
