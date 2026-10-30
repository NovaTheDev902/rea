package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class AppLockMustUpdateDialogActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    private Handler f2696a = new Handler() { // from class: com.lenovo.safecenter.MainTab.AppLockMustUpdateDialogActivity.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 0:
                    Toast.makeText(AppLockMustUpdateDialogActivity.this, (String) msg.obj, 1).show();
                    break;
            }
            super.handleMessage(msg);
        }
    };

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.dialog);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        TextView title = (TextView) findViewById(C0415R.id.title);
        title.setText(C0415R.string.update_lab_notice_text);
        TextView okbtn = (TextView) findViewById(C0415R.id.positiveButton);
        okbtn.setText(C0415R.string.install_text);
        okbtn.setOnClickListener(this);
        findViewById(C0415R.id.neutralButton).setVisibility(8);
        findViewById(C0415R.id.negativeButton).setVisibility(8);
        View contentView = LayoutInflater.from(this).inflate(C0415R.layout.dialog_notice_update, (ViewGroup) null);
        TextView note = (TextView) contentView.findViewById(C0415R.id.labUpdateNote);
        note.setText(getString(C0415R.string.app_lock_must_update));
        ((LinearLayout) findViewById(C0415R.id.content)).removeAllViews();
        ((LinearLayout) findViewById(C0415R.id.content)).addView(contentView, new ViewGroup.LayoutParams(-1, -2));
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.negativeButton /* 2131296939 */:
                finish();
                break;
            case C0415R.id.positiveButton /* 2131296941 */:
                AppDownloadActivity.copyAssetsFilesInstall(AppDownloadActivity.APP_LOCK_FILE_NAME, Const.PACKAGENAME_APP_LOCK, this, this.f2696a, 0);
                finish();
                break;
        }
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
}
