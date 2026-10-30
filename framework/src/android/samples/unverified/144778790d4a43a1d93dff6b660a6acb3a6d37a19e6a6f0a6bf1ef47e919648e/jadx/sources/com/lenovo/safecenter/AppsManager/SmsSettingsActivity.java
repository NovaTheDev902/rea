package com.lenovo.safecenter.AppsManager;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.SmsUtil;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class SmsSettingsActivity extends Activity implements View.OnClickListener, DialogUtil.SettingNumberDialogListener {
    public static final int DIALOG_SET_MONTH_LIMIT_SMS = 2;
    public static final int DIALOG_SET_TRAFFIC_SMS_QUERY = 3;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.sms_settings);
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.sms_setting_text);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(this);
        findViewById(C0415R.id.monthLimitSMSLayout).setOnClickListener(this);
        m1001b();
    }

    /* JADX INFO: renamed from: a */
    private void m1000a() {
        TextView text = (TextView) findViewById(C0415R.id.txt_monthWarmSMSSwitch);
        ImageView ImgMonthWarm = (ImageView) findViewById(C0415R.id.monthWarmSMSSwitch);
        ImgMonthWarm.setOnClickListener(this);
        if (Const.getMonthLimitSMS() == 0) {
            text.setTextColor(getResources().getColor(C0415R.color.gray2));
            ImgMonthWarm.setEnabled(false);
            Const.setOutMonthLimitSMSWarn(false);
            ImgMonthWarm.setImageResource(C0415R.drawable.btn_off);
            return;
        }
        text.setTextColor(getResources().getColor(C0415R.color.black1));
        ImgMonthWarm.setEnabled(true);
        if (Const.isOutMonthLimitSMSWarn()) {
            ImgMonthWarm.setImageResource(C0415R.drawable.btn_on);
        } else {
            ImgMonthWarm.setImageResource(C0415R.drawable.btn_off);
        }
    }

    /* JADX INFO: renamed from: b */
    private void m1001b() {
        TextView monthLimitSMS = (TextView) findViewById(C0415R.id.monthLimitSMS);
        if (Const.getMonthLimitSMS() == 0) {
            monthLimitSMS.setText(getString(C0415R.string.no_sms_package));
        } else {
            monthLimitSMS.setText(String.valueOf(Const.getMonthLimitSMS()) + getString(C0415R.string.article));
        }
        m1000a();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.monthLimitSMSLayout /* 2131297659 */:
                DialogUtil.createSettingNumberDialog(this, 2, this);
                break;
            case C0415R.id.monthWarmSMSSwitch /* 2131297663 */:
                Const.setOutMonthLimitSMSWarn(!Const.isOutMonthLimitSMSWarn());
                m1000a();
                SmsUtil.statisticsSmsSent(this);
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.SettingNumberDialogListener
    public void onSettingNumberDialogOK(int id, int number) {
        switch (id) {
            case 2:
                Const.setMonthLimitSMS(number);
                m1001b();
                SmsUtil.statisticsSmsSent(this);
                LeSafeObservable.get(this).noticeRefreshSmsSentNumCurrMonth();
                break;
        }
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.SettingNumberDialogListener
    public void onSettingNumberDialogCancel(int id, int number) {
    }
}
