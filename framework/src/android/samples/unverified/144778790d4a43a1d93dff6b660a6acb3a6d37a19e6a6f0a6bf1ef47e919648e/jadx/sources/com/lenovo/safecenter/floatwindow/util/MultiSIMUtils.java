package com.lenovo.safecenter.floatwindow.util;

import android.content.Context;
import java.lang.reflect.Method;

/* JADX INFO: loaded from: classes.dex */
public class MultiSIMUtils {

    /* JADX INFO: renamed from: a */
    Class f3577a;

    /* JADX INFO: renamed from: b */
    Object f3578b;

    /* JADX INFO: renamed from: c */
    private Context f3579c;

    public MultiSIMUtils(Context context) {
        this.f3579c = context;
        try {
            this.f3577a = Class.forName("android.provider.MultiSIMUtils");
            Method getDefault = this.f3577a.getMethod("getDefault", Context.class);
            this.f3578b = getDefault.invoke(null, context);
        } catch (Exception e) {
        }
    }

    public String getDataSubscriberId() {
        try {
            Method getDataSubscriberId = this.f3577a.getMethod("getDataSubscriberId", null);
            return (String) getDataSubscriberId.invoke(this.f3578b, null);
        } catch (Exception e) {
            return null;
        }
    }

    public String getPlatform() {
        try {
            Method getPlatform = this.f3577a.getMethod("getPlatform", null);
            return (String) getPlatform.invoke(this.f3578b, null);
        } catch (Exception e) {
            return null;
        }
    }

    public int getSimState(int mSlot) {
        try {
            Method getSimState = this.f3577a.getMethod("getSimState", Integer.TYPE);
            return ((Integer) getSimState.invoke(this.f3578b, Integer.valueOf(mSlot))).intValue();
        } catch (Exception e) {
            return 0;
        }
    }

    public String getSubscriberId(int mSlot) {
        try {
            Method getSubscriberId = this.f3577a.getMethod("getSubscriberId", Integer.TYPE);
            return (String) getSubscriberId.invoke(this.f3578b, Integer.valueOf(mSlot));
        } catch (Exception e) {
            return null;
        }
    }
}
