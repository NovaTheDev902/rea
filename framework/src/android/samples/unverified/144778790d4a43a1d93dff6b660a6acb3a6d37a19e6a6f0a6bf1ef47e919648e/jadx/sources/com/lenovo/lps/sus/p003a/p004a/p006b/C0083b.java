package com.lenovo.lps.sus.p003a.p004a.p006b;

import java.io.IOException;
import java.io.OutputStream;

/* JADX INFO: renamed from: com.lenovo.lps.sus.a.a.b.b */
/* JADX INFO: loaded from: classes.dex */
final class C0083b extends OutputStream {

    /* JADX INFO: renamed from: a */
    private OutputStream f1221a;

    /* JADX INFO: renamed from: b */
    private int f1222b = 0;

    /* JADX INFO: renamed from: c */
    private int f1223c = 0;

    /* JADX INFO: renamed from: d */
    private int f1224d = 0;

    /* JADX INFO: renamed from: e */
    private int f1225e;

    public C0083b(OutputStream outputStream) {
        this.f1221a = null;
        this.f1225e = 0;
        this.f1221a = outputStream;
        this.f1225e = 0;
    }

    /* JADX INFO: renamed from: a */
    protected final void m260a() throws IOException {
        if (this.f1223c > 0) {
            if (this.f1225e > 0 && this.f1224d == this.f1225e) {
                this.f1221a.write("\r\n".getBytes());
                this.f1224d = 0;
            }
            char cCharAt = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".charAt((this.f1222b << 8) >>> 26);
            char cCharAt2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".charAt((this.f1222b << 14) >>> 26);
            char cCharAt3 = this.f1223c < 2 ? '=' : "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".charAt((this.f1222b << 20) >>> 26);
            char cCharAt4 = this.f1223c >= 3 ? "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".charAt((this.f1222b << 26) >>> 26) : '=';
            this.f1221a.write(cCharAt);
            this.f1221a.write(cCharAt2);
            this.f1221a.write(cCharAt3);
            this.f1221a.write(cCharAt4);
            this.f1224d += 4;
            this.f1223c = 0;
            this.f1222b = 0;
        }
    }

    @Override // java.io.OutputStream, java.io.Closeable, java.lang.AutoCloseable
    public final void close() throws IOException {
        m260a();
        this.f1221a.close();
    }

    @Override // java.io.OutputStream
    public final void write(int i) throws IOException {
        this.f1222b = ((i & 255) << (16 - (this.f1223c * 8))) | this.f1222b;
        this.f1223c++;
        if (this.f1223c == 3) {
            m260a();
        }
    }
}
