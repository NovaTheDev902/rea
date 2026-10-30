package com.lenovo.safecenter.systeminfo.adapter;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.systeminfo.entity.PhoneInfoItem;
import com.lenovo.safecenter.utils.Const;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class PhoneInfoListAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private static final String f5590a = PhoneInfoListAdapter.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private List<PhoneInfoItem> f5591b;

    public PhoneInfoListAdapter(List<PhoneInfoItem> phoneItems) {
        this.f5591b = phoneItems;
    }

    @Override // android.widget.Adapter
    public int getCount() {
        if (this.f5591b != null) {
            return this.f5591b.size();
        }
        return 0;
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        if (this.f5591b != null) {
            return this.f5591b.get(position);
        }
        return null;
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        C1005a viewHolder;
        byte b = 0;
        View view = convertView;
        if (view == null) {
            viewHolder = new C1005a(b);
            view = LayoutInflater.from(Const.mContext).inflate(C0415R.layout.phoneinfo_detial_item, parent, false);
            viewHolder.f5592a = (ImageView) view.findViewById(C0415R.id.img_phoneinfo_icon);
            viewHolder.f5593b = (TextView) view.findViewById(C0415R.id.tv_phoneinfo_box);
            view.setTag(viewHolder);
        } else {
            viewHolder = (C1005a) view.getTag();
        }
        Log.i(f5590a, position + "");
        PhoneInfoItem infoItem = this.f5591b.get(position);
        viewHolder.f5592a.setImageResource(infoItem.getIconRes());
        viewHolder.f5593b.setText(infoItem.getInfo());
        return view;
    }

    /* JADX INFO: renamed from: com.lenovo.safecenter.systeminfo.adapter.PhoneInfoListAdapter$a */
    private static final class C1005a {

        /* JADX INFO: renamed from: a */
        ImageView f5592a;

        /* JADX INFO: renamed from: b */
        TextView f5593b;

        private C1005a() {
        }

        /* synthetic */ C1005a(byte b) {
            this();
        }
    }
}
