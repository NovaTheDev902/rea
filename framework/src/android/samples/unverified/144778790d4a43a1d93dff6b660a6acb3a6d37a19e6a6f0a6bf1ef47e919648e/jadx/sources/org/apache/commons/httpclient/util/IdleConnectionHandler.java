package org.apache.commons.httpclient.util;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import org.apache.commons.httpclient.HttpConnection;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class IdleConnectionHandler {

    /* JADX INFO: renamed from: a */
    static Class f6775a;

    /* JADX INFO: renamed from: b */
    private static final Log f6776b;

    /* JADX INFO: renamed from: c */
    private Map f6777c = new HashMap();

    static {
        Class clsM2847a;
        if (f6775a == null) {
            clsM2847a = m2847a("org.apache.commons.httpclient.util.IdleConnectionHandler");
            f6775a = clsM2847a;
        } else {
            clsM2847a = f6775a;
        }
        f6776b = LogFactory.getLog(clsM2847a);
    }

    /* JADX INFO: renamed from: a */
    private static Class m2847a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public void add(HttpConnection connection) {
        Long timeAdded = new Long(System.currentTimeMillis());
        if (f6776b.isDebugEnabled()) {
            f6776b.debug(new StringBuffer().append("Adding connection at: ").append(timeAdded).toString());
        }
        this.f6777c.put(connection, timeAdded);
    }

    public void remove(HttpConnection connection) {
        this.f6777c.remove(connection);
    }

    public void removeAll() {
        this.f6777c.clear();
    }

    public void closeIdleConnections(long idleTime) {
        long idleTimeout = System.currentTimeMillis() - idleTime;
        if (f6776b.isDebugEnabled()) {
            f6776b.debug(new StringBuffer().append("Checking for connections, idleTimeout: ").append(idleTimeout).toString());
        }
        Iterator connectionIter = this.f6777c.keySet().iterator();
        while (connectionIter.hasNext()) {
            HttpConnection conn = (HttpConnection) connectionIter.next();
            Long connectionTime = (Long) this.f6777c.get(conn);
            if (connectionTime.longValue() <= idleTimeout) {
                if (f6776b.isDebugEnabled()) {
                    f6776b.debug(new StringBuffer().append("Closing connection, connection time: ").append(connectionTime).toString());
                }
                connectionIter.remove();
                conn.close();
            }
        }
    }
}
