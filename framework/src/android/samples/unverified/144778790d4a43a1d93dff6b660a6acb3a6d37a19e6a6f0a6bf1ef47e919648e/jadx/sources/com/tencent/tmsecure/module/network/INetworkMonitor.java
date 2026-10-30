package com.tencent.tmsecure.module.network;

import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public interface INetworkMonitor {
    int addCallback(INetworkChangeCallBack iNetworkChangeCallBack);

    void clearAllLogs();

    ArrayList<NetworkInfoEntity> getAllLogs();

    boolean getRefreshState();

    void notifyConfigChange();

    boolean removeCallback(int i);

    boolean removeCallback(INetworkChangeCallBack iNetworkChangeCallBack);

    void setRefreshState(boolean z);
}
