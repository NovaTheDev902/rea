package com.lenovo.safecenter.utils.homepageUtil.item;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.AppsManager.PermissionControlNew;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.database.AppUtil;
import com.lenovo.safecenter.support.SafeCenterService;
import com.lenovo.safecenter.support.SafeLog;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.homepageUtil.BaseFourBox;

/* JADX INFO: loaded from: classes.dex */
public class FourBoxPrivacyShield extends BaseFourBox {
    public FourBoxPrivacyShield(Context context) {
        super(C0415R.drawable.img_privacy_shield, context.getString(C0415R.string.permission_control), context);
    }

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public View getView(View parent) {
        SafeLog log;
        ImageView icon = (ImageView) parent.findViewById(C0415R.id.img_icon);
        TextView tvTitle = (TextView) parent.findViewById(C0415R.id.tv_title);
        View layoutCenterAlign = parent.findViewById(C0415R.id.layout_content_twoLine_centerAlign);
        View layoutLeftAndRightAlign = parent.findViewById(C0415R.id.layout_content_twoLine_leftAndRightAlign);
        TextView tv_C_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_centerAlign_up);
        TextView tv_C_Line1Detail = (TextView) parent.findViewById(C0415R.id.tv_centerAlign_down);
        TextView tv_LR_Line1Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_up_title);
        TextView tv_LR_Line2Title = (TextView) parent.findViewById(C0415R.id.tv_leftAndRightAlign_down_title);
        icon.setImageResource(this.idIcon);
        tvTitle.setText(this.mTitle);
        if (SafeCenterService.privacy_count > 0 && (log = Const.lastSafeLogs.get(AppDatabase.PERM_TYPE_PRIVCY)) != null) {
            layoutCenterAlign.setVisibility(8);
            layoutLeftAndRightAlign.setVisibility(0);
            String name = m2449a(log);
            WflUtils.setSpannableString(tv_LR_Line1Title, this.mContext.getString(C0415R.string.Intercept_text) + name, this.mContext.getString(C0415R.string.Intercept_text).length(), this.mContext.getString(C0415R.string.Intercept_text).length() + name.length(), this.mContext.getResources().getColor(C0415R.color.green2));
            tv_LR_Line2Title.setText(log.logSelected == 1 ? this.mContext.getString(C0415R.string.when_calling) + AppUtil.getDescriptionByPid(this.mContext, Integer.valueOf(log.type).intValue()) : AppUtil.getDescriptionByPid(this.mContext, Integer.valueOf(log.type).intValue()));
        } else {
            layoutCenterAlign.setVisibility(0);
            layoutLeftAndRightAlign.setVisibility(8);
            tv_C_Line1Title.setText(this.mContext.getString(C0415R.string.detail_privacy_shield));
            tv_C_Line1Detail.setText(this.mContext.getString(C0415R.string.null_text));
        }
        return parent;
    }

    /* JADX INFO: renamed from: a */
    private String m2449a(SafeLog log) {
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

    @Override // com.lenovo.safecenter.utils.homepageUtil.BaseFourBox
    public void onClick() {
        enterPrivacyShield(this.mContext);
    }

    public static void enterPrivacyShield(Context context) {
        Intent intent = new Intent(context, (Class<?>) PermissionControlNew.class);
        context.startActivity(intent);
    }
}
