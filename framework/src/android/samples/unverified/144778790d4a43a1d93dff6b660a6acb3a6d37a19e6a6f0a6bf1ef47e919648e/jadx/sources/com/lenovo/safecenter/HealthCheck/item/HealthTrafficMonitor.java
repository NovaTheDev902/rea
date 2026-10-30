package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;

/* JADX INFO: loaded from: classes.dex */
public class HealthTrafficMonitor extends BaseHealthCheck {
    public HealthTrafficMonitor(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 15;
        this.isRootItem = false;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.scan_traffic_monitor_detail), this.mHealthManager);
        this.result = new HealthItemResult();
        this.result.key = this.mKey;
        this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
        this.result.title_detail = this.mContext.getString(C0415R.string.scan_traffic_monitor_detail);
        this.result.content = this.mContext.getString(C0415R.string.traffic_monitor) + this.mContext.getString(C0415R.string.opend);
        this.result.view_type = 5;
        this.result.weight = 9;
        this.result.isOnly = false;
        this.result.action_description = this.mContext.getString(C0415R.string.safe);
        this.mHealthManager.plusOrDecrementNumItem(5, true);
        this.mHealthManager.result(this.result);
        progressAddAfterScanEveryItem(this.mHealthManager);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
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
