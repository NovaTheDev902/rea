package org.apache.commons.httpclient.auth;

import com.lenovo.lps.sus.p008c.C0092c;
import org.apache.commons.codec.binary.Base64;
import org.apache.commons.httpclient.Credentials;
import org.apache.commons.httpclient.HttpMethod;
import org.apache.commons.httpclient.UsernamePasswordCredentials;
import org.apache.commons.httpclient.util.EncodingUtil;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class BasicScheme extends RFC2617Scheme {

    /* JADX INFO: renamed from: a */
    static Class f6593a;

    /* JADX INFO: renamed from: b */
    private static final Log f6594b;

    /* JADX INFO: renamed from: c */
    private boolean f6595c;

    static {
        Class clsM2764a;
        if (f6593a == null) {
            clsM2764a = m2764a("org.apache.commons.httpclient.auth.BasicScheme");
            f6593a = clsM2764a;
        } else {
            clsM2764a = f6593a;
        }
        f6594b = LogFactory.getLog(clsM2764a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2764a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public BasicScheme() {
        this.f6595c = false;
    }

    public BasicScheme(String challenge) throws MalformedChallengeException {
        super(challenge);
        this.f6595c = true;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getSchemeName() {
        return AuthState.PREEMPTIVE_AUTH_SCHEME;
    }

    @Override // org.apache.commons.httpclient.auth.RFC2617Scheme, org.apache.commons.httpclient.auth.AuthScheme
    public void processChallenge(String challenge) throws MalformedChallengeException {
        super.processChallenge(challenge);
        this.f6595c = true;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public boolean isComplete() {
        return this.f6595c;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String authenticate(Credentials credentials, String method, String uri) throws AuthenticationException {
        f6594b.trace("enter BasicScheme.authenticate(Credentials, String, String)");
        try {
            UsernamePasswordCredentials usernamepassword = (UsernamePasswordCredentials) credentials;
            return authenticate(usernamepassword);
        } catch (ClassCastException e) {
            throw new InvalidCredentialsException(new StringBuffer().append("Credentials cannot be used for basic authentication: ").append(credentials.getClass().getName()).toString());
        }
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public boolean isConnectionBased() {
        return false;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String authenticate(Credentials credentials, HttpMethod method) throws AuthenticationException {
        f6594b.trace("enter BasicScheme.authenticate(Credentials, HttpMethod)");
        if (method == null) {
            throw new IllegalArgumentException("Method may not be null");
        }
        try {
            UsernamePasswordCredentials usernamepassword = (UsernamePasswordCredentials) credentials;
            return authenticate(usernamepassword, method.getParams().getCredentialCharset());
        } catch (ClassCastException e) {
            throw new InvalidCredentialsException(new StringBuffer().append("Credentials cannot be used for basic authentication: ").append(credentials.getClass().getName()).toString());
        }
    }

    public static String authenticate(UsernamePasswordCredentials credentials) {
        return authenticate(credentials, "ISO-8859-1");
    }

    public static String authenticate(UsernamePasswordCredentials credentials, String charset) {
        f6594b.trace("enter BasicScheme.authenticate(UsernamePasswordCredentials, String)");
        if (credentials == null) {
            throw new IllegalArgumentException("Credentials may not be null");
        }
        if (charset == null || charset.length() == 0) {
            throw new IllegalArgumentException("charset may not be null or empty");
        }
        StringBuffer buffer = new StringBuffer();
        buffer.append(credentials.getUserName());
        buffer.append(C0092c.f1283N);
        buffer.append(credentials.getPassword());
        return new StringBuffer().append("Basic ").append(EncodingUtil.getAsciiString(Base64.encodeBase64(EncodingUtil.getBytes(buffer.toString(), charset)))).toString();
    }
}
