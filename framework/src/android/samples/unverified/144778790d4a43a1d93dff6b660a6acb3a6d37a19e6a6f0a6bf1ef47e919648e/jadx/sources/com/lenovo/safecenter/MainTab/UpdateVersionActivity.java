package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.lps.sus.p008c.C0092c;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.lenovoAntiSpam.utils.HttpUtils;
import com.lenovo.safecenter.utils.AlarmManageUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.DialogUtil;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.WflUtils;
import com.lenovo.safecenter.utils.update.LeSafeUpdate;
import com.lenovo.safecenter.utils.update.LeSafeUpdateInfo;
import com.lenovo.safecenter.utils.updateLab.AutoUpdateLabManager;
import com.lenovo.safecenter.utils.updateLab.UpdateLabManager;
import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Observable;
import java.util.Observer;

/* JADX INFO: loaded from: classes.dex */
public class UpdateVersionActivity extends Activity implements View.OnClickListener, DialogUtil.SettingNumberDialogListener, DialogUtil.WarnDialogListener, Observer {
    public static final int DIALOG_MANUAL_ALL_NEW = 3;
    public static final int DIALOG_MANUAL_MOBILE_UPDATE = 2;
    public static final int DIALOG_MANUAL_NO_NET = 4;

    /* JADX INFO: renamed from: h */
    private static Context f2827h;

    /* JADX INFO: renamed from: a */
    private TextView f2828a;

    /* JADX INFO: renamed from: b */
    private TextView f2829b;

    /* JADX INFO: renamed from: c */
    private TextView f2830c;

    /* JADX INFO: renamed from: d */
    private TextView f2831d;

    /* JADX INFO: renamed from: e */
    private PackageManager f2832e;

    /* JADX INFO: renamed from: f */
    private String f2833f;

    /* JADX INFO: renamed from: g */
    private PackageInfo f2834g;

    /* JADX INFO: renamed from: i */
    private LeSafeUpdate f2835i;

    /* JADX INFO: renamed from: j */
    private Handler f2836j = new Handler() { // from class: com.lenovo.safecenter.MainTab.UpdateVersionActivity.4
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    Toast.makeText(UpdateVersionActivity.f2827h, C0415R.string.install_succeeded, 1).show();
                    break;
                case 2:
                    Intent intent = new Intent("android.intent.action.VIEW");
                    intent.setDataAndType(Uri.parse("file://" + ((String) msg.obj)), "application/vnd.android.package-archive");
                    intent.setFlags(268435456);
                    UpdateVersionActivity.f2827h.startActivity(intent);
                    break;
            }
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.activity_update_version_layout);
        f2827h = this;
        this.f2832e = getPackageManager();
        ((TextView) findViewById(C0415R.id.txt_title)).setText(C0415R.string.update_and_pwd);
        ((ImageView) findViewById(C0415R.id.title_back)).setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.UpdateVersionActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                UpdateVersionActivity.this.finish();
            }
        });
        LeSafeObservable.get(getApplicationContext()).addObserver(this);
        this.f2828a = (TextView) findViewById(C0415R.id.detail_auto_update);
        this.f2831d = (TextView) findViewById(C0415R.id.button_manual_update_lab);
        this.f2829b = (TextView) findViewById(C0415R.id.detail_update_version_rate);
        this.f2829b.setText(getString(C0415R.string.detail_update_version_rate) + m1274c());
        this.f2830c = (TextView) findViewById(C0415R.id.button_update_version);
        findViewById(C0415R.id.auto_update_layout).setOnClickListener(this);
        this.f2830c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.UpdateVersionActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (WflUtils.isNetworkAvailable(UpdateVersionActivity.this)) {
                    UpdateVersionActivity.this.m1281a();
                    Log.i("sus", "Update no Started");
                } else {
                    UpdateVersionActivity.this.showDialog(4);
                }
            }
        });
        this.f2831d.setOnClickListener(this);
        m1275d();
        m1276e();
        m1278g();
    }

    /* JADX INFO: renamed from: c */
    private String m1274c() {
        try {
            this.f2834g = this.f2832e.getPackageInfo(getPackageName(), C0092c.f1300aD);
            this.f2833f = this.f2834g.versionName;
            return this.f2833f;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
            return getString(C0415R.string.get_error);
        }
    }

    /* JADX INFO: renamed from: d */
    private void m1275d() {
        boolean istrue = AutoUpdateLabManager.isAutoUpdate(this);
        if (istrue) {
            this.f2828a.setText(AutoUpdateLabManager.getSelectedUpdateModeString(this));
        } else {
            this.f2828a.setText(C0415R.string.detail_auto_update_off_note);
        }
    }

    /* JADX INFO: renamed from: e */
    private void m1276e() {
        String virusLabVersion;
        TextView updateTimeVirusLabTv = (TextView) findViewById(C0415R.id.updateTime_virus_lab);
        TextView updateTimeBlacklistLabTv = (TextView) findViewById(C0415R.id.updateTime_blacklist);
        TextView updateTimeSignCallLabTv = (TextView) findViewById(C0415R.id.updateTime_signCall);
        String virustime = String.valueOf(new File(getFilesDir() + "/qv_base.amf").lastModified());
        if (TextUtils.isEmpty(virustime) || "0".equals(virustime)) {
            virusLabVersion = "2012.11.13";
        } else {
            virusLabVersion = WflUtils.convertLongTime2DateFormat(Long.valueOf(virustime), new SimpleDateFormat("yyyy.MM.dd"));
        }
        Log.i("wu0wu", "virusLabVersion=" + virusLabVersion);
        if (!TextUtils.isEmpty(virusLabVersion)) {
            updateTimeVirusLabTv.setTextColor(getResources().getColor(C0415R.color.gray2));
            updateTimeVirusLabTv.setText(virusLabVersion);
        } else {
            updateTimeVirusLabTv.setTextColor(getResources().getColor(C0415R.color.gray2));
            updateTimeVirusLabTv.setText(getString(C0415R.string.never_updated_text));
        }
        String blackLabTime = HttpUtils.execService("lastintag", this);
        if (!TextUtils.isEmpty(blackLabTime)) {
            String blacklistLabVersion = HttpUtils.getDate(blackLabTime);
            updateTimeBlacklistLabTv.setTextColor(getResources().getColor(C0415R.color.gray2));
            updateTimeBlacklistLabTv.setText(blacklistLabVersion);
        } else {
            updateTimeBlacklistLabTv.setTextColor(getResources().getColor(C0415R.color.gray2));
            updateTimeBlacklistLabTv.setText(getString(C0415R.string.never_updated_text));
        }
        String signCallLabTime = HttpUtils.execService("sign_lastin", this);
        if (!TextUtils.isEmpty(signCallLabTime)) {
            String signCallLabVersion = HttpUtils.getDate(signCallLabTime);
            updateTimeSignCallLabTv.setTextColor(getResources().getColor(C0415R.color.gray2));
            updateTimeSignCallLabTv.setText(signCallLabVersion);
        } else {
            updateTimeSignCallLabTv.setTextColor(getResources().getColor(C0415R.color.gray2));
            updateTimeSignCallLabTv.setText("2012.07.01");
        }
        m1277f();
    }

    /* JADX INFO: renamed from: f */
    private void m1277f() {
        TextView updateTimeVirusLabTv = (TextView) findViewById(C0415R.id.updateTime_virus_lab);
        TextView updateTimeBlacklistLabTv = (TextView) findViewById(C0415R.id.updateTime_blacklist);
        TextView updateTimeSignCallLabTv = (TextView) findViewById(C0415R.id.updateTime_signCall);
        if (!UpdateLabManager.getIs_UpdateLabing(0) && UpdateLabManager.getQueryLabStatus(0) == 0) {
            updateTimeVirusLabTv.setTextColor(getResources().getColor(C0415R.color.blue_btn));
            updateTimeVirusLabTv.setText(getString(C0415R.string.has_new_update_note_text));
        }
        if (!UpdateLabManager.getIs_UpdateLabing(1) && UpdateLabManager.getQueryLabStatus(1) == 0) {
            updateTimeBlacklistLabTv.setTextColor(getResources().getColor(C0415R.color.blue_btn));
            updateTimeBlacklistLabTv.setText(getString(C0415R.string.has_new_update_note_text));
        }
        if (!UpdateLabManager.getIs_UpdateLabing(3) && UpdateLabManager.getQueryLabStatus(3) == 0) {
            updateTimeSignCallLabTv.setTextColor(getResources().getColor(C0415R.color.blue_btn));
            updateTimeSignCallLabTv.setText(getString(C0415R.string.has_new_update_note_text));
        }
    }

    /* JADX INFO: renamed from: g */
    private void m1278g() {
        if (UpdateLabManager.isUpdateingLab()) {
            this.f2831d.setClickable(false);
            this.f2831d.setTextColor(getResources().getColor(C0415R.color.gray2));
            m1280i();
        } else {
            this.f2831d.setClickable(true);
            this.f2831d.setTextColor(getResources().getColor(C0415R.color.blue_btn));
            m1279h();
        }
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.auto_update_layout /* 2131296356 */:
                removeDialog(1);
                showDialog(1);
                break;
            case C0415R.id.button_manual_update_lab /* 2131296372 */:
                if (UpdateLabManager.isAllNewVersionLab()) {
                    showDialog(3);
                } else if (!UpdateLabManager.isQueryedLab()) {
                    Toast.makeText(f2827h, f2827h.getString(C0415R.string.updateing_lab_wording_isquerying), 1).show();
                } else if (WflUtils.isWifiNetwork(this)) {
                    UpdateLabManager.isManualUpdateLab = true;
                    UpdateLabManager.startServiceUpdateLab(this);
                } else if (WflUtils.isMobileNetwork(this)) {
                    showDialog(2);
                } else if (!WflUtils.isNetworkAvailable(this)) {
                    showDialog(4);
                }
                break;
        }
    }

    @Override // android.app.Activity, android.view.KeyEvent.Callback
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (4 != keyCode) {
            return super.onKeyDown(keyCode, event);
        }
        if (!isFinishing()) {
            finish();
        }
        return true;
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        Log.e("ydp", "update onDestroy");
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected Dialog onCreateDialog(int id) {
        switch (id) {
            case 1:
                return DialogUtil.createAutoUpdateRatechoice(this, id, this);
            case 2:
            case 3:
            case 4:
                return DialogUtil.createManualUpdateDialog(this, id, this);
            default:
                return super.onCreateDialog(id);
        }
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.SettingNumberDialogListener
    public void onSettingNumberDialogOK(int id, int choiceMode) {
        Log.i("wu0wu", "auto update choiceMode=" + choiceMode);
        AutoUpdateLabManager.setAutoUpdateMode(choiceMode, this);
        if (choiceMode == 3) {
            AutoUpdateLabManager.setIsAutoUpdate(false, this);
            AlarmManageUtils.cancelNoticeUpdateLab(this);
        } else {
            AutoUpdateLabManager.setIsAutoUpdate(true, this);
        }
        if (choiceMode == 1 || choiceMode == 2) {
            AlarmManageUtils.cancelNoticeUpdateLab(this);
            AlarmManageUtils.noticeUpdateLab(this);
        }
        m1275d();
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.SettingNumberDialogListener
    public void onSettingNumberDialogCancel(int id, int choiceMode) {
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.WarnDialogListener
    public void onWarnDialogOk(int id) {
        switch (id) {
            case 2:
                UpdateLabManager.isManualUpdateLab = true;
                UpdateLabManager.startServiceUpdateLab(this);
                break;
        }
    }

    @Override // com.lenovo.safecenter.utils.DialogUtil.WarnDialogListener
    public void onWarnDialogCancel(int id) {
    }

    @Override // java.util.Observer
    public void update(Observable observable, Object data) {
        if (data instanceof Integer) {
            if (((Integer) data).intValue() == 0) {
                Log.i("wu0wu", "UpdateAndPasswordActivity LeSafeObservable.OBSERVER_UPDATED_LAB");
                m1278g();
                m1276e();
                m1279h();
                UpdateLabManager.isManualUpdateLab = false;
            }
            if (1 == ((Integer) data).intValue()) {
                m1277f();
            }
            if (11 == ((Integer) data).intValue()) {
                m1278g();
                m1280i();
            }
        }
    }

    /* JADX INFO: renamed from: h */
    private void m1279h() {
        if (!UpdateLabManager.isUpdateingLab()) {
            LinearLayout note_isUpdating_lab_layout = (LinearLayout) findViewById(C0415R.id.note_isUpdating_lab_layout);
            RelativeLayout blacklist_lab_layout = (RelativeLayout) findViewById(C0415R.id.blacklist_lab_layout);
            RelativeLayout virus_lab_layout = (RelativeLayout) findViewById(C0415R.id.virus_lab_layout);
            RelativeLayout signCall_lab_layout = (RelativeLayout) findViewById(C0415R.id.signCall_lab_layout);
            note_isUpdating_lab_layout.setVisibility(8);
            blacklist_lab_layout.setVisibility(0);
            virus_lab_layout.setVisibility(0);
            signCall_lab_layout.setVisibility(0);
        }
    }

    /* JADX INFO: renamed from: i */
    private void m1280i() {
        LinearLayout note_isUpdating_lab_layout = (LinearLayout) findViewById(C0415R.id.note_isUpdating_lab_layout);
        RelativeLayout blacklist_lab_layout = (RelativeLayout) findViewById(C0415R.id.blacklist_lab_layout);
        RelativeLayout virus_lab_layout = (RelativeLayout) findViewById(C0415R.id.virus_lab_layout);
        RelativeLayout signCall_lab_layout = (RelativeLayout) findViewById(C0415R.id.signCall_lab_layout);
        note_isUpdating_lab_layout.setVisibility(0);
        blacklist_lab_layout.setVisibility(8);
        virus_lab_layout.setVisibility(8);
        signCall_lab_layout.setVisibility(8);
    }

    /* JADX INFO: renamed from: a */
    final void m1281a() {
        if (this.f2835i == null) {
            int versionCode = 0;
            try {
                PackageInfo packageinfo = getPackageManager().getPackageInfo(getPackageName(), 0);
                versionCode = packageinfo.versionCode;
            } catch (PackageManager.NameNotFoundException e) {
                e.printStackTrace();
            }
            this.f2835i = new LeSafeUpdate(f2827h, getPackageName(), versionCode, Const.SUS_CHANNEL, false, false, false, new LeSafeUpdate.LeSafeUpdateListenser() { // from class: com.lenovo.safecenter.MainTab.UpdateVersionActivity.3
                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onQueryResp(String resultion, LeSafeUpdateInfo lfui) {
                }

                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onInstallComplete(boolean succeed) {
                }

                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onDownLoadException(int errorCode) {
                }

                @Override // com.lenovo.safecenter.utils.update.LeSafeUpdate.LeSafeUpdateListenser
                public final void onDownLoadComplete(String path) {
                }
            });
        }
        this.f2835i.upDate(false);
    }

    public boolean canExecute(String path) {
        File file = new File(path);
        for (int i = 0; i < 3; i++) {
            if (file.canExecute()) {
                Log.i("ydp", "canExecute()...true");
                return true;
            }
            Log.i("ydp", "canExecute()...false");
            try {
                Thread.sleep(1500L);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return false;
    }
}
