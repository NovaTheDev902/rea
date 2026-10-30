package com.lenovo.lps.sus.p003a.p004a.p006b;

import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: renamed from: com.lenovo.lps.sus.a.a.b.a */
/* JADX INFO: loaded from: classes.dex */
final class C0082a extends InputStream {

    /* JADX INFO: renamed from: a */
    private InputStream f1217a;

    /* JADX INFO: renamed from: b */
    private int[] f1218b;

    /* JADX INFO: renamed from: c */
    private int f1219c = 0;

    /* JADX INFO: renamed from: d */
    private boolean f1220d = false;

    public C0082a(InputStream inputStream) {
        this.f1217a = inputStream;
    }

    @Override // java.io.InputStream, java.io.Closeable, java.lang.AutoCloseable
    public final void close() throws IOException {
        this.f1217a.close();
    }

    @Override // java.io.InputStream
    public final int read() throws IOException {
        int i = 1;
        if (this.f1218b == null || this.f1219c == this.f1218b.length) {
            if (this.f1220d) {
                return -1;
            }
            char[] cArr = new char[4];
            int i2 = 0;
            while (true) {
                int i3 = this.f1217a.read();
                if (i3 == -1) {
                    if (i2 == 0) {
                        this.f1218b = new int[0];
                        this.f1220d = true;
                        break;
                    }
                    throw new IOException("Bad base64 stream");
                }
                char c = (char) i3;
                if ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".indexOf(c) != -1 || c == '=') {
                    cArr[i2] = c;
                    i2++;
                } else if (c != '\r' && c != '\n') {
                    throw new IOException("Bad base64 stream");
                }
                if (i2 >= 4) {
                    boolean z = false;
                    for (int i4 = 0; i4 < 4; i4++) {
                        if (cArr[i4] != '=') {
                            if (z) {
                                throw new IOException("Bad base64 stream");
                            }
                        } else if (!z) {
                            z = true;
                        }
                    }
                    if (cArr[3] != '=') {
                        i = 3;
                    } else {
                        if (this.f1217a.read() != -1) {
                            throw new IOException("Bad base64 stream");
                        }
                        this.f1220d = true;
                        if (cArr[2] != '=') {
                            i = 2;
                        }
                    }
                    int iIndexOf = 0;
                    for (int i5 = 0; i5 < 4; i5++) {
                        if (cArr[i5] != '=') {
                            iIndexOf |= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/".indexOf(cArr[i5]) << ((3 - i5) * 6);
                        }
                    }
                    this.f1218b = new int[i];
                    for (int i6 = 0; i6 < i; i6++) {
                        this.f1218b[i6] = (iIndexOf >>> ((2 - i6) * 8)) & 255;
                    }
                    break;
                }
            }
            if (this.f1218b.length == 0) {
                this.f1218b = null;
                return -1;
            }
            this.f1219c = 0;
        }
        int[] iArr = this.f1218b;
        int i7 = this.f1219c;
        this.f1219c = i7 + 1;
        return iArr[i7];
    }
}
