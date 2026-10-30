package org.apache.commons.httpclient.auth;

/* JADX INFO: loaded from: classes.dex */
public abstract class AuthSchemeBase implements AuthScheme {

    /* JADX INFO: renamed from: a */
    private String f6584a;

    public AuthSchemeBase(String challenge) throws MalformedChallengeException {
        this.f6584a = null;
        if (challenge == null) {
            throw new IllegalArgumentException("Challenge may not be null");
        }
        this.f6584a = challenge;
    }

    public boolean equals(Object obj) {
        return obj instanceof AuthSchemeBase ? this.f6584a.equals(((AuthSchemeBase) obj).f6584a) : super.equals(obj);
    }

    public int hashCode() {
        return this.f6584a.hashCode();
    }

    public String toString() {
        return this.f6584a;
    }
}
