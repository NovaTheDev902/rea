package com.tencent.tmsecure.module.market;

import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public interface IMarketManagerListener<K, T> {
    void onReceive(K k, ArrayList<T> arrayList);
}
