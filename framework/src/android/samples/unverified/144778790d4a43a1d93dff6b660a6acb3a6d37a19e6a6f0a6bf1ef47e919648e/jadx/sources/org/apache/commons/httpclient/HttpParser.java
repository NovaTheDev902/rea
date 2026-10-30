package org.apache.commons.httpclient;

import com.lenovo.lps.sus.p008c.C0092c;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class HttpParser {

    /* JADX INFO: renamed from: a */
    static Class f6509a;

    /* JADX INFO: renamed from: b */
    private static final Log f6510b;

    static {
        Class clsM2716a;
        if (f6509a == null) {
            clsM2716a = m2716a("org.apache.commons.httpclient.HttpParser");
            f6509a = clsM2716a;
        } else {
            clsM2716a = f6509a;
        }
        f6510b = LogFactory.getLog(clsM2716a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2716a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    private HttpParser() {
    }

    public static byte[] readRawLine(InputStream inputStream) throws IOException {
        int ch;
        f6510b.trace("enter HttpParser.readRawLine()");
        ByteArrayOutputStream buf = new ByteArrayOutputStream();
        do {
            ch = inputStream.read();
            if (ch < 0) {
                break;
            }
            buf.write(ch);
        } while (ch != 10);
        if (buf.size() == 0) {
            return null;
        }
        return buf.toByteArray();
    }

    public static String readLine(InputStream inputStream, String charset) throws IOException {
        f6510b.trace("enter HttpParser.readLine(InputStream, String)");
        byte[] rawdata = readRawLine(inputStream);
        if (rawdata == null) {
            return null;
        }
        int len = rawdata.length;
        int offset = 0;
        if (len > 0 && rawdata[len - 1] == 10) {
            offset = 0 + 1;
            if (len > 1 && rawdata[len - 2] == 13) {
                offset++;
            }
        }
        String result = EncodingUtil.getString(rawdata, 0, len - offset, charset);
        if (C1131e.f6660a.m2817a()) {
            String logoutput = result;
            if (offset == 2) {
                logoutput = new StringBuffer().append(result).append("\r\n").toString();
            } else if (offset == 1) {
                logoutput = new StringBuffer().append(result).append("\n").toString();
            }
            C1131e.f6660a.m2819b(logoutput);
            return result;
        }
        return result;
    }

    public static String readLine(InputStream inputStream) throws IOException {
        f6510b.trace("enter HttpParser.readLine(InputStream)");
        return readLine(inputStream, "US-ASCII");
    }

    public static Header[] parseHeaders(InputStream is, String charset) throws IOException {
        f6510b.trace("enter HeaderParser.parseHeaders(InputStream, String)");
        ArrayList headers = new ArrayList();
        String name = null;
        StringBuffer value = null;
        while (true) {
            String line = readLine(is, charset);
            if (line == null || line.trim().length() < 1) {
                break;
            }
            if (line.charAt(0) == ' ' || line.charAt(0) == '\t') {
                if (value != null) {
                    value.append(' ');
                    value.append(line.trim());
                }
            } else {
                if (name != null) {
                    headers.add(new Header(name, value.toString()));
                }
                int colon = line.indexOf(C0092c.f1283N);
                if (colon < 0) {
                    throw new ProtocolException(new StringBuffer().append("Unable to parse header: ").append(line).toString());
                }
                name = line.substring(0, colon).trim();
                value = new StringBuffer(line.substring(colon + 1).trim());
            }
        }
        if (name != null) {
            headers.add(new Header(name, value.toString()));
        }
        return (Header[]) headers.toArray(new Header[headers.size()]);
    }

    public static Header[] parseHeaders(InputStream is) throws IOException {
        f6510b.trace("enter HeaderParser.parseHeaders(InputStream, String)");
        return parseHeaders(is, "US-ASCII");
    }
}
