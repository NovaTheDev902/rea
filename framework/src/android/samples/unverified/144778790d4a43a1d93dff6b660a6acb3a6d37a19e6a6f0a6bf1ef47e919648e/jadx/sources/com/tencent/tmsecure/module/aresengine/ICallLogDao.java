package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.module.aresengine.CallLogEntity;

/* JADX INFO: loaded from: classes.dex */
public interface ICallLogDao<T extends CallLogEntity> {
    long insert(T t, FilterResult filterResult);
}
