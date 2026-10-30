package org.apache.commons.httpclient.methods;

import java.io.IOException;
import java.io.OutputStream;

/* JADX INFO: loaded from: classes.dex */
public class ByteArrayRequestEntity implements RequestEntity {

    /* JADX INFO: renamed from: a */
    private byte[] f6667a;

    /* JADX INFO: renamed from: b */
    private String f6668b;

    public ByteArrayRequestEntity(byte[] content) {
        this(content, null);
    }

    public ByteArrayRequestEntity(byte[] content, String contentType) {
        if (content == null) {
            throw new IllegalArgumentException("The content cannot be null");
        }
        this.f6667a = content;
        this.f6668b = contentType;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public boolean isRepeatable() {
        return true;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public String getContentType() {
        return this.f6668b;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public void writeRequest(OutputStream out) throws IOException {
        out.write(this.f6667a);
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public long getContentLength() {
        return this.f6667a.length;
    }

    public byte[] getContent() {
        return this.f6667a;
    }
}
