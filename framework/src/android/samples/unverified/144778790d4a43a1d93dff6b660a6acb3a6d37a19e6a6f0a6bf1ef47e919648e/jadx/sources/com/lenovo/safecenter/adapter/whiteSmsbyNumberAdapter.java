package com.lenovo.safecenter.adapter;

import android.content.Context;
import android.text.TextUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class whiteSmsbyNumberAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    Context f2927a;

    /* JADX INFO: renamed from: b */
    List<Contract> f2928b;

    public whiteSmsbyNumberAdapter(Context context, List<Contract> list) {
        this.f2927a = context;
        this.f2928b = list;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2928b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2928b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    public void removeItem(int position) {
        this.f2928b.remove(position);
        notifyDataSetChanged();
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0424a holder;
        byte b = 0;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f2927a).inflate(C0415R.layout.message_item, (ViewGroup) null);
            holder = new C0424a(this, b);
            holder.f2929a = (TextView) convertView.findViewById(C0415R.id.SenderPic);
            holder.f2930b = (TextView) convertView.findViewById(C0415R.id.SelfPic);
            holder.f2931c = (RelativeLayout) convertView.findViewById(C0415R.id.SmsFrame);
            holder.f2932d = (TextView) convertView.findViewById(C0415R.id.ListTitle);
            holder.f2933e = (TextView) convertView.findViewById(C0415R.id.ListSubTitle);
            holder.f2934f = (TextView) convertView.findViewById(C0415R.id.ListBody);
            convertView.setTag(holder);
        } else {
            holder = (C0424a) convertView.getTag();
        }
        Contract con = this.f2928b.get(position);
        holder.f2934f.setText(con.getSmsContent());
        holder.f2933e.setText(ContractHelpUtils.formatTime(con.getDate(), this.f2927a));
        if (con.getSmstype() == 1) {
            holder.f2931c.setBackgroundResource(C0415R.drawable.sms_bg_item_f);
            holder.f2931c.setPadding(30, 0, 5, 0);
            holder.f2930b.setVisibility(0);
            holder.f2929a.setVisibility(8);
            if (!TextUtils.isEmpty(con.getName())) {
                holder.f2932d.setText(con.getName());
            } else {
                holder.f2932d.setText(con.getPhoneNumber());
            }
        } else {
            holder.f2929a.setVisibility(0);
            holder.f2931c.setBackgroundResource(C0415R.drawable.sms_bg);
            holder.f2931c.setPadding(8, 0, 20, 0);
            holder.f2930b.setVisibility(8);
            holder.f2932d.setText(C0415R.string.self);
        }
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.whiteSmsbyNumberAdapter$a */
    private class C0424a {

        /* JADX INFO: renamed from: a */
        TextView f2929a;

        /* JADX INFO: renamed from: b */
        TextView f2930b;

        /* JADX INFO: renamed from: c */
        RelativeLayout f2931c;

        /* JADX INFO: renamed from: d */
        TextView f2932d;

        /* JADX INFO: renamed from: e */
        TextView f2933e;

        /* JADX INFO: renamed from: f */
        TextView f2934f;

        private C0424a() {
        }

        /* synthetic */ C0424a(whiteSmsbyNumberAdapter x0, byte b) {
            this();
        }
    }
}
