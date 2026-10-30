package org.apache.commons.httpclient;

import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public class ContentLengthInputStream extends InputStream {

    /* JADX INFO: renamed from: a */
    private long f6424a;

    /* JADX INFO: renamed from: b */
    private long f6425b;

    /* JADX INFO: renamed from: c */
    private boolean f6426c;

    /* JADX INFO: renamed from: d */
    private InputStream f6427d;

    public ContentLengthInputStream(InputStream in, int contentLength) {
        this(in, contentLength);
    }

    public ContentLengthInputStream(InputStream in, long contentLength) {
        this.f6425b = 0L;
        this.f6426c = false;
        this.f6427d = null;
        this.f6427d = in;
        this.f6424a = contentLength;
    }

    @Override // java.io.InputStream, java.io.Closeable, java.lang.AutoCloseable
    public void close() throws IOException {
        if (!this.f6426c) {
            try {
                ChunkedInputStream.m2699a(this);
            } finally {
                this.f6426c = true;
            }
        }
    }

    @Override // java.io.InputStream
    public int read() throws IOException {
        if (this.f6426c) {
            throw new IOException("Attempted read from closed stream.");
        }
        if (this.f6425b >= this.f6424a) {
            return -1;
        }
        this.f6425b++;
        return this.f6427d.read();
    }

    @Override // java.io.InputStream
    public int read(byte[] b, int off, int len) throws IOException {
        if (this.f6426c) {
            throw new IOException("Attempted read from closed stream.");
        }
        if (this.f6425b >= this.f6424a) {
            return -1;
        }
        if (this.f6425b + ((long) len) > this.f6424a) {
            len = (int) (this.f6424a - this.f6425b);
        }
        int count = this.f6427d.read(b, off, len);
        this.f6425b += (long) count;
        return count;
    }

    @Override // java.io.InputStream
    public int read(byte[] b) throws IOException {
        return read(b, 0, b.length);
    }

    @Override // java.io.InputStream
    public long skip(long n) throws IOException {
        long length = this.f6427d.skip(Math.min(n, this.f6424a - this.f6425b));
        if (length > 0) {
            this.f6425b += length;
        }
        return length;
    }

    @Override // java.io.InputStream
    public int available() throws IOException {
        if (this.f6426c) {
            return 0;
        }
        int avail = this.f6427d.available();
        if (this.f6425b + ((long) avail) > this.f6424a) {
            return (int) (this.f6424a - this.f6425b);
        }
        return avail;
    }
}
