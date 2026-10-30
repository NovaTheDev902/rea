package org.apache.commons.httpclient.auth;

/* JADX INFO: loaded from: classes.dex */
public class InvalidCredentialsException extends AuthenticationException {
    public InvalidCredentialsException() {
    }

    public InvalidCredentialsException(String message) {
        super(message);
    }

    public InvalidCredentialsException(String message, Throwable cause) {
        super(message, cause);
    }
}
