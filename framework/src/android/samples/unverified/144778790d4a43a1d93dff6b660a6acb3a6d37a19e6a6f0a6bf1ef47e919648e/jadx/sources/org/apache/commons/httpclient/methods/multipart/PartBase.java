package org.apache.commons.httpclient.methods.multipart;

/* JADX INFO: loaded from: classes.dex */
public abstract class PartBase extends Part {

    /* JADX INFO: renamed from: a */
    private String f6720a;

    /* JADX INFO: renamed from: c */
    private String f6721c;

    /* JADX INFO: renamed from: d */
    private String f6722d;

    /* JADX INFO: renamed from: e */
    private String f6723e;

    public PartBase(String name, String contentType, String charSet, String transferEncoding) {
        if (name == null) {
            throw new IllegalArgumentException("Name must not be null");
        }
        this.f6720a = name;
        this.f6721c = contentType;
        this.f6722d = charSet;
        this.f6723e = transferEncoding;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    public String getName() {
        return this.f6720a;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    public String getContentType() {
        return this.f6721c;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    public String getCharSet() {
        return this.f6722d;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    public String getTransferEncoding() {
        return this.f6723e;
    }

    public void setCharSet(String charSet) {
        this.f6722d = charSet;
    }

    public void setContentType(String contentType) {
        this.f6721c = contentType;
    }

    public void setName(String name) {
        if (name == null) {
            throw new IllegalArgumentException("Name must not be null");
        }
        this.f6720a = name;
    }

    public void setTransferEncoding(String transferEncoding) {
        this.f6723e = transferEncoding;
    }
}
