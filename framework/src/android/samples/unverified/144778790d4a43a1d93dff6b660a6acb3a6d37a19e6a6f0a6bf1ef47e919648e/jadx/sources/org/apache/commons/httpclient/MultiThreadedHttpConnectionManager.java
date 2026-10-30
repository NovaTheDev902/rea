package org.apache.commons.httpclient;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.ref.Reference;
import java.lang.ref.ReferenceQueue;
import java.lang.ref.WeakReference;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.WeakHashMap;
import org.apache.commons.httpclient.params.HttpConnectionManagerParams;
import org.apache.commons.httpclient.params.HttpConnectionParams;
import org.apache.commons.httpclient.protocol.Protocol;
import org.apache.commons.httpclient.util.IdleConnectionHandler;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class MultiThreadedHttpConnectionManager implements HttpConnectionManager {
    public static final int DEFAULT_MAX_HOST_CONNECTIONS = 2;
    public static final int DEFAULT_MAX_TOTAL_CONNECTIONS = 20;

    /* JADX INFO: renamed from: a */
    static Class f6519a;

    /* JADX INFO: renamed from: b */
    private static final Log f6520b;

    /* JADX INFO: renamed from: c */
    private static final Map f6521c;

    /* JADX INFO: renamed from: d */
    private static final ReferenceQueue f6522d;

    /* JADX INFO: renamed from: e */
    private static C1114f f6523e;

    /* JADX INFO: renamed from: f */
    private static WeakHashMap f6524f;

    /* JADX INFO: renamed from: g */
    private HttpConnectionManagerParams f6525g = new HttpConnectionManagerParams();

    /* JADX INFO: renamed from: i */
    private volatile boolean f6527i = false;

    /* JADX INFO: renamed from: h */
    private C1109a f6526h = new C1109a(this, (byte) 0);

    /* JADX INFO: renamed from: a */
    static HostConfiguration m2723a(HttpConnection x1) {
        HostConfiguration hostConfiguration = new HostConfiguration();
        hostConfiguration.setHost(x1.getHost(), x1.getPort(), x1.getProtocol());
        if (x1.getLocalAddress() != null) {
            hostConfiguration.setLocalAddress(x1.getLocalAddress());
        }
        if (x1.getProxyHost() != null) {
            hostConfiguration.setProxy(x1.getProxyHost(), x1.getProxyPort());
        }
        return hostConfiguration;
    }

    /* JADX INFO: renamed from: a */
    static HttpConnectionManagerParams m2725a(MultiThreadedHttpConnectionManager x0) {
        return x0.f6525g;
    }

    /* JADX INFO: renamed from: a */
    static Log m2726a() {
        return f6520b;
    }

    /* JADX INFO: renamed from: a */
    static void m2727a(C1109a x0) {
        ArrayList<HttpConnection> arrayList = new ArrayList();
        synchronized (f6521c) {
            Iterator it = f6521c.keySet().iterator();
            while (it.hasNext()) {
                Reference reference = (Reference) it.next();
                if (((C1110b) f6521c.get(reference)).f6534a == x0) {
                    it.remove();
                    HttpConnection httpConnection = (HttpConnection) reference.get();
                    if (httpConnection != null) {
                        arrayList.add(httpConnection);
                    }
                }
            }
        }
        for (HttpConnection httpConnection2 : arrayList) {
            httpConnection2.close();
            httpConnection2.setHttpConnectionManager(null);
            httpConnection2.releaseConnection();
        }
    }

    /* JADX INFO: renamed from: a */
    static void m2728a(C1113e x0) {
        synchronized (f6521c) {
            f6521c.remove(x0.f6541b);
        }
    }

    /* JADX INFO: renamed from: a */
    static void m2729a(C1113e x0, HostConfiguration x1, C1109a x2) {
        C1110b c1110b = new C1110b((byte) 0);
        c1110b.f6534a = x2;
        c1110b.f6535b = x1;
        synchronized (f6521c) {
            if (f6523e == null) {
                f6523e = new C1114f();
                f6523e.start();
            }
            f6521c.put(x0.f6541b, c1110b);
        }
    }

    /* JADX INFO: renamed from: b */
    static Map m2730b() {
        return f6521c;
    }

    /* JADX INFO: renamed from: b */
    static boolean m2731b(MultiThreadedHttpConnectionManager x0) {
        return x0.f6527i;
    }

    /* JADX INFO: renamed from: c */
    static ReferenceQueue m2732c() {
        return f6522d;
    }

    static {
        Class clsM2722a;
        if (f6519a == null) {
            clsM2722a = m2722a("org.apache.commons.httpclient.MultiThreadedHttpConnectionManager");
            f6519a = clsM2722a;
        } else {
            clsM2722a = f6519a;
        }
        f6520b = LogFactory.getLog(clsM2722a);
        f6521c = new HashMap();
        f6522d = new ReferenceQueue();
        f6524f = new WeakHashMap();
    }

    /* JADX INFO: renamed from: a */
    private static Class m2722a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public static void shutdownAll() {
        synchronized (f6521c) {
            synchronized (f6524f) {
                MultiThreadedHttpConnectionManager[] connManagers = (MultiThreadedHttpConnectionManager[]) f6524f.keySet().toArray(new MultiThreadedHttpConnectionManager[f6524f.size()]);
                for (int i = 0; i < connManagers.length; i++) {
                    if (connManagers[i] != null) {
                        connManagers[i].shutdown();
                    }
                }
            }
            if (f6523e != null) {
                f6523e.m2750a();
                f6523e = null;
            }
            f6521c.clear();
        }
    }

    public MultiThreadedHttpConnectionManager() {
        synchronized (f6524f) {
            f6524f.put(this, null);
        }
    }

    public synchronized void shutdown() {
        synchronized (this.f6526h) {
            if (!this.f6527i) {
                this.f6527i = true;
                this.f6526h.m2741a();
            }
        }
    }

    public boolean isConnectionStaleCheckingEnabled() {
        return this.f6525g.isStaleCheckingEnabled();
    }

    public void setConnectionStaleCheckingEnabled(boolean connectionStaleCheckingEnabled) {
        this.f6525g.setStaleCheckingEnabled(connectionStaleCheckingEnabled);
    }

    public void setMaxConnectionsPerHost(int maxHostConnections) {
        this.f6525g.setDefaultMaxConnectionsPerHost(maxHostConnections);
    }

    public int getMaxConnectionsPerHost() {
        return this.f6525g.getDefaultMaxConnectionsPerHost();
    }

    public void setMaxTotalConnections(int maxTotalConnections) {
        this.f6525g.setMaxTotalConnections(maxTotalConnections);
    }

    public int getMaxTotalConnections() {
        return this.f6525g.getMaxTotalConnections();
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnection getConnection(HostConfiguration hostConfiguration) {
        while (true) {
            try {
                return getConnectionWithTimeout(hostConfiguration, 0L);
            } catch (ConnectionPoolTimeoutException e) {
                f6520b.debug("Unexpected exception while waiting for connection", e);
            }
        }
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnection getConnectionWithTimeout(HostConfiguration hostConfiguration, long timeout) throws Throwable {
        f6520b.trace("enter HttpConnectionManager.getConnectionWithTimeout(HostConfiguration, long)");
        if (hostConfiguration == null) {
            throw new IllegalArgumentException("hostConfiguration is null");
        }
        if (f6520b.isDebugEnabled()) {
            f6520b.debug(new StringBuffer().append("HttpConnectionManager.getConnection:  config = ").append(hostConfiguration).append(", timeout = ").append(timeout).toString());
        }
        HttpConnection conn = m2724a(hostConfiguration, timeout);
        return new C1112d(conn);
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnection getConnection(HostConfiguration hostConfiguration, long timeout) throws HttpException {
        f6520b.trace("enter HttpConnectionManager.getConnection(HostConfiguration, long)");
        try {
            return getConnectionWithTimeout(hostConfiguration, timeout);
        } catch (ConnectionPoolTimeoutException e) {
            throw new HttpException(e.getMessage());
        }
    }

    /* JADX WARN: Code duplicated, block: B:47:0x0108 A[Catch: all -> 0x005d, TryCatch #4 {all -> 0x005d, blocks: (B:5:0x0027, B:10:0x0049, B:12:0x0051, B:13:0x005c, B:19:0x0064, B:21:0x006e, B:22:0x007b, B:24:0x0083, B:26:0x0091, B:27:0x009e, B:29:0x00a6, B:31:0x00b6, B:70:0x01c1, B:72:0x01c7, B:74:0x01e1, B:45:0x0102, B:47:0x0108, B:49:0x0122, B:50:0x0125, B:60:0x018a, B:62:0x0190, B:64:0x01aa, B:75:0x01ea), top: B:89:0x0027 }] */
    /* JADX WARN: Code duplicated, block: B:49:0x0122 A[Catch: all -> 0x005d, TryCatch #4 {all -> 0x005d, blocks: (B:5:0x0027, B:10:0x0049, B:12:0x0051, B:13:0x005c, B:19:0x0064, B:21:0x006e, B:22:0x007b, B:24:0x0083, B:26:0x0091, B:27:0x009e, B:29:0x00a6, B:31:0x00b6, B:70:0x01c1, B:72:0x01c7, B:74:0x01e1, B:45:0x0102, B:47:0x0108, B:49:0x0122, B:50:0x0125, B:60:0x018a, B:62:0x0190, B:64:0x01aa, B:75:0x01ea), top: B:89:0x0027 }] */
    /* JADX INFO: renamed from: a */
    private HttpConnection m2724a(HostConfiguration hostConfiguration, long timeout) throws Throwable {
        C1115g waitingThread;
        HttpConnection connection = null;
        int maxHostConnections = this.f6525g.getMaxConnectionsPerHost(hostConfiguration);
        int maxTotalConnections = this.f6525g.getMaxTotalConnections();
        synchronized (this.f6526h) {
            try {
                HostConfiguration hostConfiguration2 = new HostConfiguration(hostConfiguration);
                try {
                    C1111c hostPool = this.f6526h.m2740a(hostConfiguration2, true);
                    boolean useTimeout = timeout > 0;
                    long timeToWait = timeout;
                    long startWait = 0;
                    C1115g waitingThread2 = null;
                    while (connection == null) {
                        if (this.f6527i) {
                            throw new IllegalStateException("Connection factory has been shutdown.");
                        }
                        if (hostPool.f6537b.size() > 0) {
                            connection = this.f6526h.m2746c(hostConfiguration2);
                        } else if (hostPool.f6539d < maxHostConnections && C1109a.m2733a(this.f6526h) < maxTotalConnections) {
                            connection = this.f6526h.m2739a(hostConfiguration2);
                        } else if (hostPool.f6539d < maxHostConnections && C1109a.m2735b(this.f6526h).size() > 0) {
                            this.f6526h.m2747c();
                            connection = this.f6526h.m2739a(hostConfiguration2);
                        } else {
                            if (useTimeout && timeToWait <= 0) {
                                throw new ConnectionPoolTimeoutException("Timeout waiting for connection");
                            }
                            try {
                                if (f6520b.isDebugEnabled()) {
                                    f6520b.debug(new StringBuffer().append("Unable to get a connection, waiting..., hostConfig=").append(hostConfiguration2).toString());
                                }
                                if (waitingThread2 == null) {
                                    waitingThread = new C1115g((byte) 0);
                                    try {
                                        waitingThread.f6544b = hostPool;
                                        waitingThread.f6543a = Thread.currentThread();
                                    } catch (InterruptedException e) {
                                        e = e;
                                        try {
                                            if (!waitingThread.f6545c) {
                                                f6520b.debug("Interrupted while waiting for connection", e);
                                                throw new IllegalThreadStateException("Interrupted while waiting in MultiThreadedHttpConnectionManager");
                                            }
                                            if (!waitingThread.f6545c) {
                                                hostPool.f6538c.remove(waitingThread);
                                                C1109a.m2737c(this.f6526h).remove(waitingThread);
                                            }
                                            if (useTimeout) {
                                                long endWait = System.currentTimeMillis();
                                                timeToWait -= endWait - startWait;
                                            }
                                        } catch (Throwable th) {
                                            th = th;
                                            if (!waitingThread.f6545c) {
                                                hostPool.f6538c.remove(waitingThread);
                                                C1109a.m2737c(this.f6526h).remove(waitingThread);
                                            }
                                            if (useTimeout) {
                                                System.currentTimeMillis();
                                            }
                                            throw th;
                                        }
                                    }
                                } else {
                                    waitingThread2.f6545c = false;
                                    waitingThread = waitingThread2;
                                }
                                if (useTimeout) {
                                    startWait = System.currentTimeMillis();
                                }
                                hostPool.f6538c.addLast(waitingThread);
                                C1109a.m2737c(this.f6526h).addLast(waitingThread);
                                this.f6526h.wait(timeToWait);
                                if (!waitingThread.f6545c) {
                                    hostPool.f6538c.remove(waitingThread);
                                    C1109a.m2737c(this.f6526h).remove(waitingThread);
                                }
                                if (useTimeout) {
                                    long endWait2 = System.currentTimeMillis();
                                    timeToWait -= endWait2 - startWait;
                                }
                            } catch (InterruptedException e2) {
                                e = e2;
                                waitingThread = waitingThread2;
                            } catch (Throwable th2) {
                                th = th2;
                                waitingThread = waitingThread2;
                                if (!waitingThread.f6545c) {
                                    hostPool.f6538c.remove(waitingThread);
                                    C1109a.m2737c(this.f6526h).remove(waitingThread);
                                }
                                if (useTimeout) {
                                    System.currentTimeMillis();
                                }
                                throw th;
                            }
                            waitingThread2 = waitingThread;
                        }
                    }
                    return connection;
                } catch (Throwable th3) {
                    th = th3;
                    throw th;
                }
            } catch (Throwable th4) {
                th = th4;
            }
        }
    }

    public int getConnectionsInPool(HostConfiguration hostConfiguration) {
        int i;
        synchronized (this.f6526h) {
            C1111c hostPool = this.f6526h.m2740a(hostConfiguration, false);
            i = hostPool != null ? hostPool.f6539d : 0;
        }
        return i;
    }

    public int getConnectionsInPool() {
        int iM2733a;
        synchronized (this.f6526h) {
            iM2733a = C1109a.m2733a(this.f6526h);
        }
        return iM2733a;
    }

    public int getConnectionsInUse(HostConfiguration hostConfiguration) {
        return getConnectionsInPool(hostConfiguration);
    }

    public int getConnectionsInUse() {
        return getConnectionsInPool();
    }

    public void deleteClosedConnections() {
        this.f6526h.m2744b();
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public void closeIdleConnections(long idleTimeout) {
        this.f6526h.m2742a(idleTimeout);
        deleteClosedConnections();
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public void releaseConnection(HttpConnection conn) {
        f6520b.trace("enter HttpConnectionManager.releaseConnection(HttpConnection)");
        if (conn instanceof C1112d) {
            conn = ((C1112d) conn).m2749a();
        }
        SimpleHttpConnectionManager.m2756a(conn);
        this.f6526h.m2743a(conn);
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public HttpConnectionManagerParams getParams() {
        return this.f6525g;
    }

    @Override // org.apache.commons.httpclient.HttpConnectionManager
    public void setParams(HttpConnectionManagerParams params) {
        if (params == null) {
            throw new IllegalArgumentException("Parameters may not be null");
        }
        this.f6525g = params;
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.MultiThreadedHttpConnectionManager$a */
    private class C1109a {

        /* JADX INFO: renamed from: a */
        private LinkedList f6528a;

        /* JADX INFO: renamed from: b */
        private LinkedList f6529b;

        /* JADX INFO: renamed from: c */
        private final Map f6530c;

        /* JADX INFO: renamed from: d */
        private IdleConnectionHandler f6531d;

        /* JADX INFO: renamed from: e */
        private int f6532e;

        /* JADX INFO: renamed from: f */
        private final MultiThreadedHttpConnectionManager f6533f;

        private C1109a(MultiThreadedHttpConnectionManager multiThreadedHttpConnectionManager) {
            this.f6533f = multiThreadedHttpConnectionManager;
            this.f6528a = new LinkedList();
            this.f6529b = new LinkedList();
            this.f6530c = new HashMap();
            this.f6531d = new IdleConnectionHandler();
            this.f6532e = 0;
        }

        C1109a(MultiThreadedHttpConnectionManager x0, byte b) {
            this(x0);
        }

        /* JADX INFO: renamed from: a */
        static int m2733a(C1109a x0) {
            return x0.f6532e;
        }

        /* JADX INFO: renamed from: b */
        static LinkedList m2735b(C1109a x0) {
            return x0.f6528a;
        }

        /* JADX INFO: renamed from: c */
        static LinkedList m2737c(C1109a x0) {
            return x0.f6529b;
        }

        /* JADX INFO: renamed from: a */
        public final synchronized void m2741a() {
            Iterator iter = this.f6528a.iterator();
            while (iter.hasNext()) {
                HttpConnection conn = (HttpConnection) iter.next();
                iter.remove();
                conn.close();
            }
            MultiThreadedHttpConnectionManager.m2727a(this);
            Iterator iter2 = this.f6529b.iterator();
            while (iter2.hasNext()) {
                C1115g waiter = (C1115g) iter2.next();
                iter2.remove();
                waiter.f6545c = true;
                waiter.f6543a.interrupt();
            }
            this.f6530c.clear();
            this.f6531d.removeAll();
        }

        /* JADX INFO: renamed from: a */
        public final synchronized HttpConnection m2739a(HostConfiguration hostConfiguration) {
            C1113e connection;
            C1111c hostPool = m2740a(hostConfiguration, true);
            if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                MultiThreadedHttpConnectionManager.m2726a().debug(new StringBuffer().append("Allocating new connection, hostConfig=").append(hostConfiguration).toString());
            }
            connection = new C1113e(hostConfiguration);
            connection.getParams().setDefaults(MultiThreadedHttpConnectionManager.m2725a(this.f6533f));
            connection.setHttpConnectionManager(this.f6533f);
            this.f6532e++;
            hostPool.f6539d++;
            MultiThreadedHttpConnectionManager.m2729a(connection, hostConfiguration, this);
            return connection;
        }

        /* JADX INFO: renamed from: b */
        public final synchronized void m2745b(HostConfiguration config) {
            C1111c hostPool = m2740a(config, true);
            hostPool.f6539d--;
            if (hostPool.f6539d == 0 && hostPool.f6538c.isEmpty()) {
                this.f6530c.remove(config);
            }
            this.f6532e--;
            m2738d(config);
        }

        /* JADX INFO: renamed from: a */
        public final synchronized C1111c m2740a(HostConfiguration hostConfiguration, boolean create) {
            C1111c listConnections;
            MultiThreadedHttpConnectionManager.m2726a().trace("enter HttpConnectionManager.ConnectionPool.getHostPool(HostConfiguration)");
            listConnections = (C1111c) this.f6530c.get(hostConfiguration);
            if (listConnections == null && create) {
                listConnections = new C1111c((byte) 0);
                listConnections.f6536a = hostConfiguration;
                this.f6530c.put(hostConfiguration, listConnections);
            }
            return listConnections;
        }

        /* JADX INFO: renamed from: c */
        public final synchronized HttpConnection m2746c(HostConfiguration hostConfiguration) {
            C1113e connection;
            connection = null;
            C1111c hostPool = m2740a(hostConfiguration, false);
            if (hostPool != null && hostPool.f6537b.size() > 0) {
                connection = (C1113e) hostPool.f6537b.removeLast();
                this.f6528a.remove(connection);
                MultiThreadedHttpConnectionManager.m2729a(connection, hostConfiguration, this);
                if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                    MultiThreadedHttpConnectionManager.m2726a().debug(new StringBuffer().append("Getting free connection, hostConfig=").append(hostConfiguration).toString());
                }
                this.f6531d.remove(connection);
            } else if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                MultiThreadedHttpConnectionManager.m2726a().debug(new StringBuffer().append("There were no free connections to get, hostConfig=").append(hostConfiguration).toString());
            }
            return connection;
        }

        /* JADX INFO: renamed from: b */
        public final synchronized void m2744b() {
            Iterator iter = this.f6528a.iterator();
            while (iter.hasNext()) {
                HttpConnection conn = (HttpConnection) iter.next();
                if (!conn.isOpen()) {
                    iter.remove();
                    m2736b(conn);
                }
            }
        }

        /* JADX INFO: renamed from: a */
        public final synchronized void m2742a(long idleTimeout) {
            this.f6531d.closeIdleConnections(idleTimeout);
        }

        /* JADX INFO: renamed from: b */
        private synchronized void m2736b(HttpConnection connection) {
            MultiThreadedHttpConnectionManager multiThreadedHttpConnectionManager = this.f6533f;
            HostConfiguration connectionConfiguration = MultiThreadedHttpConnectionManager.m2723a(connection);
            if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                MultiThreadedHttpConnectionManager.m2726a().debug(new StringBuffer().append("Reclaiming connection, hostConfig=").append(connectionConfiguration).toString());
            }
            connection.close();
            C1111c hostPool = m2740a(connectionConfiguration, true);
            hostPool.f6537b.remove(connection);
            hostPool.f6539d--;
            this.f6532e--;
            if (hostPool.f6539d == 0 && hostPool.f6538c.isEmpty()) {
                this.f6530c.remove(connectionConfiguration);
            }
            this.f6531d.remove(connection);
        }

        /* JADX INFO: renamed from: c */
        public final synchronized void m2747c() {
            HttpConnection connection = (HttpConnection) this.f6528a.removeFirst();
            if (connection != null) {
                m2736b(connection);
            } else if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                MultiThreadedHttpConnectionManager.m2726a().debug("Attempted to reclaim an unused connection but there were none.");
            }
        }

        /* JADX INFO: renamed from: d */
        private synchronized void m2738d(HostConfiguration configuration) {
            m2734a(m2740a(configuration, true));
        }

        /* JADX INFO: renamed from: a */
        private synchronized void m2734a(C1111c hostPool) {
            C1115g waitingThread = null;
            if (hostPool.f6538c.size() > 0) {
                if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                    MultiThreadedHttpConnectionManager.m2726a().debug(new StringBuffer().append("Notifying thread waiting on host pool, hostConfig=").append(hostPool.f6536a).toString());
                }
                waitingThread = (C1115g) hostPool.f6538c.removeFirst();
                this.f6529b.remove(waitingThread);
            } else if (this.f6529b.size() > 0) {
                if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                    MultiThreadedHttpConnectionManager.m2726a().debug("No-one waiting on host pool, notifying next waiting thread.");
                }
                waitingThread = (C1115g) this.f6529b.removeFirst();
                waitingThread.f6544b.f6538c.remove(waitingThread);
            } else if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                MultiThreadedHttpConnectionManager.m2726a().debug("Notifying no-one, there are no waiting threads");
            }
            if (waitingThread != null) {
                waitingThread.f6545c = true;
                waitingThread.f6543a.interrupt();
            }
        }

        /* JADX INFO: renamed from: a */
        public final void m2743a(HttpConnection conn) {
            MultiThreadedHttpConnectionManager multiThreadedHttpConnectionManager = this.f6533f;
            HostConfiguration connectionConfiguration = MultiThreadedHttpConnectionManager.m2723a(conn);
            if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                MultiThreadedHttpConnectionManager.m2726a().debug(new StringBuffer().append("Freeing connection, hostConfig=").append(connectionConfiguration).toString());
            }
            synchronized (this) {
                if (MultiThreadedHttpConnectionManager.m2731b(this.f6533f)) {
                    conn.close();
                    return;
                }
                C1111c hostPool = m2740a(connectionConfiguration, true);
                hostPool.f6537b.add(conn);
                if (hostPool.f6539d == 0) {
                    MultiThreadedHttpConnectionManager.m2726a().error(new StringBuffer().append("Host connection pool not found, hostConfig=").append(connectionConfiguration).toString());
                    hostPool.f6539d = 1;
                }
                this.f6528a.add(conn);
                MultiThreadedHttpConnectionManager.m2728a((C1113e) conn);
                if (this.f6532e == 0) {
                    MultiThreadedHttpConnectionManager.m2726a().error(new StringBuffer().append("Host connection pool not found, hostConfig=").append(connectionConfiguration).toString());
                    this.f6532e = 1;
                }
                this.f6531d.add(conn);
                m2734a(hostPool);
            }
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.MultiThreadedHttpConnectionManager$b */
    private static class C1110b {

        /* JADX INFO: renamed from: a */
        public C1109a f6534a;

        /* JADX INFO: renamed from: b */
        public HostConfiguration f6535b;

        private C1110b() {
        }

        C1110b(byte b) {
            this();
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.MultiThreadedHttpConnectionManager$c */
    private static class C1111c {

        /* JADX INFO: renamed from: a */
        public HostConfiguration f6536a;

        /* JADX INFO: renamed from: b */
        public LinkedList f6537b;

        /* JADX INFO: renamed from: c */
        public LinkedList f6538c;

        /* JADX INFO: renamed from: d */
        public int f6539d;

        private C1111c() {
            this.f6537b = new LinkedList();
            this.f6538c = new LinkedList();
            this.f6539d = 0;
        }

        C1111c(byte b) {
            this();
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.MultiThreadedHttpConnectionManager$g */
    private static class C1115g {

        /* JADX INFO: renamed from: a */
        public Thread f6543a;

        /* JADX INFO: renamed from: b */
        public C1111c f6544b;

        /* JADX INFO: renamed from: c */
        public boolean f6545c;

        private C1115g() {
            this.f6545c = false;
        }

        C1115g(byte b) {
            this();
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.MultiThreadedHttpConnectionManager$f */
    private static class C1114f extends Thread {

        /* JADX INFO: renamed from: a */
        private volatile boolean f6542a = false;

        public C1114f() {
            setDaemon(true);
            setName("MultiThreadedHttpConnectionManager cleanup");
        }

        /* JADX INFO: renamed from: a */
        public final void m2750a() {
            this.f6542a = true;
            interrupt();
        }

        @Override // java.lang.Thread, java.lang.Runnable
        public final void run() {
            C1110b c1110b;
            while (!this.f6542a) {
                try {
                    Reference ref = MultiThreadedHttpConnectionManager.m2732c().remove();
                    if (ref != null) {
                        synchronized (MultiThreadedHttpConnectionManager.m2730b()) {
                            try {
                                c1110b = (C1110b) MultiThreadedHttpConnectionManager.m2730b().remove(ref);
                            } catch (Throwable th) {
                                throw th;
                            }
                        }
                        if (c1110b != null) {
                            if (MultiThreadedHttpConnectionManager.m2726a().isDebugEnabled()) {
                                MultiThreadedHttpConnectionManager.m2726a().debug(new StringBuffer().append("Connection reclaimed by garbage collector, hostConfig=").append(c1110b.f6535b).toString());
                            }
                            c1110b.f6534a.m2745b(c1110b.f6535b);
                        }
                    } else {
                        continue;
                    }
                } catch (InterruptedException e) {
                    MultiThreadedHttpConnectionManager.m2726a().debug("ReferenceQueueThread interrupted", e);
                }
            }
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.MultiThreadedHttpConnectionManager$e */
    private static class C1113e extends HttpConnection {

        /* JADX INFO: renamed from: b */
        public WeakReference f6541b;

        public C1113e(HostConfiguration hostConfiguration) {
            super(hostConfiguration);
            this.f6541b = new WeakReference(this, MultiThreadedHttpConnectionManager.m2732c());
        }
    }

    /* JADX INFO: renamed from: org.apache.commons.httpclient.MultiThreadedHttpConnectionManager$d */
    private static class C1112d extends HttpConnection {

        /* JADX INFO: renamed from: b */
        private HttpConnection f6540b;

        public C1112d(HttpConnection connection) {
            super(connection.getHost(), connection.getPort(), connection.getProtocol());
            this.f6540b = connection;
        }

        /* JADX INFO: renamed from: b */
        private boolean m2748b() {
            return this.f6540b != null;
        }

        /* JADX INFO: renamed from: a */
        final HttpConnection m2749a() {
            return this.f6540b;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void close() {
            if (m2748b()) {
                this.f6540b.close();
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final InetAddress getLocalAddress() {
            if (m2748b()) {
                return this.f6540b.getLocalAddress();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean isStaleCheckingEnabled() {
            if (m2748b()) {
                return this.f6540b.isStaleCheckingEnabled();
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setLocalAddress(InetAddress localAddress) {
            if (m2748b()) {
                this.f6540b.setLocalAddress(localAddress);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setStaleCheckingEnabled(boolean staleCheckEnabled) {
            if (m2748b()) {
                this.f6540b.setStaleCheckingEnabled(staleCheckEnabled);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final String getHost() {
            if (m2748b()) {
                return this.f6540b.getHost();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final HttpConnectionManager getHttpConnectionManager() {
            if (m2748b()) {
                return this.f6540b.getHttpConnectionManager();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final InputStream getLastResponseInputStream() {
            if (m2748b()) {
                return this.f6540b.getLastResponseInputStream();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final int getPort() {
            if (m2748b()) {
                return this.f6540b.getPort();
            }
            return -1;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final Protocol getProtocol() {
            if (m2748b()) {
                return this.f6540b.getProtocol();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final String getProxyHost() {
            if (m2748b()) {
                return this.f6540b.getProxyHost();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final int getProxyPort() {
            if (m2748b()) {
                return this.f6540b.getProxyPort();
            }
            return -1;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final OutputStream getRequestOutputStream() throws IllegalStateException, IOException {
            if (m2748b()) {
                return this.f6540b.getRequestOutputStream();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final InputStream getResponseInputStream() throws IllegalStateException, IOException {
            if (m2748b()) {
                return this.f6540b.getResponseInputStream();
            }
            return null;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean isOpen() {
            if (m2748b()) {
                return this.f6540b.isOpen();
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean closeIfStale() throws IOException {
            if (m2748b()) {
                return this.f6540b.closeIfStale();
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean isProxied() {
            if (m2748b()) {
                return this.f6540b.isProxied();
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean isResponseAvailable() throws IOException {
            if (m2748b()) {
                return this.f6540b.isResponseAvailable();
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean isResponseAvailable(int timeout) throws IOException {
            if (m2748b()) {
                return this.f6540b.isResponseAvailable(timeout);
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean isSecure() {
            if (m2748b()) {
                return this.f6540b.isSecure();
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final boolean isTransparent() {
            if (m2748b()) {
                return this.f6540b.isTransparent();
            }
            return false;
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void open() throws IOException {
            if (m2748b()) {
                this.f6540b.open();
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void print(String data) throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.print(data);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void printLine() throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.printLine();
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void printLine(String data) throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.printLine(data);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final String readLine() throws IllegalStateException, IOException {
            if (m2748b()) {
                return this.f6540b.readLine();
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final String readLine(String charset) throws IllegalStateException, IOException {
            if (m2748b()) {
                return this.f6540b.readLine(charset);
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void releaseConnection() {
            if (!isLocked() && m2748b()) {
                HttpConnection wrappedConnection = this.f6540b;
                this.f6540b = null;
                wrappedConnection.releaseConnection();
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setConnectionTimeout(int timeout) {
            if (m2748b()) {
                this.f6540b.setConnectionTimeout(timeout);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setHost(String host) throws IllegalStateException {
            if (m2748b()) {
                this.f6540b.setHost(host);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setHttpConnectionManager(HttpConnectionManager httpConnectionManager) {
            if (m2748b()) {
                this.f6540b.setHttpConnectionManager(httpConnectionManager);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setLastResponseInputStream(InputStream inStream) {
            if (m2748b()) {
                this.f6540b.setLastResponseInputStream(inStream);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setPort(int port) throws IllegalStateException {
            if (m2748b()) {
                this.f6540b.setPort(port);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setProtocol(Protocol protocol) {
            if (m2748b()) {
                this.f6540b.setProtocol(protocol);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setProxyHost(String host) throws IllegalStateException {
            if (m2748b()) {
                this.f6540b.setProxyHost(host);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setProxyPort(int port) throws IllegalStateException {
            if (m2748b()) {
                this.f6540b.setProxyPort(port);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setSoTimeout(int timeout) throws IllegalStateException, SocketException {
            if (m2748b()) {
                this.f6540b.setSoTimeout(timeout);
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void shutdownOutput() {
            if (m2748b()) {
                this.f6540b.shutdownOutput();
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void tunnelCreated() throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.tunnelCreated();
            }
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void write(byte[] data, int offset, int length) throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.write(data, offset, length);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void write(byte[] data) throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.write(data);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void writeLine() throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.writeLine();
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void writeLine(byte[] data) throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.writeLine(data);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void flushRequestOutputStream() throws IOException {
            if (m2748b()) {
                this.f6540b.flushRequestOutputStream();
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final int getSoTimeout() throws SocketException {
            if (m2748b()) {
                return this.f6540b.getSoTimeout();
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final String getVirtualHost() {
            if (m2748b()) {
                return this.f6540b.getVirtualHost();
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setVirtualHost(String host) throws IllegalStateException {
            if (m2748b()) {
                this.f6540b.setVirtualHost(host);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final int getSendBufferSize() throws SocketException {
            if (m2748b()) {
                return this.f6540b.getSendBufferSize();
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setSendBufferSize(int sendBufferSize) throws SocketException {
            if (m2748b()) {
                this.f6540b.setSendBufferSize(sendBufferSize);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final HttpConnectionParams getParams() {
            if (m2748b()) {
                return this.f6540b.getParams();
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setParams(HttpConnectionParams params) {
            if (m2748b()) {
                this.f6540b.setParams(params);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void print(String data, String charset) throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.print(data, charset);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void printLine(String data, String charset) throws IllegalStateException, IOException {
            if (m2748b()) {
                this.f6540b.printLine(data, charset);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }

        @Override // org.apache.commons.httpclient.HttpConnection
        public final void setSocketTimeout(int timeout) throws IllegalStateException, SocketException {
            if (m2748b()) {
                this.f6540b.setSocketTimeout(timeout);
                return;
            }
            throw new IllegalStateException("Connection has been released");
        }
    }
}
