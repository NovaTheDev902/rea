package org.apache.commons.httpclient.cookie;

import org.apache.commons.httpclient.ProtocolException;

/* JADX INFO: loaded from: classes.dex */
public class MalformedCookieException extends ProtocolException {
    public MalformedCookieException() {
    }

    public MalformedCookieException(String message) {
        super(message);
    }

    public MalformedCookieException(String message, Throwable cause) {
        super(message, cause);
    }
}
