package org.apache.commons.httpclient.cookie;

import com.lenovo.lps.sus.p008c.C0092c;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import org.apache.commons.httpclient.Cookie;
import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HeaderElement;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.httpclient.util.ParameterFormatter;

/* JADX INFO: loaded from: classes.dex */
public class RFC2965Spec extends CookieSpecBase implements CookieVersionSupport {
    public static final String SET_COOKIE2_KEY = "set-cookie2";

    /* JADX INFO: renamed from: b */
    private static final Comparator f6646b = new CookiePathComparator();

    /* JADX INFO: renamed from: c */
    private final ParameterFormatter f6647c = new ParameterFormatter();

    /* JADX INFO: renamed from: d */
    private final List f6648d;

    /* JADX INFO: renamed from: e */
    private final Map f6649e;

    /* JADX INFO: renamed from: f */
    private final CookieSpec f6650f;

    /* JADX INFO: renamed from: a */
    static boolean m2807a(int x1, int[] x2) {
        for (int i : x2) {
            if (x1 == i) {
                return true;
            }
        }
        return false;
    }

    /* JADX INFO: renamed from: a */
    static int[] m2808a(String x1) throws MalformedCookieException {
        return m2809b(x1);
    }

    public RFC2965Spec() {
        this.f6647c.setAlwaysUseQuotes(true);
        this.f6649e = new HashMap(10);
        this.f6648d = new ArrayList(10);
        this.f6650f = new RFC2109Spec();
        registerAttribHandler(Cookie2.PATH, new C1123c(this, (byte) 0));
        registerAttribHandler(Cookie2.DOMAIN, new C1121a(this, (byte) 0));
        registerAttribHandler(Cookie2.PORT, new C1124d(this, (byte) 0));
        registerAttribHandler(Cookie2.MAXAGE, new C1122b(this, (byte) 0));
        registerAttribHandler(Cookie2.SECURE, new C1129i(this, (byte) 0));
        registerAttribHandler(Cookie2.COMMENT, new C1126f(this, (byte) 0));
        registerAttribHandler(Cookie2.COMMENTURL, new C1127g(this, (byte) 0));
        registerAttribHandler(Cookie2.DISCARD, new C1128h(this, (byte) 0));
        registerAttribHandler("version", new C1125e(this, (byte) 0));
    }

    protected void registerAttribHandler(String name, CookieAttributeHandler handler) {
        if (name == null) {
            throw new IllegalArgumentException("Attribute name may not be null");
        }
        if (handler == null) {
            throw new IllegalArgumentException("Attribute handler may not be null");
        }
        if (!this.f6648d.contains(handler)) {
            this.f6648d.add(handler);
        }
        this.f6649e.put(name, handler);
    }

    protected CookieAttributeHandler findAttribHandler(String name) {
        return (CookieAttributeHandler) this.f6649e.get(name);
    }

    protected CookieAttributeHandler getAttribHandler(String name) {
        CookieAttributeHandler handler = findAttribHandler(name);
        if (handler == null) {
            throw new IllegalStateException(new StringBuffer().append("Handler not registered for ").append(name).append(" attribute.").toString());
        }
        return handler;
    }

    protected Iterator getAttribHandlerIterator() {
        return this.f6648d.iterator();
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public Cookie[] parse(String host, int port, String path, boolean secure, Header header) throws MalformedCookieException {
        LOG.trace("enter RFC2965.parse(String, int, String, boolean, Header)");
        if (header == null) {
            throw new IllegalArgumentException("Header may not be null.");
        }
        if (header.getName() == null) {
            throw new IllegalArgumentException("Header name may not be null.");
        }
        if (header.getName().equalsIgnoreCase(SET_COOKIE2_KEY)) {
            return parse(host, port, path, secure, header.getValue());
        }
        if (header.getName().equalsIgnoreCase(RFC2109Spec.SET_COOKIE_KEY)) {
            return this.f6650f.parse(host, port, path, secure, header.getValue());
        }
        throw new MalformedCookieException("Header name is not valid. RFC 2965 supports \"set-cookie\" and \"set-cookie2\" headers.");
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public Cookie[] parse(String host, int port, String path, boolean secure, String header) throws MalformedCookieException {
        LOG.trace("enter RFC2965Spec.parse(String, int, String, boolean, String)");
        if (host == null) {
            throw new IllegalArgumentException("Host of origin may not be null");
        }
        if (host.trim().equals("")) {
            throw new IllegalArgumentException("Host of origin may not be blank");
        }
        if (port < 0) {
            throw new IllegalArgumentException(new StringBuffer().append("Invalid port: ").append(port).toString());
        }
        if (path == null) {
            throw new IllegalArgumentException("Path of origin may not be null.");
        }
        if (header == null) {
            throw new IllegalArgumentException("Header may not be null.");
        }
        if (path.trim().equals("")) {
            path = CookieSpec.PATH_DELIM;
        }
        String host2 = m2810c(host);
        HeaderElement[] headerElements = HeaderElement.parseElements(header.toCharArray());
        List cookies = new LinkedList();
        for (HeaderElement headerelement : headerElements) {
            try {
                Cookie2 cookie = new Cookie2(host2, headerelement.getName(), headerelement.getValue(), path, null, false, new int[]{port});
                NameValuePair[] parameters = headerelement.getParameters();
                if (parameters != null) {
                    Map attribmap = new HashMap(parameters.length);
                    for (int j = parameters.length - 1; j >= 0; j--) {
                        NameValuePair param = parameters[j];
                        attribmap.put(param.getName().toLowerCase(), param);
                    }
                    for (Map.Entry entry : attribmap.entrySet()) {
                        parseAttribute((NameValuePair) entry.getValue(), cookie);
                    }
                }
                cookies.add(cookie);
            } catch (IllegalArgumentException ex) {
                throw new MalformedCookieException(ex.getMessage());
            }
        }
        return (Cookie[]) cookies.toArray(new Cookie[cookies.size()]);
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public void parseAttribute(NameValuePair attribute, Cookie cookie) throws MalformedCookieException {
        if (attribute == null) {
            throw new IllegalArgumentException("Attribute may not be null.");
        }
        if (attribute.getName() == null) {
            throw new IllegalArgumentException("Attribute Name may not be null.");
        }
        if (cookie == null) {
            throw new IllegalArgumentException("Cookie may not be null.");
        }
        String paramName = attribute.getName().toLowerCase();
        String paramValue = attribute.getValue();
        CookieAttributeHandler handler = findAttribHandler(paramName);
        if (handler == null) {
            if (LOG.isDebugEnabled()) {
                LOG.debug(new StringBuffer().append("Unrecognized cookie attribute: ").append(attribute.toString()).toString());
                return;
            }
            return;
        }
        handler.parse(cookie, paramValue);
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public void validate(String host, int port, String path, boolean secure, Cookie cookie) throws MalformedCookieException {
        LOG.trace("enter RFC2965Spec.validate(String, int, String, boolean, Cookie)");
        if (cookie instanceof Cookie2) {
            if (cookie.getName().indexOf(32) != -1) {
                throw new MalformedCookieException("Cookie name may not contain blanks");
            }
            if (cookie.getName().startsWith("$")) {
                throw new MalformedCookieException("Cookie name may not start with $");
            }
            CookieOrigin origin = new CookieOrigin(m2810c(host), port, path, secure);
            Iterator i = getAttribHandlerIterator();
            while (i.hasNext()) {
                CookieAttributeHandler handler = (CookieAttributeHandler) i.next();
                handler.validate(cookie, origin);
            }
            return;
        }
        this.f6650f.validate(host, port, path, secure, cookie);
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public boolean match(String host, int port, String path, boolean secure, Cookie cookie) {
        LOG.trace("enter RFC2965.match(String, int, String, boolean, Cookie");
        if (cookie == null) {
            throw new IllegalArgumentException("Cookie may not be null");
        }
        if (cookie instanceof Cookie2) {
            if (cookie.isPersistent() && cookie.isExpired()) {
                return false;
            }
            CookieOrigin origin = new CookieOrigin(m2810c(host), port, path, secure);
            Iterator i = getAttribHandlerIterator();
            while (i.hasNext()) {
                CookieAttributeHandler handler = (CookieAttributeHandler) i.next();
                if (!handler.match(cookie, origin)) {
                    return false;
                }
            }
            return true;
        }
        return this.f6650f.match(host, port, path, secure, cookie);
    }

    /* JADX INFO: renamed from: a */
    private void m2806a(Cookie2 cookie, StringBuffer buffer) {
        String name = cookie.getName();
        String value = cookie.getValue();
        if (value == null) {
            value = "";
        }
        this.f6647c.format(buffer, new NameValuePair(name, value));
        if (cookie.getDomain() != null && cookie.isDomainAttributeSpecified()) {
            buffer.append("; ");
            this.f6647c.format(buffer, new NameValuePair("$Domain", cookie.getDomain()));
        }
        if (cookie.getPath() != null && cookie.isPathAttributeSpecified()) {
            buffer.append("; ");
            this.f6647c.format(buffer, new NameValuePair("$Path", cookie.getPath()));
        }
        if (cookie.isPortAttributeSpecified()) {
            String portValue = "";
            if (!cookie.isPortAttributeBlank()) {
                int[] ports = cookie.getPorts();
                StringBuffer stringBuffer = new StringBuffer();
                int length = ports.length;
                for (int i = 0; i < length; i++) {
                    if (i > 0) {
                        stringBuffer.append(",");
                    }
                    stringBuffer.append(ports[i]);
                }
                portValue = stringBuffer.toString();
            }
            buffer.append("; ");
            this.f6647c.format(buffer, new NameValuePair("$Port", portValue));
        }
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public String formatCookie(Cookie cookie) {
        LOG.trace("enter RFC2965Spec.formatCookie(Cookie)");
        if (cookie == null) {
            throw new IllegalArgumentException("Cookie may not be null");
        }
        if (!(cookie instanceof Cookie2)) {
            return this.f6650f.formatCookie(cookie);
        }
        Cookie2 cookie2 = (Cookie2) cookie;
        int version = cookie2.getVersion();
        StringBuffer buffer = new StringBuffer();
        this.f6647c.format(buffer, new NameValuePair("$Version", Integer.toString(version)));
        buffer.append("; ");
        m2806a(cookie2, buffer);
        return buffer.toString();
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public String formatCookies(Cookie[] cookies) {
        LOG.trace("enter RFC2965Spec.formatCookieHeader(Cookie[])");
        if (cookies == null) {
            throw new IllegalArgumentException("Cookies may not be null");
        }
        boolean hasOldStyleCookie = false;
        int version = -1;
        for (Cookie cookie : cookies) {
            if (!(cookie instanceof Cookie2)) {
                hasOldStyleCookie = true;
                break;
            }
            if (cookie.getVersion() > version) {
                version = cookie.getVersion();
            }
        }
        if (version < 0) {
            version = 0;
        }
        if (hasOldStyleCookie || version < 1) {
            return this.f6650f.formatCookies(cookies);
        }
        Arrays.sort(cookies, f6646b);
        StringBuffer buffer = new StringBuffer();
        this.f6647c.format(buffer, new NameValuePair("$Version", Integer.toString(version)));
        for (Cookie cookie2 : cookies) {
            buffer.append("; ");
            m2806a((Cookie2) cookie2, buffer);
        }
        return buffer.toString();
    }

    /* JADX INFO: renamed from: b */
    private static int[] m2809b(String portValue) throws MalformedCookieException {
        StringTokenizer st = new StringTokenizer(portValue, ",");
        int[] ports = new int[st.countTokens()];
        int i = 0;
        while (st.hasMoreTokens()) {
            try {
                ports[i] = Integer.parseInt(st.nextToken().trim());
                if (ports[i] < 0) {
                    throw new MalformedCookieException("Invalid Port attribute.");
                }
                i++;
            } catch (NumberFormatException e) {
                throw new MalformedCookieException(new StringBuffer().append("Invalid Port attribute: ").append(e.getMessage()).toString());
            }
        }
        return ports;
    }

    /* JADX INFO: renamed from: c */
    private static String m2810c(String host) {
        String effectiveHost = host.toLowerCase();
        if (host.indexOf(46) < 0) {
            return new StringBuffer().append(effectiveHost).append(".local").toString();
        }
        return effectiveHost;
    }

    @Override // org.apache.commons.httpclient.cookie.CookieSpecBase, org.apache.commons.httpclient.cookie.CookieSpec
    public boolean domainMatch(String host, String domain) {
        return host.equals(domain) || (domain.startsWith(".") && host.endsWith(domain));
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$c */
    private class C1123c implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6653a;

        private C1123c(RFC2965Spec rFC2965Spec) {
            this.f6653a = rFC2965Spec;
        }

        C1123c(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String path) throws MalformedCookieException {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (path == null) {
                throw new MalformedCookieException("Missing value for path attribute");
            }
            if (path.trim().equals("")) {
                throw new MalformedCookieException("Blank value for path attribute");
            }
            cookie.setPath(path);
            cookie.setPathAttributeSpecified(true);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (origin == null) {
                throw new IllegalArgumentException("Cookie origin may not be null");
            }
            String path = origin.getPath();
            if (path == null) {
                throw new IllegalArgumentException("Path of origin host may not be null.");
            }
            if (cookie.getPath() == null) {
                throw new MalformedCookieException("Invalid cookie state: path attribute is null.");
            }
            if (path.trim().equals("")) {
                path = CookieSpec.PATH_DELIM;
            }
            if (!this.f6653a.pathMatch(path, cookie.getPath())) {
                throw new MalformedCookieException(new StringBuffer().append("Illegal path attribute \"").append(cookie.getPath()).append("\". Path of origin: \"").append(path).append(C0092c.f1282M).toString());
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (origin == null) {
                throw new IllegalArgumentException("Cookie origin may not be null");
            }
            String path = origin.getPath();
            if (cookie.getPath() == null) {
                CookieSpecBase.LOG.warn("Invalid cookie state: path attribute is null.");
                return false;
            }
            if (path.trim().equals("")) {
                path = CookieSpec.PATH_DELIM;
            }
            return this.f6653a.pathMatch(path, cookie.getPath());
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$a */
    private class C1121a implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6651a;

        private C1121a(RFC2965Spec rFC2965Spec) {
            this.f6651a = rFC2965Spec;
        }

        C1121a(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String domain) throws MalformedCookieException {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (domain == null) {
                throw new MalformedCookieException("Missing value for domain attribute");
            }
            if (domain.trim().equals("")) {
                throw new MalformedCookieException("Blank value for domain attribute");
            }
            String domain2 = domain.toLowerCase();
            if (!domain2.startsWith(".")) {
                domain2 = new StringBuffer().append(".").append(domain2).toString();
            }
            cookie.setDomain(domain2);
            cookie.setDomainAttributeSpecified(true);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (origin == null) {
                throw new IllegalArgumentException("Cookie origin may not be null");
            }
            String host = origin.getHost().toLowerCase();
            if (cookie.getDomain() == null) {
                throw new MalformedCookieException("Invalid cookie state: domain not specified");
            }
            String cookieDomain = cookie.getDomain().toLowerCase();
            if (cookie.isDomainAttributeSpecified()) {
                if (!cookieDomain.startsWith(".")) {
                    throw new MalformedCookieException(new StringBuffer().append("Domain attribute \"").append(cookie.getDomain()).append("\" violates RFC 2109: domain must start with a dot").toString());
                }
                int dotIndex = cookieDomain.indexOf(46, 1);
                if ((dotIndex < 0 || dotIndex == cookieDomain.length() - 1) && !cookieDomain.equals(".local")) {
                    throw new MalformedCookieException(new StringBuffer().append("Domain attribute \"").append(cookie.getDomain()).append("\" violates RFC 2965: the value contains no embedded dots ").append("and the value is not .local").toString());
                }
                if (!this.f6651a.domainMatch(host, cookieDomain)) {
                    throw new MalformedCookieException(new StringBuffer().append("Domain attribute \"").append(cookie.getDomain()).append("\" violates RFC 2965: effective host name does not ").append("domain-match domain attribute.").toString());
                }
                String effectiveHostWithoutDomain = host.substring(0, host.length() - cookieDomain.length());
                if (effectiveHostWithoutDomain.indexOf(46) != -1) {
                    throw new MalformedCookieException(new StringBuffer().append("Domain attribute \"").append(cookie.getDomain()).append("\" violates RFC 2965: ").append("effective host minus domain may not contain any dots").toString());
                }
                return;
            }
            if (!cookie.getDomain().equals(host)) {
                throw new MalformedCookieException(new StringBuffer().append("Illegal domain attribute: \"").append(cookie.getDomain()).append("\".").append("Domain of origin: \"").append(host).append(C0092c.f1282M).toString());
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (origin == null) {
                throw new IllegalArgumentException("Cookie origin may not be null");
            }
            String host = origin.getHost().toLowerCase();
            String cookieDomain = cookie.getDomain();
            if (!this.f6651a.domainMatch(host, cookieDomain)) {
                return false;
            }
            String effectiveHostWithoutDomain = host.substring(0, host.length() - cookieDomain.length());
            return effectiveHostWithoutDomain.indexOf(46) == -1;
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$d */
    private class C1124d implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6654a;

        private C1124d(RFC2965Spec rFC2965Spec) {
            this.f6654a = rFC2965Spec;
        }

        C1124d(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String portValue) throws MalformedCookieException {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (cookie instanceof Cookie2) {
                Cookie2 cookie2 = (Cookie2) cookie;
                if (portValue == null || portValue.trim().equals("")) {
                    cookie2.setPortAttributeBlank(true);
                } else {
                    RFC2965Spec rFC2965Spec = this.f6654a;
                    int[] ports = RFC2965Spec.m2808a(portValue);
                    cookie2.setPorts(ports);
                }
                cookie2.setPortAttributeSpecified(true);
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (origin == null) {
                throw new IllegalArgumentException("Cookie origin may not be null");
            }
            if (cookie instanceof Cookie2) {
                Cookie2 cookie2 = (Cookie2) cookie;
                int port = origin.getPort();
                if (cookie2.isPortAttributeSpecified()) {
                    RFC2965Spec rFC2965Spec = this.f6654a;
                    if (!RFC2965Spec.m2807a(port, cookie2.getPorts())) {
                        throw new MalformedCookieException("Port attribute violates RFC 2965: Request port not found in cookie's port list.");
                    }
                }
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (origin == null) {
                throw new IllegalArgumentException("Cookie origin may not be null");
            }
            if (!(cookie instanceof Cookie2)) {
                return false;
            }
            Cookie2 cookie2 = (Cookie2) cookie;
            int port = origin.getPort();
            if (cookie2.isPortAttributeSpecified()) {
                if (cookie2.getPorts() == null) {
                    CookieSpecBase.LOG.warn("Invalid cookie state: port not specified");
                    return false;
                }
                RFC2965Spec rFC2965Spec = this.f6654a;
                if (!RFC2965Spec.m2807a(port, cookie2.getPorts())) {
                    return false;
                }
            }
            return true;
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$b */
    private class C1122b implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6652a;

        private C1122b(RFC2965Spec rFC2965Spec) {
            this.f6652a = rFC2965Spec;
        }

        C1122b(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String value) throws MalformedCookieException {
            int age;
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (value == null) {
                throw new MalformedCookieException("Missing value for max-age attribute");
            }
            try {
                age = Integer.parseInt(value);
            } catch (NumberFormatException e) {
                age = -1;
            }
            if (age < 0) {
                throw new MalformedCookieException("Invalid max-age attribute.");
            }
            cookie.setExpiryDate(new Date(System.currentTimeMillis() + (((long) age) * 1000)));
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) {
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            return true;
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$i */
    private class C1129i implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6659a;

        private C1129i(RFC2965Spec rFC2965Spec) {
            this.f6659a = rFC2965Spec;
        }

        C1129i(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String secure) throws MalformedCookieException {
            cookie.setSecure(true);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (origin == null) {
                throw new IllegalArgumentException("Cookie origin may not be null");
            }
            return cookie.getSecure() == origin.isSecure();
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$f */
    private class C1126f implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6656a;

        private C1126f(RFC2965Spec rFC2965Spec) {
            this.f6656a = rFC2965Spec;
        }

        C1126f(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String comment) throws MalformedCookieException {
            cookie.setComment(comment);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            return true;
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$g */
    private class C1127g implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6657a;

        private C1127g(RFC2965Spec rFC2965Spec) {
            this.f6657a = rFC2965Spec;
        }

        C1127g(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String commenturl) throws MalformedCookieException {
            if (cookie instanceof Cookie2) {
                Cookie2 cookie2 = (Cookie2) cookie;
                cookie2.setCommentURL(commenturl);
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            return true;
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$h */
    private class C1128h implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6658a;

        private C1128h(RFC2965Spec rFC2965Spec) {
            this.f6658a = rFC2965Spec;
        }

        C1128h(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String commenturl) throws MalformedCookieException {
            if (cookie instanceof Cookie2) {
                Cookie2 cookie2 = (Cookie2) cookie;
                cookie2.setDiscard(true);
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            return true;
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.cookie.RFC2965Spec$e */
    private class C1125e implements CookieAttributeHandler {

        /* JADX INFO: renamed from: a */
        private final RFC2965Spec f6655a;

        private C1125e(RFC2965Spec rFC2965Spec) {
            this.f6655a = rFC2965Spec;
        }

        C1125e(RFC2965Spec x0, byte b) {
            this(x0);
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void parse(Cookie cookie, String value) throws MalformedCookieException {
            int version;
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (cookie instanceof Cookie2) {
                Cookie2 cookie2 = (Cookie2) cookie;
                if (value == null) {
                    throw new MalformedCookieException("Missing value for version attribute");
                }
                try {
                    version = Integer.parseInt(value);
                } catch (NumberFormatException e) {
                    version = -1;
                }
                if (version < 0) {
                    throw new MalformedCookieException("Invalid cookie version.");
                }
                cookie2.setVersion(version);
                cookie2.setVersionAttributeSpecified(true);
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final void validate(Cookie cookie, CookieOrigin origin) throws MalformedCookieException {
            if (cookie == null) {
                throw new IllegalArgumentException("Cookie may not be null");
            }
            if (cookie instanceof Cookie2) {
                Cookie2 cookie2 = (Cookie2) cookie;
                if (!cookie2.isVersionAttributeSpecified()) {
                    throw new MalformedCookieException("Violates RFC 2965. Version attribute is required.");
                }
            }
        }

        @Override // org.apache.commons.httpclient.cookie.CookieAttributeHandler
        public final boolean match(Cookie cookie, CookieOrigin origin) {
            return true;
        }
    }

    @Override // org.apache.commons.httpclient.cookie.CookieVersionSupport
    public int getVersion() {
        return 1;
    }

    @Override // org.apache.commons.httpclient.cookie.CookieVersionSupport
    public Header getVersionHeader() {
        ParameterFormatter formatter = new ParameterFormatter();
        StringBuffer buffer = new StringBuffer();
        formatter.format(buffer, new NameValuePair("$Version", Integer.toString(getVersion())));
        return new Header("Cookie2", buffer.toString(), true);
    }
}
