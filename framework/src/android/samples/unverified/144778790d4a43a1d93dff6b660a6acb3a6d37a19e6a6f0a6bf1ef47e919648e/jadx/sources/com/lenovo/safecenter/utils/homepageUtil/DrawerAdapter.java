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
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerAdvertiseIntercept;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerAgainstTheft;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerBattery;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerChargeShield;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerDailyTools;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerKillVirus;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerLeCloudSyn;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerPhoneAccelerate;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerPrivacyShield;
import com.lenovo.safecenter.utils.homepageUtil.item.DrawerPrivacyZone;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class DrawerAdapter extends BaseAdapter {

    /* JADX INFO: renamed from: a */
    private ArrayList<BaseDrawer> f5814a;

    /* JADX INFO: renamed from: b */
    private Context f5815b;

    /* JADX INFO: renamed from: c */
    private LayoutInflater f5816c;

    /* JADX INFO: renamed from: d */
    private Handler f5817d = new Handler() { // from class: com.lenovo.safecenter.utils.homepageUtil.DrawerAdapter.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    DrawerAdapter.this.notifyDataSetChanged();
                    break;
            }
        }
    };

    public DrawerAdapter(Context context, boolean isUp) {
        this.f5815b = context;
        this.f5816c = (LayoutInflater) context.getSystemService("layout_inflater");
        boolean isRoot = Const.isRootThePhone();
        if (isUp) {
            if (this.f5814a == null) {
                this.f5814a = new ArrayList<>();
                if (isRoot) {
                    this.f5814a.add(new DrawerKillVirus(this.f5815b, true));
                    this.f5814a.add(new DrawerPhoneAccelerate(this.f5815b, true));
                    this.f5814a.add(new DrawerAdvertiseIntercept(this.f5815b, true));
                    this.f5814a.add(new DrawerBattery(this.f5815b, true));
                    return;
                }
                this.f5814a.add(new DrawerBattery(this.f5815b, true));
                this.f5814a.add(new DrawerDailyTools(this.f5815b, true));
                this.f5814a.add(new DrawerAdvertiseIntercept(this.f5815b, true));
                this.f5814a.add(new DrawerLeCloudSyn(this.f5815b, true));
                return;
            }
            return;
        }
        if (this.f5814a == null) {
            this.f5814a = new ArrayList<>();
            this.f5814a.add(new DrawerPrivacyZone(this.f5815b, false));
            if (isRoot) {
                this.f5814a.add(new DrawerLeCloudSyn(this.f5815b, false));
                this.f5814a.add(new DrawerDailyTools(this.f5815b, false));
            } else {
                this.f5814a.add(new DrawerPrivacyShield(this.f5815b, false));
                this.f5814a.add(new DrawerChargeShield(this.f5815b, false));
            }
            this.f5814a.add(new DrawerAgainstTheft(this.f5815b, false));
        }
    }

    public void refresh() {
        this.f5817d.sendEmptyMessage(0);
    }

    @Override // android.widget.Adapter
    public int getCount() {
        if (this.f5814a == null) {
            return 0;
        }
        return this.f5814a.size();
    }

    @Override // android.widget.Adapter
    public Object getItem(int position) {
        if (this.f5814a == null || position >= getCount()) {
            return null;
        }
        return this.f5814a.get(position);
    }

    public void setData(ArrayList<BaseDrawer> dataSource) {
        this.f5814a.addAll(dataSource);
    }

    @Override // android.widget.Adapter
    public long getItemId(int position) {
        return position;
    }

    @Override // android.widget.Adapter
    public View getView(int position, View convertView, ViewGroup parent) {
        View v = this.f5816c.inflate(C0415R.layout.home_page_drawer_item, parent, false);
        final BaseDrawer item = this.f5814a.get(position);
        View v2 = item.getView(v);
        v2.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.utils.homepageUtil.DrawerAdapter.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v3) {
                item.onClick();
            }
        });
        return v2;
    }
}
