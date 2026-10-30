package org.apache.commons.httpclient.methods;

import java.io.IOException;
import java.io.OutputStream;

/* JADX INFO: loaded from: classes.dex */
public interface RequestEntity {
    long getContentLength();

    String getContentType();

    boolean isRepeatable();

    void writeRequest(OutputStream outputStream) throws IOException;
}
