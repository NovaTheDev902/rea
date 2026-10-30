package com.lenovo.safecenter.notificationintercept;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.ToggleButton;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class AdManager extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private TextView f4756a;

    /* JADX INFO: renamed from: b */
    private ImageView f4757b;

    /* JADX INFO: renamed from: c */
    private ToggleButton f4758c;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(1);
        setContentView(C0415R.layout.notification_admanager);
        this.f4756a = (TextView) findViewById(C0415R.id.txt_title);
        this.f4756a.setText(getString(C0415R.string.intercept_app_ad_setting));
        this.f4757b = (ImageView) findViewById(C0415R.id.title_back);
        this.f4758c = (ToggleButton) findViewById(C0415R.id.intercept_notify_switch);
        findViewById(C0415R.id.notify_switch_layout).setOnClickListener(this);
        this.f4757b.setOnClickListener(this);
        this.f4758c.setChecked(PreferenceManager.getDefaultSharedPreferences(this).getBoolean(InterceptUtils.NOTIFY_SWITCH, true));
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.notify_switch_layout /* 2131297351 */:
                this.f4758c.setChecked(!this.f4758c.isChecked());
                SharedPreferences defaultSharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
                SharedPreferences.Editor edit = defaultSharedPreferences.edit();
                edit.putBoolean(InterceptUtils.NOTIFY_SWITCH, this.f4758c.isChecked());
                edit.commit();
                break;
            case C0415R.id.title_back /* 2131297709 */:
                finish();
                break;
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
        TrackEvent.trackResume(this);
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }
}
