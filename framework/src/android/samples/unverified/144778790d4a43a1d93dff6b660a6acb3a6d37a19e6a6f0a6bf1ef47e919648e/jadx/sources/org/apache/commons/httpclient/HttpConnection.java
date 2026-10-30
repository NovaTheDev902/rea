package org.apache.commons.httpclient;

import com.lenovo.lps.sus.p008c.C0092c;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InterruptedIOException;
import java.io.OutputStream;
import java.lang.reflect.Method;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.commons.httpclient.protocol.Protocol;
import org.apache.commons.httpclient.protocol.ProtocolSocketFactory;
import org.apache.commons.httpclient.protocol.SecureProtocolSocketFactory;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.httpclient.util.ExceptionUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class HttpConnection {

    /* JADX INFO: renamed from: a */
    static Class f6458a;

    /* JADX INFO: renamed from: b */
    private static final byte[] f6459b = {13, 10};

    /* JADX INFO: renamed from: c */
    private static final Log f6460c;

    /* JADX INFO: renamed from: d */
    private String f6461d;

    /* JADX INFO: renamed from: e */
    private int f6462e;

    /* JADX INFO: renamed from: f */
    private String f6463f;

    /* JADX INFO: renamed from: g */
    private int f6464g;

    /* JADX INFO: renamed from: h */
    private Socket f6465h;

    /* JADX INFO: renamed from: i */
    private InputStream f6466i;
    protected boolean isOpen;

    /* JADX INFO: renamed from: j */
    private OutputStream f6467j;

    /* JADX INFO: renamed from: k */
    private InputStream f6468k;

    /* JADX INFO: renamed from: l */
    private Protocol f6469l;

    /* JADX INFO: renamed from: m */
    private HttpConnectionParams f6470m;

    /* JADX INFO: renamed from: n */
    private boolean f6471n;

    /* JADX INFO: renamed from: o */
    private boolean f6472o;

    /* JADX INFO: renamed from: p */
    private boolean f6473p;

    /* JADX INFO: renamed from: q */
    private HttpConnectionManager f6474q;

    /* JADX INFO: renamed from: r */
    private InetAddress f6475r;

    public HttpConnection(String host, int port) {
        this(null, -1, host, null, port, Protocol.getProtocol("http"));
    }

    public HttpConnection(String host, int port, Protocol protocol) {
        this(null, -1, host, null, port, protocol);
    }

    public HttpConnection(String host, String virtualHost, int port, Protocol protocol) {
        this(null, -1, host, virtualHost, port, protocol);
    }

    public HttpConnection(String proxyHost, int proxyPort, String host, int port) {
        this(proxyHost, proxyPort, host, null, port, Protocol.getProtocol("http"));
    }

    public HttpConnection(HostConfiguration hostConfiguration) {
        this(hostConfiguration.getProxyHost(), hostConfiguration.getProxyPort(), hostConfiguration.getHost(), hostConfiguration.getPort(), hostConfiguration.getProtocol());
        this.f6475r = hostConfiguration.getLocalAddress();
    }

    public HttpConnection(String proxyHost, int proxyPort, String host, String virtualHost, int port, Protocol protocol) {
        this(proxyHost, proxyPort, host, port, protocol);
    }

    public HttpConnection(String proxyHost, int proxyPort, String host, int port, Protocol protocol) {
        this.f6461d = null;
        this.f6462e = -1;
        this.f6463f = null;
        this.f6464g = -1;
        this.f6465h = null;
        this.f6466i = null;
        this.f6467j = null;
        this.f6468k = null;
        this.isOpen = false;
        this.f6470m = new HttpConnectionParams();
        this.f6471n = false;
        this.f6472o = false;
        this.f6473p = false;
        if (host == null) {
            throw new IllegalArgumentException("host parameter is null");
        }
        if (protocol == null) {
            throw new IllegalArgumentException("protocol is null");
        }
        this.f6463f = proxyHost;
        this.f6464g = proxyPort;
        this.f6461d = host;
        this.f6462e = protocol.resolvePort(port);
        this.f6469l = protocol;
    }

    protected Socket getSocket() {
        return this.f6465h;
    }

    public String getHost() {
        return this.f6461d;
    }

    public void setHost(String host) throws IllegalStateException {
        if (host == null) {
            throw new IllegalArgumentException("host parameter is null");
        }
        assertNotOpen();
        this.f6461d = host;
    }

    public String getVirtualHost() {
        return this.f6461d;
    }

    public void setVirtualHost(String host) throws IllegalStateException {
        assertNotOpen();
    }

    public int getPort() {
        if (this.f6462e < 0) {
            return isSecure() ? 443 : 80;
        }
        return this.f6462e;
    }

    public void setPort(int port) throws IllegalStateException {
        assertNotOpen();
        this.f6462e = port;
    }

    public String getProxyHost() {
        return this.f6463f;
    }

    public void setProxyHost(String host) throws IllegalStateException {
        assertNotOpen();
        this.f6463f = host;
    }

    public int getProxyPort() {
        return this.f6464g;
    }

    public void setProxyPort(int port) throws IllegalStateException {
        assertNotOpen();
        this.f6464g = port;
    }

    public boolean isSecure() {
        return this.f6469l.isSecure();
    }

    public Protocol getProtocol() {
        return this.f6469l;
    }

    public void setProtocol(Protocol protocol) {
        assertNotOpen();
        if (protocol == null) {
            throw new IllegalArgumentException("protocol is null");
        }
        this.f6469l = protocol;
    }

    public InetAddress getLocalAddress() {
        return this.f6475r;
    }

    public void setLocalAddress(InetAddress localAddress) {
        assertNotOpen();
        this.f6475r = localAddress;
    }

    public boolean isOpen() {
        return this.isOpen;
    }

    public boolean closeIfStale() throws IOException {
        if (!this.isOpen || !isStale()) {
            return false;
        }
        f6460c.debug("Connection is stale, closing...");
        close();
        return true;
    }

    public boolean isStaleCheckingEnabled() {
        return this.f6470m.isStaleCheckingEnabled();
    }

    public void setStaleCheckingEnabled(boolean staleCheckEnabled) {
        this.f6470m.setStaleCheckingEnabled(staleCheckEnabled);
    }

    protected boolean isStale() throws IOException {
        if (!this.isOpen) {
            return true;
        }
        boolean isStale = false;
        try {
            if (this.f6466i.available() > 0) {
                return false;
            }
            try {
                this.f6465h.setSoTimeout(1);
                this.f6466i.mark(1);
                int byteRead = this.f6466i.read();
                if (byteRead == -1) {
                    isStale = true;
                } else {
                    this.f6466i.reset();
                }
                return isStale;
            } finally {
                this.f6465h.setSoTimeout(this.f6470m.getSoTimeout());
            }
        } catch (InterruptedIOException e) {
            if (ExceptionUtil.isSocketTimeoutException(e)) {
                return false;
            }
            throw e;
        } catch (IOException e2) {
            f6460c.debug("An error occurred while reading from the socket, is appears to be stale", e2);
            return true;
        }
    }

    public boolean isProxied() {
        return this.f6463f != null && this.f6464g > 0;
    }

    public void setLastResponseInputStream(InputStream inStream) {
        this.f6468k = inStream;
    }

    public InputStream getLastResponseInputStream() {
        return this.f6468k;
    }

    public HttpConnectionParams getParams() {
        return this.f6470m;
    }

    public void setParams(HttpConnectionParams params) {
        if (params == null) {
            throw new IllegalArgumentException("Parameters may not be null");
        }
        this.f6470m = params;
    }

    public void setSoTimeout(int timeout) throws IllegalStateException, SocketException {
        this.f6470m.setSoTimeout(timeout);
        if (this.f6465h != null) {
            this.f6465h.setSoTimeout(timeout);
        }
    }

    public void setSocketTimeout(int timeout) throws IllegalStateException, SocketException {
        assertOpen();
        if (this.f6465h != null) {
            this.f6465h.setSoTimeout(timeout);
        }
    }

    public int getSoTimeout() throws SocketException {
        return this.f6470m.getSoTimeout();
    }

    public void setConnectionTimeout(int timeout) {
        this.f6470m.setConnectionTimeout(timeout);
    }

    public void open() throws IOException {
        ProtocolSocketFactory socketFactory;
        f6460c.trace("enter HttpConnection.open()");
        String host = this.f6463f == null ? this.f6461d : this.f6463f;
        int port = this.f6463f == null ? this.f6462e : this.f6464g;
        assertNotOpen();
        if (f6460c.isDebugEnabled()) {
            f6460c.debug(new StringBuffer().append("Open connection to ").append(host).append(C0092c.f1283N).append(port).toString());
        }
        try {
            if (this.f6465h == null) {
                this.f6472o = isSecure() && !isProxied();
                if (isSecure() && isProxied()) {
                    Protocol defaultprotocol = Protocol.getProtocol("http");
                    socketFactory = defaultprotocol.getSocketFactory();
                } else {
                    socketFactory = this.f6469l.getSocketFactory();
                }
                this.f6465h = socketFactory.createSocket(host, port, this.f6475r, 0, this.f6470m);
            }
            this.f6465h.setTcpNoDelay(this.f6470m.getTcpNoDelay());
            this.f6465h.setSoTimeout(this.f6470m.getSoTimeout());
            int linger = this.f6470m.getLinger();
            if (linger >= 0) {
                this.f6465h.setSoLinger(linger > 0, linger);
            }
            int sndBufSize = this.f6470m.getSendBufferSize();
            if (sndBufSize >= 0) {
                this.f6465h.setSendBufferSize(sndBufSize);
            }
            int rcvBufSize = this.f6470m.getReceiveBufferSize();
            if (rcvBufSize >= 0) {
                this.f6465h.setReceiveBufferSize(rcvBufSize);
            }
            int outbuffersize = this.f6465h.getSendBufferSize();
            if (outbuffersize > 2048 || outbuffersize <= 0) {
                outbuffersize = 2048;
            }
            int inbuffersize = this.f6465h.getReceiveBufferSize();
            if (inbuffersize > 2048 || inbuffersize <= 0) {
                inbuffersize = 2048;
            }
            this.f6466i = new BufferedInputStream(this.f6465h.getInputStream(), inbuffersize);
            this.f6467j = new BufferedOutputStream(this.f6465h.getOutputStream(), outbuffersize);
            this.isOpen = true;
        } catch (IOException e) {
            closeSocketAndStreams();
            throw e;
        }
    }

    public void tunnelCreated() throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.tunnelCreated()");
        if (!isSecure() || !isProxied()) {
            throw new IllegalStateException("Connection must be secure and proxied to use this feature");
        }
        if (this.f6472o) {
            throw new IllegalStateException("Already using a secure socket");
        }
        if (f6460c.isDebugEnabled()) {
            f6460c.debug(new StringBuffer().append("Secure tunnel to ").append(this.f6461d).append(C0092c.f1283N).append(this.f6462e).toString());
        }
        SecureProtocolSocketFactory socketFactory = (SecureProtocolSocketFactory) this.f6469l.getSocketFactory();
        this.f6465h = socketFactory.createSocket(this.f6465h, this.f6461d, this.f6462e, true);
        int sndBufSize = this.f6470m.getSendBufferSize();
        if (sndBufSize >= 0) {
            this.f6465h.setSendBufferSize(sndBufSize);
        }
        int rcvBufSize = this.f6470m.getReceiveBufferSize();
        if (rcvBufSize >= 0) {
            this.f6465h.setReceiveBufferSize(rcvBufSize);
        }
        int outbuffersize = this.f6465h.getSendBufferSize();
        if (outbuffersize > 2048) {
            outbuffersize = 2048;
        }
        int inbuffersize = this.f6465h.getReceiveBufferSize();
        if (inbuffersize > 2048) {
            inbuffersize = 2048;
        }
        this.f6466i = new BufferedInputStream(this.f6465h.getInputStream(), inbuffersize);
        this.f6467j = new BufferedOutputStream(this.f6465h.getOutputStream(), outbuffersize);
        this.f6472o = true;
        this.f6473p = true;
    }

    public boolean isTransparent() {
        return !isProxied() || this.f6473p;
    }

    public void flushRequestOutputStream() throws IOException {
        f6460c.trace("enter HttpConnection.flushRequestOutputStream()");
        assertOpen();
        this.f6467j.flush();
    }

    public OutputStream getRequestOutputStream() throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.getRequestOutputStream()");
        assertOpen();
        OutputStream out = this.f6467j;
        if (C1131e.f6661b.m2817a()) {
            return new C1133g(out, C1131e.f6661b);
        }
        return out;
    }

    public InputStream getResponseInputStream() throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.getResponseInputStream()");
        assertOpen();
        return this.f6466i;
    }

    public boolean isResponseAvailable() throws IOException {
        f6460c.trace("enter HttpConnection.isResponseAvailable()");
        return this.isOpen && this.f6466i.available() > 0;
    }

    public boolean isResponseAvailable(int timeout) throws IOException {
        f6460c.trace("enter HttpConnection.isResponseAvailable(int)");
        assertOpen();
        boolean result = false;
        try {
            if (this.f6466i.available() > 0) {
                return true;
            }
            try {
                this.f6465h.setSoTimeout(timeout);
                this.f6466i.mark(1);
                int byteRead = this.f6466i.read();
                if (byteRead != -1) {
                    this.f6466i.reset();
                    f6460c.debug("Input data available");
                    result = true;
                } else {
                    f6460c.debug("Input data not available");
                }
                try {
                    this.f6465h.setSoTimeout(this.f6470m.getSoTimeout());
                    return result;
                } catch (IOException ioe) {
                    f6460c.debug("An error ocurred while resetting soTimeout, we will assume that no response is available.", ioe);
                    return false;
                }
            } catch (InterruptedIOException e) {
                if (!ExceptionUtil.isSocketTimeoutException(e)) {
                    throw e;
                }
                if (f6460c.isDebugEnabled()) {
                    f6460c.debug(new StringBuffer().append("Input data not available after ").append(timeout).append(" ms").toString());
                }
                try {
                    this.f6465h.setSoTimeout(this.f6470m.getSoTimeout());
                    return false;
                } catch (IOException ioe2) {
                    f6460c.debug("An error ocurred while resetting soTimeout, we will assume that no response is available.", ioe2);
                    return false;
                }
            }
        } catch (Throwable th) {
            try {
                this.f6465h.setSoTimeout(this.f6470m.getSoTimeout());
            } catch (IOException ioe3) {
                f6460c.debug("An error ocurred while resetting soTimeout, we will assume that no response is available.", ioe3);
            }
            throw th;
        }
    }

    public void write(byte[] data) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.write(byte[])");
        write(data, 0, data.length);
    }

    public void write(byte[] data, int offset, int length) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.write(byte[], int, int)");
        if (offset < 0) {
            throw new IllegalArgumentException("Array offset may not be negative");
        }
        if (length < 0) {
            throw new IllegalArgumentException("Array length may not be negative");
        }
        if (offset + length > data.length) {
            throw new IllegalArgumentException("Given offset and length exceed the array length");
        }
        assertOpen();
        this.f6467j.write(data, offset, length);
    }

    public void writeLine(byte[] data) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.writeLine(byte[])");
        write(data);
        writeLine();
    }

    public void writeLine() throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.writeLine()");
        write(f6459b);
    }

    public void print(String data) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.print(String)");
        write(EncodingUtil.getBytes(data, "ISO-8859-1"));
    }

    public void print(String data, String charset) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.print(String)");
        write(EncodingUtil.getBytes(data, charset));
    }

    public void printLine(String data) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.printLine(String)");
        writeLine(EncodingUtil.getBytes(data, "ISO-8859-1"));
    }

    public void printLine(String data, String charset) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.printLine(String)");
        writeLine(EncodingUtil.getBytes(data, charset));
    }

    public void printLine() throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.printLine()");
        writeLine();
    }

    public String readLine() throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.readLine()");
        assertOpen();
        return HttpParser.readLine(this.f6466i);
    }

    public String readLine(String charset) throws IllegalStateException, IOException {
        f6460c.trace("enter HttpConnection.readLine()");
        assertOpen();
        return HttpParser.readLine(this.f6466i, charset);
    }

    public void shutdownOutput() {
        f6460c.trace("enter HttpConnection.shutdownOutput()");
        try {
            Method shutdownOutput = this.f6465h.getClass().getMethod("shutdownOutput", new Class[0]);
            Object[] params = new Object[0];
            shutdownOutput.invoke(this.f6465h, params);
        } catch (Exception ex) {
            f6460c.debug("Unexpected Exception caught", ex);
        }
    }

    public void close() {
        f6460c.trace("enter HttpConnection.close()");
        closeSocketAndStreams();
    }

    public HttpConnectionManager getHttpConnectionManager() {
        return this.f6474q;
    }

    public void setHttpConnectionManager(HttpConnectionManager httpConnectionManager) {
        this.f6474q = httpConnectionManager;
    }

    public void releaseConnection() {
        f6460c.trace("enter HttpConnection.releaseConnection()");
        if (this.f6471n) {
            f6460c.debug("Connection is locked.  Call to releaseConnection() ignored.");
        } else if (this.f6474q != null) {
            f6460c.debug("Releasing connection back to connection manager.");
            this.f6474q.releaseConnection(this);
        } else {
            f6460c.warn("HttpConnectionManager is null.  Connection cannot be released.");
        }
    }

    protected boolean isLocked() {
        return this.f6471n;
    }

    protected void setLocked(boolean locked) {
        this.f6471n = locked;
    }

    protected void closeSocketAndStreams() {
        f6460c.trace("enter HttpConnection.closeSockedAndStreams()");
        this.isOpen = false;
        this.f6468k = null;
        if (this.f6467j != null) {
            OutputStream temp = this.f6467j;
            this.f6467j = null;
            try {
                temp.close();
            } catch (Exception ex) {
                f6460c.debug("Exception caught when closing output", ex);
            }
        }
        if (this.f6466i != null) {
            InputStream temp2 = this.f6466i;
            this.f6466i = null;
            try {
                temp2.close();
            } catch (Exception ex2) {
                f6460c.debug("Exception caught when closing input", ex2);
            }
        }
        if (this.f6465h != null) {
            Socket temp3 = this.f6465h;
            this.f6465h = null;
            try {
                temp3.close();
            } catch (Exception ex3) {
                f6460c.debug("Exception caught when closing socket", ex3);
            }
        }
        this.f6473p = false;
        this.f6472o = false;
    }

    protected void assertNotOpen() throws IllegalStateException {
        if (this.isOpen) {
            throw new IllegalStateException("Connection is open");
        }
    }

    protected void assertOpen() throws IllegalStateException {
        if (!this.isOpen) {
            throw new IllegalStateException("Connection is not open");
        }
    }

    public int getSendBufferSize() throws SocketException {
        if (this.f6465h == null) {
            return -1;
        }
        return this.f6465h.getSendBufferSize();
    }

    public void setSendBufferSize(int sendBufferSize) throws SocketException {
        this.f6470m.setSendBufferSize(sendBufferSize);
    }

    static {
        Class clsM2707a;
        if (f6458a == null) {
            clsM2707a = m2707a("org.apache.commons.httpclient.HttpConnection");
            f6458a = clsM2707a;
        } else {
            clsM2707a = f6458a;
        }
        f6460c = LogFactory.getLog(clsM2707a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2707a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }
}
