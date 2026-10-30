package com.tencent.tmsecure.common;

/* JADX INFO: loaded from: classes.dex */
public interface MessageHandler {
    boolean isMatch(int i);

    DataEntity onProcessing(DataEntity dataEntity);
}
