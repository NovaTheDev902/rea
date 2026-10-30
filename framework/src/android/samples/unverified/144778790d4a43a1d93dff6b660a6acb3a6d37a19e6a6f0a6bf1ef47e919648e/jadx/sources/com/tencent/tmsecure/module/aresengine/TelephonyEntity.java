package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.common.BaseEntity;

/* JADX INFO: loaded from: classes.dex */
public abstract class TelephonyEntity extends BaseEntity {

    /* JADX INFO: renamed from: a */
    private static final long f6094a = 1;
    public String name;
    public String phonenum;

    public TelephonyEntity() {
    }

    public TelephonyEntity(TelephonyEntity telephonyEntity) {
        this.f6027id = telephonyEntity.f6027id;
        this.phonenum = telephonyEntity.phonenum;
    }
}
