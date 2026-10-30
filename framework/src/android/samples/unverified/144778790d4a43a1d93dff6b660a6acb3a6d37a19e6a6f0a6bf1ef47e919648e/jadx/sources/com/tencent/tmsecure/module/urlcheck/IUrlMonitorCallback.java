package com.tencent.tmsecure.module.urlcheck;

/* JADX INFO: loaded from: classes.dex */
public interface IUrlMonitorCallback {
    public static final int DES_ID_HOBBYHORSE = 1;
    public static final int DES_ID_NORMAL = 0;

    void onCallback(String str, int i);
}
