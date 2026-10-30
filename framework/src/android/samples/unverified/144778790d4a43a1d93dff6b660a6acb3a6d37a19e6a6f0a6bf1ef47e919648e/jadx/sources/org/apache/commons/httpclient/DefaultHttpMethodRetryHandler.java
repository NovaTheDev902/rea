package org.apache.commons.httpclient;

import java.io.IOException;
import java.io.InterruptedIOException;
import java.net.NoRouteToHostException;
import java.net.UnknownHostException;

/* JADX INFO: loaded from: classes.dex */
public class DefaultHttpMethodRetryHandler implements HttpMethodRetryHandler {

    /* JADX INFO: renamed from: a */
    private static Class f6438a;

    /* JADX INFO: renamed from: b */
    private int f6439b;

    /* JADX INFO: renamed from: c */
    private boolean f6440c;

    static {
        f6438a = null;
        try {
            f6438a = Class.forName("javax.net.ssl.SSLHandshakeException");
        } catch (ClassNotFoundException e) {
        }
    }

    public DefaultHttpMethodRetryHandler(int retryCount, boolean requestSentRetryEnabled) {
        this.f6439b = retryCount;
        this.f6440c = requestSentRetryEnabled;
    }

    public DefaultHttpMethodRetryHandler() {
        this(3, false);
    }

    @Override // org.apache.commons.httpclient.HttpMethodRetryHandler
    public boolean retryMethod(HttpMethod method, IOException exception, int executionCount) {
        if (method == null) {
            throw new IllegalArgumentException("HTTP method may not be null");
        }
        if (exception == null) {
            throw new IllegalArgumentException("Exception parameter may not be null");
        }
        if ((!(method instanceof HttpMethodBase) || !((HttpMethodBase) method).isAborted()) && executionCount <= this.f6439b) {
            if (exception instanceof NoHttpResponseException) {
                return true;
            }
            if (!(exception instanceof InterruptedIOException) && !(exception instanceof UnknownHostException) && !(exception instanceof NoRouteToHostException)) {
                if (f6438a == null || !f6438a.isInstance(exception)) {
                    return !method.isRequestSent() || this.f6440c;
                }
                return false;
            }
            return false;
        }
        return false;
    }

    public boolean isRequestSentRetryEnabled() {
        return this.f6440c;
    }

    public int getRetryCount() {
        return this.f6439b;
    }
}
