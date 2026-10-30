package org.apache.commons.httpclient.util;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ProtocolException;
import java.net.URL;
import java.security.Permission;
import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpMethod;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class HttpURLConnection extends java.net.HttpURLConnection {

    /* JADX INFO: renamed from: a */
    static Class f6771a;

    /* JADX INFO: renamed from: b */
    private static final Log f6772b;

    /* JADX INFO: renamed from: c */
    private HttpMethod f6773c;

    /* JADX INFO: renamed from: d */
    private URL f6774d;

    static {
        Class clsM2846a;
        if (f6771a == null) {
            clsM2846a = m2846a("org.apache.commons.httpclient.util.HttpURLConnection");
            f6771a = clsM2846a;
        } else {
            clsM2846a = f6771a;
        }
        f6772b = LogFactory.getLog(clsM2846a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2846a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public HttpURLConnection(HttpMethod method, URL url) {
        super(url);
        this.f6773c = method;
        this.f6774d = url;
    }

    protected HttpURLConnection(URL url) {
        super(url);
        throw new RuntimeException("An HTTP URL connection can only be constructed from a HttpMethod class");
    }

    @Override // java.net.URLConnection
    public InputStream getInputStream() throws IOException {
        f6772b.trace("enter HttpURLConnection.getInputStream()");
        return this.f6773c.getResponseBodyAsStream();
    }

    @Override // java.net.HttpURLConnection
    public InputStream getErrorStream() {
        f6772b.trace("enter HttpURLConnection.getErrorStream()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.HttpURLConnection
    public void disconnect() {
        f6772b.trace("enter HttpURLConnection.disconnect()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public void connect() throws IOException {
        f6772b.trace("enter HttpURLConnection.connect()");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.HttpURLConnection
    public boolean usingProxy() {
        f6772b.trace("enter HttpURLConnection.usingProxy()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.HttpURLConnection
    public String getRequestMethod() {
        f6772b.trace("enter HttpURLConnection.getRequestMethod()");
        return this.f6773c.getName();
    }

    @Override // java.net.HttpURLConnection
    public int getResponseCode() throws IOException {
        f6772b.trace("enter HttpURLConnection.getResponseCode()");
        return this.f6773c.getStatusCode();
    }

    @Override // java.net.HttpURLConnection
    public String getResponseMessage() throws IOException {
        f6772b.trace("enter HttpURLConnection.getResponseMessage()");
        return this.f6773c.getStatusText();
    }

    @Override // java.net.URLConnection
    public String getHeaderField(String name) {
        f6772b.trace("enter HttpURLConnection.getHeaderField(String)");
        Header[] headers = this.f6773c.getResponseHeaders();
        for (int i = headers.length - 1; i >= 0; i--) {
            if (headers[i].getName().equalsIgnoreCase(name)) {
                return headers[i].getValue();
            }
        }
        return null;
    }

    @Override // java.net.HttpURLConnection, java.net.URLConnection
    public String getHeaderFieldKey(int keyPosition) {
        f6772b.trace("enter HttpURLConnection.getHeaderFieldKey(int)");
        if (keyPosition == 0) {
            return null;
        }
        Header[] headers = this.f6773c.getResponseHeaders();
        if (keyPosition < 0 || keyPosition > headers.length) {
            return null;
        }
        return headers[keyPosition - 1].getName();
    }

    @Override // java.net.HttpURLConnection, java.net.URLConnection
    public String getHeaderField(int position) {
        f6772b.trace("enter HttpURLConnection.getHeaderField(int)");
        if (position == 0) {
            return this.f6773c.getStatusLine().toString();
        }
        Header[] headers = this.f6773c.getResponseHeaders();
        if (position < 0 || position > headers.length) {
            return null;
        }
        return headers[position - 1].getValue();
    }

    @Override // java.net.URLConnection
    public URL getURL() {
        f6772b.trace("enter HttpURLConnection.getURL()");
        return this.f6774d;
    }

    @Override // java.net.HttpURLConnection
    public void setInstanceFollowRedirects(boolean isFollowingRedirects) {
        f6772b.trace("enter HttpURLConnection.setInstanceFollowRedirects(boolean)");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.HttpURLConnection
    public boolean getInstanceFollowRedirects() {
        f6772b.trace("enter HttpURLConnection.getInstanceFollowRedirects()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.HttpURLConnection
    public void setRequestMethod(String method) throws ProtocolException {
        f6772b.trace("enter HttpURLConnection.setRequestMethod(String)");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.HttpURLConnection, java.net.URLConnection
    public Permission getPermission() throws IOException {
        f6772b.trace("enter HttpURLConnection.getPermission()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public Object getContent() throws IOException {
        f6772b.trace("enter HttpURLConnection.getContent()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public Object getContent(Class[] classes) throws IOException {
        f6772b.trace("enter HttpURLConnection.getContent(Class[])");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public OutputStream getOutputStream() throws IOException {
        f6772b.trace("enter HttpURLConnection.getOutputStream()");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public void setDoInput(boolean isInput) {
        f6772b.trace("enter HttpURLConnection.setDoInput()");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public boolean getDoInput() {
        f6772b.trace("enter HttpURLConnection.getDoInput()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public void setDoOutput(boolean isOutput) {
        f6772b.trace("enter HttpURLConnection.setDoOutput()");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public boolean getDoOutput() {
        f6772b.trace("enter HttpURLConnection.getDoOutput()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public void setAllowUserInteraction(boolean isAllowInteraction) {
        f6772b.trace("enter HttpURLConnection.setAllowUserInteraction(boolean)");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public boolean getAllowUserInteraction() {
        f6772b.trace("enter HttpURLConnection.getAllowUserInteraction()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public void setUseCaches(boolean isUsingCaches) {
        f6772b.trace("enter HttpURLConnection.setUseCaches(boolean)");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public boolean getUseCaches() {
        f6772b.trace("enter HttpURLConnection.getUseCaches()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public void setIfModifiedSince(long modificationDate) {
        f6772b.trace("enter HttpURLConnection.setIfModifiedSince(long)");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public long getIfModifiedSince() {
        f6772b.trace("enter HttpURLConnection.getIfmodifiedSince()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public boolean getDefaultUseCaches() {
        f6772b.trace("enter HttpURLConnection.getDefaultUseCaches()");
        throw new RuntimeException("Not implemented yet");
    }

    @Override // java.net.URLConnection
    public void setDefaultUseCaches(boolean isUsingCaches) {
        f6772b.trace("enter HttpURLConnection.setDefaultUseCaches(boolean)");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public void setRequestProperty(String key, String value) {
        f6772b.trace("enter HttpURLConnection.setRequestProperty()");
        throw new RuntimeException("This class can only be used with alreadyretrieved data");
    }

    @Override // java.net.URLConnection
    public String getRequestProperty(String key) {
        f6772b.trace("enter HttpURLConnection.getRequestProperty()");
        throw new RuntimeException("Not implemented yet");
    }
}
