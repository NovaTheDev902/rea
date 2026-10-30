package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.module.aresengine.TelephonyEntity;
import tms.C1168ay;
import tms.C1184bn;
import tms.C1189bs;
import tms.C1211cn;
import tms.C1216cs;

/* JADX INFO: loaded from: classes.dex */
public abstract class DataIntercepterBuilder<T extends TelephonyEntity> {
    public static final String TYPE_INCOMING_CALL = "incoming_call";
    public static final String TYPE_INCOMING_SMS = "incoming_sms";
    public static final String TYPE_OUTGOING_SMS = "outing_sms";
    public static final String TYPE_SYSTEM_CALL = "system_call";

    /* JADX INFO: renamed from: a */
    private DataMonitor<T> f6082a;

    /* JADX INFO: renamed from: b */
    private DataFilter<T> f6083b;

    /* JADX INFO: renamed from: c */
    private DataHandler f6084c;

    public static final DataIntercepterBuilder<CallLogEntity> createInComingCallIntercepterBuilder() {
        return new C1184bn();
    }

    public static final DataIntercepterBuilder<SmsEntity> createInComingSmsIntercepterBuilder() {
        return new C1189bs();
    }

    public static final DataIntercepterBuilder<SmsEntity> createOutgoingSmsIntercepterBuilder() {
        return new C1211cn();
    }

    public static final DataIntercepterBuilder<CallLogEntity> createSystemCallLogIntercepterBuilder() {
        return new C1216cs();
    }

    /* JADX INFO: renamed from: a */
    public synchronized DataIntercepter<T> m2599a() {
        C1168ay c1168ay;
        this.f6082a = this.f6082a == null ? getDataMonitor() : this.f6082a;
        this.f6083b = this.f6083b == null ? getDataFilter() : this.f6083b;
        this.f6084c = this.f6084c == null ? getDataHandler() : this.f6084c;
        if (this.f6082a == null || this.f6083b == null || this.f6084c == null) {
            throw new NullPointerException();
        }
        this.f6082a.bind(this.f6083b);
        this.f6083b.m2597a(this.f6084c);
        c1168ay = new C1168ay(this.f6082a, this.f6083b, this.f6084c);
        this.f6083b = null;
        this.f6082a = null;
        this.f6084c = null;
        return c1168ay;
    }

    /* JADX INFO: renamed from: a */
    final synchronized void m2600a(DataFilter<T> dataFilter) {
        this.f6083b = dataFilter;
    }

    public abstract DataFilter<T> getDataFilter();

    public abstract DataHandler getDataHandler();

    public abstract DataMonitor<T> getDataMonitor();

    public abstract String getName();

    public synchronized void setDataHandler(DataHandler dataHandler) {
        this.f6084c = dataHandler;
    }

    public synchronized void setDataMonitor(DataMonitor<T> dataMonitor) {
        this.f6082a = dataMonitor;
    }
}
