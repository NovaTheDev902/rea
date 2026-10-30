package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.support.AppInfo;
import com.lenovo.safecenter.utils.Const;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class HealthReadPrivacyApp extends BaseHealthCheck {
    public final int SCORE_VALUE_BACKGROUD_READ_PRIVACY = 1;

    /* JADX INFO: renamed from: a */
    private int f2440a = 0;

    /* JADX INFO: renamed from: b */
    private AppDatabase f2441b;

    public HealthReadPrivacyApp(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 13;
        this.f2441b = new AppDatabase(context);
        this.isRootItem = true;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_sole_checkup_item), this.mContext.getString(C0415R.string.scan_readPrivacyApp_detail), this.mHealthManager);
        boolean isOn = Const.getProtectPeepSwitchState();
        if (isOn) {
            ArrayList<AppInfo> readPrivacyList = this.f2441b.loadApps(this.mContext, AppDatabase.PERM_TYPE_PRIVCY, canDoInRoot());
            this.f2440a = this.f2441b.healthCheckPermission(this.mContext, readPrivacyList);
            int allAppSize = readPrivacyList.size();
            if (allAppSize != 0) {
                this.result = new HealthItemResult();
                this.result.key = this.mKey;
                this.result.title = this.mContext.getString(C0415R.string.lesafe_sole_checkup_item);
                this.result.title_detail = this.mContext.getString(C0415R.string.scan_readPrivacyApp_detail);
                if (this.f2440a != 0) {
                    this.result.content = String.format(this.mContext.getString(C0415R.string.healthcheck_readPrivacy_can_op), Integer.valueOf(this.f2440a));
                    this.result.view_type = 2;
                    this.result.weight = 3;
                    this.result.isOnly = true;
                    this.result.action_description = this.mContext.getString(C0415R.string.optimizition);
                    this.mHealthManager.setScore(this.mHealthManager.getScore() - (this.f2440a * 1));
                    this.mHealthManager.plusOrDecrementNumItem(2, true);
                    this.mPreViewType = 2;
                } else {
                    this.result.content = this.mContext.getString(C0415R.string.healthcheck_readPrivacy_safe);
                    this.result.view_type = 5;
                    this.result.weight = 9;
                    this.result.isOnly = true;
                    this.result.action_description = this.mContext.getString(C0415R.string.safe);
                    this.mHealthManager.plusOrDecrementNumItem(5, true);
                    this.mPreViewType = 5;
                }
                this.mHealthManager.result(this.result);
                progressAddAfterScanEveryItem(this.mHealthManager);
            }
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        this.f2441b.expertSuggest(this.mContext, this.f2441b.loadApps(this.mContext, AppDatabase.PERM_TYPE_PRIVCY, canDoInRoot()), false);
        refreshTitle(null, this.mContext.getString(C0415R.string.op_readPrivacyApp_detail), this.mHealthManager);
        if (this.result != null) {
            this.result.content = String.format(this.mContext.getString(C0415R.string.healthcheck_readPrivacy_op), Integer.valueOf(this.f2440a));
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
        this.mHealthManager.setScore(this.mHealthManager.getScore() + (this.f2440a * 1));
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
