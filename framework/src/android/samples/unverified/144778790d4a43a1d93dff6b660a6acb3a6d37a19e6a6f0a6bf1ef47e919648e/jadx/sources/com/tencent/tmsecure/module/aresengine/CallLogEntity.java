package com.tencent.tmsecure.module.aresengine;

/* JADX INFO: loaded from: classes.dex */
public class CallLogEntity extends TelephonyEntity {

    /* JADX INFO: renamed from: a */
    private static final long f6074a = 1;
    public long date;
    public long duration;
    public int type;

    public CallLogEntity() {
    }

    public CallLogEntity(CallLogEntity callLogEntity) {
        super(callLogEntity);
        this.date = callLogEntity.date;
        this.type = callLogEntity.type;
        this.duration = callLogEntity.duration;
    }
}
