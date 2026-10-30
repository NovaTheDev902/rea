package com.tencent.tmsecure.module.update;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.List;
import tms.C1312gy;

/* JADX INFO: loaded from: classes.dex */
public final class UpdateManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1312gy f6237a;

    public final void addObserver(int i, IUpdateObserver iUpdateObserver) {
        this.f6237a.m3443a(i, iUpdateObserver);
    }

    public final void cancel() {
        this.f6237a.m3440a();
    }

    public final void check(int i, ICheckListener iCheckListener) {
        this.f6237a.m3442a(i, iCheckListener);
    }

    public final String getFileSavePath() {
        return this.f6237a.m3445b();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6237a = new C1312gy();
        this.f6237a.onCreate(context);
        setImpl(this.f6237a);
    }

    public final void removeObserver(int i) {
        this.f6237a.m3441a(i);
    }

    public final void update(List<UpdateInfo> list, IUpdateListener iUpdateListener) {
        this.f6237a.m3444a(list, iUpdateListener);
    }
}
