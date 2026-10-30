package com.lenovo.lps.reaper.sdk.api;

import com.lenovo.lps.reaper.sdk.util.TLog;

/* JADX INFO: loaded from: classes.dex */
public final class CustomParameterManager {

    /* JADX INFO: renamed from: a */
    private final CustomParameter[] f1108a = new CustomParameter[5];

    /* JADX INFO: renamed from: b */
    private int f1109b;

    public CustomParameterManager() {
        for (int i = 0; i < 5; i++) {
            this.f1108a[i] = new CustomParameter();
        }
    }

    public final void setCustomParameter(int index, String name, String value) {
        if (CustomParameter.check(index, name, value)) {
            synchronized (this) {
                StringBuilder sb = new StringBuilder(256);
                if (sb.append(name).append(value).length() > 256) {
                    value = sb.substring(name.length(), 256).toString();
                }
                if (!this.f1108a[index - 1].isValid()) {
                    this.f1109b++;
                }
                this.f1108a[index - 1].setIndex(index);
                this.f1108a[index - 1].setName(name);
                this.f1108a[index - 1].setValue(value);
            }
        }
    }

    public final synchronized CustomParameter[] getAllCustomParameters() {
        CustomParameter[] result;
        int i;
        result = new CustomParameter[this.f1109b];
        CustomParameter[] arr$ = this.f1108a;
        int len$ = arr$.length;
        int i$ = 0;
        int i2 = 0;
        while (i$ < len$) {
            CustomParameter customParameter = arr$[i$];
            if (customParameter.isValid()) {
                i = i2 + 1;
                result[i2] = customParameter;
            } else {
                i = i2;
            }
            i$++;
            i2 = i;
        }
        return result;
    }

    public final synchronized void clear() {
        for (int i = 0; i < this.f1108a.length; i++) {
            try {
                this.f1108a[i].reset();
            } catch (Exception e) {
                TLog.m245w("CustomParameterManager", "ClearCustomParameter. " + e.getMessage());
            }
        }
        this.f1109b = 0;
    }
}
