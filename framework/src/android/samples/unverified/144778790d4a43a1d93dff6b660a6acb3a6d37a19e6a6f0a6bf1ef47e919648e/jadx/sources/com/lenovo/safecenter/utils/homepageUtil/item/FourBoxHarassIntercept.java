package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.content.Intent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.lenovoAntiSpam.newview.AntiSpamMain;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.BaseFourBox;

/* JADX INFO: loaded from: classes.dex */
public class FourBoxHarassIntercept extends BaseFourBox {
    public FourBoxHarassIntercept(Context context) {
        super(C0415R.drawable.img_harass_intercept, context.getString(C0415R.string.antispamapp_name), context);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public View getView(View parent) {
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_icon);
        TextView tvTitle = (TextView) parent.findViewById(C0415R.id.tv_title);
        ViewGroup layoutCenterAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_centerAlign);
        ViewGroup layoutLeftAndRightAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_leftAndRightAlign);
        TextView tv_C_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_centerAlign_up);
        TextView tv_LR_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_title);
        TextView tv_LR_Line1Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_detail);
        TextView tv_LR_Line2Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_title);
        TextView tv_LR_Line2Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_detail);
        icon.setImageResource(this.idIcon);
        tvTitle.setText(this.mTitle);
        if (!Const.getProtectHarassSwitchState()) {
            layoutLeftAndRightAlign.setVisibility(8);
            layoutCenterAlign.setVisibility(0);
            tv_C_Line1Title.setText(this.mContext.getString(C0415R.string.main_tab_harass) + this.mContext.getString(C0415R.string.no_open));
            tv_C_Line1Title.setTextColor(this.mContext.getResources().getColor(C0415R.color.red1));
        } else {
            layoutLeftAndRightAlign.setVisibility(0);
            layoutCenterAlign.setVisibility(8);
            tv_LR_Line1Title.setText(C0415R.string.harass_phone);
            tv_LR_Line2Title.setText(C0415R.string.garbage_sms);
            WflUtils.setSpannableString(tv_LR_Line1Detail, String.format(this.mContext.getString(C0415R.string.ge), Integer.valueOf(SafeCenterService.harass_call_count)), 0, String.valueOf(SafeCenterService.harass_call_count).length(), this.mContext.getResources().getColor(C0415R.color.green2));
            WflUtils.setSpannableString(tv_LR_Line2Detail, String.format(this.mContext.getString(C0415R.string.tiao_num), Integer.valueOf(SafeCenterService.harass_msg_count)), 0, String.valueOf(SafeCenterService.harass_msg_count).length(), this.mContext.getResources().getColor(C0415R.color.green2));
        }
        return parent;
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public void onClick() {
        Intent intent = new Intent(this.mContext, (Class<?>) AntiSpamMain.class);
        this.mContext.startActivity(intent);
    }
}
