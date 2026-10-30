package org.apache.commons.httpclient;

import java.io.IOException;
import java.io.OutputStream;
import org.apache.commons.httpclient.util.EncodingUtil;

/* JADX INFO: loaded from: classes.dex */
public class ChunkedOutputStream extends OutputStream {

    /* JADX INFO: renamed from: a */
    private static final byte[] f6414a = {13, 10};

    /* JADX INFO: renamed from: b */
    private static final byte[] f6415b = f6414a;

    /* JADX INFO: renamed from: c */
    private static final byte[] f6416c = {48};

    /* JADX INFO: renamed from: d */
    private OutputStream f6417d;

    /* JADX INFO: renamed from: e */
    private byte[] f6418e;

    /* JADX INFO: renamed from: f */
    private int f6419f;

    /* JADX INFO: renamed from: g */
    private boolean f6420g;

    public ChunkedOutputStream(OutputStream stream, int bufferSize) throws IOException {
        this.f6417d = null;
        this.f6419f = 0;
        this.f6420g = false;
        this.f6418e = new byte[bufferSize];
        this.f6417d = stream;
    }

    public ChunkedOutputStream(OutputStream stream) throws IOException {
        this(stream, 2048);
    }

    protected void flushCache() throws IOException {
        if (this.f6419f > 0) {
            byte[] chunkHeader = EncodingUtil.getAsciiBytes(new StringBuffer().append(Integer.toHexString(this.f6419f)).append("\r\n").toString());
            this.f6417d.write(chunkHeader, 0, chunkHeader.length);
            this.f6417d.write(this.f6418e, 0, this.f6419f);
            this.f6417d.write(f6415b, 0, f6415b.length);
            this.f6419f = 0;
        }
    }

    protected void flushCacheWithAppend(byte[] bufferToAppend, int off, int len) throws IOException {
        byte[] chunkHeader = EncodingUtil.getAsciiBytes(new StringBuffer().append(Integer.toHexString(this.f6419f + len)).append("\r\n").toString());
        this.f6417d.write(chunkHeader, 0, chunkHeader.length);
        this.f6417d.write(this.f6418e, 0, this.f6419f);
        this.f6417d.write(bufferToAppend, off, len);
        this.f6417d.write(f6415b, 0, f6415b.length);
        this.f6419f = 0;
    }

    protected void writeClosingChunk() throws IOException {
        this.f6417d.write(f6416c, 0, f6416c.length);
        this.f6417d.write(f6414a, 0, f6414a.length);
        this.f6417d.write(f6415b, 0, f6415b.length);
    }

    public void finish() throws IOException {
        if (!this.f6420g) {
            flushCache();
            writeClosingChunk();
            this.f6420g = true;
        }
    }

    @Override // java.io.OutputStream
    public void write(int b) throws IOException {
        this.f6418e[this.f6419f] = (byte) b;
        this.f6419f++;
        if (this.f6419f == this.f6418e.length) {
            flushCache();
        }
    }

    @Override // java.io.OutputStream
    public void write(byte[] b) throws IOException {
        write(b, 0, b.length);
    }

    @Override // java.io.OutputStream
    public void write(byte[] src, int off, int len) throws IOException {
        if (len >= this.f6418e.length - this.f6419f) {
            flushCacheWithAppend(src, off, len);
        } else {
            System.arraycopy(src, off, this.f6418e, this.f6419f, len);
            this.f6419f += len;
        }
    }

    @Override // java.io.OutputStream, java.io.Flushable
    public void flush() throws IOException {
        this.f6417d.flush();
    }

    @Override // java.io.OutputStream, java.io.Closeable, java.lang.AutoCloseable
    public void close() throws IOException {
        finish();
        super.close();
    }
}
