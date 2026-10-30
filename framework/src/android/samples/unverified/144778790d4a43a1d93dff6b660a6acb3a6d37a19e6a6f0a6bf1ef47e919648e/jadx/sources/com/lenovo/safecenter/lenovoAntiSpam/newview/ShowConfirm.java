package com.lenovo.safecenter.lenovoAntiSpam.newview;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.performancecenter.framework.DatabaseTables;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.antivirus.views.FullSystemScanActivity;
import com.lenovo.safecenter.lenovoAntiSpam.utils.HttpUtils;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class ShowConfirm extends Activity implements View.OnClickListener {
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.dialog);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        RelativeLayout rel_title = (RelativeLayout) findViewById(C0415R.id.rel_title);
        rel_title.setGravity(17);
        ImageView img = (ImageView) findViewById(C0415R.id.icon);
        img.setVisibility(8);
        img.setImageResource(C0415R.drawable.prisign_icon);
        TextView title = (TextView) findViewById(C0415R.id.title);
        title.setText(C0415R.string.harss_firsttitle);
        TextView okbtn = (TextView) findViewById(C0415R.id.positiveButton);
        okbtn.setOnClickListener(this);
        findViewById(C0415R.id.neutralButton).setVisibility(8);
        TextView cancelbtn = (TextView) findViewById(C0415R.id.negativeButton);
        cancelbtn.setOnClickListener(this);
        View contentView = LayoutInflater.from(this).inflate(C0415R.layout.dialog_notice_update, (ViewGroup) null);
        TextView note = (TextView) contentView.findViewById(C0415R.id.labUpdateNote);
        if (getIntent().getStringExtra("from").equals("cloudscan")) {
            note.setText(String.format(getString(C0415R.string.show_cloudscan), getIntent().getStringExtra("count")));
            cancelbtn.setText(C0415R.string.antivirusappvirus_nodeal);
            okbtn.setText(C0415R.string.show_cloudscanok);
        } else if (getIntent().getStringExtra("from").equals("nullnumber")) {
            note.setText(C0415R.string.nonumber_confirm);
            cancelbtn.setText(C0415R.string.first_sign_cancel);
            okbtn.setText(C0415R.string.nonumber_ok);
        }
        ((LinearLayout) findViewById(C0415R.id.content)).removeAllViews();
        ((LinearLayout) findViewById(C0415R.id.content)).addView(contentView, new ViewGroup.LayoutParams(-1, -2));
        contentView.setPadding(10, 5, 10, 5);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.negativeButton /* 2131296939 */:
                if (getIntent().getStringExtra("from").equals("cloudscan")) {
                    TrackEvent.reportUserActionIgnoreVirusCanUpdateNotice();
                }
                finish();
                break;
            case C0415R.id.positiveButton /* 2131296941 */:
                if (getIntent().getStringExtra("from").equals("cloudscan")) {
                    TrackEvent.reportUserActionCloudKillVirusCanUpdateNotice();
                    startActivity(new Intent(this, (Class<?>) FullSystemScanActivity.class));
                } else if (getIntent().getStringExtra("from").equals("nullnumber")) {
                    new HttpUtils().UpdateConfig("getnonumber", DatabaseTables.SYSTEM_MARK, this);
                }
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
        TrackEvent.trackResume(this);
        super.onResume();
    }
}
