package org.apache.commons.httpclient.util;

import java.io.InterruptedIOException;
import java.lang.reflect.Method;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class ExceptionUtil {

    /* JADX INFO: renamed from: a */
    static Class f6766a;

    /* JADX INFO: renamed from: b */
    static Class f6767b;

    /* JADX INFO: renamed from: c */
    private static final Log f6768c;

    /* JADX INFO: renamed from: d */
    private static final Method f6769d;

    /* JADX INFO: renamed from: e */
    private static final Class f6770e;

    static {
        Class clsM2843a;
        if (f6766a == null) {
            clsM2843a = m2843a("org.apache.commons.httpclient.util.ExceptionUtil");
            f6766a = clsM2843a;
        } else {
            clsM2843a = f6766a;
        }
        f6768c = LogFactory.getLog(clsM2843a);
        f6769d = m2844a();
        f6770e = m2845b();
    }

    /* JADX INFO: renamed from: a */
    private static Class m2843a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    /* JADX INFO: renamed from: a */
    private static Method m2844a() {
        Class<?> clsM2843a;
        Class clsM2843a2;
        try {
            Class<?>[] clsArr = new Class[1];
            if (f6767b == null) {
                clsM2843a = m2843a("java.lang.Throwable");
                f6767b = clsM2843a;
            } else {
                clsM2843a = f6767b;
            }
            clsArr[0] = clsM2843a;
            if (f6767b == null) {
                clsM2843a2 = m2843a("java.lang.Throwable");
                f6767b = clsM2843a2;
            } else {
                clsM2843a2 = f6767b;
            }
            return clsM2843a2.getMethod("initCause", clsArr);
        } catch (NoSuchMethodException e) {
            return null;
        }
    }

    /* JADX INFO: renamed from: b */
    private static Class m2845b() {
        try {
            return Class.forName("java.net.SocketTimeoutException");
        } catch (ClassNotFoundException e) {
            return null;
        }
    }

    public static void initCause(Throwable throwable, Throwable cause) {
        if (f6769d != null) {
            try {
                f6769d.invoke(throwable, cause);
            } catch (Exception e) {
                f6768c.warn("Exception invoking Throwable.initCause", e);
            }
        }
    }

    public static boolean isSocketTimeoutException(InterruptedIOException e) {
        if (f6770e != null) {
            return f6770e.isInstance(e);
        }
        return true;
    }
}
