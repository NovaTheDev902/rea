package com.tencent.tccdb;

/* JADX INFO: loaded from: classes.dex */
public class SmsCheckerException extends RuntimeException {

    /* JADX INFO: renamed from: a */
    private int f6020a;

    public SmsCheckerException(int i) {
        super("SmsChecker error" + Integer.toString(i));
        this.f6020a = i;
    }

    public int getError() {
        return this.f6020a;
    }
}
