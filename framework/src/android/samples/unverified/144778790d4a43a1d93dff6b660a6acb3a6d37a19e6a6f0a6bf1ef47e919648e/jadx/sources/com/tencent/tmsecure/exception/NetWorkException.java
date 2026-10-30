package com.tencent.tmsecure.exception;

/* JADX INFO: loaded from: classes.dex */
public class NetWorkException extends Exception {

    /* JADX INFO: renamed from: a */
    private static final long f6050a = 1;

    /* JADX INFO: renamed from: b */
    private int f6051b;

    public NetWorkException(int i, String str) {
        super(str);
        this.f6051b = i;
    }

    public NetWorkException(int i, String str, Throwable th) {
        super(str, th);
        this.f6051b = i;
    }

    public NetWorkException(int i, Throwable th) {
        super(th.getMessage(), th);
        this.f6051b = i;
    }

    public int getErrCode() {
        return this.f6051b;
    }

    public String getErrMsg() {
        Throwable cause;
        String message = getMessage();
        if (message == null && (cause = getCause()) != null) {
            message = cause.getMessage();
        }
        return message != null ? message : "";
    }
}
