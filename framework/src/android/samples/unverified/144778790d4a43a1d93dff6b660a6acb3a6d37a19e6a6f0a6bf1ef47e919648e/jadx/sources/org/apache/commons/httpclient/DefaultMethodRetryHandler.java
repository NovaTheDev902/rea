package org.apache.commons.httpclient;

/* JADX INFO: loaded from: classes.dex */
public class DefaultMethodRetryHandler implements MethodRetryHandler {

    /* JADX INFO: renamed from: a */
    private int f6441a = 3;

    /* JADX INFO: renamed from: b */
    private boolean f6442b = false;

    @Override // org.apache.commons.httpclient.MethodRetryHandler
    public boolean retryMethod(HttpMethod method, HttpConnection connection, HttpRecoverableException recoverableException, int executionCount, boolean requestSent) {
        return (!requestSent || this.f6442b) && executionCount <= this.f6441a;
    }

    public boolean isRequestSentRetryEnabled() {
        return this.f6442b;
    }

    public int getRetryCount() {
        return this.f6441a;
    }

    public void setRequestSentRetryEnabled(boolean requestSentRetryEnabled) {
        this.f6442b = requestSentRetryEnabled;
    }

    public void setRetryCount(int retryCount) {
        this.f6441a = retryCount;
    }
}
