package org.apache.commons.httpclient.util;

import java.io.UnsupportedEncodingException;
import org.apache.commons.codec.net.URLCodec;
import org.apache.commons.httpclient.HttpClientError;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class EncodingUtil {

    /* JADX INFO: renamed from: a */
    static Class f6764a;

    /* JADX INFO: renamed from: b */
    private static final Log f6765b;

    static {
        Class clsM2841a;
        if (f6764a == null) {
            clsM2841a = m2841a("org.apache.commons.httpclient.util.EncodingUtil");
            f6764a = clsM2841a;
        } else {
            clsM2841a = f6764a;
        }
        f6765b = LogFactory.getLog(clsM2841a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2841a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public static String formUrlEncode(NameValuePair[] pairs, String charset) {
        try {
            return m2842a(pairs, charset);
        } catch (UnsupportedEncodingException e) {
            f6765b.error(new StringBuffer().append("Encoding not supported: ").append(charset).toString());
            try {
                return m2842a(pairs, "ISO-8859-1");
            } catch (UnsupportedEncodingException e2) {
                throw new HttpClientError("Encoding not supported: ISO-8859-1");
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private static String m2842a(NameValuePair[] pairs, String charset) throws UnsupportedEncodingException {
        StringBuffer buf = new StringBuffer();
        for (int i = 0; i < pairs.length; i++) {
            URLCodec codec = new URLCodec();
            NameValuePair pair = pairs[i];
            if (pair.getName() != null) {
                if (i > 0) {
                    buf.append("&");
                }
                buf.append(codec.encode(pair.getName(), charset));
                buf.append("=");
                if (pair.getValue() != null) {
                    buf.append(codec.encode(pair.getValue(), charset));
                }
            }
        }
        return buf.toString();
    }

    public static String getString(byte[] data, int offset, int length, String charset) {
        if (data == null) {
            throw new IllegalArgumentException("Parameter may not be null");
        }
        if (charset == null || charset.length() == 0) {
            throw new IllegalArgumentException("charset may not be null or empty");
        }
        try {
            return new String(data, offset, length, charset);
        } catch (UnsupportedEncodingException e) {
            if (f6765b.isWarnEnabled()) {
                f6765b.warn(new StringBuffer().append("Unsupported encoding: ").append(charset).append(". System encoding used").toString());
            }
            return new String(data, offset, length);
        }
    }

    public static String getString(byte[] data, String charset) {
        return getString(data, 0, data.length, charset);
    }

    public static byte[] getBytes(String data, String charset) {
        if (data == null) {
            throw new IllegalArgumentException("data may not be null");
        }
        if (charset == null || charset.length() == 0) {
            throw new IllegalArgumentException("charset may not be null or empty");
        }
        try {
            return data.getBytes(charset);
        } catch (UnsupportedEncodingException e) {
            if (f6765b.isWarnEnabled()) {
                f6765b.warn(new StringBuffer().append("Unsupported encoding: ").append(charset).append(". System encoding used.").toString());
            }
            return data.getBytes();
        }
    }

    public static byte[] getAsciiBytes(String data) {
        if (data == null) {
            throw new IllegalArgumentException("Parameter may not be null");
        }
        try {
            return data.getBytes("US-ASCII");
        } catch (UnsupportedEncodingException e) {
            throw new HttpClientError("HttpClient requires ASCII support");
        }
    }

    public static String getAsciiString(byte[] data, int offset, int length) {
        if (data == null) {
            throw new IllegalArgumentException("Parameter may not be null");
        }
        try {
            return new String(data, offset, length, "US-ASCII");
        } catch (UnsupportedEncodingException e) {
            throw new HttpClientError("HttpClient requires ASCII support");
        }
    }

    public static String getAsciiString(byte[] data) {
        return getAsciiString(data, 0, data.length);
    }

    private EncodingUtil() {
    }
}
