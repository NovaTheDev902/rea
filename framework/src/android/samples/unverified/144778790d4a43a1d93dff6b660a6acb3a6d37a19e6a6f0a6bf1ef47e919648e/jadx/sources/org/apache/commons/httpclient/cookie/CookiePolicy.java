package org.apache.commons.httpclient.cookie;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public abstract class CookiePolicy {
    public static final String BROWSER_COMPATIBILITY = "compatibility";
    public static final int COMPATIBILITY = 0;
    public static final String DEFAULT = "default";
    public static final String IGNORE_COOKIES = "ignoreCookies";
    protected static final Log LOG;
    public static final String NETSCAPE = "netscape";
    public static final int NETSCAPE_DRAFT = 1;
    public static final int RFC2109 = 2;
    public static final int RFC2965 = 3;
    public static final String RFC_2109 = "rfc2109";
    public static final String RFC_2965 = "rfc2965";

    /* JADX INFO: renamed from: a */
    static Class f6635a;

    /* JADX INFO: renamed from: b */
    static Class f6636b;

    /* JADX INFO: renamed from: c */
    static Class f6637c;

    /* JADX INFO: renamed from: d */
    static Class f6638d;

    /* JADX INFO: renamed from: e */
    static Class f6639e;

    /* JADX INFO: renamed from: f */
    static Class f6640f;

    /* JADX INFO: renamed from: g */
    private static Map f6641g = Collections.synchronizedMap(new HashMap());

    /* JADX INFO: renamed from: h */
    private static int f6642h;

    static {
        Class clsM2801a;
        Class clsM2801a2;
        Class clsM2801a3;
        Class clsM2801a4;
        Class clsM2801a5;
        Class clsM2801a6;
        Class clsM2801a7;
        if (f6635a == null) {
            clsM2801a = m2801a("org.apache.commons.httpclient.cookie.RFC2109Spec");
            f6635a = clsM2801a;
        } else {
            clsM2801a = f6635a;
        }
        registerCookieSpec(DEFAULT, clsM2801a);
        if (f6635a == null) {
            clsM2801a2 = m2801a("org.apache.commons.httpclient.cookie.RFC2109Spec");
            f6635a = clsM2801a2;
        } else {
            clsM2801a2 = f6635a;
        }
        registerCookieSpec(RFC_2109, clsM2801a2);
        if (f6636b == null) {
            clsM2801a3 = m2801a("org.apache.commons.httpclient.cookie.RFC2965Spec");
            f6636b = clsM2801a3;
        } else {
            clsM2801a3 = f6636b;
        }
        registerCookieSpec(RFC_2965, clsM2801a3);
        if (f6637c == null) {
            clsM2801a4 = m2801a("org.apache.commons.httpclient.cookie.CookieSpecBase");
            f6637c = clsM2801a4;
        } else {
            clsM2801a4 = f6637c;
        }
        registerCookieSpec(BROWSER_COMPATIBILITY, clsM2801a4);
        if (f6638d == null) {
            clsM2801a5 = m2801a("org.apache.commons.httpclient.cookie.NetscapeDraftSpec");
            f6638d = clsM2801a5;
        } else {
            clsM2801a5 = f6638d;
        }
        registerCookieSpec(NETSCAPE, clsM2801a5);
        if (f6639e == null) {
            clsM2801a6 = m2801a("org.apache.commons.httpclient.cookie.IgnoreCookiesSpec");
            f6639e = clsM2801a6;
        } else {
            clsM2801a6 = f6639e;
        }
        registerCookieSpec(IGNORE_COOKIES, clsM2801a6);
        f6642h = 2;
        if (f6640f == null) {
            clsM2801a7 = m2801a("org.apache.commons.httpclient.cookie.CookiePolicy");
            f6640f = clsM2801a7;
        } else {
            clsM2801a7 = f6640f;
        }
        LOG = LogFactory.getLog(clsM2801a7);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2801a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public static void registerCookieSpec(String id, Class clazz) {
        if (id == null) {
            throw new IllegalArgumentException("Id may not be null");
        }
        if (clazz == null) {
            throw new IllegalArgumentException("Cookie spec class may not be null");
        }
        f6641g.put(id.toLowerCase(), clazz);
    }

    public static void unregisterCookieSpec(String id) {
        if (id == null) {
            throw new IllegalArgumentException("Id may not be null");
        }
        f6641g.remove(id.toLowerCase());
    }

    public static CookieSpec getCookieSpec(String id) throws IllegalStateException {
        if (id == null) {
            throw new IllegalArgumentException("Id may not be null");
        }
        Class clazz = (Class) f6641g.get(id.toLowerCase());
        if (clazz != null) {
            try {
                return (CookieSpec) clazz.newInstance();
            } catch (Exception e) {
                LOG.error(new StringBuffer().append("Error initializing cookie spec: ").append(id).toString(), e);
                throw new IllegalStateException(new StringBuffer().append(id).append(" cookie spec implemented by ").append(clazz.getName()).append(" could not be initialized").toString());
            }
        }
        throw new IllegalStateException(new StringBuffer().append("Unsupported cookie spec ").append(id).toString());
    }

    public static int getDefaultPolicy() {
        return f6642h;
    }

    public static void setDefaultPolicy(int policy) {
        f6642h = policy;
    }

    public static CookieSpec getSpecByPolicy(int policy) {
        switch (policy) {
            case 0:
                return new CookieSpecBase();
            case 1:
                return new NetscapeDraftSpec();
            case 2:
                return new RFC2109Spec();
            case 3:
                return new RFC2965Spec();
            default:
                return getDefaultSpec();
        }
    }

    public static CookieSpec getDefaultSpec() {
        try {
            return getCookieSpec(DEFAULT);
        } catch (IllegalStateException e) {
            LOG.warn("Default cookie policy is not registered");
            return new RFC2109Spec();
        }
    }

    public static CookieSpec getSpecByVersion(int ver) {
        switch (ver) {
            case 0:
                return new NetscapeDraftSpec();
            case 1:
                return new RFC2109Spec();
            default:
                return getDefaultSpec();
        }
    }

    public static CookieSpec getCompatibilitySpec() {
        return getSpecByPolicy(0);
    }

    public static String[] getRegisteredCookieSpecs() {
        return (String[]) f6641g.keySet().toArray(new String[f6641g.size()]);
    }
}
