package org.apache.commons.httpclient.protocol;

import java.io.IOException;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.net.InetAddress;
import java.net.Socket;
import org.apache.commons.httpclient.ConnectTimeoutException;

/* JADX INFO: loaded from: classes.dex */
public final class ReflectionSocketFactory {

    /* JADX INFO: renamed from: a */
    static Class f6747a;

    /* JADX INFO: renamed from: b */
    static Class f6748b;

    /* JADX INFO: renamed from: c */
    private static boolean f6749c = false;

    /* JADX INFO: renamed from: d */
    private static Constructor f6750d = null;

    /* JADX INFO: renamed from: e */
    private static Method f6751e = null;

    /* JADX INFO: renamed from: f */
    private static Method f6752f = null;

    /* JADX INFO: renamed from: g */
    private static Class f6753g = null;

    private ReflectionSocketFactory() {
    }

    public static Socket createSocket(String socketfactoryName, String host, int port, InetAddress localAddress, int localPort, int timeout) throws Throwable {
        Class clsM2839a;
        Class clsM2839a2;
        Class<?> clsM2839a3;
        if (f6749c) {
            return null;
        }
        try {
            Class<?> cls = Class.forName(socketfactoryName);
            Method method = cls.getMethod("getDefault", new Class[0]);
            Object socketfactory = method.invoke(null, new Object[0]);
            Method method2 = cls.getMethod("createSocket", new Class[0]);
            Socket socket = (Socket) method2.invoke(socketfactory, new Object[0]);
            if (f6750d == null) {
                Class<?> cls2 = Class.forName("java.net.InetSocketAddress");
                Class<?>[] clsArr = new Class[2];
                if (f6747a == null) {
                    clsM2839a3 = m2839a("java.net.InetAddress");
                    f6747a = clsM2839a3;
                } else {
                    clsM2839a3 = f6747a;
                }
                clsArr[0] = clsM2839a3;
                clsArr[1] = Integer.TYPE;
                f6750d = cls2.getConstructor(clsArr);
            }
            Object remoteaddr = f6750d.newInstance(InetAddress.getByName(host), new Integer(port));
            Object localaddr = f6750d.newInstance(localAddress, new Integer(localPort));
            if (f6751e == null) {
                if (f6748b == null) {
                    clsM2839a2 = m2839a("java.net.Socket");
                    f6748b = clsM2839a2;
                } else {
                    clsM2839a2 = f6748b;
                }
                f6751e = clsM2839a2.getMethod("connect", Class.forName("java.net.SocketAddress"), Integer.TYPE);
            }
            if (f6752f == null) {
                if (f6748b == null) {
                    clsM2839a = m2839a("java.net.Socket");
                    f6748b = clsM2839a;
                } else {
                    clsM2839a = f6748b;
                }
                f6752f = clsM2839a.getMethod("bind", Class.forName("java.net.SocketAddress"));
            }
            f6752f.invoke(socket, localaddr);
            f6751e.invoke(socket, remoteaddr, new Integer(timeout));
            return socket;
        } catch (InvocationTargetException e) {
            Throwable cause = e.getTargetException();
            if (f6753g == null) {
                try {
                    f6753g = Class.forName("java.net.SocketTimeoutException");
                } catch (ClassNotFoundException e2) {
                    f6749c = true;
                    return null;
                }
            }
            if (f6753g.isInstance(cause)) {
                throw new ConnectTimeoutException(new StringBuffer().append("The host did not accept the connection within timeout of ").append(timeout).append(" ms").toString(), cause);
            }
            if (cause instanceof IOException) {
                throw ((IOException) cause);
            }
            return null;
        } catch (Exception e3) {
            f6749c = true;
            return null;
        }
    }

    /* JADX INFO: renamed from: a */
    private static Class m2839a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }
}
