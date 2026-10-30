package com.lenovo.safecenter.antivirus.domain;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.drawable.Drawable;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class PermAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private LayoutInflater f3008a;

    /* JADX INFO: renamed from: b */
    private List<ScanInfo> f3009b;

    /* JADX INFO: renamed from: c */
    private C0442a f3010c;

    /* JADX INFO: renamed from: d */
    private Context f3011d;

    /* JADX INFO: renamed from: e */
    private boolean f3012e;

    public PermAdapter(Context context, List<ScanInfo> apps, boolean isNeedScan) {
        this.f3008a = LayoutInflater.from(context);
        this.f3009b = apps;
        this.f3011d = context;
        this.f3012e = isNeedScan;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f3009b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f3009b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.BaseAdapter, android.widget.ListAdapter
    public boolean isEnabled(int position) {
        return false;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null) {
            convertView = this.f3008a.inflate(C0415R.layout.scanitem, (ViewGroup) null);
            this.f3010c = new C0442a();
            this.f3010c.f3039a = (ImageView) convertView.findViewById(C0415R.id.scanapp_icon);
            this.f3010c.f3041c = (TextView) convertView.findViewById(C0415R.id.scanapp_name);
            this.f3010c.f3040b = (ImageView) convertView.findViewById(C0415R.id.scanapp_state);
            convertView.setTag(this.f3010c);
        } else {
            this.f3010c = (C0442a) convertView.getTag();
        }
        if (position <= 2) {
            if (position == 0) {
                this.f3010c.f3039a.setImageDrawable(this.f3011d.getResources().getDrawable(C0415R.drawable.atat_safe_icon));
                this.f3010c.f3041c.setText(C0415R.string.antivirusfull_system_scan2);
                this.f3010c.f3040b.setVisibility(8);
            } else if (position == 1) {
                this.f3010c.f3039a.setImageDrawable(this.f3011d.getResources().getDrawable(C0415R.drawable.antivirusqq));
                this.f3010c.f3041c.setText(C0415R.string.antivirusfull_system_scan3);
                this.f3010c.f3040b.setVisibility(8);
            } else if (position == 2) {
                this.f3010c.f3039a.setImageDrawable(this.f3011d.getResources().getDrawable(C0415R.drawable.antivirusbitdefend));
                this.f3010c.f3041c.setText(C0415R.string.antivirusfull_system_scan4);
                this.f3010c.f3040b.setVisibility(8);
            }
        } else if (this.f3012e) {
            this.f3010c.f3040b.setVisibility(0);
            ScanInfo info = this.f3009b.get(position);
            Log.i(AppDatabase.NUMBER, this.f3010c.f3039a + "===" + info + "==" + this.f3011d);
            Drawable icon = null;
            try {
                ApplicationInfo appInfo = this.f3011d.getPackageManager().getApplicationInfo(info.getPackageName(), 8192);
                icon = appInfo.loadIcon(this.f3011d.getPackageManager());
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
            if (icon == null) {
                icon = this.f3011d.getResources().getDrawable(C0415R.drawable.icon3);
            }
            this.f3010c.f3039a.setImageDrawable(icon);
            String str = this.f3011d.getResources().getString(C0415R.string.antivirusvirus_scaning);
            this.f3010c.f3041c.setText(String.format(str, info.getSoftName()));
            this.f3010c.f3040b.setImageDrawable(this.f3011d.getResources().getDrawable(C0415R.drawable.perm_grant1));
            if (info.isVirus()) {
                this.f3010c.f3040b.setImageDrawable(this.f3011d.getResources().getDrawable(C0415R.drawable.perm_prompt1));
            }
        } else {
            this.f3010c.f3040b.setVisibility(0);
            ScanInfo info2 = this.f3009b.get(position);
            Log.i(AppDatabase.NUMBER, this.f3010c.f3039a + "===" + info2 + "==" + this.f3011d);
            Drawable icon2 = info2.getAppInfo().loadIcon(this.f3011d.getPackageManager());
            if (icon2 == null) {
                icon2 = this.f3011d.getResources().getDrawable(C0415R.drawable.icon3);
            }
            this.f3010c.f3039a.setImageDrawable(icon2);
            String str2 = this.f3011d.getResources().getString(C0415R.string.antivirusvirus_scaning);
            this.f3010c.f3041c.setText(String.format(str2, info2.getAppInfo().loadLabel(this.f3011d.getPackageManager())));
            this.f3010c.f3040b.setImageDrawable(this.f3011d.getResources().getDrawable(C0415R.drawable.perm_grant1));
            if (info2.isVirus()) {
                this.f3010c.f3040b.setImageDrawable(this.f3011d.getResources().getDrawable(C0415R.drawable.perm_prompt1));
            }
        }
        return convertView;
    }
}
