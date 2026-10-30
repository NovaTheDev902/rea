package com.lenovo.safecenter.lenovoAntiSpam.newview;

import android.app.Activity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class FirstHarssActivity extends Activity implements View.OnClickListener {

    /* JADX INFO: renamed from: a */
    String f3896a = null;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.dialog);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        if (getIntent() != null) {
            this.f3896a = getIntent().getStringExtra("from");
        }
        RelativeLayout rel_title = (RelativeLayout) findViewById(C0415R.id.rel_title);
        rel_title.setGravity(17);
        ImageView img = (ImageView) findViewById(C0415R.id.icon);
        img.setVisibility(8);
        TextView title = (TextView) findViewById(C0415R.id.title);
        title.setText(C0415R.string.harss_firsttitle);
        TextView okbtn = (TextView) findViewById(C0415R.id.positiveButton);
        okbtn.setText(C0415R.string.known);
        okbtn.setOnClickListener(this);
        findViewById(C0415R.id.neutralButton).setVisibility(8);
        findViewById(C0415R.id.negativeButton).setVisibility(8);
        View contentView = LayoutInflater.from(this).inflate(C0415R.layout.firstharass, (ViewGroup) null);
        if (this.f3896a == null) {
            ((LinearLayout) contentView.findViewById(C0415R.id.harass_layout)).setVisibility(0);
        } else {
            ((LinearLayout) contentView.findViewById(C0415R.id.privacy_layout)).setVisibility(0);
            ((TextView) contentView.findViewById(C0415R.id.labUpdateNote)).setText(C0415R.string.privacy_firstdesc);
        }
        ((LinearLayout) findViewById(C0415R.id.content)).removeAllViews();
        ((LinearLayout) findViewById(C0415R.id.content)).addView(contentView, new ViewGroup.LayoutParams(-1, -2));
        contentView.setPadding(10, 5, 10, 5);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.positiveButton /* 2131296941 */:
                finish();
                break;
        }
    }

    @Override // android.app.Activity
    protected void onResume() {
        TrackEvent.trackResume(this);
        super.onResume();
    }

    @Override // android.app.Activity
    protected void onPause() {
        TrackEvent.trackPause(this);
        super.onPause();
    }
}
