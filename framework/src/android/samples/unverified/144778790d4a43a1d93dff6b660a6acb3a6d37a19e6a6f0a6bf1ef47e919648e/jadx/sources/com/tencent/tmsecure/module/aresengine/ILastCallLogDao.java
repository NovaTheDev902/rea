package com.tencent.tmsecure.module.aresengine;

/* JADX INFO: loaded from: classes.dex */
public interface ILastCallLogDao {
    boolean contains(String str);

    void update(CallLogEntity callLogEntity);
}
