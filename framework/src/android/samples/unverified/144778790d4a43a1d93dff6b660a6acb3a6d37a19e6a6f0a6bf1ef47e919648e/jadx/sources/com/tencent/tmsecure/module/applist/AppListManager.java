package com.tencent.tmsecure.module.applist;

import QQPIM.SoftListType;
import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import tms.C1162as;

/* JADX INFO: loaded from: classes.dex */
public class AppListManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1162as f6070a;

    public boolean contains(String str, SoftListType softListType) {
        if (isExpired()) {
            return false;
        }
        return this.f6070a.m2940a(str, softListType);
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public void onCreate(Context context) {
        this.f6070a = new C1162as();
        this.f6070a.onCreate(context);
        setImpl(this.f6070a);
    }
}
