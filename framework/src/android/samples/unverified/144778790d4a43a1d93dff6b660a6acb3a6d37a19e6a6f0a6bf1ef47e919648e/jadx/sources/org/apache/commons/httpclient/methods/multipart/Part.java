package org.apache.commons.httpclient.methods.multipart;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public abstract class Part {
    protected static final String BOUNDARY = "----------------314159265358979323846";
    protected static final byte[] BOUNDARY_BYTES;
    protected static final String CHARSET = "; charset=";
    protected static final byte[] CHARSET_BYTES;
    protected static final String CONTENT_DISPOSITION = "Content-Disposition: form-data; name=";
    protected static final byte[] CONTENT_DISPOSITION_BYTES;
    protected static final String CONTENT_TRANSFER_ENCODING = "Content-Transfer-Encoding: ";
    protected static final byte[] CONTENT_TRANSFER_ENCODING_BYTES;
    protected static final String CONTENT_TYPE = "Content-Type: ";
    protected static final byte[] CONTENT_TYPE_BYTES;
    protected static final String CRLF = "\r\n";
    protected static final byte[] CRLF_BYTES;
    protected static final String EXTRA = "--";
    protected static final byte[] EXTRA_BYTES;
    protected static final String QUOTE = "\"";
    protected static final byte[] QUOTE_BYTES;

    /* JADX INFO: renamed from: a */
    private static final Log f6716a;

    /* JADX INFO: renamed from: b */
    static Class f6717b;

    /* JADX INFO: renamed from: c */
    private static final byte[] f6718c;

    /* JADX INFO: renamed from: d */
    private byte[] f6719d;

    public abstract String getCharSet();

    public abstract String getContentType();

    public abstract String getName();

    public abstract String getTransferEncoding();

    protected abstract long lengthOfData() throws IOException;

    protected abstract void sendData(OutputStream outputStream) throws IOException;

    static {
        Class clsM2831a;
        if (f6717b == null) {
            clsM2831a = m2831a("org.apache.commons.httpclient.methods.multipart.Part");
            f6717b = clsM2831a;
        } else {
            clsM2831a = f6717b;
        }
        f6716a = LogFactory.getLog(clsM2831a);
        BOUNDARY_BYTES = EncodingUtil.getAsciiBytes(BOUNDARY);
        f6718c = BOUNDARY_BYTES;
        CRLF_BYTES = EncodingUtil.getAsciiBytes(CRLF);
        QUOTE_BYTES = EncodingUtil.getAsciiBytes("\"");
        EXTRA_BYTES = EncodingUtil.getAsciiBytes(EXTRA);
        CONTENT_DISPOSITION_BYTES = EncodingUtil.getAsciiBytes(CONTENT_DISPOSITION);
        CONTENT_TYPE_BYTES = EncodingUtil.getAsciiBytes(CONTENT_TYPE);
        CHARSET_BYTES = EncodingUtil.getAsciiBytes(CHARSET);
        CONTENT_TRANSFER_ENCODING_BYTES = EncodingUtil.getAsciiBytes(CONTENT_TRANSFER_ENCODING);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2831a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public static String getBoundary() {
        return BOUNDARY;
    }

    protected byte[] getPartBoundary() {
        return this.f6719d == null ? f6718c : this.f6719d;
    }

    public boolean isRepeatable() {
        return true;
    }

    protected void sendStart(OutputStream out) throws IOException {
        f6716a.trace("enter sendStart(OutputStream out)");
        out.write(EXTRA_BYTES);
        out.write(getPartBoundary());
        out.write(CRLF_BYTES);
    }

    protected void sendDispositionHeader(OutputStream out) throws IOException {
        f6716a.trace("enter sendDispositionHeader(OutputStream out)");
        out.write(CONTENT_DISPOSITION_BYTES);
        out.write(QUOTE_BYTES);
        out.write(EncodingUtil.getAsciiBytes(getName()));
        out.write(QUOTE_BYTES);
    }

    protected void sendContentTypeHeader(OutputStream out) throws IOException {
        f6716a.trace("enter sendContentTypeHeader(OutputStream out)");
        String contentType = getContentType();
        if (contentType != null) {
            out.write(CRLF_BYTES);
            out.write(CONTENT_TYPE_BYTES);
            out.write(EncodingUtil.getAsciiBytes(contentType));
            String charSet = getCharSet();
            if (charSet != null) {
                out.write(CHARSET_BYTES);
                out.write(EncodingUtil.getAsciiBytes(charSet));
            }
        }
    }

    protected void sendTransferEncodingHeader(OutputStream out) throws IOException {
        f6716a.trace("enter sendTransferEncodingHeader(OutputStream out)");
        String transferEncoding = getTransferEncoding();
        if (transferEncoding != null) {
            out.write(CRLF_BYTES);
            out.write(CONTENT_TRANSFER_ENCODING_BYTES);
            out.write(EncodingUtil.getAsciiBytes(transferEncoding));
        }
    }

    protected void sendEndOfHeader(OutputStream out) throws IOException {
        f6716a.trace("enter sendEndOfHeader(OutputStream out)");
        out.write(CRLF_BYTES);
        out.write(CRLF_BYTES);
    }

    protected void sendEnd(OutputStream out) throws IOException {
        f6716a.trace("enter sendEnd(OutputStream out)");
        out.write(CRLF_BYTES);
    }

    public void send(OutputStream out) throws IOException {
        f6716a.trace("enter send(OutputStream out)");
        sendStart(out);
        sendDispositionHeader(out);
        sendContentTypeHeader(out);
        sendTransferEncodingHeader(out);
        sendEndOfHeader(out);
        sendData(out);
        sendEnd(out);
    }

    public long length() throws IOException {
        f6716a.trace("enter length()");
        if (lengthOfData() < 0) {
            return -1L;
        }
        ByteArrayOutputStream overhead = new ByteArrayOutputStream();
        sendStart(overhead);
        sendDispositionHeader(overhead);
        sendContentTypeHeader(overhead);
        sendTransferEncodingHeader(overhead);
        sendEndOfHeader(overhead);
        sendEnd(overhead);
        return ((long) overhead.size()) + lengthOfData();
    }

    public String toString() {
        return getName();
    }

    public static void sendParts(OutputStream out, Part[] parts) throws IOException {
        sendParts(out, parts, f6718c);
    }

    public static void sendParts(OutputStream out, Part[] parts, byte[] partBoundary) throws IOException {
        if (parts == null) {
            throw new IllegalArgumentException("Parts may not be null");
        }
        if (partBoundary == null || partBoundary.length == 0) {
            throw new IllegalArgumentException("partBoundary may not be empty");
        }
        for (int i = 0; i < parts.length; i++) {
            parts[i].f6719d = partBoundary;
            parts[i].send(out);
        }
        out.write(EXTRA_BYTES);
        out.write(partBoundary);
        out.write(EXTRA_BYTES);
        out.write(CRLF_BYTES);
    }

    public static long getLengthOfParts(Part[] parts) throws IOException {
        return getLengthOfParts(parts, f6718c);
    }

    public static long getLengthOfParts(Part[] parts, byte[] partBoundary) throws IOException {
        f6716a.trace("getLengthOfParts(Parts[])");
        if (parts == null) {
            throw new IllegalArgumentException("Parts may not be null");
        }
        long total = 0;
        for (int i = 0; i < parts.length; i++) {
            parts[i].f6719d = partBoundary;
            long l = parts[i].length();
            if (l < 0) {
                return -1L;
            }
            total += l;
        }
        return total + ((long) EXTRA_BYTES.length) + ((long) partBoundary.length) + ((long) EXTRA_BYTES.length) + ((long) CRLF_BYTES.length);
    }
}
