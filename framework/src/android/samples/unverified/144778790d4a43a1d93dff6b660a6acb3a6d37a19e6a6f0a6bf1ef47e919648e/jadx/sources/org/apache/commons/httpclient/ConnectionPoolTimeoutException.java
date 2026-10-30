package org.apache.commons.httpclient;

/* JADX INFO: loaded from: classes.dex */
public class ConnectionPoolTimeoutException extends ConnectTimeoutException {
    public ConnectionPoolTimeoutException() {
    }

    public ConnectionPoolTimeoutException(String message) {
        super(message);
    }

    public ConnectionPoolTimeoutException(String message, Throwable cause) {
        super(message, cause);
    }
}
