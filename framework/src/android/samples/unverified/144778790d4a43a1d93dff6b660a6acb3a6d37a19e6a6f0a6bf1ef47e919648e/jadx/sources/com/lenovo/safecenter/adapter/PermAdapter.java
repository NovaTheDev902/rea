package com.lenovo.safecenter.adapter;

import android.content.Context;
import android.content.pm.PackageManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.support.AppInfo;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class PermAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private ArrayList<AppInfo> f2894a;

    /* JADX INFO: renamed from: b */
    private Context f2895b;

    /* JADX INFO: renamed from: c */
    private PackageManager f2896c;

    public PermAdapter(Context context, ArrayList<AppInfo> apps) {
        this.f2894a = apps;
        this.f2895b = context;
        this.f2896c = this.f2895b.getPackageManager();
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2894a.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2894a.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0421a holder;
        if (convertView == null) {
            LayoutInflater mInflater = LayoutInflater.from(this.f2895b);
            convertView = mInflater.inflate(C0415R.layout.second_item, (ViewGroup) null);
            holder = new C0421a();
            holder.f2904a = (ImageView) convertView.findViewById(C0415R.id.app_icon);
            holder.f2905b = (TextView) convertView.findViewById(C0415R.id.app_name);
            holder.f2906c = (TextView) convertView.findViewById(C0415R.id.app_suggest);
            holder.f2907d = (TextView) convertView.findViewById(C0415R.id.app_discription);
            holder.f2908e = (ImageView) convertView.findViewById(C0415R.id.itemcheck);
            convertView.setTag(holder);
        } else {
            holder = (C0421a) convertView.getTag();
        }
        AppInfo appInfo = this.f2894a.get(position);
        convertView.setVisibility(0);
        try {
            String cmd = appInfo.applicationInfo.loadLabel(this.f2896c).toString();
            holder.f2905b.setText(cmd);
            holder.f2904a.setImageDrawable(appInfo.applicationInfo.loadIcon(this.f2896c));
        } catch (Exception e) {
            e.printStackTrace();
            holder.f2905b.setText(appInfo.name);
            holder.f2904a.setImageResource(C0415R.drawable.icon3);
        }
        if (appInfo.appType.equals(AppDatabase.PERM_TYPE_PRIVCY) || appInfo.appType.equals("location") || appInfo.appType.equals(AppDatabase.PERM_TYPE_DEVICE)) {
            holder.f2907d.setVisibility(0);
            if (appInfo.selected == 0) {
                holder.f2907d.setText(this.f2895b.getString(C0415R.string.allow) + appInfo.permDes);
            } else {
                holder.f2907d.setText(this.f2895b.getString(C0415R.string.forbid) + appInfo.permDes);
            }
        } else {
            holder.f2907d.setVisibility(8);
        }
        ImageView tButton = holder.f2908e;
        tButton.setTag(appInfo);
        if (appInfo.selected == 0) {
            tButton.setBackgroundResource(C0415R.drawable.perm_grant);
        } else if (appInfo.selected == 1) {
            tButton.setBackgroundResource(C0415R.drawable.perm_deny);
        } else if (appInfo.selected == 2) {
            tButton.setBackgroundResource(C0415R.drawable.perm_prompt);
        }
        if (appInfo.suggest == 0) {
            holder.f2906c.setVisibility(0);
            holder.f2906c.setTextColor(this.f2895b.getResources().getColor(C0415R.color.green_allow));
            holder.f2906c.setText(C0415R.string.suggest_allow);
        } else if (appInfo.suggest == 1) {
            holder.f2906c.setVisibility(0);
            holder.f2906c.setTextColor(this.f2895b.getResources().getColor(C0415R.color.red_forbid));
            holder.f2906c.setText(C0415R.string.suggest_forbid);
        } else if (appInfo.suggest == -1) {
            holder.f2906c.setVisibility(4);
        }
        return convertView;
    }
}
