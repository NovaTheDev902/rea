package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.utils.Const;

/* JADX INFO: loaded from: classes.dex */
public class HealthProtectPrivacy extends BaseHealthCheck {
    public final int SCORE_VALUE_PROTECT_PRIVACY = 8;

    public HealthProtectPrivacy(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 12;
        this.isRootItem = true;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.scan_protect_privacy_detail), this.mHealthManager);
        this.result = new HealthItemResult();
        this.result.key = this.mKey;
        this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
        this.result.title_detail = this.mContext.getString(C0415R.string.scan_protect_privacy_detail);
        this.result.content = this.mContext.getString(C0415R.string.main_tab_private) + this.mContext.getString(C0415R.string.opend);
        this.result.view_type = 5;
        this.result.weight = 9;
        this.result.isOnly = false;
        this.result.action_description = this.mContext.getString(C0415R.string.safe);
        this.mHealthManager.plusOrDecrementNumItem(5, true);
        this.mPreViewType = 5;
        this.mHealthManager.result(this.result);
        progressAddAfterScanEveryItem(this.mHealthManager);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        Const.setProtectPeepSwitchState(true);
        refreshTitle(null, this.mContext.getString(C0415R.string.op_protect_privacy_detail), this.mHealthManager);
        if (this.result != null) {
            this.result.content = this.mContext.getString(C0415R.string.main_tab_private) + this.mContext.getString(C0415R.string.opend);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
        this.mHealthManager.setScore(this.mHealthManager.getScore() + 8);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void manual() {
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void click() {
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void clear() {
        this.result = null;
    }
}
