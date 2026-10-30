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
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.database.AppDatabase;
import com.lenovo.safecenter.lenovoAntiSpam.views.SpamConfirm;
import com.lenovo.safecenter.utils.Const;
import com.lenovo.safecenter.utils.TrackEvent;

/* JADX INFO: loaded from: classes.dex */
public class FirstSignActivity extends Activity implements View.OnClickListener {
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(C0415R.layout.dialog);
        if (Const.SDK_VERSION >= 11) {
            setFinishOnTouchOutside(false);
        }
        RelativeLayout rel_title = (RelativeLayout) findViewById(C0415R.id.rel_title);
        rel_title.setGravity(16);
        ImageView img = (ImageView) findViewById(C0415R.id.icon);
        img.setVisibility(0);
        img.setImageResource(C0415R.drawable.prisign_icon);
        TextView title = (TextView) findViewById(C0415R.id.title);
        title.setText(C0415R.string.sign);
        TextView okbtn = (TextView) findViewById(C0415R.id.positiveButton);
        okbtn.setText(C0415R.string.first_sign_ok);
        okbtn.setOnClickListener(this);
        findViewById(C0415R.id.neutralButton).setVisibility(8);
        TextView cancelbtn = (TextView) findViewById(C0415R.id.negativeButton);
        cancelbtn.setText(C0415R.string.first_sign_cancel);
        cancelbtn.setOnClickListener(this);
        View contentView = LayoutInflater.from(this).inflate(C0415R.layout.dialog_notice_update, (ViewGroup) null);
        TextView note = (TextView) contentView.findViewById(C0415R.id.labUpdateNote);
        note.setText(String.format(getString(C0415R.string.sign_actinfo), getIntent().getStringExtra(AppDatabase.NUMBER)));
        ((LinearLayout) findViewById(C0415R.id.content)).removeAllViews();
        ((LinearLayout) findViewById(C0415R.id.content)).addView(contentView, new ViewGroup.LayoutParams(-1, -2));
        contentView.setPadding(10, 5, 10, 5);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        switch (v.getId()) {
            case C0415R.id.negativeButton /* 2131296939 */:
                AppDatabase db = new AppDatabase(this);
                db.insertHarassPhone(getIntent().getStringExtra(AppDatabase.NUMBER));
                finish();
                break;
            case C0415R.id.positiveButton /* 2131296941 */:
                Intent intent = new Intent(this, (Class<?>) SpamConfirm.class);
                intent.addFlags(335544320);
                intent.putExtra(AppDatabase.NUMBER, getIntent().getStringExtra(AppDatabase.NUMBER));
                intent.putExtra("wastetime", getIntent().getIntExtra("wastetime", 0));
                startActivity(intent);
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
