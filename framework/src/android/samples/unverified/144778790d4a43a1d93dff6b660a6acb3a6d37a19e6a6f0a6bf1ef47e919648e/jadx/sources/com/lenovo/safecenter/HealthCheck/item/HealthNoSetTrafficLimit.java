package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.net.doublemode.DoubleCardUtil;
import com.lenovo.safecenter.net.support.PhoneSimInfo;
import com.lenovo.safecenter.net.support.TrafficStatsService;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.WflUtils;

/* JADX INFO: loaded from: classes.dex */
public class HealthNoSetTrafficLimit extends BaseHealthCheck implements DoubleCardUtil.SettingNumberDialogListener2 {
    public HealthNoSetTrafficLimit(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 6;
        this.isRootItem = false;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.scan_nosetTrafficLimit_detail), this.mHealthManager);
        PhoneSimInfo simInfo = TrafficStatsService.getImsiInfo(this.mContext);
        if (!TextUtils.isEmpty(simInfo.sim1IMSI) || !TextUtils.isEmpty(simInfo.sim2IMSI)) {
            boolean isNoSet = false;
            if (MyMultiSIMUtils.isMultiSim(this.mContext)) {
                if ("-1".equals(Const.getMonthLimitTraffic()) && "-1".equals(Const.getMonthLimitTraffic2())) {
                    isNoSet = true;
                }
            } else if ("-1".equals(Const.getMonthLimitTraffic())) {
                isNoSet = true;
            }
            if (isNoSet) {
                this.result = new HealthItemResult();
                this.result.key = this.mKey;
                this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
                this.result.title_detail = this.mContext.getString(C0415R.string.scan_nosetTrafficLimit_detail);
                this.result.content = this.mContext.getString(C0415R.string.scan_nosetTrafficLimit_detail);
                this.result.view_type = 3;
                this.result.weight = 5;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.set);
                this.mHealthManager.plusOrDecrementNumItem(3, true);
                this.mPreViewType = 3;
                this.mHealthManager.result(this.result);
                progressAddAfterScanEveryItem(this.mHealthManager);
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
        DoubleCardUtil.createSettingNumberDialog(this.mContext, this, 6);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void clear() {
        this.result = null;
    }

    /* JADX INFO: renamed from: a */
    private void m1131a() {
        if (this.result != null) {
            this.result.content = this.mContext.getString(C0415R.string.op_nosetTrafficLimit_detail);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
        this.mHealthManager.saveHealthScoreAndCheckupTime();
        new Thread(new Runnable() { // from class: com.lenovo.safecenter.HealthCheck.item.HealthNoSetTrafficLimit.1
            @Override // java.lang.Runnable
            public final void run() {
                TrafficStatsService.statsTrafficMobile(HealthNoSetTrafficLimit.this.mContext);
            }
        }).start();
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogOK(int[] number, int flag) {
        boolean zIsMultiSim = MyMultiSIMUtils.isMultiSim(this.mContext);
        if (Const.SDK_VERSION < 14) {
            if (number[0] != -1) {
                Const.setMonthLimitTraffic(String.valueOf(number[0]));
                m1131a();
                return;
            }
            return;
        }
        if (!zIsMultiSim) {
            if (TextUtils.isEmpty(WflUtils.getActiveSubscriberId(this.mContext))) {
                Toast.makeText(this.mContext, this.mContext.getString(C0415R.string.net_simcard_error2), 1).show();
                return;
            } else {
                if (number[0] != -1) {
                    Const.setMonthLimitTraffic(String.valueOf(number[0]));
                    m1131a();
                    return;
                }
                return;
            }
        }
        PhoneSimInfo imsiInfo = TrafficStatsService.getImsiInfo(this.mContext);
        Log.i("wu0wu", "sim1IMSI=" + imsiInfo.sim1IMSI);
        if (!TextUtils.isEmpty(imsiInfo.sim1IMSI) && number[0] != -1) {
            Const.setMonthLimitTraffic(String.valueOf(number[0]));
            m1131a();
        }
        if (TextUtils.isEmpty(imsiInfo.sim2IMSI) || number[1] == -1) {
            return;
        }
        Const.setMonthLimitTraffic2(String.valueOf(number[1]));
        m1131a();
    }

    @Override // com.lenovo.safecenter.net.doublemode.DoubleCardUtil.SettingNumberDialogListener2
    public void onSettingNumberDialogCancel(int[] number, int flag) {
    }
}
