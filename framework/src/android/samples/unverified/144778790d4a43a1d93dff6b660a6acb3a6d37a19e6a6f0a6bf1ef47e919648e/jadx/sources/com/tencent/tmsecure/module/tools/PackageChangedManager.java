package com.tencent.tmsecure.module.tools;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1309gn;

/* JADX INFO: loaded from: classes.dex */
public final class PackageChangedManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1309gn f6232a;

    public final IPackageChangedListener addListener(IPackageChangedListener iPackageChangedListener) {
        if (isExpired()) {
            return null;
        }
        return this.f6232a.m3429a(iPackageChangedListener);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6232a = new C1309gn();
        this.f6232a.onCreate(context);
        setImpl(this.f6232a);
    }

    public final IPackageChangedListener removeListener(IPackageChangedListener iPackageChangedListener) {
        if (isExpired()) {
            return null;
        }
        return this.f6232a.m3430b(iPackageChangedListener);
    }
}
