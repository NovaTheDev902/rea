package org.apache.commons.httpclient.auth;

import org.apache.commons.httpclient.util.LangUtils;

/* JADX INFO: loaded from: classes.dex */
public class AuthScope {
    public static final int ANY_PORT = -1;

    /* JADX INFO: renamed from: a */
    private String f6585a;

    /* JADX INFO: renamed from: b */
    private String f6586b;

    /* JADX INFO: renamed from: c */
    private String f6587c;

    /* JADX INFO: renamed from: d */
    private int f6588d;
    public static final String ANY_HOST = null;
    public static final String ANY_REALM = null;
    public static final String ANY_SCHEME = null;
    public static final AuthScope ANY = new AuthScope(ANY_HOST, -1, ANY_REALM, ANY_SCHEME);

    public AuthScope(String host, int port, String realm, String scheme) {
        this.f6585a = null;
        this.f6586b = null;
        this.f6587c = null;
        this.f6588d = -1;
        this.f6587c = host == null ? ANY_HOST : host.toLowerCase();
        this.f6588d = port < 0 ? -1 : port;
        this.f6586b = realm == null ? ANY_REALM : realm;
        this.f6585a = scheme == null ? ANY_SCHEME : scheme.toUpperCase();
    }

    public AuthScope(String host, int port, String realm) {
        this(host, port, realm, ANY_SCHEME);
    }

    public AuthScope(String host, int port) {
        this(host, port, ANY_REALM, ANY_SCHEME);
    }

    public AuthScope(AuthScope authscope) {
        this.f6585a = null;
        this.f6586b = null;
        this.f6587c = null;
        this.f6588d = -1;
        if (authscope == null) {
            throw new IllegalArgumentException("Scope may not be null");
        }
        this.f6587c = authscope.getHost();
        this.f6588d = authscope.getPort();
        this.f6586b = authscope.getRealm();
        this.f6585a = authscope.getScheme();
    }

    public String getHost() {
        return this.f6587c;
    }

    public int getPort() {
        return this.f6588d;
    }

    public String getRealm() {
        return this.f6586b;
    }

    public String getScheme() {
        return this.f6585a;
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2763a(String p1, String p2) {
        if (p1 == null) {
            return p1 == p2;
        }
        return p1.equals(p2);
    }

    /* JADX INFO: renamed from: a */
    private static boolean m2762a(int p1, int p2) {
        return p1 == p2;
    }

    public int match(AuthScope that) {
        int factor = 0;
        if (m2763a(this.f6585a, that.f6585a)) {
            factor = 0 + 1;
        } else if (this.f6585a != ANY_SCHEME && that.f6585a != ANY_SCHEME) {
            return -1;
        }
        if (m2763a(this.f6586b, that.f6586b)) {
            factor += 2;
        } else if (this.f6586b != ANY_REALM && that.f6586b != ANY_REALM) {
            return -1;
        }
        if (m2762a(this.f6588d, that.f6588d)) {
            factor += 4;
        } else if (this.f6588d != -1 && that.f6588d != -1) {
            return -1;
        }
        if (m2763a(this.f6587c, that.f6587c)) {
            factor += 8;
        } else if (this.f6587c != ANY_HOST && that.f6587c != ANY_HOST) {
            return -1;
        }
        return factor;
    }

    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        if (o == this) {
            return true;
        }
        if (!(o instanceof AuthScope)) {
            return super.equals(o);
        }
        AuthScope that = (AuthScope) o;
        return m2763a(this.f6587c, that.f6587c) && m2762a(this.f6588d, that.f6588d) && m2763a(this.f6586b, that.f6586b) && m2763a(this.f6585a, that.f6585a);
    }

    public String toString() {
        StringBuffer buffer = new StringBuffer();
        if (this.f6585a != null) {
            buffer.append(this.f6585a.toUpperCase());
            buffer.append(' ');
        }
        if (this.f6586b != null) {
            buffer.append('\'');
            buffer.append(this.f6586b);
            buffer.append('\'');
        } else {
            buffer.append("<any realm>");
        }
        if (this.f6587c != null) {
            buffer.append('@');
            buffer.append(this.f6587c);
            if (this.f6588d >= 0) {
                buffer.append(':');
                buffer.append(this.f6588d);
            }
        }
        return buffer.toString();
    }

    public int hashCode() {
        int hash = LangUtils.hashCode(17, this.f6587c);
        return LangUtils.hashCode(LangUtils.hashCode(LangUtils.hashCode(hash, this.f6588d), this.f6586b), this.f6585a);
    }
}
