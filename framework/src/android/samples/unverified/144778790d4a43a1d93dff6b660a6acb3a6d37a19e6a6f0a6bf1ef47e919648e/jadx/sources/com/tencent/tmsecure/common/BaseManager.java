package com.tencent.tmsecure.common;

import android.content.Context;
import tms.C1278f;

/* JADX INFO: loaded from: classes.dex */
public abstract class BaseManager {
    public static final int TYPE_AUTO = 0;
    public static final int TYPE_FOREVER = 1;
    public static final int TYPE_ONCE = 2;

    /* JADX INFO: renamed from: a */
    private BaseManager f6028a;

    protected static final boolean isExpired() {
        return C1278f.m3286a().m3297e();
    }

    public int getSingletonType() {
        if (this.f6028a != null) {
            return this.f6028a.getSingletonType();
        }
        return 0;
    }

    public abstract void onCreate(Context context);

    protected void setImpl(BaseManager baseManager) {
        this.f6028a = baseManager;
    }
}
