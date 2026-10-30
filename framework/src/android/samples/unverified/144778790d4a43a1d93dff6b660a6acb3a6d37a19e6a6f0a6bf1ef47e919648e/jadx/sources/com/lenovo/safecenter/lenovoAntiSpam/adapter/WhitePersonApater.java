package com.lenovo.safecenter.lenovoAntiSpam.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.lenovoAntiSpam.domain.BlackInfo;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class WhitePersonApater extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private Context f3784a;

    /* JADX INFO: renamed from: b */
    private List<BlackInfo> f3785b;

    public WhitePersonApater(Context context, List<BlackInfo> list) {
        this.f3784a = context;
        this.f3785b = list;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f3785b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f3785b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0587a holder;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f3784a).inflate(C0415R.layout.antispamblackinfo_item1, (ViewGroup) null);
            holder = new C0587a(this, (byte) 0);
            holder.f3786a = (ImageView) convertView.findViewById(C0415R.id.antispamblack_image);
            holder.f3789d = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_name);
            holder.f3790e = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_number);
            holder.f3788c = (ImageView) convertView.findViewById(C0415R.id.antispamisupload);
            holder.f3787b = (ImageView) convertView.findViewById(C0415R.id.antispamblack_check);
            convertView.setTag(holder);
        } else {
            holder = (C0587a) convertView.getTag();
        }
        BlackInfo info = this.f3785b.get(position);
        holder.f3787b.setVisibility(8);
        holder.f3786a.setImageResource(C0415R.drawable.antispamwhite);
        holder.f3788c.setVisibility(8);
        holder.f3790e.setText(info.getPhoneNumber());
        if (info.getName() == null || info.getName().equals("")) {
            holder.f3789d.setText(C0415R.string.antispamlocalblack_noName);
        } else {
            holder.f3789d.setText(info.getName());
        }
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.adapter.WhitePersonApater$a */
    private class C0587a {

        /* JADX INFO: renamed from: a */
        ImageView f3786a;

        /* JADX INFO: renamed from: b */
        ImageView f3787b;

        /* JADX INFO: renamed from: c */
        ImageView f3788c;

        /* JADX INFO: renamed from: d */
        TextView f3789d;

        /* JADX INFO: renamed from: e */
        TextView f3790e;

        private C0587a() {
        }

        /* synthetic */ C0587a(WhitePersonApater x0, byte b) {
            this();
        }
    }
}
