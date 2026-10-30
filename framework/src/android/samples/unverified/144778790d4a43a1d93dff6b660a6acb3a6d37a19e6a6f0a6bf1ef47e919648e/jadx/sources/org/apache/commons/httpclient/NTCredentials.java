package org.apache.commons.httpclient;

import org.apache.commons.httpclient.util.LangUtils;

/* JADX INFO: loaded from: classes.dex */
public class NTCredentials extends UsernamePasswordCredentials {

    /* JADX INFO: renamed from: a */
    private String f6546a;

    /* JADX INFO: renamed from: b */
    private String f6547b;

    public NTCredentials() {
    }

    public NTCredentials(String userName, String password, String host, String domain) {
        super(userName, password);
        if (domain == null) {
            throw new IllegalArgumentException("Domain may not be null");
        }
        this.f6546a = domain;
        if (host == null) {
            throw new IllegalArgumentException("Host may not be null");
        }
        this.f6547b = host;
    }

    public void setDomain(String domain) {
        if (domain == null) {
            throw new IllegalArgumentException("Domain may not be null");
        }
        this.f6546a = domain;
    }

    public String getDomain() {
        return this.f6546a;
    }

    public void setHost(String host) {
        if (host == null) {
            throw new IllegalArgumentException("Host may not be null");
        }
        this.f6547b = host;
    }

    public String getHost() {
        return this.f6547b;
    }

    @Override // org.apache.commons.httpclient.UsernamePasswordCredentials
    public String toString() {
        StringBuffer sbResult = new StringBuffer(super.toString());
        sbResult.append("@");
        sbResult.append(this.f6547b);
        sbResult.append(".");
        sbResult.append(this.f6546a);
        return sbResult.toString();
    }

    @Override // org.apache.commons.httpclient.UsernamePasswordCredentials
    public int hashCode() {
        int hash = super.hashCode();
        return LangUtils.hashCode(LangUtils.hashCode(hash, this.f6547b), this.f6546a);
    }

    @Override // org.apache.commons.httpclient.UsernamePasswordCredentials
    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        if (this == o) {
            return true;
        }
        if (!super.equals(o) || !(o instanceof NTCredentials)) {
            return false;
        }
        NTCredentials that = (NTCredentials) o;
        return LangUtils.equals(this.f6546a, that.f6546a) && LangUtils.equals(this.f6547b, that.f6547b);
    }
}
