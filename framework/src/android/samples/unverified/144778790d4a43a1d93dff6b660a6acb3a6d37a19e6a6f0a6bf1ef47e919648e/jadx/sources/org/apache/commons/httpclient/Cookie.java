package org.apache.commons.httpclient;

import com.lenovo.lps.sus.p008c.C0092c;
import java.io.Serializable;
import java.util.Comparator;
import java.util.Date;
import org.apache.commons.httpclient.cookie.CookiePolicy;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.commons.httpclient.util.LangUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class Cookie extends NameValuePair implements Serializable, Comparator {

    /* JADX INFO: renamed from: a */
    static Class f6428a;

    /* JADX INFO: renamed from: j */
    private static final Log f6429j;

    /* JADX INFO: renamed from: b */
    private String f6430b;

    /* JADX INFO: renamed from: c */
    private String f6431c;

    /* JADX INFO: renamed from: d */
    private Date f6432d;

    /* JADX INFO: renamed from: e */
    private String f6433e;

    /* JADX INFO: renamed from: f */
    private boolean f6434f;

    /* JADX INFO: renamed from: g */
    private boolean f6435g;

    /* JADX INFO: renamed from: h */
    private boolean f6436h;

    /* JADX INFO: renamed from: i */
    private int f6437i;

    public Cookie() {
        this((String) null, "noname", (String) null, (String) null, (Date) null, false);
    }

    public Cookie(String domain, String name, String value) {
        this(domain, name, value, (String) null, (Date) null, false);
    }

    public Cookie(String domain, String name, String value, String path, Date expires, boolean secure) {
        super(name, value);
        this.f6435g = false;
        this.f6436h = false;
        this.f6437i = 0;
        f6429j.trace("enter Cookie(String, String, String, String, Date, boolean)");
        if (name == null) {
            throw new IllegalArgumentException("Cookie name may not be null");
        }
        if (name.trim().equals("")) {
            throw new IllegalArgumentException("Cookie name may not be blank");
        }
        setPath(path);
        setDomain(domain);
        setExpiryDate(expires);
        setSecure(secure);
    }

    public Cookie(String domain, String name, String value, String path, int maxAge, boolean secure) {
        this(domain, name, value, path, (Date) null, secure);
        if (maxAge < -1) {
            throw new IllegalArgumentException(new StringBuffer().append("Invalid max age:  ").append(Integer.toString(maxAge)).toString());
        }
        if (maxAge >= 0) {
            setExpiryDate(new Date(System.currentTimeMillis() + (((long) maxAge) * 1000)));
        }
    }

    public String getComment() {
        return this.f6430b;
    }

    public void setComment(String comment) {
        this.f6430b = comment;
    }

    public Date getExpiryDate() {
        return this.f6432d;
    }

    public void setExpiryDate(Date expiryDate) {
        this.f6432d = expiryDate;
    }

    public boolean isPersistent() {
        return this.f6432d != null;
    }

    public String getDomain() {
        return this.f6431c;
    }

    public void setDomain(String domain) {
        if (domain != null) {
            int ndx = domain.indexOf(C0092c.f1283N);
            if (ndx != -1) {
                domain = domain.substring(0, ndx);
            }
            this.f6431c = domain.toLowerCase();
        }
    }

    public String getPath() {
        return this.f6433e;
    }

    public void setPath(String path) {
        this.f6433e = path;
    }

    public boolean getSecure() {
        return this.f6434f;
    }

    public void setSecure(boolean secure) {
        this.f6434f = secure;
    }

    public int getVersion() {
        return this.f6437i;
    }

    public void setVersion(int version) {
        this.f6437i = version;
    }

    public boolean isExpired() {
        return this.f6432d != null && this.f6432d.getTime() <= System.currentTimeMillis();
    }

    public boolean isExpired(Date now) {
        return this.f6432d != null && this.f6432d.getTime() <= now.getTime();
    }

    public void setPathAttributeSpecified(boolean value) {
        this.f6435g = value;
    }

    public boolean isPathAttributeSpecified() {
        return this.f6435g;
    }

    public void setDomainAttributeSpecified(boolean value) {
        this.f6436h = value;
    }

    public boolean isDomainAttributeSpecified() {
        return this.f6436h;
    }

    @Override // org.apache.commons.httpclient.NameValuePair
    public int hashCode() {
        int hash = LangUtils.hashCode(17, getName());
        return LangUtils.hashCode(LangUtils.hashCode(hash, this.f6431c), this.f6433e);
    }

    @Override // org.apache.commons.httpclient.NameValuePair, java.util.Comparator
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof Cookie)) {
            return false;
        }
        Cookie that = (Cookie) obj;
        return LangUtils.equals(getName(), that.getName()) && LangUtils.equals(this.f6431c, that.f6431c) && LangUtils.equals(this.f6433e, that.f6433e);
    }

    public String toExternalForm() {
        CookieSpec spec;
        if (getVersion() > 0) {
            spec = CookiePolicy.getDefaultSpec();
        } else {
            spec = CookiePolicy.getCookieSpec(CookiePolicy.NETSCAPE);
        }
        return spec.formatCookie(this);
    }

    @Override // java.util.Comparator
    public int compare(Object o1, Object o2) {
        f6429j.trace("enter Cookie.compare(Object, Object)");
        if (!(o1 instanceof Cookie)) {
            throw new ClassCastException(o1.getClass().getName());
        }
        if (!(o2 instanceof Cookie)) {
            throw new ClassCastException(o2.getClass().getName());
        }
        Cookie c1 = (Cookie) o1;
        Cookie c2 = (Cookie) o2;
        if (c1.getPath() == null && c2.getPath() == null) {
            return 0;
        }
        if (c1.getPath() == null) {
            return !c2.getPath().equals(CookieSpec.PATH_DELIM) ? -1 : 0;
        }
        if (c2.getPath() == null) {
            return !c1.getPath().equals(CookieSpec.PATH_DELIM) ? 1 : 0;
        }
        return c1.getPath().compareTo(c2.getPath());
    }

    @Override // org.apache.commons.httpclient.NameValuePair
    public String toString() {
        return toExternalForm();
    }

    static {
        Class clsM2703a;
        if (f6428a == null) {
            clsM2703a = m2703a("org.apache.commons.httpclient.Cookie");
            f6428a = clsM2703a;
        } else {
            clsM2703a = f6428a;
        }
        f6429j = LogFactory.getLog(clsM2703a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2703a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }
}
