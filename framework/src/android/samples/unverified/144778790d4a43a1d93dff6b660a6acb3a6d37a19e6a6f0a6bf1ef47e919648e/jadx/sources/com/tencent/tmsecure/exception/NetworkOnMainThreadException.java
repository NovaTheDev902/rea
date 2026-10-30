package com.tencent.tmsecure.exception;

/* JADX INFO: loaded from: classes.dex */
public class NetworkOnMainThreadException extends RuntimeException {

    /* JADX INFO: renamed from: a */
    private static final long f6052a = 7308789257160725333L;

    /* JADX INFO: renamed from: b */
    private static final String f6053b = "Network cannot run on main thread if the targetSDKVersion is over 9 please make sure not to invoke network relevant methods on the main thread or change the manifest targetSDKVersion to be under 10";

    public NetworkOnMainThreadException() {
        super(f6053b);
    }

    public NetworkOnMainThreadException(String str) {
        super(str);
    }
}
