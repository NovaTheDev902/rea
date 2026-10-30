package com.lenovo.safecenter.Laboratory;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.text.Html;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class SafePaymentDialogActivity extends Activity {

    /* JADX INFO: renamed from: a */
    ActivityManager f2658a;

    /* JADX INFO: renamed from: b */
    String f2659b;

    /* JADX INFO: renamed from: c */
    String f2660c;

    /* JADX INFO: renamed from: d */
    PackageManager f2661d;

    /* JADX INFO: renamed from: e */
    boolean f2662e = false;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1231a(SafePaymentDialogActivity x0, String x1) {
        x0.startActivity(new Intent("android.intent.action.DELETE", Uri.parse("package:" + x1)));
    }

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        this.f2661d = getPackageManager();
        this.f2658a = (ActivityManager) getSystemService("activity");
        this.f2660c = getIntent().getStringExtra("pkgName");
        this.f2659b = getIntent().getStringExtra("safeAppName");
        setContentView(C0415R.layout.dialog);
        ((TextView) findViewById(C0415R.id.title)).setText(C0415R.string.safepayment_dialog_title);
        ((TextView) findViewById(C0415R.id.message)).setText(Html.fromHtml(getString(C0415R.string.dialog_msg1) + this.f2659b + getString(C0415R.string.dialog_msg1_)));
        TextView textView = (TextView) findViewById(C0415R.id.positiveButton);
        textView.setText(C0415R.string.uninstall);
        textView.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentDialogActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                SafePaymentDialogActivity.m1231a(SafePaymentDialogActivity.this, SafePaymentDialogActivity.this.f2660c);
                SafePaymentDialogActivity.this.f2662e = true;
                SafePaymentDialogActivity.this.finish();
            }
        });
        findViewById(C0415R.id.neutralButton).setVisibility(8);
        TextView textView2 = (TextView) findViewById(C0415R.id.negativeButton);
        textView2.setText(C0415R.string.cancel);
        textView2.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.Laboratory.SafePaymentDialogActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                SafePaymentDialogActivity.this.f2662e = true;
                SafePaymentDialogActivity.this.finish();
            }
        });
    }

    @Override // android.app.Activity
    protected void onPause() {
        super.onPause();
        Log.e("ydp", "dialog activity onPause()");
        TrackEvent.trackPause(this);
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onStop() {
        super.onStop();
        Log.e("ydp", "dialog activity onStop()");
        if (!this.f2662e) {
            finish();
        }
    }
}
