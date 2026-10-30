package org.apache.commons.httpclient.auth;

import java.util.Map;

/* JADX INFO: loaded from: classes.dex */
public abstract class RFC2617Scheme implements AuthScheme {

    /* JADX INFO: renamed from: a */
    private Map f6609a = null;

    public RFC2617Scheme() {
    }

    public RFC2617Scheme(String challenge) throws MalformedChallengeException {
        processChallenge(challenge);
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public void processChallenge(String challenge) throws MalformedChallengeException {
        String s = AuthChallengeParser.extractScheme(challenge);
        if (!s.equalsIgnoreCase(getSchemeName())) {
            throw new MalformedChallengeException(new StringBuffer().append("Invalid ").append(getSchemeName()).append(" challenge: ").append(challenge).toString());
        }
        this.f6609a = AuthChallengeParser.extractParams(challenge);
    }

    protected Map getParameters() {
        return this.f6609a;
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getParameter(String name) {
        if (name == null) {
            throw new IllegalArgumentException("Parameter name may not be null");
        }
        if (this.f6609a == null) {
            return null;
        }
        return (String) this.f6609a.get(name.toLowerCase());
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getRealm() {
        return getParameter("realm");
    }

    @Override // org.apache.commons.httpclient.auth.AuthScheme
    public String getID() {
        return getRealm();
    }
}
