package org.apache.commons.httpclient.methods.multipart;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class FilePart extends PartBase {
    public static final String DEFAULT_CHARSET = "ISO-8859-1";
    public static final String DEFAULT_CONTENT_TYPE = "application/octet-stream";
    public static final String DEFAULT_TRANSFER_ENCODING = "binary";
    protected static final String FILE_NAME = "; filename=";

    /* JADX INFO: renamed from: a */
    static Class f6705a;

    /* JADX INFO: renamed from: c */
    private static final Log f6706c;

    /* JADX INFO: renamed from: d */
    private static final byte[] f6707d;

    /* JADX INFO: renamed from: e */
    private PartSource f6708e;

    static {
        Class clsM2829a;
        if (f6705a == null) {
            clsM2829a = m2829a("org.apache.commons.httpclient.methods.multipart.FilePart");
            f6705a = clsM2829a;
        } else {
            clsM2829a = f6705a;
        }
        f6706c = LogFactory.getLog(clsM2829a);
        f6707d = EncodingUtil.getAsciiBytes(FILE_NAME);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2829a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public FilePart(String name, PartSource partSource, String contentType, String charset) {
        super(name, contentType == null ? DEFAULT_CONTENT_TYPE : contentType, charset == null ? "ISO-8859-1" : charset, "binary");
        if (partSource == null) {
            throw new IllegalArgumentException("Source may not be null");
        }
        this.f6708e = partSource;
    }

    public FilePart(String name, PartSource partSource) {
        this(name, partSource, (String) null, (String) null);
    }

    public FilePart(String name, File file) throws FileNotFoundException {
        this(name, new FilePartSource(file), (String) null, (String) null);
    }

    public FilePart(String name, File file, String contentType, String charset) throws FileNotFoundException {
        this(name, new FilePartSource(file), contentType, charset);
    }

    public FilePart(String name, String fileName, File file) throws FileNotFoundException {
        this(name, new FilePartSource(fileName, file), (String) null, (String) null);
    }

    public FilePart(String name, String fileName, File file, String contentType, String charset) throws FileNotFoundException {
        this(name, new FilePartSource(fileName, file), contentType, charset);
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    protected void sendDispositionHeader(OutputStream out) throws IOException {
        f6706c.trace("enter sendDispositionHeader(OutputStream out)");
        super.sendDispositionHeader(out);
        String filename = this.f6708e.getFileName();
        if (filename != null) {
            out.write(f6707d);
            out.write(QUOTE_BYTES);
            out.write(EncodingUtil.getAsciiBytes(filename));
            out.write(QUOTE_BYTES);
        }
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    protected void sendData(OutputStream out) throws IOException {
        f6706c.trace("enter sendData(OutputStream out)");
        if (lengthOfData() == 0) {
            f6706c.debug("No data to send.");
            return;
        }
        byte[] tmp = new byte[4096];
        InputStream instream = this.f6708e.createInputStream();
        while (true) {
            try {
                int len = instream.read(tmp);
                if (len >= 0) {
                    out.write(tmp, 0, len);
                } else {
                    instream.close();
                    return;
                }
            } catch (Throwable th) {
                instream.close();
                throw th;
            }
        }
    }

    protected PartSource getSource() {
        f6706c.trace("enter getSource()");
        return this.f6708e;
    }

    @Override // org.apache.commons.httpclient.methods.multipart.Part
    protected long lengthOfData() throws IOException {
        f6706c.trace("enter lengthOfData()");
        return this.f6708e.getLength();
    }
}
