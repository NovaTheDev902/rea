package com.tencent.tmsecure.module.tools;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1311gx;

/* JADX INFO: loaded from: classes.dex */
public final class SingletonManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1311gx f6234a;

    public final <T extends ISingleton> T getSingleton(Class<T> cls) {
        return (T) this.f6234a.m3436a(cls);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6234a = new C1311gx();
        this.f6234a.onCreate(context);
        setImpl(this.f6234a);
    }
}
