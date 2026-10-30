package com.tencent.tmsecure.exception;

/* JADX INFO: loaded from: classes.dex */
public class NotInitializedException extends Exception {

    /* JADX INFO: renamed from: a */
    private static final long f6054a = 1;

    @Override // java.lang.Throwable
    public String getMessage() {
        return "没有完成初始化配置";
    }
}
