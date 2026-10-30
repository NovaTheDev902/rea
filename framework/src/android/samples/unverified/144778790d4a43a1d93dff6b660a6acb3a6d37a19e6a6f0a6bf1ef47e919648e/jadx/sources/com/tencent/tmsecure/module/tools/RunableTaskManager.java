package com.tencent.tmsecure.module.tools;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1310gv;

/* JADX INFO: loaded from: classes.dex */
public final class RunableTaskManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1310gv f6233a;

    public final boolean addTask(Runnable runnable, long j) {
        return this.f6233a.m3435a(runnable, j);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6233a = new C1310gv();
        this.f6233a.onCreate(context);
        setImpl(this.f6233a);
    }
}
