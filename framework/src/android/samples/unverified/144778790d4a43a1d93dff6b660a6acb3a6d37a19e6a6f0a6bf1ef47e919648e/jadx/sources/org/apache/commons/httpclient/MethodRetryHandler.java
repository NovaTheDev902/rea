package org.apache.commons.httpclient;

/* JADX INFO: loaded from: classes.dex */
public interface MethodRetryHandler {
    boolean retryMethod(HttpMethod httpMethod, HttpConnection httpConnection, HttpRecoverableException httpRecoverableException, int i, boolean z);
}
