package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.text.format.Formatter;
import android.util.Log;
import com.lenovo.performancecenter.coreui.util.Utils;
import com.lenovo.performancecenter.performance.ClearAllAppGarbage;
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
public class HealthRunningAppProcess extends BaseHealthCheck {
    public final int SCORE_VALUE_RUNNING_APP_PROCESS = 7;

    /* JADX INFO: renamed from: a */
    private int f2442a = 0;

    /* JADX INFO: renamed from: b */
    private String f2443b = null;

    /* JADX INFO: renamed from: c */
    private ClearAllAppGarbage f2444c = null;

    public HealthRunningAppProcess(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 8;
        this.isRootItem = false;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.scan_running_app_process_detail), this.mHealthManager);
        SharedPreferences defaultPreference = PreferenceManager.getDefaultSharedPreferences(this.mContext);
        long opRunningTaskTime = defaultPreference.getLong("OpRunningTaskTime", 0L);
        long optimeInterval = System.currentTimeMillis() - opRunningTaskTime;
        long interval = System.currentTimeMillis() - Utils.getLastKillTime(this.mContext);
        if (optimeInterval > TrafficCorrectSetting.TIME && interval > Utils.CLICK_INTERVAL) {
            ExecutorService exec = Executors.newFixedThreadPool(1);
            Callable<Object> call = new Callable<Object>() { // from class: com.lenovo.safecenter.HealthCheck.item.HealthRunningAppProcess.1
                @Override // java.util.concurrent.Callable
                public final Object call() throws Exception {
                    HealthRunningAppProcess.this.f2444c = new ClearAllAppGarbage(HealthRunningAppProcess.this.mContext);
                    return HealthRunningAppProcess.this.f2444c.getAllRunningAppInfo(null);
                }
            };
            Future<Object> future = exec.submit(call);
            try {
                int[] appGarbage = (int[]) future.get(8000L, TimeUnit.MILLISECONDS);
                exec.shutdownNow();
                this.f2442a = appGarbage[0];
                this.f2443b = Formatter.formatFileSize(this.mContext, appGarbage[1]);
                if (this.f2442a != 0) {
                    refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.scan_running_app_process_detail), this.mHealthManager);
                    this.result = new HealthItemResult();
                    this.result.key = this.mKey;
                    this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
                    this.result.title_detail = this.mContext.getString(C0415R.string.scan_running_app_process_detail);
                    this.result.content = String.format(this.mContext.getString(C0415R.string.detail_running_app_process), Integer.valueOf(this.f2442a), this.f2443b);
                    this.result.view_type = 2;
                    this.result.weight = 3;
                    this.result.isOnly = false;
                    this.result.action_description = this.mContext.getString(C0415R.string.optimizition);
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
                Log.i("wu0wu", "HealthRunningAppProcess scan TimeoutException...");
            }
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        this.f2444c.clearAllApp(null);
        refreshTitle(null, this.mContext.getString(C0415R.string.op_running_app_process_detail), this.mHealthManager);
        if (this.result != null) {
            this.result.content = String.format(this.mContext.getString(C0415R.string.killed_running_app_process), Integer.valueOf(this.f2442a), this.f2443b);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
        this.mHealthManager.setScore(this.mHealthManager.getScore() + 7);
        SharedPreferences defaultPreference = PreferenceManager.getDefaultSharedPreferences(this.mContext);
        defaultPreference.edit().putLong("OpRunningTaskTime", System.currentTimeMillis()).commit();
        Utils.recordKillTimeAndPosition(this.mContext, System.currentTimeMillis(), 4);
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
