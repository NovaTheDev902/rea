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
public class LocalBlackApater extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private Context f3776a;

    /* JADX INFO: renamed from: b */
    private List<BlackInfo> f3777b;

    public LocalBlackApater(Context context, List<BlackInfo> list, int type) {
        this.f3776a = context;
        this.f3777b = list;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        return this.f3777b.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        return this.f3777b.get(position);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C0586a holder;
        byte b = 0;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.f3776a).inflate(C0415R.layout.antispamblackinfo_item1, (ViewGroup) null);
            holder = new C0586a(this, b);
            holder.f3778a = (ImageView) convertView.findViewById(C0415R.id.antispamblack_image);
            holder.f3781d = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_name);
            holder.f3782e = (TextView) convertView.findViewById(C0415R.id.antispamlocalblack_number);
            holder.f3780c = (ImageView) convertView.findViewById(C0415R.id.antispamisupload);
            holder.f3779b = (ImageView) convertView.findViewById(C0415R.id.antispamblack_check);
            convertView.setTag(holder);
        } else {
            holder = (C0586a) convertView.getTag();
        }
        BlackInfo info = this.f3777b.get(position);
        holder.f3779b.setVisibility(8);
        if (info.getIsUpload() == 0) {
            holder.f3780c.setVisibility(8);
        } else if (info.getIsUpload() == 1) {
            holder.f3780c.setVisibility(0);
        }
        holder.f3782e.setText(info.getPhoneNumber());
        if (info.getName() == null || info.getName().equals("")) {
            holder.f3781d.setText(getNameStr(info.getType()));
        } else {
            holder.f3781d.setText(info.getName() + getNameStr(info.getType()));
        }
        holder.f3778a.setImageResource(C0415R.drawable.antispamblack);
        return convertView;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.lenovoAntiSpam.adapter.LocalBlackApater$a */
    private class C0586a {

        /* JADX INFO: renamed from: a */
        ImageView f3778a;

        /* JADX INFO: renamed from: b */
        ImageView f3779b;

        /* JADX INFO: renamed from: c */
        ImageView f3780c;

        /* JADX INFO: renamed from: d */
        TextView f3781d;

        /* JADX INFO: renamed from: e */
        TextView f3782e;

        private C0586a() {
        }

        /* synthetic */ C0586a(LocalBlackApater x0, byte b) {
            this();
        }
    }

    public String getNameStr(int type) {
        if (type == 2) {
            return this.f3776a.getResources().getString(C0415R.string.harss_method1);
        }
        if (type == 1) {
            return this.f3776a.getResources().getString(C0415R.string.harss_method2);
        }
        if (type == 0) {
            return this.f3776a.getResources().getString(C0415R.string.harss_method3);
        }
        return this.f3776a.getResources().getString(C0415R.string.harss_method4);
    }
}
