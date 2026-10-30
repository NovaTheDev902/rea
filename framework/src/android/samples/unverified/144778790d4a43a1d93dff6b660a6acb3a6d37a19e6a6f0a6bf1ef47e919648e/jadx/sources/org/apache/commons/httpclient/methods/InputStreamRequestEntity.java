package org.apache.commons.httpclient.methods;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class InputStreamRequestEntity implements RequestEntity {
    public static final int CONTENT_LENGTH_AUTO = -2;

    /* JADX INFO: renamed from: a */
    static Class f6685a;

    /* JADX INFO: renamed from: b */
    private static final Log f6686b;

    /* JADX INFO: renamed from: c */
    private long f6687c;

    /* JADX INFO: renamed from: d */
    private InputStream f6688d;

    /* JADX INFO: renamed from: e */
    private byte[] f6689e;

    /* JADX INFO: renamed from: f */
    private String f6690f;

    static {
        Class clsM2825a;
        if (f6685a == null) {
            clsM2825a = m2825a("org.apache.commons.httpclient.methods.InputStreamRequestEntity");
            f6685a = clsM2825a;
        } else {
            clsM2825a = f6685a;
        }
        f6686b = LogFactory.getLog(clsM2825a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2825a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public InputStreamRequestEntity(InputStream content) {
        this(content, (String) null);
    }

    public InputStreamRequestEntity(InputStream content, String contentType) {
        this(content, -2L, contentType);
    }

    public InputStreamRequestEntity(InputStream content, long contentLength) {
        this(content, contentLength, null);
    }

    public InputStreamRequestEntity(InputStream content, long contentLength, String contentType) {
        this.f6689e = null;
        if (content == null) {
            throw new IllegalArgumentException("The content cannot be null");
        }
        this.f6688d = content;
        this.f6687c = contentLength;
        this.f6690f = contentType;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public String getContentType() {
        return this.f6690f;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public boolean isRepeatable() {
        return this.f6689e != null;
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public void writeRequest(OutputStream out) throws IOException {
        if (this.f6688d != null) {
            byte[] tmp = new byte[4096];
            while (true) {
                int i = this.f6688d.read(tmp);
                if (i >= 0) {
                    out.write(tmp, 0, i);
                } else {
                    return;
                }
            }
        } else {
            if (this.f6689e != null) {
                out.write(this.f6689e);
                return;
            }
            throw new IllegalStateException("Content must be set before entity is written");
        }
    }

    @Override // org.apache.commons.httpclient.methods.RequestEntity
    public long getContentLength() {
        if (this.f6687c == -2 && this.f6689e == null && this.f6689e == null && this.f6688d != null) {
            try {
                ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();
                byte[] bArr = new byte[4096];
                while (true) {
                    int i = this.f6688d.read(bArr);
                    if (i < 0) {
                        break;
                    }
                    byteArrayOutputStream.write(bArr, 0, i);
                }
                this.f6689e = byteArrayOutputStream.toByteArray();
                this.f6688d = null;
                this.f6687c = this.f6689e.length;
            } catch (IOException e) {
                f6686b.error(e.getMessage(), e);
                this.f6689e = null;
                this.f6688d = null;
                this.f6687c = 0L;
            }
        }
        return this.f6687c;
    }

    public InputStream getContent() {
        return this.f6688d;
    }
}
