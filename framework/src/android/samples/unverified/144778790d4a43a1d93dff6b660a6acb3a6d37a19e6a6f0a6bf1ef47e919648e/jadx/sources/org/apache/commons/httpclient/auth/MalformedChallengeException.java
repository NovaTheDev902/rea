package org.apache.commons.httpclient.auth;

import org.apache.commons.httpclient.ProtocolException;

/* JADX INFO: loaded from: classes.dex */
public class MalformedChallengeException extends ProtocolException {
    public MalformedChallengeException() {
    }

    public MalformedChallengeException(String message) {
        super(message);
    }

    public MalformedChallengeException(String message, Throwable cause) {
        super(message, cause);
    }
}
