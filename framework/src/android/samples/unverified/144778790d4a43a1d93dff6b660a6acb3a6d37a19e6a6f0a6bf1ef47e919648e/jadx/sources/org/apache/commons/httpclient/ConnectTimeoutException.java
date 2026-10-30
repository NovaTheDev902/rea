package org.apache.commons.httpclient;

import java.io.InterruptedIOException;
import org.apache.commons.httpclient.util.ExceptionUtil;

/* JADX INFO: loaded from: classes.dex */
public class ConnectTimeoutException extends InterruptedIOException {
    public ConnectTimeoutException() {
    }

    public ConnectTimeoutException(String message) {
        super(message);
    }

    public ConnectTimeoutException(String message, Throwable cause) {
        super(message);
        ExceptionUtil.initCause(this, cause);
    }
}
