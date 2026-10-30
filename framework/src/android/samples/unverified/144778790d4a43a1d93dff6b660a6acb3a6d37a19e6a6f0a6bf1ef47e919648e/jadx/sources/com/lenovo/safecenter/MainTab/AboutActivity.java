package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class AboutActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private TextView f2665a;

    /* JADX INFO: renamed from: b */
    private TextView f2666b;

    /* JADX INFO: renamed from: c */
    private TextView f2667c;

    /* JADX INFO: renamed from: d */
    private TextView f2668d;

    /* JADX INFO: renamed from: e */
    private TextView f2669e;

    /* JADX INFO: renamed from: f */
    private TextView f2670f;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.about_dialog_layout);
        this.f2666b = (TextView) findViewById(C0415R.id.homepageBtn);
        this.f2667c = (TextView) findViewById(C0415R.id.bbsBtn);
        this.f2668d = (TextView) findViewById(C0415R.id.weiboBtn);
        this.f2669e = (TextView) findViewById(C0415R.id.permission_server_tv);
        this.f2670f = (TextView) findViewById(C0415R.id.permission_contract_tv);
        this.f2669e.getPaint().setFlags(8);
        this.f2669e.getPaint().setAntiAlias(true);
        this.f2670f.getPaint().setFlags(8);
        this.f2670f.getPaint().setAntiAlias(true);
        this.f2669e.setOnClickListener(this);
        this.f2670f.setOnClickListener(this);
        this.f2666b.setOnClickListener(this);
        this.f2667c.setOnClickListener(this);
        this.f2668d.setOnClickListener(this);
        this.f2665a = (TextView) findViewById(C0415R.id.version);
        try {
            PackageInfo pInfo = getApplicationContext().getPackageManager().getPackageInfo(getApplicationInfo().packageName, 32768);
            if (pInfo.versionName.length() > 6) {
                this.f2665a.setText(pInfo.versionName.substring(0, 6));
            } else {
                this.f2665a.setText(pInfo.versionName);
            }
        } catch (PackageManager.NameNotFoundException e) {
            this.f2665a.setText("");
            e.printStackTrace();
        }
        TextView topBar = (TextView) findViewById(C0415R.id.txt_title);
        topBar.setText(C0415R.string.about);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.AboutActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                AboutActivity.this.finish();
            }
        });
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.homepageBtn /* 2131296272 */:
                try {
                    Uri uri = Uri.parse("http://safe.lenovo.com");
                    Intent intent = new Intent("android.intent.action.VIEW", uri);
                    startActivity(intent);
                } catch (Exception e) {
                    Toast.makeText(this, C0415R.string.no_browser, 1).show();
                    return;
                }
                break;
            case C0415R.id.bbsBtn /* 2131296273 */:
                try {
                    Uri uri2 = Uri.parse("http://lefen.lenovo.com/forum-335-1.html");
                    Intent intent2 = new Intent("android.intent.action.VIEW", uri2);
                    startActivity(intent2);
                } catch (Exception e2) {
                    Toast.makeText(this, C0415R.string.no_browser, 1).show();
                    return;
                }
                break;
            case C0415R.id.weiboBtn /* 2131296274 */:
                try {
                    Uri uri3 = Uri.parse("http://weibo.com/leanquan");
                    Intent intent3 = new Intent("android.intent.action.VIEW", uri3);
                    startActivity(intent3);
                } catch (Exception e3) {
                    Toast.makeText(this, C0415R.string.no_browser, 1).show();
                    return;
                }
                break;
            case C0415R.id.permission_contract_tv /* 2131296276 */:
                try {
                    Uri uri4 = Uri.parse("http://safe.lenovo.com/new/safeMobile/contract.html");
                    Intent intent4 = new Intent("android.intent.action.VIEW", uri4);
                    startActivity(intent4);
                } catch (Exception e4) {
                    Toast.makeText(this, C0415R.string.no_browser, 1).show();
                    return;
                }
                break;
            case C0415R.id.permission_server_tv /* 2131296277 */:
                try {
                    Uri uri5 = Uri.parse("http://safe.lenovo.com/new/safeMobile/permission.html");
                    Intent intent5 = new Intent("android.intent.action.VIEW", uri5);
                    startActivity(intent5);
                } catch (Exception e5) {
                    Toast.makeText(this, C0415R.string.no_browser, 1).show();
                    return;
                }
                break;
        }
    }
}
