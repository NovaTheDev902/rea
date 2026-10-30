package org.apache.commons.httpclient;

import com.lenovo.lps.reaper.sdk.util.Constants;
import com.lenovo.lps.sus.p003a.p004a.p005a.InterfaceC0079b;
import com.lenovo.lps.sus.p008c.C0092c;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InterruptedIOException;
import java.util.Collection;
import org.apache.commons.httpclient.auth.AuthState;
import org.apache.commons.httpclient.cookie.CookiePolicy;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.commons.httpclient.cookie.CookieVersionSupport;
import org.apache.commons.httpclient.cookie.MalformedCookieException;
import org.apache.commons.httpclient.cookie.RFC2109Spec;
import org.apache.commons.httpclient.cookie.RFC2965Spec;
import org.apache.commons.httpclient.params.HttpMethodParams;
import org.apache.commons.httpclient.protocol.Protocol;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.httpclient.util.ExceptionUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public abstract class HttpMethodBase implements HttpMethod {

    /* JADX INFO: renamed from: a */
    private static final Log f6486a;

    /* JADX INFO: renamed from: b */
    static Class f6487b;

    /* JADX INFO: renamed from: s */
    private MethodRetryHandler f6504s;

    /* JADX INFO: renamed from: c */
    private HeaderGroup f6488c = new HeaderGroup();
    protected StatusLine statusLine = null;

    /* JADX INFO: renamed from: d */
    private HeaderGroup f6489d = new HeaderGroup();

    /* JADX INFO: renamed from: e */
    private HeaderGroup f6490e = new HeaderGroup();

    /* JADX INFO: renamed from: f */
    private String f6491f = null;

    /* JADX INFO: renamed from: g */
    private String f6492g = null;

    /* JADX INFO: renamed from: h */
    private InputStream f6493h = null;

    /* JADX INFO: renamed from: i */
    private HttpConnection f6494i = null;

    /* JADX INFO: renamed from: j */
    private byte[] f6495j = null;

    /* JADX INFO: renamed from: k */
    private boolean f6496k = false;

    /* JADX INFO: renamed from: l */
    private boolean f6497l = true;

    /* JADX INFO: renamed from: m */
    private HttpMethodParams f6498m = new HttpMethodParams();

    /* JADX INFO: renamed from: n */
    private AuthState f6499n = new AuthState();

    /* JADX INFO: renamed from: o */
    private AuthState f6500o = new AuthState();

    /* JADX INFO: renamed from: p */
    private boolean f6501p = false;

    /* JADX INFO: renamed from: q */
    private int f6502q = 0;

    /* JADX INFO: renamed from: r */
    private HttpHost f6503r = null;

    /* JADX INFO: renamed from: t */
    private boolean f6505t = false;
    protected HttpVersion effectiveVersion = null;

    /* JADX INFO: renamed from: u */
    private volatile boolean f6506u = false;

    /* JADX INFO: renamed from: v */
    private boolean f6507v = false;

    /* JADX INFO: renamed from: w */
    private CookieSpec f6508w = null;

    @Override // org.apache.commons.httpclient.HttpMethod
    public abstract String getName();

    static {
        Class clsM2711a;
        if (f6487b == null) {
            clsM2711a = m2711a("org.apache.commons.httpclient.HttpMethodBase");
            f6487b = clsM2711a;
        } else {
            clsM2711a = f6487b;
        }
        f6486a = LogFactory.getLog(clsM2711a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2711a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public HttpMethodBase() {
    }

    /* JADX WARN: Code duplicated, block: B:6:0x005a  */
    public HttpMethodBase(String uri) throws IllegalStateException, IllegalArgumentException {
        if (uri != null) {
            try {
                uri = uri.equals("") ? CookieSpec.PATH_DELIM : uri;
            } catch (URIException e) {
                throw new IllegalArgumentException(new StringBuffer().append("Invalid uri '").append(uri).append("': ").append(e.getMessage()).toString());
            }
        }
        String charset = getParams().getUriCharset();
        setURI(new URI(uri, true, charset));
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public URI getURI() throws URIException {
        StringBuffer buffer = new StringBuffer();
        if (this.f6503r != null) {
            buffer.append(this.f6503r.getProtocol().getScheme());
            buffer.append("://");
            buffer.append(this.f6503r.getHostName());
            int port = this.f6503r.getPort();
            if (port != -1 && port != this.f6503r.getProtocol().getDefaultPort()) {
                buffer.append(C0092c.f1283N);
                buffer.append(port);
            }
        }
        buffer.append(this.f6491f);
        if (this.f6492g != null) {
            buffer.append('?');
            buffer.append(this.f6492g);
        }
        String charset = getParams().getUriCharset();
        return new URI(buffer.toString(), true, charset);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setURI(URI uri) throws URIException {
        if (uri.isAbsoluteURI()) {
            this.f6503r = new HttpHost(uri);
        }
        setPath(uri.getPath() == null ? CookieSpec.PATH_DELIM : uri.getEscapedPath());
        setQueryString(uri.getEscapedQuery());
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setFollowRedirects(boolean followRedirects) {
        this.f6496k = followRedirects;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public boolean getFollowRedirects() {
        return this.f6496k;
    }

    public void setHttp11(boolean http11) {
        if (http11) {
            this.f6498m.setVersion(HttpVersion.HTTP_1_1);
        } else {
            this.f6498m.setVersion(HttpVersion.HTTP_1_0);
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public boolean getDoAuthentication() {
        return this.f6497l;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setDoAuthentication(boolean doAuthentication) {
        this.f6497l = doAuthentication;
    }

    public boolean isHttp11() {
        return this.f6498m.getVersion().equals(HttpVersion.HTTP_1_1);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setPath(String path) {
        this.f6491f = path;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void addRequestHeader(Header header) {
        f6486a.trace("HttpMethodBase.addRequestHeader(Header)");
        if (header == null) {
            f6486a.debug("null header value ignored");
        } else {
            getRequestHeaderGroup().addHeader(header);
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void addResponseFooter(Header footer) {
        getResponseTrailerHeaderGroup().addHeader(footer);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public String getPath() {
        return (this.f6491f == null || this.f6491f.equals("")) ? CookieSpec.PATH_DELIM : this.f6491f;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setQueryString(String queryString) {
        this.f6492g = queryString;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setQueryString(NameValuePair[] params) {
        f6486a.trace("enter HttpMethodBase.setQueryString(NameValuePair[])");
        this.f6492g = EncodingUtil.formUrlEncode(params, InterfaceC0079b.f1213a);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public String getQueryString() {
        return this.f6492g;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setRequestHeader(String headerName, String headerValue) {
        Header header = new Header(headerName, headerValue);
        setRequestHeader(header);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setRequestHeader(Header header) {
        Header[] headers = getRequestHeaderGroup().getHeaders(header.getName());
        for (Header header2 : headers) {
            getRequestHeaderGroup().removeHeader(header2);
        }
        getRequestHeaderGroup().addHeader(header);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header getRequestHeader(String headerName) {
        if (headerName == null) {
            return null;
        }
        return getRequestHeaderGroup().getCondensedHeader(headerName);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header[] getRequestHeaders() {
        return getRequestHeaderGroup().getAllHeaders();
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header[] getRequestHeaders(String headerName) {
        return getRequestHeaderGroup().getHeaders(headerName);
    }

    protected HeaderGroup getRequestHeaderGroup() {
        return this.f6488c;
    }

    protected HeaderGroup getResponseTrailerHeaderGroup() {
        return this.f6490e;
    }

    protected HeaderGroup getResponseHeaderGroup() {
        return this.f6489d;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header[] getResponseHeaders(String headerName) {
        return getResponseHeaderGroup().getHeaders(headerName);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public int getStatusCode() {
        return this.statusLine.getStatusCode();
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public StatusLine getStatusLine() {
        return this.statusLine;
    }

    /* JADX INFO: renamed from: a */
    private boolean m2713a() {
        return (this.f6495j == null && this.f6493h == null) ? false : true;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header[] getResponseHeaders() {
        return getResponseHeaderGroup().getAllHeaders();
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header getResponseHeader(String headerName) {
        if (headerName == null) {
            return null;
        }
        return getResponseHeaderGroup().getCondensedHeader(headerName);
    }

    public long getResponseContentLength() {
        long j = -1;
        Header[] headers = getResponseHeaderGroup().getHeaders("Content-Length");
        if (headers.length != 0) {
            if (headers.length > 1) {
                f6486a.warn("Multiple content-length headers detected");
            }
            for (int i = headers.length - 1; i >= 0; i--) {
                Header header = headers[i];
                try {
                    j = Long.parseLong(header.getValue());
                    break;
                } catch (NumberFormatException e) {
                    if (f6486a.isWarnEnabled()) {
                        f6486a.warn(new StringBuffer().append("Invalid content-length value: ").append(e.getMessage()).toString());
                    }
                }
            }
        }
        return j;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public byte[] getResponseBody() throws IOException {
        InputStream instream;
        if (this.f6495j == null && (instream = getResponseBodyAsStream()) != null) {
            long contentLength = getResponseContentLength();
            if (contentLength > 2147483647L) {
                throw new IOException(new StringBuffer().append("Content too large to be buffered: ").append(contentLength).append(" bytes").toString());
            }
            int limit = getParams().getIntParameter(HttpMethodParams.BUFFER_WARN_TRIGGER_LIMIT, 1048576);
            if (contentLength == -1 || contentLength > limit) {
                f6486a.warn("Going to buffer response body of large or unknown size. Using getResponseBodyAsStream instead is recommended.");
            }
            f6486a.debug("Buffering response body");
            ByteArrayOutputStream outstream = new ByteArrayOutputStream(contentLength > 0 ? (int) contentLength : 4096);
            byte[] buffer = new byte[4096];
            while (true) {
                int len = instream.read(buffer);
                if (len <= 0) {
                    break;
                }
                outstream.write(buffer, 0, len);
            }
            outstream.close();
            setResponseStream(null);
            this.f6495j = outstream.toByteArray();
        }
        return this.f6495j;
    }

    public byte[] getResponseBody(int maxlen) throws IOException {
        InputStream instream;
        if (maxlen < 0) {
            throw new IllegalArgumentException("maxlen must be positive");
        }
        if (this.f6495j == null && (instream = getResponseBodyAsStream()) != null) {
            long contentLength = getResponseContentLength();
            if (contentLength != -1 && contentLength > maxlen) {
                throw new HttpContentTooLargeException(new StringBuffer().append("Content-Length is ").append(contentLength).toString(), maxlen);
            }
            f6486a.debug("Buffering response body");
            ByteArrayOutputStream rawdata = new ByteArrayOutputStream(contentLength > 0 ? (int) contentLength : 4096);
            byte[] buffer = new byte[2048];
            int pos = 0;
            do {
                int len = instream.read(buffer, 0, Math.min(buffer.length, maxlen - pos));
                if (len == -1) {
                    break;
                }
                rawdata.write(buffer, 0, len);
                pos += len;
            } while (pos < maxlen);
            setResponseStream(null);
            if (pos == maxlen && instream.read() != -1) {
                throw new HttpContentTooLargeException(new StringBuffer().append("Content-Length not known but larger than ").append(maxlen).toString(), maxlen);
            }
            this.f6495j = rawdata.toByteArray();
        }
        return this.f6495j;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public InputStream getResponseBodyAsStream() throws IOException {
        if (this.f6493h != null) {
            return this.f6493h;
        }
        if (this.f6495j != null) {
            ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(this.f6495j);
            f6486a.debug("re-creating response stream from byte array");
            return byteArrayInputStream;
        }
        return null;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public String getResponseBodyAsString() throws IOException {
        byte[] rawdata = null;
        if (m2713a()) {
            rawdata = getResponseBody();
        }
        if (rawdata != null) {
            return EncodingUtil.getString(rawdata, getResponseCharSet());
        }
        return null;
    }

    public String getResponseBodyAsString(int maxlen) throws IOException {
        if (maxlen < 0) {
            throw new IllegalArgumentException("maxlen must be positive");
        }
        byte[] rawdata = null;
        if (m2713a()) {
            rawdata = getResponseBody(maxlen);
        }
        if (rawdata != null) {
            return EncodingUtil.getString(rawdata, getResponseCharSet());
        }
        return null;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header[] getResponseFooters() {
        return getResponseTrailerHeaderGroup().getAllHeaders();
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public Header getResponseFooter(String footerName) {
        if (footerName == null) {
            return null;
        }
        return getResponseTrailerHeaderGroup().getCondensedHeader(footerName);
    }

    protected void setResponseStream(InputStream responseStream) {
        this.f6493h = responseStream;
    }

    protected InputStream getResponseStream() {
        return this.f6493h;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public String getStatusText() {
        return this.statusLine.getReasonPhrase();
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setStrictMode(boolean strictMode) {
        if (strictMode) {
            this.f6498m.makeStrict();
        } else {
            this.f6498m.makeLenient();
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public boolean isStrictMode() {
        return false;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void addRequestHeader(String headerName, String headerValue) {
        addRequestHeader(new Header(headerName, headerValue));
    }

    protected boolean isConnectionCloseForced() {
        return this.f6505t;
    }

    protected void setConnectionCloseForced(boolean b) {
        if (f6486a.isDebugEnabled()) {
            f6486a.debug(new StringBuffer().append("Force-close connection: ").append(b).toString());
        }
        this.f6505t = b;
    }

    protected boolean shouldCloseConnection(HttpConnection conn) {
        if (isConnectionCloseForced()) {
            f6486a.debug("Should force-close connection.");
            return true;
        }
        Header connectionHeader = null;
        if (!conn.isTransparent()) {
            connectionHeader = this.f6489d.getFirstHeader("proxy-connection");
        }
        if (connectionHeader == null) {
            connectionHeader = this.f6489d.getFirstHeader("connection");
        }
        if (connectionHeader == null) {
            connectionHeader = this.f6488c.getFirstHeader("connection");
        }
        if (connectionHeader != null) {
            if (connectionHeader.getValue().equalsIgnoreCase("close")) {
                if (!f6486a.isDebugEnabled()) {
                    return true;
                }
                f6486a.debug(new StringBuffer().append("Should close connection in response to directive: ").append(connectionHeader.getValue()).toString());
                return true;
            }
            if (connectionHeader.getValue().equalsIgnoreCase("keep-alive")) {
                if (f6486a.isDebugEnabled()) {
                    f6486a.debug(new StringBuffer().append("Should NOT close connection in response to directive: ").append(connectionHeader.getValue()).toString());
                }
                return false;
            }
            if (f6486a.isDebugEnabled()) {
                f6486a.debug(new StringBuffer().append("Unknown directive: ").append(connectionHeader.toExternalForm()).toString());
            }
        }
        f6486a.debug("Resorting to protocol version default close connection policy");
        if (this.effectiveVersion.greaterEquals(HttpVersion.HTTP_1_1)) {
            if (f6486a.isDebugEnabled()) {
                f6486a.debug(new StringBuffer().append("Should NOT close connection, using ").append(this.effectiveVersion.toString()).toString());
            }
        } else if (f6486a.isDebugEnabled()) {
            f6486a.debug(new StringBuffer().append("Should close connection, using ").append(this.effectiveVersion.toString()).toString());
        }
        return this.effectiveVersion.lessEquals(HttpVersion.HTTP_1_0);
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public int execute(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.execute(HttpState, HttpConnection)");
        this.f6494i = conn;
        if (state == null) {
            throw new IllegalArgumentException("HttpState parameter may not be null");
        }
        if (conn == null) {
            throw new IllegalArgumentException("HttpConnection parameter may not be null");
        }
        if (this.f6506u) {
            throw new IllegalStateException("Method has been aborted");
        }
        if (!validate()) {
            throw new ProtocolException("HttpMethodBase object not valid");
        }
        this.statusLine = null;
        this.f6505t = false;
        conn.setLastResponseInputStream(null);
        if (this.effectiveVersion == null) {
            this.effectiveVersion = this.f6498m.getVersion();
        }
        writeRequest(state, conn);
        this.f6507v = true;
        readResponse(state, conn);
        this.f6501p = true;
        return this.statusLine.getStatusCode();
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void abort() {
        if (!this.f6506u) {
            this.f6506u = true;
            HttpConnection conn = this.f6494i;
            if (conn != null) {
                conn.close();
            }
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public boolean hasBeenUsed() {
        return this.f6501p;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void recycle() {
        f6486a.trace("enter HttpMethodBase.recycle()");
        releaseConnection();
        this.f6491f = null;
        this.f6496k = false;
        this.f6497l = true;
        this.f6492g = null;
        getRequestHeaderGroup().clear();
        getResponseHeaderGroup().clear();
        getResponseTrailerHeaderGroup().clear();
        this.statusLine = null;
        this.effectiveVersion = null;
        this.f6506u = false;
        this.f6501p = false;
        this.f6498m = new HttpMethodParams();
        this.f6495j = null;
        this.f6502q = 0;
        this.f6505t = false;
        this.f6499n.invalidate();
        this.f6500o.invalidate();
        this.f6508w = null;
        this.f6507v = false;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void releaseConnection() {
        try {
            if (this.f6493h != null) {
                try {
                    this.f6493h.close();
                } catch (IOException e) {
                }
            }
        } finally {
            m2714b();
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void removeRequestHeader(String headerName) {
        Header[] headers = getRequestHeaderGroup().getHeaders(headerName);
        for (Header header : headers) {
            getRequestHeaderGroup().removeHeader(header);
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void removeRequestHeader(Header header) {
        if (header != null) {
            getRequestHeaderGroup().removeHeader(header);
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public boolean validate() {
        return true;
    }

    /* JADX INFO: renamed from: a */
    private CookieSpec m2712a(HttpState state) {
        if (this.f6508w == null) {
            int i = state.getCookiePolicy();
            if (i == -1) {
                this.f6508w = CookiePolicy.getCookieSpec(this.f6498m.getCookiePolicy());
            } else {
                this.f6508w = CookiePolicy.getSpecByPolicy(i);
            }
            this.f6508w.setValidDateFormats((Collection) this.f6498m.getParameter(HttpMethodParams.DATE_PATTERNS));
        }
        return this.f6508w;
    }

    protected void addCookieRequestHeader(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.addCookieRequestHeader(HttpState, HttpConnection)");
        Header[] cookieheaders = getRequestHeaderGroup().getHeaders("Cookie");
        for (Header cookieheader : cookieheaders) {
            if (cookieheader.isAutogenerated()) {
                getRequestHeaderGroup().removeHeader(cookieheader);
            }
        }
        CookieSpec matcher = m2712a(state);
        String host = this.f6498m.getVirtualHost();
        if (host == null) {
            host = conn.getHost();
        }
        Cookie[] cookies = matcher.match(host, conn.getPort(), getPath(), conn.isSecure(), state.getCookies());
        if (cookies != null && cookies.length > 0) {
            if (getParams().isParameterTrue(HttpMethodParams.SINGLE_COOKIE_HEADER)) {
                String s = matcher.formatCookies(cookies);
                getRequestHeaderGroup().addHeader(new Header("Cookie", s, true));
            } else {
                for (Cookie cookie : cookies) {
                    String s2 = matcher.formatCookie(cookie);
                    getRequestHeaderGroup().addHeader(new Header("Cookie", s2, true));
                }
            }
            if (matcher instanceof CookieVersionSupport) {
                CookieVersionSupport versupport = (CookieVersionSupport) matcher;
                int ver = versupport.getVersion();
                boolean needVersionHeader = false;
                for (Cookie cookie2 : cookies) {
                    if (ver != cookie2.getVersion()) {
                        needVersionHeader = true;
                    }
                }
                if (needVersionHeader) {
                    getRequestHeaderGroup().addHeader(versupport.getVersionHeader());
                }
            }
        }
    }

    protected void addHostRequestHeader(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.addHostRequestHeader(HttpState, HttpConnection)");
        String host = this.f6498m.getVirtualHost();
        if (host != null) {
            f6486a.debug(new StringBuffer().append("Using virtual host name: ").append(host).toString());
        } else {
            host = conn.getHost();
        }
        int port = conn.getPort();
        if (f6486a.isDebugEnabled()) {
            f6486a.debug("Adding Host request header");
        }
        if (conn.getProtocol().getDefaultPort() != port) {
            host = new StringBuffer().append(host).append(C0092c.f1283N).append(port).toString();
        }
        setRequestHeader(Constants.Http.HTTP_HEADER_HOST, host);
    }

    protected void addProxyConnectionHeader(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.addProxyConnectionHeader(HttpState, HttpConnection)");
        if (!conn.isTransparent() && getRequestHeader("Proxy-Connection") == null) {
            addRequestHeader("Proxy-Connection", "Keep-Alive");
        }
    }

    protected void addRequestHeaders(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.addRequestHeaders(HttpState, HttpConnection)");
        addUserAgentRequestHeader(state, conn);
        addHostRequestHeader(state, conn);
        addCookieRequestHeader(state, conn);
        addProxyConnectionHeader(state, conn);
    }

    protected void addUserAgentRequestHeader(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.addUserAgentRequestHeaders(HttpState, HttpConnection)");
        if (getRequestHeader(Constants.Http.HTTP_HEADER_USER_AGENT) == null) {
            String agent = (String) getParams().getParameter(HttpMethodParams.USER_AGENT);
            if (agent == null) {
                agent = "Jakarta Commons-HttpClient";
            }
            setRequestHeader(Constants.Http.HTTP_HEADER_USER_AGENT, agent);
        }
    }

    protected void checkNotUsed() throws IllegalStateException {
        if (this.f6501p) {
            throw new IllegalStateException("Already used.");
        }
    }

    protected void checkUsed() throws IllegalStateException {
        if (!this.f6501p) {
            throw new IllegalStateException("Not Used.");
        }
    }

    protected static String generateRequestLine(HttpConnection connection, String name, String requestPath, String query, String version) {
        f6486a.trace("enter HttpMethodBase.generateRequestLine(HttpConnection, String, String, String, String)");
        StringBuffer buf = new StringBuffer();
        buf.append(name);
        buf.append(" ");
        if (!connection.isTransparent()) {
            Protocol protocol = connection.getProtocol();
            buf.append(protocol.getScheme().toLowerCase());
            buf.append("://");
            buf.append(connection.getHost());
            if (connection.getPort() != -1 && connection.getPort() != protocol.getDefaultPort()) {
                buf.append(C0092c.f1283N);
                buf.append(connection.getPort());
            }
        }
        if (requestPath == null) {
            buf.append(CookieSpec.PATH_DELIM);
        } else {
            if (!connection.isTransparent() && !requestPath.startsWith(CookieSpec.PATH_DELIM)) {
                buf.append(CookieSpec.PATH_DELIM);
            }
            buf.append(requestPath);
        }
        if (query != null) {
            if (query.indexOf("?") != 0) {
                buf.append("?");
            }
            buf.append(query);
        }
        buf.append(" ");
        buf.append(version);
        buf.append("\r\n");
        return buf.toString();
    }

    protected void processResponseBody(HttpState state, HttpConnection conn) {
    }

    protected void processResponseHeaders(HttpState state, HttpConnection conn) {
        f6486a.trace("enter HttpMethodBase.processResponseHeaders(HttpState, HttpConnection)");
        CookieSpec parser = m2712a(state);
        Header[] headers = getResponseHeaderGroup().getHeaders(RFC2109Spec.SET_COOKIE_KEY);
        processCookieHeaders(parser, headers, state, conn);
        if (parser instanceof CookieVersionSupport) {
            CookieVersionSupport versupport = (CookieVersionSupport) parser;
            if (versupport.getVersion() > 0) {
                Header[] headers2 = getResponseHeaderGroup().getHeaders(RFC2965Spec.SET_COOKIE2_KEY);
                processCookieHeaders(parser, headers2, state, conn);
            }
        }
    }

    protected void processCookieHeaders(CookieSpec parser, Header[] headers, HttpState state, HttpConnection conn) {
        f6486a.trace("enter HttpMethodBase.processCookieHeaders(Header[], HttpState, HttpConnection)");
        String host = this.f6498m.getVirtualHost();
        if (host == null) {
            host = conn.getHost();
        }
        for (Header header : headers) {
            Cookie[] cookies = null;
            try {
                cookies = parser.parse(host, conn.getPort(), getPath(), conn.isSecure(), header);
            } catch (MalformedCookieException e) {
                if (f6486a.isWarnEnabled()) {
                    f6486a.warn(new StringBuffer().append("Invalid cookie header: \"").append(header.getValue()).append("\". ").append(e.getMessage()).toString());
                }
            }
            if (cookies != null) {
                for (Cookie cookie : cookies) {
                    try {
                        parser.validate(host, conn.getPort(), getPath(), conn.isSecure(), cookie);
                        state.addCookie(cookie);
                        if (f6486a.isDebugEnabled()) {
                            f6486a.debug(new StringBuffer().append("Cookie accepted: \"").append(parser.formatCookie(cookie)).append(C0092c.f1282M).toString());
                        }
                    } catch (MalformedCookieException e2) {
                        if (f6486a.isWarnEnabled()) {
                            f6486a.warn(new StringBuffer().append("Cookie rejected: \"").append(parser.formatCookie(cookie)).append("\". ").append(e2.getMessage()).toString());
                        }
                    }
                }
            }
        }
    }

    protected void processStatusLine(HttpState state, HttpConnection conn) {
    }

    protected void readResponse(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.readResponse(HttpState, HttpConnection)");
        while (this.statusLine == null) {
            readStatusLine(state, conn);
            processStatusLine(state, conn);
            readResponseHeaders(state, conn);
            processResponseHeaders(state, conn);
            int status = this.statusLine.getStatusCode();
            if (status >= 100 && status < 200) {
                if (f6486a.isInfoEnabled()) {
                    f6486a.info(new StringBuffer().append("Discarding unexpected response: ").append(this.statusLine.toString()).toString());
                }
                this.statusLine = null;
            }
        }
        readResponseBody(state, conn);
        processResponseBody(state, conn);
    }

    protected void readResponseBody(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.readResponseBody(HttpState, HttpConnection)");
        f6486a.trace("enter HttpMethodBase.readResponseBody(HttpConnection)");
        this.f6495j = null;
        InputStream responseInputStream = conn.getResponseInputStream();
        InputStream c1132f = C1131e.f6661b.m2817a() ? new C1132f(responseInputStream, C1131e.f6661b) : responseInputStream;
        int statusCode = this.statusLine.getStatusCode();
        f6486a.trace("enter HttpMethodBase.canResponseHaveBody(int)");
        boolean z = ((statusCode >= 100 && statusCode <= 199) || statusCode == 204 || statusCode == 304) ? false : true;
        Header firstHeader = this.f6489d.getFirstHeader("Transfer-Encoding");
        if (firstHeader != null) {
            String value = firstHeader.getValue();
            if (!"chunked".equalsIgnoreCase(value) && !"identity".equalsIgnoreCase(value) && f6486a.isWarnEnabled()) {
                f6486a.warn(new StringBuffer().append("Unsupported transfer encoding: ").append(value).toString());
            }
            HeaderElement[] elements = firstHeader.getElements();
            int length = elements.length;
            if (length <= 0 || !"chunked".equalsIgnoreCase(elements[length - 1].getName())) {
                f6486a.info("Response content is not chunk-encoded");
                setConnectionCloseForced(true);
            } else if (conn.isResponseAvailable(conn.getParams().getSoTimeout())) {
                c1132f = new ChunkedInputStream(c1132f, this);
            } else {
                if (getParams().isParameterTrue(HttpMethodParams.STRICT_TRANSFER_ENCODING)) {
                    throw new ProtocolException("Chunk-encoded body declared but not sent");
                }
                f6486a.warn("Chunk-encoded body missing");
                c1132f = null;
            }
        } else {
            long responseContentLength = getResponseContentLength();
            if (responseContentLength != -1) {
                c1132f = new ContentLengthInputStream(c1132f, responseContentLength);
            } else if (z && this.effectiveVersion.greaterEquals(HttpVersion.HTTP_1_1)) {
                Header firstHeader2 = this.f6489d.getFirstHeader("Connection");
                if (!"close".equalsIgnoreCase(firstHeader2 != null ? firstHeader2.getValue() : null)) {
                    f6486a.info("Response content length is not known");
                    setConnectionCloseForced(true);
                }
            }
        }
        if (!z) {
            c1132f = null;
        }
        InputStream stream = c1132f != null ? new C1117a(c1132f, new C1119b(this)) : c1132f;
        if (stream == null) {
            responseBodyConsumed();
        } else {
            conn.setLastResponseInputStream(stream);
            setResponseStream(stream);
        }
    }

    protected void readResponseHeaders(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.readResponseHeaders(HttpState,HttpConnection)");
        getResponseHeaderGroup().clear();
        Header[] headers = HttpParser.parseHeaders(conn.getResponseInputStream(), getParams().getHttpElementCharset());
        getResponseHeaderGroup().setHeaders(headers);
    }

    protected void readStatusLine(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.readStatusLine(HttpState, HttpConnection)");
        int maxGarbageLines = getParams().getIntParameter(HttpMethodParams.STATUS_LINE_GARBAGE_LIMIT, Integer.MAX_VALUE);
        int count = 0;
        while (true) {
            String s = conn.readLine(getParams().getHttpElementCharset());
            if (s == null && count == 0) {
                throw new NoHttpResponseException(new StringBuffer().append("The server ").append(conn.getHost()).append(" failed to respond").toString());
            }
            if (C1131e.f6660a.m2817a()) {
                C1131e.f6660a.m2819b(new StringBuffer().append(s).append("\r\n").toString());
            }
            if (s == null || !StatusLine.startsWithHTTP(s)) {
                if (s == null || count >= maxGarbageLines) {
                    throw new ProtocolException(new StringBuffer().append("The server ").append(conn.getHost()).append(" failed to respond with a valid HTTP response").toString());
                }
                count++;
            } else {
                this.statusLine = new StatusLine(s);
                String versionStr = this.statusLine.getHttpVersion();
                if (getParams().isParameterFalse(HttpMethodParams.UNAMBIGUOUS_STATUS_LINE) && versionStr.equals("HTTP")) {
                    getParams().setVersion(HttpVersion.HTTP_1_0);
                    if (f6486a.isWarnEnabled()) {
                        f6486a.warn(new StringBuffer().append("Ambiguous status line (HTTP protocol version missing):").append(this.statusLine.toString()).toString());
                        return;
                    }
                    return;
                }
                this.effectiveVersion = HttpVersion.parse(versionStr);
                return;
            }
        }
    }

    protected void writeRequest(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.writeRequest(HttpState, HttpConnection)");
        writeRequestLine(state, conn);
        writeRequestHeaders(state, conn);
        conn.writeLine();
        if (C1131e.f6660a.m2817a()) {
            C1131e.f6660a.m2814a("\r\n");
        }
        HttpVersion ver = getParams().getVersion();
        Header expectheader = getRequestHeader("Expect");
        String expectvalue = expectheader != null ? expectheader.getValue() : null;
        if (expectvalue != null && expectvalue.compareToIgnoreCase("100-continue") == 0) {
            if (ver.greaterEquals(HttpVersion.HTTP_1_1)) {
                conn.flushRequestOutputStream();
                int readTimeout = conn.getParams().getSoTimeout();
                try {
                    try {
                        conn.setSocketTimeout(3000);
                        readStatusLine(state, conn);
                        processStatusLine(state, conn);
                        readResponseHeaders(state, conn);
                        processResponseHeaders(state, conn);
                        if (this.statusLine.getStatusCode() != 100) {
                            conn.setSocketTimeout(readTimeout);
                            return;
                        } else {
                            this.statusLine = null;
                            f6486a.debug("OK to continue received");
                            conn.setSocketTimeout(readTimeout);
                        }
                    } catch (InterruptedIOException e) {
                        if (!ExceptionUtil.isSocketTimeoutException(e)) {
                            throw e;
                        }
                        removeRequestHeader("Expect");
                        f6486a.info("100 (continue) read timeout. Resume sending the request");
                        conn.setSocketTimeout(readTimeout);
                    }
                } catch (Throwable th) {
                    conn.setSocketTimeout(readTimeout);
                    throw th;
                }
            } else {
                removeRequestHeader("Expect");
                f6486a.info("'Expect: 100-continue' handshake is only supported by HTTP/1.1 or higher");
            }
        }
        writeRequestBody(state, conn);
        conn.flushRequestOutputStream();
    }

    protected boolean writeRequestBody(HttpState state, HttpConnection conn) throws IOException {
        return true;
    }

    protected void writeRequestHeaders(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.writeRequestHeaders(HttpState,HttpConnection)");
        addRequestHeaders(state, conn);
        String charset = getParams().getHttpElementCharset();
        Header[] headers = getRequestHeaders();
        for (Header header : headers) {
            String s = header.toExternalForm();
            if (C1131e.f6660a.m2817a()) {
                C1131e.f6660a.m2814a(s);
            }
            conn.print(s, charset);
        }
    }

    protected void writeRequestLine(HttpState state, HttpConnection conn) throws IOException {
        f6486a.trace("enter HttpMethodBase.writeRequestLine(HttpState, HttpConnection)");
        String requestLine = generateRequestLine(conn, getName(), getPath(), getQueryString(), this.effectiveVersion.toString());
        if (C1131e.f6660a.m2817a()) {
            C1131e.f6660a.m2814a(requestLine);
        }
        conn.print(requestLine, getParams().getHttpElementCharset());
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public HttpMethodParams getParams() {
        return this.f6498m;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public void setParams(HttpMethodParams params) {
        if (params == null) {
            throw new IllegalArgumentException("Parameters may not be null");
        }
        this.f6498m = params;
    }

    public HttpVersion getEffectiveVersion() {
        return this.effectiveVersion;
    }

    public String getProxyAuthenticationRealm() {
        return this.f6500o.getRealm();
    }

    public String getAuthenticationRealm() {
        return this.f6499n.getRealm();
    }

    protected String getContentCharSet(Header contentheader) {
        NameValuePair param;
        f6486a.trace("enter getContentCharSet( Header contentheader )");
        String charset = null;
        if (contentheader != null) {
            HeaderElement[] values = contentheader.getElements();
            if (values.length == 1 && (param = values[0].getParameterByName("charset")) != null) {
                charset = param.getValue();
            }
        }
        if (charset == null) {
            charset = getParams().getContentCharset();
            if (f6486a.isDebugEnabled()) {
                f6486a.debug(new StringBuffer().append("Default charset used: ").append(charset).toString());
            }
        }
        return charset;
    }

    public String getRequestCharSet() {
        return getContentCharSet(getRequestHeader("Content-Type"));
    }

    public String getResponseCharSet() {
        return getContentCharSet(getResponseHeader("Content-Type"));
    }

    public int getRecoverableExceptionCount() {
        return this.f6502q;
    }

    protected void responseBodyConsumed() {
        this.f6493h = null;
        if (this.f6494i != null) {
            this.f6494i.setLastResponseInputStream(null);
            if (shouldCloseConnection(this.f6494i)) {
                this.f6494i.close();
            } else {
                try {
                    if (this.f6494i.isResponseAvailable()) {
                        boolean logExtraInput = getParams().isParameterTrue(HttpMethodParams.WARN_EXTRA_INPUT);
                        if (logExtraInput) {
                            f6486a.warn("Extra response data detected - closing connection");
                        }
                        this.f6494i.close();
                    }
                } catch (IOException e) {
                    f6486a.warn(e.getMessage());
                    this.f6494i.close();
                }
            }
        }
        this.f6505t = false;
        m2714b();
    }

    /* JADX INFO: renamed from: b */
    private void m2714b() {
        if (this.f6494i != null) {
            this.f6494i.releaseConnection();
            this.f6494i = null;
        }
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public HostConfiguration getHostConfiguration() {
        HostConfiguration hostconfig = new HostConfiguration();
        hostconfig.setHost(this.f6503r);
        return hostconfig;
    }

    public void setHostConfiguration(HostConfiguration hostconfig) {
        if (hostconfig != null) {
            this.f6503r = new HttpHost(hostconfig.getHost(), hostconfig.getPort(), hostconfig.getProtocol());
        } else {
            this.f6503r = null;
        }
    }

    public MethodRetryHandler getMethodRetryHandler() {
        return this.f6504s;
    }

    public void setMethodRetryHandler(MethodRetryHandler handler) {
        this.f6504s = handler;
    }

    /* JADX INFO: renamed from: a */
    final void m2715a(StatusLine statusline, HeaderGroup responseheaders, InputStream responseStream) {
        this.f6501p = true;
        this.statusLine = statusline;
        this.f6489d = responseheaders;
        this.f6495j = null;
        this.f6493h = responseStream;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public AuthState getHostAuthState() {
        return this.f6499n;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public AuthState getProxyAuthState() {
        return this.f6500o;
    }

    public boolean isAborted() {
        return this.f6506u;
    }

    @Override // org.apache.commons.httpclient.HttpMethod
    public boolean isRequestSent() {
        return this.f6507v;
    }
}
