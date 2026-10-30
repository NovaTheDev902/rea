package com.tencent.tmsecure.module.aresengine;

import android.content.Context;
import com.tencent.tmsecure.common.BaseManager;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import tms.C1164au;
import tms.C1209cl;
import tms.C1210cm;

/* JADX INFO: loaded from: classes.dex */
public final class AresEngineManager extends BaseManager {

    /* JADX INFO: renamed from: a */
    private C1164au f6071a;

    /* JADX INFO: renamed from: b */
    private Map<String, DataIntercepter<? extends TelephonyEntity>> f6072b;

    /* JADX INFO: renamed from: c */
    private C1210cm f6073c;

    public final void addIntercepter(DataIntercepterBuilder<? extends TelephonyEntity> dataIntercepterBuilder) throws RuntimeException {
        if (isExpired()) {
            return;
        }
        this.f6071a.m2945a(dataIntercepterBuilder);
    }

    public final DataIntercepter<? extends TelephonyEntity> findIntercepter(String str) {
        if (!isExpired()) {
            return this.f6071a.m2941a(str);
        }
        if (this.f6072b == null) {
            this.f6072b = new HashMap();
            for (String str2 : new String[]{DataIntercepterBuilder.TYPE_INCOMING_CALL, DataIntercepterBuilder.TYPE_INCOMING_SMS, DataIntercepterBuilder.TYPE_OUTGOING_SMS, DataIntercepterBuilder.TYPE_SYSTEM_CALL}) {
                this.f6072b.put(str2, new C1209cl(str2));
            }
        }
        return this.f6072b.get(str);
    }

    public final AresEngineFactor getAresEngineFactor() {
        return this.f6071a.m2948c();
    }

    public final IIntelligentSmsChecker getIntelligentSmsChecker() {
        if (!isExpired()) {
            return this.f6071a.m2947b();
        }
        if (this.f6073c == null) {
            this.f6073c = new C1210cm();
        }
        return this.f6073c;
    }

    public final List<DataIntercepter<? extends TelephonyEntity>> intercepters() {
        return isExpired() ? new ArrayList() : this.f6071a.m2942a();
    }

    @Override // com.tencent.tmsecure.common.BaseManager
    public final void onCreate(Context context) {
        this.f6071a = new C1164au();
        this.f6071a.onCreate(context);
        setImpl(this.f6071a);
    }

    public final boolean reportSms(List<SmsEntity> list) {
        return this.f6071a.m2946a(list);
    }

    public final void setAresEngineFactor(AresEngineFactor aresEngineFactor) {
        this.f6071a.m2944a(aresEngineFactor);
    }

    public final void setHoldoffMode(int i) {
        if (isExpired()) {
            return;
        }
        this.f6071a.m2943a(i);
    }
}
