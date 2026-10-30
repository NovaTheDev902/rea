package org.apache.commons.httpclient.methods.multipart;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Random;
import org.apache.commons.httpclient.methods.MultipartPostMethod;
import org.apache.commons.httpclient.methods.RequestEntity;
import org.apache.commons.httpclient.params.HttpMethodParams;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class MultipartRequestEntity implements RequestEntity {

    /* JADX INFO: renamed from: a */
    static Class f6711a;

    /* JADX INFO: renamed from: b */
    private static final Log f6712b;

    /* JADX INFO: renamed from: c */
    private static byte[] f6713c;

    /* JADX INFO: renamed from: d */
    private byte[] f6714d;

    /* JADX INFO: renamed from: e */
    private HttpMethodParams f6715e;
    protected Part[] parts;

    static {
        Class clsM2830a;
        if (f6711a == null) {
            clsM2830a = m2830a("org.apache.commons.httpclient.methods.multipart.MultipartRequestEntity");
            f6711a = clsM2830a;
        } else {
            clsM2830a = f6711a;
        }
        f6712b = LogFactory.getLog(clsM2830a);
        f6713c = EncodingUtil.getAsciiBytes("-_1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    }

    /* JADX INFO: renamed from: a */
    private static Class m2830a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public MultipartRequestEntity(Part[] parts, HttpMethodParams params) {
        if (parts == null) {
            throw new IllegalArgumentException("parts cannot be null");
        }
        if (params == null) {
            throw new IllegalArgumentException("params cannot be null");
        }
        this.parts = parts;
        this.f6715e = params;
    }

    protected byte[] getMultipartBoundary() {
        if (this.f6714d == null) {
            String temp = (String) this.f6715e.getParameter(HttpMethodParams.MULTIPART_BOUNDARY);
            if (temp != null) {
                this.f6714d = EncodingUtil.getAsciiBytes(temp);
            } else {
                Random random = new Random();
                byte[] bArr = new byte[random.nextInt(11) + 30];
                for (int i = 0; i < bArr.length; i++) {
                    bArr[i] = f6713c[random.nextInt(f6713c.length)];
                }
                this.f6714d = bArr;
            }
        }
        return this.f6714d;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public boolean isRepeatable() {
        for (int i = 0; i < this.parts.length; i++) {
            if (!this.parts[i].isRepeatable()) {
                return false;
            }
        }
        return true;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public void writeRequest(OutputStream out) throws IOException {
        Part.sendParts(out, this.parts, getMultipartBoundary());
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public long getContentLength() {
        try {
            return Part.getLengthOfParts(this.parts, getMultipartBoundary());
        } catch (Exception e) {
            f6712b.error("An exception occurred while getting the length of the parts", e);
            return 0L;
        }
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public String getContentType() {
        StringBuffer buffer = new StringBuffer(MultipartPostMethod.MULTIPART_FORM_CONTENT_TYPE);
        buffer.append("; boundary=");
        buffer.append(EncodingUtil.getAsciiString(getMultipartBoundary()));
        return buffer.toString();
    }
}
