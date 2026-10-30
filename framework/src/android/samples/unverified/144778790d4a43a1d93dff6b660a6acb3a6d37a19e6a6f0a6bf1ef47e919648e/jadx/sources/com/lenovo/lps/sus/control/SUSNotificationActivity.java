package com.lenovo.lps.sus.control;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import com.lenovo.providers.querypermissions.QueryPermissions;

/* JADX INFO: loaded from: classes.dex */
public class SUSNotificationActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private static String f1381a = "SUS_NOTIFICATION_TITLE";

    /* JADX INFO: renamed from: b */
    private static String f1382b = "sus_notification_dialog";

    /* JADX INFO: renamed from: c */
    private static String f1383c = QueryPermissions.f1958ID;

    /* JADX INFO: renamed from: d */
    private static AlertDialog f1384d = null;

    /* JADX INFO: renamed from: h */
    private static Integer f1385h = 3;

    /* JADX INFO: renamed from: e */
    private Context f1386e = null;

    /* JADX INFO: renamed from: f */
    private boolean f1387f = true;

    /* JADX INFO: renamed from: g */
    private int f1388g = 0;

    /* JADX INFO: renamed from: i */
    private final int f1389i = 1500;

    /* JADX INFO: renamed from: j */
    private Handler f1390j = new Handler();

    /* JADX INFO: renamed from: k */
    private Runnable f1391k = new RunnableC0106ag(this);

    /* JADX INFO: renamed from: a */
    public static void m424a() {
        if (f1384d != null) {
            f1385h = 3;
            f1384d.dismiss();
            f1384d = null;
        }
    }

    @Override // android.app.Activity
    public void finish() {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity finish isAbortUpdateFlag=" + this.f1387f);
        C0092c.m354d(false);
        super.finish();
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle bundle) {
        TextView textView;
        TextView textView2;
        TextView textView3;
        TextView textView4;
        super.onCreate(bundle);
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity .onCreate() begin");
        Intent intent = getIntent();
        requestWindowFeature(1);
        this.f1386e = this;
        boolean booleanExtra = intent.getBooleanExtra("FailFlag", false);
        this.f1388g = getResources().getConfiguration().orientation;
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onCreate() orientation=" + this.f1388g);
        C0092c.m354d(true);
        Context context = this.f1386e;
        View viewInflate = LayoutInflater.from(context).inflate(C0092c.m323a(context, "layout", f1382b), (ViewGroup) null);
        AlertDialog.Builder builder = new AlertDialog.Builder(context);
        builder.setTitle(C0092c.m343b(context, f1381a));
        builder.setView(viewInflate);
        if (f1385h.intValue() == 0) {
            f1385h = 3;
        }
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity popupPromptionDialog create");
        builder.setPositiveButton(C0092c.m343b(context, "SUS_NOTIFICATION_HIDE_BUTTONTEXT"), new DialogInterfaceOnClickListenerC0109aj(this));
        builder.setNegativeButton(C0092c.m343b(context, "SUS_NOTIFICATION_ABORTUPDATE_BUTTONTEXT"), new DialogInterfaceOnClickListenerC0102ac(this));
        builder.setOnKeyListener(new DialogInterfaceOnKeyListenerC0105af(this));
        f1384d = builder.create();
        f1384d.setCancelable(false);
        f1384d.setOnCancelListener(new DialogInterfaceOnCancelListenerC0137y(this));
        f1384d.setOnDismissListener(new DialogInterfaceOnDismissListenerC0101ab(this));
        if (f1384d == null) {
            C0098i.m409a(C0092c.f1339b, "null == myCustomDialog!!!");
            C0104ae.m447b();
        } else {
            f1384d.show();
            String strM343b = booleanExtra ? C0092c.m343b(this.f1386e, "SUS_NOTIFICATION_TIMEOUTPROMPT") : C0092c.m343b(this.f1386e, "SUS_NOTIFICATION_UPDATINGPROMPT");
            if (strM343b != null && strM343b.length() > 0 && (textView4 = (TextView) f1384d.findViewById(C0092c.m323a(context, f1383c, "SUS_NOTIFICATION_PROMPTINFO"))) != null) {
                textView4.setText(strM343b);
            }
            String strM343b2 = C0092c.m343b(this.f1386e, "SUS_NOTIFICATION_AUTOHIDPROMPTINFO_1");
            String strM343b3 = C0092c.m343b(this.f1386e, "SUS_NOTIFICATION_AUTOHIDPROMPTINFO_2");
            String string = f1385h.toString();
            if (strM343b2 != null && strM343b2.length() > 0 && (textView3 = (TextView) f1384d.findViewById(C0092c.m323a(context, f1383c, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_1"))) != null) {
                textView3.setText(strM343b2);
            }
            if (strM343b3 != null && strM343b3.length() > 0 && (textView2 = (TextView) f1384d.findViewById(C0092c.m323a(context, f1383c, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_2"))) != null) {
                textView2.setText(strM343b3);
            }
            if (string != null && string.length() > 0 && (textView = (TextView) f1384d.findViewById(C0092c.m323a(context, f1383c, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_TIME"))) != null) {
                textView.setText(string);
            }
        }
        if (this.f1390j == null || this.f1391k == null) {
            return;
        }
        this.f1390j.removeCallbacks(this.f1391k);
        this.f1390j.postDelayed(this.f1391k, 1500L);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onDestroy myContext=" + this.f1386e);
        if (this.f1386e != null) {
            this.f1386e = null;
        }
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onDestroy myCustomDialog=" + f1384d);
        if (f1384d != null) {
            f1384d.dismiss();
            f1384d = null;
        }
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onPause() {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onPause");
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onRestart() {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onRestart");
        super.onRestart();
    }

    @Override // android.app.Activity
    protected void onResume() {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onResume");
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onStart() {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onStart");
        super.onStart();
    }

    @Override // android.app.Activity
    protected void onStop() {
        C0098i.m409a(C0092c.f1339b, "SUSNotificationActivity onStop");
        super.onStop();
    }
}
