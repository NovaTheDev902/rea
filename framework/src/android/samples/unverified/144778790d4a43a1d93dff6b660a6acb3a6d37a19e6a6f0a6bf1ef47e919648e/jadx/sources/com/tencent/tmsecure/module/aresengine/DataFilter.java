package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.module.aresengine.TelephonyEntity;

/* JADX INFO: loaded from: classes.dex */
public abstract class DataFilter<T extends TelephonyEntity> {

    /* JADX INFO: renamed from: a */
    private Object f6076a = new Object();

    /* JADX INFO: renamed from: b */
    private FilterConfig f6077b;

    /* JADX INFO: renamed from: c */
    private DataHandler f6078c;

    /* JADX INFO: renamed from: a */
    public void m2596a() {
        synchronized (this.f6076a) {
            this.f6078c = null;
        }
    }

    /* JADX INFO: renamed from: a */
    public void m2597a(DataHandler dataHandler) {
        synchronized (this.f6076a) {
            this.f6078c = dataHandler;
        }
    }

    /* JADX INFO: renamed from: b */
    boolean m2598b() {
        boolean z;
        synchronized (this.f6076a) {
            z = this.f6078c != null;
        }
        return z;
    }

    public abstract FilterConfig defalutFilterConfig();

    public final FilterResult filter(T t, Object... objArr) {
        prepare(t);
        FilterResult filterResultOnFiltering = onFiltering(t, objArr);
        onFiltered(t, filterResultOnFiltering);
        synchronized (this.f6076a) {
            if (this.f6078c != null) {
                this.f6078c.sendMessage(filterResultOnFiltering);
            }
        }
        return filterResultOnFiltering;
    }

    public final synchronized FilterConfig getConfig() {
        return this.f6077b;
    }

    public void onFiltered(T t, FilterResult filterResult) {
    }

    protected abstract FilterResult onFiltering(T t, Object... objArr);

    protected void prepare(T t) {
    }

    public final synchronized void setConfig(FilterConfig filterConfig) {
        try {
            if (filterConfig == null) {
                throw new NullPointerException("the filter's config can not be null");
            }
            this.f6077b = filterConfig;
        } catch (Throwable th) {
            throw th;
        }
    }
}
