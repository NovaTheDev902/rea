package org.apache.commons.httpclient.methods.multipart;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public class ByteArrayPartSource implements PartSource {

    /* JADX INFO: renamed from: a */
    private String f6703a;

    /* JADX INFO: renamed from: b */
    private byte[] f6704b;

    public ByteArrayPartSource(String fileName, byte[] bytes) {
        this.f6703a = fileName;
        this.f6704b = bytes;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.PartSource
    public long getLength() {
        return this.f6704b.length;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.PartSource
    public String getFileName() {
        return this.f6703a;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.PartSource
    public InputStream createInputStream() throws IOException {
        return new ByteArrayInputStream(this.f6704b);
    }
}
