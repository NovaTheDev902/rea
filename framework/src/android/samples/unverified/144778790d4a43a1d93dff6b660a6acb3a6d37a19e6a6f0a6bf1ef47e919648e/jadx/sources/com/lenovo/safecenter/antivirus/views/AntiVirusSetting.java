package com.lenovo.safecenter.antivirus.views;

import android.content.DialogInterface;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.provider.Settings;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.dialog.CustomDialog;
import com.lenovo.safecenter.platform.BaseTitleActivity;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.LeSafeObservable;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class AntiVirusSetting extends BaseTitleActivity {

    /* JADX INFO: renamed from: a */
    private ImageView f3097a;

    /* JADX INFO: renamed from: b */
    private ImageView f3098b;

    /* JADX INFO: renamed from: c */
    private ImageView f3099c;

    /* JADX INFO: renamed from: d */
    private TextView f3100d;

    /* JADX INFO: renamed from: e */
    private TextView f3101e;

    /* JADX INFO: renamed from: f */
    private TextView f3102f;

    /* JADX INFO: renamed from: g */
    private TextView f3103g;

    /* JADX INFO: renamed from: a */
    static /* synthetic */ void m1332a(AntiVirusSetting x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.info).setMessage(C0415R.string.closeantivirus_info).setColorPositiveButton(false).setColorNegativeButton(true).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.AntiVirusSetting.2
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                Const.setProtectVirusSwitchState(false, AntiVirusSetting.this);
                LeSafeObservable.get(AntiVirusSetting.this).noticeRefreshProtectVirusDetail();
                AntiVirusSetting.this.init();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.AntiVirusSetting.1
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    /* JADX INFO: renamed from: b */
    static /* synthetic */ void m1333b(AntiVirusSetting x0) {
        new CustomDialog.Builder(x0).setTitle(C0415R.string.notify).setMessage(C0415R.string.closecloudscan_info).setColorPositiveButton(false).setColorNegativeButton(true).setPositiveButton(C0415R.string.ok, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.AntiVirusSetting.4
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
                PreferenceManager.getDefaultSharedPreferences(AntiVirusSetting.this).edit().putInt("netScan_switch", 0).commit();
                AntiVirusSetting.this.init();
            }
        }).setNegativeButton(C0415R.string.cancel, new DialogInterface.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.AntiVirusSetting.3
            @Override // android.content.DialogInterface.OnClickListener
            public final void onClick(DialogInterface dialog, int which) {
            }
        }).show();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.virus_set);
        setTitle(Integer.valueOf(C0415R.drawable.rf_perf_title_right), C0415R.string.Seetings, (Integer) null);
        this.f3097a = (ImageView) findViewById(C0415R.id.antispam_checkbox);
        this.f3100d = (TextView) findViewById(C0415R.id.antispam_checkboxtxt);
        this.f3102f = (TextView) findViewById(C0415R.id.antispam_txt);
        this.f3098b = (ImageView) findViewById(C0415R.id.antispam_checkbox1);
        this.f3101e = (TextView) findViewById(C0415R.id.antispam_checkboxtxt1);
        this.f3103g = (TextView) findViewById(C0415R.id.antispam_txt1);
        this.f3103g.setText(getSpan_title(C0415R.string.netscan_switch).toString());
        this.f3101e.setText(getSpan(C0415R.string.netscan_switchdesc).toString());
        this.f3102f.setText(getSpan_title(C0415R.string.antivirusrealtime_title).toString());
        this.f3099c = (ImageView) findViewById(C0415R.id.antispam_checkbox3);
        init();
        onBtnclick();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // com.lenovo.safecenter.platform.BaseTitleActivity, android.view.View.OnClickListener
    public void onClick(View v) {
        if (v.getId() == C0415R.id.base_title_left) {
            finish();
        }
    }

    public void init() {
        if (Settings.System.getInt(getContentResolver(), "isRealtimeProtectOpen", 1) == 1) {
            this.f3100d.setText(getSpan(C0415R.string.opend).toString());
            this.f3097a.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f3100d.setText(getSpan(C0415R.string.closed).toString());
            this.f3097a.setImageResource(C0415R.drawable.btn_off);
        }
        if (PreferenceManager.getDefaultSharedPreferences(this).getInt("netScan_switch", 1) == 1) {
            this.f3098b.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f3098b.setImageResource(C0415R.drawable.btn_off);
        }
        if (PreferenceManager.getDefaultSharedPreferences(this).getInt("netScan_weekservice", 1) == 1) {
            this.f3099c.setImageResource(C0415R.drawable.btn_on);
        } else {
            this.f3099c.setImageResource(C0415R.drawable.btn_off);
        }
    }

    public void onBtnclick() {
        this.f3097a.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.AntiVirusSetting.5
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (Const.getProtectVirusSwitchState(AntiVirusSetting.this)) {
                    AntiVirusSetting.m1332a(AntiVirusSetting.this);
                    return;
                }
                Const.setProtectVirusSwitchState(true, AntiVirusSetting.this);
                LeSafeObservable.get(AntiVirusSetting.this).noticeRefreshProtectVirusDetail();
                AntiVirusSetting.this.init();
            }
        });
        this.f3098b.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.AntiVirusSetting.6
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (PreferenceManager.getDefaultSharedPreferences(AntiVirusSetting.this).getInt("netScan_switch", 1) == 1) {
                    AntiVirusSetting.m1333b(AntiVirusSetting.this);
                } else {
                    PreferenceManager.getDefaultSharedPreferences(AntiVirusSetting.this).edit().putInt("netScan_switch", 1).commit();
                    AntiVirusSetting.this.init();
                }
            }
        });
        this.f3099c.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.antivirus.views.AntiVirusSetting.7
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                if (PreferenceManager.getDefaultSharedPreferences(AntiVirusSetting.this).getInt("netScan_weekservice", 1) == 1) {
                    PreferenceManager.getDefaultSharedPreferences(AntiVirusSetting.this).edit().putInt("netScan_weekservice", 0).commit();
                } else {
                    PreferenceManager.getDefaultSharedPreferences(AntiVirusSetting.this).edit().putInt("netScan_weekservice", 1).commit();
                }
                AntiVirusSetting.this.init();
            }
        });
    }

    public SpannableString getSpan(int resID) {
        SpannableString spannable = new SpannableString(getString(resID));
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.gray2)), 0, getString(resID).length(), 0);
        return spannable;
    }

    public SpannableString getSpan_title(int resID) {
        SpannableString spannable = new SpannableString(getString(resID));
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.black2)), 0, getString(resID).length(), 0);
        return spannable;
    }

    public SpannableString getSpan_str(String res) {
        SpannableString spannable = new SpannableString(res);
        spannable.setSpan(new ForegroundColorSpan(getResources().getColor(C0415R.color.gray2)), 0, res.length(), 0);
        return spannable;
    }
}
