package org.apache.commons.httpclient;

import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.OutputStream;

/* JADX INFO: renamed from: org.apache.commons.httpclient.g */
/* JADX INFO: compiled from: WireLogOutputStream.java */
/* JADX INFO: loaded from: classes.dex */
final class C1133g extends FilterOutputStream {

    /* JADX INFO: renamed from: a */
    private OutputStream f6665a;

    /* JADX INFO: renamed from: b */
    private C1131e f6666b;

    public C1133g(OutputStream out, C1131e wire) {
        super(out);
        this.f6665a = out;
        this.f6666b = wire;
    }

    @Override // java.io.FilterOutputStream, java.io.OutputStream
    public final void write(byte[] b, int off, int len) throws IOException {
        this.f6665a.write(b, off, len);
        this.f6666b.m2816a(b, off, len);
    }

    @Override // java.io.FilterOutputStream, java.io.OutputStream
    public final void write(int b) throws IOException {
        this.f6665a.write(b);
        this.f6666b.m2813a(b);
    }

    @Override // java.io.FilterOutputStream, java.io.OutputStream
    public final void write(byte[] b) throws IOException {
        this.f6665a.write(b);
        this.f6666b.m2815a(b);
    }
}
