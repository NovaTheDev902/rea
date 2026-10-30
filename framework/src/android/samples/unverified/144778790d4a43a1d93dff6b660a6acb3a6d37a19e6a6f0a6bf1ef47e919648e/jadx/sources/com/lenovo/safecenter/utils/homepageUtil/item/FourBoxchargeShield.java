package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.AppsManager.ChargeSafeNew;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.BaseFourBox;

/* JADX INFO: loaded from: classes.dex */
public class FourBoxchargeShield extends BaseFourBox {
    public FourBoxchargeShield(Context context) {
        super(C0415R.drawable.img_charge_shield, context.getString(C0415R.string.charge_safe), context);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public View getView(View parent) {
        SafeLog log;
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_icon);
        TextView tvTitle = (TextView) parent.findViewById(C0415R.id.tv_title);
        ViewGroup layoutCenterAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_centerAlign);
        ViewGroup layoutLeftAndRightAlign = (ViewGroup) parent.findViewById(C0415R.id.layout_content_twoLine_leftAndRightAlign);
        TextView tv_LR_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_title);
        TextView tv_LR_Line1Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_detail);
        TextView tv_LR_Line2Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_title);
        TextView tv_LR_Line2Detail = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_detail);
        icon.setImageResource(this.idIcon);
        tvTitle.setText(this.mTitle);
        if (SafeCenterService.charge_count > 0 && (log = Const.lastSafeLogs.get("tariff")) != null) {
            layoutCenterAlign.setVisibility(8);
            layoutLeftAndRightAlign.setVisibility(0);
            String name = m2450a(log);
            WflUtils.setSpannableString(tv_LR_Line1Title, this.mContext.getString(C0415R.string.Intercept_text) + name, this.mContext.getString(C0415R.string.Intercept_text).length(), this.mContext.getString(C0415R.string.Intercept_text).length() + name.length(), this.mContext.getResources().getColor(C0415R.color.green2));
            tv_LR_Line2Title.setText(log.logSelected == 1 ? this.mContext.getString(C0415R.string.when_calling) + AppUtil.getDescriptionByPid(this.mContext, Integer.valueOf(log.type).intValue()) : AppUtil.getDescriptionByPid(this.mContext, Integer.valueOf(log.type).intValue()));
        } else {
            layoutLeftAndRightAlign.setVisibility(0);
            layoutCenterAlign.setVisibility(8);
            tv_LR_Line1Title.setText(this.mContext.getString(C0415R.string.this_month_calltime));
            tv_LR_Line2Title.setText(this.mContext.getString(C0415R.string.this_month_sms_num));
            WflUtils.setSpannableString(tv_LR_Line1Detail, String.format(this.mContext.getString(C0415R.string.minute_num), Integer.valueOf(Const.getCallOutgoingDurationCurrMonth())), 0, String.valueOf(Const.getCallOutgoingDurationCurrMonth()).length(), this.mContext.getResources().getColor(C0415R.color.green2));
            WflUtils.setSpannableString(tv_LR_Line2Detail, String.format(this.mContext.getString(C0415R.string.tiao_num), Integer.valueOf(Const.getSmsSendNumCurrMonth())), 0, String.valueOf(Const.getSmsSendNumCurrMonth()).length(), this.mContext.getResources().getColor(C0415R.color.green2));
        }
        return parent;
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public void onClick() {
        enterchargeShield(this.mContext);
    }

    public static void enterchargeShield(Context context) {
        Intent intent = new Intent(context, (Class<?>) ChargeSafeNew.class);
        context.startActivity(intent);
    }

    /* JADX INFO: renamed from: a */
    private String m2450a(SafeLog log) {
        PackageManager pm = this.mContext.getPackageManager();
        try {
            String name = pm.getApplicationInfo(log.packageName, 0).loadLabel(pm).toString();
            return name;
        } catch (Exception e) {
            e.printStackTrace();
            String name2 = log.appName;
            return name2;
        }
    }
}
