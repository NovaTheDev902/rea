package com.tencent.tmsecure.module.aresengine;

import com.tencent.tmsecure.module.aresengine.TelephonyEntity;
import java.util.concurrent.ConcurrentLinkedQueue;

/* JADX INFO: loaded from: classes.dex */
public abstract class DataMonitor<T extends TelephonyEntity> {

    /* JADX INFO: renamed from: a */
    private Object f6085a = new Object();

    /* JADX INFO: renamed from: b */
    private ConcurrentLinkedQueue<MonitorCallback<T>> f6086b = new ConcurrentLinkedQueue<>();

    /* JADX INFO: renamed from: c */
    private DataFilter<T> f6087c;

    public static abstract class MonitorCallback<T extends TelephonyEntity> {

        /* JADX INFO: renamed from: a */
        private boolean f6088a = false;

        public void abortMonitor() {
            this.f6088a = true;
        }

        public abstract void onCallback(T t);
    }

    public final void addCallback(MonitorCallback<T> monitorCallback) {
        this.f6086b.add(monitorCallback);
    }

    public void bind(DataFilter<T> dataFilter) {
        synchronized (this.f6085a) {
            this.f6087c = dataFilter;
        }
    }

    public final void notifyDataReached(T t, Object... objArr) {
        if (t != null) {
            boolean z = false;
            if (this.f6086b.size() > 0) {
                for (MonitorCallback<T> monitorCallback : this.f6086b) {
                    monitorCallback.onCallback(t);
                    z = ((MonitorCallback) monitorCallback).f6088a;
                    if (z) {
                        break;
                    }
                }
            }
            onPostDataToFilter(z, t, objArr);
            if (z) {
                return;
            }
            synchronized (this.f6085a) {
                if (this.f6087c != null) {
                    this.f6087c.filter(t, objArr);
                }
            }
        }
    }

    public void onPostDataToFilter(boolean z, T t, Object... objArr) {
    }

    public final void removeCallback(MonitorCallback<T> monitorCallback) {
        this.f6086b.remove(monitorCallback);
    }

    public void setRegisterState(boolean z) {
    }

    public void unbind() {
        synchronized (this.f6085a) {
            this.f6087c = null;
        }
    }
}
