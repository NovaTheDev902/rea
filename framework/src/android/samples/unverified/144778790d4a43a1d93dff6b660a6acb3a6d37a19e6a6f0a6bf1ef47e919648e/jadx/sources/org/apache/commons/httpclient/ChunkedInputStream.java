package org.apache.commons.httpclient;

import com.tencent.tmsecure.module.wupsession.WupConfig;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.httpclient.util.ExceptionUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class ChunkedInputStream extends InputStream {

    /* JADX INFO: renamed from: a */
    static Class f6405a;

    /* JADX INFO: renamed from: i */
    private static final Log f6406i;

    /* JADX INFO: renamed from: b */
    private InputStream f6407b;

    /* JADX INFO: renamed from: c */
    private int f6408c;

    /* JADX INFO: renamed from: d */
    private int f6409d;

    /* JADX INFO: renamed from: e */
    private boolean f6410e;

    /* JADX INFO: renamed from: f */
    private boolean f6411f;

    /* JADX INFO: renamed from: g */
    private boolean f6412g;

    /* JADX INFO: renamed from: h */
    private HttpMethod f6413h;

    static {
        Class clsM2697a;
        if (f6405a == null) {
            clsM2697a = m2697a("org.apache.commons.httpclient.ChunkedInputStream");
            f6405a = clsM2697a;
        } else {
            clsM2697a = f6405a;
        }
        f6406i = LogFactory.getLog(clsM2697a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2697a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public ChunkedInputStream(InputStream in, HttpMethod method) throws IOException {
        this.f6410e = true;
        this.f6411f = false;
        this.f6412g = false;
        this.f6413h = null;
        if (in == null) {
            throw new IllegalArgumentException("InputStream parameter may not be null");
        }
        this.f6407b = in;
        this.f6413h = method;
        this.f6409d = 0;
    }

    public ChunkedInputStream(InputStream in) throws IOException {
        this(in, null);
    }

    @Override // java.io.InputStream
    public int read() throws IOException {
        if (this.f6412g) {
            throw new IOException("Attempted read from closed stream.");
        }
        if (this.f6411f) {
            return -1;
        }
        if (this.f6409d >= this.f6408c) {
            m2698a();
            if (this.f6411f) {
                return -1;
            }
        }
        this.f6409d++;
        return this.f6407b.read();
    }

    @Override // java.io.InputStream
    public int read(byte[] b, int off, int len) throws IOException {
        if (this.f6412g) {
            throw new IOException("Attempted read from closed stream.");
        }
        if (this.f6411f) {
            return -1;
        }
        if (this.f6409d >= this.f6408c) {
            m2698a();
            if (this.f6411f) {
                return -1;
            }
        }
        int count = this.f6407b.read(b, off, Math.min(len, this.f6408c - this.f6409d));
        this.f6409d += count;
        return count;
    }

    @Override // java.io.InputStream
    public int read(byte[] b) throws IOException {
        return read(b, 0, b.length);
    }

    /* JADX INFO: renamed from: a */
    private void m2698a() throws IOException {
        if (!this.f6410e) {
            int i = this.f6407b.read();
            int i2 = this.f6407b.read();
            if (i != 13 || i2 != 10) {
                throw new IOException(new StringBuffer().append("CRLF expected at end of chunk: ").append(i).append(CookieSpec.PATH_DELIM).append(i2).toString());
            }
        }
        this.f6408c = m2700b(this.f6407b);
        this.f6410e = false;
        this.f6409d = 0;
        if (this.f6408c == 0) {
            this.f6411f = true;
            m2701b();
        }
    }

    /* JADX INFO: renamed from: b */
    private static int m2700b(InputStream in) throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        int state = 0;
        while (state != -1) {
            int b = in.read();
            if (b == -1) {
                throw new IOException("chunked stream ended unexpectedly");
            }
            switch (state) {
                case 0:
                    switch (b) {
                        case 13:
                            state = 1;
                            continue;
                        case WupConfig.RQ_GET_TRAFFIC_CMD /* 34 */:
                            state = 2;
                            break;
                    }
                    baos.write(b);
                    break;
                case 1:
                    if (b == 10) {
                        state = -1;
                    } else {
                        throw new IOException("Protocol violation: Unexpected single newline character in chunk size");
                    }
                    break;
                case 2:
                    switch (b) {
                        case WupConfig.RQ_GET_TRAFFIC_CMD /* 34 */:
                            state = 0;
                            break;
                        case 92:
                            baos.write(in.read());
                            continue;
                    }
                    baos.write(b);
                    break;
                default:
                    throw new RuntimeException("assertion failed");
            }
        }
        String dataString = EncodingUtil.getAsciiString(baos.toByteArray());
        int separator = dataString.indexOf(59);
        String dataString2 = separator > 0 ? dataString.substring(0, separator).trim() : dataString.trim();
        try {
            int result = Integer.parseInt(dataString2.trim(), 16);
            return result;
        } catch (NumberFormatException e) {
            throw new IOException(new StringBuffer().append("Bad chunk size: ").append(dataString2).toString());
        }
    }

    /* JADX INFO: renamed from: b */
    private void m2701b() throws IOException {
        try {
            String charset = "US-ASCII";
            if (this.f6413h != null) {
                charset = this.f6413h.getParams().getHttpElementCharset();
            }
            Header[] footers = HttpParser.parseHeaders(this.f6407b, charset);
            if (this.f6413h != null) {
                for (Header header : footers) {
                    this.f6413h.addResponseFooter(header);
                }
            }
        } catch (HttpException e) {
            f6406i.error("Error parsing trailer headers", e);
            IOException ioe = new IOException(e.getMessage());
            ExceptionUtil.initCause(ioe, e);
            throw ioe;
        }
    }

    @Override // java.io.InputStream, java.io.Closeable, java.lang.AutoCloseable
    public void close() throws IOException {
        if (!this.f6412g) {
            try {
                if (!this.f6411f) {
                    m2699a(this);
                }
            } finally {
                this.f6411f = true;
                this.f6412g = true;
            }
        }
    }

    /* JADX INFO: renamed from: a */
    static void m2699a(InputStream inStream) throws IOException {
        byte[] buffer = new byte[1024];
        while (inStream.read(buffer) >= 0) {
        }
    }
}
