package org.apache.commons.httpclient;

import java.io.IOException;
import java.security.Provider;
import java.security.Security;
import org.apache.commons.httpclient.params.HttpClientParams;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class HttpClient {

    /* JADX INFO: renamed from: a */
    static Class f6452a;

    /* JADX INFO: renamed from: b */
    private static final Log f6453b;

    /* JADX INFO: renamed from: c */
    private HttpConnectionManager f6454c;

    /* JADX INFO: renamed from: d */
    private HttpState f6455d;

    /* JADX INFO: renamed from: e */
    private HttpClientParams f6456e;

    /* JADX INFO: renamed from: f */
    private HostConfiguration f6457f;

    static {
        Class clsM2706a;
        if (f6452a == null) {
            clsM2706a = m2706a("org.apache.commons.httpclient.HttpClient");
            f6452a = clsM2706a;
        } else {
            clsM2706a = f6452a;
        }
        f6453b = LogFactory.getLog(clsM2706a);
        if (f6453b.isDebugEnabled()) {
            try {
                f6453b.debug(new StringBuffer().append("Java version: ").append(System.getProperty("java.version")).toString());
                f6453b.debug(new StringBuffer().append("Java vendor: ").append(System.getProperty("java.vendor")).toString());
                f6453b.debug(new StringBuffer().append("Java class path: ").append(System.getProperty("java.class.path")).toString());
                f6453b.debug(new StringBuffer().append("Operating system name: ").append(System.getProperty("os.name")).toString());
                f6453b.debug(new StringBuffer().append("Operating system architecture: ").append(System.getProperty("os.arch")).toString());
                f6453b.debug(new StringBuffer().append("Operating system version: ").append(System.getProperty("os.version")).toString());
                Provider[] providers = Security.getProviders();
                for (Provider provider : providers) {
                    f6453b.debug(new StringBuffer().append(provider.getName()).append(" ").append(provider.getVersion()).append(": ").append(provider.getInfo()).toString());
                }
            } catch (SecurityException e) {
            }
        }
    }

    /* JADX INFO: renamed from: a */
    private static Class m2706a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public HttpClient() {
        this(new HttpClientParams());
    }

    public HttpClient(HttpClientParams params) {
        this.f6455d = new HttpState();
        this.f6456e = null;
        this.f6457f = new HostConfiguration();
        if (params == null) {
            throw new IllegalArgumentException("Params may not be null");
        }
        this.f6456e = params;
        this.f6454c = null;
        Class clazz = params.getConnectionManagerClass();
        if (clazz != null) {
            try {
                this.f6454c = (HttpConnectionManager) clazz.newInstance();
            } catch (Exception e) {
                f6453b.warn("Error instantiating connection manager class, defaulting to SimpleHttpConnectionManager", e);
            }
        }
        if (this.f6454c == null) {
            this.f6454c = new SimpleHttpConnectionManager();
        }
        if (this.f6454c != null) {
            this.f6454c.getParams().setDefaults(this.f6456e);
        }
    }

    public HttpClient(HttpClientParams params, HttpConnectionManager httpConnectionManager) {
        this.f6455d = new HttpState();
        this.f6456e = null;
        this.f6457f = new HostConfiguration();
        if (httpConnectionManager == null) {
            throw new IllegalArgumentException("httpConnectionManager cannot be null");
        }
        if (params == null) {
            throw new IllegalArgumentException("Params may not be null");
        }
        this.f6456e = params;
        this.f6454c = httpConnectionManager;
        this.f6454c.getParams().setDefaults(this.f6456e);
    }

    public HttpClient(HttpConnectionManager httpConnectionManager) {
        this(new HttpClientParams(), httpConnectionManager);
    }

    public synchronized HttpState getState() {
        return this.f6455d;
    }

    public synchronized void setState(HttpState state) {
        this.f6455d = state;
    }

    public synchronized void setStrictMode(boolean strictMode) {
        try {
            if (strictMode) {
                this.f6456e.makeStrict();
            } else {
                this.f6456e.makeLenient();
            }
        } catch (Throwable th) {
            throw th;
        }
    }

    public synchronized boolean isStrictMode() {
        return false;
    }

    public synchronized void setTimeout(int newTimeoutInMilliseconds) {
        this.f6456e.setSoTimeout(newTimeoutInMilliseconds);
    }

    public synchronized void setHttpConnectionFactoryTimeout(long timeout) {
        this.f6456e.setConnectionManagerTimeout(timeout);
    }

    public synchronized void setConnectionTimeout(int newTimeoutInMilliseconds) {
        this.f6454c.getParams().setConnectionTimeout(newTimeoutInMilliseconds);
    }

    public int executeMethod(HttpMethod method) throws IOException {
        f6453b.trace("enter HttpClient.executeMethod(HttpMethod)");
        return executeMethod(null, method, null);
    }

    public int executeMethod(HostConfiguration hostConfiguration, HttpMethod method) throws IOException {
        f6453b.trace("enter HttpClient.executeMethod(HostConfiguration,HttpMethod)");
        return executeMethod(hostConfiguration, method, null);
    }

    public int executeMethod(HostConfiguration hostconfig, HttpMethod method, HttpState state) throws IOException {
        f6453b.trace("enter HttpClient.executeMethod(HostConfiguration,HttpMethod,HttpState)");
        if (method == null) {
            throw new IllegalArgumentException("HttpMethod parameter may not be null");
        }
        HostConfiguration defaulthostconfig = getHostConfiguration();
        if (hostconfig == null) {
            hostconfig = defaulthostconfig;
        }
        URI uri = method.getURI();
        if (hostconfig == defaulthostconfig || uri.isAbsoluteURI()) {
            hostconfig = (HostConfiguration) hostconfig.clone();
            if (uri.isAbsoluteURI()) {
                hostconfig.setHost(uri);
            }
        }
        HttpConnectionManager httpConnectionManager = getHttpConnectionManager();
        HttpClientParams httpClientParams = this.f6456e;
        if (state == null) {
            state = getState();
        }
        C1120c methodDirector = new C1120c(httpConnectionManager, hostconfig, httpClientParams, state);
        methodDirector.m2799a(method);
        return method.getStatusCode();
    }

    public String getHost() {
        return this.f6457f.getHost();
    }

    public int getPort() {
        return this.f6457f.getPort();
    }

    public synchronized HostConfiguration getHostConfiguration() {
        return this.f6457f;
    }

    public synchronized void setHostConfiguration(HostConfiguration hostConfiguration) {
        this.f6457f = hostConfiguration;
    }

    public synchronized HttpConnectionManager getHttpConnectionManager() {
        return this.f6454c;
    }

    public synchronized void setHttpConnectionManager(HttpConnectionManager httpConnectionManager) {
        this.f6454c = httpConnectionManager;
        if (this.f6454c != null) {
            this.f6454c.getParams().setDefaults(this.f6456e);
        }
    }

    public HttpClientParams getParams() {
        return this.f6456e;
    }

    public void setParams(HttpClientParams params) {
        if (params == null) {
            throw new IllegalArgumentException("Parameters may not be null");
        }
        this.f6456e = params;
    }
}
