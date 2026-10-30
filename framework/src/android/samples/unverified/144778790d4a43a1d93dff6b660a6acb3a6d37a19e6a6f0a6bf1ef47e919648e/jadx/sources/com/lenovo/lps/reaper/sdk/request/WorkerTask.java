package com.lenovo.lps.reaper.sdk.request;

import com.lenovo.lps.reaper.sdk.api.DispatchCallback;
import com.lenovo.lps.reaper.sdk.util.TLog;

/* JADX INFO: loaded from: classes.dex */
public final class WorkerTask implements Runnable {

    /* JADX INFO: renamed from: a */
    private static final String f1148a = WorkerTask.class.getName();

    /* JADX INFO: renamed from: b */
    private final DispatchCallback f1149b;

    public WorkerTask(DispatchCallback dispatchCallback) {
        this.f1149b = dispatchCallback;
    }

    @Override // java.lang.Runnable
    public final void run() {
        try {
            this.f1149b.dispatch();
        } catch (Exception ex) {
            TLog.m241e(f1148a, "Error when report events to server. " + ex.getMessage());
        }
    }
}
