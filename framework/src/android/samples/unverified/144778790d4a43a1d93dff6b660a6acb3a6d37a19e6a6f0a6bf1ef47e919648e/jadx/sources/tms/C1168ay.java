package tms;

import com.tencent.tmsecure.module.aresengine.DataFilter;
import com.tencent.tmsecure.module.aresengine.DataHandler;
import com.tencent.tmsecure.module.aresengine.DataIntercepter;
import com.tencent.tmsecure.module.aresengine.DataMonitor;
import com.tencent.tmsecure.module.aresengine.TelephonyEntity;

/* JADX INFO: renamed from: tms.ay */
/* JADX INFO: loaded from: classes.dex */
public final class C1168ay<T extends TelephonyEntity> implements DataIntercepter<T> {

    /* JADX INFO: renamed from: a */
    private DataMonitor<T> f6873a;

    /* JADX INFO: renamed from: b */
    private DataFilter<T> f6874b;

    /* JADX INFO: renamed from: c */
    private DataHandler f6875c;

    public C1168ay(DataMonitor<T> dataMonitor, DataFilter<T> dataFilter, DataHandler dataHandler) {
        this.f6873a = dataMonitor;
        this.f6874b = dataFilter;
        this.f6875c = dataHandler;
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepter
    public final DataFilter<T> dataFilter() {
        return this.f6874b;
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepter
    public final DataHandler dataHandler() {
        return this.f6875c;
    }

    @Override // com.tencent.tmsecure.module.aresengine.DataIntercepter
    public final DataMonitor<T> dataMonitor() {
        return this.f6873a;
    }
}
