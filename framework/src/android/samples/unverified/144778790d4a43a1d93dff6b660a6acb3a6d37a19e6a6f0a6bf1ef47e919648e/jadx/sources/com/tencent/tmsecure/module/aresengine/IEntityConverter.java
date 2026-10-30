package com.tencent.tmsecure.module.aresengine;

/* JADX INFO: loaded from: classes.dex */
public interface IEntityConverter {
    <T extends CallLogEntity> T convert(CallLogEntity callLogEntity);

    <T extends SmsEntity> T convert(SmsEntity smsEntity);
}
