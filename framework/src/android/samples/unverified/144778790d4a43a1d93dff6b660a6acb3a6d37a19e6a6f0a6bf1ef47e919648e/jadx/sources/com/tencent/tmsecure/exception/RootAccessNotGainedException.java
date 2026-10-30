package com.tencent.tmsecure.exception;

/* JADX INFO: loaded from: classes.dex */
public class RootAccessNotGainedException extends RuntimeException {

    /* JADX INFO: renamed from: a */
    private static final long f6055a = 1;

    @Override // java.lang.Throwable
    public String getMessage() {
        return "Root permission is not granted!";
    }
}
