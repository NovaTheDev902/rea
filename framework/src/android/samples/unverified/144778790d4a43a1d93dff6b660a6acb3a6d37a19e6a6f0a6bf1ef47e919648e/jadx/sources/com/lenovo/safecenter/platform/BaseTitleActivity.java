package com.lenovo.safecenter.platform;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public abstract class BaseTitleActivity extends Activity implements View.OnClickListener {
    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.i("BaseTitleActivity", "onCreate");
        requestWindowFeature(7);
    }

    public void setTitle(Integer leftImgId, int titleStrId, Integer rightImgId) {
        getWindow().setFeatureInt(7, C0415R.layout.rf_perf_basetitle);
        Log.i("BaseTitleActivity", "setTitle()...leftImgId=" + leftImgId + "--rightImgId=" + rightImgId);
        ((TextView) findViewById(C0415R.id.base_title_center)).setText(titleStrId);
        findViewById(C0415R.id.base_title_center).setOnClickListener(this);
        if (leftImgId != null) {
            findViewById(C0415R.id.base_title_left).setOnClickListener(this);
        } else {
            setLeftImgGone(8);
        }
        if (rightImgId != null) {
            findViewById(C0415R.id.base_title_right).setOnClickListener(this);
        } else {
            setRightImgGone(8);
        }
    }

    public void setTitle(Integer leftImgId, String str, Integer rightImgId) {
        getWindow().setFeatureInt(7, C0415R.layout.rf_perf_basetitle);
        Log.i("BaseTitleActivity", "setTitle()...leftImgId=" + leftImgId + "--rightImgId=" + rightImgId);
        ((TextView) findViewById(C0415R.id.base_title_center)).setText(str);
        findViewById(C0415R.id.base_title_center).setOnClickListener(this);
        if (leftImgId != null) {
            findViewById(C0415R.id.base_title_left).setOnClickListener(this);
        } else {
            setLeftImgGone(8);
        }
        if (rightImgId != null) {
            findViewById(C0415R.id.base_title_right).setOnClickListener(this);
        } else {
            setRightImgGone(8);
        }
    }

    @Override // android.app.Activity
    protected void onDestroy() {
        super.onDestroy();
    }

    @Override // android.app.Activity
    protected void onRestart() {
        super.onRestart();
    }

    @Override // android.app.Activity
    protected void onResume() {
        super.onResume();
    }

    public void onClick(View v) {
    }

    public void setLeftImgGone(int gone) {
        Log.i("BaseTitleActivity", "setLeftImgGone()...gone=" + gone);
        findViewById(C0415R.id.base_title_left).setVisibility(gone);
    }

    public void setRightImgGone(int gone) {
        findViewById(C0415R.id.base_title_right).setVisibility(gone);
    }
}
