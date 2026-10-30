package org.apache.commons.httpclient;

import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: renamed from: org.apache.commons.httpclient.f */
/* JADX INFO: compiled from: WireLogInputStream.java */
/* JADX INFO: loaded from: classes.dex */
final class C1132f extends FilterInputStream {

    /* JADX INFO: renamed from: a */
    private InputStream f6663a;

    /* JADX INFO: renamed from: b */
    private C1131e f6664b;

    public C1132f(InputStream in, C1131e wire) {
        super(in);
        this.f6663a = in;
        this.f6664b = wire;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream
    public final int read(byte[] b, int off, int len) throws IOException {
        int l = this.f6663a.read(b, off, len);
        if (l > 0) {
            this.f6664b.m2820b(b, off, l);
        }
        return l;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream
    public final int read() throws IOException {
        int l = this.f6663a.read();
        if (l > 0) {
            this.f6664b.m2818b(l);
        }
        return l;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream
    public final int read(byte[] b) throws IOException {
        int l = this.f6663a.read(b);
        if (l > 0) {
            this.f6664b.m2820b(b, 0, l);
        }
        return l;
    }
}
