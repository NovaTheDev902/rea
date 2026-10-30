package com.tencent.tccdb;

/* JADX INFO: loaded from: classes.dex */
public class TelNumberLocatorException extends RuntimeException {

    /* JADX INFO: renamed from: a */
    private int f6024a;

    public TelNumberLocatorException(int i) {
        super("TelNumberLocator error" + Integer.toString(i));
        this.f6024a = i;
    }

    public int getError() {
        return this.f6024a;
    }
}
