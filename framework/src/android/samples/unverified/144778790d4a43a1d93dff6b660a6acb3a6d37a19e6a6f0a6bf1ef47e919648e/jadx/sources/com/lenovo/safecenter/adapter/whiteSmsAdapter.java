package com.lenovo.safecenter.adapter;

import android.content.Context;
import android.text.SpannableString;
import android.text.TextUtils;
import android.text.style.StyleSpan;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.support.Contract;
import com.lenovo.safecenter.utils.ContractHelpUtils;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class whiteSmsAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    Context f2918a;

    /* JADX INFO: renamed from: b */
    List<Contract> f2919b;

    public whiteSmsAdapter(Context context, List<Contract> list) {
        this.f2918a = context;
        this.f2919b = list;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2919b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2919b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    public void removeItem(int position) {
        this.f2919b.remove(position);
        notifyDataSetChanged();
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0423a holder;
        byte b = 0;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f2918a).inflate(C0415R.layout.whiteloginfo, (ViewGroup) null);
            holder = new C0423a(this, b);
            holder.f2920a = (ImageView) convertView.findViewById(C0415R.id.safemode_icon_call);
            holder.f2921b = (ImageView) convertView.findViewById(C0415R.id.safemode_type_icon);
            holder.f2922c = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_date);
            holder.f2923d = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_name);
            holder.f2924e = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_content);
            holder.f2925f = (TextView) convertView.findViewById(C0415R.id.txt_showcount);
            convertView.setTag(holder);
        } else {
            holder = (C0423a) convertView.getTag();
        }
        Contract sms = this.f2919b.get(position);
        Log.i("fromtype", sms.getFromtype() + "==getFromtype");
        holder.f2921b.setVisibility(8);
        if (sms.getFromtype() == 0) {
            holder.f2920a.setVisibility(8);
            String str = sms.getName();
            if (TextUtils.isEmpty(sms.getName())) {
                str = sms.getPhoneNumber();
            }
            if (sms.noreadCount > 0) {
                holder.f2925f.setText(getSpan(String.format(this.f2918a.getString(C0415R.string.pri_percente), Integer.valueOf(sms.noreadCount), Integer.valueOf(sms.getCount())), 19));
                holder.f2923d.setText(getSpan(str, 19));
            } else {
                holder.f2925f.setText(String.format(this.f2918a.getString(C0415R.string.pri_percente), Integer.valueOf(sms.noreadCount), Integer.valueOf(sms.getCount())));
                holder.f2923d.setText(str);
            }
            holder.f2922c.setVisibility(8);
            holder.f2924e.setText(sms.getSmsContent());
        } else if (sms.getFromtype() == 1) {
            holder.f2925f.setVisibility(8);
            if (sms.getCallType() == 3) {
                holder.f2920a.setImageResource(C0415R.drawable.list_icon_miss_call);
            } else if (sms.getCallType() == 2) {
                holder.f2920a.setImageResource(C0415R.drawable.list_icon_out_call);
            } else {
                holder.f2920a.setImageResource(C0415R.drawable.list_icon_in_call);
            }
            String str2 = sms.getName();
            if (TextUtils.isEmpty(sms.getName())) {
                str2 = sms.getPhoneNumber();
            }
            if (sms.getIsRead() == 1) {
                holder.f2923d.setText(getSpan(str2, 19));
            } else {
                holder.f2923d.setText(str2);
            }
            holder.f2922c.setText(ContractHelpUtils.formatTime(sms.getDate(), this.f2918a));
            Log.i(AppDatabase.CONTENT, ContractHelpUtils.formatTime(sms.getDate(), this.f2918a) + "===call==" + sms.getDate());
        }
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.whiteSmsAdapter$a */
    private class C0423a {

        /* JADX INFO: renamed from: a */
        ImageView f2920a;

        /* JADX INFO: renamed from: b */
        ImageView f2921b;

        /* JADX INFO: renamed from: c */
        TextView f2922c;

        /* JADX INFO: renamed from: d */
        TextView f2923d;

        /* JADX INFO: renamed from: e */
        TextView f2924e;

        /* JADX INFO: renamed from: f */
        TextView f2925f;

        private C0423a() {
        }

        /* synthetic */ C0423a(whiteSmsAdapter x0, byte b) {
            this();
        }
    }

    public SpannableString getSpan(String text, int size) {
        SpannableString spannable = new SpannableString(text);
        spannable.setSpan(new StyleSpan(1), 0, text.length(), 33);
        return spannable;
    }
}
