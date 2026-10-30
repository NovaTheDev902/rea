package com.lenovo.safecenter.HealthCheck;

/* JADX INFO: loaded from: classes.dex */
public interface HealthResultCallback {
    void onOneItemProcess(HealthItemResult healthItemResult);

    void result(HealthItemResult healthItemResult);
}
