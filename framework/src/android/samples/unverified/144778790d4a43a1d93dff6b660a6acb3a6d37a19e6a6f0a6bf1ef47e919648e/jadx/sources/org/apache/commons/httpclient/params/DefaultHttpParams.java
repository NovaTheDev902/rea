package org.apache.commons.httpclient.params;

import java.io.Serializable;
import java.util.HashMap;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/* JADX INFO: loaded from: classes.dex */
public class DefaultHttpParams implements Serializable, Cloneable, HttpParams {

    /* JADX INFO: renamed from: a */
    static Class f6728a;

    /* JADX INFO: renamed from: b */
    private static final Log f6729b;

    /* JADX INFO: renamed from: c */
    private static HttpParamsFactory f6730c;

    /* JADX INFO: renamed from: d */
    private HttpParams f6731d;

    /* JADX INFO: renamed from: e */
    private HashMap f6732e;

    static {
        Class clsM2834a;
        if (f6728a == null) {
            clsM2834a = m2834a("org.apache.commons.httpclient.params.DefaultHttpParams");
            f6728a = clsM2834a;
        } else {
            clsM2834a = f6728a;
        }
        f6729b = LogFactory.getLog(clsM2834a);
        f6730c = new DefaultHttpParamsFactory();
    }

    /* JADX INFO: renamed from: a */
    private static Class m2834a(String x0) {
        try {
            return Class.forName(x0);
        } catch (ClassNotFoundException x1) {
            throw new NoClassDefFoundError(x1.getMessage());
        }
    }

    public static HttpParams getDefaultParams() {
        return f6730c.getDefaultParams();
    }

    public static void setHttpParamsFactory(HttpParamsFactory httpParamsFactory) {
        if (httpParamsFactory == null) {
            throw new IllegalArgumentException("httpParamsFactory may not be null");
        }
        f6730c = httpParamsFactory;
    }

    public DefaultHttpParams(HttpParams defaults) {
        this.f6731d = null;
        this.f6732e = null;
        this.f6731d = defaults;
    }

    public DefaultHttpParams() {
        this(getDefaultParams());
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public synchronized HttpParams getDefaults() {
        return this.f6731d;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public synchronized void setDefaults(HttpParams params) {
        this.f6731d = params;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public synchronized Object getParameter(String name) {
        Object param;
        param = this.f6732e != null ? this.f6732e.get(name) : null;
        if (param == null) {
            if (this.f6731d != null) {
                param = this.f6731d.getParameter(name);
            } else {
                param = null;
            }
        }
        return param;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public synchronized void setParameter(String name, Object value) {
        if (this.f6732e == null) {
            this.f6732e = new HashMap();
        }
        this.f6732e.put(name, value);
        if (f6729b.isDebugEnabled()) {
            f6729b.debug(new StringBuffer().append("Set parameter ").append(name).append(" = ").append(value).toString());
        }
    }

    public synchronized void setParameters(String[] names, Object value) {
        for (String str : names) {
            setParameter(str, value);
        }
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public long getLongParameter(String name, long defaultValue) {
        Object param = getParameter(name);
        if (param == null) {
            return defaultValue;
        }
        long defaultValue2 = ((Long) param).longValue();
        return defaultValue2;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public void setLongParameter(String name, long value) {
        setParameter(name, new Long(value));
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public int getIntParameter(String name, int defaultValue) {
        Object param = getParameter(name);
        if (param == null) {
            return defaultValue;
        }
        int defaultValue2 = ((Integer) param).intValue();
        return defaultValue2;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public void setIntParameter(String name, int value) {
        setParameter(name, new Integer(value));
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public double getDoubleParameter(String name, double defaultValue) {
        Object param = getParameter(name);
        if (param == null) {
            return defaultValue;
        }
        double defaultValue2 = ((Double) param).doubleValue();
        return defaultValue2;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public void setDoubleParameter(String name, double value) {
        setParameter(name, new Double(value));
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public boolean getBooleanParameter(String name, boolean defaultValue) {
        Object param = getParameter(name);
        if (param == null) {
            return defaultValue;
        }
        boolean defaultValue2 = ((Boolean) param).booleanValue();
        return defaultValue2;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public void setBooleanParameter(String name, boolean value) {
        setParameter(name, value ? Boolean.TRUE : Boolean.FALSE);
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public boolean isParameterSet(String name) {
        return getParameter(name) != null;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public boolean isParameterSetLocally(String name) {
        return (this.f6732e == null || this.f6732e.get(name) == null) ? false : true;
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public boolean isParameterTrue(String name) {
        return getBooleanParameter(name, false);
    }

    @Override // org.apache.commons.httpclient.params.HttpParams
    public boolean isParameterFalse(String name) {
        return !getBooleanParameter(name, false);
    }

    public void clear() {
        this.f6732e = null;
    }

    public Object clone() throws CloneNotSupportedException {
        DefaultHttpParams clone = (DefaultHttpParams) super.clone();
        if (this.f6732e != null) {
            clone.f6732e = (HashMap) this.f6732e.clone();
        }
        clone.setDefaults(this.f6731d);
        return clone;
    }
}
