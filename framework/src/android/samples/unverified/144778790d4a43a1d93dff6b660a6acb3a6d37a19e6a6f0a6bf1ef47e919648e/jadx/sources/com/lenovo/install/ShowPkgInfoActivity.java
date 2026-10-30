package com.lenovo.install;

import android.app.Activity;
import android.content.pm.PackageParser;
import android.content.pm.PermissionInfo;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.tencent.tmsecure.utils.Log;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ShowPkgInfoActivity extends Activity {

    /* JADX INFO: renamed from: a */
    private LinearLayout f1062a;

    /* JADX INFO: renamed from: b */
    private TextView f1063b;

    /* JADX INFO: renamed from: c */
    private TextView f1064c;

    /* JADX INFO: renamed from: d */
    private ImageView f1065d;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.install_appinfo);
        this.f1062a = (LinearLayout) findViewById(C0415R.id.pression_list);
        this.f1063b = (TextView) findViewById(C0415R.id.error_txt);
        this.f1064c = (TextView) findViewById(C0415R.id.appname);
        this.f1065d = (ImageView) findViewById(C0415R.id.appicon);
        this.f1063b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.install.ShowPkgInfoActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                ShowPkgInfoActivity.this.finish();
            }
        });
        PackageParser.Package mPkgInfo = PackageUtil.getPackageInfo(Uri.parse(getIntent().getStringExtra("uri")));
        List<PermissionInfo> listpre = PackageUtil.getPerssions(mPkgInfo, this);
        if (listpre.size() > 0) {
            for (PermissionInfo info : listpre) {
                this.f1062a.addView(getView(info.loadLabel(getPackageManager()).toString(), info.loadLogo(getPackageManager())));
            }
            Log.m2636i("ww", "");
        }
        PackageUtil.AppSnippet as = PackageUtil.getAppSnippet(this, mPkgInfo.applicationInfo, Uri.parse(getIntent().getStringExtra("uri")));
        this.f1064c.setText(as.f1060a);
        this.f1065d.setImageDrawable(as.f1061b);
    }

    public View getView(String str, Drawable drawID) {
        View view1 = LayoutInflater.from(this).inflate(C0415R.layout.permission_detail_item, (ViewGroup) null);
        TextView txtnumber = (TextView) view1.findViewById(C0415R.id.tab_name);
        txtnumber.setText(str);
        return view1;
    }
}
