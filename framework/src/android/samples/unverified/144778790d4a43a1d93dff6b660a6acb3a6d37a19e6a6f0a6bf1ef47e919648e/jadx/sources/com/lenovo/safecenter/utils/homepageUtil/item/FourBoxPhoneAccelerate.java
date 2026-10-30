package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.content.Intent;
import android.text.format.Formatter;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.performancecenter.coreui.util.MemoryTools;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.performance.PhoneAccelerateActivity;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.BaseFourBox;

/* JADX INFO: loaded from: classes.dex */
public class FourBoxPhoneAccelerate extends BaseFourBox {
    public FourBoxPhoneAccelerate(Context context) {
        super(C0415R.drawable.img_phone_accelerate, context.getString(C0415R.string.phone_acceleration), context);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public View getView(View parent) {
        int i;
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_icon);
        TextView tvTitle = (TextView) parent.findViewById(C0415R.id.tv_title);
        ViewGroup layoutCenterAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_centerAlign);
        ViewGroup layoutLeftAndRightAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_leftAndRightAlign);
        TextView tv_LR_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_title);
        TextView tv_LR_Line1Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_detail);
        TextView tv_LR_Line2Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_title);
        icon.setImageResource(this.idIcon);
        tvTitle.setText(this.mTitle);
        layoutCenterAlign.setVisibility(8);
        layoutLeftAndRightAlign.setVisibility(0);
        int percentage = 100 - new MemoryTools().getSystemMeminfo();
        tv_LR_Line1Title.setText(this.mContext.getString(C0415R.string.memory_Surplus));
        String strPercentage = percentage + "%";
        tv_LR_Line1Detail.setText(strPercentage);
        long interval = System.currentTimeMillis() - Utils.getLastKillTime(this.mContext);
        if (interval < Utils.CLICK_INTERVAL) {
            tv_LR_Line1Detail.setTextColor(this.mContext.getResources().getColor(C0415R.color.green2));
        } else {
            long totalMemory = new MemoryTools().getTotalMemory() * 1024;
            WflUtils.Log("i", "wu0wu", "totalMemory=" + Formatter.formatShortFileSize(this.mContext, totalMemory));
            if (totalMemory > 536870912) {
                WflUtils.Log("i", "wu0wu", "getValueWordingInCritical=30");
                i = 30;
            } else {
                WflUtils.Log("i", "wu0wu", "getValueWordingInCritical=20");
                i = 20;
            }
            if (percentage > i) {
                tv_LR_Line1Detail.setTextColor(this.mContext.getResources().getColor(C0415R.color.green2));
                tv_LR_Line2Title.setText(this.mContext.getString(C0415R.string.can_run_more_fast));
            } else {
                tv_LR_Line1Detail.setTextColor(this.mContext.getResources().getColor(C0415R.color.red1));
                tv_LR_Line2Title.setText(this.mContext.getString(C0415R.string.clear_memory_intime));
            }
        }
        return parent;
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public void onClick() {
        enterPhoneAccelerate(this.mContext);
    }

    public static void enterPhoneAccelerate(Context context) {
        Intent it = new Intent(context, (Class<?>) PhoneAccelerateActivity.class);
        context.startActivity(it);
    }
}
