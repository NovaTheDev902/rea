package com.tencent.tmsecure.module.network;

/* JADX INFO: loaded from: classes.dex */
public interface INetworkChangeCallBack {
    void onClosingDateReached();

    void onDayChanged();

    void onNormalChanged(NetworkInfoEntity networkInfoEntity);
}
