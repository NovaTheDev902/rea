package com.lenovo.lps.sus.control;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.widget.Button;
import android.widget.TextView;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.lps.sus.p008c.C0098i;
import com.lenovo.providers.querypermissions.QueryPermissions;

/* JADX INFO: loaded from: classes.dex */
public class SUSCustdefNotificationActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private static String f1371a = "sus_customdef_notification_dialog";

    /* JADX INFO: renamed from: b */
    private static String f1372b = QueryPermissions.f1958ID;

    /* JADX INFO: renamed from: c */
    private static Context f1373c = null;

    /* JADX INFO: renamed from: e */
    private static Integer f1374e = 3;

    /* JADX INFO: renamed from: d */
    private boolean f1375d = true;

    /* JADX INFO: renamed from: f */
    private final int f1376f = 1500;

    /* JADX INFO: renamed from: g */
    private Handler f1377g = new Handler();

    /* JADX INFO: renamed from: h */
    private Button f1378h = null;

    /* JADX INFO: renamed from: i */
    private Button f1379i = null;

    /* JADX INFO: renamed from: j */
    private Runnable f1380j = new RunnableC0117e(this);

    /* JADX INFO: renamed from: b */
    public static void m416b() {
        if (f1373c != null) {
            f1374e = 3;
            ((Activity) f1373c).finish();
            f1373c = null;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m422a() {
        if (this.f1377g != null) {
            this.f1377g.removeCallbacks(this.f1380j);
            this.f1377g = null;
        }
        if (f1373c != null) {
            f1373c = null;
        }
    }

    @Override // android.app.Activity
    public void finish() {
        C0098i.m409a(C0092c.f1339b, "SUSCustdefNotificationActivity finish isAbortUpdateFlag=" + this.f1375d);
        m422a();
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
        C0098i.m409a(C0092c.f1339b, "SUSCustdefNotificationActivity .onCreate() begin");
        C0092c.m354d(true);
        setContentView(C0092c.m323a(this, "layout", f1371a));
        Intent intent = getIntent();
        f1373c = this;
        String strM343b = C0092c.m343b(f1373c, "SUS_NOTIFICATION_TITLE");
        if (strM343b != null && strM343b.length() > 0) {
            setTitle(strM343b);
        }
        boolean booleanExtra = intent.getBooleanExtra("FailFlag", false);
        this.f1378h = (Button) findViewById(C0092c.m323a(f1373c, f1372b, "SUS_NOTIFICATION_CONTINUEBUTTON"));
        String strM343b2 = C0092c.m343b(f1373c, "SUS_NOTIFICATION_HIDE_BUTTONTEXT");
        if (this.f1378h != null && strM343b2 != null && strM343b2.length() > 0) {
            this.f1378h.setOnClickListener(new ViewOnClickListenerC0110ak(this));
            this.f1378h.setText(strM343b2);
        }
        this.f1379i = (Button) findViewById(C0092c.m323a(f1373c, f1372b, "SUS_NOTIFICATION_ABORTUPDATEBUTTON"));
        String strM343b3 = C0092c.m343b(f1373c, "SUS_NOTIFICATION_ABORTUPDATE_BUTTONTEXT");
        if (this.f1379i != null) {
            this.f1379i.setOnClickListener(new ViewOnClickListenerC0122j(this));
            this.f1379i.setText(strM343b3);
        }
        String strM343b4 = booleanExtra ? C0092c.m343b(f1373c, "SUS_NOTIFICATION_TIMEOUTPROMPT") : C0092c.m343b(f1373c, "SUS_NOTIFICATION_UPDATINGPROMPT");
        if (strM343b4 != null && strM343b4.length() > 0 && (textView4 = (TextView) findViewById(C0092c.m323a(f1373c, f1372b, "SUS_NOTIFICATION_PROMPTINFO"))) != null) {
            textView4.setText(strM343b4);
        }
        String strM343b5 = C0092c.m343b(f1373c, "SUS_NOTIFICATION_AUTOHIDPROMPTINFO_1");
        String strM343b6 = C0092c.m343b(f1373c, "SUS_NOTIFICATION_AUTOHIDPROMPTINFO_2");
        String string = f1374e.toString();
        if (strM343b5 != null && strM343b5.length() > 0 && (textView3 = (TextView) findViewById(C0092c.m323a(f1373c, f1372b, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_1"))) != null) {
            textView3.setText(strM343b5);
        }
        if (strM343b6 != null && strM343b6.length() > 0 && (textView2 = (TextView) findViewById(C0092c.m323a(f1373c, f1372b, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_2"))) != null) {
            textView2.setText(strM343b6);
        }
        if (string != null && string.length() > 0 && (textView = (TextView) findViewById(C0092c.m323a(f1373c, f1372b, "SUS_NOTIFICATION_AUTOHIDPROMPTINFOTEXTVIEW_TIME"))) != null) {
            textView.setText(string);
        }
        if (this.f1377g == null || this.f1380j == null) {
            return;
        }
        this.f1377g.removeCallbacks(this.f1380j);
        this.f1377g.postDelayed(this.f1380j, 1500L);
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        C0098i.m409a(C0092c.f1339b, "SUSCustdefNotificationActivity onDestroy myContext=" + f1373c);
        m422a();
        C0092c.m354d(false);
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onRestart() {
        super.onRestart();
    }
}
