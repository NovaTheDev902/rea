package com.lenovo.safecenter.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.support.Contract;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class SmsAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private Context f2897a;

    /* JADX INFO: renamed from: b */
    private List<Contract> f2898b;

    public SmsAdapter(Context context, List<Contract> list) {
        this.f2897a = context;
        this.f2898b = list;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2898b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2898b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0420a holder;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f2897a).inflate(C0415R.layout.sms, (ViewGroup) null);
            holder = new C0420a(this, (byte) 0);
            holder.f2899a = (TextView) convertView.findViewById(C0415R.id.safemode_smsname);
            holder.f2900b = (TextView) convertView.findViewById(C0415R.id.safemode_smsnumber);
            holder.f2901c = (TextView) convertView.findViewById(C0415R.id.safemode_smscontent);
            holder.f2902d = (ImageView) convertView.findViewById(C0415R.id.safemode_smscheck);
            convertView.setTag(holder);
        } else {
            holder = (C0420a) convertView.getTag();
        }
        Contract con = this.f2898b.get(position);
        if (con.getName() == null || con.getName().equals("")) {
            holder.f2899a.setText(C0415R.string.no_name);
        } else {
            holder.f2899a.setText(con.getName());
        }
        holder.f2900b.setText(con.getPhoneNumber());
        if (con.getSmsContent() != null && !con.getSmsContent().equals("")) {
            holder.f2901c.setText(con.getSmsContent());
        } else {
            holder.f2901c.setText(C0415R.string.no_content);
        }
        if (con.isSelect()) {
            holder.f2902d.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
        } else {
            holder.f2902d.setBackgroundResource(C0415R.drawable.ic_checkbox);
        }
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.SmsAdapter$a */
    private class C0420a {

        /* JADX INFO: renamed from: a */
        TextView f2899a;

        /* JADX INFO: renamed from: b */
        TextView f2900b;

        /* JADX INFO: renamed from: c */
        TextView f2901c;

        /* JADX INFO: renamed from: d */
        ImageView f2902d;

        private C0420a() {
        }

        /* synthetic */ C0420a(SmsAdapter x0, byte b) {
            this();
        }
    }
}
