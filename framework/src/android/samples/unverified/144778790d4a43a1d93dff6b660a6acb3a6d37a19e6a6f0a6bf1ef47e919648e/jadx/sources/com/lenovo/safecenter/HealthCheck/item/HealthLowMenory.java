package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.content.Intent;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.Laboratory.AppUninstall;
import com.lenovo.safecenter.utils.MyUtils;

/* JADX INFO: loaded from: classes.dex */
public class HealthLowMenory extends BaseHealthCheck {

    /* JADX INFO: renamed from: a */
    private final float f2435a = 0.8f;

    /* JADX INFO: renamed from: b */
    private boolean f2436b = false;

    public boolean isShowLowMemoryActivity() {
        return this.f2436b;
    }

    public HealthLowMenory(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 4;
        this.isRootItem = true;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_sole_checkup_item), this.mContext.getString(C0415R.string.scan_lowmemory_detail), this.mHealthManager);
        float memoryUsedPersent = MyUtils.getDataDirectorySize();
        if (memoryUsedPersent >= 0.8f) {
            this.result = new HealthItemResult();
            this.result.key = this.mKey;
            this.result.title = this.mContext.getString(C0415R.string.lesafe_sole_checkup_item);
            this.result.title_detail = this.mContext.getString(C0415R.string.scan_lowmemory_detail);
            this.result.content = this.mContext.getString(C0415R.string.scan_lowmemory_detail);
            this.result.view_type = 3;
            this.result.weight = 5;
            this.result.isOnly = true;
            this.result.action_description = this.mContext.getString(C0415R.string.clear_text);
            this.mHealthManager.plusOrDecrementNumItem(3, true);
            this.mPreViewType = 3;
            this.mHealthManager.result(this.result);
            progressAddAfterScanEveryItem(this.mHealthManager);
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    public void manual() {
        this.f2436b = false;
        if (MyUtils.getDataDirectorySize() < 0.8f) {
            if (this.result != null) {
                this.result.view_type = 4;
                this.result.weight = 7;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
            }
            this.mHealthManager.plusOrDecrementNumItem(4, true);
            this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
            this.mHealthManager.result(this.result);
            this.mHealthManager.saveHealthScoreAndCheckupTime();
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void click() {
        Intent intent = new Intent(this.mContext, (Class<?>) AppUninstall.class);
        intent.setFlags(268435456);
        this.mContext.startActivity(intent);
        this.f2436b = true;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void clear() {
        this.result = null;
    }
}
