package org.apache.commons.httpclient.protocol;

import com.lenovo.lps.sus.p008c.C0092c;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import org.apache.commons.httpclient.util.LangUtils;

/* JADX INFO: loaded from: classes.dex */
public class Protocol {

    /* JADX INFO: renamed from: a */
    private static final Map f6742a = Collections.synchronizedMap(new HashMap());

    /* JADX INFO: renamed from: b */
    private String f6743b;

    /* JADX INFO: renamed from: c */
    private ProtocolSocketFactory f6744c;

    /* JADX INFO: renamed from: d */
    private int f6745d;

    /* JADX INFO: renamed from: e */
    private boolean f6746e;

    public static void registerProtocol(String id, Protocol protocol) {
        if (id == null) {
            throw new IllegalArgumentException("id is null");
        }
        if (protocol == null) {
            throw new IllegalArgumentException("protocol is null");
        }
        f6742a.put(id, protocol);
    }

    public static void unregisterProtocol(String id) {
        if (id == null) {
            throw new IllegalArgumentException("id is null");
        }
        f6742a.remove(id);
    }

    public static Protocol getProtocol(String id) throws IllegalStateException {
        if (id == null) {
            throw new IllegalArgumentException("id is null");
        }
        Protocol protocol = (Protocol) f6742a.get(id);
        if (protocol == null) {
            if (!"http".equals(id)) {
                if (!"https".equals(id)) {
                    throw new IllegalStateException(new StringBuffer().append("unsupported protocol: '").append(id).append("'").toString());
                }
                Protocol protocol2 = new Protocol("https", (SecureProtocolSocketFactory) SSLProtocolSocketFactory.m2840a(), 443);
                registerProtocol("https", protocol2);
                return protocol2;
            }
            Protocol protocol3 = new Protocol("http", DefaultProtocolSocketFactory.m2838a(), 80);
            registerProtocol("http", protocol3);
            return protocol3;
        }
        return protocol;
    }

    public Protocol(String scheme, ProtocolSocketFactory factory, int defaultPort) {
        if (scheme == null) {
            throw new IllegalArgumentException("scheme is null");
        }
        if (factory == null) {
            throw new IllegalArgumentException("socketFactory is null");
        }
        if (defaultPort <= 0) {
            throw new IllegalArgumentException(new StringBuffer().append("port is invalid: ").append(defaultPort).toString());
        }
        this.f6743b = scheme;
        this.f6744c = factory;
        this.f6745d = defaultPort;
        this.f6746e = factory instanceof SecureProtocolSocketFactory;
    }

    public Protocol(String scheme, SecureProtocolSocketFactory factory, int defaultPort) {
        this(scheme, (ProtocolSocketFactory) factory, defaultPort);
    }

    public int getDefaultPort() {
        return this.f6745d;
    }

    public ProtocolSocketFactory getSocketFactory() {
        return this.f6744c;
    }

    public String getScheme() {
        return this.f6743b;
    }

    public boolean isSecure() {
        return this.f6746e;
    }

    public int resolvePort(int port) {
        return port <= 0 ? getDefaultPort() : port;
    }

    public String toString() {
        return new StringBuffer().append(this.f6743b).append(C0092c.f1283N).append(this.f6745d).toString();
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof Protocol)) {
            return false;
        }
        Protocol p = (Protocol) obj;
        return this.f6745d == p.getDefaultPort() && this.f6743b.equalsIgnoreCase(p.getScheme()) && this.f6746e == p.isSecure() && this.f6744c.equals(p.getSocketFactory());
    }

    public int hashCode() {
        int hash = LangUtils.hashCode(17, this.f6745d);
        return LangUtils.hashCode(LangUtils.hashCode(LangUtils.hashCode(hash, this.f6743b.toLowerCase()), this.f6746e), this.f6744c);
    }
}
