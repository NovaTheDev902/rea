package org.apache.commons.httpclient.util;

import com.lenovo.lps.sus.p008c.C0092c;
import java.util.ArrayList;
import java.util.List;
import org.apache.commons.httpclient.HttpConnectionManager;

/* JADX INFO: loaded from: classes.dex */
public class IdleConnectionTimeoutThread extends Thread {

    /* JADX INFO: renamed from: a */
    private List f6778a = new ArrayList();

    /* JADX INFO: renamed from: b */
    private boolean f6779b = false;

    /* JADX INFO: renamed from: c */
    private long f6780c = 1000;

    /* JADX INFO: renamed from: d */
    private long f6781d = C0092c.f1328ap;

    public IdleConnectionTimeoutThread() {
        setDaemon(true);
    }

    public synchronized void addConnectionManager(HttpConnectionManager connectionManager) {
        if (this.f6779b) {
            throw new IllegalStateException("IdleConnectionTimeoutThread has been shutdown");
        }
        this.f6778a.add(connectionManager);
    }

    public synchronized void removeConnectionManager(HttpConnectionManager connectionManager) {
        if (this.f6779b) {
            throw new IllegalStateException("IdleConnectionTimeoutThread has been shutdown");
        }
        this.f6778a.remove(connectionManager);
    }

    protected void handleCloseIdleConnections(HttpConnectionManager connectionManager) {
        connectionManager.closeIdleConnections(this.f6781d);
    }

    @Override // java.lang.Thread, java.lang.Runnable
    public synchronized void run() {
        while (!this.f6779b) {
            for (HttpConnectionManager connectionManager : this.f6778a) {
                handleCloseIdleConnections(connectionManager);
            }
            try {
                wait(this.f6780c);
            } catch (InterruptedException e) {
            }
        }
        this.f6778a.clear();
    }

    public synchronized void shutdown() {
        this.f6779b = true;
        notifyAll();
    }

    public synchronized void setConnectionTimeout(long connectionTimeout) {
        if (this.f6779b) {
            throw new IllegalStateException("IdleConnectionTimeoutThread has been shutdown");
        }
        this.f6781d = connectionTimeout;
    }

    public synchronized void setTimeoutInterval(long timeoutInterval) {
        if (this.f6779b) {
            throw new IllegalStateException("IdleConnectionTimeoutThread has been shutdown");
        }
        this.f6780c = timeoutInterval;
    }
}
