package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.os.Bundle;
import android.text.format.Formatter;
import android.view.View;
import android.widget.TextView;
import com.lenovo.lps.sus.SUS;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class VersionUpdateDIalogActivity extends Activity {
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.dialog);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        TextView title = (TextView) findViewById(C0415R.id.title);
        title.setText(C0415R.string.SUS_VERSIONUPDATE);
        TextView message = (TextView) findViewById(C0415R.id.message);
        message.setText(getString(C0415R.string.SUS_UPDATEVERPROMPT_VERNAME) + getIntent().getStringExtra("versionname") + "\n" + getString(C0415R.string.SUS_UPDATEVERPROMPT_VERSIZE) + Formatter.formatFileSize(this, getIntent().getLongExtra("filesize", 0L)) + "\n" + getString(C0415R.string.SUS_UPDATESIZEPROMPT_WLAN) + "\n" + getIntent().getStringExtra("appinfo"));
        TextView okbtn = (TextView) findViewById(C0415R.id.positiveButton);
        okbtn.setText(C0415R.string.SUS_UPDATE);
        okbtn.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.VersionUpdateDIalogActivity.1
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                SUS.downloadApp(VersionUpdateDIalogActivity.this, VersionUpdateDIalogActivity.this.getIntent().getStringExtra("url"), VersionUpdateDIalogActivity.this.getIntent().getStringExtra("apkname"), Long.valueOf(VersionUpdateDIalogActivity.this.getIntent().getLongExtra("filesize", 0L)));
                VersionUpdateDIalogActivity.this.finish();
            }
        });
        findViewById(C0415R.id.neutralButton).setVisibility(8);
        TextView cancelbtn = (TextView) findViewById(C0415R.id.negativeButton);
        cancelbtn.setText(C0415R.string.cancel);
        cancelbtn.setOnClickListener(new View.OnClickListener() { // from class: com.lenovo.safecenter.MainTab.VersionUpdateDIalogActivity.2
            @Override // android.view.View.OnClickListener
            public final void onClick(View v) {
                VersionUpdateDIalogActivity.this.finish();
            }
        });
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
