package org.apache.commons.httpclient.cookie;

/* JADX INFO: loaded from: classes.dex */
public final class CookieOrigin {

    /* JADX INFO: renamed from: a */
    private final String f6631a;

    /* JADX INFO: renamed from: b */
    private final int f6632b;

    /* JADX INFO: renamed from: c */
    private final String f6633c;

    /* JADX INFO: renamed from: d */
    private final boolean f6634d;

    public CookieOrigin(String host, int port, String path, boolean secure) {
        if (host == null) {
            throw new IllegalArgumentException("Host of origin may not be null");
        }
        if (host.trim().equals("")) {
            throw new IllegalArgumentException("Host of origin may not be blank");
        }
        if (port < 0) {
            throw new IllegalArgumentException(new StringBuffer().append("Invalid port: ").append(port).toString());
        }
        if (path == null) {
            throw new IllegalArgumentException("Path of origin may not be null.");
        }
        this.f6631a = host;
        this.f6632b = port;
        this.f6633c = path;
        this.f6634d = secure;
    }

    public final String getHost() {
        return this.f6631a;
    }

    public final String getPath() {
        return this.f6633c;
    }

    public final int getPort() {
        return this.f6632b;
    }

    public final boolean isSecure() {
        return this.f6634d;
    }
}
