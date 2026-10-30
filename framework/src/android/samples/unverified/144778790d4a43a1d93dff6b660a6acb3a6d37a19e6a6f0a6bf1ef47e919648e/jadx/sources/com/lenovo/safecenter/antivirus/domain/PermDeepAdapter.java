package com.lenovo.safecenter.antivirus.domain;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class PermDeepAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private LayoutInflater f3013a;

    /* JADX INFO: renamed from: b */
    private List<QScanResultEntity> f3014b;

    /* JADX INFO: renamed from: c */
    private C0443b f3015c;

    /* JADX INFO: renamed from: d */
    private Context f3016d;

    public PermDeepAdapter(Context context, List<QScanResultEntity> files) {
        this.f3013a = LayoutInflater.from(context);
        this.f3014b = files;
        this.f3016d = context;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f3014b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f3014b.get(position);
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
        String str;
        if (convertView == null) {
            convertView = this.f3013a.inflate(C0415R.layout.scanitem, (ViewGroup) null);
            this.f3015c = new C0443b();
            this.f3015c.f3042a = (ImageView) convertView.findViewById(C0415R.id.scanapp_icon);
            this.f3015c.f3044c = (TextView) convertView.findViewById(C0415R.id.scanapp_name);
            this.f3015c.f3043b = (ImageView) convertView.findViewById(C0415R.id.scanapp_state);
            convertView.setTag(this.f3015c);
        } else {
            this.f3015c = (C0443b) convertView.getTag();
        }
        if (position <= 2) {
            if (position == 0) {
                this.f3015c.f3042a.setImageDrawable(this.f3016d.getResources().getDrawable(C0415R.drawable.atat_safe_icon));
                this.f3015c.f3044c.setText(C0415R.string.antivirusfull_system_scan2);
                this.f3015c.f3043b.setVisibility(8);
            } else if (position == 1) {
                this.f3015c.f3042a.setImageDrawable(this.f3016d.getResources().getDrawable(C0415R.drawable.antivirusqq));
                this.f3015c.f3044c.setText(C0415R.string.antivirusfull_system_scan3);
                this.f3015c.f3043b.setVisibility(8);
            } else if (position == 2) {
                this.f3015c.f3042a.setImageDrawable(this.f3016d.getResources().getDrawable(C0415R.drawable.antivirusbitdefend));
                this.f3015c.f3044c.setText(C0415R.string.antivirusfull_system_scan4);
                this.f3015c.f3043b.setVisibility(8);
            }
        } else {
            this.f3015c.f3043b.setVisibility(0);
            QScanResultEntity result = this.f3014b.get(position);
            Drawable icon = null;
            if (result.apkType == 0) {
                try {
                    ApplicationInfo appInfo = this.f3016d.getPackageManager().getApplicationInfo(result.packageName, 8192);
                    icon = appInfo.loadIcon(this.f3016d.getPackageManager());
                } catch (PackageManager.NameNotFoundException e) {
                    e.printStackTrace();
                }
            } else {
                icon = AppUtils.getUninstallAPKIcon(result.path, this.f3016d);
            }
            if (icon == null) {
                icon = this.f3016d.getResources().getDrawable(C0415R.drawable.icon3);
            }
            this.f3015c.f3042a.setImageDrawable(icon);
            if (result.apkType == 2) {
                str = result.path;
            } else {
                str = result.softName;
            }
            this.f3015c.f3044c.setText(str);
            if (result.type == 3 && result.apkType != 1) {
                this.f3015c.f3043b.setImageDrawable(this.f3016d.getResources().getDrawable(C0415R.drawable.perm_prompt1));
            } else {
                this.f3015c.f3043b.setImageDrawable(this.f3016d.getResources().getDrawable(C0415R.drawable.perm_grant1));
            }
        }
        return convertView;
    }
}
