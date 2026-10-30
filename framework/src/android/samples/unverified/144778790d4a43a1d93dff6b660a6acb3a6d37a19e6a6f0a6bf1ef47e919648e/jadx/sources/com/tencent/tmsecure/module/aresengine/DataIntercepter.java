package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.module.aresengine.TelephonyEntity;

/* JADX INFO: loaded from: classes.dex */
public interface DataIntercepter<T extends TelephonyEntity> {
    DataFilter<T> dataFilter();

    DataHandler dataHandler();

    DataMonitor<T> dataMonitor();
}
