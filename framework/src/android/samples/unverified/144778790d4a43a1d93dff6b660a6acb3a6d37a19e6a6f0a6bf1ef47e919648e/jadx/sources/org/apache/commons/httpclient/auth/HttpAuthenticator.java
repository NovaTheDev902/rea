package org.apache.commons.httpclient.auth;

import java.util.HashMap;
import java.util.Map;
import org.apache.commons.httpclient.Credentials;
import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpConnection;
import org.apache.commons.httpclient.HttpMethod;
import org.apache.commons.httpclient.HttpState;
import org.apache.commons.httpclient.UsernamePasswordCredentials;
import org.apache.commons.httpclient.cookie.CookiePolicy;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public final class HttpAuthenticator {
    public static final String PROXY_AUTH = "Proxy-Authenticate";
    public static final String PROXY_AUTH_RESP = "Proxy-Authorization";
    public static final String WWW_AUTH = "WWW-Authenticate";
    public static final String WWW_AUTH_RESP = "Authorization";

    /* JADX INFO: renamed from: a */
    static Class f6603a;

    /* JADX INFO: renamed from: b */
    private static final Log f6604b;

    static {
        Class clsM2770a;
        if (f6603a == null) {
            clsM2770a = m2770a("org.apache.commons.httpclient.auth.HttpAuthenticator");
            f6603a = clsM2770a;
        } else {
            clsM2770a = f6603a;
        }
        f6604b = LogFactory.getLog(clsM2770a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2770a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public static AuthScheme selectAuthScheme(Header[] challenges) throws MalformedChallengeException {
        f6604b.trace("enter HttpAuthenticator.selectAuthScheme(Header[])");
        if (challenges == null) {
            throw new IllegalArgumentException("Array of challenges may not be null");
        }
        if (challenges.length == 0) {
            throw new IllegalArgumentException("Array of challenges may not be empty");
        }
        Map challengemap = new HashMap(challenges.length);
        for (Header header : challenges) {
            String challenge = header.getValue();
            String s = AuthChallengeParser.extractScheme(challenge);
            challengemap.put(s, challenge);
        }
        String challenge2 = (String) challengemap.get("ntlm");
        if (challenge2 != null) {
            return new NTLMScheme(challenge2);
        }
        String challenge3 = (String) challengemap.get("digest");
        if (challenge3 != null) {
            return new DigestScheme(challenge3);
        }
        String challenge4 = (String) challengemap.get(AuthState.PREEMPTIVE_AUTH_SCHEME);
        if (challenge4 != null) {
            return new BasicScheme(challenge4);
        }
        throw new UnsupportedOperationException(new StringBuffer().append("Authentication scheme(s) not supported: ").append(challengemap.toString()).toString());
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2771a(HttpMethod method, HttpConnection conn, HttpState state, boolean proxy) throws AuthenticationException {
        if (method == null) {
            throw new IllegalArgumentException("HTTP method may not be null");
        }
        if (state == null) {
            throw new IllegalArgumentException("HTTP state may not be null");
        }
        String host = null;
        if (conn != null) {
            host = proxy ? conn.getProxyHost() : conn.getHost();
        }
        Credentials credentials = proxy ? state.getProxyCredentials(null, host) : state.getCredentials(null, host);
        if (credentials == null) {
            return false;
        }
        if (!(credentials instanceof UsernamePasswordCredentials)) {
            throw new InvalidCredentialsException(new StringBuffer().append("Credentials cannot be used for basic authentication: ").append(credentials.toString()).toString());
        }
        String auth = BasicScheme.authenticate((UsernamePasswordCredentials) credentials, method.getParams().getCredentialCharset());
        if (auth == null) {
            return false;
        }
        String s = proxy ? PROXY_AUTH_RESP : WWW_AUTH_RESP;
        Header header = new Header(s, auth, true);
        method.addRequestHeader(header);
        return true;
    }

    public static boolean authenticateDefault(HttpMethod method, HttpConnection conn, HttpState state) throws AuthenticationException {
        f6604b.trace("enter HttpAuthenticator.authenticateDefault(HttpMethod, HttpConnection, HttpState)");
        return m2771a(method, conn, state, false);
    }

    public static boolean authenticateProxyDefault(HttpMethod method, HttpConnection conn, HttpState state) throws AuthenticationException {
        f6604b.trace("enter HttpAuthenticator.authenticateProxyDefault(HttpMethod, HttpState)");
        return m2771a(method, conn, state, true);
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2772a(AuthScheme authscheme, HttpMethod method, HttpConnection conn, HttpState state, boolean proxy) throws AuthenticationException {
        if (authscheme == null) {
            throw new IllegalArgumentException("Authentication scheme may not be null");
        }
        if (method == null) {
            throw new IllegalArgumentException("HTTP method may not be null");
        }
        if (state == null) {
            throw new IllegalArgumentException("HTTP state may not be null");
        }
        String host = null;
        if (conn != null) {
            if (proxy) {
                host = conn.getProxyHost();
            } else {
                host = method.getParams().getVirtualHost();
                if (host == null) {
                    host = conn.getHost();
                }
            }
        }
        String realm = authscheme.getRealm();
        if (f6604b.isDebugEnabled()) {
            StringBuffer buffer = new StringBuffer();
            buffer.append("Using credentials for ");
            if (realm == null) {
                buffer.append(CookiePolicy.DEFAULT);
            } else {
                buffer.append('\'');
                buffer.append(realm);
                buffer.append('\'');
            }
            buffer.append(" authentication realm at ");
            buffer.append(host);
            f6604b.debug(buffer.toString());
        }
        Credentials credentials = proxy ? state.getProxyCredentials(realm, host) : state.getCredentials(realm, host);
        if (credentials == null) {
            StringBuffer buffer2 = new StringBuffer();
            buffer2.append("No credentials available for the ");
            if (realm == null) {
                buffer2.append(CookiePolicy.DEFAULT);
            } else {
                buffer2.append('\'');
                buffer2.append(realm);
                buffer2.append('\'');
            }
            buffer2.append(" authentication realm at ");
            buffer2.append(host);
            throw new CredentialsNotAvailableException(buffer2.toString());
        }
        String auth = authscheme.authenticate(credentials, method);
        if (auth != null) {
            String s = proxy ? PROXY_AUTH_RESP : WWW_AUTH_RESP;
            Header header = new Header(s, auth, true);
            method.addRequestHeader(header);
            return true;
        }
        return false;
    }

    public static boolean authenticate(AuthScheme authscheme, HttpMethod method, HttpConnection conn, HttpState state) throws AuthenticationException {
        f6604b.trace("enter HttpAuthenticator.authenticate(AuthScheme, HttpMethod, HttpConnection, HttpState)");
        return m2772a(authscheme, method, conn, state, false);
    }

    public static boolean authenticateProxy(AuthScheme authscheme, HttpMethod method, HttpConnection conn, HttpState state) throws AuthenticationException {
        f6604b.trace("enter HttpAuthenticator.authenticateProxy(AuthScheme, HttpMethod, HttpState)");
        return m2772a(authscheme, method, conn, state, true);
    }
}
