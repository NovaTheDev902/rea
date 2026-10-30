package com.lenovo.safecenter.systeminfo.service;

import android.content.Context;
import android.content.pm.PackageManager;
import android.util.DisplayMetrics;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;

/* JADX INFO: loaded from: classes.dex */
public class ScreenInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5630a = ScreenInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static ScreenInfoService f5631b = new ScreenInfoService();

    private ScreenInfoService() {
    }

    public static ScreenInfoService getInstance() {
        return f5631b;
    }

    public String getDisplayMetrics() {
        Context context = Const.mContext;
        StringBuffer buffer = new StringBuffer();
        DisplayMetrics dm = context.getApplicationContext().getResources().getDisplayMetrics();
        int screenWidth = dm.widthPixels;
        int screenHeight = dm.heightPixels;
        float xdpi = dm.xdpi;
        PackageManager pm = context.getPackageManager();
        boolean supportMultiTouch = pm.hasSystemFeature("android.hardware.touchscreen.multitouch");
        buffer.append(Const.mContext.getString(C0415R.string.srceen_px)).append(screenHeight).append('*').append(screenWidth).append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.srceen_dp)).append(xdpi).append(" Dpi").append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.srceen_mutil)).append(supportMultiTouch ? "支持" : "不支持");
        return buffer.toString();
    }
}
