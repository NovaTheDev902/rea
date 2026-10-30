package org.apache.commons.httpclient.protocol;

import java.io.IOException;
import java.net.InetAddress;

/* JADX INFO: renamed from: org.apache.commons.httpclient.protocol.a */
/* JADX INFO: compiled from: ControllerThreadSocketFactory.java */
/* JADX INFO: loaded from: classes.dex */
final class C1134a extends ControllerThreadSocketFactory.SocketTask {

    /* JADX INFO: renamed from: a */
    private final ProtocolSocketFactory f6755a;

    /* JADX INFO: renamed from: b */
    private final String f6756b;

    /* JADX INFO: renamed from: c */
    private final int f6757c;

    /* JADX INFO: renamed from: d */
    private final InetAddress f6758d;

    /* JADX INFO: renamed from: e */
    private final int f6759e;

    C1134a(ProtocolSocketFactory protocolSocketFactory, String str, int i, InetAddress inetAddress, int i2) throws IOException {
        this.f6755a = protocolSocketFactory;
        this.f6756b = str;
        this.f6757c = i;
        this.f6758d = inetAddress;
        this.f6759e = i2;
    }

    @Override // org.apache.commons.httpclient.protocol.ControllerThreadSocketFactory.SocketTask
    public final void doit() throws IOException {
        setSocket(this.f6755a.createSocket(this.f6756b, this.f6757c, this.f6758d, this.f6759e));
    }
}
