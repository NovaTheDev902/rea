package org.apache.commons.httpclient;

/* JADX INFO: loaded from: classes.dex */
public class InvalidRedirectLocationException extends RedirectException {

    /* JADX INFO: renamed from: b */
    private final String f6518b;

    public InvalidRedirectLocationException(String message, String location) {
        super(message);
        this.f6518b = location;
    }

    public InvalidRedirectLocationException(String message, String location, Throwable cause) {
        super(message, cause);
        this.f6518b = location;
    }

    public String getLocation() {
        return this.f6518b;
    }
}
