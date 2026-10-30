package org.apache.commons.httpclient;

import com.lenovo.lps.sus.p008c.C0092c;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: renamed from: org.apache.commons.httpclient.e */
/* JADX INFO: compiled from: Wire.java */
/* JADX INFO: loaded from: classes.dex */
final class C1131e {

    /* JADX INFO: renamed from: a */
    public static C1131e f6660a = new C1131e(LogFactory.getLog("httpclient.wire.header"));

    /* JADX INFO: renamed from: b */
    public static C1131e f6661b = new C1131e(LogFactory.getLog("httpclient.wire.content"));

    /* JADX INFO: renamed from: c */
    private Log f6662c;

    private C1131e(Log log) {
        this.f6662c = log;
    }

    /* JADX INFO: renamed from: a */
    private void m2811a(String header, InputStream instream) throws IOException {
        StringBuffer buffer = new StringBuffer();
        while (true) {
            int ch = instream.read();
            if (ch == -1) {
                break;
            }
            if (ch == 13) {
                buffer.append("[\\r]");
            } else if (ch == 10) {
                buffer.append("[\\n]\"");
                buffer.insert(0, C0092c.f1282M);
                buffer.insert(0, header);
                this.f6662c.debug(buffer.toString());
                buffer.setLength(0);
            } else if (ch < 32 || ch > 127) {
                buffer.append("[0x");
                buffer.append(Integer.toHexString(ch));
                buffer.append("]");
            } else {
                buffer.append((char) ch);
            }
        }
        if (buffer.length() > 0) {
            buffer.append(C0092c.f1282M);
            buffer.insert(0, C0092c.f1282M);
            buffer.insert(0, header);
            this.f6662c.debug(buffer.toString());
        }
    }

    /* JADX INFO: renamed from: a */
    public final boolean m2817a() {
        return this.f6662c.isDebugEnabled();
    }

    /* JADX INFO: renamed from: a */
    public final void m2816a(byte[] b, int off, int len) throws IOException {
        if (b == null) {
            throw new IllegalArgumentException("Output may not be null");
        }
        m2811a(">> ", new ByteArrayInputStream(b, off, len));
    }

    /* JADX INFO: renamed from: b */
    public final void m2820b(byte[] b, int off, int len) throws IOException {
        if (b == null) {
            throw new IllegalArgumentException("Input may not be null");
        }
        m2811a("<< ", new ByteArrayInputStream(b, off, len));
    }

    /* JADX INFO: renamed from: a */
    public final void m2815a(byte[] b) throws IOException {
        if (b == null) {
            throw new IllegalArgumentException("Output may not be null");
        }
        m2811a(">> ", new ByteArrayInputStream(b));
    }

    /* JADX INFO: renamed from: b */
    private void m2812b(byte[] b) throws IOException {
        if (b == null) {
            throw new IllegalArgumentException("Input may not be null");
        }
        m2811a("<< ", new ByteArrayInputStream(b));
    }

    /* JADX INFO: renamed from: a */
    public final void m2813a(int b) throws IOException {
        m2815a(new byte[]{(byte) b});
    }

    /* JADX INFO: renamed from: b */
    public final void m2818b(int b) throws IOException {
        m2812b(new byte[]{(byte) b});
    }

    /* JADX INFO: renamed from: a */
    public final void m2814a(String s) throws IOException {
        if (s == null) {
            throw new IllegalArgumentException("Output may not be null");
        }
        m2815a(s.getBytes());
    }

    /* JADX INFO: renamed from: b */
    public final void m2819b(String s) throws IOException {
        if (s == null) {
            throw new IllegalArgumentException("Input may not be null");
        }
        m2812b(s.getBytes());
    }
}
