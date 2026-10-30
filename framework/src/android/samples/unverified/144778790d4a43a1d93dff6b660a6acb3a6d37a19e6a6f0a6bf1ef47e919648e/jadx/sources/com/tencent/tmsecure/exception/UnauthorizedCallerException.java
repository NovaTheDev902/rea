package com.tencent.tmsecure.exception;

/* JADX INFO: loaded from: classes.dex */
public class UnauthorizedCallerException extends SecurityException {

    /* JADX INFO: renamed from: a */
    public static final String f6056a = "The caller is not permitted";

    /* JADX INFO: renamed from: b */
    private static final long f6057b = 1155925875005750863L;

    public UnauthorizedCallerException() {
        this(f6056a);
    }

    public UnauthorizedCallerException(String str) {
        super(str);
    }

    public UnauthorizedCallerException(String str, Throwable th) {
        super(str, th);
    }
}
