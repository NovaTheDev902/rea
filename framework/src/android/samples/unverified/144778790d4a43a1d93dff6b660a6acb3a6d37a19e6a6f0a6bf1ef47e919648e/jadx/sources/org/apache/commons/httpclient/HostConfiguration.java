package org.apache.commons.httpclient;

import java.net.InetAddress;
import org.apache.commons.httpclient.params.HostParams;
import org.apache.commons.httpclient.protocol.Protocol;
import org.apache.commons.httpclient.util.LangUtils;

/* JADX INFO: loaded from: classes.dex */
public class HostConfiguration implements Cloneable {
    public static final HostConfiguration ANY_HOST_CONFIGURATION = new HostConfiguration();

    /* JADX INFO: renamed from: a */
    private HttpHost f6448a = null;

    /* JADX INFO: renamed from: b */
    private ProxyHost f6449b = null;

    /* JADX INFO: renamed from: c */
    private InetAddress f6450c = null;

    /* JADX INFO: renamed from: d */
    private HostParams f6451d = new HostParams();

    public HostConfiguration() {
    }

    public HostConfiguration(HostConfiguration hostConfiguration) {
        m2705a(hostConfiguration);
    }

    /* JADX INFO: renamed from: a */
    private void m2705a(HostConfiguration hostConfiguration) {
        synchronized (hostConfiguration) {
            try {
                if (hostConfiguration.f6448a != null) {
                    this.f6448a = (HttpHost) hostConfiguration.f6448a.clone();
                } else {
                    this.f6448a = null;
                }
                if (hostConfiguration.f6449b != null) {
                    this.f6449b = (ProxyHost) hostConfiguration.f6449b.clone();
                } else {
                    this.f6449b = null;
                }
                this.f6450c = hostConfiguration.getLocalAddress();
                this.f6451d = (HostParams) hostConfiguration.getParams().clone();
            } catch (CloneNotSupportedException e) {
                throw new IllegalArgumentException("Host configuration could not be cloned");
            }
        }
    }

    public Object clone() {
        try {
            HostConfiguration copy = (HostConfiguration) super.clone();
            copy.m2705a(this);
            return copy;
        } catch (CloneNotSupportedException e) {
            throw new IllegalArgumentException("Host configuration could not be cloned");
        }
    }

    public synchronized String toString() {
        StringBuffer b;
        boolean appendComma = false;
        b = new StringBuffer(50);
        b.append("HostConfiguration[");
        if (this.f6448a != null) {
            appendComma = true;
            b.append("host=").append(this.f6448a);
        }
        if (this.f6449b != null) {
            if (appendComma) {
                b.append(", ");
            } else {
                appendComma = true;
            }
            b.append("proxyHost=").append(this.f6449b);
        }
        if (this.f6450c != null) {
            if (appendComma) {
                b.append(", ");
            }
            b.append("localAddress=").append(this.f6450c);
            b.append(", ");
            b.append("params=").append(this.f6451d);
        }
        b.append("]");
        return b.toString();
    }

    public synchronized boolean hostEquals(HttpConnection connection) {
        boolean z = false;
        synchronized (this) {
            try {
                if (connection == null) {
                    throw new IllegalArgumentException("Connection may not be null");
                }
                if (this.f6448a != null && this.f6448a.getHostName().equalsIgnoreCase(connection.getHost()) && this.f6448a.getPort() == connection.getPort() && this.f6448a.getProtocol().equals(connection.getProtocol()) && (this.f6450c == null ? connection.getLocalAddress() == null : this.f6450c.equals(connection.getLocalAddress()))) {
                    z = true;
                }
            } catch (Throwable th) {
                throw th;
            }
        }
        return z;
    }

    public synchronized boolean proxyEquals(HttpConnection connection) {
        boolean z = true;
        synchronized (this) {
            try {
                if (connection == null) {
                    throw new IllegalArgumentException("Connection may not be null");
                }
                if (this.f6449b != null) {
                    if (!this.f6449b.getHostName().equalsIgnoreCase(connection.getProxyHost()) || this.f6449b.getPort() != connection.getProxyPort()) {
                        z = false;
                    }
                } else if (connection.getProxyHost() != null) {
                    z = false;
                }
            } catch (Throwable th) {
                throw th;
            }
        }
        return z;
    }

    public synchronized boolean isHostSet() {
        return this.f6448a != null;
    }

    public synchronized void setHost(HttpHost host) {
        this.f6448a = host;
    }

    public synchronized void setHost(String host, int port, String protocol) {
        this.f6448a = new HttpHost(host, port, Protocol.getProtocol(protocol));
    }

    public synchronized void setHost(String host, String virtualHost, int port, Protocol protocol) {
        setHost(host, port, protocol);
        this.f6451d.setVirtualHost(virtualHost);
    }

    public synchronized void setHost(String host, int port, Protocol protocol) {
        try {
            if (host == null) {
                throw new IllegalArgumentException("host must not be null");
            }
            if (protocol == null) {
                throw new IllegalArgumentException("protocol must not be null");
            }
            this.f6448a = new HttpHost(host, port, protocol);
        } catch (Throwable th) {
            throw th;
        }
    }

    public synchronized void setHost(String host, int port) {
        setHost(host, port, Protocol.getProtocol("http"));
    }

    public synchronized void setHost(String host) {
        Protocol defaultProtocol = Protocol.getProtocol("http");
        setHost(host, defaultProtocol.getDefaultPort(), defaultProtocol);
    }

    public synchronized void setHost(URI uri) {
        try {
            setHost(uri.getHost(), uri.getPort(), uri.getScheme());
        } catch (URIException e) {
            throw new IllegalArgumentException(e.toString());
        }
    }

    public synchronized String getHostURL() {
        if (this.f6448a == null) {
            throw new IllegalStateException("Host must be set to create a host URL");
        }
        return this.f6448a.toURI();
    }

    public synchronized String getHost() {
        return this.f6448a != null ? this.f6448a.getHostName() : null;
    }

    public synchronized String getVirtualHost() {
        return this.f6451d.getVirtualHost();
    }

    public synchronized int getPort() {
        return this.f6448a != null ? this.f6448a.getPort() : -1;
    }

    public synchronized Protocol getProtocol() {
        return this.f6448a != null ? this.f6448a.getProtocol() : null;
    }

    public synchronized boolean isProxySet() {
        return this.f6449b != null;
    }

    public synchronized void setProxyHost(ProxyHost proxyHost) {
        this.f6449b = proxyHost;
    }

    public synchronized void setProxy(String proxyHost, int proxyPort) {
        this.f6449b = new ProxyHost(proxyHost, proxyPort);
    }

    public synchronized String getProxyHost() {
        return this.f6449b != null ? this.f6449b.getHostName() : null;
    }

    public synchronized int getProxyPort() {
        return this.f6449b != null ? this.f6449b.getPort() : -1;
    }

    public synchronized void setLocalAddress(InetAddress localAddress) {
        this.f6450c = localAddress;
    }

    public synchronized InetAddress getLocalAddress() {
        return this.f6450c;
    }

    public HostParams getParams() {
        return this.f6451d;
    }

    public void setParams(HostParams params) {
        if (params == null) {
            throw new IllegalArgumentException("Parameters may not be null");
        }
        this.f6451d = params;
    }

    public synchronized boolean equals(Object o) {
        boolean z = true;
        synchronized (this) {
            if (!(o instanceof HostConfiguration)) {
                z = false;
            } else if (o != this) {
                HostConfiguration that = (HostConfiguration) o;
                if (!LangUtils.equals(this.f6448a, that.f6448a) || !LangUtils.equals(this.f6449b, that.f6449b) || !LangUtils.equals(this.f6450c, that.f6450c)) {
                    z = false;
                }
            }
        }
        return z;
    }

    public synchronized int hashCode() {
        int hash;
        hash = LangUtils.hashCode(17, this.f6448a);
        return LangUtils.hashCode(LangUtils.hashCode(hash, this.f6449b), this.f6450c);
    }
}
