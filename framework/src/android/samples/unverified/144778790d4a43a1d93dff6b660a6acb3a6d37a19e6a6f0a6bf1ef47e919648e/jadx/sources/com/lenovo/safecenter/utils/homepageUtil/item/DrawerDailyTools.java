package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.content.Intent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.systeminfo.p011ui.activity.DailyTools;
import com.lenovo.safecenter.utils.NewFunctionNoticeManager;
import com.lenovo.safecenter.utils.homepageUtil.BaseDrawer;

/* JADX INFO: loaded from: classes.dex */
public class DrawerDailyTools extends BaseDrawer {
    public DrawerDailyTools(Context context, boolean isUp) {
        super(C0415R.drawable.home_page_drawer_dayly_tools, context.getString(C0415R.string.dayly_tools), context, isUp);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseDrawer
    public View getView(View parent) {
        if (NewFunctionNoticeManager.hasContentInType(this.mContext, NewFunctionNoticeManager.TYPE_TOOLS)) {
            ImageView newMark = (ImageView) parent.findViewById(C0415R.id.newmark_drawer_item);
            newMark.setVisibility(0);
        }
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_drawer_item);
        TextView title = (TextView) parent.findViewById(C0415R.id.title_drawer_item);
        ViewGroup bg = (ViewGroup) parent.findViewById(C0415R.id.layout_drawer_item);
        icon.setImageResource(this.idIcon);
        title.setText(this.mTitle);
        setBackgroundResource(bg);
        return parent;
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseDrawer
    public void onClick() {
        this.mContext.startActivity(new Intent(this.mContext, (Class<?>) DailyTools.class));
    }
}
