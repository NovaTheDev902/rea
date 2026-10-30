package org.apache.commons.httpclient.methods.multipart;

import java.io.IOException;
import java.io.OutputStream;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class StringPart extends PartBase {
    public static final String DEFAULT_CHARSET = "US-ASCII";
    public static final String DEFAULT_CONTENT_TYPE = "text/plain";
    public static final String DEFAULT_TRANSFER_ENCODING = "8bit";

    /* JADX INFO: renamed from: a */
    static Class f6724a;

    /* JADX INFO: renamed from: c */
    private static final Log f6725c;

    /* JADX INFO: renamed from: d */
    private byte[] f6726d;

    /* JADX INFO: renamed from: e */
    private String f6727e;

    static {
        Class clsM2832a;
        if (f6724a == null) {
            clsM2832a = m2832a("org.apache.commons.httpclient.methods.multipart.StringPart");
            f6724a = clsM2832a;
        } else {
            clsM2832a = f6724a;
        }
        f6725c = LogFactory.getLog(clsM2832a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2832a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public StringPart(String name, String value, String charset) {
        super(name, "text/plain", charset == null ? "US-ASCII" : charset, "8bit");
        if (value == null) {
            throw new IllegalArgumentException("Value may not be null");
        }
        if (value.indexOf(0) != -1) {
            throw new IllegalArgumentException("NULs may not be present in string parts");
        }
        this.f6727e = value;
    }

    public StringPart(String name, String value) {
        this(name, value, null);
    }

    /* JADX INFO: renamed from: a */
    private byte[] m2833a() {
        if (this.f6726d == null) {
            this.f6726d = EncodingUtil.getBytes(this.f6727e, getCharSet());
        }
        return this.f6726d;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    protected void sendData(OutputStream out) throws IOException {
        f6725c.trace("enter sendData(OutputStream)");
        out.write(m2833a());
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    protected long lengthOfData() throws IOException {
        f6725c.trace("enter lengthOfData()");
        return m2833a().length;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.PartBase
    public void setCharSet(String charSet) {
        super.setCharSet(charSet);
        this.f6726d = null;
    }
}
