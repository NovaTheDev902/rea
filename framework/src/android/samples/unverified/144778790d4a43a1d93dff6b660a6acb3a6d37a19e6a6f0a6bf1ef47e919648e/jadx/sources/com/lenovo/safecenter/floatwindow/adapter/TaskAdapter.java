package com.lenovo.safecenter.floatwindow.adapter;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.performancecenter.service.object.UsedAppInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.floatwindow.model.ViewHolder;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class TaskAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private Context f3561a;

    /* JADX INFO: renamed from: b */
    private List<UsedAppInfo> f3562b;

    /* JADX INFO: renamed from: c */
    private ViewHolder f3563c;

    /* JADX INFO: renamed from: d */
    private LayoutInflater f3564d;

    /* JADX INFO: renamed from: e */
    private PackageManager f3565e;

    public TaskAdapter(Context _context, List<UsedAppInfo> _app_lists) {
        this.f3561a = _context;
        this.f3562b = _app_lists;
        this.f3564d = LayoutInflater.from(this.f3561a);
        if (this.f3565e == null) {
            this.f3565e = _context.getPackageManager();
        }
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f3562b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return Integer.valueOf(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        View view = convertView;
        if (view == null) {
            this.f3563c = new ViewHolder();
            view = this.f3564d.inflate(C0415R.layout.assist_task_item, (ViewGroup) null);
            this.f3563c.img = (ImageView) view.findViewById(C0415R.id.item_icon);
            this.f3563c.text = (TextView) view.findViewById(C0415R.id.item_label);
            view.setTag(this.f3563c);
        } else {
            this.f3563c = (ViewHolder) view.getTag();
        }
        try {
            ApplicationInfo appInfo = this.f3565e.getApplicationInfo(this.f3562b.get(position).packageName, 0);
            this.f3563c.img.setImageDrawable(appInfo.loadIcon(this.f3565e));
            this.f3563c.text.setText(appInfo.loadLabel(this.f3565e));
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return view;
    }
}
