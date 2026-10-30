package com.lenovo.install;

import android.app.Activity;
import android.content.pm.PackageParser;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public class InstallErrorActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private TextView f1032a;

    /* JADX INFO: renamed from: b */
    private TextView f1033b;

    /* JADX INFO: renamed from: c */
    private TextView f1034c;

    /* JADX INFO: renamed from: d */
    private ImageView f1035d;

    /* JADX INFO: renamed from: e */
    private PackageParser.Package f1036e;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.install_main);
        this.f1032a = (TextView) findViewById(C0415R.id.error_txt);
        this.f1034c = (TextView) findViewById(C0415R.id.errorcontent);
        this.f1032a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.install.InstallErrorActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                InstallErrorActivity.this.finish();
            }
        });
        this.f1033b = (TextView) findViewById(C0415R.id.appname);
        this.f1035d = (ImageView) findViewById(C0415R.id.appicon);
        this.f1036e = PackageUtil.getPackageInfo(Uri.parse(getIntent().getStringExtra("uri")));
        if (this.f1036e == null) {
            this.f1035d.setImageResource(C0415R.drawable.net_traffic_out);
            this.f1034c.setText(C0415R.string.prase_error);
        } else {
            PackageUtil.AppSnippet as = PackageUtil.getAppSnippet(this, this.f1036e.applicationInfo, Uri.parse(getIntent().getStringExtra("uri")));
            this.f1035d.setImageDrawable(as.f1061b);
            this.f1033b.setText(as.f1060a);
        }
    }
}
