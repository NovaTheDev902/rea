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
public class WhiteSmsPersonApater extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private Context f3792a;

    /* JADX INFO: renamed from: b */
    private List<BlackInfo> f3793b;

    public WhiteSmsPersonApater(Context context, List<BlackInfo> list) {
        this.f3792a = context;
        this.f3793b = list;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f3793b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f3793b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0588a holder;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f3792a).inflate(C0415R.layout.antispamblackinfo_item1, (ViewGroup) null);
            holder = new C0588a(this, (byte) 0);
            holder.f3794a = (ImageView) convertView.findViewById(C0415R.id.antispamblack_image);
            holder.f3797d = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_name);
            holder.f3798e = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_number);
            holder.f3796c = (ImageView) convertView.findViewById(C0415R.id.antispamisupload);
            holder.f3795b = (ImageView) convertView.findViewById(C0415R.id.antispamblack_check);
            convertView.setTag(holder);
        } else {
            holder = (C0588a) convertView.getTag();
        }
        BlackInfo info = this.f3793b.get(position);
        holder.f3795b.setVisibility(8);
        holder.f3794a.setImageResource(C0415R.drawable.antispamsmsblacklog);
        holder.f3796c.setVisibility(8);
        holder.f3798e.setText(info.getPhoneNumber());
        if (info.getName() == null || info.getName().equals("")) {
            holder.f3797d.setText(C0415R.string.antispamlocalblack_noName);
        } else {
            holder.f3797d.setText(info.getName());
        }
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.adapter.WhiteSmsPersonApater$a */
    private class C0588a {

        /* JADX INFO: renamed from: a */
        ImageView f3794a;

        /* JADX INFO: renamed from: b */
        ImageView f3795b;

        /* JADX INFO: renamed from: c */
        ImageView f3796c;

        /* JADX INFO: renamed from: d */
        TextView f3797d;

        /* JADX INFO: renamed from: e */
        TextView f3798e;

        private C0588a() {
        }

        /* synthetic */ C0588a(WhiteSmsPersonApater x0, byte b) {
            this();
        }
    }
}
