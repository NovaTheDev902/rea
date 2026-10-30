package org.apache.commons.httpclient;

import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: renamed from: org.apache.commons.httpclient.a */
/* JADX INFO: compiled from: AutoCloseInputStream.java */
/* JADX INFO: loaded from: classes.dex */
final class C1117a extends FilterInputStream {

    /* JADX INFO: renamed from: a */
    private boolean f6572a;

    /* JADX INFO: renamed from: b */
    private boolean f6573b;

    /* JADX INFO: renamed from: c */
    private InterfaceC1130d f6574c;

    public C1117a(InputStream in, InterfaceC1130d watcher) {
        super(in);
        this.f6572a = true;
        this.f6573b = false;
        this.f6574c = null;
        this.f6574c = watcher;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream
    public final int read() throws IOException {
        if (!m2758a()) {
            return -1;
        }
        int l = super.read();
        m2757a(l);
        return l;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream
    public final int read(byte[] b, int off, int len) throws IOException {
        if (!m2758a()) {
            return -1;
        }
        int l = super.read(b, off, len);
        m2757a(l);
        return l;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream
    public final int read(byte[] b) throws IOException {
        if (!m2758a()) {
            return -1;
        }
        int l = super.read(b);
        m2757a(l);
        return l;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream
    public final int available() throws IOException {
        if (!m2758a()) {
            return 0;
        }
        int a = super.available();
        return a;
    }

    @Override // java.io.FilterInputStream, java.io.InputStream, java.io.Closeable, java.lang.AutoCloseable
    public final void close() throws IOException {
        if (!this.f6573b) {
            this.f6573b = true;
            m2759b();
        }
    }

    /* JADX INFO: renamed from: a */
    private void m2757a(int readResult) throws IOException {
        if (readResult == -1) {
            m2759b();
        }
    }

    /* JADX INFO: renamed from: a */
    private boolean m2758a() throws IOException {
        if (!this.f6572a && this.f6573b) {
            throw new IOException("Attempted read on closed stream.");
        }
        return this.f6572a;
    }

    /* JADX INFO: renamed from: b */
    private void m2759b() throws IOException {
        if (this.f6572a) {
            super.close();
            this.f6572a = false;
            if (this.f6574c != null) {
                this.f6574c.mo2786a();
            }
        }
    }
}
