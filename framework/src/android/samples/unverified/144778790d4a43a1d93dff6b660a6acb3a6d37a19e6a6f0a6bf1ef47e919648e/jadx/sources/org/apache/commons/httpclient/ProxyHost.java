package org.apache.commons.httpclient;

import org.apache.commons.httpclient.protocol.Protocol;

/* JADX INFO: loaded from: classes.dex */
public class ProxyHost extends HttpHost {
    public ProxyHost(ProxyHost httpproxy) {
        super(httpproxy);
    }

    public ProxyHost(String hostname, int port) {
        super(hostname, port, Protocol.getProtocol("http"));
    }

    public ProxyHost(String hostname) {
        this(hostname, -1);
    }

    @Override // org.apache.commons.httpclient.HttpHost
    public Object clone() throws CloneNotSupportedException {
        ProxyHost copy = (ProxyHost) super.clone();
        return copy;
    }
}
