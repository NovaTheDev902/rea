package org.apache.commons.httpclient;

/* JADX INFO: loaded from: classes.dex */
public class HttpVersion implements Comparable {
    public static final HttpVersion HTTP_0_9 = new HttpVersion(0, 9);
    public static final HttpVersion HTTP_1_0 = new HttpVersion(1, 0);
    public static final HttpVersion HTTP_1_1 = new HttpVersion(1, 1);

    /* JADX INFO: renamed from: a */
    private int f6516a;

    /* JADX INFO: renamed from: b */
    private int f6517b;

    public HttpVersion(int major, int minor) {
        this.f6516a = 0;
        this.f6517b = 0;
        if (major < 0) {
            throw new IllegalArgumentException("HTTP major version number may not be negative");
        }
        this.f6516a = major;
        if (minor < 0) {
            throw new IllegalArgumentException("HTTP minor version number may not be negative");
        }
        this.f6517b = minor;
    }

    public int getMajor() {
        return this.f6516a;
    }

    public int getMinor() {
        return this.f6517b;
    }

    public int hashCode() {
        return (this.f6516a * 100000) + this.f6517b;
    }

    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof HttpVersion)) {
            return false;
        }
        return equals((HttpVersion) obj);
    }

    public int compareTo(HttpVersion anotherVer) {
        if (anotherVer == null) {
            throw new IllegalArgumentException("Version parameter may not be null");
        }
        int delta = getMajor() - anotherVer.getMajor();
        if (delta == 0) {
            return getMinor() - anotherVer.getMinor();
        }
        return delta;
    }

    @Override // java.lang.Comparable
    public int compareTo(Object o) {
        return compareTo((HttpVersion) o);
    }

    public boolean equals(HttpVersion version) {
        return compareTo(version) == 0;
    }

    public boolean greaterEquals(HttpVersion version) {
        return compareTo(version) >= 0;
    }

    public boolean lessEquals(HttpVersion version) {
        return compareTo(version) <= 0;
    }

    public String toString() {
        StringBuffer buffer = new StringBuffer();
        buffer.append("HTTP/");
        buffer.append(this.f6516a);
        buffer.append('.');
        buffer.append(this.f6517b);
        return buffer.toString();
    }

    public static HttpVersion parse(String s) throws ProtocolException {
        if (s == null) {
            throw new IllegalArgumentException("String may not be null");
        }
        if (!s.startsWith("HTTP/")) {
            throw new ProtocolException(new StringBuffer().append("Invalid HTTP version string: ").append(s).toString());
        }
        int i1 = "HTTP/".length();
        int i2 = s.indexOf(".", i1);
        if (i2 == -1) {
            throw new ProtocolException(new StringBuffer().append("Invalid HTTP version number: ").append(s).toString());
        }
        try {
            int major = Integer.parseInt(s.substring(i1, i2));
            try {
                int minor = Integer.parseInt(s.substring(i2 + 1, s.length()));
                return new HttpVersion(major, minor);
            } catch (NumberFormatException e) {
                throw new ProtocolException(new StringBuffer().append("Invalid HTTP minor version number: ").append(s).toString());
            }
        } catch (NumberFormatException e2) {
            throw new ProtocolException(new StringBuffer().append("Invalid HTTP major version number: ").append(s).toString());
        }
    }
}
