package org.apache.commons.httpclient.methods;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import org.apache.commons.httpclient.ChunkedOutputStream;
import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpConnection;
import org.apache.commons.httpclient.HttpState;
import org.apache.commons.httpclient.HttpVersion;
import org.apache.commons.httpclient.ProtocolException;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public abstract class EntityEnclosingMethod extends ExpectContinueMethod {
    public static final long CONTENT_LENGTH_AUTO = -2;
    public static final long CONTENT_LENGTH_CHUNKED = -1;

    /* JADX INFO: renamed from: a */
    static Class f6669a;

    /* JADX INFO: renamed from: d */
    private static final Log f6670d;

    /* JADX INFO: renamed from: e */
    private InputStream f6671e;

    /* JADX INFO: renamed from: f */
    private String f6672f;

    /* JADX INFO: renamed from: g */
    private RequestEntity f6673g;

    /* JADX INFO: renamed from: h */
    private int f6674h;

    /* JADX INFO: renamed from: i */
    private long f6675i;

    /* JADX INFO: renamed from: j */
    private boolean f6676j;

    static {
        Class clsM2821a;
        if (f6669a == null) {
            clsM2821a = m2821a("org.apache.commons.httpclient.methods.EntityEnclosingMethod");
            f6669a = clsM2821a;
        } else {
            clsM2821a = f6669a;
        }
        f6670d = LogFactory.getLog(clsM2821a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2821a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public EntityEnclosingMethod() {
        this.f6671e = null;
        this.f6672f = null;
        this.f6674h = 0;
        this.f6675i = -2L;
        this.f6676j = false;
        setFollowRedirects(false);
    }

    public EntityEnclosingMethod(String uri) {
        super(uri);
        this.f6671e = null;
        this.f6672f = null;
        this.f6674h = 0;
        this.f6675i = -2L;
        this.f6676j = false;
        setFollowRedirects(false);
    }

    @Override // org.apache.commons.httpclient.methods.ExpectContinueMethod
    protected boolean hasRequestContent() {
        f6670d.trace("enter EntityEnclosingMethod.hasRequestContent()");
        return (this.f6673g == null && this.f6671e == null && this.f6672f == null) ? false : true;
    }

    protected void clearRequestBody() {
        f6670d.trace("enter EntityEnclosingMethod.clearRequestBody()");
        this.f6671e = null;
        this.f6672f = null;
        this.f6673g = null;
    }

    protected byte[] generateRequestBody() {
        f6670d.trace("enter EntityEnclosingMethod.renerateRequestBody()");
        return null;
    }

    protected RequestEntity generateRequestEntity() {
        byte[] requestBody = generateRequestBody();
        if (requestBody != null) {
            this.f6673g = new ByteArrayRequestEntity(requestBody);
        } else if (this.f6671e != null) {
            this.f6673g = new InputStreamRequestEntity(this.f6671e, this.f6675i);
            this.f6671e = null;
        } else if (this.f6672f != null) {
            String charset = getRequestCharSet();
            try {
                this.f6673g = new StringRequestEntity(this.f6672f, null, charset);
            } catch (UnsupportedEncodingException e) {
                if (f6670d.isWarnEnabled()) {
                    f6670d.warn(new StringBuffer().append(charset).append(" not supported").toString());
                }
                try {
                    this.f6673g = new StringRequestEntity(this.f6672f, null, null);
                } catch (UnsupportedEncodingException e2) {
                }
            }
        }
        return this.f6673g;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public boolean getFollowRedirects() {
        return false;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public void setFollowRedirects(boolean followRedirects) {
        if (followRedirects) {
            throw new IllegalArgumentException("Entity enclosing requests cannot be redirected without user intervention");
        }
        super.setFollowRedirects(false);
    }

    public void setRequestContentLength(int length) {
        f6670d.trace("enter EntityEnclosingMethod.setRequestContentLength(int)");
        this.f6675i = length;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    public String getRequestCharSet() {
        if (getRequestHeader("Content-Type") == null) {
            if (this.f6673g != null) {
                return getContentCharSet(new Header("Content-Type", this.f6673g.getContentType()));
            }
            return super.getRequestCharSet();
        }
        return super.getRequestCharSet();
    }

    public void setRequestContentLength(long length) {
        f6670d.trace("enter EntityEnclosingMethod.setRequestContentLength(int)");
        this.f6675i = length;
    }

    public void setContentChunked(boolean chunked) {
        this.f6676j = chunked;
    }

    protected long getRequestContentLength() {
        f6670d.trace("enter EntityEnclosingMethod.getRequestContentLength()");
        if (!hasRequestContent()) {
            return 0L;
        }
        if (this.f6676j) {
            return -1L;
        }
        if (this.f6673g == null) {
            this.f6673g = generateRequestEntity();
        }
        if (this.f6673g != null) {
            return this.f6673g.getContentLength();
        }
        return 0L;
    }

    @Override // org.apache.commons.httpclient.methods.ExpectContinueMethod, org.apache.commons.httpclient.HttpMethodBase
    protected void addRequestHeaders(HttpState state, HttpConnection conn) throws IOException {
        RequestEntity requestEntity;
        f6670d.trace("enter EntityEnclosingMethod.addRequestHeaders(HttpState, HttpConnection)");
        super.addRequestHeaders(state, conn);
        addContentLengthRequestHeader(state, conn);
        if (getRequestHeader("Content-Type") == null && (requestEntity = getRequestEntity()) != null && requestEntity.getContentType() != null) {
            setRequestHeader("Content-Type", requestEntity.getContentType());
        }
    }

    protected void addContentLengthRequestHeader(HttpState state, HttpConnection conn) throws IOException {
        f6670d.trace("enter EntityEnclosingMethod.addContentLengthRequestHeader(HttpState, HttpConnection)");
        if (getRequestHeader("content-length") == null && getRequestHeader("Transfer-Encoding") == null) {
            long len = getRequestContentLength();
            if (len < 0) {
                if (getEffectiveVersion().greaterEquals(HttpVersion.HTTP_1_1)) {
                    addRequestHeader("Transfer-Encoding", "chunked");
                    return;
                }
                throw new ProtocolException(new StringBuffer().append(getEffectiveVersion()).append(" does not support chunk encoding").toString());
            }
            addRequestHeader("Content-Length", String.valueOf(len));
        }
    }

    public void setRequestBody(InputStream body) {
        f6670d.trace("enter EntityEnclosingMethod.setRequestBody(InputStream)");
        clearRequestBody();
        this.f6671e = body;
    }

    public void setRequestBody(String body) {
        f6670d.trace("enter EntityEnclosingMethod.setRequestBody(String)");
        clearRequestBody();
        this.f6672f = body;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected boolean writeRequestBody(HttpState state, HttpConnection conn) throws IOException {
        f6670d.trace("enter EntityEnclosingMethod.writeRequestBody(HttpState, HttpConnection)");
        if (!hasRequestContent()) {
            f6670d.debug("Request body has not been specified");
        } else {
            if (this.f6673g == null) {
                this.f6673g = generateRequestEntity();
            }
            if (this.f6673g == null) {
                f6670d.debug("Request body is empty");
            } else {
                long contentLength = getRequestContentLength();
                if (this.f6674h > 0 && !this.f6673g.isRepeatable()) {
                    throw new ProtocolException("Unbuffered entity enclosing request can not be repeated.");
                }
                this.f6674h++;
                OutputStream outstream = conn.getRequestOutputStream();
                if (contentLength < 0) {
                    outstream = new ChunkedOutputStream(outstream);
                }
                this.f6673g.writeRequest(outstream);
                if (outstream instanceof ChunkedOutputStream) {
                    ((ChunkedOutputStream) outstream).finish();
                }
                outstream.flush();
                f6670d.debug("Request body sent");
            }
        }
        return true;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public void recycle() {
        f6670d.trace("enter EntityEnclosingMethod.recycle()");
        clearRequestBody();
        this.f6675i = -2L;
        this.f6674h = 0;
        this.f6676j = false;
        super.recycle();
    }

    public RequestEntity getRequestEntity() {
        return generateRequestEntity();
    }

    public void setRequestEntity(RequestEntity requestEntity) {
        clearRequestBody();
        this.f6673g = requestEntity;
    }
}
