package com.lenovo.safecenter.systeminfo.service;

import android.content.Context;
import android.os.Build;
import android.telephony.TelephonyManager;
import com.lenovo.safecenter.C0415R;
import com.lenovo.safecenter.utils.Const;

/* JADX INFO: loaded from: classes.dex */
public class PhoneInfoService {

    /* JADX INFO: renamed from: a */
    private static final String f5626a = PhoneInfoService.class.getSimpleName();

    /* JADX INFO: renamed from: b */
    private static PhoneInfoService f5627b = new PhoneInfoService();

    private PhoneInfoService() {
    }

    public static PhoneInfoService getInstance() {
        return f5627b;
    }

    public String getModelName() {
        return Build.MODEL;
    }

    public String getDeviceId() {
        Context context = Const.mContext;
        TelephonyManager manager = (TelephonyManager) context.getSystemService("phone");
        return manager.getDeviceId();
    }

    public String getSystemSoftwareVersion() {
        return Build.VERSION.RELEASE;
    }

    public String getPhoneInfo() {
        StringBuffer buffer = new StringBuffer();
        buffer.append(Const.mContext.getString(C0415R.string.machine_type)).append(getModelName()).append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.os_type)).append(getSystemSoftwareVersion()).append('\n');
        buffer.append(Const.mContext.getString(C0415R.string.phone_imsi)).append(getDeviceId() == null ? Const.mContext.getString(C0415R.string.antispamlocalblack_noName) : getDeviceId());
        return buffer.toString();
    }
}
