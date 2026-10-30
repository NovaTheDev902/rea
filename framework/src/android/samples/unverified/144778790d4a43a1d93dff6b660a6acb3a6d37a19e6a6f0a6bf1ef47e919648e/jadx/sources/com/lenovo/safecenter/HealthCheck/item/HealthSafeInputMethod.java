package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.provider.Settings;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.utils.Const;

/* JADX INFO: loaded from: classes.dex */
public class HealthSafeInputMethod extends BaseHealthCheck {
    public final int SCORE_VALUE_SAFE_INPUT_METHOD_ON = 8;

    public HealthSafeInputMethod(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 17;
        this.isRootItem = true;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_sole_checkup_item), this.mContext.getString(C0415R.string.scan_safeinput_method_detail), this.mHealthManager);
        int i = Const.getSafeInputMethod_state();
        if (i == 1) {
            this.result = new HealthItemResult();
            this.result.key = this.mKey;
            this.result.title = this.mContext.getString(C0415R.string.lesafe_sole_checkup_item);
            this.result.title_detail = this.mContext.getString(C0415R.string.scan_safeinput_method_detail);
            if (Settings.System.getInt(this.mContext.getContentResolver(), "safeinputmethod_on", 0) == 1) {
                this.result.content = this.mContext.getString(C0415R.string.safeinputmethod_protecting);
                this.result.view_type = 5;
                this.result.weight = 9;
                this.result.isOnly = true;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
                this.mHealthManager.plusOrDecrementNumItem(5, true);
            } else {
                this.result.content = this.mContext.getString(C0415R.string.safeinputmethod) + this.mContext.getString(C0415R.string.no_open);
                this.result.view_type = 2;
                this.result.weight = 3;
                this.result.isOnly = true;
                this.result.action_description = this.mContext.getString(C0415R.string.open);
                this.mHealthManager.setScore(this.mHealthManager.getScore() - 8);
                this.mHealthManager.plusOrDecrementNumItem(2, true);
                this.mPreViewType = 2;
            }
            this.mHealthManager.result(this.result);
            progressAddAfterScanEveryItem(this.mHealthManager);
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        Settings.System.putInt(this.mContext.getContentResolver(), "safeinputmethod_on", 1);
        refreshTitle(null, this.mContext.getString(C0415R.string.op_safeinput_method_detail), this.mHealthManager);
        if (this.result != null) {
            this.result.content = this.mContext.getString(C0415R.string.safeinputmethod_protecting);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = true;
            this.result.action_description = this.mContext.getString(C0415R.string.open);
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
