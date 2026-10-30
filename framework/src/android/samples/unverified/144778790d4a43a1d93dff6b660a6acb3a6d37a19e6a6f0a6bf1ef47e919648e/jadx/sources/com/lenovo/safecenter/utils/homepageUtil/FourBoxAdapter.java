package com.lenovo.safecenter.utils.homepageUtil;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.homepageUtil.item.FourBoxHarassIntercept;
import com.lenovo.safecenter.utils.homepageUtil.item.FourBoxKillVirus;
import com.lenovo.safecenter.utils.homepageUtil.item.FourBoxPhoneAccelerate;
import com.lenovo.safecenter.utils.homepageUtil.item.FourBoxPrivacyShield;
import com.lenovo.safecenter.utils.homepageUtil.item.FourBoxTrafficMonitor;
import com.lenovo.safecenter.utils.homepageUtil.item.FourBoxchargeShield;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class FourBoxAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private ArrayList<BaseFourBox> f5821a;

    /* JADX INFO: renamed from: b */
    private Context f5822b;

    /* JADX INFO: renamed from: c */
    private LayoutInflater f5823c;

    /* JADX INFO: renamed from: d */
    private Handler f5824d = new Handler() { // from class: com.lenovo.safecenter.utils.homepageUtil.FourBoxAdapter.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    FourBoxAdapter.this.notifyDataSetChanged();
                    break;
            }
        }
    };

    public FourBoxAdapter(Context context) {
        this.f5822b = context;
        this.f5823c = (LayoutInflater) context.getSystemService("layout_inflater");
        if (this.f5821a == null) {
            this.f5821a = new ArrayList<>();
            if (Const.isRootThePhone()) {
                this.f5821a.add(new FourBoxPrivacyShield(this.f5822b));
                this.f5821a.add(new FourBoxchargeShield(this.f5822b));
            } else {
                this.f5821a.add(new FourBoxKillVirus(this.f5822b));
                this.f5821a.add(new FourBoxPhoneAccelerate(this.f5822b));
            }
            this.f5821a.add(new FourBoxHarassIntercept(this.f5822b));
            this.f5821a.add(new FourBoxTrafficMonitor(this.f5822b));
        }
    }

    public void refresh() {
        this.f5824d.sendEmptyMessage(0);
    }

    @Override // android.widget.Adapter
    public int getCount() {
        if (this.f5821a == null) {
            return 0;
        }
        return this.f5821a.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        if (this.f5821a == null || position >= getCount()) {
            return null;
        }
        return this.f5821a.get(position);
    }

    public void setData(ArrayList<BaseFourBox> dataSource) {
        this.f5821a.addAll(dataSource);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        View v = this.f5823c.inflate(C0415R.layout.home_page_four_box_item, parent, false);
        final BaseFourBox item = this.f5821a.get(position);
        View v2 = item.getView(v);
        v2.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.utils.homepageUtil.FourBoxAdapter.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v3) {
                item.onClick();
            }
        });
        return v2;
    }
}
