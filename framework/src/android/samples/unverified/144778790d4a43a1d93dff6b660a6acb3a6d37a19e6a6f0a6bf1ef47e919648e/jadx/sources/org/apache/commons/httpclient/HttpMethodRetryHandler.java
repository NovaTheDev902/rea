package org.apache.commons.httpclient;

import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public interface HttpMethodRetryHandler {
    boolean retryMethod(HttpMethod httpMethod, IOException iOException, int i);
}
