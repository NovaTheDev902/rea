package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.Laboratory.SafeHomePage;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.support.CMDHelper;
import com.lenovo.safecenter.utils.TrackEvent;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

/* JADX INFO: loaded from: classes.dex */
public class HealthSafehomepage extends BaseHealthCheck {
    public final int SCORE_VALUE_SAFE_HOMEPAGE = 4;

    public HealthSafehomepage(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 3;
        this.isRootItem = true;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.scan_safehomepage_titledetail), this.mHealthManager);
        boolean isLenovoPhone = TrafficStatsService.nacServerIsExist();
        if (isLenovoPhone) {
            ExecutorService exec = Executors.newFixedThreadPool(1);
            Callable<Boolean> call = new Callable<Boolean>() { // from class: com.lenovo.safecenter.HealthCheck.item.HealthSafehomepage.1
                @Override // java.util.concurrent.Callable
                public final /* synthetic */ Boolean call() throws Exception {
                    return Boolean.valueOf(CMDHelper.homePageOn(HealthSafehomepage.this.mContext));
                }
            };
            Future<Boolean> future = exec.submit(call);
            try {
                Boolean isOn = future.get(8000L, TimeUnit.MILLISECONDS);
                exec.shutdownNow();
                if (!isOn.booleanValue()) {
                    this.result = new HealthItemResult();
                    this.result.key = this.mKey;
                    this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
                    this.result.title_detail = this.mContext.getString(C0415R.string.scan_safehomepage_titledetail);
                    this.result.content = this.mContext.getString(C0415R.string.scan_safehomepage_detail);
                    this.result.view_type = 3;
                    this.result.weight = 5;
                    this.result.isOnly = false;
                    this.result.action_description = this.mContext.getString(C0415R.string.open);
                    this.mHealthManager.plusOrDecrementNumItem(3, true);
                    this.mPreViewType = 3;
                    this.mHealthManager.result(this.result);
                    progressAddAfterScanEveryItem(this.mHealthManager);
                    TrackEvent.reportHealthNoOpenSafeHomePage();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
                exec.shutdownNow();
            } catch (ExecutionException e2) {
                e2.printStackTrace();
                exec.shutdownNow();
            } catch (TimeoutException e3) {
                e3.printStackTrace();
                exec.shutdownNow();
                Log.i("wu0wu", "HealthSafehomepage scan TimeoutException...");
            }
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void manual() {
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void click() {
        SafeHomePage.getDefault(this.mContext).register();
        if (this.result != null) {
            this.result.content = this.mContext.getString(C0415R.string.op_safehomepage_detail);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
        TrackEvent.reportUserActionHealthManualOpenSafeHomePage();
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void clear() {
        this.result = null;
    }
}
