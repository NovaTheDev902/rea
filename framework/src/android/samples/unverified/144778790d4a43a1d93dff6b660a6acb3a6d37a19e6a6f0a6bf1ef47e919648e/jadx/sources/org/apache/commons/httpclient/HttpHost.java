package org.apache.commons.httpclient;

import org.apache.commons.httpclient.protocol.Protocol;
import org.apache.commons.httpclient.util.LangUtils;

/* JADX INFO: loaded from: classes.dex */
public class HttpHost implements Cloneable {

    /* JADX INFO: renamed from: a */
    private String f6483a;

    /* JADX INFO: renamed from: b */
    private int f6484b;

    /* JADX INFO: renamed from: c */
    private Protocol f6485c;

    public HttpHost(String hostname, int port, Protocol protocol) {
        this.f6483a = null;
        this.f6484b = -1;
        this.f6485c = null;
        if (hostname == null) {
            throw new IllegalArgumentException("Host name may not be null");
        }
        if (protocol == null) {
            throw new IllegalArgumentException("Protocol may not be null");
        }
        this.f6483a = hostname;
        this.f6485c = protocol;
        if (port >= 0) {
            this.f6484b = port;
        } else {
            this.f6484b = this.f6485c.getDefaultPort();
        }
    }

    public HttpHost(String hostname, int port) {
        this(hostname, port, Protocol.getProtocol("http"));
    }

    public HttpHost(String hostname) {
        this(hostname, -1, Protocol.getProtocol("http"));
    }

    public HttpHost(URI uri) throws URIException {
        this(uri.getHost(), uri.getPort(), Protocol.getProtocol(uri.getScheme()));
    }

    public HttpHost(HttpHost httphost) {
        this.f6483a = null;
        this.f6484b = -1;
        this.f6485c = null;
        m2710a(httphost);
    }

    /* JADX INFO: renamed from: a */
    private void m2710a(HttpHost httphost) {
        this.f6483a = httphost.f6483a;
        this.f6484b = httphost.f6484b;
        this.f6485c = httphost.f6485c;
    }

    public Object clone() throws CloneNotSupportedException {
        HttpHost copy = (HttpHost) super.clone();
        copy.m2710a(this);
        return copy;
    }

    public String getHostName() {
        return this.f6483a;
    }

    public int getPort() {
        return this.f6484b;
    }

    public Protocol getProtocol() {
        return this.f6485c;
    }

    public String toURI() {
        StringBuffer buffer = new StringBuffer(50);
        buffer.append(this.f6485c.getScheme());
        buffer.append("://");
        buffer.append(this.f6483a);
        if (this.f6484b != this.f6485c.getDefaultPort()) {
            buffer.append(':');
            buffer.append(this.f6484b);
        }
        return buffer.toString();
    }

    public String toString() {
        StringBuffer buffer = new StringBuffer(50);
        buffer.append(toURI());
        return buffer.toString();
    }

    public boolean equals(Object o) {
        if (!(o instanceof HttpHost)) {
            return false;
        }
        if (o == this) {
            return true;
        }
        HttpHost that = (HttpHost) o;
        return this.f6483a.equalsIgnoreCase(that.f6483a) && this.f6484b == that.f6484b && this.f6485c.equals(that.f6485c);
    }

    public int hashCode() {
        int hash = LangUtils.hashCode(17, this.f6483a);
        return LangUtils.hashCode(LangUtils.hashCode(hash, this.f6484b), this.f6485c);
    }
}
