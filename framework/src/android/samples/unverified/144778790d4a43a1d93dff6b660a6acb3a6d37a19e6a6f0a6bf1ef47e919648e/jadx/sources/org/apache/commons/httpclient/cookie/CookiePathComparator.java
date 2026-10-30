package org.apache.commons.httpclient.cookie;

import java.util.Comparator;
import org.apache.commons.httpclient.Cookie;

/* JADX INFO: loaded from: classes.dex */
public class CookiePathComparator implements Comparator {
    /* JADX INFO: renamed from: a */
    private static String m2800a(Cookie cookie) {
        String path = cookie.getPath();
        if (path == null) {
            path = CookieSpec.PATH_DELIM;
        }
        if (!path.endsWith(CookieSpec.PATH_DELIM)) {
            return new StringBuffer().append(path).append(CookieSpec.PATH_DELIM).toString();
        }
        return path;
    }

    @Override // java.util.Comparator
    public int compare(Object o1, Object o2) {
        Cookie c1 = (Cookie) o1;
        Cookie c2 = (Cookie) o2;
        String path1 = m2800a(c1);
        String path2 = m2800a(c2);
        if (path1.equals(path2)) {
            return 0;
        }
        if (path1.startsWith(path2)) {
            return -1;
        }
        return path2.startsWith(path1) ? 1 : 0;
    }
}
