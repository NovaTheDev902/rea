package com.lenovo.safecenter.adapter;

import android.content.Context;
import android.text.TextUtils;
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
public class whiteContractAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    Context f2909a;

    /* JADX INFO: renamed from: b */
    List<Contract> f2910b;

    /* JADX INFO: renamed from: c */
    boolean f2911c;

    public whiteContractAdapter(Context context, List<Contract> list, boolean mode) {
        this.f2909a = context;
        this.f2910b = list;
        this.f2911c = mode;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f2910b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f2910b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    public void removeItem(int position) {
        this.f2910b.remove(position);
        notifyDataSetChanged();
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0422a holder;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f2909a).inflate(C0415R.layout.whiteloginfo, (ViewGroup) null);
            holder = new C0422a(this, (byte) 0);
            holder.f2912a = (ImageView) convertView.findViewById(C0415R.id.safemode_icon_call);
            holder.f2913b = (ImageView) convertView.findViewById(C0415R.id.safemode_type_icon);
            holder.f2914c = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_date);
            holder.f2915d = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_name);
            holder.f2916e = (TextView) convertView.findViewById(C0415R.id.safemode_whitesms_content);
            convertView.setTag(holder);
        } else {
            holder = (C0422a) convertView.getTag();
        }
        Contract con = this.f2910b.get(position);
        if (this.f2911c) {
            if (con.isSelect()) {
                holder.f2912a.setImageResource(C0415R.drawable.ic_checkbox_select);
            } else {
                holder.f2912a.setImageResource(C0415R.drawable.ic_checkbox);
            }
        } else {
            holder.f2912a.setVisibility(8);
        }
        String name = con.getName();
        if (TextUtils.isEmpty(name)) {
            holder.f2915d.setText(C0415R.string.no_name);
        } else {
            holder.f2915d.setText(name);
        }
        holder.f2913b.setVisibility(8);
        holder.f2914c.setText(con.getPhoneNumber());
        holder.f2916e.setVisibility(8);
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.adapter.whiteContractAdapter$a */
    private class C0422a {

        /* JADX INFO: renamed from: a */
        ImageView f2912a;

        /* JADX INFO: renamed from: b */
        ImageView f2913b;

        /* JADX INFO: renamed from: c */
        TextView f2914c;

        /* JADX INFO: renamed from: d */
        TextView f2915d;

        /* JADX INFO: renamed from: e */
        TextView f2916e;

        private C0422a() {
        }

        /* synthetic */ C0422a(whiteContractAdapter x0, byte b) {
            this();
        }
    }
}
