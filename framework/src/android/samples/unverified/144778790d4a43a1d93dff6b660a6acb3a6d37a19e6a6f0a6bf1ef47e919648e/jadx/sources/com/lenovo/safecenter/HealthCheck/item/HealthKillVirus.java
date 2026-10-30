package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.antivirus.domain.Appinfo;
import com.lenovo.safecenter.antivirus.domain.VirusDemo;
import com.lenovo.safecenter.antivirus.utils.AppUtils;
import com.lenovo.safecenter.antivirus.utils.HttpUtils;
import com.lenovo.safecenter.antivirus.utils.ScanUtils;
import com.lenovo.safecenter.antivirus.views.ScanVirusActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.WflUtils;
import com.tencent.tmsecure.common.ManagerCreator;
import com.tencent.tmsecure.module.qscanner.QScanListener;
import com.tencent.tmsecure.module.qscanner.QScanResultEntity;
import com.tencent.tmsecure.module.qscanner.QScannerManager;
import java.util.ArrayList;
import java.util.List;
import java.util.Observable;
import java.util.Observer;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

/* JADX INFO: loaded from: classes.dex */
public class HealthKillVirus extends BaseHealthCheck implements DialogUtil.WarnDialogListener, Observer {

    /* JADX INFO: renamed from: a */
    private QScannerManager f2418a;

    /* JADX INFO: renamed from: h */
    private LeSafeObservable f2425h;
    public final int SCORE_VALUE_HAS_VIRUS = 40;

    /* JADX INFO: renamed from: b */
    private int f2419b = 0;

    /* JADX INFO: renamed from: c */
    private int f2420c = 0;

    /* JADX INFO: renamed from: d */
    private final int f2421d = 0;

    /* JADX INFO: renamed from: e */
    private int f2422e = -1;

    /* JADX INFO: renamed from: f */
    private boolean f2423f = false;

    /* JADX INFO: renamed from: g */
    private Handler f2424g = new Handler() { // from class: com.lenovo.safecenter.HealthCheck.item.HealthKillVirus.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    DialogUtil.NoticePositiveDialog(HealthKillVirus.this.mContext, 1, HealthKillVirus.this.mContext.getString(C0415R.string.info), HealthKillVirus.this.mContext.getString(C0415R.string.kill_virus_dialog_content), HealthKillVirus.this);
                    break;
            }
        }
    };

    public boolean isShowkillVirusActivity() {
        return this.f2423f;
    }

    public HealthKillVirus(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 21;
        this.f2418a = (QScannerManager) ManagerCreator.getManager(QScannerManager.class);
        this.isRootItem = false;
        this.f2425h = LeSafeObservable.get(this.mContext);
        this.f2425h.addObserver(this);
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        boolean isCloudKill = false;
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), null, this.mHealthManager);
        this.result = new HealthItemResult();
        this.result.key = this.mKey;
        this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
        if (isClounKillVirus(this.mContext)) {
            this.mHealthManager.setScanProgress(this.mHealthManager.getMAX_PROGRESS());
            this.mHealthManager.setProgressBarIndeterminate(true);
            refreshTitle(null, this.mContext.getString(C0415R.string.net_virus_scaning), this.mHealthManager);
            this.result.title_detail = this.mContext.getString(C0415R.string.net_virus_scaning);
            ExecutorService exec = Executors.newFixedThreadPool(1);
            Callable<Boolean> call = new Callable<Boolean>() { // from class: com.lenovo.safecenter.HealthCheck.item.HealthKillVirus.2
                @Override // java.util.concurrent.Callable
                public final /* synthetic */ Boolean call() throws Exception {
                    List<Appinfo> appSInfo = AppUtils.getAppSInfo(HealthKillVirus.this.mContext);
                    List<VirusDemo> listCloudScanGlobal = new ScanUtils().cloudScanGlobal(appSInfo, HealthKillVirus.this.mContext);
                    AppUtils.execNetResult(listCloudScanGlobal, HealthKillVirus.this.mContext);
                    if (appSInfo != null) {
                        appSInfo.clear();
                    }
                    if (listCloudScanGlobal != null) {
                        listCloudScanGlobal.clear();
                    }
                    return true;
                }
            };
            Future<Boolean> future = exec.submit(call);
            try {
                future.get(60000L, TimeUnit.MILLISECONDS);
                exec.shutdownNow();
                isCloudKill = true;
            } catch (InterruptedException e) {
                e.printStackTrace();
                exec.shutdownNow();
                return;
            } catch (ExecutionException e2) {
                e2.printStackTrace();
                exec.shutdownNow();
                return;
            } catch (TimeoutException e3) {
                e3.printStackTrace();
                exec.shutdownNow();
                Log.i("wu0wu", "ClounKillVirus TimeoutException...");
                return;
            }
        } else {
            this.f2418a.scanInstalledPackages(new QScanListener() { // from class: com.lenovo.safecenter.HealthCheck.item.HealthKillVirus.3
                @Override // com.tencent.tmsecure.module.qscanner.QScanListener
                public final void onScanStarted() {
                    WflUtils.Log("d", "wu0wu", "onScanStarted...");
                }

                @Override // com.tencent.tmsecure.module.qscanner.QScanListener
                public final void onPackageScanProgress(int progress, QScanResultEntity qScanResult) {
                    if (HealthKillVirus.this.f2422e != progress) {
                        HealthKillVirus.this.mHealthManager.setScanProgress(HealthKillVirus.this.mHealthManager.getScanProgress() + 1);
                        HealthItemResult scanOneItemProcess = new HealthItemResult();
                        scanOneItemProcess.key = HealthKillVirus.this.mKey;
                        scanOneItemProcess.title = HealthKillVirus.this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
                        scanOneItemProcess.title_detail = HealthKillVirus.this.mContext.getString(C0415R.string.scan_virus) + qScanResult.softName;
                        HealthKillVirus.this.mHealthManager.onOneItemProcess(scanOneItemProcess);
                        WflUtils.Log("d", "wu0wu", "progress=" + progress);
                        HealthKillVirus.this.f2422e = progress;
                        if (progress == 100) {
                            AppUtils.isNeedScan(HealthKillVirus.this.mContext);
                        }
                    }
                    AppUtils.execLocalResult(qScanResult, HealthKillVirus.this.mContext);
                }

                @Override // com.tencent.tmsecure.module.qscanner.QScanListener
                public final void onScanFinished(ArrayList<QScanResultEntity> arg0) {
                    WflUtils.Log("d", "wu0wu", "onScanFinished...");
                    HealthKillVirus.this.mHealthManager.setScanProgress(HealthKillVirus.this.mHealthManager.getMAX_PROGRESS());
                }
            }, false);
        }
        this.f2419b = m1045a();
        WflUtils.Log("d", "wu0wu", "mVirusNum=" + this.f2419b);
        if (this.f2419b == 0) {
            if (isCloudKill) {
                this.result.content = this.mContext.getString(C0415R.string.netscaning_sure) + this.mContext.getString(C0415R.string.detail_no_virus);
                this.result.view_type = 5;
                this.result.weight = 9;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
                this.mHealthManager.plusOrDecrementNumItem(5, true);
            } else {
                this.result.content = this.mContext.getString(C0415R.string.local_killvirus_text) + this.mContext.getString(C0415R.string.detail_no_virus);
                this.result.view_type = 5;
                this.result.weight = 9;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
                this.mHealthManager.plusOrDecrementNumItem(5, true);
            }
        } else {
            this.result.content = String.format(this.mContext.getString(C0415R.string.detail_num_virus), Integer.valueOf(this.f2419b));
            this.result.view_type = 1;
            this.result.weight = 1;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.uninstall);
            this.mHealthManager.setScore(this.mHealthManager.getScore() - (this.f2419b * 40));
            this.mHealthManager.plusOrDecrementNumItem(1, true);
            this.mPreViewType = 1;
        }
        this.mHealthManager.result(this.result);
        HttpUtils.UpdateConfig("scantime", String.valueOf(System.currentTimeMillis()), this.mContext);
        WflUtils.Log("d", "wu0wu", "scankillvirus end...");
    }

    public static boolean isClounKillVirus(Context context) {
        return WflUtils.isNetworkAvailable(context) && !WflUtils.isMobile2GNetwork(context);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        this.f2424g.sendMessage(this.f2424g.obtainMessage(0, null));
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void manual() {
        int newVirusNum = m1045a();
        int killNum = this.f2420c - newVirusNum;
        this.f2420c = newVirusNum;
        Log.i("wu0wu", "killNum=" + killNum);
        if (newVirusNum > 0) {
            this.mHealthManager.setStatus(1);
            if (this.result != null) {
                this.result.content = String.format(this.mContext.getString(C0415R.string.detail_num_virus), Integer.valueOf(newVirusNum));
                this.result.view_type = 1;
                this.result.weight = 1;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.uninstall);
            }
        } else {
            if (this.result != null) {
                this.result.content = String.format(this.mContext.getString(C0415R.string.detail_killed_virus_num), Integer.valueOf(this.f2419b));
                this.result.view_type = 4;
                this.result.weight = 7;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
            }
            this.mHealthManager.plusOrDecrementNumItem(4, true);
            this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
            this.mHealthManager.setStatus(3);
        }
        this.mHealthManager.result(this.result);
        this.mHealthManager.setScore(this.mHealthManager.getScore() + (killNum * 40));
        if (killNum > 0) {
            Const.isHealthCheckNoOptimiza(false);
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void click() {
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void clear() {
        this.result = null;
        if (this.f2418a != null) {
            this.f2418a.freeScanner();
        }
        if (this.f2425h != null) {
            this.f2425h.deleteObservers();
            this.f2425h.close();
        }
    }

    public void cancelScan() {
        if (this.f2418a != null) {
            this.f2418a.cancelScan();
        }
    }

    public void onWarnDialogOk() {
        int newVirusNum = m1045a();
        if (newVirusNum == 0) {
            int killNum = this.f2419b - newVirusNum;
            if (this.result != null) {
                this.result.content = String.format(this.mContext.getString(C0415R.string.detail_killed_virus_num), Integer.valueOf(this.f2419b));
                this.result.view_type = 4;
                this.result.weight = 7;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
                this.mHealthManager.plusOrDecrementNumItem(4, true);
                this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
            }
            this.mHealthManager.setStatus(3);
            this.mHealthManager.result(this.result);
            this.mHealthManager.setScore(this.mHealthManager.getScore() + (killNum * 40));
            if (killNum > 0) {
                Const.isHealthCheckNoOptimiza(false);
            }
        } else {
            Intent intent = new Intent(this.mContext, (Class<?>) ScanVirusActivity.class);
            intent.putExtra("from_healthcheck", true);
            this.mContext.startActivity(intent);
            this.f2423f = true;
        }
        this.f2420c = newVirusNum;
    }

    /* JADX INFO: renamed from: a */
    private int m1045a() {
        String virusPkgNames = HttpUtils.execService("viruspkgname", this.mContext);
        if (TextUtils.isEmpty(virusPkgNames)) {
            return 0;
        }
        int count = virusPkgNames.split(",").length;
        return count;
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.WarnDialogListener
    public void onWarnDialogOk(int id) {
        switch (id) {
            case 1:
                onWarnDialogOk();
                break;
        }
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.WarnDialogListener
    public void onWarnDialogCancel(int id) {
    }

    @Override // java.util.Observer
    public void update(Observable observable, Object data) {
        if (data instanceof Integer) {
            switch (((Integer) data).intValue()) {
                case 19:
                    manual();
                    break;
            }
        }
    }
}
