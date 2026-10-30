package org.apache.commons.httpclient.methods;

import java.io.IOException;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import org.apache.commons.httpclient.HeaderElement;
import org.apache.commons.httpclient.NameValuePair;

/* JADX INFO: loaded from: classes.dex */
public class StringRequestEntity implements RequestEntity {

    /* JADX INFO: renamed from: a */
    private byte[] f6700a;

    /* JADX INFO: renamed from: b */
    private String f6701b;

    /* JADX INFO: renamed from: c */
    private String f6702c;

    public StringRequestEntity(String content) {
        if (content == null) {
            throw new IllegalArgumentException("The content cannot be null");
        }
        this.f6702c = null;
        this.f6701b = null;
        this.f6700a = content.getBytes();
    }

    public StringRequestEntity(String content, String contentType, String charset) throws UnsupportedEncodingException {
        if (content == null) {
            throw new IllegalArgumentException("The content cannot be null");
        }
        this.f6702c = contentType;
        this.f6701b = charset;
        if (contentType != null) {
            HeaderElement[] values = HeaderElement.parseElements(contentType);
            NameValuePair charsetPair = null;
            for (int i = 0; i < values.length && (charsetPair = values[i].getParameterByName("charset")) == null; i++) {
            }
            if (charset == null && charsetPair != null) {
                this.f6701b = charsetPair.getValue();
            } else if (charset != null && charsetPair == null) {
                this.f6702c = new StringBuffer().append(contentType).append("; charset=").append(charset).toString();
            }
        }
        if (this.f6701b != null) {
            this.f6700a = content.getBytes(this.f6701b);
        } else {
            this.f6700a = content.getBytes();
        }
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public String getContentType() {
        return this.f6702c;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public boolean isRepeatable() {
        return true;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public void writeRequest(OutputStream out) throws IOException {
        if (out == null) {
            throw new IllegalArgumentException("Output stream may not be null");
        }
        out.write(this.f6700a);
        out.flush();
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public long getContentLength() {
        return this.f6700a.length;
    }

    public String getContent() {
        if (this.f6701b != null) {
            try {
                return new String(this.f6700a, this.f6701b);
            } catch (UnsupportedEncodingException e) {
                return new String(this.f6700a);
            }
        }
        return new String(this.f6700a);
    }

    public String getCharset() {
        return this.f6701b;
    }
}
