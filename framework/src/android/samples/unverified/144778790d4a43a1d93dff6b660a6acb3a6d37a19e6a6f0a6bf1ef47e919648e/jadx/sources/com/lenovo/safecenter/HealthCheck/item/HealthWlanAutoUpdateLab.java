package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.utils.updateLab.AutoUpdateLabManager;

/* JADX INFO: loaded from: classes.dex */
public class HealthWlanAutoUpdateLab extends BaseHealthCheck {
    public final int SCORE_VALUE_WLAN_AUTO_UPDATE_LAB = 2;

    public HealthWlanAutoUpdateLab(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 20;
        this.isRootItem = false;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.wlan_auto_update_title), this.mHealthManager);
        this.result = new HealthItemResult();
        this.result.key = this.mKey;
        this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
        this.result.title_detail = this.mContext.getString(C0415R.string.wlan_auto_update_title);
        boolean isAutoUpdate = AutoUpdateLabManager.isAutoUpdate(this.mContext);
        if (isAutoUpdate) {
            this.result.content = this.mContext.getString(C0415R.string.op_auto_update_detail);
            this.result.view_type = 5;
            this.result.weight = 9;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
            this.mHealthManager.plusOrDecrementNumItem(5, true);
        } else {
            this.result.content = this.mContext.getString(C0415R.string.scan_auto_update_detail);
            this.result.view_type = 2;
            this.result.weight = 3;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.set);
            this.mHealthManager.setScore(this.mHealthManager.getScore() - 2);
            this.mHealthManager.plusOrDecrementNumItem(2, true);
            this.mPreViewType = 2;
        }
        this.mHealthManager.result(this.result);
        progressAddAfterScanEveryItem(this.mHealthManager);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        AutoUpdateLabManager.setIsAutoUpdate(true, this.mContext);
        AutoUpdateLabManager.setAutoUpdateMode(0, this.mContext);
        refreshTitle(null, this.mContext.getString(C0415R.string.op_auto_update_detail), this.mHealthManager);
        if (this.result != null) {
            this.result.content = this.mContext.getString(C0415R.string.op_auto_update_detail);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
        this.mHealthManager.setScore(this.mHealthManager.getScore() + 2);
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
