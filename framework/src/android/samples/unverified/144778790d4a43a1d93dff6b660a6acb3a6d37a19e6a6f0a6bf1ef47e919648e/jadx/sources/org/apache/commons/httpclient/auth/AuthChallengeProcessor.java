package org.apache.commons.httpclient.auth;

import java.util.Collection;
import java.util.Map;
import org.apache.commons.httpclient.params.HttpParams;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public final class AuthChallengeProcessor {

    /* JADX INFO: renamed from: a */
    static Class f6575a;

    /* JADX INFO: renamed from: b */
    private static final Log f6576b;

    /* JADX INFO: renamed from: c */
    private HttpParams f6577c;

    static {
        Class clsM2760a;
        if (f6575a == null) {
            clsM2760a = m2760a("org.apache.commons.httpclient.auth.AuthChallengeProcessor");
            f6575a = clsM2760a;
        } else {
            clsM2760a = f6575a;
        }
        f6576b = LogFactory.getLog(clsM2760a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2760a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public AuthChallengeProcessor(HttpParams params) {
        this.f6577c = null;
        if (params == null) {
            throw new IllegalArgumentException("Parameter collection may not be null");
        }
        this.f6577c = params;
    }

    public final AuthScheme selectAuthScheme(Map challenges) throws AuthChallengeException {
        if (challenges == null) {
            throw new IllegalArgumentException("Challenge map may not be null");
        }
        Collection<String> authPrefs = (Collection) this.f6577c.getParameter(AuthPolicy.AUTH_SCHEME_PRIORITY);
        if (authPrefs == null || authPrefs.isEmpty()) {
            authPrefs = AuthPolicy.getDefaultAuthPrefs();
        }
        if (f6576b.isDebugEnabled()) {
            f6576b.debug(new StringBuffer().append("Supported authentication schemes in the order of preference: ").append(authPrefs).toString());
        }
        AuthScheme authscheme = null;
        for (String id : authPrefs) {
            String challenge = (String) challenges.get(id.toLowerCase());
            if (challenge != null) {
                if (f6576b.isInfoEnabled()) {
                    f6576b.info(new StringBuffer().append(id).append(" authentication scheme selected").toString());
                }
                try {
                    authscheme = AuthPolicy.getAuthScheme(id);
                    break;
                } catch (IllegalStateException e) {
                    throw new AuthChallengeException(e.getMessage());
                }
            }
            if (f6576b.isDebugEnabled()) {
                f6576b.debug(new StringBuffer().append("Challenge for ").append(id).append(" authentication scheme not available").toString());
            }
        }
        if (authscheme == null) {
            throw new AuthChallengeException(new StringBuffer().append("Unable to respond to any of these challenges: ").append(challenges).toString());
        }
        return authscheme;
    }

    public final AuthScheme processChallenge(AuthState state, Map challenges) throws MalformedChallengeException, AuthenticationException {
        if (state == null) {
            throw new IllegalArgumentException("Authentication state may not be null");
        }
        if (challenges == null) {
            throw new IllegalArgumentException("Challenge map may not be null");
        }
        if (state.isPreemptive() || state.getAuthScheme() == null) {
            state.setAuthScheme(selectAuthScheme(challenges));
        }
        AuthScheme authscheme = state.getAuthScheme();
        String id = authscheme.getSchemeName();
        if (f6576b.isDebugEnabled()) {
            f6576b.debug(new StringBuffer().append("Using authentication scheme: ").append(id).toString());
        }
        String challenge = (String) challenges.get(id.toLowerCase());
        if (challenge == null) {
            throw new AuthenticationException(new StringBuffer().append(id).append(" authorization challenge expected, but not found").toString());
        }
        authscheme.processChallenge(challenge);
        f6576b.debug("Authorization challenge processed");
        return authscheme;
    }
}
