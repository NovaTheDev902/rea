package org.apache.commons.httpclient;

import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import org.apache.commons.httpclient.auth.AuthScope;
import org.apache.commons.httpclient.cookie.CookiePolicy;
import org.apache.commons.httpclient.cookie.CookieSpec;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class HttpState {
    public static final String PREEMPTIVE_DEFAULT = "false";
    public static final String PREEMPTIVE_PROPERTY = "httpclient.authentication.preemptive";

    /* JADX INFO: renamed from: a */
    static Class f6511a;

    /* JADX INFO: renamed from: d */
    private static final Log f6512d;
    protected HashMap credMap = new HashMap();
    protected HashMap proxyCred = new HashMap();
    protected ArrayList cookies = new ArrayList();

    /* JADX INFO: renamed from: b */
    private boolean f6513b = false;

    /* JADX INFO: renamed from: c */
    private int f6514c = -1;

    static {
        Class clsM2717a;
        if (f6511a == null) {
            clsM2717a = m2717a("org.apache.commons.httpclient.HttpState");
            f6511a = clsM2717a;
        } else {
            clsM2717a = f6511a;
        }
        f6512d = LogFactory.getLog(clsM2717a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2717a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public synchronized void addCookie(Cookie cookie) {
        f6512d.trace("enter HttpState.addCookie(Cookie)");
        if (cookie != null) {
            Iterator it = this.cookies.iterator();
            while (it.hasNext()) {
                Cookie tmp = (Cookie) it.next();
                if (cookie.equals(tmp)) {
                    it.remove();
                    break;
                }
            }
            if (!cookie.isExpired()) {
                this.cookies.add(cookie);
            }
        }
    }

    public synchronized void addCookies(Cookie[] cookies) {
        f6512d.trace("enter HttpState.addCookies(Cookie[])");
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                addCookie(cookie);
            }
        }
    }

    public synchronized Cookie[] getCookies() {
        f6512d.trace("enter HttpState.getCookies()");
        return (Cookie[]) this.cookies.toArray(new Cookie[this.cookies.size()]);
    }

    public synchronized Cookie[] getCookies(String domain, int port, String path, boolean secure) {
        ArrayList list;
        f6512d.trace("enter HttpState.getCookies(String, int, String, boolean)");
        CookieSpec matcher = CookiePolicy.getDefaultSpec();
        list = new ArrayList(this.cookies.size());
        int m = this.cookies.size();
        for (int i = 0; i < m; i++) {
            Cookie cookie = (Cookie) this.cookies.get(i);
            if (matcher.match(domain, port, path, secure, cookie)) {
                list.add(cookie);
            }
        }
        return (Cookie[]) list.toArray(new Cookie[list.size()]);
    }

    public synchronized boolean purgeExpiredCookies() {
        f6512d.trace("enter HttpState.purgeExpiredCookies()");
        return purgeExpiredCookies(new Date());
    }

    public synchronized boolean purgeExpiredCookies(Date date) {
        boolean removed;
        f6512d.trace("enter HttpState.purgeExpiredCookies(Date)");
        removed = false;
        Iterator it = this.cookies.iterator();
        while (it.hasNext()) {
            if (((Cookie) it.next()).isExpired(date)) {
                it.remove();
                removed = true;
            }
        }
        return removed;
    }

    public int getCookiePolicy() {
        return this.f6514c;
    }

    public void setAuthenticationPreemptive(boolean value) {
        this.f6513b = value;
    }

    public boolean isAuthenticationPreemptive() {
        return this.f6513b;
    }

    public void setCookiePolicy(int policy) {
        this.f6514c = policy;
    }

    public synchronized void setCredentials(String realm, String host, Credentials credentials) {
        f6512d.trace("enter HttpState.setCredentials(String, String, Credentials)");
        this.credMap.put(new AuthScope(host, -1, realm, AuthScope.ANY_SCHEME), credentials);
    }

    public synchronized void setCredentials(AuthScope authscope, Credentials credentials) {
        try {
            if (authscope == null) {
                throw new IllegalArgumentException("Authentication scope may not be null");
            }
            f6512d.trace("enter HttpState.setCredentials(AuthScope, Credentials)");
            this.credMap.put(authscope, credentials);
        } catch (Throwable th) {
            throw th;
        }
    }

    /* JADX INFO: renamed from: a */
    private static Credentials m2720a(HashMap map, AuthScope authscope) {
        Credentials creds = (Credentials) map.get(authscope);
        if (creds == null) {
            int bestMatchFactor = -1;
            AuthScope bestMatch = null;
            for (AuthScope current : map.keySet()) {
                int factor = authscope.match(current);
                if (factor > bestMatchFactor) {
                    bestMatchFactor = factor;
                    bestMatch = current;
                }
            }
            if (bestMatch != null) {
                return (Credentials) map.get(bestMatch);
            }
            return creds;
        }
        return creds;
    }

    public synchronized Credentials getCredentials(String realm, String host) {
        f6512d.trace("enter HttpState.getCredentials(String, String");
        return m2720a(this.credMap, new AuthScope(host, -1, realm, AuthScope.ANY_SCHEME));
    }

    public synchronized Credentials getCredentials(AuthScope authscope) {
        try {
            if (authscope == null) {
                throw new IllegalArgumentException("Authentication scope may not be null");
            }
            f6512d.trace("enter HttpState.getCredentials(AuthScope)");
        } catch (Throwable th) {
            throw th;
        }
        return m2720a(this.credMap, authscope);
    }

    public synchronized void setProxyCredentials(String realm, String proxyHost, Credentials credentials) {
        f6512d.trace("enter HttpState.setProxyCredentials(String, String, Credentials");
        this.proxyCred.put(new AuthScope(proxyHost, -1, realm, AuthScope.ANY_SCHEME), credentials);
    }

    public synchronized void setProxyCredentials(AuthScope authscope, Credentials credentials) {
        try {
            if (authscope == null) {
                throw new IllegalArgumentException("Authentication scope may not be null");
            }
            f6512d.trace("enter HttpState.setProxyCredentials(AuthScope, Credentials)");
            this.proxyCred.put(authscope, credentials);
        } catch (Throwable th) {
            throw th;
        }
    }

    public synchronized Credentials getProxyCredentials(String realm, String proxyHost) {
        f6512d.trace("enter HttpState.getCredentials(String, String");
        return m2720a(this.proxyCred, new AuthScope(proxyHost, -1, realm, AuthScope.ANY_SCHEME));
    }

    public synchronized Credentials getProxyCredentials(AuthScope authscope) {
        try {
            if (authscope == null) {
                throw new IllegalArgumentException("Authentication scope may not be null");
            }
            f6512d.trace("enter HttpState.getProxyCredentials(AuthScope)");
        } catch (Throwable th) {
            throw th;
        }
        return m2720a(this.proxyCred, authscope);
    }

    public synchronized String toString() {
        String strResult;
        StringBuffer sbResult = new StringBuffer();
        sbResult.append("[");
        sbResult.append(m2719a(this.proxyCred));
        sbResult.append(" | ");
        sbResult.append(m2719a(this.credMap));
        sbResult.append(" | ");
        sbResult.append(m2718a(this.cookies));
        sbResult.append("]");
        strResult = sbResult.toString();
        return strResult;
    }

    /* JADX INFO: renamed from: a */
    private static String m2719a(Map credMap) {
        StringBuffer sbResult = new StringBuffer();
        for (Object key : credMap.keySet()) {
            Credentials cred = (Credentials) credMap.get(key);
            if (sbResult.length() > 0) {
                sbResult.append(", ");
            }
            sbResult.append(key);
            sbResult.append("#");
            sbResult.append(cred.toString());
        }
        return sbResult.toString();
    }

    /* JADX INFO: renamed from: a */
    private static String m2718a(List cookies) {
        StringBuffer sbResult = new StringBuffer();
        Iterator iter = cookies.iterator();
        while (iter.hasNext()) {
            Cookie ck = (Cookie) iter.next();
            if (sbResult.length() > 0) {
                sbResult.append("#");
            }
            sbResult.append(ck.toExternalForm());
        }
        return sbResult.toString();
    }

    public void clearCredentials() {
        this.credMap.clear();
    }

    public void clearProxyCredentials() {
        this.proxyCred.clear();
    }

    public synchronized void clearCookies() {
        this.cookies.clear();
    }

    public void clear() {
        clearCookies();
        clearCredentials();
        clearProxyCredentials();
    }
}
