package org.apache.commons.httpclient.auth;

import org.apache.commons.httpclient.Credentials;
import org.apache.commons.httpclient.HttpMethod;
import org.apache.commons.httpclient.NTCredentials;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class NTLMScheme implements AuthScheme {

    /* JADX INFO: renamed from: a */
    static Class f6605a;

    /* JADX INFO: renamed from: b */
    private static final Log f6606b;

    /* JADX INFO: renamed from: c */
    private String f6607c;

    /* JADX INFO: renamed from: d */
    private int f6608d;

    static {
        Class clsM2773a;
        if (f6605a == null) {
            clsM2773a = m2773a("org.apache.commons.httpclient.auth.NTLMScheme");
            f6605a = clsM2773a;
        } else {
            clsM2773a = f6605a;
        }
        f6606b = LogFactory.getLog(clsM2773a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2773a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public NTLMScheme() {
        this.f6607c = null;
        this.f6608d = 0;
    }

    public NTLMScheme(String challenge) throws MalformedChallengeException {
        this.f6607c = null;
        processChallenge(challenge);
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public void processChallenge(String challenge) throws MalformedChallengeException {
        String s = AuthChallengeParser.extractScheme(challenge);
        if (!s.equalsIgnoreCase(getSchemeName())) {
            throw new MalformedChallengeException(new StringBuffer().append("Invalid NTLM challenge: ").append(challenge).toString());
        }
        int i = challenge.indexOf(32);
        if (i != -1) {
            String s2 = challenge.substring(i, challenge.length());
            this.f6607c = s2.trim();
            this.f6608d = 3;
        } else {
            this.f6607c = "";
            if (this.f6608d == 0) {
                this.f6608d = 1;
            } else {
                this.f6608d = Integer.MAX_VALUE;
            }
        }
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public boolean isComplete() {
        return this.f6608d == 4 || this.f6608d == Integer.MAX_VALUE;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getSchemeName() {
        return "ntlm";
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getRealm() {
        return null;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getID() {
        return this.f6607c;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getParameter(String name) {
        if (name == null) {
            throw new IllegalArgumentException("Parameter name may not be null");
        }
        return null;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public boolean isConnectionBased() {
        return true;
    }

    public static String authenticate(NTCredentials credentials, String challenge) throws AuthenticationException {
        f6606b.trace("enter NTLMScheme.authenticate(NTCredentials, String)");
        if (credentials == null) {
            throw new IllegalArgumentException("Credentials may not be null");
        }
        C1118a ntlm = new C1118a();
        String s = ntlm.m2783a(challenge, credentials.getUserName(), credentials.getPassword(), credentials.getHost(), credentials.getDomain());
        return new StringBuffer().append("NTLM ").append(s).toString();
    }

    public static String authenticate(NTCredentials credentials, String challenge, String charset) throws AuthenticationException {
        f6606b.trace("enter NTLMScheme.authenticate(NTCredentials, String)");
        if (credentials == null) {
            throw new IllegalArgumentException("Credentials may not be null");
        }
        C1118a ntlm = new C1118a();
        ntlm.m2785b(charset);
        String s = ntlm.m2783a(challenge, credentials.getUserName(), credentials.getPassword(), credentials.getHost(), credentials.getDomain());
        return new StringBuffer().append("NTLM ").append(s).toString();
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String authenticate(Credentials credentials, String method, String uri) throws AuthenticationException {
        f6606b.trace("enter NTLMScheme.authenticate(Credentials, String, String)");
        try {
            NTCredentials ntcredentials = (NTCredentials) credentials;
            return authenticate(ntcredentials, this.f6607c);
        } catch (ClassCastException e) {
            throw new InvalidCredentialsException(new StringBuffer().append("Credentials cannot be used for NTLM authentication: ").append(credentials.getClass().getName()).toString());
        }
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String authenticate(Credentials credentials, HttpMethod method) throws AuthenticationException {
        String response;
        f6606b.trace("enter NTLMScheme.authenticate(Credentials, HttpMethod)");
        if (this.f6608d == 0) {
            throw new IllegalStateException("NTLM authentication process has not been initiated");
        }
        try {
            NTCredentials ntcredentials = (NTCredentials) credentials;
            C1118a ntlm = new C1118a();
            ntlm.m2785b(method.getParams().getCredentialCharset());
            if (this.f6608d == 1 || this.f6608d == Integer.MAX_VALUE) {
                response = ntlm.m2782a(ntcredentials.getHost(), ntcredentials.getDomain());
                this.f6608d = 2;
            } else {
                response = ntlm.m2784a(ntcredentials.getUserName(), ntcredentials.getPassword(), ntcredentials.getHost(), ntcredentials.getDomain(), C1118a.m2778a(this.f6607c));
                this.f6608d = 4;
            }
            return new StringBuffer().append("NTLM ").append(response).toString();
        } catch (ClassCastException e) {
            throw new InvalidCredentialsException(new StringBuffer().append("Credentials cannot be used for NTLM authentication: ").append(credentials.getClass().getName()).toString());
        }
    }
}
