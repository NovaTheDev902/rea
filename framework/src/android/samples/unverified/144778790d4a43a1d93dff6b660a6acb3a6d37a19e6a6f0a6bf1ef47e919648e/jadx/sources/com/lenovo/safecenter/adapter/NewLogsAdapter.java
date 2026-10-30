package com.lenovo.safecenter.adapter;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.MyUtils;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class NewLogsAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    PackageManager f2887a;

    /* JADX INFO: renamed from: b */
    Context f2888b;

    /* JADX INFO: renamed from: c */
    List<SafeLog> f2889c;

    public NewLogsAdapter(Context context, List<SafeLog> list) {
        this.f2888b = context;
        this.f2889c = list;
        this.f2887a = context.getPackageManager();
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2889c.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2889c.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0419a holder;
        String content;
        if (convertView == null) {
            LayoutInflater mInflater = LayoutInflater.from(this.f2888b);
            convertView = mInflater.inflate(C0415R.layout.newlogsitem, (ViewGroup) null);
            holder = new C0419a();
            holder.f2890a = (ImageView) convertView.findViewById(C0415R.id.newlogs_img);
            holder.f2891b = (TextView) convertView.findViewById(C0415R.id.newlogs_time);
            holder.f2892c = (TextView) convertView.findViewById(C0415R.id.newlogs_content);
            convertView.setTag(holder);
        } else {
            holder = (C0419a) convertView.getTag();
        }
        SafeLog log = this.f2889c.get(position);
        ApplicationInfo appInfo = null;
        try {
            appInfo = this.f2887a.getApplicationInfo(log.packageName, 8704);
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        if (appInfo == null) {
            holder.f2890a.setImageResource(C0415R.drawable.icon3);
        } else {
            holder.f2890a.setImageDrawable(appInfo.loadIcon(this.f2887a));
        }
        if (log.logSelected == 1) {
            content = this.f2888b.getString(C0415R.string.when_calling) + AppUtil.getDescriptionByPid(this.f2888b, Integer.valueOf(log.type).intValue());
        } else {
            content = AppUtil.getDescriptionByPid(this.f2888b, Integer.valueOf(log.type).intValue());
        }
        if (log.action == 0) {
            String allow = this.f2888b.getString(C0415R.string.allow);
            holder.f2892c.setText(allow + content);
            MyUtils.setSpannableString(holder.f2892c, allow + content, 0, allow.length(), this.f2888b.getResources().getColor(C0415R.color.green_allow));
        } else {
            String forbid = this.f2888b.getString(C0415R.string.forbid);
            holder.f2892c.setText(forbid + content);
            MyUtils.setSpannableString(holder.f2892c, forbid + content, 0, forbid.length(), this.f2888b.getResources().getColor(C0415R.color.red_forbid));
        }
        holder.f2891b.setText(MyUtils.formatTime(log.time, this.f2888b));
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.NewLogsAdapter$a */
    class C0419a {

        /* JADX INFO: renamed from: a */
        ImageView f2890a;

        /* JADX INFO: renamed from: b */
        TextView f2891b;

        /* JADX INFO: renamed from: c */
        TextView f2892c;

        C0419a() {
        }
    }
}
