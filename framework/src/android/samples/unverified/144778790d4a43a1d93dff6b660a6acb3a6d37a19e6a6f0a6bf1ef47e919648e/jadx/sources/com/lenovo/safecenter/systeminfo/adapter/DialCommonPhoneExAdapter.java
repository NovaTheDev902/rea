package com.lenovo.safecenter.systeminfo.adapter;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.systeminfo.entity.CommonNumber;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class DialCommonPhoneExAdapter extends BaseExpandableListAdapter {

    /* JADX INFO: renamed from: a */
    private static int[] f5577a = new int[11];

    /* JADX INFO: renamed from: b */
    private HashMap<String, List<CommonNumber>> f5578b;

    /* JADX INFO: renamed from: c */
    private Context f5579c;

    /* JADX INFO: renamed from: d */
    private StringBuffer f5580d = new StringBuffer();

    public static class DialCommonPhoneChildModeHolder {
        public TextView mInfoChildText;
    }

    public static class DialCommonPhoneGroupModeHolder {

        /* JADX INFO: renamed from: a */
        ImageView f5582a;

        /* JADX INFO: renamed from: b */
        ImageView f5583b;

        /* JADX INFO: renamed from: c */
        TextView f5584c;

        /* JADX INFO: renamed from: d */
        TextView f5585d;

        /* JADX INFO: renamed from: e */
        LinearLayout f5586e;
    }

    public static class ViewBodyHolder {

        /* JADX INFO: renamed from: a */
        TextView f5587a;

        /* JADX INFO: renamed from: b */
        TextView f5588b;

        /* JADX INFO: renamed from: c */
        TextView f5589c;
        public LinearLayout mLayoutchild;
    }

    static {
        f5577a[0] = C0415R.drawable.comnum_hotal;
        f5577a[1] = C0415R.drawable.comnum_airplane;
        f5577a[2] = C0415R.drawable.comnum_ticket;
        f5577a[3] = C0415R.drawable.comnum_delivery;
        f5577a[4] = C0415R.drawable.comnum_insurance;
        f5577a[5] = C0415R.drawable.comnum_trip;
        f5577a[6] = C0415R.drawable.comnum_catering;
        f5577a[7] = C0415R.drawable.comnum_communication;
        f5577a[8] = C0415R.drawable.comnum_customer;
        f5577a[9] = C0415R.drawable.comnum_daily;
        f5577a[10] = C0415R.drawable.comnum_bank;
    }

    public DialCommonPhoneExAdapter(Context paramContext, HashMap<String, List<CommonNumber>> paramHashMap) {
        this.f5578b = new HashMap<>();
        this.f5579c = paramContext;
        this.f5578b = paramHashMap;
    }

    @Override // android.widget.ExpandableListAdapter
    public Object getChild(int groupPosition, int childPosition) {
        if (this.f5578b != null) {
            return this.f5578b.get(this.f5578b.keySet().toArray()[groupPosition]).get(childPosition);
        }
        return null;
    }

    @Override // android.widget.ExpandableListAdapter
    public long getChildId(int groupPosition, int childPosition) {
        return 0L;
    }

    @Override // android.widget.ExpandableListAdapter
    public View getChildView(int groupPosition, int childPosition, boolean isLastChild, View paramView, ViewGroup paramViewGroup) {
        View localView;
        ViewBodyHolder localObject;
        if (paramView == null) {
            localView = ((LayoutInflater) this.f5579c.getSystemService("layout_inflater")).inflate(C0415R.layout.list_item_dial_common, (ViewGroup) null);
            localObject = new ViewBodyHolder();
            localObject.f5589c = (TextView) localView.findViewById(C0415R.id.call_button);
            localObject.f5587a = (TextView) localView.findViewById(C0415R.id.name);
            localObject.f5588b = (TextView) localView.findViewById(C0415R.id.phonenum_location);
            localObject.mLayoutchild = (LinearLayout) localView;
            localView.setTag(localObject);
        } else {
            ViewBodyHolder localViewBodyHolder = (ViewBodyHolder) paramView.getTag();
            localView = paramView;
            localObject = localViewBodyHolder;
        }
        String str = (String) this.f5578b.keySet().toArray()[groupPosition];
        CommonNumber commonNumber = (CommonNumber) ((ArrayList) this.f5578b.get(str)).get(childPosition);
        localObject.f5587a.setText(commonNumber.getName());
        localObject.f5588b.setText(commonNumber.getPhoneNumber());
        int[] position = {groupPosition, childPosition};
        localObject.f5589c.setTag(position);
        localObject.f5589c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.systeminfo.adapter.DialCommonPhoneExAdapter.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                int[] a = (int[]) v.getTag();
                String str2 = (String) DialCommonPhoneExAdapter.this.f5578b.keySet().toArray()[a[0]];
                CommonNumber comNumber = (CommonNumber) ((ArrayList) DialCommonPhoneExAdapter.this.f5578b.get(str2)).get(a[1]);
                Intent phoneIntent = new Intent("android.intent.action.CALL", Uri.parse("tel:" + comNumber.getPhoneNumber()));
                DialCommonPhoneExAdapter.this.f5579c.startActivity(phoneIntent);
            }
        });
        return localView;
    }

    @Override // android.widget.ExpandableListAdapter
    public int getChildrenCount(int paramInt) {
        String str = (String) this.f5578b.keySet().toArray()[paramInt];
        return ((ArrayList) this.f5578b.get(str)).size();
    }

    @Override // android.widget.ExpandableListAdapter
    public Object getGroup(int paramInt) {
        return null;
    }

    @Override // android.widget.ExpandableListAdapter
    public int getGroupCount() {
        return this.f5578b.keySet().size();
    }

    @Override // android.widget.ExpandableListAdapter
    public long getGroupId(int paramInt) {
        return 0L;
    }

    @Override // android.widget.ExpandableListAdapter
    public View getGroupView(int groupPosition, boolean isExpanded, View paramView, ViewGroup paramViewGroup) {
        DialCommonPhoneGroupModeHolder groupViewHolder;
        if (paramView == null) {
            View localView = ((LayoutInflater) this.f5579c.getSystemService("layout_inflater")).inflate(C0415R.layout.list_item_dialphone_father, (ViewGroup) null);
            groupViewHolder = new DialCommonPhoneGroupModeHolder();
            groupViewHolder.f5586e = (LinearLayout) localView;
            groupViewHolder.f5585d = (TextView) localView.findViewById(C0415R.id.textViewCategory);
            groupViewHolder.f5584c = (TextView) localView.findViewById(C0415R.id.textMoreInfo);
            groupViewHolder.f5583b = (ImageView) localView.findViewById(C0415R.id.image_show_icon);
            groupViewHolder.f5582a = (ImageView) localView.findViewById(C0415R.id.image_logo);
            localView.setTag(groupViewHolder);
            paramView = localView;
        } else {
            groupViewHolder = (DialCommonPhoneGroupModeHolder) paramView.getTag();
        }
        String group = (String) this.f5578b.keySet().toArray()[groupPosition];
        int groupItemSize = this.f5578b.get(group).size();
        groupViewHolder.f5585d.setText(group + " (" + groupItemSize + ")");
        this.f5580d.delete(0, this.f5580d.length());
        for (int i = 0; i < groupItemSize && i < 3; i++) {
            this.f5580d.append(this.f5578b.get(group).get(i).getName());
            if (i < 2) {
                this.f5580d.append("、");
            }
        }
        if (isExpanded) {
            groupViewHolder.f5583b.setBackgroundResource(C0415R.drawable.arrow_down);
            groupViewHolder.f5586e.setBackgroundColor(this.f5579c.getResources().getColor(C0415R.color.list_item_bg_color_focus));
        } else {
            groupViewHolder.f5583b.setBackgroundResource(C0415R.drawable.arrow1);
            groupViewHolder.f5586e.setBackgroundColor(this.f5579c.getResources().getColor(C0415R.color.list_item_bg_color));
        }
        groupViewHolder.f5584c.setText(this.f5580d.toString());
        groupViewHolder.f5582a.setImageResource(f5577a[groupPosition]);
        return paramView;
    }

    @Override // android.widget.ExpandableListAdapter
    public boolean hasStableIds() {
        return false;
    }

    @Override // android.widget.ExpandableListAdapter
    public boolean isChildSelectable(int paramInt1, int paramInt2) {
        return false;
    }
}
