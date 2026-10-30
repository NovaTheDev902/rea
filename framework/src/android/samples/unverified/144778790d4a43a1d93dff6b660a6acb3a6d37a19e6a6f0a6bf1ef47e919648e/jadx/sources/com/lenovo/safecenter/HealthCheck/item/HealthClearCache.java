package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.text.format.Formatter;
import android.util.Log;
import com.lenovo.performancecenter.service.object.ApplicationDataInfo;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.net.correct.TrafficCorrectSetting;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

/* JADX INFO: loaded from: classes.dex */
public class HealthClearCache extends BaseHealthCheck {

    /* JADX INFO: renamed from: a */
    private static long f2415a = 0;
    public final int SCORE_VALUE_CACHE_PROCESS = 7;

    /* JADX INFO: renamed from: b */
    private String f2416b = null;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ int m1044a(HealthClearCache x0) {
        long j = new ApplicationDataInfo(x0.mContext).getDataInfo().cachesize;
        if (j > 2147483647L) {
            return Integer.MAX_VALUE;
        }
        return (int) j;
    }

    public HealthClearCache(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 9;
        this.isRootItem = false;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.scan_cache_detail), this.mHealthManager);
        long scantimeInterval = System.currentTimeMillis() - f2415a;
        if (scantimeInterval > TrafficCorrectSetting.TIME) {
            ExecutorService exec = Executors.newFixedThreadPool(1);
            Callable<Integer> call = new Callable<Integer>() { // from class: com.lenovo.safecenter.HealthCheck.item.HealthClearCache.1
                @Override // java.util.concurrent.Callable
                public final /* synthetic */ Integer call() throws Exception {
                    return Integer.valueOf(HealthClearCache.m1044a(HealthClearCache.this));
                }
            };
            Future<Integer> future = exec.submit(call);
            try {
                int size = future.get(8000L, TimeUnit.MILLISECONDS).intValue();
                this.f2416b = Formatter.formatShortFileSize(this.mContext, size);
                exec.shutdownNow();
                if (size > 0) {
                    this.result = new HealthItemResult();
                    this.result.key = this.mKey;
                    this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
                    this.result.title_detail = this.mContext.getString(C0415R.string.scan_cache_detail);
                    this.result.content = String.format(this.mContext.getString(C0415R.string.clear_cache_scan), this.f2416b);
                    this.result.view_type = 2;
                    this.result.weight = 3;
                    this.result.isOnly = false;
                    this.result.action_description = this.mContext.getString(C0415R.string.clear_text);
                    this.mHealthManager.setScore(this.mHealthManager.getScore() - 7);
                    this.mHealthManager.plusOrDecrementNumItem(2, true);
                    this.mPreViewType = 2;
                    this.mHealthManager.result(this.result);
                    progressAddAfterScanEveryItem(this.mHealthManager);
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
                Log.i("wu0wu", "HealthClearCache scan TimeoutException...");
            }
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        ApplicationDataInfo.clearAllCache(this.mContext.getPackageManager());
        refreshTitle(null, this.mContext.getString(C0415R.string.op_cache_detail), this.mHealthManager);
        if (this.result != null) {
            this.result.content = String.format(this.mContext.getString(C0415R.string.clear_cache_done), this.f2416b);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
        this.mHealthManager.setScore(this.mHealthManager.getScore() + 7);
        f2415a = System.currentTimeMillis();
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
