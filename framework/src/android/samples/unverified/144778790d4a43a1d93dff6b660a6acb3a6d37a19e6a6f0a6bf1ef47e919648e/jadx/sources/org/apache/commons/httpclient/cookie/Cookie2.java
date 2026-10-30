package org.apache.commons.httpclient.cookie;

import java.util.Date;
import org.apache.commons.httpclient.Cookie;

/* JADX INFO: loaded from: classes.dex */
public class Cookie2 extends Cookie {
    public static final String COMMENT = "comment";
    public static final String COMMENTURL = "commenturl";
    public static final String DISCARD = "discard";
    public static final String DOMAIN = "domain";
    public static final String MAXAGE = "max-age";
    public static final String PATH = "path";
    public static final String PORT = "port";
    public static final String SECURE = "secure";
    public static final String VERSION = "version";

    /* JADX INFO: renamed from: b */
    private String f6625b;

    /* JADX INFO: renamed from: c */
    private int[] f6626c;

    /* JADX INFO: renamed from: d */
    private boolean f6627d;

    /* JADX INFO: renamed from: e */
    private boolean f6628e;

    /* JADX INFO: renamed from: f */
    private boolean f6629f;

    /* JADX INFO: renamed from: g */
    private boolean f6630g;

    public Cookie2() {
        super((String) null, "noname", (String) null, (String) null, (Date) null, false);
        this.f6627d = false;
        this.f6628e = false;
        this.f6629f = false;
        this.f6630g = false;
    }

    public Cookie2(String domain, String name, String value) {
        super(domain, name, value);
        this.f6627d = false;
        this.f6628e = false;
        this.f6629f = false;
        this.f6630g = false;
    }

    public Cookie2(String domain, String name, String value, String path, Date expires, boolean secure) {
        super(domain, name, value, path, expires, secure);
        this.f6627d = false;
        this.f6628e = false;
        this.f6629f = false;
        this.f6630g = false;
    }

    public Cookie2(String domain, String name, String value, String path, Date expires, boolean secure, int[] ports) {
        super(domain, name, value, path, expires, secure);
        this.f6627d = false;
        this.f6628e = false;
        this.f6629f = false;
        this.f6630g = false;
        setPorts(ports);
    }

    public String getCommentURL() {
        return this.f6625b;
    }

    public void setCommentURL(String commentURL) {
        this.f6625b = commentURL;
    }

    public int[] getPorts() {
        return this.f6626c;
    }

    public void setPorts(int[] ports) {
        this.f6626c = ports;
    }

    public void setDiscard(boolean toDiscard) {
        this.f6627d = toDiscard;
    }

    @Override // org.apache.commons.httpclient.Cookie
    public boolean isPersistent() {
        return (getExpiryDate() == null || this.f6627d) ? false : true;
    }

    public void setPortAttributeSpecified(boolean value) {
        this.f6628e = value;
    }

    public boolean isPortAttributeSpecified() {
        return this.f6628e;
    }

    public void setPortAttributeBlank(boolean value) {
        this.f6629f = value;
    }

    public boolean isPortAttributeBlank() {
        return this.f6629f;
    }

    public void setVersionAttributeSpecified(boolean value) {
        this.f6630g = value;
    }

    public boolean isVersionAttributeSpecified() {
        return this.f6630g;
    }

    @Override // org.apache.commons.httpclient.Cookie
    public String toExternalForm() {
        CookieSpec spec = CookiePolicy.getCookieSpec(CookiePolicy.RFC_2965);
        return spec.formatCookie(this);
    }
}
