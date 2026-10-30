package org.apache.commons.httpclient;

import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.httpclient.params.HttpConnectionManagerParams;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class SimpleHttpConnectionManager implements HttpConnectionManager {

    /* JADX INFO: renamed from: a */
    static Class f6557a;

    /* JADX INFO: renamed from: b */
    private static final Log f6558b;

    /* JADX INFO: renamed from: c */
    private HttpConnectionManagerParams f6559c;

    /* JADX INFO: renamed from: d */
    private long f6560d;

    /* JADX INFO: renamed from: e */
    private volatile boolean f6561e;

    /* JADX INFO: renamed from: f */
    private boolean f6562f;
    protected HttpConnection httpConnection;

    static {
        Class clsM2755a;
        if (f6557a == null) {
            clsM2755a = m2755a("org.apache.commons.httpclient.SimpleHttpConnectionManager");
            f6557a = clsM2755a;
        } else {
            clsM2755a = f6557a;
        }
        f6558b = LogFactory.getLog(clsM2755a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2755a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    /* JADX INFO: renamed from: a */
    static void m2756a(HttpConnection conn) {
        InputStream lastResponse = conn.getLastResponseInputStream();
        if (lastResponse != null) {
            conn.setLastResponseInputStream(null);
            try {
                lastResponse.close();
            } catch (IOException e) {
                conn.close();
            }
        }
    }

    public SimpleHttpConnectionManager(boolean alwaysClose) {
        this.f6559c = new HttpConnectionManagerParams();
        this.f6560d = Long.MAX_VALUE;
        this.f6561e = false;
        this.f6562f = false;
        this.f6562f = alwaysClose;
    }

    public SimpleHttpConnectionManager() {
        this.f6559c = new HttpConnectionManagerParams();
        this.f6560d = Long.MAX_VALUE;
        this.f6561e = false;
        this.f6562f = false;
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnection getConnection(HostConfiguration hostConfiguration) {
        return getConnection(hostConfiguration, 0L);
    }

    public boolean isConnectionStaleCheckingEnabled() {
        return this.f6559c.isStaleCheckingEnabled();
    }

    public void setConnectionStaleCheckingEnabled(boolean connectionStaleCheckingEnabled) {
        this.f6559c.setStaleCheckingEnabled(connectionStaleCheckingEnabled);
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnection getConnectionWithTimeout(HostConfiguration hostConfiguration, long timeout) {
        if (this.httpConnection == null) {
            this.httpConnection = new HttpConnection(hostConfiguration);
            this.httpConnection.setHttpConnectionManager(this);
            this.httpConnection.getParams().setDefaults(this.f6559c);
        } else if (!hostConfiguration.hostEquals(this.httpConnection) || !hostConfiguration.proxyEquals(this.httpConnection)) {
            if (this.httpConnection.isOpen()) {
                this.httpConnection.close();
            }
            this.httpConnection.setHost(hostConfiguration.getHost());
            this.httpConnection.setPort(hostConfiguration.getPort());
            this.httpConnection.setProtocol(hostConfiguration.getProtocol());
            this.httpConnection.setLocalAddress(hostConfiguration.getLocalAddress());
            this.httpConnection.setProxyHost(hostConfiguration.getProxyHost());
            this.httpConnection.setProxyPort(hostConfiguration.getProxyPort());
        } else {
            m2756a(this.httpConnection);
        }
        this.f6560d = Long.MAX_VALUE;
        if (this.f6561e) {
            f6558b.warn("SimpleHttpConnectionManager being used incorrectly.  Be sure that HttpMethod.releaseConnection() is always called and that only one thread and/or method is using this connection manager at a time.");
        }
        this.f6561e = true;
        return this.httpConnection;
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnection getConnection(HostConfiguration hostConfiguration, long timeout) {
        return getConnectionWithTimeout(hostConfiguration, timeout);
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public void releaseConnection(HttpConnection conn) {
        if (conn != this.httpConnection) {
            throw new IllegalStateException("Unexpected release of an unknown connection.");
        }
        if (this.f6562f) {
            this.httpConnection.close();
        } else {
            m2756a(this.httpConnection);
        }
        this.f6561e = false;
        this.f6560d = System.currentTimeMillis();
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnectionManagerParams getParams() {
        return this.f6559c;
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public void setParams(HttpConnectionManagerParams params) {
        if (params == null) {
            throw new IllegalArgumentException("Parameters may not be null");
        }
        this.f6559c = params;
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public void closeIdleConnections(long idleTimeout) {
        long maxIdleTime = System.currentTimeMillis() - idleTimeout;
        if (this.f6560d <= maxIdleTime) {
            this.httpConnection.close();
        }
    }

    public void shutdown() {
        this.httpConnection.close();
    }
}
