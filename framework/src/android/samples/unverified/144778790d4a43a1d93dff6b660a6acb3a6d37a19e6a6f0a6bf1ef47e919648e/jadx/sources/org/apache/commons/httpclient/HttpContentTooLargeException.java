package org.apache.commons.httpclient;

/* JADX INFO: loaded from: classes.dex */
public class HttpContentTooLargeException extends HttpException {

    /* JADX INFO: renamed from: b */
    private int f6478b;

    public HttpContentTooLargeException(String message, int maxlen) {
        super(message);
        this.f6478b = maxlen;
    }

    public int getMaxLength() {
        return this.f6478b;
    }
}
