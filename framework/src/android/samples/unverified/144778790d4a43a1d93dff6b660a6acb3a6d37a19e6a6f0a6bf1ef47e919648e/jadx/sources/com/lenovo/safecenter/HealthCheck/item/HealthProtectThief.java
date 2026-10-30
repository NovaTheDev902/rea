package com.lenovo.safecenter.HealthCheck.item;

import android.content.Context;
import android.content.Intent;
import android.telephony.TelephonyManager;
import android.text.TextUtils;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.HealthCheck.BaseHealthCheck;
import com.lenovo.safecenter.HealthCheck.HealthItemResult;
import com.lenovo.safecenter.HealthCheck.HealthManager;
import com.lenovo.safecenter.platform.AgainstTheftSet;
import com.lenovo.safecenter.platform.MyMultiSIMUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.PwdUtil;

/* JADX INFO: loaded from: classes.dex */
public class HealthProtectThief extends BaseHealthCheck {
    public final int SCORE_VALUE_PROTECT_THIEF = 5;

    /* JADX INFO: renamed from: a */
    private boolean f2438a = false;

    /* JADX INFO: renamed from: b */
    private boolean f2439b = false;

    public boolean isShowProtectThiefActivity() {
        return this.f2439b;
    }

    public HealthProtectThief(Context context, HealthManager healthManager) {
        this.mContext = context;
        this.mKey = 5;
        this.isRootItem = false;
        this.mHealthManager = healthManager;
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void scan() {
        refreshTitle(this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item), this.mContext.getString(C0415R.string.against_theft), this.mHealthManager);
        this.result = new HealthItemResult();
        this.result.key = this.mKey;
        this.result.title = this.mContext.getString(C0415R.string.lesafe_nomal_checkup_item);
        this.result.title_detail = this.mContext.getString(C0415R.string.against_theft);
        boolean isOn = Const.getProtectThiefSwitchState();
        if (m1132a()) {
            if (isOn) {
                this.result.content = this.mContext.getString(C0415R.string.against_theft) + this.mContext.getString(C0415R.string.opend);
                this.result.view_type = 5;
                this.result.weight = 9;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
                this.mHealthManager.plusOrDecrementNumItem(5, true);
                this.mPreViewType = 5;
            } else {
                this.result.content = this.mContext.getString(C0415R.string.against_theft) + this.mContext.getString(C0415R.string.no_open);
                this.result.view_type = 2;
                this.result.weight = 3;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.open);
                this.mHealthManager.plusOrDecrementNumItem(2, true);
                this.mPreViewType = 2;
                this.mHealthManager.setScore(this.mHealthManager.getScore() - 5);
            }
        } else if (isOn) {
            this.result.content = this.mContext.getString(C0415R.string.against_theft) + this.mContext.getString(C0415R.string.opend);
            this.result.view_type = 5;
            this.result.weight = 9;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
            this.mHealthManager.plusOrDecrementNumItem(5, true);
            this.mPreViewType = 5;
        } else {
            this.result.content = this.mContext.getString(C0415R.string.against_theft) + this.mContext.getString(C0415R.string.no_open);
            this.result.view_type = 3;
            this.result.weight = 5;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.open);
            this.mHealthManager.plusOrDecrementNumItem(3, true);
            this.mPreViewType = 3;
        }
        this.mHealthManager.result(this.result);
        progressAddAfterScanEveryItem(this.mHealthManager);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void optimiza() {
        Const.setProtecThiefSwitchState(true);
        if (!this.f2438a) {
            this.mHealthManager.setScore(this.mHealthManager.getScore() + 5);
        }
        refreshTitle(null, this.mContext.getString(C0415R.string.open_theft), this.mHealthManager);
        if (this.result != null) {
            this.result.content = this.mContext.getString(C0415R.string.against_theft) + this.mContext.getString(C0415R.string.opend);
            this.result.view_type = 4;
            this.result.weight = 7;
            this.result.isOnly = false;
            this.result.action_description = this.mContext.getString(C0415R.string.safe);
        }
        this.mHealthManager.plusOrDecrementNumItem(4, true);
        this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
        this.mHealthManager.result(this.result);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    public void manual() {
        this.f2439b = false;
        if (m1132a()) {
            if (Const.getProtectThiefSwitchState()) {
                if (this.result != null) {
                    this.result.content = this.mContext.getString(C0415R.string.against_theft) + this.mContext.getString(C0415R.string.opend);
                    this.result.view_type = 4;
                    this.result.weight = 7;
                    this.result.isOnly = false;
                    this.result.action_description = this.mContext.getString(C0415R.string.safe);
                }
                this.mHealthManager.plusOrDecrementNumItem(4, true);
                this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
                this.mHealthManager.result(this.result);
                this.mHealthManager.saveHealthScoreAndCheckupTime();
                return;
            }
            if (this.result != null) {
                this.result.view_type = 4;
                this.result.weight = 7;
                this.result.isOnly = false;
                this.result.action_description = this.mContext.getString(C0415R.string.safe);
            }
            this.mHealthManager.plusOrDecrementNumItem(4, true);
            this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
            this.f2438a = true;
            this.mHealthManager.result(this.result);
        }
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void click() {
        if (PwdUtil.hasPassword(this.mContext)) {
            if (m1134c()) {
                if (m1133b()) {
                    if (this.result != null) {
                        this.result.content = this.mContext.getString(C0415R.string.against_theft) + this.mContext.getString(C0415R.string.opend);
                        this.result.view_type = 4;
                        this.result.weight = 7;
                        this.result.isOnly = false;
                        this.result.action_description = this.mContext.getString(C0415R.string.safe);
                    }
                    this.mHealthManager.plusOrDecrementNumItem(4, true);
                    this.mHealthManager.plusOrDecrementNumItem(this.mPreViewType, false);
                    this.mHealthManager.result(this.result);
                    Const.setProtecThiefSwitchState(true);
                    this.mHealthManager.saveHealthScoreAndCheckupTime();
                    return;
                }
                this.f2439b = true;
                Intent intent = new Intent(this.mContext, (Class<?>) AgainstTheftSet.class);
                intent.setFlags(268435456);
                this.mContext.startActivity(intent);
                return;
            }
            DialogUtil.NoticePositiveDialog(this.mContext, 2, this.mContext.getString(C0415R.string.info), this.mContext.getString(C0415R.string.sim_no_ready), null);
            return;
        }
        this.f2439b = true;
        DialogUtil.NoticeDialog(this.mContext, 0, this.mContext.getString(C0415R.string.info), this.mContext.getString(C0415R.string.manual_optimizition_protect_thief_dialog_content), this.mContext.getString(C0415R.string.set), null);
    }

    @Override // com.lenovo.safecenter.HealthCheck.BaseHealthCheck
    protected void clear() {
        this.result = null;
    }

    /* JADX INFO: renamed from: a */
    private boolean m1132a() {
        return PwdUtil.hasPassword(this.mContext) && m1133b() && m1134c();
    }

    /* JADX INFO: renamed from: b */
    private static boolean m1133b() {
        String safePhoneNumber = Const.getSafePhoneNumber();
        return !TextUtils.isEmpty(safePhoneNumber);
    }

    /* JADX INFO: renamed from: c */
    private boolean m1134c() {
        if (!MyMultiSIMUtils.isMultiSim(this.mContext)) {
            return ((TelephonyManager) this.mContext.getSystemService("phone")).getSimState() == 5;
        }
        int[] states = MyMultiSIMUtils.getAllSimState(this.mContext);
        int simState0 = states[0];
        int simState1 = states[1];
        boolean sim1Ready = simState0 == 5;
        boolean sim2Ready = simState1 == 5;
        return sim1Ready || sim2Ready;
    }
}
