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
import com.lenovo.safecenter.utils.ContractHelpUtils;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class CallAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private Context f2861a;

    /* JADX INFO: renamed from: b */
    private List<Contract> f2862b;

    /* JADX INFO: renamed from: c */
    private int f2863c;

    public CallAdapter(Context context, List<Contract> list, int fromType) {
        this.f2861a = context;
        this.f2862b = list;
        this.f2863c = fromType;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2862b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2862b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0416a holder;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f2861a).inflate(C0415R.layout.callcontract, (ViewGroup) null);
            holder = new C0416a(this, (byte) 0);
            holder.f2864a = (TextView) convertView.findViewById(C0415R.id.safemode_callname);
            holder.f2865b = (TextView) convertView.findViewById(C0415R.id.safemode_callnumber);
            holder.f2866c = (TextView) convertView.findViewById(C0415R.id.safemode_calldate);
            holder.f2867d = (TextView) convertView.findViewById(C0415R.id.safemode_calltype);
            holder.f2868e = (ImageView) convertView.findViewById(C0415R.id.safemode_call_check);
            convertView.setTag(holder);
        } else {
            holder = (C0416a) convertView.getTag();
        }
        Contract con = this.f2862b.get(position);
        if (con.getName() == null || con.getName().equals("")) {
            holder.f2864a.setText(C0415R.string.no_name);
        } else {
            holder.f2864a.setText(con.getName());
        }
        ImageView tButton = holder.f2868e;
        if (con.isSelect()) {
            tButton.setBackgroundResource(C0415R.drawable.ic_checkbox_select);
        } else {
            tButton.setBackgroundResource(C0415R.drawable.ic_checkbox);
        }
        if (this.f2863c == 0) {
            holder.f2865b.setVisibility(8);
            holder.f2867d.setVisibility(8);
            holder.f2866c.setText(con.getPhoneNumber());
        } else if (this.f2863c == 1) {
            holder.f2865b.setText(con.getPhoneNumber());
            holder.f2867d.setText(ContractHelpUtils.getType(this.f2861a, con.getCallType()));
            holder.f2866c.setText(ContractHelpUtils.getDate(con.getDate()));
        }
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.CallAdapter$a */
    private class C0416a {

        /* JADX INFO: renamed from: a */
        TextView f2864a;

        /* JADX INFO: renamed from: b */
        TextView f2865b;

        /* JADX INFO: renamed from: c */
        TextView f2866c;

        /* JADX INFO: renamed from: d */
        TextView f2867d;

        /* JADX INFO: renamed from: e */
        ImageView f2868e;

        private C0416a() {
        }

        /* synthetic */ C0416a(CallAdapter x0, byte b) {
            this();
        }
    }
}
