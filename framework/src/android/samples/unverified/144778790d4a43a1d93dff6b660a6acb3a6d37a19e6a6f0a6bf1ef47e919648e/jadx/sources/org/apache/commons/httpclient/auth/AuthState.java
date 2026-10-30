package org.apache.commons.httpclient.auth;

/* JADX INFO: loaded from: classes.dex */
public class AuthState {
    public static final String PREEMPTIVE_AUTH_SCHEME = "basic";

    /* JADX INFO: renamed from: a */
    private AuthScheme f6589a = null;

    /* JADX INFO: renamed from: b */
    private boolean f6590b = false;

    /* JADX INFO: renamed from: c */
    private boolean f6591c = false;

    /* JADX INFO: renamed from: d */
    private boolean f6592d = false;

    public void invalidate() {
        this.f6589a = null;
        this.f6590b = false;
        this.f6591c = false;
        this.f6592d = false;
    }

    public boolean isAuthRequested() {
        return this.f6590b;
    }

    public void setAuthRequested(boolean challengeReceived) {
        this.f6590b = challengeReceived;
    }

    public boolean isAuthAttempted() {
        return this.f6591c;
    }

    public void setAuthAttempted(boolean challengeResponded) {
        this.f6591c = challengeResponded;
    }

    public void setPreemptive() {
        if (!this.f6592d) {
            if (this.f6589a != null) {
                throw new IllegalStateException("Authentication state already initialized");
            }
            this.f6589a = AuthPolicy.getAuthScheme(PREEMPTIVE_AUTH_SCHEME);
            this.f6592d = true;
        }
    }

    public boolean isPreemptive() {
        return this.f6592d;
    }

    public void setAuthScheme(AuthScheme authScheme) {
        if (authScheme == null) {
            invalidate();
            return;
        }
        if (this.f6592d && !this.f6589a.getClass().isInstance(authScheme)) {
            this.f6592d = false;
            this.f6591c = false;
        }
        this.f6589a = authScheme;
    }

    public AuthScheme getAuthScheme() {
        return this.f6589a;
    }

    public String getRealm() {
        if (this.f6589a != null) {
            return this.f6589a.getRealm();
        }
        return null;
    }

    public String toString() {
        StringBuffer buffer = new StringBuffer();
        buffer.append("Auth state: auth requested [");
        buffer.append(this.f6590b);
        buffer.append("]; auth attempted [");
        buffer.append(this.f6591c);
        if (this.f6589a != null) {
            buffer.append("]; auth scheme [");
            buffer.append(this.f6589a.getSchemeName());
            buffer.append("]; realm [");
            buffer.append(this.f6589a.getRealm());
        }
        buffer.append("] preemptive [");
        buffer.append(this.f6592d);
        buffer.append("]");
        return buffer.toString();
    }
}
