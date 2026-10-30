package org.apache.commons.httpclient.auth;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public abstract class AuthPolicy {
    public static final String AUTH_SCHEME_PRIORITY = "http.auth.scheme-priority";
    public static final String BASIC = "Basic";
    public static final String DIGEST = "Digest";
    protected static final Log LOG;
    public static final String NTLM = "NTLM";

    /* JADX INFO: renamed from: a */
    static Class f6578a;

    /* JADX INFO: renamed from: b */
    static Class f6579b;

    /* JADX INFO: renamed from: c */
    static Class f6580c;

    /* JADX INFO: renamed from: d */
    static Class f6581d;

    /* JADX INFO: renamed from: e */
    private static final HashMap f6582e = new HashMap();

    /* JADX INFO: renamed from: f */
    private static final ArrayList f6583f = new ArrayList();

    static {
        Class clsM2761a;
        Class clsM2761a2;
        Class clsM2761a3;
        Class clsM2761a4;
        if (f6578a == null) {
            clsM2761a = m2761a("org.apache.commons.httpclient.auth.NTLMScheme");
            f6578a = clsM2761a;
        } else {
            clsM2761a = f6578a;
        }
        registerAuthScheme(NTLM, clsM2761a);
        if (f6579b == null) {
            clsM2761a2 = m2761a("org.apache.commons.httpclient.auth.DigestScheme");
            f6579b = clsM2761a2;
        } else {
            clsM2761a2 = f6579b;
        }
        registerAuthScheme(DIGEST, clsM2761a2);
        if (f6580c == null) {
            clsM2761a3 = m2761a("org.apache.commons.httpclient.auth.BasicScheme");
            f6580c = clsM2761a3;
        } else {
            clsM2761a3 = f6580c;
        }
        registerAuthScheme(BASIC, clsM2761a3);
        if (f6581d == null) {
            clsM2761a4 = m2761a("org.apache.commons.httpclient.auth.AuthPolicy");
            f6581d = clsM2761a4;
        } else {
            clsM2761a4 = f6581d;
        }
        LOG = LogFactory.getLog(clsM2761a4);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2761a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public static synchronized void registerAuthScheme(String id, Class clazz) {
        try {
            if (id == null) {
                throw new IllegalArgumentException("Id may not be null");
            }
            if (clazz == null) {
                throw new IllegalArgumentException("Authentication scheme class may not be null");
            }
            f6582e.put(id.toLowerCase(), clazz);
            f6583f.add(id.toLowerCase());
        } catch (Throwable th) {
            throw th;
        }
    }

    public static synchronized void unregisterAuthScheme(String id) {
        try {
            if (id == null) {
                throw new IllegalArgumentException("Id may not be null");
            }
            f6582e.remove(id.toLowerCase());
            f6583f.remove(id.toLowerCase());
        } catch (Throwable th) {
            throw th;
        }
    }

    public static synchronized AuthScheme getAuthScheme(String id) throws IllegalStateException {
        Class clazz;
        if (id == null) {
            throw new IllegalArgumentException("Id may not be null");
        }
        clazz = (Class) f6582e.get(id.toLowerCase());
        if (clazz != null) {
            try {
            } catch (Exception e) {
                LOG.error(new StringBuffer().append("Error initializing authentication scheme: ").append(id).toString(), e);
                throw new IllegalStateException(new StringBuffer().append(id).append(" authentication scheme implemented by ").append(clazz.getName()).append(" could not be initialized").toString());
            }
        } else {
            throw new IllegalStateException(new StringBuffer().append("Unsupported authentication scheme ").append(id).toString());
        }
        return (AuthScheme) clazz.newInstance();
    }

    public static synchronized List getDefaultAuthPrefs() {
        return (List) f6583f.clone();
    }
}
