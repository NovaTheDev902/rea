package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.PwdUtil;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.BaseDrawer;

/* JADX INFO: loaded from: classes.dex */
public class DrawerAppLock extends BaseDrawer {
    public DrawerAppLock(Context context, boolean isUp) {
        super(C0415R.drawable.img_drawer_content_app_lock, context.getString(C0415R.string.private_threebig), context, isUp);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseDrawer
    public View getView(View parent) {
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_drawer_item);
        TextView title = (TextView) parent.findViewById(C0415R.id.title_drawer_item);
        ViewGroup bg = (ViewGroup) parent.findViewById(C0415R.id.layout_drawer_item);
        ImageView newMark = (ImageView) parent.findViewById(C0415R.id.newmark_drawer_item);
        if (this.mIsNew) {
            newMark.setVisibility(0);
        } else {
            newMark.setVisibility(8);
        }
        icon.setImageResource(this.idIcon);
        title.setText(this.mTitle);
        setBackgroundResource(bg);
        return parent;
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseDrawer
    public void onClick() {
        if (PwdUtil.hasPassword(this.mContext)) {
            DialogUtil.showPwdDialog(Const.ACTION_JUMP_APP_LOCK, this.mContext);
            this.mHandler.sendEmptyMessageDelayed(1, 500L);
        } else {
            WflUtils.startSettingPasswordActivity(this.mContext, Const.ACTION_JUMP_APP_LOCK);
        }
    }
}
