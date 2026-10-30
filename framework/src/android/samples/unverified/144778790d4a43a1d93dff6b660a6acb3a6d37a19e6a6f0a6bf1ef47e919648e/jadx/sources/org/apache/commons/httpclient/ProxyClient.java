package org.apache.commons.httpclient;

import java.io.IOException;
import java.net.Socket;
import org.apache.commons.httpclient.params.HttpClientParams;
import org.apache.commons.httpclient.params.HttpConnectionManagerParams;
import org.apache.commons.httpclient.params.HttpParams;

/* JADX INFO: loaded from: classes.dex */
public class ProxyClient {

    /* JADX INFO: renamed from: a */
    private HttpState f6550a;

    /* JADX INFO: renamed from: b */
    private HttpClientParams f6551b;

    /* JADX INFO: renamed from: c */
    private HostConfiguration f6552c;

    public ProxyClient() {
        this(new HttpClientParams());
    }

    public ProxyClient(HttpClientParams params) {
        this.f6550a = new HttpState();
        this.f6551b = null;
        this.f6552c = new HostConfiguration();
        if (params == null) {
            throw new IllegalArgumentException("Params may not be null");
        }
        this.f6551b = params;
    }

    public synchronized HttpState getState() {
        return this.f6550a;
    }

    public synchronized void setState(HttpState state) {
        this.f6550a = state;
    }

    public synchronized HostConfiguration getHostConfiguration() {
        return this.f6552c;
    }

    public synchronized void setHostConfiguration(HostConfiguration hostConfiguration) {
        this.f6552c = hostConfiguration;
    }

    public synchronized HttpClientParams getParams() {
        return this.f6551b;
    }

    public synchronized void setParams(HttpClientParams params) {
        try {
            if (params == null) {
                throw new IllegalArgumentException("Parameters may not be null");
            }
            this.f6551b = params;
        } catch (Throwable th) {
            throw th;
        }
    }

    public ConnectResponse connect() throws IOException {
        HostConfiguration hostconf = getHostConfiguration();
        if (hostconf.getProxyHost() == null) {
            throw new IllegalStateException("proxy host must be configured");
        }
        if (hostconf.getHost() == null) {
            throw new IllegalStateException("destination host must be configured");
        }
        if (hostconf.getProtocol().isSecure()) {
            throw new IllegalStateException("secure protocol socket factory may not be used");
        }
        ConnectMethod method = new ConnectMethod(getHostConfiguration());
        method.getParams().setDefaults(getParams());
        C1116a connectionManager = new C1116a();
        connectionManager.m2754a(getParams());
        C1120c director = new C1120c(connectionManager, hostconf, getParams(), getState());
        director.m2799a(method);
        ConnectResponse response = new ConnectResponse((byte) 0);
        ConnectResponse.m2752a(response, method);
        if (method.getStatusCode() == 200) {
            ConnectResponse.m2751a(response, connectionManager.m2753a().getSocket());
        } else {
            connectionManager.m2753a().close();
        }
        return response;
    }

    public static class ConnectResponse {

        /* JADX INFO: renamed from: a */
        private ConnectMethod f6553a;

        /* JADX INFO: renamed from: b */
        private Socket f6554b;

        ConnectResponse(byte b) {
            this();
        }

        /* JADX INFO: renamed from: a */
        static void m2751a(ConnectResponse x0, Socket x1) {
            x0.f6554b = x1;
        }

        /* JADX INFO: renamed from: a */
        static void m2752a(ConnectResponse x0, ConnectMethod x1) {
            x0.f6553a = x1;
        }

        private ConnectResponse() {
        }

        public ConnectMethod getConnectMethod() {
            return this.f6553a;
        }

        public Socket getSocket() {
            return this.f6554b;
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.ProxyClient$a */
    static class C1116a implements HttpConnectionManager {

        /* JADX INFO: renamed from: a */
        private HttpConnection f6555a;

        /* JADX INFO: renamed from: b */
        private HttpParams f6556b;

        C1116a() {
        }

        @Override // org.apache.commons.httpclient.HttpConnectionManager
        public final void closeIdleConnections(long idleTimeout) {
        }

        /* JADX INFO: renamed from: a */
        public final HttpConnection m2753a() {
            return this.f6555a;
        }

        /* JADX INFO: renamed from: a */
        public final void m2754a(HttpParams httpParams) {
            this.f6556b = httpParams;
        }

        @Override // org.apache.commons.httpclient.HttpConnectionManager
        public final HttpConnection getConnectionWithTimeout(HostConfiguration hostConfiguration, long timeout) {
            this.f6555a = new HttpConnection(hostConfiguration);
            this.f6555a.setHttpConnectionManager(this);
            this.f6555a.getParams().setDefaults(this.f6556b);
            return this.f6555a;
        }

        @Override // org.apache.commons.httpclient.HttpConnectionManager
        public final HttpConnection getConnection(HostConfiguration hostConfiguration, long timeout) throws HttpException {
            return getConnectionWithTimeout(hostConfiguration, timeout);
        }

        @Override // org.apache.commons.httpclient.HttpConnectionManager
        public final HttpConnection getConnection(HostConfiguration hostConfiguration) {
            return getConnectionWithTimeout(hostConfiguration, -1L);
        }

        @Override // org.apache.commons.httpclient.HttpConnectionManager
        public final void releaseConnection(HttpConnection conn) {
        }

        @Override // org.apache.commons.httpclient.HttpConnectionManager
        public final HttpConnectionManagerParams getParams() {
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnectionManager
        public final void setParams(HttpConnectionManagerParams params) {
        }
    }
}
