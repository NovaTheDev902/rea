package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.module.aresengine.SmsEntity;

/* JADX INFO: loaded from: classes.dex */
public interface ISmsDao<T extends SmsEntity> {
    long insert(T t, FilterResult filterResult);
}
