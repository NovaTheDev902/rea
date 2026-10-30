package com.lenovo.safecenter.utils.homepageUtil;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Handler;
import android.os.Message;
import android.preference.PreferenceManager;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import com.lenovo.safecenter.C0415R;

/* JADX INFO: loaded from: classes.dex */
public abstract class BaseDrawer {
    protected static SharedPreferences mSp;
    protected int idIcon;
    protected Context mContext;
    protected boolean mIsUp;
    protected String mTitle;
    protected boolean mIsNew = false;
    protected Handler mHandler = new Handler() { // from class: com.lenovo.safecenter.utils.homepageUtil.BaseDrawer.1
        @Override // android.os.Handler
        public final void handleMessage(Message msg) {
            switch (msg.what) {
                case 1:
                    InputMethodManager m = (InputMethodManager) BaseDrawer.this.mContext.getSystemService("input_method");
                    m.toggleSoftInput(0, 2);
                    break;
            }
        }
    };

    public abstract View getView(View view);

    public abstract void onClick();

    public BaseDrawer(int idIcon, String title, Context context, boolean isUp) {
        this.idIcon = idIcon;
        this.mTitle = title;
        this.mContext = context;
        this.mIsUp = isUp;
        mSp = PreferenceManager.getDefaultSharedPreferences(this.mContext);
    }

    public void setBackgroundResource(ViewGroup v) {
        if (this.mIsUp) {
            v.setBackgroundResource(C0415R.drawable.home_page_drawer_up_content_bg_selector);
        } else {
            v.setBackgroundResource(C0415R.drawable.home_page_drawer_down_content_bg_selector);
        }
    }
}
