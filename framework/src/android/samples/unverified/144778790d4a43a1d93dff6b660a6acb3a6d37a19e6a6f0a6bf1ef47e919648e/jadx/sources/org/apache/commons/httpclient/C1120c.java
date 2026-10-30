package org.apache.commons.httpclient;

import QQPIM.ECloudCMDID;
import java.io.IOException;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import org.apache.commons.httpclient.auth.AuthChallengeException;
import org.apache.commons.httpclient.auth.AuthChallengeParser;
import org.apache.commons.httpclient.auth.AuthChallengeProcessor;
import org.apache.commons.httpclient.auth.AuthScheme;
import org.apache.commons.httpclient.auth.AuthScope;
import org.apache.commons.httpclient.auth.AuthState;
import org.apache.commons.httpclient.auth.AuthenticationException;
import org.apache.commons.httpclient.auth.CredentialsNotAvailableException;
import org.apache.commons.httpclient.auth.CredentialsProvider;
import org.apache.commons.httpclient.auth.HttpAuthenticator;
import org.apache.commons.httpclient.auth.MalformedChallengeException;
import org.apache.commons.httpclient.params.HostParams;
import org.apache.commons.httpclient.params.HttpClientParams;
import org.apache.commons.httpclient.params.HttpMethodParams;
import org.apache.commons.httpclient.params.HttpParams;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: renamed from: org.apache.commons.httpclient.c */
/* JADX INFO: compiled from: HttpMethodDirector.java */
/* JADX INFO: loaded from: classes.dex */
class C1120c {

    /* JADX INFO: renamed from: a */
    static Class f6614a;

    /* JADX INFO: renamed from: b */
    private static final Log f6615b;

    /* JADX INFO: renamed from: c */
    private ConnectMethod f6616c;

    /* JADX INFO: renamed from: d */
    private HttpState f6617d;

    /* JADX INFO: renamed from: e */
    private HostConfiguration f6618e;

    /* JADX INFO: renamed from: f */
    private HttpConnectionManager f6619f;

    /* JADX INFO: renamed from: g */
    private HttpClientParams f6620g;

    /* JADX INFO: renamed from: h */
    private HttpConnection f6621h;

    /* JADX INFO: renamed from: j */
    private AuthChallengeProcessor f6623j;

    /* JADX INFO: renamed from: i */
    private boolean f6622i = false;

    /* JADX INFO: renamed from: k */
    private Set f6624k = null;

    static {
        Class clsM2787a;
        if (f6614a == null) {
            clsM2787a = m2787a("org.apache.commons.httpclient.c");
            f6614a = clsM2787a;
        } else {
            clsM2787a = f6614a;
        }
        f6615b = LogFactory.getLog(clsM2787a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2787a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public C1120c(HttpConnectionManager connectionManager, HostConfiguration hostConfiguration, HttpClientParams params, HttpState state) {
        this.f6623j = null;
        this.f6619f = connectionManager;
        this.f6618e = hostConfiguration;
        this.f6620g = params;
        this.f6617d = state;
        this.f6623j = new AuthChallengeProcessor(this.f6620g);
    }

    /* JADX INFO: renamed from: a */
    public final void m2799a(HttpMethod method) throws IOException {
        boolean z;
        boolean z2;
        AuthState hostAuthState;
        AuthScheme authScheme;
        if (method == null) {
            throw new IllegalArgumentException("Method may not be null");
        }
        this.f6618e.getParams().setDefaults(this.f6620g);
        method.getParams().setDefaults(this.f6618e.getParams());
        Collection defaults = (Collection) this.f6618e.getParams().getParameter(HostParams.DEFAULT_HEADERS);
        if (defaults != null) {
            Iterator i = defaults.iterator();
            while (i.hasNext()) {
                method.addRequestHeader((Header) i.next());
            }
        }
        try {
            int maxRedirects = this.f6620g.getIntParameter(HttpClientParams.MAX_REDIRECTS, 100);
            int redirectCount = 0;
            while (true) {
                if (this.f6621h != null && !this.f6618e.hostEquals(this.f6621h)) {
                    this.f6621h.setLocked(false);
                    this.f6621h.releaseConnection();
                    this.f6621h = null;
                }
                if (this.f6621h == null) {
                    this.f6621h = this.f6619f.getConnectionWithTimeout(this.f6618e, this.f6620g.getConnectionManagerTimeout());
                    this.f6621h.setLocked(true);
                    if (this.f6620g.isAuthenticationPreemptive() || this.f6617d.isAuthenticationPreemptive()) {
                        f6615b.debug("Preemptively sending default basic credentials");
                        method.getHostAuthState().setPreemptive();
                        method.getHostAuthState().setAuthAttempted(true);
                        if (this.f6621h.isProxied() && !this.f6621h.isSecure()) {
                            method.getProxyAuthState().setPreemptive();
                            method.getProxyAuthState().setAuthAttempted(true);
                        }
                    }
                }
                try {
                    if (this.f6621h.isProxied() && !this.f6621h.isSecure()) {
                        m2792b(method);
                    }
                    if (m2790a(method, HttpAuthenticator.WWW_AUTH_RESP) && (authScheme = (hostAuthState = method.getHostAuthState()).getAuthScheme()) != null && (hostAuthState.isAuthRequested() || !authScheme.isConnectionBased())) {
                        String virtualHost = method.getParams().getVirtualHost();
                        if (virtualHost == null) {
                            virtualHost = this.f6621h.getHost();
                        }
                        AuthScope authScope = new AuthScope(virtualHost, this.f6621h.getPort(), authScheme.getRealm(), authScheme.getSchemeName());
                        if (f6615b.isDebugEnabled()) {
                            f6615b.debug(new StringBuffer().append("Authenticating with ").append(authScope).toString());
                        }
                        Credentials credentials = this.f6617d.getCredentials(authScope);
                        if (credentials != null) {
                            String strAuthenticate = authScheme.authenticate(credentials, method);
                            if (strAuthenticate != null) {
                                method.addRequestHeader(new Header(HttpAuthenticator.WWW_AUTH_RESP, strAuthenticate, true));
                            }
                        } else if (f6615b.isWarnEnabled()) {
                            f6615b.warn(new StringBuffer().append("Required credentials not available for ").append(authScope).toString());
                            if (method.getHostAuthState().isPreemptive()) {
                                f6615b.warn("Preemptive authentication requested but no default credentials available");
                            }
                        }
                    }
                } catch (AuthenticationException e) {
                    f6615b.error(e.getMessage(), e);
                }
                m2794d(method);
                if (this.f6616c != null) {
                    f6615b.debug("CONNECT failed, fake the response for the original method");
                    if (method instanceof HttpMethodBase) {
                        ((HttpMethodBase) method).m2715a(this.f6616c.getStatusLine(), this.f6616c.getResponseHeaderGroup(), this.f6616c.getResponseBodyAsStream());
                        method.getProxyAuthState().setAuthScheme(this.f6616c.getProxyAuthState().getAuthScheme());
                        this.f6616c = null;
                    } else {
                        this.f6622i = true;
                        f6615b.warn("Unable to fake response on method as it is not derived from HttpMethodBase.");
                    }
                } else {
                    boolean retry = false;
                    switch (method.getStatusCode()) {
                        case 301:
                        case 302:
                        case 303:
                        case 307:
                            f6615b.debug("Redirect required");
                            z = method.getFollowRedirects();
                            break;
                        case 304:
                        case 305:
                        case ECloudCMDID._ECCID_SetSoftBlackWhite /* 306 */:
                        default:
                            z = false;
                            break;
                    }
                    if (z && m2795e(method)) {
                        retry = true;
                        redirectCount++;
                        if (redirectCount >= maxRedirects) {
                            f6615b.error("Narrowly avoided an infinite loop in execute");
                            throw new RedirectException(new StringBuffer().append("Maximum redirects (").append(maxRedirects).append(") exceeded").toString());
                        }
                        if (f6615b.isDebugEnabled()) {
                            f6615b.debug(new StringBuffer().append("Execute redirect ").append(redirectCount).append(" of ").append(maxRedirects).toString());
                        }
                    }
                    method.getHostAuthState().setAuthRequested(method.getStatusCode() == 401);
                    method.getProxyAuthState().setAuthRequested(method.getStatusCode() == 407);
                    if (method.getHostAuthState().isAuthRequested() || method.getProxyAuthState().isAuthRequested()) {
                        f6615b.debug("Authorization required");
                        if (method.getDoAuthentication()) {
                            z2 = true;
                        } else {
                            f6615b.info("Authentication requested but doAuthentication is disabled");
                            z2 = false;
                        }
                    } else {
                        z2 = false;
                    }
                    if (z2 && m2796f(method)) {
                        f6615b.debug("Retry authentication");
                        retry = true;
                    }
                    if (retry) {
                        if (method.getResponseBodyAsStream() != null) {
                            method.getResponseBodyAsStream().close();
                        }
                    }
                }
            }
            if (this.f6621h != null) {
                this.f6621h.setLocked(false);
            }
            if ((this.f6622i || method.getResponseBodyAsStream() == null) && this.f6621h != null) {
                this.f6621h.releaseConnection();
            }
        } catch (Throwable th) {
            if (this.f6621h != null) {
                this.f6621h.setLocked(false);
            }
            if ((this.f6622i || method.getResponseBodyAsStream() == null) && this.f6621h != null) {
                this.f6621h.releaseConnection();
            }
            throw th;
        }
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2790a(HttpMethod method, String name) {
        Header[] authheaders = method.getRequestHeaders(name);
        boolean clean = true;
        for (Header authheader : authheaders) {
            if (authheader.isAutogenerated()) {
                method.removeRequestHeader(authheader);
            } else {
                clean = false;
            }
        }
        return clean;
    }

    /* JADX INFO: renamed from: b */
    private void m2792b(HttpMethod method) throws AuthenticationException {
        AuthState authstate;
        AuthScheme authscheme;
        if (m2790a(method, HttpAuthenticator.PROXY_AUTH_RESP) && (authscheme = (authstate = method.getProxyAuthState()).getAuthScheme()) != null) {
            if (authstate.isAuthRequested() || !authscheme.isConnectionBased()) {
                AuthScope authscope = new AuthScope(this.f6621h.getProxyHost(), this.f6621h.getProxyPort(), authscheme.getRealm(), authscheme.getSchemeName());
                if (f6615b.isDebugEnabled()) {
                    f6615b.debug(new StringBuffer().append("Authenticating with ").append(authscope).toString());
                }
                Credentials credentials = this.f6617d.getProxyCredentials(authscope);
                if (credentials != null) {
                    String authstring = authscheme.authenticate(credentials, method);
                    if (authstring != null) {
                        method.addRequestHeader(new Header(HttpAuthenticator.PROXY_AUTH_RESP, authstring, true));
                        return;
                    }
                    return;
                }
                if (f6615b.isWarnEnabled()) {
                    f6615b.warn(new StringBuffer().append("Required proxy credentials not available for ").append(authscope).toString());
                    if (method.getProxyAuthState().isPreemptive()) {
                        f6615b.warn("Preemptive authentication requested but no default proxy credentials available");
                    }
                }
            }
        }
    }

    /* JADX INFO: renamed from: c */
    private void m2793c(HttpMethod method) throws IOException {
        int timeout = 0;
        Object param = method.getParams().getParameter("http.socket.timeout");
        if (param == null) {
            param = this.f6621h.getParams().getParameter("http.socket.timeout");
        }
        if (param != null) {
            timeout = ((Integer) param).intValue();
        }
        this.f6621h.setSocketTimeout(timeout);
    }

    /* JADX INFO: renamed from: d */
    private void m2794d(HttpMethod method) throws IOException {
        MethodRetryHandler handler;
        int execCount = 0;
        while (true) {
            execCount++;
            try {
                if (f6615b.isTraceEnabled()) {
                    f6615b.trace(new StringBuffer().append("Attempt number ").append(execCount).append(" to process request").toString());
                }
                if (this.f6621h.getParams().isStaleCheckingEnabled()) {
                    this.f6621h.closeIfStale();
                }
                if (!this.f6621h.isOpen()) {
                    this.f6621h.open();
                    if (this.f6621h.isProxied() && this.f6621h.isSecure() && !(method instanceof ConnectMethod) && !m2789a()) {
                        return;
                    }
                }
                m2793c(method);
                method.execute(this.f6617d, this.f6621h);
                return;
            } catch (HttpException e) {
                throw e;
            } catch (IOException e2) {
                try {
                    try {
                        f6615b.debug("Closing the connection.");
                        this.f6621h.close();
                        if ((method instanceof HttpMethodBase) && (handler = ((HttpMethodBase) method).getMethodRetryHandler()) != null && !handler.retryMethod(method, this.f6621h, new HttpRecoverableException(e2.getMessage()), execCount, method.isRequestSent())) {
                            f6615b.debug("Method retry handler returned false. Automatic recovery will not be attempted");
                            throw e2;
                        }
                        HttpMethodRetryHandler handler2 = (HttpMethodRetryHandler) method.getParams().getParameter(HttpMethodParams.RETRY_HANDLER);
                        if (handler2 == null) {
                            handler2 = new DefaultHttpMethodRetryHandler();
                        }
                        if (!handler2.retryMethod(method, e2, execCount)) {
                            f6615b.debug("Method retry handler returned false. Automatic recovery will not be attempted");
                            throw e2;
                        }
                        if (f6615b.isInfoEnabled()) {
                            f6615b.info(new StringBuffer().append("I/O exception (").append(e2.getClass().getName()).append(") caught when processing request: ").append(e2.getMessage()).toString());
                        }
                        if (f6615b.isDebugEnabled()) {
                            f6615b.debug(e2.getMessage(), e2);
                        }
                        f6615b.info("Retrying request");
                    } catch (RuntimeException e3) {
                        if (this.f6621h.isOpen()) {
                            f6615b.debug("Closing the connection.");
                            this.f6621h.close();
                        }
                        this.f6622i = true;
                        throw e3;
                    }
                } catch (IOException e4) {
                    if (this.f6621h.isOpen()) {
                        f6615b.debug("Closing the connection.");
                        this.f6621h.close();
                    }
                    this.f6622i = true;
                    throw e4;
                }
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private boolean m2789a() throws IOException {
        int code;
        this.f6616c = new ConnectMethod(this.f6618e);
        this.f6616c.getParams().setDefaults(this.f6618e.getParams());
        while (true) {
            if (!this.f6621h.isOpen()) {
                this.f6621h.open();
            }
            if (this.f6620g.isAuthenticationPreemptive() || this.f6617d.isAuthenticationPreemptive()) {
                f6615b.debug("Preemptively sending default basic credentials");
                this.f6616c.getProxyAuthState().setPreemptive();
                this.f6616c.getProxyAuthState().setAuthAttempted(true);
            }
            try {
                m2792b(this.f6616c);
            } catch (AuthenticationException e) {
                f6615b.error(e.getMessage(), e);
            }
            m2793c(this.f6616c);
            this.f6616c.execute(this.f6617d, this.f6621h);
            code = this.f6616c.getStatusCode();
            boolean retry = false;
            AuthState authstate = this.f6616c.getProxyAuthState();
            authstate.setAuthRequested(code == 407);
            if (authstate.isAuthRequested() && m2796f(this.f6616c)) {
                retry = true;
            }
            if (!retry) {
                break;
            }
            if (this.f6616c.getResponseBodyAsStream() != null) {
                this.f6616c.getResponseBodyAsStream().close();
            }
        }
        if (code >= 200 && code < 300) {
            this.f6621h.tunnelCreated();
            this.f6616c = null;
            return true;
        }
        this.f6621h.close();
        return false;
    }

    /* JADX INFO: renamed from: e */
    private boolean m2795e(HttpMethod method) throws RedirectException {
        URI redirectUri;
        Header locationHeader = method.getResponseHeader("location");
        if (locationHeader == null) {
            f6615b.error(new StringBuffer().append("Received redirect response ").append(method.getStatusCode()).append(" but no location header").toString());
            return false;
        }
        String location = locationHeader.getValue();
        if (f6615b.isDebugEnabled()) {
            f6615b.debug(new StringBuffer().append("Redirect requested to location '").append(location).append("'").toString());
        }
        try {
            URI currentUri = new URI(this.f6621h.getProtocol().getScheme(), (String) null, this.f6621h.getHost(), this.f6621h.getPort(), method.getPath());
            try {
                String charset = method.getParams().getUriCharset();
                URI redirectUri2 = new URI(location, true, charset);
                try {
                    if (redirectUri2.isRelativeURI()) {
                        if (this.f6620g.isParameterTrue(HttpClientParams.REJECT_RELATIVE_REDIRECT)) {
                            f6615b.warn(new StringBuffer().append("Relative redirect location '").append(location).append("' not allowed").toString());
                            return false;
                        }
                        f6615b.debug("Redirect URI is not absolute - parsing as relative");
                        redirectUri = new URI(currentUri, redirectUri2);
                    } else {
                        method.getParams().setDefaults(this.f6620g);
                        redirectUri = redirectUri2;
                    }
                    method.setURI(redirectUri);
                    this.f6618e.setHost(redirectUri);
                    if (this.f6620g.isParameterFalse(HttpClientParams.ALLOW_CIRCULAR_REDIRECTS)) {
                        if (this.f6624k == null) {
                            this.f6624k = new HashSet();
                        }
                        this.f6624k.add(currentUri);
                        try {
                            if (redirectUri.hasQuery()) {
                                redirectUri.setQuery(null);
                            }
                            if (this.f6624k.contains(redirectUri)) {
                                throw new CircularRedirectException(new StringBuffer().append("Circular redirect to '").append(redirectUri).append("'").toString());
                            }
                        } catch (URIException e) {
                            return false;
                        }
                    }
                    if (f6615b.isDebugEnabled()) {
                        f6615b.debug(new StringBuffer().append("Redirecting from '").append(currentUri.getEscapedURI()).append("' to '").append(redirectUri.getEscapedURI()).toString());
                    }
                    method.getHostAuthState().invalidate();
                    return true;
                } catch (URIException e2) {
                    ex = e2;
                    throw new InvalidRedirectLocationException(new StringBuffer().append("Invalid redirect location: ").append(location).toString(), location, ex);
                }
            } catch (URIException e3) {
                ex = e3;
            }
        } catch (URIException e4) {
            ex = e4;
        }
    }

    /* JADX INFO: renamed from: f */
    private boolean m2796f(HttpMethod method) {
        boolean zM2798h = false;
        f6615b.trace("enter HttpMethodBase.processAuthenticationResponse(HttpState, HttpConnection)");
        try {
            switch (method.getStatusCode()) {
                case 401:
                    zM2798h = m2797g(method);
                    break;
                case HttpStatus.SC_PROXY_AUTHENTICATION_REQUIRED /* 407 */:
                    zM2798h = m2798h(method);
                    break;
            }
        } catch (Exception e) {
            if (f6615b.isErrorEnabled()) {
                f6615b.error(e.getMessage(), e);
            }
        }
        return zM2798h;
    }

    /* JADX INFO: renamed from: g */
    private boolean m2797g(HttpMethod method) throws MalformedChallengeException, AuthenticationException {
        AuthState authstate = method.getHostAuthState();
        Map challenges = AuthChallengeParser.parseChallenges(method.getResponseHeaders(HttpAuthenticator.WWW_AUTH));
        if (challenges.isEmpty()) {
            f6615b.debug("Authentication challenge(s) not found");
            return false;
        }
        AuthScheme authscheme = null;
        try {
            authscheme = this.f6623j.processChallenge(authstate, challenges);
        } catch (AuthChallengeException e) {
            if (f6615b.isWarnEnabled()) {
                f6615b.warn(e.getMessage());
            }
        }
        if (authscheme == null) {
            return false;
        }
        String host = method.getParams().getVirtualHost();
        if (host == null) {
            host = this.f6621h.getHost();
        }
        int port = this.f6621h.getPort();
        AuthScope authscope = new AuthScope(host, port, authscheme.getRealm(), authscheme.getSchemeName());
        if (f6615b.isDebugEnabled()) {
            f6615b.debug(new StringBuffer().append("Authentication scope: ").append(authscope).toString());
        }
        if (authstate.isAuthAttempted() && authscheme.isComplete()) {
            if (m2788a(authscheme, method.getParams(), authscope) != null) {
                return true;
            }
            if (!f6615b.isInfoEnabled()) {
                return false;
            }
            f6615b.info(new StringBuffer().append("Failure authenticating with ").append(authscope).toString());
            return false;
        }
        authstate.setAuthAttempted(true);
        Credentials credentials = this.f6617d.getCredentials(authscope);
        if (credentials == null) {
            credentials = m2788a(authscheme, method.getParams(), authscope);
        }
        if (credentials != null) {
            return true;
        }
        if (!f6615b.isInfoEnabled()) {
            return false;
        }
        f6615b.info(new StringBuffer().append("No credentials available for ").append(authscope).toString());
        return false;
    }

    /* JADX INFO: renamed from: h */
    private boolean m2798h(HttpMethod method) throws MalformedChallengeException, AuthenticationException {
        AuthState authstate = method.getProxyAuthState();
        Map proxyChallenges = AuthChallengeParser.parseChallenges(method.getResponseHeaders(HttpAuthenticator.PROXY_AUTH));
        if (proxyChallenges.isEmpty()) {
            f6615b.debug("Proxy authentication challenge(s) not found");
            return false;
        }
        AuthScheme authscheme = null;
        try {
            authscheme = this.f6623j.processChallenge(authstate, proxyChallenges);
        } catch (AuthChallengeException e) {
            if (f6615b.isWarnEnabled()) {
                f6615b.warn(e.getMessage());
            }
        }
        if (authscheme == null) {
            return false;
        }
        AuthScope authscope = new AuthScope(this.f6621h.getProxyHost(), this.f6621h.getProxyPort(), authscheme.getRealm(), authscheme.getSchemeName());
        if (f6615b.isDebugEnabled()) {
            f6615b.debug(new StringBuffer().append("Proxy authentication scope: ").append(authscope).toString());
        }
        if (authstate.isAuthAttempted() && authscheme.isComplete()) {
            if (m2791b(authscheme, method.getParams(), authscope) != null) {
                return true;
            }
            if (!f6615b.isInfoEnabled()) {
                return false;
            }
            f6615b.info(new StringBuffer().append("Failure authenticating with ").append(authscope).toString());
            return false;
        }
        authstate.setAuthAttempted(true);
        Credentials credentials = this.f6617d.getProxyCredentials(authscope);
        if (credentials == null) {
            credentials = m2791b(authscheme, method.getParams(), authscope);
        }
        if (credentials != null) {
            return true;
        }
        if (!f6615b.isInfoEnabled()) {
            return false;
        }
        f6615b.info(new StringBuffer().append("No credentials available for ").append(authscope).toString());
        return false;
    }

    /* JADX INFO: renamed from: a */
    private Credentials m2788a(AuthScheme authScheme, HttpParams params, AuthScope authscope) {
        f6615b.debug("Credentials required");
        Credentials creds = null;
        CredentialsProvider credProvider = (CredentialsProvider) params.getParameter(CredentialsProvider.PROVIDER);
        if (credProvider != null) {
            try {
                creds = credProvider.getCredentials(authScheme, authscope.getHost(), authscope.getPort(), false);
            } catch (CredentialsNotAvailableException e) {
                f6615b.warn(e.getMessage());
            }
            if (creds != null) {
                this.f6617d.setCredentials(authscope, creds);
                if (f6615b.isDebugEnabled()) {
                    f6615b.debug(new StringBuffer().append(authscope).append(" new credentials given").toString());
                }
            }
        } else {
            f6615b.debug("Credentials provider not available");
        }
        return creds;
    }

    /* JADX INFO: renamed from: b */
    private Credentials m2791b(AuthScheme authScheme, HttpParams params, AuthScope authscope) {
        f6615b.debug("Proxy credentials required");
        Credentials creds = null;
        CredentialsProvider credProvider = (CredentialsProvider) params.getParameter(CredentialsProvider.PROVIDER);
        if (credProvider != null) {
            try {
                creds = credProvider.getCredentials(authScheme, authscope.getHost(), authscope.getPort(), true);
            } catch (CredentialsNotAvailableException e) {
                f6615b.warn(e.getMessage());
            }
            if (creds != null) {
                this.f6617d.setProxyCredentials(authscope, creds);
                if (f6615b.isDebugEnabled()) {
                    f6615b.debug(new StringBuffer().append(authscope).append(" new credentials given").toString());
                }
            }
        } else {
            f6615b.debug("Proxy credentials provider not available");
        }
        return creds;
    }
}
