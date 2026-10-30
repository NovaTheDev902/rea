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
public class ManwhiteSmsAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    Context f2879a;

    /* JADX INFO: renamed from: b */
    List<Contract> f2880b;

    public ManwhiteSmsAdapter(Context context, List<Contract> list) {
        this.f2879a = context;
        this.f2880b = list;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2880b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2880b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    public void removeItem(int position) {
        this.f2880b.remove(position);
        notifyDataSetChanged();
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0418a holder;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f2879a).inflate(C0415R.layout.whiteloginfo, (ViewGroup) null);
            holder = new C0418a(this, (byte) 0);
            holder.f2881a = (ImageView) convertView.findViewById(C0415R.id.safemode_icon_call);
            holder.f2882b = (ImageView) convertView.findViewById(C0415R.id.safemode_type_icon);
            holder.f2883c = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_date);
            holder.f2884d = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_name);
            holder.f2885e = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_content);
            convertView.setTag(holder);
        } else {
            holder = (C0418a) convertView.getTag();
        }
        Contract sms = this.f2880b.get(position);
        if (sms.getFromtype() == 0) {
            String str = sms.getName();
            if (sms.getName() == null) {
                str = sms.getPhoneNumber();
            }
            int count = sms.getCount();
            if (count > 0) {
                String recordcount = this.f2879a.getString(C0415R.string.record_count);
                str = str + String.format(recordcount, String.valueOf(count));
            }
            if (sms.isSelect()) {
                holder.f2881a.setImageResource(C0415R.drawable.ic_checkbox_select);
            } else {
                holder.f2881a.setImageResource(C0415R.drawable.ic_checkbox);
            }
            holder.f2882b.setImageResource(C0415R.drawable.safemode_pri_message);
            holder.f2884d.setText(str);
            String date = this.f2879a.getString(C0415R.string.formattime);
            holder.f2883c.setText(String.format(date, ContractHelpUtils.formatTime(sms.getDate(), this.f2879a)));
            holder.f2885e.setText(sms.getSmsContent());
        } else if (sms.getFromtype() == 1) {
            String str2 = sms.getName();
            if (sms.getName() == null) {
                str2 = sms.getPhoneNumber();
            }
            if (sms.isSelect()) {
                holder.f2881a.setImageResource(C0415R.drawable.ic_checkbox_select);
            } else {
                holder.f2881a.setImageResource(C0415R.drawable.ic_checkbox);
            }
            if (sms.getCallType() == 1) {
                holder.f2882b.setImageResource(C0415R.drawable.list_icon_in_call);
            } else if (sms.getCallType() == 3) {
                holder.f2882b.setImageResource(C0415R.drawable.list_icon_miss_call);
            } else if (sms.getCallType() == 2) {
                holder.f2882b.setImageResource(C0415R.drawable.list_icon_out_call);
            }
            holder.f2884d.setText(str2);
            holder.f2883c.setText(ContractHelpUtils.formatTime(sms.getDate(), this.f2879a));
        }
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.ManwhiteSmsAdapter$a */
    private class C0418a {

        /* JADX INFO: renamed from: a */
        ImageView f2881a;

        /* JADX INFO: renamed from: b */
        ImageView f2882b;

        /* JADX INFO: renamed from: c */
        TextView f2883c;

        /* JADX INFO: renamed from: d */
        TextView f2884d;

        /* JADX INFO: renamed from: e */
        TextView f2885e;

        private C0418a() {
        }

        /* synthetic */ C0418a(ManwhiteSmsAdapter x0, byte b) {
            this();
        }
    }
}
