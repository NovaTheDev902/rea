package com.lenovo.safecenter.MainTab;

import android.app.Activity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;
import com.lenovo.safecenter.utils.updateLab.UpdateLabManager;

/* JADX INFO: loaded from: classes.dex */
public class LabUpdateDialogActivity extends Activity implements View.OnClickListener {
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
        okbtn.setText(C0415R.string.update);
        okbtn.setOnClickListener(this);
        findViewById(C0415R.id.neutralButton).setVisibility(8);
        TextView cancelbtn = (TextView) findViewById(C0415R.id.negativeButton);
        cancelbtn.setText(C0415R.string.last_time_do);
        cancelbtn.setOnClickListener(this);
        View contentView = LayoutInflater.from(this).inflate(C0415R.layout.dialog_notice_update, (ViewGroup) null);
        TextView note = (TextView) contentView.findViewById(C0415R.id.labUpdateNote);
        StringBuffer canUpdatelabs = new StringBuffer();
        if (UpdateLabManager.getQueryLabStatus(0) == 0) {
            canUpdatelabs.append(" ");
            canUpdatelabs.append(getString(C0415R.string.title_virus_lab));
        }
        if (UpdateLabManager.getQueryLabStatus(1) == 0) {
            if (canUpdatelabs.length() != 0) {
                canUpdatelabs.append("、");
            }
            canUpdatelabs.append(getString(C0415R.string.harass_lab_text));
            canUpdatelabs.append(" ");
        }
        if (UpdateLabManager.getQueryLabStatus(3) == 0) {
            if (canUpdatelabs.length() != 0) {
                canUpdatelabs.append("、");
            }
            canUpdatelabs.append(getString(C0415R.string.biaoji_lab));
            canUpdatelabs.append(" ");
        }
        note.setText(String.format(getString(C0415R.string.has_lab_update_note_message), canUpdatelabs.toString()));
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
                UpdateLabManager.startServiceUpdateLab(this);
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
