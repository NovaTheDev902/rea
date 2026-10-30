package com.lenovo.safecenter.HealthCheck;

import android.content.Context;
import com.lenovo.safecenter.utils.WflUtils;

/* JADX INFO: loaded from: classes.dex */
public abstract class BaseHealthCheck {
    protected Context mContext;
    protected HealthManager mHealthManager;
    protected int mPreViewType = 0;
    protected int mKey = 0;
    protected HealthItemResult result = null;
    protected boolean isRootItem = false;

    protected abstract void clear();

    protected abstract void click();

    protected abstract void manual();

    protected abstract void optimiza();

    protected abstract void scan();

    protected void refreshTitle(String title, String titleDetail, HealthManager mHealthManager) {
        HealthItemResult result = new HealthItemResult();
        result.title = title;
        result.title_detail = titleDetail;
        mHealthManager.onOneItemProcess(result);
    }

    protected void progressAddAfterScanEveryItem(HealthManager healthManager) {
        healthManager.setScanProgress(healthManager.getScanProgress() + healthManager.getValueProgressEveryCheck());
    }

    protected boolean canDoInRoot() {
        return WflUtils.isRoot();
    }
}
