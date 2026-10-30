package org.apache.commons.httpclient;

import java.io.IOException;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class ConnectMethod extends HttpMethodBase {
    public static final String NAME = "CONNECT";

    /* JADX INFO: renamed from: a */
    static Class f6421a;

    /* JADX INFO: renamed from: d */
    private static final Log f6422d;

    /* JADX INFO: renamed from: c */
    private final HostConfiguration f6423c;

    public ConnectMethod() {
        this.f6423c = null;
    }

    public ConnectMethod(HttpMethod method) {
        this.f6423c = null;
    }

    public ConnectMethod(HostConfiguration targethost) {
        if (targethost == null) {
            throw new IllegalArgumentException("Target host may not be null");
        }
        this.f6423c = targethost;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getName() {
        return NAME;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public String getPath() {
        if (this.f6423c == null) {
            return CookieSpec.PATH_DELIM;
        }
        StringBuffer buffer = new StringBuffer();
        buffer.append(this.f6423c.getHost());
        int port = this.f6423c.getPort();
        if (port == -1) {
            port = this.f6423c.getProtocol().getDefaultPort();
        }
        buffer.append(':');
        buffer.append(port);
        return buffer.toString();
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public URI getURI() throws URIException {
        String charset = getParams().getUriCharset();
        return new URI(getPath(), true, charset);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected void addCookieRequestHeader(HttpState state, HttpConnection conn) throws IOException {
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected void addRequestHeaders(HttpState state, HttpConnection conn) throws IOException {
        f6422d.trace("enter ConnectMethod.addRequestHeaders(HttpState, HttpConnection)");
        addUserAgentRequestHeader(state, conn);
        addHostRequestHeader(state, conn);
        addProxyConnectionHeader(state, conn);
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase, org.apache.commons.httpclient.HttpMethod
    public int execute(HttpState state, HttpConnection conn) throws IOException {
        f6422d.trace("enter ConnectMethod.execute(HttpState, HttpConnection)");
        int code = super.execute(state, conn);
        if (f6422d.isDebugEnabled()) {
            f6422d.debug(new StringBuffer().append("CONNECT status code ").append(code).toString());
        }
        return code;
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected void writeRequestLine(HttpState state, HttpConnection conn) throws IOException {
        StringBuffer buffer = new StringBuffer();
        buffer.append(getName());
        buffer.append(' ');
        if (this.f6423c != null) {
            buffer.append(getPath());
        } else {
            int port = conn.getPort();
            if (port == -1) {
                port = conn.getProtocol().getDefaultPort();
            }
            buffer.append(conn.getHost());
            buffer.append(':');
            buffer.append(port);
        }
        buffer.append(" ");
        buffer.append(getEffectiveVersion());
        String line = buffer.toString();
        conn.printLine(line, getParams().getHttpElementCharset());
        if (C1131e.f6660a.m2817a()) {
            C1131e.f6660a.m2814a(line);
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethodBase
    protected boolean shouldCloseConnection(HttpConnection conn) {
        if (getStatusCode() != 200) {
            return super.shouldCloseConnection(conn);
        }
        Header connectionHeader = null;
        if (!conn.isTransparent()) {
            connectionHeader = getResponseHeader("proxy-connection");
        }
        if (connectionHeader == null) {
            connectionHeader = getResponseHeader("connection");
        }
        if (connectionHeader != null && connectionHeader.getValue().equalsIgnoreCase("close") && f6422d.isWarnEnabled()) {
            f6422d.warn(new StringBuffer().append("Invalid header encountered '").append(connectionHeader.toExternalForm()).append("' in response ").append(getStatusLine().toString()).toString());
        }
        return false;
    }

    static {
        Class clsM2702a;
        if (f6421a == null) {
            clsM2702a = m2702a("org.apache.commons.httpclient.ConnectMethod");
            f6421a = clsM2702a;
        } else {
            clsM2702a = f6421a;
        }
        f6422d = LogFactory.getLog(clsM2702a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2702a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }
}
